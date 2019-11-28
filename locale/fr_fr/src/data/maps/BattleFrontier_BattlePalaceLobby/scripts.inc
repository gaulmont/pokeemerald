BattleFrontier_BattlePalaceLobby_MapScripts:: @ 824D77E
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceLobby_MapScript2_24D79D
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceLobby_MapScript2_24D789
	.byte 0

BattleFrontier_BattlePalaceLobby_MapScript2_24D789: @ 824D789
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceLobby_EventScript_24D793
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_24D793:: @ 824D793
	setvar VAR_TEMP_1, 1
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePalaceLobby_MapScript2_24D79D: @ 824D79D
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePalaceLobby_EventScript_24D7C7
	map_script_2 VAR_TEMP_0, 1, BattleFrontier_BattlePalaceLobby_EventScript_24D7D0
	map_script_2 VAR_TEMP_0, 2, BattleFrontier_BattlePalaceLobby_EventScript_24D908
	map_script_2 VAR_TEMP_0, 3, BattleFrontier_BattlePalaceLobby_EventScript_24D817
	map_script_2 VAR_TEMP_0, 4, BattleFrontier_BattlePalaceLobby_EventScript_24D873
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_24D7C7:: @ 824D7C7
	setvar VAR_0x8004, 0
	special CallFrontierUtilFunc
	end

BattleFrontier_BattlePalaceLobby_EventScript_24D7D0:: @ 824D7D0
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E636, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special CallBattlePalaceFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 0
	special CallBattlePalaceFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_24D817:: @ 824D817
	lockall
	setvar VAR_0x8004, 10
	special CallFrontierUtilFunc
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24D838
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E497, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_24D840

BattleFrontier_BattlePalaceLobby_EventScript_24D838:: @ 824D838
	msgbox BattleFrontier_BattlePalaceLobby_Text_24EE81, MSGBOX_DEFAULT

BattleFrontier_BattlePalaceLobby_EventScript_24D840:: @ 824D840
	msgbox BattleFrontier_BattlePalaceLobby_Text_24EEB9, MSGBOX_DEFAULT
	setvar VAR_0x8004, 11
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattlePalaceLobby_Text_241520, 9
	message BattleFrontier_BattlePalaceLobby_Text_24E4F7
	waitmessage
	call BattleFrontier_BattlePalaceLobby_EventScript_24D8A1
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E0D8, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_24D873:: @ 824D873
	lockall
	message BattleFrontier_BattlePalaceLobby_Text_24E41E
	waitmessage
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 0
	special CallBattlePalaceFunction
	call BattleFrontier_BattlePalaceLobby_EventScript_24D8A1
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E0D8, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_24D8A1:: @ 824D8A1
	setvar VAR_0x8004, 8
	special CallFrontierUtilFunc
	special LoadPlayerParty
	special HealPlayerParty
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 0
	special CallBattlePalaceFunction
	playse SE_SAVE
	waitse
	call BattleFrontier_BattlePalaceLobby_EventScript_23E8E0
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24D907
	message BattleFrontier_BattlePalaceLobby_Text_24EF16
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_24D907
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_24D902
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_24D907

BattleFrontier_BattlePalaceLobby_EventScript_24D902:: @ 824D902
	call BattleFrontier_BattlePalaceLobby_EventScript_23E8B4

BattleFrontier_BattlePalaceLobby_EventScript_24D907:: @ 824D907
	return

BattleFrontier_BattlePalaceLobby_EventScript_24D908:: @ 824D908
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E5D8, MSGBOX_DEFAULT
	message BattleFrontier_BattlePalaceLobby_Text_24E5F6
	waitmessage
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 1
	special CallBattlePalaceFunction
	playse SE_SAVE
	waitse
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_TEMP_0, 255
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DAF3

BattleFrontier_BattlePalaceLobby_EventScript_24D944:: @ 824D944
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 2
	setvar VAR_FRONTIER_BATTLE_MODE, 0
	goto BattleFrontier_BattlePalaceLobby_EventScript_24D968
	end

BattleFrontier_BattlePalaceLobby_EventScript_24D956:: @ 824D956
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 2
	setvar VAR_FRONTIER_BATTLE_MODE, 1
	goto BattleFrontier_BattlePalaceLobby_EventScript_24D968
	end

BattleFrontier_BattlePalaceLobby_EventScript_24D968:: @ 824D968
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 0
	special CallBattlePalaceFunction
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattlePalaceLobby_EventScript_24D817
	special SavePlayerParty
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DB9E
	compare VAR_FRONTIER_BATTLE_MODE, 1
	call_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DBA7

BattleFrontier_BattlePalaceLobby_EventScript_24D999:: @ 824D999
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DBB0
	compare VAR_FRONTIER_BATTLE_MODE, 1
	call_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DBB6
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_24D9E6
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_24DB20
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_24DB94
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_24DB94

BattleFrontier_BattlePalaceLobby_EventScript_24D9E6:: @ 824D9E6
	message BattleFrontier_BattlePalaceLobby_Text_24E119
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, 0
	switch VAR_RESULT
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_24DB94
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_24DB94
	setvar VAR_0x8004, 15
	special CallFrontierUtilFunc
	compare VAR_0x8004, 1
	goto_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DB45
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	copyvar VAR_0x8006, VAR_RESULT
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E399, MSGBOX_DEFAULT
	fadescreen 1
	call BattleFrontier_BattlePalaceLobby_EventScript_23F2B7
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, 3
	special sub_80F9490
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DB91
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E3C8, MSGBOX_YESNO
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_24DB91
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_24DA87
	case 127, BattleFrontier_BattlePalaceLobby_EventScript_24DB91

BattleFrontier_BattlePalaceLobby_EventScript_24DA87:: @ 824DA87
	setvar VAR_TEMP_0, 0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 4
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 0
	special CallBattlePalaceFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 1
	special CallBattlePalaceFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 1
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DB7A

BattleFrontier_BattlePalaceLobby_EventScript_24DAF3:: @ 824DAF3
	special SavePlayerParty
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E408, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePalaceLobby_EventScript_24DBBC
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR, 255, 8, 13
	setvar VAR_TEMP_0, 0
	waitstate
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DB20:: @ 824DB20
	compare VAR_FRONTIER_BATTLE_MODE, 1
	goto_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DB38
	msgbox BattleFrontier_BattlePalaceLobby_Text_24DE17, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_24D999

BattleFrontier_BattlePalaceLobby_EventScript_24DB38:: @ 824DB38
	msgbox BattleFrontier_BattlePalaceLobby_Text_24EBC2, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_24D999

BattleFrontier_BattlePalaceLobby_EventScript_24DB45:: @ 824DB45
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_24DB60
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_24DB6D

BattleFrontier_BattlePalaceLobby_EventScript_24DB60:: @ 824DB60
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E173, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DB9C

BattleFrontier_BattlePalaceLobby_EventScript_24DB6D:: @ 824DB6D
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E29E, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DB9C

BattleFrontier_BattlePalaceLobby_EventScript_24DB7A:: @ 824DB7A
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DB94

BattleFrontier_BattlePalaceLobby_EventScript_24DB91:: @ 824DB91
	special LoadPlayerParty

BattleFrontier_BattlePalaceLobby_EventScript_24DB94:: @ 824DB94
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E0D8, MSGBOX_DEFAULT

BattleFrontier_BattlePalaceLobby_EventScript_24DB9C:: @ 824DB9C
	release
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DB9E:: @ 824DB9E
	msgbox BattleFrontier_BattlePalaceLobby_Text_24DD5B, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_24DBA7:: @ 824DBA7
	msgbox BattleFrontier_BattlePalaceLobby_Text_24EB06, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_24DBB0:: @ 824DBB0
	message BattleFrontier_BattlePalaceLobby_Text_24DDE1
	return

BattleFrontier_BattlePalaceLobby_EventScript_24DBB6:: @ 824DBB6
	message BattleFrontier_BattlePalaceLobby_Text_24EB8C
	return

BattleFrontier_BattlePalaceLobby_EventScript_24DBBC:: @ 824DBBC
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DC23
	compare VAR_FRONTIER_BATTLE_MODE, 1
	call_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DC29
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_24DC47
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_24DC47
	waitmovement 0
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DC2F
	compare VAR_FRONTIER_BATTLE_MODE, 1
	call_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DC35
	waitdooranim
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_24DC49
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_24DC4C
	waitmovement 0
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DC3B
	compare VAR_FRONTIER_BATTLE_MODE, 1
	call_if_eq BattleFrontier_BattlePalaceLobby_EventScript_24DC41
	waitdooranim
	return

BattleFrontier_BattlePalaceLobby_EventScript_24DC23:: @ 824DC23
	setvar VAR_LAST_TALKED, 1
	return

BattleFrontier_BattlePalaceLobby_EventScript_24DC29:: @ 824DC29
	setvar VAR_LAST_TALKED, 6
	return

BattleFrontier_BattlePalaceLobby_EventScript_24DC2F:: @ 824DC2F
	opendoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_24DC35:: @ 824DC35
	opendoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_24DC3B:: @ 824DC3B
	closedoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_24DC41:: @ 824DC41
	closedoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_Movement_24DC47: @ 824DC47
	walk_up
	step_end

BattleFrontier_BattlePalaceLobby_Movement_24DC49: @ 824DC49
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_Movement_24DC4C: @ 824DC4C
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_EventScript_24DC50:: @ 824DC50
	lockall
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DC69:: @ 824DC69
	lockall
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 1
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DC82:: @ 824DC82
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E6E3, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DC8B:: @ 824DC8B
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E851, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DC94:: @ 824DC94
	msgbox BattleFrontier_BattlePalaceLobby_Text_24E992, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DC9D:: @ 824DC9D
	msgbox BattleFrontier_BattlePalaceLobby_Text_24EA4B, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DCA6:: @ 824DCA6
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_24EF66, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DCB5
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DCB5:: @ 824DCB5
	message BattleFrontier_BattlePalaceLobby_Text_24EF88
	waitmessage
	multichoice 16, 0, MULTI_BATTLE_PALACE_RULES, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_24DD13
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_24DD21
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_24DD2F
	case 3, BattleFrontier_BattlePalaceLobby_EventScript_24DD3D
	case 4, BattleFrontier_BattlePalaceLobby_EventScript_24DD4B
	case 5, BattleFrontier_BattlePalaceLobby_EventScript_24DD59
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_24DD59
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DD13:: @ 824DD13
	msgbox BattleFrontier_BattlePalaceLobby_Text_24EFAB, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DCB5
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DD21:: @ 824DD21
	msgbox BattleFrontier_BattlePalaceLobby_Text_24F049, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DCB5
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DD2F:: @ 824DD2F
	msgbox BattleFrontier_BattlePalaceLobby_Text_24F190, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DCB5
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DD3D:: @ 824DD3D
	msgbox BattleFrontier_BattlePalaceLobby_Text_24F2E8, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DCB5
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DD4B:: @ 824DD4B
	msgbox BattleFrontier_BattlePalaceLobby_Text_24F3F4, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_24DCB5
	end

BattleFrontier_BattlePalaceLobby_EventScript_24DD59:: @ 824DD59
	releaseall
	end

BattleFrontier_BattlePalaceLobby_Text_24DD5B: @ 824DD5B
	.string "Bienvenue au PALACE DE COMBAT!\p"
	.string "Ici, nous mettons à l'épreuve\n"
	.string "l'esprit des DRESSEURS!\p"
	.string "Je serai votre guide dans les\n"
	.string "HALLS DE COMBAT SOLO.$"

BattleFrontier_BattlePalaceLobby_Text_24DDE1: @ 824DDE1
	.string "Voulez-vous relever le défi d'un\n"
	.string "HALL DE COMBAT SOLO?$"

BattleFrontier_BattlePalaceLobby_Text_24DE17: @ 824DE17
	.string "Au PALACE DE COMBAT, il y a plusieurs\n"
	.string "salles réservées aux COMBATS SOLO, que\l"
	.string "l'on appelle les HALLS DE COMBAT SOLO.\p"
	.string "Les COMBATS SOLO qui y ont lieu sont\n"
	.string "un peu particuliers. Une importante\l"
	.string "règle y est ajoutée.\p"
	.string "Les DRESSEURS peuvent seulement\n"
	.string "faire entrer et sortir leurs POKéMON.\p"
	.string "Les DRESSEURS ne peuvent pas donner\n"
	.string "d'autres ordres à leurs POKéMON.\p"
	.string "Les POKéMON agiront conformément\n"
	.string "à leur nature et se battront seuls.\p"
	.string "Vous devez placer votre confiance en\n"
	.string "vos POKéMON et les regarder.\p"
	.string "Si vous réalisez l'exploit de battre\n"
	.string "sept DRESSEURS à la suite, vous\l"
	.string "recevrez des POINTS DE COMBAT.\p"
	.string "Si vous voulez interrompre le défi,\n"
	.string "veuillez sauvegarder la partie.\p"
	.string "Assurez-vous de bien sauvegarder, ou\n"
	.string "vous ne pourrez pas reprendre le défi.$"

BattleFrontier_BattlePalaceLobby_Text_24E0D8: @ 824E0D8
	.string "Revenez quand vous aurez fortifié\n"
	.string "votre esprit et vos POKéMON.$"

BattleFrontier_BattlePalaceLobby_Text_24E119: @ 824E119
	.string "Il y a deux HALLS DE COMBAT:\n"
	.string "niveau 50 et niveau libre.\l"
	.string "Que choisissez-vous?$"

BattleFrontier_BattlePalaceLobby_Text_24E173: @ 824E173
	.string "Je regrette…\p"
	.string "Vous n'avez pas trois POKéMON\n"
	.string "aptes à participer.\p"
	.string "Il vous faut trois POKéMON différents\n"
	.string "pour participer.\p"
	.string "Ces POKéMON doivent être de niveau\n"
	.string "50 ou moins.\p"
	.string "Ils doivent aussi tenir des objets\n"
	.string "différents.\p"
	.string "Les OEUFS{STR_VAR_1} inaptes au combat.\p"
	.string "Revenez me voir quand vous aurez\n"
	.string "ce qu'il faut.$"

BattleFrontier_BattlePalaceLobby_Text_24E29E: @ 824E29E
	.string "Je regrette…\p"
	.string "Vous n'avez pas trois POKéMON\n"
	.string "aptes à participer.\p"
	.string "Il vous faut trois POKéMON différents\n"
	.string "pour participer.\p"
	.string "Ils doivent aussi tenir des objets\n"
	.string "différents.\p"
	.string "Les OEUFS{STR_VAR_1} inaptes au combat.\p"
	.string "Revenez me voir quand vous aurez\n"
	.string "ce qu'il faut.$"

BattleFrontier_BattlePalaceLobby_Text_24E399: @ 824E399
	.string "Très bien. Maintenant, veuillez choisir\n"
	.string "vos trois POKéMON.$"

BattleFrontier_BattlePalaceLobby_Text_24E3C8: @ 824E3C8
	.string "Avant d'accéder à un HALL DE COMBAT,\n"
	.string "votre partie doit être sauvegardée. OK?$"

BattleFrontier_BattlePalaceLobby_Text_24E408: @ 824E408
	.string "Très bien.\n"
	.string "Suivez-moi, je vous prie.$"

BattleFrontier_BattlePalaceLobby_Text_24E41E: @ 824E41E
	.string "Ce fut un privilège de pouvoir assister\n"
	.string "à un tel combat.\p"
	.string "Votre résultat va être sauvegardé.\n"
	.string "Je vous demande de patienter un peu.$"

BattleFrontier_BattlePalaceLobby_Text_24E497: @ 824E497
	.string "Sept victoires consécutives…\p"
	.string "Les liens qui unissent votre esprit à\n"
	.string "vos POKéMON sont solides et sincères.$"

BattleFrontier_BattlePalaceLobby_Text_24E4F7: @ 824E4F7
	.string "Votre résultat va être sauvegardé.\n"
	.string "Je vous demande de patienter un peu.$"

BattleFrontier_BattlePalaceLobby_Text_24E533: @ 824E5333
	.string "For the feat of your 7-win streak,\n"
	.string "we present you with Battle Point(s).$"

VerdanturfTown_BattleTentLobby_Text_24E57B: @ 824E57B
	.string "Malheureusement, vous ne pouvez\n"
	.string "rien porter d'autre.\p"
	.string "Je vous demande de faire de la place\n"
	.string "dans votre SAC et de revenir me voir.$"

BattleFrontier_BattlePalaceLobby_Text_24E5D8: @ 824E5D8
VerdanturfTown_BattleTentLobby_Text_24E5D8: @ 824E5D8
	.string "Nous vous attendions…$"

BattleFrontier_BattlePalaceLobby_Text_24E5F6: @ 824E5F6
VerdanturfTown_BattleTentLobby_Text_24E5F6: @ 824E5F6
	.string "Avant d'accéder à un HALL DE COMBAT,\n"
	.string "votre partie doit être sauvegardée. OK?$"

BattleFrontier_BattlePalaceLobby_Text_24E636: @ 824E636
VerdanturfTown_BattleTentLobby_Text_24E636: @ 824E636
	.string "Je regrette!\p"
	.string "Vous n'avez pas sauvegardé avant de\n"
	.string "quitter votre dernier défi.\p"
	.string "C'est malheureux, mais nous avons dû\n"
	.string "vous disqualifier.$"

BattleFrontier_BattlePalaceLobby_Text_24E6C9: @ 824E6C9
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattlePalaceLobby_Text_24E6E3: @ 824E6E3
	.string "Pour un DRESSEUR hardi comme moi,\n"
	.string "il faut des POKéMON hardis aussi!\p"
	.string "L'attaque est la meilleure des\n"
	.string "défenses! Il faut attaquer sans cesse!\p"
	.string "Mais ce n'est pas de ça que je voulais\n"
	.string "parler.\p"
	.string "De temps en temps, il y a une fille\n"
	.string "super mignonne qui passe par ici.\p"
	.string "Elle dit qu'elle est capable de savoir\n"
	.string "ce que les POKéMON pensent.\p"
	.string "Je ne sais pas si c'est vrai, mais en\n"
	.string "tout cas elle est super mignonne!\p"
	.string "Hé!\n"
	.string "Pourquoi tu me regardes comme ça?$"

BattleFrontier_BattlePalaceLobby_Text_24E851: @ 824E851
	.string "Hum…\p"
	.string "Apparemment, ici c'est la nature des\n"
	.string "POKéMON ainsi que les capacités qu'ils\l"
	.string "connaissent qui sont importantes.\p"
	.string "En fait, il faut que les capacités qu'ils\n"
	.string "connaissent soient en accord avec leur\l"
	.string "nature.\p"
	.string "Si un POKéMON est en difficulté et n'est\n"
	.string "pas à la hauteur de son potentiel, il\l"
	.string "faut se demander si ses capacités\l"
	.string "correspondent bien à sa nature.$"

BattleFrontier_BattlePalaceLobby_Text_24E992: @ 824E992
	.string "Mon POKéMON est très docile,\n"
	.string "en temps normal.\p"
	.string "Mais dès qu'il est dans un HALL DE\n"
	.string "COMBAT, il n'est plus le même.\l"
	.string "Il devient méchant!\p"
	.string "Je t'assure, il me fait peur!$"

BattleFrontier_BattlePalaceLobby_Text_24EA4B: @ 824EA4B
	.string "Je me demande quelle est la nature\n"
	.string "d'un POKéMON qui affaiblit l'ennemi\l"
	.string "petit à petit pour prendre la tête.\p"
	.string "Ce serait surprenant qu'il soit LACHE\n"
	.string "de nature.\p"
	.string "Non, ça ne peut pas être ça.$"

BattleFrontier_BattlePalaceLobby_Text_24EB06: @ 824EB06
	.string "Bienvenue au PALACE DE COMBAT!\p"
	.string "Ici, nous mettons à l'épreuve\n"
	.string "l'esprit des DRESSEURS!\p"
	.string "Je prends les inscriptions pour les\n"
	.string "HALLS DE COMBAT DUO.$"

BattleFrontier_BattlePalaceLobby_Text_24EB8C: @ 824EB8C
	.string "Voulez-vous relever le défi d'un\n"
	.string "HALL DE COMBAT DUO?$"

BattleFrontier_BattlePalaceLobby_Text_24EBC2: @ 824EBC2
	.string "Au PALACE DE COMBAT, il y a plusieurs\n"
	.string "salles réservées aux COMBATS DUO, que\l"
	.string "l'on appelle les HALLS DE COMBAT DUO.\p"
	.string "Les COMBATS DUO qui y ont lieu sont\n"
	.string "un peu particuliers. Une importante\l"
	.string "règle y est ajoutée.\p"
	.string "Les DRESSEURS peuvent seulement\n"
	.string "faire entrer et sortir leurs POKéMON.\p"
	.string "Les DRESSEURS ne peuvent pas donner\n"
	.string "d'autres ordres à leurs POKéMON.\p"
	.string "Les POKéMON agiront conformément\n"
	.string "à leur nature et se battront seuls.\p"
	.string "Vous devez placer votre confiance en\n"
	.string "vos POKéMON et les regarder.\p"
	.string "Si vous réalisez l'exploit de battre\n"
	.string "sept DRESSEURS à la suite, vous\l"
	.string "recevrez des POINTS DE COMBAT.\p"
	.string "Si vous voulez interrompre le défi,\n"
	.string "veuillez sauvegarder la partie.\p"
	.string "Assurez-vous de bien sauvegarder, ou\n"
	.string "vous ne pourrez pas reprendre le défi.$"

BattleFrontier_BattlePalaceLobby_Text_24EE81: @ 824EE81
	.string "Battre le CAPT. PALACE et sept\n"
	.string "DRESSEURS de suite…$"

BattleFrontier_BattlePalaceLobby_Text_24EEB9: @ 824EEB9
	.string "Les liens qui vous unissent à vos\n"
	.string "POKéMON vont se voir récompensés par\l"
	.string "des POINTS DE COMBAT.$"

BattleFrontier_BattlePalaceLobby_Text_24EF16: @ 824EF16
	.string "Voulez-vous enregistrer votre dernier\n"
	.string "combat au PALACE DE COMBAT sur\l"
	.string "votre PASSE ZONE?$"

BattleFrontier_BattlePalaceLobby_Text_24EF66: @ 824EF66
	.string "Règles des HALLS DE COMBAT.$"

BattleFrontier_BattlePalaceLobby_Text_24EF88: @ 824EF88
VerdanturfTown_BattleTentLobby_Text_24EF88: @ 824EF88
	.string "Quel chapitre voulez-vous lire?$"

BattleFrontier_BattlePalaceLobby_Text_24EFAB: @ 824EFAB
VerdanturfTown_BattleTentLobby_Text_24EFAB: @ 824EFAB
	.string "Ici, les POKéMON doivent penser et se\n"
	.string "battre par eux-mêmes.\p"
	.string "A la différence des POKéMON sauvages,\n"
	.string "ceux qui vivent avec des humains ont un\l"
	.string "comportement spécifique à leur nature.$"

BattleFrontier_BattlePalaceLobby_Text_24F049: @ 824F049
VerdanturfTown_BattleTentLobby_Text_24F049: @ 824F049
	.string "La nature d'un POKéMON lui dictera\n"
	.string "peut-être d'attaquer coûte que coûte.\p"
	.string "Un autre POKéMON pourra préférer se\n"
	.string "protéger du danger.\p"
	.string "Un autre aimera peut-être contrarier\n"
	.string "et déconcerter ses ennemis.\p"
	.string "Selon sa nature, un POKéMON préférera\n"
	.string "certaines capacités, qu'il saura mieux\l"
	.string "utiliser que les autres.\p"
	.string "Certaines capacités ne lui plairont pas\n"
	.string "et il aura du mal à les utiliser.$"

BattleFrontier_BattlePalaceLobby_Text_24F190: @ 824F190
VerdanturfTown_BattleTentLobby_Text_24F190: @ 824F190
	.string "Les capacités offensives font subir\n"
	.string "des dommages immédiats à l'ennemi.\p"
	.string "Les capacités défensives servent à se\n"
	.string "préparer à l'attaque ennemie, à se\l"
	.string "soigner ou autre.\p"
	.string "Il y a aussi d'autres capacités visant\n"
	.string "à affaiblir l'ennemi en provoquant\l"
	.string "des problèmes de statut comme\l"
	.string "l'empoisonnement ou la paralysie.\p"
	.string "Les POKéMON choisiront leurs capacités\n"
	.string "parmi ces trois catégories.$"

BattleFrontier_BattlePalaceLobby_Text_24F2E8: @ 824F2E8
VerdanturfTown_BattleTentLobby_Text_24F2E8: @ 824F2E8
	.string "Sans les ordres de son DRESSEUR, il\n"
	.string "se peut qu'un POKéMON n'utilise pas\l"
	.string "efficacement certaines capacités.\p"
	.string "Un POKéMON utilise mal les capacités\n"
	.string "qu'il n'aime pas.\p"
	.string "Si un POKéMON ne connaît que des\n"
	.string "capacités contraires à sa nature, il ne\l"
	.string "sera pas à la hauteur de son potentiel.$"

BattleFrontier_BattlePalaceLobby_Text_24F3F4: @ 824F3F4
VerdanturfTown_BattleTentLobby_Text_24F3F4: @ 824F3F4
	.string "Il se peut qu'un POKéMON se mette\n"
	.string "à utiliser des capacités contraires à\l"
	.string "sa nature s'il est en danger.\p"
	.string "Si un POKéMON commence à agir\n"
	.string "bizarrement, surveillez-le bien.$"

