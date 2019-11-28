Route110_TrickHousePuzzle7_MapScripts:: @ 826E091
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHousePuzzle7_MapScript1_26E0A6
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle7_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle7_MapScript1_26E1B4
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHousePuzzle7_MapScript2_26E1C0
	.byte 0

Route110_TrickHousePuzzle7_MapScript1_26E0A6: @ 826E0A6
	call Route110_TrickHousePuzzle7_EventScript_26E0AC
	end

Route110_TrickHousePuzzle7_EventScript_26E0AC:: @ 826E0AC
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1, Route110_TrickHousePuzzle7_EventScript_26E0DA
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2, Route110_TrickHousePuzzle7_EventScript_26E0ED
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3, Route110_TrickHousePuzzle7_EventScript_26E100
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4, Route110_TrickHousePuzzle7_EventScript_26E113
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5, Route110_TrickHousePuzzle7_EventScript_26E126
	return

Route110_TrickHousePuzzle7_EventScript_26E0DA:: @ 826E0DA
	setmetatile 13, 17, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Up, 0
	setmetatile 12, 16, METATILE_TrickHousePuzzle_Lever_On, 1
	return

Route110_TrickHousePuzzle7_EventScript_26E0ED:: @ 826E0ED
	setmetatile 12, 13, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Up, 0
	setmetatile 12, 11, METATILE_TrickHousePuzzle_Lever_On, 1
	return

Route110_TrickHousePuzzle7_EventScript_26E100:: @ 826E100
	setmetatile 7, 12, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Up, 0
	setmetatile 5, 10, METATILE_TrickHousePuzzle_Lever_On, 1
	return

Route110_TrickHousePuzzle7_EventScript_26E113:: @ 826E113
	setmetatile 6, 6, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Right_Alt, 0
	setmetatile 4, 4, METATILE_TrickHousePuzzle_Lever_On, 1
	return

Route110_TrickHousePuzzle7_EventScript_26E126:: @ 826E126
	setmetatile 8, 4, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Left, 0
	setmetatile 7, 5, METATILE_TrickHousePuzzle_Lever_On, 1
	return

Route110_TrickHousePuzzle7_EventScript_26E139:: @ 826E139
	setmetatile 13, 17, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Down, 0
	setmetatile 12, 16, METATILE_TrickHousePuzzle_Lever_Off, 1
	return

Route110_TrickHousePuzzle7_EventScript_26E14C:: @ 826E14C
	setmetatile 12, 13, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Left, 0
	setmetatile 12, 11, METATILE_TrickHousePuzzle_Lever_Off, 1
	return

Route110_TrickHousePuzzle7_EventScript_26E15F:: @ 826E15F
	setmetatile 7, 12, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Down, 0
	setmetatile 5, 10, METATILE_TrickHousePuzzle_Lever_Off, 1
	return

Route110_TrickHousePuzzle7_EventScript_26E172:: @ 826E172
	setmetatile 6, 6, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Left_Alt, 0
	setmetatile 4, 4, METATILE_TrickHousePuzzle_Lever_Off, 1
	return

Route110_TrickHousePuzzle7_EventScript_26E185:: @ 826E185
	setmetatile 8, 4, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Right, 0
	setmetatile 7, 5, METATILE_TrickHousePuzzle_Lever_Off, 1
	return

Route110_TrickHousePuzzle7_OnTransition: @ 826E198
	compare VAR_TRICK_HOUSE_PUZZLE_7_STATE_2, 1
	goto_if_eq Route110_TrickHousePuzzle7_EventScript_26E1B3
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5
	end

Route110_TrickHousePuzzle7_EventScript_26E1B3:: @ 826E1B3
	end

Route110_TrickHousePuzzle7_MapScript1_26E1B4: @ 826E1B4
	compare VAR_TRICK_HOUSE_PUZZLE_7_STATE_2, 1
	call_if_eq Route110_TrickHousePuzzle7_EventScript_26E0AC
	end

Route110_TrickHousePuzzle7_MapScript2_26E1C0: @ 826E1C0
	map_script_2 VAR_TRICK_HOUSE_PUZZLE_7_STATE_2, 1, Route110_TrickHousePuzzle7_EventScript_26E1CA
	.2byte 0

Route110_TrickHousePuzzle7_EventScript_26E1CA:: @ 826E1CA
	setvar VAR_TRICK_HOUSE_PUZZLE_7_STATE_2, 0
	end

Route110_TrickHousePuzzle7_EventScript_26E1D0:: @ 826E1D0
	lockall
	compare VAR_TRICK_HOUSE_PUZZLE_7_STATE, 0
	goto_if_eq Route110_TrickHousePuzzle7_EventScript_26E1E2
	goto Route110_TrickHousePuzzle7_EventScript_26A3DB
	end

Route110_TrickHousePuzzle7_EventScript_26E1E2:: @ 826E1E2
	setvar VAR_TRICK_HOUSE_PUZZLE_7_STATE, 1
	goto Route110_TrickHousePuzzle7_EventScript_26A3E5
	end

Route110_TrickHousePuzzle7_EventScript_26E1ED:: @ 826E1ED
	lockall
	setvar VAR_TRICK_HOUSE_PUZZLE_7_STATE_2, 1
	warpteleport MAP_ROUTE110_TRICK_HOUSE_PUZZLE7, 255, 3, 19
	waitstate
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_26E1FE:: @ 826E1FE
	lockall
	delay 32
	call_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1, Route110_TrickHousePuzzle7_EventScript_26E0DA
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1, Route110_TrickHousePuzzle7_EventScript_26E139
	special DrawWholeMapView
	playse SE_TK_KASYA
	goto_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1, Route110_TrickHousePuzzle7_EventScript_26E2E9
	goto_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1, Route110_TrickHousePuzzle7_EventScript_26E2EE
	end

Route110_TrickHousePuzzle7_EventScript_26E22D:: @ 826E22D
	lockall
	delay 32
	call_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2, Route110_TrickHousePuzzle7_EventScript_26E0ED
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2, Route110_TrickHousePuzzle7_EventScript_26E14C
	special DrawWholeMapView
	playse SE_TK_KASYA
	goto_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2, Route110_TrickHousePuzzle7_EventScript_26E2F3
	goto_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2, Route110_TrickHousePuzzle7_EventScript_26E2F8
	end

Route110_TrickHousePuzzle7_EventScript_26E25C:: @ 826E25C
	lockall
	delay 32
	call_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3, Route110_TrickHousePuzzle7_EventScript_26E100
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3, Route110_TrickHousePuzzle7_EventScript_26E15F
	special DrawWholeMapView
	playse SE_TK_KASYA
	goto_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3, Route110_TrickHousePuzzle7_EventScript_26E2FD
	goto_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3, Route110_TrickHousePuzzle7_EventScript_26E302
	end

Route110_TrickHousePuzzle7_EventScript_26E28B:: @ 826E28B
	lockall
	delay 32
	call_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4, Route110_TrickHousePuzzle7_EventScript_26E113
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4, Route110_TrickHousePuzzle7_EventScript_26E172
	special DrawWholeMapView
	playse SE_TK_KASYA
	goto_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4, Route110_TrickHousePuzzle7_EventScript_26E307
	goto_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4, Route110_TrickHousePuzzle7_EventScript_26E30C
	end

Route110_TrickHousePuzzle7_EventScript_26E2BA:: @ 826E2BA
	lockall
	delay 32
	call_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5, Route110_TrickHousePuzzle7_EventScript_26E126
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5, Route110_TrickHousePuzzle7_EventScript_26E185
	special DrawWholeMapView
	playse SE_TK_KASYA
	goto_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5, Route110_TrickHousePuzzle7_EventScript_26E311
	goto_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5, Route110_TrickHousePuzzle7_EventScript_26E316
	end

Route110_TrickHousePuzzle7_EventScript_26E2E9:: @ 826E2E9
	setflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_26E2EE:: @ 826E2EE
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_26E2F3:: @ 826E2F3
	setflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_26E2F8:: @ 826E2F8
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_26E2FD:: @ 826E2FD
	setflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_26E302:: @ 826E302
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_26E307:: @ 826E307
	setflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_26E30C:: @ 826E30C
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_26E311:: @ 826E311
	setflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_26E316:: @ 826E316
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_26E31B:: @ 826E31B
	playse SE_MU_PACHI
	waitse
	playse SE_TU_SAA
	initrotatingtilepuzzle TRUE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

Route110_TrickHousePuzzle7_EventScript_26E331:: @ 826E331
	playse SE_MU_PACHI
	waitse
	playse SE_TU_SAA
	initrotatingtilepuzzle TRUE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

Route110_TrickHousePuzzle7_EventScript_26E347:: @ 826E347
	playse SE_MU_PACHI
	waitse
	playse SE_TU_SAA
	initrotatingtilepuzzle TRUE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

Route110_TrickHousePuzzle7_EventScript_26E35D:: @ 826E35D
	playse SE_MU_PACHI
	waitse
	playse SE_TU_SAA
	initrotatingtilepuzzle TRUE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

Route110_TrickHousePuzzle7_EventScript_26E373:: @ 826E373
	playse SE_MU_PACHI
	waitse
	playse SE_TU_SAA
	initrotatingtilepuzzle TRUE
	moverotatingtileobjects 4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

Route110_TrickHousePuzzle7_EventScript_26E389:: @ 826E389
	trainerbattle_single TRAINER_JOSHUA, Route110_TrickHousePuzzle7_Text_26E481, Route110_TrickHousePuzzle7_Text_26E4C1
	msgbox Route110_TrickHousePuzzle7_Text_26E4F4, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle7_EventScript_26E3A0:: @ 826E3A0
	trainerbattle_single TRAINER_PATRICIA, Route110_TrickHousePuzzle7_Text_26E531, Route110_TrickHousePuzzle7_Text_26E564
	msgbox Route110_TrickHousePuzzle7_Text_26E57F, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle7_EventScript_26E3B7:: @ 826E3B7
	trainerbattle_single TRAINER_ALEXIS, Route110_TrickHousePuzzle7_Text_26E5C0, Route110_TrickHousePuzzle7_Text_26E604
	msgbox Route110_TrickHousePuzzle7_Text_26E61E, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle7_EventScript_26E3CE:: @ 826E3CE
	trainerbattle_single TRAINER_MARIELA, Route110_TrickHousePuzzle7_Text_26E66B, Route110_TrickHousePuzzle7_Text_26E69C
	msgbox Route110_TrickHousePuzzle7_Text_26E6BC, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle7_EventScript_26E3E5:: @ 826E3E5
	trainerbattle_single TRAINER_ALVARO, Route110_TrickHousePuzzle7_Text_26E6DA, Route110_TrickHousePuzzle7_Text_26E700
	msgbox Route110_TrickHousePuzzle7_Text_26E722, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle7_EventScript_26E3FC:: @ 826E3FC
	trainerbattle_single TRAINER_EVERETT, Route110_TrickHousePuzzle7_Text_26E78D, Route110_TrickHousePuzzle7_Text_26E7AB
	msgbox Route110_TrickHousePuzzle7_Text_26E7C4, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle7_EventScript_26E413:: @ 826E413
	.string "{PLAYER} écrit le code secret\n"
	.string "sur la porte.\p"
	.string "“Le MAITRE DES PIEGES est trognon!”\n"
	.string "… … … … … … … …\p"
	.string "La porte s'ouvre!$"

Route110_TrickHousePuzzle7_Text_26E481: @ 826E481
	.string "Le MAITRE DES PIEGES disparaît dans\n"
	.string "un nuage de fumée. Comment fait-il?$"

Route110_TrickHousePuzzle7_Text_26E4C1: @ 826E4C1
	.string "Aïeuuuuh! Tu es drôlement balèze!\n"
	.string "Comment fais-tu?$"

Route110_TrickHousePuzzle7_Text_26E4F4: @ 826E4F4
	.string "Moi aussi, j'aimerais pouvoir\n"
	.string "disparaître dans un nuage de fumée.$"

Route110_TrickHousePuzzle7_Text_26E531: @ 826E531
	.string "Tourner en rond sans arrêt…\n"
	.string "Ça porte malheur…$"

Route110_TrickHousePuzzle7_Text_26E564: @ 826E564
	.string "Une défaite!\n"
	.string "C'est un mauvais présage…$"

Route110_TrickHousePuzzle7_Text_26E57F: @ 826E57F
	.string "Ça fait dix fois que je reviens au même\n"
	.string "endroit. Ça va me porter malheur.$"

Route110_TrickHousePuzzle7_Text_26E5C0: @ 826E5C0
	.string "Le gagnant passera la porte le premier.\n"
	.string "Voilà ce que j'en dis.$"

Route110_TrickHousePuzzle7_Text_26E604: @ 826E604
	.string "Oh!\n"
	.string "Bon, allez, après toi!$"

Route110_TrickHousePuzzle7_Text_26E61E: @ 826E61E
	.string "Je pense que tu finiras par résoudre\n"
	.string "toutes les énigmes de la\l"
	.string "MAISON DES PIEGES.$"

Route110_TrickHousePuzzle7_Text_26E66B: @ 826E66B
	.string "Tiens, te voilà enfin, toi!\n"
	.string "Il n'y a plus de temps à perdre!$"

Route110_TrickHousePuzzle7_Text_26E69C: @ 826E69C
	.string "Un petit sourire, tu as gagné!$"

Route110_TrickHousePuzzle7_Text_26E6BC: @ 826E6BC
	.string "Je ne suis pas en colère.\n"
	.string "Je ne suis pas comme ça, moi!$"

Route110_TrickHousePuzzle7_Text_26E6DA: @ 826E6DA
	.string "Je dois dire que je te voyais venir!$"

Route110_TrickHousePuzzle7_Text_26E700: @ 826E700
	.string "Par contre, ça, je ne l'ai pas vu venir…$"

Route110_TrickHousePuzzle7_Text_26E722: @ 826E722
	.string "Oui, enfin ce n'est pas le meilleur\n"
	.string "endroit pour faire connaissance.\p"
	.string "On ne doit pas être très nets, tous\n"
	.string "les deux!$"

Route110_TrickHousePuzzle7_Text_26E78D: @ 826E78D
	.string "On est un peu à l'étroit ici…$"

Route110_TrickHousePuzzle7_Text_26E7AB: @ 826E7AB
	.string "Quelle force! Je m'incline.$"
	
Route110_TrickHousePuzzle7_Text_26E7C4: @ 826E7C4
	.string "Ce que j'aimerais être toi…$"
