LavaridgeTown_PokemonCenter_1F_MapScripts:: @ 81FFAFA
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LavaridgeTown_PokemonCenter_1F_OnTransition: @ 81FFB05
	setrespawn HEAL_LOCATION_LAVARIDGE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

LavaridgeTown_PokemonCenter_1F_EventScript_1FFB0E:: @ 81FFB0E
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_1FFB1C:: @ 81FFB1C
	msgbox LavaridgeTown_PokemonCenter_1F_Text_1FFBAD, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_1FFB25:: @ 81FFB25
	msgbox LavaridgeTown_PokemonCenter_1F_Text_1FFB37, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_1FFB2E:: @ 81FFB2E
	msgbox LavaridgeTown_PokemonCenter_1F_Text_1FFC21, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_Text_1FFB37: @ 81FFB37
	.string "Je crois que les POKéMON deviennent\n"
	.string "plus proches de leurs DRESSEURS s'ils\l"
	.string "passent du temps ensemble.\p"
	.string Plus ils passent de temps ensemble,\n"
	.string |plus ils sont proches. J'en suis sûre.$"

LavaridgeTown_PokemonCenter_1F_Text_1FFBAD: @ 81FFBAD
	.string "Les sources chaudes me font un bien\n"
	.string "fou.\p"
	.string "J'aimerais que mes POKéMON puissent\n"
	.string "en profiter aussi.$"

LavaridgeTown_PokemonCenter_1F_Text_1FFC21: @ 81FFC21
	.string "Ho ho! Hé, tu sais que tu peux accéder\n"
	.string "aux sources chaudes par ici?\p"
	.string "Puisque les POKéMON se reposent, les\n"
	.string "DRESSEURS devraient aussi se reposer.$"

