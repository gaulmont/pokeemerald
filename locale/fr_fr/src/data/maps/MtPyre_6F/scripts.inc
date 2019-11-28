MtPyre_6F_MapScripts:: @ 8231D3A
	.byte 0

MtPyre_6F_EventScript_231D3B:: @ 8231D3B
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_231DB4, MtPyre_6F_Text_231DE2, MtPyre_6F_EventScript_231D67
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq MtPyre_6F_EventScript_231D86
	msgbox MtPyre_6F_Text_231DFC, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_231D67:: @ 8231D67
	special sub_80B4808
	waitmovement 0
	msgbox MtPyre_6F_Text_231E43, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_231D86:: @ 8231D86
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_231EB3, MtPyre_6F_Text_231ECB
	msgbox MtPyre_6F_Text_231EE1, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_231D9D:: @ 8231D9D
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_231F11, MtPyre_6F_Text_231F4A
	msgbox MtPyre_6F_Text_231F5C, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_231DB4: @ 8231DB4
	.string "Quand je suis ici…\n"
	.string "Un étrange pouvoir s'empare de moi…$"

MtPyre_6F_Text_231DE2: @ 8231DE2
	.string "Le pouvoir s'affaiblit…$"

MtPyre_6F_Text_231DFC: @ 8231DFC
	.string "Ce pouvoir vient peut-être des esprits\n"
	.string "errants des POKéMON qui reposent ici…$"

MtPyre_6F_Text_231E43: @ 8231E43
	.string "J'ai perdu ce match, mais…\n"
	.string "J'ai ce petit don en moi…\p"
	.string "Et sans même poser les mains\n"
	.string "sur ton POKéNAV…$"

MtPyre_6F_Text_231EB3: @ 8231EB3
	.string "Derrière toi…\n"
	.string "Qu'est-ce que c'est…$"

MtPyre_6F_Text_231ECB: @ 8231ECB
	.string "Quelque chose a disparu…$"

MtPyre_6F_Text_231EE1: @ 8231EE1
	.string "Les POKéMON qui reposent ici…\n"
	.string "Parfois, ils s'amusent…$"

MtPyre_6F_Text_231F11: @ 8231F11
	.string "Est-ce que tu as perdu ton chemin?\n"
	.string "Ne t'inquiète pas, je suis là!$"

MtPyre_6F_Text_231F4A: @ 8231F4A
	.string "Tu n'avais pas perdu ton chemin?$"

MtPyre_6F_Text_231F5C: @ 8231F5C
	.string "Je pensais qu'un DRESSEUR perdu\n"
	.string "serait plus facile à battre.\p"
	.string "Je m'étais trompé et je ne\n"
	.string "recommencerai plus…$"

