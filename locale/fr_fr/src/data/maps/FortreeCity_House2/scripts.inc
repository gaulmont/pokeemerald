FortreeCity_House2_MapScripts:: @ 82177CA
	.byte 0

FortreeCity_House2_EventScript_2177CB:: @ 82177CB
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM10, FortreeCity_House2_EventScript_21786E
	call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_217862
	msgbox FortreeCity_House2_Text_2178D6, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, 1
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_217878
	msgbox FortreeCity_House2_Text_21796A, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, 1
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_217878
	msgbox FortreeCity_House2_Text_2179C9, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, 1
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_217878
	msgbox FortreeCity_House2_Text_217A28, MSGBOX_DEFAULT
	giveitem_std ITEM_TM10
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM10
	msgbox FortreeCity_House2_Text_217A91, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_217862:: @ 8217862
	msgbox FortreeCity_House2_Text_217882, MSGBOX_DEFAULT
	setflag FLAG_MET_HIDDEN_POWER_GIVER
	return

FortreeCity_House2_EventScript_21786E:: @ 821786E
	msgbox FortreeCity_House2_Text_217A91, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_217878:: @ 8217878
	msgbox FortreeCity_House2_Text_217AC7, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_Text_217882: @ 8217882
	.string "Les humains… Les POKéMON…\p"
	.string "Leurs pouvoirs cachés se développent\n"
	.string "lorsqu'ils vivent en milieu naturel…$"

FortreeCity_House2_Text_2178D6: @ 82178D6
	.string "Laisse la vieille dame que je suis voir si\n"
	.string "ton pouvoir caché s'est éveillé…\p"
	.string "J'ai une pièce dans une main.\p"
	.string "Dans quelle main l'ai-je cachée?\n"
	.string "La droite ou la gauche?$"

FortreeCity_House2_Text_21796A: @ 821796A
	.string "Oh! Oui, c'est juste!\p"
	.string "On va réessayer.\p"
	.string "Dans quelle main est la pièce?\n"
	.string "La droite ou la gauche?$"

FortreeCity_House2_Text_2179C9: @ 82179C9
	.string "Oh! Oui, c'est juste!\p"
	.string "On va réessayer.\p"
	.string "Dans quelle main est la pièce?\n"
	.string "La droite ou la gauche?$"

FortreeCity_House2_Text_217A28: @ 8217A28
	.string "Oh! Superbe!\n"
	.string "Ton pouvoir caché s'est réveillé!\p"
	.string "Tiens, prends ça et révèle le pouvoir\n"
	.string "caché de tes POKéMON.$"

FortreeCity_House2_Text_217A91: @ 8217A91
	.string "PUISSANCE CACHEE est une capacité\n"
	.string "qui diffère selon les POKéMON.$"

FortreeCity_House2_Text_217AC7: @ 8217AC7
	.string "Non, dommage.\n"
	.string "Tu n'as pas fait le bon choix.$"

