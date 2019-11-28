VictoryRoad_1F_MapScripts:: @ 8235D7A
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	.byte 0

VictoryRoad_1F_OnTransition: @ 8235D80
	compare VAR_VICTORY_ROAD_1F_STATE, 1
	call_if_eq VictoryRoad_1F_EventScript_235D97
	compare VAR_VICTORY_ROAD_1F_STATE, 2
	call_if_eq VictoryRoad_1F_EventScript_235DA3
	end

VictoryRoad_1F_EventScript_235D97:: @ 8235D97
	setobjectxyperm 4, 2, 24
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_235DA3:: @ 8235DA3
	setobjectxyperm 4, 3, 24
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_235DAF:: @ 8235DAF
	lockall
	setvar VAR_0x8008, 1
	addobject 4
	applymovement 4, VictoryRoad_1F_Movement_235E15
	waitmovement 0
	goto VictoryRoad_1F_EventScript_235DE1
	end

VictoryRoad_1F_EventScript_235DC8:: @ 8235DC8
	lockall
	setvar VAR_0x8008, 2
	addobject 4
	applymovement 4, VictoryRoad_1F_Movement_235E21
	waitmovement 0
	goto VictoryRoad_1F_EventScript_235DE1
	end

VictoryRoad_1F_EventScript_235DE1:: @ 8235DE1
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox VictoryRoad_1F_Text_235EE6, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_1, VictoryRoad_1F_Text_235FFC
	msgbox VictoryRoad_1F_Text_236020, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	copyobjectxytoperm 4
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
	releaseall
	end

VictoryRoad_1F_Movement_235E15: @ 8235E15
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

VictoryRoad_1F_Movement_235E21: @ 8235E21
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

VictoryRoad_1F_EventScript_235E2C:: @ 8235E2C
	msgbox VictoryRoad_1F_Text_236020, MSGBOX_NPC
	end

VictoryRoad_1F_EventScript_235E35:: @ 8235E35
	trainerbattle_single TRAINER_WALLY_3, VictoryRoad_1F_Text_236073, VictoryRoad_1F_Text_2360DA
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq VictoryRoad_1F_EventScript_235E5C
	msgbox VictoryRoad_1F_Text_2360FE, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_235E5C:: @ 8235E5C
	trainerbattle_rematch TRAINER_WALLY_3, VictoryRoad_1F_Text_236073, VictoryRoad_1F_Text_2360DA
	msgbox VictoryRoad_1F_Text_2360FE, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_235E73:: @ 8235E73
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_236184, VictoryRoad_1F_Text_2361CB
	msgbox VictoryRoad_1F_Text_2361E5, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_235E8A:: @ 8235E8A
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_236248, VictoryRoad_1F_Text_236290
	msgbox VictoryRoad_1F_Text_2362A4, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_235EA1:: @ 8235EA1
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_2362EE, VictoryRoad_1F_Text_236336
	msgbox VictoryRoad_1F_Text_236356, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_235EB8:: @ 8235EB8
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_236390, VictoryRoad_1F_Text_2363C4
	msgbox VictoryRoad_1F_Text_2363D5, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_235ECF:: @ 8235ECF
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_236468, VictoryRoad_1F_Text_2364A7
	msgbox VictoryRoad_1F_Text_2364BB, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_Text_235EE6: @ 8235EE6
	.string "TIMMY: Salut, {PLAYER}!\p"
	.string "J'parie que ça t'surprend de m'voir ici!\p"
	.string "J'ai fait le chemin jusqu'ici, et c'est\n"
	.string "grâce à toi!\p"
	.string "{PLAYER}, le fait de perdre contre toi\n"
	.string "l'autre fois m'a rendu plus fort!\p"
	.string "Mais je ne perdrai plus maintenant!\p"
	.string "Je vais gagner! Pour les POKéMON qui\n"
	.string "m'ont donné courage et force!\p"
	.string "OK… Me voilà!$"

VictoryRoad_1F_Text_235FFC: @ 8235FFC
	.string "Waouh!\n"
	.string "{PLAYER}, quelle force tu as quand même!$"

VictoryRoad_1F_Text_236020: @ 8236020
	.string "TIMMY: Je n'ai pas réussi à te battre\n"
	.string "aujourd'hui {PLAYER}, mais un de ces\l"
	.string "jours, je t'aurai!$"

VictoryRoad_1F_Text_236073: @ 8236073
	.string "TIMMY: Salut, {PLAYER}!\p"
	.string "Je suis devenu plus fort!\n"
	.string "Il faut que j'te montre, {PLAYER}!\p"
	.string "OK… J'arrive!$"

VictoryRoad_1F_Text_2360DA: @ 82360DA
	.string "Waouh!\n"
	.string "{PLAYER}, quelle force tu as quand même!$"

VictoryRoad_1F_Text_2360FE: @ 82360FE
	.string "TIMMY: Je n'ai pas réussi à te battre\n"
	.string "aujourd'hui, {PLAYER}, mais un de ces\l"
	.string "jours, je t'aurai…\p"
	.string "Et j'affronterai la LIGUE POKéMON!$"

VictoryRoad_1F_Text_236184: @ 8236184
	.string "J'ai fait ça plus d'une fois, mais la\n"
	.string "dernière partie est tellement longue…$"

VictoryRoad_1F_Text_2361CB: @ 82361CB
	.string "Mon rêve s'arrête là, encore une fois…$"

VictoryRoad_1F_Text_2361E5: @ 82361E5
	.string "T'as fait un bon bout d'chemin. Continue\n"
	.string "sur ta lancée et deviens le MAITRE!\l"
	.string "S'il y en a un qui peut réussir,\l"
	.string "c'est bien toi.$"

VictoryRoad_1F_Text_236248: @ 8236248
	.string "Je n'ai pas fait toute cette route pour\n"
	.string "perdre. Pas question!$"

VictoryRoad_1F_Text_236290: @ 8236290
	.string "Impossible…\n"
	.string "J'ai perdu?$"

VictoryRoad_1F_Text_2362A4: @ 82362A4
	.string "J'ai perdu à ce niveau…\p"
	.string "Je n'ai donc pas les qualifications\n"
	.string "requises pour être le MAITRE…$"

VictoryRoad_1F_Text_2362EE: @ 82362EE
	.string "Cette route difficile et sans fin\n"
	.string "porte bien son nom de VICTOIRE.$"

VictoryRoad_1F_Text_236336: @ 8236336
	.string "Ton style de combat est génial…$"

VictoryRoad_1F_Text_236356: @ 8236356
	.string "Tu sembles avoir le potentiel pour\n"
	.string "devenir le MAITRE.$"

VictoryRoad_1F_Text_236390: @ 8236390
	.string "Qu'est-ce que la ROUTE VICTOIRE?\n"
	.string "Je te le dirai quand tu gagneras!$"

VictoryRoad_1F_Text_2363C4: @ 82363C4
	.string "OK!\n"
	.string "Bien joué!$"

VictoryRoad_1F_Text_2363D5: @ 82363D5
	.string "Sortir d'ici sain et sauf, c'est\n"
	.string "le dernier test pour les DRESSEURS\l"
	.string "qui veulent devenir MAITRE POKéMON.\p"
	.string "C'est pour cela qu'on appelle ce lieu\n"
	.string "la ROUTE VICTOIRE.$"

VictoryRoad_1F_Text_236468: @ 8236468
	.string "Je n'ai rien à dire à quelqu'un qui est\n"
	.string "allé si loin. Viens te battre!$"

VictoryRoad_1F_Text_2364A7: @ 82364A7
	.string "Une vraie disgrâce…$"

VictoryRoad_1F_Text_2364BB: @ 82364BB
	.string "Humpf, continue tout droit.\n"
	.string "Si tu en as le courage.$"
