Route104_MrBrineysHouse_MapScripts:: @ 8229D2E
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_MrBrineysHouse_OnTransition
	.byte 0

Route104_MrBrineysHouse_OnTransition: @ 8229D34
	setflag FLAG_LANDMARK_MR_BRINEY_HOUSE
	compare VAR_BRINEY_HOUSE_STATE, 1
	call_if_eq Route104_MrBrineysHouse_EventScript_229D50
	call_if_set FLAG_RECEIVED_POKENAV, Route104_MrBrineysHouse_EventScript_229D4C
	end

Route104_MrBrineysHouse_EventScript_229D4C:: @ 8229D4C
	setflag FLAG_HIDE_RUSBORO_CITY_RIVAL
	return

Route104_MrBrineysHouse_EventScript_229D50:: @ 8229D50
	setobjectxyperm 1, 9, 3
	setobjectmovementtype 1, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT
	setobjectxyperm 2, 9, 6
	setobjectmovementtype 2, MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN
	return

Route104_MrBrineysHouse_EventScript_229D67:: @ 8229D67
	lock
	faceplayer
	call_if_unset FLAG_MR_BRINEY_SAILING_INTRO, Route104_MrBrineysHouse_EventScript_229D8A
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_MrBrineysHouse_EventScript_229DE1
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route104_MrBrineysHouse_EventScript_229DFA
	goto Route104_MrBrineysHouse_EventScript_229DAE
	end

Route104_MrBrineysHouse_EventScript_229D8A:: @ 8229D8A
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	msgbox Route104_MrBrineysHouse_Text_229E70, MSGBOX_DEFAULT
	msgbox Route104_MrBrineysHouse_Text_229E9B, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Route104_MrBrineysHouse_EventScript_229E13
	goto Route104_MrBrineysHouse_EventScript_229E27
	end

Route104_MrBrineysHouse_EventScript_229DAE:: @ 8229DAE
	message Route104_MrBrineysHouse_Text_22A268
	waitmessage
	multichoicedefault 20, 8, MULTI_BRINEY_OFF_DEWFORD, 1, 0
	switch VAR_RESULT
	case 0, Route104_MrBrineysHouse_EventScript_229E27
	case 1, Route104_MrBrineysHouse_EventScript_229E1D
	case MULTI_B_PRESSED, Route104_MrBrineysHouse_EventScript_229E1D
	end

Route104_MrBrineysHouse_EventScript_229DE1:: @ 8229DE1
	msgbox Route104_MrBrineysHouse_Text_22A0AD, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Route104_MrBrineysHouse_EventScript_229E13
	goto Route104_MrBrineysHouse_EventScript_229E27
	end

Route104_MrBrineysHouse_EventScript_229DFA:: @ 8229DFA
	msgbox Route104_MrBrineysHouse_Text_22A18F, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Route104_MrBrineysHouse_EventScript_229E13
	goto Route104_MrBrineysHouse_EventScript_229E27
	end

Route104_MrBrineysHouse_EventScript_229E13:: @ 8229E13
	msgbox Route104_MrBrineysHouse_Text_22A041, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_229E1D:: @ 8229E1D
	msgbox Route104_MrBrineysHouse_Text_22A2C3, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_229E27:: @ 8229E27
	msgbox Route104_MrBrineysHouse_Text_229FE9, MSGBOX_DEFAULT
	call EventScript_BackupMrBrineyLocation
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 1
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setflag FLAG_HIDE_RUSBORO_CITY_RIVAL
	setflag FLAG_HIDE_ROUTE_104_RIVAL
	warp MAP_ROUTE104, 255, 13, 51
	waitstate
	releaseall
	end

Route104_MrBrineysHouse_EventScript_229E5D:: @ 8229E5D
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, 0
	msgbox Route104_MrBrineysHouse_Text_22A337, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route104_MrBrineysHouse_Text_229E70: @ 8229E70
	.string "M. MARCO: Attends, mon p'tit!\n"
	.string "PIKO, viens ici!$"

Route104_MrBrineysHouse_Text_229E9B: @ 8229E9B
	.string "Hein? Tu es {PLAYER}{KUN}!\n"
	.string "Tu as sauvé mon PIKO adoré!\l"
	.string "Nous te devons une fière chandelle!\p"
	.string "Comment?\n"
	.string "Tu veux embarquer avec moi?\p"
	.string "Humm…\p"
	.string "Alors comme ça, tu as une LETTRE à\n"
	.string "destination de MYOKARA et un\l"
	.string "paquet à déposer à POIVRESSEL?\p"
	.string "Tu ne dois pas avoir le temps\n"
	.string "de t'ennuyer!\p"
	.string "Quoi qu'il en soit, pas de problème\n"
	.string "Je peux t'aider.\p"
	.string "Tu as frappé à la bonne porte!\n"
	.string "On met le cap sur MYOKARA.$"

Route104_MrBrineysHouse_Text_229FE9: @ 8229FE9
	.string "M. MARCO: VILLAGE MYOKARA,\n"
	.string "nous voilà!\p"
	.string "Levons l'ancre!\n"
	.string "PIKO, mon chouchou, on met les voiles!$"

Route104_MrBrineysHouse_Text_22A041: @ 822A041
	.string "M. MARCO: Ah bon?\n"
	.string "Ta livraison peut attendre?\p"
	.string "Dans ce cas, reviens me voir quand tu\n"
	.string "voudras mettre les voiles!$"

Route104_MrBrineysHouse_Text_22A0AD: @ 822A0AD
	.string "M. MARCO: Ohé!\n"
	.string "Je vois très bien ce que tu veux dire!\p"
	.string "Tu dois livrer une LETTRE à MYOKARA\n"
	.string "et un paquet à POIVRESSEL.\p"
	.string "Ça n'me pose pas d'problème. Je suis\n"
	.string "l'homme de la situation!\p"
	.string "On mettra d'abord le cap sur MYOKARA.$"

Route104_MrBrineysHouse_Text_22A18F: @ 822A18F
	.string "M. MARCO: Ohé!\n"
	.string "Je vois très bien ce que tu veux dire!\p"
	.string "Tu dois livrer un paquet au CAPT. POUPE\n"
	.string "à POIVRESSEL.\p"
	.string "Ça n'me pose pas d'problème. Je suis\n"
	.string "l'homme de la situation!\p"
	.string "FOn mettra d'abord le cap sur MYOKARA.$"

Route104_MrBrineysHouse_Text_22A268: @ 822A268
	.string "M. MARCO: Ohé!\n"
	.string "Je peux appareiller quand tu veux!\p"
	.string "Bien! Où va-t-on, mon pote?$"

Route104_MrBrineysHouse_Text_22A2C3: @ 822A2C3
	.string "M. MARCO: Ah bon?\n"
	.string "Bah, PIKO te doit la vie.\p"
	.string "Tu peux revenir quand tu veux et\n"
	.string "je mettrai les voiles pour toi!$"

Route104_MrBrineysHouse_Text_22A337: @ 822A337
	.string "PIKO: Pii pi-hiorou!$"

