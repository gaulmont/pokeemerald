PetalburgCity_PokemonCenter_1F_MapScripts:: @ 82079E8
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition: @ 82079F3
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse:: @ 82079FC
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan:: @ 8207A0A
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster:: @ 8207A13
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman:: @ 8207A1C
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo:: @ 8207A38
	compare VAR_STARTER_MON, 0
	call_if_eq PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	compare VAR_STARTER_MON, 1
	call_if_eq PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	compare VAR_STARTER_MON, 2
	call_if_eq PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType:: @ 8207A5B
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType:: @ 8207A64
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType:: @ 8207A6D
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem: @ 8207A76
	.string "Ce système de stockage de POKéMON\n"
	.string "sur PC…\p"
	.string "Celui qui l'a inventé doit être\n"
	.string "une sorte de génie de la science!$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP: @ 8207AD6
	.string "Quand mon POKéMON mange une\n"
	.string "BAIE ORAN, il récupère des PV!$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon: @ 8207B09
	.string "Il existe de nombreux types de POKéMON.\p"
	.string "Chaque type a ses forces et ses\n"
	.string "faiblesses face aux autres types.\p"
	.string "Selon les types de POKéMON,\n"
	.string "le combat peut être facile ou difficile.$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType: @ 8207BB0
	.string "Par exemple, ton ARCKO est un\n"
	.string "POKéMON du type PLANTE.\p"
	.string "Il est fort contre les POKéMON\n"
	.string "des types EAU et SOL.\p"
	.string "Mais il est faible contre les POKéMON\n"
	.string "du type FEU.$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType: @ 8207C35
	.string "Par exemple, ton POUSSIFEU est un\n"
	.string "POKéMON du type FEU.\p"
	.string "Il est fort contre les POKéMON\n"
	.string "des types PLANTE et INSECTE.\p"
	.string "Mais il est faible contre les POKéMON\n"
	.string "du type EAU.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType: @ 8207CB7
	.string "Par exemple, ton GOBOU est un\n"
	.string "POKéMON du type EAU.\p"
	.string "Il est fort contre les POKéMON\n"
	.string "du type FEU.\p"
	.string "Mais il est faible contre les POKéMON\n"
	.string "des types PLANTE et ELECTRIK.$"

