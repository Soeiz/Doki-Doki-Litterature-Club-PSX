//Whoa. I didn't thought the poem sharing was so complex ! Good job Dan.
int n_poemappeal[3] = {0,0,0}; 
int s_poemappeal[3] = {0,0,0}; 
int m_poemappeal[3] = {0,0,0}; 
int y_poemappeal[3] = {0,0,0}; 
bool n_readpoem, y_readpoem, s_readpoem, m_readpoem = false;
char poemwinner[3][7] = {"Null", "Null", "Null"};
int currdialogue = 0;
/*
	currdialogue is like the "label" for the poem sharing. Since you can't check entire strings in C, it's just an int with this comment to help you here.

	0 : No one (choosing)

	1 : ch1_y_end
	2 : ch2_y_end
	3 : ch3_y_end
	4 : ch3_y_end_special

	5 : ch1_n_end
	6 : ch2_n_end
	7 : ch3_n_end
	8 : ch3_n_end_special

	9 : ch1_s_end
	10 : ch2_s_end
	11 : ch3_s_end

	12 : ch1_m_end
	13 : ch1_m_end2
	14 : ch2_m_end
	15: ch3_m_end

	16 : ch1_n_bad
	17 : ch1_n_med
	18 : ch1_n_good
	19 : ch2_n_bad
	20 : ch2_n_med
	21 : ch2_n_good
	22 : ch3_n_bad
	23 : ch3_n_med
	24 : ch3_n_good

	25 : ch1_s_bad
	26 : ch1_s_med
	27 : ch1_s_good
	28 : ch2_s_bad
	29 : ch2_s_med
	30 : ch2_s_good
	31 : ch3_s_bad
	32 : ch3_s_med
	33 : ch3_s_good

	34 : ch1_y_bad
	35 : ch1_y_med
	36 : ch1_y_good
	37 : ch2_y_bad
	38 : ch2_y_med
	39 : ch2_y_good
	40 : ch3_y_bad
	41 : ch3_y_med
	42 : ch3_y_good

	43 : m_sayori1
	44 : m_natsuki1
	45 : m_yuri1
	46 : m_sayori2
	47 : m_natsuki2
	48 : m_yuri2
	49 : m_sayori3
	50 : m_natsuki3
	51 : m_yuri3



	2679 lines of dialogue for the poem responses... Wish luck for me guys

*/

void setDialogue(const char *talker, const char *talk) {
	sprintf(nameshowed, talker);
	sprintf(dialogueline, talk);

	if (nameshowed[0] != ' ') {showname = true;} else {showname = false;}
}
void DialogueTyping(void) {
    if (strcmp(dialoguedisplayed,dialogueline) != 0 && !finishedwriting) { // IF dialoguedisplayed AND dialogueline is not exactly the same, AND it has not finished writing...

        if (frametextspeed == 1) { //Look if the last writing is finished

            dialoguedisplayed[indexdialogue] = dialogueline[indexdialogue]; //Write one letter based on the indexdialogue var
            indexdialogue++; //Advance one letter
            frametextspeed = frametextspeedfixed; //Reset the time for writing

        } else { //If last writing is not finished
            frametextspeed--; //FINISH.
        }
    } else {//IF dialoguedisplayed AND dialogueline is exactly the same
        if (indexdialogue != 0) {
            indexdialogue = 0; //Stop writing.
            dialogueEndText(); //Func to make things when the typing ends (choices, for instances.)
        }
    }
}

#include "DialogueLinesCH1.h"
#include "DialogueLinesCH3.h"
#include "DialoguePoemSharing.h"

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
						setDialogue(" ", "This game is not suitable for children or those who are easily disturbed.");
					break;
					case 2 :
						setDialogue(" ", "Individuals suffering from anxiety or depression may not have a safe experience playing this game. For content warnings, please visit: http://ddlc.moe/warning.html");
					break;
					case 3 :
						setDialogue(" ", "By playing Doki Doki Litterature Club, you agree that you are at least 13 years of age, and you consent to your exposure of highly disturbing content.");
					break;
				}
			} else {
				switch(currentline) {
					case 1 :
						setDialogue(" ", "It appears that you do not have any inserted memory cards in your playstation console.");
					break;
					case 2 :
						setDialogue(" ", "You should insert a memory card in the A Slot of your console. Without it, you will not be able to save, or load.");
					break;
					case 3 :
						setDialogue(" ", "By playing Doki Doki Litterature Club, you agree that you are at least 13 years of age, and you consent to your exposure of highly disturbing content.");
					break;
				}

			}
		break; // No need for separate files

		case 2:
			if (poemmoment) {
				changeDialogueLinePoem();
				return;
			}
			switch(currentchapter) {
				case 1 :
					changeDialogueLineCH1();
				break;
				case 3 :
					changeDialogueLineCH3();
				break;
			}
		break;
		case 4:
			switch(currentline) {
				case 1:
					setDialogue("MC", "\".......Sayo--\"");
				break;
			}
		break;// No need for separate files
	}
}