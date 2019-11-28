BattleFrontier_BattlePyramidLobby_MapScripts:: @ 8250716
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_MapScript2_250735
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePyramidLobby_MapScript2_2497FB
	.byte 0

BattleFrontier_BattlePyramidLobby_MapScript2_250721: @ 8250721
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidLobby_EventScript_25072B
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_25072B: @ 825072B
	setvar VAR_TEMP_1, 1
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePyramidLobby_MapScript2_250735: @ 8250735
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePyramidLobby_EventScript_25075F
	map_script_2 VAR_TEMP_0, 1, BattleFrontier_BattlePyramidLobby_EventScript_250768
	map_script_2 VAR_TEMP_0, 2, BattleFrontier_BattlePyramidLobby_EventScript_2508AC
	map_script_2 VAR_TEMP_0, 3, BattleFrontier_BattlePyramidLobby_EventScript_2507B1
	map_script_2 VAR_TEMP_0, 4, BattleFrontier_BattlePyramidLobby_EventScript_250852
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_25075F:: @ 825075F
	setvar VAR_0x8004, 0
	special CallFrontierUtilFunc
	end

BattleFrontier_BattlePyramidLobby_EventScript_250768:: @ 8250768
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_2516D6
	waitmessage
	playse SE_EXPMAX
	waitse
	closemessage
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SET_DATA
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special CallBattlePyramidFunction
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SET_DATA
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 0
	special CallBattlePyramidFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_2507B1:: @ 82507B1
	lockall
	setvar VAR_0x8004, 10
	special CallFrontierUtilFunc
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattlePyramidLobby_EventScript_2507D2
	msgbox BattleFrontier_BattlePyramidLobby_Text_2517B5, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_2507DA

BattleFrontier_BattlePyramidLobby_EventScript_2507D2:: @ 82507D2
	msgbox BattleFrontier_BattlePyramidLobby_Text_2525F4, MSGBOX_DEFAULT

BattleFrontier_BattlePyramidLobby_EventScript_2507DA:: @ 82507DA
	special DoBattlePyramidMonsHaveHeldItem
	compare VAR_RESULT, TRUE
	call_if_eq BattleFrontier_BattlePyramidLobby_EventScript_250DDB
	clearflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	setvar VAR_0x8004, 8
	special CallFrontierUtilFunc
	special LoadPlayerParty
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_CLEAR_HELD_ITEMS
	special CallBattlePyramidFunction
	special HealPlayerParty
	message BattleFrontier_BattlePyramidLobby_Text_2519F8
	waitmessage
	playse SE_EXPMAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_252662, MSGBOX_DEFAULT
	setvar VAR_0x8004, 11
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattlePyramidLobby_Text_241520, 9
	message BattleFrontier_BattlePyramidLobby_Text_251A77
	waitmessage
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SET_REWARD
	special CallBattlePyramidFunction
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_3
	setvar VAR_0x8005, 0
	special CallBattlePyramidFunction
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_251BB6, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_250852:: @ 8250852
	setvar VAR_0x8004, 8
	special CallFrontierUtilFunc
	special LoadPlayerParty
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_CLEAR_HELD_ITEMS
	special CallBattlePyramidFunction
	special HealPlayerParty
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_251B5A
	waitmessage
	playse SE_EXPMAX
	waitse
	message BattleFrontier_BattlePyramidLobby_Text_251A77
	waitmessage
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SET_DATA
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 0
	special CallBattlePyramidFunction
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_3
	setvar VAR_0x8005, 0
	special CallBattlePyramidFunction
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_251BB6, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_2508AC:: @ 82508AC
	goto BattleFrontier_BattlePyramidLobby_EventScript_250A21

BattleFrontier_BattlePyramidLobby_EventScript_2508B1:: @ 82508B1
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 6
	setvar VAR_FRONTIER_BATTLE_MODE, 0
	special SavePlayerParty
	msgbox BattleFrontier_BattlePyramidLobby_Text_250F31, MSGBOX_DEFAULT

BattleFrontier_BattlePyramidLobby_EventScript_2508C8:: @ 82508C8
	message BattleFrontier_BattlePyramidLobby_Text_250FA7
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_250904
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_250A68
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_250AC4
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_250AC4

BattleFrontier_BattlePyramidLobby_EventScript_250904:: @ 8250904
	message BattleFrontier_BattlePyramidLobby_Text_251248
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, 0
	switch VAR_RESULT
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_250AC4
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_250AC4
	setvar VAR_0x8004, 15
	special CallFrontierUtilFunc
	compare VAR_0x8004, 1
	goto_if_eq BattleFrontier_BattlePyramidLobby_EventScript_250A75
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	copyvar VAR_0x8006, VAR_RESULT
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattlePyramidLobby_Text_251297, MSGBOX_DEFAULT
	fadescreen 1
	call BattleFrontier_BattlePyramidLobby_EventScript_23F2B7
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, 3
	special sub_80F9490
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePyramidLobby_EventScript_250AC1
	msgbox BattleFrontier_BattlePyramidLobby_Text_2514E6, MSGBOX_YESNO
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_250AC1
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_2509A5
	case 127, BattleFrontier_BattlePyramidLobby_EventScript_250AC1

BattleFrontier_BattlePyramidLobby_EventScript_2509A5:: @ 82509A5
	setvar VAR_TEMP_0, 0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 4
	special CallFrontierUtilFunc
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_INIT_CHALLENGE
	special CallBattlePyramidFunction
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SET_DATA
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 1
	special CallBattlePyramidFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 1
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SEED_FLOOR
	special CallBattlePyramidFunction
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_INIT_TRAINERS
	special CallBattlePyramidFunction
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePyramidLobby_EventScript_250AAA

BattleFrontier_BattlePyramidLobby_EventScript_250A21:: @ 8250A21
	special SavePlayerParty
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattlePyramidLobby_Text_251531, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePyramidLobby_EventScript_250D56
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_RESULT, 0
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_EMPTY_SQUARE, 255, 1, 1
	setvar VAR_TEMP_0, 0
	waitstate
	end

BattleFrontier_BattlePyramidLobby_EventScript_250A68:: @ 8250A68
	msgbox BattleFrontier_BattlePyramidLobby_Text_25100C, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_2508C8

BattleFrontier_BattlePyramidLobby_EventScript_250A75:: @ 8250A75
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_250A90
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_250A9D

BattleFrontier_BattlePyramidLobby_EventScript_250A90:: @ 8250A90
	msgbox BattleFrontier_BattlePyramidLobby_Text_2513C1, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_250ACC

BattleFrontier_BattlePyramidLobby_EventScript_250A9D:: @ 8250A9D
	msgbox BattleFrontier_BattlePyramidLobby_Text_2512E2, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_250ACC

BattleFrontier_BattlePyramidLobby_EventScript_250AAA:: @ 8250AAA
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	goto BattleFrontier_BattlePyramidLobby_EventScript_250AC4

BattleFrontier_BattlePyramidLobby_EventScript_250AC1:: @ 8250AC1
	special LoadPlayerParty

BattleFrontier_BattlePyramidLobby_EventScript_250AC4:: @ 8250AC4
	msgbox BattleFrontier_BattlePyramidLobby_Text_250FE5, MSGBOX_DEFAULT

BattleFrontier_BattlePyramidLobby_EventScript_250ACC:: @ 8250ACC
	release
	end

BattleFrontier_BattlePyramidLobby_EventScript_250ACE:: @ 8250ACE
	lockall
	applymovement 2, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_251C3B, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidLobby_EventScript_250AF0
	msgbox BattleFrontier_BattlePyramidLobby_Text_252461, MSGBOX_DEFAULT
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_250AF0:: @ 8250AF0
	multichoice 17, 6, MULTI_LEVEL_MODE, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_250B28
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_250B66
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_250B27
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_250B27
	return

BattleFrontier_BattlePyramidLobby_EventScript_250B27:: @ 8250B27
	return

BattleFrontier_BattlePyramidLobby_EventScript_250B28:: @ 8250B28
	msgbox BattleFrontier_BattlePyramidLobby_Text_251C8A, MSGBOX_DEFAULT
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_GET_DATA
	setvar VAR_0x8005, 5
	special CallBattlePyramidFunction
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattlePyramidLobby_EventScript_250B53
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_250BA4
	return

BattleFrontier_BattlePyramidLobby_EventScript_250B53:: @ 8250B53
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_GET_DATA
	setvar VAR_0x8005, 3
	special CallBattlePyramidFunction
	goto BattleFrontier_BattlePyramidLobby_EventScript_250BA4
	return

BattleFrontier_BattlePyramidLobby_EventScript_250B66:: @ 8250B66
	msgbox BattleFrontier_BattlePyramidLobby_Text_251C8A, MSGBOX_DEFAULT
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_GET_DATA
	setvar VAR_0x8005, 6
	special CallBattlePyramidFunction
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattlePyramidLobby_EventScript_250B91
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_250BA4
	return

BattleFrontier_BattlePyramidLobby_EventScript_250B91:: @ 8250B91
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_GET_DATA
	setvar VAR_0x8005, 4
	special CallBattlePyramidFunction
	goto BattleFrontier_BattlePyramidLobby_EventScript_250BA4
	return

BattleFrontier_BattlePyramidLobby_EventScript_250BA4:: @ 8250BA4
	copyvar VAR_0x8004, VAR_RESULT
	special GetBattlePyramidHint
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_250C8E
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_250C97
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_250CA0
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_250CA9
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_250CB2
	case 5, BattleFrontier_BattlePyramidLobby_EventScript_250CBB
	case 6, BattleFrontier_BattlePyramidLobby_EventScript_250CC4
	case 7, BattleFrontier_BattlePyramidLobby_EventScript_250CCD
	case 8, BattleFrontier_BattlePyramidLobby_EventScript_250CD6
	case 9, BattleFrontier_BattlePyramidLobby_EventScript_250CDF
	case 10, BattleFrontier_BattlePyramidLobby_EventScript_250CE8
	case 11, BattleFrontier_BattlePyramidLobby_EventScript_250CF1
	case 12, BattleFrontier_BattlePyramidLobby_EventScript_250CFA
	case 13, BattleFrontier_BattlePyramidLobby_EventScript_250D03
	case 14, BattleFrontier_BattlePyramidLobby_EventScript_250D0C
	case 15, BattleFrontier_BattlePyramidLobby_EventScript_250D15
	case 16, BattleFrontier_BattlePyramidLobby_EventScript_250D1E
	case 17, BattleFrontier_BattlePyramidLobby_EventScript_250D27
	case 18, BattleFrontier_BattlePyramidLobby_EventScript_250D30
	case 19, BattleFrontier_BattlePyramidLobby_EventScript_250D39
	return

BattleFrontier_BattlePyramidLobby_EventScript_250C8E:: @ 8250C8E
	msgbox BattleFrontier_BattlePyramidLobby_Text_251CB3, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250C97:: @ 8250C97
	msgbox BattleFrontier_BattlePyramidLobby_Text_251D07, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250CA0:: @ 8250CA0
	msgbox BattleFrontier_BattlePyramidLobby_Text_251D54, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250CA9:: @ 8250CA9
	msgbox BattleFrontier_BattlePyramidLobby_Text_251D9C, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250CB2:: @ 8250CB2
	msgbox BattleFrontier_BattlePyramidLobby_Text_251E3D, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250CBB:: @ 8250CBB
	msgbox BattleFrontier_BattlePyramidLobby_Text_251EA1, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250CC4:: @ 8250CC4
	msgbox BattleFrontier_BattlePyramidLobby_Text_251F17, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250CCD:: @ 8250CCD
	msgbox BattleFrontier_BattlePyramidLobby_Text_251F6E, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250CD6:: @ 8250CD6
	msgbox BattleFrontier_BattlePyramidLobby_Text_251FC7, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250CDF:: @ 8250CDF
	msgbox BattleFrontier_BattlePyramidLobby_Text_25201B, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250CE8:: @ 8250CE8
	msgbox BattleFrontier_BattlePyramidLobby_Text_252068, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250CF1:: @ 8250CF1
	msgbox BattleFrontier_BattlePyramidLobby_Text_2520BA, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250CFA:: @ 8250CFA
	msgbox BattleFrontier_BattlePyramidLobby_Text_252158, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250D03:: @ 8250D03
	msgbox BattleFrontier_BattlePyramidLobby_Text_2521B4, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250D0C:: @ 8250D0C
	msgbox BattleFrontier_BattlePyramidLobby_Text_252206, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250D15:: @ 8250D15
	msgbox BattleFrontier_BattlePyramidLobby_Text_25225A, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250D1E:: @ 8250D1E
	msgbox BattleFrontier_BattlePyramidLobby_Text_2522AE, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250D27:: @ 8250D27
	msgbox BattleFrontier_BattlePyramidLobby_Text_25230B, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250D30:: @ 8250D30
	msgbox BattleFrontier_BattlePyramidLobby_Text_252364, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250D39:: @ 8250D39
	msgbox BattleFrontier_BattlePyramidLobby_Text_252403, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250D42:: @ 8250D42
	lockall
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 6
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_250D56:: @ 8250D56
	applymovement 1, BattleFrontier_BattlePyramidLobby_Movement_250DC4
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_250DCD
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_251569, MSGBOX_DEFAULT
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_GET_DATA
	setvar VAR_0x8005, 1
	special CallBattlePyramidFunction
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePyramidLobby_EventScript_250D94
	msgbox BattleFrontier_BattlePyramidLobby_Text_2515AD, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_250D9C

BattleFrontier_BattlePyramidLobby_EventScript_250D94:: @ 8250D94
	msgbox BattleFrontier_BattlePyramidLobby_Text_2515F4, MSGBOX_DEFAULT

BattleFrontier_BattlePyramidLobby_EventScript_250D9C:: @ 8250D9C
	message BattleFrontier_BattlePyramidLobby_Text_25161E
	waitmessage
	playse SE_EXPMAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_251647, MSGBOX_DEFAULT
	closemessage
	applymovement 1, BattleFrontier_BattlePyramidLobby_Movement_250DD5
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_250DD8
	waitmovement 0
	return

BattleFrontier_BattlePyramidLobby_Movement_250DC4: @ 8250DC4
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattlePyramidLobby_Movement_250DCD: @ 8250DCD
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_Movement_250DD5: @ 8250DD5
	walk_right
	face_left
	step_end

BattleFrontier_BattlePyramidLobby_Movement_250DD8: @ 8250DD8
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_EventScript_250DDB:: @ 8250DDB
	msgbox BattleFrontier_BattlePyramidLobby_Text_2517FC, MSGBOX_DEFAULT
	setflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	special TryStoreHeldItemsInPyramidBag
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePyramidLobby_EventScript_250E00
	message BattleFrontier_BattlePyramidLobby_Text_2518C6
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_250E09
	end

BattleFrontier_BattlePyramidLobby_EventScript_250E00:: @ 8250E00
	msgbox BattleFrontier_BattlePyramidLobby_Text_251881, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_250E09:: @ 8250E09
	multichoice 17, 6, MULTI_FRONTIER_ITEM_CHOOSE, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_250E40
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_250E50
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_250E60
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_250E60
	end

BattleFrontier_BattlePyramidLobby_EventScript_250E40:: @ 8250E40
	special sub_81C4F24
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_25197E
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_250E09
	end

BattleFrontier_BattlePyramidLobby_EventScript_250E50:: @ 8250E50
	special BattlePyramidChooseMonHeldItems
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_25197E
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_250E09
	end

BattleFrontier_BattlePyramidLobby_EventScript_250E60:: @ 8250E60
	special DoBattlePyramidMonsHaveHeldItem
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_BattlePyramidLobby_EventScript_250E6F
	return

BattleFrontier_BattlePyramidLobby_EventScript_250E6F:: @ 8250E6F
	msgbox BattleFrontier_BattlePyramidLobby_Text_25194F, MSGBOX_DEFAULT
	message BattleFrontier_BattlePyramidLobby_Text_25197E
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_250E09
	end

BattleFrontier_BattlePyramidLobby_EventScript_250E83:: @ 8250E83
	msgbox BattleFrontier_BattlePyramidLobby_Text_2524DA, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_250E8C:: @ 8250E8C
	msgbox BattleFrontier_BattlePyramidLobby_Text_252595, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_250E95:: @ 8250E95
	lockall
	msgbox BattleFrontier_BattlePyramidLobby_Text_2526B6, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_250EA4
	end

BattleFrontier_BattlePyramidLobby_EventScript_250EA4:: @ 8250EA4
	message BattleFrontier_BattlePyramidLobby_Text_2526D9
	waitmessage
	multichoice 15, 2, MULTI_BATTLE_PYRAMID_RULES, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_250EF7
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_250F05
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_250F13
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_250F21
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_250F2F
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_250F2F
	end

BattleFrontier_BattlePyramidLobby_EventScript_250EF7:: @ 8250EF7
	msgbox BattleFrontier_BattlePyramidLobby_Text_2526FC, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_250EA4
	end

BattleFrontier_BattlePyramidLobby_EventScript_250F05:: @ 8250F05
	msgbox BattleFrontier_BattlePyramidLobby_Text_2527A9, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_250EA4
	end

BattleFrontier_BattlePyramidLobby_EventScript_250F13:: @ 8250F13
	msgbox BattleFrontier_BattlePyramidLobby_Text_25285A, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_250EA4
	end

BattleFrontier_BattlePyramidLobby_EventScript_250F21:: @ 8250F21
	msgbox BattleFrontier_BattlePyramidLobby_Text_252924, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_250EA4
	end

BattleFrontier_BattlePyramidLobby_EventScript_250F2F:: @ 8250F2F
	releaseall
	end

BattleFrontier_BattlePyramidLobby_Text_250F31: @ 8250F31
	.string "Bienvenue à la PYRAMIDE DE COMBAT!\p"
	.string "Ici, nous mettons à l'épreuve\n"
	.string "le courage des DRESSEURS!\p"
	.string "Je serai votre guide pour le\n"
	.string "COMBAT QUETE.$"

BattleFrontier_BattlePyramidLobby_Text_250FA7: @ 8250FA7
	.string "Avez-vous le courage de relever le\n"
	.string "défi du COMBAT QUETE?$"

BattleFrontier_BattlePyramidLobby_Text_250FE5: @ 8250FE5
	.string "Nous attendrons votre prochain défi\n"
	.string "avec impatience.$"

BattleFrontier_BattlePyramidLobby_Text_25100C: @ 825100C
	.string "Lors du COMBAT QUETE, vous devez\n"
	.string "explorer la PYRAMIDE et essayer d'en\l"
	.string "atteindre le sommet.\p"
	.string "Chacun des sept niveaux de la PYRAMIDE\n"
	.string "est un labyrinthe. Ils sont truffés de\l"
	.string "DRESSEURS et de POKéMON sauvages.\p"
	.string "Vous devez y entrer avec trois POKéMON\n"
	.string "ne portant aucun objet.\p"
	.string "On vous fournira un SAC DE COMBAT\n"
	.string "pour y mettre les objets.\p"
	.string "Si vous échouez, vous perdez les objets\n"
	.string "placés dans le SAC DE COMBAT.\p"
	.string "Si vous voulez interrompre le défi,\n"
	.string "sélectionnez “REPOS”\l"
	.string "et sauvegardez la partie.\p"
	.string "Assurez-vous de bien sauvegarder, ou\n"
	.string "vous ne pourrez pas reprendre le défi.$"

BattleFrontier_BattlePyramidLobby_Text_251248: @ 8251248
	.string "La PYRAMIDE offre deux possibilités:\n"
	.string "niveau 50 et niveau libre.\l"
	.string "Que choisissez-vous?$"

BattleFrontier_BattlePyramidLobby_Text_251297: @ 8251297
	.string "Très bien. Choisissez les trois POKéMON\n"
	.string "qui vont vous accompagner.$"

BattleFrontier_BattlePyramidLobby_Text_2512E2: @ 82512E2
	.string "Il y a un petit problème!\p"
	.string "Vous n'avez pas trois POKéMON\n"
	.string "aptes à participer.\p"
	.string "Souvenez-vous que vous devez leur\n"
	.string "reprendre les objets qu'ils portent.\p"
	.string "Les OEUFS{STR_VAR_1} inaptes au combat.\p"
	.string "On en reparlera quand vous aurez\n"
	.string "ce qu'il faut.$"

BattleFrontier_BattlePyramidLobby_Text_2513C1: @ 82513C1
	.string "Il y a un petit problème!\p"
	.string "Vous n'avez pas trois POKéMON\n"
	.string "aptes à participer.\p"
	.string "Il vous faut trois POKéMON différents\n"
	.string "de niveau 50 ou moins pour participer.\p"
	.string "Souvenez-vous que vous devez leur\n"
	.string "reprendre les objets qu'ils portent.\p"
	.string "Les OEUFS{STR_VAR_1} inaptes au combat.\p"
	.string "On en reparlera quand vous aurez\n"
	.string "ce qu'il faut.$"

BattleFrontier_BattlePyramidLobby_Text_2514E6: @ 82514E6
	.string "Pour accéder à la PYRAMIDE DE COMBAT,\n"
	.string "votre partie doit être sauvegardée. OK?$"

BattleFrontier_BattlePyramidLobby_Text_251531: @ 8251531
	.string "Très bien. Je vais vous accompagner\n"
	.string "dans la PYRAMIDE DE COMBAT.$"

BattleFrontier_BattlePyramidLobby_Text_251569: @ 8251569
	.string "Nous gardons votre SAC pendant votre\n"
	.string "exploration, {PLAYER}.$"

BattleFrontier_BattlePyramidLobby_Text_2515AD: @ 82515AD
	.string "Tenez, prenez votre ancien SAC DE\n"
	.string "COMBAT en échange.$"

BattleFrontier_BattlePyramidLobby_Text_2515F4: @ 82515F4
	.string "Tenez, prenez ce SAC DE\n"
	.string "COMBAT en échange.$"

BattleFrontier_BattlePyramidLobby_Text_25161E: @ 825161E
	.string "{PLAYER} a échangé le SAC avec le\n"
	.string "SAC DE COMBAT.$"

BattleFrontier_BattlePyramidLobby_Text_251647: @ 8251647
	.string "Ce type de plaque permet d'être\n"
	.string "transporté au niveau supérieur de\l"
	.string "la PYRAMIDE.\p"
	.string "J'espère que tout va bien se passer\n"
	.string "pour vous!$"

BattleFrontier_BattlePyramidLobby_Text_2516D6: @ 82516D6
	.string "Il y a un gros problème!\p"
	.string "Vous n'avez pas sauvegardé avant de\n"
	.string "quitter votre dernier défi.\p"
	.string "Dans ce cas, c'est la disqualification.\n"
	.string "C'est dommage!\p"
	.string "Je vous rends votre SAC, tenez.\p"
	.string "{PLAYER} a récupéré le SAC.$"

BattleFrontier_BattlePyramidLobby_Text_2517B5: @ 82517B5
	.string "Quel plaisir de vous revoir!\p"
	.string "Vous avez conquis la PYRAMIDE!\n"
	.string "Ce fut splendide!$"

BattleFrontier_BattlePyramidLobby_Text_2517FC: @ 82517FC
	.string "Il y a un petit problème!\p"
	.string "Au moins un de vos POKéMON porte\n"
	.string "un objet.\p"
	.string "Malheureusement, les objets obtenus\n"
	.string "dans la PYRAMIDE doivent rester ici.$"

BattleFrontier_BattlePyramidLobby_Text_251881: @ 8251881
	.string "Tous les objets vont être placés dans\n"
	.string "votre SAC DE COMBAT, {PLAYER}.$"

BattleFrontier_BattlePyramidLobby_Text_2518C6: @ 82518C6
	.string "Le SAC DE COMBAT ne peut pas contenir\n"
	.string "tous vos objets, je suis désolé.\p"
	.string "Choisissez les objets à laisser dans le\n"
	.string "SAC DE COMBAT et avec vos POKéMON.$"

BattleFrontier_BattlePyramidLobby_Text_25194F: @ 825194F
	.string "Au moins un POKéMON porte encore\n"
	.string "un objet.$"

BattleFrontier_BattlePyramidLobby_Text_25197E: @ 825197E
	.string "Choisissez les objets à laisser dans le\n"
	.string "SAC DE COMBAT et avec vos POKéMON.$"

BattleFrontier_BattlePyramidLobby_Text_2519CA: @ 82519CA
	.string "{PLAYER} returned everything that\n"
	.string "the POKéMON held.$"

BattleFrontier_BattlePyramidLobby_Text_2519F8: @ 82519F8
	.string "Votre SAC DE COMBAT va être conservé\n"
	.string "pour votre prochain défi.\p"
	.string "{PLAYER} a rendu le SAC DE COMBAT et a\n"
	.string "repris le SAC.$"

BattleFrontier_BattlePyramidLobby_Text_251A77: @ 8251A77
	.string "Votre résultat va être sauvegardé.\n"
	.string "Veuillez patienter.$"

BattleFrontier_BattlePyramidLobby_Text_251AA0: @ 8251AA0
	.string "As a memento for conquering\n"
	.string "the BATTLE PYRAMID, please take this.$"

BattleFrontier_BattlePyramidLobby_Text_251AE2: @ 8251AE2
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattlePyramidLobby_Text_251AFC: @ 8251AFC
	.string "…Ah…\n"
	.string "Your BAG appears to be filled.\p"
	.string "Please return after you've organized\n"
	.string "your BAG's contents.$"

BattleFrontier_BattlePyramidLobby_Text_251B5A: @ 8251B5A
	.string "Que c'est décevant…\p"
	.string "Voici votre SAC.\p"
	.string "{PLAYER} a récupéré le SAC.$"

BattleFrontier_BattlePyramidLobby_Text_251BB6: @ 8251BB6
	.string "Nous attendrons votre prochain défi\n"
	.string "avec impatience.$"

BattleFrontier_BattlePyramidLobby_Text_251BDE: @ 8251BDE
	.string "We have been looking forward to\n"
	.string "your arrival!\p"
	.string "Here is your prize for conquering\n"
	.string "the PYRAMID.$"

BattleFrontier_BattlePyramidLobby_Text_251C3B: @ 8251C3B
	.string "Bienvenue à toi…\p"
	.string "Je serais ravie de te dire les malheurs\n"
	.string "qui t'attendent dans la PYRAMIDE…$"

BattleFrontier_BattlePyramidLobby_Text_251C8A: @ 8251C8A
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "… … … … … …\n"
	.string "Ah!$"

BattleFrontier_BattlePyramidLobby_Text_251CB3: @ 8251CB3
	.string "Je vois une pluie d'étincelles…\p"
	.string "Dans cette pluie, je vois tes POKéMON\n"
	.string "lutter contre la paralysie…$"

BattleFrontier_BattlePyramidLobby_Text_251D07: @ 8251D07
	.string "Je vois du poison…\p"
	.string "Oui, tes POKéMON souffrent d'un\n"
	.string "empoisonnement…$"

BattleFrontier_BattlePyramidLobby_Text_251D54: @ 8251D54
	.string "Je vois des flammes rouges…\p"
	.string "Tes POKéMON souffrent de\n"
	.string "brûlures…$"

BattleFrontier_BattlePyramidLobby_Text_251D9C: @ 8251D9C
	.string "Je ressens la pression d'une fureur\n"
	.string "incontrôlable…\p"
	.string "C'est une malédiction…\p"
	.string "Et je vois les POINTS DE POUVOIR de\n"
	.string "tes POKéMON se faire drainer.\l"
	.string "Ils sont obligés d'utiliser LUTTE…$"

BattleFrontier_BattlePyramidLobby_Text_251E3D: @ 8251E3D
	.string "Je vois des POKéMON voler à haute\n"
	.string "altitude…\p"
	.string "Tes POKéMON sont frustrés face à\n"
	.string "l'échec de leurs capacités de type SOL…$"

BattleFrontier_BattlePyramidLobby_Text_251EA1: @ 8251EA1
	.string "Je sens une énergie incroyable\n"
	.string "provenant du sol…\p"
	.string "Je vois tes POKéMON incapables\n"
	.string "d'échapper à son emprise…$"

BattleFrontier_BattlePyramidLobby_Text_251F17: @ 8251F17
	.string "Je vois des POKéMON de type GLACE…\p"
	.string "Tes POKéMON luttent contre le froid\n"
	.string "mordant de la glace…$"

BattleFrontier_BattlePyramidLobby_Text_251F6E: @ 8251F6E
	.string "Je vois une myriade de capacités\n"
	.string "dangereuses pour celui qui les utilise…\p"
	.string "Tes POKéMON en souffrent…$"

BattleFrontier_BattlePyramidLobby_Text_251FC7: @ 8251FC7
	.string "Je vois des POKéMON de type PSY…\p"
	.string "Tes POKéMON sont aux prises avec\n"
	.string "des capacités de type PSY…$"

BattleFrontier_BattlePyramidLobby_Text_25201B: @ 825201B
	.string "Je vois des POKéMON de type ROCHE…\p"
	.string "Et je vois tes POKéMON souffrir à cause\n"
	.string "de capacités de type ROCHE…$"

BattleFrontier_BattlePyramidLobby_Text_252068: @ 8252068
	.string "Je vois des POKéMON de type COMBAT…\p"
	.string "Tes POKéMON sont assaillis d'attaques\n"
	.string "de type COMBAT…$"

BattleFrontier_BattlePyramidLobby_Text_2520BA: @ 82520BA
	.string "DANSE PLUIE… ZENITH…\n"
	.string "TEMPETESABLE… GRELE…\p"
	.string "Je vois des POKéMON qui se renforcent\n"
	.string "avec les conditions climatiques…\p"
	.string "Tes POKéMON sont perdus, les\n"
	.string "capacités sont de tous types…$"

BattleFrontier_BattlePyramidLobby_Text_252158: @ 8252158
	.string "Je vois des POKéMON de type INSECTE…\p"
	.string "Tes POKéMON subissent des attaques\n"
	.string "de différentes sortes…$"

BattleFrontier_BattlePyramidLobby_Text_2521B4: @ 82521B4
	.string "Je vois des POKéMON de type TENEBRES…\p"
	.string "Tes POKéMON sont aux prises avec\n"
	.string "des capacités de type TENEBRES…$"

BattleFrontier_BattlePyramidLobby_Text_252206: @ 8252206
	.string "Je vois des POKéMON de type EAU…\p"
	.string "Tes POKéMON sont aux prises avec\n"
	.string "des capacités de type EAU…$"

BattleFrontier_BattlePyramidLobby_Text_25225A: @ 825225A
	.string "Je vois des POKéMON de type SPECTRE…\p"
	.string "Tes POKéMON sont aux prises avec des\n"
	.string "capacités de type SPECTRE…$"

BattleFrontier_BattlePyramidLobby_Text_2522AE: @ 82522AE
	.string "Je vois des POKéMON de type ACIER…\p"
	.string "Tes POKéMON sont aux prises avec des\n"
	.string "capacités très puissantes…$"

BattleFrontier_BattlePyramidLobby_Text_25230B: @ 825230B
	.string "Je vois des POKéMON volants…\p"
	.string "Tes POKéMON sont aux prises avec des\n"
	.string "capacités très puissantes…$"

BattleFrontier_BattlePyramidLobby_Text_252364: @ 8252364
	.string "Je vois ceux qui dérivent du pouvoir\n"
	.string "de la pierre…\p"
	.string "Je sens le feu, l'eau et l'électricité…\p"
	.string "Tes POKéMON doivent affronter ces\n"
	.string "trois pouvoirs…$"

BattleFrontier_BattlePyramidLobby_Text_252403: @ 8252403
	.string "Je vois des POKéMON de type NORMAL…\p"
	.string "Tes POKéMON sont aux prises avec des\n"
	.string "capacités très puissantes…$"

BattleFrontier_BattlePyramidLobby_Text_252461: @ 8252461
	.string "Que tu me croies ou non n'a aucune\n"
	.string "importance…\p"
	.string "Tu as le pouvoir de modifier ton avenir…\n"
	.string "Je te souhaite de réussir…$"

BattleFrontier_BattlePyramidLobby_Text_2524DA: @ 82524DA
	.string "J'ai un secret pour toi.\p"
	.string "Si tu cours, tu risques d'attirer\n"
	.string "l'attention des DRESSEURS et ils\l"
	.string "voudront se battre contre toi.\p"
	.string "Pour les éviter, il faut se faire discret\n"
	.string "et passer lentement à côté d'eux.$"

BattleFrontier_BattlePyramidLobby_Text_252595: @ 8252595
	.string "Ahhhhh!\p"
	.string "J'avais plein d'objets, mais ils se sont\n"
	.string "envolés quand j'ai perdu!\p"
	.string "Ouin!!!!!!!!!!!!$"

BattleFrontier_BattlePyramidLobby_Text_2525F4: @ 82525F4
	.string "Vous voilà de retour!\n"
	.string "Vous avez réussi l'impossible!\p"
	.string "Vous avez battu le ROI PYRAMIDE\n"
	.string "et conquis la PYRAMIDE DE COMBAT!$"

BattleFrontier_BattlePyramidLobby_Text_252662: @ 8252662
	.string "Jeune intrépide!\n"
	.string "Votre courage va être récompensé\l"
	.string "par des POINTS DE COMBAT!$"

BattleFrontier_BattlePyramidLobby_Text_2526B6: @ 82526B6
	.string "Règles du COMBAT QUETE.$"

BattleFrontier_BattlePyramidLobby_Text_2526D9: @ 82526D9
	.string "Quel chapitre voulez-vous lire?$"

BattleFrontier_BattlePyramidLobby_Text_2526FC: @ 82526FC
	.string "Une fois la PYRAMIDE conquise,\n"
	.string "les POKéMON sauvages qui s'y trouvent\l"
	.string "sont remplacés par d'autres.\p"
	.string "Il faut en profiter pour les observer\n"
	.string "et apprendre à connaître de\l"
	.string "nouveaux POKéMON sauvages.$"

BattleFrontier_BattlePyramidLobby_Text_2527A9: @ 82527A9
	.string "Des DRESSEURS vous attendent à\n"
	.string "l'intérieur de la PYRAMIDE.\p"
	.string "A chaque niveau, il y a jusqu'à\n"
	.string "huit DRESSEURS.\p"
	.string "Quand vous en battez un, vous\n"
	.string "recevez une information importante.$"

BattleFrontier_BattlePyramidLobby_Text_25285A: @ 825285A
	.string "Les labyrinthes de la PYRAMIDE\n"
	.string "changent à chaque fois que vous\l"
	.string "y entrez.\p"
	.string "Les labyrinthes sont très peu éclairés.\n"
	.string "Vous devez avancer avec précaution.\p"
	.string "Quand vous battez un POKéMON sauvage\n"
	.string "ou un DRESSEUR, la lumière s'intensifie.$"

BattleFrontier_BattlePyramidLobby_Text_252924: @ 8252924
	.string "Le SAC DE COMBAT sera votre SAC\n"
	.string "dans la PYRAMIDE.\p"
	.string "Il y a deux SACS DE COMBAT: un pour\n"
	.string "niveau 50 et un pour niveau libre.\p"
	.string "Chacun peut contenir 99 exemplaires\n"
	.string "de dix types d'objets différents.\p"
	.string "Le contenu du SAC DE COMBAT est\n"
	.string "perdu si vous échouez.$"

