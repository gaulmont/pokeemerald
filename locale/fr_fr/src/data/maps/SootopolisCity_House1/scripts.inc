SootopolisCity_House1_MapScripts:: @ 822694C
	.byte 0

SootopolisCity_House1_EventScript_22694D:: @ 822694D
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM31, SootopolisCity_House1_EventScript_226984
	msgbox SootopolisCity_House1_Text_2269A1, MSGBOX_DEFAULT
	giveitem_std ITEM_TM31
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM31
	msgbox SootopolisCity_House1_Text_226A13, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House1_EventScript_226984:: @ 8226984
	msgbox SootopolisCity_House1_Text_226A13, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House1_EventScript_22698E:: @ 822698E
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KECLEON, 0
	msgbox SootopolisCity_House1_Text_226A60, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House1_Text_2269A1: @ 82269A1
	.string "Je suis resté trente ans à\n"
	.string "ATALANOPOLIS pour améliorer\l"
	.string "mes connaissances.\p"
	.string "J'ai conçu une CT renversante.\n"
	.string "Je te la lègue!$"

SootopolisCity_House1_Text_226A13: @ 8226A13
	.string "La CT31 contient CASSE-BRIQUE!\n"
	.string "Un coup si terrible que je n'peux\l"
	.string "le décrire.$"

SootopolisCity_House1_Text_226A60: @ 8226A60
	.string "KECLEON: Eooon.$"

