MauvilleCity_GameCorner_MapScripts:: @ 820FBB8
	.byte 0

MauvilleCity_GameCorner_EventScript_20FBB9:: @ 820FBB9
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_210460, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_20FCB7
	message MauvilleCity_GameCorner_Text_2104DF
	waitmessage
	showmoneybox 0, 0, 0
	showcoinsbox 1, 6
	goto MauvilleCity_GameCorner_EventScript_20FBE5

MauvilleCity_GameCorner_EventScript_20FBE5:: @ 820FBE5
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, 0
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_20FC33
	case 1, MauvilleCity_GameCorner_EventScript_20FC75
	goto MauvilleCity_GameCorner_EventScript_20FCD1
	end

MauvilleCity_GameCorner_EventScript_20FC0C:: @ 820FC0C
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 1, 0
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_20FC33
	case 1, MauvilleCity_GameCorner_EventScript_20FC75
	goto MauvilleCity_GameCorner_EventScript_20FCD1
	end

MauvilleCity_GameCorner_EventScript_20FC33:: @ 820FC33
	checkcoins VAR_TEMP_1
	compare VAR_TEMP_1, 9950
	goto_if_ge MauvilleCity_GameCorner_EventScript_20FCE1
	checkmoney 1000, 0
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_20FCC1
	givecoins 50
	takemoney 1000, 0
	updatemoneybox 0, 0
	updatecoinsbox 1, 6
	playse SE_REGI
	msgbox MauvilleCity_GameCorner_Text_210529, MSGBOX_DEFAULT
	hidemoneybox
	nop
	nop
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_20FC75:: @ 820FC75
	checkcoins VAR_TEMP_1
	compare VAR_TEMP_1, 9500
	goto_if_ge MauvilleCity_GameCorner_EventScript_20FCE1
	checkmoney 10000, 0
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_20FCC1
	givecoins 500
	takemoney 10000, 0
	updatemoneybox 0, 0
	updatecoinsbox 1, 6
	playse SE_REGI
	msgbox MauvilleCity_GameCorner_Text_210529, MSGBOX_DEFAULT
	hidemoneybox
	nop
	nop
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_20FCB7:: @ 820FCB7
	msgbox MauvilleCity_GameCorner_Text_21047E, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_20FCC1:: @ 820FCC1
	msgbox MauvilleCity_GameCorner_Text_210553, MSGBOX_DEFAULT
	hidemoneybox
	nop
	nop
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_20FCD1:: @ 820FCD1
	msgbox MauvilleCity_GameCorner_Text_21059A, MSGBOX_DEFAULT
	hidemoneybox
	nop
	nop
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_20FCE1:: @ 820FCE1
	msgbox MauvilleCity_GameCorner_Text_21057E, MSGBOX_DEFAULT
	hidemoneybox
	nop
	nop
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_20FCF1:: @ 820FCF1
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_2105D7, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_GameCorner_EventScript_20FD0D
	release
	end

MauvilleCity_GameCorner_EventScript_20FD0D:: @ 820FD0D
	message MauvilleCity_GameCorner_Text_21060D
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto MauvilleCity_GameCorner_EventScript_20FD2B

MauvilleCity_GameCorner_EventScript_20FD20:: @ 820FD20
	message MauvilleCity_GameCorner_Text_21060D
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_20FD2B

MauvilleCity_GameCorner_EventScript_20FD2B:: @ 820FD2B
	multichoice 12, 0, MULTI_GAME_CORNER_DOLLS, 0
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_20FD67
	case 1, MauvilleCity_GameCorner_EventScript_20FD75
	case 2, MauvilleCity_GameCorner_EventScript_20FD83
	case 3, MauvilleCity_GameCorner_EventScript_20FE92
	goto MauvilleCity_GameCorner_EventScript_20FE92
	end

MauvilleCity_GameCorner_EventScript_20FD67:: @ 820FD67
	setvar VAR_TEMP_1, 1
	bufferdecorationname 0, DECOR_TREECKO_DOLL
	goto MauvilleCity_GameCorner_EventScript_20FD91

MauvilleCity_GameCorner_EventScript_20FD75:: @ 820FD75
	setvar VAR_TEMP_1, 2
	bufferdecorationname 0, DECOR_TORCHIC_DOLL
	goto MauvilleCity_GameCorner_EventScript_20FD91

MauvilleCity_GameCorner_EventScript_20FD83:: @ 820FD83
	setvar VAR_TEMP_1, 3
	bufferdecorationname 0, DECOR_MUDKIP_DOLL
	goto MauvilleCity_GameCorner_EventScript_20FD91

MauvilleCity_GameCorner_EventScript_20FD91:: @ 820FD91
	msgbox MauvilleCity_GameCorner_Text_210705, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_20FE92
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_20FDCB
	case 2, MauvilleCity_GameCorner_EventScript_20FE05
	case 3, MauvilleCity_GameCorner_EventScript_20FE3F
	end

MauvilleCity_GameCorner_EventScript_20FDCB:: @ 820FDCB
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, 1000
	goto_if_lt MauvilleCity_GameCorner_EventScript_20FE79
	bufferdecorationname 1, DECOR_TREECKO_DOLL
	checkdecorspace DECOR_TREECKO_DOLL
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_20FE87
	takecoins 1000
	givedecoration DECOR_TREECKO_DOLL
	updatecoinsbox 1, 1
	playse SE_REGI
	msgbox MauvilleCity_GameCorner_Text_210646, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_20FD20
	end

MauvilleCity_GameCorner_EventScript_20FE05:: @ 820FE05
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, 1000
	goto_if_lt MauvilleCity_GameCorner_EventScript_20FE79
	bufferdecorationname 1, DECOR_TORCHIC_DOLL
	checkdecorspace DECOR_TORCHIC_DOLL
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_20FE87
	takecoins 1000
	givedecoration DECOR_TORCHIC_DOLL
	updatecoinsbox 1, 1
	playse SE_REGI
	msgbox MauvilleCity_GameCorner_Text_210646, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_20FD20
	end

MauvilleCity_GameCorner_EventScript_20FE3F:: @ 820FE3F
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, 1000
	goto_if_lt MauvilleCity_GameCorner_EventScript_20FE79
	bufferdecorationname 1, DECOR_MUDKIP_DOLL
	checkdecorspace DECOR_MUDKIP_DOLL
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_20FE87
	takecoins 1000
	givedecoration DECOR_MUDKIP_DOLL
	updatecoinsbox 1, 1
	playse SE_REGI
	msgbox MauvilleCity_GameCorner_Text_210646, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_20FD20
	end

MauvilleCity_GameCorner_EventScript_20FE79:: @ 820FE79
	msgbox MauvilleCity_GameCorner_Text_210673, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_20FD20
	end

MauvilleCity_GameCorner_EventScript_20FE87:: @ 820FE87
	call Common_EventScript_NoRoomLeftForAnother
	goto MauvilleCity_GameCorner_EventScript_20FD20
	end

MauvilleCity_GameCorner_EventScript_20FE92:: @ 820FE92
	msgbox MauvilleCity_GameCorner_Text_2106BF, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

MauvilleCity_GameCorner_EventScript_20FE9F:: @ 820FE9F
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_2105D7, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_GameCorner_EventScript_20FEBB
	release
	end

MauvilleCity_GameCorner_EventScript_20FEBB:: @ 820FEBB
	message MauvilleCity_GameCorner_Text_21060D
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto MauvilleCity_GameCorner_EventScript_20FED9

MauvilleCity_GameCorner_EventScript_20FECE:: @ 820FECE
	message MauvilleCity_GameCorner_Text_21060D
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_20FED9

MauvilleCity_GameCorner_EventScript_20FED9:: @ 820FED9
	multichoice 12, 0, MULTI_GAME_CORNER_TMS, 0
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_20FF2B
	case 1, MauvilleCity_GameCorner_EventScript_20FF3E
	case 2, MauvilleCity_GameCorner_EventScript_20FF51
	case 3, MauvilleCity_GameCorner_EventScript_20FF64
	case 4, MauvilleCity_GameCorner_EventScript_20FF77
	case 5, MauvilleCity_GameCorner_EventScript_210118
	goto MauvilleCity_GameCorner_EventScript_210118
	end

MauvilleCity_GameCorner_EventScript_20FF2B:: @ 820FF2B
	setvar VAR_TEMP_1, 1
	bufferitemname 0, ITEM_TM32
	setvar VAR_0x8004, 320
	goto MauvilleCity_GameCorner_EventScript_20FF8A

MauvilleCity_GameCorner_EventScript_20FF3E:: @ 820FF3E
	setvar VAR_TEMP_1, 2
	bufferitemname 0, ITEM_TM29
	setvar VAR_0x8004, 317
	goto MauvilleCity_GameCorner_EventScript_20FF8A

MauvilleCity_GameCorner_EventScript_20FF51:: @ 820FF51
	setvar VAR_TEMP_1, 3
	bufferitemname 0, ITEM_TM35
	setvar VAR_0x8004, 323
	goto MauvilleCity_GameCorner_EventScript_20FF8A

MauvilleCity_GameCorner_EventScript_20FF64:: @ 820FF64
	setvar VAR_TEMP_1, 4
	bufferitemname 0, ITEM_TM24
	setvar VAR_0x8004, 312
	goto MauvilleCity_GameCorner_EventScript_20FF8A

MauvilleCity_GameCorner_EventScript_20FF77:: @ 820FF77
	setvar VAR_TEMP_1, 5
	bufferitemname 0, ITEM_TM13
	setvar VAR_0x8004, 301
	goto MauvilleCity_GameCorner_EventScript_20FF8A

MauvilleCity_GameCorner_EventScript_20FF8A:: @ 820FF8A
	special BufferTMHMMoveName
	msgbox MauvilleCity_GameCorner_Text_210629, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_210118
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_20FFDD
	case 2, MauvilleCity_GameCorner_EventScript_210017
	case 3, MauvilleCity_GameCorner_EventScript_210051
	case 4, MauvilleCity_GameCorner_EventScript_21008B
	case 5, MauvilleCity_GameCorner_EventScript_2100C5
	end

MauvilleCity_GameCorner_EventScript_20FFDD:: @ 820FFDD
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, 1500
	goto_if_lt MauvilleCity_GameCorner_EventScript_2100FF
	checkitemspace ITEM_TM32, 1
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_21010D
	takecoins 1500
	giveitem ITEM_TM32, 1
	updatecoinsbox 1, 1
	playse SE_REGI
	msgbox MauvilleCity_GameCorner_Text_21071B, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_20FECE
	end

MauvilleCity_GameCorner_EventScript_210017:: @ 8210017
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, 3500
	goto_if_lt MauvilleCity_GameCorner_EventScript_2100FF
	checkitemspace ITEM_TM29, 1
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_21010D
	takecoins 3500
	giveitem ITEM_TM29, 1
	updatecoinsbox 1, 1
	playse SE_REGI
	msgbox MauvilleCity_GameCorner_Text_21071B, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_20FECE
	end

MauvilleCity_GameCorner_EventScript_210051:: @ 8210051
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, 4000
	goto_if_lt MauvilleCity_GameCorner_EventScript_2100FF
	checkitemspace ITEM_TM35, 1
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_21010D
	takecoins 4000
	giveitem ITEM_TM35, 1
	updatecoinsbox 1, 1
	playse SE_REGI
	msgbox MauvilleCity_GameCorner_Text_21071B, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_20FECE
	end

MauvilleCity_GameCorner_EventScript_21008B:: @ 821008B
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, 4000
	goto_if_lt MauvilleCity_GameCorner_EventScript_2100FF
	checkitemspace ITEM_TM24, 1
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_21010D
	takecoins 4000
	giveitem ITEM_TM24, 1
	updatecoinsbox 1, 1
	playse SE_REGI
	msgbox MauvilleCity_GameCorner_Text_21071B, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_20FECE
	end

MauvilleCity_GameCorner_EventScript_2100C5:: @ 82100C5
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, 4000
	goto_if_lt MauvilleCity_GameCorner_EventScript_2100FF
	checkitemspace ITEM_TM13, 1
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_21010D
	takecoins 4000
	giveitem ITEM_TM13, 1
	updatecoinsbox 1, 1
	playse SE_REGI
	msgbox MauvilleCity_GameCorner_Text_21071B, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_20FECE
	end

MauvilleCity_GameCorner_EventScript_2100FF:: @ 82100FF
	msgbox MauvilleCity_GameCorner_Text_210673, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_20FECE
	end

MauvilleCity_GameCorner_EventScript_21010D:: @ 821010D
	call Common_EventScript_BagIsFull
	goto MauvilleCity_GameCorner_EventScript_20FECE
	end

MauvilleCity_GameCorner_EventScript_210118:: @ 8210118
	msgbox MauvilleCity_GameCorner_Text_2106BF, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

MauvilleCity_GameCorner_EventScript_210125:: @ 8210125
	msgbox MauvilleCity_GameCorner_Text_2109D3, MSGBOX_NPC
	end

MauvilleCity_GameCorner_EventScript_21012E:: @ 821012E
	msgbox MauvilleCity_GameCorner_Text_210A05, MSGBOX_NPC
	end

MauvilleCity_GameCorner_EventScript_210137:: @ 8210137
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_STARTER_DOLL, MauvilleCity_GameCorner_EventScript_210213
	msgbox MauvilleCity_GameCorner_Text_210750, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_210209
	switch VAR_STARTER_MON
	case 0, MauvilleCity_GameCorner_EventScript_21017C
	case 1, MauvilleCity_GameCorner_EventScript_2101A6
	case 2, MauvilleCity_GameCorner_EventScript_2101D0
	end

MauvilleCity_GameCorner_EventScript_21017C:: @ 821017C
	bufferdecorationname 1, DECOR_TREECKO_DOLL
	checkdecorspace DECOR_TREECKO_DOLL
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_2101FA
	msgbox MauvilleCity_GameCorner_Text_21079C, MSGBOX_DEFAULT
	givedecoration_std DECOR_TREECKO_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_210213
	end

MauvilleCity_GameCorner_EventScript_2101A6:: @ 82101A6
	bufferdecorationname 1, DECOR_TORCHIC_DOLL
	checkdecorspace DECOR_TORCHIC_DOLL
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_2101FA
	msgbox MauvilleCity_GameCorner_Text_21079C, MSGBOX_DEFAULT
	givedecoration_std DECOR_TORCHIC_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_210213
	end

MauvilleCity_GameCorner_EventScript_2101D0:: @ 82101D0
	bufferdecorationname 1, DECOR_MUDKIP_DOLL
	checkdecorspace DECOR_MUDKIP_DOLL
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_2101FA
	msgbox MauvilleCity_GameCorner_Text_21079C, MSGBOX_DEFAULT
	givedecoration_std DECOR_MUDKIP_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_210213
	end

MauvilleCity_GameCorner_EventScript_2101FA:: @ 82101FA
	call Common_EventScript_NoRoomLeftForAnother
	msgbox MauvilleCity_GameCorner_Text_2107A9, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_210209:: @ 8210209
	msgbox MauvilleCity_GameCorner_Text_2107CE, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_210213:: @ 8210213
	msgbox MauvilleCity_GameCorner_Text_2107FB, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_21021D:: @ 821021D
	lock
	faceplayer
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_GameCorner_EventScript_21023D
	msgbox MauvilleCity_GameCorner_Text_210830, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_2102A9
	end

MauvilleCity_GameCorner_EventScript_21023D:: @ 821023D
	goto_if_set FLAG_RECEIVED_20_COINS, MauvilleCity_GameCorner_EventScript_21026B
	checkcoins VAR_TEMP_1
	compare VAR_TEMP_1, 1
	goto_if_ge MauvilleCity_GameCorner_EventScript_21026B
	setflag FLAG_RECEIVED_20_COINS
	givecoins 20
	msgbox MauvilleCity_GameCorner_Text_2108A0, MSGBOX_DEFAULT
	playse SE_REGI
	goto MauvilleCity_GameCorner_EventScript_21026B
	end

MauvilleCity_GameCorner_EventScript_21026B:: @ 821026B
	msgbox MauvilleCity_GameCorner_Text_2108EF, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_2102A9
	end

MauvilleCity_GameCorner_EventScript_210279:: @ 8210279
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_210932, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_2102A9
	end

MauvilleCity_GameCorner_EventScript_210289:: @ 8210289
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_21098E, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_2102A9
	end

MauvilleCity_GameCorner_EventScript_210299:: @ 8210299
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_210A51, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_2102A9
	end

MauvilleCity_GameCorner_EventScript_2102A9:: @ 82102A9
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_GameCorner_EventScript_2102B6:: @ 82102B6
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_210A82, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_2102A9
	end

MauvilleCity_GameCorner_EventScript_2102C6:: @ 82102C6
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_210B04, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_2102A9
	end

MauvilleCity_GameCorner_EventScript_2102D6:: @ 82102D6
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_2102F6:: @ 82102F6
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_210316:: @ 8210316
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_210336:: @ 8210336
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_210356:: @ 8210356
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_210376:: @ 8210376
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_210396:: @ 8210396
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 6
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_2103B6:: @ 82103B6
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 7
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_2103D6:: @ 82103D6
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 8
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_2103F6:: @ 82103F6
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 9
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_210416:: @ 8210416
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 10
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_210436:: @ 8210436
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 11
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_NoCoinCase:: @ 8210456
	msgbox MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_GameCorner_Text_210460: @ 8210460
	.string "C'est le CASINO DE LAVANDIA.$"

MauvilleCity_GameCorner_Text_21047E: @ 821047E
	.string "Oui, vous vouliez quelques JETONS\n"
	.string "pour jouer?\p"
	.string "Mais vous n'avez pas de BOITE JETONS\n"
	.string "pour les ranger.$"

MauvilleCity_GameCorner_Text_2104DF: @ 82104DF
	.string "Seriez-vous à la recherche de JETONS?\p"
	.string "C'est 1000$ les 50 JETONS.\n"
	.string "Combien en voulez-vous?$"

MauvilleCity_GameCorner_Text_210529: @ 8210529
	.string "Merci beaucoup!\n"
	.string "Voilà vos JETONS!$"

MauvilleCity_GameCorner_Text_210553: @ 8210553
	.string "Hum… Vous n'avez pas l'air d'avoir\n"
	.string "assez d'argent…$"

MauvilleCity_GameCorner_Text_21057E: @ 821057E
	.string "Oh!\n"
	.string "Votre BOITE JETONS est pleine.$"

MauvilleCity_GameCorner_Text_21059A: @ 821059A
	.string "Alors vous n'avez pas besoin de JETONS?\n"
	.string "Bonne chance pour la suite!$"

MauvilleCity_GameCorner_Text_2105D7: @ 82105D7
	.string "Bienvenue.\p"
	.string "Vous pouvez échanger vos JETONS\n"
	.string "contre les prix à gagner ici.$"

MauvilleCity_GameCorner_Text_21060D: @ 821060D
	.string "Quel prix souhaiteriez-vous recevoir?$"

MauvilleCity_GameCorner_Text_210629: @ 8210629
	.string "Vous choisissez\n"
	.string "{STR_VAR_1} {STR_VAR_2}?$"

MauvilleCity_GameCorner_Text_210646: @ 8210646
	.string "Merci!\n"
	.string "Ce sera envoyé chez vous, sur votre PC.$"

MauvilleCity_GameCorner_Text_210673: @ 8210673
	.string "Vous n'avez pas assez de JETONS.$"

MauvilleCity_GameCorner_Text_210690: @ 8210690
	.string "There isn't any room available for\n"
	.string "placing {STR_VAR_1}.$"

MauvilleCity_GameCorner_Text_2106BF: @ 82106BF
	.string "Merci de votre visite.\n"
	.string "Revenez quand vous voulez.$"

MauvilleCity_GameCorner_Text_210705: @ 8210705
	.string "Vous choisissez {STR_VAR_1}?$"

MauvilleCity_GameCorner_Text_21071B: @ 821071B
	.string "Voilà!$"

MauvilleCity_GameCorner_Text_210728: @ 8210728
	.string "Oh, you can't carry any more than that.$"

MauvilleCity_GameCorner_Text_210750: @ 8210750
	.string "Je me suis trompée. J'ai deux fois\n"
	.string "la même POUPEE.\p"
	.string "Tu en veux une?$"

MauvilleCity_GameCorner_Text_21079C: @ 821079C
	.string "Voici!$"

MauvilleCity_GameCorner_Text_2107A9: @ 82107A9
	.string "Hein?\n"
	.string "Tu la veux, mais pas tout de suite?$"

MauvilleCity_GameCorner_Text_2107CE: @ 82107CE
	.string "Oh, ne t'en fais pas!\n"
	.string "Tu sais, tu peux la prendre.$"

MauvilleCity_GameCorner_Text_2107FB: @ 82107FB
	.string "Il y a un prix que j'aimerais bien avoir,\n"
	.string "mais je ne peux pas gagner le jackpot.$"

MauvilleCity_GameCorner_Text_210830: @ 8210830
	.string "Hé, mon p'tit, si tu veux jouer ici,\n"
	.string "il te faut une BOITE JETONS.\p"
	.string "Je pense que la jeune femme de la\n"
	.string "maison voisine en a une. Va la voir!$"

MauvilleCity_GameCorner_Text_2108A0: @ 82108A0
	.string "La chance continue!\n"
	.string "C'est trop pour moi.\p"
	.string "Tiens, prends des JETONS!$"

MauvilleCity_GameCorner_Text_2108EF: @ 82108EF
	.string "On a tous une bonne raison\n"
	.string "d'aimer LAVANDIA.\p"
	.string "La mienne, c'est le CASINO.$"

MauvilleCity_GameCorner_Text_210932: @ 8210932
	.string "La mise n'est pas la même pour\n"
	.string "toutes les tables de ROULETTE.\p"
	.string "Vérifie tes JETONS avant de choisir\n"
	.string "une table de jeu.$"

MauvilleCity_GameCorner_Text_21098E: @ 821098E
	.string "On perd vite la notion du temps ici!\n"
	.string "Je ferais bien de retourner travailler.$"

MauvilleCity_GameCorner_Text_2109D3: @ 82109D3
	.string "Il faut des JETONS pour jouer\n"
	.string "au CASINO.$"

MauvilleCity_GameCorner_Text_210A05: @ 8210A05
	.string "Cette ROULETTE…\n"
	.string "C'est très difficile.\p"
	.string "Gagner ou perdre, tout est une question\n"
	.string "de chance.$"

MauvilleCity_GameCorner_Text_210A51: @ 8210A51
	.string "Il est possible de mettre jusqu'à trois\n"
	.string "JETONS dans une MACHINE A SOUS.$"

MauvilleCity_GameCorner_Text_210A82: @ 8210A82
	.string "C'est très dur de la faire s'arrêter en\n"
	.string "plein sur le “7.”\p"
	.string "Si ça s'arrête sur “7”\n"
	.string "pendant le jeu bonus du REEL TIME, tu\l"
	.string "gagnes des JETONS en plus.$"

MauvilleCity_GameCorner_Text_210B04: @ 8210B04
	.string "Voilà quelques petits trucs à savoir\n"
	.string "à propos des MACHINES A SOUS.\p"
	.string "Plus tu as d'éclairs, plus tu as de\n"
	.string "chances de tomber sur le REEL TIME.\p"
	.string "Dans une partie avec un maximum de\n"
	.string "5 chances pour le REEL TIME…\p"
	.string "Il est possible d'avoir quatre bonus\n"
	.string "et après, un big bonus.\p"
	.string "Ça fait un total de 660 JETONS,\n"
	.string "mais c'est très difficile de l'avoir.$"

MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase: @ 8210C2E
	.string "Tu ne peux pas jouer si tu n'as\n"
	.string "pas de BOITE JETONS.$"

