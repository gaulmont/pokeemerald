BattleFrontier_BattlePalaceBattleRoom_MapScripts:: @ 824F815
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePalaceBattleRoom_MapScript1_24F825
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceBattleRoom_MapScript2_24F861
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceBattleRoom_MapScript2_24FE34
	.byte 0

BattleFrontier_BattlePalaceBattleRoom_MapScript1_24F825: @ 824F825
	setvar VAR_0x8004, 5
	special CallFrontierUtilFunc
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_24F833
	end

BattleFrontier_BattlePalaceBattleRoom_EventScript_24F833:: @ 824F833
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_24F84B
	compare VAR_RESULT, FEMALE
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_24F856
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_24F84B:: @ 824F84B
	setvar VAR_OBJ_GFX_ID_1, EVENT_OBJ_GFX_RIVAL_BRENDAN_NORMAL
	setvar VAR_OBJ_GFX_ID_0, EVENT_OBJ_GFX_RIVAL_BRENDAN_NORMAL
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_24F856:: @ 824F856
	setvar VAR_OBJ_GFX_ID_1, EVENT_OBJ_GFX_RIVAL_MAY_NORMAL
	setvar VAR_OBJ_GFX_ID_0, EVENT_OBJ_GFX_RIVAL_MAY_NORMAL
	return

BattleFrontier_BattlePalaceBattleRoom_MapScript2_24F861: @ 824F861
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_24F86B
	.2byte 0

BattleFrontier_BattlePalaceBattleRoom_EventScript_24F86B:: @ 824F86B
	showobjectat 1, MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	special CallFrontierUtilFunc
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_24F8B5
	applymovement 1, BattleFrontier_BattlePalaceBattleRoom_Movement_24FE9B
	waitmovement 0
	applymovement 3, BattleFrontier_BattlePalaceBattleRoom_Movement_24FEAC
	setvar VAR_TEMP_2, 1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 1
	special CallFrontierUtilFunc
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_24F98A

BattleFrontier_BattlePalaceBattleRoom_EventScript_24F8B5:: @ 824F8B5
	applymovement 1, BattleFrontier_BattlePalaceBattleRoom_Movement_24FE92
	waitmovement 0

BattleFrontier_BattlePalaceBattleRoom_EventScript_24F8BF:: @ 824F8BF
	setvar VAR_0x8004, 3
	special sub_8161F74
	addobject 2
	applymovement 2, BattleFrontier_BattlePalaceBattleRoom_Movement_24FEA1
	waitmovement 0
	setvar VAR_0x8004, 5
	special CallBattlePalaceFunction
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_24FDF7
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_24F911

BattleFrontier_BattlePalaceBattleRoom_EventScript_24F8FA:: @ 824F8FA
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 4
	special CallFrontierUtilFunc
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_24FEBB

BattleFrontier_BattlePalaceBattleRoom_EventScript_24F911:: @ 824F911
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_241EBA
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	special CallFrontierUtilFunc
	addvar VAR_RESULT, 1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	copyvar VAR_0x8006, VAR_RESULT
	special CallFrontierUtilFunc
	switch VAR_RESULT
	case 7, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB28
	applymovement 2, BattleFrontier_BattlePalaceBattleRoom_Movement_24FEA7
	waitmovement 0
	removeobject 2
	applymovement 1, BattleFrontier_BattlePalaceBattleRoom_Movement_24FE99
	applymovement 3, BattleFrontier_BattlePalaceBattleRoom_Movement_24FEAC
	waitmovement 0
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_24FF00, MSGBOX_DEFAULT
	special LoadPlayerParty
	special SavePlayerParty
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	special CallFrontierUtilFunc
	playfanfare MUS_ME_ASA
	waitfanfare
	special HealPlayerParty

BattleFrontier_BattlePalaceBattleRoom_EventScript_24F98A:: @ 824F98A
	setvar VAR_0x8004, 9
	special CallFrontierUtilFunc
	copyvar VAR_TEMP_F, VAR_RESULT
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB61
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	special CallFrontierUtilFunc
	compare VAR_RESULT, 1
	call_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE66
	compare VAR_RESULT, 2
	call_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE6D
	compare VAR_RESULT, 3
	call_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE74
	compare VAR_RESULT, 4
	call_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE7B
	compare VAR_RESULT, 5
	call_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE82
	compare VAR_RESULT, 6
	call_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE89
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_23E8E0
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_24FA42
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB14
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FA78
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FAB4
	case 3, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FAE2
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_24F98A

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FA42:: @ 824FA42
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB14
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FAB4
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FAE2
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_24F98A

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FA78:: @ 824FA78
	message BattleFrontier_BattlePalaceBattleRoom_Text_25009E
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_24F98A
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FAAA
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_24F98A

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FAAA:: @ 824FAAA
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_23E8B4
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_24F98A

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FAB4:: @ 824FAB4
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_250030, MSGBOX_YESNO
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_24F98A
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB3F
	case 127, BattleFrontier_BattlePalaceBattleRoom_EventScript_24F98A

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FAE2:: @ 824FAE2
	message BattleFrontier_BattlePalaceBattleRoom_Text_25005A
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_24F98A
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_24F8FA
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_24F98A

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB14:: @ 824FB14
	applymovement 1, BattleFrontier_BattlePalaceBattleRoom_Movement_24FE97
	applymovement 3, BattleFrontier_BattlePalaceBattleRoom_Movement_24FE97
	closemessage
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_24F8BF

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB28:: @ 824FB28
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 3
	special CallFrontierUtilFunc
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_24FEBB

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB3F:: @ 824FB3F
	message BattleFrontier_BattlePalaceBattleRoom_Text_25007E
	waitmessage
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 2
	special CallBattlePalaceFunction
	playse SE_SAVE
	waitse
	fadescreen 1
	setvar VAR_0x8004, 4
	special CallFrontierUtilFunc
	end

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB61:: @ 824FB61
	compare VAR_TEMP_2, 1
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB79
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_2500DD, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 1

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB79:: @ 824FB79
	message BattleFrontier_BattlePalaceBattleRoom_Text_25014A
	waitmessage
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_23E8E0
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_24FBD0
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FC06
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FA78
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FAB4
	case 3, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FAE2
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB79

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FBD0:: @ 824FBD0
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FC06
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FAB4
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FAE2
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB79

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FC06:: @ 824FC06
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_242170
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_25017C, MSGBOX_DEFAULT
	closemessage
	applymovement 1, BattleFrontier_BattlePalaceBattleRoom_Movement_24FE97
	applymovement 3, BattleFrontier_BattlePalaceBattleRoom_Movement_24FE97
	setobjectxyperm 2, 15, 1
	addobject 2
	hideobjectat 2, MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
	setobjectxy 2, 13, 1
	setobjectxyperm 2, 13, 1
	applymovement 4, BattleFrontier_BattlePalaceBattleRoom_Movement_24FEDF
	applymovement 5, BattleFrontier_BattlePalaceBattleRoom_Movement_24FEE7
	applymovement 2, BattleFrontier_BattlePalaceBattleRoom_Movement_24FEF2
	waitmovement 0
	switch VAR_TEMP_F
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FD3A
	case 3, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FCAA
	case 4, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FD67
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 7
	special CallFrontierUtilFunc
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattlePalaceBattleRoom_EventScript_24FCAA
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_2501C1, MSGBOX_DEFAULT
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 7
	special CallFrontierUtilFunc

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FCAA:: @ 824FCAA
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_2502C4, MSGBOX_DEFAULT
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_24FDF7
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_24FCC7
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_24F8FA

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FCC7:: @ 824FCC7
	setvar VAR_0x8004, 6
	special CallBattlePalaceFunction
	setvar VAR_0x8004, 12
	special CallFrontierUtilFunc
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB28
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_2502FF, MSGBOX_DEFAULT
	applymovement 1, BattleFrontier_BattlePalaceBattleRoom_Movement_24FE99
	applymovement 3, BattleFrontier_BattlePalaceBattleRoom_Movement_24FEAC
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_25036D, MSGBOX_DEFAULT
	playfanfare MUS_ME_SYMBOLGET
	message BattleFrontier_BattlePalaceBattleRoom_Text_2503DC
	waitmessage
	waitfanfare
	setvar VAR_0x8004, 13
	special CallFrontierUtilFunc
	applymovement 2, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement 1, Common_Movement_WalkInPlaceFastestRight
	applymovement 3, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_250412, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB28

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FD3A:: @ 824FD3A
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 7
	special CallFrontierUtilFunc
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattlePalaceBattleRoom_EventScript_24FD67
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_250485, MSGBOX_DEFAULT
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 7
	special CallFrontierUtilFunc

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FD67:: @ 824FD67
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_250572, MSGBOX_DEFAULT
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_24FDF7
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_24FD84
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_24F8FA

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FD84:: @ 824FD84
	setvar VAR_0x8004, 6
	special CallBattlePalaceFunction
	setvar VAR_0x8004, 12
	special CallFrontierUtilFunc
	compare VAR_RESULT, 2
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB28
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_25057E, MSGBOX_DEFAULT
	applymovement 1, BattleFrontier_BattlePalaceBattleRoom_Movement_24FE99
	applymovement 3, BattleFrontier_BattlePalaceBattleRoom_Movement_24FEAC
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_250629, MSGBOX_DEFAULT
	playfanfare MUS_ME_SYMBOLGET
	message BattleFrontier_BattlePalaceBattleRoom_Text_250699
	waitmessage
	waitfanfare
	setvar VAR_0x8004, 13
	special CallFrontierUtilFunc
	applymovement 2, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement 1, Common_Movement_WalkInPlaceFastestRight
	applymovement 3, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_2506C4, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_24FB28

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FDF7:: @ 824FDF7
VerdanturfTown_BattleTentBattleRoom_EventScript_24FDF7:: @ 824FDF7
	closemessage
	setvar VAR_TEMP_2, 0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_BATTLE_PALACE
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	setvar VAR_0x8004, 18
	special CallFrontierUtilFunc
	special HealPlayerParty
	setvar VAR_0x8004, 21
	special CallFrontierUtilFunc
	return

BattleFrontier_BattlePalaceBattleRoom_MapScript2_24FE34: @ 824FE34
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE3E
	.2byte 0

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE3E:: @ 824FE3E
	hideobjectat 1, MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_24F833
	setvar VAR_TEMP_1, 1
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_24FE90
	removeobject 2
	applymovement 4, BattleFrontier_BattlePalaceBattleRoom_Movement_24FE90
	applymovement 5, BattleFrontier_BattlePalaceBattleRoom_Movement_24FE90
	end

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE66:: @ 824FE66
	message BattleFrontier_BattlePalaceBattleRoom_Text_24FF28
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE6D:: @ 824FE6D
	message BattleFrontier_BattlePalaceBattleRoom_Text_24FF54
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE74:: @ 824FE74
	message BattleFrontier_BattlePalaceBattleRoom_Text_24FF80
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE7B:: @ 824FE7B
	message BattleFrontier_BattlePalaceBattleRoom_Text_24FFAC
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE82:: @ 824FE82
	message BattleFrontier_BattlePalaceBattleRoom_Text_24FFD8
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FE89:: @ 824FE89
	message BattleFrontier_BattlePalaceBattleRoom_Text_250004
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_Movement_24FE90: @ 824FE90
	set_invisible
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_24FE92: @ 824FE92
	set_visible
	walk_up
	walk_up
	walk_up
	walk_up

BattleFrontier_BattlePalaceBattleRoom_Movement_24FE97: @ 824FE97
	face_right
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_24FE99: @ 824FE99
	face_up
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_24FE9B: @ 824FE9B
	set_visible
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_24FEA1: @ 824FEA1
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_24FEA7: @ 824FEA7
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_24FEAC: @ 824FEAC
	face_down
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_24FEAE: @ 824FEAE
	set_visible
	walk_slow_down
	walk_slow_down
	face_left
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_24FEB3: @ 824FEB3
	set_visible
	walk_slow_down
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_24FEB6: @ 824FEB6
	walk_slow_down
	walk_slow_down
	walk_slow_down
	face_left
	step_end

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FEBB:: @ 824FEBB
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_24FED5
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_LOBBY, 255, 5, 7
	waitstate
	end

BattleFrontier_BattlePalaceBattleRoom_EventScript_24FED5:: @ 824FED5
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_LOBBY, 255, 19, 7
	waitstate
	end

BattleFrontier_BattlePalaceBattleRoom_Movement_24FEDF: @ 824FEDF
	delay_16
	delay_16
	set_visible
	walk_down
	walk_right
	walk_down
	walk_in_place_fastest_left
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_24FEE7: @ 824FEE7
	set_visible
	walk_fast_down
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_in_place_fastest_left
	delay_16
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_24FEF2: @ 824FEF2
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	set_visible
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	face_left
	step_end

BattleFrontier_BattlePalaceBattleRoom_Text_24FF00: @ 824FF00
VerdanturfTown_BattleTentBattleRoom_Text_24FF00: @ 824FF00
	.string "Excellent…\n"
	.string "Je vais soigner vos POKéMON.$"

BattleFrontier_BattlePalaceBattleRoom_Text_24FF28: @ 824FF28
VerdanturfTown_BattleTentBattleRoom_Text_24FF28: @ 824FF28
	.string "Le deuxième adversaire est prêt.\n"
	.string "Pouvons-nous commencer?$"

BattleFrontier_BattlePalaceBattleRoom_Text_24FF54: @ 824FF54
VerdanturfTown_BattleTentBattleRoom_Text_24FF54: @ 824FF54
	.string "Le troisième adversaire est prêt.\n"
	.string "Pouvons-nous commencer?$"

BattleFrontier_BattlePalaceBattleRoom_Text_24FF80: @ 824FF80
	.string "Le quatrième adversaire est prêt.\n"
	.string "Pouvons-nous commencer?$"

BattleFrontier_BattlePalaceBattleRoom_Text_24FFAC: @ 824FFAC
	.string "Le cinquième adversaire est prêt.\n"
	.string "Pouvons-nous commencer?$"

BattleFrontier_BattlePalaceBattleRoom_Text_24FFD8: @ 824FFD8
	.string "Le sixième adversaire est prêt.\n"
	.string "Pouvons-nous commencer?$"

BattleFrontier_BattlePalaceBattleRoom_Text_250004: @ 8250004
	.string "Le septième adversaire est prêt.\n"
	.string "Pouvons-nous commencer?$"

BattleFrontier_BattlePalaceBattleRoom_Text_250030: @ 8250030
VerdanturfTown_BattleTentBattleRoom_Text_250030: @ 8250030
	.string "Voulez-vous sauvegarder la partie et\n"
	.string "arrêter de jouer?$"

BattleFrontier_BattlePalaceBattleRoom_Text_25005A: @ 825005A
VerdanturfTown_BattleTentBattleRoom_Text_25005A: @ 825005A
	.string "Voulez-vous abandonner votre défi?$"

BattleFrontier_BattlePalaceBattleRoom_Text_25007E: @ 825007E
VerdanturfTown_BattleTentBattleRoom_Text_25007E: @ 825007E
	.string "Sauvegarde en cours…\n"
	.string "Veuillez patienter.$"

BattleFrontier_BattlePalaceBattleRoom_Text_25009E: @ 825009E
	.string "Voulez-vous enregistrer votre dernier\n"
	.string "combat sur votre PASSE ZONE?$"

BattleFrontier_BattlePalaceBattleRoom_Text_2500DD: @ 82500DD
	.string "Et maintenant…\p"
	.string "Vos victoires vous donnent le droit\n"
	.string "d'affronter le CAPT. PALACE…$"

BattleFrontier_BattlePalaceBattleRoom_Text_25014A: @ 825014A
	.string "Le CAPT. PALACE est prêt.\n"
	.string "Pouvons-nous commencer?$"

BattleFrontier_BattlePalaceBattleRoom_Text_25017C: @ 825017C
	.string "Veuillez accueillir comme il se doit\n"
	.string "le CAPT. PALACE, ESTEBAN!$"

BattleFrontier_BattlePalaceBattleRoom_Text_2501C1: @ 82501C1
	.string "ESTEBAN: Je ne fais qu'un avec mes\n"
	.string "POKéMON!\p"
	.string "Mon cœur et celui de mes POKéMON\n"
	.string "battent à l'unisson!\p"
	.string "Dis-moi, DRESSEUR en herbe!\n"
	.string "Crois-tu en tes POKéMON?\p"
	.string "Est-ce que tu crois en eux, quoi\n"
	.string "qu'il arrive?\p"
	.string "La confiance qui te lie à tes POKéMON\n"
	.string "devra être à toute épreuve!$"

BattleFrontier_BattlePalaceBattleRoom_Text_2502C4: @ 82502C4
	.string "Montre-moi les liens qui t'unissent à\n"
	.string "tes POKéMON!$"

BattleFrontier_BattlePalaceBattleRoom_Text_2502FF: @ 82502FF
	.string "ESTEBAN: Ahhhhh!\p"
	.string "Je me suis un peu trop vanté!\n"
	.string "Désolé pour ce petit numéro!\p"
	.string "Allez…\n"
	.string "Donne-moi ce que tu sais!$"

BattleFrontier_BattlePalaceBattleRoom_Text_25036D: @ 825036D
	.string "Un bon DRESSEUR ne doit jamais perdre\n"
	.string "la face…\p"
	.string "Allez, ton PASSE ZONE!\n"
	.string "Et que ça saute!$"

BattleFrontier_BattlePalaceBattleRoom_Text_2503DC: @ 82503DC
	.string "Le SYMBOLE ESPRIT a été ajouté sur le\n"
	.string "PASSE ZONE!$"

BattleFrontier_BattlePalaceBattleRoom_Text_250412: @ 8250412
	.string "ESTEBAN: Tu lis dans tes POKéMON comme\n"
	.string "dans un livre ouvert.\p"
	.string "J'attendrai avec impatience l'instant\n"
	.string "où nous nous reverrons.$"

BattleFrontier_BattlePalaceBattleRoom_Text_250485: @ 8250485
	.string "ESTEBAN: Ahhhhh!!!\n"
	.string "Te voilà?\p"
	.string "Tu as dû développer un lien\n"
	.string "unique avec tes POKéMON.\p"
	.string "Battons-nous!\p"
	.string "Cette fois, je ne vais pas faire le\n"
	.string "malin! Cette fois, je vais gagner!\p"
	.string "On peut commencer?\n"
	.string "Prépare-toi à perdre!$"

BattleFrontier_BattlePalaceBattleRoom_Text_250572: @ 8250572
	.string "… … …\n"
	.string "Ahhhhh!$"

BattleFrontier_BattlePalaceBattleRoom_Text_25057E: @ 825057E
	.string "ESTEBAN: Ce fut une belle\n"
	.string "démonstration! Mes POKéMON, même\l"
	.string "déchaînés, n'ont pas battu les tiens.\p"
	.string "Votre esprit d'équipe est remarquable!\p"
	.string "Allez…\n"
	.string "Tu me donnes ce que tu sais?$"

BattleFrontier_BattlePalaceBattleRoom_Text_250629: @ 8250629
	.string "Un bon DRESSEUR se doit d'être\n"
	.string "respectueux…\p"
	.string "Allez, grouille-toi!\n"
	.string "Sors-moi ton PASSE ZONE!$"

BattleFrontier_BattlePalaceBattleRoom_Text_250699: @ 8250699
	.string "Le SYMBOLE ESPRIT a pris une couleur\n"
	.string "dorée!$"

BattleFrontier_BattlePalaceBattleRoom_Text_2506C4: @ 82506C4
	.string "ESTEBAN: Ah, ah!\p"
	.string "Reviens me voir quand tu veux!\n"
	.string "Nous t'attendrons de pied ferme!$"
