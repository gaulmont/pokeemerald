EverGrandeCity_SidneysRoom_MapScripts:: @ 8227F01
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_SidneysRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_SidneysRoom_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_SidneysRoom_OnFrame
	.byte 0

EverGrandeCity_SidneysRoom_OnTransition: @ 8227F16
	setflag FLAG_MET_SCOTT_IN_EVERGRANDE
	setflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
	end

EverGrandeCity_SidneysRoom_OnLoad: @ 8227F1D
	call_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_ResetAdvanceToNextRoom
	compare VAR_ELITE_4_STATE, 1
	call_if_eq EverGrandeCity_SidneysRoom_EventScript_CloseDoor
	end

EverGrandeCity_SidneysRoom_EventScript_ResetAdvanceToNextRoom:: @ 8227F32
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_SidneysRoom_EventScript_CloseDoor:: @ 8227F38
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_SidneysRoom_OnWarp: @ 8227F3E
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_SidneysRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_PlayerTurnNorth:: @ 8227F48
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_SidneysRoom_OnFrame: @ 8227F4D
	map_script_2 VAR_ELITE_4_STATE, 0, EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor:: @ 8227F57
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 1
	releaseall
	end

EverGrandeCity_SidneysRoom_EventScript_Sidney:: @ 8227F64
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeech
	playbgm MUS_SITENNOU, 0
	msgbox EverGrandeCity_SidneysRoom_Text_PreBattleSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SIDNEY, EverGrandeCity_SidneysRoom_Text_Defeat
	goto EverGrandeCity_SidneysRoom_EventScript_Defeated
	end

EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeech:: @ 8227F8B
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_SidneysRoom_EventScript_Defeated:: @ 8227F95
	setflag FLAG_DEFEATED_ELITE_4_SIDNEY
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_SidneysRoom_Text_PreBattleSpeech: @ 8227FA7
	.string "Bienvenue, adversaire!\n"
	.string "Je suis DAMIEN du CONSEIL des 4.\p"
	.string "J'aime la façon dont tu me regardes.\n"
	.string "Tu vas sûrement faire un bon combat.\l"
	.string "C'est bien! Vraiment bien!\p"
	.string "Bon! Toi et moi, livrons un combat\n"
	.string "comme on ne peut en voir qu'ici, à\l"
	.string "la LIGUE POKéMON!$"

EverGrandeCity_SidneysRoom_Text_Defeat: @ 82280A2
	.string "Alors, ça te fait plaisir? J'ai perdu!\n"
	.string "Tant pis, c'était sympa.$"

EverGrandeCity_SidneysRoom_Text_PostBattleSpeech: @ 82280EC
	.string "Bon, écoute ce que le perdant veut\n"
	.string "te dire.\p"
	.string "Tu as ce qu'il faut pour continuer.\n"
	.string "Alors va dans la prochaine pièce et\l"
	.string "bon combat!$"

