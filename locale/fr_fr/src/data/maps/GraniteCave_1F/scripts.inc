GraniteCave_1F_MapScripts:: @ 822DA5D
	.byte 0

GraniteCave_1F_EventScript_22DA5E:: @ 822DA5E
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM05, GraniteCave_1F_EventScript_22DA8A
	msgbox GraniteCave_1F_Text_22DA94, MSGBOX_DEFAULT
	giveitem_std ITEM_HM05
	setflag FLAG_RECEIVED_HM05
	msgbox GraniteCave_1F_Text_22DBB7, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_22DA8A:: @ 822DA8A
	msgbox GraniteCave_1F_Text_22DBB7, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_22DA94: @ 822DA94
	.string "Hé, toi!\n"
	.string "Il fait terriblement sombre là-dedans.\l"
	.string "Ça va être difficile à explorer.\p"
	.string "Ce type qui est passé tout à l'heure…\n"
	.string "PIERRE, je crois que c'était ça.\p"
	.string "Il savait utiliser FLASH, alors il n'a pas\n"
	.string "dû avoir de problème, mais…\p"
	.string "Pour nous, les MONTAGNARDS, la devise\n"
	.string "est d'aider ceux que l'on rencontre.\p"
	.string "Vas-y et bon courage!$"

GraniteCave_1F_Text_22DBB7: @ 822DBB7
	.string "Apprends cette CS FLASH\n"
	.string "à un POKéMON et utilise-la.\p"
	.string "Ça permet d'éclairer même les cavernes\n"
	.string "les plus sombres.\p"
	.string "Mais pour l'utiliser, il faut le BADGE\n"
	.string "de l'ARENE POKéMON de MYOKARA.$"

