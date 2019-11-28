LilycoveCity_PokemonCenter_1F_MapScripts:: @ 821C5B2
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LilycoveCity_PokemonCenter_1F_OnTransition: @ 821C5BD
	setrespawn HEAL_LOCATION_LILYCOVE_CITY
	goto LilycoveCity_PokemonCenter_1F_EventScript_21C5C6
	end

LilycoveCity_PokemonCenter_1F_EventScript_21C5C6:: @ 821C5C6
	special SetLilycoveLadyGfx
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_21C5E0
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_21C5E4
	end

LilycoveCity_PokemonCenter_1F_EventScript_21C5E0:: @ 821C5E0
	setflag FLAG_HIDE_LILYCOVE_POKEMON_CENTER_LADY
	end

LilycoveCity_PokemonCenter_1F_EventScript_21C5E4:: @ 821C5E4
	clearflag FLAG_HIDE_LILYCOVE_POKEMON_CENTER_LADY
	end

LilycoveCity_PokemonCenter_1F_EventScript_21C5E8:: @ 821C5E8
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_21C5F6:: @ 821C5F6
	msgbox LilycoveCity_PokemonCenter_1F_Text_21C61E, MSGBOX_NPC
	end

LilycoveCity_PokemonCenter_1F_EventScript_21C5FF:: @ 821C5FF
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_PokemonCenter_1F_EventScript_21C614
	msgbox LilycoveCity_PokemonCenter_1F_Text_21C69D, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_21C614:: @ 821C614
	msgbox LilycoveCity_PokemonCenter_1F_Text_21C6F6, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_Text_21C61E: @ 821C61E
	.string "Je me demande combien de types de\n"
	.string "POKéMON il existe dans le monde.\p"
	.string "Ce serait super de traverser les océans\n"
	.string "et d'échanger des POKéMON très\l"
	.string "loin d'ici.$"

LilycoveCity_PokemonCenter_1F_Text_21C69D: @ 821C69D
	.string "J'ai entendu parler d'une bande de\n"
	.string "sales vauriens qui volent les POKéMON\l"
	.string "et qui piquent les METEORITES.$"

LilycoveCity_PokemonCenter_1F_Text_21C6F6: @ 821C6F6
	.string "Ces sales vauriens qui volent les\n"
	.string "POKéMON et piquent les METEORITES…\p"
	.string "Je ne les ai pas vus dans les parages.$"

