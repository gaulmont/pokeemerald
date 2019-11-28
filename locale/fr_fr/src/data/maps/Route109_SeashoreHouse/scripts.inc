Route109_SeashoreHouse_MapScripts:: @ 82693F4
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	.byte 0

Route109_SeashoreHouse_OnTransition: @ 82693FA
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeashoreHouse_EventScript_Owner:: @ 82693FE
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction:: @ 8269428
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_DefeatedTrainers:: @ 8269432
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
	giveitem_std ITEM_SODA_POP, 6
	compare VAR_RESULT, 0
	goto_if_eq Route109_SeashoreHouse_EventScript_BagFull
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_BagFull:: @ 8269456
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop:: @ 8269460
	showmoneybox 0, 0, 0
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route109_SeashoreHouse_EventScript_BuySodaPop
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	nop
	nop
	release
	end

Route109_SeashoreHouse_EventScript_BuySodaPop:: @ 8269484
	checkmoney 300, 0
	compare VAR_RESULT, FALSE
	goto_if_eq Route109_SeashoreHouse_EventScript_NotEnoughMoney
	checkitemspace ITEM_SODA_POP, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Route109_SeashoreHouse_EventScript_NotEnoughSpace
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
	takemoney 300, 0
	updatemoneybox 0, 0
	giveitem_std ITEM_SODA_POP
	hidemoneybox
	nop
	nop
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughMoney:: @ 82694C8
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	nop
	nop
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughSpace:: @ 82694D5
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	nop
	nop
	release
	end

Route109_SeashoreHouse_EventScript_Dwayne:: @ 82694E2
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Johanna:: @ 82694FD
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Simon:: @ 8269518
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion:: @ 8269533
	checktrainerflag TRAINER_DWAYNE
	goto_if_lt Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	checktrainerflag TRAINER_JOHANNA
	goto_if_lt Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	checktrainerflag TRAINER_SIMON
	goto_if_lt Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
	release
	end

Route109_SeashoreHouse_EventScript_TrainersNotCompleted:: @ 8269553
	release
	end

Route109_SeashoreHouse_Text_SeashoreHouseIntro: @ 8269555
	.string "Je suis le propriétaire de la MAISON\n"
	.string "DU BORD DE MER, mais tu peux m'appeler\l"
	.string "M. MER!\p"
	.string "Ce que j'aime par-dessus tout, ce sont\n"
	.string "les combats endiablés de POKéMON.\p"
	.string "Voyons si tu as un esprit combatif!\p"
	.string "Si tu peux vaincre tous ces DRESSEURS,\n"
	.string "je t'offrirai une récompense.$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches: @ 8269635
	.string "Montre-moi de beaux combats!\p"
	.string "Après tout, c'est pour ça que je dirige\n"
	.string "la MAISON DU BORD DE MER!$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles: @ 8269685
	.string "Bravo, ça c'était du combat qui tue!\n"
	.string "Ces combats étaient incroyables! J'en\l"
	.string "ai eu pour mon argent!\p"
	.string "Pour te remercier de m'avoir offert un\n"
	.string "tel spectacle, je vais t'offrir ça.\p"
	.string "Une demi-douzaine de bouteilles de\n"
	.string "SODA COOL!$"

Route109_SeashoreHouse_Text_BagFull: @ 826973A
	.string "Oh, mais dis-moi, ton SAC est plein. Je\n"
	.string "vais garder ça pour toi.$"

Route109_SeashoreHouse_Text_WantToBuySodaPop: @ 826977E
	.string "Tu veux acheter du SODA COOL?\n"
	.string "Les POKéMON adorent ça!\p"
	.string "C'est 300$ la bouteille!\n"
	.string "Achètes-en!$"

Route109_SeashoreHouse_Text_HereYouGo: @ 82697C8
	.string "Voilà!$"

Route109_SeashoreHouse_Text_NotEnoughMoney: @ 82697D5
	.string "Tu n'as pas assez d'argent.$"

Route109_SeashoreHouse_Text_ThatsTooBad: @ 82697EF
	.string "Non?\n"
	.string "Tant pis.$"

Route109_SeashoreHouse_Text_DwayneIntro: @ 8269803
	.string "Si tu cherches un combat en haute mer,\n"
	.string "je suis ton homme. Le meilleur\l"
	.string "de tous, petit matelot!$"

Route109_SeashoreHouse_Text_DwayneDefeated: @ 8269867
	.string "C'était un beau combat!\n"
	.string "J'accepte la défaite, mon pote!$"

Route109_SeashoreHouse_Text_DwaynePostBattle: @ 826989D
	.string "Quand je suis à POIVRESSEL,\n"
	.string "je me bats et je bois du SODA COOL!$"

Route109_SeashoreHouse_Text_JohannaIntro: @ 82698E3
	.string "Moi, je ne perds pas mon temps avec des\n"
	.string "combats qui n'en valent pas la peine.\p"
	.string "Au moins, les combats endiablés enri-\n"
	.string "chissent les DRESSEURS et les POKéMON!$"

Route109_SeashoreHouse_Text_JohannaDefeated: @ 8269947
	.string "J'ai pas eu le temps de m'ennuyer!$"

Route109_SeashoreHouse_Text_JohannaPostBattle: @ 8269953
	.string "J'ai soif, maintenant. Je vais aller\n"
	.string "boire un SODA COOL.$"

Route109_SeashoreHouse_Text_SimonIntro: @ 8269986
	.string "Je vais te montrer la puissance de mes\n"
	.string "POKéMON, mais ne viens pas pleurer!$"

Route109_SeashoreHouse_Text_SimonDefeated: @ 82699C5
	.string "J'ai perdu, mais je ne vais pas pleurer…$"

Route109_SeashoreHouse_Text_SimonPostBattle: @ 82699DF
	.string "Si un de mes POKéMON pouvait me\n"
	.string "transporter sur son dos, je ne serais\l"
	.string "pas obligé de garder cette bouée.$"

