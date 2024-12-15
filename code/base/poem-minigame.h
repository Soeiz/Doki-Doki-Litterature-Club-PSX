//POEM FUNCS

//Notebook scene Variables

bool beginwriting = false;

bool limiterstart = false;

int selectedwords = 0;

int progressionwords = 1;

char words[10][20] = {"ehehe"};

int selectionword = 0;
bool limiterselectword = false;
bool wordisselected = false;

int dokispoint[3] = {0,0,0}; //Yuri, Natsuki, Sayori
int whowon = 0; //1 for Yuri, 2 for Natsuki, 3 for Sayori

bool yurihappy = false;
int frameyurih = 0;
int bouncedtwiceY = 0;
int yspeedyuri = 0;
bool liljumpY = false;

bool sayorihappy = false;
int bouncedtwiceS = 0;
int framesayorih = 0;
int yspeedsayori = 0;
int Xside = 1;
bool liljumpS = false;

bool natsukihappy = false;
int bouncedtwiceN = 0;
int framenatsukih = 0;
int yspeednatsuki = 0;
bool liljumpN = false;

int bouncedtwiceM = 0;
int yspeedmonika = 0;
bool monikahappy = false;
int framemonikah = 0;

int writingframe = 5; //Waiting frames var to prevent double tapping 

/*
char dictionnarywords[][20] = {

}*/

char dictionnarywordsS[88][20] = {
    "Adventure","Alone","Amazing","Awesome",
    "Beauty","Bed","Bliss","Broken",
    "Calm","Charm","Cheer","Childhood",
    "Clumsy","Color","Comfort","Cry",
    "Dance","Dark","Daydream","Dazzle",
    "Death","Defeat","Depression","Embrace",
    "Empty","Excitement","Extraordinary","Family",
    "Fear","Feather","Fireflies","Fireworks",
    "Flower","Flying","Forgive","Friends",
    "Fun","Grief","Happiness","Heart",
    "Holiday","Hope","Hopeless","Hurt",
    "Joy","Laugh","Lazy","Loud",
    "Love","Lucky","Marriage","Memories",
    "Misery","Misfortune","Music","Nature",
    "Ocean","Pain","Party","Passion",
    "Peaceful","Play","Prayer","Precious",
    "Promise","Rainbow","Raincloud","Romance",
    "Rose","Sadness","Scars","Shame",
    "Silly","Sing","Smile","Sparkle",
    "Special","Sunny","Sunset","Sweet",
    "Tears","Together","Tragedy","Treasure",
    "Unrequited","Vacation","Warm","Wonderful"
};

char dictionnarywordsN[62][20]= {
    "Anger","Anime","Blanket","Boop",
    "Bouncy","Bubbles","Bunny","Candy",
    "Cheeks","Chocolate","Clouds","Cute",
    "Doki-Doki","Email","Fantasy","Fluffy",
    "Games","Giggles","Hair","Headphones",
    "Heartbeat","Hop","Jump","Jumpy",
    "Kawaii","Kiss","Kitty","Lipstick",
    "Lollipop","Marshmallow","Melody","Milk",
    "Mouse","Nibble","Nightgown","Papa",
    "Parfait","Peace","Pink","Playground",
    "Poof","Pout","Puppy","Pure",
    "Ribbon","Shiny","Shopping","Skipping",
    "Skirt","Socks","Spinning","Sticky",
    "Strawberry","Sugar","Summer","Swimsuit",
    "Twirl","Valentine","Vanilla","Waterfall",
    "Whisper","Whistle"
};

char dictionnarywordsY[78][20] = {
    "Afterimage","Agonizing","Ambient","Analysis","Anxiety","Atone",
    "Aura","Breathe","Cage","Captive","Climax","Contamination",
    "Covet","Crimson","Desire","Despise","Destiny","Determination",
    "Disarray","Disaster","Disoriented","Disown","Dream","Effulgent",
    "Electricity","Entropy","Essence","Eternity","Existence","Explode",
    "Extreme","Fester","Fickle","Flee","Frigthening","Graveyard",
    "Heavensent","Horror","Imagination","Incapable","Incongruent","Infallible",
    "Inferno","Infinite","Insight","Intellectual","Journey","Judgment",
    "Landscape","Lust","Massacre","Meager","Melancholy","Philosophy",
    "Pleasure","Portrait","Question","Raindrops","Secretive","Sensation",
    "Starscape","Suicide","Tenacious","Time","Uncanny","Uncontrollable",
    "Unending","Universe","Unrestrained","Unstable","Variance","Vertigo",
    "Vibrant","Vitality","Vivacious","Vivid","Whirlwind","Wrath"
};
char dictionnarywordsM[26][20] = {
    "Monika","Mo ika"," onika","M nika","Mon ka","Moni a",
    "Monik ","akinoM","M    onika","Moooooooooo","Monikkkkkkkk","Mooniikaa",
    "M ","Moni  ","Mokina","Mkinao","   i  "," O",
    "  N","     K","     A","Minoooo","Mooka","MoMoMoMoMoMoMo",
    "MoniMoniMoni","MonikaMonikaMonika"
};

char usedwords[20][20] = {
    "","","","","","","","","","",
    "","","","","","","","","",""
};

int dokiword[10];

//Used to shuffle words
void ChangePoemsWords(void) {
    selectionword = 0;
    if (currentchapter == 1) {
        for (int i = 0; i < 10; i++) { 
            Ran(4);
            int usedwordlength = sizeof(usedwords) / sizeof(usedwords[0]); //
            switch(RAN) {
                case 1:
                    Ran(sizeof(dictionnarywordsS) / sizeof(dictionnarywordsS[0])); //Pick a random word in the catalogue of words

                    for (int y = 0; y < usedwordlength; y++) {//For every words present in the line
                        if (strcmp(dictionnarywordsS[RAN], usedwords[y]) == 0) { //if There's two of the same
                            Ran(sizeof(dictionnarywordsS) / sizeof(dictionnarywordsS[0])); //Pick another one
                        }
                    }
                    sprintf(words[i], dictionnarywordsS[RAN]); //Put the word in the list 
                    dokiword[i] = 1; 
                break;

                case 2: 
                    Ran(sizeof(dictionnarywordsN) / sizeof(dictionnarywordsN[0]));

                    for (int y = 0; y < usedwordlength; y++) {
                        if (strcmp(dictionnarywordsN[RAN], usedwords[y]) == 0) {
                            Ran(sizeof(dictionnarywordsN) / sizeof(dictionnarywordsN[0]));
                        }
                    }
                    sprintf(words[i], dictionnarywordsN[RAN]);   
                    dokiword[i] = 2;   
                break;

                case 3: 
                    Ran(sizeof(dictionnarywordsY) / sizeof(dictionnarywordsY[0]));

                    for (int y = 0; y < usedwordlength; y++) {
                        if (strcmp(dictionnarywordsY[RAN], usedwords[y]) == 0) {
                            Ran(sizeof(dictionnarywordsY) / sizeof(dictionnarywordsY[0]));
                        }
                    }
                    sprintf(words[i], dictionnarywordsY[RAN]);  
                    dokiword[i] = 3; 
                break;
            }
        }
    }
    if (currentchapter == 2) {

    }
    if (currentchapter == 3) {
        for (int i = 0; i < 10; i++) { 
            int usedwordlength = sizeof(usedwords) / sizeof(usedwords[0]);
            Ran(sizeof(dictionnarywordsM) / sizeof(dictionnarywordsM[0])); //Pick a random word in the catalogue of words

            for (int y = 0; y < usedwordlength; y++) {//For every words present in the line
                if (strcmp(dictionnarywordsM[RAN], usedwords[y]) == 0) { //if There's two of the same
                    Ran(sizeof(dictionnarywordsM) / sizeof(dictionnarywordsM[0])); //Pick another one
                }
            }
            sprintf(words[i], dictionnarywordsM[RAN]); //Put the word in the list 
            dokiword[i] = 1; 
        }
    }//Only monika, how hard
}

//Used by poem minigame when pressing a word
void DistributePoint(void) {
    //I know this is a "simplified version" and that there's a point hierarchy for each words, but ATM let's keep it simple
    char selectedword[20];

    sprintf(selectedword, words[selectionword]);

    for (int i = 0; i < (sizeof(dictionnarywordsY) / sizeof(dictionnarywordsY[0])); i++) {
        if (strcmp(dictionnarywordsY[i], selectedword) == 0) {
            dokispoint[0]++;
            ChangePoemsWords();
            yurihappy = true;
            bouncedtwiceY = 2;
            yspeedyuri = -2;
        }   
    }
    for (int i = 0; i < (sizeof(dictionnarywordsN) / sizeof(dictionnarywordsN[0])); i++) {
        if (strcmp(dictionnarywordsN[i], selectedword) == 0) {
            dokispoint[1]++;
            ChangePoemsWords();
            natsukihappy = true;
            bouncedtwiceN = 2;
            yspeednatsuki = -2;
        }   
    }
    for (int i = 0; i < (sizeof(dictionnarywordsS) / sizeof(dictionnarywordsS[0])); i++) {
        if (strcmp(dictionnarywordsS[i], selectedword) == 0) {
            dokispoint[2]++;
            ChangePoemsWords();
            sayorihappy = true;
            bouncedtwiceS = 2;
            yspeedsayori = -2;
        }   
    }
    for (int i = 0; i < (sizeof(dictionnarywordsM) / sizeof(dictionnarywordsM[0])); i++) {
        if (strcmp(dictionnarywordsM[i], selectedword) == 0) {
            dokispoint[2]++;
            ChangePoemsWords();
        }   
    }
}

//Which doki's heart have you touched ?
void WhoHeartWon(void) {
	//Set other ints for dokis point for more comprehensive

	int SayorisPoints = dokispoint[2];
	int NatsukisPoints = dokispoint[1];
	int YurisPoints = dokispoint[0];

	if (SayorisPoints > (YurisPoints && NatsukisPoints)) {
		whowon = 3;
	}
	if (NatsukisPoints > (SayorisPoints && YurisPoints)) {
		whowon = 2;
	}
	if (YurisPoints > (NatsukisPoints && SayorisPoints)) {
		whowon = 1;
	}
}

void PrintWords(void) {
        FntPrint("                     %d/20\n",progressionwords - 1); 

        int i = 0; 

        while (i < 10) {
	        if (selectionword == i) {
	            FntPrint("\n\n         >%s", words[i]);
	        } else {
	            FntPrint("\n\n          %s", words[i]);
	        }
	        i++;
        }

}
