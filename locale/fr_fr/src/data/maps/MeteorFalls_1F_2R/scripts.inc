MeteorFalls_1F_2R_MapScripts:: @ 822C4DD
	.byte 0

MeteorFalls_1F_2R_EventScript_22C4DE:: @ 822C4DE
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_22C608, MeteorFalls_1F_2R_Text_22C678, MeteorFalls_1F_2R_EventScript_22C50A
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq MeteorFalls_1F_2R_EventScript_22C529
	msgbox MeteorFalls_1F_2R_Text_22C6A3, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_22C50A:: @ 822C50A
	special sub_80B4808
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_22C6F6, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_22C529:: @ 822C529
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_22C73F, MeteorFalls_1F_2R_Text_22C7AD
	msgbox MeteorFalls_1F_2R_Text_22C7D8, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_22C540:: @ 822C540
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_22C843, MeteorFalls_1F_2R_Text_22C89C, MeteorFalls_1F_2R_Text_22C92B, MeteorFalls_1F_2R_EventScript_22C570
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq MeteorFalls_1F_2R_EventScript_22C589
	msgbox MeteorFalls_1F_2R_Text_22C8C1, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_22C570:: @ 822C570
	msgbox MeteorFalls_1F_2R_Text_22C99C, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_22C589:: @ 822C589
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_22CB47, MeteorFalls_1F_2R_Text_22CBA0, MeteorFalls_1F_2R_Text_22CC27
	msgbox MeteorFalls_1F_2R_Text_22CBC5, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_22C5A4:: @ 822C5A4
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_22C9E6, MeteorFalls_1F_2R_Text_22CA44, MeteorFalls_1F_2R_Text_22CACD, MeteorFalls_1F_2R_EventScript_22C5D4
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq MeteorFalls_1F_2R_EventScript_22C5ED
	msgbox MeteorFalls_1F_2R_Text_22CA70, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_22C5D4:: @ 822C5D4
	msgbox MeteorFalls_1F_2R_Text_22C99C, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_22C5ED:: @ 822C5ED
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_22CC98, MeteorFalls_1F_2R_Text_22CD08, MeteorFalls_1F_2R_Text_22CDAB
	msgbox MeteorFalls_1F_2R_Text_22CD34, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_22C608: @ 822C608
	.string "C'est ici que nous, adeptes des dragons,\n"
	.string "nous entraînons.\p"
	.string "Même le MAITRE nous a rendu visite.\n"
	.string "Tu vois comme c'est spécial ici?$"

MeteorFalls_1F_2R_Text_22C678: @ 822C678
	.string "Arrgh!\n"
	.string "Je n'imaginais pas ta force si grande!$"

MeteorFalls_1F_2R_Text_22C6A3: @ 822C6A3
	.string "La route est encore longue et difficile.\p"
	.string "Quand deviendrons-nous les meilleurs,\n"
	.string "mes POKéMON et moi?$"

MeteorFalls_1F_2R_Text_22C6F6: @ 822C6F6
	.string "Je veux en savoir plus sur ta puissance.\n"
	.string "Laisse-moi t'enregistrer dans mon\l"
	.string "POKéNAV.$"

MeteorFalls_1F_2R_Text_22C73F: @ 822C73F
	.string "Depuis notre rencontre, on s'est\n"
	.string "entraînés dur pour devenir numéro un.\p"
	.string "Donne-nous la possibilité de voir à quel\n"
	.string "point notre puissance a augmenté!$"

MeteorFalls_1F_2R_Text_22C7AD: @ 822C7AD
	.string "Arrgh!\n"
	.string "Je n'imaginais pas ta force si grande!$"

MeteorFalls_1F_2R_Text_22C7D8: @ 822C7D8
	.string "Il est évident que tu as poursuivi\n"
	.string "l'entraînement de tes POKéMON.\p"
	.string "Aussi longtemps que tu seras solide,\n"
	.string "je pourrai, moi aussi, l'être davantage!$"

MeteorFalls_1F_2R_Text_22C843: @ 822C843
	.string "JOHN: On a toujours fait des combats\n"
	.string "de POKéMON ensemble.\l"
	.string "On a confiance l'un en l'autre.$"

MeteorFalls_1F_2R_Text_22C89C: @ 822C89C
	.string "JOHN: Oh, non.\n"
	.string "On a perdu, ma douce.$"

MeteorFalls_1F_2R_Text_22C8C1: @ 822C8C1
	.string "JOHN: Nous sommes mariés depuis\n"
	.string "cinquante ans.\p"
	.string "Et il faut que je livre un combat contre\n"
	.string "ma propre femme. Tu imagines?$"

MeteorFalls_1F_2R_Text_22C92B: @ 822C92B
	.string "JOHN: Eh bien, quel jeune DRESSEUR!\p"
	.string "Tu veux te battre avec nous? Si oui, il\n"
	.string "faudra revenir avec plus de POKéMON.$"

MeteorFalls_1F_2R_Text_22C99C: @ 822C99C
	.string "JOHN: Jeune DRESSEUR, nous\n"
	.string "affronteras-tu de nouveau si la\l"
	.string "chance se présente?$"

MeteorFalls_1F_2R_Text_22C9E6: @ 822C9E6
	.string "JAY: Nous sommes mariés depuis\n"
	.string "cinquante ans.\p"
	.string "Le lien qui nous unit en tant que couple\n"
	.string "ne pourra jamais être rompu.$"

MeteorFalls_1F_2R_Text_22CA44: @ 822CA44
	.string "JAY: Oh non!\n"
	.string "On a perdu, mon cher époux.$"

MeteorFalls_1F_2R_Text_22CA70: @ 822CA70
	.string "JAY: Cinquante ans de mariage…\p"
	.string "Quand on n'est pas d'accord, on règle\n"
	.string "toujours ça par un combat de POKéMON…$"

MeteorFalls_1F_2R_Text_22CACD: @ 822CACD
	.string "JAY: Tu es un jeune DRESSEUR, hein?\p"
	.string "Pour te battre contre nous, il faut que\n"
	.string "tu reviennes avec plus de POKéMON.$"

MeteorFalls_1F_2R_Text_22CB47: @ 822CB47
	.string "JOHN: On a toujours fait des combats\n"
	.string "de POKéMON ensemble.\p"
	.string "On a confiance l'un en l'autre.$"

MeteorFalls_1F_2R_Text_22CBA0: @ 822CBA0
	.string "JOHN: Oh, non!\n"
	.string "On a perdu, ma douce.$"

MeteorFalls_1F_2R_Text_22CBC5: @ 822CBC5
	.string "JOHN: Cinquante ans de mariage…\p"
	.string "A la réflexion, ma chère femme et moi,\n"
	.string "on s'est battus jour après jour…$"

MeteorFalls_1F_2R_Text_22CC27: @ 822CC27
	.string "JOHN: Eh bien, quel jeune DRESSEUR!\p"
	.string "Tu veux te battre avec nous? Si oui, il\n"
	.string "faudra revenir avec plus de POKéMON.$"

MeteorFalls_1F_2R_Text_22CC98: @ 822CC98
	.string "JAY: Nous sommes mariés depuis\n"
	.string "cinquante ans.\p"
	.string "On s'est toujours soutenus.\n"
	.string "Ça nous a rendus forts.$"

MeteorFalls_1F_2R_Text_22CD08: @ 822CD08
	.string "JAY: Oh non!\n"
	.string "On a perdu, mon cher époux.$"

MeteorFalls_1F_2R_Text_22CD34: @ 822CD34
	.string "JAY: Cinquante ans de mariage…\n"
	.string "Tellement de choses se sont passées!\p"
	.string "que l'on va encore avoir\n"
	.string "de bons souvenirs ensemble.$"

MeteorFalls_1F_2R_Text_22CDAB: @ 822CDAB
	.string "JAY: Tu es un jeune DRESSEUR, hein?\p"
	.string "Pour te battre contre nous, il faut que\n"
	.string "tu reviennes avec plus de POKéMON.$"

