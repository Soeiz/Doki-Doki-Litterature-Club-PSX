void changeDialogueLinePoem(void) {
	if (currentline == 1 && dokipoem == 0) {
		setDialogue(" ", "Who should I show my poems to first?");
		createChoice(4,2);

		if (sample != 10) {
			//Loading Music
			brutalchange = false;
			requestedsong = 10;
		}
	}
	switch(currentchapter) {
		case 1:
			switch(currentday) {
				case 2:
					switch(dokipoem) {
						case 4:
							switch (currentline) {
								case 2:
									setDialogue(" ", "I'm definitely most comfortable sharing it with Sayori first.");
								break;
								case 3:
									setDialogue(" ", "She's my good friend, after all.");
								break;
							}
						break;
						case 3:
							setDialogue(" ", "Natsuki");
							currentline = 0;
						break;
						case 2:
							setDialogue(" ", "Yuri");
							currentline = 0;
						break;
						case 1:
							setDialogue(" ", "Monika");
							currentline = 0;
						break;
					}
				break;
			}
		break;
	}
}