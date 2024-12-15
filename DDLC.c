#include "code/consnfunc.h" //This is the new "constants" files I was using, but this time there's everything in it

/*
    TO FIX : 
    
        Sometimes when not having memory card it doesn't want to load IG ?

        Why is there a -1 ERROR code ???

        Console : 

        Text not displayed correctly (color)
        Debug's text not displayed (seems to freeze when menu is debug doki)

    TO DO :
        Select hide away textbox

        

    Custom names ...

    Better font (1/2)

    V0.2.0

*/

int main(void) {
    init();    

    //SPU
    u_long spu_address;
    spuSetup(&spuSettings);
    // Init sound settings
    initSnd();

    for (u_short vag = 0; vag < VAG_NBR; vag++ ){
        vagsoundBank[vag].spu_address = setSPUtransfer(&vagsoundBank[vag]);
    }

    MemCardInit(0);
    MemCardStart();

    clearVRAM();

    LoadTexture(_binary_images_GUI_TEXTBOXLIL_tim_start, &textbox);
    
    // Init CD system
    CdInit();

    PadInit(0);                     // Initialize pad.  Mode is always 0

    // Init heap
    InitHeap((u_long *)ramAddr, sizeof(ramAddr));

    MemcardSavesInit();

    MemCardLoad();

    changeBG(0,true,false); //Loading warning image

    ChangeFontColor(254,254,254);

    while (1) {   

        XAPlayBack();

        pad = PadRead(0);

        ClearOTagR(ot[db], OTLEN);

        //Controlling CD Volume (for music)
        CdlATV cd_vol;
        
        //Memory function to create all of the required save files.
        if (createsave) {CreateSaveFunc(false, 0);}

        if (!loading) {controllerinput();}

        if (!mutevolume) {
            if (!multiplemusics) {cd_vol.val0 = cd_vol.val2 = currentmusicvolume;}
            else {cd_vol.val0 = currentmusicvolumemulti[0]; cd_vol.val2 = currentmusicvolumemulti[1];} //Only used in poem sharing, for good transition
        } else {
            cd_vol.val0 = cd_vol.val2 = 0;
        }

        CdMix(&cd_vol);

        if (oldline != currentline) {ChangeDialogueLine(); if (ispoemhere) {ispoemhere = false;} oldline = currentline;}

        DialogueTyping(); //Basically the most important feature in a visual novel. In dialogueMain

        DebugFuncs();

        if (oldscreen != currentscreen) {BeginScene(currentscreen);} //IF currentscreen has changed, trigger the BeginScene.

        frameforseed++; //Used for random, and some other things

        switch (currentscreen) {
            case 0: //Warning screen
                if (bgalpha != 128 && isunderstood == false) {
                    bgalpha += 2;
                } else {
                    if (framedelay == 1) {currentline++; showtextbox = true; framedelay--;}
                    else {
                        framedelay--;
                    }
                }

                MakeTextBox();

                makepoly(0);


                //FntPrint("\n\n\n\n\n\n%s" Test for bugging out text ?

                if(choices) {
                    choicesPrint();
                } else {
                    FntPrint("\n\n\n\n\n\n");
                } //Used to compensate so that we always see the text

                if (showtextbox) {FntPrint("%s\n\n\n\n\n%s",extraNs, dialoguedisplayed);} 

                if (isunderstood) {
                    if (changedbg == false) {
                        if (bgalpha != 0) {bgalpha -= 2;} else {
                            changeBG(1, true,false);
                            changedbg = true; 
                        }
                    } else {
                        if (bgalpha != 128) {bgalpha += 2;} else {
                            if (frameuntillaunch != 0) {frameuntillaunch--;} else {
                                currentscreen = 1;
                            }
                        }
                    }
                }
            break;

            case 1:

                if (ErrorCode != 0 && debugbuild && ErrorCode != -1) {FntPrint("Error ! Code : %d", ErrorCode);}

                //BG color, useful for opening
                setRGB0(&draw[0], fadeinNoutalpha, fadeinNoutalpha, fadeinNoutalpha); // set color for first draw area
                setRGB0(&draw[1], fadeinNoutalpha, fadeinNoutalpha, fadeinNoutalpha); // set color for second draw area

                if (deleteddokis[2] == false || memorycardmissing) {

                    if (!transitiontogame) {
                        if (menuintroframes == 1) {
                            if (currentchapter == 3) {ChangeMusic(22, true);} 
                            else {ChangeMusic(0, true);}
                        }

                        if (menuintroframes == 365) {ChangeFontColor(160,160,160);}

                        if (pad & PADR1 && pad & PADRup && pad & PADRright && pad & PADL2) {
                            currentscreen = 5;
                        }

                    } else {
                        if (fadeinNoutalpha > 1) {
                            fadeinNoutalpha -= 2;
                            if (currentmusicvolume > 0) {currentmusicvolume -= 2;}
                        } else {
                            fadeinNoutalpha = 0;
                            currentscreen = 2;
                        }
                    }

                    if (repeatsong == 0) {
                        ChangeMusic(1, true);
                    } else {repeatsong--;}

                    makepoly(2);

                    MenuOpening(); //I know this is not very optimized but I need this for the intro

                } else {

                    if (menuintroframes > 60 && menuintroframes < 380 || menuintroframes > 480) {
                        if (bgalpha != 128) {bgalpha++;}
                    } else {
                        if (bgalpha != 0) {bgalpha -= 2;}
                    }

                    if (repeatsong == 0) {
                        ChangeMusic(4, true);
                    } else {repeatsong--;}

                    makepoly(5);
                }

                menuintroframes++;
            break;

            case 2:
                if (ErrorCode != 0 && debugbuild && ErrorCode != -1) {FntPrint("Error! Code: %d, See source", ErrorCode);}

                if (bgalpha < 2) {blockedline = true;} else {blockedline = false;}

                loadBG(requestedimage, false, keepmusic); //Will not actually change BG, but will request it when the screen is black AND requestedimage is other value than -1

                if (!loading) {loadMusic(requestedsong, brutalchange);} else {loadMusic(sample, false);} //IF not loading, acting like loadBG whenever requestedsong is other value than -1. ELSE, Used to to do a fade out of the music !

                if (!fadein) {SpecialLinesActions();}

                if (currentchapter == 3) {RandomDialogue();}

                if (repeatsong == 0) {
                    if (cursong == 7 || cursong == 10 || cursong == 12 || cursong == 14 || cursong == 16 || cursong == 18) {cursong++;} //Basically every musics that has intro/loop
                    if (hasseensayorideath) {cursong = 21;}
                    ChangeMusic(cursong, true);
                } else {
                    repeatsong--;
                }

                if (abletoFFW && currentline < maxlineforFFW) {FFW = true;} else {FFW = false;}

                if (FFW && !loading) {
                    if (frameforseed % 5 == 1) {
                        if (indexdialogue > 0) {sprintf(dialoguedisplayed,dialogueline); indexdialogue = 0; dialogueEndText();} else {if (!blockedline) {currentline++;}}
                    }
                }

                if (!changingmusic) {if (currentmusicvolume < 128) {currentmusicvolume += 2;}} else {currentmusicvolume -= 2;}

                if (!loading) {
                    if (bgalpha == 128) {
                        if (fadein) {fadein = false; currentline++;}
                    }                        
                    if (imagealpha > -1) {
                        if (bgalpha > imagealpha) {
                            bgalpha -= 2;
                        }
                        if (bgalpha < imagealpha) {
                            bgalpha += 2;
                        }
                    }
                   if (!separatealphatextbox) {bgalphatextbox = imagealpha;} //If not, you can customise the textbox's alpha.
                }

                if (fadeout) {
                    blockedline = true;
                    if (imagealpha == 0) {
                        ChangeMusic(3,true);
                        currentscreen = 3;
                        fadeout = false;
                    } else {imagealpha--;}
                }

                if (!ispoemhere) {
                    //Core element incoming : T.E.X.T

                    //WAIT ! I won- Before that, we need to look if we're not in cg... Because we can't see properly so we would need to lower the textbox and all that shit
                    if (textboxlow) {FntPrint("\n");}

                    if(choices) {
                        choicesPrint();
                    } else {
                        FntPrint("\n\n\n\n\n\n");
                    } //Used to compensate so that we always see the text

                    if (!fadein && !loading && showtextbox) {FntPrint("%s\n\n%s\n\n\n%s",extraNs, nameshowed, dialoguedisplayed);} 

                } else {
                    FntPrint("%s",WrittenPoem);
                }

                MakeTextBox();

                makepoly(4);

                if (isinpause) {MenuBGMoving();}
            break;

            case 3: //Writing Poems !!
                makepoly(3);

                if (writingframe > 0) {writingframe--;}

                if (progressionwords == 21) {
                    transitiontogame = true; 
                    if (whowon == 0) {WhoHeartWon();}
                }

                if (repeatsong == 0) {
                    if (cursong == 2) {cursong++;}
                    ChangeMusic(cursong, true);
                } else {repeatsong--;}

                if (!transitiontogame) {
                    if (bgalpha != 128) {
                        bgalpha += 2;
                        fadeinNoutalpha += 2;
                    } else {beginwriting = true;}
                } else {
                    if (bgalpha > 1) {
                        bgalpha -= 2;
                        currentmusicvolume -= 2;
                    } else {
                        bgalpha = 0;
                        currentscreen = 2;
                        if (currentchapter != 3) { currentday++; }
                        ResetDialogue();
                    }
                }

                PrintWords();
            break; //Writing Poems !!

            case 4: //Cutscene Viewer

                if (fakeErrorCode != 0) {FntPrint("Error! Code: %d, See source", fakeErrorCode);}

                MakeTextBox();

                makepoly(4);

                DoCutscenes();

            break; //Cutscene Viewer

            case 5: //Debug screen

                DebugDokies();

                makepoly(4);

                MenuBGMoving();

                if (repeatsong == 0 && debugislooping) {
                    if (sample != 2) {ChangeMusic(sample, true);} else {ChangeMusic(3, true);}
                } else {repeatsong--;}

                if (fadeinNoutalpha < 255) {fadeinNoutalpha += 5;}

                DebugPrint();

                DebugController();

            break; //Debug screen

            case 6: //Video viewer
                if (strPlayDone) {
                    switch(strselection) {
                        case 0:

                        break; //Rick
                        case 1:

                        break; //End
                        case 2:
                            currentscreen = 1;
                        break; //Fake
                    }
                }
            break; //Video viewer
        }
        FntFlush(-1);              
        display();                 
    }
    return 0;
}