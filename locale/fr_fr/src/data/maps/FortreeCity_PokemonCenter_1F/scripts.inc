FortreeCity_PokemonCenter_1F_MapScripts:: @ 82173D8
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition: @ 82173E3
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_2173E7:: @ 82173E7
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_2173F5:: @ 82173F5
	msgbox FortreeCity_PokemonCenter_1F_Text_217410, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_2173FE:: @ 82173FE
	msgbox FortreeCity_PokemonCenter_1F_Text_21746D, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_217407:: @ 8217407
	msgbox FortreeCity_PokemonCenter_1F_Text_21751F, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_217410: @ 8217410
	.string "Ecoute, mon petit, est-ce que tu\n"
	.string "travailles sur un POKéDEX?\p"
	.string "Hum… Va au PARC SAFARI, sur la.\n"
	.string "ROUTE 121! C'est mon conseil.$"

FortreeCity_PokemonCenter_1F_Text_21746D: @ 821746D
	.string "Tu as déjà fait quelque chose au\n"
	.string "CENTRE DE DONNEES?\p"
	.string "C'est ingénieux. Ça permet d'échanger\n"
	.string "des données entre DRESSEURS.\p"
	.string "Je sais pas trop comment ça marche,\n"
	.string "mais c'est cool. C'est même génial!$"

FortreeCity_PokemonCenter_1F_Text_21751F: @ 821751F
	.string "Hé, tu as un POKéNAV!\n"
	.string "C'est le même que le mien!\p"
	.string "Tu connais la fonction MATCH PHONE?\p"
	.string "Utilise-la pour tchater avec les\n"
	.string "DRESSEURS que tu auras enregistrés.\p"
	.string "Cette option t'indique aussi les\n"
	.string "DRESSEURS souhaitant une revanche.\p"
	.string "C'est pas génial?\n"
	.string "Y a pas mieux que DEVON!$"

