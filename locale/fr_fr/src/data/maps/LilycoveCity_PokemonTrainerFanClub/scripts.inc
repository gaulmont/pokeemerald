LilycoveCity_PokemonTrainerFanClub_MapScripts:: @ 821C785
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_PokemonTrainerFanClub_MapScript2_21C790
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_PokemonTrainerFanClub_OnTransition
	.byte 0

LilycoveCity_PokemonTrainerFanClub_MapScript2_21C790: @ 821C790
	map_script_2 VAR_LILYCOVE_FAN_CLUB_STATE, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_21C79A
	.2byte 0

LilycoveCity_PokemonTrainerFanClub_EventScript_21C79A:: @ 821C79A
	lockall
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21CF00, MSGBOX_DEFAULT
	applymovement 4, LilycoveCity_PokemonTrainerFanClub_Movement_21C7FD
	applymovement 2, LilycoveCity_PokemonTrainerFanClub_Movement_21C7F5
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21CF12, MSGBOX_DEFAULT
	applymovement 4, LilycoveCity_PokemonTrainerFanClub_Movement_21C804
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	applymovement 4, LilycoveCity_PokemonTrainerFanClub_Movement_21C807
	waitmovement 0
	setvar VAR_LILYCOVE_FAN_CLUB_STATE, 2
	releaseall
	end

LilycoveCity_PokemonTrainerFanClub_Movement_21C7F5: @ 821C7F5
	delay_8
	walk_in_place_fastest_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

LilycoveCity_PokemonTrainerFanClub_Movement_21C7FD: @ 821C7FD
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_down
	step_end

LilycoveCity_PokemonTrainerFanClub_Movement_21C804: @ 821C804
	walk_down
	walk_in_place_fastest_right
	step_end

LilycoveCity_PokemonTrainerFanClub_Movement_21C807: @ 821C807
	jump_in_place_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_in_place_fastest_down
	step_end

LilycoveCity_PokemonTrainerFanClub_OnTransition: @ 821C80D
	call LilycoveCity_PokemonTrainerFanClub_EventScript_21C8DA
	compare VAR_LILYCOVE_FAN_CLUB_STATE, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21C9F8
	compare VAR_LILYCOVE_FAN_CLUB_STATE, 2
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21C829
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21C829:: @ 821C829
	special UpdateMovedLilycoveFanClubMembers
	call LilycoveCity_PokemonTrainerFanClub_EventScript_21C8F5
	setvar VAR_0x8004, 8
	specialvar VAR_RESULT, ShouldMoveLilycoveFanClubMember
	compare VAR_RESULT, 0
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21C9B8
	setvar VAR_0x8004, 9
	specialvar VAR_RESULT, ShouldMoveLilycoveFanClubMember
	compare VAR_RESULT, 0
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21C9C0
	setvar VAR_0x8004, 10
	specialvar VAR_RESULT, ShouldMoveLilycoveFanClubMember
	compare VAR_RESULT, 0
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21C9C8
	setvar VAR_0x8004, 11
	specialvar VAR_RESULT, ShouldMoveLilycoveFanClubMember
	compare VAR_RESULT, 0
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21C9D0
	setvar VAR_0x8004, 12
	specialvar VAR_RESULT, ShouldMoveLilycoveFanClubMember
	compare VAR_RESULT, 0
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21C9D8
	setvar VAR_0x8004, 13
	specialvar VAR_RESULT, ShouldMoveLilycoveFanClubMember
	compare VAR_RESULT, 0
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21C9E0
	setvar VAR_0x8004, 14
	specialvar VAR_RESULT, ShouldMoveLilycoveFanClubMember
	compare VAR_RESULT, 0
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21C9E8
	setvar VAR_0x8004, 15
	specialvar VAR_RESULT, ShouldMoveLilycoveFanClubMember
	compare VAR_RESULT, 0
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21C9F0
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21C8DA:: @ 821C8DA
	specialvar VAR_RESULT, sub_80EE7C0
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21C8F1
	clearflag FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER
	clearflag FLAG_FAN_CLUB_STRENGTH_SHARED
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_21C8F1:: @ 821C8F1
	setflag FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_21C8F5:: @ 821C8F5
	setvar VAR_0x8005, 8
	setvar VAR_0x8004, 8
	specialvar VAR_RESULT, ShouldMoveLilycoveFanClubMember
	compare VAR_RESULT, 0
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21C9AE
	setvar VAR_0x8004, 9
	specialvar VAR_RESULT, ShouldMoveLilycoveFanClubMember
	compare VAR_RESULT, 0
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21C9AE
	setvar VAR_0x8004, 10
	specialvar VAR_RESULT, ShouldMoveLilycoveFanClubMember
	compare VAR_RESULT, 0
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21C9AE
	setvar VAR_0x8004, 11
	specialvar VAR_RESULT, ShouldMoveLilycoveFanClubMember
	compare VAR_RESULT, 0
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21C9AE
	setvar VAR_0x8004, 12
	specialvar VAR_RESULT, ShouldMoveLilycoveFanClubMember
	compare VAR_RESULT, 0
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21C9AE
	setvar VAR_0x8004, 13
	specialvar VAR_RESULT, ShouldMoveLilycoveFanClubMember
	compare VAR_RESULT, 0
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21C9AE
	setvar VAR_0x8004, 14
	specialvar VAR_RESULT, ShouldMoveLilycoveFanClubMember
	compare VAR_RESULT, 0
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21C9AE
	setvar VAR_0x8004, 15
	specialvar VAR_RESULT, ShouldMoveLilycoveFanClubMember
	compare VAR_RESULT, 0
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21C9AE
	compare VAR_0x8005, 5
	goto_if_ge LilycoveCity_PokemonTrainerFanClub_EventScript_21C9B4
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_21C9AE:: @ 821C9AE
	subvar VAR_0x8005, 1
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_21C9B4:: @ 821C9B4
	special sub_80EE72C
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_21C9B8:: @ 821C9B8
	setobjectxyperm 1, 7, 5
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_21C9C0:: @ 821C9C0
	setobjectxyperm 3, 3, 4
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_21C9C8:: @ 821C9C8
	setobjectxyperm 4, 7, 2
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_21C9D0:: @ 821C9D0
	setobjectxyperm 5, 5, 5
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_21C9D8:: @ 821C9D8
	setobjectxyperm 6, 5, 2
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_21C9E0:: @ 821C9E0
	setobjectxyperm 2, 8, 4
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_21C9E8:: @ 821C9E8
	setobjectxyperm 7, 3, 3
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_21C9F0:: @ 821C9F0
	setobjectxyperm 8, 8, 3
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_21C9F8:: @ 821C9F8
	call LilycoveCity_PokemonTrainerFanClub_EventScript_21C8F5
	call LilycoveCity_PokemonTrainerFanClub_EventScript_21C9C0
	call LilycoveCity_PokemonTrainerFanClub_EventScript_21C9D0
	call LilycoveCity_PokemonTrainerFanClub_EventScript_21C9D8
	call LilycoveCity_PokemonTrainerFanClub_EventScript_21C9E8
	call LilycoveCity_PokemonTrainerFanClub_EventScript_21C9F0
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CA17:: @ 821CA17
	lock
	faceplayer
	setvar VAR_0x8004, 13
	special BufferStreakTrainerText
	compare VAR_LILYCOVE_FAN_CLUB_STATE, 0
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CA84
	specialvar VAR_RESULT, ShouldMoveLilycoveFanClubMember
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CA56
	specialvar VAR_RESULT, GetNumMovedLilycoveFanClubMembers
	compare VAR_RESULT, 7
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CA7A
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21D12A, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CA56:: @ 821CA56
	specialvar VAR_RESULT, GetNumMovedLilycoveFanClubMembers
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CA70
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21D094, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CA70:: @ 821CA70
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21D0BB, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CA7A:: @ 821CA7A
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21D1B5, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CA84:: @ 821CA84
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21D20C, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CA8E:: @ 821CA8E
	lock
	faceplayer
	setvar VAR_0x8004, 8
	special BufferStreakTrainerText
	compare VAR_LILYCOVE_FAN_CLUB_STATE, 0
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CAFB
	specialvar VAR_RESULT, ShouldMoveLilycoveFanClubMember
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CACD
	specialvar VAR_RESULT, GetNumMovedLilycoveFanClubMembers
	compare VAR_RESULT, 7
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CAF1
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21D347, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CACD:: @ 821CACD
	specialvar VAR_RESULT, GetNumMovedLilycoveFanClubMembers
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CAE7
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21D2A6, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CAE7:: @ 821CAE7
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21D2CE, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CAF1:: @ 821CAF1
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21D377, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CAFB:: @ 821CAFB
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21D3EE, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CB05:: @ 821CB05
	lock
	faceplayer
	setvar VAR_0x8004, 9
	special BufferStreakTrainerText
	compare VAR_LILYCOVE_FAN_CLUB_STATE, 0
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CB72
	specialvar VAR_RESULT, ShouldMoveLilycoveFanClubMember
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CB44
	specialvar VAR_RESULT, GetNumMovedLilycoveFanClubMembers
	compare VAR_RESULT, 7
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CB68
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21D52E, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CB44:: @ 821CB44
	specialvar VAR_RESULT, GetNumMovedLilycoveFanClubMembers
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CB5E
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21D438, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CB5E:: @ 821CB5E
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21D4A3, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CB68:: @ 821CB68
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21D5DC, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CB72:: @ 821CB72
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21D69C, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CB7C:: @ 821CB7C
	lock
	faceplayer
	setvar VAR_0x8004, 10
	special BufferStreakTrainerText
	compare VAR_LILYCOVE_FAN_CLUB_STATE, 0
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CBE9
	specialvar VAR_RESULT, ShouldMoveLilycoveFanClubMember
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CBBB
	specialvar VAR_RESULT, GetNumMovedLilycoveFanClubMembers
	compare VAR_RESULT, 7
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CBDF
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21D822, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CBBB:: @ 821CBBB
	specialvar VAR_RESULT, GetNumMovedLilycoveFanClubMembers
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CBD5
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21D751, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CBD5:: @ 821CBD5
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21D79B, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CBDF:: @ 821CBDF
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21D857, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CBE9:: @ 821CBE9
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21D8C4, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CBF3:: @ 821CBF3
	lock
	faceplayer
	setvar VAR_0x8004, 11
	special BufferStreakTrainerText
	specialvar VAR_RESULT, ShouldMoveLilycoveFanClubMember
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CC27
	specialvar VAR_RESULT, GetNumMovedLilycoveFanClubMembers
	compare VAR_RESULT, 7
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CC4B
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21D9D1, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CC27:: @ 821CC27
	specialvar VAR_RESULT, GetNumMovedLilycoveFanClubMembers
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CC41
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21D921, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CC41:: @ 821CC41
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21D96A, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CC4B:: @ 821CC4B
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21DA0D, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CC55:: @ 821CC55
	lock
	faceplayer
	setvar VAR_0x8004, 12
	special BufferStreakTrainerText
	specialvar VAR_RESULT, ShouldMoveLilycoveFanClubMember
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CC89
	specialvar VAR_RESULT, GetNumMovedLilycoveFanClubMembers
	compare VAR_RESULT, 7
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CCAD
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21DB69, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CC89:: @ 821CC89
	specialvar VAR_RESULT, GetNumMovedLilycoveFanClubMembers
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CCA3
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21DA73, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CCA3:: @ 821CCA3
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21DAF5, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CCAD:: @ 821CCAD
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21DBFB, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CCB7:: @ 821CCB7
	lock
	faceplayer
	setvar VAR_0x8004, 14
	special BufferStreakTrainerText
	specialvar VAR_RESULT, ShouldMoveLilycoveFanClubMember
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CCEB
	specialvar VAR_RESULT, GetNumMovedLilycoveFanClubMembers
	compare VAR_RESULT, 7
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CD0F
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21DD36, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CCEB:: @ 821CCEB
	specialvar VAR_RESULT, GetNumMovedLilycoveFanClubMembers
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CD05
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21DC68, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CD05:: @ 821CD05
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21DCD6, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CD0F:: @ 821CD0F
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21DDCE, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CD19:: @ 821CD19
	lock
	faceplayer
	setvar VAR_0x8004, 15
	special BufferStreakTrainerText
	specialvar VAR_RESULT, ShouldMoveLilycoveFanClubMember
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CD4D
	specialvar VAR_RESULT, GetNumMovedLilycoveFanClubMembers
	compare VAR_RESULT, 7
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CD71
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21DEFF, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CD4D:: @ 821CD4D
	specialvar VAR_RESULT, GetNumMovedLilycoveFanClubMembers
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CD67
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21DE72, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CD67:: @ 821CD67
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21DE83, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CD71:: @ 821CD71
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_21DF51, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CD7B:: @ 821CD7B
	lock
	faceplayer
	goto_if_set FLAG_FAN_CLUB_STRENGTH_SHARED, LilycoveCity_PokemonTrainerFanClub_EventScript_21CEED
	goto_if_unset FLAG_FAN_CLUB_STRENGTH_SHARED, LilycoveCity_PokemonTrainerFanClub_EventScript_21CD90
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CD90:: @ 821CD90
	setvar VAR_0x8005, 11
	special InterviewBefore
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CEFF
	copyvar VAR_0x800A, VAR_0x8006
	setvar VAR_0x8004, 8
	special BufferStreakTrainerText
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_281BCB, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_FAN_QUESTION
	copyvar VAR_0x8005, VAR_0x800A
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CDE0
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CDEE
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CDE0:: @ 821CDE0
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_281C06, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonTrainerFanClub_EventScript_21CE4D
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CDEE:: @ 821CDEE
	setvar VAR_0x8004, 8
	special BufferStreakTrainerText
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_281C3D, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CEC6
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CE15
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CE15:: @ 821CE15
	setvar VAR_0x8004, 8
	special BufferStreakTrainerText
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_281C65, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_FAN_QUESTION
	copyvar VAR_0x8005, VAR_0x800A
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CDE0
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CDEE
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CE4D:: @ 821CE4D
	setvar VAR_0x8004, 8
	special BufferStreakTrainerText
	message LilycoveCity_PokemonTrainerFanClub_Text_281C95
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_POKEMON_FAN_CLUB_RATER
	special ShowScrollableMultichoice
	waitstate
	setvar VAR_0x8004, 8
	switch VAR_RESULT
	case 11, LilycoveCity_PokemonTrainerFanClub_EventScript_21CE9F
	case MULTI_B_PRESSED, LilycoveCity_PokemonTrainerFanClub_EventScript_21CE9F
	setvar VAR_0x8004, 8
	special BufferStreakTrainerText
	copyvar VAR_0x8006, VAR_0x800A
	copyvar VAR_0x8005, VAR_RESULT
	special PutFanClubSpecialOnTheAir
	goto LilycoveCity_PokemonTrainerFanClub_EventScript_21CED8
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CE9F:: @ 821CE9F
	setvar VAR_0x8004, 8
	special BufferStreakTrainerText
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_281CCD, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CEC6
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_21CE4D
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CEC6:: @ 821CEC6
	setvar VAR_0x8004, 8
	special BufferStreakTrainerText
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_281CF5, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CED8:: @ 821CED8
	setvar VAR_0x8004, 8
	special BufferStreakTrainerText
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_281D40, MSGBOX_DEFAULT
	setflag FLAG_FAN_CLUB_STRENGTH_SHARED
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CEED:: @ 821CEED
	setvar VAR_0x8004, 8
	special BufferStreakTrainerText
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_281DB4, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_21CEFF:: @ 821CEFF
	end

LilycoveCity_PokemonTrainerFanClub_Text_21CF00: @ 821CF00
	.string "Oh, waouh!\n"
	.string "C'est {PLAYER}!$"

LilycoveCity_PokemonTrainerFanClub_Text_21CF12: @ 821CF12
	.string "J'ai appris la nouvelle!\n"
	.string "Quelle force tu as, n'est-ce pas?\p"
	.string "Ici, c'est toujours à qui va découvrir\n"
	.string "le DRESSEUR le plus fort.\p"
	.string "Alors, quand j'ai entendu parler de toi,\n"
	.string "j'ai décidé d'être ton fan!\p"
	.string "J'espère que tu vas continuer à te\n"
	.string "battre contre de puissants DRESSEURS.\p"
	.string "Comme ça, on verra encore plus\n"
	.string "de super combats.\p"
	.string "Et les autres ici pourront voir\n"
	.string "comme tu es extraordinaire.\p"
	.string "Rappelle-toi, je suis avec toi,\n"
	.string "{PLAYER}!$"

LilycoveCity_PokemonTrainerFanClub_Text_21D094: @ 821D094
	.string "Yé, {PLAYER}!\n"
	.string "On veut te voir gagner!$"

LilycoveCity_PokemonTrainerFanClub_Text_21D0BB: @ 821D0BB
	.string "Les autres ne savent pas qu'il\n"
	.string "n'y a pas meilleur que toi!\p"
	.string "C'est pas vrai, {PLAYER}?\n"
	.string "Montre-leur que t'as du cran!$"

LilycoveCity_PokemonTrainerFanClub_Text_21D12A: @ 821D12A
	.string "J'aime pas dire ça, mais le DRESSEUR\n"
	.string "dont tout le monde parle, c'est\l"
	.string "{STR_VAR_1}, Pas de doute là-dessus!\p"
	.string "La puissance de ce DRESSEUR…\n"
	.string "C'est exceptionnel.$"

LilycoveCity_PokemonTrainerFanClub_Text_21D1B5: @ 821D1B5
	.string "Mince alors… J'ai dit à tout le monde\n"
	.string "qu'il n'y a pas meilleur que {STR_VAR_1}…\p"
	.string "Mais personne ne m'écoute…$"

LilycoveCity_PokemonTrainerFanClub_Text_21D20C: @ 821D20C
	.string "J'ai entendu parler d'un tout nouveau\n"
	.string "DRESSEUR, très puissant.\p"
	.string "Il paraît que ce DRESSEUR bat même\n"
	.string "les CHAMPIONS D'ARENES.\p"
	.string "Tu as entendu parler de ce nouveau\n"
	.string "DRESSEUR?$"

LilycoveCity_PokemonTrainerFanClub_Text_21D2A6: @ 821D2A6
	.string "Oh!\n"
	.string "{PLAYER}!\p"
	.string "Vas-y!\n"
	.string "Je te soutiens!$"

LilycoveCity_PokemonTrainerFanClub_Text_21D2CE: @ 821D2CE
	.string "Oh…\n"
	.string "BASTIENY…\p"
	.string "Oh, non! Attends!\n"
	.string "C'est pas juste! Non, non et non!\p"
	.string "Je suis ta fan envers et contre tout!\p"
	.string "Alors rends-moi fière de toi!\n"
	.string "Vas-y!$"

LilycoveCity_PokemonTrainerFanClub_Text_21D347: @ 821D347
	.string "Je ne peux rien y faire. Je ne peux\n"
	.string "qu'aimer BASTIEN…$"

LilycoveCity_PokemonTrainerFanClub_Text_21D377: @ 821D377
	.string "Personne ne comprend le charme de\n"
	.string "BASTIEN…\p"
	.string "Ça m'est égal!\p"
	.string "Même si je suis la seule, je vais\n"
	.string "continuer à supporter BASTIEN!$"

LilycoveCity_PokemonTrainerFanClub_Text_21D3EE: @ 821D3EE
	.string "Peu importe ce qu'en disent les autres,\n"
	.string "mon DRESSEUR préféré, c'est le\l"
	.string "CHAMPION D'ARENE de MYOKARA, BASTIEN!$"

LilycoveCity_PokemonTrainerFanClub_Text_21D438: @ 821D438
	.string "Tu surpasses ton propre père à tous\n"
	.string "les égards!\p"
	.string "Je t'assure, il n'y a aucun doute\n"
	.string "là-dessus!$"

LilycoveCity_PokemonTrainerFanClub_Text_21D4A3: @ 821D4A3
	.string "Même quand les choses tournaient mal,\n"
	.string "ton père n'abandonnait jamais.\p"
	.string "Je sais que c'est vrai.\p"
	.string "Ne jamais renoncer, même si tu perds!\n"
	.string "Alors, continue à te battre!$"

LilycoveCity_PokemonTrainerFanClub_Text_21D52E: @ 821D52E
	.string "NORMAN s'est battu avec plus de force,\n"
	.string "de charisme et de sens du spectacle\l"
	.string "que toi.\p"
	.string "Même si les gens disent que ta\n"
	.string "puissance est grande…\p"
	.string "tu as encore du chemin à faire\n"
	.string "pour rattraper ton père.$"

LilycoveCity_PokemonTrainerFanClub_Text_21D5DC: @ 821D5DC
	.string "Tu commences à inspirer le respect,\n"
	.string "comme NORMAN.\p"
	.string "Mais il y a quelque chose de différent\n"
	.string "entre NORMAN et toi.\p"
	.string "Je ne peux pas te dire ce que c'est.\n"
	.string "Tu devras le découvrir par toi-même.$"

LilycoveCity_PokemonTrainerFanClub_Text_21D69C: @ 821D69C
	.string "Nous tous, ici, sommes de grands\n"
	.string "fans des combats de POKéMON.\p"
	.string "On débat pour savoir qui nous semble\n"
	.string "le plus fort de tous les DRESSEURS.\p"
	.string "Si tu devenais célèbre, on pourrait\n"
	.string "même devenir tes fans!$"

LilycoveCity_PokemonTrainerFanClub_Text_21D751: @ 821D751
	.string "Oh, youhouh! C'est {PLAYER}!\n"
	.string "En vrai!\p"
	.string "Serre-moi la main, serre-moi la main!$"

LilycoveCity_PokemonTrainerFanClub_Text_21D79B: @ 821D79B
	.string "Je t'encouragerai toujours, {PLAYER}!\n"
	.string "Toujours, toujours!\p"
	.string "Je ne veux pas te voir perdre,\n"
	.string "{PLAYER}.\p"
	.string "Car je sais que tu as vraiment, vraiment\n"
	.string "beaucoup de force, {PLAYER}!$"

LilycoveCity_PokemonTrainerFanClub_Text_21D822: @ 821D822
	.string "{STR_VAR_1} est vraiment cool…\p"
	.string "Tout le monde est d'accord, pas vrai?$"

LilycoveCity_PokemonTrainerFanClub_Text_21D857: @ 821D857
	.string "{STR_VAR_1} est vraiment cool, tu ne\n"
	.string "trouves pas?\p"
	.string "Même s'il n'y a que moi, je vais continuer\n"
	.string "à encourager mon DRESSEUR préféré.$"

LilycoveCity_PokemonTrainerFanClub_Text_21D8C4: @ 821D8C4
	.string "Mon DRESSEUR préféré doit être…\p"
	.string "Cool…\p"
	.string "Fort…\p"
	.string "Et très sympa…\p"
	.string "Si seulement il existait un tel\n"
	.string "DRESSEUR…$"

LilycoveCity_PokemonTrainerFanClub_Text_21D921: @ 821D921
	.string "Waouh! C'est {PLAYER}!\n"
	.string "Génial!\p"
	.string "Quand je serai grand, je veux être\n"
	.string "aussi fort que toi, {PLAYER}!$"

LilycoveCity_PokemonTrainerFanClub_Text_21D96A: @ 821D96A
	.string "Même s'il n'y a que moi…\p"
	.string "Je n'encouragerai toujours que toi,\n"
	.string "{PLAYER}!\p"
	.string "Parce que je crois en toi, {PLAYER}!$"

LilycoveCity_PokemonTrainerFanClub_Text_21D9D1: @ 821D9D1
	.string "{STR_VAR_1} est tellement cool…\n"
	.string "Je veux serrer la main de ma star.$"

LilycoveCity_PokemonTrainerFanClub_Text_21DA0D: @ 821DA0D
	.string "Même s'il n'y a que moi…\p"
	.string "Je ne cesserai jamais d'être fan\n"
	.string "de {STR_VAR_1}!\p"
	.string "Parce que je sais que {STR_VAR_1}\n"
	.string "ne perd jamais!$"

LilycoveCity_PokemonTrainerFanClub_Text_21DA73: @ 821DA73
	.string "{PLAYER}!\n"
	.string "Tu es vraiment quelqu'un\n"
	.string "d'exceptionnel!\p"
	.string "Dès que j'ai posé les yeux sur toi,\n"
	.string "j'ai su que tu étais remarquable.\p"
	.string "Apparemment, j'ai vu juste.$"

LilycoveCity_PokemonTrainerFanClub_Text_21DAF5: @ 821DAF5
	.string "Qui se préoccupe des autres?\n"
	.string "Je te soutiendrai quoi qu'il arrive!\p"
	.string "Ne t'inquiète pas. Continue à te battre\n"
	.string "comme d'habitude.$"

LilycoveCity_PokemonTrainerFanClub_Text_21DB69: @ 821DB69
	.string "Je pense que tu es un bon\n"
	.string "DRESSEUR.\p"
	.string "Mais je pense aussi que {STR_VAR_1}\n"
	.string "est maintenant en tête.\p"
	.string "Ce n'est que mon humble avis.\n"
	.string "Ne t'en préoccupe pas trop.$"

LilycoveCity_PokemonTrainerFanClub_Text_21DBFB: @ 821DBFB
	.string "Quelle vigueur! Ta force est peut-être\n"
	.string "plus grande que celle de {STR_VAR_1}.\p"
	.string "Mais {STR_VAR_1} a besoin de moi.\p"
	.string "Si je n'encourage pas {STR_VAR_1},\n"
	.string "qui le fera?$"

LilycoveCity_PokemonTrainerFanClub_Text_21DC68: @ 821DC68
	.string "Tu m'as fait changer d'avis!\n"
	.string "Tu es robuste, hein?\p"
	.string "J'aimerais bien que tu m'expliques\n"
	.string "comment tu as pu devenir si balèze!$"

LilycoveCity_PokemonTrainerFanClub_Text_21DCD6: @ 821DCD6
	.string "Plus la situation est difficile, plus la\n"
	.string "bataille est intéressante.\p"
	.string "J'ai hâte de voir le prochain combat!$"

LilycoveCity_PokemonTrainerFanClub_Text_21DD36: @ 821DD36
	.string "Parmi les DRESSEURS puissants,\n"
	.string "{STR_VAR_1} sort du lot.\p"
	.string "Cette force est tout simplement\n"
	.string "anormale.\p"
	.string "Tu te défends bien, mais tu n'as\n"
	.string "pas le niveau de {STR_VAR_1}.$"

LilycoveCity_PokemonTrainerFanClub_Text_21DDCE: @ 821DDCE
	.string "Tu es très populaire…\p"
	.string "Tu es robuste et sensible envers les\n"
	.string "POKéMON. Personne ne peut t'enlever ça.\p"
	.string "Mais, tu sais, je crois en {STR_VAR_1}.\p"
	.string "{STR_VAR_1} est vraiment plus balèze!\n"
	.string "Je suis optimiste!$"

LilycoveCity_PokemonTrainerFanClub_Text_21DE72: @ 821DE72
	.string "Tu…\p"
	.string "Impressionnant!$"

LilycoveCity_PokemonTrainerFanClub_Text_21DE83: @ 821DE83
	.string "Ta vraie valeur, c'est une bonne chose\n"
	.string "que je la reconnaisse.\p"
	.string "Je doute que les autres comprennent\n"
	.string "le pouvoir caché qu'elle renferme.$"

LilycoveCity_PokemonTrainerFanClub_Text_21DEFF: @ 821DEFF
	.string "Oui, je vois la force dans tes yeux.\p"
	.string "Mais tu n'as pas encore pris conscience\n"
	.string "de ton potentiel.$"

LilycoveCity_PokemonTrainerFanClub_Text_21DF51: @ 821DF51
	.string "C'est vrai que tu as une force\n"
	.string "extraordinaire.\p"
	.string "Mais!\n"
	.string "Je dois dire…\p"
	.string "Cette force ne peut pas encore être\n"
	.string "considérée comme la vraie force!\p"
	.string "La vraie force est…!\n"
	.string "… …\p"
	.string "En fait, je n'en ai moi-même aucune idée.$"
