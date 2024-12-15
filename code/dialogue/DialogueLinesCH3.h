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
void changeDialogueLineCH3(void) {
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
				sprintf(dialogueline, "\"Oh, also, since I kinda broke the script... Haha...\"");
			break;
			case 26:
				sprintf(dialogueline, "\"I manually saved the game on your memory card!\"");
			break;
			case 27:
				sprintf(dialogueline, "\"That way, if for whatever reason you turn off the console, I'll still be there.\"");
			break;
			case 28:
				sprintf(dialogueline, "\"But don't ever think about it. I don't want to leave you.\"");
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
}