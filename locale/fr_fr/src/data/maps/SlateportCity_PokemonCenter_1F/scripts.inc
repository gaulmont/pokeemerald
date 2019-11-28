SlateportCity_PokemonCenter_1F_MapScripts:: @ 820DABF
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SlateportCity_PokemonCenter_1F_OnTransition: @ 820DACA
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

SlateportCity_PokemonCenter_1F_EventScript_20DAD3:: @ 820DAD3
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SlateportCity_PokemonCenter_1F_EventScript_20DAE1:: @ 820DAE1
	msgbox SlateportCity_PokemonCenter_1F_Text_20DAF3, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_EventScript_20DAEA:: @ 820DAEA
	msgbox SlateportCity_PokemonCenter_1F_Text_20DBBC, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_Text_20DAF3: @ 820DAF3
	.string "Une petite astuce pour combattre?\p"
	.string "Il faut faire progresser divers types\n"
	.string "de POKéMON en même temps.\p"
	.string "Ce n'est pas bien d'avoir un seul\n"
	.string "POKéMON qui soit fort.\p"
	.string "S'il a un handicap à cause de son type,\n"
	.string "il n'aura aucune chance.$"

SlateportCity_PokemonCenter_1F_Text_20DBBC: @ 820DBBC
	.string "J'échange des POKéMON avec mes amis.\p"
	.string "Quand le POKéMON échangé porte\n"
	.string "un objet, je suis encore plus contente.$"