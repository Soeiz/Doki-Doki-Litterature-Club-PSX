#include <sys/types.h>
#include <sys/file.h>
#include <stdio.h>
#include <stdbool.h>

#include <kernel.h>
#include <libgte.h>
#include <libetc.h>
#include <libgpu.h>
#include <libsnd.h>
#include <libspu.h>
#include <rand.h>
#include <libapi.h>
#include <string.h>
#include <libmcrd.h>
#include <libpress.h>

#include <libcd.h>
#include <malloc.h>

//Thanks Lameguy64 for saving & loading techniques

                                                                                                                //Game Variables

int imagedebugger = 0;
int debuggerframes = 60;

int strselection = 0;

int ErrorCode = 0;
int fakeErrorCode = 0;

int transitionlimitframes = 300;

/*
    ErrorCode helps you to debug features and other things in the game.
    imagedebugger & debuggerframes will unstuck you if the game is stuck in loading.
    transitionlimitframes will reset the game if the transition take to much time (3 seconds).

    11 : Failed to find instructions on the "beginscene" function.
    12 : Failed to create save using the alone argument (require "which" argument).
    13 : Loaded too many times ! (See changeBG)
    14 : Transition taking too much time.
    5416193 : Happy Thoughts. (memcardthings.h / L.534)
    


    Monika, stop trying to load too much please. I know this is difficult to not being included in the memory card when trying to save, but please if you do, stop corrupting the RAM.
*/

int currentchapter = 1;

int currentday = 0;

int timeMoniUnstuckU = 0;

int currentscreen = 1; //Won't change anything if you modify it, check MemcardSavesInit.

int oldscreen = 0; //Used to detect screen changes.

/*
    0 : Warning
    1 : Menu
    2 : In-game
    3 : Writing Poems
    5 : Debug scene

*/

int imagealpha = -1;

int currentimage = -1;
int requestedimage = -1;

bool monikaroom = false; //Used for multiple layers

int secondlayeralpha[2] = {128,128};
bool onewaycosmos = true;

bool usesecondimage = false; //Mostly for when sayori dead

/*
    -1 : Nothing
    0 : Warning1
    1 : Warning2
    2 : Club
    3 : Notebook
    4 : Resident
    5 : Sayori Bedroom
    6 : Kitchen
    7 : Club
    8 : Corridor
    9 : Natsuki special
    10 : Sayori special
    11 : House
    12 : Classroom
    13 : Manga closet
    14 : Yuri special
    15 : JUST MONIKA
*/

bool finishedwriting = false;
int currentline = 0;
bool blockedline = false;
bool dokimoment = false;
bool poemmoment = false;
int dokipoem = 0;

char responsestrings[10][4] = {"ee","aa","ii","oo"};
int choicereason = 0;

int oldline = 0;

int indexdialogue;

char dialogueline[100] = " ";

char WrittenPoem[500] = "   Hello everyone ! \n   I hope you like this \n   little demo of mine. \n   In the future, I'll try \n   and do the WHOLE game !\n   Join the discord server and \n   subscribe to the game page \n   for more informations ! \n   TIP : Circle + Triangle + \n   R1 + L2 on titlescreen";

int frametextspeed = 1;
int frametextspeedfixed = 1;

bool limitercross, limitermenuselect = true;

bool choices = false;
int numberchoices = 1;
int selectionchoices = 1;
char extraNs[10] = "\n\n\n\n\n\n";
int lastresponse = 0;

bool loading = false;

bool isbghere = true;

bool ispoemhere = false;
bool poemfinished = false;

bool showtextbox = false;
bool textboxlow = false;
bool toggletextbox = false; //Use in images.h

int Yspeedtextbox = 0;

    //Warning scene variables
    
    int frameforseed = 0;

    bool isunderstood = false;

    bool changedbg = false;

    int bgalpha = 0;
    int bgalphatextbox = 128;
    bool separatealphatextbox = false;
    int framedelay = 60;

    int frameuntillaunch = 120;

    //Menu scene variables

    bool isinsettings = false;
    bool unabletopause = false;

    int menuintroframes = 0;
    int fadeinNoutalpha = 0;
    int MMspeed = 2;
    int GlogoYspeed = 0;
    bool itbounced = false;

    int selection = 0;

    bool transitiontogame = false;

    // In-Game Scenes Variables

    int randomwait = -1;
    int randomdialogue = 0;
    bool indialogue = true;
    
    int currentspeaker = 0; //1 Monika, 2 Natsuki, 3 Sayori, 4 Yuri. Used when character speaks to "zoom" them in (WIP)

    bool FFW = false;
    bool abletoFFW = true;
    int maxlineforFFW = 999;

    bool sayorivisible = false;

    bool yurivisible = false;

    bool natsukivisible = false;

    bool monikavisible = false;

    bool isinpause = false;

    bool isinloadingscreen = false;
    bool isinsavingscreen = false;
    
    char dialoguehistory[100][5] = {"e", "e", "e", "e", "e"};

    bool fadein = true;

    bool fadeout = false;

    char dialoguedisplayed[200] = "";

    bool showname = false;
    char nameshowed[10] = "???";

    bool deleteddokis[4] = {false,false,false,false}; //Monika, Natsuki, Sayori, Yuri

    bool sayoriconfess = false;

    bool hasseensayorideath = false;
    bool sayorihangingvisible = false;

    int timeuleftMoni = 0; //Used for chapter 3, 0 because each time you boot up the game it increment, so first time is 1, normal dialogue.

    //Cutscene Var

    int cutsceneNum = 1; // Number of the cutscene
    
    /*
        1: Sayori hanging
        2: Yuri kniffing
        3: End

    */

    int cutsceneframes = -1; //Used as a timer

    //Video viewer vars

    int videoframes = 2; //Used as a timer

// Define start address of allocated memory
// Let's use an array so we don't have to worry about using a memory segment that's already in use.
static unsigned char ramAddr[0x39000]; // https://discord.com/channels/642647820683444236/663664210525290507/864936962199781387
// We could also set a memory address manually, but we have to make sure this won't get in the way of other routines.
// void * ramAddr = (void *)0x80030D40; 

int RAN;
int Ran(int max)
{
    RAN = (rand()%max);
    if (RAN == 0) {RAN++;}
    return 0;
}

                                                                                                                //Base files
#include "base/asc2sjis.h"
#include "base/strplay.c"
#include "base/poem-minigame.h"
#include "base/music-sounds.h"
#include "base/images.h"
#include "base/memcardthings.h"

                                                                                                            //General Functions

void init(void)
{   
    ResetCallback();
    ResetGraph(0);

    // Initialize and setup the GTE
    
    InitGeom();
    SetGeomOffset(CENTERX,CENTERY);
    SetGeomScreen(CENTERX);

    SetDefDispEnv(&disp[0], 0, 0         , SCREENXRES, SCREENYRES);     // Set display area for both &disp[0] and &disp[1]
    SetDefDispEnv(&disp[1], 0, SCREENYRES, SCREENXRES, SCREENYRES);     // &disp[0] is on top  of &disp[1]
    SetDefDrawEnv(&draw[0], 0, SCREENYRES, SCREENXRES, SCREENYRES);     // Set draw for both &draw[0] and &draw[1]
    SetDefDrawEnv(&draw[1], 0, 0         , SCREENXRES, SCREENYRES);     // &draw[0] is below &draw[1]
    // Set video mode
    if (VMODE){ SetVideoMode(MODE_PAL);}
    SetDispMask(1);                 // Display on screen    
    setRGB0(&draw[0], 0, 0, 0); // set color for first draw area
    setRGB0(&draw[1], 0, 0, 0); // set color for second draw area
    draw[0].isbg = 1;               // set mask for draw areas. 1 means repainting the area with the RGB color each frame 
    draw[1].isbg = 1;
    PutDispEnv(&disp[db]);          // set the disp and draw environnments
    PutDrawEnv(&draw[db]);
    //FntLoad(FONTX, FONTY);                // Load font to vram at FONTX,FONTY
    //FntOpen(100, 100, 48, 20, 0, 12 );    // FntOpen(x, y, width, height,  black_bg, max. nbr. chars)
    //FntColor(fntColor, fntColorBG);
    FntLoad(960, 0);
    FntOpen(MARGINX, SCREENYRES - MARGINY - FONTSIZE, SCREENXRES - MARGINX * 2, FONTSIZE, 0, 280 );
    

}

void display(void) {
    DrawSync(0);                    // Wait for all drawing to terminate
    VSync(0);                       // Wait for the next vertical blank
    PutDispEnv(&disp[db]);          // set alternate disp and draw environnments
    PutDrawEnv(&draw[db]);  
    DrawOTag(&ot[db][OTLEN - 1]);
    db = !db;                       // flip db value (0 or 1)
    nextpri = primbuff[db];
}
//Used only when changing days or chapters
void ResetDialogue(void) {
    sprintf(nameshowed, "  ");
    sprintf(dialogueline, " ");
    sprintf(dialoguedisplayed, " ");

    monikavisible = false;
    yurivisible = false;
    sayorivisible = false;
    natsukivisible = false;

    if (currentchapter != 3) {currentline = 0;}

    sayoposY = 0;
    natsuposY = 0;
    moniposY = 0;
    yuriposY = 0;

    sayoposZ = 0;

    changeDokiPos(1,1,1);
    changeDokiPos(2,1,1);
    changeDokiPos(3,1,1);
    changeDokiPos(4,1,1);

    MovVectorpoem.vy = 150;
    ispoemhere = false;
    MovVectortextbox.vy = 20;
} 

//ResetGame is mostly used when error-ed, or after Sayori hanging, etc.
void ResetGame(bool ishardcore) {
    if (mutevolume) {mutevolume = false;}

    MovVectormenumonika.vx = 25;
    MovVectormenumonika.vy = -40;

    MovVectormenuyuri.vx = -15;
    MovVectormenuyuri.vy = -55;

    MovVectormenunatsuki.vx = 20;
    MovVectormenunatsuki.vy = -45;

    ScaleVectormenuyuri.vx = ONE;
    ScaleVectormenuyuri.vy = ONE;

    ScaleVectormenumonika.vx = ONE;
    ScaleVectormenumonika.vy = ONE;

    ScaleVectormenunatsuki.vx = ONE;
    ScaleVectormenunatsuki.vy = ONE;

    MovVectorlogo.vx = -25;
    MovVectorlogo.vy = -35;

    sayorihangingvisible = false;

    currentmusicvolume = 128;

    currentmusicvolumemulti[0] = 128;
    currentmusicvolumemulti[1] = 128;

    bgalpha = 0;
    currentscreen = 1;

    ResetDialogue();

    fadein = true;

    //ChangeFontColor(10,10,10);

    menuintroframes = 0;
    selection = 0;
    isinsettings = false;
    isinloadingscreen = false;
    isinpause = false;

    repeatsong = 1080;
    fixedrepeatsong = 1080;

    itbounced = false;

    transitiontogame = false;

    fadeinNoutalpha = 0;

    transitionlimitframes = 300;

    disp[0].isrgb24 = 0;
    disp[1].isrgb24 = 0;
    draw[0].isbg = 1; 
    draw[1].isbg = 1;


    if (ishardcore) {
    }
    
}


//BeginScene is a func that is being called at the start of a new scene.
void BeginScene(int scene) {
    srand(frameforseed); //To have even more rand
    switch(scene) {
        case 0:
            textboxlow = false;
            changeBG(0,true,false);
            isunderstood = false;
            ChangeFontColor(255,255,255);
            isbghere = true;
            CdControlF(CdlPause,0);
            currentline = 0;
            oldline = 0;
            bgalpha = 0;
        break;
        case 1:
            textboxlow = true;
            if (deleteddokis[2] == true) {ChangeMusic(4, true);}
            LoadAllTextures();
            isbghere = false;
            currentline = 0;
            oldline = 0;
            CheckForDeletion();
            MovVectorGlogo.vy = -112;
            MovVectorMM.vx = -140;
            MMspeed = 2;
            GlogoYspeed = 0;
            menuintroframes = 0;
            cursong = 0;
            disp[0].isrgb24 = 0;
            disp[1].isrgb24 = 0;
            draw[0].isbg = 1; 
            draw[1].isbg = 1;
            fadeinNoutalpha = 0;
        break;
        case 2:
            ResetDialogue();
            imagealpha = 128;
            isbghere = true;
            bgalpha = 0;
            fadein = true;
            bgalphatextbox = 0;
            ChangeFontColor(255,255,255);
            showtextbox = true;
            LoadTextBox(); //Separated bc of menuBG
            LoadAllTexturesIG();
            switch(currentchapter) {
                case 1:
                    switch(currentday) {
                        case 1:
                            changeBG(4,true,false);
                            ChangeMusic(5, true);
                            cursong = 5; //Set for the repeatsong to work properly.
                        break;
                        case 2:
                            ChangeMusic(5, true);
                            cursong = 5;
                            changeBG(2,true,false);
                        break;
                        default :
                            changeBG(4,true,false);
                            ChangeMusic(6, true);
                            cursong = 6;
                        break;
                    }
                break;
                case 2:

                break;
                case 3:
                    setRGB0(&draw[0], 0, 0, 0); // set color for first draw area
                    setRGB0(&draw[1], 0, 0, 0); // set color for second draw area
                    textboxlow = true;
                    bgalphatextbox = 128;
                    changeBG(15,true,false);
                    checkforGames();
                    if (currentline == 0) {
                        fadein = false;
                        imagealpha = 0;
                        isbghere = false;
                        bgalpha = 0;
                        CdControlF(CdlPause,0);
                        cursong = 22222;
                    } else {
                        cursong = 23;
                        ChangeMusic(23,true);
                    }
                    CheckForDeletion();
                    if (deleteddokis[3] == false) {
                        MemCardDeleteFile(16*currentCard,SAVENAMENATS);
                        MemCardDeleteFile(16*currentCard,SAVENAMEYURI);
                        MemCardDeleteFile(16*currentCard,SAVENAMESAYO); //Just in case
                    }
                    timeuleftMoni++;
                    currentline++;
                    CreateSaveFunc(true,0); //It will be impossible to save normally, so it's done automatically.
                break;
            }
        break;
        case 3:
            LoadTexturesMinigames();
            ChangeFontColor(20,20,20);
            if (currentchapter == 3) {
                changeBG(16,true,false);
                cursong = 24;
                ChangeMusic(24, true);
            } else {
                changeBG(3,true,false);
                cursong = 2;
                ChangeMusic(2, true);
            }
            bgalpha = 0;
            ChangePoemsWords();
            isbghere = true;
            currentmusicvolume = 128;
            transitiontogame = false;
            progressionwords = 1;
        break;
        case 4:
            ResetDialogue();
            ChangeFontColor(255,255,255);
            setRGB0(&draw[0], 0, 0, 0); // set color for first draw area
            setRGB0(&draw[1], 0, 0, 0); // set color for second draw area
            switch(cutsceneNum) {
                case 1:
                    cutsceneframes = 1500;
                    menuintroframes = 0;
                    LoadTextBox(); //Separated bc of menuBG
                    showtextbox = true;
                    changeBG(5,true,false);
                    cursong = 20;
                    ChangeMusic(20, true);
                break;
            }
        break;
        case 5:
            ChangeMusic(2, true);
            repeatsong = 864;
            fadeinNoutalpha = 0;
            ChangeFontColor(20,20,20);

        break;
        case 6:
            videoframes = 3300;
            PlayStr(320, 240, 0, 0, &StrFile[strselection]);
            disp[0].isrgb24 = 1;
            disp[1].isrgb24 = 1;
            draw[0].isbg = 0;  // Don't forget to set it back after the video, or else you're gonna have a bad trip
            draw[1].isbg = 0;
        break;
        default :
            ResetGame(false);
            ErrorCode = 11;
        break;
    }
    oldscreen = currentscreen;
}
void SpecialLinesActions() {
    switch(currentchapter) {
        case 1:
            if (hasseensayorideath) {
                switch(currentline) {
                    case 11:
                        if (bgalpha < 2) {
                            currentline++;
                        }
                    break;
                }
                return;
            }
            switch(currentday) {
                case 1:
                    switch(currentline) {//I HAVE to put these here because in dialoguelines file it'll only be asked once.
                        case 88:
                        break;
                    }
                break;

                case 2:
                    if (dokimoment) {
                        if (whowon == 1) {
                            switch(currentline) {
                                case 6:
                                break;
                                case 134:
                                    changeBG(14,false,true);
                                break;
                                case 175:
                                    changeBG(2,false,true);
                                break;
                            }
                        }
                        if (whowon == 2) {
                            switch(currentline) {
                                case 5:
                                    changeBG(13,false,false);
                                    cursong = 7;
                                    ChangeMusic(7, false);
                                break;
                                case 52:
                                    changeBG(2,false,true);
                                break;
                                case 122:
                                    changeBG(9,false,true);
                                break;
                                case 188:
                                    changeBG(2,false,true);
                                break;
                            }
                        }
                        if (whowon == 3) {
                            switch(currentline) {
                                case 43:
                                    if (bgalpha < 2) {
                                        currentline++;
                                    }
                                break;
                                case 51:
                                    if (bgalpha > 126) {
                                        currentline++;
                                    }
                                break;
                                case 114:
                                    changeBG(10,false,true);
                                break;
                                case 149:
                                    changeBG(2,false,true);
                                break;
                            }
                        }

                    }

                break;

                default :
                break;
            }


        break;
        case 3:
            switch(randomdialogue) {
                case 0:
                    switch(currentline) {
                        case 131:
                            loading = true;
                            if (bgalpha != 0) {
                                bgalpha--;
                                bgalphatextbox--;
                            } else {
                                ChangeMusic(3,true);
                                currentscreen = 3;
                            }
                        break;
                    }
                break;
            }
        break;
    }
}

//Used when finishing a line.
void dialogueEndText(void) {
    if (currentline == 3 && currentscreen == 0 && !isunderstood) {
        sprintf(responsestrings[0], "I understand.");
        choices = true;
    }
    if (currentscreen == 4) {
        showtextbox = false;
        bgalphatextbox = 0;
        isbghere = true;
    }
    switch(currentday) {
        case 2:
            switch(currentline) {
                case 89:
                    if (!dokimoment) {
                        sprintf(responsestrings[0], "Sayori");
                        sprintf(responsestrings[1], "Natsuki");
                        sprintf(responsestrings[2], "Yuri");
                        sprintf(responsestrings[3], "Monika");
                        numberchoices = 4;
                        choices = true;
                    }
                break;
            }

        break;
    }
    finishedwriting = true;
}

void DoCutscenes() {
    switch(cutsceneNum) {
        default :
            FntPrint("0 is selected. Press start.");
        break; //Most certainly 0
        case 1:
            if (showtextbox) {FntPrint("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n%s\n\n\n%s", nameshowed, dialoguedisplayed);} 

            if (repeatsong == 0) {
                cursong = 21;
                ChangeMusic(21, true);
            } else {repeatsong--;}
            /*
            if (ScaleVectorbg.vx > ONE) {
                ScaleVectorbg.vx--;
                ScaleVectorbg.vy--;
                ScaleVectorbg.vz--;
            }*/

            cutsceneframes--;

            switch(cutsceneframes) {
                case 1450:
                    currentline++;
                break;
                case 1437:
                    sayorihangingvisible = true;
                    ChangeFontColor(20,20,20);
                    /*
                    ScaleVectorbg.vx = ONE + 512;
                    ScaleVectorbg.vy = ONE + 512;
                    ScaleVectorbg.vz = ONE + 512;
                    MovVectorbg.vx -= 6;
                    MovVectorbg2.vx += 6;*/
                break;
                case 1202:
                    usesecondimage = true;
                break;
                case 1194:
                    ScaleVectorbg.vx = ONE + 2048;
                    ScaleVectorbg.vy = ONE + 2048;
                    ScaleVectorbg.vz = ONE + 2048;

                    MovVectorbg.vy += 20;
                    MovVectorbg.vx -= 10;

                    ScaleVectorsayoH.vx = ONE + 2048;
                    ScaleVectorsayoH.vy = ONE + 2048;
                    ScaleVectorsayoH.vz = ONE + 2048;

                    MovVectorsayoH.vy -= 5;
                    MovVectorsayoH.vx += 5;
                break;
                case 1184:
                    usesecondimage = false;
                    ScaleVectorbg.vx = ONE + 4096;
                    ScaleVectorbg.vy = ONE + 4096;
                    ScaleVectorbg.vz = ONE + 4096;

                    MovVectorbg.vy += 20;
                    MovVectorbg.vx -= 10;

                    ScaleVectorsayoH.vx = ONE + 4096;
                    ScaleVectorsayoH.vy = ONE + 4096;
                    ScaleVectorsayoH.vz = ONE + 4096;

                    MovVectorsayoH.vy -= 5;
                    MovVectorsayoH.vx += 5;


                    /*
                    ScaleVectorbg2.vx = ONE + 2048;
                    ScaleVectorbg2.vy = ONE + 2048;
                    ScaleVectorbg2.vz = ONE + 2048;
                    
                    VertPosbg2[0].vx += 33;
                    VertPosbg2[1].vx += 33;
                    VertPosbg2[2].vx += 33;
                    VertPosbg2[3].vx += 33;*/

                    VertPosbg2[0].vx = 0;
                    VertPosbg2[1].vx = 0;
                    VertPosbg2[2].vx = 0;
                    VertPosbg2[3].vx = 0;
                    VertPosbg2[0].vy = 0;
                    VertPosbg2[1].vy = 0;
                    VertPosbg2[2].vy = 0;
                    VertPosbg2[3].vy = 0;


                break;
                case 970:
                    MovVectorlogo.vx -= 20;
                    MovVectorlogo.vy -= 20;
                break;
                case 888:
                    MovVectorsayoH.vy += 10;
                    MovVectorsayoH.vx += 20;

                    ScaleVectorsayoH.vx = ONE + 4608;
                    ScaleVectorsayoH.vy = ONE + 4608;
                    ScaleVectorsayoH.vz = ONE + 4608;

                break;
                case 870:
                    MovVectorsayoH.vy -= 10;
                    MovVectorsayoH.vx -= 20;

                    ScaleVectorsayoH.vx = ONE + 4096;
                    ScaleVectorsayoH.vy = ONE + 4096;
                    ScaleVectorsayoH.vz = ONE + 4096;

                break;
                case 550:
                    fakeErrorCode = 5416193;
                    hasseensayorideath = true;
                break;
                case 0:
                    oldscreen = 2; //To prevent weird behiavour because of "beginscene". Too different case to use it, so I do it manually.
                    currentscreen = 2;
                    currentline = 0;
                    hasseensayorideath = true;
                    bgalpha = 128;
                    bgalphatextbox = 128;
                break;
            }
        break; //Sayori's Death
        case 2:

        break; //Yuri's Death
        case 3:

        break; //End cutscene
    }
}

                                                                                                                            //Other files 
#include "controllers.h"
#include "debugfunctions.h"
#include "dialogue/DialogueMain.h"


// "MemCardDeleteFile(16*currentCard,SAVENAMESAYO);" (last lines, memcardthings.h) Does not serve any purpose, it's just here for the dramatic effect. Lol