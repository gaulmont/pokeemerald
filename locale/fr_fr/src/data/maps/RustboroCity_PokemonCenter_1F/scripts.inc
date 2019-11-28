RustboroCity_PokemonCenter_1F_MapScripts:: @ 8214D62
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition: @ 8214D6D
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_214D76:: @ 8214D76
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_214D84:: @ 8214D84
	msgbox RustboroCity_PokemonCenter_1F_Text_214D9F, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_214D8D:: @ 8214D8D
	msgbox RustboroCity_PokemonCenter_1F_Text_214E13, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_214D96:: @ 8214D96
	msgbox RustboroCity_PokemonCenter_1F_Text_214E81, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_214D9F: @ 8214D9F
	.string "Mon POKéMON est NAIF et celui de mon\n"
	.string "ami est JOVIAL. C'est leur nature.\p"
	.string "C'est fascinant de voir comme les\n"
	.string "POKéMON ont leur caractère!$"

RustboroCity_PokemonCenter_1F_Text_214E13: @ 8214E13
	.string "Tout comme chez les hommes, il existe\n"
	.string "des POKéMON mâles et femelles.\p"
	.string "Mais la différence entre les deux sexes\n"
	.string "ne saute pas aux yeux.$"

RustboroCity_PokemonCenter_1F_Text_214E81: @ 8214E81
	.string "L'homme de la maison voisine m'a donné\n"
	.string "un CS!\p"
	.string "Je l'ai apprise à mon POKéMON pour\n"
	.string "qu'il COUPE les petits arbres.$"

