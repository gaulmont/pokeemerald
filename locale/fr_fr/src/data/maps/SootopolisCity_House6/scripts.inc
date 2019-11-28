SootopolisCity_House6_MapScripts:: @ 8226F5B
	.byte 0

SootopolisCity_House6_EventScript_226F5C:: @ 8226F5C
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_WAILMER_DOLL, SootopolisCity_House6_EventScript_226FA3
	msgbox SootopolisCity_House6_Text_226FC3, MSGBOX_YESNO
	compare VAR_RESULT, 0
	call_if_eq SootopolisCity_House6_EventScript_226F99
	msgbox SootopolisCity_House6_Text_227034, MSGBOX_DEFAULT
	givedecoration_std DECOR_WAILMER_DOLL
	compare VAR_RESULT, 0
	goto_if_eq SootopolisCity_House6_EventScript_226FAD
	setflag FLAG_RECEIVED_WAILMER_DOLL
	release
	end

SootopolisCity_House6_EventScript_226F99:: @ 8226F99
	msgbox SootopolisCity_House6_Text_22708F, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_226FA3:: @ 8226FA3
	msgbox SootopolisCity_House6_Text_2270B7, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_226FAD:: @ 8226FAD
	bufferdecorationname 1, DECOR_WAILMER_DOLL
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	msgbox SootopolisCity_House6_Text_22704A, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_Text_226FC3: @ 8226FC3
	.string "Bonjour! Vous êtes la première personne\n"
	.string "à venir chez nous depuis longtemps.\p"
	.string "Comme vous illuminez ma journée, je\n"
	.string "vous offre une grande POUPEE WAILMER.$"

SootopolisCity_House6_Text_227034: @ 8227034
	.string "Prenez-en soin!$"

SootopolisCity_House6_Text_22704A: @ 822704A
	.string "Oh, vous la voulez, mais pas maintenant?\n"
	.string "D'accord. Je vous la mets de côté.$"

SootopolisCity_House6_Text_22708F: @ 822708F
	.string "C'est sûr?\n"
	.string "Vous ne voulez pas de cette POUPEE?$"

SootopolisCity_House6_Text_2270B7: @ 82270B7
	.string "J'adore les POUPEE en peluche!$"

