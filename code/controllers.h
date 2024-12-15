//Controller

TILE * PADL;                    // Tile primitives
TILE * TRIGGERL;
TILE * PADR;
TILE * TRIGGERR;
TILE * START, * SELECT;

int pad = 0;    

void SettingsFunc() {
    FntPrint("\n\n\n\n\n\n");
    if (selection == 1) {FntPrint("      >  Frame Text Speed : %d\n\n",frametextspeedfixed);} else {FntPrint("         Frame Text Speed : %d\n\n",frametextspeedfixed);}
    if (selection == 2) {FntPrint("      >  Save Progress\n\n");} else {FntPrint("         Save Progress\n\n");}
    if (selection == 3) {FntPrint("      >  Return\n\n");} else {FntPrint("         Return\n\n");}

    if (ErrorCode == 0) {
        if (selection == 4) {FntPrint("      >  V 0.2.0 DEMO\n\n");} else {FntPrint("         V 0.2.0 DEMO\n\n");}
        if (selection == 5) {FntPrint("      >  Made by Soeiz\n\n");} else {FntPrint("         Made by Soeiz\n\n");}
    } else {
        if (selection == 6) {FntPrint("      >  See Error\n\n");} else {FntPrint("         See Errors\n\n");}
        if (selection == 7) {FntPrint("      >  On the source\n\n");} else {FntPrint("         On the Source\n\n");}
    }
            
    if (pad & PADRdown) {
        if (!limitercross) {
            SpuSetKey(SPU_ON, SPU_00CH);
            switch(selection) {
                case 2:
                    CreateSaveFunc(true,0);
                break;
                case 3:
                    isinsettings = false;
                    LoadTexture(_binary_images_text_settingselected_tim_start, &newgame);
                    if (currentscreen == 1) {selection = 3;} else {selection = 4;}
                break;
            }
            limitercross = 1;
        }
    }

    if (pad & PADLright && selection == 1) {
            if (limitermenuselect == true) {return;}
            frametextspeedfixed++;
        limitermenuselect = true;
    }
    if (pad & PADLleft && selection == 1) {
        if (frametextspeedfixed > 1) {        
            if (limitermenuselect == true) {return;}
            frametextspeedfixed--;
        } else {frametextspeedfixed = 1;}
        limitermenuselect = true;
    }
    if (pad & PADLdown) {
        if (selection < 4) {
            if (limitermenuselect == true) {return;}
            selection++;
        } else {selection = 1;}
        limitermenuselect = true;
    }
    if (pad & PADLup) {
        if (selection > 0) {        
            if (limitermenuselect == true) {return;}
            selection--;
        } else {selection = 3;}
        limitermenuselect = true;
    }
    return;
}

void controllerinput(void) {
    if (choices && numberchoices > 1) {
        if (pad & PADLdown) {
            if (selectionchoices > 0) {        
                if (limitermenuselect == true) {return;}
                selectionchoices--;
            } else {selectionchoices = 4;}
            limitermenuselect = true;
            SpuSetKey(SPU_ON, SPU_01CH);
        }
        if (pad & PADLup) {
            if (selectionchoices < 5) {
                if (limitermenuselect == true) {return;}
                selectionchoices++;
            } else {selectionchoices = 1;}
            limitermenuselect = true;
            SpuSetKey(SPU_ON, SPU_01CH);
        }
    }

    if (ispoemhere && currentscreen != 2) {
        if (pad & PADRdown) {
            if (limitercross) {return;}
            ispoemhere = false;
            limitercross = true;
        }
    } //Mostly for debug purposes, but I'll not put it there


    if (pad & PADstart && pad & PADselect) {
        if (!limiterstart) {
            if (currentscreen < 3) {currentscreen++;} else {currentscreen = 1;}
            isinsettings = false;
            isinpause = false;
            limiterstart = true;
        }
    }

    switch(currentscreen) {
        case 0:
            if (pad & PADstart) {
                if (!limiterstart) {
                    if (isunderstood == false && currentline == 3) {
                        isunderstood = true;
                        choices = false;
                        sprintf(dialogueline, " ");
                        SpuSetKey(SPU_ON, SPU_00CH);
                        showtextbox = false;
                    }
                }
            }

            if (pad & PADRdown) {
                if (limitercross) {return;}
                if (currentline > 2 && currentscreen == 0) {return;}
                if (indexdialogue > 0) {sprintf(dialoguedisplayed,dialogueline); indexdialogue = 0; limitercross = true; return;}
                if (blockedline) {return;}
                currentline++;
                limitercross = true;
            }
        break;

        case 1:
            if (isinsettings) {SettingsFunc();}

            if (deleteddokis[2] == false || memorycardmissing) {
                if (pad & PADRdown) {
                    if (!limitercross) {
                        if (menuintroframes > 500) {
                            SpuSetKey(SPU_ON, SPU_00CH);
                            switch(selection) {
                                case 1:
                                    transitiontogame = true;
                                    currentday = 1;
                                break;
                                case 2:
                                    transitiontogame = true;
                                break;

                                case 3:
                                    isinsettings = true;
                                    selection = 1;
                                    LoadTexture(_binary_images_text_LoadGame_tim_start, &loadgame);
                                break;
                            }
                        }
                    }
                }
                if (menuintroframes > 500 && !transitiontogame) {
                    if (pad & PADLdown) {
                        if (selection < 4) {
                            if (limitermenuselect == true) {return;}
                            selection++;
                        } else {selection = 1;}
                        limitermenuselect = true;
                        SpuSetKey(SPU_ON, SPU_01CH);
                        if (selection == 1) {LoadTexture(_binary_images_text_newselected_tim_start, &newgame);} else {LoadTexture(_binary_images_text_new_tim_start, &newgame);}
                        if (selection == 2) {LoadTexture(_binary_images_text_LoadGameselected_tim_start, &loadgame);} else {LoadTexture(_binary_images_text_LoadGame_tim_start, &loadgame);}
                        if (selection == 3) {LoadTexture(_binary_images_text_settingselected_tim_start, &settings);} else {LoadTexture(_binary_images_text_setting_tim_start, &settings);}
                    }
                    if (pad & PADLup) {
                        if (selection > 0) {        
                            if (limitermenuselect == true) {return;}
                            selection--;
                        } else {selection = 3;}
                        limitermenuselect = true;
                        SpuSetKey(SPU_ON, SPU_01CH);
                        if (selection == 1) {LoadTexture(_binary_images_text_newselected_tim_start, &newgame);} else {LoadTexture(_binary_images_text_new_tim_start, &newgame);}
                        if (selection == 2) {LoadTexture(_binary_images_text_LoadGameselected_tim_start, &loadgame);} else {LoadTexture(_binary_images_text_LoadGame_tim_start, &loadgame);}
                        if (selection == 3) {LoadTexture(_binary_images_text_settingselected_tim_start, &settings);} else {LoadTexture(_binary_images_text_setting_tim_start, &settings);}
                    }
                }
            }
        break;

        case 2:

            if (isinsettings) {SettingsFunc();}

            if (pad & PADLdown) {
                if (selection < 5) {
                    if (limitermenuselect == true) {return;}
                    selection++;
                } else {selection = 1;}
                limitermenuselect = true;

                SpuSetKey(SPU_ON, SPU_01CH);
                if (selection == 1) {LoadTexture(_binary_images_text_MAINMENUSELECTED_tim_start, &settings);} else {LoadTexture(_binary_images_text_MAINMENU_tim_start, &settings);}
                if (selection == 2) {LoadTexture(_binary_images_text_SaveGameselected_tim_start, &savegame);} else {LoadTexture(_binary_images_text_SaveGame_tim_start, &savegame);}
                if (selection == 3) {LoadTexture(_binary_images_text_LoadGameselected_tim_start, &loadgame);} else {LoadTexture(_binary_images_text_LoadGame_tim_start, &loadgame);}
                if (selection == 4) {LoadTexture(_binary_images_text_settingselected_tim_start, &settings);} else {LoadTexture(_binary_images_text_setting_tim_start, &settings);}

            }
            if (pad & PADLup) {
                if (selection > 0) {        
                    if (limitermenuselect == true) {return;}
                    selection--;
                } else {selection = 4;}
                limitermenuselect = true;

                SpuSetKey(SPU_ON, SPU_01CH);
                if (selection == 1) {LoadTexture(_binary_images_text_MAINMENUSELECTED_tim_start, &settings);} else {LoadTexture(_binary_images_text_MAINMENU_tim_start, &settings);}
                if (selection == 2) {LoadTexture(_binary_images_text_SaveGameselected_tim_start, &savegame);} else {LoadTexture(_binary_images_text_SaveGame_tim_start, &savegame);}
                if (selection == 3) {LoadTexture(_binary_images_text_LoadGameselected_tim_start, &loadgame);} else {LoadTexture(_binary_images_text_LoadGame_tim_start, &loadgame);}
                if (selection == 4) {LoadTexture(_binary_images_text_settingselected_tim_start, &settings);} else {LoadTexture(_binary_images_text_setting_tim_start, &settings);}
            }

            if (pad & PADRdown) {
                if (limitercross) {return;}
                if (!isinpause) {
                    if (currentline > 2 && currentscreen == 0) {return;}
                    if (indexdialogue > 0) {sprintf(dialoguedisplayed,dialogueline); indexdialogue = 0; limitercross = true; return;}
                    if (choices == false) {
                        currentline++;
                        limitercross = true;
                    } else {
                        if (choicereason == 2) {dokipoem = selectionchoices;}
                        lastresponse = selectionchoices;
                        currentline++;
                        SpuSetKey(SPU_ON, SPU_00CH);
                        choices = false;
                    }
                } else {
                    switch(selection) {
                        case 1:
                            ResetGame(false);
                        break;
                        case 2:
                            CreateSaveFunc(true,0);
                        break;
                        case 3:

                        break;
                        case 4:
                            isinsettings = true;
                        break;
                    }
                }
                limitercross = true;
            }

            if (pad & PADstart) {
                if (!limiterstart) {
                    if (!unabletopause) {isinpause = !isinpause;}
                    if (currentchapter == 3) {return;}
                    if (isinpause) {
                        showtextbox = false;
                        fadeinNoutalpha = 255;
                        ChangeFontColor(160,160,160);
                        isbghere = false;
                    } else {
                        ChangeFontColor(255,255,255);
                        isbghere = true;
                        showtextbox = true;
                    }
                }
            }
            if (pad & PADRup) {
                abletoFFW = true;
            } else {abletoFFW = false;}

        break;

        case 3:
            if (pad & PADRdown) {
                if (!limitercross) {
                    if (beginwriting && progressionwords < 21 && writingframe == 0) {
                        SpuSetKey(SPU_ON, SPU_00CH);
                        DistributePoint();
                        progressionwords++;
                        writingframe = 5;
                    }
                } 
            }
            if (!transitiontogame) {
                if (pad & PADLdown) {
                    if (selectionword < 10) {
                        if (limiterselectword) {return;}
                        selectionword++;
                    } else {selectionword = 0;}
                    limiterselectword = true;
                }
                if (pad & PADLup) {
                    if (selectionword >= 0) {
                        if (limiterselectword) {return;}
                        selectionword--;
                    } else {selectionword = 9;}
                    limiterselectword = true;
                }
            }
        break;
        case 4:
            if (cutsceneNum == 0 && pad & PADstart) {
                ResetGame(false);
            }
        break;
    }
    if (pad & PADstart) {limiterstart = true;} else {limiterstart = false;}

    if (pad & PADRdown) {limitercross = true;} else {limitercross = false;}

    if ((pad & PADLdown || pad & PADLup) && (choices || currentscreen == 1 && menuintroframes > 365)) {

    }

    if (!(pad & PADLdown || pad & PADLup || pad & PADLright || pad & PADLleft)) {
        limitermenuselect = false;
        limiterselectword = false;
    }
}
