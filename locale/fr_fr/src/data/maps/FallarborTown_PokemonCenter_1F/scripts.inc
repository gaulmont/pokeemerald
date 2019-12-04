FallarborTown_PokemonCenter_1F_MapScripts:: @ 8200BCD
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FallarborTown_PokemonCenter_1F_OnTransition: @ 8200BD8
	setrespawn HEAL_LOCATION_FALLARBOR_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

FallarborTown_PokemonCenter_1F_EventScript_200BE1:: @ 8200BE1
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_200BEF:: @ 8200BEF
	msgbox FallarborTown_PokemonCenter_1F_Text_200E22, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_200BF8:: @ 8200BF8
	msgbox FallarborTown_PokemonCenter_1F_Text_200E8B, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_200C01:: @ 8200C01
	lock
	faceplayer
	msgbox FallarborTown_PokemonCenter_1F_Text_200C6B, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_NORTH, FallarborTown_PokemonCenter_1F_EventScript_200C28
	case DIR_WEST, FallarborTown_PokemonCenter_1F_EventScript_200C38
	end

FallarborTown_PokemonCenter_1F_EventScript_200C28:: @ 8200C28
	applymovement 4, FallarborTown_PokemonCenter_1F_Movement_200C53
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_200C48
	end

FallarborTown_PokemonCenter_1F_EventScript_200C38:: @ 8200C38
	applymovement 4, FallarborTown_PokemonCenter_1F_Movement_200C60
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_200C48
	end

FallarborTown_PokemonCenter_1F_EventScript_200C48:: @ 8200C48
	playse SE_JIDO_DOA
	removeobject 4
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	release
	end

FallarborTown_PokemonCenter_1F_Movement_200C53: @ 8200C53
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Movement_200C60: @ 8200C60
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Text_200C6B: @ 8200C6B
	.string "Oh, bonjour.\n"
	.string "Qui es-tu?\p"
	.string "D'accord, tu t'appelles {PLAYER}{KUN}.\n"
	.string "Tu es DRESSEUR, apparemment.\p"
	.string "Cela veut donc dire que tu utilises ce\n"
	.string "programme de Gestion de Stocks de\n"
	.string "POKéMON que j'ai développé.\p"
	.string "Enfin, c'est une conclusion que je tire\n"
	.string "d'un processus de déduction simple.\p"
	.string "Tu me parles parce que tu veux\n"
	.string "accéder à quelque chose sur ce PC.\p"
	.string "Oh, pardon, je ne me suis pas présentée.\n"
	.string "Je m'appelle ANNETTE.\p"
	.string "Enchantée. Je suis contente que tu\n"
	.string "utilises la Gestion de Stocks.\p"
	.string "Si tu en as l'occasion, viens me rendre.\n"
	.string "visite. J'habite sur la ROUTE 114.$"

FallarborTown_PokemonCenter_1F_Text_200E22: @ 8200E22
	.string "Je me demande à quoi ressemblaient les\n"
	.string "POKéMON durant la préhistoire.\p"
	.string "Le MANIAQUE DES FOSSILES qui vit\n"
	.string "en bordure de la ville doit le savoir.$"

FallarborTown_PokemonCenter_1F_Text_200E8B: @ 8200E8B
	.string "Dans les champs d'AUTEQUIA,\n"
	.string "nous mettons de jeunes plants en\l"
	.string "terre. Ce sont des arbres très vivaces\l"
	.string "qui poussent dans la cendre volcanique.$"

