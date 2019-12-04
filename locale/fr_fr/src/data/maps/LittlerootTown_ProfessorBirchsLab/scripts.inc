LittlerootTown_ProfessorBirchsLab_MapScripts:: @ 81F9C91
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_ProfessorBirchsLab_MapScript1_1F9CA1
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_ProfessorBirchsLab_MapScript2_1F9D06
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_ProfessorBirchsLab_MapScript2_1F9DB9
	.byte 0

LittlerootTown_ProfessorBirchsLab_MapScript1_1F9CA1: @ 81F9CA1
	call Common_EventScript_SetupRivalGfxId
	call ProfBirch_EventScript_UpdateLocation
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_1F9CF7
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_1F9CF3
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9CCD
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9CCD:: @ 81F9CCD
	specialvar VAR_RESULT, HasAllHoennMons
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9CE9
	setobjectmovementtype 3, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectxyperm 3, 5, 10
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9CE9:: @ 81F9CE9
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1F9CF3

LittlerootTown_ProfessorBirchsLab_EventScript_1F9CF3:: @ 81F9CF3
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9CF7:: @ 81F9CF7
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
	setobjectmovementtype 3, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectxyperm 3, 5, 10
	end

LittlerootTown_ProfessorBirchsLab_MapScript2_1F9D06: @ 81F9D06
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D40
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D45
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D45
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D71
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D71
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D75
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D75
	.2byte 0

LittlerootTown_ProfessorBirchsLab_EventScript_1F9D40:: @ 81F9D40
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9D45:: @ 81F9D45
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	addobject 2
	addobject 3
	turnobject 3, DIR_NORTH
	setobjectxy 3, 5, 5
	turnobject 2, DIR_SOUTH
	setobjectxy 2, 6, 4
	turnobject 1, DIR_EAST
	setobjectxy 1, 10, 10
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9D71:: @ 81F9D71
	addobject 3
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9D75:: @ 81F9D75
	addobject 4
	addobject 5
	addobject 6
	addobject 3
	turnobject 4, DIR_SOUTH
	setobjectxy 4, 8, 4
	turnobject 5, DIR_SOUTH
	setobjectxy 5, 9, 4
	turnobject 6, DIR_SOUTH
	setobjectxy 6, 10, 4
	turnobject 2, DIR_SOUTH
	setobjectxy 2, 6, 4
	turnobject 3, DIR_EAST
	setobjectxy 3, 5, 5
	end

LittlerootTown_ProfessorBirchsLab_MapScript2_1F9DB9: @ 81F9DB9
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_1F9DDB
	map_script_2 VAR_BIRCH_LAB_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_1F9E67
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_1F9E80
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_1F9F62
	.2byte 0

LittlerootTown_ProfessorBirchsLab_EventScript_1F9DDB:: @ 81F9DDB
	lockall
	bufferleadmonspeciesname 0
	message LittlerootTown_ProfessorBirchsLab_Text_1FA74D
	waitmessage
	playfanfare MUS_FANFA4
	waitfanfare
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FA8B1, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9E07
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9E17
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9E07:: @ 81F9E07
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1F9E17
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9E17:: @ 81F9E17
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FA8F6, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9E36
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9E48
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9E36:: @ 81F9E36
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FA9D5, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_ROUTE_101_BOY
	setvar VAR_BIRCH_LAB_STATE, 3
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9E48:: @ 81F9E48
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAA35, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9E36
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9E48
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9E67:: @ 81F9E67
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_1F9E78
	waitmovement 0
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA2F8
	end

LittlerootTown_ProfessorBirchsLab_Movement_1F9E78: @ 81F9E78
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9E80:: @ 81F9E80
	lockall
	delay 30
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB16D, MSGBOX_DEFAULT
	closemessage
	applymovement 2, LittlerootTown_ProfessorBirchsLab_Movement_1F9F46
	waitmovement 0
	delay 20
	playse SE_TK_KASYA
	delay 10
	playse SE_TK_KASYA
	delay 10
	playse SE_TK_KASYA
	delay 10
	playse SE_TK_KASYA
	delay 20
	applymovement 3, Common_Movement_WalkInPlaceFastestRight
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9F32
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9F3C
	playse SE_PC_ON
	waitse
	delay 20
	applymovement 2, LittlerootTown_ProfessorBirchsLab_Movement_1F9F58
	waitmovement 0
	applymovement 3, Common_Movement_WalkInPlaceFastestUp
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB419, MSGBOX_DEFAULT
	playfanfare MUS_FANFA4
	message LittlerootTown_ProfessorBirchsLab_Text_1FB436
	waitmessage
	waitfanfare
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB466, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
	setvar VAR_SCOTT_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_NATIONAL_DEX
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9F32:: @ 81F9F32
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB30F, MSGBOX_DEFAULT
	closemessage
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1F9F3C:: @ 81F9F3C
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB38E, MSGBOX_DEFAULT
	closemessage
	return

LittlerootTown_ProfessorBirchsLab_Movement_1F9F46: @ 81F9F46
	walk_left
	walk_in_place_fastest_down
	delay_16
	delay_16
	walk_right
	walk_in_place_fastest_down
	delay_16
	delay_16
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

LittlerootTown_ProfessorBirchsLab_Movement_1F9F58: @ 81F9F58
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_in_place_fastest_down
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9F62:: @ 81F9F62
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_1F9F7C
	waitmovement 0
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB5F9, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_Movement_1F9F7C: @ 81F9F7C
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9F84:: @ 81F9F84
	lock
	faceplayer
	compare VAR_BIRCH_LAB_STATE, 3
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_1F9FB1
	goto_if_set FLAG_BIRCH_AIDE_MET, LittlerootTown_ProfessorBirchsLab_EventScript_1F9FA7
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FA4E2, MSGBOX_DEFAULT
	setflag FLAG_BIRCH_AIDE_MET
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9FA7:: @ 81F9FA7
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FA641, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9FB1:: @ 81F9FB1
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FA6CE, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9FBB:: @ 81F9FBB
	release
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_1FA057
	applymovement 2, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	showmonpic SPECIES_CYNDAQUIL, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB7F6, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA061
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA06C
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9FEF:: @ 81F9FEF
	release
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_1FA057
	applymovement 2, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	showmonpic SPECIES_TOTODILE, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB869, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA061
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA10D
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA023:: @ 81FA023
	release
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_1FA057
	applymovement 2, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	showmonpic SPECIES_CHIKORITA, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB8E0, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA061
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA1AE
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA057:: @ 81FA057
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FBAF8, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA061:: @ 81FA061
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB959, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA06C:: @ 81FA06C
	bufferspeciesname 0, SPECIES_CYNDAQUIL
	setvar VAR_TEMP_1, SPECIES_CYNDAQUIL
	givemon SPECIES_CYNDAQUIL, 5, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA0A1
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA0CC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA0A1:: @ 81FA0A1
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F
	removeobject 4
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA0FD
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA0FD
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA0CC:: @ 81FA0CC
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F
	removeobject 4
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA0F2
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA0F2
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA0F2:: @ 81FA0F2
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA0FD
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA0FD:: @ 81FA0FD
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FBA2C, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA10D:: @ 81FA10D
	bufferspeciesname 0, SPECIES_TOTODILE
	setvar VAR_TEMP_1, SPECIES_TOTODILE
	givemon SPECIES_TOTODILE, 5, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA142
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA16D
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA142:: @ 81FA142
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F
	removeobject 5
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA19E
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA19E
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA16D:: @ 81FA16D
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F
	removeobject 5
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA193
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA193
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA193:: @ 81FA193
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA19E
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA19E:: @ 81FA19E
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FBA2C, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA1AE:: @ 81FA1AE
	bufferspeciesname 0, SPECIES_CHIKORITA
	setvar VAR_TEMP_1, SPECIES_CHIKORITA
	givemon SPECIES_CHIKORITA, 5, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA1E3
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA20E
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA1E3:: @ 81FA1E3
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F
	removeobject 6
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA23F
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA23F
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA20E:: @ 81FA20E
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F
	removeobject 6
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA234
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA234
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA234:: @ 81FA234
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA23F
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA23F:: @ 81FA23F
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FBA2C, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F:: @ 81FA24F
	playfanfare MUS_FANFA4
	message LittlerootTown_ProfessorBirchsLab_Text_1FB9D7
	waitmessage
	waitfanfare
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA25A:: @ 81FA25A
	lock
	faceplayer
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA28A
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA294
	goto_if_unset FLAG_HAS_MATCH_CALL, LittlerootTown_ProfessorBirchsLab_EventScript_1FA29E
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA29E
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA28A:: @ 81FA28A
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB787, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA294:: @ 81FA294
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB466, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA29E:: @ 81FA29E
	goto_if_unset FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380, ProfBirch_EventScript_RatePokedexOrRegister
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
	goto_if_eq ProfBirch_EventScript_RatePokedexOrRegister
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	goto_if_ge ProfBirch_EventScript_RatePokedexOrRegister
	compare VAR_BIRCH_LAB_STATE, 5
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA3C4
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAA74, MSGBOX_DEFAULT
	release
	end

EventScript_RegisterProfBirch:: @ 81FA2D2
	msgbox Route101_Text_2B5F52, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox Route101_Text_2B603A, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	setvar VAR_REGISTER_BIRCH_STATE, 2
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA2F8:: @ 81FA2F8
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAB22, MSGBOX_DEFAULT
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA3AC
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAC4B, MSGBOX_DEFAULT
	closemessage
	applymovement 3, LittlerootTown_ProfessorBirchsLab_Movement_1FA3E0
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA352
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA37F
	setvar VAR_BIRCH_LAB_STATE, 5
	setflag FLAG_ADVENTURE_STARTED
	setvar VAR_OLDALE_TOWN_STATE, 1
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
	setvar VAR_LITTLEROOT_TOWN_STATE, 3
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA352:: @ 81FA352
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FADD7, MSGBOX_DEFAULT
	giveitem_std ITEM_POKE_BALL, 5
	compare VAR_RESULT, 0
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA3CE
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAE40, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA37F:: @ 81FA37F
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAF3F, MSGBOX_DEFAULT
	giveitem_std ITEM_POKE_BALL, 5
	compare VAR_RESULT, 0
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA3D7
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAF8E, MSGBOX_DEFAULT
	setvar VAR_RESULT, 1
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA3AC:: @ 81FA3AC
	playfanfare MUS_FANFA4
	message LittlerootTown_ProfessorBirchsLab_Text_1FAC32
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special sub_81AFDA0
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA3C4:: @ 81FA3C4
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAD6F, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA3CE:: @ 81FA3CE
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAEF3, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA3D7:: @ 81FA3D7
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB05D, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_Movement_1FA3E0: @ 81FA3E0
	walk_down
	walk_in_place_fastest_left
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA3E3:: @ 81FA3E3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB0A2, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA3EC:: @ 81FA3EC
	lock
	faceplayer
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA43A
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_1FA465
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_1FA490
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA428
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA431
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA428:: @ 81FA428
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAF08, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA431:: @ 81FA431
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB073, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA43A:: @ 81FA43A
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA453
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA45C
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA453:: @ 81FA453
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FBB68, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA45C:: @ 81FA45C
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FBC2D, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA465:: @ 81FA465
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA47E
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA487
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA47E:: @ 81FA47E
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FBC8D, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA487:: @ 81FA487
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FBCD2, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA490:: @ 81FA490
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA4A9
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA4B2
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA4A9:: @ 81FA4A9
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB528, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA4B2:: @ 81FA4B2
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB58A, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_1FA4BB:: @ 81FA4BB
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB0E7, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA4C4:: @ 81FA4C4
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB124, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA4CD:: @ 81FA4CD
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB148, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA4D6:: @ 81FA4D6
	lockall
	pokenavcall LittlerootTown_ProfessorBirchsLab_Text_1FBD1A
	waitmessage
	clearflag FLAG_SCOTT_CALL_NATIONAL_DEX
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_Text_1FA4E2: @ 81FA4E2
	.string "Hein? Le PROF. SEKO?\p"
	.string "Le PROFESSEUR est sur le terrain.\n"
	.string "C'est-à-dire qu'il n'est pas ici.\p"
	.string "Laisse-moi t'expliquer ce que\n"
	.string "signifie être sur le terrain.\p"
	.string "Il s'agit de réaliser nos études dans un\n"
	.string "environnement naturel, en plaine ou en\l"
	.string "montagne, plutôt qu'en laboratoire.\p"
	.string "Le PROFESSEUR n'est pas du genre à\n"
	.string "rester derrière un bureau. Il préfère\l"
	.string "sortir et faire ses expériences plutôt\l"
	.string "que de rester ici à lire des livres.$"

LittlerootTown_ProfessorBirchsLab_Text_1FA641: @ 81FA641
	.string "Le PROFESSEUR n'est pas du genre à\n"
	.string "rester derrière un bureau. Il préfère\l"
	.string "sortir et faire ses expériences plutôt\l"
	.string "que de rester ici à lire des livres.$"

LittlerootTown_ProfessorBirchsLab_Text_1FA6CE: @ 81FA6CE
	.string "Le PROF. SEKO étudie l'habitat et la\n"
	.string "répartition géographique des POKéMON.\p"
	.string "Le PROFESSEUR aime aussi se faire aider\n"
	.string"par {RIVAL}. Ils s'aiment beaucoup.$"

LittlerootTown_ProfessorBirchsLab_Text_1FA74D: @ 81FA74D
	.string "PROF. SEKO: Alors, {PLAYER}{KUN}.\p"
	.string "Ton père m'a beaucoup parlé de toi.\p"
	.string "Il m'a dit que tu n'avais pas encore\n"
	.string "de POKéMON à toi.\p"
	.string "Mais tu as fait preuve d'un aplomb\n"
	.string "formidable pendant ce dernier combat!\p"
	.string "Je suppose que le sang de ton père\n"
	.string "coule dans tes veines, après tout!\p"
	.string "Je sais ce que je vais faire. Pour te\n"
	.string "remercier, je vais te donner le POKéMON\l"
	.string "que tu as utilisé tout à l'heure.\p"
	.string "{PLAYER} reçoit {STR_VAR_1}!$"

LittlerootTown_ProfessorBirchsLab_Text_1FA8B1: @ 81FA8B1
	.string "PROF. SEKO: Si tu veux, tu peux\n"
	.string "donner un surnom à ton {STR_VAR_1}?$"

LittlerootTown_ProfessorBirchsLab_Text_1FA8F6: @ 81FA8F6
	.string "PROF. SEKO: Si tu entraînes ton\n"
	.string "POKéMON et que tu gagnes de\l"
	.string "l'expérience, tu feras un bon DRESSEUR.\p"
	.string "{RIVAL} étudie aussi les POKéMON\n"
	.string "en m'aidant.\p"
	.string "{PLAYER}{KUN}, ce serait une bonne idée\n"
	.string "d'aller voir {RIVAL}. Qu'en penses-tu?$"

LittlerootTown_ProfessorBirchsLab_Text_1FA9D5: @ 81FA9D5
	.string "PROF. SEKO: Super!\n"
	.string "Ça fera plaisir à {RIVAL}.\p"
	.string "Demande-lui de t'apprendre en\n"
	.string "quoi consiste la vie de DRESSEUR.$"

LittlerootTown_ProfessorBirchsLab_Text_1FAA35: @ 81FAA35
	.string "PROF. SEKO: Oh, je t'en prie.\n"
	.string "Tu devrais y aller.$"

LittlerootTown_ProfessorBirchsLab_Text_1FAA74: @ 81FAA74
	.string "PROF. SEKO: Où est {RIVAL}?\n"
	.string "A la maison, je pense.\p"
	.string "Ou alors quelque part dans les herbes\n"
	.string "hautes à chercher des POKéMON…\p"
	.string "Si tes POKéMON sont fatigués, tu\n"
	.string "peux aller te reposer chez toi.$"

LittlerootTown_ProfessorBirchsLab_Text_1FAB22: @ 81FAB22
	.string "PROF. SEKO: Oh, bonjour, {PLAYER}{KUN}!\p"
	.string "Il paraît que tu as battu {RIVAL}.\n"
	.string "Belle performance! Tu as remporté ton\l"
	.string "premier combat contre une DRESSEUR\l"
	.string "averti!\p"
	.string "{RIVAL} m'aide dans mes études depuis\n"
	.string "bien longtemps.\p"
	.string "{RIVAL} a déjà de l'expérience comme\n"
	.string "DRESSEUR.\p"
	.string "Tiens, {PLAYER}{KUN}, j'ai commandé ça pour\n"
	.string "mes recherches, mais je crois que ce\l"
	.string "POKéDEX te sera plus utile qu'à moi.$"

LittlerootTown_ProfessorBirchsLab_Text_1FAC32: @ 81FAC32
	.string "{PLAYER} reçoit le POKéDEX!$"

LittlerootTown_ProfessorBirchsLab_Text_1FAC4B: @ 81FAC4B
	.string "PROF. SEKO: Le POKéDEX est un outil\n"
	.string "de haute technologie qui enregistre\l"
	.string "automatiquement les informations sur\l"
	.string "les POKéMON rencontrés ou attrapés.\p"
	.string "{RIVAL}, emmène le sien partout.\p"
	.string "A chaque fois qu'un nouveau POKéMON\n"
	.string "est enregistré dans son POKéDEX,\l"
	.string "{RIVAL} vient me chercher sur le\l"
	.string "terrain pour me le montrer.$"

LittlerootTown_ProfessorBirchsLab_Text_1FAD6F: @ 81FAD6F
	.string "PROF. SEKO: Tu vas découvrir\n"
	.string "de nombreux POKéMON!\p"
	.string "Arrg, je crois que je vais retourner sur\n"
	.string "le terrain. Ça me démange!$"

LittlerootTown_ProfessorBirchsLab_Text_1FADD7: @ 81FADD7
	.string "FLORA: Oh, c'est super, {PLAYER}{KUN}!\n"
	.string "Toi aussi, tu as un POKéDEX!\p"
	.string "C'est génial! Tout comme moi!\n"
	.string "Tiens, j'ai quelque chose pour toi!$"

LittlerootTown_ProfessorBirchsLab_Text_1FAE40: @ 81FAE40
	.string "FLORA: Tu verras, c'est marrant\n"
	.string "d'attraper plein de POKéMON!\p"
	.string "Je vais aller explorer un peu la région\n"
	.string "parce que je veux d'autres POKéMON.\p"
	.string "Si je trouve des POKéMON mignons,\n"
	.string "je les attraperai avec des POKé BALLS!$"

LittlerootTown_ProfessorBirchsLab_Text_1FAEF3: @ 81FAEF3
	.string "Oh? Ton SAC est plein.$"

LittlerootTown_ProfessorBirchsLab_Text_1FAF08: @ 81FAF08
	.string "FLORA: Je me demande où je vais aller\n"
	.string "chercher de nouveaux POKéMON!$"

LittlerootTown_ProfessorBirchsLab_Text_1FAF3F: @ 81FAF3F
	.string "BRICE: Hé…\n"
	.string "Alors, toi aussi, tu as un POKéDEX.\p"
	.string "Dans ce cas, tiens.\n"
	.string "Je vais te donner ça.$"

LittlerootTown_ProfessorBirchsLab_Text_1FAF8E: @ 81FAF8E
	.string "BRICE: Tu sais, c'est super rigolo\n"
	.string "d'avoir plein de POKéMON.\p"
	.string "Je vais aller explorer un peu la région\n"
	.string "parce que je veux d'autres POKéMON.\p"
	.string "Si je trouve de chouettes POKéMON,\n"
	.string "je les attraperai avec des POKé BALLS.$"

LittlerootTown_ProfessorBirchsLab_Text_1FB05D: @ 81FB05D
	.string "Hé, ton SAC est plein.$"

LittlerootTown_ProfessorBirchsLab_Text_1FB073: @ 81FB073
	.string "BRICE: Où est-ce que je vais aller\n"
	.string "chercher des POKéMON, maintenant?$"

LittlerootTown_ProfessorBirchsLab_Text_1FB0A2: @ 81FB0A2
	.string "Cette machine a l'air compliquée. Le\n"
	.string "PROF. doit l'utiliser pour ses études.$"

LittlerootTown_ProfessorBirchsLab_Text_1FB0E7: @ 81FB0E7
	.string "C'est un PC utilisé pour la recherche.\n"
	.string "Mieux vaut éviter de l'abîmer.$"

LittlerootTown_ProfessorBirchsLab_Text_1FB124: @ 81FB124
	.string "Il y a plein de livres sur les POKéMON.$"

LittlerootTown_ProfessorBirchsLab_Text_1FB148: @ 81FB148
	.string "C'est un livre difficile à lire.$"

LittlerootTown_ProfessorBirchsLab_Text_1FB16D: @ 81FB16D
	.string "PROF. SEKO: Maintenant…\p"
	.string "{PLAYER}{KUN} et {RIVAL}, vous m'avez aidé\n"
	.string "dans mon étude des POKéMON.\p"
	.string "Votre aide a permis de faire des\n"
	.string "découvertes.\p"
	.string "Il semble que dans la région de HOENN,\n"
	.string "il y a des POKéMON provenant d'autres\l"
	.string "régions.\p"
	.string "Cela montre à quel point la région de\n"
	.string "HOENN a une nature riche et variée.\p"
	.string "C'est pour cela qu'il est nécessaire\n"
	.string "que je passe votre POKéDEX en\l"
	.string "Mode NATIONAL.\p"
	.string "Laissez-moi voir vos POKéDEX.$"

LittlerootTown_ProfessorBirchsLab_Text_1FB30F: @ 81FB30F
	.string "FLORA: Hi, hi, hi!\p"
	.string "Super, mon POKéDEX aussi a été\n"
	.string "mis à jour!\p"
	.string "C'est grâce à toi {PLAYER}{KUN}!\n"
	.string "Tu as attrapé plein de POKéMON!$"

LittlerootTown_ProfessorBirchsLab_Text_1FB38E: @ 81FB38E
	.string "BRICE: J'ai traversé la région de HOENN\n"
	.string "à la recherche de POKéMON.\p"
	.string "C'est grâce à moi si tu as le\n"
	.string "Mode NATIONAL du POKéDEX.\p"
	.string "T'as du bol, {PLAYER}!$"

LittlerootTown_ProfessorBirchsLab_Text_1FB419: @ 81FB419
	.string "PROF. SEKO: Terminé!$"

LittlerootTown_ProfessorBirchsLab_Text_1FB436: @ 81FB436
	.string "Le POKéDEX de {PLAYER} est passé\n"
	.string "en Mode NATIONAL!$"

LittlerootTown_ProfessorBirchsLab_Text_1FB466: @ 81FB466
	.string "PROF. SEKO: Ecoute-moi. Tu as le titre.\n"
	.string "de MAITRE de la LIGUE, mais ton périple\l"
	.string "n'en est pas pour autant terminé.\p"
	.string "Le chemin qui mène aux POKéMON est\n"
	.string "infini.\p"
	.string "Il y aura toujours un coin d'herbe verte\n"
	.string "qui t'attendra quelque part!$"

LittlerootTown_ProfessorBirchsLab_Text_1FB528: @ 81FB528
	.string "FLORA: Je crois que je vais arrêter\n"
	.string "le terrain pendant un temps.\p"
	.string "Je vais rester ici pour aider un peu\n"
	.string "mon père.$"

LittlerootTown_ProfessorBirchsLab_Text_1FB58A: @ 81FB58A
	.string "BRICE: J'arrête momentanément\n"
	.string "les sorties sur le terrain.\p"
	.string "Je vais rester ici pour aider un peu\n"
	.string "mon père.$"

LittlerootTown_ProfessorBirchsLab_Text_1FB5F9: @ 81FB5F9
	.string "PROF. SEKO: Oh, {PLAYER}{KUN}!\n"
	.string "Je vais jeter un œil à ton POKéDEX.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Oui, il n'y a pas de doute.\p"
	.string "Tu as vraiment rempli le POKéDEX de la\n"
	.string "région de HOENN.\p"
	.string "Je dois dire que c'est absolument\n"
	.string "stupéfiant.\p"
	.string "J'aimerais t'offrir quelque chose.\p"
	.string "J'ai envie de récompenser le formidable\n"
	.string "travail que tu as accompli.\p"
	.string "Je veux te donner un POKéMON rare qu'on\n"
	.string "ne trouve pas dans notre région!\p"
	.string "Tu peux choisir entre ces trois\n"
	.string "POKéMON!$"

LittlerootTown_ProfessorBirchsLab_Text_1FB787: @ 81FB787
	.string "PROF. SEKO: Ce sont des POKéMON rares\n"
	.string "provenant d'une autre région!\p"
	.string "Tu peux choisir entre ces trois\n"
	.string "POKéMON!$"

LittlerootTown_ProfessorBirchsLab_Text_1FB7F6: @ 81FB7F6
	.string "PROF. SEKO: Le POKéMON FEU\n"
	.string "HERICENDRE t'intéresse?\p"
	.string "Tu as l'œil, toi!\p"
	.string "Tu choisis donc un HERICENDRE?$"

LittlerootTown_ProfessorBirchsLab_Text_1FB869: @ 81FB869
	.string "PROF. SEKO: Tu veux le POKéMON EAU\n"
	.string "KAIMINUS?\p"
	.string "Tu sais reconnaître les bons POKéMON.\p"
	.string "Le KAIMINUS, alors?$"

LittlerootTown_ProfessorBirchsLab_Text_1FB8E0: @ 81FB8E0
	.string "PROF. SEKO: Tu veux le POKéMON PLANTE\n"
	.string "GERMIGNON?\p"
	.string "Décidément, tu sais ce que tu fais!\p"
	.string "Tu prends le GERMIGNON, alors?$"

LittlerootTown_ProfessorBirchsLab_Text_1FB959: @ 81FB959
	.string "PROF. SEKO: Réfléchis bien avant de\n"
	.string "prendre une décision.\p"
	.string "Ce sont des POKéMON dont la valeur\n"
	.string "est inestimable.$"

LittlerootTown_ProfessorBirchsLab_Text_1FB9A8: @ 81FB9A8
	.string "PROF. SEKO: Je vois!\n"
	.string "Tu as pris un bon POKéMON!$"

LittlerootTown_ProfessorBirchsLab_Text_1FB9D7: @ 81FB9D7
	.string "{PLAYER} obtient {STR_VAR_1}\n"
	.string "du PROF. SEKO.$"

LittlerootTown_ProfessorBirchsLab_Text_1FB9FC: @ 81FB9FC
	.string "Tu veux donner un surnom au\n"
	.string "{STR_VAR_1} que tu as reçu?$"

LittlerootTown_ProfessorBirchsLab_Text_1FBA2C: @ 81FBA2C
	.string "PROF. SEKO: Ecoute-moi, {PLAYER}{KUN}.\n"
	.string "Tu as rempli le POKéDEX de HOENN,\l"
	.string "mais ton périple n'est pas terminé.\p"
	.string "Le chemin qui mène aux POKéMON\n"
	.string "est infini.\p"
	.string "Il y aura toujours un coin d'herbe verte\n"
	.string "qui t'attendra quelque part!$"

LittlerootTown_ProfessorBirchsLab_Text_1FBAF8: @ 81FBAF8
	.string "Tu as obtenu le POKéMON promis.\n"
	.string "Il est temps de partir.$"

LittlerootTown_ProfessorBirchsLab_Text_1FBB3A: @ 81FBB3A
	.string "Oh, tu n'as plus de place pour\n"
	.string "ce POKéMON.$"

LittlerootTown_ProfessorBirchsLab_Text_1FBB68: @ 81FBB68
	.string "FLORA: {PLAYER}{KUN}, maintenant…\n"
	.string "Qu'est-ce que tu vas faire?\p"
	.string "vas continuer les combats pour\n"
	.string "affûter ta technique?\p"
	.string "Ou est-ce que tu vas essayer de\n"
	.string "remplir le POKéDEX NATIONAL?\p"
	.string "Moi je reste ici pour aider mon père.$"

LittlerootTown_ProfessorBirchsLab_Text_1FBC2D: @ 81FBC2D
	.string "BRICE: Plutôt que de trouver de\n"
	.string "nouveaux POKéMON, je préfère élever\l"
	.string "celui que j'ai, lentement mais sûrement.$"

LittlerootTown_ProfessorBirchsLab_Text_1FBC8D: @ 81FBC8D
	.string "FLORA: Salut, {PLAYER}{KUN}!\n"
	.string "Tu es allé à la ZONE DE COMBAT?$"

LittlerootTown_ProfessorBirchsLab_Text_1FBCD2: @ 81FBCD2
	.string "BRICE: Tiens, {PLAYER}!\n"
	.string "Tu es allée à la ZONE DE COMBAT?$"

LittlerootTown_ProfessorBirchsLab_Text_1FBD1A: @ 81FBD1A
	.string "… … … … … …\n"
	.string "… … … … … Bip!\p"
	.string "SCOTT: Bonjour, bonjour, {PLAYER}!\n"
	.string "C'est moi, SCOTT.\p"
	.string "Je suis à bord du MARINA. J'aime\n"
	.string "sentir le vent frais du large!\p"
	.string "Dis-moi…\p"
	.string "J'aimerais t'inviter quelque part.\p"
	.string "ça t'intéresse, prends le ferry à\n"
	.string "POIVRESSEL ou NENUCRIQUE.\p"
	.string "Je t'en dirai plus quand tu seras\n"
	.string "là-bas! J'espère t'y voir bientôt!\p"
	.string "… … … … … …\n"
	.string "… … … … … Clic!$"
