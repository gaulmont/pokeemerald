Route128_MapScripts:: @ 81F6B38
	map_script MAP_SCRIPT_ON_TRANSITION, Route128_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route128_MapScript2_1F6B4D
	.byte 0

Route128_OnTransition: @ 81F6B43
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetWeather15
	end

Route128_MapScript2_1F6B4D: @ 81F6B4D
	map_script_2 VAR_ROUTE128_STATE, 1, Route128_EventScript_1F6B57
	.2byte 0

Route128_EventScript_1F6B57:: @ 81F6B57
	lockall
	delay 20
	applymovement 4, Route128_Movement_1F6C89
	waitmovement 0
	msgbox Route128_Text_1F6DF5, MSGBOX_DEFAULT
	closemessage
	applymovement 4, Route128_Movement_1F6C91
	waitmovement 0
	msgbox Route128_Text_1F6E48, MSGBOX_DEFAULT
	closemessage
	applymovement 5, Route128_Movement_1F6CAD
	waitmovement 0
	applymovement 4, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox Route128_Text_1F6E5A, MSGBOX_DEFAULT
	closemessage
	applymovement 5, Route128_Movement_1F6CBB
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox Route128_Text_1F6F1E, MSGBOX_DEFAULT
	closemessage
	applymovement 4, Route128_Movement_1F6C96
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	applymovement 5, Route128_Movement_1F6CA8
	waitmovement 0
	msgbox Route128_Text_1F704F, MSGBOX_DEFAULT
	closemessage
	delay 40
	applymovement 5, Route128_Movement_1F6CB0
	applymovement 4, Route128_Movement_1F6C9B
	waitmovement 0
	removeobject 5
	removeobject 4
	delay 100
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	waitfieldeffect FLDEFF_NPCFLY_OUT
	addobject 3
	applymovement 3, Route128_Movement_1F6C87
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox Route128_Text_1F70C9, MSGBOX_DEFAULT
	closemessage
	applymovement 3, Route128_Movement_1F6C85
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox Route128_Text_1F70EA, MSGBOX_DEFAULT
	applymovement 3, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox Route128_Text_1F721B, MSGBOX_DEFAULT
	closemessage
	applymovement 3, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject 3
	waitfieldeffect FLDEFF_NPCFLY_OUT
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_ROUTE128_STATE, 2
	releaseall
	end

Route128_Movement_1F6C76: @ 81F6C76
	walk_fast_left
	step_end

Route128_Movement_1F6C78: @ 81F6C78
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route128_Movement_1F6C85: @ 81F6C85
	walk_up
	step_end

Route128_Movement_1F6C87: @ 81F6C87
	walk_fast_left
	step_end

Route128_Movement_1F6C89: @ 81F6C89
	walk_fast_down
	walk_in_place_fastest_left
	delay_16
	walk_in_place_fastest_right
	delay_16
	delay_16
	walk_in_place_fastest_down
	step_end

Route128_Movement_1F6C91: @ 81F6C91
	lock_facing_direction
	walk_slow_up
	delay_16
	unlock_facing_direction
	step_end

Route128_Movement_1F6C96: @ 81F6C96
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_in_place_fastest_right
	step_end

Route128_Movement_1F6C9B: @ 81F6C9B
	delay_16
	delay_16
	walk_fast_up
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route128_Movement_1F6CA8: @ 81F6CA8
	walk_left
	walk_left
	delay_8
	delay_4
	step_end

Route128_Movement_1F6CAD: @ 81F6CAD
	walk_left
	walk_in_place_fastest_down
	step_end

Route128_Movement_1F6CB0: @ 81F6CB0
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route128_Movement_1F6CBB: @ 81F6CBB
	walk_right
	walk_in_place_fastest_down
	step_end

Route128_EventScript_1F6CBE:: @ 81F6CBE
	trainerbattle_single TRAINER_ISAIAH_1, Route128_Text_2A287F, Route128_Text_2A28AB, Route128_EventScript_1F6CEA
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route128_EventScript_1F6D09
	msgbox Route128_Text_2A28D7, MSGBOX_DEFAULT
	release
	end

Route128_EventScript_1F6CEA:: @ 81F6CEA
	special sub_80B4808
	waitmovement 0
	msgbox Route128_Text_2A2916, MSGBOX_DEFAULT
	register_matchcall TRAINER_ISAIAH_1
	release
	end

Route128_EventScript_1F6D09:: @ 81F6D09
	trainerbattle_rematch TRAINER_ISAIAH_1, Route128_Text_2A2975, Route128_Text_2A29B8
	msgbox Route128_Text_2A29DC, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_1F6D20:: @ 81F6D20
	trainerbattle_single TRAINER_KATELYN_1, Route128_Text_2A2A1F, Route128_Text_2A2A94, Route128_EventScript_1F6D4C
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route128_EventScript_1F6D6B
	msgbox Route128_Text_2A2AB7, MSGBOX_DEFAULT
	release
	end

Route128_EventScript_1F6D4C:: @ 81F6D4C
	special sub_80B4808
	waitmovement 0
	msgbox Route128_Text_2A2AF9, MSGBOX_DEFAULT
	register_matchcall TRAINER_KATELYN_1
	release
	end

Route128_EventScript_1F6D6B:: @ 81F6D6B
	trainerbattle_rematch TRAINER_KATELYN_1, Route128_Text_2A2B41, Route128_Text_2A2BAB
	msgbox Route128_Text_2A2BDD, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_1F6D82:: @ 81F6D82
	trainerbattle_single TRAINER_ALEXA, Route128_Text_2A2C1C, Route128_Text_2A2C79
	msgbox Route128_Text_2A2C95, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_1F6D99:: @ 81F6D99
	trainerbattle_single TRAINER_RUBEN, Route128_Text_2A2CD9, Route128_Text_2A2CFE
	msgbox Route128_Text_2A2D0D, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_1F6DB0:: @ 81F6DB0
	trainerbattle_single TRAINER_WAYNE, Route128_Text_2A2D3D, Route128_Text_2A2DA9
	msgbox Route128_Text_2A2DBA, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_1F6DC7:: @ 81F6DC7
	trainerbattle_single TRAINER_HARRISON, Route128_Text_2A2E0F, Route128_Text_2A2E44
	msgbox Route128_Text_2A2E6C, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_1F6DDE:: @ 81F6DDE
	trainerbattle_single TRAINER_CARLEE, Route128_Text_2A2EC8, Route128_Text_2A2EFA
	msgbox Route128_Text_2A2F2F, MSGBOX_AUTOCLOSE
	end

Route128_Text_1F6DF5: @ 81F6DF5
	.string "ARTHUR: Que s'est-il passé?\n"
	.string "Quel spectacle de désolation…\p"
	.string "Aurais-je… commis une terrible erreur?$"

Route128_Text_1F6E48: @ 81F6E48
	.string "Je…\n"
	.string "Je voulais juste…$"

Route128_Text_1F6E5A: @ 81F6E5A
	.string "MAX: Tu comprends maintenant,\n"
	.string "ARTHUR?\p"
	.string "Tu vois finalement comme ton rêve a\n"
	.string "tourné au cauchemar? Un vrai désastre!\p"
	.string "On doit faire vite! On doit agir\n"
	.string "avant que la situation ne devienne\l"
	.string "incontrôlable!$"

Route128_Text_1F6F1E: @ 81F6F1E
	.string "MAX: {PLAYER}, ne dis rien.\p"
	.string "Je sais que je n'ai pas le droit de\n"
	.string "critiquer ARTHUR…\p"
	.string "Mais vu la tournure des évènements,\n"
	.string "je doute que nous puissions faire\l"
	.string "quelque chose.\p"
	.string "Mais nous ne pouvons pas rester\n"
	.string "ici les bras croisés.\p"
	.string "ARTHUR et moi devons tout tenter\n"
	.string "pour mettre un terme à tout ceci…$"

Route128_Text_1F704F: @ 81F704F
	.string "MAX: Ça dépasse l'entendement…\p"
	.string "Ces POKéMON ancestraux…\p"
	.string "Leur pouvoir est incroyable.\n"
	.string "Ils ont perturbé l'équilibre même\l"
	.string "de la nature…$"

Route128_Text_1F70C9: @ 81F70C9
	.string "PIERRE: {PLAYER}{KUN}!\n"
	.string "Que se passe-t-il?$"

Route128_Text_1F70EA: @ 81F70EA
	.string "C'est terrible…\p"
	.string "Après la vague de chaleur, c'est\n"
	.string "maintenant un déluge que nous devons\l"
	.string "affronter.\p"
	.string "Si ça continue, tout HOENN…\n"
	.string "Non, le monde entier va sombrer.\p"
	.string "Cet énorme nuage s'étend depuis\n"
	.string "ATALANOPOLIS…\p"
	.string "Que peut-il bien se passer là-bas?\p"
	.string "Inutile d'épiloguer là-dessus ici…\n"
	.string "Les réponses sont à ATALANOPOLIS…$"

Route128_Text_1F721B: @ 81F721B
	.string "{PLAYER}{KUN}…\n"
	.string "Je ne sais pas ce que tu comptes faire,\l"
	.string "mais ne fais rien d'imprudent.\p"
	.string "OK.\n"
	.string "Je vais à ATALANOPOLIS.$"

