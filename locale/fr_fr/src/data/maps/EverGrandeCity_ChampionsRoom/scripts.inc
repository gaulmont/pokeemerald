EverGrandeCity_ChampionsRoom_MapScripts:: @ 82289EF
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition: @ 82289FF
	call Common_EventScript_SetupRivalGfxId
	end

EverGrandeCity_ChampionsRoom_OnWarp: @ 8228A05
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth:: @ 8228A0F
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame: @ 8228A14
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom:: @ 8228A1E
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkUp4
	waitmovement 0
	delay 40
	applymovement EVENT_OBJ_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
	waitmovement 0
	setvar VAR_TEMP_1, 1
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace
    releaseall
    end

EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace: @ 8228A42
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_Wallace:: @ 8228A45
	playbgm MUS_DAIGO, 0
	msgbox EverGrandeCity_ChampionsRoom_Text_PreBattleSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_Defeated:: @ 8228A61
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, 0
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, 0
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
	compare VAR_RESULT, FEMALE
	call_if_eq EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
	addobject 2
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	compare VAR_RESULT, FEMALE
	goto_if_eq EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	end

EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic:: @ 8228ABC
	playbgm MUS_GIRL_SUP, 0
	return

EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic:: @ 8228AC1
	playbgm MUS_BOY_SUP, 0
	return

EverGrandeCity_ChampionsRoom_EventScript_MayAdvice:: @ 8228AC6
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice:: @ 8228AFB
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF:: @ 8228B30
	closemessage
	addobject 3
	applymovement 3, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
	call ProfBirch_EventScript_RatePokedex
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
	applymovement 1, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 20
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement 1, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement EVENT_OBJ_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement 3, Common_Movement_WalkInPlaceFastestUp
	applymovement 2, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
	waitmovement 0
	delay 20
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	compare VAR_RESULT, FEMALE
	call_if_eq EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	closemessage
	applymovement 1, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement EVENT_OBJ_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 255, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations:: @ 8228BEB
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations:: @ 8228BF4
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer:: @ 8228BFD
	applymovement 2, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth:: @ 8228C12
	applymovement 2, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart: @ 8228C1D
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit: @ 8228C20
	walk_up
	delay_16
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer: @ 8228C26
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_fastest_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth: @ 8228C2F
	walk_in_place_fastest_up
	delay_16
	walk_in_place_fastest_right
	delay_16
	walk_in_place_fastest_up
	delay_8
	walk_in_place_fastest_right
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalFollows: @ 8228C38
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart: @ 8228C3B
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit: @ 8228C3F
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_BirchArrives: @ 8228C43
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_fastest_left
	step_end

EverGrandeCity_ChampionsRoom_Text_PreBattleSpeech: @ 8228C4C
	.string "MARC: Bienvenue, {PLAYER}{KUN}.\p"
	.string "A propos de l'incident d'ATALANOPOLIS…\n"
	.string "Réussir à mettre un terme à cette\l"
	.string "crise par tes propres moyens…\p"
	.string "Oups!\p"
	.string "Ça ne serait pas juste de dire que\n"
	.string "tout le mérite te revient.\p"
	.string "Tu as surmonté la situation grâce aux\n"
	.string "liens que tu as avec tes POKéMON.\p"
	.string "Nous, DRESSEURS, prenons soin de nos\n"
	.string "POKéMON en leur donnant des objets\l"
	.string "et en leur apprenant des capacités.\p"
	.string "Mais nous apprenons également\n"
	.string "énormément de nos POKéMON.\p"
	.string "Et c'est ici que tu peux tester le\n"
	.string "résultat de tous tes efforts, face à\l"
	.string "d'autres DRESSEURS et leurs POKéMON.\p"
	.string "Maintenant!\p"
	.string "Qui de nous deux va pouvoir se vanter\n"
	.string "d'avoir les meilleurs POKéMON d'HOENN?\p"
	.string "Nous allons le savoir tout de suite!$"

EverGrandeCity_ChampionsRoom_Text_Defeat: @ 8228EAC
	.string "Tu as réussi à me battre, moi, le\n"
	.string "MAITRE POKéMON…\p"
	.string "Beau travail.\n"
	.string "Tu as combattu de façon exaspérante,\l"
	.string "mais cependant glorieuse et élégante!\p"
	.string "Gloire à toi, {PLAYER}{KUN}!\p"
	.string "Tu es un DRESSEUR POKéMON\n"
	.string "de grande classe!$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech: @ 8228F66
	.string "MARC: Les POKéMON que tu as\n"
	.string "envoyés au combat…\p"
	.string "Par moments, ils dansaient comme\n"
	.string "une brise de printemps, à d'autres,\l"
	.string "ils frappaient comme l'éclair.\p"
	.string "Bien que de manière assurée, tu\n"
	.string "as su combattre élégamment!\p"
	.string "Même moi, je fus ébloui par tant\n"
	.string "de maestria!\p"
	.string "Tu te trouves désormais au\n"
	.string "sommet de la LIGUE POKéMON.\p"
	.string "Je te proclame maintenant le\n"
	.string "nouveau…$"

EverGrandeCity_ChampionsRoom_Text_MayAdvice: @ 82290CA
	.string "FLORA: {PLAYER}{KUN}!\p"
	.string "Voici un petit conseil avant que tu\n"
	.string "n'affrontes le MAITRE…$"

EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver: @ 822910B
	.string "FLORA: Hum? Quoi, quoi, quoi?\n"
	.string "What, what, what?\p"
	.string "{PLAYER}{KUN}…\n"
	.string "Il se pourrait que…\l"
	.string "C'est déjà fait?$"

EverGrandeCity_ChampionsRoom_Text_BrendanAdvice: @ 8229152
	.string "BRICE: {PLAYER}!\p"
	.string "Tu veux un conseil avant d'affronter\n"
	.string "le MAITRE…?$"

EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon: @ 82291A2
	.string "BRICE: {PLAYER}…\p"
	.string "Serais-tu en train de me dire…\n"
	.string "que tu as battu le MAITRE?$"

EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex: @ 82291E6
	.string "PROF. SEKO: Tu as vu?\n"
	.string "Qu'est-ce que je t'avais dit, {RIVAL}?\p"
	.string "Ne t'avais-je pas dit de ne pas te faire\n"
	.string "de soucis pour {PLAYER}{KUN}?\p"
	.string "… … … … … … … …\n"
	.string "{PLAYER}{KUN}, tu as enfin réussi!\p"
	.string "Quand j'ai su que tu avais battu ton\n"
	.string "propre père à l'ARENE de CLEMENTI,\l"
	.string "je me suis dit que tu avais une chance…\p"
	.string "Mais réaliser que tu es maintenant\n"
	.string "le MAITRE!\p"
	.string "Ah, oui!\p"
	.string "Qu'est-il advenu de ton POKéDEX?\n"
	.string "Laisse-moi voir.$"

EverGrandeCity_ChampionsRoom_Text_BirchCongratulations: @ 822934D
	.string "PROF. SEKO: Quoi qu'il en soit,\n"
	.string "félicitations!\p"
	.string "Entre fièrement dans l'ultime pièce!$"

EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe: @ 8229399
	.string "MARC: {PLAYER}{KUN}…\p"
	.string "Je vais donc terminer ma phrase.\p"
	.string "Le nouveau MAITRE!\p"
	.string "Suis-moi.$"

EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside: @ 82293EB
	.string "MARC: Je suis désolé, mais…\p"
	.string "A partir d'ici, seuls les DRESSEURS\n"
	.string "devenus MAITRES peuvent entrer.\p"
	.string "Tu vas devoir attendre à l'extérieur\n"
	.string "avec le PROFESSEUR.$"

EverGrandeCity_ChampionsRoom_Text_MayCongratulations: @ 8229479
	.string "FLORA: Mais… Mais…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Je plaisante! Pas de problème!\n"
	.string "C'est le règlement!\p"
	.string "{PLAYER}{KUN}!\n"
	.string "Sincères félicitations!$"

EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations: @ 82294F5
	.string "BRICE: … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Si c'est le règlement…\p"
	.string "{PLAYER}, c'est bien!\n"
	.string "Félicitations!$"

