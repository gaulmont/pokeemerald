PacifidlogTown_PokemonCenter_1F_MapScripts:: @ 82034A7
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PacifidlogTown_PokemonCenter_1F_OnTransition: @ 82034B2
	setrespawn HEAL_LOCATION_PACIFIDLOG_TOWN
	end

PacifidlogTown_PokemonCenter_1F_EventScript_2034B6:: @ 82034B6
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_2034C4:: @ 82034C4
	msgbox PacifidlogTown_PokemonCenter_1F_Text_2034DF, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_2034CD:: @ 82034CD
	msgbox PacifidlogTown_PokemonCenter_1F_Text_20350F, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_2034D6:: @ 82034D6
	msgbox PacifidlogTown_PokemonCenter_1F_Text_20356F, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_Text_2034DF: @ 82034DF
	.string "De quelle couleur est ta CARTE DE\n"
	.string "DRESSEUR? La mienne est cuivrée!$"

PacifidlogTown_PokemonCenter_1F_Text_20350F: @ 820350F
	.string "PACIFIVILLE flotte au-dessus\n"
	.string "d'une colonie de CORAYON.\p"
	.string "Ça semble incroyable, non?$"

PacifidlogTown_PokemonCenter_1F_Text_20356F: @ 820356F
	.string "On dit que les ancêtres des habitants\n"
	.string "de PACIFIVILLE sont nés sur\l"
	.string "des bateaux, pour y vivre et y mourir.\p"
	.string "Je crois qu'ils vivaient comme ça\n"
	.string "parce qu'ils cherchaient quelque\l"
	.string "chose.$"

