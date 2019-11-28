EverGrandeCity_PokemonCenter_1F_MapScripts:: @ 8229A34
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

EverGrandeCity_PokemonCenter_1F_OnTransition: @ 8229A3F
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY_1
	call_if_unset FLAG_MET_SCOTT_IN_EVERGRANDE, EverGrandeCity_PokemonCenter_1F_EventScript_229A4C
	end

EverGrandeCity_PokemonCenter_1F_EventScript_229A4C:: @ 8229A4C
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
	return

EverGrandeCity_PokemonCenter_1F_EventScript_229A59:: @ 8229A59
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_229A67:: @ 8229A67
	msgbox EverGrandeCity_PokemonCenter_1F_Text_229ADA, MSGBOX_NPC
	end

EverGrandeCity_PokemonCenter_1F_EventScript_229A70:: @ 8229A70
	msgbox EverGrandeCity_PokemonCenter_1F_Text_229B62, MSGBOX_NPC
	end

EverGrandeCity_PokemonCenter_1F_EventScript_229A79:: @ 8229A79
	lock
	faceplayer
	msgbox EverGrandeCity_PokemonCenter_1F_Text_229BF1, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, DIR_NORTH
	call_if_eq EverGrandeCity_PokemonCenter_1F_EventScript_229AB6
	compare VAR_FACING, DIR_EAST
	call_if_eq EverGrandeCity_PokemonCenter_1F_EventScript_229AC1
	compare VAR_FACING, DIR_WEST
	call_if_eq EverGrandeCity_PokemonCenter_1F_EventScript_229AC1
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_EVERGRANDE
	playse SE_KAIDAN
	waitse
	removeobject 4
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_229AB6:: @ 8229AB6
	applymovement 4, EverGrandeCity_PokemonCenter_1F_Movement_229ACC
	waitmovement 0
	return

EverGrandeCity_PokemonCenter_1F_EventScript_229AC1:: @ 8229AC1
	applymovement 4, EverGrandeCity_PokemonCenter_1F_Movement_229AD3
	waitmovement 0
	return

EverGrandeCity_PokemonCenter_1F_Movement_229ACC: @ 8229ACC
	walk_left
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	step_end

EverGrandeCity_PokemonCenter_1F_Movement_229AD3: @ 8229AD3
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

EverGrandeCity_PokemonCenter_1F_Text_229ADA: @ 8229ADA
	.string "La LIGUE POKéMON se trouve juste\n"
	.string "un peu après la ROUTE VICTOIRE.\p"
	.string "Si tu as fait la route jusqu'ici,\n"
	.string "autant continuer!$"

EverGrandeCity_PokemonCenter_1F_Text_229B62: @ 8229B62
	.string "Longue et impitoyable ROUTE VICTOIRE…\p"
	.string "C'est comme refaire un trajet\n"
	.string "déjà parcouru…\p"
	.string "Crois en tes POKéMON et donne-leur\n"
	.string "tout ce que tu as!$"

EverGrandeCity_PokemonCenter_1F_Text_229BF1: @ 8229BF1
	.string "SCOTT: {PLAYER}{KUN}, tu as franchi les\n"
	.string "étapes qui mènent à la LIGUE POKéMON!\p"
	.string "Je suis heureux pour toi! Ça a valu le\n"
	.string "coup que je te soutienne!\p"
	.string "{PLAYER}{KUN}, si tu arrives à devenir le\n"
	.string "MAITRE de la LIGUE POKéMON…\p"
	.string "Je prendrai contact avec toi.\p"
	.string "OK, le chemin de la gloire est\n"
	.string "devant toi!$"

