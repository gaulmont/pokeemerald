SlateportCity_Harbor_MapScripts:: @ 820C97D
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_Harbor_OnTransition
	.byte 0

SlateportCity_Harbor_OnTransition: @ 820C983
	setescapewarp MAP_SLATEPORT_CITY, 255, 28, 13
	setvar VAR_TEMP_1, 0
	compare VAR_SLATEPORT_HARBOR_STATE, 1
	call_if_eq SlateportCity_Harbor_EventScript_20C9A9
	call_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_20C9A5
	end

SlateportCity_Harbor_EventScript_20C9A5:: @ 820C9A5
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
	return

SlateportCity_Harbor_EventScript_20C9A9:: @ 820C9A9
	savebgm MUS_AQA_0
	setobjectxyperm 4, 12, 13
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_LEFT
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	return

SlateportCity_Harbor_EventScript_20C9BB:: @ 820C9BB
	lockall
	setvar VAR_0x8008, 0
	goto SlateportCity_Harbor_EventScript_20C9F5
	end

SlateportCity_Harbor_EventScript_20C9C7:: @ 820C9C7
	lockall
	setvar VAR_0x8008, 1
	goto SlateportCity_Harbor_EventScript_20C9F5
	end

SlateportCity_Harbor_EventScript_20C9D3:: @ 820C9D3
	lockall
	setvar VAR_0x8008, 2
	goto SlateportCity_Harbor_EventScript_20C9F5
	end

SlateportCity_Harbor_EventScript_20C9DF:: @ 820C9DF
	lockall
	setvar VAR_0x8008, 3
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_Harbor_Movement_20CAEF
	waitmovement 0
	goto SlateportCity_Harbor_EventScript_20C9F5
	end

SlateportCity_Harbor_EventScript_20C9F5:: @ 820C9F5
	applymovement 7, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	applymovement 6, Common_Movement_WalkInPlaceFastestDown
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox SlateportCity_Harbor_Text_20D291, MSGBOX_DEFAULT
	closemessage
	applymovement 6, SlateportCity_Harbor_Movement_20CAC8
	applymovement 7, SlateportCity_Harbor_Movement_20CAC8
	applymovement 8, SlateportCity_Harbor_Movement_20CAD2
	waitmovement 0
	removeobject 6
	removeobject 7
	removeobject 8
	setvar VAR_SLATEPORT_HARBOR_STATE, 2
	setflag FLAG_MET_TEAM_AQUA_HARBOR
	setflag FLAG_HIDE_LILCOVE_MOTEL_SCOTT
	compare VAR_0x8008, 0
	call_if_eq SlateportCity_Harbor_EventScript_20CA89
	compare VAR_0x8008, 1
	call_if_eq SlateportCity_Harbor_EventScript_20CA9E
	compare VAR_0x8008, 2
	call_if_eq SlateportCity_Harbor_EventScript_20CAB3
	compare VAR_0x8008, 3
	call_if_eq SlateportCity_Harbor_EventScript_20CAB3
	msgbox SlateportCity_Harbor_Text_20D35A, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE
	copyobjectxytoperm 4
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_RIGHT
	releaseall
	end

SlateportCity_Harbor_EventScript_20CA89:: @ 820CA89
	applymovement 4, SlateportCity_Harbor_Movement_20CAE0
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_20CA9E:: @ 820CA9E
	applymovement 4, SlateportCity_Harbor_Movement_20CAE6
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_20CAB3:: @ 820CAB3
	applymovement 4, SlateportCity_Harbor_Movement_20CAEB
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

SlateportCity_Harbor_Movement_20CAC8: @ 820CAC8
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

SlateportCity_Harbor_Movement_20CACD: @ 820CACD
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

SlateportCity_Harbor_Movement_20CAD2: @ 820CAD2
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SlateportCity_Harbor_Movement_20CAE0: @ 820CAE0
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

SlateportCity_Harbor_Movement_20CAE6: @ 820CAE6
	walk_left
	walk_left
	walk_up
	walk_left
	step_end

SlateportCity_Harbor_Movement_20CAEB: @ 820CAEB
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Harbor_Movement_20CAEF: @ 820CAEF
	walk_up
	step_end

SlateportCity_Harbor_EventScript_20CAF1:: @ 820CAF1
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_20CB06
	msgbox SlateportCity_Harbor_Text_20CE20, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_20CB06:: @ 820CB06
	msgbox SlateportCity_Harbor_Text_20CE87, MSGBOX_DEFAULT
	message SlateportCity_Harbor_Text_20CF1C
	waitmessage
	goto SlateportCity_Harbor_EventScript_20CB1A
	end

SlateportCity_Harbor_EventScript_20CB1A:: @ 820CB1A
	goto_if_set FLAG_MET_SCOTT_ON_SS_TIDAL, SlateportCity_Harbor_EventScript_20CB50
	multichoicedefault 18, 8, MULTI_SSTIDAL_SLATEPORT_NO_BF, 2, 0
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_20CB92
	case 1, SlateportCity_Harbor_EventScript_20CC2D
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_20CC2D
	end

SlateportCity_Harbor_EventScript_20CB50:: @ 820CB50
	multichoicedefault 17, 6, MULTI_SSTIDAL_SLATEPORT_WITH_BF, 2, 0
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_20CB92
	case 1, SlateportCity_Harbor_EventScript_20CBBA
	case 2, SlateportCity_Harbor_EventScript_20CC2D
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_20CC2D
	end

SlateportCity_Harbor_EventScript_20CB88:: @ 820CB88
	msgbox SlateportCity_Harbor_Text_20CEC1, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_20CB92:: @ 820CB92
	msgbox SlateportCity_Harbor_Text_20CF93, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_Harbor_EventScript_20CBDD
	setvar VAR_PORTHOLE_STATE, 1
	call SlateportCity_Harbor_EventScript_20CBE9
	warp MAP_SS_TIDAL_CORRIDOR, 255, 1, 10
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_20CBBA:: @ 820CBBA
	msgbox SlateportCity_Harbor_Text_20CFAE, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_Harbor_EventScript_20CBDD
	call SlateportCity_Harbor_EventScript_20CBE9
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 255, 19, 67
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_20CBDD:: @ 820CBDD
	message SlateportCity_Harbor_Text_20CFFA
	waitmessage
	goto SlateportCity_Harbor_EventScript_20CB1A
	end

SlateportCity_Harbor_EventScript_20CBE9:: @ 820CBE9
	msgbox SlateportCity_Harbor_Text_20CFCB, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_SLATEPORT_CITY_HARBOR
	compare VAR_FACING, DIR_NORTH
	call_if_eq SlateportCity_Harbor_EventScript_20CC42
	compare VAR_FACING, DIR_EAST
	call_if_eq SlateportCity_Harbor_EventScript_20CC37
	delay 30
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_PETALBURG_CITY
	setvar VAR_0x8004, 5
	call Common_EventScript_FerryDepart
	return

SlateportCity_Harbor_EventScript_20CC2D:: @ 820CC2D
	msgbox SlateportCity_Harbor_Text_20CF71, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_20CC37:: @ 820CC37
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_Harbor_Movement_20CC4D
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_20CC42:: @ 820CC42
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_Harbor_Movement_20CC50
	waitmovement 0
	return

SlateportCity_Harbor_Movement_20CC4D: @ 820CC4D
	walk_right
	walk_in_place_fastest_up
	step_end

SlateportCity_Harbor_Movement_20CC50: @ 820CC50
	walk_up
	step_end

SlateportCity_Harbor_EventScript_20CC52:: @ 820CC52
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_20CC89
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, SlateportCity_Harbor_EventScript_20CC93
	call_if_set FLAG_DEFEATED_GROUDON, SlateportCity_Harbor_EventScript_20CC93
	compare VAR_0x8004, 2
	goto_if_eq SlateportCity_Harbor_EventScript_20CC89
	msgbox SlateportCity_Harbor_Text_20D08E, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_20CC89:: @ 820CC89
	msgbox SlateportCity_Harbor_Text_20D01C, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_20CC93:: @ 820CC93
	addvar VAR_0x8004, 1
	return

SlateportCity_Harbor_EventScript_20CC99:: @ 820CC99
	msgbox SlateportCity_Harbor_Text_20D194, MSGBOX_NPC
	end

SlateportCity_Harbor_EventScript_20CCA2:: @ 820CCA2
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, SlateportCity_Harbor_EventScript_20CD00
	goto_if_set FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE, SlateportCity_Harbor_EventScript_20CCF6
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, SlateportCity_Harbor_EventScript_20CCE9
	compare VAR_SLATEPORT_HARBOR_STATE, 2
	goto_if_eq SlateportCity_Harbor_EventScript_20CCDF
	msgbox SlateportCity_Harbor_Text_20D232, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Harbor_EventScript_20CCDF:: @ 820CCDF
	msgbox SlateportCity_Harbor_Text_20D35A, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_20CCE9:: @ 820CCE9
	setflag FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE
	msgbox SlateportCity_Harbor_Text_20D42B, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_20CCF6:: @ 820CCF6
	msgbox SlateportCity_Harbor_Text_20D58A, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_20CD00:: @ 820CD00
	compare VAR_TEMP_1, 1
	goto_if_eq SlateportCity_Harbor_EventScript_20CE11
	checkitem ITEM_SCANNER, 1
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_Harbor_EventScript_20CD38
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_20CD2E
	msgbox SlateportCity_Harbor_Text_20D65C, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_20CD2E:: @ 820CD2E
	msgbox SlateportCity_Harbor_Text_20D6CB, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_20CD38:: @ 820CD38
	message SlateportCity_Harbor_Text_20D76C
	waitmessage
	goto SlateportCity_Harbor_EventScript_20CD44
	end

SlateportCity_Harbor_EventScript_20CD44:: @ 820CD44
	multichoice 0, 0, MULTI_STERN_DEEPSEA, 0
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_20CD7B
	case 1, SlateportCity_Harbor_EventScript_20CDBB
	case 2, SlateportCity_Harbor_EventScript_20CDFB
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_20CDFB
	end

SlateportCity_Harbor_EventScript_20CD7B:: @ 820CD7B
	msgbox SlateportCity_Harbor_Text_20D8BC, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_Harbor_EventScript_20CE05
	giveitem_std ITEM_DEEP_SEA_TOOTH
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	takeitem ITEM_SCANNER, 1
	msgbox SlateportCity_Harbor_Text_20D94A, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_20CE11
	end

SlateportCity_Harbor_EventScript_20CDBB:: @ 820CDBB
	msgbox SlateportCity_Harbor_Text_20D8F1, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_Harbor_EventScript_20CE05
	giveitem_std ITEM_DEEP_SEA_SCALE
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	takeitem ITEM_SCANNER, 1
	msgbox SlateportCity_Harbor_Text_20D94A, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_20CE11
	end

SlateportCity_Harbor_EventScript_20CDFB:: @ 820CDFB
	msgbox SlateportCity_Harbor_Text_20D841, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_20CE05:: @ 820CE05
	message SlateportCity_Harbor_Text_20D926
	waitmessage
	goto SlateportCity_Harbor_EventScript_20CD44
	end

SlateportCity_Harbor_EventScript_20CE11:: @ 820CE11
	setvar VAR_TEMP_1, 1
	msgbox SlateportCity_Harbor_Text_20D970, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_Text_20CE20: @ 820CE20
	.string "Je vous demande pardon?\n"
	.string "Vous cherchez un bateau?\p"
	.string "Désolée, vous ne pouvez pas embarquer\n"
	.string "sur le ferry pour le moment.$"

SlateportCity_Harbor_Text_20CE87: @ 820CE87
	.string "Bonjour. C'est pour le ferry?\n"
	.string "Puis-je voir votre PASSE BATEAU?$"


SlateportCity_Harbor_Text_20CEC1: @ 820CEC1
	.string "{PLAYER} n'a pas le PASSE BATEAU…\p"
	.string "Je suis désolée.\p"
	.string "Il vous faut un PASSE BATEAU pour\n"
	.string "embarquer sur le ferry.$"

SlateportCity_Harbor_Text_20CF1C: @ 820CF1C
	.string "{PLAYER} montre le PASSE BATEAU…\p"
	.string "Parfait! Tout y est!\p"
	.string "Et où souhaitez-vous aller?$"

SlateportCity_Harbor_Text_20CF71: @ 820CF71
	.string "Revenez une autre fois!$"

SlateportCity_Harbor_Text_20CF93: @ 820CF93
	.string "Alors, cap sur NENUCRIQUE?$"

SlateportCity_Harbor_Text_20CFAE: @ 820CFAE
	.string "Cap sur la ZONE DE COMBAT!$"

SlateportCity_Harbor_Text_20CFCB: @ 820CFCB
	.string "Veuillez monter sur le ferry et\n"
	.string "attendre le départ.$"

SlateportCity_Harbor_Text_20CFFA: @ 820CFFA
	.string "Alors, où souhaiteriez-vous aller?$"

SlateportCity_Harbor_Text_20D01C: @ 820D01C
	.string "Un voyage au fond de la mer…\n"
	.string "Je me demande comment c'est.\p"
	.string "Un jour, j'aimerais bien aller comme ça,\n"
	.string "dans les profondeurs de la mer.$"

SlateportCity_Harbor_Text_20D08E: @ 820D08E
	.string "Pour appareiller en toute sécurité,\n"
	.string "nous devons d'abord consulter la météo!\p"
	.string "En parlant de ça, j'ai appris quelque\n"
	.string "chose d'une personne travaillant\l"
	.string "au CENTRE METEO.\p"
	.string "Des changements climatiques\n"
	.string "importants auraient été reportés\l"
	.string "un peu partout!\p"
	.string "Tu devrais aller faire un tour au\n"
	.string "CENTRE METEO et te renseigner!$"

SlateportCity_Harbor_Text_20D194: @ 820D194
	.string "Je voulais accompagner le CAPT. POUPE\n"
	.string "dans son exploration des fonds marins.\p"
	.string "Mais le sous-marin est trop petit.\p"
	.string "Si j'avais embarqué, il n'y aurait plus eu\n"
	.string "assez de place pour le CAPITAINE…$"

SlateportCity_Harbor_Text_20D232: @ 820D232
	.string "CAPT. POUPE: Ces brutes…\p"
	.string "Ce sont eux qui ont tenté de voler\n"
	.string "le PACK DEVON au MUSEE.$"

SlateportCity_Harbor_Text_20D291: @ 820D291
	.string "ARTHUR: Oh?\n"
	.string "Encore toi!\p"
	.string "Tu nous as suivis jusqu'ici! Tu\n"
	.string "n'abandonnes donc jamais?\p"
	.string "Mais maintenant…\n"
	.string "personne ne peut nous arrêter!\p"
	.string "Ou peut-être comptes-tu nous suivre\n"
	.string "dans notre PLANQUE à NENUCRIQUE?\p"
	.string "Ah, ah, ah, ah…$"

SlateportCity_Harbor_Text_20D35A: @ 820D35A
	.string "CAPT. POUPE: Pourquoi…\p"
	.string "Pourquoi la TEAM AQUA voudrait-elle\n"
	.string "voler mon SOUS-MARIN D'EXPLORATION 1?\p"
	.string "Ils ne peuvent pas s'intéresser au\n"
	.string "POKéMON qui sommeille au fond\l"
	.string "de l'océan…\p"
	.string "De toute façon, même si je voulais les\n"
	.string "poursuivre, je n'aurais aucune chance…$"

SlateportCity_Harbor_Text_20D42B: @ 820D42B
	.string "CAPT. POUPE: Oh, {PLAYER}{KUN}…\p"
	.string "Bon… Alors la TEAM AQUA s'est enfuie\n"
	.string "avant que tu ne puisses l'arrêter…\p"
	.string "Oh, non, tu n'as rien à te reprocher!\n"
	.string "Ce n'est pas de ta faute.\p"
	.string "Tenter de rattraper un sous-marin…\n"
	.string "C'est impossible pour beaucoup de gens.\p"
	.string "Il aurait fallu que tu aies un POKéMON\n"
	.string "connaissant PLONGEE…\p"
	.string "Si tu te rendais à ALGATIA,\n"
	.string "peut-être que…\p"
	.string "De nombreux plongeurs vivent là-bas,\n"
	.string "quelqu'un pourrait t'apprendre…$"

SlateportCity_Harbor_Text_20D58A: @ 820D58A
	.string "CAPT. POUPE: Tenter de rattraper un\n"
	.string "sous-marin… C'est impossible!\p"
	.string "Il aurait fallu que tu aies un POKéMON\n"
	.string "connaissant PLONGEE.\p"
	.string "Si tu te rendais à ALGATIA,\n"
	.string "peut-être que…\p"
	.string "De nombreux plongeurs vivent là-bas,\n"
	.string "quelqu'un pourrait t'apprendre…$"

SlateportCity_Harbor_Text_20D65C: @ 820D65C
	.string "CAPT. POUPE: Oh, oui.\n"
	.string "M. MARCO est passé au CHANTIER NAVAL.\p"
	.string "Ça ne va plus prendre très longtemps\n"
	.string "maintenant pour finir le ferry!$"

SlateportCity_Harbor_Text_20D6CB: @ 820D6CB
	.string "CAPT. POUPE: {PLAYER}{KUN}!\p"
	.string "On a enfin fini le ferry LE MARINA!\p"
	.string "On n'aurait jamais pu l'achever\n"
	.string "sans ton ami M. MARCO.\p"
	.string "Va donc faire une petite croisière!$"

SlateportCity_Harbor_Text_20D76C: @ 820D76C
	.string "CAPT. POUPE: Oh?\n"
	.string "{PLAYER}{KUN}, cet objet que tu as…\p"
	.string "C'est un SCANNER! Ça nous aiderait\n"
	.string "certainement pour nos explorations.\p"
	.string "{PLAYER}{KUN}, certainement pour nos explorations\n"
	.string "SCANNER contre autre chose?\p"
	.string "Comme, disons, une DENT OCEAN\n"
	.string "ou une ECAILLEOCEAN par exemple?$"

SlateportCity_Harbor_Text_20D841: @ 820D841
	.string "CAPT. POUPE: C'est sûr?\n"
	.string "Ça ne te sert à rien, {PLAYER}{KUN}…\p"
	.string "Bon, d'accord alors. Si tu veux échanger\n"
	.string "ton SCANNER, fais-moi signe!$"

SlateportCity_Harbor_Text_20D8BC: @ 820D8BC
	.string "CAPT. POUPE: Tu veux bien l'échanger\n"
	.string "contre ma DENT OCEAN?$"

SlateportCity_Harbor_Text_20D8F1: @ 820D8F1
	.string "CAPT. POUPE: Tu veux bien l'échanger\n"
	.string "contre mon ECAILLEOCEAN?$"

SlateportCity_Harbor_Text_20D926: @ 820D926
	.string "CAPT. POUPE: Lequel veux-tu?$"

SlateportCity_Harbor_Text_20D94A: @ 820D94A
	.string "{PLAYER} remet le SCANNER au\n"
	.string "CAPT. POUPE.$"

SlateportCity_Harbor_Text_20D970: @ 820D970
	.string "CAPT. POUPE: Merci, {PLAYER}{KUN}!\n"
	.string "Ça va nous aider dans nos recherches!$"