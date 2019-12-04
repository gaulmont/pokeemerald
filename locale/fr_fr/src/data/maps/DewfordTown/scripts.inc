DewfordTown_MapScripts:: @ 81E9507
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_OnTransition
	.byte 0

DewfordTown_OnTransition: @ 81E950D
	setflag FLAG_VISITED_DEWFORD_TOWN
	end

DewfordTown_EventScript_1E9511:: @ 81E9511
	lock
	faceplayer
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, DewfordTown_EventScript_1E9585
	message DewfordTown_Text_1E9C8A
	waitmessage
	multichoicedefault 21, 6, MULTI_BRINEY_ON_DEWFORD, 2, 0
	switch VAR_RESULT
	case 0, DewfordTown_EventScript_1E955A
	case 1, DewfordTown_EventScript_1E956A
	case 2, DewfordTown_EventScript_1E957A
	case MULTI_B_PRESSED, DewfordTown_EventScript_1E957A
	end

DewfordTown_EventScript_1E955A:: @ 81E955A
	msgbox DewfordTown_Text_1E9CE5, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_1E9660
	release
	end

DewfordTown_EventScript_1E956A:: @ 81E956A
	msgbox DewfordTown_Text_1E9D3A, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_1E96E7
	release
	end

DewfordTown_EventScript_1E957A:: @ 81E957A
	msgbox DewfordTown_Text_1E9D8F, MSGBOX_DEFAULT
	closemessage
	release
	end

DewfordTown_EventScript_1E9585:: @ 81E9585
	msgbox DewfordTown_Text_1E9B24, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_EventScript_1E95A2
	msgbox DewfordTown_Text_1E9BD9, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_1E95A2:: @ 81E95A2
	msgbox DewfordTown_Text_1E9B7F, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_1E9660
	end

DewfordTown_EventScript_1E95B1:: @ 81E95B1
	msgbox DewfordTown_Text_1E99A8, MSGBOX_NPC
	end

DewfordTown_EventScript_1E95BA:: @ 81E95BA
	msgbox DewfordTown_Text_1E9A0F, MSGBOX_SIGN
	end

DewfordTown_EventScript_1E95C3:: @ 81E95C3
	msgbox DewfordTown_Text_1E9A3D, MSGBOX_SIGN
	end

DewfordTown_EventScript_1E95CC:: @ 81E95CC
	msgbox DewfordTown_Text_1E9A7F, MSGBOX_SIGN
	end

DewfordTown_EventScript_1E95D5:: @ 81E95D5
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD, DewfordTown_EventScript_1E962A
	msgbox DewfordTown_Text_1E9DD1, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_EventScript_1E95FF
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_EventScript_1E9620
	end

DewfordTown_EventScript_1E95FF:: @ 81E95FF
	msgbox DewfordTown_Text_1E9E14, MSGBOX_DEFAULT
	giveitem_std ITEM_OLD_ROD
	setflag FLAG_RECEIVED_OLD_ROD
	msgbox DewfordTown_Text_1E9E65, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_1E9620:: @ 81E9620
	msgbox DewfordTown_Text_1E9F92, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_1E962A:: @ 81E962A
	message DewfordTown_Text_1E9FB8
	waitmessage
	multichoice 20, 8, MULTI_HOWS_FISHING, 1
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_EventScript_1E964C
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_EventScript_1E9656
	end

DewfordTown_EventScript_1E964C:: @ 81E964C
	msgbox DewfordTown_Text_1E9FD0, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_1E9656:: @ 81E9656
	msgbox DewfordTown_Text_1EA004, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_1E9660:: @ 81E9660
	call EventScript_BackupMrBrineyLocation
	setobjectpriority 2, MAP_DEWFORD_TOWN, 0
	setobjectpriority EVENT_OBJ_ID_PLAYER, MAP_DEWFORD_TOWN, 0
	applymovement 2, DewfordTown_Movement_1E991D
	waitmovement 0
	removeobject 2
	applymovement EVENT_OBJ_ID_PLAYER, DewfordTown_Movement_1E9911
	waitmovement 0
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_DEWFORD_TOWN
	call Common_EventScript_PlayBrineysBoatMusic
	applymovement 4, DewfordTown_Movement_1E97A2
	applymovement EVENT_OBJ_ID_PLAYER, DewfordTown_Movement_1E97A2
	waitmovement 0
	showobjectat EVENT_OBJ_ID_PLAYER, MAP_ROUTE104
	call Common_EventScript_StopBrineysBoatMusic
	applymovement EVENT_OBJ_ID_PLAYER, DewfordTown_Movement_1E9914
	waitmovement 0
	showobjectat EVENT_OBJ_ID_PLAYER, MAP_ROUTE104
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	hideobjectat 4, MAP_DEWFORD_TOWN
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 2
	resetobjectpriority EVENT_OBJ_ID_PLAYER, MAP_DEWFORD_TOWN
	warp MAP_ROUTE104_MR_BRINEYS_HOUSE, 255, 5, 4
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
	waitstate
	release
	end

DewfordTown_EventScript_1E96E7:: @ 81E96E7
	call EventScript_BackupMrBrineyLocation
	setobjectpriority 2, MAP_DEWFORD_TOWN, 0
	setobjectpriority EVENT_OBJ_ID_PLAYER, MAP_DEWFORD_TOWN, 1
	applymovement 2, DewfordTown_Movement_1E991D
	waitmovement 0
	removeobject 2
	applymovement EVENT_OBJ_ID_PLAYER, DewfordTown_Movement_1E9911
	waitmovement 0
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_DEWFORD_TOWN
	call Common_EventScript_PlayBrineysBoatMusic
	applymovement 4, DewfordTown_Movement_1E9865
	applymovement EVENT_OBJ_ID_PLAYER, DewfordTown_Movement_1E9865
	waitmovement 0
	call Common_EventScript_StopBrineysBoatMusic
	showobjectat EVENT_OBJ_ID_PLAYER, MAP_ROUTE109
	applymovement EVENT_OBJ_ID_PLAYER, DewfordTown_Movement_1E9918
	waitmovement 0
	setobjectxyperm 2, 21, 26
	addobject 2
	setobjectpriority 2, MAP_ROUTE109, 0
	applymovement 2, DewfordTown_Movement_1E991F
	waitmovement 0
	clearflag FLAG_HIDE_ROUTE_109_MR_BRINEY
	addobject 1
	clearflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	hideobjectat 4, MAP_DEWFORD_TOWN
	call_if_unset FLAG_DELIVERED_DEVON_GOODS, DewfordTown_EventScript_1E9790
	call_if_set FLAG_DELIVERED_DEVON_GOODS, DewfordTown_EventScript_1E9799
	closemessage
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
	resetobjectpriority EVENT_OBJ_ID_PLAYER, MAP_DEWFORD_TOWN
	resetobjectpriority 2, MAP_ROUTE109
	copyobjectxytoperm 2
	release
	end

DewfordTown_EventScript_1E9790:: @ 81E9790
	msgbox DewfordTown_Text_BrineyLandedInSlateportDeliverGoods, MSGBOX_DEFAULT
	return

DewfordTown_EventScript_1E9799:: @ 81E9799
	msgbox DewfordTown_Text_BrineyLandedInSlateport, MSGBOX_DEFAULT
	return

DewfordTown_Movement_1E97A2: @ 81E97A2
	walk_up
	walk_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DewfordTown_Movement_1E9865: @ 81E9865
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

DewfordTown_Movement_1E9911: @ 81E9911
	walk_right
	walk_up
	step_end

DewfordTown_Movement_1E9914: @ 81E9914
	walk_up
	walk_up
	walk_up
	step_end

DewfordTown_Movement_1E9918: @ 81E9918
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

DewfordTown_Movement_1E991D: @ 81E991D
	walk_up
	step_end

DewfordTown_Movement_1E991F: @ 81E991F
	walk_up
	walk_up
	step_end

DewfordTown_EventScript_1E9922:: @ 81E9922
	lock
	faceplayer
	call DewfordTown_EventScript_271E8B
	msgbox DewfordTown_Text_1EA136, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_EventScript_1E9948
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_EventScript_1E9952
	end

DewfordTown_EventScript_1E9948:: @ 81E9948
	msgbox DewfordTown_Text_1EA491, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_1E9952:: @ 81E9952
	msgbox DewfordTown_Text_1EA242, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_TRENDY_PHRASE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_EventScript_1E997D
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_EventScript_1E9994
	end

DewfordTown_EventScript_1E997D:: @ 81E997D
	incrementgamestat GAME_STAT_STARTED_TRENDS
	compare VAR_0x8004, 0
	goto_if_eq DewfordTown_EventScript_1E999E
	msgbox DewfordTown_Text_1EA2AA, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_1E9994:: @ 81E9994
	msgbox DewfordTown_Text_1EA443, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_1E999E:: @ 81E999E
	msgbox DewfordTown_Text_1EA3FE, MSGBOX_DEFAULT
	release
	end

DewfordTown_Text_1E99A8: @ 81E99A8
	.string "Le VILLAGE MYOKARA est une petite.\n"
	.string "communauté insulaire.\p"
	.string "Ici, quand un truc est à la mode,\n"
	.string "tout le monde se l'arrache.$"

DewfordTown_Text_1E9A0F: @ 81E9A0F
	.string "VILLAGE MYOKARA\n"
	.string "“Une petite île au cœur de la mer.”$"

DewfordTown_Text_1E9A3D: @ 81E9A3D
	.string "ARENE POKéMON du VILLAGE MYOKARA\n"
	.string "CHAMPION: BASTIEN\l"
	.string "“Une vraie déferlante au combat!”$"

DewfordTown_Text_1E9A7F: @ 81E9A7F
	.string "CENTRE CULTUREL DE MYOKARA\n"
	.string "“Echange de tous types\n"
	.string "d'informations!”$"

Route104_Text_LandedInDewfordDeliverLetter: @ 81E9AAF
	.string "M. MARCO: Oyé!\n"
	.string "Nous sommes arrivés à MYOKARA.\p"
	.string "Je suppose que tu vas aller remettre\n"
	.string "cette LETTRE à ce… comment … PIERRE!$"

DewfordTown_Text_1E9B24: @ 81E9B24
	.string "M. MARCO: As-tu donné ta LETTRE?\p"
	.string "Ou comptes-tu retourner à CLEMENTI?$"

DewfordTown_Text_1E9B7F: @ 81E9B7F
	.string "M. MARCO: Allons-y pour\n"
	.string "CLEMENTI-VILLE!\p"
	.string "On lève l'ancre!\n"
	.string "PIKO, on embarque, mon chou!$"

DewfordTown_Text_1E9BD9: @ 81E9BD9
	.string "M. MARCO: Alors tu y vas et tu donnes la\n"
	.string "LETTRE. Je t'attendrai.$"

DewfordTown_Text_BrineyLandedInDewford: @ 81E9C1D
	.string "M. MARCO: Oyé!\n"
	.string "Nous sommes arrivés à MYOKARA!\p"
	.string "Tu y vas et tu n'auras qu'à me prévenir\n"
	.string "quand tu voudras repartir en mer!$"

DewfordTown_Text_1E9C8A: @ 81E9C8A
	.string "M. MARCO: Ohé!\n"
	.string "Pour toi, je sors en mer quand tu veux!\p"
	.string "Alors, mon camarade, où partons-nous?$"

DewfordTown_Text_1E9CE5: @ 81E9CE5
	.string "M. MARCO: CLEMENTI-VILLE, c'est ça?\p"
	.string "On lève l'ancre!\n"
	.string "PIKO, on embarque, mon chou!$"

DewfordTown_Text_1E9D3A: @ 81E9D3A
	.string "M. MARCO: POIVRESSEL, c'est bien ça?\p"
	.string "On lève l'ancre!\n"
	.string "PIKO, on embarque, mon chou!$"

DewfordTown_Text_1E9D8F: @ 81E9D8F
	.string "M. MARCO: Tu n'auras qu'à me prévenir\n"
	.string "quand tu auras besoin d'embarquer!$"

DewfordTown_Text_1E9DD1: @ 81E9DD1
	.string "C'est un endroit renommé pour la pêche.\n"
	.string "T'as attrapé le virus de la pêche?$"

DewfordTown_Text_1E9E14: @ 81E9E14
	.string "J'ai entendu ce que tu as dit\n"
	.string "et j'ai apprécié tes paroles!\p"
	.string "Je te donne une de mes CANNES à pêche.$"

DewfordTown_Text_1E9E65: @ 81E9E65
	.string "Et en plus, je vais même te donner un\n"
	.string "petit conseil pour la pêche!\p"
	.string "Tu dois d'abord te placer face à la mer\n"
	.string "et ensuite utiliser la CANNE.\p"
	.string "Concentre-toi…\n"
	.string "Si ça mord, tire sur la CANNE.\p"
	.string "Parfois, tu peux attraper quelque\n"
	.string "chose tout de suite, mais pour les plus\l"
	.string "grosses prises, il faut prendre le temps\l"
	.string "de tirer sur la CANNE pour les ramener.$"

DewfordTown_Text_1E9F92: @ 81E9F92
	.string "Ah, c'est comme ça?\n"
	.string "C'est vraiment dommage.$"

DewfordTown_Text_1E9FB8: @ 81E9FB8
	.string "Yo!\n"
	.string "Alors, ça va la pêche?$"

DewfordTown_Text_1E9FD0: @ 81E9FD0
	.string "C'est bien! Super!\n"
	.string "Ramène de grosses prises!$"

DewfordTown_Text_1EA004: @ 81EA004
	.string "Oh, hé, ne t'en va pas! Je vais te donner\n"
	.string "un petit conseil pour la pêche.\p"
	.string "Tu dois d'abord te placer face à la mer,\n"
	.string "et ensuite utiliser la CANNE.\p"
	.string "Concentre-toi…\n"
	.string "Si ça mord, tire sur la CANNE.\p"
	.string "Parfois, tu peux attraper quelque\n"
	.string "chose tout de suite, mais pour les plus\l"
	.string "grosses prises, il faut prendre le temps\l"
	.string "de tirer sur la CANNE pour les ramener.$"

DewfordTown_Text_1EA136: @ 81EA136
	.string "J'aime ce qui est en vogue, branché et à\n"
	.string "la mode. Je me tiens toujours informé.\p"
	.string "Hé, t'as déjà entendu parler de\n"
	.string "“{STR_VAR_1}”?\p"
	.string "C'est ça!\n"
	.string "Bien sûr que tu connais!\p"
	.string "Forcément, ouais,\n"
	.string "“{STR_VAR_1}”…\l"
	.string "Y a pas plus cool!\p"
	.string "Peu importe d'où tu viens,\n"
	.string "“{STR_VAR_1}”\l"
	.string "c'est ce qu'il y a de plus branché, hein?$"

DewfordTown_Text_1EA242: @ 81EA242
	.string "Hum?\n"
	.string "C'est pas ce qui est à la mode?\p"
	.string "Bon, alors dis-moi ce qui est nouveau\n"
	.string "et “in”?$"

DewfordTown_Text_1EA2AA: @ 81EA2AA
	.string "Hum?\n"
	.string "“{STR_VAR_2}”?\p"
	.string "… …\p"
	.string "…Hum… Ouais, c'est ça!\n"
	.string "Ouais, je l'savais! Je l'savais déjà!\p"
	.string "Bien sûr que j'étais au courant!\n"
	.string "“{STR_VAR_2},” hein?\p"
	.string "Ouais, bien sûr, tout juste!\n"
	.string "Attends, y a pas plus cool que\l"
	.string "“{STR_VAR_2}”?\p"
	.string "Y a pas plus branché en vocabulaire\n"
	.string "branché. Tu croyais que j'savais pas\p"
	.string "“{STR_VAR_1}”…\n"
	.string "C'était cool il y a cinq minutes.\p"
	.string "Mais, “{STR_VAR_2}” is\n"
	.string "c'est ce qui est à la mode maintenant!$"

DewfordTown_Text_1EA3FE: @ 81EA3FE
	.string "Hum…\n"
	.string "“{STR_VAR_2},” hein?\p"
	.string "Mais personnellement, je trouve que\n"
	.string "“{STR_VAR_1}”\l"
	.string "est définitivement plus cool.$"

DewfordTown_Text_1EA443: @ 81EA443
	.string "Si tu entends parler de nouvelles\n"
	.string "modes, viens m'en parler, d'accord??$"

DewfordTown_Text_1EA491: @ 81EA491
	.string "Ouais, tout à fait!\p"
	.string "“{STR_VAR_1}”\n"
	.string "reflète bien la tendance actuelle.$"
