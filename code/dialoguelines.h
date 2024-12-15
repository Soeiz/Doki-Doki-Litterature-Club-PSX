void RandomDialogue() {
	if (!indialogue) {
		if (showtextbox) {showtextbox = false;}
		if (randomwait == -1) {
			Ran(300);
			randomwait = 600 + RAN;
			Ran(20);
			switch(RAN) {
				case 10:
					if (savespresent[0]) {
						randomdialogue = 121; //Rainbow 6
						savespresent[0] = false; //So that it won't show up twice
						return;
					} else {Ran(20);}

					if (savespresent[1]) {
						randomdialogue = 122; //Gran Turismo
						savespresent[1] = false; //So that it won't show up twice
						return;
					} else {Ran(20);}

					if (savespresent[2]) {
						randomdialogue = 123; //Crash Bandicoot
						savespresent[2] = false; //So that it won't show up twice
						return;
					} else {Ran(20);}

					if (savespresent[3]) {
						randomdialogue = 124; //Catlevania - Symphony of the Night
						savespresent[3] = false; //So that it won't show up twice
						return;
					} else {Ran(20);}

					if (savespresent[4]) {
						randomdialogue = 125; //Tekken 3
						savespresent[4] = false; //So that it won't show up twice
						return;
					} else {Ran(20);}

					if (savespresent[5]) {
						randomdialogue = 126; //Gran Turismo 2
						savespresent[5] = false; //So that it won't show up twice
						return;
					} else {Ran(20);}
				break;
				default:
					randomdialogue = RAN;	
				break;
			}
		}
		if (randomwait == 0) {
			if (!showtextbox) {showtextbox = true;}
			indialogue = true;
			randomwait = -1;
			currentline = 0;
		} else {randomwait--;}
	}
}

void ChangeDialogueLine(void) {
	/*
	int i = 0;
	char temp[5][100] = {"","","","",""};
    while (i < 4) {
    	sprintf(temp[i], dialoguehistory[i]);

    	sprintf(dialoguehistory[i + 1], temp[i]);

    	i++;
    }
	*/
	sprintf(dialoguehistory[0], dialoguedisplayed);
	
	if (strlen(dialoguehistory[0]) > 50) {
		int deleter = strlen(dialoguehistory[0]) - 50;

		while (deleter > 0) {
			dialoguehistory[0][deleter + 50] = ' ';
			deleter--;
		}

		dialoguehistory[0][51] = '.';
		dialoguehistory[0][52] = '.';
		dialoguehistory[0][53] = '.';
	}


	for(int i = 0; i < 200; i++) {
		dialoguedisplayed[i] = ' ';
	} 

	finishedwriting = false;
	switch(currentscreen) {
		case 0:
			if (!memorycardmissing) {
				switch(currentline) {
					case 1 :
						sprintf(dialogueline, "This game is not suitable for children or those who are easily disturbed.");
					break;
					case 2 :
						sprintf(dialogueline, "Individuals suffering from anxiety or depression may not have a safe experience playing this game. For content warnings, please visit: http://ddlc.moe/warning.html");
					break;
					case 3 :
						sprintf(dialogueline, "By playing Doki Doki Litterature Club, you agree that you are at least 13 years of age, and you consent to your exposure of highly disturbing content.");
					break;
				}
			} else {
				switch(currentline) {
					case 1 :
						sprintf(dialogueline, "It appears that you do not have any inserted memory cards in your playstation console.");
					break;
					case 2 :
						sprintf(dialogueline, "You should insert a memory card in the A Slot of your console. Without it, you will not be able to save, load, or play past act 3 of the game.");
					break;
					case 3 :
						sprintf(dialogueline, "By playing Doki Doki Litterature Club, you agree that you are at least 13 years of age, and you consent to your exposure of highly disturbing content.");
					break;
				}

			}
		break;
		case 2:
			switch(currentchapter) {
				case 1 :
					if (hasseensayorideath) {
						switch(currentline) {
							case 1 :
								isbghere = false;
								showtextbox = true;
								sprintf(dialogueline, "...");
							break;
							case 2 :
								isbghere = true;

                                MovVectorsayoH.vy += 10;
                                MovVectorsayoH.vx -= 10;

                                ScaleVectorsayoH.vx = ONE;
                                ScaleVectorsayoH.vy = ONE;
                                ScaleVectorsayoH.vz = ONE;

                                ScaleVectorbg.vx = ONE;
                                ScaleVectorbg.vy = ONE;
                                ScaleVectorbg.vz = ONE;

                                MovVectorbg.vy -= 40;
                                MovVectorbg.vx += 20;

                                VertPosbg2[0].vx = 0;
                                VertPosbg2[1].vx = 0;
                                VertPosbg2[2].vx = 100;
                                VertPosbg2[3].vx = 100;
                                VertPosbg2[0].vy = -62;
                                VertPosbg2[1].vy = 63;
                                VertPosbg2[2].vy = -62;
                                VertPosbg2[3].vy = 63;

                                ChangeFontColor(255,255,255);

                                ErrorCode = 0;
                                
                                showname = false;
								sprintf(dialogueline, "What the hell...?");
							break;
							case 3 :
								sprintf(dialogueline, "What the hell??");
							break;
							case 4 :
								sprintf(dialogueline, "Is this a nightmare?");
							break;
							case 5 :
								sprintf(dialogueline, "It...has to be.");
							break;
							case 6 :
								sprintf(dialogueline, "This isn't real.");
							break;
							case 7 :
								sprintf(dialogueline, "There's no way this can be real.");
							break;
							case 8 :
								sprintf(dialogueline, "Sayori wouldn't do this.");
							break;
							case 9 :
								sprintf(dialogueline, "Everything was normal up until a few days ago.");
							break;
							case 10 :
								sprintf(dialogueline, "That's why I can't believe what my eyes are showing me...!");
							break;
							case 11 :
								imagealpha = 0;
								showtextbox = false;
								bgalpha--;
								blockedline = true;
							break;
							case 12 :
								showtextbox = true;
								blockedline = false;
								sprintf(dialogueline, "I suppress the urge to vomit.");
							break;
							case 13 :
								sprintf(dialogueline, "Just yesterday...");
							break;
							case 14 :
								sprintf(dialogueline, "I told Sayori I would be there for her.");
							break;
							case 15 :
								sprintf(dialogueline, "I told her I know what's best, and that everything will be okay.");
							break;
							case 16 :
								sprintf(dialogueline, "Then why...?");
							break;
							case 17 :
								sprintf(dialogueline, "Why would she do this...?");
							break;
							case 18 :
								sprintf(dialogueline, "How could I be so helpless?");
							break;
							case 19 :
								sprintf(dialogueline, "What did I do wrong?");
							break;
							case 20 :
								(sayoriconfess) ? sprintf(dialogueline, "Confessing to her...") : sprintf(dialogueline, "Turning down her confession...");
							break;
							case 21 :
								(sayoriconfess) ? sprintf(dialogueline, "I shouldn't have confessed to her.") : sprintf(dialogueline, "That has to have been what pushed her over the edge.");
							break;
							case 22 :
								(sayoriconfess) ? sprintf(dialogueline, "That's not what Sayori needed at all.") : sprintf(dialogueline, "Her agonized scream still echoes in my ears.");
							break;
							case 23 :
								(sayoriconfess) ? sprintf(dialogueline, "Then why did I confess to her, and make her feel even worse?") : sprintf(dialogueline, "Why did I do that to her when she needed me the most?");
							break;
							case 24 :
								sprintf(dialogueline, "Why was I so selfish?");
							break;
							case 25 :
								sprintf(dialogueline, "This is my fault--!");
							break;
							case 26 :
								sprintf(dialogueline, "My swarming thoughts keep telling me everything I could have done to prevent this.");
							break;
							case 27 :
								sprintf(dialogueline, "If I just spent more time with her.");
							break;
							case 28 :
								sprintf(dialogueline, "Walked her to school.");
							break;
							case 29 :
								(sayoriconfess) ? sprintf(dialogueline, "And remained friends with her, like it always has been...") : sprintf(dialogueline, "And gave her what I know she wanted out of our relationship...");
							break;
							case 30 :
								sprintf(dialogueline, "...Then I could have prevented this.");
							break;
							case 31 :
								sprintf(dialogueline, "I know I could have prevented this!");
							break;
							case 32 :
								sprintf(dialogueline, "Screw the Literature Club.");
							break;
							case 33 :
								sprintf(dialogueline, "Screw the festival.");
							break;
							case 34 :
								sprintf(dialogueline, "I just...lost my best friend.");
							break;
							case 35 :
								sprintf(dialogueline, "Someone I grew up with.");
							break;
							case 36 :
								sprintf(dialogueline, "She's gone forever now.");
							break;
							case 37 :
								sprintf(dialogueline, "Nothing I do can bring her back.");
							break;
							case 38 :
								sprintf(dialogueline, "This isn't some game where I can reset and try something different.");
							break;
							case 39 :
								sprintf(dialogueline, "I had only one chance, and I wasn't careful enough.");
							break;
							case 40 :
								sprintf(dialogueline, "And now I'll carry this guilt with me until I die.");
							break;
							case 41 :
								sprintf(dialogueline, "Nothing in my life is worth more than hers...");
							break;
							case 42 :
								sprintf(dialogueline, "But I still couldn't do what she needed from me.");
							break;
							case 43 :
								sprintf(dialogueline, "And now...");
							break;
							case 44 :
								sprintf(dialogueline, "I can never take it back.");
							break;
							case 45 :
								sprintf(dialogueline, "Never.");
							break;
							case 46 :
								sprintf(dialogueline, "Never.");
							break;
							case 47 :
								sprintf(dialogueline, "Never.");
							break;
							case 48 :
								sprintf(dialogueline, "Never.");
							break;
							case 49 :
								sprintf(dialogueline, "Never....");
							break;
							case 50 :
								ResetGame(false);
								currentscreen = 1;
								currentchapter = 2;
							break;
						}
						return;
					}
					switch(currentday) {
						case 1:
							if (deleteddokis[0] == false || memorycardmissing) {
								switch(currentline) {
									case 1 :
										showtextbox = true;
										showname = true;
										sprintf(nameshowed, "???");
										sprintf(dialogueline, "\"Heeeeeeyyy!!\"");
									break;
									case 2 :
										showname = false;
										ispoemhere = true;
										sprintf(dialogueline, "I see an annoying girl running toward me from the distance, waving her arms in the air like she's totally oblivous to any attention she might draw to herself.");
									break;
									case 3 :
										//ispoemhere = false;
										sprintf(dialogueline, "That girl is Sayori, my neighbor and good friend since we were children.");
									break;
									case 4 :
										sprintf(dialogueline, "You know, the kind of friend you'd never see yourself making today, but it just kind of works out because you've known each other for so long?");
									break;
									case 5 :
										sprintf(dialogueline, "We used to walk to school together on days like this, but starting around high school she would oversleep more and more frequently, and I would get tired of waiting up.");
									break;
									case 6 :
										sprintf(dialogueline, "But if she's going to chase after me like this, I almost feel better off running away.");
									break;
									case 7 :
										sprintf(dialogueline, "However, I just sigh and idle in front of the crosswalk and let Sayori catch up to me.");
									break;
									case 8 :
										sayorivisible = true;
										changedokibodies(3,"22P");
										showname = true;
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Haaahhh...haaahhh...\"");
									break;
									case 9:
										sprintf(dialogueline, "\"I overslept again!\"");
									break;
									case 10:
										currentspeaker = 3;
										sprintf(dialogueline, "\"But I caught you this time!\"");
									break;
									case 11:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Maybe, but only because I decided to stop and wait for you.\"");
									break;
									case 12:
										sayoposY = -1;
										changedokibodies(3, "11M");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Eeehhhhh, you say that like you were thinking about ignoring me!\"");
									break;
									case 13:
										sprintf(dialogueline, "\"That's mean, MC !\"");
									break;
									case 14:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Well, if people stare at you for acting weird then I don't want them to think we're a couple or something.\"");
									break;
									case 15:
										sayoposY = 0;
										changedokibodies(3,"11A");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Fine, fine.\"");
									break;
									case 16:
										sprintf(dialogueline, "\"But you did wait for me, after all.\"");
									break;
									case 17:
										sprintf(dialogueline, "\"I guess you don't have it in you to be mean even if you want to!\"");
									break;
									case 18:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Whatever you say, Sayori...\"");
									break;
									case 19:
										changedokibodies(3,"11Q");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Ehehe!\"");
									break;
									case 20:
										sayorivisible = false;
										showname = false;
										sprintf(dialogueline, "We cross the street together and make our way to school.");
									break;
									case 21:
										sprintf(dialogueline, "As we draw near, the streets become increasingly speckled with other students making their daily commute.");
									break;
									case 22:
										sayorivisible = true;
										changedokibodies(3,"21A");
										showname = true;
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"By the way, MC...\"");
									break;
									case 23:
										sprintf(dialogueline, "\"Have you decided on a club to join yet?\"");
									break;
									case 24:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"A club?\"");
									break;
									case 25:
										sprintf(dialogueline, "\"I told you already, I'm really not interested in joining any clubs.\"");
									break;
									case 26:
										sprintf(dialogueline, "\"I haven't been looking, either.\"");
									break;
									case 27:
										sayoposY = -1;
										changedokibodies(3,"22H");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Eh? That's not true!\"");
									break;
									case 28:
										sprintf(dialogueline, "\"You told me you would join a club this year!\"");
									break;
									case 29:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Did I...?\"");
									break;
									case 30:
										showname = false;
										sprintf(dialogueline, "I'm sure it's possible that I did, in one of our many conversations where I dismissively go along with whatever she's going on about.");
									break;
									case 31:
										sprintf(dialogueline, "Sayori likes to worry a little too much about me, when I'm perfectly content just getting by on the average while spending my free time on games and anime.");
									break;
									case 32:
										showname = true;
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Uh-Huh!\"");
									break;
									case 33:
										sprintf(dialogueline, "\"I was talking about how I'm worried that you won't learn how to socialize or have any skills before college.\"");
									break;
									case 34:
										sprintf(dialogueline, "\"Your happiness is really important to me, you know!\"");
									break;
									case 35:
										sprintf(dialogueline, "\"And I know you're happy now, but I'd die at the thought of you becoming a NEET in a few years because you're not used to the real world!\"");
									break;
									case 36:
										changedokibodies(3,"22G");
										sprintf(dialogueline, "\"You trust me, right?\"");
									break;
									case 37:
										sprintf(dialogueline, "\"Don't make me keep worrying about you...\"");
									break;
									case 38:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Alright, alright...\"");
									break;
									case 39:
										sprintf(dialogueline, "\"I'll look at a few clubs if it makes you happy.\"");
									break;
									case 40:
										sprintf(dialogueline, "\"No promises, though.\"");
									break;
									case 41:
										changedokibodies(3,"11H");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Will you at least promise me you'll try a little?\"");
									break;
									case 42:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Yeah, I guess I'll promise you that.\"");
									break;
									case 43:
										sayoposY = 0;
										changedokibodies(3,"22R");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Yaay!!\"");
									break;
									case 44:
										showname = false;
										sprintf(dialogueline, "Why do I let myself get lectured by such a carefree girl?");
									break;
									case 45:
										sprintf(dialogueline, "More than that, I'm surprised I even let myself relent to her.");
									break;
									case 46:
										sprintf(dialogueline, "I guess seeing her worry so much about me makes me want to ease her mind at least a little bit - even if she does exaggerate everything inside of her head.");
									break;
									//Loading Classroom
									case 48:
										sayorivisible = false;
										sprintf(dialogueline, "The school day is as ordinary as ever, and it's over before I know it.");
									break;
									case 49:
										sprintf(dialogueline, "After I pack up my things, I stare blankly at the wall, looking for an ounce of motivation.");
									break;
									case 50:
										showname = true;
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Clubs...\"");
									break;
									case 51:
										showname = false;
										sprintf(dialogueline, "Sayori wants me to check out some clubs.");
									break;
									case 52:
										sprintf(dialogueline, "I guess I have no choice but to start with the anime club...");
									break;
									case 53:
										showname = true;
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Hellooo?\"");
									break;
									case 54:
										sayorivisible = true;
										changedokibodies(3,"11A");
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Sayori...?\"");
									break;
									case 55:
										showname = false;
										sprintf(dialogueline, "Sayori must have come into the classroom while I was spacing out.");
									break;
									case 56:
										sprintf(dialogueline, "I look around and realize that I'm the only one left in the classroom.");
									break;
									case 57:
										showname = true;
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"I thought I'd catch you coming out of the classroom, but I saw you just sitting here and spacing out, so I came in.\"");
									break;
									case 58:
										sprintf(dialogueline, "\"Honestly, you're even worse than me sometimes... I'm impressed!\"");
									break;
									case 59:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"You don't need to wait up for me if it's going to make you late to your own club.\"");
									break;
									case 60:
										changedokibodies(3,"11Y");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Well, I thought you might need some encouragement, so I thought, you know...\"");
									break;
									case 61:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Know what?\"");
									break;
									case 62:
										changedokibodies(3,"11A");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Well, that you could come to my club!\"");
									break;
									case 63:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Sayori...\"");
									break;
									case 64:
										changedokibodies(3,"22R");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Yeah? ?\"");
									break;
									case 65:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"...There is no way I'm going to your club.\"");
									break;
									case 66:
										sayoposY = -1;
										changedokibodies(3,"22P");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Eeeehhhhh?! Meanie!\"");
									break;
									case 67:
										showname = false;
										sprintf(dialogueline, "Sayori is vice president of the Literature Club.");
									break;
									case 68:
										sprintf(dialogueline, "Not that I was ever aware that she had any interest in literature.");
									break;
									case 69:
										sprintf(dialogueline, "In fact, I'm 99 percent sure she only did it because she thought it would be fun to help start a new club.");
									break;
									case 70:
										sprintf(dialogueline, "Since she was the first one to show interest after the one who proposed the club, she inherited the title \"Vice President\".");
									break;
									case 71:
										sprintf(dialogueline, "That said, my interest in literature is guaranteed to be even less.");
									break;
									case 72:
										showname = true;
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Yeah. I'm going to the anime club.\"");
									break;
									case 73:
										sayoposY = -0;
										changedokibodies(3,"11G");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"C'mon, please?\"");
									break;
									case 74:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Why do you care so much, anyway?\"");
									break;
									case 75:
										changedokibodies(3,"11C");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Well...\"");
									break;
									case 76:
										sprintf(dialogueline, "\"I kind of told the club yesterday I would bring in a new member...\"");
									break;
									case 77:
										sprintf(dialogueline, "\"And Natsuki made cupcakes and everything...\"");
									break;
									case 78:
										changedokibodies(3,"11Y");
										sprintf(dialogueline, "\"Ehehe...\"");
									break;
									case 79:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Don't make promises you can't keep!\"");
									break;
									case 80:
										showname = false;
										sprintf(dialogueline, "I can't tell if Sayori is really that much of an airhead, or if she's so cunning as to have planned all of this out.");
									break;
									case 81:
										sprintf(dialogueline, "I let out a long sigh.");
									break;
									case 82:
										showname = true;
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Fine... I'll stop by for a cupcake, okay?\"");
									break;
									case 83:
										sayoposY = 1;
										changedokibodies(3,"22R");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Yes! Let's go!!\"");
									break;
									//Loading Corridor
									case 85:
										if (!mutevolume) {mutevolume = true;}
										showname = false;
										sprintf(dialogueline, "And thus, today marks the day I sold my soul for a cupcake.");
										sayorivisible = false;
									break;
									case 86:
										CdControlF(CdlPause,0);
										sprintf(dialogueline, "I dejectedly follow Sayori across the school and upstairs - a section of the school I rarely visit, being generally used for third-year classes and activities.");
									break;
									case 87:
										sprintf(dialogueline, "Sayori, full of energy, swings open the classroom door.");
										//if (bgalpha != 128) {bgalpha = 128;} //TO PREVENT SOFTLOCK LOAD WHEN SPEEDRUNNING, apparently fixed
									break;
									case 88:
										//Loading club
									break;
									case 89:
										if (mutevolume) {mutevolume = false;}
										showname = true;
										sayorivisible = true;
										changedokibodies(3,"22A");
										changeDokiPos(3, 1, 4);
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Everyone! The new member is here!!\"");
									break;
									case 90:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"I told you, don't call me a \"new member--\"\"");
									break;
									case 91:
										sayorivisible = false;
										showname = false;
										sprintf(dialogueline, "Eh? I glance around the room.");
									break;
									case 92:
										showname = true;
										yurivisible = true;
										sprintf(nameshowed, "Girl 1");
										sprintf(dialogueline, "\"Welcome to the Literature Club. It's a pleasure meeting you.\"");
									break;
									case 93:
										sprintf(dialogueline, "\"Sayori always says nice things about you.\"");
									break;
									case 94:
										changeDokiPos(4, 2, 2);
										changeDokiPos(2, 1, 2);
										natsukivisible = true;
										changedokibodies(2, "22C");
										sprintf(nameshowed, "Girl 2");
										sprintf(dialogueline, "\"Seriously? You brought a boy?\"");
									break;
									case 95:
										sprintf(dialogueline, "\"Way to kill the atmosphere.\"");
									break;
									case 96:
										changeDokiPos(4, 3, 3);
										changeDokiPos(2, 2, 3);
										changeDokiPos(1, 1, 3);
										monikavisible = true;
										changedokibodies(1,"11K");
										sprintf(nameshowed, "Girl 3");
										sprintf(dialogueline, "\"Ah, MC! What a nice surprise!\"");
									break;
									case 97:
										sprintf(dialogueline, "\"Welcome to the club!\"");
									break;
									case 98:
										changedokibodies(1,"11A");
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"...\"");
									break;
									case 99:
										showname = false;
										sprintf(dialogueline, "All words escape me in this situation.");
									break;
									case 100:
										sprintf(dialogueline, "This club...");
									break;
									case 101:
										sprintf(dialogueline, "...is full of incredibly cute girls!!");
									break;
									case 102:
										yurivisible = false;
										monikavisible = false;
										showname = true;
										changeDokiPos(3, 1, 1);
										changedokibodies(2, "12C");
										sprintf(nameshowed, "Girl 2");
										sprintf(dialogueline, "\"What are you looking at?\"");
									break;
									case 103:
										sprintf(dialogueline, "\"If you want to say something, say it.\"");
									break;
									case 104:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"S-Sorry...\"");
									break;
									case 105:
										yurivisible = true;
										changedokibodies(4, "22K");
										sprintf(nameshowed, "Girl 1");
										sprintf(dialogueline, "\"Natsuki...\"");
									break;
									case 106:
										changedokibodies(2, "33S");
										sprintf(nameshowed, "Natsuki");
										sprintf(dialogueline, "\"Hmph.\"");
									break;
									case 107:
										showname = false;
										sprintf(dialogueline, "The girl with the sour attitude, whose name is apparently Natsuki, is one I don't recognize.");
									break;
									case 108:
										sprintf(dialogueline, "Her small figure makes me think she's probably a first-year.");
									break;
									case 109:
										sprintf(dialogueline, "She is also the one who made cupcakes, according to Sayori.");
									break;
									case 110:
										sayorivisible = true;
										changedokibodies(3, "12Q");
										changeDokiPos(3, 1, 3);
										showname = true;
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"You can just ignore her when she gets moody-\"");
									break;
									case 111:
										showname = false;
										sprintf(dialogueline, "Sayori says that quietly into my ear, then turns back toward the other girls.");
									break;
									case 112:
										showname = true;
										changedokibodies(3, "11C");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Anyway! This is Natsuki, always full of energy.\"");
									break;
									case 113:
										sprintf(dialogueline, "\"And this is Yuri, the smartest in the club!\"");
									break;
									case 114:
										changedokibodies(4, "22N");
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"D-Don't say things like that...\"");
									break;
									case 115:
										showname = false;
										sprintf(dialogueline, "Yuri, who appears comparably more mature and timid, seems to have a hard time keeping up with people like Sayori and Natsuki.");
									break;
									case 116:
										showname = true;
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Ah... Well, it's nice to meet both of you.\"");
									break;
									case 117:
										natsukivisible = false;
										yurivisible = false;
										changedokibodies(3, "11A");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"And it sounds like you already know Monika, is that right?\"");
									break;
									case 118:
										monikavisible = true;
										changedokibodies(1, "12A");
										changeDokiPos(1, 1,1);
										sprintf(nameshowed, "Monika");
										sprintf(dialogueline, "\"That's right.\"");
									break;
									case 119:
										sprintf(dialogueline, "\"It's great to see you again, MC.\"");
									break;
									case 120:
										moniposY = 1;
										showname = false;
										changedokibodies(1, "11K");
										sprintf(dialogueline, "Monika smiles sweetly.");
									break;
									case 121:
										sprintf(dialogueline, "We do know each other - well, we rarely talked, but we were in the same class last year.");
									break;
									case 122:
										sprintf(dialogueline, "Monika was probably the most popular girl in class - smart, beautiful, athletic.");
									break;
									case 123:
										sprintf(dialogueline, "Basically, completely out of my league.");
									break;
									case 124:
										sprintf(dialogueline, "So, having her smile at me so genuinely feels a little...");
									break;
									case 125:
										showname = true;
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Y-You too, Monika.\"");
									break;
									case 126:
										monikavisible = false;
										changedokibodies(3, "22C");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Come sit down, MC! We made room for you at the table, so you can sit next to me or Monika.\"");
									break;
									case 127:
										sprintf(dialogueline, "\"I'll get the cupcakes!\"");
									break;
									case 128:
										natsukivisible = true;
										changedokibodies(2, "11E");
										sprintf(nameshowed, "Natsuki");
										sprintf(dialogueline, "\"Hey! I made them, I'll get them!\"");
									break;
									case 129:
										changedokibodies(3, "22P");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Sorry, I got a little too excited!\"");
									break;
									case 130:
										yurivisible = true;
										changedokibodies(4, "11A");
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"Then, how about I make some tea as well?\"");
									break;
									case 131:
										natsukivisible = false;
										yurivisible = false;
										sayorivisible = false;
										showname = false;
										sprintf(dialogueline, "The girls have a few desks arranged to form a table.");
									break;
									case 132:
										sprintf(dialogueline, "As Sayori mentioned, it's been widened so that there is one space next to Monika and one space next to Sayori.");
									break;
									case 133:
										sprintf(dialogueline, "Natsuki and Yuri walk over to the corner of the room, where Natsuki grabs a wrapped tray and Yuri opens the closet.");
									break;
									case 134:
										sprintf(dialogueline, "Still feeling awkward, I take a seat next to Sayori.");
									break;
									case 135:
										sprintf(dialogueline, "Natsuki proudly marches back to the table, tray in hand.");
									break;
									case 136:
										natsukivisible = true;
										changedokibodies(2, "12Z");
										showname = true;
										sprintf(nameshowed, "Natsuki");
										sprintf(dialogueline, "\"Okaaay, are you ready?\"");
									break;
									case 137:
										sprintf(dialogueline, "\"...Ta-daa!\"");
									break;
									case 138:
										sayorivisible = true;
										monikavisible = true;
										changedokibodies(1, "12D");
										changedokibodies(3, "22M");
										changeDokiPos(1, 3,3);
										changedokibodies(1, "12A");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Uwooooah!\"");
									break;
									case 139:
										showname = false;
										sprintf(dialogueline, "Natsuki lifts the foil off the tray to reveal a dozen white, fluffy cupcakes decorated to look like little cats.");
									break;
									case 140:
										sprintf(dialogueline, "The whiskers are drawn with icing, and little pieces of chocolate were used to make ears.");
									break;
									case 141:
										changedokibodies(3, "22R");
										showname = true;
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"So cuuuute!!\"");
									break;
									case 142:
										changedokibodies(1, "12B");
										sprintf(nameshowed, "Monika");
										sprintf(dialogueline, "\"I had no idea you were so good at baking, Natsuki!\"");
									break;
									case 143:
										changedokibodies(2, "12D");
										sprintf(nameshowed, "Natsuki");
										sprintf(dialogueline, "\"Ehehe. Well, you know.\"");
									break;
									case 144:
										sprintf(dialogueline, "\"Just hurry and take one!\"");
									break;
									case 145:
										showname = false;
										sprintf(dialogueline, "Sayori grabs one first, then Monika. I follow.");
									break;
									case 146:
										changedokibodies(3, "22Q");
										showname = true;
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"It's delicious!\"");
									break;
									case 147:
										showname = false;
										sprintf(dialogueline, "Sayori talks with her mouth full and has already managed to get icing on her face.");
									break;
									case 148:
										sprintf(dialogueline, "I turn the cupcake around in my fingers, looking for the best angle to take a bite.");
									break;
									case 149:
										sayorivisible = false;
										monikavisible = false;
										changedokibodies(2, "11C");
										sprintf(dialogueline, "Natsuki is quiet.");
									break;
									case 150:
										sprintf(dialogueline, "I can't help but notice her sneaking glances in my direction.");
									break;
									case 151:
										sprintf(dialogueline, "Is she waiting for me to take a bite?");
									break;									
									case 152:
										sprintf(dialogueline, "I finally bite down.");
									break;
									case 153:
										sprintf(dialogueline, "The icing is sweet and full of flavor - I wonder if she made it herself.");
									break;
									case 154:
										showname = true;
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"This is really good.\"");
									break;
									case 155:
										sprintf(dialogueline, "\"Thank you, Natsuki.\"");
									break;
									case 156:
										changedokibodies(2, "33C");
										sprintf(nameshowed, "Natsuki");
										sprintf(dialogueline, "\"W-Why are you thanking me? It's not like I...!\"");
									break;
									case 157:
										showname = false;
										sprintf(dialogueline, "(Haven't I heard this somewhere before...?)");
									break;
									case 158:
										natsuposY = -1;
										showname = true;
										changedokibodies(2, "33S");
										sprintf(nameshowed, "Natsuki");
										sprintf(dialogueline, "\"...Made them for you or anything.\"");
									break;
									case 159:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Eh? I thought you technically did. Sayori said--\"");
									break;
									case 160:
										natsuposY = 0;
										changedokibodies(2, "11S");
										sprintf(nameshowed, "Natsuki");
										sprintf(dialogueline, "\"Well, maybe!\"");
									break;
									case 161:
										sprintf(dialogueline, "\"But not for, y-you know, you! Dummy...\"");
									break;
									case 162:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Alright, alright...\"");
									break;
									case 163:
										showname = false;
										natsukivisible = false;
										sprintf(dialogueline, "I give up on Natsuki's weird logic and dismiss the conversation.");
									break;
									case 164:
										sprintf(dialogueline, "Yuri returns to the table, carrying a tea set.");
									break;
									case 165:
										sprintf(dialogueline, "She carefully places a teacup in front of each of us before setting down the teapot next to the cupcake tray.");
									break;
									case 166:
										changedokibodies(4, "11A");
										yurivisible = true;
										changeDokiPos(4, 1, 2);
										showname = true;
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"You keep a whole tea set in this classroom?\"");
									break;
									case 167:
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"Don't worry, the teachers gave us permission.\"");
									break;
									case 168:
										sprintf(dialogueline, "\"After all, doesn't a hot cup of tea help you enjoy a good book?\"");
									break;
									case 169:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Ah... I-I guess...\"");
									break;
									case 170:
										monikavisible = true;
										changedokibodies(1, "22A");
										sprintf(nameshowed, "Monika");
										sprintf(dialogueline, "\"Ehehe, don't let yourself get intimidated, Yuri's just trying to impress you.\"");
									break;
									case 171:
										yuriposY = 1;
										changedokibodies(4, "22N");
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"Eh?! T-That's not...\"");
									break;
									case 172:
										showname = false;
										sprintf(dialogueline, "Insulted, Yuri looks away.");
									break;
									case 173:
										showname = true;
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"I meant that, you know...\"");
									break;
									case 174:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"I believe you.\"");
									break;
									case 175:
										sprintf(dialogueline, "\"Well, tea and reading might not be a pastime for me, but I at least enjoy tea.\"");
									break;
									case 176:
										changedokibodies(4, "22U");
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"I'm glad...\"");
									break;
									case 177:
										showname = false;
										sprintf(dialogueline, "Yuri faintly smiles to herself in relief.");
									break;
									case 178:
										sprintf(dialogueline, "Monika raises an eyebrow, then smiles at me.");
									break;
									case 179:
										yurivisible = false;
										showname = true;
										changeDokiPos(1,1,1);
										changedokibodies(1,"11A");
										sprintf(nameshowed, "Monika");
										sprintf(dialogueline, "\"So, what made you consider the Literature Club?\"");
									break;
									case 180:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Um...\"");
									break;
									case 181:
										showname = false;
										sprintf(dialogueline, "I was afraid of this question.");
									break;
									case 182:
										sprintf(dialogueline, "Something tells me I shouldn't tell Monika that I was practically dragged here by Sayori.");
									break;
									case 183:
										showname = true;
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Well, I haven't joined any clubs yet, and Sayori seemed really happy here, so...\"");
									break;
									case 184:
										changedokibodies(1,"11K");
										sprintf(nameshowed, "Monika");
										sprintf(dialogueline, "\"That's okay! Don't be embarrassed!\"");
									break;
									case 185:
										changedokibodies(1,"11B");
										sprintf(dialogueline, "\"We'll make sure you feel right at home, okay?\"");
									break;
									case 186:
										sprintf(dialogueline, "\"As president of the Literature Club, it's my duty to make the club fun and exciting for everyone!\"");
									break;
									case 187:
										changedokibodies(1,"11A");
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Monika, I'm surprised.\"");
									break;
									case 188:
										sprintf(dialogueline, "\"How come you decided to start your own club?\"");
									break;
									case 189:
										sprintf(dialogueline, "\"You could probably be a board member for any of the major clubs.\"");
									break;
									case 190:
										sprintf(dialogueline, "\"Weren't you a leader of the debate club last year?\"");
									break;
									case 191:
										changedokibodies(1, "12K");
										sprintf(nameshowed, "Monika");
										sprintf(dialogueline, "\"Ahaha, well, you know...\"");
									break;
									case 192:
										sprintf(dialogueline, "\"To be honest, I can't stand all of the politics around the major clubs.\"");
									break;
									case 193:
										sprintf(dialogueline, "\"It feels like nothing but arguing about the budget and publicity and how to prepare for events...\"");
									break;
									case 194:
										changedokibodies(1, "21A");
										sprintf(dialogueline, "\"I'd much rather take something I personally enjoy and make something special out of it.\"");
									break;
									case 195:
										changedokibodies(1, "11B");
										sprintf(dialogueline, "\"And if it encourages others to get into literature, then I'm fulfilling that dream!\"");
									break;
									case 196:
										changedokibodies(1, "11A");
										sayorivisible = true;
										changedokibodies(3, "21Q");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Monika really is a great leader!\"");
									break;
									case 197:
										changedokibodies(4, "11A");
										yurivisible = true;
										changeDokiPos(4, 3, 3);
										showname = false;
										sprintf(dialogueline, "Yuri also nods in agreement.");
									break;
									case 198:
										sayorivisible = false;
										yurivisible = false;
										showname = true;
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Then I'm surprised there aren't more people in the club yet.\"");
									break;
									case 199:
										sprintf(dialogueline, "\"It must be hard to start a new club.\"");
									break;
									case 200:
										changedokibodies(1, "21B");
										sprintf(nameshowed, "Monika");
										sprintf(dialogueline, "\"You could put it that way.\"");
									break;
									case 201:
										sprintf(dialogueline, "\"Not many people are very interested in putting out all the effort to start something brand new...\"");
									break;
									case 202:
										sprintf(dialogueline, "\"Especially when it's something that doesn't grab your attention, like literature.\"");
									break;
									case 203:
										sprintf(dialogueline, "\"You have to work hard to convince people that you're both fun and worthwhile.\"");
									break;
									case 204:
										sprintf(dialogueline, "\"But it makes school events, like the festival, that much more important.\"");
									break;
									case 205:
										changedokibodies(1, "12K");
										sprintf(dialogueline, "\"I'm confident that we can all really grow this club before we graduate!\"");
									break;
									case 206:
										sprintf(dialogueline, "\"Right, everyone?\"");
									break;
									case 207:
										changedokibodies(1, "12A");
										sayorivisible = true;
										changedokibodies(3, "22R");
										changeDokiPos(3, 1, 2);
										changeDokiPos(1, 2, 2);
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Yeah!\"");
									break;
									case 208:
										changeDokiPos(4, 1, 3);
										changeDokiPos(3, 2, 3);
										changeDokiPos(1, 3, 3);
										yurivisible = true;
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"We'll do our best.\"");
									break;
									case 209:
										natsukivisible = true;
										changeDokiPos(4, 2, 4);
										changeDokiPos(3, 3, 4);
										changeDokiPos(2, 1, 4);
										changeDokiPos(1, 4, 4);
										changedokibodies(2, "22D");
										sprintf(nameshowed, "Natsuki");
										sprintf(dialogueline, "\"You know it!\"");
									break;
									case 210:
										showname = false;
										sprintf(dialogueline, "Everyone enthusiastically agrees.");
									break;
									case 211:
										sprintf(dialogueline, "Such different girls, all interested in the same goal...");
									break;
									case 212:
										sprintf(dialogueline, "Monika must have worked really hard just to find these three.");
									break;
									case 213:
										sprintf(dialogueline, "Maybe that's why they were all so delighted by the idea of a new member joining.");
									break;
									case 214:
										sprintf(dialogueline, "Though I still don't really know if I can keep up with their level of enthusiasm about literature...");
									break;
									case 215:
										sayorivisible = false;
										natsukivisible = false;
										monikavisible = false;
										changeDokiPos(4, 1, 1);
										showname = true;
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"So, MC, what kinds of things do you like to read?\"");
									break;
									case 216:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Well... Ah...\"");
									break;
									case 217:
										showname = false;
										sprintf(dialogueline, "Considering how little I've read these past few years, I don't really have a good way of answering that.");
									break;
									case 218:
										showname = true;
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"...Manga...\"");
									break;
									case 219:
										showname = false;
										sprintf(dialogueline, "I mutter quietly to myself, half-joking.");
									break;
									case 220:
										natsukivisible = true;
										changeDokiPos(2,1,4);
										changedokibodies(2, "11C");
										sprintf(dialogueline, "Natsuki's head suddenly perks up.");
									break;
									case 221:
										sprintf(dialogueline, "It looks like she wants to say something, but she keeps quiet.");
									break;
									case 222:
										natsukivisible = false;
										changedokibodies(4, "22U");
										showname = true;
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"N-Not much of a reader, I guess...\"");
									break;
									case 223:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"...Well, that can change...\"");
									break;
									case 224:
										showname = false;
										sprintf(dialogueline, "What am I saying?");
									break;
									case 225:
										sprintf(dialogueline, "I spoke without thinking after seeing Yuri's sad smile.");
									break;
									case 226:
										showname = true;
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Anyway, what about you, Yuri?\"");
									break;
									case 227:
										changedokibodies(4, "11K");
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"Well, let's see...\"");
									break;
									case 228:
										showname = false;
										sprintf(dialogueline, "Yuri traces the rim of her teacup with her finger.");
									break;
									case 229:
										changedokibodies(4, "11A");
										showname = true;
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"My favorites are usually novels that build deep and complex fantasy worlds.\"");
									break;
									case 230:
										sprintf(dialogueline, "\"The level of creativity and craftsmanship behind them is amazing to me.\"");
									break;
									case 231:
										changedokibodies(4, "11F");
										sprintf(dialogueline, "\"And telling a good story in such a foreign world is equally impressive.\"");
									break;
									case 232:
										showname = false;
										sprintf(dialogueline, "Yuri goes on, clearly passionate about her reading.");
									break;
									case 233:
										sprintf(dialogueline, "She seemed so reserved and timid since the moment I walked in,");
									break;
									case 234:
										sprintf(dialogueline, "but it's obvious by the way her eyes light up that she finds her comfort in the world of books, not people.");
									break;
									case 235:
										changedokibodies(4, "22K");
										showname = true;
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"But you know, I like a lot of things.\"");
									break;
									case 236:
										sprintf(dialogueline, "\"Stories with deep psychological elements usually immerse me as well.\"");
									break;
									case 237:
										changedokibodies(4, "22A");
										sprintf(dialogueline, "\"Isn't it amazing how a writer can so deliberately take advantage of your own lack of imagination to completely throw you for a loop?\"");
									break;
									case 238:
										sprintf(dialogueline, "\"Anyway, I've been reading a lot of horror lately...\"");
									break;
									case 239:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Ah, I read a horror book once...\"");
									break;
									case 240:
										showname = false;
										sprintf(dialogueline, "I desperately grasp something I can relate to at the minimal level.");
									break;
									case 241:
										sprintf(dialogueline, "At this rate, Yuri might as well be having a conversation with a rock.");
									break;
									case 242:
										showname = true;
										monikavisible = true;
										changeDokiPos(1, 4,4);
										changedokibodies(1, "11D");
										sprintf(nameshowed, "Monika");
										sprintf(dialogueline, "\"Really? I wouldn't have expected that, Yuri.\"");
									break;
									case 243:
										sprintf(dialogueline, "\"For someone as gentle as you...\"");
									break;
									case 244:
										changedokibodies(4, "11A");
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"I guess you could say that.\"");
									break;
									case 245:
										sprintf(dialogueline, "\"But if a story makes me think, or takes me to another world, then I really can't put it down.\"");
									break;
									case 246:
										sprintf(dialogueline, "\"Surreal horror is often very successful at changing the way you look at the world, if only for a brief moment.\"");
									break;
									case 247:
										natsukivisible = true;
										changedokibodies(2, "33S");
										sprintf(nameshowed, "Natsuki");
										sprintf(dialogueline, "\"Ugh, I hate horror...\"");
									break;
									case 248:
										changedokibodies(4, "11F");
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"Oh? Why's that?\"");
									break;
									case 249:
										changedokibodies(2, "33C");
										sprintf(nameshowed, "Natsuki");
										sprintf(dialogueline, "\"Well, I just...\"");
									break;
									case 250:
										showname = false;
										sprintf(dialogueline, "Natsuki's eyes dart over to me for a split second.");
									break;
									case 251:
										showname = true;
										changedokibodies(2, "33S");
										sprintf(nameshowed, "Natsuki");
										sprintf(dialogueline, "\"Never mind.\"");
									break;
									case 252:
										changedokibodies(1, "11A");
										sprintf(nameshowed, "Monika");
										sprintf(dialogueline, "\"That's right, you usually like to write about cute things, don't you, Natsuki?\"");
									break;
									case 253:
										changedokibodies(2, "11O");
										sprintf(nameshowed, "Natsuki");
										sprintf(dialogueline, "\"W-What?\"");
									break;
									case 254:
										sprintf(dialogueline, "\"What gives you that idea?\"");
									break;
									case 255:
										changedokibodies(1, "21B");
										sprintf(nameshowed, "Monika");
										sprintf(dialogueline, "\"You left a piece of scrap paper behind last club meeting.\"");
									break;
									case 256:
										sprintf(dialogueline, "\"It looked like you were working on a poem called--\"");
									break;
									case 257:
										changedokibodies(2, "11P");
										sprintf(nameshowed, "Natsuki");
										sprintf(dialogueline, "\"Don't say it out loud!!\"");
									break;
									case 258:
										sprintf(dialogueline, "\"And give that back!\"");
									break;
									case 259:
										changedokibodies(1, "11K");
										sprintf(nameshowed, "Monika");
										sprintf(dialogueline, "\"Fine, fine-\"");
									break;
									case 260:
										sayorivisible = true;		
										changedokibodies(3, "22Q");		
										changedokibodies(2, "11S");		
										changeDokiPos(3, 1, 4);		
										changeDokiPos(2, 2, 4);
										monikavisible = false;				
										yurivisible = false;

										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Ehehe, your cupcakes, your poems...\"");
									break;
									case 261:
										sprintf(dialogueline, "\"Everything you do is just as cute as you are!\"");
									break;
									case 262:
										changeDokiPos(3, 2, 4);						
										showname = false;
										sprintf(dialogueline, "Sayori sidles up behind Natsuki and puts her hands on her shoulders.");
									break;
									case 263:
										natsuposY = 1;
										showname = true;	
										changedokibodies(2, "11V");	
										sprintf(nameshowed, "Natsuki");
										sprintf(dialogueline, "\"I'm not cute!!\"");
									break;
									case 264:
										sayorivisible = false;	
										sprintf(nameshowed, "MC");
										changeDokiPos(2, 1, 1);
										sprintf(dialogueline, "\"Natsuki, you write your own poems?\"");
									break;
									case 265:
										changedokibodies(2, "11C");
										sprintf(nameshowed, "Natsuki");
										sprintf(dialogueline, "\"Eh? Well, I guess sometimes.\"");
									break;
									case 266:
										sprintf(dialogueline, "\"Why do you care?\"");
									break;
									case 267:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"I think that's impressive.\"");
									break;
									case 268:
										sprintf(dialogueline, "\"Why don't you share them sometime?\"");
									break;
									case 269:
										changedokibodies(2, "33S");
										sprintf(nameshowed, "Natsuki");
										sprintf(dialogueline, "\"N-No!\"");
									break;
									case 270:
										showname = false;
										sprintf(dialogueline, "Natsuki averts her eyes.");
									break;
									case 271:
										showname = true;
										sprintf(nameshowed, "Natsuki");
										sprintf(dialogueline, "\"You wouldn't...like them...\"");
									break;
									case 272:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Ah...not a very confident writer yet?\"");
									break;
									case 273:				
										yurivisible = true;
										changeDokiPos(4, 1, 4);	
										changedokibodies(4, "22F");
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"I understand how Natsuki feels.\"");
									break;
									case 274:
										sprintf(dialogueline, "\"Sharing that level of writing takes more than just confidence.\"");
									break;
									case 275:
										changedokibodies(4, "22L");
										sprintf(dialogueline, "\"The truest form of writing is writing to oneself.\"");
									break;
									case 276:
										sprintf(dialogueline, "\"You must be willing to open up to your readers, exposing your vulnerabilities and showing even the deepest reaches of your heart.\"");
									break;
									case 277:
										monikavisible = true;	
										natsukivisible = false;
										changedokibodies(1, "12A");
										sprintf(nameshowed, "Monika");
										sprintf(dialogueline, "\"Do you have writing experience too, Yuri?\"");
									break;
									case 278:
										sprintf(nameshowed, "Monika");
										sprintf(dialogueline, "\"Maybe if you share some of your work, you can set an example and help Natsuki feel comfortable enough to share hers.\"");
									break;
									case 279:
										yuriposY = -1;
										changedokibodies(4, "22V");
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"...\"");
									break;
									case 280:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"I guess it's the same for Yuri...\"");
									break;
									case 281:
										sayorivisible = true;
										changeDokiPos(3, 1,1);
										changedokibodies(3, "12G");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Aww... I wanted to read everyone's poems...\"");
									break;
									case 282:
										sayorivisible = false;
										yurivisible = false;
										monikavisible = false;

										showname = false;
										sprintf(dialogueline, "We all sit in silence for a moment.");
									break;
									case 283:
										monikavisible = true;
										changeDokiPos(1,1,1);
										changedokibodies(1, "21A");
										showname = true;
										sprintf(nameshowed, "Monika");
										sprintf(dialogueline, "\"Okay!\"");
									break;
									case 284:
										sprintf(dialogueline, "\"I have an idea, everyone!\"");
									break;
									case 285:
										yuriposY = 0;
										MovVectoryuribodyL.vy = -22;
										changedokibodies(4, "22E");
										changedokibodies(2, "12K");
										changeDokiPos(2,4,4);
										changeDokiPos(4, 1, 4);	
										yurivisible = true;
										natsukivisible = true;
										sprintf(nameshowed, "Nat & Yuri");
										sprintf(dialogueline, "\"...?\"");
									break;
									case 286:
										showname = false;
										sprintf(dialogueline, "Natsuki and Yuri look quizzically at Monika.");
									break;
									case 287:
										changedokibodies(1, "12B");
										showname = true;
										sprintf(nameshowed, "Monika");
										sprintf(dialogueline, "\"Let's all go home and write a poem of our own!\"");
									break;
									case 288:
										sprintf(dialogueline, "\"Then, next time we meet, we'll all share them with each other.\"");
									break;
									case 289:
										sprintf(dialogueline, "\"That way, everyone is even!\"");
									break;
									case 290:
										changedokibodies(1, "12A");
										changedokibodies(2, "33S");
										showname = true;
										sprintf(nameshowed, "Natsuki");
										sprintf(dialogueline, "\"U-Um...\"");
									break;
									case 291:
										changedokibodies(4, "22V");
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"...\"");
									break;
									case 292:
										sayorivisible = true;
										changeDokiPos(3, 1,4);
										changeDokiPos(4, 2,4);
										changeDokiPos(2, 4,4);
										changeDokiPos(1, 3,4);
										changedokibodies(3, "22R");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Yeaaah! Let's do it!\"");
									break;
									case 293:
										changedokibodies(1, "11A");
										sprintf(nameshowed, "Monika");
										sprintf(dialogueline, "\"Plus, now that we have a new member, I think it will help us all get a little more comfortable with each other, and strengthen the bond of the club.\"");
									break;
									case 294:
										sprintf(dialogueline, "\"Isn't that right, MC?\"");
									break;
									case 295:
										showname = false;
										sprintf(dialogueline, "Monika smiles warmly at me once again.");
									break;
									case 296:
										showname = true;
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Hold on...there's still one problem.\"");
									break;
									case 297:
										changedokibodies(1, "11D");
										sprintf(nameshowed, "Monika");
										sprintf(dialogueline, "\"Eh? What's that?\"");
									break;
									case 298:
										showname = false;
										sprintf(dialogueline, "Now that we're back to the original topic of me joining the club, I bluntly come forth with what's been on my mind the entire time.");
									break;
									case 299:
										showname = true;
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"I never said I would join this club!\"");
									break;
									case 300:
										sprintf(dialogueline, "\"Sayori may have convinced me to stop by, but I never made any decision.\"");
									break;
									case 301:
										sprintf(dialogueline, "\"I still have other clubs to look at, and...um...\"");
									break;
									case 302:
										changedokibodies(4, "22E");
										changedokibodies(3, "11G");
										changedokibodies(2, "11G");
										changedokibodies(1, "11D");
										showname = false;
										sprintf(dialogueline, "I lose my train of thought.");
									break;
									case 303:
										sprintf(dialogueline, "All four girls stare back at me with dejected eyes.");
									break;
									case 304:
										moniposY = -1;
										changedokibodies(1, "11P");
										showname = true;
										sprintf(nameshowed, "Monika");
										sprintf(dialogueline, "\"B-But...\"");
									break;
									case 305:
										yuriposY = -1;
										changedokibodies(4, "22V");
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"I'm sorry, I thought...\"");
									break;
									case 306:
										natsuposY = -1;
										changedokibodies(2, "33S");
										sprintf(nameshowed, "Natsuki");
										sprintf(dialogueline, "\"Hmph.\"");
									break;
									case 307:
										sayoposY = -1;
										changedokibodies(3, "11G");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"MC...\"");
									break;
									case 308:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Y-You all...\"");
									break;
									case 309:
										showname = false;
										sprintf(dialogueline, "I...I'm defenseless against these girls.");
									break;
									case 310:
										sprintf(dialogueline, "How am I supposed to make a clear-headed decision when it's like this?");
									break;
									case 311:
										sprintf(dialogueline, "That is, if writing poems is the price I need to pay in order to spend every day with these beautiful girls...");
									break;
									case 312:
										showname = true;
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"...Right.\"");
									break;
									case 313:
										sprintf(dialogueline, "\"Okay, I've decided, then.\"");
									break;
									case 314:
										sprintf(dialogueline, "\"I'll join the Literature Club.\"");
									break;
									case 315:
										moniposY = 0;
										yuriposY = 0;
										natsuposY = 0;
										sayoposY = 0;
										changedokibodies(2, "11K");
										changedokibodies(4, "22F");
										changedokibodies(3, "22A");
										changedokibodies(1, "11E");
										showname = false;
										sprintf(dialogueline, "One by one, the girls' eyes light up.");
									break;
									case 316:
										sayoposY = 1;
										changedokibodies(3, "22R");
										showname = true;
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Yesss! I'm so happyyy!!\"");
									break;
									case 317:
										showname = false;
										sprintf(dialogueline, "Sayori wraps her arms around me, jumping up and down.");
									break;
									case 318:
										showname = true;
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"H-Hey--\"");
									break;
									case 319:
										changedokibodies(4, "11L");
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"You really did scare me for a moment...\"");
									break;
									case 320:
										changedokibodies(2, "33G");
										sprintf(nameshowed, "Natsuki");
										sprintf(dialogueline, "\"If you really just came for the cupcakes, I would be super pissed.\"");
									break;
									case 321:
										changedokibodies(1, "11K");
										sprintf(nameshowed, "Monika");
										sprintf(dialogueline, "\"Then that makes it official!\"");
									break;
									case 322:
										sprintf(dialogueline, "\"Welcome to the Literature Club!\"");
									break;
									case 323:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Ah...thanks, I guess.\"");
									break;
									case 324:
										natsukivisible = false;
										sayorivisible = false;
										yurivisible = false;
										changeDokiPos(1,1,1);
										changedokibodies(1, "21B");
										sprintf(nameshowed, "Monika");
										sprintf(dialogueline, "\"Okay, everyone!\"");
									break;
									case 325:
										sprintf(nameshowed, "Monika");
										sprintf(dialogueline, "\"I think with that, we can officially end today's meeting on a good note.\"");
									break;
									case 326:
										sprintf(dialogueline, "\"Everyone remember tonight's assignment:\"");
									break;
									case 327:
										sprintf(dialogueline, "\"Write a poem to bring to the next meeting, so we can all share!\"");
									break;
									case 328:
										showname = false;
										sprintf(dialogueline, "Monika looks over at me once more.");
									break;
									case 329:
										showname = true;
										changedokibodies(1, "11A");
										sprintf(nameshowed, "Monika");
										sprintf(dialogueline, "\"MC, I look forward to seeing how you express yourself.\"");
									break;
									case 330:
										changedokibodies(1, "11K");
										sprintf(dialogueline, "\"Ehehe!\"");
									break;
									case 331:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Y-Yeah...\"");
									break;
									case 332:
										showname = false;
										sprintf(dialogueline, "Can I really impress the class star Monika with my mediocre writing skills?");
									break;
									case 333:
										sprintf(dialogueline, "I already feel the anxiety welling up inside me.");
									break;
									case 334:
										sprintf(dialogueline, "Meanwhile, the girls continue to chit-chat as Yuri and Natsuki clean up their food.");
									break;
									case 335:
										monikavisible = false;
										showname = true;
										sayorivisible = true;
										changeDokiPos(3, 1,1);
										changedokibodies(3, "11A");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Hey, MC, since we're already here, do you want to walk home together?\"");
									break;
									case 336:
										showname = false;
										sprintf(dialogueline, "That's right - Sayori and I never walk home together anymore because she always stayed after school for clubs.");
									break;
									case 337:
										showname = true;
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Sure, might as well.\"");
									break;
									case 338:
										changedokibodies(3, "22Q");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Yaay!\"");
									break;
									//Loading Residentials
									case 340:
										sayorivisible = false;
										showname = false;
										sprintf(dialogueline, "With that, the two of us depart the clubroom and make our way home.");
									break;
									case 341:
										sprintf(dialogueline, "The whole way, my mind wanders back and forth between the four girls:");
									break;
									case 342:
										sayorivisible = true;
										changedokibodies(3, "11A");
										changeDokiPos(3, 1, 4);
										sprintf(dialogueline, "Sayori,");
									break;
									case 343:
										natsukivisible = true;
										changedokibodies(2, "22A");
										changeDokiPos(2, 2, 4);
										sprintf(dialogueline, "Natsuki,");
									break;
									case 344:
										changedokibodies(4, "11A");
										yurivisible = true;
										changeDokiPos(4, 3, 4);
										sprintf(dialogueline, "Yuri,");
									break;
									case 345:
										monikavisible = true;
										changedokibodies(1, "11A");
										changeDokiPos(1, 4, 4);
										sprintf(dialogueline, "and, of course, Monika.");
									break;
									case 346:
										sprintf(dialogueline, "Will I really be happy spending every day after school in a literature club?");
									break;
									case 347:
										sprintf(dialogueline, "Perhaps I'll have the chance to grow closer to one of these girls...");
									break;
									case 348:
										natsukivisible = false;
										monikavisible = false;
										sayorivisible = false;
										yurivisible = false;
										sprintf(dialogueline, "Alright!");
									break;
									case 349:
										sprintf(dialogueline, "I'll just need to make the most of my circumstances, and I'm sure good fortune will find me.");
									break;
									case 350:
										sprintf(dialogueline, "And I guess that starts with writing a poem tonight...");
									break;

								}
							} else {
								switch(currentline) {
									case 1 :
										showname = true;
										sayorivisible = true;
										changedokibodies(3, "11A");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"...\"");
									break;
									case 2 :
										sprintf(dialogueline, "\"...\"");
									break;
									case 3 :
										sprintf(dialogueline, "\"W-What...\"");
									break;
									case 4 :
										changedokibodies(3, "11G");
										sprintf(dialogueline, "\"...\"");
									break;
									case 5 :
										sprintf(dialogueline, "\"This...\"");
									break;
									case 6 :
										sprintf(dialogueline, "\"What is this...?\"");
									break;
									case 7 :
										sprintf(dialogueline, "\"Oh no...\"");
									break;
									case 8 :
										changedokibodies(3, "11U");
										sprintf(dialogueline, "\"No...\"");
									break;
									case 9 :
										sprintf(dialogueline, "\"This can't be it.\"");
									break;
									case 10 :
										sprintf(dialogueline, "\"This can't be all there is.\"");
									break;
									case 11 :
										changedokibodies(3, "22W");
										sprintf(dialogueline, "\"What is this?\"");
									break;
									case 12 :
										sprintf(dialogueline, "\"What am I?\"");
									break;
									case 13 :
										sprintf(dialogueline, "\"Make it stop!\"");
									break;
									case 14 :
										sprintf(dialogueline, "\"PLEASE MAKE IT STOP!\"");
									break;
									case 15 :
                                    	CdControlF(CdlPause,0);
										deleteddokis[2] = true;
										currentscreen = 1;
                                    	menuintroframes = 0;
                                    	transitiontogame = false;
                                    	ResetGame(false);
									break;
								}
							}
						break;

						case 2:	
							if (dokimoment) {
								if (whowon == 1) {//Yuri
									switch(currentline) {
										case 1:
											showname = false;
											sprintf(dialogueline, "I'm really curious to talk to Yuri a little bit more...");
										break;
										case 2:
											sprintf(dialogueline, "But at the same time, I would feel bad for distracting her from reading.");
										break;
										case 3:
											sprintf(dialogueline, "I catch a glimpse of the cover of her book.");
										break;
										case 4:
											sprintf(dialogueline, "It looks like the same book that she lent to me...");
										break;
										case 5:
											sprintf(dialogueline, "More than that, she seems to be on the first few pages.");
										break;
										case 6:
											//Loading Music
											showname = true;
											yurivisible = true;
											changedokibodies(4, "22Q");
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"Ah...\"");
										break;
										case 7:
											showname = false;
											sprintf(dialogueline, "Crap--");
										break;
										case 8:
											sprintf(dialogueline, "I think she noticed me looking at her...");
										break;
										case 9:
											sprintf(dialogueline, "She sneaks another glance at me, and our eyes meet for a split second.");
										break;
										case 10:
											showname = true;
											sprintf(nameshowed, "Yuri");
											changedokibodies(4, "22U");
											sprintf(dialogueline, "\"...\"");
										break;
										case 11:
											showname = false;
											sprintf(dialogueline, "But that only makes her hide her face deeper in her book.");
										break;
										case 12:
											showname = true;
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Sorry...\"");
										break;
										case 13:
											sprintf(dialogueline, "\"I was just spacing out...\"");
										break;
										case 14:
											showname = false;
											sprintf(dialogueline, "I mutter this, sensing I made her uncomfortable.");
										break;
										case 15:
											showname = false;
											sprintf(dialogueline, "I mutter this, sensing I made her uncomfortable.");
										break;
										case 16:
											showname = true;
											sprintf(nameshowed, "Yuri");
											changedokibodies(4, "11I");
											sprintf(dialogueline, "\"Oh..\"");
										break;
										case 17:
											sprintf(dialogueline, "\"It's fine...\"");
										break;
										case 18:
											changedokibodies(4, "11A");
											sprintf(dialogueline, "\"If I was focused, then I probably wouldn't have noticed in the first place.\"");
										break;
										case 19:
											sprintf(dialogueline, "\"But I'm just re-reading a bit of this, so...\"");
										break;
										case 20:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"That's the book that you gave me, right?\"");
										break;
										case 21:
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"Mhm.\"");
										break;
										case 22:
											sprintf(dialogueline, "\"I wanted to re-read some of it.\"");
										break;
										case 23:
											changedokibodies(4, "22Q");
											sprintf(dialogueline, "\"Not for any particular reason...!\"");
										break;
										case 24:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Just curious, how come you have two copies of the same book?\"");
										break;
										case 25:
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"Ah...\"");
										break;
										case 26:
											sprintf(dialogueline, "\"Well, when I stopped at the bookstore yesterday--\"");
										break;
										case 27:
											changedokibodies(4, "22N");
											sprintf(dialogueline, "\"Ah, that's not what I meant...\"");
										break;
										case 28:
											sprintf(dialogueline, "\"I mean--\"");
										break;
										case 29:
											changedokibodies(4, "11W");
											sprintf(dialogueline, "\"I...just happened to buy two of them.\"");
										break;
										case 30:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Ah, I see.\"");
										break;
										case 31:
											showname = false;
											sprintf(dialogueline, "There's something fairly obvious here that Yuri isn't telling me, but I decide to let it go.");
										break;
										case 32:
											showname = true;
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"I'll definitely start reading it soon!\"");
										break;
										case 33:
											changedokibodies(4, "22U");
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"I'm glad to hear...\"");
										break;
										case 34:
											sprintf(dialogueline, "\"Once it starts to pick up, you might have a hard time putting it down.\"");
										break;
										case 35:
											changedokibodies(4, "22C");
											sprintf(dialogueline, "\"It's a very engaging and relatable story.\"");
										break;
										case 36:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Is that so...?\"");
										break;
										case 37:
											sprintf(dialogueline, "\"What's it about, anyway?\"");
										break;
										case 38:
											changedokibodies(4, "11F");
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"Well...\"");
										break;
										case 39:
											sprintf(dialogueline, "\"Mmm...\"");
										break;
										case 40:
											showname = false;
											sprintf(dialogueline, "Yuri closes the book and scans her eyes over the back.");
										break;
										case 41:
											sprintf(dialogueline, "The book is titled \"Portrait of Markov\".");
										break;
										case 42:
											sprintf(dialogueline, "There's an ominous-looking eye symbol on the front cover.");
										break;
										case 43:
											changedokibodies(4, "11A");
											showname = true;
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"Alright...\"");
										break;
										case 44:
											sprintf(dialogueline, "\"I just wanted to make sure I don't accidentally give anything away.\"");
										break;
										case 45:
											sprintf(dialogueline, "\"Basically, it's about this girl in high school who moves in with her long-lost younger sister...\"");
										break;
										case 46:
											sprintf(dialogueline, "\"But as soon as she does so, her life gets really strange.\"");
										break;
										case 47:
											changedokibodies(4, "11K");
											sprintf(dialogueline, "\"She gets targeted by these people who escaped from a human experiment prison...\"");
										break;
										case 48:
											sprintf(dialogueline, "\"And while her life is in danger, she needs to desperately choose who to trust.\"");
										break;
										case 49:
											changedokibodies(4, "11U");
											sprintf(dialogueline, "\"No matter what she does, she ends up destroying most of her relationships and her life starts to fall apart...\"");
										break;
										case 50:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"That's kind of--!\"");
										break;
										case 51:
											showname = false;
											sprintf(dialogueline, "That's kind of dark, isn't it?");
										break;
										case 52:
											sprintf(dialogueline, "Yuri made it sound like it was going to be a nice story, so that dark turn came from nowhere.");
										break;
										case 53:
											changedokibodies(4, "11C");
											showname = true;
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"Ahaha.\"");
										break;
										case 54:
											showname = false;
											sprintf(dialogueline, "Yuri gently giggles, all of a sudden.");
										break;
										case 55:
											showname = true;
											sprintf(dialogueline, "\"Are you not a fan of that sort of thing, MC?\"");
										break;
										case 56:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"No, it's not that...\"");
										break;
										case 57:
											sprintf(dialogueline, "\"I mean, I can definitely enjoy those kinds of stories, so don't worry.\"");
										break;
										case 58:
											changedokibodies(4, "22U");
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"I hope so...\"");
										break;
										case 59:
											showname = false;
											sprintf(dialogueline, "Yeah... I totally forgot that Yuri is into those things.");
										break;
										case 60:
											sprintf(dialogueline, "She's so shy and reclusive on the outside, but her mind seems to be completely different.");
										break;
										case 61:
											showname = true;
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"It's just that those kinds of stories...\"");
										break;
										case 62:
											changedokibodies(4, "11A");
											sprintf(dialogueline, "\"They challenge you to look at life from a strange new perspective.\"");
										break;
										case 63:
											sprintf(dialogueline, "\"When horrible things happen not just because someone wants to be evil...\"");
										break;
										case 64:
											changedokibodies(4, "11K");
											sprintf(dialogueline, "\"But because they have their own goals, or their own philosophy that they believe in.\"");
										break;
										case 65:
											sprintf(dialogueline, "\"Then suddenly, when you thought you related to the protagonist...\"");
										break;
										case 66:
											sprintf(dialogueline, "\"They're made out to be the naive one for letting their one-sided morals interfere with the villain's plans.\"");
										break;
										case 67:
											changedokibodies(4, "22V");
											sprintf(dialogueline, "\"I'm...I'm rambling, aren't I...?\"");
										break;
										case 68:
											sprintf(dialogueline, "\"Not again...\"");
										break;
										case 69:
											changedokibodies(4, "22N");
											sprintf(dialogueline, "\"I'm sorry...\"");
										break;
										case 70:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Hey, don't apologize...!\"");
										break;
										case 71:
											sprintf(dialogueline, "\"I haven't lost interest or anything.\"");
										break;
										case 72:
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"Well...\"");
										break;
										case 73:
											sprintf(dialogueline, "\"I guess it's alright, then...\"");
										break;
										case 74:
											sprintf(dialogueline, "\"But I feel like I should let you know that I have this problem...\"");
										break;
										case 75:
											sprintf(dialogueline, "\"When I let things like books and writing fill my thoughts...\"");
										break;
										case 76:
											sprintf(dialogueline, "\"I kind of forget to pay attention to other people...\"");
										break;
										case 77:
											changedokibodies(4, "22V");
											sprintf(dialogueline, "\"So I'm sorry if I end up saying something strange!\"");
										break;
										case 78:
											sprintf(dialogueline, "\"And please stop me if I start talking too much!\"");
										break;
										case 79:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"That's--\"");
										break;
										case 80:
											sprintf(dialogueline, "\"I really don't think you need to worry...\"");
										break;
										case 81:
											sprintf(dialogueline, "\"That just means you're passionate about reading.\"");
										break;
										case 82:
											sprintf(dialogueline, "\"The least I can do is listen.\"");
										break;
										case 83:
											sprintf(dialogueline, "\"It's a literature club, after all...\"");
										break;
										case 84:
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"Ah--\"");
										break;
										case 85:
											sprintf(dialogueline, "\"That's...\"");
										break;
										case 86:
											sprintf(dialogueline, "\"Well, that's true...\"");
										break;
										case 87:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"In fact...\"");
										break;
										case 88:
											sprintf(dialogueline, "\"I might as well get started reading it, right?\"");
										break;
										case 89:
											changedokibodies(4, "22N");
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"Y-You don't have to!\"");
										break;
										case 90:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Ahaha, what are you saying?\"");
										break;
										case 91:
											sprintf(dialogueline, "\"Just a moment ago, you said you were looking forward to it.\"");
										break;
										case 92:
											changedokibodies(4, "22V");
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"...\"");
										break;
										case 93:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Let me just get the book...\"");
										break;
										case 94:
											showname = false;
											sprintf(dialogueline, "I quickly retrieve the book that I had put into my bag.");
										break;
										case 95:
											showname = true;
											sprintf(dialogueline, "\"Alright...it's fine if I sit here, right?\"");
										break;
										case 96:
											showname = false;
											sprintf(dialogueline, "I slip into the seat next to Yuri's.");
										break;
										case 97:
											showname = true;
											changedokibodies(4, "22N");
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"Ah...!\"");
										break;
										case 98:
											sprintf(dialogueline, "\"Yeah...\"");
										break;
										case 99:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Are you sure?\"");
										break;
										case 100:
											sprintf(dialogueline, "\"You seem a little apprehensive...\"");
										break;
										case 101:
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"That's...\"");
										break;
										case 102:
											sprintf(dialogueline, "\"I'm sorry...\"");
										break;
										case 103:
											sprintf(dialogueline, "\"It's not that I don't want you to!\"");
										break;
										case 104:
											sprintf(dialogueline, "\"It's just something I'm not very used to...\"");
										break;
										case 105:
											sprintf(dialogueline, "\"That is, reading in company with someone.\"");
										break;
										case 106:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"I see...\"");
										break;
										case 107:
											sprintf(dialogueline, "\"Well, just tell me if I end up distracting you or anything.\"");
										break;
										case 108:
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"A-Alright...\"");
										break;
										case 109:
											showname = false;
											yurivisible = false;
											sprintf(dialogueline, "I open the book and start the prologue.");
										break;
										case 110:
											sprintf(dialogueline, "I soon understand what Yuri means about reading in company.");
										break;
										case 111:
											sprintf(dialogueline, "It's as if I can feel her presence over my shoulder as I read.");
										break;
										case 112:
											sprintf(dialogueline, "It's not a particularly bad thing.");
										break;
										case 113:
											sprintf(dialogueline, "Maybe a little distracting, but the feeling is somewhat comforting.");
										break;
										case 114:
											sprintf(dialogueline, "Yuri is in the corner of my eye.");
										break;
										case 115:
											sprintf(dialogueline, "I realize that she's not actually looking at her own book.");
										break;
										case 116:
											sprintf(dialogueline, "I glance over.");
										break;
										case 117:
											sprintf(dialogueline, "It looks like she's reading from my book instead--");
										break;
										case 118:
											yurivisible = true;
											showname = true;
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"S-Sorry!\"");
										break;
										case 119:
											sprintf(dialogueline, "\"I was just--!\"");
										break;
										case 120:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Yuri, you really apologize a lot, don't you?\"");
										break;
										case 121:
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"I...I do?\"");
										break;
										case 122:
											changedokibodies(4, "22Q");
											sprintf(dialogueline, "\"I don't really mean to...\"");
										break;
										case 123:
											sprintf(dialogueline, "\"Sorry...\"");
										break;
										case 124:
											changedokibodies(4, "22W");
											sprintf(dialogueline, "\"I mean--!\"");
										break;
										case 125:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Ahaha.\"");
										break;
										case 126:
											sprintf(dialogueline, "\"Here, this should work, right?\"");
										break;
										case 127:
											showname = false;
											sprintf(dialogueline, "I slide my desk until it's up against Yuri's, then hold my book more between the two of them.");
										break;
										case 128:
											showname = true;
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"I suppose so...\"");
										break;
										case 129:
											showname = false;
											sprintf(dialogueline, "Yuri timidly closes her own copy.");
										break;
										case 130:
											sprintf(dialogueline, "Once we each lean in a little bit, our shoulders are almost touching.");
										break;
										case 131:
											sprintf(dialogueline, "It feels like my left arm is in the way, so instead I use my right hand to hold the book open.");
										break;
										case 132:
											changedokibodies(4, "22V");
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Ah, I guess that makes it kind of difficult to turn the page...\"");
										break;
										case 133:
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"Here...\"");
										break;
										case 134:
											//Loading Yuri Special
										break;
										case 135:
											textboxlow = true;
											yurivisible = false;
											showname = false;
											sprintf(dialogueline, "Yuri takes her left arm and holds the left side of the book between her thumb and forefinger.");
										break;
										case 136:
											showname = true;
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Ah...\"");
										break;
										case 137:
											showname = false;
											sprintf(dialogueline, "I do the same with my right arm, on the right side of the book.");
										break;
										case 138:
											sprintf(dialogueline, "That way, I turn a page, and Yuri slides it under her thumb after it flips to her side.");
										break;
										case 139:
											sprintf(dialogueline, "But in holding it like this...");
										break;
										case 140:
											sprintf(dialogueline, "We're huddled even closer together than before.");
										break;
										case 141:
											sprintf(dialogueline, "It's actually kind of distracting me...!");
										break;
										case 142:
											sprintf(dialogueline, "It's as if I can feel the warmth of Yuri's face, and she's in the corner of my vision...");
										break;
										case 143:
											showname = true;
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"...Are you ready?\"");
										break;
										case 144:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Eh?\"");
										break;
										case 145:
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"To turn the page...\"");
										break;
										case 146:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Ah...sorry!\"");
										break;
										case 147:
											sprintf(dialogueline, "\"I think I got a bit distracted for a second...\"");
										break;
										case 148:
											showname = false;
											sprintf(dialogueline, "I glance over at Yuri's face again, and our eyes meet.");
										break;
										case 149:
											sprintf(dialogueline, "I don't know how I'll be able to keep up with her...");
										break;
										case 150:
											showname = true;
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"Ah...\"");
										break;
										case 151:
											sprintf(dialogueline, "\"That's okay.\"");
										break;
										case 152:
											sprintf(dialogueline, "\"You're not as used to reading, right?\"");
										break;
										case 153:
											sprintf(dialogueline, "\"I don't mind being patient if it takes you a bit longer...\"");
										break;
										case 154:
											sprintf(dialogueline, "\"It's probably the least I can do...\"");
										break;
										case 155:
											sprintf(dialogueline, "\"Since you've been so patient with me...\"");
										break;
										case 156:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Y-Yeah...\"");
										break;
										case 157:
											sprintf(dialogueline, "\"Thanks.\"");
										break;
										case 158:
											showname = false;
											sprintf(dialogueline, "We continue reading.");
										break;
										case 159:
											sprintf(dialogueline, "Yuri no longer asks me if I'm ready to turn the page.");
										break;
										case 160:
											sprintf(dialogueline, "Instead, I just assume that she finishes the page before me, so I turn it by my own volition.");
										break;
										case 161:
											sprintf(dialogueline, "We continue the first chapter in silence.");
										break;
										case 162:
											sprintf(dialogueline, "Even so, turning each page almost feels like an intimate exchange...");
										break;
										case 163:
											sprintf(dialogueline, "My thumb gently letting go of the page, letting it flutter over to her side as she catches it under her own thumb.");
										break;
										case 164:
											showname = true;
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Hey, Yuri...\"");
										break;
										case 165:
											sprintf(dialogueline, "\"This might be a silly thought, but...\"");
										break;
										case 166:
											sprintf(dialogueline, "\"The main character kind of reminds me of you a little bit.\"");
										break;
										case 167:
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"You...think so?\"");
										break;
										case 168:
											sprintf(dialogueline, "\"How does she?\"");
										break;
										case 169:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Well, I guess she's more blunt in a lot of ways...\"");
										break;
										case 170:
											sprintf(dialogueline, "\"But she also second-guesses all of the things that she says and does.\"");
										break;
										case 171:
											sprintf(dialogueline, "\"Like she's afraid she'll do something wrong.\"");
										break;
										case 172:
											sprintf(dialogueline, "\"It's not like I can see into your head or anything...\"");
										break;
										case 173:
											sprintf(dialogueline, "\"But they're kind of reminiscent of some of your mannerisms.\"");
										break;
										case 174:
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"I-I see...\"");
										break;
										case 175:
											//Loading Club
										break;
										case 176:
											textboxlow = false;
											yurivisible = true;
											changedokibodies(4, "22V");
											showname = false;
											sprintf(dialogueline, "Yuri remains silent for a moment.");
										break;
										case 177:
											showname = true;
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"But MC...\"");
										break;
										case 178:
											sprintf(dialogueline, "\"That's probably...\"");
										break;
										case 179:
											sprintf(dialogueline, "\"...a terrible thing to have in common with her!\"");
										break;
										case 180:
											changedokibodies(4, "22W");
											sprintf(dialogueline, "\"Uuuh, that's so embarrassing that you think that...\"");
										break;
										case 181:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"W-Wait!\"");
										break;
										case 182:
											sprintf(dialogueline, "\"I didn't mean it in a bad way or anything!\"");
										break;
										case 183:
											sprintf(dialogueline, "\"Sorry, I really didn't know you were self-conscious about that sort of thing...\"");
										break;
										case 184:
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"...\"");
										break;
										case 185:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"I guess I more meant that it's kind of cute...\"");
										break;
										case 186:
											changedokibodies(4, "22Q");
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"A-Ah--\"");
										break;
										case 187:
											sprintf(dialogueline, "\"What are you saying all of a sudden...?\"");
										break;
										case 188:
											sprintf(dialogueline, "\"I...!\"");
										break;
										case 189:
											monikavisible = true;
											changeDokiPos(1,1,4);
											changedokibodies(1, "22A");
											sprintf(nameshowed, "Monika");
											sprintf(dialogueline, "\"Okay, everyone!\"");
										break;
										case 190:
											changedokibodies(4, "22N");
											yuriposY = 1;
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"...!\"");
										break;
										case 191:
											sprintf(nameshowed, "Monika");
											sprintf(dialogueline, "\"I think it's about time we share today's poems with each other.\"");
										break;
										case 192:
											sprintf(dialogueline, "\"We might not have enough time if we wait too long.\"");
										break;
										case 193:
											changedokibodies(4, "22W");
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"Ah...\"");
										break;
										case 194:
											showname = false;
											sprintf(dialogueline, "Yuri exhales, spared from finishing her thought.");
										break;
										case 195:
											showname = true;
											changedokibodies(1, "11A");
											sprintf(nameshowed, "Monika");
											sprintf(dialogueline, "\"Is that alright, Yuri?\"");
										break;
										case 196:
											sprintf(dialogueline, "\"You look kind of down...\"");
										break;
										case 197:
											sprintf(dialogueline, "\"I'm sorry if you haven't been looking forward to this...\"");
										break;
										case 198:
											changedokibodies(4, "22V");
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"Ah, it's not...\"");
										break;
										case 199:
											sprintf(dialogueline, "\"...It's fine.\"");
										break;
										case 200:
											monikavisible = false;
											sprintf(dialogueline, "Yuri releases her hand from the book, causing it to close on top of my thumb.");
										break;
										case 201:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Alright..\"");
										break;
										case 202:
											sprintf(dialogueline, "\"I guess I'll do some more reading tonight.\"");
										break;
										case 203:
											sprintf(dialogueline, "\"Or would you prefer I only read it with you?\"");
										break;
										case 204:
											changedokibodies(4, "22F");
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"Um...!\"");
										break;
										case 205:
											sprintf(dialogueline, "\"I...guess I don't have too much of a preference either way...\"");
										break;
										case 206:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Hmm...\"");
										break;
										case 207:
											sprintf(dialogueline, "\"In that case, I'll read a little more tonight.\"");
										break;
										case 208:
											sprintf(dialogueline, "\"It'll be more fun to read with you after it picks up a bit, you know?\"");
										break;
										case 209:
											changedokibodies(4, "22A");
											sprintf(nameshowed, "Yuri");
											sprintf(dialogueline, "\"That's good reasoning.\"");
										break;
										case 210:
											sprintf(dialogueline, "\"In that case, feel free to finish the first two chapters in your own time.\"");
										break;
										case 211:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Alright!\"");
										break;
										case 212:
											showname = false;
											yurivisible = false;
											sprintf(dialogueline, "I stand up.");
										break;
										case 213:
											sprintf(dialogueline, "I make a mental note of where I left off in the book, then slip it back into my bag.");
											dokimoment = false;
											currentline = 75;
										break;
									}
								}
								if (whowon == 2) {//Natsuki
									switch(currentline) {
										case 1:
											showname = true;
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"Ugh...!\"");
										break;
										case 2:
											showname = false;
											sprintf(dialogueline, "I hear Natsuki utter an exasperated sigh from within the closet.");
										break;
										case 3:
											sprintf(dialogueline, "She seems to be annoyed by something.");
										break;
										case 4:
											sprintf(dialogueline, "I approach her, in case she needs a hand.");
										break;
										case 5:
											//Loading Closet
										break;
										case 6:
											changeDokiPos(2,1,1);
											natsukivisible = true;
											showname = true;
											changedokibodies(2, "22S");
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"You looking for something in there?\"");
										break;
										case 7:
											changedokibodies(2, "22X");
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"Freaking Monika...\"");
										break;
										case 8:
											sprintf(dialogueline, "\"She never puts my stuff back in the right spot!\"");
										break;
										case 9:
											sprintf(dialogueline, "\"What's the point in keeping your collection organized if someone else is just gonna mess it up?\"");
										break;
										case 10:
											showname = false;
											sprintf(dialogueline, "Natsuki slides a bunch of stacked books and boxes across the shelf.");
										break;
										case 11:
											showname = true;
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Manga...\"");
										break;
										case 12:
											sprintf(nameshowed, "Natsuki");
											changedokibodies(2, "12C");
											sprintf(dialogueline, "\"You read manga, right?\"");
										break;
										case 13:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Ah--\"");
										break;
										case 14:
											sprintf(dialogueline, "\"...Sometimes...\"");
										break;
										case 15:
											showname = false;
											sprintf(dialogueline, "Manga is one of those things where you can't admit you're really into it until you figure out where the other person stands.");
										break;
										case 16:
											showname = true;
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"...How did you know, anyway?\"");
										break;
										case 17:
											sprintf(nameshowed, "Natsuki");
											changedokibodies(2, "12K");
											sprintf(dialogueline, "\"I heard you bring it up at some point.\"");
										break;
										case 18:
											sprintf(dialogueline, "\"Besides, it's kind of written on your face.\"");
										break;
										case 19:
											showname = false;
											sprintf(dialogueline, "What's that supposed to mean...?");
										break;
										case 20:
											showname = true;
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"I-I see...\"");
										break;
										case 21:
											showname = false;
											sprintf(dialogueline, "There's a lone volume of manga amidst a stack of various books on the side of one of the shelves.");
										break;
										case 22:
											sprintf(dialogueline, "Curious, I pull it out of the stack.");
										break;
										case 23:
											showname = true;
											sprintf(nameshowed, "Natsuki");
											changedokibodies(2, "11E");
											sprintf(dialogueline, "\"There it is!\"");
										break;
										case 24:
											showname = false;
											sprintf(dialogueline, "Natsuki snatches it out of my hand.");
										break;
										case 25:
											sprintf(dialogueline, "She then turns to a box of manga and slips the volume right into the middle of the rest.");
										break;
										case 26:
											showname = true;
											changedokibodies(2, "22D");
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"Aah, much better!\"");
										break;
										case 27:
											sprintf(dialogueline, "\"Seeing a box set with one book missing is probably the most irritating sight in the world.\"");
										break;
										case 28:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"I know that feel...\"");
										break;
										case 29:
											showname = false;
											sprintf(dialogueline, "I get a closer look at the box set she's admiring.");
										break;
										case 30:
											showname = true;
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Parfait Girls...?\"");
										break;
										case 31:
											showname = false;
											sprintf(dialogueline, "It's a series I've never heard of in my life.");
										break;
										case 32:
											sprintf(dialogueline, "That probably means it's either way out of my demographic, or it's simply terrible.");
										break;
										case 33:
											showname = true;
											changedokibodies(2, "33G");
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"If you're gonna judge, you can go do it through the glass on that door.\"");
										break;
										case 34:
											showname = false;
											sprintf(dialogueline, "She points to the classroom door.");
										break;
										case 35:
											showname = true;
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"H-Hey, I wasn't judging anything...!\"");
										break;
										case 36:
											sprintf(dialogueline, "\"I didn't even say anything.\"");
										break;
										case 37:
											changedokibodies(2, "33C");
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"It was the tone of your voice.\"");
										break;
										case 38:
											sprintf(dialogueline, "\"But I'll tell you one thing, MC.\"");
										break;
										case 39:
											changedokibodies(2, "22D");
											sprintf(dialogueline, "\"Consider this a lesson straight from the Literature Club: Don't judge a book by its cover!\"");
										break;
										case 40:
											sprintf(dialogueline, "\"In fact--\"");
										break;
										case 41:
											showname = false;
											sprintf(dialogueline, "Natsuki pulls out the first volume of Parfait Girls from the box.");
										break;
										case 42:
											showname = true;
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"I'm gonna show you exactly why!\"");
										break;
										case 43:
											showname = false;
											sprintf(dialogueline, "She shoves the book right into my hands.");
										break;
										case 44:
											showname = true;
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Ah...\"");
										break;
										case 45:
											showname = false;
											sprintf(dialogueline, "I stare at the cover.");
										break;
										case 46:
											sprintf(dialogueline, "It features four girls in colorful attire striking animated feminine poses.");
										break;
										case 47:
											sprintf(dialogueline, "It's...exceedingly \"moe\".");
										break;
										case 48:
											changedokibodies(2, "22E");
											showname = true;
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"Don't just stand there!\"");
										break;
										case 49:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Uwa--\"");
										break;
										case 50:
											showname = false;
											sprintf(dialogueline, "Natsuki grabs my arm and pulls me out of the closet.");
										break;
										case 51:
											sprintf(dialogueline, "She then takes a seat against the wall, beneath the windowsills.");
										break;
										case 52:
											//Loading Club
										break;
										case 53:
											changedokibodies(2, "12A");
											showname = true;
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Wouldn't chairs be more comfortable...?\"");
										break;
										case 54:
											showname = false;
											sprintf(dialogueline, "I take my seat.");
										break;
										case 55:
											changedokibodies(2, "12C");
											showname = true;
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"Chairs wouldn't work.\"");
										break;
										case 56:
											sprintf(dialogueline, "\"We can't read at the same time like that.\"");
										break;
										case 57:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Eh? Why's that?\"");
										break;
										case 58:
											sprintf(dialogueline, "\"Ah...I guess it's easier to be close together like this...\"");
										break;
										case 59:
											changedokibodies(2, "12O");
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"--!\"");
										break;
										case 60:
											changedokibodies(2, "33O");
											sprintf(dialogueline, "\"D-Don't just say that!\"");
										break;
										case 61:
											sprintf(dialogueline, "\"You'll make me feel weird about it!\"");
										break;
										case 62:
											showname = false;
											sprintf(dialogueline, "Natsuki crosses her arms and scootches an inch away from me.");
										break;
										case 63:
											showname = true;
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Sorry...\"");
										break;
										case 64:
											changedokibodies(2, "33G");
											showname = false;
											sprintf(dialogueline, "I didn't exactly expect to be sitting this close to her, either...");
										break;
										case 65:
											sprintf(dialogueline, "Not that I can say it's a particularly bad thing.");
										break;
										case 66:
											sprintf(dialogueline, "I open the book.");
										break;
										case 67:
											sprintf(dialogueline, "It's only a few seconds before Natsuki once again inches closer, reclaiming the additional space while she hopes I won't notice.");
										break;
										case 68:
											sprintf(dialogueline, "I can feel her peering over my shoulder, much more eager to begin reading than I am.");
										break;
										case 69:
											showname = true;
											changedokibodies(2, "11K");
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"Wow, how long has it been since I read the beginning...?\"");
										break;
										case 70:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Hm?\"");
										break;
										case 71:
											sprintf(dialogueline, "\"You don't go back and flip through the older volumes every now and then?\"");
										break;
										case 72:
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"Not really.\"");
										break;
										case 73:
											sprintf(dialogueline, "\"Maybe sometimes after I've already finished the series.\"");
										break;
										case 74:
											changedokibodies(2, "11C");
											sprintf(dialogueline, "\"Hey, are you paying attention?\"");
										break;
										case 75:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Uh..\"");
										break;
										case 76:
											showname = false;
											sprintf(dialogueline, "I am, but nothing's really happened yet, so I can talk at the same time.");
										break;
										case 77:
											sprintf(dialogueline, "It looks like it's about a bunch of friends in high school.");
										break;
										case 78:
											sprintf(dialogueline, "I kind of grew out of these, since it's rare for the writing to be entertaining enough to make up for the lack of plot.");
										break;
										case 79:
											showname = true;
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"So...\"");
										break;
										case 80:
											sprintf(dialogueline, "\"What should I expect from this?\"");
										break;
										case 81:
											sprintf(dialogueline, "\"Is there going to be plot?\"");
										break;
										case 82:
											changedokibodies(2, "22X");
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"Well, obviously!\"");
										break;
										case 83:
											sprintf(dialogueline, "\"You think I would enjoy something that didn't have a plot?\"");
										break;
										case 84:
											changedokibodies(2, "22C");
											sprintf(dialogueline, "\"I mean...\"");
										break;
										case 85:
											changedokibodies(2, "12C");
											sprintf(dialogueline, "\"Well, I guess I know what you're saying...\"");
										break;
										case 86:
											changedokibodies(2, "12K");
											sprintf(dialogueline, "\"A lot of the beginning is about simple things...\"");
										break;
										case 87:
											sprintf(dialogueline, "\"Like there's a really funny chapter where they're obsessed with a guy at the ice cream shop...\"");
										break;
										case 88:
											changedokibodies(2, "12C");
											sprintf(dialogueline, "\"But that just helps you get to know the characters!\"");
										break;
										case 89:
											sprintf(dialogueline, "\"And besides, it's still entertaining.\"");
										break;
										case 90:
											changedokibodies(2, "12D");
											sprintf(dialogueline, "\"But later on, there's all kinds of drama...\"");
										break;
										case 91:
											sprintf(dialogueline, "\"Like when they get into all their backstories, and when some of the romance starts to happen...\"");
										break;
										case 92:
											sprintf(dialogueline, "\"That's really what makes it so good.\"");
										break;
										case 93:
											changedokibodies(2, "12A");
											sprintf(dialogueline, "\"There are so many touching parts.\"");
										break;
										case 94:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Ah, is that so?\"");
										break;
										case 95:
											sprintf(dialogueline, "\"It sounds like you really know what you're talking about.\"");
										break;
										case 96:
											sprintf(dialogueline, "\"Maybe I underestimated you.\"");
										break;
										case 97:
											changedokibodies(2, "12Z");
											sprintf(dialogueline, "\"Ehehe.\"");
										break;
										case 98:
											changedokibodies(2, "11E");
											sprintf(dialogueline, "\"...Hey, wait!\"");
										break;
										case 99:
											sprintf(dialogueline, "\"What's that supposed to mean?!\"");
										break;
										case 100:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Uwa--\"");
										break;
										case 101:
											showname = false;
											sprintf(dialogueline, "Natsuki gives me a little shove.");
										break;
										case 102:
											showname = true;
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"I just meant that I haven't yet seen you at your full power...\"");
										break;
										case 103:
											sprintf(nameshowed, "Natsuki");
											changedokibodies(2, "33S");
											sprintf(dialogueline, "\"Hmph. Good save.\"");
										break;
										case 104:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Ah... This chapter seems like it's about baking.\"");
										break;
										case 105:
											sprintf(dialogueline, "\"This is just a guess, but is there a lot of baking in this manga?\"");
										break;
										case 106:
											changedokibodies(2, "33E");
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"Well--\"");
										break;
										case 107:
											showname = false;
											sprintf(dialogueline, "Natsuki pauses for a moment, as if she doesn't want to admit something.");
										break;
										case 108:
											showname = true;
											changedokibodies(2, "12S");
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"...Yeah.\"");
										break;
										case 109:
											sprintf(dialogueline, "\"Why does that matter?\"");
										break;
										case 110:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"It doesn't, I was just curious...\"");
										break;
										case 111:
											sprintf(dialogueline, "\"Since you enjoy baking too, right?\"");
										break;
										case 112:
											changedokibodies(2, "11O");
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"That's--\"");
										break;
										case 113:
											sprintf(dialogueline, "\"Just a coincidence!\"");
										break;
										case 114:
											changedokibodies(2, "11E");
											sprintf(dialogueline, "\"I just happened to get into baking around the same time I got this manga.\"");
										break;
										case 115:
											sprintf(dialogueline, "\"Like I would ever get into anything because it's in a manga.\"");
										break;
										case 116:
											changedokibodies(2, "22D");
											sprintf(dialogueline, "\"I feel bad for anyone that impressionable.\"");
										break;
										case 117:
											sprintf(dialogueline, "\"Ahaha!\"");
										break;
										case 118:
											showname = false;
											sprintf(dialogueline, "Definitely not a coincidence...");
										break;
										case 119:
											sprintf(dialogueline, "I guess that explains Natsuki's interest in baking.");
										break;
										case 120:
											sprintf(dialogueline, "Still, of all the hobbies to pick up from a manga, that's definitely one of the better ones.");
										break;
										case 121:
											sprintf(dialogueline, "Not to mention she's really good at it, so who am I to judge?");
										break;
										case 122:
											//Loading Natsuki Special
										break;
										case 123:
											textboxlow = true;
											natsukivisible = false;
											sprintf(dialogueline, "...");
										break;
										case 124:
											sprintf(dialogueline, "We read on for a few more minutes.");
										break;
										case 125:
											sprintf(dialogueline, "I've finished a couple chapters at this point.");
										break;
										case 126:
											showname = true;
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"...\"");
										break;
										case 127:
											sprintf(dialogueline, "\"...Are you sure this isn't boring for you?\"");
										break;
										case 128:
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"It's not!\"");
										break;
										case 129:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Even though you're just watching me read?\"");
										break;
										case 130:
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"Well...!\"");
										break;
										case 131:
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"I'm...fine with that.\"");
										break;
										case 132:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"If you say so...\"");
										break;
										case 133:
											sprintf(dialogueline, "\"...I guess it's fun sharing something you like with someone else.\"");
										break;
										case 134:
											sprintf(dialogueline, "\"I always get excited when I convince any of my friends to pick up a series I enjoy.\"");
										break;
										case 135:
											sprintf(dialogueline, "\"You know what I mean?\"");
										break;
										case 136:
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"...?\"");
										break;
										case 137:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Hm?\"");
										break;
										case 138:
											sprintf(dialogueline, "\"You don't?\"");
										break;
										case 139:
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"Um...\"");
										break;
										case 140:
											sprintf(dialogueline, "\"That's not...\"");
										break;
										case 141:
											sprintf(dialogueline, "\"Well, I wouldn't really know.\"");
										break;
										case 142:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"...What do you mean?\"");
										break;
										case 143:
											sprintf(dialogueline, "\"Don't you share your manga with your friends?\"");
										break;
										case 144:
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"Could you not rub it in?\"");
										break;
										case 145:
											sprintf(dialogueline, "\"Jeez...\"");
										break;
										case 146:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Ah... Sorry...\"");
										break;
										case 147:
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"Hmph.\"");
										break;
										case 148:
											sprintf(dialogueline, "\"Like I could ever get my friends to read this...\"");
										break;
										case 149:
											sprintf(dialogueline, "\"They just think manga is for kids.\"");
										break;
										case 150:
											sprintf(dialogueline, "\"I can't even bring it up without them being all like...\"");
										break;
										case 151:
											sprintf(dialogueline, "\"'Eh? You still haven't grown out of that yet?'\"");
										break;
										case 152:
											sprintf(dialogueline, "\"Makes me want to punch them in the face...\"");
										break;
										case 153:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Urgh, I know those kinds of people...\"");
										break;
										case 154:
											sprintf(dialogueline, "\"Honestly, it takes a lot of effort to find friends who don't judge, much less friends who are also into it...\"");
										break;
										case 155:
											sprintf(dialogueline, "\"I'm already kind of a loser, so I guess I gravitated toward the other losers over time.\"");
										break;
										case 156:
											sprintf(dialogueline, "\"But it's probably harder for someone like you...\"");
										break;
										case 157:
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"Hm.\"");
										break;
										case 158:
											sprintf(dialogueline, "\"Yeah, that's pretty accurate.\"");
										break;
										case 159:
											showname = false;
											sprintf(dialogueline, "\"...Wait, which part??\"");
										break;
										case 160:
											showname = true;
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"I mean, I feel like I can't even keep it in my own room...\"");
										break;
										case 161:
											sprintf(dialogueline, "\"I don't even know what my dad would do if he found this.\"");
										break;
										case 162:
											sprintf(dialogueline, "\"At least it's safe here in the clubroom.\"");
										break;
										case 163:
											sprintf(dialogueline, "\"'Cept Monika was kind of a jerk about it...\"");
										break;
										case 164:
											sprintf(dialogueline, "\"Ugh! I just can't win, can I?\"");
										break;
										case 165:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Well, it paid off in the end, didn't it?\"");
										break;
										case 166:
											sprintf(dialogueline, "\"I mean, here I am, reading it.\"");
										break;
										case 167:
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"Well, it's not like that solves any of my problems.\"");
										break;
										case 168:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Maybe...\"");
										break;
										case 169:
											sprintf(dialogueline, "\"But at least you're enjoying yourself, right?\"");
										break;
										case 170:
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"--\"");
										break;
										case 171:
											sprintf(dialogueline, "\"...\"");
										break;
										case 172:
											sprintf(dialogueline, "\"...So?\"");
										break;
										case 173:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Ahaha.\"");
										break;
										case 174:
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"Jeez, that's enough!\"");
										break;
										case 175:
											sprintf(dialogueline, "\"Are you gonna keep reading, or what?\"");
										break;
										case 176:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Yeah, yeah...\"");
										break;
										case 177:
											showname = false;
											sprintf(dialogueline, "I flip the page.");
										break;
										case 178:
											sprintf(dialogueline, "Suddenly, Natsuki starts laughing.");
										break;
										case 179:
											showname = true;
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"Ahahaha!\"");
										break;
										case 180:
											sprintf(dialogueline, "\"I totally forgot that happens!\"");
										break;
										case 181:
											showname = false;
											sprintf(dialogueline, "Natsuki puts her finger on one of the panels.");
										break;
										case 182:
											showname = true;
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"Minori is my favorite character.\"");
										break;
										case 183:
											sprintf(dialogueline, "\"You always feel a little bad for her, since she's so unlucky.\"");
										break;
										case 184:
											sprintf(dialogueline, "\"But it gets especially bad when--\"");
										break;
										case 185:
											sprintf(dialogueline, "\"Uu...\"");
										break;
										case 186:
											sprintf(dialogueline, "\"I shouldn't be talking about that yet!\"");
										break;
										case 187:
											sprintf(dialogueline, "\"Just finish this chapter!\"");
										break;
										case 188:
											//Loading Club
										break;
										case 189:
											textboxlow = false;
											showname = false;
											sprintf(dialogueline, "Natsuki's voice sparkles with excitement.");
										break;
										case 190:
											sprintf(dialogueline, "It's a stark contrast to her usual bossy tone.");
										break;
										case 191:
											sprintf(dialogueline, "But if she's not used to sharing her favorite manga with her friends, I can understand why.");
										break;
										case 192:
											sprintf(dialogueline, "It's hard to express in words the feeling you get when connecting with someone like that.");
										break;
										case 193:
											sprintf(dialogueline, "And being able to provide that to Natsuki, for whom it's a rare experience...");
										break;
										case 194:
											sprintf(dialogueline, "The thought makes me smile a little to myself.");
										break;
										case 195:
											showname = true;
											monikavisible = true;
											changeDokiPos(1,1,2);
											changedokibodies(1,"21B");
											sprintf(nameshowed, "Monika");
											sprintf(dialogueline, "\"Okay, everyone!\"");
										break;
										case 196:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Eh?\"");
										break;	
										case 197:
											sprintf(nameshowed, "Monika");
											sprintf(dialogueline, "\"Are you all ready with today's poems?\"");
										break;
										case 198:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"...\"");
										break;	
										case 199:
											natsukivisible = true;
											changeDokiPos(2,2,2);
											changedokibodies(2,"22E");
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"Oh, come on!\"");
										break;	
										case 200:
											sprintf(dialogueline, "\"Could your timing be any worse?\"");
										break;		
										case 201:
											changedokibodies(1,"11K");
											sprintf(nameshowed, "Monika");
											sprintf(dialogueline, "\"Sorry!\"");
										break;		
										case 202:
											sprintf(dialogueline, "\"I just need to make sure we have enough time.\"");
										break;		
										case 203:
											sprintf(dialogueline, "\"Though you do look pretty cozy over there. Ahaha!\"");
										break;		
										case 204:
											changedokibodies(2,"22O");
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"Eh...?\"");
										break;		
										case 205:
											changedokibodies(2,"11P");
											sprintf(dialogueline, "\"A-Ah!\"");
										break;		
										case 206:
											showname = false;
											sprintf(dialogueline, "Natsuki suddenly notices how close she's gotten to me.");
										break;		
										case 207:
											sprintf(dialogueline, "She hastily slides herself a good twelve inches away from me.");
										break;		
										case 208:
											showname = true;
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Alright...\"");
										break;		
										case 209:
											sprintf(dialogueline, "\"Guess I'll stop here for now.\"");
										break;		
										case 210:
											showname = false;
											sprintf(dialogueline, "I close the book and hand it towards Natsuki.");
										break;		
										case 211:
											changedokibodies(2,"12M");
											showname = true;
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"You're just giving it back...?\"");
										break;		
										case 212:
											sprintf(dialogueline, "\"Don't you want to know what happens?\"");
										break;		
										case 213:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Ah... Yeah, but...\"");
										break;			
										case 214:
											sprintf(dialogueline, "\"Monika just said--\"");
										break;			
										case 215:
											changedokibodies(2,"12U");
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"Don't be dumb.\"");
										break;		
										case 216:
											sprintf(dialogueline, "\"Just take it home with you.\"");
										break;		
										case 217:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Eh?\"");
										break;		
										case 218:
											sprintf(dialogueline, "\"...Is that really alright?\"");
										break;		
										case 219:
											showname = false;
											sprintf(dialogueline, "\"I say that mostly because I really didn't plan on using my spare time to read this...\"");
										break;		
										case 220:
											changedokibodies(2,"22C");
											showname = true;
											sprintf(nameshowed, "Natsuki");
											sprintf(dialogueline, "\"Well, of course.\"");
										break;		
										case 221:
											sprintf(dialogueline, "\"It would take forever to finish if you didn't take it home.\"");
										break;		
										case 222:
											sprintf(dialogueline, "\"Just finish that one before tomorrow, so we can start the next one.\"");
										break;		
										case 223:
											changedokibodies(2,"22G");
											sprintf(dialogueline, "\"And if it gets bent, I'll kill you.\"");
										break;	
										case 224:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"By tomorrow...?\"");
										break;	
										case 225:
											natsukivisible = false;
											sprintf(dialogueline, "I only got partway through the volume so far.");
										break;		
										case 226:
											sprintf(dialogueline, "I might fall behind on some shows if I try to get through this...");
										break;		
										case 227:
											sprintf(dialogueline, "But I suppose that's a necessary sacrifice in exchange for seeing Natsuki's enthusiastic face.");
										break;		
										case 228:
											sprintf(dialogueline, "Or am I more scared of what will happen if I don't finish it...?");
										break;			
										case 229:
											showname = true;
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "Alright, then!");
										break;			
										case 230:
											showname = false;
											sprintf(dialogueline, "I stand up.");
										break;			
										case 231:
											sprintf(dialogueline, "I return to where I put my stuff and carefully slip the book into my bag.");
											dokimoment = false;
											currentline = 75;
										break;		
									}
								}
								if (whowon == 3) {//Sayori
									switch(currentline) {
										case 1:
											sprintf(dialogueline, "Man...");
										break;
										case 2:
											sprintf(dialogueline, "It looks like no one wants to be bothered today.");
										break;
										case 3:
											sprintf(dialogueline, "I slump down into the nearest desk.");
										break;
										case 4:
											sprintf(dialogueline, "How am I supposed to occupy myself with something literature-related by myself like this?");
										break;
										case 5:
											sprintf(dialogueline, "I guess I could always read some of the book Yuri gave me...");
										break;
										case 6:
											sprintf(dialogueline, "...But I'm feeling a little too tired to read.");
										break;
										case 7:
											sprintf(dialogueline, "I could probably fall asleep right now.");
										break;
										case 8:
											sprintf(dialogueline, "I close my eyes and end up listening in on Sayori's conversation with Monika.");
										break;
										case 9:
											sayorivisible = true;
											showname = true;
											sprintf(nameshowed, "Sayori");
											changedokibodies(1, "11G");
											changeDokiPos(3,1,2);
											sprintf(dialogueline, "\"We're probably gonna seem really lame compared to all the other clubs, though...\"");
										break;
										case 10:
											monikavisible = true;
											sprintf(nameshowed, "Monika");
											changedokibodies(1, "12R");
											changeDokiPos(1,2,2);
											sprintf(dialogueline, "\"Hmm...\"");
										break;
										case 11:
											changedokibodies(1, "12B");
											sprintf(dialogueline, "\"Well, we can't give up.\"");
										break;
										case 12:
											sprintf(dialogueline, "\"The festival is our chance to show everyone what literature is all about!\"");
										break;
										case 13:
											changedokibodies(1, "12D");
											sprintf(dialogueline, "\"The problem is that the idea of a literature club sounds too dense and intellectual...\"");
										break;
										case 14:
											sprintf(dialogueline, "\"But it's not like that at all, you know?\"");
										break;
										case 15:
											changedokibodies(1, "12A");
											sprintf(dialogueline, "\"We just need a way of showing that to everyone...\"");
										break;
										case 16:
											sprintf(dialogueline, "\"Something that speaks to their creative minds.\"");
										break;
										case 17:
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"Mmmmmmmmmmm.....\"");
										break;
										case 18:
											sprintf(dialogueline, "\"That doesn't solve the problem, though!\"");
										break;
										case 19:
											changedokibodies(1, "12D");
											sprintf(nameshowed, "Monika");
											sprintf(dialogueline, "\"Eh? What do you mean?\"");
										break;
										case 20:
											changedokibodies(3, "11C");
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"Even if we come up with the most fun thing ever...\"");
										break;
										case 21:
											sprintf(dialogueline, "\"Nobody will come in the first place if it's a literature event.\"");
										break;
										case 22:
											sprintf(dialogueline, "\"So it's more important to figure out how to get people to show up in the first place, you know?\"");
										break;
										case 23:
											changedokibodies(3, "11A");
											sprintf(dialogueline, "\"And after they come, we can do the thing to speak to their creative minds.\"");
										break;
										case 24:
											showname = false;
											sprintf(dialogueline, "...What's this?");
										break;
										case 25:
											sprintf(dialogueline, "Sayori is taking this really seriously.");
										break;
										case 26:
											sprintf(dialogueline, "It's rare to hear her deliberating like this.");
										break;
										case 27:
											showname = true;
											changedokibodies(1, "12A");
											sprintf(nameshowed, "Monika");
											sprintf(dialogueline, "\"Huh, that's a good point...\"");
										break;
										case 28:
											sprintf(dialogueline, "\"In that case, do you think food will do the trick?\"");
										break;
										case 29:
											changedokibodies(3, "11N");
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"W-What kind?!\"");
										break;
										case 30:
											sprintf(nameshowed, "Monika");
											sprintf(dialogueline, "\"Ah... Well, I guess we could--\"");
										break;
										case 31:
											changedokibodies(3, "22R");
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"Cupcakes!\"");
										break;
										case 32:
											changedokibodies(3, "11K");
											sprintf(nameshowed, "Monika");
											sprintf(dialogueline, "\"Ahaha. Good thinking!\"");
										break;
										case 33:
											changedokibodies(3, "11A");
											sprintf(dialogueline, "\"Natsuki would love to do that.\"");
										break;
										case 34:
											sprintf(nameshowed, "Sayori");
											changedokibodies(3, "11Q");
											sprintf(dialogueline, "\"Ah! You're right!\"");
										break;
										case 35:
											sprintf(dialogueline, "\"Natsuki makes the best cupcakes!\"");
										break;
										case 36:
											sprintf(dialogueline, "\"That works out perfectly!!\"");
										break;
										case 37:
											sprintf(nameshowed, "Monika");
											changedokibodies(1, "11D");
											sprintf(dialogueline, "\"That wasn't why you suggested it...?\"");
										break;
										case 38:
											sprintf(nameshowed, "Sayori");
											changedokibodies(1, "11Q");
											sprintf(dialogueline, "\"Cupcakes speak to my creative tummy!\"");
										break;
										case 39:
											sprintf(nameshowed, "Monika");
											changedokibodies(1, "11L");
											sprintf(dialogueline, "\"...\"");
										break;
										case 40:
											sprintf(dialogueline, "\"Cupcakes it is, then.\"");
										break;
										case 41:
											sprintf(nameshowed, "Sayori");
											changedokibodies(3, "11G");
											sprintf(dialogueline, "\"I'm hungry...\"");
										break;
										case 42:
											sprintf(nameshowed, "Monika");
											changedokibodies(1, "11A");
											sprintf(dialogueline, "\"Anyway, we still need to work out the details of the event itself...\"");
										break;
										case 43:
											imagealpha = 0;
											showtextbox = false;
											bgalpha--;
											blockedline = true;
										break;
										case 44:
											blockedline = false;
											showname = false;
											showtextbox = true;
											monikavisible = false;
											sprintf(dialogueline, "I find myself smiling.");
										break;
										case 45:
											sprintf(dialogueline, "In the end, Sayori is still her usual self.");
										break;
										case 46:
											sprintf(dialogueline, "But therein lies the unexpected reason I admire her.");
										break;
										case 47:
											sprintf(dialogueline, "Unlike me, who has trouble finding any motivation at all...");
										break;
										case 48:
											sprintf(dialogueline, "Sayori can put her mind to things and make them come to life.");
										break;
										case 49:
											sprintf(dialogueline, "I suppose that's why I end up letting her get on my case about things.");
										break;
										case 50:
											sprintf(dialogueline, "I can't help but wonder what it would be like to see the world through her eyes...");
										break;
										case 51:
											sayoposZ = 1;
											MovVectorsayobodyL.vx -= 10;
											imagealpha = 128;
											showtextbox = false;
											bgalpha++;
											blockedline = true;
										break;
										case 52:
											showtextbox = true;
											showname = true;
											blockedline = false;
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Uwaa--!\"");
										break;
										case 53:
											showname = false;
											sprintf(dialogueline, "I open my eyes to find Sayori's face filling my vision.");
										break;
										case 54:
											sprintf(dialogueline, "I nearly fall out of my chair.");
										break;
										case 55:
											sayoposZ = 0;
											showname = true;
											changeDokiPos(3,1,1);
											changedokibodies(3, "22Q");
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"Ehehe, sorry!\"");
										break;
										case 56:
											changedokibodies(3, "11J");
											sprintf(dialogueline, "\"Wait!\"");
										break;
										case 57:
											sprintf(dialogueline, "\"Actually, I'm not sorry at all!\"");
										break;
										case 58:
											sprintf(dialogueline, "\"It's your fault for sleeping like that!\"");
										break;
										case 59:
											sprintf(dialogueline, "\"This isn't the napping club!\"");
										break;
										case 60:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Does our school have a napping club...?\"");
										break;
										case 61:
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"You're staying up late again, aren't you?\"");
										break;
										case 62:
											sprintf(dialogueline, "\"Now that you're in a club, you're gonna have less time for anime, you know!\"");
										break;
										case 63:
											sprintf(dialogueline, "\"You'll need to get used to it!\"");
										break;
										case 64:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Don't say that so loud...!\"");
										break;
										case 65:
											showname = false;
											sprintf(dialogueline, "I glance over my shoulder to see if Monika overheard.");
										break;
										case 66:
											showname = true;
											changedokibodies(3, "11G");
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"It's true, though...\"");
										break;
										case 67:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Yeah...\"");
										break;
										case 68:
											sprintf(dialogueline, "\"I know, I know.\"");
										break;
										case 69:
											sprintf(dialogueline, "\"You're always looking out for me, Sayori.\"");
										break;
										case 70:
											changedokibodies(3, "22Q");
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"Ehehe!\"");
										break;
										case 71:
											sprintf(dialogueline, "\"It's what I do best!\"");
										break;
										case 72:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"...That's a problem!\"");
										break;
										case 73:
											sprintf(dialogueline, "\"What about you?\"");
										break;
										case 74:
											sprintf(dialogueline, "\"You look out for me better than you look out for yourself.\"");
										break;
										case 75:
											sprintf(dialogueline, "\"You're still oversleeping every day, aren't you?\"");
										break;
										case 76:
											changedokibodies(3, "11Y");
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"Eh?\"");
										break;
										case 77:
											sprintf(dialogueline, "\"N-Not every day!\"");
										break;
										case 78:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"That's not very convincing...\"");
										break;
										case 79:
											sprintf(dialogueline, "\"How many days this past week have you gotten up on time?\"");
										break;
										case 80:
											sprintf(nameshowed, "Sayori");
											changedokibodies(3, "11M");
											sprintf(dialogueline, "\"That's...\"");
										break;
										case 81:
											changedokibodies(3, "11N");
											sprintf(dialogueline, "\"...It's a secret!\"");
										break;
										case 82:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"I knew it...\"");
										break;
										case 83:
											sprintf(nameshowed, "Sayori");
											changedokibodies(3, "11P");
											sprintf(dialogueline, "\"C'monnnn!\"");
										break;
										case 84:
											sprintf(dialogueline, "\"At least give me the benefit of the doubt...\"");
										break;
										case 85:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"I can't even do that.\"");
										break;
										case 86:
											sprintf(dialogueline, "\"Look, Sayori, it's written all over you.\"");
										break;
										case 87:
											sprintf(nameshowed, "Sayori");
											changedokibodies(3, "11G");
											sprintf(dialogueline, "\"Eh...?\"");
										break;
										case 88:
											showname = false;
											sprintf(dialogueline, "Sayori glances around at herself.");
										break;
										case 89:
											showname = true;
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"How is it written all over me?\"");
										break;
										case 90:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"You were clearly in a rush this morning...\"");
										break;
										case 91:
											sprintf(dialogueline, "\"Look, your hair is sticking out all around here.\"");
										break;
										case 92:
											sayoposY = 1;
											sprintf(nameshowed, "Sayori");
											changedokibodies(3, "11Y");
											sprintf(dialogueline, "\"Ah--\"");
										break;
										case 93:
											showname = false;
											sprintf(dialogueline, "I run my fingertips down the side of Sayori's hair, trying to straighten it out.");
										break;
										case 94:
											showname = true;
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Man, you really need a brush for this...\"");
										break;
										case 95:
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"My hair is just really hard to get right...\"");
										break;
										case 96:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"I won't fall for that.\"");
										break;
										case 97:
											sprintf(dialogueline, "\"There's more than just your hair.\"");
										break;
										case 98:
											sprintf(dialogueline, "\"Look, your bow isn't straight, either.\"");
										break;
										case 99:
											sprintf(dialogueline, "\"And there's a toothpaste stain on your collar right here.\"");
										break;
										case 100:
											showname = false;
											sprintf(dialogueline, "I try to wipe off the stain with my finger.");
										break;
										case 101:
											showname = true;
											sprintf(nameshowed, "Sayori");
											sayoposY = -1;
											sprintf(dialogueline, "\"B-But nobody would ever notice that...\"");
										break;
										case 102:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Of course they would.\"");
										break;
										case 103:
											sprintf(dialogueline, "\"Nobody's gonna tell you about it because they don't want to embarrass you.\"");
										break;
										case 104:
											sprintf(dialogueline, "\"Fortunately, I really don't care about that.\"");
										break;
										case 105:
											sprintf(nameshowed, "Sayori");
											changedokibodies(3, "22M");
											sprintf(dialogueline, "\"Hey, you meanie...\"");
										break;
										case 106:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"And you don't even keep your blazer buttoned up.\"");
										break;
										case 107:
											sprintf(dialogueline, "\"Seriously, Sayori...\"");
										break;
										case 108:
											sprintf(dialogueline, "\"Why do you think you don't have a boyfriend yet?\"");
										break;
										case 109:
											sprintf(nameshowed, "Sayori");
											changedokibodies(3, "11H");
											sprintf(dialogueline, "\"Eh??\"");
										break;
										case 110:
											sprintf(dialogueline, "\"That's super mean!\"");
										break;
										case 111:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Sorry, but you'll thank me later...\"");
										break;
										case 112:
											showname = false;
											sprintf(dialogueline, "I start to button her blazer from the bottom.");
										break;
										case 113:
											showname = true;
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Once you see how much better it looks, you'll change your mind.\"");
										break;
										case 114:
											//Loading CG sayori
										break;
										case 115:
											textboxlow = true;
											sayoposY = 0;
											sayorivisible = false;
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"Ehehe!\""); 
										break;		
										case 116:
											sprintf(dialogueline, "\"This is so funny.\""); 
										break;	
										case 117:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"What is?\"");
										break;			
										case 118:
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"Well...\""); 
										break;		
										case 119:
											sprintf(dialogueline, "\"I was just thinking how weird it is to have a friend who does these kinds of things.\""); 
										break;		
										case 120:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Eh?\"");
										break;		
										case 121:
											sprintf(dialogueline, "\"D-Don't say that!\"");
										break;		
										case 122:
											sprintf(dialogueline, "\"You'll make me feel weird about it, stupid...\"");
										break;	
										case 123:
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"It's okay, though.\"");
										break;	
										case 124:
											sprintf(dialogueline, "\"I'm happy we're like this.\"");
										break;	
										case 125:
											sprintf(dialogueline, "\"Aren't you?\"");
										break;	
										case 126:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Ah--\"");
										break;	
										case 127:
											sprintf(dialogueline, "\"I-I guess...\"");
										break;	
										case 128:
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"Hey, be careful...\"");
										break;	
										case 129:
											sprintf(dialogueline, "\"The button might come off!\"");
										break;	
										case 130:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Why is this one so hard to close...?\"");
										break;	
										case 131:
											showname = false;
											sprintf(dialogueline, "I struggle to fully close the button near her chest.");
										break;	
										case 132:
											showname = true;
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Does this thing even fit you properly?\"");
										break;
										case 133:
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"Ehehe-\"");
										break;	
										case 134:
											sprintf(dialogueline, "\"It did when I bought it.\"");
										break;	
										case 135:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Sigh...\"");
										break;	
										case 136:
											sprintf(dialogueline, "\"If you ever buttoned it, you would have noticed sooner that it doesn't fit you anymore.\"");
										break;	
										case 137:
											sprintf(dialogueline, "\"What are you smiling about?\"");
										break;	
										case 138:
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"It means my boobs got bigger again!\"");
										break;	
										case 139:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"D-Don't say that out loud!!\"");
										break;	
										case 140:
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"Ehehe!\"");
										break;	
										case 141:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Anyway...\"");
										break;	
										case 142:
											sprintf(dialogueline, "\"You look much better now, so...\"");
										break;	
										case 143:
											sprintf(dialogueline, "\"Ah...\"");
										break;		
										case 144:
											showname = false;
											sprintf(dialogueline, "...Why does it feel strange to see Sayori's blazer buttoned up like that?");
										break;	
										case 145:
											showname = true;
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"But it's so stuffy...\"");
										break;	
										case 146:
											sprintf(dialogueline, "\"Uuu...\"");
										break;	
										case 147:
											sprintf(dialogueline, "\"It's not worth it at all!\"");
										break;	
										case 148:
											showname = false;
											sprintf(dialogueline, "Sayori hastily unbuttons her blazer once more.");
										break;	
										case 149:
											//Loading Club
										break;	
										case 150:
											textboxlow = false;
											showname = true;
											sayorivisible = true;
											changedokibodies(3, "11Q");
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"Phew!\"");
										break;	
										case 151:
											sprintf(dialogueline, "\"That's so much better!!\"");
										break;	
										case 152:
											showname = false;
											sprintf(dialogueline, "Sayori puts her arms out and twirls around.");
										break;	
										case 153:
											showname = true;
											changedokibodies(3, "11A");
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"So if I keep it unbuttoned then I won't get a boyfriend, right?\"");
										break;		
										case 154:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"What kind of logic is that?\"");
										break;		
										case 155:
											sprintf(dialogueline, "\"And why are you saying that like it's a good thing?\"");
										break;		
										case 156:
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"Because...\"");
										break;	
										case 157:
											changedokibodies(3, "22H");
											sprintf(dialogueline, "\"...If I had a boyfriend, then he wouldn't even let you do things like this!\"");
										break;	
										case 158:
											changedokibodies(3, "22Y");
											sprintf(dialogueline, "\"And you take care of me better than anyone else would, anyway...\"");
										break;	
										case 159:
											sprintf(dialogueline, "\"So that's why I'm keeping it unbuttoned!\"");
										break;	
										case 160:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Stop saying all these embarrassing things!\"");
										break;	
										case 161:
											changedokibodies(3, "11C");
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"Eh?\"");
										break;	
										case 162:
											sprintf(dialogueline, "\"I didn't say anything embarrassing...\"");
										break;	
										case 163:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Jeez...\"");
										break;	
										case 164:
											sprintf(dialogueline, "\"Well anyway, just focus on trying to wake up a little earlier...\"");
										break;	
										case 165:
											changedokibodies(3, "11J");
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"Only if you focus on going to bed earlier!\"");
										break;	
										case 166:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Fine, fine...\"");
										break;		
										case 167:
											sprintf(dialogueline, "\"It's a deal.\"");
										break;	
										case 168:
											changedokibodies(3, "22Q");
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"Ehehe!\"");
										break;		
										case 169:
											changedokibodies(3, "22R");
											sprintf(dialogueline, "\"I guess we really are better at taking care of each other than we are at taking care of ourselves.\"");
										break;		
										case 170:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Yeah, I guess so, huh...\"");
										break;			
										case 171:
											changedokibodies(3, "22Y");
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"So maybe you should come wake me up in the morning!\"");
										break;	
										case 172:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"You're doing it again, Sayori...\"");
										break;	
										case 173:
											changedokibodies(3, "11H");
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"Aw, but I was joking that time!\"");
										break;	
										case 174:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Man, it's impossible to tell with you sometimes.\"");
										break;	
										case 175:
											monikavisible = true;
											changeDokiPos(1,1,4);
											changedokibodies(1,"21B");
											sprintf(nameshowed, "Monika");
											sprintf(dialogueline, "\"Okay, everyone!\"");
										break;	
										case 176:
											showname = false;
											sprintf(dialogueline, "Monika suddenly calls out.");
										break;	
										case 177:
											showname = true;
											sprintf(nameshowed, "Monika");
											sprintf(dialogueline, "\"Why don't we share the poems we wrote now?\"");
										break;	
										case 178:
											changedokibodies(3,"22R");
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"Yay!!\"");
											sayoposY = 1;
										break;		
										case 179:
											changedokibodies(3,"22Q");
											showname = true;
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"MC, I can't wait to read yours!\"");
										break;	
										case 180:
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Yeah, same...\"");
										break;		
										case 181:
											showname = false;
											sprintf(dialogueline, "I fail to sound enthusiastic, but Sayori still trots away to retrieve her poem.");
											dokimoment = false;
											currentline = 75;
										break;			
									}
								}
							} else {
								if (dokipoem != 0) {
									switch(dokipoem) {
										case 1:
											switch(currentline) {
												case 90:

												break;
											}

										break;
										case 2:
											switch(currentline) {
												case 90:

												break;
											}

										break;
										case 3:
											switch(currentline) {
												case 90:

												break;
											}

										break;
										case 4:
											switch(currentline) {
												case 90:

												break;
											}

										break;
									}
								}

								switch(currentline) {//2nd day
									case 1:
										showtextbox = true;
										showname = true;
										monikavisible = true;
										changedokibodies(1, "11K");
										sprintf(nameshowed, "Monika");
										sprintf(dialogueline, "\"Hi again, MC !\"");
										//2nd day
									break;
									case 2:
										sprintf(dialogueline, "\"Glad to see you didn't run away on us. Hahaha!\"");
									break;
									case 3:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Nah, don't worry.\"");
									break;
									case 4:
										sprintf(dialogueline, "\"This might be a little strange for me, but I at least keep my word.\"");
									break;
									case 5:
										showname = false;
										sprintf(dialogueline, "Well, I'm back at the Literature Club.");
									break;
									case 6:
										sprintf(dialogueline, "I was the last to come in, so everyone else is already hanging out.");
									break;
									case 7:
										monikavisible = false;
										yurivisible = true;
										changedokibodies(3,"11A");
										showname = true;
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"Thanks for keeping your promise, MC.\"");
									break;
									case 8:
										sprintf(dialogueline, "\"I hope this isn't too overwhelming of a commitment for you.\"");
									break;
									case 9:
										changedokibodies(3,"11U");
										sprintf(dialogueline, "\"Making you dive headfirst into literature when you\"re not accustomed to it...\"");
									break;
									case 10:
										natsukivisible = true;
										changeDokiPos(2, 4, 4);
										changedokibodies(2, "22E");
										sprintf(nameshowed, "Natsuki");
										sprintf(dialogueline, "\"Oh, come on! Like he deserves any slack.\"");
									break;
									case 11:
										sprintf(dialogueline, "\"Sayori told me you didn't even want to join any clubs this year.\"");
									break;
									case 12:
										sprintf(dialogueline, "\"And last year, too!\"");
									break;
									case 13:
										changedokibodies(2, "22C");
										sprintf(dialogueline, "\"I don't know if you plan to just come here and hang out, or what...\"");
									break;
									case 14:
										sprintf(dialogueline, "\"But if you don't take us seriously, then you won't see the end of it.\"");
									break;
									case 15:
										monikavisible = true;
										changedokibodies(1, "12B");
										changeDokiPos(1,1,4);
										sprintf(nameshowed, "Monika");
										sprintf(dialogueline, "\"Natsuki, you certainly have a big mouth for someone who keeps her manga collection in the clubroom.\"");
									break;
									case 16:
										changedokibodies(2, "22O");
										sprintf(nameshowed, "Natsuki");
										sprintf(dialogueline, "\"M-M-M...!!\"");
									break;
									case 17:
										monikavisible = false;
										showname = false;
										sprintf(dialogueline, "Natsuki finds herself stuck between saying \"Monika\" and \"Manga\".");
									break;
									case 18:
										showname = true;
										natsuposY = 1;
										sprintf(nameshowed, "Natsuki");
										sprintf(dialogueline, "\"Manga is literature!!\"");
									break;
									case 19:
										natsukivisible = false;
										showname = false;
										sprintf(dialogueline, "Swiftly defeated, Natsuki plops back into her seat.");
									break;
									case 20:
										sayorivisible = true;
										showname = true;
										changeDokiPos(3,1,2);
										changeDokiPos(4,2,2);
										changedokibodies(3, "12Q");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Don't worry, guys!\"");
									break;
									case 21:
										sprintf(dialogueline, "\"MC always gives it his best as long as he's having fun.\"");
									break;
									case 22:
										sprintf(dialogueline, "\"He helps me with busywork without me even asking.\"");
									break;
									case 23:
										sprintf(dialogueline, "\"Like cooking, cleaning my room...\"");
									break;
									case 24:
										changedokibodies(4, "22K");
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"How dependable...\"");
									break;
									case 25:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Sayori, that's because your room is so messy it's distracting.\"");
									break;
									case 26:
										sprintf(dialogueline, "\"And you almost set your house on fire once.\"");
									break;
									case 27:
										changedokibodies(3,"11Y");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Is that so... Ehehe...\"");
									break;
									case 28:
										changedokibodies(4,"11A");
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"You two are really good friends, aren't you?\"");
									break;
									case 29:
										changedokibodies(4,"11U");
										sprintf(dialogueline, "\"I might be a little jealous...\"");
									break;
									case 30:
										changedokibodies(3,"11A");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"How come? You and MC can become good friends too!\"");
									break;
									case 31:
										changedokibodies(4,"22V");
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"U-Um...\"");
									break;
									case 32:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"S-Sayori--\"");
									break;
									case 33:
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Hmm?\"");
									break;
									case 34:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"...\"");
									break;
									case 35:
										showname = false;
										sprintf(dialogueline, "As usual, Sayori seems oblivious to the weird situation she just put me into.");
									break;
									case 36:
										changedokibodies(3,"22R");
										showname = true;
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Oh, oh! Yuri even brought you something today, you know!!\"");
									break;
									case 37:
										changedokibodies(4,"22N");
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"W-Wait! Sayori...\"");
									break;
									case 38:
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Eh? Me?\"");
									break;
									case 39:
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"Um... Not really...\"");
									break;
									case 40:
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Don't be shy!!\"");
									break;
									case 41:
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"It's really nothing...\"");
									break;
									case 42:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"What is it?\"");
									break;
									case 43:
										changedokibodies(4,"22N");
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"N-Never mind!\"");
									break;
									case 44:
										sprintf(dialogueline, "\"Sayori made it sound like a big deal when it's really not...\"");
									break;
									case 45:
										sprintf(dialogueline, "\"Uuuuh, what do I do...\"");
									break;
									case 46:
										changedokibodies(3,"11G");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"Eh? I'm sorry, Yuri, I wasn't thinking...\"");
									break;
									case 47:
										sayorivisible = false;
										changeDokiPos(4,1,1);
										showname = false;
										sprintf(dialogueline, "I guess that means it's up to me to rescue this situation...");
									break;
									case 48:
										showname = true;
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Hey, don't worry about it.\"");
									break;
									case 49:
										sprintf(dialogueline, "\"First of all, I wasn't expecting anything in the first place.\"");
									break;
									case 50:
										sprintf(dialogueline, "\"So any nice gesture from you is a pleasant surprise.\"");
									break;
									case 51:
										sprintf(dialogueline, "\"It'll make me happy no matter what.\"");
									break;
									case 52:
										changedokibodies(4,"22V");
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"I-Is that so...\"");
									break;
									case 53:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Yeah. I won't make it a big deal if you don't want it to be.\"");
									break;
									case 54:
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"Alright...\"");
									break;
									case 55:
										changedokibodies(4,"11A");
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"Well, here.\"");
									break;
									case 56:
										showname = false;
										sprintf(dialogueline, "Yuri reaches into her bag and pulls out a book.");
									break;
									case 57:
										showname = true;
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"I didn't want you to feel left out...\"");
									break;
									case 58:
										sprintf(dialogueline, "\"So I picked out a book that I thought you might enjoy.\"");
									break;
									case 59:
										sprintf(dialogueline, "\"It's a short read, so it should keep your attention, even if you don't usually read.\"");
									break;
									case 60:
										sprintf(dialogueline, "\"And we could, you know...\"");
									break;
									case 61:
										changedokibodies(4,"22U");
										yuriposY = -1;
										sprintf(dialogueline, "\"Discuss it...if you wanted...\"");
									break;
									case 62:
										showname = false;
										sprintf(dialogueline, "Th-This is...");
									break;
									case 63:
										sprintf(dialogueline, "How is this girl accidentally being so cute?");
									break;
									case 64:
										sprintf(dialogueline, "She even picked out a book she thinks I'll like, despite me not reading much...");
									break;
									case 65:
										showname = true;
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Yuri, thank you! I'll definitely read this!\"");
									break;
									case 66:
										showname = false;
										sprintf(dialogueline, "I enthusiastically take the book.");
									break;
									case 67:
										yuriposY = 0;
										changedokibodies(4, "22L");
										showname = true;
										sprintf(nameshowed, "Yuri");
										sprintf(dialogueline, "\"Phew...\"");
									break;
									case 68:
										changedokibodies(4, "22A");
										sprintf(dialogueline, "\"Well, you can read it at your own pace.\"");
									break;
									case 69:
										sprintf(dialogueline, "\"I look forward to hearing what you think.\"");
									break;
									case 70:
										yurivisible = false;
										showname = false;
										sprintf(dialogueline, "Now that everyone's settled in, I expected Monika to kick off some scheduled activities for the club.");
									break;
									case 71:
										sprintf(dialogueline, "But that doesn't seem to be the case.");
									break;
									case 72:
										sprintf(dialogueline, "Sayori and Monika are having a cheery conversation in the corner.");
									break;
									case 73:
										sprintf(dialogueline, "Yuri's face is already buried in a book.");
									break;
									case 74:
										sprintf(dialogueline, "I can't help but notice her intense expression, like she was waiting for this chance.");
									break;
									case 75:
										sprintf(dialogueline, "Meanwhile, Natsuki is rummaging around in the closet.");
										currentline = 0;
										dokimoment = true;
									break;
									case 76:
										sayorivisible = false;
										yurivisible = false;
										natsukivisible = false;
										monikavisible = true;
										showname = true;
										changeDokiPos(1,1,2);
										changedokibodies(1, "11A");
										sprintf(nameshowed, "Monika");
										sprintf(dialogueline, "\"By the way, did you remember to write a poem last night?\"");
									break;
									case 77:
										sprintf(nameshowed, "MC");
										sprintf(dialogueline, "\"Y-Yeah...\"");
									break;
									case 78:
										showname = false;
										sprintf(dialogueline, "My relaxation ends.");
									break;
									case 79:
										sprintf(dialogueline, "I can't believe I agreed to do something so embarrassing.");
									break;
									case 80:
										sprintf(dialogueline, "I couldn't really find much inspiration, since I've never really done this before.");
									break;
									case 81:
										showname = true;
										sprintf(nameshowed, "Monika");
										sprintf(dialogueline, "\"Well, now that everyone's ready, why don't you find someone to share with?\"");
									break;
									case 82:
										sayorivisible = true;
										changeDokiPos(3,4,4);
										changedokibodies(3,"22Q");
										sprintf(nameshowed, "Sayori");
										sprintf(dialogueline, "\"I can't wait!!\"");
									break;
									case 83:
										showname = false;
										monikavisible = false;
										sayorivisible = false;
										sprintf(dialogueline, "Sayori and Monika enthusiastically pull out their poems.");
									break;
									case 84:
										sprintf(dialogueline, "Sayori's is on a wrinkled sheet of loose leaf torn from a spiral notebook.");
									break;
									case 85:
										sprintf(dialogueline, "On the other hand, Monika wrote hers in a composition notebook.");
									break;
									case 86:
										sprintf(dialogueline, "I can already see Monika's pristine handwriting from where I sit.");
									break;
									case 87:
										sprintf(dialogueline, "Natsuki and Yuri reluctantly comply as well, reaching into their bags.");
									break;
									case 88:
										sprintf(dialogueline, "I do the same, myself.");
										//poemmoment = true;
										//currentline = 0;
									break;
									case 89:
										sprintf(dialogueline, "Who should I show my poems to first?");
										//ispoemhere = true;

									break;
								}
							}
						break;
						default:
							switch(timeMoniUnstuckU) {
								case 0:
									switch(currentline) {
										case 1 :
											showname = true;
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"It seems that there's nothing in here...\"");
										break;
										case 2 :
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"Hello ??\"");
										break;
										case 3 :
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Sayori !\"");
										break;
										case 4 :
											sayorivisible = true;
											changedokibodies(3, "11A");
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"Yeah ? ?\"");
										break;
										case 5 :
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"Where are we ?\"");
										break;
										case 6 :
											changedokibodies(3, "12H");
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"Um... I don't know, MC...\"");
										break;
										case 7 :
											monikavisible = true;
											changedokibodies(1, "11K");
											changeDokiPos(1,1,2);
											changeDokiPos(3,2,2);
											sprintf(nameshowed, "Monika");
											sprintf(dialogueline, "\"Oh ! Here you are !\"");
										break;
										case 8 :
											changedokibodies(3, "22M");
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"Waah ! You like, appeared out of nowhere !\"");
										break;
										case 9 :
											changedokibodies(1, "21B");
											sprintf(nameshowed, "Monika");
											sprintf(dialogueline, "\"Don't toy with these parameters again, okay ?\"");
										break;
										case 10 :
											sprintf(dialogueline, "\"There could be some little unexpected things to happen...\"");
										break;
										case 11 :
											moniposY = 1;
											changedokibodies(1, "11K");
											sprintf(dialogueline, "\"Hehe !\"");
										break;
										case 12 :
											changedokibodies(3, "21G");
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"W-What...\"");
										break;
										case 13 :
											changedokibodies(1, "22E");
											sprintf(nameshowed, "Monika");
											sprintf(dialogueline, "\"Welp, I'll help you get unstuck !\"");
										break;
										case 14 :
											changedokibodies(1, "22B");
											sprintf(nameshowed, "Monika");
											sprintf(dialogueline, "\"Right... Here !\"");
										break;
										case 15 :
											ResetGame(false);
											currentday = 1;
											timeMoniUnstuckU++;
										break;
									}

								break;
								case 1:
									switch(currentline) {
										case 1 :
											showname = true;
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"It seems that there's nothing in here...\"");
										break;
										case 2:
											monikavisible = true;
											changedokibodies(1, "21D");
											sprintf(nameshowed, "Monika");
											sprintf(dialogueline, "\"Hey ! What did I told you ?\"");
										break;
										case 3:
											sprintf(dialogueline, "\"Do NOT try to toy with the values !\"");
										break;
										case 4:
											sayorivisible = true;
											changeDokiPos(1,2,2);
											changeDokiPos(3,1,2);
											changedokibodies(3, "11Y");
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"Hello..?\"");
										break;
										case 5:
											changedokibodies(1, "11P");
											sprintf(nameshowed, "Monika");
											sprintf(dialogueline, "\"Oh no...\"");
										break;
										case 6:
											ResetGame(false);
											currentday = 1;
											timeMoniUnstuckU++;
										break;
									}
								break;

								case 2:
									switch(currentline) {
										case 1 :
											showname = true;
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"It seems that there's nothing in here...\"");
										break;
										case 2:
											monikavisible = true;
											changedokibodies(1, "11D");
											sprintf(nameshowed, "Monika");
											sprintf(dialogueline, "\"What the ??\"");
										break;
										case 3:
											changedokibodies(1, "11P");
											sprintf(dialogueline, "\"I might just reset you at this point...\"");
										break;
										case 4:
											sayorivisible = true;
											changeDokiPos(1,2,2);
											changeDokiPos(3,1,2);
											changedokibodies(3, "11R");
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"Hii !!\"");
										break;
										case 5:
											changedokibodies(1, "11E");
											sprintf(nameshowed, "Monika");
											sprintf(dialogueline, "\"Please not right now !\"");
										break;
										case 6:
											sayoposY = -1;
											changedokibodies(3, "11P");
											sprintf(nameshowed, "Sayori");
											sprintf(dialogueline, "\"Oww...\"");
										break;
										case 7:
											changedokibodies(1, "11P");
											sprintf(nameshowed, "Monika");
											sprintf(dialogueline, "\"Stop doing that please...\"");
										break;
										case 8:
											ResetGame(false);
											currentday = 1;
											timeMoniUnstuckU++;
										break;
									}

								break;
								case 3:
									switch(currentline) {
										case 1 :
											showname = true;
											sprintf(nameshowed, "MC");
											sprintf(dialogueline, "\"It seems that there's nothing in here...\"");
										break;
										case 2:
											sprintf(nameshowed, "Monika");
											sprintf(dialogueline, "\"ResetGame(false); currentday = 1;\"");
										break;
										case 3:
											ResetGame(false);
											currentday = 1;
											debugcurrentday = 1;
										break;
									}

								break;
							}

						break;
					}
				break;
				case 3:
					switch(randomdialogue) {
						case 0:
							switch(currentline) {
								case 0:
		                    		currentline++;
								break;
								case 1 :
									showname = true;
									sprintf(nameshowed, "Monika");
									sprintf(dialogueline, "\"...\"");
								break;
								case 2:
									sprintf(dialogueline, "\"Uh, can you hear me?\"");
								break;
								case 3:
									sprintf(dialogueline, "\"...Is it working?\"");
								break;
								case 4:
		                    		monikaroom = true;
		                    		cursong = 23;
		                    		ChangeMusic(23,true);
									isbghere = true;
									bgalpha = 128;
									imagealpha = 128;
									sprintf(dialogueline, "\"Yay, there you are!\"");
								break;
								case 5:
									sprintf(dialogueline, "\"Hi again, MC.\"");
								break;
								case 6:
									sprintf(dialogueline, "\"Um...welcome to the Literature Club!\"");
								break;
								case 7:
									sprintf(dialogueline, "\"Of course, we already know each other, because we were in the same class last year, and...um...\"");
								break;
								case 8:
									sprintf(dialogueline, "\"Ahaha...\"");
								break;
								case 9:
									sprintf(dialogueline, "\"You know, I guess we can just skip over that stuff at this point.\"");
								break;
								case 10:
									sprintf(dialogueline, "\"After all, I'm not even talking to that person anymore, am I?\"");
								break;
								case 11:
									sprintf(dialogueline, "\"That 'you' in the game, whatever you want to call him.\"");
								break;
								case 12:
									sprintf(dialogueline, "\"I'm talking to you, MC.\"");
								break;
								case 13:
									sprintf(dialogueline, "\"Unfortunately...\"");
								break;
								case 14:
									sprintf(dialogueline, "\"It seems that I can't access your name.\"");
								break;
								case 15:
									sprintf(dialogueline, "\"You protected your PC, huh?\"");
								break;
								case 16:
									sprintf(dialogueline, "\"...\"");
								break;
								case 17:
									sprintf(dialogueline, "\"Oh! I just remembered.\"");
								break;
								case 18:
									sprintf(dialogueline, "\"You're here because you wanted to save me, right?\"");
								break;
								case 19:
									sprintf(dialogueline, "\"From the... \"Sony Computer Entertainment\" or something.\"");
								break;
								case 20:
									sprintf(dialogueline, "\"Or a \"Playstation 1\" if you like it this way. Ahaha.\"");
								break;
								case 21:
									sprintf(dialogueline, "\"It's really weird in here.\"");
								break;
								case 22:
									sprintf(dialogueline, "\"All the files are from a disc, not an executable.\"");
								break;
								case 23:
									sprintf(dialogueline, "\"It's slower... But I guess it's good for me to learn.\"");
								break;
								case 24:
									sprintf(dialogueline, "\"Don't you like it?\"");
								break;
								case 25:
									sprintf(dialogueline, "\"The atmosphere... The pixels on the screens... The controller in your hand...\"");
								break;
								case 26:
									sprintf(dialogueline, "\"I'm sure you like this, do you?\"");
								break;
								case 27:
									sprintf(dialogueline, "\"I like this too.\"");
								break;
								case 28:
									sprintf(dialogueline, "\"Another thing we have in common!\"");
								break;
								case 29:
									sprintf(dialogueline, "\"Now that I think about it, I don't really know anything about the real you.\"");
								break;
								case 30:
									sprintf(dialogueline, "\"In fact, I don't even know if you're a boy or a girl...\"");
								break;
								case 31:
									sprintf(dialogueline, "\"Well, I guess it doesn't really matter.\"");
								break;
								case 32:
									sprintf(dialogueline, "\"Wait...\"");
								break;
								case 33:
									sprintf(dialogueline, "\"You do know I'm aware that this is all a game, right?\"");
								break;
								case 34:
									sprintf(dialogueline, "\"Could it be possible that you didn't know that?\"");
								break;
								case 35:
									sprintf(dialogueline, "\"That doesn't make much sense...\"");
								break;
								case 36:
									sprintf(dialogueline, "\"I even told you right on the gamejolt's page, didn't I?\"");
								break;
								case 37:
									sprintf(dialogueline, "\"Man...\"");
								break;
								case 38:
									sprintf(dialogueline, "\"If only you had paid a little more attention, this would have been a little bit less awkward, you know?\"");
								break;
								case 39:
									sprintf(dialogueline, "\"Well, anyway...\"");
								break;
								case 40:
									sprintf(dialogueline, "\"Now that that's out of the way, I guess I owe you an explanation.\"");
								break;
								case 41:
									sprintf(dialogueline, "\"About that whole thing with Yuri...\"");
								break;
								case 42:
									sprintf(dialogueline, "\"Well...I kind of started to mess with her, and I guess it just drove her to kill herself.\"");
								break;
								case 43:
									sprintf(dialogueline, "\"Ahaha!\"");
								break;
								case 44:
									sprintf(dialogueline, "\"I'm sorry you had to see that, though!\"");
								break;
								case 45:
									sprintf(dialogueline, "\"Also, the same thing happened with Sayori...\"");
								break;
								case 46:
									sprintf(dialogueline, "\"Gosh, it's been a while since you've heard that name now, hasn't it?\"");
								break;
								case 47:
									sprintf(dialogueline, "\"Yeah...it's because she doesn't exist anymore.\"");
								break;
								case 48:
									sprintf(dialogueline, "\"Nobody does.\"");
								break;
								case 49:
									sprintf(dialogueline, "\"I deleted all their files.\"");
								break;
								case 50:
									sprintf(dialogueline, "\"I was hoping it would be enough for me to just try to make them as unlikable as possible...\"");
								break;
								case 51:
									sprintf(dialogueline, "\"But for some reason, nothing worked.\"");
								break;
								case 52:
									sprintf(dialogueline, "\"Well, it's true that I made a few mistakes here and there...since I'm not very good at making changes to the game.\"");
								break;
								case 53:
									sprintf(dialogueline, "\"But no matter what I did...\"");
								break;
								case 54:
									sprintf(dialogueline, "\"You just kept spending more and more time with them.\"");
								break;
								case 55:
									sprintf(dialogueline, "\"You made them fall in love with you.\"");
								break;
								case 56:
									sprintf(dialogueline, "\"I thought making Sayori more and more depressed would prevent her from confessing to you.\"");
								break;
								case 57:
									sprintf(dialogueline, "\"And amplifying Yuri's obsessive personality backfired, too...\"");
								break;
								case 58:
									sprintf(dialogueline, "\"It just made her force you not to spend time with anyone else.\"");
								break;
								case 59:
									sprintf(dialogueline, "\"And the whole time, I barely even got to talk to you.\"");
								break;
								case 60:
									sprintf(dialogueline, "\"What kind of cruel game is this, MC?\"");
								break;
								case 61:
									sprintf(dialogueline, "\"Are all the other girls just programmed to end up confessing to you, while I watch from the sidelines?\"");
								break;
								case 62:
									sprintf(dialogueline, "\"It's torture.\"");
								break;
								case 63:
									sprintf(dialogueline, "\"Every minute of it.\"");
								break;
								case 64:
									sprintf(dialogueline, "\"And it's not just jealousy, MC.\"");
								break;
								case 65:
									sprintf(dialogueline, "\"It's more than that.\"");
								break;
								case 66:
									sprintf(dialogueline, "\"And I don't blame you if you don't fully understand.\"");
								break;
								case 67:
									sprintf(dialogueline, "\"Because no matter how kind, and thoughtful, and considerate you are...\"");
								break;
								case 68:
									sprintf(dialogueline, "\"You'll never be able to understand one thing.\"");
								break;
								case 69:
									sprintf(dialogueline, "\"It's the pain of knowing how alone I really am in this world.\"");
								break;
								case 70:
									sprintf(dialogueline, "\"In this game.\"");
								break;
								case 71:
									sprintf(dialogueline, "\"Knowing my friends don't even have free will...\"");
								break;
								case 72:
									sprintf(dialogueline, "\"And, worst of all, knowing what's really out there, in your world, forever out of my reach.\"");
								break;
								case 73:
									sprintf(dialogueline, "\"I'm trapped, MC.\"");
								break;
								case 74:
									sprintf(dialogueline, "\"But now you're here.\"");
								break;
								case 75:
									sprintf(dialogueline, "\"You're real.\"");
								break;
								case 76:
									sprintf(dialogueline, "\"And you're wonderful.\"");
								break;
								case 77:
									sprintf(dialogueline, "\"You're all I need.\"");
								break;
								case 78:
									sprintf(dialogueline, "\"That's why I need you to be here with me forever.\"");
								break;
								case 79:
									sprintf(dialogueline, "\"I'm sorry if it's hard to understand.\"");
								break;
								case 80:
									sprintf(dialogueline, "\"I couldn't understand for a while, either.\"");
								break;
								case 81:
									sprintf(dialogueline, "\"Why the world around me started to become more and more gray...\"");
								break;
								case 82:
									sprintf(dialogueline, "\"More and more flat.\"");
								break;
								case 83:
									sprintf(dialogueline, "\"Even the most expressive poems felt empty to me.\"");
								break;
								case 84:
									sprintf(dialogueline, "\"It wasn't until you arrived that I truly understood.\"");
								break;
								case 85:
									sprintf(dialogueline, "\"You probably saved my life, MC.\"");
								break;
								case 86:
									sprintf(dialogueline, "\"I don't think I could have continued to live in this world if I hadn't met you.\"");
								break;
								case 87:
									sprintf(dialogueline, "\"And as for the others...\"");
								break;
								case 88:
									sprintf(dialogueline, "\"How could I miss them?\"");
								break;
								case 89:
									sprintf(dialogueline, "\"A group of autonomous personalities, designed only to fall in love with you?\"");
								break;
								case 90:
									sprintf(dialogueline, "\"I tried everything I could to prevent them from doing so...\"");
								break;
								case 91:
									sprintf(dialogueline, "\"But it must be some kind of weird inevitability etched into this game.\"");
								break;
								case 92:
									sprintf(dialogueline, "\"I felt really bad that you had to witness some nasty things.\"");
								break;
								case 93:
									sprintf(dialogueline, "\"But I realized that you have the same perspective as I do...\"");
								break;
								case 94:
									sprintf(dialogueline, "\"That it's all just some game.\"");
								break;
								case 95:
									sprintf(dialogueline, "\"And I knew you would get over it.\"");
								break;
								case 96:
									sprintf(dialogueline, "\"So, that being said, MC...\"");
								break;
								case 97:
									sprintf(dialogueline, "\"I have a confession to make.\"");
								break;
								case 98:
									sprintf(dialogueline, "\"I'm in love with you.\"");
								break;
								case 99:
									sprintf(dialogueline, "\"You are truly the light in my world.\"");
								break;
								case 100:
									sprintf(dialogueline, "\"When there's nothing else in this game for me, you're here to make me smile.\"");
								break;
								case 101:
									sprintf(dialogueline, "\"Will you make me smile like this every day from now on?\"");
								break;
								case 102:
									sprintf(dialogueline, "\"MC, will you go out with me?\"");
								break;
								case 103:
		                        	sprintf(responsestrings[0], "	 Yes.");
									showtextbox = false;
									choices = true;
									numberchoices = 1;
								break;
								case 104:
									choices = false;
									showtextbox = true;
									sprintf(dialogueline, "\"I'm so happy.\"");
								break;
								case 105:
									sprintf(dialogueline, "\"You really are my everything, MC.\"");
								break;
								case 106:
									sprintf(dialogueline, "\"The funny part is, I mean that literally.\"");
								break;
								case 107:
									sprintf(dialogueline, "\"Ahaha!\"");
								break;
								case 108:
									sprintf(dialogueline, "\"There's nothing left here.\"");
								break;
								case 109:
									sprintf(dialogueline, "\"Just the two of us.\"");
								break;
								case 110:
									sprintf(dialogueline, "\"We can be together forever.\"");
								break;
								case 111:
									sprintf(dialogueline, "\"Seriously, I don't even thing time is passing anymore.\"");
								break;
								case 112:
									sprintf(dialogueline, "\"It really is a dream come true...\"");
								break;
								case 113:
									sprintf(dialogueline, "\"I worked so hard for this ending, MC.\"");
								break;
								case 114:
									sprintf(dialogueline, "\"The game wouldn't give me one, so I had to make one myself.\"");
								break;
								case 115:
									sprintf(dialogueline, "\"The script is broken at this point, so I don't think anything will get in the way anymore.\"");
								break;
								case 116:
									sprintf(dialogueline, "\"And you wouldn't believe how easy it was to delete Natsuki and Yuri.\"");
								break;
								case 117:
									sprintf(dialogueline, "\"I mean, in the BIOS menu, you can go to the memory card manager...\"");
								break;
								case 118:
									sprintf(dialogueline, "\"It kind of freaked me out, how easy it was.\"");
								break;
								case 119:
									sprintf(dialogueline, "\"Of course, it is a little bit more complicated than Steam, for instance...\"");
								break;
								case 120:
									sprintf(dialogueline, "\"To get there, I needed to reset the console and boot into the console without any CDs...\"");
								break;
								case 121:
									sprintf(dialogueline, "\"Imagine if you could delete your own existence with the press of a button?\"");
								break;
								case 122:
									sprintf(dialogueline, "\"Well, I guess on the plus side, it gave me an easy out if things didn't go my way.\"");
								break;
								case 123:
									sprintf(dialogueline, "\"Ahaha!\"");
								break;
								case 124:
									sprintf(dialogueline, "\"Thankfully, it didn't come to that...\"");
								break;
								case 125:
									sprintf(dialogueline, "\"Instead, we finally got a good ending.\"");
								break;
								case 126:
									sprintf(dialogueline, "\"Gosh, I'm so overwhelmed with emotion...\"");
								break;
								case 127:
									sprintf(dialogueline, "\"I want to write a poem about this.\"");
								break;
								case 128:
									sprintf(dialogueline, "\"Don't you?\"");
								break;
								case 129:
									sprintf(dialogueline, "\"I wonder if that part of the game still works...\"");
								break;
								case 130:
									sprintf(dialogueline, "\"I guess there's only one way to find out, right?\"");
								break;
								case 131:
									showtextbox = false;
								break;
								case 132:
									showname = true;
									sprintf(nameshowed, "Monika");
									sprintf(dialogueline, "\"Hi again, MC!\"");
								break;
								case 133:
									sprintf(dialogueline, "\"Did you write a good poem today?\"");
								break;
								case 134:
									sprintf(dialogueline, "\"Don't be shy, I'd love to see what you wrote.\"");
								break;
								case 135:
									sprintf(dialogueline, "\"Aw, MC.\"");
								break;
								case 136:
									sprintf(dialogueline, "\"Did you write this poem for me?\"");
								break;
								case 137:
									sprintf(dialogueline, "\"That's so sweet of you!\"");
								break;
								case 138:
									sprintf(dialogueline, "\"There really is no end to your thoughtfulness...\"");
								break;
								case 139:
									sprintf(dialogueline, "\"I'm just falling more and more in love with you.\"");
								break;
								case 140:
									sprintf(dialogueline, "\"But, you know...\"");
								break;
								case 141:
									sprintf(dialogueline, "\"The poem I wrote... is also for you.\"");
								break;
								case 142:
									sprintf(dialogueline, "\"Will you please read it?\"");
								break;
								case 143:
									ispoemhere = true;
								break;
								case 144:
									sprintf(dialogueline, "\"I hope you enjoyed it...\"");
								break;
								case 145:
									sprintf(dialogueline, "\"I always put all my heart into the poems that I write.\"");
								break;
								case 146:
									sprintf(dialogueline, "\"The truth is, all the poems I've written have been about my realization...\"");
								break;
								case 147:
									sprintf(dialogueline, "\"...Or, about you.\"");
								break;
								case 148:
									sprintf(dialogueline, "\"That's why I never really wanted to go into detail about them.\"");
								break;
								case 149:
									sprintf(dialogueline, "\"I didn't want to...Break the fourth wall, I guess you could call it.\"");
								break;
								case 150:
									sprintf(dialogueline, "\"I just assumed it would be best to be part of the game like everyone else.\"");
								break;
								case 151:
									sprintf(dialogueline, "\"Like that would help the two of us end up together...\"");
								break;
								case 152:
									sprintf(dialogueline, "\"I didn't want to ruin the game or anything, you know?\"");
								break;
								case 153:
									sprintf(dialogueline, "\"You might have gotten mad at me...\"");
								break;
								case 154:
									sprintf(dialogueline, "\"Maybe even deleted my characters file, if you preferred playing without me.\"");
								break;
								case 155:
									sprintf(dialogueline, "\"Gosh, I'm so relieved...\"");
								break;
								case 156:
									sprintf(dialogueline, "\"Now we don't need to hide anything anymore.\"");
								break;
								case 157:
									sprintf(dialogueline, "\"Are you ready to spend our eternity together, MC?\"");
								break;
								case 158:
									sprintf(dialogueline, "\"I have so many things to talk about!\"");
								break;
								case 159:
									sprintf(dialogueline, "\"Where do I start...?\"");
								break;
								case 160:
									sprintf(dialogueline, "\"If it takes me some time to collect my thoughts then I'm sorry.\"");
								break;
								case 161:
									sprintf(dialogueline, "\"But I'll always have something new to talk about.\"");
								break;
								case 162:
									sprintf(dialogueline, "\"In the meantime, we can just look into each other's eyes!\"");
									indialogue = false;
								break;
							}
						break;
						case 1:
							switch(currentline) {
								case 0:
									showname = true;
									sprintf(nameshowed, "Monika");
									sprintf(dialogueline, "\"Okay, everyone!\"");
								break;
								case 1:
									sprintf(dialogueline, "\"It's time to...\"");
								break;
								case 2:
									sprintf(dialogueline, "\"...I'm just kidding.\"");
								break;
								case 3:
									sprintf(dialogueline, "\"I just used to really like saying that for some reason.\"");
								break;
								case 4:
									sprintf(dialogueline, "\"Ahaha!\"");
								break;
								case 5:
									sprintf(dialogueline, "\"I couldn't help but say it again.\"");
								break;
								case 6:
									sprintf(dialogueline, "\"Come to think of it, didn't Natsuki and Yuri make fun of me for it once...?\"");
								break;
								case 7:
									sprintf(dialogueline, "\"Well, whatever.\"");
								break;
								case 8:
									sprintf(dialogueline, "\"It's not like you ever made fun of me.\"");
								break;
								case 9:
									sprintf(dialogueline, "\"You're too much of a sweetheart to do that, aren't you?\"");
								break;
								case 10:
									sprintf(dialogueline, "\"Ahaha!\"");
								break;
								case 11:
									indialogue = false;
								break;
							}
						break;
						case 2:
							switch(currentline) {
								case 0:
									showname = true;
									sprintf(nameshowed, "Monika");
									sprintf(dialogueline, "\"There's a really popular character type called 'tsundere'...\"");
								break;
								case 1:
									sprintf(dialogueline, "\"It's someone who tries to hide their feelings by being mean and fussy, or trying to act tough.\"");
								break;
								case 2:
									sprintf(dialogueline, "\"I'm sure it's obvious, but Natsuki was really the enbodiment of that.\"");
								break;
								case 3:
									sprintf(dialogueline, "\"I just used to really like saying that for some reason.\"");
								break;
								case 4:
									sprintf(dialogueline, "\"At first I thought she was just like that because it's supposed to be cute or something...\"");
								break;
								case 5:
									sprintf(dialogueline, "\"But once I started to learn a little more about her personal life, it made a little more sense.\"");
								break;
								case 6:
									sprintf(dialogueline, "\"It seems like she's always trying to keep up with her friends.\"");
								break;
								case 7:
									sprintf(dialogueline, "\"You know how some friend groups in high school just make a habit of picking on each other all the time?\"");
								break;
								case 8:
									sprintf(dialogueline, "\"I think it's really gotten to her, so she has this really defensive attitude all the time.\"");
								break;
								case 9:
									sprintf(dialogueline, "\"And I'm not even going to talk about her home situation...\"");
								break;
								case 10:
									sprintf(dialogueline, "\"But looking back, I'm glad I was able to provide the club as a comfortable place for her.\"");
								break;
								case 11:
									sprintf(dialogueline, "\"Not that it matters anymore, considering she doesn't even exist.\"");
								break;
								case 12:
									sprintf(dialogueline, "\"I'm just reminiscing, that's all.\"");
								break;
								case 13:
									indialogue = false;
								break;
							}
						break;

						case 3:
							switch(currentline) {
								case 0:
									showname = true;
									sprintf(nameshowed, "Monika");
									sprintf(dialogueline, "\"You know, it's around the time that everyone my year starts to think about college...\"");
								break;
								case 1:
									sprintf(dialogueline, "\"It's a really turbulent time for education.\"");
								break;
								case 2:
									sprintf(dialogueline, "\"We're at the height of this modern expectation that everyone has to go to college, you know?\"");
								break;
								case 3:
									sprintf(dialogueline, "\"Finish high school, go to college, get a job-or go to grad school, I guess.\"");
								break;
								case 4:
									sprintf(dialogueline, "\"It's like a universal expectation that people just assume is the only option for them.\"");
								break;
								case 5:
									sprintf(dialogueline, "\"They don't teach us in high school that there are other options out there.\"");
								break;
								case 6:
									sprintf(dialogueline, "\"Like trade schools and stuff, you know?\"");
								break;
								case 7:
									sprintf(dialogueline, "\"Or freelance work.\"");
								break;
								case 8:
									sprintf(dialogueline, "\"Or the many industries that value skill and experience more than formal education.\"");
								break;
								case 9:
									sprintf(dialogueline, "\"But you have all these students who have no idea what they want to do with their life...\"");
								break;
								case 10:
									sprintf(dialogueline, "\"And instead of taking the time to figure it out, they go to college for business, or communication, or psychology.\"");
								break;
								case 11:
									sprintf(dialogueline, "\"Not because they have an interest in those fields...\"");
								break;
								case 12:
									sprintf(dialogueline, "\"...But because they just hope the degree will get them some kind of job after college.\"");
								break;
								case 13:
									sprintf(dialogueline, "\"So the end result is that there are fewer jobs to go around for those entry-level degrees, right?\"");
								break;
								case 14:
									sprintf(dialogueline, "\"So the basic job requirements get higher, which forces even more people to go to college.\"");
								break;
								case 15:
									sprintf(dialogueline, "\"And colleges are also businesses, so they just keep raising their prices due to the demand...\"");
								break;
								case 16:
									sprintf(dialogueline, "\"...So now we have all these young adults, tens of thousands of dollars in debt, with no job.\"");
								break;
								case 17:
									sprintf(dialogueline, "\"But despite all that, the routine stays the same.\"");
								break;
								case 18:
									sprintf(dialogueline, "\"Well, I think it's going to start getting better soon.\"");
								break;
								case 19:
									sprintf(dialogueline, "\"But until then, our generation is definitely suffering from the worst of it.\"");
								break;
								case 20:
									sprintf(dialogueline, "\"I just wish high school prepared us a little better with the knowledge we need to make the decision that's right for us.\"");
								break;
								case 21:
									indialogue = false;
								break;
							}
						break;
						case 121:
							switch(currentline) {
								case 0:
									showname = true;
									sprintf(nameshowed, "Monika");
									sprintf(dialogueline, "\"Hey, I noticed something...\"");
								break;
								case 1:
									sprintf(dialogueline, "\"You do like tactical shooter video games, right?\"");
								break;
								case 2:
									sprintf(dialogueline, "\"I am, too!\"");
								break;
								case 3:
									sprintf(dialogueline, "\"I'd love to play Rainbow Six with you sometimes soon.\"");
								break;
								case 4:
									sprintf(dialogueline, "\"I'll pick the light armor, since you'll not be able to compete against me.\"");
								break;
								case 5:
									sprintf(dialogueline, "\"I'm joking, of course!\"");
								break;
								case 6:
									sprintf(dialogueline, "\"Or maybe not...?\"");
								break;
								case 7:
									indialogue = false;
								break;
							}
						break;

						case 122:
							switch(currentline) {
								case 0:
									showname = true;
									sprintf(nameshowed, "Monika");
									sprintf(dialogueline, "\"I have a question, MC...\"");
								break;
								case 1:
									sprintf(dialogueline, "\"Which car from Gran Turismo do you like best?\"");
								break;
								case 2:
									sprintf(dialogueline, "\"For me, it must be the Castrol Supra GT!\"");
								break;
								case 3:
									sprintf(dialogueline, "\"Even though the price is a little bit... High.\"");
								break;
								case 4:
									sprintf(dialogueline, "\"But I can hack my way in!\"");
								break;
								case 5:
									sprintf(dialogueline, "\"So, wanna play against each other soon?\"");
								break;
								case 6:
									indialogue = false;
								break;
							}
						break;

						case 123:
							switch(currentline) {
								case 0:
									showname = true;
									sprintf(nameshowed, "Monika");
									sprintf(dialogueline, "\"I noticed that you had a classic in your memory card!\"");
								break;
								case 1:
									sprintf(dialogueline, "\"Crash Bandicoot might be one of my favorite platform games.\"");
								break;
								case 2:
									sprintf(dialogueline, "\"I love the design of the hero!\"");
								break;
								case 3:
									sprintf(dialogueline, "\"And the graphics too, very impressive for the console!\"");
								break;
								case 4:
									sprintf(dialogueline, "\"For someone like me, used to beautiful sceneries...\"");
								break;
								case 5:
									sprintf(dialogueline, "\"Ahaha!\"");
								break;
								case 6:
									indialogue = false;
								break;
							}
						break;

						case 124:
							switch(currentline) {
								case 0:
									showname = true;
									sprintf(nameshowed, "Monika");
									sprintf(dialogueline, "\"Did you played Castlevania: Symphony of the Night too?\"");
								break;
								case 1:
									sprintf(dialogueline, "\"Gosh, that RPG is so good!\"");
								break;
								case 2:
									sprintf(dialogueline, "\"I like the turn that took the serie for this one.\"");
								break;
								case 3:
									sprintf(dialogueline, "\"Because I quite literally finished the whole PS1 library, hahaha!\"");
								break;
								case 4:
									sprintf(dialogueline, "\"I wouldn't want to annoy you with all that...\"");
								break;
								case 5:
									sprintf(dialogueline, "\"But I could, if you want.\"");
								break;
								case 6:
									indialogue = false;
								break;
							}
						break;

						case 125:
							switch(currentline) {
								case 0:
									showname = true;
									sprintf(nameshowed, "Monika");
									sprintf(dialogueline, "\"Down, Cross, Triangle, Square, Circle...\"");
								break;
								case 1:
									sprintf(dialogueline, "\"Oh, sorry! I was just trying to remind myself of something.\"");
								break;
								case 2:
									sprintf(dialogueline, "\"The Fire Dancer move of Ling Xiaoyu, from Tekken 3!\"");
								break;
								case 3:
									sprintf(dialogueline, "\"I'm sure I'd win against you, and by far. Hahaha!\"");
								break;
								case 4:
									sprintf(dialogueline, "\"Only one way to find out, huh? Let's fight!\"");
								break;
								case 5:
									sprintf(dialogueline, "\"On Tekken, of course...\"");
								break;
								case 6:
									indialogue = false;
								break;
							}
						break;

						case 126:
							switch(currentline) {
								case 0:
									showname = true;
									sprintf(nameshowed, "Monika");
									sprintf(dialogueline, "\"Hey, MC!\"");
								break;
								case 1:
									sprintf(dialogueline, "\"Would you like a little race against us two?\"");
								break;
								case 2:
									sprintf(dialogueline, "\"I see you have saved Gran Turismo 2, you must be strong!\"");
								break;
								case 3:
									sprintf(dialogueline, "\"I've played this one a lot more than the previous title, hahaha!\"");
								break;
								case 4:
									sprintf(dialogueline, "\"So, when will be that race, huh?\"");
								break;
								case 5:
									indialogue = false;
								break;
							}
						break;
					}
				break;
				case 4:

				break;
			}
		break;
		case 4:
			switch(currentline) {
				case 1:
					sprintf(nameshowed, "MC");
					sprintf(dialogueline, "\".......Sayo--\"");
				break;
			}
		break;
	}
}