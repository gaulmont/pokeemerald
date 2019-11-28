Route110_TrickHousePuzzle6_MapScripts:: @ 826DDA7
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle6_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHousePuzzle6_MapScript2_26DDB6
	.byte 0

Route110_TrickHousePuzzle6_OnTransition: @ 826DDB2
	special RotatingGate_InitPuzzle
	end

Route110_TrickHousePuzzle6_MapScript2_26DDB6: @ 826DDB6
	map_script_2 VAR_TEMP_0, 16384, Route110_TrickHousePuzzle6_EventScript_26DDC0
	.2byte 0

Route110_TrickHousePuzzle6_EventScript_26DDC0:: @ 826DDC0
	special RotatingGate_InitPuzzleAndGraphics
	end

Route110_TrickHousePuzzle6_EventScript_26DDC4:: @ 826DDC4
	lockall
	compare VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0
	goto_if_eq Route110_TrickHousePuzzle6_EventScript_26DDD6
	goto Route110_TrickHousePuzzle6_EventScript_26A3DB
	end

Route110_TrickHousePuzzle6_EventScript_26DDD6:: @ 826DDD6
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 1
	goto Route110_TrickHousePuzzle6_EventScript_26A3E5
	end

Route110_TrickHousePuzzle6_EventScript_26DDE1:: @ 826DDE1
	trainerbattle_single TRAINER_SOPHIA, Route110_TrickHousePuzzle6_Text_26DE93, Route110_TrickHousePuzzle6_Text_26DED2
	msgbox Route110_TrickHousePuzzle6_Text_26DEF3, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_26DDF8:: @ 826DDF8
	trainerbattle_single TRAINER_BENNY, Route110_TrickHousePuzzle6_Text_26DF55, Route110_TrickHousePuzzle6_Text_26DF8D
	msgbox Route110_TrickHousePuzzle6_Text_26DFA0, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_26DE0F:: @ 826DE0F
	trainerbattle_single TRAINER_SEBASTIAN, Route110_TrickHousePuzzle6_Text_26DFD7, Route110_TrickHousePuzzle6_Text_26E004
	msgbox Route110_TrickHousePuzzle6_Text_26E048, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_Text_26DE26: @ 826DE26
	.string "{PLAYER} écrit le code secret\n"
	.string "sur la porte.\p"
	.string "“Le MAITRE DES PIEGES est\n"
	.string "tout pour moi.”\l"
	.string "… … … … … … … …\p"
	.string "La porte s'ouvre!$"

Route110_TrickHousePuzzle6_Text_26DE93: @ 826DE93
	.string "Quand on m'a parlé d'une maison bizarre,\n"
	.string "je me suis sentie obligée d'y aller.$"

Route110_TrickHousePuzzle6_Text_26DED2: @ 826DED2
	.string "J'ai découvert un DRESSEUR balèze!$"

Route110_TrickHousePuzzle6_Text_26DEF3: @ 826DEF3
	.string "Je suis sûre de m'amuser quand\n"
	.string "je viens ici.\p"
	.string "Je ne me lasse pas de ce défi.\n"
	.string "C'est toujours aussi bien!$"

Route110_TrickHousePuzzle6_Text_26DF55: @ 826DF55
	.string "Je pourrais demander à mes POKéMON\n"
	.string "OISEAU de voler au-dessus du mur…$"

Route110_TrickHousePuzzle6_Text_26DF8D: @ 826DF8D
	.string "Gniiiii! J'ai tout raté!$"

Route110_TrickHousePuzzle6_Text_26DFA0: @ 826DFA0
	.string "Hé, hé, hé… Je suppose que j'ai perdu\n"
	.string "parce que j'ai essayé de tricher.$"

Route110_TrickHousePuzzle6_Text_26DFD7: @ 826DFD7
	.string "Toutes ces portes pivotantes me\n"
	.string "donnent le tournis…$"

Route110_TrickHousePuzzle6_Text_26E004: @ 826E004
	.string "Tout tourne autour de moi! Je ne vais\n"
	.string "pas le supporter plus longtemps…$"

Route110_TrickHousePuzzle6_Text_26E048: @ 826E048
	.string "Ça n'a pas l'air de te déranger.\n"
	.string "Ou bien est-ce juste du bluff?$"

