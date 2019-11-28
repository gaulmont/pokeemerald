Route110_TrickHousePuzzle1_MapScripts:: @ 826B90F
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_MapScript1_26B915
	.byte 0

Route110_TrickHousePuzzle1_MapScript1_26B915: @ 826B915
	compare VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2
	goto_if_eq Route110_TrickHousePuzzle1_EventScript_26B921
	end

Route110_TrickHousePuzzle1_EventScript_26B921:: @ 826B921
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, 0
	end

Route110_TrickHousePuzzle1_EventScript_26B92B:: @ 826B92B
	lockall
	compare VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0
	goto_if_eq Route110_TrickHousePuzzle1_EventScript_26B93D
	goto Route110_TrickHousePuzzle1_EventScript_26A3DB
	end

Route110_TrickHousePuzzle1_EventScript_26B93D:: @ 826B93D
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
	goto Route110_TrickHousePuzzle1_EventScript_26A3E5
	end

Route110_TrickHousePuzzle1_EventScript_26B948:: @ 826B948
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_26B9FB, Route110_TrickHousePuzzle1_Text_26BA3F
	msgbox Route110_TrickHousePuzzle1_Text_26BA57, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_26B95F:: @ 826B95F
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_26BA82, Route110_TrickHousePuzzle1_Text_26BAB0
	msgbox Route110_TrickHousePuzzle1_Text_26BAC3, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_26B976:: @ 826B976
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_26BB10, Route110_TrickHousePuzzle1_Text_26BB2E
	msgbox Route110_TrickHousePuzzle1_Text_26BB52, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_Text_26B98D:: @ 826B98D
	.string "{PLAYER} écrit le code secret\n"
	.string "sur la porte.\p"
	.string "“Le MAITRE DES PIEGES est formidable.”\n"
	.string "… … … … … … … …\p"
	.string "La porte s'ouvre!$"

Route110_TrickHousePuzzle1_Text_26B9FB: @ 826B9FB
	.string "Grâce à COUPE, que je viens d'apprendre,\n"
	.string "je vais vaincre à la force de ma lame!$"

Route110_TrickHousePuzzle1_Text_26BA3F: @ 826BA3F
	.string "Pourquoi as-tu l'air si sérieux?$"

Route110_TrickHousePuzzle1_Text_26BA57: @ 826BA57
	.string "Je ne me lasse pas de trancher,\n"
	.string "découper et taillader!$"

Route110_TrickHousePuzzle1_Text_26BA82: @ 826BA82
	.string "Je me suis retrouvé dans cette étrange\n"
	.string "maison par hasard…$"

Route110_TrickHousePuzzle1_Text_26BAB0: @ 826BAB0
	.string "Et maintenant, j'ai perdu…$"

Route110_TrickHousePuzzle1_Text_26BAC3: @ 826BAC3
	.string "J'ai perdu mon chemin, un combat et\n"
	.string "la tête… Je n'arrive pas à sortir…$"

Route110_TrickHousePuzzle1_Text_26BB10: @ 826BB10
	.string "Mais qui est le MAITRE DES PIEGES?$"

Route110_TrickHousePuzzle1_Text_26BB2E: @ 826BB2E
	.string "Tu as gagné parce que j'étais perdue\n"
	.string "dans mes pensées!$"

Route110_TrickHousePuzzle1_Text_26BB52: @ 826BB52
	.string "Tu es balèze!\n"
	.string "Mais qui es-tu, au juste?$"

