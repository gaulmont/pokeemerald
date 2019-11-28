Route110_TrickHousePuzzle4_MapScripts:: @ 826C860
	.byte 0

Route110_TrickHousePuzzle4_EventScript_26C861:: @ 826C861
	lockall
	compare VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0
	goto_if_eq Route110_TrickHousePuzzle4_EventScript_26C873
	goto Route110_TrickHousePuzzle4_EventScript_26A3DB
	end

Route110_TrickHousePuzzle4_EventScript_26C873:: @ 826C873
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto Route110_TrickHousePuzzle4_EventScript_26A3E5
	end

Route110_TrickHousePuzzle4_EventScript_26C87E:: @ 826C87E
	trainerbattle_single TRAINER_CORA, Route110_TrickHousePuzzle4_Text_26C92D, Route110_TrickHousePuzzle4_Text_26C96E
	msgbox Route110_TrickHousePuzzle4_Text_26C9A2, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_26C895:: @ 826C895
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_26C9E4, Route110_TrickHousePuzzle4_Text_26CA20
	msgbox Route110_TrickHousePuzzle4_Text_26CA53, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_26C8AC:: @ 826C8AC
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_26CA9C, Route110_TrickHousePuzzle4_Text_26CACB
	msgbox Route110_TrickHousePuzzle4_Text_26CAD1, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_Text_26C8C3: @ 826C8C3
	.string "{PLAYER} écrit le code secret\n"
	.string "sur la porte.\p"
	.string "“Le MAITRE DES PIEGES est cool.”\n"
	.string "… … … … … … … …\p"
	.string "La porte s'ouvre!$"

Route110_TrickHousePuzzle4_Text_26C92D: @ 826C92D
	.string "Tous ces trucs à résoudre, c'est trop\n"
	.string "compliqué. Je voulais juste me battre!$"

Route110_TrickHousePuzzle4_Text_26C96E: @ 826C96E
	.string "Même si j'ai perdu, je préfère me battre!$"

Route110_TrickHousePuzzle4_Text_26C9A2: @ 826C9A2
	.string "Tu n'es pas d'accord? Ce que tu\n"
	.string "cherches, c'est surtout des DRESSEURS.$"

Route110_TrickHousePuzzle4_Text_26C9E4: @ 826C9E4
	.string "Hé, hé! Des rochers comme ça, je peux\n"
	.string "les pousser avec un seul doigt!$"

Route110_TrickHousePuzzle4_Text_26CA20: @ 826CA20
	.string "Je peux pousser des rochers, mais je\n"
	.string "n'arrive pas à résoudre les énigmes…$"

Route110_TrickHousePuzzle4_Text_26CA53: @ 826CA53
	.string "Il ne suffit pas d'être musclé…\n"
	.string "Il faut utiliser sa tête et être malin!$"

Route110_TrickHousePuzzle4_Text_26CA9C: @ 826CA9C
	.string "La MAISON DES PIEGES est de plus en\n"
	.string "plus compliquée, n'est-ce pas?$"

Route110_TrickHousePuzzle4_Text_26CACB: @ 826CACB
	.string "Aaargh!$"

Route110_TrickHousePuzzle4_Text_26CAD1: @ 826CAD1
	.string "Quelqu'un est-il déjà arrivé à la fin?$"

