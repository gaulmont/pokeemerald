PetalburgCity_WallysHouse_MapScripts:: @ 8204229
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_MapScript2_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_MapScript2_OnWarp
	.byte 0

PetalburgCity_WallysHouse_MapScript2_OnWarp: @ 8204234
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerUncleFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerUncleFaceEachOther:: @ 820423E
	turnobject EVENT_OBJ_ID_PLAYER, DIR_EAST
	turnobject 1, DIR_WEST
	end

PetalburgCity_WallysHouse_MapScript2_OnFrame: @ 8204247
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHM03Surf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHM03Surf:: @ 8204251
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem_std ITEM_HM03
	setflag FLAG_RECEIVED_HM03
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallyUncle:: @ 8204278
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM03, PetalburgCity_WallysHouse_EventScript_ReceievedHM03Surf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHM03Surf:: @ 82042A2
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad:: @ 82042AC
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally:: @ 82042B6
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallyAunt:: @ 82042C0
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM03, PetalburgCity_WallysHouse_EventScript_ReceivedHM03Surf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHM03Surf:: @ 82042D5
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally: @ 82042DF
	.string "Tu es…\n"
	.string "Ah, tu dois être {PLAYER}{KUN}, n'est-ce pas?\p"
	.string "Merci d'avoir joué avec TIMMY.\p"
	.string "Il est faible et maladif depuis\n"
	.string "qu'il est tout petit.\p"
	.string "Nous l'avons envoyé chez des parents à\n"
	.string "VERGAZON pour quelque temps.\p"
	.string "L'air qu'on y respire est bien\n"
	.string "meilleur qu'ici.\p"
	.string "Comment ça? Où est TIMMY?\n"
	.string "Il est déjà parti, notre TIMMY.\p"
	.string "Je me demande où il peut bien\n"
	.string "être en ce moment.$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing: @ 820444D
	.string "Comment va notre TIMMY?$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs: @ 820446E
	.string "{PLAYER}{KUN}! Merci d'avoir accepté\n"
	.string "de venir.\p"
	.string "Notre TIMMY est en meilleure santé\n"
	.string "depuis qu'il est allé à VERGAZON.\p"
	.string "Et c'est à toi que nous le devons!\p"
	.string "Quand TIMMY a quitté la ville, tu l'as\n"
	.string "aidé à attraper un POKéMON, pas vrai?\p"
	.string "Je pense que ça l'a rendu très heureux.\p"
	.string "En fait, il n'y a pas que lui. Cela m'a\n"
	.string "aussi rendu heureux, moi son père.\p"
	.string "Quelle chance pour lui d'avoir comme\n"
	.string "camarade quelqu'un d'aussi bien que toi!\p"
	.string "Ce n'est pas pour te flatter, mais\n"
	.string "j'aimerais que tu acceptes ça.$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces: @ 820461A
	.string "Si ton POKéMON peut utiliser SURF,\n"
	.string "tu découvriras toutes sortes de lieux.$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon: @ 8204661
	.string "TIMMY va bientôt rentrer.\n"
	.string "Je l'attends avec impatience.$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity: @ 8204698
	.string "Ah? Tu as vu TIMMY à ETERNARA?\p"
	.string "Oh, {PLAYER}{KUN}, ne dis pas n'importe quoi!\p"
	.string "Même s'il va mieux, il n'a pas\n"
	.string "pu aller aussi loin tout seul..$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy: @ 8204732
	.string "TIMMY était très content de nous\n"
	.string "dire qu'il avait attrapé un POKéMON.\p"
	.string "Ça faisait une éternité que je ne\n"
	.string "l'avais pas vu sourire comme ça.$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling: @ 82047A7
	.string "N'en parle pas à mon mari…\p"
	.string "Mais notre TIMMY a quitté VERGAZON\n"
	.string "sans rien dire à personne.\p"
	.string "Tu sais, TIMMY est frêle, mais\n"
	.string "il a beaucoup de volonté.\p"
	.string "Je suis sûre qu'il rentrera bientôt\n"
	.string "sain et sauf.$"

