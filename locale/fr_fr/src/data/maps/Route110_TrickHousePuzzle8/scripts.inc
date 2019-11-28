Route110_TrickHousePuzzle8_MapScripts:: @ 826E801
	.byte 0

Route110_TrickHousePuzzle8_EventScript_26E802:: @ 826E802
	lockall
	compare VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0
	goto_if_eq Route110_TrickHousePuzzle8_EventScript_26E814
	goto Route110_TrickHousePuzzle8_EventScript_26A3DB
	end

Route110_TrickHousePuzzle8_EventScript_26E814:: @ 826E814
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 1
	goto Route110_TrickHousePuzzle8_EventScript_26A3E5
	end

Route110_TrickHousePuzzle8_EventScript_26E81F:: @ 826E81F
	trainerbattle_single TRAINER_VINCENT, Route110_TrickHousePuzzle8_Text_26E8CD, Route110_TrickHousePuzzle8_Text_26E8F6
	msgbox Route110_TrickHousePuzzle8_Text_26E918, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_26E836:: @ 826E836
	trainerbattle_single TRAINER_KEIRA, Route110_TrickHousePuzzle8_Text_26E954, Route110_TrickHousePuzzle8_Text_26E97F
	msgbox Route110_TrickHousePuzzle8_Text_26E99F, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_26E84D:: @ 826E84D
	trainerbattle_single TRAINER_LEROY, Route110_TrickHousePuzzle8_Text_26E9D7, Route110_TrickHousePuzzle8_Text_26EA14
	msgbox Route110_TrickHousePuzzle8_Text_26EA3F, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_26E864:: @ 826E864
	.string "{PLAYER} écrit le code secret\n"
	.string "sur la porte.\p"
	.string "“J'aime le MAITRE DES PIEGES.”\n"
	.string "… … … … … … … …\p"
	.string "La porte s'ouvre!$"

Route110_TrickHousePuzzle8_Text_26E8CD: @ 826E8CD
	.string "Peu de DRESSEURS sont arrivés\n"
	.string "aussi loin.$"

Route110_TrickHousePuzzle8_Text_26E8F6: @ 826E8F6
	.string "Ça doit vouloir dire que tu es balèze…$"

Route110_TrickHousePuzzle8_Text_26E918: @ 826E918
	.string "Tu as battu le MAITRE de la LIGUE\n"
	.string "POKéMON? Les bras m'en tombent!$"

Route110_TrickHousePuzzle8_Text_26E954: @ 826E954
	.string "C'est une sacrée chance de se battre\n"
	.string "contre moi!$"

Route110_TrickHousePuzzle8_Text_26E97F: @ 826E97F
	.string "C'est impossible!\n"
	.string "Je ne peux pas perdre!$"

Route110_TrickHousePuzzle8_Text_26E99F: @ 826E99F
	.string "Ta victoire tient du miracle.\n"
	.string "Tu vas pouvoir frimer.$"

Route110_TrickHousePuzzle8_Text_26E9D7: @ 826E9D7
	.string "Toi aussi, tu luttes pour relever le défi\n"
	.string "de la MAISON DES PIEGES.$"

Route110_TrickHousePuzzle8_Text_26EA14: @ 826EA14
	.string "Mmmh. Je vois…\n"
	.string "Ton style est très impressionnant.$"

Route110_TrickHousePuzzle8_Text_26EA3F: @ 826EA3F
	.string "Tu devrais plaire au MAITRE DES PIEGES.$"
