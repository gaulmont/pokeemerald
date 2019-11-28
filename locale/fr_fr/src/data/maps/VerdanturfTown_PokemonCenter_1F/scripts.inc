VerdanturfTown_PokemonCenter_1F_MapScripts:: @ 8202726
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdanturfTown_PokemonCenter_1F_OnTransition: @ 8202731
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

VerdanturfTown_PokemonCenter_1F_EventScript_20273A:: @ 820273A
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_202748:: @ 8202748
	msgbox VerdanturfTown_PokemonCenter_1F_Text_20275A, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_202751:: @ 8202751
	msgbox VerdanturfTown_PokemonCenter_1F_Text_20280B, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_Text_20275A: @ 820275A
	.string "Tu n'es pas un vrai DRESSEUR\n"
	.string "si tu ne crois pas en tes POKéMON.\p"
	.string "Pour réussir, il faut avoir une entière\n"
	.string "confiance en ses POKéMON.$"

VerdanturfTown_PokemonCenter_1F_Text_20280B: @ 820280B
	.string "Si les gens viennent à VERGAZON…\p"
	.string "C'est pour la TENTE DE COMBAT, bien sûr\p"
	.string "Tiens, toi par exemple. Que viens-tu\n"
	.string "faire ici?$"

