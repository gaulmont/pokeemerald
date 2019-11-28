FallarborTown_MoveRelearnersHouse_MapScripts:: @ 8201382
	.byte 0

FallarborTown_MoveRelearnersHouse_EventScript_MoveRelearner:: @ 8201383
	lockall
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	msgbox FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove:: @ 82013A8
	checkitem ITEM_HEART_SCALE, 1
	compare VAR_RESULT, 0
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	msgbox FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case 0, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon:: @ 82013D6
	msgbox FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg
	compare VAR_0x8005, 0
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove:: @ 820140C
	msgbox FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	compare VAR_0x8004, 0
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	msgbox FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	takeitem ITEM_HEART_SCALE, 1
	goto FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	end

FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon:: @ 8201436
	msgbox FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg:: @ 8201444
	msgbox FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale:: @ 8201452
	msgbox FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor: @ 820145C
	.string "Je suis le MAITRE DES CAPACITES.\p"
	.string "Je connais absolument toutes les\n"
	.string "attaques que les POKéMON peuvent\l"
	.string "apprendre. Et je peux enseigner ces\l"
	.string "attaques à d'autres POKéMON.\p"
	.string "Je peux enseigner une attaque à l'un de\n"
	.string "tes POKéMON, si tu veux.\p"
	.string "Je peux le faire en échange d'une\n"
	.string "ECAILLECOEUR. Je les collectionne.$"

FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove: @ 8201541
	.string "Oh! Génial! C'est une ECAILLECOEUR\n"
	.string "d'une belle taille!\p"
	.string "Tu veux que j'enseigne une attaque\n"
	.string "à un de tes POKéMON?$"

FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon: @ 82015A5
	.string "A quel POKéMON dois-je l'enseigner?$"

FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove: @ 82015C3
	.string "Quelle attaque dois-je enseigner?$"

FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon: @ 82015DE
	.string "Désolé…\p"
	.string "Apparemment, il n'y a aucune attaque\n"
	.string "que je puisse apprendre à ce POKéMON.$"

FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale: @ 8201627
	.string "{PLAYER} donne une ECAILLECOEUR\n"
	.string "en échange.$"

FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale: @ 8201653
	.string "Si tu veux que j'enseigne une attaque\n"
	.string "à ton POKéMON, reviens avec\l"
	.string "une ECAILLECOEUR.$"

FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg: @ 8201697
	.string "Quoi? Mais je ne peux pas apprendre\n"
	.string "une attaque à un OEUF.$"

