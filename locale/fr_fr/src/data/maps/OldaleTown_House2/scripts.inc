OldaleTown_House2_MapScripts:: @ 81FBF5A
	.byte 0

OldaleTown_House2_EventScript_Woman:: @ 81FBF5B
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man:: @ 81FBF64
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp: @ 81FBF6D
	.string "Lorsque les POKéMON se battent, ils\n"
	.string "gagnent de l'expérience et deviennent\l"
	.string "plus forts.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon: @ 81FBFB0
	.string "Si les POKéMON de ton équipe deviennent\n"
	.string "plus forts, tu pourras voyager plus\l"
	.string "loin.$"

