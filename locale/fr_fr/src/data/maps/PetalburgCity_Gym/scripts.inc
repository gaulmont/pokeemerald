PetalburgCity_Gym_MapScripts:: @ 8204889
	map_script MAP_SCRIPT_ON_LOAD, PetalburgCity_Gym_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_Gym_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_Gym_OnFrame
	.byte 0

PetalburgCity_Gym_OnLoad: @ 820489E
	compare VAR_PETALBURG_GYM_STATE, 6
	goto_if_eq PetalburgCity_Gym_EventScript_OpenUnlockedDoors
	compare VAR_PETALBURG_GYM_STATE, 7
	call_if_ge PetalburgCity_Gym_EventScript_UnlockAllDoors
	end

@ NOTE: Strength and OHKO rooms are misleading. Both are more accurately Critical-Hit
PetalburgCity_Gym_EventScript_OpenUnlockedDoors:: @ 82048B5
	setvar VAR_0x8005, 1
	call PetalburgCity_Gym_EventScript_OpenGymEntranceDoors
	checktrainerflag TRAINER_RANDALL
	call_if_eq PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
	checktrainerflag TRAINER_MARY
	call_if_eq PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
	checktrainerflag TRAINER_PARKER
	call_if_eq PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
	checktrainerflag TRAINER_ALEXIA
	call_if_eq PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
	checktrainerflag TRAINER_GEORGE
	call_if_eq PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
	checktrainerflag TRAINER_JODY
	call_if_eq PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
	checktrainerflag TRAINER_BERKE
	call_if_eq PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
	end

PetalburgCity_Gym_EventScript_UnlockAllDoors:: @ 82048FF
	setvar VAR_0x8005, 1
	call PetalburgCity_Gym_EventScript_OpenGymEntranceDoors
	call PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
	call PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
	call PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
	call PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
	call PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
	call PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
	call PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
	return

PetalburgCity_Gym_OnTransition: @ 820492D
	compare VAR_PETALBURG_GYM_STATE, 1
	call_if_eq PetalburgCity_Gym_EventScript_MoveWallyToEntrance
	compare VAR_PETALBURG_GYM_STATE, 6
	call_if_lt PetalburgCity_Gym_EventScript_MoveNormanToEntrance
	call_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_CheckNormanForRematch
	end

PetalburgCity_Gym_EventScript_MoveWallyToEntrance:: @ 820494D
	setobjectxyperm 10, 5, 108
	return

PetalburgCity_Gym_EventScript_MoveNormanToEntrance:: @ 8204955
	setobjectxyperm 1, 4, 107
	return

PetalburgCity_Gym_EventScript_CheckNormanForRematch:: @ 820495D
	setorcopyvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_NORMAN_1
	specialvar VAR_RESULT, IsTrainerReadyForRematch
	compare VAR_RESULT, TRUE
	goto_if_eq PetalburgCity_Gym_EventScript_DontMoveNormanToFront
	compare VAR_PETALBURG_GYM_STATE, 8
	goto_if_eq PetalburgCity_Gym_EventScript_DontMoveNormanToFront
	setobjectxyperm 1, 4, 107
	return

PetalburgCity_Gym_EventScript_DontMoveNormanToFront:: @ 8204985
	setvar VAR_PETALBURG_GYM_STATE, 8
	end

PetalburgCity_Gym_OnWarp: @ 820498B
	map_script_2 VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_TurnPlayerNorth
	.2byte 0

PetalburgCity_Gym_EventScript_TurnPlayerNorth:: @ 8204995
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

PetalburgCity_Gym_OnFrame: @ 820499A
	map_script_2 VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial
	.2byte 0

PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial:: @ 82049A4
	lockall
	msgbox PetalburgCity_Gym_Text_DadSoDidItWorkOut, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyThankYouBye, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	applymovement 10, PetalburgCity_Gym_Movement_WallyExitGym
	waitmovement 0
	playse SE_KAIDAN
	removeobject 10
	setflag FLAG_HIDE_PETALBURG_CITY_WALLY
	delay 30
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox PetalburgCity_Gym_Text_DadGoCollectBadges, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_GYM_STATE, 2
	releaseall
	end

PetalburgCity_Gym_Movement_WallyExitGym: @ 82049EC
	walk_down
	walk_down
	walk_down
	delay_16
	step_end

PetalburgCity_Gym_EventScript_Norman:: @ 82049F1
	lock
	faceplayer
	switch VAR_PETALBURG_GYM_STATE
	case 2, PetalburgCity_Gym_EventScript_NormanNoBadges
	case 3, PetalburgCity_Gym_EventScript_NormanOneBadge
	case 4, PetalburgCity_Gym_EventScript_NormanTwoBadges
	case 5, PetalburgCity_Gym_EventScript_NormanThreeBadges
	case 6, PetalburgCity_Gym_EventScript_NormanBattle
	case 7, PetalburgCity_Gym_EventScript_NormanPostBattle
	case 8, PetalburgCity_Gym_EventScript_NormanRematch
	msgbox PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, PetalburgCity_Gym_EventScript_BeginWallyTutorialSouth
	case DIR_NORTH, PetalburgCity_Gym_EventScript_BeginWallyTutorialNorth
	case DIR_WEST, PetalburgCity_Gym_EventScript_BeginWallyTutorialWest
	case DIR_EAST, PetalburgCity_Gym_EventScript_BeginWallyTutorialEast
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorialSouth:: @ 8204A80
	setvar VAR_0x8008, 0
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorialNorth:: @ 8204A8B
	setvar VAR_0x8008, 1
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorialWest:: @ 8204A96
	setvar VAR_0x8008, 2
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorialEast:: @ 8204AA1
	setvar VAR_0x8008, 3
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorial:: @ 8204AAC
	addobject 10  @ Wally
	playse SE_DOOR
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_Gym_EventScript_WallyArriveSouth
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_WallyArriveNorth
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_WallyArriveWestEast
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_WallyArriveWestEast
	msgbox PetalburgCity_Gym_Text_WallyIdLikeAPokemon, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_DadOhYoureWallyRight, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_DadHmISee, MSGBOX_DEFAULT
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressPlayerWest
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressPlayerEast
	msgbox PetalburgCity_Gym_Text_DadPlayerGoWithWally, MSGBOX_DEFAULT
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressWallySouth
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressWallyNorth
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressWallyWest
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressWallyEast
	msgbox PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyOhWowThankYou, MSGBOX_DEFAULT
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_Gym_EventScript_NormanFaceDoorSouth
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_NormanFaceDoorNorth
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_NormanFaceDoorWest
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_NormanFaceDoorEast
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_Gym_EventScript_WallyFacePlayer
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_WallyFaceDown
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_WallyFacePlayer
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_WallyFacePlayer
	msgbox PetalburgCity_Gym_Text_WouldYouReallyComeWithMe, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DONT_TRANSITION_MUSIC
	playbgm MUS_TSURETEK, 0
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_Gym_EventScript_ExitGymWithWallySouth
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_ExitGymWithWallyWest
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_ExitGymWithWallyEast
	removeobject 10
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_AUNT
	setvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_PETALBURG_CITY_STATE, 2
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLY
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLY
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	special InitBirchState
	warp MAP_PETALBURG_CITY, 255, 15, 8
	waitstate
	release
	end

PetalburgCity_Gym_EventScript_WallyArriveSouth:: @ 8204C31
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	applymovement 10, PetalburgCity_Gym_Movement_WallyArrive
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyArriveNorth:: @ 8204C43
	applymovement 10, PetalburgCity_Gym_Movement_WallyArriveNorth
	waitmovement 0
	applymovement 1, Common_Movement_WalkInPlaceFastestRight
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyArriveWestEast:: @ 8204C5F
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	applymovement 10, PetalburgCity_Gym_Movement_WallyArrive
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallySouth:: @ 8204C78
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	applymovement 10, PetalburgCity_Gym_Movement_WallyExitSouthWest
	applymovement EVENT_OBJ_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallySouth
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth:: @ 8204C91
	applymovement 10, PetalburgCity_Gym_Movement_WallyExitNorth
	applymovement EVENT_OBJ_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallyWest:: @ 8204CA3
	applymovement 10, PetalburgCity_Gym_Movement_WallyExitSouthWest
	applymovement EVENT_OBJ_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyWest
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallyEast:: @ 8204CB5
	applymovement 10, PetalburgCity_Gym_Movement_WallyExitEast
	applymovement EVENT_OBJ_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyEast
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth:: @ 8204CC7
	applymovement 1, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth:: @ 8204CD2
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerWest:: @ 8204CE4
	applymovement 1, Common_Movement_WalkInPlaceFastestRight
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerEast:: @ 8204CF6
	applymovement 1, Common_Movement_WalkInPlaceFastestLeft
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallySouth:: @ 8204D08
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallyNorth:: @ 8204D13
	applymovement 1, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallyWest:: @ 8204D1E
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallyEast:: @ 8204D29
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyFacePlayer:: @ 8204D34
	applymovement 10, Common_Movement_FacePlayer
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyFaceDown:: @ 8204D3F
	applymovement 10, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanNoBadges:: @ 8204D4A
	msgbox PetalburgCity_Gym_Text_NormanGoToRustboro, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanOneBadge:: @ 8204D54
	msgbox PetalburgCity_Gym_Text_NormanGoToDewford, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanTwoBadges:: @ 8204D5E
	msgbox PetalburgCity_Gym_Text_YouHaveGottenStronger, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanThreeBadges:: @ 8204D68
	msgbox PetalburgCity_Gym_Text_YouHaveGottenStronger, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanFaceDoorSouth:: @ 8204D72
	return

@ For all other NormanFaceDoorX, Norman is already facing the door from NormanAddressWallyX
PetalburgCity_Gym_EventScript_NormanFaceDoorNorth:: @ 8204D73
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanFaceDoorWest:: @ 8204D7E
	return

PetalburgCity_Gym_EventScript_NormanFaceDoorEast:: @ 8204D7F
	return

PetalburgCity_Gym_EventScript_NormanPostBattle:: @ 8204D80
	call PetalburgCity_Gym_EventScript_ShouldGiveEnigmaBerry
	compare VAR_RESULT, TRUE
	goto_if_eq PetalburgCity_Gym_EventScript_GiveEnigmaBerry
	goto_if_unset FLAG_RECEIVED_TM42, PetalburgCity_Gym_EventScript_GiveFacade2
	goto_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_NoAmountOfTrainingIsEnough
	msgbox PetalburgCity_Gym_Text_DadGoingToKeepTraining, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_GiveFacade2:: @ 8204DAC
	call PetalburgCity_Gym_EventScript_GiveFacade
	release
	end

PetalburgCity_Gym_EventScript_NormanRematch:: @ 8204DB3
	trainerbattle_rematch_double TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanPreRematch, PetalburgCity_Gym_Text_NormanRematchDefeat, PetalburgCity_Gym_Text_NormanRematchNeedTwoMons
	msgbox PetalburgCity_Gym_Text_NormanPostRematch, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_ShouldGiveEnigmaBerry:: @ 8204DCE
	specialvar VAR_RESULT, IsEnigmaBerryValid
	compare VAR_RESULT, FALSE
	goto_if_eq PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	checkitem ITEM_ENIGMA_BERRY, 1
	compare VAR_RESULT, TRUE
	goto_if_eq PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	checkpcitem ITEM_ENIGMA_BERRY, 1
	compare VAR_RESULT, TRUE
	goto_if_eq PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	compare VAR_ENIGMA_BERRY_AVAILABLE, 0
	goto_if_eq PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	msgbox PetalburgCity_Gym_Text_GiveEnigmaBerry, MSGBOX_DEFAULT
	setvar VAR_RESULT, TRUE
	return

PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry:: @ 8204E17
	setvar VAR_RESULT, FALSE
	return

PetalburgCity_Gym_EventScript_GiveEnigmaBerry:: @ 8204E1D
	giveitem_std ITEM_ENIGMA_BERRY
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setvar VAR_ENIGMA_BERRY_AVAILABLE, 0
	release
	end

PetalburgCity_Gym_EventScript_NormanBattle:: @ 8204E3B
	msgbox PetalburgCity_Gym_Text_NormanPreBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanDefeat
	message PetalburgCity_Gym_Text_ReceivedBalanceBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_PETALBURG_GYM
	setvar VAR_PETALBURG_GYM_STATE, 7
	setflag FLAG_BADGE05_GET
	special ResetHealLocationFromDewford
	call EventScript_HideMrBriney
	setflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	clearflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setvar VAR_0x8008, 5
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN
	call PetalburgCity_Gym_EventScript_UnlockAllDoors
	special DrawWholeMapView
	call PetalburgCity_Gym_EventScript_GiveFacade
	delay 30
	msgbox PetalburgCity_Gym_Text_DadHappyAndSad, MSGBOX_DEFAULT
	closemessage
	delay 40
	playse SE_DOOR
	delay 10
	addobject 11  @ Wallys Uncle
	switch VAR_FACING
	case DIR_NORTH, PetalburgCity_Gym_EventScript_WallysUncleArrivesNorth
	case DIR_WEST, PetalburgCity_Gym_EventScript_WallysUncleArrivesWest
	case DIR_EAST, PetalburgCity_Gym_EventScript_WallysUncleArrivesEast
	end

PetalburgCity_Gym_EventScript_GiveFacade:: @ 8204ED2
	giveitem_std ITEM_TM42
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_BagIsFull
	setflag FLAG_RECEIVED_TM42
	msgbox PetalburgCity_Gym_Text_ExplainFacade, MSGBOX_DEFAULT
	return

PetalburgCity_Gym_EventScript_WallysUncleArrivesNorth:: @ 8204EF5
	setvar VAR_0x8008, 1
	goto PetalburgCity_Gym_EventScript_WallysUncleArrives

PetalburgCity_Gym_EventScript_WallysUncleArrivesEast:: @ 8204EFF
	setvar VAR_0x8008, 2
	goto PetalburgCity_Gym_EventScript_WallysUncleArrives

PetalburgCity_Gym_EventScript_WallysUncleArrivesWest:: @ 8204F09
	setvar VAR_0x8008, 3
	goto PetalburgCity_Gym_EventScript_WallysUncleArrives

PetalburgCity_Gym_EventScript_WallysUncleArrives:: @ 8204F13
	applymovement 11, PetalburgCity_Gym_Movement_WallysUncleEnterGym
	waitmovement 0
	playse SE_PIN
	applymovement 11, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 11, Common_Movement_Delay48
	waitmovement 0
	delay 10
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_WallysUncleApproachPlayerNorth
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_WallysUncleApproachPlayerEast
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_WallysUncleApproachPlayerWest
	msgbox PetalburgCity_Gym_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 20
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_WallysUncleFaceNormanNorth
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_WallysUncleFaceNormanEast
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_WallysUncleFaceNormanWest
	msgbox PetalburgCity_Gym_Text_LetMeBorrowPlayer, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DONT_TRANSITION_MUSIC
	playbgm MUS_TSURETEK, 0
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_ExitGymWithWallysUncleNorth
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_ExitGymWithWallysUncleEast
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_ExitGymWithWallysUncleWest
	removeobject 11
	setvar VAR_PETALBURG_CITY_STATE, 4
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLYS_UNCLE
	warp MAP_PETALBURG_CITY, 255, 15, 8
	waitstate
	release
	end

PetalburgCity_Gym_EventScript_WallysUncleFaceNormanNorth:: @ 8204FCC
	applymovement 11, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysUncleFaceNormanEast:: @ 8204FD7
	applymovement 11, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysUncleFaceNormanWest:: @ 8204FE2
	applymovement 11, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysUncleApproachPlayerNorth:: @ 8204FED
	applymovement 11, PetalburgCity_Gym_Movement_WallysUncleApproachPlayerNorth
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	applymovement 1, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysUncleApproachPlayerEast:: @ 8205009
	applymovement 11, PetalburgCity_Gym_Movement_WallysUncleApproachPlayerEast
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysUncleApproachPlayerWest:: @ 8205025
	applymovement 11, PetalburgCity_Gym_Movement_WallysUncleApproachPlayerWest
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallysUncleNorth:: @ 8205041
	applymovement 11, PetalburgCity_Gym_Movement_WallysUncleExitNorth
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	applymovement EVENT_OBJ_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysUncleNorth
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallysUncleEast:: @ 820505A
	applymovement 11, PetalburgCity_Gym_Movement_WallysUncleExitEast
	applymovement EVENT_OBJ_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysUncleEast
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallysUncleWest:: @ 820506C
	applymovement 11, PetalburgCity_Gym_Movement_WallysUncleExitWest
	applymovement EVENT_OBJ_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysUncleWest
	waitmovement 0
	return

PetalburgCity_Gym_Movement_WallysUncleExitNorth: @ 820507E
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_fastest_up
	delay_8
	walk_in_place_down
	set_invisible
	step_end

PetalburgCity_Gym_Movement_WallysUncleExitEast: @ 8205089
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_fastest_up
	delay_8
	walk_in_place_down
	set_invisible
	step_end

PetalburgCity_Gym_Movement_WallysUncleExitWest: @ 8205094
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_fastest_up
	delay_8
	walk_in_place_down
	set_invisible
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallysUncleNorth: @ 82050A1
	delay_16
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallysUncleEast: @ 82050A9
	delay_16
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallysUncleWest: @ 82050B1
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

PetalburgCity_Gym_Movement_WallysUncleEnterGym: @ 82050BB
	walk_up
	delay_8
	walk_in_place_fastest_right
	delay_8
	walk_in_place_fastest_left
	delay_16
	walk_in_place_fastest_up
	step_end

PetalburgCity_Gym_Movement_WallysUncleApproachPlayerNorth: @ 82050C3
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_right
	step_end

PetalburgCity_Gym_Movement_WallysUncleApproachPlayerEast: @ 82050CA
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

PetalburgCity_Gym_Movement_WallysUncleApproachPlayerWest: @ 82050D0
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	step_end

@ Unused
PetalburgCity_Gym_Movement_2050D8: @ 82050D8
	walk_in_place_fastest_up
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_fastest_down
	step_end

PetalburgCity_Gym_Movement_WallyArriveNorth: @ 82050E1
	delay_16
	walk_up
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_in_place_fastest_left
	step_end

PetalburgCity_Gym_Movement_WallyArrive: @ 82050EB
	delay_16
	walk_up
	delay_16
	delay_8
	walk_up
	walk_up
	step_end

PetalburgCity_Gym_Movement_WallyExitNorth: @ 82050F2
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_up
	delay_16
	walk_in_place_down
	step_end

PetalburgCity_Gym_Movement_WallyExitEast: @ 82050FA
	walk_down
	walk_down
	walk_right
	walk_down
	walk_in_place_fastest_up
	delay_16
	walk_in_place_down
	step_end

PetalburgCity_Gym_Movement_WallyExitSouthWest: @ 8205102
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_up
	delay_16
	walk_in_place_down
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth: @ 8205109
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallySouth: @ 8205111
	delay_16
	delay_16
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallyWest: @ 820511B
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallyEast: @ 8205123
	walk_in_place_fastest_down
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_EventScript_NoAmountOfTrainingIsEnough:: @ 820512D
	msgbox PetalburgCity_Gym_Text_DadNoAmountOfTrainingIsEnough, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_SpeedRoomDoor:: @ 8205137
	lockall
	compare VAR_PETALBURG_GYM_STATE, 6
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 85
	msgbox PetalburgCity_Gym_Text_EnterSpeedRoom, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_EnterRoom:: @ 820516C
	closemessage
	delay 30
	warpdoor MAP_PETALBURG_CITY_GYM, 255, VAR_0x8008, VAR_0x8009
	waitstate
	releaseall
	end

PetalburgCity_Gym_EventScript_DontEnterRoom:: @ 820517B
	releaseall
	end

PetalburgCity_Gym_EventScript_DoorLocked:: @ 820517D
	msgbox PetalburgCity_Gym_Text_DoorAppearsLocked, MSGBOX_DEFAULT
	releaseall
	end

@ VAR_0x8008 and VAR_0x8009 below are the x and y coordinates of the warp
PetalburgCity_Gym_EventScript_AccuracyRoomDoor:: @ 8205187
	lockall
	compare VAR_PETALBURG_GYM_STATE, 6
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 98
	msgbox PetalburgCity_Gym_Text_EnterAccuracyRoom, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_ConfusionRoomDoor:: @ 82051BC
	lockall
	checktrainerflag TRAINER_RANDALL
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 46
	msgbox PetalburgCity_Gym_Text_EnterConfusionRoom, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftDefenseRoomDoor:: @ 82051EF
	lockall
	checktrainerflag TRAINER_RANDALL
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 59
	msgbox PetalburgCity_Gym_Text_EnterDefenseRoom, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightDefenseRoomDoor:: @ 8205222
	lockall
	checktrainerflag TRAINER_MARY
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 59
	msgbox PetalburgCity_Gym_Text_EnterDefenseRoom, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RecoveryRoomDoor:: @ 8205255
	lockall
	checktrainerflag TRAINER_MARY
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 72
	msgbox PetalburgCity_Gym_Text_EnterRecoveryRoom, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftStrengthRoomDoor:: @ 8205288
	lockall
	checktrainerflag TRAINER_PARKER
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 20
	msgbox PetalburgCity_Gym_Text_EnterStrengthRoom, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightStrengthRoomDoor:: @ 82052BB
	lockall
	checktrainerflag TRAINER_ALEXIA
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 20
	msgbox PetalburgCity_Gym_Text_EnterStrengthRoom, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftOHKORoomDoor:: @ 82052EE
	lockall
	checktrainerflag TRAINER_ALEXIA
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 33
	msgbox PetalburgCity_Gym_Text_EnterOHKORoom, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightOHKORoomDoor:: @ 8205321
	lockall
	checktrainerflag TRAINER_GEORGE
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 33
	msgbox PetalburgCity_Gym_Text_EnterOHKORoom, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftGymLeadersRoomDoor:: @ 8205354
	lockall
	checktrainerflag TRAINER_JODY
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 7
	msgbox PetalburgCity_Gym_Text_EnterGymLeadersRoom, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightGymLeadersRoomDoor:: @ 8205387
	lockall
	checktrainerflag TRAINER_BERKE
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 7
	msgbox PetalburgCity_Gym_Text_EnterGymLeadersRoom, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_Randall:: @ 82053BA
	trainerbattle_single TRAINER_RANDALL, PetalburgCity_Gym_Text_RandallPreBattle, PetalburgCity_Gym_Text_RandallDefeat, PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_RandallPostBadge
	msgbox PetalburgCity_Gym_Text_RandallPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors:: @ 82053DE
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_RandallPostBadge:: @ 82053ED
	msgbox PetalburgCity_Gym_Text_RandallPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Parker:: @ 82053F6
	trainerbattle_single TRAINER_PARKER, PetalburgCity_Gym_Text_ParkerPreBattle, PetalburgCity_Gym_Text_ParkerDefeat, PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_ParkerPostBadge
	msgbox PetalburgCity_Gym_Text_ParkerPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors:: @ 820541A
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_ParkerPostBadge:: @ 8205429
	msgbox PetalburgCity_Gym_Text_ParkerPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_George:: @ 8205432
	trainerbattle_single TRAINER_GEORGE, PetalburgCity_Gym_Text_GeorgePreBattle, PetalburgCity_Gym_Text_GeorgeDefeat, PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GeorgePostBadge
	msgbox PetalburgCity_Gym_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors:: @ 8205456
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_GeorgePostBadge:: @ 8205465
	msgbox PetalburgCity_Gym_Text_GeorgePostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Berke:: @ 820546E
	trainerbattle_single TRAINER_BERKE, PetalburgCity_Gym_Text_BerkePreBattle, PetalburgCity_Gym_Text_BerkeDefeat, PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_BerkePostBadge
	msgbox PetalburgCity_Gym_Text_BerkePostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors:: @ 8205492
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_BerkePostBadge:: @ 82054A1
	msgbox PetalburgCity_Gym_Text_BerkePostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Mary:: @ 82054AA
	trainerbattle_single TRAINER_MARY, PetalburgCity_Gym_Text_MaryPreBattle, PetalburgCity_Gym_Text_MaryDefeat, PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_MaryPostBadge
	msgbox PetalburgCity_Gym_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors:: @ 82054CE
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_MaryPostBadge:: @ 82054DD
	msgbox PetalburgCity_Gym_Text_MaryPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Alexia:: @ 82054E6
	trainerbattle_single TRAINER_ALEXIA, PetalburgCity_Gym_Text_AlexiaPreBattle, PetalburgCity_Gym_Text_AlexiaDefeat, PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_AlexiaPostBadge
	msgbox PetalburgCity_Gym_Text_AlexiaPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors:: @ 820550A
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_AlexiaPostBadge:: @ 8205519
	msgbox PetalburgCity_Gym_Text_AlexiaPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Jody:: @ 8205522
	trainerbattle_single TRAINER_JODY, PetalburgCity_Gym_Text_JodyPreBattle, PetalburgCity_Gym_Text_JodyDefeat, PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_JodyPostBadge
	msgbox PetalburgCity_Gym_Text_JodyPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors:: @ 8205546
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_JodyPostBadge:: @ 8205555
	msgbox PetalburgCity_Gym_Text_JodyPostBadge, MSGBOX_NPC
	end

@ VAR_0x8004 below is the room number
@ VAR_0x8005 below is 0 when the door should be slid open and 1 when it should be unlocked immediately
PetalburgCity_Gym_EventScript_OpenGymEntranceDoors:: @ 820555E
	setvar VAR_0x8004, 1
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors:: @ 820557F
	setvar VAR_0x8004, 2
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors:: @ 82055A0
	setvar VAR_0x8004, 3
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors:: @ 82055C1
	setvar VAR_0x8004, 4
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors:: @ 82055E2
	setvar VAR_0x8004, 5
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors:: @ 8205603
	setvar VAR_0x8004, 6
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors:: @ 8205624
	setvar VAR_0x8004, 7
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenOHKORoomDoors:: @ 8205645
	setvar VAR_0x8004, 8
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles:: @ 8205666
	setmetatile 6, 85, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 7, 85, METATILE_PetalburgGym_RoomEntrance_Right, 0
	setmetatile 1, 98, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 2, 98, METATILE_PetalburgGym_RoomEntrance_Right, 0
	return

PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles:: @ 820568B
	setmetatile 6, 46, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 7, 46, METATILE_PetalburgGym_RoomEntrance_Right, 0
	setmetatile 1, 59, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 2, 59, METATILE_PetalburgGym_RoomEntrance_Right, 0
	return

PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles:: @ 82056B0
	setmetatile 6, 59, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 7, 59, METATILE_PetalburgGym_RoomEntrance_Right, 0
	setmetatile 1, 72, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 2, 72, METATILE_PetalburgGym_RoomEntrance_Right, 0
	return

PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles:: @ 82056D5
	setmetatile 1, 20, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 2, 20, METATILE_PetalburgGym_RoomEntrance_Right, 0
	return

PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles:: @ 82056E8
	setmetatile 6, 20, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 7, 20, METATILE_PetalburgGym_RoomEntrance_Right, 0
	setmetatile 1, 33, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 2, 33, METATILE_PetalburgGym_RoomEntrance_Right, 0
	return

PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles:: @ 820570D
	setmetatile 6, 33, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 7, 33, METATILE_PetalburgGym_RoomEntrance_Right, 0
	return

PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles:: @ 8205720
	setmetatile 1, 7, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 2, 7, METATILE_PetalburgGym_RoomEntrance_Right, 0
	return

PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles:: @ 8205733
	setmetatile 6, 7, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 7, 7, METATILE_PetalburgGym_RoomEntrance_Right, 0
	return

PetalburgCity_Gym_EventScript_SlideOpenRoomDoors:: @ 8205746
	special PetalburgGymSlideOpenRoomDoors
	waitstate
	return

PetalburgCity_Gym_EventScript_UnlockRoomDoors:: @ 820574B
	special PetalburgGymUnlockRoomDoors
	return

PetalburgCity_Gym_EventScript_GymGuide:: @ 820574F
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GymGuidePostVictory
	msgbox PetalburgCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_GymGuidePostVictory:: @ 8205764
	msgbox PetalburgCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_LeftGymStatue:: @ 820576E
	lockall
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymStatueCertified
	goto PetalburgCity_Gym_EventScript_GymStatue
	end

PetalburgCity_Gym_EventScript_RightGymStatue:: @ 820577E
	lockall
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymStatueCertified
	goto PetalburgCity_Gym_EventScript_GymStatue
	end

PetalburgCity_Gym_EventScript_GymStatueCertified:: @ 820578E
	msgbox PetalburgCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

PetalburgCity_Gym_EventScript_GymStatue:: @ 8205798
	msgbox PetalburgCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon: @ 82057A2
	.string "PAPA: Hum?\p"
	.string "Tiens, mais c'est toi {PLAYER}!\n"
	.string "Alors, le déménagement est fini?\p"
	.string "Je suis surpris de voir que tu as réussi\n"
	.string "à venir jusqu'ici par toi-même.\p"
	.string "Oh, je vois.\n"
	.string "Tu es avec tes POKéMON.\p"
	.string "Hum… Je suppose que tu vas aussi\n"
	.string "devenir DRESSEUR, {PLAYER}.\p"
	.string "C'est une très bonne nouvelle!\n"
	.string "J'attendais ça avec impatience!$"

PetalburgCity_Gym_Text_WallyIdLikeAPokemon: @ 82058B1
	.string "Oh… Je… j'aimerais avoir\n"
	.string "un POKéMON, s'il vous plaît…$"

PetalburgCity_Gym_Text_DadOhYoureWallyRight: @ 82058DB
	.string "PAPA: Hein? Tu es… Heu… Oh, mais oui,\n"
	.string "tu es TIMMY, n'est-ce pas?$"

PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon: @ 8205910
	.string "TIMMY: Je vais dans ma famille\n"
	.string "à VERGAZON.\p"
	.string "Comme je savais que j'allais être seul,\n"
	.string "j'voulais attraper un POKéMON en route.\p"
	.string "Mais je n'ai pas réussi.\n"
	.string "Je ne sais pas comment faire…$"

PetalburgCity_Gym_Text_DadHmISee: @ 82059D8
	.string "PAPA: Hum, je vois.$"

PetalburgCity_Gym_Text_DadPlayerGoWithWally: @ 82059E8
	.string "PAPA: {PLAYER}, tu as entendu?\p"
	.string "Va avec TIMMY et assure-toi\n"
	.string "qu'il attrape un POKéMON sans risque.$"

PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon: @ 8205A46
	.string "Tiens, TIMMY! Je te prête mon POKéMON.\p"
	.string "TIMMY reçoit un ZIGZATON!$"

PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall: @ 8205A89
	.string "TIMMY: Oh, waouh!\n"
	.string "Un POKéMON!\p"
	.string "PAPA: Hum. Je vais aussi te donner\n"
	.string "une POKé BALL. Allez, file!\p"
	.string "TIMMY reçoit une POKé BALL!$"

PetalburgCity_Gym_Text_WallyOhWowThankYou: @ 8205AF4
	.string "TIMMY: Oh, waouh!\n"
	.string "Merci!$"

PetalburgCity_Gym_Text_WouldYouReallyComeWithMe: @ 8205B0F
	.string "{PLAYER}… Tu veux bien venir\n"
	.string "avec moi? Vraiment?$"

PetalburgCity_Gym_Text_DadSoDidItWorkOut: @ 8205B32
	.string "PAPA: Alors, ça a marché?$"

PetalburgCity_Gym_Text_WallyThankYouBye: @ 8205B4C
	.string "TIMMY: Oui, en effet. Merci.\n"
	.string "Je vous rends votre POKéMON.\p"
	.string "{PLAYER}, merci de m'avoir accompagné.\p"
	.string "C'est grâce à vous deux que j'ai \n"
	.string "pu attraper mon POKéMON.\p"
	.string "Je promets de bien m'en occuper.\p"
	.string "Oh! Maman m'attend. J'y vais!\n"
	.string "A plus, {PLAYER}!$"

PetalburgCity_Gym_Text_DadGoCollectBadges: @ 8205C40
	.string "PAPA: Bon, maintenant…\p"
	.string "{PLAYER}, si tu veux devenir un\n"
	.string "bon DRESSEUR, voici mon conseil.\p"
	.string "Va à MEROUVILLE, c'est la ville\n"
	.string "qui se trouve un peu plus loin.\p"
	.string "Là, il te faudra battre le CHAMPION\n"
	.string "D'ARENE, ROXANNE.\p"
	.string "Ensuite, rends-toi dans les autres\n"
	.string "ARENES et bats les CHAMPIONS.\p"
	.string "Tu dois obtenir leurs BADGES,\n"
	.string "compris?\p"
	.string "Bien sûr, je suis aussi un CHAMPION.\n"
	.string "Un jour, on s'affrontera, {PLAYER}.\p"
	.string "Mais avant, il va falloir que tu\n"
	.string "améliores ton niveau, {PLAYER}.$"

PetalburgCity_Gym_Text_NormanGoToRustboro: @ 8205DB4
	.string "PAPA: Hum? Tu ne devais pas aller\n"
	.string "à l'ARENE de MEROUVILLE?\p"
	.string "Je n'ai aucun intérêt à affronter\n"
	.string "un DRESSEUR novice.\p"
	.string "{PLAYER}, t'affronterai quand\n"
	.string "tu auras un meilleur niveau.\p"
	.string "Nous combattrons, {PLAYER}, quand tu\n"
	.string "auras quatre BADGES à me montrer, OK?$"

PetalburgCity_Gym_Text_NormanGoToDewford: @ 8205EAE
	.string "PAPA: Je vois… Alors, tu as battu\n"
	.string "le CHAMPION de MEROUVILLE.\p"
	.string "Mais il y a bien d'autres DRESSEURS\n"
	.string "plus forts que toi, {PLAYER}.\p"
	.string "Traverse l'océan et va au\n"
	.string "VILLAGE MYOKARA.\p"
	.string "Tu devras y affronter un CHAMPION\n"
	.string "nommé BASTIEN.$"

PetalburgCity_Gym_Text_YouHaveGottenStronger: @ 8205F87
	.string "PAPA: Hum… {PLAYER}, tu as\n"
	.string "bien progressé.\p"
	.string "Je le vois au nombre de BADGES\n"
	.string "que tu as obtenus.$"

PetalburgCity_Gym_Text_NormanPreBattle: @ 8205FE5
	.string "PAPA: Hum…\n"
	.string "Alors tu as obtenu quatre BADGES.\p"
	.string "Très bien. Comme promis, nous allons\n"
	.string "faire un combat de POKéMON.\p"
	.string "{PLAYER}…\p"
	.string "Je suis si heureux de pouvoir\n"
	.string "affronter mon propre enfant.\p"
	.string "Mais un combat reste un combat!\p"
	.string "Je ferai tout ce qui est en mon pouvoir\n"
	.string "de CHAMPION D'ARENE pour gagner.\p"
	.string "{PLAYER}, il va aussi falloir donner\n"
	.string "le meilleur de toi-même!$"

PetalburgCity_Gym_Text_NormanDefeat: @ 8206107
	.string "…\p"
	.string "Je… Je ne peux…\p"
	.string "Je ne peux pas le croire. {PLAYER}…\p"
	.string "J'ai perdu contre toi?\p"
	.string "Mais le jeu, c'est le jeu!\n"
	.string "Voilà pour toi!$"

PetalburgCity_Gym_Text_ReceivedBalanceBadge: @ 8206162
	.string "{PLAYER} reçoit le BADGE BALANCIER\n"
	.string "de la part de PAPA!$"

PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis: @ 820618A
	.string "PAPA: Avec ce BADGE, la DEFENSE\n"
	.string "tous tes POKéMON va augmenter.\p"
	.string "Tout POKéMON connaissant la CS SURF\n"
	.string "pourra se déplacer sur l'eau.\p"
	.string "Je te l'offre, {PLAYER}. Je suis sûr\n"
	.string "que tu en feras bon usage.$"

PetalburgCity_Gym_Text_ExplainFacade: @ 8206254
	.string "PAPA: La CT42 contient FACADE.\p"
	.string "Elle double la puissance des capacités\n"
	.string "si le POKéMON est empoisonné,\l"
	.string "paralysé ou brûlé.\p"
	.string "Elle peut permettre de retourner une\n"
	.string "situation difficile à son avantage.$"

PetalburgCity_Gym_Text_DadHappyAndSad: @ 82062FB
	.string "PAPA: En tant que CHAMPION,\n"
	.string "je ne peux exprimer ma déception…\p"
	.string "Et en tant que père, ça me rend à la fois\n"
	.string "heureux et un peu triste. Etrange…$"

PetalburgCity_Gym_Text_PleaseComeWithMe: @ 8206377
	.string "Ah, te voilà {PLAYER}{KUN}!\p"
	.string "Viens avec moi, s'il te plaît.\n"
	.string "Je voudrais te donner quelque chose.$"

PetalburgCity_Gym_Text_LetMeBorrowPlayer: @ 82063CA
	.string "NORMAN, ça ne t'embête pas,\n"
	.string "n'est-ce pas?\p"
	.string "Tu veux bien me laisser parler avec\n"
	.string "{PLAYER}{KUN} pendant deux minutes?$"

PetalburgCity_Gym_Text_DadGoingToKeepTraining: @ 8206417
	.string "PAPA: {PLAYER}, tu devrais rendre visite\n"
	.string "à ta mère le plus souvent possible.\p"
	.string "Je vais rester ici et je redoublerai\n"
	.string "d'efforts pour mon entraînement.\p"
	.string "En tant que DRESSEUR, je dois\n"
	.string "prendre ma revanche, {PLAYER}!$"

PetalburgCity_Gym_Text_DadNoAmountOfTrainingIsEnough: @ 82064C3
	.string "PAPA: {PLAYER}, comment ça se passe?\p"
	.string "Le monde des POKéMON est vaste.\p"
	.string "Je pense que tout l'entraînement du\n"
	.string "monde ne suffirait jamais.$"

PetalburgCity_Gym_Text_GymGuideAdvice: @ 8206542
	.string "Hé, comment ça va, futur MAITRE\n"
	.string "{PLAYER}?\p"
	.string "Les portes de cette ARENE s'ouvrent\n"
	.string "dès que tu bats un DRESSEUR.\p"
	.string "Oups! Ici, les portes sont déjà\n"
	.string "ouvertes. Ne m'attaque pas!\p"
	.string "Les DRESSEURS de l'ARENE de CLEMENTI\n"
	.string "utilisent toutes sortes d'objets.\p"
	.string "La porte de gauche mène à la\n"
	.string "SALLE VITESSE.\p"
	.string "La porte de droite mène à la\n"
	.string "SALLE PRECISION.\p"
	.string "Le nom de la salle sera inscrit\n"
	.string "sur la porte. Fais le bon choix!\p"
	.string "Après avoir choisi la porte…\n"
	.string "Oh, et après tout, vas-y!$"

PetalburgCity_Gym_Text_GymGuidePostVictory: @ 82066F3
	.string "{PLAYER}! Waouh! Tu as même battu\n"
	.string "ton propre père!\p"
	.string "Oh, waouh! Quel retournement\n"
	.string "de situation exceptionnel!$"

PetalburgCity_Gym_Text_RandallPreBattle: @ 820674F
	.string "La capacité d'attaquer avant l'ennemi…\p"
	.string "Rien que ça suffit à donner un avantage\n"
	.string "certain, pas vrai?$"

PetalburgCity_Gym_Text_RandallDefeat: @ 82067B9
	.string "C'était un très beau combat!$"

PetalburgCity_Gym_Text_RandallPostBattle: @ 82067D8
	.string "Va dans la salle suivante!\n"
	.string "Un autre combat t'attend.\p"
	.string "A droite, se trouve la salle\n"
	.string "CONFUSION.\p"
	.string "A droite, se trouve la SALLE DEFENSE.$"

PetalburgCity_Gym_Text_RandallPostBadge: @ 820685E
	.string "Peu importe qui tu bats ou contre\n"
	.string "qui tu perds, tu ne dois jamais négliger\l"
	.string "l'entraînement ni tes POKéMON.\p"
	.string "D'après moi, c'est avant tout\n"
	.string "le devoir d'un CHAMPION D'ARENE.$"

PetalburgCity_Gym_Text_ParkerPreBattle: @ 82068FD
	.string "C'est la SALLE CONFUSION.\p"
	.string "Laisse-moi voir si tu es vraiment\n"
	.string "proche de tes POKéMON!$"

PetalburgCity_Gym_Text_ParkerDefeat: @ 820694F
	.string "Je n'ai pas réussi à vous rendre…\n"
	.string "suffisamment confus…\p"
	.string "Le lien qui t'unit à tes POKéMON\n"
	.string "est vraiment très fort.$"

PetalburgCity_Gym_Text_ParkerPostBattle: @ 8206996
	.string "La salle suivante est la SALLE FORCE.\n"
	.string "Peux-tu résister à la force pure?$"

PetalburgCity_Gym_Text_ParkerPostBadge: @ 82069D9
	.string "Après ta victoire sur notre CHAMPION,\n"
	.string "l'entraînement s'est intensifié.$"

PetalburgCity_Gym_Text_GeorgePreBattle: @ 8206A1B
	.string "C'est au moment où tu crois gagner\n"
	.string "que ton adversaire récupère ses PV…\p"
	.string "Tu peux imaginer comme c'est\n"
	.string "frustrant?\p"
	.string "Je vais justement te montrer\n"
	.string "à quel point ça l'est!$"

PetalburgCity_Gym_Text_GeorgeDefeat: @ 8206AB8
	.string "Je n'ai pas pu récupérer assez de PV…\n"
	.string "Quelle puissance d'ATTAQUE…$"

PetalburgCity_Gym_Text_GeorgePostBattle: @ 8206AE9
	.string "Je n'en attendais pas moins d'un\n"
	.string "enfant de CHAMPION.\p"
	.string "Non, attends! Il faut se donner du mal\n"
	.string "pour avoir les capacités d'un DRESSEUR.\p"
	.string "J'ai perdu parce que je n'ai pas fait\n"
	.string "suffisamment d'efforts.\p"
	.string "En avant vers la SALLE COUP CRITIQUE!$"

PetalburgCity_Gym_Text_GeorgePostBadge: @ 8206BB1
	.string "Je vais continuer à m'entraîner dans\n"
	.string "les ARENES et je deviendrai CHAMPION.$"

PetalburgCity_Gym_Text_BerkePreBattle: @ 8206BF4
	.string "Je ne vais pas te faciliter les choses\n"
	.string "parce que tu es l'enfant du CHAMPION.\p"
	.string "Tu vas voir comme un coup critique\n"
	.string "peut être terrible pour un POKéMON!$"

PetalburgCity_Gym_Text_BerkeDefeat: @ 8206C7D
	.string "Quelle puissance!\n"
	.string "Je ne regrette pas ce combat.$"

PetalburgCity_Gym_Text_BerkePostBattle: @ 8206C9F
	.string "Ton père est très fort. C'est un\n"
	.string "CHAMPION que je respecte.\p"
	.string "Et je discerne en toi la même ardeur\n"
	.string "que celle de ton père.\p"
	.string "J'espère que tu affronteras ton\n"
	.string "père dans un remarquable combat.$"

PetalburgCity_Gym_Text_BerkePostBadge: @ 8206D56
	.string "Depuis que ton père est le CHAMPION,\n"
	.string "les DRESSEURS de CLEMENTI-VILLE\l"
	.string "sont plus résistants.$"

PetalburgCity_Gym_Text_MaryPreBattle: @ 8206DB2
	.string "Hi hi hi…\n"
	.string "C'est la SALLE PRECISION.\p"
	.string "C'est pénible de voir que certains\n"
	.string "ratent jamais aucune attaque.$"

PetalburgCity_Gym_Text_MaryDefeat: @ 8206E0D
	.string "A côté de moi, tu joues dans la\n"
	.string "cour des grands…$"

PetalburgCity_Gym_Text_MaryPostBattle: @ 8206E26
	.string "D'autres DRESSEURS, encore\n"
	.string "plus forts, t'attendent.\p"
	.string "A gauche, c'est la SALLE DEFENSE\n"
	.string "et à droite, la SALLE RECUPERATION.\p"
	.string "De toute façon, la puissance d'ATTAQUE\n"
	.string "de tes POKéMON sera mise à l'épreuve.$"

PetalburgCity_Gym_Text_MaryPostBadge: @ 8206ED8
	.string "Sais-tu ce à quoi nous aspirons\n"
	.string "en tant que DRESSEURS?\p"
	.string "Nous nous efforçons d'être en\n"
	.string "totale osmose avec nos POKéMON.$"

PetalburgCity_Gym_Text_AlexiaPreBattle: @ 8206F44
	.string "Plus ma DEFENSE est élevée, plus\n"
	.string "audacieuse je peux être en attaquant.$"

PetalburgCity_Gym_Text_AlexiaDefeat: @ 8206F82
	.string "Nos défenses n'ont pas suffi…$"

PetalburgCity_Gym_Text_AlexiaPostBattle: @ 8206F9F
	.string "Je dois dire que tu m'as donné\n"
	.string "une bonne leçon.\p"
	.string "Allez, continue! La porte de gauche\n"
	.string "mène à la SALLE FORCE.\p"
	.string "La porte de droite donne sur\n"
	.string "la SALLE COUP CRITIQUE.\p"
	.string "Toutes deux mènent à des DRESSEURS\n"
	.string "spécialisés dans l'offensive.$"

PetalburgCity_Gym_Text_AlexiaPostBadge: @ 8207069
	.string "Salut! Tu as déjà utilisé SURF? Si ce\n"
	.string "n'est pas le cas, tu devrais essayer.$"

PetalburgCity_Gym_Text_JodyPreBattle: @ 8207088
	.string "ONotre CHAMPION nous a dit de\n"
	.string "tout donner pour te battre.\p"
	.string "Même si tu es son enfant!$"

PetalburgCity_Gym_Text_JodyDefeat: @ 82070E6
	.string "Mais… J'ai pourtant tout donné!$"

PetalburgCity_Gym_Text_JodyPostBattle: @ 82070FB
	.string "La façon dont tu utilises tes POKéMON…\n"
	.string "C'est tout ton père!\p"
	.string "Continue! Le CHAMPION, ton père,\n"
	.string "t'attend.$"

PetalburgCity_Gym_Text_JodyPostBadge: @ 8207170
	.string "En effet, c'est très bien de rendre\n"
	.string "tes POKéMON plus forts.\p"
	.string "Mais qu'est-ce qui détermine\n"
	.string "la victoire?\p"
	.string "Ce sont les sentiments des DRESSEURS\n"
	.string "pour leurs POKéMON.$"

PetalburgCity_Gym_Text_DoorAppearsLocked: @ 82071F4
	.string "Cette porte semble être fermée\n"
	.string "à clé pour le moment…$"

PetalburgCity_Gym_Text_EnterSpeedRoom: @ 820721E
	.string "“SALLE VITESSE”\n"
	.string "est inscrit sur cette porte.\p"
	.string "Voulez-vous entrer?$"

@ Unused
PetalburgCity_Gym_Text_DoorAppearsLocked2: @ 8207256
	.string "Cette porte semble être fermée\n"
	.string "à clé pour le moment…$"

PetalburgCity_Gym_Text_EnterAccuracyRoom: @ 8207280
	.string "“SALLE PRECISION”\n"
	.string "est inscrit sur cette porte.\p"
	.string "Voulez-vous entrer?$"

PetalburgCity_Gym_Text_EnterConfusionRoom: @ 82072BB
	.string "“SALLE CONFUSION”\n"
	.string "est inscrit sur cette porte.\p"
	.string "Voulez-vous entrer?$"

PetalburgCity_Gym_Text_EnterDefenseRoom: @ 82072F7
	.string "“SALLE DEFENSE”\n"
	.string "est inscrit sur cette porte.\p"
	.string "Voulez-vous entrer?$"

PetalburgCity_Gym_Text_EnterRecoveryRoom: @ 8207331
	.string "“SALLE RECUPERATION”\n"
	.string "est inscrit sur cette porte.\p"
	.string "Voulez-vous entrer?$"

PetalburgCity_Gym_Text_EnterStrengthRoom: @ 820736C
	.string "“SALLE FORCE”\n"
	.string "est inscrit sur cette porte.\p"
	.string "Voulez-vous entrer?$"

PetalburgCity_Gym_Text_EnterOHKORoom: @ 82073A7
	.string "“SALLE COUP CRITIQUE”\n"
	.string "est inscrit sur cette porte.\p"
	.string "Voulez-vous entrer?$"

PetalburgCity_Gym_Text_EnterGymLeadersRoom: @ 82073E4
	.string "“SALLE du CHAMPION D'ARENE\p"
	.string "“Va voir quels POKéMON t'attendent!”\n"
	.string "est inscrit sur cette porte.\p"
	.string "Voulez-vous entrer?$"

PetalburgCity_Gym_Text_GymStatue: @ 820744C
	.string "ARENE POKéMON de CLEMENTI-VILLE$"

PetalburgCity_Gym_Text_GymStatueCertified: @ 8207467
	.string "ARENE POKéMON de CLEMENTI-VILLE\p"
	.string "NOUVEAU DRESSEUR RECONNU PAR NORMAN:\n"
	.string "{PLAYER}$"

PetalburgCity_Gym_Text_NormanPreRematch: @ 82074A2
	.string "PAPA: {PLAYER}…\n"
	.string "Je savais que tu viendrais.\p"
	.string "Je ne peux pas refuser un\n"
	.string "combat contre toi.\p"
	.string "Tu comprends, n'est-ce pas?\p"
	.string "Dans une ARENE, les liens du sang\n"
	.string "ne comptent pas.\p"
	.string "…Nous sommes de la même\n"
	.string "famille, mais nous ne nous ferons pas\l"
	.string "de cadeau!\p"
	.string "N'est-ce pas, {PLAYER}?$"

PetalburgCity_Gym_Text_NormanRematchDefeat: @ 82075CE
	.string "Hein… Haha…\n"
	.string "Tu n'as vraiment pas retenu tes coups…$"

PetalburgCity_Gym_Text_NormanPostRematch: @ 82075F7
	.string "PAPA: {PLAYER}…\n"
	.string "Etait-ce un rêve?\p"
	.string "Mon rêve…\n"
	.string "Hahaha…\l"
	.string "En fait, il s'est déjà réalisé.$"

PetalburgCity_Gym_Text_NormanRematchNeedTwoMons: @ 820764A
	.string "PAPA: {PLAYER}…\n"
	.string "Je savais que tu viendrais.\p"
	.string "Je ne peux pas refuser un\n"
	.string "combat contre toi.\p"
	.string "Tu comprends, n'est-ce pas?\p"
	.string "Dans une ARENE, les liens du sang\n"
	.string "ne comptent pas.\p"
	.string "… Une seconde, {PLAYER}.\p"
	.string "N'as-tu vraiment qu'un POKéMON\n"
	.string "capable de se battre?\p"
	.string "Désolé, mais tu devras revenir avec\n"
	.string "au moins deux POKéMON.$"

