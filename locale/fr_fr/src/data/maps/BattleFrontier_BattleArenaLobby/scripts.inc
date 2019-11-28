BattleFrontier_BattleArenaLobby_MapScripts:: @ 8255C36
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_MapScript2_255C55
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_MapScript2_255C41
	.byte 0

BattleFrontier_BattleArenaLobby_MapScript2_255C41: @ 8255C41
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaLobby_EventScript_255C4B
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_255C4B:: @ 8255C4B
	setvar VAR_TEMP_1, 1
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleArenaLobby_MapScript2_255C55: @ 8255C55
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleArenaLobby_EventScript_255C7F
	map_script_2 VAR_TEMP_0, 1, BattleFrontier_BattleArenaLobby_EventScript_255C88
	map_script_2 VAR_TEMP_0, 2, BattleFrontier_BattleArenaLobby_EventScript_255DC0
	map_script_2 VAR_TEMP_0, 3, BattleFrontier_BattleArenaLobby_EventScript_255CCF
	map_script_2 VAR_TEMP_0, 4, BattleFrontier_BattleArenaLobby_EventScript_255D2B
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_255C7F:: @ 8255C7F
	setvar VAR_0x8004, 0
	special CallFrontierUtilFunc
	end

BattleFrontier_BattleArenaLobby_EventScript_255C88:: @ 8255C88
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_256811, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special CallBattleArenaFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 0
	special CallBattleArenaFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_255CCF:: @ 8255CCF
	lockall
	setvar VAR_0x8004, 10
	special CallFrontierUtilFunc
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleArenaLobby_EventScript_255CF0
	msgbox BattleFrontier_BattleArenaLobby_Text_2568E7, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_255CF8

BattleFrontier_BattleArenaLobby_EventScript_255CF0:: @ 8255CF0
	msgbox BattleFrontier_BattleArenaLobby_Text_2572D9, MSGBOX_DEFAULT

BattleFrontier_BattleArenaLobby_EventScript_255CF8:: @ 8255CF8
	msgbox BattleFrontier_BattleArenaLobby_Text_257353, MSGBOX_DEFAULT
	setvar VAR_0x8004, 11
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattleArenaLobby_Text_241520, 9
	message BattleFrontier_BattleArenaLobby_Text_256931
	waitmessage
	call BattleFrontier_BattleArenaLobby_EventScript_255D59
	msgbox BattleFrontier_BattleArenaLobby_Text_256A74, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_255D2B:: @ 8255D2B
	lockall
	message BattleFrontier_BattleArenaLobby_Text_256A2C
	waitmessage
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 0
	special CallBattleArenaFunction
	call BattleFrontier_BattleArenaLobby_EventScript_255D59
	msgbox BattleFrontier_BattleArenaLobby_Text_256A74, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_255D59:: @ 8255D59
	setvar VAR_0x8004, 8
	special CallFrontierUtilFunc
	special LoadPlayerParty
	special HealPlayerParty
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 0
	special CallBattleArenaFunction
	playse SE_SAVE
	waitse
	call BattleFrontier_BattleArenaLobby_EventScript_23E8E0
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleArenaLobby_EventScript_255DBF
	message BattleFrontier_BattleArenaLobby_Text_256B19
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaLobby_EventScript_255DBF
	case 0, BattleFrontier_BattleArenaLobby_EventScript_255DBA
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_255DBF

BattleFrontier_BattleArenaLobby_EventScript_255DBA:: @ 8255DBA
	call BattleFrontier_BattleArenaLobby_EventScript_23E8B4

BattleFrontier_BattleArenaLobby_EventScript_255DBF:: @ 8255DBF
	return

BattleFrontier_BattleArenaLobby_EventScript_255DC0:: @ 8255DC0
	lockall
	message BattleFrontier_BattleArenaLobby_Text_256AA1
	waitmessage
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 1
	special CallBattleArenaFunction
	playse SE_SAVE
	waitse
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_TEMP_0, 255
	goto BattleFrontier_BattleArenaLobby_EventScript_255F54

BattleFrontier_BattleArenaLobby_EventScript_255DF4:: @ 8255DF4
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 3
	setvar VAR_FRONTIER_BATTLE_MODE, 0
	special SavePlayerParty
	msgbox BattleFrontier_BattleArenaLobby_Text_256166, MSGBOX_DEFAULT

BattleFrontier_BattleArenaLobby_EventScript_255E0B:: @ 8255E0B
	message BattleFrontier_BattleArenaLobby_Text_2561EA
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_255E47
	case 1, BattleFrontier_BattleArenaLobby_EventScript_255F9F
	case 2, BattleFrontier_BattleArenaLobby_EventScript_255FFB
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_255FFB

BattleFrontier_BattleArenaLobby_EventScript_255E47:: @ 8255E47
	message BattleFrontier_BattleArenaLobby_Text_256513
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, 0
	switch VAR_RESULT
	case 2, BattleFrontier_BattleArenaLobby_EventScript_255FFB
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_255FFB
	setvar VAR_0x8004, 15
	special CallFrontierUtilFunc
	compare VAR_0x8004, 1
	goto_if_eq BattleFrontier_BattleArenaLobby_EventScript_255FAC
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	copyvar VAR_0x8006, VAR_RESULT
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattleArenaLobby_Text_256573, MSGBOX_DEFAULT
	fadescreen 1
	call BattleFrontier_BattleArenaLobby_EventScript_23F2B7
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, 3
	special sub_80F9490
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleArenaLobby_EventScript_255FF8
	msgbox BattleFrontier_BattleArenaLobby_Text_2564CE, MSGBOX_YESNO
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_255FF8
	case 1, BattleFrontier_BattleArenaLobby_EventScript_255EE8
	case 127, BattleFrontier_BattleArenaLobby_EventScript_255FF8

BattleFrontier_BattleArenaLobby_EventScript_255EE8:: @ 8255EE8
	setvar VAR_TEMP_0, 0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 4
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 0
	special CallBattleArenaFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 1
	special CallBattleArenaFunction
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 1
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleArenaLobby_EventScript_255FE1

BattleFrontier_BattleArenaLobby_EventScript_255F54:: @ 8255F54
	special SavePlayerParty
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattleArenaLobby_Text_2567E6, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	special CallFrontierUtilFunc
	compare VAR_RESULT, 0
	call_if_eq BattleFrontier_BattleArenaLobby_EventScript_256005
	compare VAR_RESULT, 1
	call_if_eq BattleFrontier_BattleArenaLobby_EventScript_256050
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR, 255, 9, 13
	setvar VAR_TEMP_0, 0
	waitstate
	end

BattleFrontier_BattleArenaLobby_EventScript_255F9F:: @ 8255F9F
	msgbox BattleFrontier_BattleArenaLobby_Text_25624C, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_255E0B

BattleFrontier_BattleArenaLobby_EventScript_255FAC:: @ 8255FAC
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_255FC7
	case 1, BattleFrontier_BattleArenaLobby_EventScript_255FD4

BattleFrontier_BattleArenaLobby_EventScript_255FC7:: @ 8255FC7
	msgbox BattleFrontier_BattleArenaLobby_Text_2566A8, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_256003

BattleFrontier_BattleArenaLobby_EventScript_255FD4:: @ 8255FD4
	msgbox BattleFrontier_BattleArenaLobby_Text_2565A5, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_256003

BattleFrontier_BattleArenaLobby_EventScript_255FE1:: @ 8255FE1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleArenaLobby_EventScript_255FFB

BattleFrontier_BattleArenaLobby_EventScript_255FF8:: @ 8255FF8
	special LoadPlayerParty

BattleFrontier_BattleArenaLobby_EventScript_255FFB:: @ 8255FFB
	msgbox BattleFrontier_BattleArenaLobby_Text_25621F, MSGBOX_DEFAULT

BattleFrontier_BattleArenaLobby_EventScript_256003:: @ 8256003
	release
	end

BattleFrontier_BattleArenaLobby_EventScript_256005:: @ 8256005
	applymovement 1, BattleFrontier_BattleArenaLobby_Movement_256034
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_256041
	waitmovement 0
	opendoor 2, 2
	waitdooranim
	applymovement 1, BattleFrontier_BattleArenaLobby_Movement_25603E
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_25604C
	waitmovement 0
	closedoor 2, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_256034: @ 8256034
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_25603E: @ 825603E
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_Movement_256041: @ 8256041
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_25604C: @ 825604C
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_EventScript_256050:: @ 8256050
	applymovement 1, BattleFrontier_BattleArenaLobby_Movement_25607F
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_256088
	waitmovement 0
	opendoor 11, 2
	waitdooranim
	applymovement 1, BattleFrontier_BattleArenaLobby_Movement_25603E
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_25604C
	waitmovement 0
	closedoor 11, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_25607F: @ 825607F
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_256088: @ 8256088
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

BattleFrontier_BattleArenaLobby_EventScript_256092:: @ 8256092
	lockall
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 3
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_2560A6:: @ 82560A6
	msgbox BattleFrontier_BattleArenaLobby_Text_256B5C, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_2560AF:: @ 82560AF
	msgbox BattleFrontier_BattleArenaLobby_Text_256BCB, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_2560B8:: @ 82560B8
	msgbox BattleFrontier_BattleArenaLobby_Text_256C19, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_2560C1:: @ 82560C1
	msgbox BattleFrontier_BattleArenaLobby_Text_256C9A, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_2560CA:: @ 82560CA
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_256DB8, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_2560D9
	end

BattleFrontier_BattleArenaLobby_EventScript_2560D9:: @ 82560D9
	message BattleFrontier_BattleArenaLobby_Text_256DDF
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_ARENA_RULES, 0
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_25612C
	case 1, BattleFrontier_BattleArenaLobby_EventScript_25613A
	case 2, BattleFrontier_BattleArenaLobby_EventScript_256148
	case 3, BattleFrontier_BattleArenaLobby_EventScript_256156
	case 4, BattleFrontier_BattleArenaLobby_EventScript_256164
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_256164
	end

BattleFrontier_BattleArenaLobby_EventScript_25612C:: @ 825612C
	msgbox BattleFrontier_BattleArenaLobby_Text_256E02, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_2560D9
	end

BattleFrontier_BattleArenaLobby_EventScript_25613A:: @ 825613A
	msgbox BattleFrontier_BattleArenaLobby_Text_256F43, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_2560D9
	end

BattleFrontier_BattleArenaLobby_EventScript_256148:: @ 8256148
	msgbox BattleFrontier_BattleArenaLobby_Text_256FF2, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_2560D9
	end

BattleFrontier_BattleArenaLobby_EventScript_256156:: @ 8256156
	msgbox BattleFrontier_BattleArenaLobby_Text_257202, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_2560D9
	end

BattleFrontier_BattleArenaLobby_EventScript_256164:: @ 8256164
	releaseall
	end

BattleFrontier_BattleArenaLobby_Text_256166: @ 8256166
	.string "Bienvenue au DOJO DE COMBAT!\p"
	.string "Ici, nous mettons à l'épreuve\n"
	.string "le cran des DRESSEURS!\p"
	.string "Je serai votre guide pour le\n"
	.string "TOURNOI K.O.!$"

BattleFrontier_BattleArenaLobby_Text_2561EA: @ 82561EA
	.string "Voulez-vous relever le défi du\n"
	.string "DOJO DE COMBAT?$"

BattleFrontier_BattleArenaLobby_Text_25621F: @ 825621F
	.string "Nous espérons que vous relèverez\n"
	.string "bientôt notre défi!$"

BattleFrontier_BattleArenaLobby_Text_25624C: @ 825624C
	.string "Au DOJO DE COMBAT, vous participez à un\n"
	.string "TOURNOI K.O.\p"
	.string "Les participants s'inscrivent avec une\n"
	.string "équipe de trois POKéMON.\p"
	.string "Ces POKéMON doivent être placés dans\n"
	.string "l'ordre dans lequel ils apparaîtront.\p"
	.string "Pendant un combat, ils apparaîtront\n"
	.string "l'un après l'autre dans l'ordre\l"
	.string "prédéfini.\p"
	.string "Un POKéMON qui entre au combat doit\n"
	.string "y rester jusqu'à la fin.\p"
	.string "S'il n'y a pas de vainqueur au bout de\n"
	.string "trois tours, l'ARBITRE intervient.\p"
	.string "Si vous voulez interrompre le défi,\n"
	.string "veuillez sauvegarder la partie.\p"
	.string "Si vous ne sauvegardez pas, vous ne\n"
	.string "pourrez pas reprendre ce défi.\p"
	.string "Si vous mettez K.O. sept DRESSEURS\n"
	.string "à la suite, nous vous remettons des\l"
	.string "POINTS DE COMBAT.$"

BattleFrontier_BattleArenaLobby_Text_2564CE: @ 82564CE
	.string "Avant de me suivre dans le DOJO DE\n"
	.string "COMBAT, vous devez sauvegarder. OK?$"

BattleFrontier_BattleArenaLobby_Text_256513: @ 8256513
	.string "Au DOJO DE COMBAT, vous avez le choix\n"
	.string "entre niveau 50 et niveau libre.\l"
	.string "Que choisissez-vous?$"

BattleFrontier_BattleArenaLobby_Text_256573: @ 8256573
	.string "Veuillez choisir les trois POKéMON que\n"
	.string "vous souhaitez inscrire.$"

BattleFrontier_BattleArenaLobby_Text_2565A5: @ 82565A5
	.string "Je regrette, cher DRESSEUR!\p"
	.string "Vous n'avez pas trois POKéMON\n"
	.string "aptes à participer.\p"
	.string "Il vous faut trois POKéMON différents\n"
	.string "pour participer.\p"
	.string "Ils doivent aussi tenir des objets\n"
	.string "différents.\p"
	.string "Les OEUFS{STR_VAR_1} inaptes au combat.\p"
	.string "Revenez me voir quand vous aurez\n"
	.string "ce qu'il faut.$"

BattleFrontier_BattleArenaLobby_Text_2566A8: @ 82566A8
	.string "Je regrette, cher DRESSEUR!\p"
	.string "Vous n'avez pas trois POKéMON\n"
	.string "aptes à participer.\p"
	.string "Il vous faut trois POKéMON différents\n"
	.string "pour participer.\p"
	.string "Il vous faut trois POKéMON différents\n"
	.string "de niveau 50 ou moins pour participer.\p"
	.string "Ils doivent aussi tenir des objets\n"
	.string "différents.\p"
	.string "Les OEUFS{STR_VAR_1} inaptes au combat.\p"
	.string "Revenez me voir quand vous aurez\n"
	.string "ce qu'il faut.$"

BattleFrontier_BattleArenaLobby_Text_2567E6: @ 82567E6
	.string "Suivez-moi dans le DOJO DE COMBAT.$"

BattleFrontier_BattleArenaLobby_Text_256811: @ 8256811
	.string "Je regrette, cher DRESSEUR!\p"
	.string "Vous n'avez pas sauvegardé avant de\n"
	.string "quitter votre dernier défi.\p"
	.string "Dans ce cas, c'est la disqualification.\n"
	.string "Quel dommage!\p"
	.string "Bien entendu, vous pouvez recommencer\n"
	.string "un autre défi.$"

BattleFrontier_BattleArenaLobby_Text_2568E7: @ 82568E7
	.string "Toutes mes félicitations! Vous avez\n"
	.string "battu sept DRESSEURS à la suite!$"

BattleFrontier_BattleArenaLobby_Text_256931: @ 8256931
	.string "Votre performance va être sauvegardée.\n"
	.string "Veuillez patienter.$"

BattleFrontier_BattleArenaLobby_Text_256977: @ 8256977
	.string "In commemoration of your 7-win streak,\n"
	.string "we present you with this prize.$"

BattleFrontier_BattleArenaLobby_Text_2569BE: @ 82569BE
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleArenaLobby_Text_2569D8: @ 82569D8
	.string "Oh?\n"
	.string "Your BAG seems to be full.\p"
	.string "I urge you to clear space and\n"
	.string "return for your prize.$"

BattleFrontier_BattleArenaLobby_Text_256A2C: @ 8256A2C
	.string "Merci d'avoir participé!\p"
	.string "Votre résultat va être sauvegardé.\n"
	.string "Veuillez patienter.$"

BattleFrontier_BattleArenaLobby_Text_256A74: @ 8256A74
	.string "J'espère vous revoir bientôt au DOJO DE\n"
	.string "COMBAT.$"

BattleFrontier_BattleArenaLobby_Text_256AA1: @ 8256AA1
	.string "Nous vous attendions!\p"
	.string "Vous devez sauvegarder avant de me\n"
	.string "suivre dans le DOJO DE COMBAT.\l"
	.string "Veuillez patienter.$"

BattleFrontier_BattleArenaLobby_Text_256B19: @ 8256B19
	.string "J'enregistre votre dernier combat au\n"
	.string "DOJO DE COMBAT sur votre PASSE ZONE?$"

BattleFrontier_BattleArenaLobby_Text_256B5C: @ 8256B5C
	.string "J'ai perdu sur décision de l'ARBITRE…\n"
	.string "J'aurais dû attaquer…\p"
	.string "Mais je n'ai utilisé que des capacités\n"
	.string "défensives…$"

BattleFrontier_BattleArenaLobby_Text_256BCB: @ 8256BCB
	.string "J'ai gagné sur décision de l'ARBITRE!\p"
	.string "Je n'ai pas arrêté de porter des coups\n"
	.string "et ça lui a plu!$"

BattleFrontier_BattleArenaLobby_Text_256C19: @ 8256C19
	.string "Le combat a été déclaré nul.\p"
	.string "Il ne restait plus de temps et mes\n"
	.string "POKéMON et ceux de l'adversaire\l"
	.string "avaient le même niveau de PV.$"

BattleFrontier_BattleArenaLobby_Text_256C9A: @ 8256C9A
	.string "Dans le DOJO DE COMBAT, l'ordre\n"
	.string "des POKéMON est très important.\p"
	.string "Si ton premier POKéMON a certains\n"
	.string "points faibles liés à son type, ton\l"
	.string "deuxième POKéMON doit les compenser,\l"
	.string "par exemple.\p"
	.string "Ça permet de créer une équipe efficace.$"

BattleFrontier_BattleArenaLobby_Text_256DB8: @ 8256DB8
FallarborTown_BattleTentLobby_Text_256DB8: @ 8256DB8
	.string "Règles du TOURNOI K.O.$"

BattleFrontier_BattleArenaLobby_Text_256DDF: @ 8256DDF
FallarborTown_BattleTentLobby_Text_256DDF: @ 8256DDF
	.string "Quel chapitre voulez-vous lire?$"

BattleFrontier_BattleArenaLobby_Text_256E02: @ 8256E02
FallarborTown_BattleTentLobby_Text_256E02: @ 8256E02
	.string "Le TOURNOI K.O. n'a pas les mêmes règles\n"
	.string "que les combats normaux.\p"
	.string "Tout d'abord, un combat ne dure que\n"
	.string "trois tours.\p"
	.string "S'il n'y a pas de vainqueur au bout de\n"
	.string "trois tours, l'ARBITRE intervient.\p"
	.string "L'ARBITRE basera son choix sur la façon\n"
	.string "dont les POKéMON ont combattu.\p"
	.string "Aussi, un POKéMON qui entre au combat\n"
	.string "doit y rester jusqu'à la fin.$"

BattleFrontier_BattleArenaLobby_Text_256F43: @ 8256F43
FallarborTown_BattleTentLobby_Text_256F43: @ 8256F43
	.string "Le premier critère de jugement\n"
	.string "est le “mental”.\l"
	.string "C'est l'agressivité des concurrents.\p"
	.string "Cela dépend du nombre de capacités\n"
	.string "offensives qui ont été utilisées.$"

BattleFrontier_BattleArenaLobby_Text_256FF2: @ 8256FF2
FallarborTown_BattleTentLobby_Text_256FF2: @ 8256FF2
	.string "Le second critère de jugement est\n"
	.string "la “technique”.\l"
	.string "C'est l'efficacité avec laquelle les\l"
	.string "POKéMON utilisent leurs capacités.\p"
	.string "Si une capacité est réussie, le\n"
	.string "niveau de technique augmente.\p"
	.string "Si une capacité a échoué, le niveau de\n"
	.string "technique diminue.\p"
	.string "Pour une capacité offensive, le niveau\n"
	.string "de technique augmente si la capacité\l"
	.string "est “super efficace” et diminue\l"
	.string "si elle n'est “pas très efficace”.\p"
	.string "Les capacités telles qu'ABRI et\n"
	.string "DETECTION ne comptent pas.\p"
	.string "Si l'adversaire a utilisé ABRI ou\n"
	.string "DETECTION et que l'attaque de votre\l"
	.string "POKéMON n'a pas pu l'atteindre, son\l"
	.string "niveau de technique ne descend pas.$"

BattleFrontier_BattleArenaLobby_Text_257202: @ 8257202
FallarborTown_BattleTentLobby_Text_257202: @ 8257202
	.string "Le troisième critère de jugement est\n"
	.string "le “physique”.\l"
	.string "Il dépend du nombre de PV restant\l"
	.string "à la fin du combat.\p"
	.string "Cela prend en compte les PV que le\n"
	.string "POKéMON avait au début et ceux qui\l"
	.string "lui restent à la fin.$"

BattleFrontier_BattleArenaLobby_Text_2572D9: @ 82572D9
	.string "Vous avez arraché la victoire à la\n"
	.string "PRO DU DOJO et battu sept DRESSEURS!\p"
	.string "Félicitations pour cette magnifique\n"
	.string "performance!$"

BattleFrontier_BattleArenaLobby_Text_257353: @ 8257353
	.string "Cher DRESSEUR, votre cran vous\n"
	.string "rapporte des POINTS DE COMBAT.$"
