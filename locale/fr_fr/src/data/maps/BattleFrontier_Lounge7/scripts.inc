BattleFrontier_Lounge7_MapScripts:: @ 8265254
	.byte 0

BattleFrontier_Lounge7_EventScript_265255:: @ 8265255
	lock
	faceplayer
	setvar VAR_TEMP_C, 9
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_265276
	msgbox BattleFrontier_Lounge7_Text_2656ED, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_265284
	end

BattleFrontier_Lounge7_EventScript_265276:: @ 8265276
	msgbox BattleFrontier_Lounge7_Text_2658AB, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_265284
	end

BattleFrontier_Lounge7_EventScript_265284:: @ 8265284
	message BattleFrontier_Lounge7_Text_2658EF
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_E, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_2653D7
	case 1, BattleFrontier_Lounge7_EventScript_2653E2
	case 2, BattleFrontier_Lounge7_EventScript_2653ED
	case 3, BattleFrontier_Lounge7_EventScript_2653F8
	case 4, BattleFrontier_Lounge7_EventScript_265403
	case 5, BattleFrontier_Lounge7_EventScript_26540E
	case 6, BattleFrontier_Lounge7_EventScript_265419
	case 7, BattleFrontier_Lounge7_EventScript_265424
	case 8, BattleFrontier_Lounge7_EventScript_26542F
	case 9, BattleFrontier_Lounge7_EventScript_26543A
	case 10, BattleFrontier_Lounge7_EventScript_265635
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_265635
	end

BattleFrontier_Lounge7_EventScript_26532F:: @ 826532F
	message BattleFrontier_Lounge7_Text_2658EF
	waitmessage
	setvar VAR_TEMP_E, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_2653D7
	case 1, BattleFrontier_Lounge7_EventScript_2653E2
	case 2, BattleFrontier_Lounge7_EventScript_2653ED
	case 3, BattleFrontier_Lounge7_EventScript_2653F8
	case 4, BattleFrontier_Lounge7_EventScript_265403
	case 5, BattleFrontier_Lounge7_EventScript_26540E
	case 6, BattleFrontier_Lounge7_EventScript_265419
	case 7, BattleFrontier_Lounge7_EventScript_265424
	case 8, BattleFrontier_Lounge7_EventScript_26542F
	case 9, BattleFrontier_Lounge7_EventScript_26543A
	case 10, BattleFrontier_Lounge7_EventScript_265635
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_265635
	end

BattleFrontier_Lounge7_EventScript_2653D7:: @ 82653D7
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_2653E2:: @ 82653E2
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_2653ED:: @ 82653ED
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_2653F8:: @ 82653F8
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_265403:: @ 8265403
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_26540E:: @ 826540E
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_265419:: @ 8265419
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_265424:: @ 8265424
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_26542F:: @ 826542F
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_26543A:: @ 826543A
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_265445:: @ 8265445
	lock
	faceplayer
	setvar VAR_TEMP_C, 10
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_265466
	msgbox BattleFrontier_Lounge7_Text_265A6C, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_265474
	end

BattleFrontier_Lounge7_EventScript_265466:: @ 8265466
	msgbox BattleFrontier_Lounge7_Text_265C2C, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_265474
	end

BattleFrontier_Lounge7_EventScript_265474:: @ 8265474
	message BattleFrontier_Lounge7_Text_2658EF
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_E, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_2655C7
	case 1, BattleFrontier_Lounge7_EventScript_2655D2
	case 2, BattleFrontier_Lounge7_EventScript_2655DD
	case 3, BattleFrontier_Lounge7_EventScript_2655E8
	case 4, BattleFrontier_Lounge7_EventScript_2655F3
	case 5, BattleFrontier_Lounge7_EventScript_2655FE
	case 6, BattleFrontier_Lounge7_EventScript_265609
	case 7, BattleFrontier_Lounge7_EventScript_265614
	case 8, BattleFrontier_Lounge7_EventScript_26561F
	case 9, BattleFrontier_Lounge7_EventScript_26562A
	case 10, BattleFrontier_Lounge7_EventScript_265635
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_265635
	end

BattleFrontier_Lounge7_EventScript_26551F:: @ 826551F
	message BattleFrontier_Lounge7_Text_2658EF
	waitmessage
	setvar VAR_TEMP_E, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_2655C7
	case 1, BattleFrontier_Lounge7_EventScript_2655D2
	case 2, BattleFrontier_Lounge7_EventScript_2655DD
	case 3, BattleFrontier_Lounge7_EventScript_2655E8
	case 4, BattleFrontier_Lounge7_EventScript_2655F3
	case 5, BattleFrontier_Lounge7_EventScript_2655FE
	case 6, BattleFrontier_Lounge7_EventScript_265609
	case 7, BattleFrontier_Lounge7_EventScript_265614
	case 8, BattleFrontier_Lounge7_EventScript_26561F
	case 9, BattleFrontier_Lounge7_EventScript_26562A
	case 10, BattleFrontier_Lounge7_EventScript_265635
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_265635
	end

BattleFrontier_Lounge7_EventScript_2655C7:: @ 82655C7
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_2655D2:: @ 82655D2
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_2655DD:: @ 82655DD
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_2655E8:: @ 82655E8
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_2655F3:: @ 82655F3
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_2655FE:: @ 82655FE
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_265609:: @ 8265609
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_265614:: @ 8265614
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_26561F:: @ 826561F
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_26562A:: @ 826562A
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_26564F
	end

BattleFrontier_Lounge7_EventScript_265635:: @ 8265635
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_265A0E, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_265645:: @ 8265645
	msgbox BattleFrontier_Lounge7_Text_265A0E, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8004 here is used to determine which move name to buffer
@ VAR_0x8005 here is used to determine which move tutor was spoken to
BattleFrontier_Lounge7_EventScript_26564F:: @ 826564F
	copyvar VAR_0x8004, VAR_TEMP_D
	copyvar VAR_0x8005, VAR_TEMP_E
	special BufferBattleFrontierTutorMoveName
	buffernumberstring 1, VAR_0x8008
	copyvar VAR_0x8004, VAR_TEMP_C
	msgbox BattleFrontier_Lounge7_Text_265921, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_Lounge7_EventScript_2656CA
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	compare VAR_TEMP_1, VAR_0x8008
	goto_if_ge BattleFrontier_Lounge7_EventScript_265696
	msgbox BattleFrontier_Lounge7_Text_265997, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_2656CA
	end

BattleFrontier_Lounge7_EventScript_265696:: @ 8265696
	msgbox BattleFrontier_Lounge7_Text_26595A, MSGBOX_DEFAULT
	special GetBattleFrontierTutorMoveIndex
	fadescreen 1
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_Lounge7_EventScript_265645
	msgbox BattleFrontier_Lounge7_Text_2659C7, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_Lounge7_EventScript_2656CA:: @ 82656CA
	compare VAR_TEMP_E, 0
	goto_if_eq BattleFrontier_Lounge7_EventScript_26532F
	goto BattleFrontier_Lounge7_EventScript_26551F
	end

BattleFrontier_Lounge7_EventScript_2656DB:: @ 82656DB
	msgbox BattleFrontier_Lounge7_Text_265C6F, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_2656E4:: @ 82656E4
	msgbox BattleFrontier_Lounge7_Text_265D17, MSGBOX_NPC
	end

BattleFrontier_Lounge7_Text_2656ED: @ 82656ED
	.string "Oh, oh!\p"
	.string "Tu auras du mal à le croire, mais dans le\n"
	.string "temps, j'étais un DRESSEUR hors pair.\p"
	.string "On disait que j'étais le CANON le\n"
	.string "plus doué du coin!\p"
	.string "… … … … … …\p"
	.string "Comment?\n"
	.string "Je sais, c'est dur à croire.\p"
	.string "Je ne suis pas comme cette vantarde en\n"
	.string "face. Moi, j'ai vraiment du talent!\p"
	.string "Je vais te le prouver.\n"
	.string "Je peux enseigner à tes POKéMON des\l"
	.string "capacités particulières mais mignonnes.\p"
	.string "Bien sûr, ce ne sera pas gratuit.\n"
	.string "Si tu payais ces capacités avec des\l"
	.string "POINTS DE COMBAT?$"

BattleFrontier_Lounge7_Text_2658AB: @ 82658AB
	.string "Oh, oh!\p"
	.string "Tu veux des capacités particulières\n"
	.string "mais mignonnes pour tes POKéMON?$"

BattleFrontier_Lounge7_Text_2658EF: @ 82658EF
	.string "Bien!\n"
	.string "Quelle capacité veux-tu?$"

BattleFrontier_Lounge7_Text_265921: @ 8265921
	.string "{STR_VAR_1}, n'est-ce pas?\n"
	.string "{STR_VAR_2} POINTS DE COMBAT, d'accord?$"

BattleFrontier_Lounge7_Text_26595A: @ 826595A
	.string "Maintenant, choisis le POKéMON à\n"
	.string "qui je dois enseigner cette capacité.$"

BattleFrontier_Lounge7_Text_265997: @ 8265997
	.string "Mais enfin…\n"
	.string "Tu n'as pas assez de POINTS DE COMBAT!$"

BattleFrontier_Lounge7_Text_2659C7: @ 82659C7
	.string "Je suis douée, non?\n"
	.string "Je prends tes POINTS DE COMBAT, merci!$"

BattleFrontier_Lounge7_Text_265A0E: @ 8265A0E
	.string "Oh?\n"
	.string "Tu as changé d'avis…\p"
	.string "Si tu veux que je te montre à quel point\n"
	.string "je suis douée, reviens me voir!$"

BattleFrontier_Lounge7_Text_265A6C: @ 8265A6C
	.string "Hi, hi, hi!\p"
	.string "C'est difficile à imaginer, à présent,\n"
	.string "mais j'ai été un DRESSEUR fantastique.\p"
	.string "On disait que j'étais la plus forte\n"
	.string "des NAGEUSE, rien que ça!\p"
	.string "… … … … … …\p"
	.string "Comment?\n"
	.string "Tu ne me crois pas, évidemment.\p"
	.string "Je ne suis pas comme cette menteuse\n"
	.string "en face. J'ai vraiment du talent!\p"
	.string "Je peux te le prouver. Je peux\n"
	.string "enseigner des capacités difficiles\l"
	.string "mais belles à tes POKéMON.\p"
	.string "Bien sûr, ce ne sera pas gratuit.\n"
	.string "Si tu payais ces capacités avec des\l"
	.string "POINTS DE COMBAT?$"

BattleFrontier_Lounge7_Text_265C2C: @ 8265C2C
	.string "Hi, hi, hi!\p"
	.string "Tu veux que j'enseigne des capacités\n"
	.string "difficiles mais belles à tes POKéMON?$"

BattleFrontier_Lounge7_Text_265C6F: @ 8265C6F
	.string "Ces deux vieilles dames n'arrêtent pas\n"
	.string "de se critiquer, comme si elles se\l"
	.string "détestaient.\p"
	.string "Mais si c'était vrai, elles ne seraient\n"
	.string "pas toujours ensemble ici, non?$"

BattleFrontier_Lounge7_Text_265D17: @ 8265D17
	.string "Quand j'étais encore un GAMIN, ces deux\n"
	.string "femmes étaient fortes et magnifiques.\p"
	.string "Elles faisaient des ravages parmi\n"
	.string "les DRESSEURS.\p"
	.string "Mais malgré leur âge, elles sont\n"
	.string "toujours très fortes.\p"
	.string "On peut même dire qu'elles ont fait\n"
	.string "mûrir leurs capacités POKéMON.\p"
	.string "Tout de même… Je ne peux pas\n"
	.string "m'empêcher de penser…\p"
	.string "Vieillir, c'est bien cruel…$"

BattleFrontier_Lounge7_Text_265E30:: @ 8265E30
	.string "Regagne jusqu'à la\n"
	.string "moitié des PV max\n"
	.string "du lanceur.$"

BattleFrontier_Lounge7_Text_265E5B:: @ 8265E5B
	.string "Inflige des\n"
	.string "dégâts selon le\n"
	.string "niveau du lanceur.$"

BattleFrontier_Lounge7_Text_265E8A:: @ 8265E8A
	.string "Aspire la moitié\n"
	.string "des dégâts sur\n"
	.string "l'ennemi endormi.$"

BattleFrontier_Lounge7_Text_265EC0:: @ 8265EC0
	.string "Un coup de poing\n"
	.string "d'une puissance\n"
	.string "incroyable.$"

BattleFrontier_Lounge7_Text_265EED:: @ 8265EED
	.string "Un coup de pied\n"
	.string "super puissant et\n"
	.string "intense.$"

BattleFrontier_Lounge7_Text_265F1C:: @ 8265F1C
	.string "Une attaque en\n"
	.string "charge. Peut pa-\n"
	.string "ralyser l'ennemi.$"

BattleFrontier_Lounge7_Text_265F47:: @ 8265F47
	.string "Envoie de gros\n"
	.string "rochers. Peut\n"
	.string "apeurer l'ennemi.$"

BattleFrontier_Lounge7_Text_265F77:: @ 8265F77
	.string "Renvoie toute\n"
	.string "attaque physique,\n"
	.string "2 fois plus fort.$"

BattleFrontier_Lounge7_Text_265FAA:: @ 8265FAA
	.string "Un faible choc\n"
	.string "électrique qui\n"
	.string "paralyse l'ennemi.$"

BattleFrontier_Lounge7_Text_265FDD:: @ 8265FDD
	.string "Une danse de\n"
	.string "combat pour\n"
	.string "booster l'ATTAQUE.$"

BattleFrontier_Lounge7_Text_26600A:: @ 826600A
	.string "S'enroule, cache\n"
	.string "les faiblesses.\n"
	.string "Monte la DEFENSE.$"

BattleFrontier_Lounge7_Text_26603E:: @ 826603E
	.string "Attaque sonore\n"
	.string "qui ne peut être\n"
	.string "lancée qu'endormi.$"

BattleFrontier_Lounge7_Text_266070:: @ 8266070
	.string "Envoie de la boue\n"
	.string "au visage et rend\n"
	.string "moins précis.$"

BattleFrontier_Lounge7_Text_2660A6:: @ 82660A6
	.string "Envoie des rayons\n"
	.string "en forme d'étoile.\n"
	.string "Touche toujours.$"

BattleFrontier_Lounge7_Text_2660D0:: @ 82660D0
	.string "Attaque glaciale.\n"
	.string "Baisse la VITESSE\n"
	.string "de l'ennemi.$"

BattleFrontier_Lounge7_Text_2660FF:: @ 82660FF
	.string "Encaisse les\n"
	.string "attaques du tour\n"
	.string "et conserve 1 PV.$"

BattleFrontier_Lounge7_Text_26612D:: @ 826612D
	.string "Copie les effets\n"
	.string "de l'ennemi et les\n"
	.string "passe au lanceur.$"

BattleFrontier_Lounge7_Text_26615F:: @ 826615F
	.string "Un poing de glace\n"
	.string "pouvant geler\n"
	.string "l'ennemi.$"

BattleFrontier_Lounge7_Text_266185:: @ 8266185
	.string "Un poing électri-\n"
	.string "que pouvant para-\n"
	.string "lyser l'ennemi.$"

BattleFrontier_Lounge7_Text_2661B5:: @ 82661B5
	.string "Un poing de feu\n"
	.string "pouvant brûler\n"
	.string "l'ennemi.$"
