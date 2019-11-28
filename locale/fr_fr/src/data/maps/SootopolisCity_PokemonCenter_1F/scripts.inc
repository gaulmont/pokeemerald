SootopolisCity_PokemonCenter_1F_MapScripts:: @ 82264F1
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SootopolisCity_PokemonCenter_1F_OnTransition: @ 82264FC
	setrespawn HEAL_LOCATION_SOOTOPOLIS_CITY
	end

SootopolisCity_PokemonCenter_1F_EventScript_226500:: @ 8226500
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_22650E:: @ 822650E
	lock
	faceplayer
	compare VAR_SKY_PILLAR_STATE, 2
	goto_if_ge SootopolisCity_PokemonCenter_1F_EventScript_22652E
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_22652E
	msgbox SootopolisCity_PokemonCenter_1F_Text_22664B, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_22652E:: @ 822652E
	msgbox SootopolisCity_PokemonCenter_1F_Text_226562, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_226538:: @ 8226538
	lock
	faceplayer
	compare VAR_SKY_PILLAR_STATE, 2
	goto_if_ge SootopolisCity_PokemonCenter_1F_EventScript_226558
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_226558
	msgbox SootopolisCity_PokemonCenter_1F_Text_22672F, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_226558:: @ 8226558
	msgbox SootopolisCity_PokemonCenter_1F_Text_2266B9, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_Text_226562: @ 8226562
	.string "On raconte que MARC est le DRESSEUR\n"
	.string "le plus fort de tout HOENN.\p"
	.string "L'ARENE de cette ville est dirigée par\n"
	.string "celui qui lui a tout appris.\p"
	.string "Mais le CONSEIL 4…\p"
	.string "On dit qu'ils sont encore plus forts\n"
	.string "que le mentor de MARC.\p"
	.string "Mais jusqu'à quel point?$"

SootopolisCity_PokemonCenter_1F_Text_22664B: @ 822664B
	.string "Tout le monde en ville s'est réfugié\n"
	.string "chez soi et personne ne veut sortir.\p"
	.string "Même moi je ferais bien de ne pas\n"
	.string "m'aventurer dehors.$"

SootopolisCity_PokemonCenter_1F_Text_2266B9: @ 82266B9
	.string "Peu importe ce qui se passera, où\n"
	.string "et quand ça se passera, je resterai\l"
	.string "toujours amie avec les POKéMON.\p"
	.string "Car c'est cool d'être avec les POKéMON!$"

SootopolisCity_PokemonCenter_1F_Text_22672F: @ 822672F
	.string "Je ne sais pas pourquoi…\p"
	.string "mais… j'ai vraiment peur… $"

