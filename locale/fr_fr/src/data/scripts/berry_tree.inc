BerryTreeScript:: @ 82742F9
	special EventObjectInteractionGetBerryTreeData
	switch VAR_0x8004
	case BERRY_STAGE_SPARKLING, BerryTree_EventScript_Sparkling
	case BERRY_STAGE_NO_BERRY, BerryTree_EventScript_CheckSoil
	case BERRY_STAGE_PLANTED, BerryTree_EventScript_CheckBerryStage1
	case BERRY_STAGE_SPROUTED, BerryTree_EventScript_CheckBerryStage2
	case BERRY_STAGE_TALLER, BerryTree_EventScript_CheckBerryStage3
	case BERRY_STAGE_FLOWERING, BerryTree_EventScript_CheckBerryStage4
	case BERRY_STAGE_BERRIES, BerryTree_EventScript_CheckBerryFullyGrown
	end

BerryTree_EventScript_Sparkling:: @ 827434F
	lockall
	message BerryTree_Text_ExclamationPoint
	waitmessage
	waitbuttonpress
	releaseall
	end

BerryTree_EventScript_CheckSoil:: @ 8274359
	lock
	faceplayer
	specialvar VAR_RESULT, PlayerHasBerries
	compare VAR_RESULT, TRUE
	goto_if_eq BerryTree_EventScript_WantToPlant
	message BerryTree_Text_ItsSoftLoamySoil
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_WantToPlant:: @ 8274374
	msgbox BerryTree_Text_WantToPlant, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq BerryTree_EventScript_ChooseBerryToPlant
	compare VAR_RESULT, 0
	goto_if_eq BerryTree_EventScript_CancelPlanting
	end

BerryTree_EventScript_ChooseBerryToPlant:: @ 8274393
	fadescreen 1
	closemessage
	special Bag_ChooseBerry
	waitstate
	compare VAR_ITEM_ID, 0
	goto_if_eq BerryTree_EventScript_CancelPlanting
	takeitem VAR_ITEM_ID, 1
	call BerryTree_EventScript_PlantBerry

BerryTree_EventScript_CancelPlanting:: @ 82743AF
	release
	end

BerryTree_EventScript_CheckBerryStage1:: @ 82743B1
	lockall
	special EventObjectInteractionGetBerryCountString
	message BerryTree_Text_BerryGrowthStage1
	waitmessage
	waitbuttonpress
	goto BerryTree_EventScript_WantToWater

BerryTree_EventScript_CheckBerryStage2:: @ 82743C1
	lockall
	special EventObjectInteractionGetBerryName
	message BerryTree_Text_BerryGrowthStage2
	waitmessage
	waitbuttonpress
	goto BerryTree_EventScript_WantToWater

BerryTree_EventScript_CheckBerryStage3:: @ 82743D1
	lockall
	special EventObjectInteractionGetBerryName
	message BerryTree_Text_BerryGrowthStage3
	waitmessage
	waitbuttonpress
	goto BerryTree_EventScript_WantToWater

BerryTree_EventScript_CheckBerryStage4:: @ 82743E1
	call BerryTree_EventScript_GetCareAdverb
	lockall
	special EventObjectInteractionGetBerryName
	message BerryTree_Text_BerryGrowthStage4
	waitmessage
	waitbuttonpress
	goto BerryTree_EventScript_WantToWater

@ VAR_0x8005 here is the number of times watered
@ Buffered by EventObjectInteractionGetBerryTreeData
BerryTree_EventScript_GetCareAdverb:: @ 82743F6
	compare VAR_0x8005, 0
	goto_if_eq BerryTree_EventScript_SetAdverbPoor
	compare VAR_0x8005, 4
	goto_if_eq BerryTree_EventScript_SetAdverbGreat
	bufferstring 1, BerryTree_Text_CareAdverbGood
	return

BerryTree_EventScript_SetAdverbGreat:: @ 8274413
	bufferstring 1, BerryTree_Text_CareAdverbGreat
	return

BerryTree_EventScript_SetAdverbPoor:: @ 827441A
	bufferstring 1, BerryTree_Text_CareAdverbPoor
	return

@ VAR_0x8006 here is the number of berries
BerryTree_EventScript_CheckBerryFullyGrown:: @ 8274421
	buffernumberstring 1, VAR_0x8006
	lock
	faceplayer
	special EventObjectInteractionGetBerryCountString
	msgbox BerryTree_Text_WantToPick, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq BerryTree_EventScript_PickBerry
	compare VAR_RESULT, 0
	goto_if_eq BerryTree_EventScript_CancelPickingBerry

BerryTree_EventScript_PickBerry:: @ 8274448
	special EventObjectInteractionPickBerryTree
	compare VAR_0x8004, 0
	goto_if_eq BerryTree_EventScript_BerryPocketFull
	special IncrementDailyPickedBerries
	special EventObjectInteractionRemoveBerryTree
	message BerryTree_Text_PickedTheBerry
	playfanfare MUS_ME_KINOMI
	waitmessage
	waitfanfare
	waitbuttonpress
	message BerryTree_Text_PutAwayBerry
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_BerryPocketFull:: @ 8274470
	message BerryTree_Text_BerryPocketFull
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_CancelPickingBerry:: @ 8274479
	message BerryTree_Text_BerryLeftUnpicked
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_ItemUsePlantBerry:: @ 8274482
	lockall
	special EventObjectInteractionGetBerryTreeData
	call BerryTree_EventScript_PlantBerry
	releaseall
	end

BerryTree_EventScript_WantToWater:: @ 827448D
	checkitem ITEM_WAILMER_PAIL, 1
	compare VAR_RESULT, 0
	goto_if_eq BerryTree_EventScript_DontWater
	special EventObjectInteractionGetBerryName
	msgbox BerryTree_Text_WantToWater, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq BerryTree_EventScript_WaterBerry
	compare VAR_RESULT, 0
	goto_if_eq BerryTree_EventScript_DontWater

BerryTree_EventScript_DontWater:: @ 82744BE
	releaseall
	end

BerryTree_EventScript_ItemUseWailmerPail:: @ 82744C0
	special EventObjectInteractionGetBerryTreeData
	lockall
BerryTree_EventScript_WaterBerry:: @ 82744C4
	special EventObjectInteractionGetBerryName
	message BerryTree_Text_WateredTheBerry
	waitmessage
	special EventObjectInteractionWaterBerryTree
	special DoWateringBerryTreeAnim
	waitstate
	message BerryTree_Text_PlantIsDelighted
	waitmessage
	waitbuttonpress
	releaseall
	end

BerryTree_EventScript_PlantBerry:: @ 82744DD
	special EventObjectInteractionPlantBerryTree
	incrementgamestat GAME_STAT_PLANTED_BERRIES
	special IncrementDailyPlantedBerries
	special EventObjectInteractionGetBerryCountString
	message BerryTree_Text_PlantedOneBerry
	waitmessage
	waitbuttonpress
	return

BerryTree_Text_ItsSoftLoamySoil: @ 82744F0
	.string "C'est un sol meuble et fertile.$"

BerryTree_Text_WantToPlant: @ 8274507
	.string "C'est un sol meuble et fertile.\n"
	.string "Voulez-vous planter une BAIE?$"

BerryTree_Text_PlantedOneBerry: @ 8274535
	.string "{PLAYER} a planté une {STR_VAR_1}.$"

BerryTree_Text_BerryGrowthStage1: @ 8274560
	.string "Une {STR_VAR_1} a été plantée ici.$"

BerryTree_Text_BerryGrowthStage2: @ 8274579
	.string "{STR_VAR_1} a bourgeonné.$"

BerryTree_Text_BerryGrowthStage3: @ 827458A
	.string "Cette plante de {STR_VAR_1} a poussé.$"

BerryTree_Text_BerryGrowthStage4: @ 82745AB
	.string "Ces fleurs de {STR_VAR_1} ont éclos et sont\n"
	.string "{STR_VAR_2}.$"

BerryTree_Text_CareAdverbGreat: @ 82745CD
	.string "d'une beauté incomparable$"

BerryTree_Text_CareAdverbPoor: @ 82745DE
	.string "ravissantes$"

BerryTree_Text_CareAdverbGood: @ 82745E5
	.string "jolies$"

BerryTree_Text_WantToPick: @ 82745EE
	.string "Il y a {STR_VAR_2} {STR_VAR_1}!\p"
	.string "Cueillir {STR_VAR_1}?$"

BerryTree_Text_PickedTheBerry: @ 827461B
	.string "{PLAYER} a cueilli {STR_VAR_2} {STR_VAR_1}.$"

BerryTree_Text_PutAwayBerry: @ 8274630
	.string "{PLAYER} met {STR_VAR_1} dans la\n"
	.string "POCHE BAIES du SAC.\p"
	.string "Le sol est à nouveau meuble et fertile.$"

BerryTree_Text_BerryPocketFull: @ 827468F
	.string "La POCHE BAIES du SAC est pleine.\p"
	.string "Impossible de cueillir {STR_VAR_1}.$"

BerryTree_Text_BerryLeftUnpicked: @ 82746CB
	.string "{PLAYER} n'a pas cueilli\n"
	.string "{STR_VAR_1}.$"

BerryTree_Text_WantToWater: @ 82746E4
	.string "Voulez-vous arroser la BAIE\n"
	.string "{STR_VAR_1} avec le SEAU WAILMER?$"

BerryTree_Text_WateredTheBerry: @ 8274710
	.string "{PLAYER} arrose la {STR_VAR_1}.$"

BerryTree_Text_PlantIsDelighted: @ 8274723
	.string "La plante semble ravie.$"

BerryTree_Text_ExclamationPoint: @ 8274744
	.string "!$"
