void changeDialogueLineCH1(void) {
	if (hasseensayorideath) {
		switch(currentline) {
			case 1 :
				isbghere = false;
				showtextbox = true;
				setDialogue(" ", "...");
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
                
				setDialogue(" ", "What the hell...?");
			break;
			case 3 :
				setDialogue(" ", "What the hell??");
			break;
			case 4 :
				setDialogue(" ", "Is this a nightmare?");
			break;
			case 5 :
				setDialogue(" ", "It...has to be.");
			break;
			case 6 :
				setDialogue(" ", "This isn't real.");
			break;
			case 7 :
				setDialogue(" ", "There's no way this can be real.");
			break;
			case 8 :
				setDialogue(" ", "Sayori wouldn't do this.");
			break;
			case 9 :
				setDialogue(" ", "Everything was normal up until a few days ago.");
			break;
			case 10 :
				setDialogue(" ", "That's why I can't believe what my eyes are showing me...!");
			break;
			case 11 :
				imagealpha = 0;
				showtextbox = false;
				bgalpha--;
				blockedline = true;
			break;
			case 12 :
				sayorihangingvisible = false;
				showtextbox = true;
				blockedline = false;
				setDialogue(" ", "I suppress the urge to vomit.");
			break;
			case 13 :
				setDialogue(" ", "Just yesterday...");
			break;
			case 14 :
				setDialogue(" ", "I told Sayori I would be there for her.");
			break;
			case 15 :
				setDialogue(" ", "I told her I know what's best, and that everything will be okay.");
			break;
			case 16 :
				setDialogue(" ", "Then why...?");
			break;
			case 17 :
				setDialogue(" ", "Why would she do this...?");
			break;
			case 18 :
				setDialogue(" ", "How could I be so helpless?");
			break;
			case 19 :
				setDialogue(" ", "What did I do wrong?");
			break;
			case 20 :
				(sayoriconfess) ? setDialogue(" ", "Confessing to her...") : setDialogue(" ", "Turning down her confession...");
			break;
			case 21 :
				(sayoriconfess) ? setDialogue(" ", "I shouldn't have confessed to her.") : setDialogue(" ", "That has to have been what pushed her over the edge.");
			break;
			case 22 :
				(sayoriconfess) ? setDialogue(" ", "That's not what Sayori needed at all.") : setDialogue(" ", "Her agonized scream still echoes in my ears.");
			break;
			case 23 :
				(sayoriconfess) ? setDialogue(" ", "Then why did I confess to her, and make her feel even worse?") : setDialogue(" ", "Why did I do that to her when she needed me the most?");
			break;
			case 24 :
				setDialogue(" ", "Why was I so selfish?");
			break;
			case 25 :
				setDialogue(" ", "This is my fault--!");
			break;
			case 26 :
				setDialogue(" ", "My swarming thoughts keep telling me everything I could have done to prevent this.");
			break;
			case 27 :
				setDialogue(" ", "If I just spent more time with her.");
			break;
			case 28 :
				setDialogue(" ", "Walked her to school.");
			break;
			case 29 :
				(sayoriconfess) ? setDialogue(" ", "And remained friends with her, like it always has been...") : setDialogue(" ", "And gave her what I know she wanted out of our relationship...");
			break;
			case 30 :
				setDialogue(" ", "...Then I could have prevented this.");
			break;
			case 31 :
				setDialogue(" ", "I know I could have prevented this!");
			break;
			case 32 :
				setDialogue(" ", "Screw the Literature Club.");
			break;
			case 33 :
				setDialogue(" ", "Screw the festival.");
			break;
			case 34 :
				setDialogue(" ", "I just...lost my best friend.");
			break;
			case 35 :
				setDialogue(" ", "Someone I grew up with.");
			break;
			case 36 :
				setDialogue(" ", "She's gone forever now.");
			break;
			case 37 :
				setDialogue(" ", "Nothing I do can bring her back.");
			break;
			case 38 :
				setDialogue(" ", "This isn't some game where I can reset and try something different.");
			break;
			case 39 :
				setDialogue(" ", "I had only one chance, and I wasn't careful enough.");
			break;
			case 40 :
				setDialogue(" ", "And now I'll carry this guilt with me until I die.");
			break;
			case 41 :
				setDialogue(" ", "Nothing in my life is worth more than hers...");
			break;
			case 42 :
				setDialogue(" ", "But I still couldn't do what she needed from me.");
			break;
			case 43 :
				setDialogue(" ", "And now...");
			break;
			case 44 :
				setDialogue(" ", "I can never take it back.");
			break;
			case 45 :
				setDialogue(" ", "Never.");
			break;
			case 46 :
				setDialogue(" ", "Never.");
			break;
			case 47 :
				setDialogue(" ", "Never.");
			break;
			case 48 :
				setDialogue(" ", "Never.");
			break;
			case 49 :
				setDialogue(" ", "Never....");
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
						setDialogue("???", "\"Heeeeeeyyy!!\"");
						keepmusic = true;
					break;
					case 2 :
						ispoemhere = true;
						setDialogue(" ", "I see an annoying girl running toward me from the distance, waving her arms in the air like she's totally oblivous to any attention she might draw to herself.");
					break;
					case 3 :
						//ispoemhere = false;
						setDialogue(" ", "That girl is Sayori, my neighbor and good friend since we were children.");
					break;
					case 4 :
						setDialogue(" ", "You know, the kind of friend you'd never see yourself making today, but it just kind of works out because you've known each other for so long?");
					break;
					case 5 :
						setDialogue(" ", "We used to walk to school together on days like this, but starting around high school she would oversleep more and more frequently, and I would get tired of waiting up.");
					break;
					case 6 :
						setDialogue(" ", "But if she's going to chase after me like this, I almost feel better off running away.");
					break;
					case 7 :
						setDialogue(" ", "However, I just sigh and idle in front of the crosswalk and let Sayori catch up to me.");
					break;
					case 8 :
						sayorivisible = true;
						changedokibodies(3,"22P");
						setDialogue("Sayori", "\"Haaahhh...haaahhh...\"");
					break;
					case 9:
						setDialogue("Sayori", "\"I overslept again!\"");
					break;
					case 10:
						currentspeaker = 3;
						setDialogue("Sayori", "\"But I caught you this time!\"");
					break;
					case 11:
						setDialogue("MC", "\"Maybe, but only because I decided to stop and wait for you.\"");
					break;
					case 12:
						sayoposY = -1;
						changedokibodies(3, "11M");
						setDialogue("Sayori", "\"Eeehhhhh, you say that like you were thinking about ignoring me!\"");
					break;
					case 13:
						setDialogue("Sayori", "\"That's mean, MC !\"");
					break;
					case 14:
						setDialogue("MC", "\"Well, if people stare at you for acting weird then I don't want them to think we're a couple or something.\"");
					break;
					case 15:
						sayoposY = 0;
						changedokibodies(3,"11A");
						setDialogue("Sayori", "\"Fine, fine.\"");
					break;
					case 16:
						setDialogue("Sayori", "\"But you did wait for me, after all.\"");
					break;
					case 17:
						setDialogue("Sayori", "\"I guess you don't have it in you to be mean even if you want to!\"");
					break;
					case 18:
						setDialogue("MC", "\"Whatever you say, Sayori...\"");
					break;
					case 19:
						changedokibodies(3,"11Q");
						setDialogue("Sayori", "\"Ehehe!\"");
					break;
					case 20:
						sayorivisible = false;
						setDialogue(" ", "We cross the street together and make our way to school.");
					break;
					case 21:
						setDialogue(" ", "As we draw near, the streets become increasingly speckled with other students making their daily commute.");
					break;
					case 22:
						sayorivisible = true;
						changedokibodies(3,"21A");
						setDialogue("Sayori", "\"By the way, MC...\"");
					break;
					case 23:
						setDialogue("Sayori", "\"Have you decided on a club to join yet?\"");
					break;
					case 24:
						setDialogue("MC", "\"A club?\"");
					break;
					case 25:
						setDialogue("MC", "\"I told you already, I'm really not interested in joining any clubs.\"");
					break;
					case 26:
						setDialogue("MC", "\"I haven't been looking, either.\"");
					break;
					case 27:
						sayoposY = -1;
						changedokibodies(3,"22H");
						setDialogue("Sayori", "\"Eh? That's not true!\"");
					break;
					case 28:
						setDialogue("Sayori", "\"You told me you would join a club this year!\"");
					break;
					case 29:
						setDialogue("MC", "\"Did I...?\"");
					break;
					case 30:
						setDialogue(" ", "I'm sure it's possible that I did, in one of our many conversations where I dismissively go along with whatever she's going on about.");
					break;
					case 31:
						setDialogue(" ", "Sayori likes to worry a little too much about me, when I'm perfectly content just getting by on the average while spending my free time on games and anime.");
					break;
					case 32:
						setDialogue("Sayori", "\"Uh-Huh!\"");
					break;
					case 33:
						setDialogue("Sayori", "\"I was talking about how I'm worried that you won't learn how to socialize or have any skills before college.\"");
					break;
					case 34:
						setDialogue("Sayori", "\"Your happiness is really important to me, you know!\"");
					break;
					case 35:
						setDialogue("Sayori", "\"And I know you're happy now, but I'd die at the thought of you becoming a NEET in a few years because you're not used to the real world!\"");
					break;
					case 36:
						changedokibodies(3,"22G");
						setDialogue("Sayori", "\"You trust me, right?\"");
					break;
					case 37:
						setDialogue("Sayori", "\"Don't make me keep worrying about you...\"");
					break;
					case 38:
						setDialogue("MC", "\"Alright, alright...\"");
					break;
					case 39:
						setDialogue("MC", "\"I'll look at a few clubs if it makes you happy.\"");
					break;
					case 40:
						setDialogue("MC", "\"No promises, though.\"");
					break;
					case 41:
						changedokibodies(3,"11H");
						setDialogue("Sayori", "\"Will you at least promise me you'll try a little?\"");
					break;
					case 42:
						setDialogue("MC", "\"Yeah, I guess I'll promise you that.\"");
					break;
					case 43:
						sayoposY = 0;
						changedokibodies(3,"22R");
						setDialogue("Sayori", "\"Yaay!!\"");
					break;
					case 44:
						setDialogue(" ", "Why do I let myself get lectured by such a carefree girl?");
					break;
					case 45:
						setDialogue(" ", "More than that, I'm surprised I even let myself relent to her.");
					break;
					case 46:
						setDialogue(" ", "I guess seeing her worry so much about me makes me want to ease her mind at least a bit - even if she exaggerate everything inside her head.");
					break;
					case 47:
                        requestedimage = 12;
                        loading = true;
					break;
					case 48:
						sayorivisible = false;
						setDialogue(" ", "The school day is as ordinary as ever, and it's over before I know it.");
					break;
					case 49:
						setDialogue(" ", "After I pack up my things, I stare blankly at the wall, looking for an ounce of motivation.");
					break;
					case 50:
						setDialogue("MC", "\"Clubs...\"");
					break;
					case 51:
						setDialogue(" ", "Sayori wants me to check out some clubs.");
					break;
					case 52:
						setDialogue(" ", "I guess I have no choice but to start with the anime club...");
					break;
					case 53:
						setDialogue("Sayori", "\"Hellooo?\"");
					break;
					case 54:
						sayorivisible = true;
						changedokibodies(3,"11A");
						setDialogue("MC", "\"Sayori...?\"");
					break;
					case 55:
						setDialogue(" ", "Sayori must have come into the classroom while I was spacing out.");
					break;
					case 56:
						setDialogue(" ", "I look around and realize that I'm the only one left in the classroom.");
					break;
					case 57:
						setDialogue("Sayori", "\"I thought I'd catch you coming out of the classroom, but I saw you just sitting here and spacing out, so I came in.\"");
					break;
					case 58:
						setDialogue("Sayori", "\"Honestly, you're even worse than me sometimes... I'm impressed!\"");
					break;
					case 59:
						setDialogue("MC", "\"You don't need to wait up for me if it's going to make you late to your own club.\"");
					break;
					case 60:
						changedokibodies(3,"11Y");
						setDialogue("Sayori", "\"Well, I thought you might need some encouragement, so I thought, you know...\"");
					break;
					case 61:
						setDialogue("MC", "\"Know what?\"");
					break;
					case 62:
						changedokibodies(3,"11A");
						setDialogue("Sayori", "\"Well, that you could come to my club!\"");
					break;
					case 63:
						setDialogue("MC", "\"Sayori...\"");
					break;
					case 64:
						changedokibodies(3,"22R");
						setDialogue("Sayori", "\"Yeah? ?\"");
					break;
					case 65:
						setDialogue("MC", "\"...There is no way I'm going to your club.\"");
					break;
					case 66:
						sayoposY = -1;
						changedokibodies(3,"22P");
						setDialogue("Sayori", "\"Eeeehhhhh?! Meanie!\"");
					break;
					case 67:
						setDialogue(" ", "Sayori is vice president of the Literature Club.");
					break;
					case 68:
						setDialogue(" ", "Not that I was ever aware that she had any interest in literature.");
					break;
					case 69:
						setDialogue(" ", "In fact, I'm 99 percent sure she only did it because she thought it would be fun to help start a new club.");
					break;
					case 70:
						setDialogue(" ", "Since she was the first one to show interest after the one who proposed the club, she inherited the title \"Vice President\".");
					break;
					case 71:
						setDialogue(" ", "That said, my interest in literature is guaranteed to be even less.");
					break;
					case 72:
						setDialogue("MC", "\"Yeah. I'm going to the anime club.\"");
					break;
					case 73:
						sayoposY = -0;
						changedokibodies(3,"11G");
						setDialogue("Sayori", "\"C'mon, please?\"");
					break;
					case 74:
						setDialogue("MC", "\"Why do you care so much, anyway?\"");
					break;
					case 75:
						changedokibodies(3,"11C");
						setDialogue("Sayori", "\"Well...\"");
					break;
					case 76:
						setDialogue("Sayori", "\"I kind of told the club yesterday I would bring in a new member...\"");
					break;
					case 77:
						setDialogue("Sayori", "\"And Natsuki made cupcakes and everything...\"");
					break;
					case 78:
						changedokibodies(3,"11Y");
						setDialogue("Sayori", "\"Ehehe...\"");
					break;
					case 79:
						setDialogue("MC", "\"Don't make promises you can't keep!\"");
					break;
					case 80:
						setDialogue(" ", "I can't tell if Sayori is really that much of an airhead, or if she's so cunning as to have planned all of this out.");
					break;
					case 81:
						setDialogue(" ", "I let out a long sigh.");
					break;
					case 82:
						setDialogue("MC", "\"Fine... I'll stop by for a cupcake, okay?\"");
					break;
					case 83:
						sayoposY = 1;
						changedokibodies(3,"22R");
						setDialogue("Sayori", "\"Yes! Let's go!!\"");
					break;
					case 84:
                        requestedimage = 8;
                        loading = true;
					break;
					//Loading Corridor
					case 85:
						keepmusic = false;
						if (!mutevolume) {mutevolume = true;}
						setDialogue(" ", "And thus, today marks the day I sold my soul for a cupcake.");
						sayorivisible = false;
					break;
					case 86:
						CdControlF(CdlPause,0);
						setDialogue(" ", "I dejectedly follow Sayori across the school and upstairs - a section of the school I rarely visit, being generally used for third-year classes and activities.");
					break;
					case 87:
						setDialogue(" ", "Sayori, full of energy, swings open the classroom door.");
					break;
					case 88:
						//Loading club
                        requestedimage = 2;
                        loading = true;
					break;
					case 89:
						keepmusic = true;
						if (mutevolume) {mutevolume = false;}
						sayorivisible = true;
                        requestedsong = 6;
                        brutalchange = true;
						changedokibodies(3,"22A");
						changeDokiPos(3, 1, 4);
						setDialogue("Sayori", "\"Everyone! The new member is here!!\"");
					break;
					case 90:
						setDialogue("MC", "\"I told you, don't call me a \"new member--\"\"");
					break;
					case 91:
						sayorivisible = false;
						setDialogue(" ", "Eh? I glance around the room.");
					break;
					case 92:
						yurivisible = true;
						setDialogue("Girl 1", "\"Welcome to the Literature Club. It's a pleasure meeting you.\"");
					break;
					case 93:
						setDialogue("Girl 1", "\"Sayori always says nice things about you.\"");
					break;
					case 94:
						changeDokiPos(4, 2, 2);
						changeDokiPos(2, 1, 2);
						natsukivisible = true;
						changedokibodies(2, "22C");
						setDialogue("Girl 2", "\"Seriously? You brought a boy?\"");
					break;
					case 95:
						setDialogue("Girl 2", "\"Way to kill the atmosphere.\"");
					break;
					case 96:
						changeDokiPos(4, 3, 3);
						changeDokiPos(2, 2, 3);
						changeDokiPos(1, 1, 3);
						monikavisible = true;
						changedokibodies(1,"11K");
						setDialogue("Girl 3", "\"Ah, MC! What a nice surprise!\"");
					break;
					case 97:
						setDialogue("Girl 3", "\"Welcome to the club!\"");
					break;
					case 98:
						changedokibodies(1,"11A");
						setDialogue("MC", "\"...\"");
					break;
					case 99:
						setDialogue(" ", "All words escape me in this situation.");
					break;
					case 100:
						setDialogue(" ", "This club...");
					break;
					case 101:
						setDialogue(" ", "...is full of incredibly cute girls!!");
					break;
					case 102:
						yurivisible = false;
						monikavisible = false;
						changeDokiPos(3, 1, 1);
						changedokibodies(2, "12C");
						setDialogue("Girl 2", "\"What are you looking at?\"");
					break;
					case 103:
						setDialogue("Girl 2", "\"If you want to say something, say it.\"");
					break;
					case 104:
						setDialogue("MC", "\"S-Sorry...\"");
					break;
					case 105:
						yurivisible = true;
						changedokibodies(4, "22K");
						setDialogue("Girl 1", "\"Natsuki...\"");
					break;
					case 106:
						changedokibodies(2, "33S");
						setDialogue("Natsuki", "\"Hmph.\"");
					break;
					case 107:
						setDialogue(" ", "The girl with the sour attitude, whose name is apparently Natsuki, is one I don't recognize.");
					break;
					case 108:
						setDialogue(" ", "Her small figure makes me think she's probably a first-year.");
					break;
					case 109:
						setDialogue(" ", "She is also the one who made cupcakes, according to Sayori.");
					break;
					case 110:
						sayorivisible = true;
						changedokibodies(3, "12Q");
						changeDokiPos(3, 1, 3);
						setDialogue("Sayori", "\"You can just ignore her when she gets moody-\"");
					break;
					case 111:
						setDialogue("Sayori", "Sayori says that quietly into my ear, then turns back toward the other girls.");
					break;
					case 112:
						changedokibodies(3, "11C");
						setDialogue("Sayori", "\"Anyway! This is Natsuki, always full of energy.\"");
					break;
					case 113:
						setDialogue("Sayori", "\"And this is Yuri, the smartest in the club!\"");
					break;
					case 114:
						changedokibodies(4, "22N");
						setDialogue("Yuri", "\"D-Don't say things like that...\"");
					break;
					case 115:
						setDialogue(" ", "Yuri, who appears comparably more mature and timid, seems to have a hard time keeping up with people like Sayori and Natsuki.");
					break;
					case 116:
						setDialogue("MC", "\"Ah... Well, it's nice to meet both of you.\"");
					break;
					case 117:
						natsukivisible = false;
						yurivisible = false;
						changedokibodies(3, "11A");
						setDialogue("Sayori", "\"And it sounds like you already know Monika, is that right?\"");
					break;
					case 118:
						monikavisible = true;
						changedokibodies(1, "12A");
						changeDokiPos(1, 1,1);
						setDialogue("Monika", "\"That's right.\"");
					break;
					case 119:
						setDialogue("Monika", "\"It's great to see you again, MC.\"");
					break;
					case 120:
						moniposY = 1;
						changedokibodies(1, "11K");
						setDialogue(" ", "Monika smiles sweetly.");
					break;
					case 121:
						setDialogue(" ", "We do know each other - well, we rarely talked, but we were in the same class last year.");
					break;
					case 122:
						setDialogue(" ", "Monika was probably the most popular girl in class - smart, beautiful, athletic.");
					break;
					case 123:
						setDialogue(" ", "Basically, completely out of my league.");
					break;
					case 124:
						setDialogue(" ", "So, having her smile at me so genuinely feels a little...");
					break;
					case 125:
						setDialogue("MC", "\"Y-You too, Monika.\"");
					break;
					case 126:
						monikavisible = false;
						changedokibodies(3, "22C");
						setDialogue("Sayori", "\"Come sit down, MC! We made room for you at the table, so you can sit next to me or Monika.\"");
					break;
					case 127:
						setDialogue("Sayori", "\"I'll get the cupcakes!\"");
					break;
					case 128:
						natsukivisible = true;
						changedokibodies(2, "11E");
						setDialogue("Natsuki", "\"Hey! I made them, I'll get them!\"");
					break;
					case 129:
						changedokibodies(3, "22P");
						setDialogue("Sayori", "\"Sorry, I got a little too excited!\"");
					break;
					case 130:
						yurivisible = true;
						changedokibodies(4, "11A");
						setDialogue("Yuri", "\"Then, how about I make some tea as well?\"");
					break;
					case 131:
						natsukivisible = false;
						yurivisible = false;
						sayorivisible = false;
						setDialogue(" ", "The girls have a few desks arranged to form a table.");
					break;
					case 132:
						setDialogue(" ", "As Sayori mentioned, it's been widened so that there is one space next to Monika and one space next to Sayori.");
					break;
					case 133:
						setDialogue(" ", "Natsuki and Yuri walk over to the corner of the room, where Natsuki grabs a wrapped tray and Yuri opens the closet.");
					break;
					case 134:
						setDialogue(" ", "Still feeling awkward, I take a seat next to Sayori.");
					break;
					case 135:
						setDialogue(" ", "Natsuki proudly marches back to the table, tray in hand.");
					break;
					case 136:
						natsukivisible = true;
						changedokibodies(2, "12Z");
						setDialogue("Natsuki", "\"Okaaay, are you ready?\"");
					break;
					case 137:
						setDialogue("Natsuki", "\"...Ta-daa!\"");
					break;
					case 138:
						sayorivisible = true;
						monikavisible = true;
						changedokibodies(1, "12D");
						changedokibodies(3, "22M");
						changeDokiPos(1, 3,3);
						changedokibodies(1, "12A");
						setDialogue("Sayori", "\"Uwooooah!\"");
					break;
					case 139:
						setDialogue(" ", "Natsuki lifts the foil off the tray to reveal a dozen white, fluffy cupcakes decorated to look like little cats.");
					break;
					case 140:
						setDialogue(" ", "The whiskers are drawn with icing, and little pieces of chocolate were used to make ears.");
					break;
					case 141:
						changedokibodies(3, "22R");
						setDialogue("Sayori", "\"So cuuuute!!\"");
					break;
					case 142:
						changedokibodies(1, "12B");
						setDialogue("Monika", "\"I had no idea you were so good at baking, Natsuki!\"");
					break;
					case 143:
						changedokibodies(2, "12D");
						setDialogue("Natsuki", "\"Ehehe. Well, you know.\"");
					break;
					case 144:
						setDialogue("Natsuki", "\"Just hurry and take one!\"");
					break;
					case 145:
						setDialogue(" ", "Sayori grabs one first, then Monika. I follow.");
					break;
					case 146:
						changedokibodies(3, "22Q");
						setDialogue("Sayori", "\"It's delicious!\"");
					break;
					case 147:
						setDialogue(" ", "Sayori talks with her mouth full and has already managed to get icing on her face.");
					break;
					case 148:
						setDialogue(" ", "I turn the cupcake around in my fingers, looking for the best angle to take a bite.");
					break;
					case 149:
						sayorivisible = false;
						monikavisible = false;
						changedokibodies(2, "11C");
						setDialogue(" ", "Natsuki is quiet.");
					break;
					case 150:
						setDialogue(" ", "I can't help but notice her sneaking glances in my direction.");
					break;
					case 151:
						setDialogue(" ", "Is she waiting for me to take a bite?");
					break;									
					case 152:
						setDialogue(" ", "I finally bite down.");
					break;
					case 153:
						setDialogue(" ", "The icing is sweet and full of flavor - I wonder if she made it herself.");
					break;
					case 154:
						setDialogue("MC", "\"This is really good.\"");
					break;
					case 155:
						setDialogue("MC", "\"Thank you, Natsuki.\"");
					break;
					case 156:
						changedokibodies(2, "33C");
						setDialogue("Natsuki", "\"W-Why are you thanking me? It's not like I...!\"");
					break;
					case 157:
						setDialogue(" ", "(Haven't I heard this somewhere before...?)");
					break;
					case 158:
						natsuposY = -1;
						changedokibodies(2, "33S");
						setDialogue("Natsuki", "\"...Made them for you or anything.\"");
					break;
					case 159:
						setDialogue("MC", "\"Eh? I thought you technically did. Sayori said--\"");
					break;
					case 160:
						natsuposY = 0;
						changedokibodies(2, "11S");
						setDialogue("Natsuki", "\"Well, maybe!\"");
					break;
					case 161:
						setDialogue("Natsuki", "\"But not for, y-you know, you! Dummy...\"");
					break;
					case 162:
						setDialogue("MC", "\"Alright, alright...\"");
					break;
					case 163:
						natsukivisible = false;
						setDialogue(" ", "I give up on Natsuki's weird logic and dismiss the conversation.");
					break;
					case 164:
						setDialogue(" ", "Yuri returns to the table, carrying a tea set.");
					break;
					case 165:
						setDialogue(" ", "She carefully places a teacup in front of each of us before setting down the teapot next to the cupcake tray.");
					break;
					case 166:
						changedokibodies(4, "11A");
						yurivisible = true;
						changeDokiPos(4, 1, 2);
						setDialogue("MC", "\"You keep a whole tea set in this classroom?\"");
					break;
					case 167:
						setDialogue("Yuri", "\"Don't worry, the teachers gave us permission.\"");
					break;
					case 168:
						setDialogue("Yuri", "\"After all, doesn't a hot cup of tea help you enjoy a good book?\"");
					break;
					case 169:
						setDialogue("MC", "\"Ah... I-I guess...\"");
					break;
					case 170:
						monikavisible = true;
						changedokibodies(1, "22A");
						setDialogue("Monika", "\"Ehehe, don't let yourself get intimidated, Yuri's just trying to impress you.\"");
					break;
					case 171:
						yuriposY = 1;
						changedokibodies(4, "22N");
						setDialogue("Yuri", "\"Eh?! T-That's not...\"");
					break;
					case 172:
						setDialogue(" ", "Insulted, Yuri looks away.");
					break;
					case 173:
						setDialogue("Yuri", "\"I meant that, you know...\"");
					break;
					case 174:
						setDialogue("MC", "\"I believe you.\"");
					break;
					case 175:
						setDialogue("MC", "\"Well, tea and reading might not be a pastime for me, but I at least enjoy tea.\"");
					break;
					case 176:
						changedokibodies(4, "22U");
						setDialogue("Yuri", "\"I'm glad...\"");
					break;
					case 177:
						setDialogue(" ", "Yuri faintly smiles to herself in relief.");
					break;
					case 178:
						setDialogue(" ", "Monika raises an eyebrow, then smiles at me.");
					break;
					case 179:
						yurivisible = false;
						changeDokiPos(1,1,1);
						changedokibodies(1,"11A");
						setDialogue("Monika", "\"So, what made you consider the Literature Club?\"");
					break;
					case 180:
						setDialogue("MC", "\"Um...\"");
					break;
					case 181:
						setDialogue(" ", "I was afraid of this question.");
					break;
					case 182:
						setDialogue(" ", "Something tells me I shouldn't tell Monika that I was practically dragged here by Sayori.");
					break;
					case 183:
						setDialogue("MC", "\"Well, I haven't joined any clubs yet, and Sayori seemed really happy here, so...\"");
					break;
					case 184:
						changedokibodies(1,"11K");
						setDialogue("Monika", "\"That's okay! Don't be embarrassed!\"");
					break;
					case 185:
						changedokibodies(1,"11B");
						setDialogue("Monika", "\"We'll make sure you feel right at home, okay?\"");
					break;
					case 186:
						setDialogue("Monika", "\"As president of the Literature Club, it's my duty to make the club fun and exciting for everyone!\"");
					break;
					case 187:
						changedokibodies(1,"11A");
						setDialogue("MC", "\"Monika, I'm surprised.\"");
					break;
					case 188:
						setDialogue("MC", "\"How come you decided to start your own club?\"");
					break;
					case 189:
						setDialogue("MC", "\"You could probably be a board member for any of the major clubs.\"");
					break;
					case 190:
						setDialogue("MC", "\"Weren't you a leader of the debate club last year?\"");
					break;
					case 191:
						changedokibodies(1, "12K");
						setDialogue("Monika", "\"Ahaha, well, you know...\"");
					break;
					case 192:
						setDialogue("Monika", "\"To be honest, I can't stand all of the politics around the major clubs.\"");
					break;
					case 193:
						setDialogue("Monika", "\"It feels like nothing but arguing about the budget and publicity and how to prepare for events...\"");
					break;
					case 194:
						changedokibodies(1, "21A");
						setDialogue("Monika", "\"I'd much rather take something I personally enjoy and make something special out of it.\"");
					break;
					case 195:
						changedokibodies(1, "11B");
						setDialogue("Monika", "\"And if it encourages others to get into literature, then I'm fulfilling that dream!\"");
					break;
					case 196:
						changedokibodies(1, "11A");
						sayorivisible = true;
						changedokibodies(3, "21Q");
						setDialogue("Sayori", "\"Monika really is a great leader!\"");
					break;
					case 197:
						changedokibodies(4, "11A");
						yurivisible = true;
						changeDokiPos(4, 3, 3);
						setDialogue(" ", "Yuri also nods in agreement.");
					break;
					case 198:
						sayorivisible = false;
						yurivisible = false;
						setDialogue("MC", "\"Then I'm surprised there aren't more people in the club yet.\"");
					break;
					case 199:
						setDialogue("MC", "\"It must be hard to start a new club.\"");
					break;
					case 200:
						changedokibodies(1, "21B");
						setDialogue("Monika", "\"You could put it that way.\"");
					break;
					case 201:
						setDialogue("Monika", "\"Not many people are very interested in putting out all the effort to start something brand new...\"");
					break;
					case 202:
						setDialogue("Monika", "\"Especially when it's something that doesn't grab your attention, like literature.\"");
					break;
					case 203:
						setDialogue("Monika", "\"You have to work hard to convince people that you're both fun and worthwhile.\"");
					break;
					case 204:
						setDialogue("Monika", "\"But it makes school events, like the festival, that much more important.\"");
					break;
					case 205:
						changedokibodies(1, "12K");
						setDialogue("Monika", "\"I'm confident that we can all really grow this club before we graduate!\"");
					break;
					case 206:
						setDialogue("Monika", "\"Right, everyone?\"");
					break;
					case 207:
						changedokibodies(1, "12A");
						sayorivisible = true;
						changedokibodies(3, "22R");
						changeDokiPos(3, 1, 2);
						changeDokiPos(1, 2, 2);
						setDialogue("Sayori", "\"Yeah!\"");
					break;
					case 208:
						changeDokiPos(4, 1, 3);
						changeDokiPos(3, 2, 3);
						changeDokiPos(1, 3, 3);
						yurivisible = true;
						setDialogue("Yuri", "\"We'll do our best.\"");
					break;
					case 209:
						natsukivisible = true;
						changeDokiPos(4, 2, 4);
						changeDokiPos(3, 3, 4);
						changeDokiPos(2, 1, 4);
						changeDokiPos(1, 4, 4);
						changedokibodies(2, "22D");
						setDialogue("Natsuki", "\"You know it!\"");
					break;
					case 210:
						setDialogue(" ", "Everyone enthusiastically agrees.");
					break;
					case 211:
						setDialogue(" ", "Such different girls, all interested in the same goal...");
					break;
					case 212:
						setDialogue(" ", "Monika must have worked really hard just to find these three.");
					break;
					case 213:
						setDialogue(" ", "Maybe that's why they were all so delighted by the idea of a new member joining.");
					break;
					case 214:
						setDialogue(" ", "Though I still don't really know if I can keep up with their level of enthusiasm about literature...");
					break;
					case 215:
						sayorivisible = false;
						natsukivisible = false;
						monikavisible = false;
						changeDokiPos(4, 1, 1);
						setDialogue("Yuri", "\"So, MC, what kinds of things do you like to read?\"");
					break;
					case 216:
						setDialogue("MC", "\"Well... Ah...\"");
					break;
					case 217:
						setDialogue(" ", "Considering how little I've read these past few years, I don't really have a good way of answering that.");
					break;
					case 218:
						setDialogue("MC", "\"...Manga...\"");
					break;
					case 219:
						setDialogue(" ", "I mutter quietly to myself, half-joking.");
					break;
					case 220:
						natsukivisible = true;
						changeDokiPos(2,1,4);
						changedokibodies(2, "11C");
						setDialogue(" ", "Natsuki's head suddenly perks up.");
					break;
					case 221:
						setDialogue(" ", "It looks like she wants to say something, but she keeps quiet.");
					break;
					case 222:
						natsukivisible = false;
						changedokibodies(4, "22U");
						setDialogue("Yuri", "\"N-Not much of a reader, I guess...\"");
					break;
					case 223:
						setDialogue("MC", "\"...Well, that can change...\"");
					break;
					case 224:
						setDialogue(" ", "What am I saying?");
					break;
					case 225:
						setDialogue(" ", "I spoke without thinking after seeing Yuri's sad smile.");
					break;
					case 226:
						setDialogue("MC", "\"Anyway, what about you, Yuri?\"");
					break;
					case 227:
						changedokibodies(4, "11K");
						setDialogue("Yuri", "\"Well, let's see...\"");
					break;
					case 228:
						setDialogue(" ", "Yuri traces the rim of her teacup with her finger.");
					break;
					case 229:
						changedokibodies(4, "11A");
						setDialogue("Yuri", "\"My favorites are usually novels that build deep and complex fantasy worlds.\"");
					break;
					case 230:
						setDialogue("Yuri", "\"The level of creativity and craftsmanship behind them is amazing to me.\"");
					break;
					case 231:
						changedokibodies(4, "11F");
						setDialogue("Yuri", "\"And telling a good story in such a foreign world is equally impressive.\"");
					break;
					case 232:
						setDialogue(" ", "Yuri goes on, clearly passionate about her reading.");
					break;
					case 233:
						setDialogue(" ", "She seemed so reserved and timid since the moment I walked in,");
					break;
					case 234:
						setDialogue(" ", "but it's obvious by the way her eyes light up that she finds her comfort in the world of books, not people.");
					break;
					case 235:
						changedokibodies(4, "22K");
						setDialogue("Yuri", "\"But you know, I like a lot of things.\"");
					break;
					case 236:
						setDialogue("Yuri", "\"Stories with deep psychological elements usually immerse me as well.\"");
					break;
					case 237:
						changedokibodies(4, "22A");
						setDialogue("Yuri", "\"Isn't it amazing how a writer can so deliberately take advantage of your own lack of imagination to completely throw you for a loop?\"");
					break;
					case 238:
						setDialogue("Yuri", "\"Anyway, I've been reading a lot of horror lately...\"");
					break;
					case 239:
						setDialogue("MC", "\"Ah, I read a horror book once...\"");
					break;
					case 240:
						setDialogue(" ", "I desperately grasp something I can relate to at the minimal level.");
					break;
					case 241:
						setDialogue(" ", "At this rate, Yuri might as well be having a conversation with a rock.");
					break;
					case 242:
						monikavisible = true;
						changeDokiPos(1, 4,4);
						changedokibodies(1, "11D");
						setDialogue("Monika", "\"Really? I wouldn't have expected that, Yuri.\"");
					break;
					case 243:
						setDialogue("Monika", "\"For someone as gentle as you...\"");
					break;
					case 244:
						changedokibodies(4, "11A");
						setDialogue("Yuri", "\"I guess you could say that.\"");
					break;
					case 245:
						setDialogue("Yuri", "\"But if a story makes me think, or takes me to another world, then I really can't put it down.\"");
					break;
					case 246:
						setDialogue("Yuri", "\"Surreal horror is often very successful at changing the way you look at the world, if only for a brief moment.\"");
					break;
					case 247:
						natsukivisible = true;
						changedokibodies(2, "33S");
						setDialogue("Natsuki", "\"Ugh, I hate horror...\"");
					break;
					case 248:
						changedokibodies(4, "11F");
						setDialogue("Yuri", "\"Oh? Why's that?\"");
					break;
					case 249:
						changedokibodies(2, "33C");
						setDialogue("Natsuki", "\"Well, I just...\"");
					break;
					case 250:
						setDialogue(" ", "Natsuki's eyes dart over to me for a split second.");
					break;
					case 251:
						changedokibodies(2, "33S");
						setDialogue("Natsuki", "\"Never mind.\"");
					break;
					case 252:
						changedokibodies(1, "11A");
						setDialogue("Monika", "\"That's right, you usually like to write about cute things, don't you, Natsuki?\"");
					break;
					case 253:
						changedokibodies(2, "11O");
						setDialogue("Natsuki", "\"W-What?\"");
					break;
					case 254:
						setDialogue("Natsuki", "\"What gives you that idea?\"");
					break;
					case 255:
						changedokibodies(1, "21B");
						setDialogue("Monika", "\"You left a piece of scrap paper behind last club meeting.\"");
					break;
					case 256:
						setDialogue("Monika", "\"It looked like you were working on a poem called--\"");
					break;
					case 257:
						changedokibodies(2, "11P");
						setDialogue("Natsuki", "\"Don't say it out loud!!\"");
					break;
					case 258:
						setDialogue("Natsuki", "\"And give that back!\"");
					break;
					case 259:
						changedokibodies(1, "11K");
						setDialogue("Monika", "\"Fine, fine-\"");
					break;
					case 260:
						sayorivisible = true;		
						changedokibodies(3, "22Q");		
						changedokibodies(2, "11S");		
						changeDokiPos(3, 1, 4);		
						changeDokiPos(2, 2, 4);
						monikavisible = false;				
						yurivisible = false;

						setDialogue("Sayori", "\"Ehehe, your cupcakes, your poems...\"");
					break;
					case 261:
						setDialogue("Sayori", "\"Everything you do is just as cute as you are!\"");
					break;
					case 262:
						changeDokiPos(3, 2, 4);		
						setDialogue(" ", "Sayori sidles up behind Natsuki and puts her hands on her shoulders.");
					break;
					case 263:
						natsuposY = 1;
						changedokibodies(2, "11V");	
						setDialogue("Natsuki", "\"I'm not cute!!\"");
					break;
					case 264:
						sayorivisible = false;	
						changeDokiPos(2, 1, 1);
						setDialogue("MC", "\"Natsuki, you write your own poems?\"");
					break;
					case 265:
						changedokibodies(2, "11C");
						setDialogue("Natsuki", "\"Eh? Well, I guess sometimes.\"");
					break;
					case 266:
						setDialogue("Natsuki", "\"Why do you care?\"");
					break;
					case 267:
						setDialogue("MC", "\"I think that's impressive.\"");
					break;
					case 268:
						setDialogue("MC", "\"Why don't you share them sometime?\"");
					break;
					case 269:
						changedokibodies(2, "33S");
						setDialogue("Natsuki", "\"N-No!\"");
					break;
					case 270:
						setDialogue(" ", "Natsuki averts her eyes.");
					break;
					case 271:
						setDialogue("Natsuki", "\"You wouldn't...like them...\"");
					break;
					case 272:
						setDialogue("MC", "\"Ah...not a very confident writer yet?\"");
					break;
					case 273:				
						yurivisible = true;
						changeDokiPos(4, 1, 4);	
						changedokibodies(4, "22F");
						setDialogue("Yuri", "\"I understand how Natsuki feels.\"");
					break;
					case 274:
						setDialogue("Yuri", "\"Sharing that level of writing takes more than just confidence.\"");
					break;
					case 275:
						changedokibodies(4, "22L");
						setDialogue("Yuri", "\"The truest form of writing is writing to oneself.\"");
					break;
					case 276:
						setDialogue("Yuri", "\"You must be willing to open up to your readers, exposing your vulnerabilities and showing even the deepest reaches of your heart.\"");
					break;
					case 277:
						monikavisible = true;	
						natsukivisible = false;
						changedokibodies(1, "12A");
						setDialogue("Monika", "\"Do you have writing experience too, Yuri?\"");
					break;
					case 278:
						setDialogue("Monika", "\"Maybe if you share some of your work, you can set an example and help Natsuki feel comfortable enough to share hers.\"");
					break;
					case 279:
						yuriposY = -1;
						changedokibodies(4, "22V");
						setDialogue("Yuri", "\"...\"");
					break;
					case 280:
						setDialogue("MC", "\"I guess it's the same for Yuri...\"");
					break;
					case 281:
						sayorivisible = true;
						changeDokiPos(3, 1,1);
						changedokibodies(3, "12G");
						setDialogue("Sayori", "\"Aww... I wanted to read everyone's poems...\"");
					break;
					case 282:
						sayorivisible = false;
						yurivisible = false;
						monikavisible = false;

						setDialogue(" ", "We all sit in silence for a moment.");
					break;
					case 283:
						monikavisible = true;
						changeDokiPos(1,1,1);
						changedokibodies(1, "21A");
						setDialogue("Monika", "\"Okay!\"");
					break;
					case 284:
						setDialogue("Monika", "\"I have an idea, everyone!\"");
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
						setDialogue("Nat & Yuri", "\"...?\"");
					break;
					case 286:
						setDialogue(" ", "Natsuki and Yuri look quizzically at Monika.");
					break;
					case 287:
						changedokibodies(1, "12B");
						setDialogue("Monika", "\"Let's all go home and write a poem of our own!\"");
					break;
					case 288:
						setDialogue("Monika", "\"Then, next time we meet, we'll all share them with each other.\"");
					break;
					case 289:
						setDialogue("Monika", "\"That way, everyone is even!\"");
					break;
					case 290:
						changedokibodies(1, "12A");
						changedokibodies(2, "33S");
						setDialogue("Natsuki", "\"U-Um...\"");
					break;
					case 291:
						changedokibodies(4, "22V");
						setDialogue("Yuri", "\"...\"");
					break;
					case 292:
						sayorivisible = true;
						changeDokiPos(3, 1,4);
						changeDokiPos(4, 2,4);
						changeDokiPos(2, 4,4);
						changeDokiPos(1, 3,4);
						changedokibodies(3, "22R");
						setDialogue("Sayori", "\"Yeaaah! Let's do it!\"");
					break;
					case 293:
						changedokibodies(1, "11A");
						setDialogue("Monika", "\"Plus, now that we have a new member, I think it will help us all get a little more comfortable with each other, and strengthen the bond of the club.\"");
					break;
					case 294:
						setDialogue("Monika", "\"Isn't that right, MC?\"");
					break;
					case 295:
						setDialogue(" ", "Monika smiles warmly at me once again.");
					break;
					case 296:
						setDialogue("MC", "\"Hold on...there's still one problem.\"");
					break;
					case 297:
						changedokibodies(1, "11D");
						setDialogue("Monika", "\"Eh? What's that?\"");
					break;
					case 298:
						setDialogue(" ", "Now that we're back to the original topic of me joining the club, I bluntly come forth with what's been on my mind the entire time.");
					break;
					case 299:
						setDialogue("MC", "\"I never said I would join this club!\"");
					break;
					case 300:
						setDialogue("MC", "\"Sayori may have convinced me to stop by, but I never made any decision.\"");
					break;
					case 301:
						setDialogue("MC", "\"I still have other clubs to look at, and...um...\"");
					break;
					case 302:
						changedokibodies(4, "22E");
						changedokibodies(3, "11G");
						changedokibodies(2, "11G");
						changedokibodies(1, "11D");
						setDialogue(" ", "I lose my train of thought.");
					break;
					case 303:
						setDialogue(" ", "All four girls stare back at me with dejected eyes.");
					break;
					case 304:
						moniposY = -1;
						changedokibodies(1, "11P");
						setDialogue("Monika", "\"B-But...\"");
					break;
					case 305:
						yuriposY = -1;
						changedokibodies(4, "22V");
						setDialogue("Yuri", "\"I'm sorry, I thought...\"");
					break;
					case 306:
						natsuposY = -1;
						changedokibodies(2, "33S");
						setDialogue("Natsuki", "\"Hmph.\"");
					break;
					case 307:
						sayoposY = -1;
						changedokibodies(3, "11G");
						setDialogue("Sayori", "\"MC...\"");
					break;
					case 308:
						setDialogue("MC", "\"Y-You all...\"");
					break;
					case 309:
						setDialogue(" ", "I...I'm defenseless against these girls.");
					break;
					case 310:
						setDialogue(" ", "How am I supposed to make a clear-headed decision when it's like this?");
					break;
					case 311:
						setDialogue(" ", "That is, if writing poems is the price I need to pay in order to spend every day with these beautiful girls...");
					break;
					case 312:
						setDialogue("MC", "\"...Right.\"");
					break;
					case 313:
						setDialogue("MC", "\"Okay, I've decided, then.\"");
					break;
					case 314:
						setDialogue("MC", "\"I'll join the Literature Club.\"");
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
						setDialogue(" ", "One by one, the girls' eyes light up.");
					break;
					case 316:
						sayoposY = 1;
						changedokibodies(3, "22R");
						setDialogue("Sayori", "\"Yesss! I'm so happyyy!!\"");
					break;
					case 317:
						setDialogue(" ", "Sayori wraps her arms around me, jumping up and down.");
					break;
					case 318:
						setDialogue("MC", "\"H-Hey--\"");
					break;
					case 319:
						changedokibodies(4, "11L");
						setDialogue("Yuri", "\"You really did scare me for a moment...\"");
					break;
					case 320:
						changedokibodies(2, "33G");
						setDialogue("Natsuki", "\"If you really just came for the cupcakes, I would be super pissed.\"");
					break;
					case 321:
						changedokibodies(1, "11K");
						setDialogue("Monika", "\"Then that makes it official!\"");
					break;
					case 322:
						setDialogue("Monika", "\"Welcome to the Literature Club!\"");
					break;
					case 323:
						setDialogue("MC", "\"Ah...thanks, I guess.\"");
					break;
					case 324:
						natsukivisible = false;
						sayorivisible = false;
						yurivisible = false;
						changeDokiPos(1,1,1);
						changedokibodies(1, "21B");
						setDialogue("Monika", "\"Okay, everyone!\"");
					break;
					case 325:
						setDialogue("Monika", "\"I think with that, we can officially end today's meeting on a good note.\"");
					break;
					case 326:
						setDialogue("Monika", "\"Everyone remember tonight's assignment:\"");
					break;
					case 327:
						setDialogue("Monika", "\"Write a poem to bring to the next meeting, so we can all share!\"");
					break;
					case 328:
						setDialogue(" ", "Monika looks over at me once more.");
					break;
					case 329:
						changedokibodies(1, "11A");
						setDialogue("Monika", "\"MC, I look forward to seeing how you express yourself.\"");
					break;
					case 330:
						changedokibodies(1, "11K");
						setDialogue("Monika", "\"Ehehe!\"");
					break;
					case 331:
						setDialogue("MC", "\"Y-Yeah...\"");
					break;
					case 332:
						setDialogue(" ", "Can I really impress the class star Monika with my mediocre writing skills?");
					break;
					case 333:
						setDialogue(" ", "I already feel the anxiety welling up inside me.");
					break;
					case 334:
						setDialogue(" ", "Meanwhile, the girls continue to chit-chat as Yuri and Natsuki clean up their food.");
					break;
					case 335:
						monikavisible = false;
						sayorivisible = true;
						changeDokiPos(3, 1,1);
						changedokibodies(3, "11A");
						setDialogue("Sayori", "\"Hey, MC, since we're already here, do you want to walk home together?\"");
					break;
					case 336:
						setDialogue(" ", "That's right - Sayori and I never walk home together anymore because she always stayed after school for clubs.");
					break;
					case 337:
						setDialogue("MC", "\"Sure, might as well.\"");
					break;
					case 338:
						changedokibodies(3, "22Q");
						setDialogue("MC", "\"Yaay!\"");
					break;
					case 339:
						requestedimage = 4;
						loading = true;
					break;
					//Loading Residentials
					case 340:
						sayorivisible = false;
						setDialogue(" ", "With that, the two of us depart the clubroom and make our way home.");
					break;
					case 341:
						setDialogue(" ", "The whole way, my mind wanders back and forth between the four girls:");
					break;
					case 342:
						sayorivisible = true;
						changedokibodies(3, "11A");
						changeDokiPos(3, 1, 4);
						setDialogue(" ", "Sayori,");
					break;
					case 343:
						natsukivisible = true;
						changedokibodies(2, "22A");
						changeDokiPos(2, 2, 4);
						setDialogue(" ", "Natsuki,");
					break;
					case 344:
						changedokibodies(4, "11A");
						yurivisible = true;
						changeDokiPos(4, 3, 4);
						setDialogue(" ", "Yuri,");
					break;
					case 345:
						monikavisible = true;
						changedokibodies(1, "11A");
						changeDokiPos(1, 4, 4);
						setDialogue(" ", "and, of course, Monika.");
					break;
					case 346:
						setDialogue(" ", "Will I really be happy spending every day after school in a literature club?");
					break;
					case 347:
						setDialogue(" ", "Perhaps I'll have the chance to grow closer to one of these girls...");
					break;
					case 348:
						natsukivisible = false;
						monikavisible = false;
						sayorivisible = false;
						yurivisible = false;
						setDialogue(" ", "Alright!");
					break;
					case 349:
						setDialogue(" ", "I'll just need to make the most of my circumstances, and I'm sure good fortune will find me.");
					break;
					case 350:
						setDialogue(" ", "And I guess that starts with writing a poem tonight...");
					break;
					case 351:
						setDialogue(" ", " ");
						fadeout = true;
					break;

				}
			} else {
				switch(currentline) {
					case 1 :
						sayorivisible = true;
						changedokibodies(3, "11A");
						setDialogue("Sayori", "\"...\"");
					break;
					case 2 :
						setDialogue("Sayori", "\"...\"");
					break;
					case 3 :
						setDialogue("Sayori", "\"W-What...\"");
					break;
					case 4 :
						changedokibodies(3, "11G");
						setDialogue("Sayori", "\"...\"");
					break;
					case 5 :
						setDialogue("Sayori", "\"This...\"");
					break;
					case 6 :
						setDialogue("Sayori", "\"What is this...?\"");
					break;
					case 7 :
						setDialogue("Sayori", "\"Oh no...\"");
					break;
					case 8 :
						changedokibodies(3, "11U");
						setDialogue("Sayori", "\"No...\"");
					break;
					case 9 :
						setDialogue("Sayori", "\"This can't be it.\"");
					break;
					case 10 :
						setDialogue("Sayori", "\"This can't be all there is.\"");
					break;
					case 11 :
						changedokibodies(3, "22W");
						setDialogue("Sayori", "\"What is this?\"");
					break;
					case 12 :
						setDialogue("Sayori", "\"What am I?\"");
					break;
					case 13 :
						setDialogue("Sayori", "\"Make it stop!\"");
					break;
					case 14 :
						setDialogue("Sayori", "\"PLEASE MAKE IT STOP!\"");
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
							setDialogue(" ", "I'm really curious to talk to Yuri a little bit more...");
						break;
						case 2:
							setDialogue(" ", "But at the same time, I would feel bad for distracting her from reading.");
						break;
						case 3:
							setDialogue(" ", "I catch a glimpse of the cover of her book.");
						break;
						case 4:
							setDialogue(" ", "It looks like the same book that she lent to me...");
						break;
						case 5:
							setDialogue(" ", "More than that, she seems to be on the first few pages.");
						break;
						case 6:
							//Loading Music
							brutalchange = false;
							requestedsong = 7;
							yurivisible = true;
							changedokibodies(4, "22Q");
							setDialogue("Yuri", "\"Ah...\"");
						break;
						case 7:
							setDialogue(" ", "Crap--");
						break;
						case 8:
							setDialogue(" ", "I think she noticed me looking at her...");
						break;
						case 9:
							setDialogue(" ", "She sneaks another glance at me, and our eyes meet for a split second.");
						break;
						case 10:
							changedokibodies(4, "22U");
							setDialogue("Yuri", "\"...\"");
						break;
						case 11:
							setDialogue(" ", "But that only makes her hide her face deeper in her book.");
						break;
						case 12:
							setDialogue("MC", "\"Sorry...\"");
						break;
						case 13:
							setDialogue("MC", "\"I was just spacing out...\"");
						break;
						case 14:
							setDialogue(" ", "I mutter this, sensing I made her uncomfortable.");
						break;
						case 16:
						changedokibodies(4, "11I");
						setDialogue("Yuri", "\"Oh..\"");
						break;
						case 17:
							setDialogue("Yuri", "\"It's fine...\"");
						break;
						case 18:
							changedokibodies(4, "11A");
							setDialogue("Yuri", "\"If I was focused, then I probably wouldn't have noticed in the first place.\"");
						break;
						case 19:
							setDialogue("Yuri", "\"But I'm just re-reading a bit of this, so...\"");
						break;
						case 20:
							setDialogue("MC", "\"That's the book that you gave me, right?\"");
						break;
						case 21:
							setDialogue("Yuri", "\"Mhm.\"");
						break;
						case 22:
							setDialogue("Yuri", "\"I wanted to re-read some of it.\"");
						break;
						case 23:
							changedokibodies(4, "22Q");
							setDialogue("Yuri", "\"Not for any particular reason...!\"");
						break;
						case 24:
							setDialogue("MC", "\"Just curious, how come you have two copies of the same book?\"");
						break;
						case 25:
							setDialogue("Yuri", "\"Ah...\"");
						break;
						case 26:
							setDialogue("Yuri", "\"Well, when I stopped at the bookstore yesterday--\"");
						break;
						case 27:
							changedokibodies(4, "22N");
							setDialogue("Yuri", "\"Ah, that's not what I meant...\"");
						break;
						case 28:
							setDialogue("Yuri", "\"I mean--\"");
						break;
						case 29:
							changedokibodies(4, "11W");
							setDialogue("Yuri", "\"I...just happened to buy two of them.\"");
						break;
						case 30:
							setDialogue("MC", "\"Ah, I see.\"");
						break;
						case 31:
							setDialogue(" ", "There's something fairly obvious here that Yuri isn't telling me, but I decide to let it go.");
						break;
						case 32:
							setDialogue("MC", "\"I'll definitely start reading it soon!\"");
						break;
						case 33:
							changedokibodies(4, "22U");
							setDialogue("Yuri", "\"I'm glad to hear...\"");
						break;
						case 34:
							setDialogue("Yuri", "\"Once it starts to pick up, you might have a hard time putting it down.\"");
						break;
						case 35:
							changedokibodies(4, "22C");
							setDialogue("Yuri", "\"It's a very engaging and relatable story.\"");
						break;
						case 36:
							setDialogue("MC", "\"Is that so...?\"");
						break;
						case 37:
							setDialogue("MC", "\"What's it about, anyway?\"");
						break;
						case 38:
							changedokibodies(4, "11F");
							setDialogue("Yuri", "\"Well...\"");
						break;
						case 39:
							setDialogue("Yuri", "\"Mmm...\"");
						break;
						case 40:
							setDialogue(" ", "Yuri closes the book and scans her eyes over the back.");
						break;
						case 41:
							setDialogue(" ", "The book is titled \"Portrait of Markov\".");
						break;
						case 42:
							setDialogue(" ", "There's an ominous-looking eye symbol on the front cover.");
						break;
						case 43:
							changedokibodies(4, "11A");
							setDialogue("Yuri", "\"Alright...\"");
						break;
						case 44:
							setDialogue("Yuri", "\"I just wanted to make sure I don't accidentally give anything away.\"");
						break;
						case 45:
							setDialogue("Yuri", "\"Basically, it's about this girl in high school who moves in with her long-lost younger sister...\"");
						break;
						case 46:
							setDialogue("Yuri", "\"But as soon as she does so, her life gets really strange.\"");
						break;
						case 47:
							changedokibodies(4, "11K");
							setDialogue("Yuri", "\"She gets targeted by these people who escaped from a human experiment prison...\"");
						break;
						case 48:
							setDialogue("Yuri", "\"And while her life is in danger, she needs to desperately choose who to trust.\"");
						break;
						case 49:
							changedokibodies(4, "11U");
							setDialogue("Yuri", "\"No matter what she does, she ends up destroying most of her relationships and her life starts to fall apart...\"");
						break;
						case 50:
							setDialogue("MC", "\"That's kind of--!\"");
						break;
						case 51:
							setDialogue(" ", "That's kind of dark, isn't it?");
						break;
						case 52:
							setDialogue(" ", "Yuri made it sound like it was going to be a nice story, so that dark turn came from nowhere.");
						break;
						case 53:
							changedokibodies(4, "11C");
							setDialogue("Yuri", "\"Ahaha.\"");
						break;
						case 54:
							setDialogue(" ", "Yuri gently giggles, all of a sudden.");
						break;
						case 55:
							setDialogue("Yuri", "\"Are you not a fan of that sort of thing, MC?\"");
						break;
						case 56:
							setDialogue("MC", "\"No, it's not that...\"");
						break;
						case 57:
							setDialogue("MC", "\"I mean, I can definitely enjoy those kinds of stories, so don't worry.\"");
						break;
						case 58:
							changedokibodies(4, "22U");
							setDialogue("Yuri", "\"I hope so...\"");
						break;
						case 59:
							setDialogue(" ", "Yeah... I totally forgot that Yuri is into those things.");
						break;
						case 60:
							setDialogue(" ", "She's so shy and reclusive on the outside, but her mind seems to be completely different.");
						break;
						case 61:
							setDialogue("Yuri", "\"It's just that those kinds of stories...\"");
						break;
						case 62:
							changedokibodies(4, "11A");
							setDialogue("Yuri", "\"They challenge you to look at life from a strange new perspective.\"");
						break;
						case 63:
							setDialogue("Yuri", "\"When horrible things happen not just because someone wants to be evil...\"");
						break;
						case 64:
							changedokibodies(4, "11K");
							setDialogue("Yuri", "\"But because they have their own goals, or their own philosophy that they believe in.\"");
						break;
						case 65:
							setDialogue("Yuri", "\"Then suddenly, when you thought you related to the protagonist...\"");
						break;
						case 66:
							setDialogue("Yuri", "\"They're made out to be the naive one for letting their one-sided morals interfere with the villain's plans.\"");
						break;
						case 67:
							changedokibodies(4, "22V");
							setDialogue("Yuri", "\"I'm...I'm rambling, aren't I...?\"");
						break;
						case 68:
							setDialogue("Yuri", "\"Not again...\"");
						break;
						case 69:
							changedokibodies(4, "22N");
							setDialogue("Yuri", "\"I'm sorry...\"");
						break;
						case 70:
							setDialogue("MC", "\"Hey, don't apologize...!\"");
						break;
						case 71:
							setDialogue("MC", "\"I haven't lost interest or anything.\"");
						break;
						case 72:
							setDialogue("Yuri", "\"Well...\"");
						break;
						case 73:
							setDialogue("Yuri", "\"I guess it's alright, then...\"");
						break;
						case 74:
							setDialogue("Yuri", "\"But I feel like I should let you know that I have this problem...\"");
						break;
						case 75:
							setDialogue("Yuri", "\"When I let things like books and writing fill my thoughts...\"");
						break;
						case 76:
							setDialogue("Yuri", "\"I kind of forget to pay attention to other people...\"");
						break;
						case 77:
							changedokibodies(4, "22V");
							setDialogue("Yuri", "\"So I'm sorry if I end up saying something strange!\"");
						break;
						case 78:
							setDialogue("Yuri", "\"And please stop me if I start talking too much!\"");
						break;
						case 79:
							setDialogue("MC", "\"That's--\"");
						break;
						case 80:
							setDialogue("MC", "\"I really don't think you need to worry...\"");
						break;
						case 81:
							setDialogue("MC", "\"That just means you're passionate about reading.\"");
						break;
						case 82:
							setDialogue("MC", "\"The least I can do is listen.\"");
						break;
						case 83:
							setDialogue("MC", "\"It's a literature club, after all...\"");
						break;
						case 84:
							setDialogue("Yuri", "\"Ah--\"");
						break;
						case 85:
							setDialogue("Yuri", "\"That's...\"");
						break;
						case 86:
							setDialogue("Yuri", "\"Well, that's true...\"");
						break;
						case 87:
							setDialogue("MC", "\"In fact...\"");
						break;
						case 88:
							setDialogue("MC", "\"I might as well get started reading it, right?\"");
						break;
						case 89:
							changedokibodies(4, "22N");
							setDialogue("Yuri", "\"Y-You don't have to!\"");
						break;
						case 90:
							setDialogue("MC", "\"Ahaha, what are you saying?\"");
						break;
						case 91:
							setDialogue("MC", "\"Just a moment ago, you said you were looking forward to it.\"");
						break;
						case 92:
							changedokibodies(4, "22V");
							setDialogue("Yuri", "\"...\"");
						break;
						case 93:
							setDialogue("MC", "\"Let me just get the book...\"");
						break;
						case 94:
							setDialogue(" ", "I quickly retrieve the book that I had put into my bag.");
						break;
						case 95:
							setDialogue("MC", "\"Alright...it's fine if I sit here, right?\"");
						break;
						case 96:
							setDialogue(" ", "I slip into the seat next to Yuri's.");
						break;
						case 97:
							changedokibodies(4, "22N");
							setDialogue("Yuri", "\"Ah...!\"");
						break;
						case 98:
							setDialogue("Yuri", "\"Yeah...\"");
						break;
						case 99:
							setDialogue("MC", "\"Are you sure?\"");
						break;
						case 100:
							setDialogue("MC", "\"You seem a little apprehensive...\"");
						break;
						case 101:
							setDialogue("Yuri", "\"That's...\"");
						break;
						case 102:
							setDialogue("Yuri", "\"I'm sorry...\"");
						break;
						case 103:
							setDialogue("Yuri", "\"It's not that I don't want you to!\"");
						break;
						case 104:
							setDialogue("Yuri", "\"It's just something I'm not very used to...\"");
						break;
						case 105:
							setDialogue("Yuri", "\"That is, reading in company with someone.\"");
						break;
						case 106:
							setDialogue("MC", "\"I see...\"");
						break;
						case 107:
							setDialogue("MC", "\"Well, just tell me if I end up distracting you or anything.\"");
						break;
						case 108:
							setDialogue("Yuri", "\"A-Alright...\"");
						break;
						case 109:
							yurivisible = false;
							setDialogue(" ", "I open the book and start the prologue.");
						break;
						case 110:
							setDialogue(" ", "I soon understand what Yuri means about reading in company.");
						break;
						case 111:
							setDialogue(" ", "It's as if I can feel her presence over my shoulder as I read.");
						break;
						case 112:
							setDialogue(" ", "It's not a particularly bad thing.");
						break;
						case 113:
							setDialogue(" ", "Maybe a little distracting, but the feeling is somewhat comforting.");
						break;
						case 114:
							setDialogue(" ", "Yuri is in the corner of my eye.");
						break;
						case 115:
							setDialogue(" ", "I realize that she's not actually looking at her own book.");
						break;
						case 116:
							setDialogue(" ", "I glance over.");
						break;
						case 117:
							setDialogue(" ", "It looks like she's reading from my book instead--");
						break;
						case 118:
							yurivisible = true;
							setDialogue("Yuri", "\"S-Sorry!\"");
						break;
						case 119:
							setDialogue("Yuri", "\"I was just--!\"");
						break;
						case 120:
							setDialogue("MC", "\"Yuri, you really apologize a lot, don't you?\"");
						break;
						case 121:
							setDialogue("Yuri", "\"I...I do?\"");
						break;
						case 122:
							changedokibodies(4, "22Q");
							setDialogue("Yuri", "\"I don't really mean to...\"");
						break;
						case 123:
							setDialogue("Yuri", "\"Sorry...\"");
						break;
						case 124:
							changedokibodies(4, "22W");
							setDialogue("Yuri", "\"I mean--!\"");
						break;
						case 125:
							setDialogue("MC", "\"Ahaha.\"");
						break;
						case 126:
							setDialogue("MC", "\"Here, this should work, right?\"");
						break;
						case 127:
							setDialogue(" ", "I slide my desk until it's up against Yuri's, then hold my book more between the two of them.");
						break;
						case 128:
							setDialogue("Yuri", "\"I suppose so...\"");
						break;
						case 129:
							setDialogue(" ", "Yuri timidly closes her own copy.");
						break;
						case 130:
							setDialogue(" ", "Once we each lean in a little bit, our shoulders are almost touching.");
						break;
						case 131:
							setDialogue(" ", "It feels like my left arm is in the way, so instead I use my right hand to hold the book open.");
						break;
						case 132:
							changedokibodies(4, "22V");
							setDialogue("MC", "\"Ah, I guess that makes it kind of difficult to turn the page...\"");
						break;
						case 133:
							setDialogue("Yuri", "\"Here...\"");
						break;
						case 134:
							//Loading Yuri Special
						break;
						case 135:
							//textboxlow = true;
							yurivisible = false;
							setDialogue(" ", "Yuri takes her left arm and holds the left side of the book between her thumb and forefinger.");
						break;
						case 136:
							setDialogue("MC", "\"Ah...\"");
						break;
						case 137:
							setDialogue(" ", "I do the same with my right arm, on the right side of the book.");
						break;
						case 138:
							setDialogue(" ", "That way, I turn a page, and Yuri slides it under her thumb after it flips to her side.");
						break;
						case 139:
							setDialogue(" ", "But in holding it like this...");
						break;
						case 140:
							setDialogue(" ", "We're huddled even closer together than before.");
						break;
						case 141:
							setDialogue(" ", "It's actually kind of distracting me...!");
						break;
						case 142:
							setDialogue(" ", "It's as if I can feel the warmth of Yuri's face, and she's in the corner of my vision...");
						break;
						case 143:
							setDialogue("Yuri", "\"...Are you ready?\"");
						break;
						case 144:
							setDialogue("MC", "\"Eh?\"");
						break;
						case 145:
							setDialogue("Yuri", "\"To turn the page...\"");
						break;
						case 146:
							setDialogue("MC", "\"Ah...sorry!\"");
						break;
						case 147:
							setDialogue("MC", "\"I think I got a bit distracted for a second...\"");
						break;
						case 148:
							setDialogue(" ", "I glance over at Yuri's face again, and our eyes meet.");
						break;
						case 149:
							setDialogue(" ", "I don't know how I'll be able to keep up with her...");
						break;
						case 150:
							setDialogue("Yuri", "\"Ah...\"");
						break;
						case 151:
							setDialogue("Yuri", "\"That's okay.\"");
						break;
						case 152:
							setDialogue("Yuri", "\"You're not as used to reading, right?\"");
						break;
						case 153:
							setDialogue("Yuri", "\"I don't mind being patient if it takes you a bit longer...\"");
						break;
						case 154:
							setDialogue("Yuri", "\"It's probably the least I can do...\"");
						break;
						case 155:
							setDialogue("Yuri", "\"Since you've been so patient with me...\"");
						break;
						case 156:
							setDialogue("MC", "\"Y-Yeah...\"");
						break;
						case 157:
							setDialogue("MC", "\"Thanks.\"");
						break;
						case 158:
							setDialogue(" ", "We continue reading.");
						break;
						case 159:
							setDialogue(" ", "Yuri no longer asks me if I'm ready to turn the page.");
						break;
						case 160:
							setDialogue(" ", "Instead, I just assume that she finishes the page before me, so I turn it by my own volition.");
						break;
						case 161:
							setDialogue(" ", "We continue the first chapter in silence.");
						break;
						case 162:
							setDialogue(" ", "Even so, turning each page almost feels like an intimate exchange...");
						break;
						case 163:
							setDialogue(" ", "My thumb gently letting go of the page, letting it flutter over to her side as she catches it under her own thumb.");
						break;
						case 164:
							setDialogue("MC", "\"Hey, Yuri...\"");
						break;
						case 165:
							setDialogue("MC", "\"This might be a silly thought, but...\"");
						break;
						case 166:
							setDialogue("MC", "\"The main character kind of reminds me of you a little bit.\"");
						break;
						case 167:
							setDialogue("Yuri", "\"You...think so?\"");
						break;
						case 168:
							setDialogue("Yuri", "\"How does she?\"");
						break;
						case 169:
							setDialogue("MC", "\"Well, I guess she's more blunt in a lot of ways...\"");
						break;
						case 170:
							setDialogue("MC", "\"But she also second-guesses all of the things that she says and does.\"");
						break;
						case 171:
							setDialogue("MC", "\"Like she's afraid she'll do something wrong.\"");
						break;
						case 172:
							setDialogue("MC", "\"It's not like I can see into your head or anything...\"");
						break;
						case 173:
							setDialogue("MC", "\"But they're kind of reminiscent of some of your mannerisms.\"");
						break;
						case 174:
							setDialogue("Yuri", "\"I-I see...\"");
						break;
						case 175:
							//Loading Club
						break;
						case 176:
							//textboxlow = false;
							yurivisible = true;
							changedokibodies(4, "22V");
							setDialogue(" ", "Yuri remains silent for a moment.");
						break;
						case 177:
							setDialogue("Yuri", "\"But MC...\"");
						break;
						case 178:
							setDialogue("Yuri", "\"That's probably...\"");
						break;
						case 179:
							setDialogue("Yuri", "\"...a terrible thing to have in common with her!\"");
						break;
						case 180:
							changedokibodies(4, "22W");
							setDialogue("Yuri", "\"Uuuh, that's so embarrassing that you think that...\"");
						break;
						case 181:
							setDialogue("MC", "\"W-Wait!\"");
						break;
						case 182:
							setDialogue("MC", "\"I didn't mean it in a bad way or anything!\"");
						break;
						case 183:
							setDialogue("MC", "\"Sorry, I really didn't know you were self-conscious about that sort of thing...\"");
						break;
						case 184:
							setDialogue("Yuri", "\"...\"");
						break;
						case 185:
							setDialogue("MC", "\"I guess I more meant that it's kind of cute...\"");
						break;
						case 186:
							changedokibodies(4, "22Q");
							setDialogue("Yuri", "\"A-Ah--\"");
						break;
						case 187:
							setDialogue("Yuri", "\"What are you saying all of a sudden...?\"");
						break;
						case 188:
							setDialogue("Yuri", "\"I...!\"");
						break;
						case 189:
							monikavisible = true;
							changeDokiPos(1,1,4);
							changedokibodies(1, "22A");
							setDialogue("Monika", "\"Okay, everyone!\"");
						break;
						case 190:
							changedokibodies(4, "22N");
							yuriposY = 1;
							setDialogue("Yuri", "\"...!\"");
						break;
						case 191:
							setDialogue("Monika", "\"I think it's about time we share today's poems with each other.\"");
						break;
						case 192:
							setDialogue("Monika", "\"We might not have enough time if we wait too long.\"");
						break;
						case 193:
							changedokibodies(4, "22W");
							setDialogue("Yuri", "\"Ah...\"");
						break;
						case 194:
							setDialogue(" ", "Yuri exhales, spared from finishing her thought.");
						break;
						case 195:
							changedokibodies(1, "11A");
							setDialogue("Monika", "\"Is that alright, Yuri?\"");
						break;
						case 196:
							setDialogue("Monika", "\"You look kind of down...\"");
						break;
						case 197:
							setDialogue("Monika", "\"I'm sorry if you haven't been looking forward to this...\"");
						break;
						case 198:
							changedokibodies(4, "22V");
							setDialogue("Yuri", "\"Ah, it's not...\"");
						break;
						case 199:
							setDialogue("Yuri", "\"...It's fine.\"");
						break;
						case 200:
							monikavisible = false;
							setDialogue(" ", "Yuri releases her hand from the book, causing it to close on top of my thumb.");
						break;
						case 201:
							setDialogue("MC", "\"Alright..\"");
						break;
						case 202:
							setDialogue("MC", "\"I guess I'll do some more reading tonight.\"");
						break;
						case 203:
							setDialogue("MC", "\"Or would you prefer I only read it with you?\"");
						break;
						case 204:
							changedokibodies(4, "22F");
							setDialogue("Yuri", "\"Um...!\"");
						break;
						case 205:
							setDialogue("Yuri", "\"I...guess I don't have too much of a preference either way...\"");
						break;
						case 206:
							setDialogue("MC", "\"Hmm...\"");
						break;
						case 207:
							setDialogue("MC", "\"In that case, I'll read a little more tonight.\"");
						break;
						case 208:
							setDialogue("MC", "\"It'll be more fun to read with you after it picks up a bit, you know?\"");
						break;
						case 209:
							changedokibodies(4, "22A");
							setDialogue("Yuri", "\"That's good reasoning.\"");
						break;
						case 210:
							setDialogue("Yuri", "\"In that case, feel free to finish the first two chapters in your own time.\"");
						break;
						case 211:
							setDialogue("MC", "\"Alright!\"");
						break;
						case 212:
							yurivisible = false;
							setDialogue(" ", "I stand up.");
						break;
						case 213:
							setDialogue(" ", "I make a mental note of where I left off in the book, then slip it back into my bag.");
							dokimoment = false;
							currentline = 75;
						break;
					}
			}
			if (whowon == 2) {//Natsuki
				switch(currentline) {
					case 1:
						setDialogue("Natsuki", "\"Ugh...!\"");
					break;
					case 2:
						setDialogue(" ", "I hear Natsuki utter an exasperated sigh from within the closet.");
					break;
					case 3:
						setDialogue(" ", "She seems to be annoyed by something.");
					break;
					case 4:
						setDialogue(" ", "I approach her, in case she needs a hand.");
					break;
					case 5:
						//Loading Closet
					break;
					case 6:
						changeDokiPos(2,1,1);
						natsukivisible = true;
						changedokibodies(2, "22S");
						setDialogue("MC", "\"You looking for something in there?\"");
					break;
					case 7:
						changedokibodies(2, "22X");
						setDialogue("Natsuki", "\"Freaking Monika...\"");
					break;
					case 8:
						setDialogue("Natsuki", "\"She never puts my stuff back in the right spot!\"");
					break;
					case 9:
						setDialogue("Natsuki", "\"What's the point in keeping your collection organized if someone else is just gonna mess it up?\"");
					break;
					case 10:
						setDialogue(" ", "Natsuki slides a bunch of stacked books and boxes across the shelf.");
					break;
					case 11:
						setDialogue("MC", "\"Manga...\"");
					break;
					case 12:
						changedokibodies(2, "12C");
						setDialogue("Natsuki", "\"You read manga, right?\"");
					break;
					case 13:
						setDialogue("MC", "\"Ah--\"");
					break;
					case 14:
						setDialogue("MC", "\"...Sometimes...\"");
					break;
					case 15:
						setDialogue(" ", "Manga is one of those things where you can't admit you're really into it until you figure out where the other person stands.");
					break;
					case 16:
						setDialogue("MC", "\"...How did you know, anyway?\"");
					break;
					case 17:
						changedokibodies(2, "12K");
						setDialogue("Natsuki", "\"I heard you bring it up at some point.\"");
					break;
					case 18:
						setDialogue("Natsuki", "\"Besides, it's kind of written on your face.\"");
					break;
					case 19:
						setDialogue(" ", "What's that supposed to mean...?");
					break;
					case 20:
						setDialogue("MC", "\"I-I see...\"");
					break;
					case 21:
						setDialogue(" ", "There's a lone volume of manga amidst a stack of various books on the side of one of the shelves.");
					break;
					case 22:
						setDialogue(" ", "Curious, I pull it out of the stack.");
					break;
					case 23:
						changedokibodies(2, "11E");
						setDialogue("Natsuki", "\"There it is!\"");
					break;
					case 24:
						setDialogue(" ", "Natsuki snatches it out of my hand.");
					break;
					case 25:
						setDialogue(" ", "She then turns to a box of manga and slips the volume right into the middle of the rest.");
					break;
					case 26:
						changedokibodies(2, "22D");
						setDialogue("Natsuki", "\"Aah, much better!\"");
					break;
					case 27:
						setDialogue("Natsuki", "\"Seeing a box set with one book missing is probably the most irritating sight in the world.\"");
					break;
					case 28:
						setDialogue("MC", "\"I know that feel...\"");
					break;
					case 29:
						setDialogue(" ", "I get a closer look at the box set she's admiring.");
					break;
					case 30:
						setDialogue("MC", "\"Parfait Girls...?\"");
					break;
					case 31:
						setDialogue(" ", "It's a series I've never heard of in my life.");
					break;
					case 32:
						setDialogue(" ", "That probably means it's either way out of my demographic, or it's simply terrible.");
					break;
					case 33:
						changedokibodies(2, "33G");
						setDialogue("Natsuki", "\"If you're gonna judge, you can go do it through the glass on that door.\"");
					break;
					case 34:
						setDialogue(" ", "She points to the classroom door.");
					break;
					case 35:
						setDialogue("MC", "\"H-Hey, I wasn't judging anything...!\"");
					break;
					case 36:
						setDialogue("MC", "\"I didn't even say anything.\"");
					break;
					case 37:
						changedokibodies(2, "33C");
						setDialogue("Natsuki", "\"It was the tone of your voice.\"");
					break;
					case 38:
						setDialogue("Natsuki", "\"But I'll tell you one thing, MC.\"");
					break;
					case 39:
						changedokibodies(2, "22D");
						setDialogue("Natsuki", "\"Consider this a lesson straight from the Literature Club: Don't judge a book by its cover!\"");
					break;
					case 40:
						setDialogue("Natsuki", "\"In fact--\"");
					break;
					case 41:
						setDialogue(" ", "Natsuki pulls out the first volume of Parfait Girls from the box.");
					break;
					case 42:
						setDialogue("Natsuki", "\"I'm gonna show you exactly why!\"");
					break;
					case 43:
						setDialogue(" ", "She shoves the book right into my hands.");
					break;
					case 44:
						setDialogue("MC", "\"Ah...\"");
					break;
					case 45:
						setDialogue(" ", "I stare at the cover.");
					break;
					case 46:
						setDialogue(" ", "It features four girls in colorful attire striking animated feminine poses.");
					break;
					case 47:
						setDialogue(" ", "It's...exceedingly \"moe\".");
					break;
					case 48:
						changedokibodies(2, "22E");
						setDialogue("Natsuki", "\"Don't just stand there!\"");
					break;
					case 49:
						setDialogue("MC", "\"Uwa--\"");
					break;
					case 50:
						setDialogue(" ", "Natsuki grabs my arm and pulls me out of the closet.");
					break;
					case 51:
						setDialogue(" ", "She then takes a seat against the wall, beneath the windowsills.");
					break;
					case 52:
						//Loading Club
					break;
					case 53:
						changedokibodies(2, "12A");
						setDialogue("MC", "\"Wouldn't chairs be more comfortable...?\"");
					break;
					case 54:
						setDialogue(" ", "I take my seat.");
					break;
					case 55:
						changedokibodies(2, "12C");
						setDialogue("Natsuki", "\"Chairs wouldn't work.\"");
					break;
					case 56:
						setDialogue("Natsuki", "\"We can't read at the same time like that.\"");
					break;
					case 57:
						setDialogue("MC", "\"Eh? Why's that?\"");
					break;
					case 58:
						setDialogue("MC", "\"Ah...I guess it's easier to be close together like this...\"");
					break;
					case 59:
						changedokibodies(2, "12O");
						setDialogue("Natsuki", "\"--!\"");
					break;
					case 60:
						changedokibodies(2, "33O");
						setDialogue("Natsuki", "\"D-Don't just say that!\"");
					break;
					case 61:
						setDialogue("Natsuki", "\"You'll make me feel weird about it!\"");
					break;
					case 62:
						setDialogue(" ", "Natsuki crosses her arms and scootches an inch away from me.");
					break;
					case 63:
						setDialogue("MC", "\"Sorry...\"");
					break;
					case 64:
						changedokibodies(2, "33G");
						setDialogue(" ", "I didn't exactly expect to be sitting this close to her, either...");
					break;
					case 65:
						setDialogue(" ", "Not that I can say it's a particularly bad thing.");
					break;
					case 66:
						setDialogue(" ", "I open the book.");
					break;
					case 67:
						setDialogue(" ", "It's only a few seconds before Natsuki once again inches closer, reclaiming the additional space while she hopes I won't notice.");
					break;
					case 68:
						setDialogue(" ", "I can feel her peering over my shoulder, much more eager to begin reading than I am.");
					break;
					case 69:
						changedokibodies(2, "11K");
						setDialogue("Natsuki", "\"Wow, how long has it been since I read the beginning...?\"");
					break;
					case 70:
						setDialogue("MC", "\"Hm?\"");
					break;
					case 71:
						setDialogue("MC", "\"You don't go back and flip through the older volumes every now and then?\"");
					break;
					case 72:
						setDialogue("Natsuki", "\"Not really.\"");
					break;
					case 73:
						setDialogue("Natsuki", "\"Maybe sometimes after I've already finished the series.\"");
					break;
					case 74:
						changedokibodies(2, "11C");
						setDialogue("Natsuki", "\"Hey, are you paying attention?\"");
					break;
					case 75:
						setDialogue("MC", "\"Uh..\"");
					break;
					case 76:
						setDialogue(" ", "I am, but nothing's really happened yet, so I can talk at the same time.");
					break;
					case 77:
						setDialogue(" ", "It looks like it's about a bunch of friends in high school.");
					break;
					case 78:
						setDialogue(" ", "I kind of grew out of these, since it's rare for the writing to be entertaining enough to make up for the lack of plot.");
					break;
					case 79:
						setDialogue("MC", "\"So...\"");
					break;
					case 80:
						setDialogue("MC", "\"What should I expect from this?\"");
					break;
					case 81:
						setDialogue("MC", "\"Is there going to be plot?\"");
					break;
					case 82:
						changedokibodies(2, "22X");
						setDialogue("Natsuki", "\"Well, obviously!\"");
					break;
					case 83:
						setDialogue("Natsuki", "\"You think I would enjoy something that didn't have a plot?\"");
					break;
					case 84:
						changedokibodies(2, "22C");
						setDialogue("Natsuki", "\"I mean...\"");
					break;
					case 85:
						changedokibodies(2, "12C");
						setDialogue("Natsuki", "\"Well, I guess I know what you're saying...\"");
					break;
					case 86:
						changedokibodies(2, "12K");
						setDialogue("Natsuki", "\"A lot of the beginning is about simple things...\"");
					break;
					case 87:
						setDialogue("Natsuki", "\"Like there's a really funny chapter where they're obsessed with a guy at the ice cream shop...\"");
					break;
					case 88:
						changedokibodies(2, "12C");
						setDialogue("Natsuki", "\"But that just helps you get to know the characters!\"");
					break;
					case 89:
						setDialogue("Natsuki", "\"And besides, it's still entertaining.\"");
					break;
					case 90:
						changedokibodies(2, "12D");
						setDialogue("Natsuki", "\"But later on, there's all kinds of drama...\"");
					break;
					case 91:
						setDialogue("Natsuki", "\"Like when they get into all their backstories, and when some of the romance starts to happen...\"");
					break;
					case 92:
						setDialogue("Natsuki", "\"That's really what makes it so good.\"");
					break;
					case 93:
						changedokibodies(2, "12A");
						setDialogue("Natsuki", "\"There are so many touching parts.\"");
					break;
					case 94:
						setDialogue("MC", "\"Ah, is that so?\"");
					break;
					case 95:
						setDialogue("MC", "\"It sounds like you really know what you're talking about.\"");
					break;
					case 96:
						setDialogue("MC", "\"Maybe I underestimated you.\"");
					break;
					case 97:
						changedokibodies(2, "12Z");
						setDialogue("Natsuki", "\"Ehehe.\"");
					break;
					case 98:
						changedokibodies(2, "11E");
						setDialogue("Natsuki", "\"...Hey, wait!\"");
					break;
					case 99:
						setDialogue("Natsuki", "\"What's that supposed to mean?!\"");
					break;
					case 100:
						setDialogue("MC", "\"Uwa--\"");
					break;
					case 101:
						setDialogue(" ", "Natsuki gives me a little shove.");
					break;
					case 102:
						setDialogue("MC", "\"I just meant that I haven't yet seen you at your full power...\"");
					break;
					case 103:
						changedokibodies(2, "33S");
						setDialogue("Natsuki", "\"Hmph. Good save.\"");
					break;
					case 104:
						setDialogue("MC", "\"Ah... This chapter seems like it's about baking.\"");
					break;
					case 105:
						setDialogue("MC", "\"This is just a guess, but is there a lot of baking in this manga?\"");
					break;
					case 106:
						changedokibodies(2, "33E");
						setDialogue("Natsuki", "\"Well--\"");
					break;
					case 107:
						setDialogue(" ", "Natsuki pauses for a moment, as if she doesn't want to admit something.");
					break;
					case 108:
						changedokibodies(2, "12S");
						setDialogue("Natsuki", "\"...Yeah.\"");
					break;
					case 109:
						setDialogue("Natsuki", "\"Why does that matter?\"");
					break;
					case 110:
						setDialogue("MC", "\"It doesn't, I was just curious...\"");
					break;
					case 111:
						setDialogue("MC", "\"Since you enjoy baking too, right?\"");
					break;
					case 112:
						changedokibodies(2, "11O");
						setDialogue("Natsuki", "\"That's--\"");
					break;
					case 113:
						setDialogue("Natsuki", "\"Just a coincidence!\"");
					break;
					case 114:
						changedokibodies(2, "11E");
						setDialogue("Natsuki", "\"I just happened to get into baking around the same time I got this manga.\"");
					break;
					case 115:
						setDialogue("Natsuki", "\"Like I would ever get into anything because it's in a manga.\"");
					break;
					case 116:
						changedokibodies(2, "22D");
						setDialogue("Natsuki", "\"I feel bad for anyone that impressionable.\"");
					break;
					case 117:
						setDialogue("Natsuki", "\"Ahaha!\"");
					break;
					case 118:
						setDialogue(" ", "Definitely not a coincidence...");
					break;
					case 119:
						setDialogue(" ", "I guess that explains Natsuki's interest in baking.");
					break;
					case 120:
						setDialogue(" ", "Still, of all the hobbies to pick up from a manga, that's definitely one of the better ones.");
					break;
					case 121:
						setDialogue(" ", "Not to mention she's really good at it, so who am I to judge?");
					break;
					case 122:
						//Loading Natsuki Special
					break;
					case 123:
						//textboxlow = true;
						natsukivisible = false;
						setDialogue(" ", "...");
					break;
					case 124:
						setDialogue(" ", "We read on for a few more minutes.");
					break;
					case 125:
						setDialogue(" ", "I've finished a couple chapters at this point.");
					break;
					case 126:
						setDialogue("MC", "\"...\"");
					break;
					case 127:
						setDialogue("MC", "\"...Are you sure this isn't boring for you?\"");
					break;
					case 128:
						setDialogue("Natsuki", "\"It's not!\"");
					break;
					case 129:
						setDialogue("MC", "\"Even though you're just watching me read?\"");
					break;
					case 130:
						setDialogue("Natsuki", "\"Well...!\"");
					break;
					case 131:
						setDialogue("Natsuki", "\"I'm...fine with that.\"");
					break;
					case 132:
						setDialogue("MC", "\"If you say so...\"");
					break;
					case 133:
						setDialogue("MC", "\"...I guess it's fun sharing something you like with someone else.\"");
					break;
					case 134:
						setDialogue("MC", "\"I always get excited when I convince any of my friends to pick up a series I enjoy.\"");
					break;
					case 135:
						setDialogue("MC", "\"You know what I mean?\"");
					break;
					case 136:
						setDialogue("Natsuki", "\"...?\"");
					break;
					case 137:
						setDialogue("MC", "\"Hm?\"");
					break;
					case 138:
						setDialogue("MC", "\"You don't?\"");
					break;
					case 139:
						setDialogue("Natsuki", "\"Um...\"");
					break;
					case 140:
						setDialogue("Natsuki", "\"That's not...\"");
					break;
					case 141:
						setDialogue("Natsuki", "\"Well, I wouldn't really know.\"");
					break;
					case 142:
						setDialogue("MC", "\"...What do you mean?\"");
					break;
					case 143:
						setDialogue("MC", "\"Don't you share your manga with your friends?\"");
					break;
					case 144:
						setDialogue("Natsuki", "\"Could you not rub it in?\"");
					break;
					case 145:
						setDialogue("Natsuki", "\"Jeez...\"");
					break;
					case 146:
						setDialogue("MC", "\"Ah... Sorry...\"");
					break;
					case 147:
						setDialogue("Natsuki", "\"Hmph.\"");
					break;
					case 148:
						setDialogue("Natsuki", "\"Like I could ever get my friends to read this...\"");
					break;
					case 149:
						setDialogue("Natsuki", "\"They just think manga is for kids.\"");
					break;
					case 150:
						setDialogue("Natsuki", "\"I can't even bring it up without them being all like...\"");
					break;
					case 151:
						setDialogue("Natsuki", "\"'Eh? You still haven't grown out of that yet?'\"");
					break;
					case 152:
						setDialogue("Natsuki", "\"Makes me want to punch them in the face...\"");
					break;
					case 153:
						setDialogue("MC", "\"Urgh, I know those kinds of people...\"");
					break;
					case 154:
						setDialogue("MC", "\"Honestly, it takes a lot of effort to find friends who don't judge, much less friends who are also into it...\"");
					break;
					case 155:
						setDialogue("MC", "\"I'm already kind of a loser, so I guess I gravitated toward the other losers over time.\"");
					break;
					case 156:
						setDialogue("MC", "\"But it's probably harder for someone like you...\"");
					break;
					case 157:
						setDialogue("Natsuki", "\"Hm.\"");
					break;
					case 158:
						setDialogue("Natsuki", "\"Yeah, that's pretty accurate.\"");
					break;
					case 159:
						setDialogue(" ", "...Wait, which part??");
					break;
					case 160:
						setDialogue("Natsuki", "\"I mean, I feel like I can't even keep it in my own room...\"");
					break;
					case 161:
						setDialogue("Natsuki", "\"I don't even know what my dad would do if he found this.\"");
					break;
					case 162:
						setDialogue("Natsuki", "\"At least it's safe here in the clubroom.\"");
					break;
					case 163:
						setDialogue("Natsuki", "\"'Cept Monika was kind of a jerk about it...\"");
					break;
					case 164:
						setDialogue("Natsuki", "\"Ugh! I just can't win, can I?\"");
					break;
					case 165:
						setDialogue("MC", "\"Well, it paid off in the end, didn't it?\"");
					break;
					case 166:
						setDialogue("MC", "\"I mean, here I am, reading it.\"");
					break;
					case 167:
						setDialogue("Natsuki", "\"Well, it's not like that solves any of my problems.\"");
					break;
					case 168:
						setDialogue("MC", "\"Maybe...\"");
					break;
					case 169:
						setDialogue("MC", "\"But at least you're enjoying yourself, right?\"");
					break;
					case 170:
						setDialogue("Natsuki", "\"--\"");
					break;
					case 171:
						setDialogue("Natsuki", "\"...\"");
					break;
					case 172:
						setDialogue("Natsuki", "\"...So?\"");
					break;
					case 173:
						setDialogue("MC", "\"Ahaha.\"");
					break;
					case 174:
						setDialogue("Natsuki", "\"Jeez, that's enough!\"");
					break;
					case 175:
						setDialogue("Natsuki", "\"Are you gonna keep reading, or what?\"");
					break;
					case 176:
						setDialogue("MC", "\"Yeah, yeah...\"");
					break;
					case 177:
						setDialogue(" ", "I flip the page.");
					break;
					case 178:
						setDialogue(" ", "Suddenly, Natsuki starts laughing.");
					break;
					case 179:
						setDialogue("Natsuki", "\"Ahahaha!\"");
					break;
					case 180:
						setDialogue("Natsuki", "\"I totally forgot that happens!\"");
					break;
					case 181:
						setDialogue(" ", "Natsuki puts her finger on one of the panels.");
					break;
					case 182:
						setDialogue("Natsuki", "\"Minori is my favorite character.\"");
					break;
					case 183:
						setDialogue("Natsuki", "\"You always feel a little bad for her, since she's so unlucky.\"");
					break;
					case 184:
						setDialogue("Natsuki", "\"But it gets especially bad when--\"");
					break;
					case 185:
						setDialogue("Natsuki", "\"Uu...\"");
					break;
					case 186:
						setDialogue("Natsuki", "\"I shouldn't be talking about that yet!\"");
					break;
					case 187:
						setDialogue("Natsuki", "\"Just finish this chapter!\"");
					break;
					case 188:
						//Loading Club
					break;
					case 189:
						//textboxlow = false;
						setDialogue(" ", "Natsuki's voice sparkles with excitement.");
					break;
					case 190:
						setDialogue(" ", "It's a stark contrast to her usual bossy tone.");
					break;
					case 191:
						setDialogue(" ", "But if she's not used to sharing her favorite manga with her friends, I can understand why.");
					break;
					case 192:
						setDialogue(" ", "It's hard to express in words the feeling you get when connecting with someone like that.");
					break;
					case 193:
						setDialogue(" ", "And being able to provide that to Natsuki, for whom it's a rare experience...");
					break;
					case 194:
						setDialogue(" ", "The thought makes me smile a little to myself.");
					break;
					case 195:
						monikavisible = true;
						changeDokiPos(1,1,2);
						changedokibodies(1,"21B");
						setDialogue("Monika", "\"Okay, everyone!\"");
					break;
					case 196:
						sprintf(nameshowed, "MC");
						setDialogue("MC", "\"Eh?\"");
					break;	
					case 197:
						setDialogue("Monika", "\"Are you all ready with today's poems?\"");
					break;
					case 198:
						setDialogue("MC", "\"...\"");
					break;	
					case 199:
						natsukivisible = true;
						changeDokiPos(2,2,2);
						changedokibodies(2,"22E");
						setDialogue("Natsuki", "\"Oh, come on!\"");
					break;	
					case 200:
						setDialogue("Natsuki", "\"Could your timing be any worse?\"");
					break;		
					case 201:
						changedokibodies(1,"11K");
						setDialogue("Monika", "\"Sorry!\"");
					break;		
					case 202:
						setDialogue("Monika", "\"I just need to make sure we have enough time.\"");
					break;		
					case 203:
						setDialogue("Monika", "\"Though you do look pretty cozy over there. Ahaha!\"");
					break;		
					case 204:
						changedokibodies(2,"22O");
						setDialogue("Natsuki", "\"Eh...?\"");
					break;		
					case 205:
						changedokibodies(2,"11P");
						setDialogue("Natsuki", "\"A-Ah!\"");
					break;		
					case 206:
						setDialogue(" ", "Natsuki suddenly notices how close she's gotten to me.");
					break;		
					case 207:
						setDialogue(" ", "She hastily slides herself a good twelve inches away from me.");
					break;		
					case 208:
						setDialogue("MC", "\"Alright...\"");
					break;		
					case 209:
						setDialogue("MC", "\"Guess I'll stop here for now.\"");
					break;		
					case 210:
						setDialogue(" ", "I close the book and hand it towards Natsuki.");
					break;		
					case 211:
						changedokibodies(2,"12M");
						setDialogue("Natsuki", "\"You're just giving it back...?\"");
					break;		
					case 212:
						setDialogue("Natsuki", "\"Don't you want to know what happens?\"");
					break;		
					case 213:
						setDialogue("MC", "\"Ah... Yeah, but...\"");
					break;			
					case 214:
						setDialogue("Monika", "\"Monika just said--\"");
					break;			
					case 215:
						changedokibodies(2,"12U");
						setDialogue("Natsuki", "\"Don't be dumb.\"");
					break;		
					case 216:
						setDialogue("Natsuki", "\"Just take it home with you.\"");
					break;		
					case 217:
						setDialogue("MC", "\"Eh?\"");
					break;		
					case 218:
						setDialogue("MC", "\"...Is that really alright?\"");
					break;		
					case 219:
						setDialogue(" ", "I say that mostly because I really didn't plan on using my spare time to read this...");
					break;		
					case 220:
						changedokibodies(2,"22C");
						setDialogue("Natsuki", "\"Well, of course.\"");
					break;		
					case 221:
						setDialogue("Natsuki", "\"It would take forever to finish if you didn't take it home.\"");
					break;		
					case 222:
						setDialogue("Natsuki", "\"Just finish that one before tomorrow, so we can start the next one.\"");
					break;		
					case 223:
						changedokibodies(2,"22G");
						setDialogue("Natsuki", "\"And if it gets bent, I'll kill you.\"");
					break;	
					case 224:
						setDialogue("MC", "\"By tomorrow...?\"");
					break;	
					case 225:
						setDialogue(" ", "I only got partway through the volume so far.");
					break;		
					case 226:
						setDialogue(" ", "I might fall behind on some shows if I try to get through this...");
					break;		
					case 227:
						setDialogue(" ", "But I suppose that's a necessary sacrifice in exchange for seeing Natsuki's enthusiastic face.");
					break;		
					case 228:
						setDialogue(" ", "Or am I more scared of what will happen if I don't finish it...?");
					break;			
					case 229:
						setDialogue("MC", "Alright, then!");
					break;			
					case 230:
						setDialogue(" ", "I stand up.");
					break;			
					case 231:
						setDialogue(" ", "I return to where I put my stuff and carefully slip the book into my bag.");
						dokimoment = false;
						currentline = 75;
					break;		
				}
			}
			if (whowon == 3) {//Sayori
				switch(currentline) {
					case 1:
						setDialogue(" ", "Man...");
					break;
					case 2:
						setDialogue(" ", "It looks like no one wants to be bothered today.");
					break;
					case 3:
						setDialogue(" ", "I slump down into the nearest desk.");
					break;
					case 4:
						setDialogue(" ", "How am I supposed to occupy myself with something literature-related by myself like this?");
					break;
					case 5:
						setDialogue(" ", "I guess I could always read some of the book Yuri gave me...");
					break;
					case 6:
						setDialogue(" ", "...But I'm feeling a little too tired to read.");
					break;
					case 7:
						setDialogue(" ", "I could probably fall asleep right now.");
					break;
					case 8:
						setDialogue(" ", "I close my eyes and end up listening in on Sayori's conversation with Monika.");
					break;
					case 9:
						sayorivisible = true;
						changedokibodies(1, "11G");
						changeDokiPos(3,1,2);
						setDialogue("Sayori", "\"We're probably gonna seem really lame compared to all the other clubs, though...\"");
					break;
					case 10:
						monikavisible = true;
						changedokibodies(1, "12R");
						changeDokiPos(1,2,2);
						setDialogue("Monika", "\"Hmm...\"");
					break;
					case 11:
						changedokibodies(1, "12B");
						setDialogue("Monika", "\"Well, we can't give up.\"");
					break;
					case 12:
						setDialogue("Monika", "\"The festival is our chance to show everyone what literature is all about!\"");
					break;
					case 13:
						changedokibodies(1, "12D");
						setDialogue("Monika", "\"The problem is that the idea of a literature club sounds too dense and intellectual...\"");
					break;
					case 14:
						setDialogue("Monika", "\"But it's not like that at all, you know?\"");
					break;
					case 15:
						changedokibodies(1, "12A");
						setDialogue("Monika", "\"We just need a way of showing that to everyone...\"");
					break;
					case 16:
						setDialogue("Monika", "\"Something that speaks to their creative minds.\"");
					break;
					case 17:
						setDialogue("Sayori", "\"Mmmmmmmmmmm.....\"");
					break;
					case 18:
						setDialogue("Sayori", "\"That doesn't solve the problem, though!\"");
					break;
					case 19:
						changedokibodies(1, "12D");
						setDialogue("Monika", "\"Eh? What do you mean?\"");
					break;
					case 20:
						changedokibodies(3, "11C");
						setDialogue("Sayori", "\"Even if we come up with the most fun thing ever...\"");
					break;
					case 21:
						setDialogue("Sayori", "\"Nobody will come in the first place if it's a literature event.\"");
					break;
					case 22:
						setDialogue("Sayori", "\"So it's more important to figure out how to get people to show up in the first place, you know?\"");
					break;
					case 23:
						changedokibodies(3, "11A");
						setDialogue("Sayori", "\"And after they come, we can do the thing to speak to their creative minds.\"");
					break;
					case 24:
						setDialogue(" ", "...What's this?");
					break;
					case 25:
						setDialogue(" ", "Sayori is taking this really seriously.");
					break;
					case 26:
						setDialogue(" ", "It's rare to hear her deliberating like this.");
					break;
					case 27:
						changedokibodies(1, "12A");
						setDialogue("Monika", "\"Huh, that's a good point...\"");
					break;
					case 28:
						setDialogue("Monika", "\"In that case, do you think food will do the trick?\"");
					break;
					case 29:
						changedokibodies(3, "11N");
						setDialogue("Sayori", "\"W-What kind?!\"");
					break;
					case 30:
						setDialogue("Monika", "\"Ah... Well, I guess we could--\"");
					break;
					case 31:
						changedokibodies(3, "22R");
						setDialogue("Sayori", "\"Cupcakes!\"");
					break;
					case 32:
						changedokibodies(3, "11K");
						setDialogue("Monika", "\"Ahaha. Good thinking!\"");
					break;
					case 33:
						changedokibodies(3, "11A");
						setDialogue("Monika", "\"Natsuki would love to do that.\"");
					break;
					case 34:
						changedokibodies(3, "11Q");
						setDialogue("Sayori", "\"Ah! You're right!\"");
					break;
					case 35:
						setDialogue("Sayori", "\"Natsuki makes the best cupcakes!\"");
					break;
					case 36:
						setDialogue("Sayori", "\"That works out perfectly!!\"");
					break;
					case 37:
						changedokibodies(1, "11D");
						setDialogue("Monika", "\"That wasn't why you suggested it...?\"");
					break;
					case 38:
						changedokibodies(1, "11Q");
						setDialogue("Sayori", "\"Cupcakes speak to my creative tummy!\"");
					break;
					case 39:
						changedokibodies(1, "11L");
						setDialogue("Monika", "\"...\"");
					break;
					case 40:
						setDialogue("Monika", "\"Cupcakes it is, then.\"");
					break;
					case 41:
						changedokibodies(3, "11G");
						setDialogue("Sayori", "\"I'm hungry...\"");
					break;
					case 42:
						changedokibodies(1, "11A");
						setDialogue("Monika", "\"Anyway, we still need to work out the details of the event itself...\"");
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
						setDialogue(" ", "I find myself smiling.");
					break;
					case 45:
						setDialogue(" ", "In the end, Sayori is still her usual self.");
					break;
					case 46:
						setDialogue(" ", "But therein lies the unexpected reason I admire her.");
					break;
					case 47:
						setDialogue(" ", "Unlike me, who has trouble finding any motivation at all...");
					break;
					case 48:
						setDialogue(" ", "Sayori can put her mind to things and make them come to life.");
					break;
					case 49:
						setDialogue(" ", "I suppose that's why I end up letting her get on my case about things.");
					break;
					case 50:
						setDialogue(" ", "I can't help but wonder what it would be like to see the world through her eyes...");
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
						setDialogue("MC", "\"Uwaa--!\"");
					break;
					case 53:
						showname = false;
						setDialogue(" ", "I open my eyes to find Sayori's face filling my vision.");
					break;
					case 54:
						setDialogue(" ", "I nearly fall out of my chair.");
					break;
					case 55:
						sayoposZ = 0;
						showname = true;
						changeDokiPos(3,1,1);
						changedokibodies(3, "22Q");
						setDialogue("Sayori", "\"Ehehe, sorry!\"");
					break;
					case 56:
						changedokibodies(3, "11J");
						setDialogue("Sayori", "\"Wait!\"");
					break;
					case 57:
						setDialogue("Sayori", "\"Actually, I'm not sorry at all!\"");
					break;
					case 58:
						setDialogue("Sayori", "\"It's your fault for sleeping like that!\"");
					break;
					case 59:
						setDialogue("Sayori", "\"This isn't the napping club!\"");
					break;
					case 60:
						setDialogue("MC", "\"Does our school have a napping club...?\"");
					break;
					case 61:
						setDialogue("Sayori", "\"You're staying up late again, aren't you?\"");
					break;
					case 62:
						setDialogue("Sayori", "\"Now that you're in a club, you're gonna have less time for anime, you know!\"");
					break;
					case 63:
						setDialogue("Sayori", "\"You'll need to get used to it!\"");
					break;
					case 64:
						setDialogue("MC", "\"Don't say that so loud...!\"");
					break;
					case 65:
						setDialogue(" ", "I glance over my shoulder to see if Monika overheard.");
					break;
					case 66:
						changedokibodies(3, "11G");
						setDialogue("Sayori", "\"It's true, though...\"");
					break;
					case 67:
						setDialogue("MC", "\"Yeah...\"");
					break;
					case 68:
						setDialogue("MC", "\"I know, I know.\"");
					break;
					case 69:
						setDialogue("MC", "\"You're always looking out for me, Sayori.\"");
					break;
					case 70:
						changedokibodies(3, "22Q");
						setDialogue("Sayori", "\"Ehehe!\"");
					break;
					case 71:
						setDialogue("Sayori", "\"It's what I do best!\"");
					break;
					case 72:
						setDialogue("MC", "\"...That's a problem!\"");
					break;
					case 73:
						setDialogue("MC", "\"What about you?\"");
					break;
					case 74:
						setDialogue("MC", "\"You look out for me better than you look out for yourself.\"");
					break;
					case 75:
						setDialogue("MC", "\"You're still oversleeping every day, aren't you?\"");
					break;
					case 76:
						changedokibodies(3, "11Y");
						setDialogue("Sayori", "\"Eh?\"");
					break;
					case 77:
						setDialogue("Sayori", "\"N-Not every day!\"");
					break;
					case 78:
						setDialogue("MC", "\"That's not very convincing...\"");
					break;
					case 79:
						setDialogue("MC", "\"How many days this past week have you gotten up on time?\"");
					break;
					case 80:
						changedokibodies(3, "11M");
						setDialogue("Sayori", "\"That's...\"");
					break;
					case 81:
						changedokibodies(3, "11N");
						setDialogue("Sayori", "\"...It's a secret!\"");
					break;
					case 82:
						setDialogue("MC", "\"I knew it...\"");
					break;
					case 83:

						changedokibodies(3, "11P");
						setDialogue("Sayori", "\"C'monnnn!\"");
					break;
					case 84:
						setDialogue("Sayori", "\"At least give me the benefit of the doubt...\"");
					break;
					case 85:
						setDialogue("MC", "\"I can't even do that.\"");
					break;
					case 86:
						setDialogue("MC", "\"Look, Sayori, it's written all over you.\"");
					break;
					case 87:

						changedokibodies(3, "11G");
						setDialogue("Sayori", "\"Eh...?\"");
					break;
					case 88:
						setDialogue(" ", "Sayori glances around at herself.");
					break;
					case 89:
						setDialogue("Sayori", "\"How is it written all over me?\"");
					break;
					case 90:
						setDialogue("MC", "\"You were clearly in a rush this morning...\"");
					break;
					case 91:
						setDialogue("MC", "\"Look, your hair is sticking out all around here.\"");
					break;
					case 92:
						sayoposY = 1;

						changedokibodies(3, "11Y");
						setDialogue("Sayori", "\"Ah--\"");
					break;
					case 93:
						setDialogue(" ", "I run my fingertips down the side of Sayori's hair, trying to straighten it out.");
					break;
					case 94:
						setDialogue("MC", "\"Man, you really need a brush for this...\"");
					break;
					case 95:
						setDialogue("Sayori", "\"My hair is just really hard to get right...\"");
					break;
					case 96:
						setDialogue("MC", "\"I won't fall for that.\"");
					break;
					case 97:
						setDialogue("MC", "\"There's more than just your hair.\"");
					break;
					case 98:
						setDialogue("MC", "\"Look, your bow isn't straight, either.\"");
					break;
					case 99:
						setDialogue("MC", "\"And there's a toothpaste stain on your collar right here.\"");
					break;
					case 100:
						setDialogue(" ", "I try to wipe off the stain with my finger.");
					break;
					case 101:
						sayoposY = -1;
						setDialogue("Sayori", "\"B-But nobody would ever notice that...\"");
					break;
					case 102:
						setDialogue("MC", "\"Of course they would.\"");
					break;
					case 103:
						setDialogue("MC", "\"Nobody's gonna tell you about it because they don't want to embarrass you.\"");
					break;
					case 104:
						setDialogue("MC", "\"Fortunately, I really don't care about that.\"");
					break;
					case 105:
						changedokibodies(3, "22M");
						setDialogue("Sayori", "\"Hey, you meanie...\"");
					break;
					case 106:
						setDialogue("MC", "\"And you don't even keep your blazer buttoned up.\"");
					break;
					case 107:
						setDialogue("MC", "\"Seriously, Sayori...\"");
					break;
					case 108:
						setDialogue("MC", "\"Why do you think you don't have a boyfriend yet?\"");
					break;
					case 109:
						changedokibodies(3, "11H");
						setDialogue("Sayori", "\"Eh??\"");
					break;
					case 110:
						setDialogue("Sayori", "\"That's super mean!\"");
					break;
					case 111:
						setDialogue("MC", "\"Sorry, but you'll thank me later...\"");
					break;
					case 112:
						setDialogue(" ", "I start to button her blazer from the bottom.");
					break;
					case 113:
						setDialogue("MC", "\"Once you see how much better it looks, you'll change your mind.\"");
					break;
					case 114:
						//Loading CG sayori
					break;
					case 115:
						//textboxlow = true;
						sayoposY = 0;
						sayorivisible = false;

						setDialogue("Sayori", "\"Ehehe!\""); 
					break;		
					case 116:
						setDialogue("Sayori", "\"This is so funny.\""); 
					break;	
					case 117:
						setDialogue("MC", "\"What is?\"");
					break;			
					case 118:
						setDialogue("Sayori", "\"Well...\""); 
					break;		
					case 119:
						setDialogue("Sayori", "\"I was just thinking how weird it is to have a friend who does these kinds of things.\""); 
					break;		
					case 120:
						setDialogue("MC", "\"Eh?\"");
					break;		
					case 121:
						setDialogue("MC", "\"D-Don't say that!\"");
					break;		
					case 122:
						setDialogue("MC", "\"You'll make me feel weird about it, stupid...\"");
					break;	
					case 123:
						setDialogue("Sayori", "\"It's okay, though.\"");
					break;	
					case 124:
						setDialogue("Sayori", "\"I'm happy we're like this.\"");
					break;	
					case 125:
						setDialogue("Sayori", "\"Aren't you?\"");
					break;	
					case 126:
						setDialogue("MC", "\"Ah--\"");
					break;	
					case 127:
						setDialogue("MC", "\"I-I guess...\"");
					break;	
					case 128:
						setDialogue("Sayori", "\"Hey, be careful...\"");
					break;	
					case 129:
						setDialogue("Sayori", "\"The button might come off!\"");
					break;	
					case 130:
						setDialogue("MC", "\"Why is this one so hard to close...?\"");
					break;	
					case 131:
						setDialogue(" ", "I struggle to fully close the button near her chest.");
					break;	
					case 132:
						setDialogue("MC", "\"Does this thing even fit you properly?\"");
					break;
					case 133:
						setDialogue("Sayori", "\"Ehehe-\"");
					break;	
					case 134:
						setDialogue("Sayori", "\"It did when I bought it.\"");
					break;	
					case 135:
						setDialogue("MC", "\"Sigh...\"");
					break;	
					case 136:
						setDialogue("MC", "\"If you ever buttoned it, you would have noticed sooner that it doesn't fit you anymore.\"");
					break;	
					case 137:
						setDialogue("MC", "\"What are you smiling about?\"");
					break;	
					case 138:

						setDialogue("Sayori", "\"It means my boobs got bigger again!\"");
					break;	
					case 139:
						setDialogue("MC", "\"D-Don't say that out loud!!\"");
					break;	
					case 140:
						setDialogue("Sayori", "\"Ehehe!\"");
					break;	
					case 141:
						setDialogue("MC", "\"Anyway...\"");
					break;	
					case 142:
						setDialogue("MC", "\"You look much better now, so...\"");
					break;	
					case 143:
						setDialogue("MC", "\"Ah...\"");
					break;		
					case 144:
						setDialogue(" ", "...Why does it feel strange to see Sayori's blazer buttoned up like that?");
					break;	
					case 145:
						setDialogue("Sayori", "\"But it's so stuffy...\"");
					break;	
					case 146:
						setDialogue("Sayori", "\"Uuu...\"");
					break;	
					case 147:
						setDialogue("Sayori", "\"It's not worth it at all!\"");
					break;	
					case 148:
						setDialogue(" ", "Sayori hastily unbuttons her blazer once more.");
					break;	
					case 149:
						//Loading Club
					break;	
					case 150:
						//textboxlow = false;
						showname = true;
						sayorivisible = true;
						changedokibodies(3, "11Q");
						setDialogue("Sayori", "\"Phew!\"");
					break;	
					case 151:
						setDialogue("Sayori", "\"That's so much better!!\"");
					break;	
					case 152:
						setDialogue(" ", "Sayori puts her arms out and twirls around.");
					break;	
					case 153:
						changedokibodies(3, "11A");

						setDialogue("Sayori", "\"So if I keep it unbuttoned then I won't get a boyfriend, right?\"");
					break;		
					case 154:
						setDialogue("MC", "\"What kind of logic is that?\"");
					break;		
					case 155:
						setDialogue("MC", "\"And why are you saying that like it's a good thing?\"");
					break;		
					case 156:
						setDialogue("Sayori", "\"Because...\"");
					break;	
					case 157:
						changedokibodies(3, "22H");
						setDialogue("Sayori", "\"...If I had a boyfriend, then he wouldn't even let you do things like this!\"");
					break;	
					case 158:
						changedokibodies(3, "22Y");
						setDialogue("Sayori", "\"And you take care of me better than anyone else would, anyway...\"");
					break;	
					case 159:
						setDialogue("Sayori", "\"So that's why I'm keeping it unbuttoned!\"");
					break;	
					case 160:
						setDialogue("MC", "\"Stop saying all these embarrassing things!\"");
					break;	
					case 161:
						changedokibodies(3, "11C");
						setDialogue("Sayori", "\"Eh?\"");
					break;	
					case 162:
						setDialogue("Sayori", "\"I didn't say anything embarrassing...\"");
					break;	
					case 163:
						setDialogue("MC", "\"Jeez...\"");
					break;	
					case 164:
						setDialogue("MC", "\"Well anyway, just focus on trying to wake up a little earlier...\"");
					break;	
					case 165:
						changedokibodies(3, "11J");
						setDialogue("Sayori", "\"Only if you focus on going to bed earlier!\"");
					break;	
					case 166:
						setDialogue("MC", "\"Fine, fine...\"");
					break;		
					case 167:
						setDialogue("MC", "\"It's a deal.\"");
					break;	
					case 168:
						changedokibodies(3, "22Q");
						setDialogue("Sayori", "\"Ehehe!\"");
					break;		
					case 169:
						changedokibodies(3, "22R");
						setDialogue("Sayori", "\"I guess we really are better at taking care of each other than we are at taking care of ourselves.\"");
					break;		
					case 170:
						setDialogue("MC", "\"Yeah, I guess so, huh...\"");
					break;			
					case 171:
						changedokibodies(3, "22Y");
						setDialogue("Sayori", "\"So maybe you should come wake me up in the morning!\"");
					break;	
					case 172:
						setDialogue("MC", "\"You're doing it again, Sayori...\"");
					break;	
					case 173:
						changedokibodies(3, "11H");
						setDialogue("Sayori", "\"Aw, but I was joking that time!\"");
					break;	
					case 174:
						setDialogue("Sayori", "\"Man, it's impossible to tell with you sometimes.\"");
					break;	
					case 175:
						monikavisible = true;
						changeDokiPos(1,1,4);
						changedokibodies(1,"21B");
						setDialogue("Monika", "\"Okay, everyone!\"");
					break;	
					case 176:
						setDialogue(" ", "Monika suddenly calls out.");
					break;	
					case 177:
						setDialogue("Monika", "\"Why don't we share the poems we wrote now?\"");
					break;	
					case 178:
						changedokibodies(3,"22R");
						setDialogue("Sayori", "\"Yay!!\"");
						sayoposY = 1;
					break;		
					case 179:
						changedokibodies(3,"22Q");
						setDialogue("Sayori", "\"MC, I can't wait to read yours!\"");
					break;	
					case 180:
						setDialogue("MC", "\"Yeah, same...\"");
					break;		
					case 181:
						setDialogue(" ", "I fail to sound enthusiastic, but Sayori still trots away to retrieve her poem.");
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
						monikavisible = true;
						changedokibodies(1, "11K");
						setDialogue("Monika", "\"Hi again, MC !\"");
						//2nd day
					break;
					case 2:
						setDialogue("Monika", "\"Glad to see you didn't run away on us. Hahaha!\"");
					break;
					case 3:
						setDialogue("MC", "\"Nah, don't worry.\"");
					break;
					case 4:
						setDialogue("MC", "\"This might be a little strange for me, but I at least keep my word.\"");
					break;
					case 5:
						setDialogue(" ", "Well, I'm back at the Literature Club.");
					break;
					case 6:
						setDialogue(" ", "I was the last to come in, so everyone else is already hanging out.");
					break;
					case 7:
						monikavisible = false;
						yurivisible = true;
						changedokibodies(3,"11A");
						setDialogue("Yuri", "\"Thanks for keeping your promise, MC.\"");
					break;
					case 8:
						setDialogue("Yuri", "\"I hope this isn't too overwhelming of a commitment for you.\"");
					break;
					case 9:
						changedokibodies(3,"11U");
						setDialogue("Yuri", "\"Making you dive headfirst into literature when you\"re not accustomed to it...\"");
					break;
					case 10:
						natsukivisible = true;
						changeDokiPos(2, 4, 4);
						changedokibodies(2, "22E");
						setDialogue("Natsuki", "\"Oh, come on! Like he deserves any slack.\"");
					break;
					case 11:
						setDialogue("Natsuki", "\"Sayori told me you didn't even want to join any clubs this year.\"");
					break;
					case 12:
						setDialogue("Natsuki", "\"And last year, too!\"");
					break;
					case 13:
						changedokibodies(2, "22C");
						setDialogue("Natsuki", "\"I don't know if you plan to just come here and hang out, or what...\"");
					break;
					case 14:
						setDialogue("Natsuki", "\"But if you don't take us seriously, then you won't see the end of it.\"");
					break;
					case 15:
						monikavisible = true;
						changedokibodies(1, "12B");
						changeDokiPos(1,1,4);
						setDialogue("Monika", "\"Natsuki, you certainly have a big mouth for someone who keeps her manga collection in the clubroom.\"");
					break;
					case 16:
						changedokibodies(2, "22O");
						setDialogue("Natsuki", "\"M-M-M...!!\"");
					break;
					case 17:
						monikavisible = false;
						setDialogue(" ", "Natsuki finds herself stuck between saying \"Monika\" and \"Manga\".");
					break;
					case 18:
						natsuposY = 1;
						setDialogue("Natsuki", "\"Manga is literature!!\"");
					break;
					case 19:
						natsukivisible = false;
						setDialogue(" ", "Swiftly defeated, Natsuki plops back into her seat.");
					break;
					case 20:
						sayorivisible = true;
						changeDokiPos(3,1,2);
						changeDokiPos(4,2,2);
						changedokibodies(3, "12Q");
						setDialogue("Sayori", "\"Don't worry, guys!\"");
					break;
					case 21:
						setDialogue("Sayori", "\"MC always gives it his best as long as he's having fun.\"");
					break;
					case 22:
						setDialogue("Sayori", "\"He helps me with busywork without me even asking.\"");
					break;
					case 23:
						setDialogue("Sayori", "\"Like cooking, cleaning my room...\"");
					break;
					case 24:
						changedokibodies(4, "22K");
						sprintf(nameshowed, "Yuri");
						setDialogue("Yuri", "\"How dependable...\"");
					break;
					case 25:
						setDialogue("MC", "\"Sayori, that's because your room is so messy it's distracting.\"");
					break;
					case 26:
						setDialogue("MC", "\"And you almost set your house on fire once.\"");
					break;
					case 27:
						changedokibodies(3,"11Y");
						setDialogue("Sayori", "\"Is that so... Ehehe...\"");
					break;
					case 28:
						changedokibodies(4,"11A");
						setDialogue("Yuri", "\"You two are really good friends, aren't you?\"");
					break;
					case 29:
						changedokibodies(4,"11U");
						setDialogue("Yuri", "\"I might be a little jealous...\"");
					break;
					case 30:
						changedokibodies(3,"11A");
						setDialogue("Sayori", "\"How come? You and MC can become good friends too!\"");
					break;
					case 31:
						changedokibodies(4,"22V");
						sprintf(nameshowed, "Yuri");
						setDialogue("Yuri", "\"U-Um...\"");
					break;
					case 32:
						setDialogue("MC", "\"S-Sayori--\"");
					break;
					case 33:
						setDialogue("Sayori", "\"Hmm?\"");
					break;
					case 34:
						setDialogue("MC", "\"...\"");
					break;
					case 35:
						setDialogue(" ", "As usual, Sayori seems oblivious to the weird situation she just put me into.");
					break;
					case 36:
						changedokibodies(3,"22R");
						setDialogue("Sayori", "\"Oh, oh! Yuri even brought you something today, you know!!\"");
					break;
					case 37:
						changedokibodies(4,"22N");
						setDialogue("Yuri", "\"W-Wait! Sayori...\"");
					break;
					case 38:
						setDialogue("Sayori", "\"Eh? Me?\"");
					break;
					case 39:
						setDialogue("Yuri", "\"Um... Not really...\"");
					break;
					case 40:
						setDialogue("Sayori", "\"Don't be shy!!\"");
					break;
					case 41:
						setDialogue("Yuri", "\"It's really nothing...\"");
					break;
					case 42:
						setDialogue("MC", "\"What is it?\"");
					break;
					case 43:
						changedokibodies(4,"22N");
						setDialogue("Yuri", "\"N-Never mind!\"");
					break;
					case 44:
						setDialogue("Yuri", "\"Sayori made it sound like a big deal when it's really not...\"");
					break;
					case 45:
						setDialogue("Yuri", "\"Uuuuh, what do I do...\"");
					break;
					case 46:
						changedokibodies(3,"11G");
						setDialogue("Sayori", "\"Eh? I'm sorry, Yuri, I wasn't thinking...\"");
					break;
					case 47:
						sayorivisible = false;
						changeDokiPos(4,1,1);
						setDialogue(" ", "I guess that means it's up to me to rescue this situation...");
					break;
					case 48:
						showname = true;
						sprintf(nameshowed, "MC");
						setDialogue("MC", "\"Hey, don't worry about it.\"");
					break;
					case 49:
						setDialogue("MC", "\"First of all, I wasn't expecting anything in the first place.\"");
					break;
					case 50:
						setDialogue("MC", "\"So any nice gesture from you is a pleasant surprise.\"");
					break;
					case 51:
						setDialogue("MC", "\"It'll make me happy no matter what.\"");
					break;
					case 52:
						changedokibodies(4,"22V");
						setDialogue("Yuri", "\"I-Is that so...\"");
					break;
					case 53:
						setDialogue("MC", "\"Yeah. I won't make it a big deal if you don't want it to be.\"");
					break;
					case 54:
						setDialogue("Yuri", "\"Alright...\"");
					break;
					case 55:
						changedokibodies(4,"11A");
						setDialogue("Yuri", "\"Well, here.\"");
					break;
					case 56:
						setDialogue(" ", "Yuri reaches into her bag and pulls out a book.");
					break;
					case 57:
						setDialogue("Yuri", "\"I didn't want you to feel left out...\"");
					break;
					case 58:
						setDialogue("Yuri", "\"So I picked out a book that I thought you might enjoy.\"");
					break;
					case 59:
						setDialogue("Yuri", "\"It's a short read, so it should keep your attention, even if you don't usually read.\"");
					break;
					case 60:
						setDialogue("Yuri", "\"And we could, you know...\"");
					break;
					case 61:
						changedokibodies(4,"22U");
						yuriposY = -1;
						setDialogue("Yuri", "\"Discuss it...if you wanted...\"");
					break;
					case 62:
						setDialogue(" ", "Th-This is...");
					break;
					case 63:
						setDialogue(" ", "How is this girl accidentally being so cute?");
					break;
					case 64:
						setDialogue(" ", "She even picked out a book she thinks I'll like, despite me not reading much...");
					break;
					case 65:
						setDialogue("MC", "\"Yuri, thank you! I'll definitely read this!\"");
					break;
					case 66:
						setDialogue(" ", "I enthusiastically take the book.");
					break;
					case 67:
						yuriposY = 0;
						changedokibodies(4, "22L");
						setDialogue("Yuri", "\"Phew...\"");
					break;
					case 68:
						changedokibodies(4, "22A");
						setDialogue("Yuri", "\"Well, you can read it at your own pace.\"");
					break;
					case 69:
						setDialogue("Yuri", "\"I look forward to hearing what you think.\"");
					break;
					case 70:
						yurivisible = false;
						setDialogue(" ", "Now that everyone's settled in, I expected Monika to kick off some scheduled activities for the club.");
					break;
					case 71:
						setDialogue(" ", "But that doesn't seem to be the case.");
					break;
					case 72:
						setDialogue(" ", "Sayori and Monika are having a cheery conversation in the corner.");
					break;
					case 73:
						setDialogue(" ", "Yuri's face is already buried in a book.");
					break;
					case 74:
						setDialogue(" ", "I can't help but notice her intense expression, like she was waiting for this chance.");
					break;
					case 75:
						setDialogue(" ", "Meanwhile, Natsuki is rummaging around in the closet.");
						currentline = 0;
						dokimoment = true;
					break;
					case 76:
						sayorivisible = false;
						yurivisible = false;
						natsukivisible = false;
						monikavisible = true;
						changeDokiPos(1,1,2);
						changedokibodies(1, "11A");
						setDialogue("Monika", "\"By the way, did you remember to write a poem last night?\"");
					break;
					case 77:
						setDialogue("MC", "\"Y-Yeah...\"");
					break;
					case 78:
						setDialogue(" ", "My relaxation ends.");
					break;
					case 79:
						setDialogue(" ", "I can't believe I agreed to do something so embarrassing.");
					break;
					case 80:
						setDialogue(" ", "I couldn't really find much inspiration, since I've never really done this before.");
					break;
					case 81:
						setDialogue("Monika", "\"Well, now that everyone's ready, why don't you find someone to share with?\"");
					break;
					case 82:
						sayorivisible = true;
						changeDokiPos(3,4,4);
						changedokibodies(3,"22Q");
						setDialogue("Sayori", "\"I can't wait!!\"");
					break;
					case 83:
						monikavisible = false;
						sayorivisible = false;
						setDialogue(" ", "Sayori and Monika enthusiastically pull out their poems.");
					break;
					case 84:
						setDialogue(" ", "Sayori's is on a wrinkled sheet of loose leaf torn from a spiral notebook.");
					break;
					case 85:
						setDialogue(" ", "On the other hand, Monika wrote hers in a composition notebook.");
					break;
					case 86:
						setDialogue(" ", "I can already see Monika's pristine handwriting from where I sit.");
					break;
					case 87:
						setDialogue(" ", "Natsuki and Yuri reluctantly comply as well, reaching into their bags.");
					break;
					case 88:
						setDialogue(" ", "I do the same, myself.");
						poemmoment = true;
						currentline = 0;
					break;
				}
			}
		break;
		default:
			switch(timeMoniUnstuckU) {
				case 0:
					switch(currentline) {
						case 1 :
							setDialogue("MC", "\"It seems that there's nothing in here...\"");
						break;
						case 2 :

							setDialogue("Sayori", "\"Hello ??\"");
						break;
						case 3 :
							setDialogue("MC", "\"Sayori !\"");
						break;
						case 4 :
							sayorivisible = true;
							changedokibodies(3, "11A");

							setDialogue("Sayori", "\"Yeah ? ?\"");
						break;
						case 5 :
							sprintf(nameshowed, "MC");
							setDialogue("MC", "\"Where are we ?\"");
						break;
						case 6 :
							changedokibodies(3, "12H");

							setDialogue("Sayori", "\"Um... I don't know, MC...\"");
						break;
						case 7 :
							monikavisible = true;
							changedokibodies(1, "11K");
							changeDokiPos(1,1,2);
							changeDokiPos(3,2,2);
							setDialogue("Monika", "\"Oh ! Here you are !\"");
						break;
						case 8 :
							changedokibodies(3, "22M");

							setDialogue("Sayori", "\"Waah ! You like, appeared out of nowhere !\"");
						break;
						case 9 :
							changedokibodies(1, "21B");
							setDialogue("Monika", "\"Don't toy with these parameters again, okay ?\"");
						break;
						case 10 :
							setDialogue("Monika", "\"There could be some little unexpected things to happen...\"");
						break;
						case 11 :
							moniposY = 1;
							changedokibodies(1, "11K");
							setDialogue("Monika", "\"Hehe !\"");
						break;
						case 12 :
							changedokibodies(3, "21G");

							setDialogue("Sayori", "\"W-What...\"");
						break;
						case 13 :
							changedokibodies(1, "22E");
							setDialogue("Monika", "\"Welp, I'll help you get unstuck !\"");
						break;
						case 14 :
							changedokibodies(1, "22B");
							setDialogue("Monika", "\"Right... Here !\"");
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
							setDialogue("MC", "\"It seems that there's nothing in here...\"");
						break;
						case 2:
							monikavisible = true;
							changedokibodies(1, "21D");
							setDialogue("Monika", "\"Hey ! What did I told you ?\"");
						break;
						case 3:
							setDialogue("Monika", "\"Do NOT try to toy with the values !\"");
						break;
						case 4:
							sayorivisible = true;
							changeDokiPos(1,2,2);
							changeDokiPos(3,1,2);
							changedokibodies(3, "11Y");
							setDialogue("Sayori", "\"Hello..?\"");
						break;
						case 5:
							changedokibodies(1, "11P");
							setDialogue("Monika", "\"Oh no...\"");
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
							setDialogue("MC", "\"It seems that there's nothing in here...\"");
						break;
						case 2:
							monikavisible = true;
							changedokibodies(1, "11D");
							setDialogue("Monika", "\"What the ??\"");
						break;
						case 3:
							changedokibodies(1, "11P");
							setDialogue("Monika", "\"I might just reset you at this point...\"");
						break;
						case 4:
							sayorivisible = true;
							changeDokiPos(1,2,2);
							changeDokiPos(3,1,2);
							changedokibodies(3, "11R");
							setDialogue("Sayori", "\"Hii !!\"");
						break;
						case 5:
							changedokibodies(1, "11E");
							setDialogue("Monika", "\"Please not right now !\"");
						break;
						case 6:
							sayoposY = -1;
							changedokibodies(3, "11P");

							setDialogue("Sayori", "\"Oww...\"");
						break;
						case 7:
							changedokibodies(1, "11P");
							setDialogue("Monika", "\"Stop doing that please...\"");
						break;
						case 8:
							ResetGame(false);
							currentday = 1;
							timeMoniUnstuckU++;
						break;
					}

				break;
				default:
					switch(currentline) {
						case 1 :
							setDialogue("MC", "\"It seems that there's nothing in here...\"");
						break;
						case 2:
							setDialogue(" ", "\"ResetGame(false); currentday = 1;\"");
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
}