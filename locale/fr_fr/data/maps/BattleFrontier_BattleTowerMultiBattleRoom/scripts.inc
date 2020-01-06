BattleFrontier_BattleTowerMultiBattleRoom_MapScripts:: @ 8243D92
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiBattleRoom_MapScript1_243DA7
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiBattleRoom_MapScript1_243DB0
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiBattleRoom_MapScript2_243E14
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiBattleRoom_MapScript2_243E23
	.byte 0

BattleFrontier_BattleTowerMultiBattleRoom_MapScript1_243DA7: @ 8243DA7
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_RESTORE_PARTY
	special CallBattlePyramidFunction
	end

BattleFrontier_BattleTowerMultiBattleRoom_MapScript1_243DB0: @ 8243DB0
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243DDA
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	setvar VAR_0x8004, 10
	special sub_8161F74
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243DDA:: @ 8243DDA
	setvar VAR_OBJ_GFX_ID_0, EVENT_OBJ_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, EVENT_OBJ_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, EVENT_OBJ_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, EVENT_OBJ_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, EVENT_OBJ_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, EVENT_OBJ_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, EVENT_OBJ_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, EVENT_OBJ_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm 1, 10, 2
	end

BattleFrontier_BattleTowerMultiBattleRoom_MapScript2_243E14: @ 8243E14
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E1E
	.2byte 0

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E1E:: @ 8243E1E
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiBattleRoom_MapScript2_243E23: @ 8243E23
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E41
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E35
	.2byte 0

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E35:: @ 8243E35
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243EB5
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E41:: @ 8243E41
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243E75
	waitmovement 0
	applymovement 1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243E77
	waitmovement 0
	copyobjectxytoperm 1
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiBattleRoom_Text_244056, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243E75: @ 8243E75
	walk_down
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243E77: @ 8243E77
	walk_left
	walk_in_place_fastest_down
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E7A:: @ 8243E7A
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_244094
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E9D
	msgbox BattleFrontier_BattleTowerMultiBattleRoom_Text_24410C, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E9D:: @ 8243E9D
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 1
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_241C03
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243EB5:: @ 8243EB5
	msgbox BattleFrontier_BattleTowerMultiBattleRoom_Text_244149, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243EE4
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 255, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243EE4:: @ 8243EE4
	applymovement 1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F26
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F1A
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243EF6: @ 8243EF6
	applymovement 1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F26
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F1E
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F08: @ 8243F08
	applymovement 1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F26
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F22
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F1A: @ 8243F1A
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F1E: @ 8243F1E
	walk_right
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F22: @ 8243F22
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F26: @ 8243F26
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F29:: @ 8243F29
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36:: @ 8243F36
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FC3
	setvar VAR_0x8004, 11
	setvar VAR_0x8005, 0
	special sub_8161F74
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 11
	setvar VAR_0x8005, 1
	special sub_8161F74
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 11
	setvar VAR_0x8005, 2
	special sub_8161F74
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FC3
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FC3
	setvar VAR_0x8004, 11
	setvar VAR_0x8005, 3
	special sub_8161F74
	waitmessage
	waitbuttonpress
	closemessage
	compare VAR_FACING, DIR_SOUTH
	call_if_ne BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FD4
	compare VAR_FACING, DIR_SOUTH
	call_if_eq BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FDF
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_BATTLE_ROOM, 255, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FC3:: @ 8243FC3
	setvar VAR_0x8004, 11
	setvar VAR_0x8005, 4
	special sub_8161F74
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FD4:: @ 8243FD4
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243FEA
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FDF:: @ 8243FDF
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243FF2
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243FEA: @ 8243FEA
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243FF2: @ 8243FF2
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FFB:: @ 8243FFB
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_244008:: @ 8244008
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_244015:: @ 8244015
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_244022:: @ 8244022
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_24402F:: @ 824402F
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_24403C:: @ 824403C
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_244049:: @ 8244049
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor2ndOpponentSet: @ 8249547
	.string "La deuxième équipe adverse est prête.\n"
	.string "Pouvons-nous commencer?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor3rdOpponentSet: @ 8249578
	.string "La troisième équipe adverse est prête.\n"
	.string "Pouvons-nous commencer?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor4thOpponentSet: @ 82495A9
	.string "La quatrième équipe adverse est prête.\n"
	.string "Pouvons-nous commencer?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor5thOpponentSet: @ 82495DA
	.string "La cinquième équipe adverse est prête.\n"
	.string "Pouvons-nous commencer?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor6thOpponentSet: @ 824960B
	.string "La sixième équipe adverse est prête.\n"
	.string "Pouvons-nous commencer?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor7thOpponentSet: @ 824963C
	.string "La septième équipe adverse est prête.\n"
	.string "Pouvons-nous commencer?$"

@ Unused
BattleFrontier_BattleTowerMultiBattleRoom_Text_2ndOpponentSetNext: @ 824966D
	.string "The 2nd set of opponents is next.\n"
	.string "Do your best!$"

@ Unused
BattleFrontier_BattleTowerMultiBattleRoom_Text_3rdOpponentSetNext: @ 824969D
	.string "The 3rd set of opponents is next.\n"
	.string "Do your best!$"

@ Unused
BattleFrontier_BattleTowerMultiBattleRoom_Text_4thOpponentSetNext: @ 82496CD
	.string "The 4th set of opponents is next.\n"
	.string "Do your best!$"

@ Unused
BattleFrontier_BattleTowerMultiBattleRoom_Text_5thOpponentSetNext: @ 82496FD
	.string "The 5th set of opponents is next.\n"
	.string "Do your best!$"

@ Unused
BattleFrontier_BattleTowerMultiBattleRoom_Text_6thOpponentSetNext: @ 824972D
	.string "The 6th set of opponents is next.\n"
	.string "Do your best!$"

@ Unused
BattleFrontier_BattleTowerMultiBattleRoom_Text_7thOpponentSetNext: @ 824975D
	.string "The 7th set of opponents is next.\n"
	.string "Do your best!$"

gText_LinkStandby3:: @ 824978D
	.string "Connexion...$"

gText_YourPartnerHasRetired:: @ 824979B
	.string "Votre partenaire a arrêté.\p"
	.string "Votre défi dans la SALLE DE\n"
	.string "COMBAT va être annulé.$"
