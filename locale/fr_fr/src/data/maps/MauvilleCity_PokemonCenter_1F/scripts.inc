MauvilleCity_PokemonCenter_1F_MapScripts:: @ 8210E5B
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MauvilleCity_PokemonCenter_1F_OnTransition: @ 8210E66
	setrespawn HEAL_LOCATION_MAUVILLE_CITY
	call Common_EventScript_UpdateBrineyLocation
	goto MauvilleCity_PokemonCenter_1F_EventScript_210E74
	end

MauvilleCity_PokemonCenter_1F_EventScript_210E74:: @ 8210E74
	special ScrSpecial_SetMauvilleOldManEventObjGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_210E78:: @ 8210E78
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_210E86:: @ 8210E86
	msgbox MauvilleCity_PokemonCenter_1F_Text_210EA1, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_210E8F:: @ 8210E8F
	msgbox MauvilleCity_PokemonCenter_1F_Text_210F06, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_210E98:: @ 8210E98
	msgbox MauvilleCity_PokemonCenter_1F_Text_210F8A, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_Text_210EA1: @ 8210EA1
	.string "L'homme qui est là-bas dit des choses\n"
	.string "étranges.\p"
	.string "Il est marrant, mais bizarre aussi.\n"
	.string "Je ne suis pas près de l'oublier!$"

MauvilleCity_PokemonCenter_1F_Text_210F06: @ 8210F06
	.string "Quand j'ai échangé des données au\n"
	.string "CENTRE DE DONNEES, il y a eu une mise à\l"
	.string "jour de ce qui est à la mode à MYOKARA.\p"
	.string "Maintenant, j'ai les mêmes que mes amis!$"

MauvilleCity_PokemonCenter_1F_Text_210F8A: @ 8210F8A
	.string "Un CENTRE DE DONNEES a ouvert à l'étage\n"
	.string "du CENTRE POKéMON.\p"
	.string "Je ne sais pas de quoi il s'agit au juste,\n"
	.string "mais ça a l'air sympa. Je passerai voir!$"

