BattleFrontier_BattlePointExchangeServiceCorner_MapScripts:: @ 825F070
	.byte 0

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F071:: @ 825F071
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25F7FA, MSGBOX_DEFAULT
	special ShowBattlePointsWindow
	return

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F07D:: @ 825F07D
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FF12, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A:: @ 825F08A
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	compare VAR_TEMP_1, VAR_0x8008
	goto_if_ge BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F0C9
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FE86, MSGBOX_DEFAULT
	compare VAR_TEMP_2, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185
	compare VAR_TEMP_2, 1
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F38E
	compare VAR_TEMP_2, 2
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F4B1
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F602
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F0C9:: @ 825F0C9
	compare VAR_TEMP_2, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F0E5
	compare VAR_TEMP_2, 1
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F0E5
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F12A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F0E5:: @ 825F0E5
	checkdecorspace VAR_0x8009
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F11D
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	givedecoration VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_REGI
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FE45, MSGBOX_DEFAULT
	compare VAR_TEMP_2, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F38E
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F11D:: @ 825F11D
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FEB9, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F12A:: @ 825F12A
	checkitemspace VAR_0x8009, 1
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F166
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	giveitem VAR_0x8009, 1
	special UpdateBattlePointsWindow
	playse SE_REGI
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FE72, MSGBOX_DEFAULT
	compare VAR_TEMP_2, 2
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F4B1
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F602
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F166:: @ 825F166
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FEE3, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F173:: @ 825F173
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	call BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F071
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185:: @ 825F185
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F21E
	case 1, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F241
	case 2, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F264
	case 3, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F287
	case 4, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F2AA
	case 5, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F2CD
	case 6, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F2F0
	case 7, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F313
	case 8, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F336
	case 9, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F359
	case 10, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F07D
	case MULTI_B_PRESSED, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F07D
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F21E:: @ 825F21E
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25F8B6, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, DECOR_KISS_POSTER
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F241:: @ 825F241
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25F8E6, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, DECOR_KISS_CUSHION
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F264:: @ 825F264
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25F917, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, DECOR_SMOOCHUM_DOLL
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F287:: @ 825F287
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25F949, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_TOGEPI_DOLL
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F2AA:: @ 825F2AA
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25F979, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_MEOWTH_DOLL
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F2CD:: @ 825F2CD
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25F9A9, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_CLEFAIRY_DOLL
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F2F0:: @ 825F2F0
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25F9DB, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_DITTO_DOLL
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F313:: @ 825F313
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FA0A, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_CYNDAQUIL_DOLL
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F336:: @ 825F336
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FA3D, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_CHIKORITA_DOLL
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F359:: @ 825F359
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FA70, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F185
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_TOTODILE_DOLL
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F37C:: @ 825F37C
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	call BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F071
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F38E
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F38E:: @ 825F38E
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F3F0
	case 1, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F413
	case 2, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F436
	case 3, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F459
	case 4, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F47C
	case 5, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F07D
	case MULTI_B_PRESSED, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F07D
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F3F0:: @ 825F3F0
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FAA2, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F38E
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, DECOR_LAPRAS_DOLL
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F413:: @ 825F413
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FAD2, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F38E
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, DECOR_SNORLAX_DOLL
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F436:: @ 825F436
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FB03, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F38E
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_VENUSAUR_DOLL
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F459:: @ 825F459
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FB35, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F38E
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_CHARIZARD_DOLL
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F47C:: @ 825F47C
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FB68, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F38E
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_BLASTOISE_DOLL
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F49F:: @ 825F49F
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	call BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F071
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F4B1
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F4B1:: @ 825F4B1
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F51E
	case 1, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F541
	case 2, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F564
	case 3, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F587
	case 4, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F5AA
	case 5, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F5CD
	case 6, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F07D
	case MULTI_B_PRESSED, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F07D
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F51E:: @ 825F51E
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FB9B, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F4B1
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_PROTEIN
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F541:: @ 825F541
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FBC7, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F4B1
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_CALCIUM
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F564:: @ 825F564
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FBF3, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F4B1
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_IRON
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F587:: @ 825F587
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FC1C, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F4B1
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_ZINC
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F5AA:: @ 825F5AA
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FC45, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F4B1
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_CARBOS
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F5CD:: @ 825F5CD
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FC70, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F4B1
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_HP_UP
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F5F0:: @ 825F5F0
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	call BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F071
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F602
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F602:: @ 825F602
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F690
	case 1, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F6B3
	case 2, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F6D6
	case 3, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F6F9
	case 4, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F71C
	case 5, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F73F
	case 6, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F762
	case 7, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F785
	case 8, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F7A8
	case 9, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F07D
	case MULTI_B_PRESSED, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F07D
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F690:: @ 825F690
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FE17, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F602
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_LEFTOVERS
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F6B3:: @ 825F6B3
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FCCB, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F602
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_WHITE_HERB
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F6D6:: @ 825F6D6
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FCFA, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F602
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_QUICK_CLAW
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F6F9:: @ 825F6F9
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FD29, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F602
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_MENTAL_HERB
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F71C:: @ 825F71C
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FC9A, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F602
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_BRIGHT_POWDER
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F73F:: @ 825F73F
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FD59, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F602
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_CHOICE_BAND
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F762:: @ 825F762
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FD89, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F602
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_KINGS_ROCK
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F785:: @ 825F785
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FDB9, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F602
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_FOCUS_BAND
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F7A8:: @ 825F7A8
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FDE8, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F602
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_SCOPE_LENS
	goto BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F08A
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F7CB:: @ 825F7CB
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_260099, MSGBOX_NPC
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F7D4:: @ 825F7D4
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_26002E, MSGBOX_NPC
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F7DD:: @ 825F7DD
	lock
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FFD0, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F7E8:: @ 825F7E8
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_25FF5D, MSGBOX_NPC
	end

BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F7F1:: @ 825F7F1
	msgbox BattleFrontier_BattlePointExchangeServiceCorner_Text_26012D, MSGBOX_NPC
	end

BattleFrontier_BattlePointExchangeServiceCorner_Text_25F7FA: @ 825F7FA
	.string "Bonjour! Vous êtes au SERVICE\n"
	.string "D'ECHANGE.\p"
	.string "Nous échangeons vos POINTS DE COMBAT\n"
	.string "contre de magnifiques prix.\p"
	.string "Veuillez choisir un objet.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25F890: @ 825F890
	.string "Please choose a prize from this list.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25F8B6: @ 825F8B6
	.string "Vous avez choisi le prix POSTER BAISER.\n"
	.string "C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25F8E6: @ 825F8E6
	.string "Vous avez choisi le prix\n"
	.string "COUSSIN BAISER. C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25F917: @ 825F917
	.string "Vous avez choisi le prix POUPEE\n"
	.string "LIPPOUTI. C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25F949: @ 825F949
	.string "Vous avez choisi le prix POUPEE TOGEPI.\n"
	.string "C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25F979: @ 825F979
	.string "Vous avez choisi le prix\n"
	.string "POUPEE MIAOUSS. C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25F9A9: @ 825F9A9
	.string "Vous avez choisi le prix\n"
	.string "POUPEE MELOFEE. C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25F9DB: @ 825F9DB
	.string "Vous avez choisi le prix POUP.\n"
	.string "METAMORPH. C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FA0A: @ 825FA0A
	.string "Vous avez choisi le prix POUP.\n"
	.string "HERICENDRE. C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FA3D: @ 825FA3D
	.string "Vous avez choisi le prix\n"
	.string "POUP. GERMIGNON. C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FA70: @ 825FA70
	.string "Vous avez choisi le prix\n"
	.string "POUPEE KAIMINUS. C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FAA2: @ 825FAA2
	.string "Vous avez choisi le prix POUPEE\n"
	.string "LOKHLASS. C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FAD2: @ 825FAD2
	.string "Vous avez choisi le prix \n"
	.string "POUPEE RONFLEX. C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FB03: @ 825FB03
	.string "Vous avez choisi le prix POUP.\n"
	.string "FLORIZARRE. C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FB35: @ 825FB35
	.string "Vous avez choisi le prix POUP.\n"
	.string "DRACAUFEU. C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FB68: @ 825FB68
	.string "Vous avez choisi le prix POUPEE\n"
	.string "TORTANK. C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FB9B: @ 825FB9B
	.string "Vous avez choisi le prix PROTEINE.\n"
	.string "C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FBC7: @ 825FBC7
	.string "Vous avez choisi le prix CALCIUM.\n"
	.string "C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FBF3: @ 825FBF3
	.string "Vous avez choisi le prix FER.\n"
	.string "C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FC1C: @ 825FC1C
	.string "Vous avez choisi le prix ZINC.\n"
	.string "C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FC45: @ 825FC45
	.string "Vous avez choisi le prix CARBONE.\n"
	.string "C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FC70: @ 825FC70
	.string "Vous avez choisi le prix PV PLUS.\n"
	.string "C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FC9A: @ 825FC9A
	.string "Vous avez choisi le prix POUDRECLAIRE.\n"
	.string "C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FCCB: @ 825FCCB
	.string "Vous avez choisi le prix HERBEBLANCHE.\n"
	.string "C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FCFA: @ 825FCFA
	.string "Vous avez choisi le prix VIVE GRIFFE.\n"
	.string "C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FD29: @ 825FD29
	.string "Vous avez choisi le prix HERBE MENTAL.\n"
	.string "C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FD59: @ 825FD59
	.string "Vous avez choisi le prix BAND. CHOIX.\n"
	.string "C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FD89: @ 825FD89
	.string "Vous avez choisi le prix ROCHE ROYALE.\n"
	.string "C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FDB9: @ 825FDB9
	.string "Vous avez choisi le prix BANDEAU.\n"
	.string "C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FDE8: @ 825FDE8
	.string "Vous avez choisi le prix LENTILSCOPE.\n"
	.string "C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FE17: @ 825FE17
	.string "Vous avez choisi le prix RESTES.\n"
	.string "C'est bien cela?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FE45: @ 825FE45
	.string "Merci!\n"
	.string "Ce sera envoyé chez vous, sur votre PC.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FE72: @ 825FE72
	.string "Voici votre prix!$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FE86: @ 825FE86
	.string "Je suis désolée, mais vous n'avez pas\n"
	.string "assez de POINTS DE COMBAT…$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FEB9: @ 825FEB9
	.string "Je suis désolée, mais votre PC semble\n"
	.string "être plein…$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FEE3: @ 825FEE3
	.string "Je suis désolée, mais vous n'avez pas\n"
	.string "assez de place…$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FF12: @ 825FF12
	.string "Merci de votre visite.\n"
	.string "Revenez quand vous voulez.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FF5D: @ 825FF5D
	.string "Oh, ce que c'est beau!\n"
	.string "J'aimerais tout avoir!\l"
	.string "Les jolis COUSSINS!\l"
	.string "Les grosses POUPEES!\l"
	.string "Les petites POUPEES!\l"
	.string "J'aimerais tout avoir!$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_25FFD0: @ 825FFD0
	.string "Dis à maman ce que tu veux.\p"
	.string "Si tu veux quelque chose, je ferai\n"
	.string "tout pour te l'offrir, mon chéri!$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_26002E: @ 826002E
	.string "Si j'arrive à me procurer ces objets, \n"
	.string "mes POKéMON vont devenir plus forts.\p"
	.string "Oui, plutôt deux fois qu'une!\n"
	.string "Il me faut ces objets!$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_260099: @ 8260099
	.string "Tiens?\n"
	.string "Mais qu'est-ce que tu regardes, là?\p"
	.string "Arrête de reluquer ma poupée\n"
	.string "comme ça.\p"
	.string "Si tu en veux une, tu n'as qu'à\n"
	.string "l'acheter! Pas vrai, LIPPOUTI?$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_26012D: @ 826012D
	.string "Dis, tu savais ça?\p"
	.string "Si tu rejoues et améliores ton résultat\n"
	.string "dans un bâtiment de la ZONE DE COMBAT,\l"
	.string "tu obtiens plus de POINTS DE COMBAT.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_2601AA:: @ 82601AA
	.string "Un grand poster avec l'image de\n"
	.string "LIPPOUTI.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_2601D0:: @ 82601D0
	.string "Un coussin LIPPOUTI à poser\n"
	.string "sur un support.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_260201:: @ 8260201
	.string "Une poupée LIPPOUTI à poser\n"
	.string "sur un support.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_26022F:: @ 826022F
	.string "Une poupée TOGEPI à poser\n"
	.string "sur un support.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_26025B:: @ 826025B
	.string "Une poupée MIAOUSS à poser\n"
	.string "sur un support.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_260287:: @ 8260287
	.string "Une poupée MELOFEE à poser\n"
	.string "sur un support.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_2602B5:: @ 82602B5
	.string "Une poupée METAMORPH à poser\n"
	.string "sur un support.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_2602E0:: @ 82602E0
	.string "Une poupée HERICENDRE à poser\n"
	.string "sur un support.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_26030F:: @ 826030F
	.string "Une poupée GERMIGNON à poser\n"
	.string "sur un support.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_26033E:: @ 826033E
	.string "Une poupée KAIMINUS à poser\n"
	.string "sur un support.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_26036C:: @ 826036C
	.string "Une grande poupée.\n"
	.string "A poser sur un support.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_260397:: @ 8260397
	.string "Monte l'ATTAQUE d'un POKéMON.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_2603BE:: @ 82603BE
	.string "Monte l'ATQ. SPE. d'un POKéMON.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_2603E6:: @ 82603E6
	.string "Monte la DEFENSE d'un POKéMON.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_26040E:: @ 826040E
	.string "Monte la DEF. SPE. d'un POKéMON.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_260436:: @ 8260436
	.string "Monte la VITESSE d'un POKéMON.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_26045C:: @ 826045C
	.string "Monte les PV d'un POKéMON.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_26047A:: @ 826047A
	.string "Objet tenu permettant de restaurer\n"
	.string "les PV au combat.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_2604AC:: @ 82604AC
	.string "Objet tenu qui restaure les stats\n"
	.string "baissées.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_2604D8:: @ 82604D8
	.string "Objet tenu qui permet parfois de\n"
	.string "frapper le premier.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_26050F:: @ 826050F
	.string "Objet tenu qui annule l'attirance\n"
	.string "d'un POKéMON.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_260542:: @ 8260542
	.string "Objet tenu qui intimide et baisse\n"
	.string "la précision.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_260575:: @ 8260575
	.string "Monte la puissance d'une attaque.\n"
	.string "Désactive les autres.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_2605A8:: @ 82605A8
	.string "Objet tenu pouvant apeurer l'ennemi\n"
	.string "s'il est touché.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_2605E2:: @ 82605E2
	.string "Objet tenu pouvant parfois empêcher\n"
	.string "d'être mis K.O.$"

BattleFrontier_BattlePointExchangeServiceCorner_Text_260613:: @ 8260613
	.string "Objet tenu pour monter le taux de\n"
	.string "critiques.$"
