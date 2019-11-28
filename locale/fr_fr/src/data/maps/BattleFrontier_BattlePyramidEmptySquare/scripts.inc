BattleFrontier_BattlePyramidEmptySquare_MapScripts:: @ 8252A33
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidEmptySquare_MapScript1_252AA2
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidEmptySquare_MapScript2_252A43
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidEmptySquare_MapScript1_252BCA
	.byte 0

BattleFrontier_BattlePyramidEmptySquare_MapScript2_252A43: @ 8252A43
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidEmptySquare_EventScript_252A5D
	map_script_2 VAR_TEMP_E, 0, BattleFrontier_BattlePyramidEmptySquare_EventScript_252A98
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidEmptySquare_EventScript_252A8F
	.2byte 0

BattleFrontier_BattlePyramidEmptySquare_EventScript_252A5D:: @ 8252A5D
	lockall
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, 1
	setvar VAR_0x8007, 55
	setvar VAR_RESULT, 0

BattleFrontier_BattlePyramidEmptySquare_EventScript_252A77:: @ 8252A77
	special CallBattlePyramidFunction
	delay 2
	compare VAR_RESULT, 2
	goto_if_ne BattleFrontier_BattlePyramidEmptySquare_EventScript_252A77
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252A8F:: @ 8252A8F
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252A98:: @ 8252A98
	playbgm MUS_PYRAMID, 0
	setvar VAR_TEMP_E, 1
	end

BattleFrontier_BattlePyramidEmptySquare_MapScript1_252AA2: @ 8252AA2
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SET_FLOOR_PALETTE
	special CallBattlePyramidFunction
	setvar VAR_0x8004, 0
	special CallFrontierUtilFunc
	switch VAR_TEMP_0
	case 0, BattleFrontier_BattlePyramidEmptySquare_EventScript_252B8D
	case 1, BattleFrontier_BattlePyramidEmptySquare_EventScript_252B66
	case 2, BattleFrontier_BattlePyramidEmptySquare_EventScript_252B8D
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 5
	special CallFrontierUtilFunc
	compare VAR_RESULT, 4
	goto_if_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B39
	compare VAR_RESULT, 5
	goto_if_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B39
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B39
	compare VAR_RESULT, 2
	goto_if_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B42
	compare VAR_RESULT, 3
	goto_if_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B42
	compare VAR_RESULT, 9
	goto_if_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252B42
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 8
	special CallFrontierUtilFunc
	setvar VAR_TEMP_D, 1

BattleFrontier_BattlePyramidEmptySquare_EventScript_252B39:: @ 8252B39
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_RESTORE_PARTY
	special CallBattlePyramidFunction
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252B42:: @ 8252B42
BattleFrontier_BattlePyramidTop_EventScript_252B42:: @ 8252B42
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 4
	special CallFrontierUtilFunc
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SET_DATA
	setvar VAR_0x8005, 7
	setvar VAR_0x8006, 255
	special CallBattlePyramidFunction

BattleFrontier_BattlePyramidEmptySquare_EventScript_252B66:: @ 8252B66
BattleFrontier_BattlePyramidTop_EventScript_252B66:: @ 8252B66
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallBattlePyramidFunction
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_CLEAR_HELD_ITEMS
	special CallBattlePyramidFunction
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 255, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252B8D:: @ 8252B8D
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_3
	setvar VAR_0x8005, 1
	special CallBattlePyramidFunction
	special SavePlayerParty
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_INIT_TRAINERS
	special CallBattlePyramidFunction
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	special CallFrontierUtilFunc
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidEmptySquare_MapScript1_252BCA: @ 8252BCA
	call BattleFrontier_BattlePyramidEmptySquare_EventScript_252BD5
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252BD5:: @ 8252BD5
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 32
	setvar VAR_0x8006, 0
	special CallBattlePyramidFunction
	return

BattleFrontier_BattlePyramidEmptySquare_EventScript_252BE8:: @ 8252BE8
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_241EBA
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	special CallFrontierUtilFunc
	addvar VAR_RESULT, 1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	copyvar VAR_0x8006, VAR_RESULT
	special CallFrontierUtilFunc
	compare VAR_RESULT, 7
	goto_if_eq BattleFrontier_BattlePyramidEmptySquare_EventScript_252C45
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SEED_FLOOR
	special CallBattlePyramidFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_EMPTY_SQUARE, 255, 1, 1
	waitstate
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252C45:: @ 8252C45
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 255, 17, 17
	waitstate
	end

BattlePyramid_TrainerBattle:: @ 8252C4F
	trainerbattle TRAINER_BATTLE_PYRAMID, TRAINER_PHILLIP, 0, BattleFacility_TrainerBattle_PlaceholderText, BattleFacility_TrainerBattle_PlaceholderText
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SHOW_HINT_TEXT
	special CallBattlePyramidFunction
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall:: @ 8252C6A
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SET_ITEM
	special CallBattlePyramidFunction
	callstd STD_FIND_ITEM
	compare VAR_0x8007, 0
	goto_if_eq BattlePyramid_FindItemBall_End
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_HIDE_ITEM
	special CallBattlePyramidFunction

BattlePyramid_FindItemBall_End:: @ 8252C87
	end

BattleFrontier_BattlePyramidEmptySquare_EventScript_252C88:: @ 8252C88
	goto BattleFrontier_BattlePyramidTop_EventScript_252B42

BattleFacility_TrainerBattle_PlaceholderText: @ 8252C8D
	.string "C'est le message d'essai.$"

gText_BattlePyramidConfirmRest:: @ 8252CA7
	.string "Votre quête à la PYRAMIDE DE COMBAT\n"
	.string "sera sauvegardée pour que vous\l"
	.string "puissiez faire une pause. OK?$"

gText_BattlePyramidConfirmRetire:: @ 8252CFB
	.string "Voulez-vous vraiment abandonner votre\n"
	.string "quête à la PYRAMIDE?$"

BattlePyramid_ExitHintUp_Text1:: @ 8252D2D
	.string "Pour sortir de ce niveau, il faut aller\n"
	.string "dans cette direction: {UP_ARROW}.$"

BattlePyramid_ExitHintLeft_Text1:: @ 8252D57
	.string "Pour sortir de ce niveau, il faut aller\n"
	.string "dans cette direction: {LEFT_ARROW}.$"

BattlePyramid_ExitHintRight_Text1:: @ 8252D81
	.string "Pour sortir de ce niveau, il faut aller\n"
	.string "dans cette direction: {RIGHT_ARROW}.$"

BattlePyramid_ExitHintDown_Text1:: @ 8252DAB
	.string "Pour sortir de ce niveau, il faut aller\n"
	.string "dans cette direction: {DOWN_ARROW}.$"

BattlePyramid_ExitHintUp_Text2:: @ 8252DD5
	.string "La sortie de ce niveau se trouve\n"
	.string "dans cette direction: {UP_ARROW}.$"

BattlePyramid_ExitHintLeft_Text2:: @ 8252E03
	.string "La sortie de ce niveau se trouve\n"
	.string "dans cette direction: {LEFT_ARROW}.$"

BattlePyramid_ExitHintRight_Text2:: @ 8252E31
	.string "La sortie de ce niveau se trouve\n"
	.string "dans cette direction: {RIGHT_ARROW}.$"

BattlePyramid_ExitHintDown_Text2:: @ 8252E5F
	.string "La sortie de ce niveau se trouve\n"
	.string "dans cette direction: {DOWN_ARROW}.$"

BattlePyramid_ExitHintUp_Text3:: @ 8252E8D
	.string "Va dans la direction {UP_ARROW}\n"
	.string "pour sortir.$"

BattlePyramid_ExitHintLeft_Text3:: @ 8252EAA
	.string "Va dans la direction {LEFT_ARROW}\n"
	.string "pour sortir.$"

BattlePyramid_ExitHintRight_Text3:: @ 8252EC7
	.string "Va dans la direction {RIGHT_ARROW}\n"
	.string "pour sortir.$"

BattlePyramid_ExitHintDown_Text3:: @ 8252EE4
	.string "Va dans la direction {DOWN_ARROW}\n"
	.string "pour sortir.$"

BattlePyramid_ExitHintUp_Text4:: @ 8252F01
	.string "A ce niveau, la sortie se trouve\n"
	.string "par là: {UP_ARROW}.$"

BattlePyramid_ExitHintLeft_Text4:: @ 8252F3A
	.string "A ce niveau, la sortie se trouve\n"
	.string "par là: {LEFT_ARROW}.$"

BattlePyramid_ExitHintRight_Text4:: @ 8252F73
	.string "A ce niveau, la sortie se trouve\n"
	.string "par là: {RIGHT_ARROW}.$"

BattlePyramid_ExitHintDown_Text4:: @ 8252FAC
	.string "A ce niveau, la sortie se trouve\n"
	.string "par là: {DOWN_ARROW}.$"

BattlePyramid_ExitHintUp_Text5:: @ 8252FE5
	.string "La sortie?\n"
	.string "C'est par là, mon petit: {UP_ARROW}.$"

BattlePyramid_ExitHintLeft_Text5:: @ 8253000
	.string "La sortie?\n"
	.string "C'est par là, mon petit: {LEFT_ARROW}.$"

BattlePyramid_ExitHintRight_Text5:: @ 825301B
	.string "La sortie?\n"
	.string "C'est par là, mon petit: {RIGHT_ARROW}.$"

BattlePyramid_ExitHintDown_Text5:: @ 8253036
	.string "La sortie?\n"
	.string "C'est par là, mon petit: {DOWN_ARROW}.$"

BattlePyramid_ExitHintUp_Text6:: @ 8253051
	.string "Pour sortir de ce niveau, va dans\n"
	.string "cette direction: {UP_ARROW}.$"

BattlePyramid_ExitHintLeft_Text6:: @ 825307C
	.string "Pour sortir de ce niveau, va dans\n"
	.string "cette direction: {LEFT_ARROW}.$"

BattlePyramid_ExitHintRight_Text6:: @ 82530A7
	.string "Pour sortir de ce niveau, va dans\n"
	.string "cette direction: {RIGHT_ARROW}.$"

BattlePyramid_ExitHintDown_Text6:: @ 82530D2
	.string "Pour sortir de ce niveau, va dans\n"
	.string "cette direction: {DOWN_ARROW}.$"

BattlePyramid_EightItemsRemaining_Text1:: @ 82530FD
	.string "Tu cherches des objets?\p"
	.string "Il reste huit objets à trouver.$"

BattlePyramid_SevenItemsRemaining_Text1:: @ 8253140
	.string "Tu cherches des objets?\p"
	.string "Il reste sept objets à trouver.$"

BattlePyramid_SixItemsRemaining_Text1:: @ 8253183
	.string "Tu cherches des objets?\p"
	.string "Il reste six objets à trouver.$"

BattlePyramid_FiveItemsRemaining_Text1:: @ 82531C4
	.string "Tu cherches des objets?\p"
	.string "Il reste cinq objets à trouver.$"

BattlePyramid_FourItemsRemaining_Text1:: @ 8253206
	.string "Tu cherches des objets?\p"
	.string "Il reste quatre objets à trouver.$"

BattlePyramid_ThreeItemsRemaining_Text1:: @ 8253248
	.string "Tu cherches des objets?\p"
	.string "Il reste trois objets à trouver.$"

BattlePyramid_TwoItemsRemaining_Text1:: @ 825328B
	.string "Tu cherches des objets?\p"
	.string "Il reste deux objets à trouver.$"

BattlePyramid_OneItemRemaining_Text1:: @ 82532CC
	.string "Tu cherches des objets?\p"
	.string "Il reste un objet à trouver.$"

BattlePyramid_ZeroItemsRemaining_Text1:: @ 825330B
	.string "Tu cherches des objets?\p"
	.string "Il n'y a plus d'objets à trouver!$"

BattlePyramid_EightItemsRemaining_Text2:: @ 825334D
	.string "Tu as gagné, alors je vais te confier\n"
	.string "un petit secret!\p"
	.string "Il y a huit objets à trouver.$"

BattlePyramid_SevenItemsRemaining_Text2:: @ 82533A6
	.string "Tu as gagné, alors je vais te confier\n"
	.string "un petit secret!\p"
	.string "Il y a sept objets à trouver.$"

BattlePyramid_SixItemsRemaining_Text2:: @ 8253404
	.string "Tu as gagné, alors je vais te confier\n"
	.string "un petit secret!\p"
	.string "Il y a six objets à trouver.$"

BattlePyramid_FiveItemsRemaining_Text2:: @ 8253460
	.string "Tu as gagné, alors je vais te confier\n"
	.string "un petit secret!\p"
	.string "Il y a cinq objets à trouver.$"

BattlePyramid_FourItemsRemaining_Text2:: @ 82534BD
	.string "Tu as gagné, alors je vais te confier\n"
	.string "un petit secret!\p"
	.string "Il y a quatre objets à trouver.$"

BattlePyramid_ThreeItemsRemaining_Text2:: @ 825351A
	.string "Tu as gagné, alors je vais te confier\n"
	.string "un petit secret!\p"
	.string "Il y a trois objets à trouver.$"

BattlePyramid_TwoItemsRemaining_Text2:: @ 8253578
	.string "Tu as gagné, alors je vais te confier\n"
	.string "un petit secret!\p"
	.string "Il y a deux objets à trouver.$"

BattlePyramid_OneItemRemaining_Text2:: @ 82535D4
	.string "Tu as gagné, alors je vais te confier\n"
	.string "un petit secret!\p"
	.string "Il y a un objet à trouver.$"

BattlePyramid_ZeroItemsRemaining_Text2:: @ 825362E
	.string "Tu as gagné, alors je vais te confier\n"
	.string "un petit secret!\p"
	.string "Il n'y a plus d'objets à trouver.$"

BattlePyramid_EightItemsRemaining_Text3:: @ 825368B
	.string "Comment se porte ton stock d'objets?\p"
	.string "Je dirais qu'il reste huit objets à\n"
	.string "ramasser par terre.$"

BattlePyramid_SevenItemsRemaining_Text3:: @ 82536F8
	.string "Comment se porte ton stock d'objets?\p"
	.string "Je dirais qu'il reste sept objets à\n"
	.string "ramasser par terre.$"

BattlePyramid_SixItemsRemaining_Text3:: @ 8253765
	.string "Comment se porte ton stock d'objets?\p"
	.string "Je dirais qu'il reste six objets à\n"
	.string "ramasser par terre.$"

BattlePyramid_FiveItemsRemaining_Text3:: @ 82537D0
	.string "Comment se porte ton stock d'objets?\p"
	.string "Je dirais qu'il reste cinq objets à\n"
	.string "ramasser par terre.$"

BattlePyramid_FourItemsRemaining_Text3:: @ 825383C
	.string "Comment se porte ton stock d'objets?\p"
	.string "Je dirais qu'il reste quatre objets à\n"
	.string "ramasser par terre.$"

BattlePyramid_ThreeItemsRemaining_Text3:: @ 82538A8
	.string "Comment se porte ton stock d'objets?\p"
	.string "Je dirais qu'il reste trois objets à\n"
	.string "ramasser par terre.$"

BattlePyramid_TwoItemsRemaining_Text3:: @ 8253915
	.string "Comment se porte ton stock d'objets?\p"
	.string "Je dirais qu'il reste deux objets à\n"
	.string "ramasser par terre.$"

BattlePyramid_OneItemRemaining_Text3:: @ 8253980
	.string "Comment se porte ton stock d'objets?\p"
	.string "Je dirais qu'il reste un objet à\n"
	.string "ramasser par terre.$"

BattlePyramid_ZeroItemsRemaining_Text3:: @ 82539EC
	.string "Comment se porte ton stock d'objets?\p"
	.string "Je dirais qu'il ne reste plus d'objets à\n"
	.string "ramasser par terre.$"

BattlePyramid_EightItemsRemaining_Text4:: @ 8253A69
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu'il reste huit objets\n"
	.string "à ramasser.$"

BattlePyramid_SevenItemsRemaining_Text4:: @ 8253AC4
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu'il reste sept objets\n"
	.string "à ramasser.$"

BattlePyramid_SixItemsRemaining_Text4:: @ 8253B1F
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu'il reste six objets\n"
	.string "à ramasser.$"

BattlePyramid_FiveItemsRemaining_Text4:: @ 8253B78
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu'il reste cinq objets\n"
	.string "à ramasser.$"

BattlePyramid_FourItemsRemaining_Text4:: @ 8253BD2
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu'il reste quatre objets\n"
	.string "à ramasser.$"

BattlePyramid_ThreeItemsRemaining_Text4:: @ 8253C2C
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu'il reste trois objets\n"
	.string "à ramasser.$"

BattlePyramid_TwoItemsRemaining_Text4:: @ 8253C87
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu'il reste deux objets\n"
	.string "à ramasser.$"

BattlePyramid_OneItemRemaining_Text4:: @ 8253CE0
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu'il reste un objet\n"
	.string "à ramasser.$"

BattlePyramid_ZeroItemsRemaining_Text4:: @ 8253D3E
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu'il ne reste aucun objet\n"
	.string "à ramasser.$"

BattlePyramid_EightItemsRemaining_Text5:: @ 8253D96
	.string "A ce niveau de la PYRAMIDE,\n"
	.string "il y a huit objets à trouver…$"

BattlePyramid_SevenItemsRemaining_Text5:: @ 8253DD2
	.string "A ce niveau de la PYRAMIDE,\n"
	.string "il y a sept objets à trouver…$"

BattlePyramid_SixItemsRemaining_Text5:: @ 8253E0E
	.string "A ce niveau de la PYRAMIDE,\n"
	.string "il y a six objets à trouver…$"

BattlePyramid_FiveItemsRemaining_Text5:: @ 8253E48
	.string "A ce niveau de la PYRAMIDE,\n"
	.string "il y a cinq objets à trouver…$"

BattlePyramid_FourItemsRemaining_Text5:: @ 8253E83
	.string "A ce niveau de la PYRAMIDE,\n"
	.string "il y a quatre objets à trouver…$"

BattlePyramid_ThreeItemsRemaining_Text5:: @ 8253EBE
	.string "A ce niveau de la PYRAMIDE,\n"
	.string "il y a trois objets à trouver…$"

BattlePyramid_TwoItemsRemaining_Text5:: @ 8253EFA
	.string "A ce niveau de la PYRAMIDE,\n"
	.string "il y a deux objets à trouver…$"

BattlePyramid_OneItemRemaining_Text5:: @ 8253F34
	.string "A ce niveau de la PYRAMIDE,\n"
	.string "il y a un objet à trouver…$"

BattlePyramid_ZeroItemsRemaining_Text5:: @ 8253F6C
	.string "A ce niveau de la PYRAMIDE,\n"
	.string "il n'y a pas d'objets à trouver…$"

BattlePyramid_EightItemsRemaining_Text6:: @ 8253FA5
	.string "Est-ce que tu as trouvé des objets?\p"
	.string "Je pense qu'il en reste huit à ce\n"
	.string "niveau.$"

BattlePyramid_SevenItemsRemaining_Text6:: @ 8253FF7
	.string "Est-ce que tu as trouvé des objets?\p"
	.string "Je pense qu'il en reste sept à ce\n"
	.string "niveau.$"

BattlePyramid_SixItemsRemaining_Text6:: @ 8254049
	.string "Est-ce que tu as trouvé des objets?\p"
	.string "Je pense qu'il en reste six à ce\n"
	.string "niveau.$"

BattlePyramid_FiveItemsRemaining_Text6:: @ 8254099
	.string "Est-ce que tu as trouvé des objets?\p"
	.string "Je pense qu'il en reste cinq à ce\n"
	.string "niveau.$"

BattlePyramid_FourItemsRemaining_Text6:: @ 82540EA
	.string "Est-ce que tu as trouvé des objets?\p"
	.string "Je pense qu'il en reste quatre à ce\n"
	.string "niveau.$"

BattlePyramid_ThreeItemsRemaining_Text6:: @ 825413B
	.string "Est-ce que tu as trouvé des objets?\p"
	.string "Je pense qu'il en reste trois à ce\n"
	.string "niveau.$"

BattlePyramid_TwoItemsRemaining_Text6:: @ 825418D
	.string "Est-ce que tu as trouvé des objets?\p"
	.string "Je pense qu'il en reste deux à ce\n"
	.string "niveau.$"

BattlePyramid_OneItemRemaining_Text6:: @ 82541DD
	.string "Est-ce que tu as trouvé des objets?\p"
	.string "Je pense qu'il en reste un à ce\n"
	.string "niveau.$"

BattlePyramid_ZeroItemsRemaining_Text6:: @ 825422B
	.string "Est-ce que tu as trouvé des objets?\p"
	.string "Je pense qu'il n'en reste plus à ce\n"
	.string "niveau.$"

BattlePyramid_SevenTrainersRemaining_Text1:: @ 825427A
	.string "Tu as été formidable!\p"
	.string "Mais il y a encore sept DRESSEURS\n"
	.string "à battre!$"

BattlePyramid_SixTrainersRemaining_Text1:: @ 82542CB
	.string "Tu as été formidable!\p"
	.string "Mais il y a encore six DRESSEURS\n"
	.string "à battre!$"

BattlePyramid_FiveTrainersRemaining_Text1:: @ 825431A
	.string "Tu as été formidable!\p"
	.string "Mais il y a encore cinq DRESSEURS\n"
	.string "à battre!$"

BattlePyramid_FourTrainersRemaining_Text1:: @ 825436A
	.string "Tu as été formidable!\p"
	.string "Mais il y a encore quatre DRESSEURS\n"
	.string "à battre!$"

BattlePyramid_ThreeTrainersRemaining_Text1:: @ 82543BA
	.string "Tu as été formidable!\p"
	.string "Mais il y a encore trois DRESSEURS\n"
	.string "à battre!$"

BattlePyramid_TwoTrainersRemaining_Text1:: @ 825440B
	.string "Tu as été formidable!\p"
	.string "Mais il y a encore deux DRESSEURS\n"
	.string "à battre!$"

BattlePyramid_OneTrainersRemaining_Text1:: @ 825445A
	.string "Tu as été formidable!\p"
	.string "Mais il y a encore un DRESSEUR\n"
	.string "à battre!$"

BattlePyramid_ZeroTrainersRemaining_Text1:: @ 82544A6
	.string "Tu as été formidable!\p"
	.string "Il n'y a plus de DRESSEUR\n"
	.string "à battre!$"

BattlePyramid_SevenTrainersRemaining_Text2:: @ 82544E6
	.string "C'est rageant!\p"
	.string "Mais il y a sept autres DRESSEURS!\n"
	.string "Tu ne résisteras pas!$"

BattlePyramid_SixTrainersRemaining_Text2:: @ 8254538
	.string "C'est rageant!\p"
	.string "Mais il y a six autres DRESSEURS!\n"
	.string "Tu ne résisteras pas!$"

BattlePyramid_FiveTrainersRemaining_Text2:: @ 8254588
	.string "C'est rageant!\p"
	.string "Mais il y a cinq autres DRESSEURS!\n"
	.string "Tu ne résisteras pas!$"

BattlePyramid_FourTrainersRemaining_Text2:: @ 82545D9
	.string "C'est rageant!\p"
	.string "Mais il y a quatre autres DRESSEURS!\n"
	.string "Tu ne résisteras pas!$"

BattlePyramid_ThreeTrainersRemaining_Text2:: @ 825462A
	.string "C'est rageant!\p"
	.string "Mais il y a trois autres DRESSEURS!\n"
	.string "Tu ne résisteras pas!$"

BattlePyramid_TwoTrainersRemaining_Text2:: @ 825467C
	.string "C'est rageant!\p"
	.string "Mais il y a deux autres DRESSEURS!\n"
	.string "Tu ne résisteras pas!$"

BattlePyramid_OneTrainersRemaining_Text2:: @ 82546CC
	.string "C'est rageant!\p"
	.string "Mais il y a un autre DRESSEUR!\n"
	.string "Tu ne résisteras pas!$"

BattlePyramid_ZeroTrainersRemaining_Text2:: @ 825471E
	.string "C'est rageant!\p"
	.string "Il ne reste plus de DRESSEUR!$"

BattlePyramid_SevenTrainersRemaining_Text3:: @ 8254767
	.string "C'est impressionnant!\p"
	.string "Il reste sept DRESSEURS à ce niveau.\n"
	.string "Arriveras-tu à tous les battre?$"

BattlePyramid_SixTrainersRemaining_Text3:: @ 82547C9
	.string "C'est impressionnant!\p"
	.string "Il reste six DRESSEURS à ce niveau.\n"
	.string "Arriveras-tu à tous les battre?$"

BattlePyramid_FiveTrainersRemaining_Text3:: @ 8254829
	.string "C'est impressionnant!\p"
	.string "Il reste cinq DRESSEURS à ce niveau.\n"
	.string "Arriveras-tu à tous les battre?$"

BattlePyramid_FourTrainersRemaining_Text3:: @ 825488A
	.string "C'est impressionnant!\p"
	.string "Il reste quatre DRESSEURS à ce niveau.\n"
	.string "Arriveras-tu à tous les battre?$"

BattlePyramid_ThreeTrainersRemaining_Text3:: @ 82548EB
	.string "C'est impressionnant!\p"
	.string "Il reste trois DRESSEURS à ce niveau.\n"
	.string "Arriveras-tu à tous les battre?$"

BattlePyramid_TwoTrainersRemaining_Text3:: @ 825494D
	.string "C'est impressionnant!\p"
	.string "Il reste deux DRESSEURS à ce niveau.\n"
	.string "Arriveras-tu à tous les battre?$"

BattlePyramid_OneTrainersRemaining_Text3:: @ 82549AE
	.string "C'est impressionnant!\p"
	.string "Il reste un DRESSEUR à ce niveau.\n"
	.string "Arriveras-tu à le battre?$"

BattlePyramid_ZeroTrainersRemaining_Text3:: @ 8254A0B
	.string "C'est impressionnant!\p"
	.string "Il ne reste plus de DRESSEURS\n"
	.string "à ce niveau.$"

BattlePyramid_SevenTrainersRemaining_Text4:: @ 8254A59
	.string "Peut-être réussiras-tu à résister\n"
	.string "aux sept autres DRESSEURS du niveau.$"

BattlePyramid_SixTrainersRemaining_Text4:: @ 8254A9E
	.string "Peut-être réussiras-tu à résister\n"
	.string "aux six autres DRESSEURS du niveau.$"

BattlePyramid_FiveTrainersRemaining_Text4:: @ 8254AE1
	.string "Peut-être réussiras-tu à résister\n"
	.string "aux cinq autres DRESSEURS du niveau.$"

BattlePyramid_FourTrainersRemaining_Text4:: @ 8254B25
	.string "Peut-être réussiras-tu à résister aux\n"
	.string "quatre autres DRESSEURS du niveau.$"

BattlePyramid_ThreeTrainersRemaining_Text4:: @ 8254B69
	.string "Peut-être réussiras-tu à résister\n"
	.string "aux trois autres DRESSEURS du niveau.$"

BattlePyramid_TwoTrainersRemaining_Text4:: @ 8254BAE
	.string "Peut-être réussiras-tu à résister\n"
	.string "aux deux autres DRESSEURS du niveau.$"

BattlePyramid_OneTrainersRemaining_Text4:: @ 8254BF1
	.string "Peut-être réussiras-tu à résister\n"
	.string "au dernier DRESSEUR du niveau.$"

BattlePyramid_ZeroTrainersRemaining_Text4:: @ 8254C3E
	.string "Tu as résisté à tous les DRESSEURS\n"
	.string "du niveau. Il n'en reste aucun.$"

BattlePyramid_SevenTrainersRemaining_Text5:: @ 8254C77
	.string "Si ça se trouve, tu vas battre les\n"
	.string "sept autres DRESSEURS.$"

BattlePyramid_SixTrainersRemaining_Text5:: @ 8254CC0
	.string "Si ça se trouve, tu vas battre les\n"
	.string "six autres DRESSEURS.$"

BattlePyramid_FiveTrainersRemaining_Text5:: @ 8254D07
	.string "Si ça se trouve, tu vas battre les\n"
	.string "cinq autres DRESSEURS.$"

BattlePyramid_FourTrainersRemaining_Text5:: @ 8254D4F
	.string "Si ça se trouve, tu vas battre les\n"
	.string "quatre autres DRESSEURS.$"

BattlePyramid_ThreeTrainersRemaining_Text5:: @ 8254D97
	.string "Si ça se trouve, tu vas battre les\n"
	.string "trois autres DRESSEURS.$"

BattlePyramid_TwoTrainersRemaining_Text5:: @ 8254DE0
	.string "Si ça se trouve, tu vas battre les\n"
	.string "deux autres DRESSEURS.$"

BattlePyramid_OneTrainersRemaining_Text5:: @ 8254E27
	.string "Si ça se trouve, tu vas battre le\n"
	.string "dernier DRESSEUR.$"

BattlePyramid_ZeroTrainersRemaining_Text5:: @ 8254E6E
	.string "Tu te bats à la perfection.\p"
	.string "Il ne reste aucun DRESSEUR à\n"
	.string "battre.$"

BattlePyramid_SevenTrainersRemaining_Text6:: @ 8254ED3
	.string "Je me demande si tu vas battre\n"
	.string "les sept autres DRESSEURS!$"

BattlePyramid_SixTrainersRemaining_Text6:: @ 8254F0E
	.string "Je me demande si tu vas battre\n"
	.string "les six autres DRESSEURS!$"

BattlePyramid_FiveTrainersRemaining_Text6:: @ 8254F47
	.string "Je me demande si tu vas battre\n"
	.string "les cinq autres DRESSEURS!$"

BattlePyramid_FourTrainersRemaining_Text6:: @ 8254F81
	.string "Je me demande si tu vas battre\n"
	.string "les quatre autres DRESSEURS!$"

BattlePyramid_ThreeTrainersRemaining_Text6:: @ 8254FBB
	.string "Je me demande si tu vas battre\n"
	.string "les trois autres DRESSEURS!$"

BattlePyramid_TwoTrainersRemaining_Text6:: @ 8254FF6
	.string "Je me demande si tu vas battre\n"
	.string "les deux autres DRESSEURS!$"

BattlePyramid_OneTrainersRemaining_Text6:: @ 825502F
	.string "Je me demande si tu vas battre\n"
	.string "le dernier DRESSEUR!$"

BattlePyramid_ZeroTrainersRemaining_Text6:: @ 8255068
	.string "Il n'y a plus de DRESSEUR à\n"
	.string "battre ici…$"
