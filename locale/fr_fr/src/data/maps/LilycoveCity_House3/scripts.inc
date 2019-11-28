LilycoveCity_House3_MapScripts:: @ 821EE3C
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition: @ 821EE42
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_21EE4B:: @ 821EE4B
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_21EF99, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_House3_EventScript_21EE75
	msgbox LilycoveCity_House3_Text_21F0F8, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_21EE75:: @ 821EE75
	msgbox LilycoveCity_House3_Text_21F0A9, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_21EE8A:: @ 821EE8A
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_21F430, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_21EEA1:: @ 821EEA1
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_21EF71
	case 1, LilycoveCity_House3_EventScript_21EF7B
	case 2, LilycoveCity_House3_EventScript_21EF85
	case 3, LilycoveCity_House3_EventScript_21EF8F
	end

LilycoveCity_House3_EventScript_21EED5:: @ 821EED5
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_21EF71
	case 1, LilycoveCity_House3_EventScript_21EF7B
	case 2, LilycoveCity_House3_EventScript_21EF85
	case 3, LilycoveCity_House3_EventScript_21EF8F
	end

LilycoveCity_House3_EventScript_21EF09:: @ 821EF09
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_21EF71
	case 1, LilycoveCity_House3_EventScript_21EF7B
	case 2, LilycoveCity_House3_EventScript_21EF85
	case 3, LilycoveCity_House3_EventScript_21EF8F
	end

LilycoveCity_House3_EventScript_21EF3D:: @ 821EF3D
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_21EF71
	case 1, LilycoveCity_House3_EventScript_21EF7B
	case 2, LilycoveCity_House3_EventScript_21EF85
	case 3, LilycoveCity_House3_EventScript_21EF8F
	end

LilycoveCity_House3_EventScript_21EF71:: @ 821EF71
	msgbox LilycoveCity_House3_Text_21F4A7, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_21EF7B:: @ 821EF7B
	msgbox LilycoveCity_House3_Text_21F4E0, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_21EF85:: @ 821EF85
	msgbox LilycoveCity_House3_Text_21F523, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_21EF8F:: @ 821EF8F
	msgbox LilycoveCity_House3_Text_21F55A, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_21EF99: @ 821EF99
	.string "Oh, ça alors! Tu voyages en solitaire?\n"
	.string "Mais tu es si jeune! C'est bien pour toi!\p"
	.string "Je suis sûre que tu pourrais apprendre\n"
	.string "un truc ou deux à mes enfants!\p"
	.string "Moi? Je suis une spécialiste\n"
	.string "des {POKEBLOCK}S.\p"
	.string "Si je me concentre un peu, je peux\n"
	.string "concocter de fabuleux {POKEBLOCK}S.\p"
	.string "Tu veux apprendre des choses de la\n"
	.string "spécialiste des {POKEBLOCK}S?$"

LilycoveCity_House3_Text_21F0A9: @ 821F0A9
	.string "Tu ne veux vraiment pas?\p"
	.string "Tu ne devrais pas toujours vouloir\n"
	.string "tout faire toi-même, mon p'tit!$"

LilycoveCity_House3_Text_21F0F8: @ 821F0F8
	.string "Bien! Quelle âme avertie!\n"
	.string "C'est un peu long, alors écoute bien!\p"
	.string "C'est bon, je peux commencer?\p"
	.string "Si tu observes les {POKEBLOCK}S,\n"
	.string "tu verras qu'ils sont classés\l"
	.string "selon leur onctuosité.\p"
	.string "Plus le chiffre est bas, plus c'est\n"
	.string "onctueux et mieux c'est. N'oublie pas!\p"
	.string "Un bon {POKEBLOCK} est très onctueux\n"
	.string "et a un niveau élevé.\p"
	.string "Un POKéMON peut manger plus de\n"
	.string "bons {POKEBLOCK}S que de normaux.\p"
	.string "Et c'est important.\p"
	.string "Pour faire des {POKEBLOCK}S onctueux, il\n"
	.string "faut utiliser plusieurs sortes de\l"
	.string "BAIES.\p"
	.string "Ne sois pas avare! La variété des BAIES\n"
	.string "influe sur l'onctuosité des {POKEBLOCK}S.\p"
	.string "Et autre chose…\p"
	.string "Plus il y a de personnes qui mixent les\n"
	.string "BAIES, plus les {POKEBLOCK}S sont onctueux.\p"
	.string "C'est pourquoi tu dois parler aux\n"
	.string "autres et faire des {POKEBLOCK}S avec eux.\p"
	.string "Voilà à peu près tout ce que tu dois\n"
	.string "savoir pour faire de bons {POKEBLOCK}S.\p"
	.string "Si chacun avait des POKéMON qu'il\n"
	.string "aime, d'onctueux {POKEBLOCK}S, et une famille\l"
	.string "aimante, le monde ne serait que bonheur.\p"
	.string "N'abandonne pas, mon p'tit.$"

LilycoveCity_House3_Text_21F430: @ 821F430
	.string "WQuand ma femme a mis au monde des\n"
	.string "quadruplés, ça a été un choc!\p"
	.string "Mais maintenant, je suis heureux de les\n"
	.string "voir jouer ensemble.$"

LilycoveCity_House3_Text_21F4A7: @ 821F4A7
	.string "On va faire des COMBATS MULTI, mais\n"
	.string "je sais que je vais gagner.$"

LilycoveCity_House3_Text_21F4E0: @ 821F4E0
	.string "On aime bien échanger des données\n"
	.string "au CENTRE DE DONNEES.\p"
	.string "Mais qu'est-ce qu'on va échanger\n"
	.string "au juste?$"

LilycoveCity_House3_Text_21F523: @ 821F523
	.string "On va faire de super {POKEBLOCK}S\n"
	.string "avec un MIXEUR!$"

LilycoveCity_House3_Text_21F55A: @ 821F55A
	.string "Je veux que tu voies à quel point mon\n"
	.string "POKéMON est fort. Alors on va tous\l"
	.string "les deux participer à un CONCOURS.$"