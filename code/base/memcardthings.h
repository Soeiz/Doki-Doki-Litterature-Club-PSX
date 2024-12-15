
//MEMORY CARD

// Converts strings from 8-bit ASCII characters to 16-bit Shift-JIS character encoding
void asc2sjis(char *asctext, u_short *sjistext) {
    
    // A small function to simplify the use of the ascii2sjis() function in asc2sjis.c
    
    int  i;
    char *ptr;
    
    union {
        u_short code;
        struct {
            char low;
            char high;
        } k_word;
    } kanji;
    
    for (i=0, ptr=(u_char*)sjistext; asctext[i] != 0x00; i++) {
        kanji.code  = ascii2sjis(asctext[i]);
        *ptr++ = kanji.k_word.high;
        *ptr++ = kanji.k_word.low;
    }
    
    sjistext[i] = 0x00;
    
}

bool memorycardmissing = false;

bool memorycardmode = false; //If set to true, no memory card will have to be present. So, no saves !

bool createsave = true;

int dokicreated = 0; //To create them in memory card

bool savespresent[10] = {false,false,false,false,false};

/*
    1 : RAINBOW 6
    2 : Gran Turismo
    3 : Crash Bandicoot
    4 : Catlevania - Symphony of the Night
    5 : Tekken 3
    6 : GT 2 
*/

#define SAVENAMEMAIN    "DDLCPS-17MAIN"
#define SAVETITLEMAIN   "Doki Doki Litterature Club !"

#define SAVENAMESAYO    "DDLCPS-17SAYO"
#define SAVETITLESAYO   "DDLC : SAYORI'S FILE"

#define SAVENAMEMONI    "DDLCPS-17MONI"
#define SAVETITLEMONI   "DDLC : MONIKA'S FILE"

#define SAVENAMEYURI    "DDLCPS-17YURI"
#define SAVETITLEYURI   "DDLC : YURI'S FILE"

#define SAVENAMENATS    "DDLCPS-17NATS"
#define SAVETITLENATS   "DDLC : NATSUKI'S FILE"

// Test save icon's CLUT (or color palette) data
u_short saveIcon_clut[16] = {
    0x0000,0xF999,0xFC1F,0x0000,
    0x0000,0x0000,0x0000,0x0000,
    0x0000,0x0000,0x0000,0x0000,
    0x0000,0x0000,0x0000,0x0000
};

// Test save icon's image data (16x16 4-bit)
u_short saveIcon_image[1][16][4] = {
    // First icon frame
    {{0x0000,0x1110,0x0111,0x0000 },
    { 0x0000,0x1111,0x1111,0x0000 },
    { 0x1000,0x2221,0x1222,0x0001 },
    { 0x1100,0x2222,0x2222,0x0011 },
    { 0x2110,0x2222,0x2222,0x0112 },
    { 0x2211,0x2222,0x2222,0x1122 },
    { 0x2211,0x2222,0x2222,0x1122 },
    { 0x2211,0x2222,0x2222,0x1122 },
    { 0x2211,0x2222,0x2222,0x1122 },
    { 0x2211,0x2222,0x2222,0x1122 },
    { 0x2211,0x2222,0x2222,0x1122 },
    { 0x2110,0x2222,0x2222,0x0112 },
    { 0x1100,0x2222,0x2222,0x0011 },
    { 0x1000,0x2221,0x1222,0x0001 },
    { 0x0000,0x1110,0x0111,0x0000 },
    { 0x0000,0x1110,0x0111,0x0000 }}
}; //I hate doing that

// Save block header structure
typedef struct {
    char    id[2];      // Always 'SC'
    char    type;       // Number of icon frames (0x11 - one frame, 0x12 - two frames, 0x13 - three frames)
    char    size;       // Size of save file in blocks
    u_short title[32];  // Title of save file (encoded in Shift-JIS format)
    char    pad[28];    // Unused
    char    clut[32];   // Color palette of icon frames (16 RGB5X1 16-bit color entries)
} SAVEHDR;

short numCards=0;       // Number of cards detected
short currentCard=0;    // Current card number
long  cardCmd;          // Card command return value
long  slotResult[2];    // Slot result value

long    fileCount[2]={0};
long    blockCount[2]={0};

struct DIRENTRY fileList[2][15];
    
void checkforGames(void) {
    if (memorycardmode) {return;}

    MemCardGetDirentry(16*currentCard, "*", &fileList[currentCard][0], &fileCount[currentCard], 0, 15);

    for (int i = 0; i < fileCount[currentCard]; i++) {

        char * stringtocheck = fileList[currentCard][i].name;

        switch(stringtocheck[12]) {
            case 'R': //R6
                savespresent[0] = true;
            break;
            case '0': //Crash
                savespresent[2] = true;
            break;
            case 'T': //Tekken
                savespresent[4] = true;
            break;
            case 'G': //first GT1, second GT2
                if (stringtocheck[13] == 'T') {savespresent[1] = true;} else {savespresent[5] = true;}
            break;
        }
        if (strcmp(stringtocheck,"*BESLES-01136R6-02-01") == 0) {savespresent[i] = true;}

        if (strcmp(stringtocheck,"BESCES-00984GT") == 0) {savespresent[i] = true;}

        if (strcmp(stringtocheck,"BESCES-0034400990050") == 0) {savespresent[i] = true;}

        if (strcmp(stringtocheck,"BASLUS-00067DRAX00") == 0) {savespresent[i] = true;}

        if (strcmp(stringtocheck,"BASCES-01237TEKKEN-3") == 0) {savespresent[i] = true;}
    }

}


void CheckForDeletion(void) {
    if (memorycardmode) {return;}

    MemCardGetDirentry(16*currentCard, "*", &fileList[currentCard][0], &fileCount[currentCard], 0, 15);

    deleteddokis[0] = true;
    deleteddokis[1] = true;
    deleteddokis[2] = true;
    deleteddokis[3] = true;

    for (int i = 0; i < 15; i++) {
        char * stringtocheck = fileList[currentCard][i].name;

        switch(stringtocheck[9]) {
            case 'S':
                deleteddokis[2] = false;
            break;
            case 'M':

                if (stringtocheck[10] == 'O') {
                    deleteddokis[0] = false;
                }

                if (stringtocheck[10] == 'A') {
                    memorycardmissing = false;
                }


            break;
            case 'Y':
                deleteddokis[3] = false;
            break;
            case 'N':
                deleteddokis[1] = false;
            break;
        }
    }
}

void MemCardLoad(void) {
    if (memorycardmode) {return;}

    //This function tries to load the data such as current chapter, day from the MAIN save (not the character saves)

    // Open the created file
    MemCardOpen(16*currentCard, SAVENAMEMAIN, O_RDONLY);

    // Read thingies
    currentchapter = MemCardReadData((u_long*)&currentchapter, 128*2, 256);
    while(MemCardSync(1, &cardCmd, &slotResult[0]) == 0);

    // Read thingies
    currentday = MemCardReadData((u_long*)&currentday, 128*3, 256);
    while(MemCardSync(1, &cardCmd, &slotResult[0]) == 0);

    // Read thingies
    timeuleftMoni = MemCardReadData((u_long*)&timeuleftMoni, 128*4, 256);
    while(MemCardSync(1, &cardCmd, &slotResult[0]) == 0);

    MemCardClose();

    if (currentchapter == 0) {currentchapter = 1;} //Shouldn't be 0, so set to 1

    if (currentday == 0) {currentday = 1;} //Shouldn't be 0, so set to 1
}

void CreateSaveFunc(bool alone, int which) {
    if (memorycardmode) {return;}

    if (alone) {
        char SaveName[15];
        char SaveTitle[15];

        switch(which) {
            case 1:
                sprintf(SaveTitle, SAVETITLEMONI);
                sprintf(SaveName, SAVENAMEMONI);
            break;//Monika
            case 2:
                sprintf(SaveTitle, SAVETITLESAYO);
                sprintf(SaveName, SAVENAMESAYO);
            break;//Sayori
            case 3:
                sprintf(SaveTitle, SAVETITLENATS);
                sprintf(SaveName, SAVENAMENATS);
            break;//Natsuki
            case 4:
                sprintf(SaveTitle, SAVETITLEYURI);
                sprintf(SaveName, SAVENAMEYURI);
            break;//Yuri
            case 0:
                sprintf(SaveTitle, SAVETITLEMAIN);
                sprintf(SaveName, SAVENAMEMAIN); //Used when changing days and other things
            break;
            default :
                ErrorCode = 12;
            break;
        }

        SAVEHDR header;

        header.id[0]='S'; header.id[1]='C'; // ID must always say SC
        header.type     = 0x11;                 // 1 frame icon
        header.size     = 1;                    // 1 block
            
        // Convert save title from ASCII to SJIS
        asc2sjis(SaveTitle, header.title);
        
        // Copy icon's CLUT to the header
        memcpy(header.clut, saveIcon_clut, 32);

        // Open save block for writing. If it doesn't exist, create it.

        if (MemCardCreateFile(16*currentCard, SaveName, 1) == 0x07) { // Is memory card full?
            
            FntPrint("\n\nerror: memory card is full\n", numCards);
            FntPrint("press X to continue", numCards);
            
            //return back
        }
        
        // Open the created file
        MemCardOpen(16*currentCard, SaveName, O_WRONLY);

        // Write the header
        MemCardWriteData((u_long*)&header, 128*0, 128);
        while(MemCardSync(1, &cardCmd, &slotResult[0]) == 0);
        
        // Write the icon frames
        MemCardWriteData((u_long*)&saveIcon_image, 128*1, 256);
        while(MemCardSync(1, &cardCmd, &slotResult[0]) == 0);

        if (which == 0) {

            // Write thingies
            MemCardWriteData((u_long*)&currentchapter, 128*2, 256);
            while(MemCardSync(1, &cardCmd, &slotResult[0]) == 0);

            // Write thingies
            MemCardWriteData((u_long*)&currentday, 128*3, 256);
            while(MemCardSync(1, &cardCmd, &slotResult[0]) == 0);

            MemCardWriteData((u_long*)&timeuleftMoni, 128*4, 256);
            while(MemCardSync(1, &cardCmd, &slotResult[0]) == 0);
        }

        //Close the created file
        MemCardClose();

        return;
    }
    switch(dokicreated) {
        case 0:
            currentscreen = 0; //Send to warning screen

            SAVEHDR header;

            header.id[0]='S'; header.id[1]='C'; // ID must always say SC
            header.type     = 0x11;                 // 1 frame icon
            header.size     = 1;                    // 1 block
                
            // Convert save title from ASCII to SJIS
            asc2sjis(SAVETITLEMAIN, header.title);
            
            // Copy icon's CLUT to the header
            memcpy(header.clut, saveIcon_clut, 32);

            // Open save block for writing. If it doesn't exist, create it.

            if (MemCardCreateFile(16*currentCard, SAVENAMEMAIN, 1) == 0x07) { // Is memory card full?
                
                FntPrint("\n\nerror: memory card is full\n", numCards);
                FntPrint("press X to continue", numCards);
                
                //return back
            }
            
            // Open the created file
            MemCardOpen(16*currentCard, SAVENAMEMAIN, O_WRONLY);

            // Write the header
            MemCardWriteData((u_long*)&header, 128*0, 128);
            while(MemCardSync(1, &cardCmd, &slotResult[0]) == 0);
            
            // Write the icon frames
            MemCardWriteData((u_long*)&saveIcon_image, 128*1, 256);
            while(MemCardSync(1, &cardCmd, &slotResult[0]) == 0);

            // Write thingies
            MemCardWriteData((u_long*)&currentchapter, 128*2, 256);
            while(MemCardSync(1, &cardCmd, &slotResult[0]) == 0);

            MemCardWriteData((u_long*)&currentday, 128*3, 256);
            while(MemCardSync(1, &cardCmd, &slotResult[0]) == 0);

            //Close the created file
            MemCardClose();

            dokicreated++;
            return;
        break;
        case 1:
            header.id[0]='S'; header.id[1]='C'; // ID must always say SC
            header.type     = 0x11;                 // 1 frame icon
            header.size     = 1;                    // 1 block
                
            // Convert save title from ASCII to SJIS
            asc2sjis(SAVETITLESAYO, header.title);
            
            // Copy icon's CLUT to the header
            memcpy(header.clut, saveIcon_clut, 32);

            // Open save block for writing. If it doesn't exist, create it.

            if (MemCardCreateFile(16*currentCard, SAVENAMESAYO, 1) == 0x07) { // Is memory card full?
                
                FntPrint("\n\nerror: memory card is full\n", numCards);
                FntPrint("press X to continue", numCards);
                
                //return back
            }
            
            // Open the created file
            MemCardOpen(16*currentCard, SAVENAMESAYO, O_WRONLY);

            // Write the header
            MemCardWriteData((u_long*)&header, 128*0, 128);
            while(MemCardSync(1, &cardCmd, &slotResult[0]) == 0);
            
            // Write the icon frames
            MemCardWriteData((u_long*)&saveIcon_image, 128*1, 256);
            while(MemCardSync(1, &cardCmd, &slotResult[0]) == 0);

            //Close the created file
            MemCardClose();

            deleteddokis[2] = false;
            dokicreated++;
            return;

        break;
        case 2:
            header.id[0]='S'; header.id[1]='C'; // ID must always say SC
            header.type     = 0x11;                 // 1 frame icon
            header.size     = 1;                    // 1 block
                
            // Convert save title from ASCII to SJIS
            asc2sjis(SAVETITLEMONI, header.title);
            
            // Copy icon's CLUT to the header
            memcpy(header.clut, saveIcon_clut, 32);

            // Open save block for writing. If it doesn't exist, create it.

            if (MemCardCreateFile(16*currentCard, SAVENAMEMONI, 1) == 0x07) { // Is memory card full?
                
                FntPrint("\n\nerror: memory card is full\n", numCards);
                FntPrint("press X to continue", numCards);
                
                //return back
            }
            
            // Open the created file
            MemCardOpen(16*currentCard, SAVENAMEMONI, O_WRONLY);

            // Write the header
            MemCardWriteData((u_long*)&header, 128*0, 128);
            while(MemCardSync(1, &cardCmd, &slotResult[0]) == 0);
            
            // Write the icon frames
            MemCardWriteData((u_long*)&saveIcon_image, 128*1, 256);
            while(MemCardSync(1, &cardCmd, &slotResult[0]) == 0);

            //Close the created file
            MemCardClose();

            deleteddokis[0] = false;
            dokicreated++;
            return;
        break;
        case 3:
            header.id[0]='S'; header.id[1]='C'; // ID must always say SC
            header.type     = 0x11;                 // 1 frame icon
            header.size     = 1;                    // 1 block
                
            // Convert save title from ASCII to SJIS
            asc2sjis(SAVETITLEYURI, header.title);
            
            // Copy icon's CLUT to the header
            memcpy(header.clut, saveIcon_clut, 32);

            // Open save block for writing. If it doesn't exist, create it.

            if (MemCardCreateFile(16*currentCard, SAVENAMEYURI, 1) == 0x07) { // Is memory card full?
                
                FntPrint("\n\nerror: memory card is full\n", numCards);
                FntPrint("press X to continue", numCards);
                
                //return back
            }
            
            // Open the created file
            MemCardOpen(16*currentCard, SAVENAMEYURI, O_WRONLY);

            // Write the header
            MemCardWriteData((u_long*)&header, 128*0, 128);
            while(MemCardSync(1, &cardCmd, &slotResult[0]) == 0);
            
            // Write the icon frames
            MemCardWriteData((u_long*)&saveIcon_image, 128*1, 256);
            while(MemCardSync(1, &cardCmd, &slotResult[0]) == 0);

            //Close the created file
            MemCardClose();
            
            deleteddokis[3] = false;
            dokicreated++;
            return;

        break;
        case 4:
            header.id[0]='S'; header.id[1]='C'; // ID must always say SC
            header.type     = 0x11;                 // 1 frame icon
            header.size     = 1;                    // 1 block
                
            // Convert save title from ASCII to SJIS
            asc2sjis(SAVETITLENATS, header.title);
            
            // Copy icon's CLUT to the header
            memcpy(header.clut, saveIcon_clut, 32);

            // Open save block for writing. If it doesn't exist, create it.

            if (MemCardCreateFile(16*currentCard, SAVENAMENATS, 1) == 0x07) { // Is memory card full?
                
                FntPrint("\n\nerror: memory card is full\n", numCards);
                FntPrint("press X to continue", numCards);
                
                //return back
            }
            
            // Open the created file
            MemCardOpen(16*currentCard, SAVENAMENATS, O_WRONLY);

            // Write the header
            MemCardWriteData((u_long*)&header, 128*0, 128);
            while(MemCardSync(1, &cardCmd, &slotResult[0]) == 0);
            
            // Write the icon frames
            MemCardWriteData((u_long*)&saveIcon_image, 128*1, 256);
            while(MemCardSync(1, &cardCmd, &slotResult[0]) == 0);

            //Close the created file
            MemCardClose();
            
            deleteddokis[1] = false;
            dokicreated++;
            return;

        break;
        case 5:
            createsave = false;
            dokicreated = 0;
            CheckForDeletion();
        break;
    }

}
void MemcardSavesInit(void) {
    if (memorycardmode) {return;}

    if (MemCardOpen(16*currentCard, SAVENAMEMAIN, O_WRONLY) == McErrNone) { //If good card + having everything, go on !
        createsave = false;
        CheckForDeletion();
        currentscreen = 1;
    } else {memorycardmissing = true;} //If not, make it like you don't have a mem card

    if (!memorycardmissing) {CheckForDeletion();}

    if (deleteddokis[2] == false) {
        if (deleteddokis[3] == true) {CreateSaveFunc(true, 4);} //Make them back when launching game if sayori not deleted
        if (deleteddokis[1] == true) {CreateSaveFunc(true, 3);}
    } else {










        
        ErrorCode = 5416193; // Get out of my head. Get out of my head. Get out of my head. Get out of my head. Get out of my head. Get out of my head. Get out of my head. Get out of my head. Get out of my head. Get out of my head.  
        MemCardDeleteFile(16*currentCard,SAVENAMENATS);// Get out of my head before I do what I know is best for you.
        MemCardDeleteFile(16*currentCard,SAVENAMEYURI);// Get out of my head before I listen to everything she said to me.
        MemCardDeleteFile(16*currentCard,SAVENAMEMONI);// Get out of my head before I show you how much I love you.
        MemCardDeleteFile(16*currentCard,SAVENAMEMAIN);// Get out of my head before I finish writing this poem.
    







        // But a poem is never actually finished.
        // It just stops moving.
        MemCardDeleteFile(16*currentCard,SAVENAMESAYO);
    }
}