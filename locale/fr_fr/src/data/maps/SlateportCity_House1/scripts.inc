SlateportCity_House1_MapScripts:: @ 8209AA4
	.byte 0

SlateportCity_House1_EventScript_209AA5:: @ 8209AA5
	lock
	faceplayer
	msgbox SlateportCity_House1_Text_209B8E, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_House1_EventScript_209AC6
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_House1_EventScript_209AE9
	end

SlateportCity_House1_EventScript_209AC6:: @ 8209AC6
	msgbox SlateportCity_House1_Text_209BFF, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_ne SlateportCity_House1_EventScript_209AF3
	compare VAR_0x8004, 255
	goto_if_eq SlateportCity_House1_EventScript_209AE9
	end

SlateportCity_House1_EventScript_209AE9:: @ 8209AE9
	msgbox SlateportCity_House1_Text_209D42, MSGBOX_DEFAULT
	release
	end

SlateportCity_House1_EventScript_209AF3:: @ 8209AF3
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq SlateportCity_House1_EventScript_209B46
	special TV_CopyNicknameToStringVar1AndEnsureTerminated
	special TV_CheckMonOTIDEqualsPlayerID
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_House1_EventScript_209B50
	specialvar VAR_RESULT, MonOTNameMatchesPlayer
	special TV_CopyNicknameToStringVar1AndEnsureTerminated
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_House1_EventScript_209B50
	msgbox SlateportCity_House1_Text_209C2B, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_House1_EventScript_209B5A
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_House1_EventScript_209AE9
	end

SlateportCity_House1_EventScript_209B46:: @ 8209B46
	msgbox SlateportCity_House1_Text_209E74, MSGBOX_DEFAULT
	release
	end

SlateportCity_House1_EventScript_209B50:: @ 8209B50
	msgbox SlateportCity_House1_Text_209DF0, MSGBOX_DEFAULT
	release
	end

SlateportCity_House1_EventScript_209B5A:: @ 8209B5A
	msgbox SlateportCity_House1_Text_209CA4, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TV_PutNameRaterShowOnTheAirIfNicknameChanged
	special TV_CopyNicknameToStringVar1AndEnsureTerminated
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_House1_EventScript_209B84
	msgbox SlateportCity_House1_Text_209D5E, MSGBOX_DEFAULT
	release
	end

SlateportCity_House1_EventScript_209B84:: @ 8209B84
	msgbox SlateportCity_House1_Text_209CD4, MSGBOX_DEFAULT
	release
	end

SlateportCity_House1_Text_209B8E: @ 8209B8E
	.string "Je suis le SPECIALISTE DES NOMS!\n"
	.string "Je donne des conseils sur les surnoms\l"
	.string "à choisir.\p"
	.string "Et si j'examinais le surnom que tu as\n"
	.string "donné à l'un de tes POKéMON?$"

SlateportCity_House1_Text_209BFF: @ 8209BFF
	.string "Le surnom de quel POKéMON veux-t\n"
	.string "que je juge?$"

SlateportCity_House1_Text_209C2B: @ 8209C2B
	.string "Hum… {STR_VAR_1}, c'est ça? C'est pas\n"
	.string "mal, ce surnom que tu lui as donné.\p"
	.string "Mais que dirais-tu de lui en\n"
	.string "donner un meilleur?$"

SlateportCity_House1_Text_209CA4: @ 8209CA4
	.string "Bon, alors quel va être le\n"
	.string "nouveau surnom?$"

SlateportCity_House1_Text_209CD4: @ 8209CD4
	.string "Très bien! A partir de maintenant, ce\n"
	.string "POKéMON sera surnommé {STR_VAR_1}!\p"
	.string "C'est mieux qu'avant!\n"
	.string "Tu en as de la chance!$"

SlateportCity_House1_Text_209D42: @ 8209D42
	.string "Je vois.\n"
	.string "Reviens me voir.$"

SlateportCity_House1_Text_209D5E: @ 8209D5E
	.string "Ça y est! A partir de maintenant, ce\n"
	.string "POKéMON sera surnommé {STR_VAR_1}!\p"
	.string "Ce surnom ne semble pas très différent\n"
	.string "de l'autre et pourtant, il sonne mieux!\p"
	.string "Tu en as de la chance!$"

SlateportCity_House1_Text_209DF0: @ 8209DF0
	.string "Hum… C'est {STR_VAR_1}!\p"
	.string "C'est un magnifique surnom!\n"
	.string "Rien à redire!\p"
	.string "Tu ferais bien de chouchouter ton\n"
	.string "{STR_VAR_1} à partir de maintenant.$"

SlateportCity_House1_Text_209E74: @ 8209E74
	.string "Voyons, voyons…\n"
	.string "Ce n'est qu'un OEUF!$"

