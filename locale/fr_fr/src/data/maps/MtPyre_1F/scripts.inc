MtPyre_1F_MapScripts:: @ 8230F3E
	.byte 0

MtPyre_1F_EventScript_230F3F:: @ 8230F3F
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_230F6E
	msgbox MtPyre_1F_Text_230F8A, MSGBOX_DEFAULT
	giveitem_std ITEM_CLEANSE_TAG
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_230F6E:: @ 8230F6E
	msgbox MtPyre_1F_Text_231005, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_230F78:: @ 8230F78
	msgbox MtPyre_1F_Text_23104F, MSGBOX_NPC
	end

MtPyre_1F_EventScript_230F81:: @ 8230F81
	msgbox MtPyre_1F_Text_2310BA, MSGBOX_NPC
	end

MtPyre_1F_Text_230F8A: @ 8230F8A
	.string "Toutes sortes d'êtres se promènent sur\n"
	.string "versants du MONT MEMORIA…\p"
	.string "On ne sait jamais ce qui peut arriver.\n"
	.string "Prends ça. C'est pour ton bien.$"

MtPyre_1F_Text_231005: @ 8231005
	.string "Fais tenir cette RUNE PURIF. à l'un\n"
	.string "de tes POKéMON.\p"
	.string "Ça éloignera les POKéMON sauvages.$"

MtPyre_1F_Text_23104F: @ 823104F
	.string "Es-tu là pour présenter tes respects\n"
	.string "aux esprits des défunts POKéMON?\p"
	.string "Tu dois prendre grand soin de tes\n"
	.string "POKéMON.$"

MtPyre_1F_Text_2310BA: @ 82310BA
	.string "C'est ici que repose mon ZIGZATON\n"
	.string "C'est un endroit que je chéris…$"

