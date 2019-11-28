BattleFrontier_BattleDomeLobby_MapScripts:: @ 82497E2
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleDomeLobby_MapScript1_2497F2
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeLobby_MapScript2_24980F
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_MapScript2_2497FB
	.byte 0

BattleFrontier_BattleDomeLobby_MapScript1_2497F2: @ 82497F2
	setvar VAR_0x8004, 21
	special CallBattleDomeFunction
	end

BattleFrontier_BattleDomeLobby_MapScript2_2497FB: @ 82497FB
BattleFrontier_BattlePyramidLobby_MapScript2_2497FB: @ 82497FB
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleDomeLobby_EventScript_249805
	.2byte 0

BattleFrontier_BattleDomeLobby_EventScript_249805:: @ 8249805
	setvar VAR_TEMP_1, 1
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleDomeLobby_MapScript2_24980F: @ 824980F
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleDomeLobby_EventScript_249839
	map_script_2 VAR_TEMP_0, 1, BattleFrontier_BattleDomeLobby_EventScript_249842
	map_script_2 VAR_TEMP_0, 2, BattleFrontier_BattleDomeLobby_EventScript_2499F9
	map_script_2 VAR_TEMP_0, 3, BattleFrontier_BattleDomeLobby_EventScript_24989B
	map_script_2 VAR_TEMP_0, 4, BattleFrontier_BattleDomeLobby_EventScript_249940
	.2byte 0

BattleFrontier_BattleDomeLobby_EventScript_249839:: @ 8249839
	setvar VAR_0x8004, 0
	special CallFrontierUtilFunc
	end

BattleFrontier_BattleDomeLobby_EventScript_249842:: @ 8249842
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_24A45F, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallBattleDomeFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special CallBattleDomeFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 1
	special CallBattleDomeFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_24989B:: @ 824989B
	call BattleFrontier_BattleDomeLobby_EventScript_241EBA
	lockall
	setvar VAR_0x8004, 10
	special CallFrontierUtilFunc
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleDomeLobby_EventScript_2498C1
	msgbox BattleFrontier_BattleDomeLobby_Text_24A4E9, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_2498C9

BattleFrontier_BattleDomeLobby_EventScript_2498C1:: @ 82498C1
	msgbox BattleFrontier_BattleDomeLobby_Text_24AD67, MSGBOX_DEFAULT

BattleFrontier_BattleDomeLobby_EventScript_2498C9:: @ 82498C9
	msgbox BattleFrontier_BattleDomeLobby_Text_24ADB1, MSGBOX_DEFAULT
	setvar VAR_0x8004, 11
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattleDomeLobby_Text_241520, 9
	message BattleFrontier_BattleDomeLobby_Text_24A5D6
	waitmessage
	special LoadPlayerParty
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 8
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 1
	special CallBattleDomeFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 7
	setvar VAR_0x8006, 1
	special CallBattleDomeFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 1
	special CallBattleDomeFunction
	special LoadPlayerParty
	special HealPlayerParty
	goto BattleFrontier_BattleDomeLobby_EventScript_249991

BattleFrontier_BattleDomeLobby_EventScript_249940:: @ 8249940
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_24A5BF, MSGBOX_DEFAULT
	message BattleFrontier_BattleDomeLobby_Text_24A5D6
	waitmessage
	special LoadPlayerParty
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 8
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special CallBattleDomeFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 1
	special CallBattleDomeFunction
	special LoadPlayerParty
	special HealPlayerParty

BattleFrontier_BattleDomeLobby_EventScript_249991:: @ 8249991
	setvar VAR_0x8004, 13
	setvar VAR_0x8005, 0
	special CallBattleDomeFunction
	playse SE_SAVE
	waitse
	call BattleFrontier_BattleDomeLobby_EventScript_23E8E0
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleDomeLobby_EventScript_2499E9
	message BattleFrontier_BattleDomeLobby_Text_24AE17
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleDomeLobby_EventScript_2499E9
	case 0, BattleFrontier_BattleDomeLobby_EventScript_2499E4
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_2499E9

BattleFrontier_BattleDomeLobby_EventScript_2499E4:: @ 82499E4
	call BattleFrontier_BattleDomeLobby_EventScript_23E8B4

BattleFrontier_BattleDomeLobby_EventScript_2499E9:: @ 82499E9
	msgbox BattleFrontier_BattleDomeLobby_Text_249F74, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_2499F9:: @ 82499F9
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_24A5FE, MSGBOX_DEFAULT
	message BattleFrontier_BattleDomeLobby_Text_24A61A
	waitmessage
	setvar VAR_0x8004, 13
	setvar VAR_0x8005, 1
	special CallBattleDomeFunction
	playse SE_SAVE
	waitse
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_TEMP_0, 255
	goto BattleFrontier_BattleDomeLobby_EventScript_249BC2

BattleFrontier_BattleDomeLobby_EventScript_249A35:: @ 8249A35
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 1
	setvar VAR_FRONTIER_BATTLE_MODE, 0
	goto BattleFrontier_BattleDomeLobby_EventScript_249A59
	end

BattleFrontier_BattleDomeLobby_EventScript_249A47:: @ 8249A47
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 1
	setvar VAR_FRONTIER_BATTLE_MODE, 1
	goto BattleFrontier_BattleDomeLobby_EventScript_249A59
	end

BattleFrontier_BattleDomeLobby_EventScript_249A59:: @ 8249A59
	special SavePlayerParty
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249CFD
	compare VAR_FRONTIER_BATTLE_MODE, 1
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249D06

BattleFrontier_BattleDomeLobby_EventScript_249A72:: @ 8249A72
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249D0F
	compare VAR_FRONTIER_BATTLE_MODE, 1
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249D15
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeLobby_EventScript_249ABF
	case 1, BattleFrontier_BattleDomeLobby_EventScript_249BFA
	case 2, BattleFrontier_BattleDomeLobby_EventScript_249C64
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_249C64

BattleFrontier_BattleDomeLobby_EventScript_249ABF:: @ 8249ABF
	message BattleFrontier_BattleDomeLobby_Text_24A210
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, 0
	switch VAR_RESULT
	case 2, BattleFrontier_BattleDomeLobby_EventScript_249C64
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_249C64
	setvar VAR_0x8004, 15
	special CallFrontierUtilFunc
	compare VAR_0x8004, 1
	goto_if_eq BattleFrontier_BattleDomeLobby_EventScript_249C15
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	copyvar VAR_0x8006, VAR_RESULT
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattleDomeLobby_Text_24A26E, MSGBOX_DEFAULT
	fadescreen 1
	call BattleFrontier_BattleDomeLobby_EventScript_23F2B7
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, 3
	special sub_80F9490
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleDomeLobby_EventScript_249C61
	msgbox BattleFrontier_BattleDomeLobby_Text_24A1C6, MSGBOX_YESNO
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeLobby_EventScript_249C61
	case 1, BattleFrontier_BattleDomeLobby_EventScript_249B60
	case 127, BattleFrontier_BattleDomeLobby_EventScript_249C61

BattleFrontier_BattleDomeLobby_EventScript_249B60:: @ 8249B60
	setvar VAR_TEMP_0, 0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 4
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 0
	special CallBattleDomeFunction
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
	goto_if_eq BattleFrontier_BattleDomeLobby_EventScript_249C4A
	setvar VAR_0x8004, 22
	special CallBattleDomeFunction

BattleFrontier_BattleDomeLobby_EventScript_249BC2:: @ 8249BC2
	special SavePlayerParty
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 15
	special CallBattleDomeFunction
	msgbox BattleFrontier_BattleDomeLobby_Text_24A437, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattleDomeLobby_EventScript_249C6E
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_CORRIDOR, 255, 23, 6
	setvar VAR_TEMP_0, 0
	waitstate
	end

BattleFrontier_BattleDomeLobby_EventScript_249BFA:: @ 8249BFA
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249D1B
	compare VAR_FRONTIER_BATTLE_MODE, 1
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249D24
	goto BattleFrontier_BattleDomeLobby_EventScript_249A72

BattleFrontier_BattleDomeLobby_EventScript_249C15:: @ 8249C15
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeLobby_EventScript_249C30
	case 1, BattleFrontier_BattleDomeLobby_EventScript_249C3D

BattleFrontier_BattleDomeLobby_EventScript_249C30:: @ 8249C30
	msgbox BattleFrontier_BattleDomeLobby_Text_24A353, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_249C6C

BattleFrontier_BattleDomeLobby_EventScript_249C3D:: @ 8249C3D
	msgbox BattleFrontier_BattleDomeLobby_Text_24A2AB, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_249C6C

BattleFrontier_BattleDomeLobby_EventScript_249C4A:: @ 8249C4A
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleDomeLobby_EventScript_249C64

BattleFrontier_BattleDomeLobby_EventScript_249C61:: @ 8249C61
	special LoadPlayerParty

BattleFrontier_BattleDomeLobby_EventScript_249C64:: @ 8249C64
	msgbox BattleFrontier_BattleDomeLobby_Text_249F74, MSGBOX_DEFAULT

BattleFrontier_BattleDomeLobby_EventScript_249C6C:: @ 8249C6C
	release
	end

BattleFrontier_BattleDomeLobby_EventScript_249C6E:: @ 8249C6E
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249CDD
	compare VAR_FRONTIER_BATTLE_MODE, 1
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249CE5
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleDomeLobby_Movement_249D45
	waitmovement 0
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249D2D
	compare VAR_FRONTIER_BATTLE_MODE, 1
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249D33
	waitdooranim
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249CED
	compare VAR_FRONTIER_BATTLE_MODE, 1
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249CF5
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleDomeLobby_Movement_249D4E
	waitmovement 0
	compare VAR_FRONTIER_BATTLE_MODE, 0
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249D39
	compare VAR_FRONTIER_BATTLE_MODE, 1
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249D3F
	waitdooranim
	return

BattleFrontier_BattleDomeLobby_EventScript_249CDD:: @ 8249CDD
	applymovement 1, BattleFrontier_BattleDomeLobby_Movement_249D45
	return

BattleFrontier_BattleDomeLobby_EventScript_249CE5:: @ 8249CE5
	applymovement 6, BattleFrontier_BattleDomeLobby_Movement_249D45
	return

BattleFrontier_BattleDomeLobby_EventScript_249CED:: @ 8249CED
	applymovement 1, BattleFrontier_BattleDomeLobby_Movement_249D4B
	return

BattleFrontier_BattleDomeLobby_EventScript_249CF5:: @ 8249CF5
	applymovement 6, BattleFrontier_BattleDomeLobby_Movement_249D4B
	return

BattleFrontier_BattleDomeLobby_EventScript_249CFD:: @ 8249CFD
	msgbox BattleFrontier_BattleDomeLobby_Text_249EB7, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_249D06:: @ 8249D06
	msgbox BattleFrontier_BattleDomeLobby_Text_24A664, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_249D0F:: @ 8249D0F
	message BattleFrontier_BattleDomeLobby_Text_249F3A
	return

BattleFrontier_BattleDomeLobby_EventScript_249D15:: @ 8249D15
	message BattleFrontier_BattleDomeLobby_Text_24A6E7
	return

BattleFrontier_BattleDomeLobby_EventScript_249D1B:: @ 8249D1B
	msgbox BattleFrontier_BattleDomeLobby_Text_249F8E, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_249D24:: @ 8249D24
	msgbox BattleFrontier_BattleDomeLobby_Text_24A721, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_249D2D:: @ 8249D2D
	opendoor 5, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_249D33:: @ 8249D33
	opendoor 17, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_249D39:: @ 8249D39
	closedoor 5, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_249D3F:: @ 8249D3F
	closedoor 17, 4
	return

BattleFrontier_BattleDomeLobby_Movement_249D45: @ 8249D45
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleDomeLobby_Movement_249D4B: @ 8249D4B
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeLobby_Movement_249D4E: @ 8249D4E
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeLobby_EventScript_249D52:: @ 8249D52
	lockall
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_249D6B:: @ 8249D6B
	lockall
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 1
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_249D84:: @ 8249D84
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 9
	special CallBattleDomeFunction
	compare VAR_RESULT, 0
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249DC9
	compare VAR_RESULT, 1
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249DD2
	compare VAR_RESULT, 2
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249DDB
	compare VAR_RESULT, 3
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_249DE4
	fadescreen 1
	setvar VAR_0x8004, 8
	special CallBattleDomeFunction
	waitstate
	end

BattleFrontier_BattleDomeLobby_EventScript_249DC9:: @ 8249DC9
	msgbox BattleFrontier_BattleDomeLobby_Text_24A966, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_249DD2:: @ 8249DD2
	msgbox BattleFrontier_BattleDomeLobby_Text_24A9A9, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_249DDB:: @ 8249DDB
	msgbox BattleFrontier_BattleDomeLobby_Text_24A9EC, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_249DE4:: @ 8249DE4
	msgbox BattleFrontier_BattleDomeLobby_Text_24AA31, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_249DED:: @ 8249DED
	setvar VAR_0x8004, 20
	special CallBattleDomeFunction
	msgbox BattleFrontier_BattleDomeLobby_Text_24AA76, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_249DFE:: @ 8249DFE
	msgbox BattleFrontier_BattleDomeLobby_Text_24AB94, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_249E07:: @ 8249E07
	msgbox BattleFrontier_BattleDomeLobby_Text_24AC76, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_249E10:: @ 8249E10
	msgbox BattleFrontier_BattleDomeLobby_Text_24ACD3, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_249E19:: @ 8249E19
	msgbox BattleFrontier_OutsideWest_Text_24AB06, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_249E22:: @ 8249E22
	msgbox BattleFrontier_OutsideWest_Text_24AB44, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_249E2B:: @ 8249E2B
	msgbox BattleFrontier_OutsideWest_Text_24AB75, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_249E34:: @ 8249E34
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_24AE63, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_249E43
	end

BattleFrontier_BattleDomeLobby_EventScript_249E43:: @ 8249E43
	message BattleFrontier_BattleDomeLobby_Text_24AE8B
	waitmessage
	multichoice 17, 4, MULTI_BATTLE_DOME_RULES, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeLobby_EventScript_249E8B
	case 1, BattleFrontier_BattleDomeLobby_EventScript_249E99
	case 2, BattleFrontier_BattleDomeLobby_EventScript_249EA7
	case 3, BattleFrontier_BattleDomeLobby_EventScript_249EB5
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_249EB5
	end

BattleFrontier_BattleDomeLobby_EventScript_249E8B:: @ 8249E8B
	msgbox BattleFrontier_BattleDomeLobby_Text_24AEAE, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_249E43
	end

BattleFrontier_BattleDomeLobby_EventScript_249E99:: @ 8249E99
	msgbox BattleFrontier_BattleDomeLobby_Text_24AF4C, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_249E43
	end

BattleFrontier_BattleDomeLobby_EventScript_249EA7:: @ 8249EA7
	msgbox BattleFrontier_BattleDomeLobby_Text_24B073, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_249E43
	end

BattleFrontier_BattleDomeLobby_EventScript_249EB5:: @ 8249EB5
	releaseall
	end

BattleFrontier_BattleDomeLobby_Text_249EB7: @ 8249EB7
	.string "Bienvenue au DOME DE COMBAT!\p"
	.string "Ici, nous mettons à l'épreuve\n"
	.string "la tactique des DRESSEURS!\p"
	.string "Je serai votre guide pour le\n"
	.string "TOURNOI DE COMBAT SOLO.$"

BattleFrontier_BattleDomeLobby_Text_249F3A: @ 8249F3A
	.string "Voulez-vous participer à un TOURNOI\n"
	.string "DE COMBAT SOLO?$"

BattleFrontier_BattleDomeLobby_Text_249F74: @ 8249F74
	.string "A une prochaine fois peut-être!$"

BattleFrontier_BattleDomeLobby_Text_249F8E: @ 8249F8E
	.string "Le TOURNOI DE COMBAT SOLO est, comme\n"
	.string "son nom l'indique, un tournoi constitué\l"
	.string "de COMBATS SOLO.\p"
	.string "Tous les DRESSEURS qui y participent\n"
	.string "doivent avoir trois POKéMON.\p"
	.string "Lors des combats, l'un des trois\n"
	.string "POKéMON est gardé en réserve.\p"
	.string "Les deux autres POKéMON peuvent se\n"
	.string "battrent l'un après l'autre.\p"
	.string "Etudiez les trois POKéMON de\n"
	.string "l'adversaire avant de choisir les deux\l"
	.string "POKéMON que vous envoyez au combat.\p"
	.string "Vous devez vaincre quatre DRESSEURS\n"
	.string "pour remporter le tournoi.\p"
	.string "Des POINTS DE COMBAT sont remis\n"
	.string "au vainqueur du tournoi.\p"
	.string "Si vous voulez interrompre le défi,\n"
	.string "veuillez sauvegarder la partie.\p"
	.string "Assurez-vous de bien sauvegarder, ou\n"
	.string "vous ne pourrez pas reprendre le défi.$"

BattleFrontier_BattleDomeLobby_Text_24A1C6: @ 824A1C6
	.string "Avant de pouvoir me suivre dans le DOME\n"
	.string "DE COMBAT, vous devez sauvegarder. OK?$"

BattleFrontier_BattleDomeLobby_Text_24A210: @ 824A210
	.string "Le tournoi propose deux niveaux de\n"
	.string "défi: niveau 50 et niveau libre.\l"
	.string "Que choisissez-vous?$"

BattleFrontier_BattleDomeLobby_Text_24A26E: @ 824A26E
	.string "Veuillez choisir les trois POKéMON que\n"
	.string "vous souhaitez inscrire.$"

BattleFrontier_BattleDomeLobby_Text_24A2AB: @ 824A2AB
	.string "Je regrette!\p"
	.string "Vous n'avez pas trois POKéMON\n"
	.string "aptes à participer.\p"
	.string "Ils doivent aussi tenir des objets\n"
	.string "différents.\p"
	.string "Les OEUFS{STR_VAR_1} inaptes au combat.\p"
	.string "Revenez me voir quand vous aurez\n"
	.string "ce qu'il faut.$"

BattleFrontier_BattleDomeLobby_Text_24A353: @ 824A353
	.string "Je regrette!\p"
	.string "Vous n'avez pas trois POKéMON\n"
	.string "aptes à participer.\p"
	.string "Il vous faut trois POKéMON différents\n"
	.string "de niveau 50 ou moins pour participer.\p"
	.string "Ils doivent aussi tenir des objets\n"
	.string "différents.\p"
	.string "Les OEUFS{STR_VAR_1} inaptes au combat.\p"
	.string "Revenez me voir quand vous aurez\n"
	.string "ce qu'il faut.$"

BattleFrontier_BattleDomeLobby_Text_24A437: @ 824A437
	.string "Veuillez me suivre dans le\n"
	.string "DOME DE COMBAT.$"

BattleFrontier_BattleDomeLobby_Text_24A45F: @ 824A45F
	.string "Je regrette!\p"
	.string "Vous n'avez pas sauvegardé avant de\n"
	.string "quitter votre dernier défi.\p"
	.string "Dans ce cas, c'est la disqualification.\n"
	.string "C'est dommage!$"

BattleFrontier_BattleDomeLobby_Text_24A4E9: @ 824A4E9
	.string "Félicitations pour avoir remporté ce\n"
	.string "TOURNOI DE COMBAT!$"

BattleFrontier_BattleDomeLobby_Text_24A51D: @ 824A51D
	.string "Here is your prize for your Battle\n"
	.string "Tournament victory.$"

VerdanturfTown_BattleTentLobby_Text_24A554: @ 824A554
	.string "{PLAYER} reçoit {STR_VAR_1}\n"
	.string "en récompense.$"

VerdanturfTown_BattleTentLobby_Text_24A56E: @ 824A56E
	.string "Oh, your BAG appears to be full.\p"
	.string "Please make room in your BAG, then come\n"
	.string "see me.$"

BattleFrontier_BattleDomeLobby_Text_24A5BF: @ 824A5BF
	.string "Merci d'avoir joué!$"

BattleFrontier_BattleDomeLobby_Text_24A5D6: @ 824A5D6
	.string "Votre résultat va être sauvegardé.\n"
	.string "Veuillez patienter.$"

BattleFrontier_BattleDomeLobby_Text_24A5FE: @ 824A5FE
	.string "Nous vous attendions!$"

BattleFrontier_BattleDomeLobby_Text_24A61A: @ 824A61A
	.string "Vous devez sauvegarder avant d'entrer\n"
	.string "dans le DOME DE COMBAT. Patientez.$"

BattleFrontier_BattleDomeLobby_Text_24A664: @ 824A664
	.string "Bienvenue au DOME DE COMBAT!\p"
	.string "Ici, nous mettons à l'épreuve\n"
	.string "la tactique des DRESSEURS!\p"
	.string "Je serai votre guide pour le\n"
	.string "TOURNOI DE COMBAT DUO.$"

BattleFrontier_BattleDomeLobby_Text_24A6E7: @ 824A6E7
	.string "Voulez-vous participer à un TOURNOI DE\n"
	.string "COMBAT DUO?$"

BattleFrontier_BattleDomeLobby_Text_24A721: @ 824A721
	.string "Le TOURNOI DE COMBAT DUO est, comme\n"
	.string "son nom l'indique, un tournoi constitué\l"
	.string "de COMBATS DUO.\p"
	.string "Tous les DRESSEURS qui y participent\n"
	.string "doivent avoir trois POKéMON.\p"
	.string "Lors des combats, l'un des trois\n"
	.string "POKéMON est gardé en réserve.\p"
	.string "Les deux autres POKéMON doivent faire\n"
	.string "un COMBAT DUO.\p"
	.string "Etudiez les trois POKéMON de\n"
	.string "l'adversaire avant de choisir les deux\l"
	.string "POKéMON que vous envoyez au combat.\p"
	.string "Vous devez vaincre quatre DRESSEURS\n"
	.string "pour remporter le tournoi.\p"
	.string "Des POINTS DE COMBAT sont remis\n"
	.string "au vainqueur du tournoi.\p"
	.string "Si vous voulez interrompre le défi,\n"
	.string "veuillez sauvegarder la partie.\p"
	.string "Assurez-vous de bien sauvegarder, ou\n"
	.string "vous ne pourrez pas reprendre le défi.$"

BattleFrontier_BattleDomeLobby_Text_24A966: @ 824A966
	.string "Résultats du dernier TOURNOI DE COMBAT\n"
	.string "SOLO niveau 50.$"

BattleFrontier_BattleDomeLobby_Text_24A9A9: @ 824A9A9
	.string "Résultats du dernier TOURNOI DE COMBAT\n"
	.string "DUO niveau 50.$"

BattleFrontier_BattleDomeLobby_Text_24A9EC: @ 824A9EC
	.string "Résultats du dernier TOURNOI DE COMBAT\n"
	.string "SOLO niveau libre.$"

BattleFrontier_BattleDomeLobby_Text_24AA31: @ 824AA31
	.string "Résultats du dernier TOURNOI DE COMBAT\n"
	.string "DUO niveau libre.$"

BattleFrontier_BattleDomeLobby_Text_24AA76: @ 824AA76
	.string "Tu as assisté au dernier\n"
	.string "TOURNOI DE COMBAT?\p"
	.string "{STR_VAR_1}, le vainqueur,\n"
	.string "était vraiment balèze!\p"
	.string "Tu devrais consulter les résultats\n"
	.string "sur le panneau à côté du PC.$"

BattleFrontier_OutsideWest_Text_24AB06: @ 824AB06
	.string "La ZONE DE COMBAT… J'ai rêvé\n"
	.string "d'un tel endroit pendant des années.$"

BattleFrontier_OutsideWest_Text_24AB44: @ 824AB44
	.string "DOME DE COMBAT \n"
	.string "Devenez une star incontestable!$"

BattleFrontier_OutsideWest_Text_24AB75: @ 824AB75
	.string "??????\n"
	.string "Construction en cours!$"

BattleFrontier_BattleDomeLobby_Text_24AB94: @ 824AB94
	.string "Quand un DRESSEUR remporte\n"
	.string "plusieurs tournois au DOME DE\l"
	.string "COMBAT, il devient une vraie star.\p"
	.string "C'est ce qui attire les DRESSEURS au\n"
	.string "DOME DE COMBAT.\p"
	.string "Un DRESSEUR qui enchaîne les\n"
	.string "victoires est vraiment une star.$"

BattleFrontier_BattleDomeLobby_Text_24AC76: @ 824AC76
	.string "Au premier tour, j'ai affronté un\n"
	.string "habitué du DOME DE COMBAT.\p"
	.string "Je me suis fait ratatiner…$"

BattleFrontier_BattleDomeLobby_Text_24ACD3: @ 824ACD3
	.string "J'aurais gagné si j'avais mis ce POKéMON\n"
	.string "en réserve.\p"
	.string "Avant de choisir quels POKéMON tu\n"
	.string "envoies au combat, regarde bien ceux\l"
	.string "de l'adversaire.$"

BattleFrontier_BattleDomeLobby_Text_24AD67: @ 824AD67
	.string "Félicitations!\p"
	.string "Vous avez battu la STAR DU DOME et\n"
	.string "remporté le TOURNOI DE COMBAT!$"

BattleFrontier_BattleDomeLobby_Text_24ADB1: @ 824ADB1
	.string "Votre excellente tactique va être\n"
	.string "récompensée en POINTS DE COMBAT!$"

BattleFrontier_BattleDomeLobby_Text_24AE17: @ 824AE17
	.string "Voulez-vous enregistrer votre dernier\n"
	.string "combat au DOME DE COMBAT sur votre\l"
	.string "PASSE ZONE?$"

BattleFrontier_BattleDomeLobby_Text_24AE63: @ 824AE63
	.string "Règles du TOURNOI DE COMBAT.$"

BattleFrontier_BattleDomeLobby_Text_24AE8B: @ 824AE8B
	.string "Quel chapitre voulez-vous lire?$"

BattleFrontier_BattleDomeLobby_Text_24AEAE: @ 824AEAE
	.string "Les DRESSEURS s'affrontent suivant\n"
	.string "la force de leurs POKéMON.\p"
	.string "Cela évite que les DRESSEURS forts\n"
	.string "ne se rencontrent dès le début.$"

BattleFrontier_BattleDomeLobby_Text_24AF4C: @ 824AF4C
	.string "Dans la salle d'attente, le guide vous\n"
	.string "donne accès au “TABLEAU”.\p"
	.string "Ce tableau des rencontres contient\n"
	.string "différentes informations.\p"
	.string "Vous pouvez y consulter les résultats,\n"
	.string "les POKéMON détenus par les DRESSEURS\l"
	.string "et les styles de combat des DRESSEURS.$"

BattleFrontier_BattleDomeLobby_Text_24B073: @ 824B073
	.string "Si deux POKéMON adverses\n"
	.string "s'évanouissent au même moment, un\l"
	.string "double K.O., ce sont les ARBITRES qui\l"
	.string "désignent le vainqueur.$"
