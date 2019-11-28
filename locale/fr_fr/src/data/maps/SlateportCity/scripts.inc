SlateportCity_MapScripts:: @ 81DCC61
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_MapScript2_1DCD12
	.byte 0

SlateportCity_OnTransition: @ 81DCC6C
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_1DCC8D
	compare VAR_SLATEPORT_CITY_STATE, 1
	call_if_eq SlateportCity_EventScript_1DCC99
	compare VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	call_if_eq SlateportCity_EventScript_1DCCE7
	end

SlateportCity_EventScript_1DCC8D:: @ 81DCC8D
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_LINK_CONTEST_ROOM_STATE, 0
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	return

SlateportCity_EventScript_1DCC99:: @ 81DCC99
	setobjectxyperm 11, 28, 13
	setobjectxyperm 7, 25, 13
	setobjectxyperm 3, 25, 14
	setobjectxyperm 6, 27, 16
	setobjectxyperm 8, 28, 16
	setobjectxyperm 1, 29, 16
	setobjectxyperm 2, 31, 14
	setobjectmovementtype 11, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype 7, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype 8, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_1DCCE7:: @ 81DCCE7
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 30
	goto_if_eq SlateportCity_EventScript_1DCD06
	setobjectxyperm 35, 23, 27
	setobjectmovementtype 35, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_1DCD06:: @ 81DCD06
	setobjectxyperm 35, 22, 27
	setobjectmovementtype 35, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_MapScript2_1DCD12: @ 81DCD12
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_1DCD1C
	.2byte 0

SlateportCity_EventScript_1DCD1C:: @ 81DCD1C
	lockall
	addobject 35
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_Movement_1DCDA8
	applymovement 35, SlateportCity_Movement_1DCDAC
	waitmovement 0
	msgbox SlateportCity_Text_1DF032, MSGBOX_DEFAULT
	closemessage
	applymovement 35, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	delay 60
	msgbox SlateportCity_Text_1DF0FE, MSGBOX_DEFAULT
	applymovement 35, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox SlateportCity_Text_1DF12B, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox SlateportCity_Text_1DF1A6, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_1DF1D3, MSGBOX_DEFAULT
	closemessage
	applymovement 35, SlateportCity_Movement_1DCDB4
	waitmovement 0
	removeobject 35
	setobjectxyperm 35, 10, 12
	setobjectmovementtype 35, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlateportCity_Movement_1DCDA8: @ 81DCDA8
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

SlateportCity_Movement_1DCDAC: @ 81DCDAC
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_1DCDB4: @ 81DCDB4
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_1DCDBD:: @ 81DCDBD
	lock
	faceplayer
	message SlateportCity_Text_1DD64A
	waitmessage
	pokemart SlateportCity_Pokemart_1DCDD4
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_Pokemart_1DCDD4: @ 81DCDD4
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end

SlateportCity_EventScript_1DCDE4:: @ 81DCDE4
	lock
	faceplayer
	bufferleadmonspeciesname 0
	msgbox SlateportCity_Text_1DD68A, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	compare VAR_RESULT, 1
	call_if_eq SlateportCity_EventScript_1DCE38
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	compare VAR_RESULT, 0
	call_if_eq SlateportCity_EventScript_1DCE2E
	msgbox SlateportCity_Text_1DD697, MSGBOX_DEFAULT
	playfanfare MUS_FANFA4
	message SlateportCity_Text_1DD6E3
	waitfanfare
	msgbox SlateportCity_Text_1DD702, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_1DCE2E:: @ 81DCE2E
	msgbox SlateportCity_Text_1DD722, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCE38:: @ 81DCE38
	msgbox SlateportCity_Text_1DD77B, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCE42:: @ 81DCE42
	lock
	faceplayer
	compare VAR_SLATEPORT_CITY_STATE, 1
	call_if_eq SlateportCity_EventScript_1DCE59
	msgbox SlateportCity_Text_1DD81A, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCE59:: @ 81DCE59
	msgbox SlateportCity_Text_1DE3E2, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCE63:: @ 81DCE63
	lock
	faceplayer
	compare VAR_SLATEPORT_CITY_STATE, 1
	call_if_eq SlateportCity_EventScript_1DCE7A
	msgbox SlateportCity_Text_1DD8A6, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCE7A:: @ 81DCE7A
	msgbox SlateportCity_Text_1DE28E, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCE84:: @ 81DCE84
	lock
	faceplayer
	compare VAR_SLATEPORT_CITY_STATE, 1
	call_if_eq SlateportCity_EventScript_1DCEA4
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_1DCEAE
	msgbox SlateportCity_Text_1DD93D, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCEA4:: @ 81DCEA4
	msgbox SlateportCity_Text_1DE30C, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCEAE:: @ 81DCEAE
	msgbox SlateportCity_Text_1DD999, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCEB8:: @ 81DCEB8
	lock
	faceplayer
	compare VAR_SLATEPORT_CITY_STATE, 1
	call_if_eq SlateportCity_EventScript_1DCECF
	msgbox SlateportCity_Text_1DDA34, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCECF:: @ 81DCECF
	msgbox SlateportCity_Text_1DE376, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCED9:: @ 81DCED9
	compare VAR_SLATEPORT_CITY_STATE, 1
	goto_if_eq SlateportCity_EventScript_1DCEED
	msgbox SlateportCity_Text_1DDA9A, MSGBOX_NPC
	end

SlateportCity_EventScript_1DCEED:: @ 81DCEED
	msgbox SlateportCity_Text_1DE43D, MSGBOX_SIGN
	end

SlateportCity_EventScript_1DCEF6:: @ 81DCEF6
	lock
	faceplayer
	compare VAR_SLATEPORT_CITY_STATE, 1
	call_if_eq SlateportCity_EventScript_1DCF0D
	msgbox SlateportCity_Text_1DDB21, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCF0D:: @ 81DCF0D
	msgbox SlateportCity_Text_1DE460, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCF17:: @ 81DCF17
	lock
	faceplayer
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_1DCF2C
	msgbox SlateportCity_Text_1DDBAC, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCF2C:: @ 81DCF2C
	msgbox SlateportCity_Text_1DDBD5, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCF36:: @ 81DCF36
	msgbox SlateportCity_Text_1DE8BC, MSGBOX_SIGN
	end

SlateportCity_EventScript_1DCF3F:: @ 81DCF3F
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_1DCF66
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_1DCF5C
	msgbox SlateportCity_Text_1DE8F8, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_1DCF5C:: @ 81DCF5C
	msgbox SlateportCity_Text_1DE940, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_1DCF66:: @ 81DCF66
	msgbox SlateportCity_Text_1DE9AA, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_1DCF70:: @ 81DCF70
	msgbox SlateportCity_Text_1DEA0B, MSGBOX_SIGN
	end

SlateportCity_EventScript_1DCF79:: @ 81DCF79
	msgbox SlateportCity_Text_1DEA3B, MSGBOX_SIGN
	end

SlateportCity_EventScript_1DCF82:: @ 81DCF82
	msgbox SlateportCity_Text_1DEA6F, MSGBOX_SIGN
	end

SlateportCity_EventScript_1DCF8B:: @ 81DCF8B
	msgbox SlateportCity_Text_1DEAAF, MSGBOX_SIGN
	end

SlateportCity_EventScript_1DCF94:: @ 81DCF94
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_1DCFA8
	msgbox SlateportCity_Text_1DEAE3, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_1DCFA8:: @ 81DCFA8
	msgbox SlateportCity_Text_1DEB5A, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_1DCFB2:: @ 81DCFB2
	msgbox SlateportCity_Text_1DEBA0, MSGBOX_SIGN
	end

SlateportCity_EventScript_1DCFBB:: @ 81DCFBB
	lock
	faceplayer
	compare VAR_SLATEPORT_CITY_STATE, 1
	call_if_eq SlateportCity_EventScript_1DCFD2
	msgbox SlateportCity_Text_1DE10E, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCFD2:: @ 81DCFD2
	msgbox SlateportCity_Text_1DE10E, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DCFDC:: @ 81DCFDC
	msgbox SlateportCity_Text_1DE16C, MSGBOX_NPC
	end

SlateportCity_EventScript_1DCFE5:: @ 81DCFE5
	msgbox SlateportCity_Text_1DDFF7, MSGBOX_NPC
	end

SlateportCity_EventScript_1DCFEE:: @ 81DCFEE
	msgbox SlateportCity_Text_1DE04B, MSGBOX_NPC
	end

SlateportCity_EventScript_1DCFF7:: @ 81DCFF7
	msgbox SlateportCity_Text_1DE0D2, MSGBOX_NPC
	end

SlateportCity_EventScript_1DD000:: @ 81DD000
	msgbox SlateportCity_Text_1DE1EC, MSGBOX_NPC
	end

SlateportCity_EventScript_1DD009:: @ 81DD009
	lock
	faceplayer
	msgbox SlateportCity_Text_1DDC4F, MSGBOX_DEFAULT
	closemessage
	applymovement 5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_1DD020:: @ 81DD020
	lock
	faceplayer
	msgbox SlateportCity_Text_1DDC8A, MSGBOX_DEFAULT
	closemessage
	applymovement 18, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_1DD037:: @ 81DD037
	lock
	faceplayer
	msgbox SlateportCity_Text_1DDCD5, MSGBOX_DEFAULT
	closemessage
	applymovement 19, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_1DD04E:: @ 81DD04E
	lock
	faceplayer
	msgbox SlateportCity_Text_1DDD18, MSGBOX_DEFAULT
	closemessage
	applymovement 26, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_1DD065:: @ 81DD065
	lock
	faceplayer
	msgbox SlateportCity_Text_1DDD7D, MSGBOX_DEFAULT
	closemessage
	applymovement 27, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_1DD07C:: @ 81DD07C
	lock
	faceplayer
	msgbox SlateportCity_Text_1DDDC0, MSGBOX_DEFAULT
	closemessage
	applymovement 28, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_1DD093:: @ 81DD093
	lock
	faceplayer
	msgbox SlateportCity_Text_1DDDDF, MSGBOX_DEFAULT
	closemessage
	applymovement 29, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_1DD0AA:: @ 81DD0AA
	lock
	faceplayer
	msgbox SlateportCity_Text_1DDE2F, MSGBOX_DEFAULT
	closemessage
	applymovement 30, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_1DD0C1:: @ 81DD0C1
	lock
	faceplayer
	playse SE_PIN
	applymovement 31, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 31, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_Text_1DDE6E, MSGBOX_DEFAULT
	closemessage
	applymovement 31, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement 31, SlateportCity_Movement_1DD147
	waitmovement 0
	applymovement 31, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_Text_1DDE86, MSGBOX_DEFAULT
	closemessage
	applymovement 31, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement 31, SlateportCity_Movement_1DD147
	waitmovement 0
	msgbox SlateportCity_Text_1DDEB8, MSGBOX_DEFAULT
	closemessage
	applymovement 31, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 31, SlateportCity_Movement_1DD147
	waitmovement 0
	applymovement 31, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Movement_1DD147: @ 81DD147
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_1DD14A:: @ 81DD14A
	msgbox SlateportCity_Text_1DDF32, MSGBOX_SIGN
	end

SlateportCity_EventScript_1DD153:: @ 81DD153
	lock
	faceplayer
	msgbox SlateportCity_Text_1DDF8D, MSGBOX_DEFAULT
	closemessage
	applymovement 33, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_1DD16A:: @ 81DD16A
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls: @ 81DD184
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	.2byte DECOR_NONE
	release
	end

SlateportCity_EventScript_1DD18E:: @ 81DD18E
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DD198:: @ 81DD198
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_1DD18E
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_1DD1B8
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemartDecor_1DD1B8: @ 81DD1B8
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	.2byte DECOR_NONE
	release
	end

SlateportCity_EventScript_1DD1D8:: @ 81DD1D8
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_1DD1F0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_1DD1F0: @ 81DD1F0
	.2byte ITEM_TM10
	.2byte ITEM_TM43
	.2byte ITEM_NONE
	release
	end

SlateportCity_EventScript_1DD1F8:: @ 81DD1F8
	lockall
	msgbox SlateportCity_Text_1DE502, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_1DE54A, MSGBOX_DEFAULT
	closemessage
	applymovement 10, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	delay 10
	applymovement 9, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 25
	applymovement 11, SlateportCity_Movement_1DD33C
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_Movement_1DD34A
	applymovement 10, SlateportCity_Movement_1DD319
	applymovement 9, SlateportCity_Movement_1DD326
	waitmovement 0
	removeobject 10
	removeobject 9
	msgbox SlateportCity_Text_1DE5F7, MSGBOX_DEFAULT
	applymovement 11, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox SlateportCity_Text_1DE64F, MSGBOX_DEFAULT
	playbgm MUS_AQA_0, 0
	msgbox SlateportCity_Text_1DE724, MSGBOX_DEFAULT
	applymovement 6, Common_Movement_WalkInPlaceFastestLeft
	applymovement 1, Common_Movement_WalkInPlaceFastestLeft
	applymovement 7, SlateportCity_Movement_1DD309
	applymovement 3, Common_Movement_QuestionMark
	applymovement 2, SlateportCity_Movement_1DD311
	waitmovement 0
	applymovement 11, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox SlateportCity_Text_1DE7F7, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement 11, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 11, Common_Movement_Delay48
	waitmovement 0
	applymovement 11, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox SlateportCity_Text_1DE860, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_1DE8A0, MSGBOX_DEFAULT
	closemessage
	applymovement 11, SlateportCity_Movement_1DD337
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_Movement_1DD344
	waitmovement 0
	removeobject 11
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setvar VAR_SLATEPORT_CITY_STATE, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 255, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_1DD309: @ 81DD309
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_fastest_right
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

SlateportCity_Movement_1DD311: @ 81DD311
	emote_question_mark
	walk_in_place_fastest_up
	delay_16
	walk_in_place_fastest_down
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

SlateportCity_Movement_1DD319: @ 81DD319
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_1DD326: @ 81DD326
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_1DD334: @ 81DD334
	walk_down
	walk_in_place_fastest_up
	step_end

SlateportCity_Movement_1DD337: @ 81DD337
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_1DD33C: @ 81DD33C
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_1DD344: @ 81DD344
	walk_in_place_fastest_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_1DD34A: @ 81DD34A
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_down
	step_end

SlateportCity_EventScript_1DD353:: @ 81DD353
	msgbox SlateportCity_Text_1DE491, MSGBOX_SIGN
	end

SlateportCity_EventScript_1DD35C:: @ 81DD35C
	msgbox SlateportCity_Text_1DE4C4, MSGBOX_SIGN
	end

SlateportCity_EventScript_1DD365:: @ 81DD365
	msgbox SlateportCity_Text_1DD7AD, MSGBOX_NPC
	end

SlateportCity_EventScript_1DD36E:: @ 81DD36E
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_1DD39A
	msgbox SlateportCity_Text_1DEBCE, MSGBOX_DEFAULT
	giveitem_std ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_1DED27, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DD39A:: @ 81DD39A
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_EventScript_1DD3C0
	msgbox SlateportCity_Text_1DEE40, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_1DD3CA
	end

SlateportCity_EventScript_1DD3C0:: @ 81DD3C0
	msgbox SlateportCity_Text_1DED27, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_1DD3CA:: @ 81DD3CA
	message SlateportCity_Text_1DEE67
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_1DD46E
	case 1, SlateportCity_EventScript_1DD482
	case 2, SlateportCity_EventScript_1DD496
	case 3, SlateportCity_EventScript_1DD4AA
	case 4, SlateportCity_EventScript_1DD4BE
	case 5, SlateportCity_EventScript_1DD4D2
	case 6, SlateportCity_EventScript_1DD4E6
	case 7, SlateportCity_EventScript_1DD4FA
	case 8, SlateportCity_EventScript_1DD50E
	case 9, SlateportCity_EventScript_1DD522
	case 10, SlateportCity_EventScript_1DD536
	case 11, SlateportCity_EventScript_1DD54A
	case MULTI_B_PRESSED, SlateportCity_EventScript_1DD54A
	end

SlateportCity_EventScript_1DD46E:: @ 81DD46E
	bufferitemname 0, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD482:: @ 81DD482
	bufferitemname 0, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD496:: @ 81DD496
	bufferitemname 0, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD4AA:: @ 81DD4AA
	bufferitemname 0, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD4BE:: @ 81DD4BE
	bufferitemname 0, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD4D2:: @ 81DD4D2
	bufferitemname 0, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD4E6:: @ 81DD4E6
	bufferitemname 0, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD4FA:: @ 81DD4FA
	bufferitemname 0, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD50E:: @ 81DD50E
	bufferitemname 0, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD522:: @ 81DD522
	bufferitemname 0, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD536:: @ 81DD536
	bufferitemname 0, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD54A:: @ 81DD54A
	msgbox SlateportCity_Text_1DEFBC, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_1DD557:: @ 81DD557
	msgbox SlateportCity_Text_1DEE90, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_EventScript_1DD3CA
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_EventScript_1DD5CE
	giveitem_std VAR_0x8008
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_EventScript_1DD5C1
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_1DEEF7, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_EventScript_1DD3CA
	msgbox SlateportCity_Text_1DEF79, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_1DD5C1:: @ 81DD5C1
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_1DD5CE:: @ 81DD5CE
	msgbox SlateportCity_Text_1DEEC9, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_1DD3CA
	end

SlateportCity_EventScript_1DD5DC:: @ 81DD5DC
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	opendoor 10, 12
	waitdooranim
	addobject 35
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_Movement_1DD630
	applymovement 35, SlateportCity_Movement_1DD637
	waitmovement 0
	closedoor 10, 12
	waitdooranim
	msgbox SlateportCity_Text_1DF28C, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_Movement_1DD634
	applymovement 35, SlateportCity_Movement_1DD63A
	waitmovement 0
	removeobject 35
	addvar VAR_SCOTT_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end

SlateportCity_Movement_1DD630: @ 81DD630
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

SlateportCity_Movement_1DD634: @ 81DD634
	delay_16
	walk_in_place_fastest_right
	step_end

SlateportCity_Movement_1DD637: @ 81DD637
	delay_8
	walk_down
	step_end

SlateportCity_Movement_1DD63A: @ 81DD63A
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_1DD643:: @ 81DD643
	lockall
	special sub_80224D0
	waitstate
	releaseall
	end

SlateportCity_Text_1DD64A: @ 81DD64A
	.string "Je suis le MAITRE DE LA FORME!\n"
	.string "J'ai tout ce qu'il vous faut!$"

SlateportCity_Text_1DD68A: @ 81DD68A
	.string "Oh?\n"
	.string "Ton {STR_VAR_1}…$"

SlateportCity_Text_1DD697: @ 81DD697
	.string "Bien joué!\p"
	.string "En récompense, voici ce RUBAN \n"
	.string "pour ton POKéMON.$"

SlateportCity_Text_1DD6E3: @ 81DD6E3
	.string "{PLAYER} reçoit le RUBAN.$"

SlateportCity_Text_1DD702: @ 81DD702
	.string "{PLAYER} met le RUBAN \n"
	.string "sur {STR_VAR_1}.$"

SlateportCity_Text_1DD722: @ 81DD722
	.string "Il faut que tu fasses plus d'efforts.\p"
	.string "Si tu le fais, je donnerai quelque\n"
	.string "chose de chouette à ton POKéMON.$"

SlateportCity_Text_1DD77B: @ 81DD77B
	.string "Oh! Ton {STR_VAR_1},, ce RUBAN\n"
	.string "lui va bien!$"

SlateportCity_Text_1DD7AD: @ 81DD7AD
	.string "La lumière du phare se voit à des\n"
	.string "kilomètres à la ronde.\p"
	.string "Je me demande si ça n'effraie pas les\n"
	.string "POKéMON dans la mer.$"

SlateportCity_Text_1DD81A: @ 81DD81A
	.string "Oh, regarde ça!\p"
	.string "Les algues que l'on peut prendre par\n"
	.string "ici sont fraîches et pleines de vie.\p"
	.string "C'est comme si elles allaient se\n"
	.string "cabrer et attaquer!$"

SlateportCity_Text_1DD8A6: @ 81DD8A6
	.string "Là où l'eau est propre, se regroupent\n"
	.string "les fruits de la généreuse récolte.\p"
	.string "Et là où les gens se rassemblent,\n"
	.string "s'établit un marché.\p"
	.string "C'est ainsi qu'une ville se crée et\n"
	.string "se développe.$"

SlateportCity_Text_1DD93D: @ 81DD93D
	.string "Faire ses achats là où l'on peut sentir\n"
	.string "le souffle de l'océan…\p"
	.string "POIVRESSEL est un lieu si merveilleux!$"

SlateportCity_Text_1DD999: @ 81DD999
	.string "Si tu mets des POUPEES ou des COUSSINS\n"
	.string "par terre, ils seront salis.\p"
	.string "Je vais acheter des BRIQUES pour\n"
	.string "que mes POUPEES et mes COUSSINS ne\l"
	.string "soient pas salis.$"

SlateportCity_Text_1DDA34: @ 81DDA34
	.string "Coool! Je vais bientôt aller me battre\n"
	.string "dans une TENTE DE COMBAT!\p"
	.string "Mais avant, il faut que j'attrape\n"
	.string "quelques POKéMON!$"

SlateportCity_Text_1DDA9A: @ 81DDA9A
	.string "Pfou… Je suis claqué…\p"
	.string "Je suis venu à pied de LAVANDIA.\n"
	.string "Cette ville est immense.\p"
	.string "Si j'avais su, je serais venu en VELO.$"

SlateportCity_Text_1DDB21: @ 81DDB21
	.string "POUPE, celui qui a fondé ce\n"
	.string "MUSEE, est aussi à la tête d'une\l"
	.string "équipe d'exploration sous-marine.\p"
	.string "Alors tout le monde l'appelle\n"
	.string "CAPT. POUPE.$"

SlateportCity_Text_1DDBAC: @ 81DDBAC
	.string "Qu'est-ce que c'est que ça?\n"
	.string "Cette longue file…$"

SlateportCity_Text_1DDBD5: @ 81DDBD5
	.string "Lorsque j'étais enfant, je venais\n"
	.string "souvent au MUSEE.\p"
	.string "Après avoir vu les expositions, je\n"
	.string "songeais aux mystères de la mer.$"

SlateportCity_Text_1DDC4F: @ 81DDC4F
	.string "Hé, toi! Arrête de pousser!\n"
	.string "Tu vois pas que c'est la file d'attente?$"

SlateportCity_Text_1DDC8A: @ 81DDC8A
	.string "La TEAM AQUA a une règle concernant\n"
	.string "le rassemblement et la dispersion sur\l"
	.string "le lieu de l'action.$"

SlateportCity_Text_1DDCD5: @ 81DDCD5
	.string "Notre CHEF est brillant.\p"
	.string "Mais que veut-il faire avec ce\n"
	.string "MUSEE?$"

SlateportCity_Text_1DDD18: @ 81DDD18
	.string "Je me demande en quoi va consister le\n"
	.string "prochain projet\p"
	.string "Enervé, notre CHEF est effrayant, alors\n"
	.string "j'ferais bien d'pas tout faire rater.$"

SlateportCity_Text_1DDD7D: @ 81DDD7D
	.string "S'il y a quelque chose au MUSEE qui\n"
	.string "peut être utile, on n'a qu'à se servir!$"

SlateportCity_Text_1DDDC0: @ 81DDDC0
	.string "Hé, toi, là!\n"
	.string "On ne coupe pas la queue!$"

SlateportCity_Text_1DDDDF: @ 81DDDDF
	.string "Une longue file d'attente, hein?\p"
	.string "Ça me rappelle quand je faisais la queue\n"
	.string "pour acheter les jeux qui cartonnaient.$"

SlateportCity_Text_1DDE2F: @ 81DDE2F
	.string "Pourquoi on fait la queue pour payer?\n"
	.string "On n'a qu'à entrer après tout!$"

SlateportCity_Text_1DDE6E: @ 81DDE6E
	.string "Quoi? Quoi?$"

SlateportCity_Text_1DDE86: @ 81DDE86
	.string "Tu veux lire ce panneau?\n"
	.string "Je vais le lire pour toi!$"

SlateportCity_Text_1DDEB8: @ 81DDEB8
	.string "Voyons…\p"
	.string "Hum… Je crois que ça dit\n"
	.string "que la vie dans la mer est éternelle.\p"
	.string "Ouaip, je suis sûr que c'est ce qui\n"
	.string "est écrit.$"

SlateportCity_Text_1DDF32: @ 81DDF32
	.string "Grumpf…\p"
	.string "J'aurais dû apporter ma Game Boy\n"
	.string "Advance pour jouer dans la file\l"
	.string "d'attente…\p"
	.string "Grumpf…$"

SlateportCity_Text_1DDF8D: @ 81DDF8D
	.string "Quand tout sera terminé, on ira\n"
	.string "ensemble aux sources chaudes!\p"
	.string "C'est ce que dit notre leader.\n"
	.string "J'ai super hâte!$"

SlateportCity_Text_1DDFF7: @ 81DDFF7
	.string "La mer est tellement vaste…\p"
	.string "La mer peut-elle être faite des larmes\n"
	.string "par les POKéMON?$"

SlateportCity_Text_1DE04B: @ 81DE04B
	.string "Tu sais ce qu'ils font des bateaux\n"
	.string "devenus trop usagés pour naviguer?\p"
	.string "Ils les font couler dans la mer pour\n"
	.string "qu'ils servent de refuge aux POKéMON.$"

SlateportCity_Text_1DE0D2: @ 81DE0D2
	.string "A chaque fois que je viens ici, je me\n"
	.string "laisse emporter et j'achète trop.$"

SlateportCity_Text_1DE10E: @ 81DE10E
	.string "Si tu veux changer le surnom de l'un de\n"
	.string "tes POKéMON, va voir le SPECIALISTE\l"
	.string "DES NOMS.$"

SlateportCity_Text_1DE16C: @ 81DE16C
	.string "Tu ne peux pas donner de surnom à un\n"
	.string "POKéMON échangé.\p"
	.string "L'amour du premier DRESSEUR de ce\n"
	.string "POKéMON est contenu dans ce surnom.$"

SlateportCity_Text_1DE1EC: @ 81DE1EC
	.string "Une TENTE DE COMBAT a été\n"
	.string "récemment construite à POIVRESSEL.\p"
	.string "Les ARENES sont marrantes, mais les\n"
	.string "TENTES DE COMBAT, c'est autre chose.\p"
	.string "Tu devrais y aller si tu veux te battre\n"
	.string "contre des POKéMON redoutables.$"

SlateportCity_Text_1DE28E: @ 81DE28E
	.string "J'espérais qu'il y aurait une grande\n"
	.string "star pour avoir un autographe.\p"
	.string "Mais qui est cet homme interviewé?\n"
	.string "Ne serait-ce pas le CAPT. POUPE?$"

SlateportCity_Text_1DE30C: @ 81DE30C
	.string "La journaliste est tellement sympa et\n"
	.string "si jolie.\p"
	.string "Quand je serai grande, je serai\n"
	.string "reporter international!$"

SlateportCity_Text_1DE376: @ 81DE376
	.string "Le CAPT. POUPE dit qu'ils ont\n"
	.string "trouvé quelque chose au fond de la mer.\p"
	.string "Je me demande ce que c'est…\n"
	.string "Qu'est-ce que ça pourrait bien être?$"

SlateportCity_Text_1DE3E2: @ 81DE3E2
	.string "Que se passe-t-il ici?\p"
	.string "Le bon CAPITAINE est-il revenu du\n"
	.string "fond de l'océan avec une grosse prise?$"

SlateportCity_Text_1DE43D: @ 81DE43D
	.string "Hé! Tu regardes?\n"
	.string "Est-ce que je passe à la télé?$"

SlateportCity_Text_1DE460: @ 81DE460
	.string "Une interview à la télé! Là!\n"
	.string "Le CAPITAINE est célèbre!$"

SlateportCity_Text_1DE491: @ 81DE491
	.string "GUY: OK, CAPT. POUPE,\n"
	.string "un sourire à la caméra!$"

SlateportCity_Text_1DE4C4: @ 81DE4C4
	.string "INES: Je vois, je vois. Vous avez\n"
	.string "vécu une expérience inestimable…$"

SlateportCity_Text_1DE502: @ 81DE502
	.string "CAPT. POUPE: En effet! Nous comptons\n"
	.string "progresser grâce à notre exploration.$"

SlateportCity_Text_1DE54A: @ 81DE54A
	.string "INES: Merveilleux, CAPT. POUPE!\n"
	.string "Merci de nous avoir accordé un peu\l"
	.string "de votre précieux temps.\p"
	.string "Nous espérons vous revoir pour\n"
	.string "discuter de nouvelles découvertes!$"

SlateportCity_Text_1DE5F7: @ 81DE5F7
	.string "CAPT. POUPE: Ouh…\p"
	.string "C'était la première fois qu'on me\n"
	.string "filmait pour passer à la télé.\l"
	.string "C'était stressant.$"

SlateportCity_Text_1DE64F: @ 81DE64F
	.string "Oh, {PLAYER}{KUN}!\n"
	.string "Tu as l'air en pleine forme!\p"
	.string "Nous avons fait une grande découverte\n"
	.string "en explorant les fonds marins.\p"
	.string "Nous avons trouvé une caverne\n"
	.string "sous-marine sur le CHENAL 128.\p"
	.string "Nous pensons qu'il s'agit de l'habitat\n"
	.string "d'un POKéMON que nous croyions disparu.$"

SlateportCity_Text_1DE724: @ 81DE724
	.string "Hum, hum…\n"
	.string "CAPT. POUPE, je suppose.\p"
	.string "Nous, la TEAM AQUA, allons prendre\n"
	.string "le contrôle de votre sous-marin!\p"
	.string "Il est inutile de vous y opposer!\n"
	.string "Nous comptons sur votre coopération!\p"
	.string "Hum, hum…\n"
	.string "Il ne vous reste plus qu'à découvrir\l"
	.string "ce que la TEAM AQUA a prévu de faire!$"

SlateportCity_Text_1DE7F7: @ 81DE7F7
	.string "CAPT. POUPE: Qu'est-ce que ça pouvait\n"
	.string "bien être?\p"
	.string "On aurait dit quelqu'un avec\n"
	.string "un mégaphone…\p"
	.string "D'où ce son venait-il?$"

SlateportCity_Text_1DE860: @ 81DE860
	.string "Ça vient de l'EMBARCADERE!\p"
	.string "Le sous-marin!\n"
	.string "Ils essaient de le prendre!$"

SlateportCity_Text_1DE8A0: @ 81DE8A0
	.string "{PLAYER}{KUN}!\n"
	.string "Viens avec moi!$"

SlateportCity_Text_1DE8BC: @ 81DE8BC
	.string "TENTE DE COMBAT de POIVRESSEL\n"
	.string "“Pour les meilleurs POKéMON!”$"

SlateportCity_Text_1DE8F8: @ 81DE8F8
	.string "CHANTIER NAVAL DE POUPE\p"
	.string "“Recherche marin capable de\n"
	.string "naviguer sur tous les courants.”$"

SlateportCity_Text_1DE940: @ 81DE940
	.string "CHANTIER NAVAL DE POUPE\p"
	.string "“Le ferry LE MARINA desservant les\n"
	.string "embarcadères de POIVRESSEL et\l"
	.string "NENUCRIQUE sera bientôt terminé.”$"

SlateportCity_Text_1DE9AA: @ 81DE9AA
	.string "CHANTIER NAVAL DE POUPE\p"
	.string "“L'embarquement sur le ferry\n"
	.string "LE MARINA entre POIVRESSEL et\l"
	.string "NENUCRIQUE se fait a l'EMBARCADERE.”$"

SlateportCity_Text_1DEA0B: @ 81DEA0B
	.string "FAN CLUB POKéMON\n"
	.string "“Pour tous les fans de POKéMON!”$"

SlateportCity_Text_1DEA3B: @ 81DEA3B
	.string "“La mer infinie supporte\n"
	.string "toutes les formes de vie.”\p"
	.string "MUSEE OCEANOGRAPHIQUE$"

SlateportCity_Text_1DEA6F: @ 81DEA6F
	.string "POIVRESSEL\p"
	.string "“Le port où le chemin des hommes\n"
	.string "et celui des POKéMON se croisent.”$"

SlateportCity_Text_1DEAAF: @ 81DEAAF
	.string "MARCHE DE POIVRESSEL\n"
	.string "“Des objets uniques introuvables\l"
	.string "ailleurs!”$"

SlateportCity_Text_1DEAE3: @ 81DEAE3
	.string "EMBARCADERE DE POIVRESSEL\p"
	.string "“Le ferry LE MARINA est\n"
	.string "en construction au CHANTIER NAVAL.\p"
	.string "“Il devrait entrer en service\n"
	.string "sous peu.”$"

SlateportCity_Text_1DEB5A: @ 81DEB5A
	.string "EMBARCADERE DE POIVRESSEL\p"
	.string "“Profitez d'une merveilleuse croisière\n"
	.string "sur LE MARINA.”$"

SlateportCity_Text_1DEBA0: @ 81DEBA0
	.string "MAISON DU SPECIALISTE DES NOMS\n"
	.string "“Conseil en surnoms de POKéMON.”$"

SlateportCity_Text_1DEBCE: @ 81DEBCE
	.string "Si un POKéMON sauvage est blessé,\n"
	.string "il se soigne en mâchant des BAIES.\p"
	.string "Tu le savais?\p"
	.string "En voyant ça, quelqu'un a eu l'idée de\n"
	.string "faire des médicaments à base de\l"
	.string "BAIES.\p"
	.string "Tu le savais?\p"
	.string "Pour transformer des BAIES en\n"
	.string "médicaments, il faut les réduire\l"
	.string "en poudre.\p"
	.string "Tu le savais?\p"
	.string "On dirait que tu t'intéresses\n"
	.string "aux BAIES!\p"
	.string "J'ai quelque chose qui va sûrement\n"
	.string "te plaire!$"

SlateportCity_Text_1DED27: @ 81DED27
	.string "J'ai récemment fait installer des\n"
	.string "machines pour broyer les BAIES\l"
	.string dans les CENTRES POKéMON.\p"
	.string "Les BROYEURS DE BAIES se\n"
	.string "trouvent dans la SALLE LINK DIRECT.\p"
	.string "Tu le savais?\p"
	.string "Pourrais-tu aller faire de la\n"
	.string "POUDRE BAIE pour moi en\p"
	.string "utilisant ces machines?\p"
	.string "Je ferai une préparation juste\n"
	.string "pour toi si tu arrives à broyer\p"
	.string "des BAIES et à me ramener\n"
	.string "la POUDRE BAIE.$"

SlateportCity_Text_1DEE40: @ 81DEE40
	.string "M'as-tu amené de la POUDRE BAIE?$"

SlateportCity_Text_1DEE67: @ 81DEE67
	.string "Contre quoi veux-tu l'échanger?$"

SlateportCity_Text_1DEE90: @ 81DEE90
	.string "Je vais te donner 1 {STR_VAR_1}\n"
	.string "contre la POUDRE BAIE.$"

SlateportCity_Text_1DEEC9: @ 81DEEC9
	.string "Hmm\n"
	.string "Tu n'as pas assez de POUDRE BAIE.$"

SlateportCity_Text_1DEEF7: @ 81DEEF7
	.string "Cette POUDRE BAIE a l'air bonne.\n"
	.string "Ça fera de bons médicaments.\p"
	.string "Tu veux échanger ce qui te reste de\n"
	.string "POUDRE BAIE contre autre chose?$"

SlateportCity_Text_1DEF79: @ 81DEF79
	.string "OK! Reviens-me voir quand tu auras\n"
	.string "plus de POUDRE BAIE!$"

SlateportCity_Text_1DEFBC: @ 81DEFBC
	.string "Reviens me voir si tu veux échanger\n"
	.string "de la POUDRE BAIE contre des\l"
	.string "médicaments.\p"
	.string "Je fais toujours des affaires ici.\p"
	.string "Tu le savais?$"

SlateportCity_Text_1DF032: @ 81DF032
	.string "SCOTT: Hein?\n"
	.string "C'est pas la première fois qu'on se\l"
	.string "rencontre, non?\p"
	.string "Est-ce que je me suis déjà présenté?\n"
	.string "Je m'appelle SCOTT.\p"
	.string "Je viens de voir la TEAM AQUA partir\n"
	.string "d'ici en trombe.\p"
	.string "Laisse-moi deviner… C'est toi\n"
	.string "qui les as fait fuir?$"

SlateportCity_Text_1DF0FE: @ 81DF0FE
	.string "SCOTT: Hum…\n"
	.string "Peut-être…\p"
	.string "Peut-être que ce DRESSEUR…$"

SlateportCity_Text_1DF12B: @ 81DF12B
	.string "SCOTT: Très bien! Je pense que nous\n"
	.string "allons devenir amis.\p"
	.string "Echangeons nos numéros pour les\n"
	.string "enregistrer dans nos POKéNAVS.\p"
	.string "… … … … … …$"

SlateportCity_Text_1DF1A6: @ 81DF1A6
	.string "Vous avez enregistré SCOTT dans\n"
	.string "le POKéNAV.$"

SlateportCity_Text_1DF1D3: @ 81DF1D3
	.string "SCOTT: J'aimerais bien rester un peu\n"
	.string "avec toi, mais je veux aussi garder un\l"
	.string "œil sur les autres gens talentueux.\p"
	.string "Alors je vais visiter les autres villes\n"
	.string "pendant quelque temps encore.\p"
	.string "A bientôt, {PLAYER}{KUN}!$"

SlateportCity_Text_1DF28C: @ 81DF28C
	.string "SCOTT: Oh, mais…\n"
	.string "C'est bien toi, {PLAYER}{KUN}!\p"
	.string "{PLAYER}{KUN}, je suis sûr que tu veux\n"
	.string "participer au défi de la\l"
	.string "TENTE DE COMBAT?\p"
	.string "C'est une bonne idée!\n"
	.string "C'est même une très bonne idée!\p"
	.string "Après tout, les bons DRESSEURS\n"
	.string "se doivent d'aller dans les\l"
	.string "TENTES DE COMBAT!\p"
	.string "Donne-toi à fond!$"
