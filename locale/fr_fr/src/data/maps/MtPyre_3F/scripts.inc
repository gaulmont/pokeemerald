MtPyre_3F_MapScripts:: @ 8231752
	.byte 0

MtPyre_3F_EventScript_231753:: @ 8231753
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_2317E3, MtPyre_3F_Text_231853
	msgbox MtPyre_3F_Text_231869, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_23176A:: @ 823176A
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_2318A1, MtPyre_3F_Text_2318DD
	msgbox MtPyre_3F_Text_2318F2, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_231781:: @ 8231781
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_231952, MtPyre_3F_Text_23196A, MtPyre_3F_EventScript_2317AD
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq MtPyre_3F_EventScript_2317CC
	msgbox MtPyre_3F_Text_23199B, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_2317AD:: @ 82317AD
	special sub_80B4808
	waitmovement 0
	msgbox MtPyre_3F_Text_231A49, MSGBOX_DEFAULT
	register_matchcall TRAINER_GABRIELLE_1
	release
	end

MtPyre_3F_EventScript_2317CC:: @ 82317CC
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_231AAB, MtPyre_3F_Text_231AE6
	msgbox MtPyre_3F_Text_231B0D, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_2317E3: @ 82317E3
	.string "L'air pur de la montagne a augmenté\n"
	.string "mon pouvoir psychique!\p"
	.string "Un p'tit mioche comme toi…\n"
	.string "Tu rêves de gagner?$"

MtPyre_3F_Text_231853: @ 8231853
	.string "J'ai honte de moi…$"

MtPyre_3F_Text_231869: @ 8231869
	.string "Mes pouvoirs psychiques se sont sans\n"
	.string "aucun doute accrus, mais…$"

MtPyre_3F_Text_2318A1: @ 82318A1
	.string "Ah ah ah ah!\p"
	.string "C'est pas un endroit pour les mômes,\n"
	.string "encore moins pour toi!$"

MtPyre_3F_Text_2318DD: @ 82318DD
	.string "Il est clair que j'ai perdu…$"

MtPyre_3F_Text_2318F2: @ 82318F2
	.string "Ça veut dire que mon entraînement\n"
	.string "n'est pas encore suffisant…\p"
	.string "Il faut que je continue à travailler\n"
	.string "pour arriver au plus haut niveau…\p"
	.string "Allez! Je suis motivée!$"

MtPyre_3F_Text_231952: @ 8231952
	.string "Qu'est-ce que tu viens faire ici?$"

MtPyre_3F_Text_23196A: @ 823196A
	.string "C'était époustouflant!\n"
	.string "Tu es un DRESSEUR d'exception!$"

MtPyre_3F_Text_23199B: @ 823199B
	.string "Les POKéMON qui ne sont plus de\n"
	.string "ce monde…\l"
	.string "Les POKéMON à tes côtés maintenant…\p"
	.string "Et les POKéMON que tu rencontreras\n"
	.string "dans le futur…\p"
	.string "Ils méritent tous d'être aimés de la\n"
	.string "même façon. Ne l'oublie pas!.$"

MtPyre_3F_Text_231A49: @ 8231A49
	.string "J'aimerais revoir tes POKéMON quand\n"
	.string "ils auront plus d'expérience…\p"
	.string "Laisse-moi voir ton POKéNAV.$"

MtPyre_3F_Text_231AAB: @ 8231AAB
	.string "Oh, c'est toi…\p"
	.string "Tu es là pour me montrer comme tes\n"
	.string "POKéMON ont progressé?$"

MtPyre_3F_Text_231AE6: @ 8231AE6
	.string "Incroyable! Je suis vraiment heureuse\n"
	.string "de connaître quelqu'un comme toi!$"

MtPyre_3F_Text_231B0D: @ 8231B0D
	.string "Les POKéMON qui ne sont plus de\n"
	.string "ce monde…\l"
	.string "Les POKéMON à tes côtés maintenant…\p"
	.string "Et les POKéMON que tu rencontreras\n"
	.string "dans le futur…\p"
	.string "Ils méritent tous d'être aimés de la\n"
	.string "même façon. Je vois que tu n'as\l"
	.string "pas oublié!$"

