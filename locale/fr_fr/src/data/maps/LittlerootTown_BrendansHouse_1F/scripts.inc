LittlerootTown_BrendansHouse_1F_MapScripts:: @ 81F7755
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad: @ 81F7765
	compare VAR_LITTLEROOT_INTRO_STATE, 6
	call_if_lt LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes:: @ 81F777A
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, 1
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, 1
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual:: @ 81F778D
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual:: @ 81F779A
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, 1
	return

LittlerootTown_BrendansHouse_1F_OnTransition: @ 81F77A4
	compare VAR_LITTLEROOT_INTRO_STATE, 3
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	compare VAR_LITTLEROOT_INTRO_STATE, 5
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
	compare VAR_LITTLEROOT_INTRO_STATE, 6
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs:: @ 81F77C6
	setobjectxyperm 1, 8, 4
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV:: @ 81F77D2
	setobjectxyperm 1, 4, 5
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor:: @ 81F77DE
	setobjectxyperm 1, 9, 8
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
LittlerootTown_BrendansHouse_1F_OnFrame: @ 81F77EA
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock:: @ 81F7814
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	applymovement 1, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 255, 7, 1
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs: @ 81F783A
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn:: @ 81F783C
	lockall
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, MALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport:: @ 81F784D
	lockall
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 1  @ Object event ID for Mom
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
	end

LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor:: @ 81F785E
	lockall
	playse SE_PIN
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	applymovement 4, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE, 2
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach: @ 81F789C
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom:: @ 81F78A3
	lockall
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0:: @ 81F78BE
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1:: @ 81F78CA
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2:: @ 81F78D6
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival:: @ 81F78E2
	playse SE_KAIDAN
	delay 10
	addobject 7
	delay 30
	playse SE_PIN
	applymovement 7, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	compare VAR_0x8008, 1
	call_if_ne LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
	playbgm MUS_BOY_SUP, 1
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
	compare VAR_0x8008, 2
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
	compare VAR_0x8008, 2
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
	playse SE_KAIDAN
	removeobject 7
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan:: @ 81F7981
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0:: @ 81F798C
	applymovement 7, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1:: @ 81F7997
	applymovement 7, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2:: @ 81F79A2
	applymovement 7, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0: @ 81F79AD
	walk_in_place_fastest_left
	walk_left
	walk_in_place_fastest_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1: @ 81F79B5
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2: @ 81F79B9
	walk_in_place_fastest_right
	walk_right
	walk_in_place_fastest_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0:: @ 81F79C1
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
	applymovement 7, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1:: @ 81F79D3
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
	applymovement 7, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2:: @ 81F79E5
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
	applymovement 7, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0: @ 81F79F7
	delay_16
	delay_8
	walk_in_place_fastest_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1: @ 81F79FB
	delay_16
	delay_8
	walk_in_place_fastest_right
	delay_16
	delay_16
	walk_in_place_fastest_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2: @ 81F7A02
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0: @ 81F7A06
	walk_in_place_fastest_right
	walk_right
	walk_in_place_fastest_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1: @ 81F7A0C
	walk_in_place_fastest_right
	walk_right
	walk_in_place_fastest_up
	walk_up
	walk_up
	walk_in_place_fastest_left
	walk_left
	walk_in_place_fastest_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2: @ 81F7A16
	walk_in_place_fastest_left
	walk_left
	walk_in_place_fastest_up
	walk_up
	walk_up
	step_end

PlayersHouse_1F_Text_IsntItNiceInHere: @ 81F7A1C
	.string "MAMAN: Alors, {PLAYER}?\n"
	.string "C'est joli ici, non?$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock: @ 81F7A46
	.string "Les POKéMON déménageurs font tout\n"
	.string "le travail et nettoient après.\p"
	.string "C'est vraiment pratique!\p"
	.string "{PLAYER}, ta chambre est à l'étage.\n"
	.string "Va voir à quoi elle ressemble, mon chou!\p"
	.string "PAPA a acheté une nouvelle horloge\n"
	.string "pour fêter notre déménagement.\p"
	.string "N'oublie pas de la mettre à l'heure!$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom: @ 81F7B24
	.string "MAMAN: Eh bien, {PLAYER}?\p"
	.string "Tu n'as pas envie de voir ta\n"
	.string "nouvelle chambre?$"

PlayersHouse_1F_Text_GoSetTheClock: @ 81F7B67
	.string "MAMAN: {PLAYER}.\p"
	.string "Va mettre l'horloge de ta chambre à\n"
	.string "l'heure, mon chou.$"

PlayersHouse_1F_Text_OhComeQuickly: @ 81F7B96
	.string "MAMAN: Oh! {PLAYER}, {PLAYER}!\n"
	.string "Vite! Viens voir!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn: @ 81F7BBC
	.string "MAMAN: Regarde! C'est l'ARENE de\n"
	.string "CLEMENTI-VILLE!\p"
	.string "On va peut-être voir PAPA!$"

PlayersHouse_1F_Text_ItsOverWeMissedHim: @ 81F7BF1
	.string "MAMAN: Oh… C'est terminé.\p"
	.string "Ils ont sûrement interviewé PAPA,\n"
	.string "mais on l'a raté. Dommage.$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor: @ 81F7C35
	.string "Ah, tiens!\n"
	.string "L'un des amis de PAPA vit ici.\p"
	.string "Il s'appelle PROF. SEKO.\p"
	.string "C'est notre voisin. Tu pourrais aller\n"
	.string "lui dire bonjour et te présenter.$"

PlayersHouse_1F_Text_SeeYouHoney: @ 81F7CC3
	.string "MAMAN: A plus tard, mon chou!$"

PlayersHouse_1F_Text_DidYouMeetProfBirch: @ 81F7CD8
	.string "MAMAN: Tu as déjà rencontré le\n"
	.string "PROF. SEKO?$"

PlayersHouse_1F_Text_YouShouldRestABit: @ 81F7D08
	.string "MAMAN: Comment ça va, {PLAYER}?\n"
	.string "Tu as l'air raplapla.\p"
	.string "Tu devrais peut-être te reposer.$"

PlayersHouse_1F_Text_TakeCareHoney: @ 81F7D5C
	.string "MAMAN: A bientôt, mon chou!$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom: @ 81F7D73
	.string "MAMAN: Oh? PAPA t'a donné\n"
	.string "un BADGE?\p"
	.string "Dans ce cas, je vais te donner ça!$"

PlayersHouse_1F_Text_DontPushYourselfTooHard: @ 81F7DBE
	.string "Ne t'épuise pas trop, mon chou. Tu peux\n"
	.string "revenir à la maison quand tu veux.\p"
	.string "Bon courage, mon poussin!$"

PlayersHouse_1F_Text_IsThatAPokenav: @ 81F7E0E
	.string "MAMAN: C'est un POKéNAV, mon chou?\n"
	.string "Quelqu'un de DEVON te l'a donné?\p"
	.string "Dis, mon chou? Et si tu enregistrais\n"
	.string "ta maman?\p"
	.string "… … …$"

PlayersHouse_1F_Text_RegisteredMom: @ 81F7E89
	.string "Vous avez enregistré MAMAN\n"
	.string "dans le POKéNAV.$"

PlayersHouse_1F_Text_Vigoroth1: @ 81F7EA8
	.string "Vigooooh…$"

PlayersHouse_1F_Text_Vigoroth2: @ 81F7EB3
	.string "Gorooooh…$"

PlayersHouse_1F_Text_ReportFromPetalburgGym: @ 81F7EC6
	.string "JOURNALISTE: …Ce reportage vous a été\n"
	.string "présenté devant l'ARENE de CLEMENTI.$"

PlayersHouse_1F_Text_TheresAMovieOnTV: @ 81F7F0F
	.string "Il y a un film à la télé.\p"
	.string "hommes dansent sur un\n"
	.string "grand piano.\p"
	.string "Bon, il faut y aller!$"

PlayersHouse_1F_Text_RunningShoesManual: @ 81F7F66
	.string "C'est le manuel d'instructions des\n"
	.string "CHAUSSURES DE SPORT.\p"
	.string "“Lorsque vous portez vos CHAUSSURES\n"
	.string "DE SPORT, appuyez sur le bouton B\l"
	.string "pour courir.”\p"
	.string "“Enfilez vos CHAUSSURES DE SPORT\n"
	.string "et foncez droit devant!”$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou: @ 81F800E
	.string "PAPA: Hein?\p"
	.string "Hé, mais c'est {PLAYER}!\p"
	.string "Ça fait un moment qu'on ne s'est pas\n"
	.string "vus. Tu as l'air d'avoir plus d'aplomb.\p"
	.string "C'est l'impression que tu me donnes.\n"
	.string "Mais ton vieux père n'abandonne pas!\p"
	.string "Ah, oui, j'ai quelque chose pour toi.\n"
	.string "Un certain M. MARCO m'a donné ça\l"
	.string "pour toi.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove: @ 81F80FE
	.string "PAPA: C'est un PASSE pour le ferry?\p"
	.string "Si ma mémoire est bonne, il y a des\n"
	.string "embarcadères à POIVRESSEL et à\l"
	.string "NENUCRIQUE pour le ferry.$"

PlayersHouse_1F_Text_BetterGetBackToGym: @ 81F815B
	.string "Je dois retourner à l'ARENE de\n"
	.string "CLEMENTI-VILLE.\p"
	.string "Désolé chérie, je dois déjà repartir.$"

PlayersHouse_1F_Text_DadShouldStayLonger: @ 81F81B9
	.string "MAMAN: Ton PAPA est incroyable…\p"
	.string "Il n'est jamais à la maison et quand il\n"
	.string "rentre, il ne parle que de POKéMON.\p"
	.string "Il devrait se reposer et rentrer\n"
	.string "plus souvent.$"

PlayersHouse_1F_Text_IsThatABreakingStory: @ 81F824B
	.string "MAMAN: Est-ce que c'est un scoop?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash: @ 81F826F
	.string "Et voici un bulletin spécial\n"
	.string "d'informations.\p"
	.string "Selon des témoignages, un POKéMON\n"
	.string "VOLANT de couleur BZZT… a été\l"
	.string "aperçu à plusieurs endroits dans HOENN.\p"
	.string "L'identité de ce POKéMON n'a pas encore\n"
	.string "été déterminée.\p"
	.string "Et maintenant, voici votre film du soir\n"
	.string "en exclusivité.$"

PlayersHouse_1F_Text_WhatColorDidTheySay: @ 81F8351
	.string "MAMAN: {PLAYER}, tu as compris?\p"
	.string "Qu'est-ce qu'ils ont dit à propos de la\n"
	.string "de ce POKéMON?$"

PlayersHouse_1F_Text_StillUnknownPokemon: @ 81F83A1
	.string "MAMAN: Dire qu'il reste encore des\n"
	.string "POKéMON inconnus à notre époque.$"
