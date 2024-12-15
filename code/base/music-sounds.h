                                                                                                        //XA - CD LOAD
#define BtoS(len) ( ( len + CD_SECTOR_SIZE - 1 ) / CD_SECTOR_SIZE ) 
// Name of file to load
static char * loadFile;
// libcd's CD file structure contains size, location and filename
CdlFILE filePos = {0};
//~ struct EXEC * exeStruct;
// Load data to this buffer
u_long * dataBuffer;              
// Those are not strictly needed, but we'll use them to see the commands results.
// They could be replaced by a 0 in the various functions they're used with.
u_char CtrlResult[8];
// Value returned by CDread() - 1 is good, 0 is bad
int CDreadOK = 0;
// Value returned by CDsync() - Returns remaining sectors to load. 0 is good.
int CDreadResult = 0;

#define CD_SECTOR_SIZE 1204

// Number of VAG files to load
#define VAG_NBR 3
#define MALLOC_MAX VAG_NBR            // Max number of time we can call SpuMalloc

// convert Little endian to Big endian
#define SWAP_ENDIAN32(x) (((x)>>24) | (((x)>>8) & 0xFF00) | (((x)<<8) & 0x00FF0000) | ((x)<<24))
// Memory management table ; allow MALLOC_MAX calls to SpuMalloc() - libref47.pdf p.1044

char spu_malloc_rec[SPU_MALLOC_RECSIZ * (MALLOC_MAX + 1)]; 

// Custom struct to handle VAG files
typedef struct VAGsound {
    u_char * VAGfile;        // Pointer to VAG data address
    u_long spu_channel;      // SPU voice to playback to
    u_long spu_address;      // SPU address for memory freeing spu mem
} VAGsound;

// VAG header struct (see fileformat47.pdf, p.209)
typedef struct VAGhdr {                // All the values in this header must be big endian
        char id[4];                    // VAGp         4 bytes -> 1 char * 4
        unsigned int version;          // 4 bytes
        unsigned int reserved;         // 4 bytes
        unsigned int dataSize;         // (in bytes) 4 bytes
        unsigned int samplingFrequency;// 4 bytes
        char  reserved2[12];           // 12 bytes -> 1 char * 12
        char  name[16];                // 16 bytes -> 1 char * 16
        // Waveform data after that
} VAGhdr;

// SPU settings
SpuCommonAttr commonAttributes;          // structure for changing common voice attributes
SpuVoiceAttr  voiceAttributes ;          // structure for changing individual voice attributes   


                                                                                                            //VAG

// extern VAG files
extern u_char _binary_sounds_GUI_select_vag_start;
extern u_char _binary_sounds_GUI_hover_vag_start;
extern u_char _binary_sounds_SFX_pageflip_vag_start;
// soundBank
VAGsound vagsoundBank[VAG_NBR] = {
      { &_binary_sounds_GUI_select_vag_start,
        SPU_00CH, 0 },   
      { &_binary_sounds_GUI_hover_vag_start,
        SPU_01CH, 0 },   
      { &_binary_sounds_SFX_pageflip_vag_start,
        SPU_02CH, 0 },   
};
 
void XAsetup()
{   
    u_char param[4];
    // ORing the parameters we need to set ; drive speed,  ADPCM play, Subheader filter, sector size
    // If using CdlModeSpeed(Double speed), you need to load an XA file that has 8 channels.
    // In single speed, a 4 channels XA is to be used.
    param[0] = CdlModeSpeed|CdlModeRT|CdlModeSF|CdlModeSize1;
    // Issue primitive command to CD-ROM system (Blocking-type)
    // Set the parameters above
    CdControlB(CdlSetmode, param, 0);
    // Pause at current pos
    CdControlF(CdlPause,0);
}
                                                                                                            // XA - MUSICS
// SPU attributes
SpuCommonAttr spuSettings;
#define CD_SECTOR_SIZE 1204
// XA
// Sector offset for XA data 4: simple speed, 8: double speed
#define XA_CHANNELS 8
#define XA_CDSPEED XA_CHANNELS >> 2
// Number of XA samples ( != # of XA files )
#define XA_TRACKS 4

typedef struct XAsound {
    u_int id;
    u_int size;
    // We can find size in sector : size / 2336, start value begins at 23, end value is at start + offset ( (size / 2336)-1 * #channels )
    // subsequent start value have an 8 bytes offset (n-1.end + 8)
    u_char file, channel;
    u_int start, end;
    int cursor;
} XAsound;

typedef struct XAbank {
    u_int index;
    int offset;
    XAsound samples[];
} XAbank;

XAbank soundBank = {
        25,
        0,
        {
            //(silence.xa = 1496)

            //Channel 0
            // id   size   file  channel start end cursor
            {   0,  791904,   1,     0,     0,   2704,  -1 }, //Menu Intro.xa
            {   1,  4779456,   1,     0,     4200,   20560,  -1 }, //Menu Loop.xa
            {   2,  633056,   1,     0,     22056,   24216,  -1 }, //Writing Poems Intro.xa
            {   3,  4732736,   1,     0,     25712,   41912,  -1 }, //Writing Poems Loop.xa
            {   4,  2807872,   1,     0,     43408,   53016,  -1 }, //Hanginthere.xa
            //Channel 1
            {   5,  3349824,   1,     1,     0,   11464,  -1 }, //Ohayousayori!.xa
            {   6,  4398688 ,   1,     1,     12960,   28016,  -1 }, //DDLCvibe.xa
            {   7,  467200 ,   1,     1,     29512,   31104,  -1 }, //PlayWithMeIntro.xa
            {   8,  3504000 ,   1,     1,     32600,   44592,  -1 }, //PlayWithMeLoop.xa
            {   9,  3029792 ,   1,     1,     46088,   56456,  -1 }, //PoemPanic!.xa
            //Channel 2
            {   10,  415808,   1,     2,     0,   1416,  -1 }, //Okay,Everyone!Intro.xa
            {   11,  3440928 ,   1,     2,     2912,   14688,  -1 }, //Okay,Everyone!Loop.xa
            {   12,  161184 ,   1,     2,     16184,   16728,  -1 }, //Okay,Everyone!IntroMoni.xa
            {   13,  3819360 ,   1,     2,     18224,   31296,  -1 },//Okay,Everyone!LoopMoni.xa
            {   14,  184544 ,   1,     2,     32792,   33416,  -1 },//Okay,Everyone!IntroNatsu.xa
            {   15,  3029792 ,   1,     2,     34912,   45280,  -1 },//Okay,Everyone!LoopNatsu.xa
            //Channel 3
            {   16,  184544 ,   1,     3,     0,   624,  -1 }, //Okay,Everyone!IntroSayo.xa 624
            {   17,  3826368 ,   1,     3,     2120,   15216,  -1 },//Okay,Everyone!LoopSayo.xa 13096
            {   18,  184544 ,   1,     3,     16712,   17336,  -1 },//Okay,Everyone!IntroYuri.xa 624
            {   19,  3826368 ,   1,     3,     18832,   31928,  -1 },//Okay,Everyone!LoopYuri.xa 13096
            {   20,  2490176,   1,     3,     33424,   41848,  -1 }, //S_Kill_Begin.xa 8424
            {   21,  3387200,   1,     3,     43344,   54936,  -1 }, //S_Kill_Loop.xa, 11592
            //Channel 4
            {   22,  151840,   1,     4,     0,   512,  -1 }, //Act 3 Intro.xa
            {   23,  5036416,   1,     4,     2008,   19248,  -1 }, //Act 3 JUSTMONIKA.xa
            {   24,  1936544,   1,     4,     20744,   27368,  -1 }, //ghost.xa
        }
};

// XA file to load
static char * loadXA = "\\INTER8.XA;1";
// File informations : pos, size, name
CdlFILE XAPos = {0};
// CD filter
CdlFILTER filter;
// File position in m/s/f
CdlLOC  loc;

int sample = -1;

int repeatsong = 1080;
int fixedrepeatsong = 1080; //when repeatsong hit 0, it repeats. 

bool keepmusic = false;

int cursong = 0;
int requestedsong = -1;
bool brutalchange = false;

int testingforunpause = 0;

int currentmusicvolume = 128;
int currentmusicvolumemulti[2] = {128,128};
bool multiplemusics = false;
bool mutevolume = false;

// Audio initialisation & functions
void initSnd(void) {
    SpuInitMalloc(MALLOC_MAX, spu_malloc_rec);                      // Maximum number of blocks, mem. management table address.
    commonAttributes.mask = (SPU_COMMON_MVOLL | SPU_COMMON_MVOLR);  // Mask which attributes to set
    commonAttributes.mvol.left  = 0x3fff;                           // Master volume left
    commonAttributes.mvol.right = 0x3fff;                           // see libref47.pdf, p.1058
    commonAttributes.cd.volume.left = 0x6000;
    commonAttributes.cd.volume.right = 0x6000;
    // Apply settings
    SpuSetCommonAttr(&commonAttributes);                            // set attributes
    SpuSetIRQ(SPU_OFF);
    SpuSetKey(SpuOff, SPU_ALLCH);
}

void spuSetup(SpuCommonAttr * spuSettings) {
    // Init Spu
    SpuInit();
    // Set master & CD volume to max
    spuSettings->mask = (SPU_COMMON_MVOLL | SPU_COMMON_MVOLR | SPU_COMMON_CDVOLL | SPU_COMMON_CDVOLR | SPU_COMMON_CDMIX);
    spuSettings->mvol.left  = 0x6000;
    spuSettings->mvol.right = 0x6000;
    spuSettings->cd.volume.left = 0x6000;
    spuSettings->cd.volume.right = 0x6000;
    // Enable CD input ON
    spuSettings->cd.mix = SPU_ON;
    // Apply settings
    SpuSetCommonAttr(spuSettings);
    // Set transfer mode 
    SpuSetTransferMode(SPU_TRANSFER_BY_DMA);
}

u_long sendVAGtoSPU(unsigned int VAG_data_size, u_char *VAG_data) {
    u_long transferred;
    SpuSetTransferMode(SpuTransByDMA);                              // DMA transfer; can do other processing during transfer
    transferred = SpuWrite (VAG_data + sizeof(VAGhdr), VAG_data_size);     // transfer VAG_data_size bytes from VAG_data  address to sound buffer
    SpuIsTransferCompleted (SPU_TRANSFER_WAIT);                     // Checks whether transfer is completed and waits for completion
    return transferred;
}

void setVoiceAttr(unsigned int pitch, long channel, unsigned long soundAddr ) {
    voiceAttributes.mask=                                   //~ Attributes (bit string, 1 bit per attribute)
    (
      SPU_VOICE_VOLL |
      SPU_VOICE_VOLR |
      SPU_VOICE_PITCH |
      SPU_VOICE_WDSA |
      SPU_VOICE_ADSR_AMODE |
      SPU_VOICE_ADSR_SMODE |
      SPU_VOICE_ADSR_RMODE |
      SPU_VOICE_ADSR_AR |
      SPU_VOICE_ADSR_DR |
      SPU_VOICE_ADSR_SR |
      SPU_VOICE_ADSR_RR |
      SPU_VOICE_ADSR_SL
    );
    voiceAttributes.voice        = channel;                 //~ Voice (low 24 bits are a bit string, 1 bit per voice )
    voiceAttributes.volume.left  = 0x0;                  //~ Volume 
    voiceAttributes.volume.right = 0x0;                  //~ Volume
    voiceAttributes.pitch        = pitch;                   //~ Interval (set pitch)
    voiceAttributes.addr         = soundAddr;               //~ Waveform data start address
    voiceAttributes.a_mode       = SPU_VOICE_LINEARIncN;    //~ Attack rate mode  = Linear Increase - see libref47.pdf p.1091
    voiceAttributes.s_mode       = SPU_VOICE_LINEARIncN;    //~ Sustain rate mode = Linear Increase
    voiceAttributes.r_mode       = SPU_VOICE_LINEARDecN;    //~ Release rate mode = Linear Decrease
    voiceAttributes.ar           = 0x0;                     //~ Attack rate
    voiceAttributes.dr           = 0x0;                     //~ Decay rate
    voiceAttributes.rr           = 0x0;                     //~ Release rate
    voiceAttributes.sr           = 0x0;                     //~ Sustain rate
    voiceAttributes.sl           = 0xf;                     //~ Sustain level
    SpuSetVoiceAttr(&voiceAttributes);                      // set attributes
    SpuSetVoiceVolume(0, 0x3500, 0x3500);//Select
    SpuSetVoiceVolume(1, 0x3500, 0x3500);//Hover
    SpuSetVoiceVolume(2, 0x3500, 0x3500);//Page flip
}

u_long setSPUtransfer(VAGsound * sound) {
    // Return spu_address
    u_long transferred, spu_address;
    u_int pitch;
    const VAGhdr * VAGheader = (VAGhdr *) sound->VAGfile;
    pitch = (SWAP_ENDIAN32(VAGheader->samplingFrequency) << 12) / 44100L; 
    spu_address = SpuMalloc(SWAP_ENDIAN32(VAGheader->dataSize));                // Allocate an area of dataSize bytes in the sound buffer. 
    SpuSetTransferStartAddr(spu_address);                                       // Sets a starting address in the sound buffer
    transferred = sendVAGtoSPU(SWAP_ENDIAN32(VAGheader->dataSize), sound->VAGfile);
    setVoiceAttr(pitch, sound->spu_channel, spu_address); 
    // Return 1 if ok, size transferred else.
    //~ if (transferred == SWAP_ENDIAN32(VAGheader->dataSize)){
        //~ return 1;
        //~ }
    //~ return transferred;
    return spu_address;
}
//testingforunpause = soundBank.samples[sample].cursor;
void XAPlayBack(void) {
    // if sample is set
    if (sample != -1 ){
        // Begin XA file playback...
        // if sample's cursor is 0
        if (soundBank.samples[sample].cursor == 0){
            //If the value has been changed (because of a bg change)
            if (testingforunpause != 0) {
                CdIntToPos(soundBank.samples[sample].start + soundBank.offset + testingforunpause + 1000, &loc);
                testingforunpause = 0;
            } else {
                // Convert sector number to CD position in min/second/frame and set CdlLOC accordingly.
                CdIntToPos( soundBank.samples[sample].start + soundBank.offset , &loc);  
            }
            // Send CDROM read command
            CdControlF(CdlReadS, (u_char *)&loc);
            // Set playing flag
        }
        // if sample's cursor is close to sample's end position, stop playback
        if ((soundBank.samples[sample].cursor += XA_CDSPEED) >= soundBank.samples[sample].end - soundBank.samples[sample].start  ){
            CdControlF(CdlStop,0);
            soundBank.samples[sample].cursor = -1;
            sample = -1;
        }
    }
}


bool changingmusic = true;

//ChangeMusic is called when, well, I dunno use your brain bruh
void ChangeMusic(int music, bool isbrutal) {
    //Brutal is mostly when looping ! If not, it's when changing tracks

    if (currentmusicvolume > 0 && !isbrutal) {changingmusic = true; currentmusicvolume -= 2; blockedline = true;} else {

        if (loading) {currentmusicvolume += 2; return;} //Is not supposed to go past that when loading bg

        sample = music;
        filter.chan = soundBank.samples[sample].channel;
        filter.file = soundBank.samples[sample].file;
        CdControlF(CdlSetfilter, (u_char *)&filter);
        soundBank.samples[sample].cursor = 0;

        switch(music) {//Might be way easier for everyone else to set up
            case 0:
                fixedrepeatsong = 1080;
            break;
            case 1:
                fixedrepeatsong = 6540;
            break;
            case 2:
                fixedrepeatsong = 864;
            break;
            case 3:
                fixedrepeatsong = 6480;
            break;
            case 4:
                fixedrepeatsong = 3845;
            break;
            case 5:
                fixedrepeatsong = 4590;
            break;
            case 6:
                fixedrepeatsong = 6018;
            break;
            case 7:
                fixedrepeatsong = 636;
            break;
            case 8:
                fixedrepeatsong = 4800;
            break;
            case 9:
                fixedrepeatsong = 4146;
            break;
            case 10:
                fixedrepeatsong = 564;
            break;
            case 11:
                fixedrepeatsong = 4710;
            break;
            case 12:
                fixedrepeatsong = 216;
            break;
            case 13:
                fixedrepeatsong = 5226;
            break;
            case 14:
                fixedrepeatsong = 246;
            break;
            case 15:
                fixedrepeatsong = 5226;
            break;
            case 16:
                fixedrepeatsong = 246;
            break;
            case 17:
                fixedrepeatsong = 5226;
            break;
            case 18:
                fixedrepeatsong = 246;
            break;
            case 19:
                fixedrepeatsong = 5226;
            break;
            case 20:
                fixedrepeatsong = 3372;
            break;
            case 21:
                fixedrepeatsong = 4620;
            break;
            case 22:
                fixedrepeatsong = 204;
            break;
            case 23:
                fixedrepeatsong = 6294;
            break;
            case 24:
                fixedrepeatsong = 2646;
            break;
        }

        repeatsong = fixedrepeatsong;
        changingmusic = false;
        blockedline = false;
        requestedsong = -1;
        brutalchange = false; 
        cursong = sample; //Just in case
    }

}
void loadMusic(int music, bool isbrutal) {
    if (music == -1) {return;}
    ChangeMusic(music,isbrutal);
}
