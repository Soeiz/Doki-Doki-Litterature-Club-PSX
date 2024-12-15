//Serie of specific functions to detect any anomalies during gameplay, to prevent crash or soft-lock.
//Also contains debug mode
	
int debugimage = 0;
int debugsound = 0;
bool debugmono = false;
bool debugislooping = true;

int debugselectionmax = 6;

int debugdoki = 0;
int debugLpose = 0;
int debugRpose = 0;
char debughead[1] = "A";
int debugheadselect = 1;

char bodyArgument[3] = "11A";

int debugcurrentchapter = 1;

int debugcurrentday = 1;

int debugcurrentscreen = 0;

int debugmenu = 1;

int imageselectionmax = 14;

bool debugbuild = true;

void DebugFuncs() {
    //Debugger to know if there's too much images being loaded on the same time (always mean that we're softlocked)
    if (imagedebugger > 0) {
        if (debuggerframes < 0) {
            imagedebugger--; debuggerframes = 60;
        } else {
            debuggerframes--;
        }
    }
    if (imagedebugger > 2) {
        ResetGame(false);
        ErrorCode = 13;
    }

    if (fadeinNoutalpha < 5 && currentscreen == 1 && deleteddokis[2] == false && menuintroframes > 60) {
        if (transitionlimitframes != 0) {transitionlimitframes--;} else {ResetGame(false); ErrorCode = 14; BeginScene(1);}
    } else {transitionlimitframes = 300;}
    //Does NOT recover from a freeze, just a softlock


    //Other things such as debugging texts

    //int realsoundlength = (soundBank.samples[sample].end - soundBank.samples[sample].start);

    //int test = realsoundlength / 1.2;

    /*for(int i=0; i<fileCount[currentCard]; i++) {
        FntPrint(" %s\n", fileList[currentCard][i].name);
    } */

    if (debugbuild) {FntPrint("%d %d", cursong, currentline);}
}

void DebugDokies(void) {
    if (bgalpha != 128) {bgalpha = 128;}

    yurivisible = false;
    natsukivisible = false;
    monikavisible = false;
    sayorivisible = false;

    if (debugmenu == 3) {
        switch(debugdoki) {
            case 1:
                monikavisible = true;
                MovVectormonibodyL.vx = 16;
                MovVectormonibodyL.vy = 5;
            break;
            case 2:
                natsukivisible = true;
                MovVectornatsubodyL.vx = 18;
                MovVectornatsubodyL.vy = 7;
            break;
            case 3:
                sayorivisible = true;
                sayoposZ = 2;
                sayoposY = -2;
                MovVectorsayobodyL.vx = 17;
                MovVectorsayobodyL.vy = 5;
            break;
            case 4:
                yurivisible = true;
                MovVectoryuribodyL.vx = 17;
                MovVectoryuribodyL.vy = 5;
            break;
        }
    }
}

void DebugChangeDokiBody(void) {

    // I have enough of this shit, it doesn't want to "debughead = alphabet[debugheadselect]; so I do that. Sorry."

    switch(debugheadselect) {
        case 1:
            debughead[0] = 'A';
        break;
        case 2:
            debughead[0] = 'B';
        break;
        case 3:
            debughead[0] = 'C';
        break;
        case 4:
            debughead[0] = 'D';
        break;
        case 5:
            debughead[0] = 'E';
        break;
        case 6:
            debughead[0] = 'F';
        break;
        case 7:
            debughead[0] = 'G';
        break;
        case 8:
            debughead[0] = 'H';
        break;
        case 9:
            debughead[0] = 'I';
        break;
        case 10:
            debughead[0] = 'J';
        break;
        case 11:
            debughead[0] = 'K';
        break;
        case 12:
            debughead[0] = 'L';
        break;
        case 13:
            debughead[0] = 'M';
        break;
        case 14:
            debughead[0] = 'N';
        break;
        case 15:
            debughead[0] = 'O';
        break;
        case 16:
            debughead[0] = 'P';
        break;
        case 17:
            debughead[0] = 'Q';
        break;
        case 18:
            debughead[0] = 'R';
        break;
        case 19:
            debughead[0] = 'S';
        break;
        case 20:
            debughead[0] = 'T';
        break;
        case 21:
            debughead[0] = 'U';
        break;
        case 22:
            debughead[0] = 'V';
        break;
        case 23:
            debughead[0] = 'W';
        break;
        case 24:
            debughead[0] = 'X';
        break;
        case 25:
            debughead[0] = 'Y';
        break;
        case 26:
            debughead[0] = 'Z';
        break;
    }
    

    sprintf(bodyArgument, "%d%d%s", debugLpose, debugRpose, debughead);

    changedokibodies(debugdoki, bodyArgument);

}

void DebugPrint(void) {
    FntPrint("        Debug scene !\n\n");

    FntPrint("Current bugs : Using debug (V0.2)\n");

    FntPrint("Console bugs : Yes (see source)\n\n");

    if (selection == 1) {FntPrint("> Change menu\n");} else {FntPrint("  Change menu\n");}

    switch(debugmenu) {
        case 1:
            FntPrint("Change var :\n");

            if (selection == 2) {FntPrint("> CurrentScreen : %d\n", debugcurrentscreen);} else {FntPrint("  CurrentScreen : %d\n", debugcurrentscreen);}
            if (selection == 3) {FntPrint("> CurrentChapter : %d\n", debugcurrentchapter);}else {FntPrint("  CurrentChapter : %d\n", debugcurrentchapter);}
            if (selection == 4) {FntPrint("> Currentday : %d\n", debugcurrentday);} else {FntPrint("  Currentday : %d\n", debugcurrentday);}
            if (debugcurrentscreen == 6) {
                if (selection == 5) {
                    FntPrint("> Current Video : %d\n\n", strselection);
                } 
                else {
                    FntPrint("  Current Video : %d\n\n", strselection);
                }
            }
            else {
                if (selection == 5) {
                    FntPrint("> Who won : %d\n\n", whowon);
                }
                else {
                  FntPrint("  Who won : %d\n\n", whowon);
                }
            }
        

            if (selection == 6 && debugmenu != 2 || selection == 7 && debugmenu == 2) {FntPrint("> Save changes (will exit debug)\n");} else {FntPrint("  Save changes (will exit debug) \n");}
        break;

        case 2:
            FntPrint("Debug features :\n");

            if (selection == 2) {FntPrint("> CurrentMusic : %d, cursor %d, length %d (stop earlier)\n", sample,soundBank.samples[sample].cursor, soundBank.samples[sample].end - soundBank.samples[sample].start);} else {FntPrint("  CurrentMusic : %d\n", sample);}
            if (selection == 3) {FntPrint("> CurrentSound : %d\n", debugsound);} else {FntPrint("  CurrentSound : %d\n", debugsound);}
            if (selection == 4) {FntPrint("> CurrentImage : %d\n\n", debugimage);} else {FntPrint("  CurrentImage : %d\n\n", debugimage);}
            if (selection == 5) {FntPrint("> Left Volume : %d\n", currentmusicvolumemulti[0]);} else {FntPrint("  Left Volume : %d\n", currentmusicvolumemulti[0]);}
            if (selection == 6) {FntPrint("> Right Volume : %d\n", currentmusicvolumemulti[1]);} else {FntPrint("  Right Volume : %d\n", currentmusicvolumemulti[1]);}
            if (selection == 7) {FntPrint("> is looping : %d\n", debugislooping);} else {FntPrint("  is looping : %d\n", debugislooping);}

        break;

        case 3:
            FntPrint("Character changing :\n");

            if (selection == 2) {FntPrint("> debugdoki : %d\n", debugdoki);} else {FntPrint("  debugdoki : %d\n", debugdoki);}
            if (selection == 3) {FntPrint("> Left pose : %d\n", debugLpose);} else {FntPrint("  Left pose : %d\n", debugLpose);}
            if (selection == 4) {FntPrint("> Right pose : %d\n", debugRpose);} else {FntPrint("  Right pose : %d\n", debugRpose);}
            if (selection == 5) {FntPrint("> Head pose : %s\n", debughead);} else {FntPrint("  Head pose : %s\n", debughead);}
        break;
    }
}

void DebugController(void) {//Too long to put it on controllers.h
    if (pad & PADstart && frameforseed % 11 == 1 && selection == 1) {
        if (debugmenu < 3) {
            debugmenu++;
            switch(debugmenu) {
                case 2:
                    debugselectionmax = 7;
                    LoadAllTextures();
                    multiplemusics = true;
                break;
                case 3:
                    LoadAllTexturesIG();
                    debugselectionmax = 5;
                break;
            }
        } else {
            debugmenu = 1;
            debugselectionmax = 6;
            LoadAllTextures();
        }
    }

    if (pad & PADLdown) {
        if (selection < debugselectionmax + 1) {
            if (limitermenuselect == true) {return;}
            selection++;
        } else {selection = 1;}
        limitermenuselect = true;
        SpuSetKey(SPU_ON, SPU_01CH);
    }

    if (pad & PADLup) {
        if (selection > 0) {        
            if (limitermenuselect == true) {return;}
            selection--;
        } else {selection = debugselectionmax;}
        limitermenuselect = true;
        SpuSetKey(SPU_ON, SPU_01CH);
    }

    switch(debugmenu) {
        case 1:
            if (pad & PADLright) {
                if (limiterselectword) {return;}
                switch(selection) {
                    case 2:
                        if (debugcurrentscreen < 6) {
                            debugcurrentscreen++;
                        } else {
                            debugcurrentscreen = 0;
                        }
                    break;

                    case 3:
                        if (debugcurrentchapter < 3) {
                            debugcurrentchapter++;
                        } else {
                            debugcurrentchapter = 0;
                        }
                    break;

                    case 4:
                        if (debugcurrentday < 3) {
                            debugcurrentday++;
                        } else {
                            debugcurrentday = 0;
                        }
                    break;

                    case 5:
                        if (debugcurrentscreen != 6) {
                            if (whowon < 3) {
                                whowon++;
                            } else {
                                whowon = 0;
                            }
                        } else {
                            if (strselection < 3) {
                                strselection++;
                            } else {
                                strselection = 0;
                            }
                        }
                    break;
                }
                limiterselectword = true;
            }

            if (pad & PADLleft) {
                if (limiterselectword) {return;}
                switch(selection) {
                    case 2:
                        if (debugcurrentscreen > 0) {
                            debugcurrentscreen--;
                        } else {
                            debugcurrentscreen = 6;
                        }
                    break;
                    case 3:
                        if (debugcurrentchapter > 0) {
                            debugcurrentchapter--;
                        } else {
                            debugcurrentchapter = 3;
                        }
                    break;
                    case 4:
                        if (debugcurrentday > 0) {
                            debugcurrentday--;
                        } else {
                            debugcurrentday = 3;
                        }
                    break;
                    case 5:
                        if (debugcurrentscreen != 6) {
                            if (whowon > 0) {
                                whowon--;
                            } else {
                                whowon = 3;
                            }
                        } else {
                            if (strselection > 0) {
                                strselection--;
                            } else {
                                strselection = 3;
                            }
                        }
                    break;
                }
                limiterselectword = true;
            }

            if (pad & PADstart) {
                if (frameforseed % 11 == 1) {
                    switch(selection) {
                        case 6:
                            currentscreen = debugcurrentscreen;
                            currentday = debugcurrentday;
                            currentchapter = debugcurrentchapter;
                        break;
                        case 5:
                            ispoemhere = true;
                        break;
                    } 
                }
            }

        break;

        case 2:
            if (pad & PADLright) {
                if (limiterselectword) {return;}
                switch(selection) {
                    case 2:
                        if (sample < 24) {
                            sample++;
                        } else {
                            sample = 0;
                        }
                        ChangeMusic(sample,true);
                    break;

                    case 3:
                        if (debugsound < 24) {
                            debugsound++;
                        } else {
                            debugsound = 0;
                        }
                        SpuSetKey(SPU_ON, debugsound);
                    break;

                    case 4:
                        if (debugimage < imageselectionmax) {
                            debugimage++;
                        } else {
                            debugimage = -1;
                        }
                    break;
                    case 5:
                        if (currentmusicvolumemulti[0] < 128) {
                            currentmusicvolumemulti[0]++;
                        }
                    break;
                    case 6:
                        if (currentmusicvolumemulti[1] < 128) {
                            currentmusicvolumemulti[1]++;
                        }
                    break;
                    case 7:
                        debugislooping = !debugislooping;
                    break;
                }
                if (selection != 5 && selection != 6) {limiterselectword = true;}
            }

            if (pad & PADLleft) {
                if (limiterselectword) {return;}
                switch(selection) {
                    case 2:
                        if (sample > 0) {
                            sample--;
                        } else {
                            sample = 24;
                        }
                        ChangeMusic(sample,true);
                    break;
                    case 3:
                        if (debugsound > 0) {
                            debugsound--;
                        } else {
                            debugsound = 24;
                        }
                        SpuSetKey(SPU_ON, debugsound);
                    break;
                    case 4:
                        if (debugimage > -1) {
                            debugimage--;
                        } else {
                            debugimage = imageselectionmax;
                        }
                    break;
                    case 5:
                        if (currentmusicvolumemulti[0] > 0) {
                            currentmusicvolumemulti[0]--;
                        }
                    break;
                    case 6:
                        if (currentmusicvolumemulti[1] > 0) {
                            currentmusicvolumemulti[1]--;
                        }
                    break;
                    case 7:
                        debugislooping = !debugislooping;
                    break;
                }
                if (selection != 5 && selection != 6) {limiterselectword = true;}

                if (sample >= 10 && sample <= 19) {debugmono = true;} else {debugmono = false;} //Used to control left or right sound
            }

            if (pad & PADstart) {
                if (frameforseed % 11 == 1) {
                    switch(selection) {
                        case 4:
                            if (debugimage == -1) {
                                isbghere = false;
                            } else {
                                changeBG(debugimage, true ,false);
                                ChangeBGdetails(4);
                                isbghere = true; 
                                bgalpha = 128;
                            }
                        break;
                    }
                }
            }

        break;

        case 3:
            DebugChangeDokiBody();
            if (pad & PADLright) {
                if (limiterselectword) {return;}
                switch(selection) {
                    case 2:
                        if (debugdoki < 4) {debugdoki++;} else {debugdoki = 0;}
                    break;
                    case 3:
                        if (debugLpose < 4) {debugLpose++;} else {debugLpose = 0;}
                    break;
                    case 4:
                        if (debugRpose < 4) {debugRpose++;} else {debugRpose = 0;}
                    break;
                    case 5:
                        if (debugheadselect < 27) {debugheadselect++;} else {debugheadselect = 0;}
                    break;
                }
                limiterselectword = true;
            }
            if (pad & PADLleft) {
                if (limiterselectword) {return;}
                switch(selection) {
                    case 2:
                        if (debugdoki > 0) {debugdoki--;} else {debugdoki = 4;}
                    break;
                    case 3:
                        if (debugLpose > 0) {debugLpose--;} else {debugLpose = 4;}
                    break;
                    case 4:
                        if (debugRpose > 0) {debugRpose--;} else {debugRpose = 4;}
                    break;
                    case 5:
                        if (debugheadselect > 0) {debugheadselect--;} else {debugheadselect = 26;}
                    break;
                }
                limiterselectword = true;
            }

        break;
    }
    if (!(pad & PADstart)) {limiterstart = false;}

    if (!(pad & PADLdown || pad & PADLup || pad & PADLright || pad & PADLleft)) {
        limitermenuselect = false;
        limiterselectword = false;
    }
}