MauvilleCity_PokemonCenter_2F_MapScripts:: @ 8211008
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
MauvilleCity_PokemonCenter_2F_EventScript_Colosseum:: @ 821101D
	call CableClub_EventScript_Colosseum
	end

MauvilleCity_PokemonCenter_2F_EventScript_TradeCenter:: @ 8211023
	call CableClub_EventScript_TradeCenter
	end

MauvilleCity_PokemonCenter_2F_EventScript_RecordCorner:: @ 8211029
	call CableClub_EventScript_RecordCorner
	end

MauvilleCity_PokemonCenter_2F_EventScript_Youngster:: @ 821102F
	msgbox MauvilleCity_PokemonCenter_2F_Text_Youngster, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_2F_Text_Youngster: @ 8211038
	.string "Tu savais que tu pouvais faire des\n"
	.string "combats en link au COLISEE?\p"
	.string "Ils affichent tes résultats au mur pour\n"
	.string "que tout le monde puisse les voir.\p"
	.string "C'est embêtant quand tu cumules plus\n"
	.string "de défaites que de victoires…$"

