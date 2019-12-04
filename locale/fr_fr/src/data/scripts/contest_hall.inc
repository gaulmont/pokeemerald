LilycoveCity_ContestLobby_EventScript_279CC5:: @ 8279CC5
	lock
	faceplayer
	compare VAR_CONTEST_PRIZE_PICKUP, 0
	goto_if_ne LilycoveCity_ContestLobby_EventScript_279D13
	call_if_set FLAG_RECEIVED_POKEBLOCK_CASE, LilycoveCity_ContestLobby_EventScript_279CEA
	call_if_unset FLAG_RECEIVED_POKEBLOCK_CASE, LilycoveCity_ContestLobby_EventScript_279CF3
	goto LilycoveCity_ContestLobby_EventScript_279D5A
	end

LilycoveCity_ContestLobby_EventScript_279CEA:: @ 8279CEA
	msgbox LilycoveCity_ContestLobby_Text_27AEA8, MSGBOX_DEFAULT
	return

LilycoveCity_ContestLobby_EventScript_279CF3:: @ 8279CF3
	msgbox LilycoveCity_ContestLobby_Text_27ADA7, MSGBOX_DEFAULT
	giveitem_std ITEM_POKEBLOCK_CASE
	setflag FLAG_RECEIVED_POKEBLOCK_CASE
	msgbox LilycoveCity_ContestLobby_Text_27AE47, MSGBOX_DEFAULT
	return

LilycoveCity_ContestLobby_EventScript_279D13:: @ 8279D13
	msgbox LilycoveCity_ContestLobby_Text_27B67B, MSGBOX_DEFAULT
	switch VAR_CONTEST_PRIZE_PICKUP
	case 4, LilycoveCity_ContestLobby_EventScript_279D2C
	end

LilycoveCity_ContestLobby_EventScript_279D2C:: @ 8279D2C
	giveitem_std ITEM_LUXURY_BALL
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_ContestLobby_EventScript_279D4B
	setvar VAR_CONTEST_PRIZE_PICKUP, 0
	closemessage
	release
	end

LilycoveCity_ContestLobby_EventScript_279D4B:: @ 8279D4B
	call Common_EventScript_BagIsFull
	msgbox LilycoveCity_ContestLobby_Text_27B6E7, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_279D5A:: @ 8279D5A
	message LilycoveCity_ContestLobby_Text_27AF28
	waitmessage
	multichoice 0, 0, MULTI_ENTERINFO, 0
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_279E62
	case 1, LilycoveCity_ContestLobby_EventScript_279D97
	case 2, LilycoveCity_ContestLobby_EventScript_279E09
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_279E09
	end

LilycoveCity_ContestLobby_EventScript_279D97:: @ 8279D97
	message LilycoveCity_ContestLobby_Text_27AF5E
	waitmessage
	multichoice 0, 0, MULTI_CONTEST_INFO, 0
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_279DDF
	case 1, LilycoveCity_ContestLobby_EventScript_279DED
	case 2, LilycoveCity_ContestLobby_EventScript_279DFB
	case 3, LilycoveCity_ContestLobby_EventScript_279D5A
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_279D5A
	end

LilycoveCity_ContestLobby_EventScript_279DDF:: @ 8279DDF
	msgbox LilycoveCity_ContestLobby_Text_27AF7A, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_279D97
	end

LilycoveCity_ContestLobby_EventScript_279DED:: @ 8279DED
	msgbox LilycoveCity_ContestLobby_Text_27B17D, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_279D97
	end

LilycoveCity_ContestLobby_EventScript_279DFB:: @ 8279DFB
	msgbox LilycoveCity_ContestLobby_Text_27B221, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_279D97
	end

LilycoveCity_ContestLobby_EventScript_279E09:: @ 8279E09
	msgbox LilycoveCity_ContestLobby_Text_27BD4F, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_279E13:: @ 8279E13
	msgbox LilycoveCity_ContestLobby_Text_27B44A, MSGBOX_DEFAULT
	choosecontestmon
	compare VAR_0x8004, 255
	goto_if_eq LilycoveCity_ContestLobby_EventScript_279E09
	special sub_80F7F30
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_ContestLobby_EventScript_279F12
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_ContestLobby_EventScript_279F87
	compare VAR_RESULT, 2
	goto_if_eq LilycoveCity_ContestLobby_EventScript_279F45
	compare VAR_RESULT, 3
	goto_if_eq LilycoveCity_ContestLobby_EventScript_279F69
	compare VAR_RESULT, 4
	goto_if_eq LilycoveCity_ContestLobby_EventScript_279F78
	end

LilycoveCity_ContestLobby_EventScript_279E62:: @ 8279E62
	message LilycoveCity_ContestLobby_Text_27B3FF
	waitmessage
	multichoice 0, 0, MULTI_CONTEST_RANK, 0
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_279EB5
	case 1, LilycoveCity_ContestLobby_EventScript_279EC0
	case 2, LilycoveCity_ContestLobby_EventScript_279ECB
	case 3, LilycoveCity_ContestLobby_EventScript_279ED6
	case 4, LilycoveCity_ContestLobby_EventScript_279E09
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_279E09
	end

LilycoveCity_ContestLobby_EventScript_279EB5:: @ 8279EB5
	setvar VAR_CONTEST_RANK, 0
	goto LilycoveCity_ContestLobby_EventScript_279EE1
	end

LilycoveCity_ContestLobby_EventScript_279EC0:: @ 8279EC0
	setvar VAR_CONTEST_RANK, 1
	goto LilycoveCity_ContestLobby_EventScript_279EE1
	end

LilycoveCity_ContestLobby_EventScript_279ECB:: @ 8279ECB
	setvar VAR_CONTEST_RANK, 2
	goto LilycoveCity_ContestLobby_EventScript_279EE1
	end

LilycoveCity_ContestLobby_EventScript_279ED6:: @ 8279ED6
	setvar VAR_CONTEST_RANK, 3
	goto LilycoveCity_ContestLobby_EventScript_279EE1
	end

LilycoveCity_ContestLobby_EventScript_279EE1:: @ 8279EE1
	message LilycoveCity_ContestLobby_Text_27B423
	waitmessage
	multichoice 0, 0, MULTI_CONTEST_TYPE, 0
	switch VAR_RESULT
	case 5, LilycoveCity_ContestLobby_EventScript_279E09
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_279E09
	copyvar VAR_CONTEST_CATEGORY, VAR_RESULT
	goto LilycoveCity_ContestLobby_EventScript_279E13
	end

LilycoveCity_ContestLobby_EventScript_279F12:: @ 8279F12
	msgbox LilycoveCity_ContestLobby_Text_27B471, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_279E13
	release
	end

LilycoveCity_ContestLobby_EventScript_279F21:: @ 8279F21
	msgbox LilycoveCity_ContestLobby_Text_27B5C4, MSGBOX_YESNO
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_279E13
	case 1, LilycoveCity_ContestLobby_EventScript_279F87
	end

LilycoveCity_ContestLobby_EventScript_279F45:: @ 8279F45
	msgbox LilycoveCity_ContestLobby_Text_27B547, MSGBOX_YESNO
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_279E13
	case 1, LilycoveCity_ContestLobby_EventScript_279F87
	end

LilycoveCity_ContestLobby_EventScript_279F69:: @ 8279F69
	msgbox LilycoveCity_ContestLobby_Text_27B4C4, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_279E13
	release
	end

LilycoveCity_ContestLobby_EventScript_279F78:: @ 8279F78
	msgbox LilycoveCity_ContestLobby_Text_27B501, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_279E13
	release
	end

LilycoveCity_ContestLobby_EventScript_279F87:: @ 8279F87
	msgbox LilycoveCity_ContestLobby_Text_27B5E2, MSGBOX_DEFAULT
	closemessage
	releaseall
	setvar VAR_LINK_CONTEST_ROOM_STATE, 1
	return

LinkContestRoom1_EventScript_279F97:: @ 8279F97
	special sub_80F90DC
	setvar VAR_0x8006, 0
	lockall
	applymovement 14, LinkContestRoom1_Movement_27AD43
	waitmovement 0
	applymovement 1, LinkContestRoom1_Movement_27AD09
	waitmovement 0
	releaseall
	call LinkContestRoom1_EventScript_27A133
	call LinkContestRoom1_EventScript_279FF2
	call LinkContestRoom1_EventScript_27A03C
	call LinkContestRoom1_EventScript_27A097
	call LinkContestRoom1_EventScript_27A0F5
	call LinkContestRoom1_EventScript_27A801
	call LinkContestRoom1_EventScript_27A8A5
	call LinkContestRoom1_EventScript_27A987
	call LinkContestRoom1_EventScript_27A9D4
	call LinkContestRoom1_EventScript_27AA1B
	call LinkContestRoom1_EventScript_27AB36
	setvar VAR_LINK_CONTEST_ROOM_STATE, 2
	return

LinkContestRoom1_EventScript_279FF2:: @ 8279FF2
	switch VAR_CONTEST_RANK
	case 0, LinkContestRoom1_EventScript_27A024
	case 1, LinkContestRoom1_EventScript_27A02A
	case 2, LinkContestRoom1_EventScript_27A030
	case 3, LinkContestRoom1_EventScript_27A036
	return

LinkContestRoom1_EventScript_27A024:: @ 827A024
	setvar VAR_0x8009, STDSTRING_NORMAL
	return

LinkContestRoom1_EventScript_27A02A:: @ 827A02A
	setvar VAR_0x8009, STDSTRING_SUPER
	return

LinkContestRoom1_EventScript_27A030:: @ 827A030
	setvar VAR_0x8009, STDSTRING_HYPER
	return

LinkContestRoom1_EventScript_27A036:: @ 827A036
	setvar VAR_0x8009, STDSTRING_MASTER
	return

LinkContestRoom1_EventScript_27A03C:: @ 827A03C
	switch VAR_CONTEST_CATEGORY
	case 0, LinkContestRoom1_EventScript_27A079
	case 1, LinkContestRoom1_EventScript_27A07F
	case 2, LinkContestRoom1_EventScript_27A085
	case 3, LinkContestRoom1_EventScript_27A08B
	case 4, LinkContestRoom1_EventScript_27A091
	return

LinkContestRoom1_EventScript_27A079:: @ 827A079
	setvar VAR_0x8008, CONTEST_CATEGORY_COOL
	return

LinkContestRoom1_EventScript_27A07F:: @ 827A07F
	setvar VAR_0x8008, CONTEST_CATEGORY_BEAUTY
	return

LinkContestRoom1_EventScript_27A085:: @ 827A085
	setvar VAR_0x8008, CONTEST_CATEGORY_CUTE
	return

LinkContestRoom1_EventScript_27A08B:: @ 827A08B
	setvar VAR_0x8008, CONTEST_CATEGORY_SMART
	return

LinkContestRoom1_EventScript_27A091:: @ 827A091
	setvar VAR_0x8008, CONTEST_CATEGORY_TOUGH
	return

LinkContestRoom1_EventScript_27A097:: @ 827A097
	buffercontesttypestring 1, VAR_0x8008
	bufferstdstring 2, VAR_0x8009
	call LinkContestRoom1_EventScript_27A0B1
	lockall
	applymovement 1, LinkContestRoom1_Movement_27AD0B
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27A0B1:: @ 827A0B1
	compare VAR_CONTEST_LOCATION, 5
	goto_if_eq LinkContestRoom1_EventScript_27A0C7
	lockall
	msgbox LinkContestRoom1_Text_27B711, MSGBOX_DEFAULT
	releaseall
	return

LinkContestRoom1_EventScript_27A0C7:: @ 827A0C7
	specialvar VAR_RESULT, sub_80F9160
	compare VAR_RESULT, 1
	goto_if_eq LinkContestRoom1_EventScript_27A0DE
	messageautoscroll LinkContestRoom1_Text_27B78F
	waitmessage
	return

LinkContestRoom1_EventScript_27A0DE:: @ 827A0DE
	messageautoscroll LinkContestRoom1_Text_27C929
	waitmessage
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27C972
	waitmessage
	call LinkContestRoom1_EventScript_27A133
	return

LinkContestRoom1_EventScript_27A0F5:: @ 827A0F5
	call LinkContestRoom1_EventScript_27A149
	call LinkContestRoom1_EventScript_27A1D2
	call LinkContestRoom1_EventScript_27A34F
	call LinkContestRoom1_EventScript_27A2D5
	call LinkContestRoom1_EventScript_27A77A
	call LinkContestRoom1_EventScript_27A133
	call LinkContestRoom1_EventScript_27A133
	addvar VAR_0x8006, 1
	compare VAR_0x8006, 4
	goto_if_ne LinkContestRoom1_EventScript_27A0F5
	call LinkContestRoom1_EventScript_27A230
	setvar VAR_TEMP_1, 6
	return

LinkContestRoom1_EventScript_27A133:: @ 827A133
	specialvar VAR_RESULT, sub_80F9160
	compare VAR_RESULT, 1
	goto_if_eq LinkContestRoom1_EventScript_27A144
	return

LinkContestRoom1_EventScript_27A144:: @ 827A144
	special sub_80F905C
	waitstate
	return

LinkContestRoom1_EventScript_27A149:: @ 827A149
	compare VAR_0x8006, 0
	goto_if_eq LinkContestRoom1_EventScript_27A176
	compare VAR_0x8006, 1
	goto_if_eq LinkContestRoom1_EventScript_27A18D
	compare VAR_0x8006, 2
	goto_if_eq LinkContestRoom1_EventScript_27A1A4
	compare VAR_0x8006, 3
	goto_if_eq LinkContestRoom1_EventScript_27A1BB
	return

LinkContestRoom1_EventScript_27A176:: @ 827A176
	call LinkContestRoom1_EventScript_27A133
	lockall
	applymovement 3, LinkContestRoom1_Movement_27AD52
	waitmovement 0
	releaseall
	setvar VAR_0x800B, 3
	return

LinkContestRoom1_EventScript_27A18D:: @ 827A18D
	call LinkContestRoom1_EventScript_27A133
	lockall
	applymovement 4, LinkContestRoom1_Movement_27AD5E
	waitmovement 0
	releaseall
	setvar VAR_0x800B, 4
	return

LinkContestRoom1_EventScript_27A1A4:: @ 827A1A4
	call LinkContestRoom1_EventScript_27A133
	lockall
	applymovement 5, LinkContestRoom1_Movement_27AD66
	waitmovement 0
	releaseall
	setvar VAR_0x800B, 5
	return

LinkContestRoom1_EventScript_27A1BB:: @ 827A1BB
	call LinkContestRoom1_EventScript_27A133
	lockall
	applymovement 14, LinkContestRoom1_Movement_27AD6E
	waitmovement 0
	releaseall
	setvar VAR_0x800B, 14
	return

LinkContestRoom1_EventScript_27A1D2:: @ 827A1D2
	special sub_80F8850
	addvar VAR_0x8006, 1
	buffernumberstring 1, VAR_0x8006
	lockall
	applymovement VAR_0x800B, LinkContestRoom1_Movement_27AD20
	waitmovement 0
	releaseall
	call LinkContestRoom1_EventScript_27A133
	call LinkContestRoom1_EventScript_27AD80
	addobject 13
	playse SE_DANSA
	lockall
	applymovement VAR_0x800B, LinkContestRoom1_Movement_27AD20
	waitmovement 0
	releaseall
	addvar VAR_0x8006, 65535
	playse SE_BOWA2
	special ShowContestEntryMonPic
	call LinkContestRoom1_EventScript_27A217
	return

LinkContestRoom1_EventScript_27A217:: @ 827A217
	compare VAR_CONTEST_LOCATION, 5
	goto_if_eq LinkContestRoom1_EventScript_27A229
	message LinkContestRoom1_Text_27B815
	waitmessage
	return

LinkContestRoom1_EventScript_27A229:: @ 827A229
	messageautoscroll LinkContestRoom1_Text_27B815
	waitmessage
	return

LinkContestRoom1_EventScript_27A230:: @ 827A230
	call LinkContestRoom1_EventScript_27A26C
	call LinkContestRoom1_EventScript_27A2B9
	playse SE_W227B
	waitmessage
	call LinkContestRoom1_EventScript_27AA1B
	applymovement 1, LinkContestRoom1_Movement_27AD23
	waitmovement 0
	applymovement 2, LinkContestRoom1_Movement_27AD25
	waitmovement 0
	delay 20
	applymovement 1, LinkContestRoom1_Movement_27AD13
	applymovement 2, LinkContestRoom1_Movement_27AD13
	waitmovement 0
	return

LinkContestRoom1_EventScript_27A26C:: @ 827A26C
	compare VAR_CONTEST_LOCATION, 5
	goto_if_eq LinkContestRoom1_EventScript_27A280
	msgbox LinkContestRoom1_Text_27B830, MSGBOX_DEFAULT
	return

LinkContestRoom1_EventScript_27A280:: @ 827A280
	specialvar VAR_RESULT, sub_80F9160
	compare VAR_RESULT, 1
	goto_if_eq LinkContestRoom1_EventScript_27A297
	messageautoscroll LinkContestRoom1_Text_27B830
	waitmessage
	return

LinkContestRoom1_EventScript_27A297:: @ 827A297
	messageautoscroll LinkContestRoom1_Text_27C9AF
	waitmessage
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27CA04
	waitmessage
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27CA42
	waitmessage
	call LinkContestRoom1_EventScript_27A133
	return

LinkContestRoom1_EventScript_27A2B9:: @ 827A2B9
	compare VAR_CONTEST_LOCATION, 5
	goto_if_eq LinkContestRoom1_EventScript_27A2CA
	message LinkContestRoom1_Text_27B8F2
	return

LinkContestRoom1_EventScript_27A2CA:: @ 827A2CA
	messageautoscroll LinkContestRoom1_Text_27B8F2
	call LinkContestRoom1_EventScript_27A133
	return

LinkContestRoom1_EventScript_27A2D5:: @ 827A2D5
	call LinkContestRoom1_EventScript_27A133
	applymovement 1, LinkContestRoom1_Movement_27AD33
	waitmovement 0
	playse SE_W227B
	call LinkContestRoom1_EventScript_27AA6F
	applymovement 9, LinkContestRoom1_Movement_27AD3B
	applymovement 12, LinkContestRoom1_Movement_27AD3F
	applymovement 7, LinkContestRoom1_Movement_27AD3B
	waitmovement 0
	applymovement 1, LinkContestRoom1_Movement_27AD3B
	waitmovement 0
	applymovement 10, LinkContestRoom1_Movement_27AD33
	applymovement 11, LinkContestRoom1_Movement_27AD3F
	applymovement 6, LinkContestRoom1_Movement_27AD37
	applymovement 8, LinkContestRoom1_Movement_27AD33
	waitmovement 0
	applymovement 1, LinkContestRoom1_Movement_27AD45
	waitmovement 0
	applymovement 1, LinkContestRoom1_Movement_27AD4E
	applymovement 2, LinkContestRoom1_Movement_27AD49
	waitmovement 0
	releaseall
	call LinkContestRoom1_EventScript_27A133
	return

LinkContestRoom1_EventScript_27A34F:: @ 827A34F
	special sub_80F82FC
	compare VAR_CONTEST_LOCATION, 1
	call_if_eq LinkContestRoom1_EventScript_27A454
	compare VAR_CONTEST_LOCATION, 2
	call_if_eq LinkContestRoom1_EventScript_27A4B2
	compare VAR_CONTEST_LOCATION, 3
	call_if_eq LinkContestRoom1_EventScript_27A510
	compare VAR_CONTEST_LOCATION, 4
	call_if_eq LinkContestRoom1_EventScript_27A56E
	compare VAR_CONTEST_LOCATION, 5
	call_if_eq LinkContestRoom1_EventScript_27A5CC
	setvar VAR_TEMP_1, 9
	setvar VAR_TEMP_2, 9
	setvar VAR_TEMP_3, 9
	setvar VAR_TEMP_4, 9
	setvar VAR_TEMP_5, 9
	setvar VAR_TEMP_6, 9
	setvar VAR_TEMP_7, 9
	setvar VAR_TEMP_8, 9
	compare VAR_TEMP_0, 0
	call_if_gt LinkContestRoom1_EventScript_27A3E5
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_5, 0
	setvar VAR_TEMP_6, 0
	setvar VAR_TEMP_7, 0
	setvar VAR_TEMP_8, 0
	return

LinkContestRoom1_EventScript_27A3E5:: @ 827A3E5
	setvar VAR_RESULT, 8
	special ScriptRandom
	compare VAR_RESULT, 0
	call_if_eq LinkContestRoom1_EventScript_27A65A
	compare VAR_RESULT, 1
	call_if_eq LinkContestRoom1_EventScript_27A67E
	compare VAR_RESULT, 2
	call_if_eq LinkContestRoom1_EventScript_27A6A2
	compare VAR_RESULT, 3
	call_if_eq LinkContestRoom1_EventScript_27A6C6
	compare VAR_RESULT, 4
	call_if_eq LinkContestRoom1_EventScript_27A6EA
	compare VAR_RESULT, 5
	call_if_eq LinkContestRoom1_EventScript_27A70E
	compare VAR_RESULT, 6
	call_if_eq LinkContestRoom1_EventScript_27A732
	compare VAR_RESULT, 7
	call_if_eq LinkContestRoom1_EventScript_27A756
	compare VAR_TEMP_0, 0
	goto_if_gt LinkContestRoom1_EventScript_27A3E5
	waitmovement 0
	return

LinkContestRoom1_EventScript_27A454:: @ 827A454
	compare VAR_0x8004, 80
	goto_if_gt LinkContestRoom1_EventScript_27A654
	compare VAR_0x8004, 70
	goto_if_gt LinkContestRoom1_EventScript_27A64E
	compare VAR_0x8004, 60
	goto_if_gt LinkContestRoom1_EventScript_27A648
	compare VAR_0x8004, 50
	goto_if_gt LinkContestRoom1_EventScript_27A642
	compare VAR_0x8004, 40
	goto_if_gt LinkContestRoom1_EventScript_27A63C
	compare VAR_0x8004, 30
	goto_if_gt LinkContestRoom1_EventScript_27A636
	compare VAR_0x8004, 20
	goto_if_gt LinkContestRoom1_EventScript_27A630
	compare VAR_0x8004, 10
	goto_if_gt LinkContestRoom1_EventScript_27A62A
	setvar VAR_TEMP_0, 0
	return

LinkContestRoom1_EventScript_27A4B2:: @ 827A4B2
	compare VAR_0x8004, 230
	goto_if_gt LinkContestRoom1_EventScript_27A654
	compare VAR_0x8004, 210
	goto_if_gt LinkContestRoom1_EventScript_27A64E
	compare VAR_0x8004, 190
	goto_if_gt LinkContestRoom1_EventScript_27A648
	compare VAR_0x8004, 170
	goto_if_gt LinkContestRoom1_EventScript_27A642
	compare VAR_0x8004, 150
	goto_if_gt LinkContestRoom1_EventScript_27A63C
	compare VAR_0x8004, 130
	goto_if_gt LinkContestRoom1_EventScript_27A636
	compare VAR_0x8004, 110
	goto_if_gt LinkContestRoom1_EventScript_27A630
	compare VAR_0x8004, 90
	goto_if_gt LinkContestRoom1_EventScript_27A62A
	setvar VAR_TEMP_0, 0
	return

LinkContestRoom1_EventScript_27A510:: @ 827A510
	compare VAR_0x8004, 380
	goto_if_gt LinkContestRoom1_EventScript_27A654
	compare VAR_0x8004, 350
	goto_if_gt LinkContestRoom1_EventScript_27A64E
	compare VAR_0x8004, 320
	goto_if_gt LinkContestRoom1_EventScript_27A648
	compare VAR_0x8004, 290
	goto_if_gt LinkContestRoom1_EventScript_27A642
	compare VAR_0x8004, 260
	goto_if_gt LinkContestRoom1_EventScript_27A63C
	compare VAR_0x8004, 230
	goto_if_gt LinkContestRoom1_EventScript_27A636
	compare VAR_0x8004, 200
	goto_if_gt LinkContestRoom1_EventScript_27A630
	compare VAR_0x8004, 170
	goto_if_gt LinkContestRoom1_EventScript_27A62A
	setvar VAR_TEMP_0, 0
	return

LinkContestRoom1_EventScript_27A56E:: @ 827A56E
	compare VAR_0x8004, 600
	goto_if_gt LinkContestRoom1_EventScript_27A654
	compare VAR_0x8004, 560
	goto_if_gt LinkContestRoom1_EventScript_27A64E
	compare VAR_0x8004, 520
	goto_if_gt LinkContestRoom1_EventScript_27A648
	compare VAR_0x8004, 480
	goto_if_gt LinkContestRoom1_EventScript_27A642
	compare VAR_0x8004, 440
	goto_if_gt LinkContestRoom1_EventScript_27A63C
	compare VAR_0x8004, 400
	goto_if_gt LinkContestRoom1_EventScript_27A636
	compare VAR_0x8004, 360
	goto_if_gt LinkContestRoom1_EventScript_27A630
	compare VAR_0x8004, 320
	goto_if_gt LinkContestRoom1_EventScript_27A62A
	setvar VAR_TEMP_0, 0
	return

LinkContestRoom1_EventScript_27A5CC:: @ 827A5CC
	compare VAR_0x8004, 600
	goto_if_gt LinkContestRoom1_EventScript_27A654
	compare VAR_0x8004, 550
	goto_if_gt LinkContestRoom1_EventScript_27A64E
	compare VAR_0x8004, 500
	goto_if_gt LinkContestRoom1_EventScript_27A648
	compare VAR_0x8004, 450
	goto_if_gt LinkContestRoom1_EventScript_27A642
	compare VAR_0x8004, 400
	goto_if_gt LinkContestRoom1_EventScript_27A63C
	compare VAR_0x8004, 300
	goto_if_gt LinkContestRoom1_EventScript_27A636
	compare VAR_0x8004, 200
	goto_if_gt LinkContestRoom1_EventScript_27A630
	compare VAR_0x8004, 100
	goto_if_gt LinkContestRoom1_EventScript_27A62A
	setvar VAR_TEMP_0, 0
	return

LinkContestRoom1_EventScript_27A62A:: @ 827A62A
	setvar VAR_TEMP_0, 1
	return

LinkContestRoom1_EventScript_27A630:: @ 827A630
	setvar VAR_TEMP_0, 2
	return

LinkContestRoom1_EventScript_27A636:: @ 827A636
	setvar VAR_TEMP_0, 3
	return

LinkContestRoom1_EventScript_27A63C:: @ 827A63C
	setvar VAR_TEMP_0, 4
	return

LinkContestRoom1_EventScript_27A642:: @ 827A642
	setvar VAR_TEMP_0, 5
	return

LinkContestRoom1_EventScript_27A648:: @ 827A648
	setvar VAR_TEMP_0, 6
	return

LinkContestRoom1_EventScript_27A64E:: @ 827A64E
	setvar VAR_TEMP_0, 7
	return

LinkContestRoom1_EventScript_27A654:: @ 827A654
	setvar VAR_TEMP_0, 8
	return

LinkContestRoom1_EventScript_27A65A:: @ 827A65A
	compare VAR_TEMP_1, 1
	goto_if_eq LinkContestRoom1_EventScript_27A67D
	applymovement 6, LinkContestRoom1_Movement_27AD11
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_1, 1
	addvar VAR_TEMP_0, 65535
	return

LinkContestRoom1_EventScript_27A67D:: @ 827A67D
	return

LinkContestRoom1_EventScript_27A67E:: @ 827A67E
	compare VAR_TEMP_2, 1
	goto_if_eq LinkContestRoom1_EventScript_27A6A1
	applymovement 12, LinkContestRoom1_Movement_27AD11
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_2, 1
	addvar VAR_TEMP_0, 65535
	return

LinkContestRoom1_EventScript_27A6A1:: @ 827A6A1
	return

LinkContestRoom1_EventScript_27A6A2:: @ 827A6A2
	compare VAR_TEMP_3, 1
	goto_if_eq LinkContestRoom1_EventScript_27A6C5
	applymovement 7, LinkContestRoom1_Movement_27AD11
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_3, 1
	addvar VAR_TEMP_0, 65535
	return

LinkContestRoom1_EventScript_27A6C5:: @ 827A6C5
	return

LinkContestRoom1_EventScript_27A6C6:: @ 827A6C6
	compare VAR_TEMP_4, 1
	goto_if_eq LinkContestRoom1_EventScript_27A6E9
	applymovement 8, LinkContestRoom1_Movement_27AD11
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_4, 1
	addvar VAR_TEMP_0, 65535
	return

LinkContestRoom1_EventScript_27A6E9:: @ 827A6E9
	return

LinkContestRoom1_EventScript_27A6EA:: @ 827A6EA
	compare VAR_TEMP_5, 1
	goto_if_eq LinkContestRoom1_EventScript_27A70D
	applymovement 9, LinkContestRoom1_Movement_27AD11
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_5, 1
	addvar VAR_TEMP_0, 65535
	return

LinkContestRoom1_EventScript_27A70D:: @ 827A70D
	return

LinkContestRoom1_EventScript_27A70E:: @ 827A70E
	compare VAR_TEMP_6, 1
	goto_if_eq LinkContestRoom1_EventScript_27A731
	applymovement 10, LinkContestRoom1_Movement_27AD11
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_6, 1
	addvar VAR_TEMP_0, 65535
	return

LinkContestRoom1_EventScript_27A731:: @ 827A731
	return

LinkContestRoom1_EventScript_27A732:: @ 827A732
	compare VAR_TEMP_7, 1
	goto_if_eq LinkContestRoom1_EventScript_27A755
	applymovement 11, LinkContestRoom1_Movement_27AD11
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_7, 1
	addvar VAR_TEMP_0, 65535
	return

LinkContestRoom1_EventScript_27A755:: @ 827A755
	return

LinkContestRoom1_EventScript_27A756:: @ 827A756
	compare VAR_TEMP_8, 1
	goto_if_eq LinkContestRoom1_EventScript_27A779
	applymovement 15, LinkContestRoom1_Movement_27AD11
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_8, 1
	addvar VAR_TEMP_0, 65535
	return

LinkContestRoom1_EventScript_27A779:: @ 827A779
	return

LinkContestRoom1_EventScript_27A77A:: @ 827A77A
	closemessage
	release
	removeobject 13
	special sub_80F8EB8
	call LinkContestRoom1_EventScript_27A133
	switch VAR_0x8006
	case 0, LinkContestRoom1_EventScript_27A7B9
	case 1, LinkContestRoom1_EventScript_27A7CB
	case 2, LinkContestRoom1_EventScript_27A7DD
	case 3, LinkContestRoom1_EventScript_27A7EF
	return

LinkContestRoom1_EventScript_27A7B9:: @ 827A7B9
	call LinkContestRoom1_EventScript_27A133
	lockall
	applymovement VAR_0x800B, LinkContestRoom1_Movement_27AD58
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27A7CB:: @ 827A7CB
	call LinkContestRoom1_EventScript_27A133
	lockall
	applymovement VAR_0x800B, LinkContestRoom1_Movement_27AD62
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27A7DD:: @ 827A7DD
	call LinkContestRoom1_EventScript_27A133
	lockall
	applymovement VAR_0x800B, LinkContestRoom1_Movement_27AD6A
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27A7EF:: @ 827A7EF
	call LinkContestRoom1_EventScript_27A133
	lockall
	applymovement VAR_0x800B, LinkContestRoom1_Movement_27AD74
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27A801:: @ 827A801
	lockall
	applymovement 1, LinkContestRoom1_Movement_27AD27
	waitmovement 0
	call LinkContestRoom1_EventScript_27A133
	call LinkContestRoom1_EventScript_27A853
	waitmessage
	applymovement 1, LinkContestRoom1_Movement_27AD15
	applymovement 2, LinkContestRoom1_Movement_27AD19
	waitmovement 0
	releaseall
	call LinkContestRoom1_EventScript_27A133
	setvar VAR_TEMP_9, 1
	special sub_80F910C
	startcontest
	special sub_80F90DC
	setvar VAR_TEMP_9, 0
	lockall
	applymovement 1, LinkContestRoom1_Movement_27AD19
	applymovement 2, LinkContestRoom1_Movement_27AD15
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27A853:: @ 827A853
	compare VAR_CONTEST_LOCATION, 5
	goto_if_eq LinkContestRoom1_EventScript_27A867
	msgbox LinkContestRoom1_Text_27B904, MSGBOX_DEFAULT
	return

LinkContestRoom1_EventScript_27A867:: @ 827A867
	specialvar VAR_RESULT, sub_80F9160
	compare VAR_RESULT, 1
	goto_if_eq LinkContestRoom1_EventScript_27A87E
	messageautoscroll LinkContestRoom1_Text_27B904
	waitmessage
	return

LinkContestRoom1_EventScript_27A87E:: @ 827A87E
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27CA71
	waitmessage
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27CAD0
	waitmessage
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27CB55
	waitmessage
	call LinkContestRoom1_EventScript_27A133
	return

LinkContestRoom1_EventScript_27A8A5:: @ 827A8A5
	call LinkContestRoom1_EventScript_27A133
	call LinkContestRoom1_EventScript_27A8FB
	call LinkContestRoom1_EventScript_27A133
	call LinkContestRoom1_EventScript_27A91E
	call LinkContestRoom1_EventScript_27A133
	applymovement 1, LinkContestRoom1_Movement_27AD0F
	waitmovement 0
	call LinkContestRoom1_EventScript_27A941
	call LinkContestRoom1_EventScript_27A133
	call LinkContestRoom1_EventScript_27A964
	call LinkContestRoom1_EventScript_27A133
	applymovement 1, LinkContestRoom1_Movement_27AD13
	waitmovement 0
	closemessage
	releaseall
	special sub_80F910C
	setvar VAR_TEMP_9, 1
	showcontestresults
	setvar VAR_TEMP_9, 0
	playbgm MUS_CON_FAN, 0
	return

LinkContestRoom1_EventScript_27A8FB:: @ 827A8FB
	compare VAR_CONTEST_LOCATION, 5
	goto_if_eq LinkContestRoom1_EventScript_27A90F
	msgbox LinkContestRoom1_Text_27BA15, MSGBOX_DEFAULT
	return

LinkContestRoom1_EventScript_27A90F:: @ 827A90F
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27BA15
	waitmessage
	delay 30
	return

LinkContestRoom1_EventScript_27A91E:: @ 827A91E
	compare VAR_CONTEST_LOCATION, 5
	goto_if_eq LinkContestRoom1_EventScript_27A932
	msgbox LinkContestRoom1_Text_27BA30, MSGBOX_DEFAULT
	return

LinkContestRoom1_EventScript_27A932:: @ 827A932
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27BA30
	waitmessage
	delay 30
	return

LinkContestRoom1_EventScript_27A941:: @ 827A941
	compare VAR_CONTEST_LOCATION, 5
	goto_if_eq LinkContestRoom1_EventScript_27A955
	msgbox LinkContestRoom1_Text_27BAAC, MSGBOX_DEFAULT
	return

LinkContestRoom1_EventScript_27A955:: @ 827A955
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27BAAC
	waitmessage
	delay 30
	return

LinkContestRoom1_EventScript_27A964:: @ 827A964
	compare VAR_CONTEST_LOCATION, 5
	goto_if_eq LinkContestRoom1_EventScript_27A978
	msgbox LinkContestRoom1_Text_27BB25, MSGBOX_DEFAULT
	return

LinkContestRoom1_EventScript_27A978:: @ 827A978
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27BB25
	waitmessage
	delay 30
	return

LinkContestRoom1_EventScript_27A987:: @ 827A987
	special sub_80F831C
	switch VAR_0x8005
	case 0, LinkContestRoom1_EventScript_27A9BC
	case 1, LinkContestRoom1_EventScript_27A9C2
	case 2, LinkContestRoom1_EventScript_27A9C8
	case 3, LinkContestRoom1_EventScript_27A9CE
	return

LinkContestRoom1_EventScript_27A9BC:: @ 827A9BC
	setvar VAR_TEMP_3, 3
	return

LinkContestRoom1_EventScript_27A9C2:: @ 827A9C2
	setvar VAR_TEMP_3, 4
	return

LinkContestRoom1_EventScript_27A9C8:: @ 827A9C8
	setvar VAR_TEMP_3, 5
	return

LinkContestRoom1_EventScript_27A9CE:: @ 827A9CE
	setvar VAR_TEMP_3, 14
	return

LinkContestRoom1_EventScript_27A9D4:: @ 827A9D4
	special sub_80F834C
	special sub_80F8390
	addvar VAR_0x8005, 1
	buffernumberstring 1, VAR_0x8005
	addvar VAR_0x8005, 65535
	call LinkContestRoom1_EventScript_27AA00
	applymovement VAR_TEMP_3, LinkContestRoom1_Movement_27AD1D
	waitmovement 0
	playse SE_W227B
	setvar VAR_TEMP_1, 0
	return

LinkContestRoom1_EventScript_27AA00:: @ 827AA00
	compare VAR_CONTEST_LOCATION, 5
	goto_if_eq LinkContestRoom1_EventScript_27AA14
	msgbox LinkContestRoom1_Text_27BB4C, MSGBOX_DEFAULT
	return

LinkContestRoom1_EventScript_27AA14:: @ 827AA14
	messageautoscroll LinkContestRoom1_Text_27BB4C
	waitmessage
	return

LinkContestRoom1_EventScript_27AA1B:: @ 827AA1B
	addvar VAR_TEMP_1, 1
	lockall
	compare VAR_CONTEST_LOCATION, 1
	call_if_gt LinkContestRoom1_EventScript_27AA6F
	applymovement 9, LinkContestRoom1_Movement_27AD3B
	applymovement 12, LinkContestRoom1_Movement_27AD3F
	applymovement 7, LinkContestRoom1_Movement_27AD3B
	delay 30
	applymovement 10, LinkContestRoom1_Movement_27AD33
	applymovement 11, LinkContestRoom1_Movement_27AD3F
	applymovement 6, LinkContestRoom1_Movement_27AD37
	applymovement 8, LinkContestRoom1_Movement_27AD33
	compare VAR_TEMP_1, 4
	goto_if_ne LinkContestRoom1_EventScript_27AA1B
	delay 30
	return

LinkContestRoom1_EventScript_27AA6F:: @ 827AA6F
	turnvobject 0, DIR_SOUTH
	turnvobject 2, DIR_SOUTH
	turnvobject 4, DIR_EAST
	turnvobject 6, DIR_SOUTH
	turnvobject 8, DIR_SOUTH
	turnvobject 10, DIR_SOUTH
	turnvobject 12, DIR_SOUTH
	turnvobject 14, DIR_SOUTH
	turnvobject 16, DIR_SOUTH
	turnvobject 18, DIR_SOUTH
	turnvobject 20, DIR_EAST
	turnvobject 22, DIR_EAST
	turnvobject 25, DIR_EAST
	turnvobject 27, DIR_WEST
	turnvobject 28, DIR_EAST
	delay 10
	turnvobject 0, DIR_EAST
	turnvobject 2, DIR_EAST
	turnvobject 4, DIR_EAST
	turnvobject 6, DIR_EAST
	turnvobject 8, DIR_EAST
	turnvobject 10, DIR_WEST
	turnvobject 12, DIR_WEST
	turnvobject 14, DIR_WEST
	turnvobject 16, DIR_WEST
	turnvobject 18, DIR_WEST
	turnvobject 20, DIR_SOUTH
	turnvobject 22, DIR_SOUTH
	turnvobject 25, DIR_NORTH
	turnvobject 27, DIR_NORTH
	turnvobject 28, DIR_NORTH
	delay 10
	turnvobject 1, DIR_NORTH
	turnvobject 3, DIR_NORTH
	turnvobject 5, DIR_NORTH
	turnvobject 7, DIR_NORTH
	turnvobject 9, DIR_EAST
	turnvobject 11, DIR_NORTH
	turnvobject 15, DIR_NORTH
	turnvobject 13, DIR_NORTH
	turnvobject 17, DIR_NORTH
	turnvobject 19, DIR_NORTH
	turnvobject 21, DIR_WEST
	turnvobject 23, DIR_WEST
	turnvobject 24, DIR_WEST
	turnvobject 26, DIR_EAST
	turnvobject 29, DIR_WEST
	turnvobject 30, DIR_WEST
	delay 10
	turnvobject 1, DIR_EAST
	turnvobject 3, DIR_EAST
	turnvobject 5, DIR_EAST
	turnvobject 7, DIR_EAST
	turnvobject 9, DIR_EAST
	turnvobject 11, DIR_WEST
	turnvobject 15, DIR_WEST
	turnvobject 13, DIR_WEST
	turnvobject 17, DIR_WEST
	turnvobject 19, DIR_WEST
	turnvobject 21, DIR_SOUTH
	turnvobject 23, DIR_SOUTH
	turnvobject 24, DIR_SOUTH
	turnvobject 26, DIR_NORTH
	turnvobject 29, DIR_NORTH
	turnvobject 30, DIR_NORTH
	delay 10
	return

LinkContestRoom1_EventScript_27AB36:: @ 827AB36
	compare VAR_CONTEST_LOCATION, 5
	goto_if_eq LinkContestRoom1_EventScript_27ABD8
	call LinkContestRoom1_EventScript_27AB9E
	goto_if_set FLAG_TEMP_2, LinkContestRoom1_EventScript_27AB82
	lockall
	msgbox LinkContestRoom1_Text_27BBA8, MSGBOX_DEFAULT
	releaseall
	call LinkContestRoom1_EventScript_27ABF8
	call LinkContestRoom1_EventScript_27AC5E
	playse SE_W227B
	setvar VAR_TEMP_1, 0
	call LinkContestRoom1_EventScript_27AA1B
	delay 30
	special sub_80F88E8
	compare VAR_0x8004, 1
	goto_if_eq LinkContestRoom1_EventScript_27ABD2
	return

LinkContestRoom1_EventScript_27AB82:: @ 827AB82
	lockall
	msgbox LinkContestRoom1_Text_27BB7A, MSGBOX_DEFAULT
	releaseall
	delay 90
	special sub_80F88E8
	compare VAR_0x8004, 1
	goto_if_eq LinkContestRoom1_EventScript_27ABD2
	return

LinkContestRoom1_EventScript_27AB9E:: @ 827AB9E
	specialvar VAR_RESULT, sub_80F7F7C
	compare VAR_RESULT, 1
	goto_if_eq LinkContestRoom1_EventScript_27ABAF
	return

LinkContestRoom1_EventScript_27ABAF:: @ 827ABAF
	special sub_80F831C
	compare VAR_0x8005, 3
	goto_if_eq LinkContestRoom1_EventScript_27ABBE
	return

LinkContestRoom1_EventScript_27ABBE:: @ 827ABBE
	compare VAR_CONTEST_RANK, 3
	goto_if_eq LinkContestRoom1_EventScript_27ABCD
	setflag FLAG_TEMP_2
	return

LinkContestRoom1_EventScript_27ABCD:: @ 827ABCD
	return

LinkContestRoom1_EventScript_27ABCE:: @ 827ABCE
	setflag FLAG_CONTEST_SKETCH_CREATED
	return

LinkContestRoom1_EventScript_27ABD2:: @ 827ABD2
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 1
	return

LinkContestRoom1_EventScript_27ABD8:: @ 827ABD8
	delay 60
	special sub_80F84B0
	special sub_80F831C
	special sub_80F88E8
	compare VAR_0x8004, 1
	goto_if_eq LinkContestRoom1_EventScript_27ABF1
	closemessage
	return

LinkContestRoom1_EventScript_27ABF1:: @ 827ABF1
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 2
	return

LinkContestRoom1_EventScript_27ABF7:: @ 827ABF7
	return

LinkContestRoom1_EventScript_27ABF8:: @ 827ABF8
	switch VAR_0x8005
	case 0, LinkContestRoom1_EventScript_27AC2A
	case 1, LinkContestRoom1_EventScript_27AC37
	case 2, LinkContestRoom1_EventScript_27AC44
	case 3, LinkContestRoom1_EventScript_27AC51
	return

LinkContestRoom1_EventScript_27AC2A:: @ 827AC2A
	lockall
	applymovement VAR_TEMP_3, LinkContestRoom1_Movement_27AD7A
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27AC37:: @ 827AC37
	lockall
	applymovement VAR_TEMP_3, LinkContestRoom1_Movement_27AD7E
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27AC44:: @ 827AC44
	lockall
	applymovement VAR_TEMP_3, LinkContestRoom1_Movement_27AD29
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27AC51:: @ 827AC51
	lockall
	applymovement VAR_TEMP_3, LinkContestRoom1_Movement_27AD2D
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27AC5E:: @ 827AC5E
	special sub_80F831C
	compare VAR_0x8005, 3
	goto_if_eq LinkContestRoom1_EventScript_27AC77
	lockall
	msgbox LinkContestRoom1_Text_27BB7A, MSGBOX_DEFAULT
	releaseall
	return

LinkContestRoom1_EventScript_27AC77:: @ 827AC77
	compare VAR_CONTEST_LOCATION, 2
	call_if_eq LinkContestRoom1_EventScript_27ABCE
	specialvar VAR_RESULT, sub_80F7F7C
	compare VAR_RESULT, 0
	goto_if_eq LinkContestRoom1_EventScript_27ACDF
	compare VAR_CONTEST_RANK, 3
	goto_if_eq LinkContestRoom1_EventScript_27ACBD
	lockall
	msgbox LinkContestRoom1_Text_27BB7A, MSGBOX_DEFAULT
	releaseall
	return

LinkContestRoom1_EventScript_27ACA8:: @ 827ACA8
	lockall
	call Common_EventScript_BagIsFull
	msgbox LinkContestRoom1_Text_27BC2F, MSGBOX_DEFAULT
	releaseall
	setvar VAR_CONTEST_PRIZE_PICKUP, 4
	return

LinkContestRoom1_EventScript_27ACBD:: @ 827ACBD
	giveitem_std ITEM_LUXURY_BALL
	compare VAR_RESULT, 0
	goto_if_eq LinkContestRoom1_EventScript_27ACA8
	lockall
	msgbox LinkContestRoom1_Text_27BB7A, MSGBOX_DEFAULT
	releaseall
	return

LinkContestRoom1_EventScript_27ACDF:: @ 827ACDF
	special sub_80F7FFC
	incrementgamestat GAME_STAT_RECEIVED_RIBBONS
	setflag FLAG_SYS_RIBBON_GET
	lockall
	msgbox LinkContestRoom1_Text_27BBD4, MSGBOX_DEFAULT
	playfanfare MUS_FANFA4
	msgbox LinkContestRoom1_Text_27BC00, MSGBOX_DEFAULT
	waitfanfare
	special sub_80F8390
	msgbox LinkContestRoom1_Text_27BC16, MSGBOX_DEFAULT
	releaseall
	return

LinkContestRoom1_Movement_27AD09: @ 827AD09
	walk_down
	step_end

LinkContestRoom1_Movement_27AD0B: @ 827AD0B
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

LinkContestRoom1_Movement_27AD0F: @ 827AD0F
	walk_in_place_fastest_right
	step_end

LinkContestRoom1_Movement_27AD11: @ 827AD11
	emote_heart
	step_end

LinkContestRoom1_Movement_27AD13: @ 827AD13
	walk_in_place_fastest_down
	step_end

LinkContestRoom1_Movement_27AD15: @ 827AD15
	walk_left
	walk_left
	walk_in_place_fastest_down
	step_end

LinkContestRoom1_Movement_27AD19: @ 827AD19
	walk_right
	walk_right
	walk_in_place_fastest_down
	step_end

LinkContestRoom1_Movement_27AD1D: @ 827AD1D
	walk_up
	walk_in_place_fastest_down
	step_end

LinkContestRoom1_Movement_27AD20: @ 827AD20
	delay_16
	delay_16
	step_end

LinkContestRoom1_Movement_27AD23: @ 827AD23
	walk_in_place_fastest_right
	step_end

LinkContestRoom1_Movement_27AD25: @ 827AD25
	walk_in_place_fastest_left
	step_end

LinkContestRoom1_Movement_27AD27: @ 827AD27
	walk_in_place_fastest_down
	step_end

LinkContestRoom1_Movement_27AD29: @ 827AD29
	walk_left
	walk_left
	walk_up
	step_end

LinkContestRoom1_Movement_27AD2D: @ 827AD2D
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

LinkContestRoom1_Movement_27AD33: @ 827AD33
	face_left
	delay_16
	face_original_direction
	step_end

LinkContestRoom1_Movement_27AD37: @ 827AD37
	face_up
	delay_16
	face_original_direction
	step_end

LinkContestRoom1_Movement_27AD3B: @ 827AD3B
	face_right
	delay_16
	face_original_direction
	step_end

LinkContestRoom1_Movement_27AD3F: @ 827AD3F
	face_down
	delay_16
	face_original_direction
	step_end

LinkContestRoom1_Movement_27AD43: @ 827AD43
	face_up
	step_end

LinkContestRoom1_Movement_27AD45: @ 827AD45
	face_up
	delay_16
	walk_in_place_fastest_right
	step_end

LinkContestRoom1_Movement_27AD49: @ 827AD49
	walk_in_place_fastest_left
	delay_16
	delay_16
	walk_in_place_fastest_down
	step_end

LinkContestRoom1_Movement_27AD4E: @ 827AD4E
	delay_16
	delay_16
	walk_in_place_fastest_down
	step_end

LinkContestRoom1_Movement_27AD52: @ 827AD52
	walk_up
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

LinkContestRoom1_Movement_27AD58: @ 827AD58
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_in_place_fastest_up
	step_end

LinkContestRoom1_Movement_27AD5E: @ 827AD5E
	walk_up
	walk_right
	walk_in_place_fastest_up
	step_end

LinkContestRoom1_Movement_27AD62: @ 827AD62
	walk_fast_left
	walk_fast_down
	walk_in_place_fastest_up
	step_end

LinkContestRoom1_Movement_27AD66: @ 827AD66
	walk_up
	walk_left
	walk_in_place_fastest_up
	step_end

LinkContestRoom1_Movement_27AD6A: @ 827AD6A
	walk_fast_right
	walk_fast_down
	walk_in_place_fastest_up
	step_end

LinkContestRoom1_Movement_27AD6E: @ 827AD6E
	walk_up
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

LinkContestRoom1_Movement_27AD74: @ 827AD74
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_in_place_fastest_up
	step_end

LinkContestRoom1_Movement_27AD7A: @ 827AD7A
	walk_right
	walk_right
	walk_up
	step_end

LinkContestRoom1_Movement_27AD7E: @ 827AD7E
	walk_up
	step_end

LinkContestRoom1_EventScript_27AD80:: @ 827AD80
	specialvar VAR_RESULT, sub_80F9134
	compare VAR_RESULT, 1
	goto_if_eq LinkContestRoom1_EventScript_27AD91
	return

LinkContestRoom1_EventScript_27AD91:: @ 827AD91
	return

LilycoveCity_ContestLobby_EventScript_27AD92:: @ 827AD92
	specialvar VAR_RESULT, sub_80F9134
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_ContestLobby_EventScript_27ADA3
	return

LilycoveCity_ContestLobby_EventScript_27ADA3:: @ 827ADA3
	delay 9
	return

LilycoveCity_ContestLobby_Text_27ADA7: @ 827ADA7
	.string "Bonjour!\p"
	.string "Vous êtes à la réception des\n"
	.string "CONCOURS POKéMON.\p"
	.string "Oh? Mais vous n'avez pas encore\n"
	.string "de BOITE {POKEBLOCK}.\p"
	.string "Dans ce cas, nous allons vous en\n"
	.string "fournir une!$"

LilycoveCity_ContestLobby_Text_27AE47: @ 827AE47
	.string "OK, maintenant que le problème\n"
	.string "est réglé…\p"
	.string "Bonjour!\p"
	.string "Vous êtes à la réception des\n"
	.string "CONCOURS POKéMON.$"

LilycoveCity_ContestLobby_Text_27AEA8: @ 827AEA8
	.string "Bonjour!\p"
	.string "Nous prenons les inscriptions aux\n"
	.string "CONCOURS POKéMON.$"

LilycoveCity_ContestLobby_Text_27AEE3: @ 827AEE3
	.string "Hello!\p"
	.string "This reception counter is only\n"
	.string "for 4-player POKéMON CONTESTS.$"

LilycoveCity_ContestLobby_Text_27AF28: @ 827AF28
	.string "Voulez-vous faire participer un de vos\n"
	.string "POKéMON à un CONCOURS?$"

LilycoveCity_ContestLobby_Text_27AF5E: @ 827AF5E
	.string "A quel sujet?$"

LilycoveCity_ContestLobby_Text_27AF7A: @ 827AF7A
	.string "Dans un CONCOURS POKéMON, il y a quatre\n"
	.string "DRESSEURS qui font chacun participer\l"
	.string "un POKéMON.\p"
	.string "Un CONCOURS comporte un jugement\n"
	.string "préliminaire et un jugement secondaire.\p"
	.string "Le jugement préliminaire est un\n"
	.string "jugement auquel participe le public.\p"
	.string "Le jugement secondaire concerne les\n"
	.string "démonstrations de capacités.\p"
	.string "Il faut préparer ses démonstrations\n"
	.string "afin d'attirer l'attention du JUGE et\l"
	.string "d'enthousiasmer le public.\p"
	.string "Faites de votre mieux pour vous\n"
	.string "imposer.\p"
	.string "Les scores obtenus au premier tour et\n"
	.string "au second tour sont totalisés à la fin.\p"
	.string "Le POKéMON obtenant le score total le\n"
	.string "plus élevé est déclaré vainqueur.$"

LilycoveCity_ContestLobby_Text_27B17D: @ 827B17D
	.string "Il y a cinq types de CONCOURS:\p"
	.string "SANG-FROID, BEAUTE, GRACE,\n"
	.string "INTELLIGENCE et ROBUSTESSE.\p"
	.string "Il faut choisir le CONCOURS en fonction\n"
	.string "du POKéMON que vous voulez inscrire.$"

LilycoveCity_ContestLobby_Text_27B221: @ 827B221
	.string "Il y a quatre catégories de CONCOURS\n"
	.string "POKéMON:\p"
	.string "NORMAL, SUPER, HYPER et MASTER.\p"
	.string "Tous les POKéMON peuvent s'inscrire\n"
	.string "dans la catégorie NORMAL.\p"
	.string "Un POKéMON remportant un CONCOURS\n"
	.string "catégorie NORMAL peut passer à la\l"
	.string "catégorie SUPER du même CONCOURS.\p"
	.string "De même, gagner la catégorie\n"
	.string "SUPER permet de passer à la catégorie\l"
	.string "HYPER et gagner la catégorie HYPER\l"
	.string "permet de passer à la catégorie MASTER.\p"
	.string "Après une victoire dans la catégorie\n"
	.string "MASTER, le POKéMON peut être présenté\l"
	.string "dans cette catégorie à tout moment.$"

LilycoveCity_ContestLobby_Text_27B3FF: @ 827B3FF
	.string "Dans quelle catégorie souhaitez-vous\n"
	.string "participer?$"

LilycoveCity_ContestLobby_Text_27B423: @ 827B423
	.string "Quel CONCOURS choisissez-vous?$"

LilycoveCity_ContestLobby_Text_27B44A: @ 827B44A
	.string "Quel POKéMON choisissez-vous?$"

LilycoveCity_ContestLobby_Text_27B471: @ 827B471
	.string "Quel dommage, votre POKéMON n'est pas\n"
	.string "encore assez qualifié pour concourir\l"
	.string "dans cette catégorie…$"

LilycoveCity_ContestLobby_Text_27B4C4: @ 827B4C4
	.string "Un OEUF ne peut malheureusement pas\n"
	.string "participer à un CONCOURS POKéMON.$"

LilycoveCity_ContestLobby_Text_27B501: @ 827B501
	.string "Votre POKéMON n'est pas en \n"
	.string "état de participer à un CONCOURS…$"

LilycoveCity_ContestLobby_Text_27B547: @ 827B547
	.string "Oh, mais ce RUBAN…\p"
	.string "Votre POKéMON a déjà gagné ce\n"
	.string "CONCOURS, n'est-ce pas?\p"
	.string "Vous voulez quand même l'inscrire à\n"
	.string "ce CONCOURS?$"

LilycoveCity_ContestLobby_Text_27B5C4: @ 827B5C4
	.string "Est-ce votre POKéMON DE CONCOURS?$"

LilycoveCity_ContestLobby_Text_27B5E2: @ 827B5E2
	.string "D'accord, je vais inscrire votre POKéMON\n"
	.string "au CONCOURS.\p"
	.string "Votre POKéMON sera le concurrent Nº 4.\n"
	.string "Le CONCOURS va bientôt débuter.$"

LilycoveCity_ContestLobby_Text_27B653: @ 827B653
	.string "Veuillez entrer.\n"
	.string "Bonne chance!$"

LilycoveCity_ContestLobby_Text_27B67B: @ 827B67B
	.string "Félicitations! Votre POKéMON remporte\n"
	.string "le CONCOURS!\p"
	.string "Nous allons vous donner votre prix.\n"
	.string "Par ici, je vous en prie!$"

LilycoveCity_ContestLobby_Text_27B6E7: @ 827B6E7
	.string "Repassez plus tard pour prendre votre\n"
	.string "prix.$"

LinkContestRoom1_Text_27B711: @ 827B711
	.string "ANIMATRICE: Votre attention! Je n'ai\n"
	.string "qu'un mot à dire: {STR_VAR_2}! Que le\l"
	.string "CONCOURS catégorie {STR_VAR_3} commence!\p"
	.string "Voici les DRESSEURS en compétition\n"
	.string "et leurs POKéMON.$"

LinkContestRoom1_Text_27B78F: @ 827B78F
	.string "ANIMATRICE: Votre attention! Je n'ai\n"
	.string "qu'un mot à dire: {STR_VAR_2}! Que le\l"
	.string "CONCOURS en link avec 4 joueurs\l"
	.string "commence!\p"
	.string "Voici les DRESSEURS en compétition\n"
	.string "et leurs POKéMON.$"

LinkContestRoom1_Text_27B815: @ 827B815
	.string "ANIMATRICE: Concurrent Nº {STR_VAR_2}!\n"
	.string "{STR_VAR_3} de {STR_VAR_1}!$"

LinkContestRoom1_Text_27B830: @ 827B830
	.string "ANIMATRICE: Nous venons de voir les\n"
	.string "quatre concurrents POKéMON.\p"
	.string "Maintenant, c'est le jugement\n"
	.string "préliminaire!\p"
	.string "Les membres du public vont choisir\n"
	.string "leurs concurrents POKéMON préférés.\p"
	.string "N'attendons pas une minute de plus, que\n"
	.string "le vote commence!$"

LinkContestRoom1_Text_27B8F2: @ 827B8F2
	.string "Vote en cours…$"

LinkContestRoom1_Text_27B904: @ 827B904
	.string "Le vote est achevé!\p"
	.string "Pendant le comptage des voix, \n"
	.string "passons au jugement secondaire!\p"
	.string "Il s'agit du moment très attendu des\n"
	.string "démonstrations!\p"
	.string "Que les concurrents nous éblouissent!\p"
	.string "Un peu d'enthousiasme!\n"
	.string "Place aux démonstrations!$"

LinkContestRoom1_Text_27BA15: @ 827BA15
	.string "ANIMATRICE: Le second tour est\n"
	.string "terminé!$"

LinkContestRoom1_Text_27BA30: @ 827BA30
	.string "Merci à tous pour ces démonstrations\n"
	.string "d'une rare qualité!\p"
	.string "Les délibérations touchent à leur fin!\n"
	.string "Merci pour vos efforts!$"

LinkContestRoom1_Text_27BAAC: @ 827BAAC
	.string "Maintenant il ne reste plus qu'à\n"
	.string "annoncer le grand gagnant.\p"
	.string "Le JUGE est prêt à faire son\n"
	.string "annonce!$"

LinkContestRoom1_Text_27BB25: @ 827BB25
	.string "JUGE: Je vais annoncer le vainqueur!$"

LinkContestRoom1_Text_27BB4C: @ 827BB4C
	.string "ANIMATRICE: Concurrent Nº {STR_VAR_2}!\p"
	.string "Félicitations,\n"
	.string "{STR_VAR_3} et {STR_VAR_1}!$"

LinkContestRoom1_Text_27BB7A: @ 827BB7A
	.string "ANIMATRICE: Félicitations!\n"
	.string "J'espère vous revoir bientôt!$"

LinkContestRoom1_Text_27BBA8: @ 827BBA8
	.string "ANIMATRICE: Tenez!\n"
	.string "Voici votre prix!$"

LinkContestRoom1_Text_27BBD4: @ 827BBD4
	.string "Pour récompenser votre victoire,\n"
	.string "voici ce RUBAN!$"

LinkContestRoom1_Text_27BC00: @ 827BC00
	.string "{PLAYER} reçoit un RUBAN.$"

LinkContestRoom1_Text_27BC16: @ 827BC16
	.string "{PLAYER} met le RUBAN sur\n"
	.string "{STR_VAR_1}.$"

LinkContestRoom1_Text_27BC2F: @ 827BC2F
	.string "Venez chercher votre prix plus tard\n"
	.string "à l'accueil.\l"
	.string "J'espère vous revoir bientôt!$"

LinkContestRoom1_Text_27BC82: @ 827BC82
	.string "I only register four players for\n"
	.string "POKéMON CONTESTS.\p"
	.string "If three other players link up, all\n"
	.string "four may enter the same CONTEST.\p"
	.string "Would you like to take part?$"

LilycoveCity_ContestLobby_Text_27BD17: @ 827BD17
	.string "Avant de débuter un CONCOURS,\n"
	.string "il faut sauvegarder sa partie.$"

LilycoveCity_ContestLobby_Text_27BD4F: @ 827BD4F
	.string "Nous espérons vous compter parmi\n"
	.string "nos participants une prochaine fois.$"

LilycoveCity_ContestLobby_Text_27BD7A: @ 827BD7A
	.string "Would you like to enter a CONTEST?$"

LilycoveCity_ContestLobby_Text_27BD9D: @ 827BD9D
	.string "When four players are ready, connect\n"
	.string "over a Game Link cable, and register\l"
	.string "with me, please.\p"
	.string "Please choose the same CONTEST\n"
	.string "as your fellow contestants.\p"
	.string "The CONTEST begins as soon as all\n"
	.string "players register their entry.\p"
	.string "After that, the usual CONTEST rules\n"
	.string "apply.$"

LilycoveCity_ContestLobby_Text_27BE9E: @ 827BE9E
	.string "Which CONTEST would you like to enter?$"

LilycoveCity_ContestLobby_Text_27BEC5: @ 827BEC5
	.string "Which POKéMON would you like to enter?$"

LilycoveCity_ContestLobby_Text_27BEEC: @ 827BEEC
	.string "Transmission…$"

LilycoveCity_ContestLobby_Text_27BEFA: @ 827BEFA
	.string "Erreur de transmission…$"

LilycoveCity_ContestLobby_Text_27BF0E: @ 827BF0E
	.string "Vous avez peut-être choisi un\n"
	.string "CONCOURS différent des autres joueurs.$"

LilycoveCity_ContestLobby_Text_27BF4B: @ 827BF4B
	.string "Vous avez peut-être fait un choix\n"
	.string "différent des autres joueurs.$"

LilycoveCity_ContestLobby_Text_27BF85: @ 827BF85
	.string "Veuillez patienter.\n"
	.string "Appuyez sur le bouton B pour annuler…$"

LilycoveCity_ContestLobby_Text_27BFA7: @ 827BFA7
	.string "We hope you will participate another\n"
	.string "time.$"

LilycoveCity_ContestLobby_Text_27BFD2: @ 827BFD2
	.string "Transmission error.\n"
	.string "Please try again.$"

LilycoveCity_ContestLobby_Text_27BFF8: @ 827BFF8
	.string "Je vais inscrire votre POKéMON au\n"
	.string "CONCOURS.\p"
	.string "Votre POKéMON sera le concurrent Nº {STR_VAR_2}.$"

LilycoveCity_ContestLobby_Text_27C043: @ 827C043
	.string "Le CONCOURS va bientôt débuter.$"

LilycoveCity_ContestLobby_Text_27C063: @ 827C063
	.string "Bienvenue. Vous êtes à la réception\n"
	.string "des CONCOURS POKéMON en link.\p"
	.string "Vous pouvez participer aux CONCOURS\n"
	.string "avec un ou plusieurs amis.$"

LilycoveCity_ContestLobby_Text_27C0DA: @ 827C0DA
	.string "A quel sujet?$"

LilycoveCity_ContestLobby_Text_27C0F6: @ 827C0F6
	.string "Voulez-vous participer à un CONCOURS?$"

LilycoveCity_ContestLobby_Text_27C119: @ 827C119
	.string "Quel CONCOURS choisissez-vous?$"

LilycoveCity_ContestLobby_Text_27C140: @ 827C140
	.string "Votre POKéMON n'est pas en \n"
	.string "état de participer à un CONCOURS…$"

LilycoveCity_ContestLobby_Text_27C186: @ 827C186
	.string "Un OEUF ne peut malheureusement pas\n"
	.string "participer à un CONCOURS POKéMON.$"

LilycoveCity_ContestLobby_Text_27C1C3: @ 827C1C3
	.string "Quel POKéMON choisissez-vous?$"

Text_DecideLinkLeader: @ 827C1EA
	.string "Veuillez choisir lequel de vous\n"
	.string "deux sera le MENEUR.\p"
	.string "L'autre joueur devra ensuite\n"
	.string "choisir “JOINDRE”.$"

LilycoveCity_ContestLobby_Text_27C254: @ 827C254
	.string "Au moins un joueur est entré en\n"
	.string "utilisant la réception 4-joueurs.\p"
	.string "Quatre joueurs doivent être connectés\n"
	.string "avec des câbles GBA Game Link.\p"
	.string "Quand tous les joueurs sont prêts,\n"
	.string "sélectionnez MODE-G (MODE GLOBAL)\l"
	.string "et enregistrez-vous de nouveau.$"

LilycoveCity_ContestLobby_Text_27C340: @ 827C340
	.string "C'est un CONCOURS pour deux à quatre\n"
	.string "joueurs connectés avec des câbles GBA\l"
	.string "Game Link ou des adaptateurs sans fil.\p"
	.string "Les participants doivent d'abord\n"
	.string "choisir le mode auquel ils\l"
	.string "veulent jouer.\p"
	.string "Il y a deux modes différents.\p"
	.string "Le MODE-E (MODE EMERAUDE) est pour\n"
	.string "deux à quatre joueurs ayant chacun une\l"
	.string "cartouche de jeu POKéMON Emeraude.\p"
	.string "Le MODE-G (MODE GLOBAL) est seulement\n"
	.string "pour quatre joueurs ayant chacun une\p"
	.string "cartouche de jeu POKéMON Emeraude,\n"
	.string "Rubis ou Saphir.\p"
	.string "Les joueurs doivent discuter ensemble\n"
	.string "du mode qu'ils veulent utiliser et\l"
	.string "choisir ensuite le même.\p"
	.string "L'inscription se termine une fois que\n"
	.string "tous les joueurs ont choisi le même\l"
	.string "CONCOURS dans le même mode.\p"
	.string "Après ça, le CONCOURS débute\n"
	.string "normalement.$"

LilycoveCity_ContestLobby_Text_27C5B1: @ 827C5B1
	.string "Dans le MODE-E (MODE EMERAUDE),\n"
	.string "un CONCOURS LINK prend place avec\l"
	.string "deux à quatre joueurs ayant chacun\l"
	.string "une cartouche de jeu POKéMON Emeraude.\p"
	.string "Les joueurs doivent être connectés en\n"
	.string "utilisant des câbles GBA Game Link ou\l"
	.string "des adaptateurs sans fil.\p"
	.string "S'il y a moins de quatre joueurs, des\n"
	.string "DRESSEURS se trouvant dans le hall\l"
	.string "viendront pour compléter la partie.\p"
	.string "Veuillez noter que le MODE-E n'est\n"
	.string "pas disponible dans POKéMON Rubis\l"
	.string "ou Saphir.$"

LilycoveCity_ContestLobby_Text_27C742: @ 827C742
	.string "Le MODE-G (MODE GLOBAL) est\n"
	.string "spécifiquement conçu pour quatre\p"
	.string "joueurs connectés avec des\n"
	.string "câbles GBA Game Link.\p"
	.string "Chaque joueur doit utiliser une\n"
	.string "cartouche de jeu POKéMON Emeraude,\l"
	.string "Rubis ou Saphir.\p"
	.string "Le CONCOURS commence dès que\n"
	.string "tous les joueurs ont choisi MODE-G\l"
	.string "(POKéMON Emeraude) ou sont\l"
	.string "entrés en passant par la réception\l"
	.string "4-joueurs (POKéMON Rubis ou Saphir).$"

LilycoveCity_ContestLobby_Text_27C879: @ 827C879
	.string "Je suis terriblement désolée.\p"
	.string "Le MODE-G ne fonctionne pas avec\n"
	.string "les adaptateurs sans fil.\p"
	.string "Veuillez sélectionner le MODE-E ou\n"
	.string "essayez avec des câbles GBA Game Link.$"

LilycoveCity_ContestLobby_Text_27C8FD: @ 827C8FD
	.string "A quel MODE CONCOURS\n"
	.string "voulez-vous participer?$"

LinkContestRoom1_Text_27C929: @ 827C929
	.string "ANIMATRICE: Votre attention! Je n'ai\n"
	.string "qu'un mot à dire: {STR_VAR_2}! Que le\l"
	.string "CONCOURS en link avec 4 joueurs\l"
	.string "commence!$"

LinkContestRoom1_Text_27C972: @ 827C972
	.string "Voici les DRESSEURS en compétition\n"
	.string "et leurs POKéMON:$"

LinkContestRoom1_Text_27C9AF: @ 827C9AF
	.string "ANIMATRICE: Nous venons de voir les\n"
	.string "quatre concurrents POKéMON.\p"
	.string "Maintenant, c'est le jugement\n"
	.string "préliminaire!$"

LinkContestRoom1_Text_27CA04: @ 827CA04
	.string "Les membres du public vont choisir\n"
	.string "leurs concurrents POKéMON préférés.$"

LinkContestRoom1_Text_27CA42: @ 827CA42
	.string "N'attendons pas une minute de plus, que\n"
	.string "le vote commence!$"

LinkContestRoom1_Text_27CA71: @ 827CA71
	.string "Le vote est achevé!\p"
	.string "Pendant le comptage des voix, \n"
	.string "passons au jugement secondaire!$"

LinkContestRoom1_Text_27CAD0: @ 827CAD0
	.string "Il s'agit du moment très attendu des\n"
	.string "démonstrations!\p"
	.string "Que les concurrents nous éblouissent!$"

LinkContestRoom1_Text_27CB55: @ 827CB55
	.string "Un peu d'enthousiasme!\n"
	.string "Place aux démonstrations!$"
