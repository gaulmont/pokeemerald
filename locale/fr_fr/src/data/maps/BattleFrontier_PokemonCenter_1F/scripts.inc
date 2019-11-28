BattleFrontier_PokemonCenter_1F_MapScripts:: @ 82678F9
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_PokemonCenter_1F_MapScript1_267904
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

BattleFrontier_PokemonCenter_1F_MapScript1_267904: @ 8267904
	setrespawn HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST
	end

BattleFrontier_PokemonCenter_1F_EventScript_267908:: @ 8267908
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_267916:: @ 8267916
	msgbox BattleFrontier_PokemonCenter_1F_Text_267944, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_26791F:: @ 826791F
	msgbox BattleFrontier_PokemonCenter_1F_Text_2679EB, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_267928:: @ 8267928
	msgbox BattleFrontier_PokemonCenter_1F_Text_267A4B, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_267931:: @ 8267931
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, 0
	msgbox BattleFrontier_PokemonCenter_1F_Text_267A90, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_PokemonCenter_1F_Text_267944: @ 8267944
	.string "J'ai vu quelqu'un utiliser un POKéMON\n"
	.string "que je ne connaissais pas!\p"
	.string "En tout cas, je n'en avais jamais\n"
	.string "entendu parler à l'ECOLE DE DRESSEURS.\p"
	.string "Je me demande bien où tu peux\n"
	.string "attraper ce genre de POKéMON.$"

BattleFrontier_PokemonCenter_1F_Text_2679EB: @ 82679EB
	.string "Bien! Prochain arrêt, le DOJO DE COMBAT!\n"
	.string "Je vais prendre des POKéMON du système\l"
	.string "de Gestion de Stocks de POKéMON.$"

BattleFrontier_PokemonCenter_1F_Text_267A4B: @ 8267A4B
	.string "Hi, hi, hi… Je vais relever tous\n"
	.string "les défis avec mon bébé!$"

BattleFrontier_PokemonCenter_1F_Text_267A90: @ 8267A90
	.string "SKITTY: Kiiiiity!$"

