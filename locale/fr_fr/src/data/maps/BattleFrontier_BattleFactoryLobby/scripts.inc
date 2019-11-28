BattleFrontier_BattleFactoryLobby_MapScripts:: @ 82583E8
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryLobby_MapScript2_258407
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryLobby_MapScript2_2583F3
	.byte 0

BattleFrontier_BattleFactoryLobby_MapScript2_2583F3: @ 82583F3
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryLobby_EventScript_2583FD
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_2583FD:: @ 82583FD
	setvar VAR_TEMP_1, 1
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleFactoryLobby_MapScript2_258407: @ 8258407
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleFactoryLobby_EventScript_258431
	map_script_2 VAR_TEMP_0, 1, BattleFrontier_BattleFactoryLobby_EventScript_25843A
	map_script_2 VAR_TEMP_0, 2, BattleFrontier_BattleFactoryLobby_EventScript_258592
	map_script_2 VAR_TEMP_0, 3, BattleFrontier_BattleFactoryLobby_EventScript_25849B
	map_script_2 VAR_TEMP_0, 4, BattleFrontier_BattleFactoryLobby_EventScript_258506
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_258431:: @ 8258431
	setvar VAR_0x8004, 0
	special CallFrontierUtilFunc
	end

BattleFrontier_BattleFactoryLobby_EventScript_25843A:: @ 825843A
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_258ECA, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 8
	special CallBattleFactoryFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special CallBattleFactoryFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special CallBattleFactoryFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 0
	special CallBattleFactoryFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_25849B:: @ 825849B
	lockall
	setvar VAR_0x8004, 10
	special CallFrontierUtilFunc
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleFactoryLobby_EventScript_2584BD
	msgbox BattleFrontier_BattleFactoryLobby_Text_258D93, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattleFactoryLobby_EventScript_2584C6

BattleFrontier_BattleFactoryLobby_EventScript_2584BD:: @ 82584BD
	msgbox BattleFrontier_BattleFactoryLobby_Text_25926A, MSGBOX_DEFAULT
	waitmessage

BattleFrontier_BattleFactoryLobby_EventScript_2584C6:: @ 82584C6
	msgbox BattleFrontier_BattleFactoryLobby_Text_2592BD, MSGBOX_DEFAULT
	setvar VAR_0x8004, 11
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattleFactoryLobby_Text_241520, 9
	message BattleFrontier_BattleFactoryLobby_Text_259323
	waitmessage
	setvar VAR_0x8004, 8
	special CallFrontierUtilFunc
	special LoadPlayerParty
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 0
	special CallBattleFactoryFunction
	playse SE_SAVE
	waitse
	goto BattleFrontier_BattleFactoryLobby_EventScript_25853B
	end

BattleFrontier_BattleFactoryLobby_EventScript_258506:: @ 8258506
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_258CC7
	waitmessage
	setvar VAR_0x8004, 8
	special CallFrontierUtilFunc
	special LoadPlayerParty
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 0
	special CallBattleFactoryFunction
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 0
	special CallBattleFactoryFunction
	playse SE_SAVE
	waitse

BattleFrontier_BattleFactoryLobby_EventScript_25853B:: @ 825853B
	call BattleFrontier_BattleFactoryLobby_EventScript_23E8E0
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleFactoryLobby_EventScript_258582
	message BattleFrontier_BattleFactoryLobby_Text_259388
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_258582
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_25857D
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_258582

BattleFrontier_BattleFactoryLobby_EventScript_25857D:: @ 825857D
	call BattleFrontier_BattleFactoryLobby_EventScript_23E8B4

BattleFrontier_BattleFactoryLobby_EventScript_258582:: @ 8258582
	msgbox BattleFrontier_BattleFactoryLobby_Text_258BC5, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_258592:: @ 8258592
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_258E77
	waitmessage
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 1
	special CallBattleFactoryFunction
	playse SE_SAVE
	waitse
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_TEMP_0, 255
	setvar VAR_0x8006, 2
	goto BattleFrontier_BattleFactoryLobby_EventScript_25871A

BattleFrontier_BattleFactoryLobby_EventScript_2585CB:: @ 82585CB
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 4
	setvar VAR_FRONTIER_BATTLE_MODE, 0
	goto BattleFrontier_BattleFactoryLobby_EventScript_2585ED
	end

BattleFrontier_BattleFactoryLobby_EventScript_2585DD:: @ 82585DD
	setvar VAR_FRONTIER_FACILITY, 4
	setvar VAR_FRONTIER_BATTLE_MODE, 1
	goto BattleFrontier_BattleFactoryLobby_EventScript_2585ED
	end

BattleFrontier_BattleFactoryLobby_EventScript_2585ED:: @ 82585ED
	special SavePlayerParty
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattleFactoryLobby_EventScript_2587B1
	compare VAR_FRONTIER_BATTLE_MODE, 1
	call_if_eq BattleFrontier_BattleFactoryLobby_EventScript_2587BA

BattleFrontier_BattleFactoryLobby_EventScript_258606:: @ 8258606
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattleFactoryLobby_EventScript_2587C3
	compare VAR_FRONTIER_BATTLE_MODE, 1
	call_if_eq BattleFrontier_BattleFactoryLobby_EventScript_2587C9
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_258653
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_258768
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_25879D
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_25879D

BattleFrontier_BattleFactoryLobby_EventScript_258653:: @ 8258653
	message BattleFrontier_BattleFactoryLobby_Text_258BE9
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, 0
	switch VAR_RESULT
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_25879D
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_25879D
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	copyvar VAR_0x8006, VAR_RESULT
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattleFactoryLobby_Text_258C27, MSGBOX_YESNO
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_25879A
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_2586B9
	case 127, BattleFrontier_BattleFactoryLobby_EventScript_25879A

BattleFrontier_BattleFactoryLobby_EventScript_2586B9:: @ 82586B9
	setvar VAR_TEMP_0, 0
	setvar VAR_0x8004, 0
	special CallBattleFactoryFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 1
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 1
	special CallBattleFactoryFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleFactoryLobby_EventScript_258783
	setvar VAR_0x8006, 0

BattleFrontier_BattleFactoryLobby_EventScript_25871A:: @ 825871A
	special SavePlayerParty
	msgbox BattleFrontier_BattleFactoryLobby_Text_258CB1, MSGBOX_DEFAULT
	closemessage
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattleFactoryLobby_EventScript_25875C
	compare VAR_FRONTIER_BATTLE_MODE, 1
	call_if_eq BattleFrontier_BattleFactoryLobby_EventScript_258762
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_2587A7
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_2587AC
	waitmovement 0
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 255, 8, 13
	setvar VAR_TEMP_0, 0
	waitstate
	end

BattleFrontier_BattleFactoryLobby_EventScript_25875C:: @ 825875C
	setvar VAR_LAST_TALKED, 1
	return

BattleFrontier_BattleFactoryLobby_EventScript_258762:: @ 8258762
	setvar VAR_LAST_TALKED, 6
	return

BattleFrontier_BattleFactoryLobby_EventScript_258768:: @ 8258768
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattleFactoryLobby_EventScript_2587CF
	compare VAR_FRONTIER_BATTLE_MODE, 1
	call_if_eq BattleFrontier_BattleFactoryLobby_EventScript_2587D8
	goto BattleFrontier_BattleFactoryLobby_EventScript_258606

BattleFrontier_BattleFactoryLobby_EventScript_258783:: @ 8258783
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleFactoryLobby_EventScript_25879D

BattleFrontier_BattleFactoryLobby_EventScript_25879A:: @ 825879A
	special LoadPlayerParty

BattleFrontier_BattleFactoryLobby_EventScript_25879D:: @ 825879D
	msgbox BattleFrontier_BattleFactoryLobby_Text_258BC5, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_Movement_2587A7: @ 82587A7
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleFactoryLobby_Movement_2587AC: @ 82587AC
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryLobby_EventScript_2587B1:: @ 82587B1
	msgbox BattleFrontier_BattleFactoryLobby_Text_2588EE, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_2587BA:: @ 82587BA
	msgbox BattleFrontier_BattleFactoryLobby_Text_258F93, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_2587C3:: @ 82587C3
	message BattleFrontier_BattleFactoryLobby_Text_25897A
	return

BattleFrontier_BattleFactoryLobby_EventScript_2587C9:: @ 82587C9
	message BattleFrontier_BattleFactoryLobby_Text_25901F
	return

BattleFrontier_BattleFactoryLobby_EventScript_2587CF:: @ 82587CF
	msgbox BattleFrontier_BattleFactoryLobby_Text_2589B3, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_2587D8:: @ 82587D8
	msgbox BattleFrontier_BattleFactoryLobby_Text_259058, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_2587E1:: @ 82587E1
	lockall
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_2587FA:: @ 82587FA
	lockall
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, 1
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_258813:: @ 8258813
	msgbox BattleFrontier_BattleFactoryLobby_Text_2593D7, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_25881C:: @ 825881C
	msgbox BattleFrontier_BattleFactoryLobby_Text_2594E5, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_258825:: @ 8258825
	lock
	msgbox BattleFrontier_BattleFactoryLobby_Text_259547, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_258830:: @ 8258830
	msgbox BattleFrontier_BattleFactoryLobby_Text_2595C4, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_258839:: @ 8258839
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_259721, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_258848
	end

BattleFrontier_BattleFactoryLobby_EventScript_258848:: @ 8258848
	message BattleFrontier_BattleFactoryLobby_Text_259743
	waitmessage
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_2588A6
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_2588B4
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_2588C2
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_2588D0
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_2588DE
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_2588EC
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_2588EC
	end

BattleFrontier_BattleFactoryLobby_EventScript_2588A6:: @ 82588A6
	msgbox BattleFrontier_BattleFactoryLobby_Text_259766, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_258848
	end

BattleFrontier_BattleFactoryLobby_EventScript_2588B4:: @ 82588B4
	msgbox BattleFrontier_BattleFactoryLobby_Text_2597FB, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_258848
	end

BattleFrontier_BattleFactoryLobby_EventScript_2588C2:: @ 82588C2
	msgbox BattleFrontier_BattleFactoryLobby_Text_25987E, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_258848
	end

BattleFrontier_BattleFactoryLobby_EventScript_2588D0:: @ 82588D0
	msgbox BattleFrontier_BattleFactoryLobby_Text_259920, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_258848
	end

BattleFrontier_BattleFactoryLobby_EventScript_2588DE:: @ 82588DE
	msgbox BattleFrontier_BattleFactoryLobby_Text_259A5E, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_258848
	end

BattleFrontier_BattleFactoryLobby_EventScript_2588EC:: @ 82588EC
	releaseall
	end

BattleFrontier_BattleFactoryLobby_Text_2588EE: @ 82588EE
	.string "Bienvenue à l'USINE DE COMBAT!\p"
	.string "Ici, nous mettons à l'épreuve\n"
	.string "le savoir des DRESSEURS!\p"
	.string "Je serai votre guide pour le TOURNOI\n"
	.string "COMBAT ECHANGE SOLO.$"

BattleFrontier_BattleFactoryLobby_Text_25897A: @ 825897A
	.string "Voulez-vous relever le défi du\n"
	.string "COMBAT ECHANGE SOLO?$"

BattleFrontier_BattleFactoryLobby_Text_2589B3: @ 82589B3
	.string "Le TOURNOI COMBAT ECHANGE SOLO\n"
	.string "se compose de COMBATS SOLO. Vous\l"
	.string "utilisez des POKéMON de location.\p"
	.string "Vous devez choisir trois POKéMON parmi\n"
	.string "les POKéMON de location.\p"
	.string "Ensuite, vous faites des COMBATS\n"
	.string "SOLO avec ces POKéMON.\p"
	.string "Si vous gagnez, vous pouvez échanger\n"
	.string "l'un des POKéMON de location.\p"
	.string "Si vous gagnez sept combats à la suite,\n"
	.string "vous gagnez des POINTS DE COMBAT.\p"
	.string "Si vous voulez interrompre le défi,\n"
	.string "veuillez sauvegarder la partie.\p"
	.string "Si vous ne sauvegardez pas,\n"
	.string "c'est la disqualification.$"

BattleFrontier_BattleFactoryLobby_Text_258BC5: @ 8258BC5
	.string "Nous espérons vous compter parmi\n"
	.string "nos participants une prochaine fois.$"

BattleFrontier_BattleFactoryLobby_Text_258BE9: @ 8258BE9
	.string "Que choisissez-vous: niveau 50 ou\n"
	.string "niveau libre?$"

BattleFrontier_BattleFactoryLobby_Text_258C27: @ 8258C27
	.string "Avant de commencer, votre partie doit\n"
	.string "être sauvegardée. OK?$"

BattleFrontier_BattleFactoryLobby_Text_258C6F: @ 8258C6F
	.string "Okay, I will hold your POKéMON for\n"
	.string "safekeeping while you compete.$"

BattleFrontier_BattleFactoryLobby_Text_258CB1: @ 8258CB1
	.string "Suivez-moi, je vous prie.$"

BattleFrontier_BattleFactoryLobby_Text_258CC7: @ 8258CC7
	.string "Merci d'avoir joué!\p"
	.string "Je vous rends vos POKéMON et reprends\n"
	.string "les POKéMON de location.\p"
	.string "Je dois sauvegarder vos données.\n"
	.string "Veuillez patienter.$"

BattleFrontier_BattleFactoryLobby_Text_258D54: @ 8258D54
	.string "I will return your POKéMON in exchange\n"
	.string "for our rental POKéMON.$"

BattleFrontier_BattleFactoryLobby_Text_258D93: @ 8258D93
	.string "Félicitations! Vous avez gagné sept\n"
	.string "COMBATS ECHANGE à la suite!$"

BattleFrontier_BattleFactoryLobby_Text_258DD3: @ 8258DD3
	.string "In recognition of your 7-win streak,\n"
	.string "we award you these Battle Point(s).$"

BattleFrontier_BattleFactoryLobby_Text_258E1C: @ 8258E1C
	.string "Oh, oh, oh!\p"
	.string "Your Battle Points are maxed.\p"
	.string "Please come back after using\n"
	.string "some Battle Points.$"

BattleFrontier_BattleFactoryLobby_Text_258E77: @ 8258E77
	.string "Nous vous attendions!\p"
	.string "Avant de reprendre votre défi, vous\n"
	.string "devez sauvegarder la partie.$"

BattleFrontier_BattleFactoryLobby_Text_258ECA: @ 8258ECA
	.string "Je regrette!\p"
	.string "Vous n'avez pas sauvegardé avant de\n"
	.string "quitter votre dernier défi.\p"
	.string "Dans ce cas, c'est la disqualification.\n"
	.string "C'est dommage!$"

BattleFrontier_BattleFactoryLobby_Text_258F55: @ 8258F55
	.string "We'll return your personal POKéMON.$"

BattleFrontier_BattleFactoryLobby_Text_258F79: @ 8258F79
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleFactoryLobby_Text_258F93: @ 8258F93
	.string "Bienvenue à l'USINE DE COMBAT!\p"
	.string "Ici, nous mettons à l'épreuve\n"
	.string "le savoir des DRESSEURS!\p"
	.string "Je serai votre guide pour le TOURNOI\n"
	.string "COMBAT ECHANGE DUO.$"

BattleFrontier_BattleFactoryLobby_Text_25901F: @ 825901F
	.string "Voulez-vous relever le défi du\n"
	.string "COMBAT ECHANGE DUO?$"

BattleFrontier_BattleFactoryLobby_Text_259058: @ 8259058
	.string "Le TOURNOI COMBAT ECHANGE DUO\n"
	.string "se compose de COMBATS DUO. Vous\l"
	.string "utilisez des POKéMON de location.\p"
	.string "Vous devez choisir trois POKéMON parmi\n"
	.string "les POKéMON de location.\p"
	.string "Ensuite, vous faites des COMBATS\n"
	.string "DUO avec ces POKéMON.\p"
	.string "Si vous gagnez, vous pouvez échanger\n"
	.string "l'un des POKéMON de location.\p"
	.string "Si vous gagnez sept combats à la suite,\n"
	.string "vous gagnez des POINTS DE COMBAT.\p"
	.string "Si vous voulez interrompre le défi,\n"
	.string "veuillez sauvegarder la partie.\p"
	.string "Assurez-vous de bien sauvegarder, ou\n"
	.string "vous ne pourrez pas reprendre le défi.$"

BattleFrontier_BattleFactoryLobby_Text_25926A: @ 825926A
	.string "Félicitations! Vous avez battu le\n"
	.string "CHEF D'USINE et gagné\l"
	.string "sept matchs à la suite!$"

BattleFrontier_BattleFactoryLobby_Text_2592BD: @ 82592BD
	.string "Votre savoir et votre intelligence vont\n"
	.string "être récompensés par des POINTS\l"
	.string "DE COMBAT!$"

BattleFrontier_BattleFactoryLobby_Text_259323: @ 8259323
	.string "Je vous rends vos POKéMON et reprends\n"
	.string "les POKéMON de location.\p"
	.string "Je dois sauvegarder vos données.\n"
	.string "Veuillez patienter.$"

BattleFrontier_BattleFactoryLobby_Text_259388: @ 8259388
	.string "Voulez-vous enregistrer votre dernier\n"
	.string "combat à l'USINE DE COMBAT sur votre\l"
	.string "PASSE ZONE?$"

BattleFrontier_BattleFactoryLobby_Text_2593D7: @ 82593D7
	.string "Hé, dis-moi!\p"
	.string "Tu crois que c'est facile de se battre\n"
	.string "ici parce qu'on te prête des POKéMON?\p"
	.string "Eh bien, si tu penses ça, tu te mets\n"
	.string "le doigt dans l'œil! Crois-moi!\p"
	.string "Tu dois connaître énormément de\n"
	.string "choses sur les POKéMON et sur leurs\l"
	.string "capacités pour gagner ici!$"

BattleFrontier_BattleFactoryLobby_Text_2594E5: @ 82594E5
	.string "A l'échange, j'ai pris un autre POKéMON…\n"
	.string "Ce n'était pas une très bonne idée…\p"
	.string "Ils nous ont écrasés…$"

BattleFrontier_BattleFactoryLobby_Text_259547: @ 8259547
	.string "Ça ne s'est pas du tout passé\n"
	.string "comme je l'avais prévu.\p"
	.string "Il faut bien étudier les POKéMON de\n"
	.string "l'adversaire pour savoir lequel choisir\l"
	.string "pendant l'échange à la fin du combat.$"

BattleFrontier_BattleFactoryLobby_Text_2595C4: @ 82595C4
	.string "Tu sais, on te donne des infos sur\n"
	.string "l'adversaire avant les combats.\p"
	.string "Je m'y connais bien, mais je trouve\n"
	.string "que les infos ne sont pas très claires.$"

BattleFrontier_BattleFactoryLobby_Text_259658: @ 8259658
	.string "Like, I'm really tough, but I get bored\n"
	.string "really easily, so I just kept swapping\l"
	.string "and battling over and over.\p"
	.string "So anyway, when I kept entering\n"
	.string "Battle Swap events, I noticed they\l"
	.string "varied the rental POKéMON.$"

BattleFrontier_BattleFactoryLobby_Text_259721: @ 8259721
SlateportCity_BattleTentLobby_Text_259721: @ 8259721
	.string "Règles du COMBAT ECHANGE.$"

BattleFrontier_BattleFactoryLobby_Text_259743: @ 8259743
SlateportCity_BattleTentLobby_Text_259743: @ 8259743
	.string "Quel chapitre voulez-vous lire?$"

BattleFrontier_BattleFactoryLobby_Text_259766: @ 8259766
	.string "Lors d'un COMBAT ECHANGE, vous ne\n"
	.string "pouvez utiliser que trois POKéMON.\p"
	.string "Qu'ils aient été prêtés ou échangés,\n"
	.string "votre équipe ne peut pas avoir deux\l"
	.string "fois le même POKéMON.$"

BattleFrontier_BattleFactoryLobby_Text_2597FB: @ 82597FB
	.string "Vous pouvez échanger un POKéMON avec\n"
	.string "le DRESSEUR que vous venez de battre.\p"
	.string "Vous ne pouvez obtenir que les POKéMON\n"
	.string "se trouvant dans son équipe.$"

BattleFrontier_BattleFactoryLobby_Text_25987E: @ 825987E
	.string "A chaque fois que vous gagnez, vous\n"
	.string "pouvez échanger un de vos POKéMON\l"
	.string "avec un de ceux de votre adversaire.\p"
	.string "Vous ne pouvez pas faire d'échange\n"
	.string "avec le septième DRESSEUR.$"

BattleFrontier_BattleFactoryLobby_Text_259920: @ 8259920
	.string "Voici deux choses à savoir sur les\n"
	.string "échanges de POKéMON.\p"
	.string "Avant l'échange, vous ne pouvez pas\n"
	.string "connaître les stats du POKéMON\l"
	.string "que vous voulez recevoir.\p"
	.string "Les POKéMON de votre équipe sont\n"
	.string "alignés dans l'ordre où vous les avez\l"
	.string "loués.\p"
	.string "Cet ordre reste le même lorsque vous\n"
	.string "échangez des POKéMON.$"

BattleFrontier_BattleFactoryLobby_Text_259A5E: @ 8259A5E
	.string "En niveau libre, les POKéMON de\n"
	.string "location et les POKéMON des\l"
	.string "adversaires sont tous de niveau 100.$"
