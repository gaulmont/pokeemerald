LilycoveCity_MapScripts:: @ 81E2B3C
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_MapScript1_1E2B61
	.byte 0

LilycoveCity_OnTransition: @ 81E2B47
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_LINK_CONTEST_ROOM_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetWeather15
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_MapScript1_1E2B61: @ 81E2B61
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_1E2B6B
	end

LilycoveCity_EventScript_1E2B6B:: @ 81E2B6B
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, 1
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, 1
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, 1
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, 1
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, 1
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, 1
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, 1
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, 1
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, 1
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, 1
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, 1
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, 1
	return

LilycoveCity_EventScript_1E2BD8:: @ 81E2BD8
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_1E2C18
	msgbox LilycoveCity_Text_2A7244, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem_std VAR_RESULT
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_2A72E3, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_1E2C18:: @ 81E2C18
	msgbox LilycoveCity_Text_2A7321, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_1E2C22:: @ 81E2C22
	msgbox LilycoveCity_Text_1E3D9E, MSGBOX_NPC
	end

LilycoveCity_EventScript_1E2C2B:: @ 81E2C2B
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_1E2C40
	msgbox LilycoveCity_Text_1E3E3C, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_1E2C40:: @ 81E2C40
	msgbox LilycoveCity_Text_1E3E7D, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_1E2C4A:: @ 81E2C4A
	msgbox LilycoveCity_Text_1E3F05, MSGBOX_NPC
	end

LilycoveCity_EventScript_1E2C53:: @ 81E2C53
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_1E2C68
	msgbox LilycoveCity_Text_1E3FAB, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_1E2C68:: @ 81E2C68
	msgbox LilycoveCity_Text_1E4020, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_1E2C72:: @ 81E2C72
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_1E2C87
	msgbox LilycoveCity_Text_1E40AD, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_1E2C87:: @ 81E2C87
	msgbox LilycoveCity_Text_1E4145, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_1E2C91:: @ 81E2C91
	msgbox LilycoveCity_Text_1E417B, MSGBOX_NPC
	end

LilycoveCity_EventScript_1E2C9A:: @ 81E2C9A
	msgbox LilycoveCity_Text_1E420B, MSGBOX_SIGN
	end

LilycoveCity_EventScript_1E2CA3:: @ 81E2CA3
	msgbox LilycoveCity_Text_1E4283, MSGBOX_SIGN
	end

LilycoveCity_EventScript_1E2CAC:: @ 81E2CAC
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_1E2CC1
	msgbox LilycoveCity_Text_1E42FC, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_1E2CC1:: @ 81E2CC1
	msgbox LilycoveCity_Text_1E43FF, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_1E2CCB:: @ 81E2CCB
	msgbox LilycoveCity_Text_1E48A5, MSGBOX_NPC
	end

LilycoveCity_EventScript_1E2CD4:: @ 81E2CD4
	msgbox LilycoveCity_Text_1E4902, MSGBOX_NPC
	end

LilycoveCity_EventScript_1E2CDD:: @ 81E2CDD
	lockall
	msgbox LilycoveCity_Text_1E494D, MSGBOX_NPC
	applymovement 20, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_1E2CEE:: @ 81E2CEE
	lockall
	msgbox LilycoveCity_Text_1E49F4, MSGBOX_NPC
	applymovement 19, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_1E2CFF:: @ 81E2CFF
	msgbox LilycoveCity_Text_1E448B, MSGBOX_SIGN
	end

LilycoveCity_EventScript_1E2D08:: @ 81E2D08
	msgbox LilycoveCity_Text_1E44C3, MSGBOX_SIGN
	end

LilycoveCity_EventScript_1E2D11:: @ 81E2D11
	msgbox LilycoveCity_Text_1E44FC, MSGBOX_SIGN
	end

LilycoveCity_EventScript_1E2D1A:: @ 81E2D1A
	lockall
	specialvar VAR_0x8004, CountPlayerContestPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_1E2D3A
	msgbox LilycoveCity_Text_1E4571, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_1E2D3A:: @ 81E2D3A
	msgbox LilycoveCity_Text_1E4534, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_1E2D44:: @ 81E2D44
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_1E2D58
	msgbox LilycoveCity_Text_1E45A7, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_1E2D58:: @ 81E2D58
	msgbox LilycoveCity_Text_1E4624, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_1E2D62:: @ 81E2D62
	msgbox LilycoveCity_Text_1E466E, MSGBOX_SIGN
	end

LilycoveCity_EventScript_1E2D6B:: @ 81E2D6B
	msgbox LilycoveCity_Text_1E46BE, MSGBOX_SIGN
	end

LilycoveCity_EventScript_1E2D74:: @ 81E2D74
	msgbox LilycoveCity_Text_1E473D, MSGBOX_SIGN
	end

LilycoveCity_EventScript_1E2D7D:: @ 81E2D7D
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_1E2DB0
	msgbox LilycoveCity_Text_1E3D1F, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_1E3D4A, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_1E2DB0:: @ 81E2DB0
	msgbox LilycoveCity_Text_1E3D1F, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_1E2DBA:: @ 81E2DBA
	msgbox LilycoveCity_Text_1E3B2C, MSGBOX_NPC
	end

LilycoveCity_EventScript_1E2DC3:: @ 81E2DC3
	msgbox LilycoveCity_Text_1E3B95, MSGBOX_NPC
	end

LilycoveCity_EventScript_1E2DCC:: @ 81E2DCC
	msgbox LilycoveCity_Text_1E3C46, MSGBOX_NPC
	end

LilycoveCity_EventScript_1E2DD5:: @ 81E2DD5
	msgbox LilycoveCity_Text_1E3CBE, MSGBOX_NPC
	end

LilycoveCity_EventScript_1E2DDE:: @ 81E2DDE
	lock
	faceplayer
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LilycoveCity_EventScript_1E2DF8
	compare VAR_RESULT, FEMALE
	goto_if_eq LilycoveCity_EventScript_1E2E6B
	end

LilycoveCity_EventScript_1E2DF8:: @ 81E2DF8
	playbgm MUS_GIRL_SUP, 1
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_1E2E48
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_1E2E51
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_EventScript_1E2E5A
	msgbox LilycoveCity_Text_1E3234, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_1E2EDE
	case 1, LilycoveCity_EventScript_1E2EEE
	case 2, LilycoveCity_EventScript_1E2EFE
	end

LilycoveCity_EventScript_1E2E48:: @ 81E2E48
	msgbox LilycoveCity_Text_1E31F5, MSGBOX_YESNO
	return

LilycoveCity_EventScript_1E2E51:: @ 81E2E51
	msgbox LilycoveCity_Text_1E3061, MSGBOX_YESNO
	return

LilycoveCity_EventScript_1E2E5A:: @ 81E2E5A
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_1E318D, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_1E2E6B:: @ 81E2E6B
	playbgm MUS_BOY_SUP, 1
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_1E2EBB
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_1E2EC4
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_EventScript_1E2ECD
	msgbox LilycoveCity_Text_1E373C, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_1E2F0E
	case 1, LilycoveCity_EventScript_1E2F1E
	case 2, LilycoveCity_EventScript_1E2F2E
	end

LilycoveCity_EventScript_1E2EBB:: @ 81E2EBB
	msgbox LilycoveCity_Text_1E36FA, MSGBOX_YESNO
	return

LilycoveCity_EventScript_1E2EC4:: @ 81E2EC4
	msgbox LilycoveCity_Text_1E3608, MSGBOX_YESNO
	return

LilycoveCity_EventScript_1E2ECD:: @ 81E2ECD
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_1E36BF, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_1E2EDE:: @ 81E2EDE
	trainerbattle_no_intro TRAINER_MAY_12, LilycoveCity_Text_1E3275
	goto LilycoveCity_EventScript_1E2F3E
	end

LilycoveCity_EventScript_1E2EEE:: @ 81E2EEE
	trainerbattle_no_intro TRAINER_MAY_13, LilycoveCity_Text_1E3275
	goto LilycoveCity_EventScript_1E2F3E
	end

LilycoveCity_EventScript_1E2EFE:: @ 81E2EFE
	trainerbattle_no_intro TRAINER_MAY_11, LilycoveCity_Text_1E3275
	goto LilycoveCity_EventScript_1E2F3E
	end

LilycoveCity_EventScript_1E2F0E:: @ 81E2F0E
	trainerbattle_no_intro TRAINER_BRENDAN_14, LilycoveCity_Text_1E3777
	goto LilycoveCity_EventScript_1E2FAA
	end

LilycoveCity_EventScript_1E2F1E:: @ 81E2F1E
	trainerbattle_no_intro TRAINER_BRENDAN_15, LilycoveCity_Text_1E3777
	goto LilycoveCity_EventScript_1E2FAA
	end

LilycoveCity_EventScript_1E2F2E:: @ 81E2F2E
	trainerbattle_no_intro TRAINER_BRENDAN_13, LilycoveCity_Text_1E3777
	goto LilycoveCity_EventScript_1E2FAA
	end

LilycoveCity_EventScript_1E2F3E:: @ 81E2F3E
	msgbox LilycoveCity_Text_1E32FB, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_1E2F76
	compare VAR_RESULT, 0
	call_if_eq LilycoveCity_EventScript_1E2F86
	compare VAR_RESULT, 1
	call_if_eq LilycoveCity_EventScript_1E2F8F
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_1E3006
	end

LilycoveCity_EventScript_1E2F76:: @ 81E2F76
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_1E2F80
	return

LilycoveCity_EventScript_1E2F80:: @ 81E2F80
	setvar VAR_RESULT, 1
	return

LilycoveCity_EventScript_1E2F86:: @ 81E2F86
	msgbox LilycoveCity_Text_1E3398, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_1E2F8F:: @ 81E2F8F
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_1E2FA1
	msgbox LilycoveCity_Text_1E346D, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_1E2FA1:: @ 81E2FA1
	msgbox LilycoveCity_Text_1E353A, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_1E2FAA:: @ 81E2FAA
	msgbox LilycoveCity_Text_1E37D7, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_1E2F76
	compare VAR_RESULT, 0
	call_if_eq LilycoveCity_EventScript_1E2FE2
	compare VAR_RESULT, 1
	call_if_eq LilycoveCity_EventScript_1E2FEB
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_1E3006
	end

LilycoveCity_EventScript_1E2FE2:: @ 81E2FE2
	msgbox LilycoveCity_Text_1E3876, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_1E2FEB:: @ 81E2FEB
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_1E2FFD
	msgbox LilycoveCity_Text_1E390C, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_1E2FFD:: @ 81E2FFD
	msgbox LilycoveCity_Text_1E39E3, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_1E3006:: @ 81E3006
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_1E302D:: @ 81E302D
	lock
	faceplayer
	msgbox LilycoveCity_Text_1E4774, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_eq LilycoveCity_EventScript_1E304F
	compare VAR_RESULT, 0
	call_if_eq LilycoveCity_EventScript_1E3058
	release
	end

LilycoveCity_EventScript_1E304F:: @ 81E304F
	msgbox LilycoveCity_Text_1E47A1, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_1E3058:: @ 81E3058
	msgbox LilycoveCity_Text_1E4824, MSGBOX_DEFAULT
	return

LilycoveCity_Text_1E3061: @ 81E3061
	.string "FLORA: Oh, hé?\n"
	.string "{PLAYER}{KUN}, toi aussi tu fais tes achats?\p"
	.string "J'ai acheté tout un tas de POUPEES\n"
	.string "et de POSTERS.\p"
	.string "Bien sûr, j'ai aussi attrapé plein de\n"
	.string "POKéMON, et je les entraîne\l"
	.string "correctement aussi.\p"
	.string "En fait, j'aimerais plutôt savoir si toi,\n"
	.string "{PLAYER}{KUN}, tu dresses bien tes POKéMON.\p"
	.string "Je vais me battre contre toi pour que\n"
	.string "tu me montres tes POKéMON, {PLAYER}{KUN}.$"

LilycoveCity_Text_1E318D: @ 81E318D
	.string "FLORA: Quoi? {PLAYER}{KUN}, tu n'avais\n"
	.string "pas dressé tes POKéMON?\p"
	.string "Ce n'est pas une très bonne\n"
	.string "performance pour un DRESSEUR…$"

LilycoveCity_Text_1E31F5: @ 81E31F5
	.string "FLORA: Viens te battre que je puisse\n"
	.string "voir ce que valent tes POKéMON!$"

LilycoveCity_Text_1E3234: @ 81E3234
	.string "FLORA: Tes POKéMON ne pourront pas\n"
	.string "battre ceux que j'ai élevés, {PLAYER}{KUN}!$"

LilycoveCity_Text_1E3275: @ 81E3275
	.string "… … … … … … … …\p"
	.string "Je me rappelle, {PLAYER}{KUN}, à la fois où on\n"
	.string "a combattu sur la ROUTE 103.\p"
	.string "Ce combat, {PLAYER}{KUN}, t'a permis de\n"
	.string "progresser, n'est-ce pas?$"

LilycoveCity_Text_1E32FB: @ 81E32FB
	.string "FLORA: Je pense que je vais bientôt\n"
	.string "rentrer à BOURG-EN-VOL.\p"
	.string "J'ai attrapé un bon nombre de POKéMON,\n"
	.string "et mon POKéDEX se remplit, alors je vais\l"
	.string "montrer tout ça à mon papa.$"

LilycoveCity_Text_1E3398: @ 81E3398
	.string "{PLAYER}{KUN}, que vas-tu faire?\p"
	.string "Rassembler tous les BADGES et relever\n"
	.string "le défi de la LIGUE POKéMON?\p"
	.string "{PLAYER}{KUN}, pendant que tu rassembles\n"
	.string "les BADGES, je continue à remplir\l"
	.string "mon.!\n"
	.string "J'aurai fini avant toi!\p"
	.string "A plus tard!$"

LilycoveCity_Text_1E346D: @ 81E346D
	.string "{PLAYER}{KUN}, que vas-tu faire?\p"
	.string "Vas-tu relever le défi de la LIGUE\n"
	.string "POKéMON?\p"
	.string "ou vas-tu plutôt remplir ton\n"
	.string "POKéDEX?\p"
	.string "Tu as peut-être gagné le combat, mais\n"
	.string "je complèterai mon POKéDEX avant toi!\p"
	.string "A plus tard!$"

LilycoveCity_Text_1E353A: @ 81E353A
	.string "{PLAYER}{KUN}, que vas-tu faire?\p"
	.string "Vas-tu relever le défi de la ZONE DE\n"
	.string "COMBAT?\p"
	.string "ou vas-tu plutôt remplir ton\n"
	.string "POKéDEX?\p"
	.string "Tu as peut-être gagné le combat, mais\n"
	.string "je complèterai mon POKéDEX avant toi!\p"
	.string "A plus tard!$"

LilycoveCity_Text_1E3608: @ 81E3608
	.string "BRICE: Oh, hé, c'est {PLAYER}.\p"
	.string "Je fais une course pour mon papa.\n"
	.string "Non, je n'achète pas de POUPEE.\p"
	.string "En tout cas, ça fait un bout d'temps.\p"
	.string "on se fait un petit combat pour voir\n"
	.string "qui a le mieux dressé ses POKéMON?$"

LilycoveCity_Text_1E36BF: @ 81E36BF
	.string "BRICE: Y a un problème?\n"
	.string "T'as pas confiance en toi?$"

LilycoveCity_Text_1E36FA: @ 81E36FA
	.string "BRICE: Tu veux t'battre pour voir qui\n"
	.string "a le mieux dressé ses POKéMON?$"

LilycoveCity_Text_1E373C: @ 81E373C
	.string "BRICE: Ouh, Mais tu sais que je ne\n"
	.string "contre toi, {PLAYER}.$"

LilycoveCity_Text_1E3777: @ 81E3777
	.string "Hum…\n"
	.string "T'as bien progressé.\p"
	.string "Je suis dégoûté! J'avais pourtant un\n"
	.string "avantage sur toi en tant que DRESSEUR…$"

LilycoveCity_Text_1E37D7: @ 81E37D7
	.string "BRICE: Je…\n"
	.string "Je compte rentrer à BOURG-EN-VOL.\p"
	.string "Tu sais, j'aide mon père à remplir son\n"
	.string "POKéDEX. Il commence à être bien garni,\l"
	.string "alors je devrais aller lui montrer.$"

LilycoveCity_Text_1E3876: @ 81E3876
	.string "{PLAYER}{KUN}, que vas-tu faire?\p"
	.string "Rassembler tous les BADGES et relever\n"
	.string "le défi de la LIGUE POKéMON?\p"
	.string "Je vais peut-être faire ça aussi…\p"
	.string "Enfin, de toute façon il faut tenir bon!$"

LilycoveCity_Text_1E390C: @ 81E390C
	.string "{PLAYER}, que vas-tu faire?\p"
	.string "Maintenant que tu es si robuste, tu vas\n"
	.string "relever le défi de la LIGUE POKéMON?\p"
	.string "Hé, même moi, si j'entraînais un peu plus\n"
	.string "mes POKéMON, je pourrais être plus fort\l"
	.string "que toi, {PLAYER}.\p"
	.string "Enfin, de toute façon il faut tenir bon!$"

LilycoveCity_Text_1E39E3: @ 81E39E3
	.string "{PLAYER}, que vas-tu faire?\p"
	.string "Maintenant que tu es si robuste, tu\n"
	.string "vas t'attaquer à la ZONE DE COMBAT?\p"
	.string "Ou est-ce que tu vas compléter\n"
	.string "ton POKéDEX?\p"
	.string "Maintenant que tu es un très bon DRESSEUR\n"
	.string "tu devrais aller à la ZONE DE COMBAT.\p"
	.string "Hé, si j'entraînais un peu plus mes\n"
	.string "POKéMON, je serais plus fort que toi.\p"
	.string "J'irai peut-être à la ZONE DE COMBAT\n"
	.string "Enfin, de toute façon il faut tenir bon!$"

LilycoveCity_Text_1E3B2C: @ 81E3B2C
	.string "Hum, hum ,hum…\p"
	.string "Aujourd'hui, on a ramené plus gros\n"
	.string "butin dans notre PLANQUE secrète…\p"
	.string "Qu… Qui es-tu?!\n"
	.string "Je parlais tout seul!$"

LilycoveCity_Text_1E3B95: @ 81E3B95
	.string "Je suis juste un SBIRE, alors je ne\n"
	.string "sais pas ce que le CHEF pense…\p"
	.string "Mais en étant dans la TEAM AQUA, je\n"
	.string "vais réaliser de grandes choses!\p"	
	.string "Qu… Qui es-tu?!\n"
	.string "Je parlais tout seul!$"

LilycoveCity_Text_1E3C46: @ 81E3C46
	.string "Hé, toi!\p"
	.string "Ne va pas dans la caverne de la crique!\p"
	.string "Pourquoi? Mais parce que!\n"
	.string "Je suis adulte, tu n'as qu'à m'écouter!$"

LilycoveCity_Text_1E3CBE: @ 81E3CBE
	.string "Si le monde entier nous appartient,\n"
	.string "à nous la TEAM AQUA, ce sera aussi un\l"
	.string "endroit plus agréable pour les POKéMON.$"

LilycoveCity_Text_1E3D1F: @ 81E3D1F
	.string "Là! WAILMER!\n"
	.string "Sortez de l'eau maintenant!$"

LilycoveCity_Text_1E3D4A: @ 81E3D4A
	.string "Hum? Qu'est-ce que tu veux?\p"
	.string "Tu perturbes notre entraînement, alors\n"
	.string "tu pourrais pas déguerpir, par hasard?$"

LilycoveCity_Text_1E3D9E: @ 81E3D9E
	.string "Il y a une SALLE DE CONCOURS\n"
	.string "POKéMON dans cette ville. \p"
	.string "Ça veut dire qu'on peut y voir des\n"
	.string "POKéMON bien dressés venant\n"
	.string "des quatres coins du pays.\p"
	.string "Mon cœur d'enthousiasme!$"

LilycoveCity_Text_1E3E3C: @ 81E3E3C
	.string "Tu as vu cette étrange carvene dans la\n"
	.string "crique, au bout de la ville?$"

LilycoveCity_Text_1E3E7D: @ 81E3E7D
	.string "Je vais apprendre de nouvelles\n"
	.string "capacités à mon POKéMON pour\n"
	.string "qu'il participe à un CONCOURS.\p"
	.string "Alors, je vais aller voir l'EFFACEUR DE\n"
	.string "CAPACITES, pour qu'il lui fasse oublier\n"
	.string "certaines CS.$"

LilycoveCity_Text_1E3F05: @ 81E3F05
	.string "Je viens de KANTO.\p"
	.string "La région de HOENN est très belle\n"
	.string "avec son eau et sa nature verdoyante.\p"
	.string "Hum? Attends une seconde…\p"
	.string "Y aurait-il des POKéMON rares qui\n"
	.string "ne vivent que dnas cette zone?$"

LilycoveCity_Text_1E3FAB: @ 81E3FAB
	.string "La TEAM AQUA entraîne ses WAILMER\n"
	.string "dans la crique.\p"
	.string "Nous, les MARINS, ça nous gêne! On ne\n"
	.string "peut pas aller en mer avec nos bateaux!$"

LilycoveCity_Text_1E4020: @ 81E4020
	.string "Eh, t'es au courant?\p"
	.string "Quelqu'un a chassé la TEAM AQUA\n"
	.string "de la voie que nous empruntons!\p"
	.string "Les WAILMER ne sont plus dans la\n"
	.string "crique, alors on peut à nouveau sortir\n"
	.string "en mer.$"

LilycoveCity_Text_1E40AD: @ 81E40AD
	.string "Je faisais une petite sieste sur la\n"
	.string "plage, bercée par le bruit des vagues…\p"
	.string "quand quelqu'un m'a volé mon POKéMON!\p"
	.string "Qui est le ravisseur?\n"
	.string "La TEAM AQUA? Est-ce la TEAM AQUA?$"

LilycoveCity_Text_1E4145: @ 81E4145
	.string "Le POKéMON qui me manquait…\n"
	.string "Il est revenu sans que j'm'en aperçoive!$"

LilycoveCity_Text_1E417B: @ 81E417B
	.string "Je suis MARCHAND D'ART.\p"
	.string "J'achète et je vends des œuvres d'art,\n"
	.string "essentiellement des tableaux.\p"
	.string "J'ai entendu dire que le MUSEE, ici,\n"
	.string "exposait de magnifiques œuvres…$"

LilycoveCity_Text_1E420B: @ 81E420B
	.string "Même quand on vieillit et qu'on devient,\n"
	.string "tout ridé, la mer semble toujours jeune\l"
	.string "grâce à l'éclat radieux de la vie…\p"
	.string "Oh, oh, oh…$"

LilycoveCity_Text_1E4283: @ 81E4283
	.string "Il y a soixante ans, mon mari m'a\n"
	.string "demandée en mariage ici.\l"
	.string "La mer est toujours aussi belle.\p"
	.string "Aaaaaaaaaaaah…$"

LilycoveCity_Text_1E42FC: @ 81E42FC
	.string "Hum, tu as entendu parler de l'étrange\n"
	.string "caverne dans cette crique?\p"
	.string "il s'agissait d'une cavité naturelle,\n"
	.string "mais c'était avant que la TEAM AQUA\l"
	.string "ne vienne la restaurer.\p"
	.string "Ils se présentent comme les “amoureux\n"
	.string "de la nature”!\p"
	.string "Mais il y a une grande différence entre\n"
	.string "ce qu'ils disent et ce qu'ils font!$"

LilycoveCity_Text_1E43FF: @ 81E43FF
	.string "Cette caverne dans la crique…\p"
	.string "Je n'avais pas remarqué, mais elle\n"
	.string "est complètement vide maintenant.\p"
	.string "Ces vauriens de la TEAM AQUA, ils ont\n"
	.string "dû partir pour de bon.$"

LilycoveCity_Text_1E448B: @ 81E448B
	.string "NENUCRIQUE\p"
	.string "“Là où la terre s'arrête, là où la\n"
	.string "mer commence.”$"

LilycoveCity_Text_1E44C3: @ 81E44C3
	.string "CONCOURS POKéMON\n"
	.string "“Participez aux CONCOURS avec\n"
	.string "vos amis!”$"

LilycoveCity_Text_1E44FC: @ 81E44FC
	.string "HOTEL CRIQUE CRACK\p"
	.string "“Souvenez-vous de nous commes les\n"
	.string "cracks de la crique.”$"

LilycoveCity_Text_1E4534: @ 81E4534
	.string "MUSEE NENUCRIQUE\p"
	.string "“Exposition de la collection de \n"
	.string "chefs-d'œuvre POKéMON!”$"

LilycoveCity_Text_1E4571: @ 81E4571
	.string "MUSEE NENUCRIQUE\p"
	.string "“Exposition de la collection\n"
	.string "POKéMON de {PLAYER}!”$"

LilycoveCity_Text_1E45A7: @ 81E45A7
	.string "EMBARCADERE DE NENUCRIQUE\p"
	.string "Le ferry LE MARINA est\n"
	.string "en construction à POIVRESSEL.\p"
	.string "“Il entrera bientôt en service.”$"

LilycoveCity_Text_1E4624: @ 81E4624
	.string "EMBARCADERE DE NENUCRIQUE\p"
	.string "“Profitez d'une merveilleuse\n"
	.string "croisière sur LE MARINA.”$"

LilycoveCity_Text_1E466E: @ 81E466E
	.string "FAN CLUB DES DRESSEURS POKéMON\p"
	.string "Des noms de DRESSEURS parsèment le\n"
	.string "panneau…$"

LilycoveCity_Text_1E46BE: @ 81E46BE
	.string "CENTRE COMMERCIAL DE NENUCRIQUE\p"
	.string "“Marchandises à profusion\n"
	.string "et débordement d'enthousiasme!\p"
	.string "“L'endroit idéal pour trouver tout\n"
	.string "ce qu'il vous faut!”$"

LilycoveCity_Text_1E473D: @ 81E473D
	.string "MAISON DE L'EFFACEUR DE CAPACITES\p"
	.string "“Toutes les capacités de POKéMON\n"
	.string "non désirées sont oubliées.”$"

LilycoveCity_Text_1E4774: @ 81E4774
	.string "Tu connais cet appareil appelé\n"
	.string "MIXEUR?$"

LilycoveCity_Text_1E47A1: @ 81E47A1
	.string "Il faut s'y mettre à plusieurs pour que\n"
	.string "ça tourne plus vite.\p"
	.string "J'ai entendu dire que plus ça tourne\n"
	.string "vite, meilleurs sont les {POKEBLOCK}S.$"

LilycoveCity_Text_1E4824: @ 81E4824
	.string "On l'utilise pour fabriquer une sorte de\n"
	.string "bonbon appelé {POKEBLOCK}.\p"
	.string "Si tu donnes un bon {POKEBLOCK} à un\n"
	.string "POKéMON, sa condition va s'améliorer.$"

LilycoveCity_Text_1E48A5: @ 81E48A5
	.string "J'ai entendu dire qu'il y aurait une tour\n"
	.string "au-delà de la mer.\p"
	.string "Je crois qu'on l'appelle le PILIER\n"
	.string "CELESTE.$"

LilycoveCity_Text_1E4902: @ 81E4902
	.string "J'ai vu cette tour immense quelque\n"
	.string "part près du CHENAL 131.\p"
	.string "Est-ce possible?$"

LilycoveCity_Text_1E494D: @ 81E494D
	.string "On vient juste d'arriver ici pour passer\n"
	.string "notre lune de miel.\p"
	.string "Et on a vu un POKéMON dy type DRAGON\n"
	.string "voler très haut dans le ciel.\p"
	.string "Il y a vraiment des POKéMON comme ça\n"
	.string "à HOENN?$"

LilycoveCity_Text_1E49F4: @ 81E49F4
	.string "Pour notre lune de miel, on a l'intention\n"
	.string "de voir autant de POKéMON que possible.\p"
	.string "Alors imagine un peu ce qu'on a pu\n"
	.string "ressentir en voyant ce POKéMON rare.\p"
	.string "Il n'y a pas de mots pour l'expliquer!$"
	
