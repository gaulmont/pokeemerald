Route119_MapScripts:: @ 81F4424
	map_script MAP_SCRIPT_ON_RESUME, Route119_MapScript1_1F442F
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_OnTransition
	.byte 0

Route119_MapScript1_1F442F: @ 81F442F
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route119_EventScript_1F4439
	end

Route119_EventScript_1F4439:: @ 81F4439
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

Route119_OnTransition: @ 81F444D
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	compare VAR_WEATHER_INSTITUTE_STATE, 1
	call_if_eq Route119_EventScript_1F4466
	special SetRoute119Weather
	end

Route119_EventScript_1F4466:: @ 81F4466
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS
	setvar VAR_WEATHER_INSTITUTE_STATE, 2
	return

Route119_EventScript_1F4472:: @ 81F4472
	setvar VAR_TEMP_1, 1
	goto Route119_EventScript_1F4488
	end

Route119_EventScript_1F447D:: @ 81F447D
	setvar VAR_TEMP_1, 2
	goto Route119_EventScript_1F4488
	end

Route119_EventScript_1F4488:: @ 81F4488
	lockall
	addobject 25
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq Route119_EventScript_1F4501
	compare VAR_RESULT, FEMALE
	call_if_eq Route119_EventScript_1F4506
	delay 65
	compare VAR_TEMP_1, 1
	call_if_eq Route119_EventScript_1F46C6
	compare VAR_TEMP_1, 2
	call_if_eq Route119_EventScript_1F46D1
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 30
	compare VAR_TEMP_1, 1
	call_if_eq Route119_EventScript_1F4700
	compare VAR_TEMP_1, 2
	call_if_eq Route119_EventScript_1F470F
	removeobject 25
	addobject 16
	delay 30
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route119_EventScript_1F450B
	compare VAR_RESULT, FEMALE
	goto_if_eq Route119_EventScript_1F4585
	releaseall
	end

Route119_EventScript_1F4501:: @ 81F4501
	playbgm MUS_GIRL_SUP, 1
	return

Route119_EventScript_1F4506:: @ 81F4506
	playbgm MUS_BOY_SUP, 1
	return

Route119_EventScript_1F450B:: @ 81F450B
	msgbox Route119_Text_1F49FD, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_1F453A
	case 1, Route119_EventScript_1F454A
	case 2, Route119_EventScript_1F455A
	end

Route119_EventScript_1F453A:: @ 81F453A
	trainerbattle_no_intro TRAINER_MAY_6, Route119_Text_1F4A98
	goto Route119_EventScript_1F456A
	end

Route119_EventScript_1F454A:: @ 81F454A
	trainerbattle_no_intro TRAINER_MAY_9, Route119_Text_1F4A98
	goto Route119_EventScript_1F456A
	end

Route119_EventScript_1F455A:: @ 81F455A
	trainerbattle_no_intro TRAINER_MAY_3, Route119_Text_1F4A98
	goto Route119_EventScript_1F456A
	end

Route119_EventScript_1F456A:: @ 81F456A
	msgbox Route119_Text_1F4AF3, MSGBOX_DEFAULT
	call Route119_EventScript_1F45FF
	msgbox Route119_Text_1F4B56, MSGBOX_DEFAULT
	goto Route119_EventScript_1F460F
	end

Route119_EventScript_1F4585:: @ 81F4585
	msgbox Route119_Text_1F4C9A, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_1F45B4
	case 1, Route119_EventScript_1F45C4
	case 2, Route119_EventScript_1F45D4
	end

Route119_EventScript_1F45B4:: @ 81F45B4
	trainerbattle_no_intro TRAINER_BRENDAN_6, Route119_Text_1F4D24
	goto Route119_EventScript_1F45E4
	end

Route119_EventScript_1F45C4:: @ 81F45C4
	trainerbattle_no_intro TRAINER_BRENDAN_9, Route119_Text_1F4D24
	goto Route119_EventScript_1F45E4
	end

Route119_EventScript_1F45D4:: @ 81F45D4
	trainerbattle_no_intro TRAINER_BRENDAN_3, Route119_Text_1F4D24
	goto Route119_EventScript_1F45E4
	end

Route119_EventScript_1F45E4:: @ 81F45E4
	msgbox Route119_Text_1F4D4B, MSGBOX_DEFAULT
	call Route119_EventScript_1F45FF
	msgbox Route119_Text_1F4DB5, MSGBOX_DEFAULT
	goto Route119_EventScript_1F460F
	end

Route119_EventScript_1F45FF:: @ 81F45FF
	giveitem_std ITEM_HM02
	setflag FLAG_RECEIVED_HM02
	return

Route119_EventScript_1F460F:: @ 81F460F
	closemessage
	compare VAR_TEMP_1, 1
	call_if_eq Route119_EventScript_1F4700
	compare VAR_TEMP_1, 2
	call_if_eq Route119_EventScript_1F470F
	removeobject 16
	addobject 25
	delay 30
	compare VAR_TEMP_1, 1
	call_if_eq Route119_EventScript_1F46DC
	compare VAR_TEMP_1, 2
	call_if_eq Route119_EventScript_1F46EE
	removeobject 25
	setvar VAR_ROUTE119_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	delay 60
	compare VAR_TEMP_1, 1
	call_if_eq Route119_EventScript_1F46A0
	compare VAR_TEMP_1, 2
	call_if_eq Route119_EventScript_1F46A8
	addobject 43
	applymovement 43, Route119_Movement_1F4752
	waitmovement 0
	addvar VAR_SCOTT_STATE, 1
	msgbox Route119_Text_1F4E60, MSGBOX_DEFAULT
	closemessage
	compare VAR_TEMP_1, 1
	call_if_eq Route119_EventScript_1F46B0
	compare VAR_TEMP_1, 2
	call_if_eq Route119_EventScript_1F46BB
	removeobject 43
	releaseall
	end

Route119_EventScript_1F46A0:: @ 81F46A0
	setobjectxyperm 43, 27, 25
	return

Route119_EventScript_1F46A8:: @ 81F46A8
	setobjectxyperm 43, 28, 25
	return

Route119_EventScript_1F46B0:: @ 81F46B0
	applymovement 43, Route119_Movement_1F475A
	waitmovement 0
	return

Route119_EventScript_1F46BB:: @ 81F46BB
	applymovement 43, Route119_Movement_1F4763
	waitmovement 0
	return

Route119_EventScript_1F46C6:: @ 81F46C6
	applymovement 25, Route119_Movement_1F4728
	waitmovement 0
	return

Route119_EventScript_1F46D1:: @ 81F46D1
	applymovement 25, Route119_Movement_1F4732
	waitmovement 0
	return

Route119_EventScript_1F46DC:: @ 81F46DC
	applymovement EVENT_OBJ_ID_PLAYER, Route119_Movement_1F471E
	applymovement 25, Route119_Movement_1F473D
	waitmovement 0
	return

Route119_EventScript_1F46EE:: @ 81F46EE
	applymovement EVENT_OBJ_ID_PLAYER, Route119_Movement_1F4723
	applymovement 25, Route119_Movement_1F4747
	waitmovement 0
	return

Route119_EventScript_1F4700:: @ 81F4700
	setobjectxyperm 16, 25, 32
	setobjectxyperm 25, 25, 32
	return

Route119_EventScript_1F470F:: @ 81F470F
	setobjectxyperm 16, 26, 32
	setobjectxyperm 25, 26, 32
	return

Route119_Movement_1F471E: @ 81F471E
	delay_16
	walk_in_place_fastest_right
	delay_8
	walk_in_place_fastest_up
	step_end

Route119_Movement_1F4723: @ 81F4723
	delay_16
	walk_in_place_fastest_left
	delay_8
	walk_in_place_fastest_up
	step_end

Route119_Movement_1F4728: @ 81F4728
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

Route119_Movement_1F4732: @ 81F4732
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

Route119_Movement_1F473D: @ 81F473D
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route119_Movement_1F4747: @ 81F4747
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route119_Movement_1F4752: @ 81F4752
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

Route119_Movement_1F475A: @ 81F475A
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_Movement_1F4763: @ 81F4763
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_EventScript_1F476B:: @ 81F476B
	msgbox Route119_Text_1F5261, MSGBOX_NPC
	end

Route119_EventScript_1F4774:: @ 81F4774
	msgbox Route119_Text_1F530E, MSGBOX_SIGN
	end

Route119_EventScript_1F477D:: @ 81F477D
	msgbox Route119_Text_1F5327, MSGBOX_SIGN
	end

Route119_EventScript_1F4786:: @ 81F4786
	trainerbattle_single TRAINER_BRENT, Route119_Text_29D8C2, Route119_Text_29D8F0
	msgbox Route119_Text_29D902, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F479D:: @ 81F479D
	trainerbattle_single TRAINER_DONALD, Route119_Text_29D941, Route119_Text_29D97C
	msgbox Route119_Text_29D993, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F47B4:: @ 81F47B4
	trainerbattle_single TRAINER_TAYLOR, Route119_Text_29D9CD, Route119_Text_29DA14
	msgbox Route119_Text_29DA2C, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F47CB:: @ 81F47CB
	trainerbattle_single TRAINER_DOUG, Route119_Text_29DA7D, Route119_Text_29DABC
	msgbox Route119_Text_29DADB, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F47E2:: @ 81F47E2
	trainerbattle_single TRAINER_GREG, Route119_Text_29DB17, Route119_Text_29DB66
	msgbox Route119_Text_29DB7C, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F47F9:: @ 81F47F9
	trainerbattle_single TRAINER_KENT, Route119_Text_29DBC2, Route119_Text_29DC20
	msgbox Route119_Text_29DC2B, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F4810:: @ 81F4810
	trainerbattle_single TRAINER_JACKSON_1, Route119_Text_29DC4C, Route119_Text_29DC9F, Route119_EventScript_1F483C
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route119_EventScript_1F485B
	msgbox Route119_Text_29DCC6, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_1F483C:: @ 81F483C
	special sub_80B4808
	waitmovement 0
	msgbox Route119_Text_29DD1C, MSGBOX_DEFAULT
	register_matchcall TRAINER_JACKSON_1
	release
	end

Route119_EventScript_1F485B:: @ 81F485B
	trainerbattle_rematch TRAINER_JACKSON_1, Route119_Text_29DD62, Route119_Text_29DDA5
	msgbox Route119_Text_29DDBD, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F4872:: @ 81F4872
	trainerbattle_single TRAINER_CATHERINE_1, Route119_Text_29DE0F, Route119_Text_29DE5D, Route119_EventScript_1F489E
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route119_EventScript_1F48BD
	msgbox Route119_Text_29DE88, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_1F489E:: @ 81F489E
	special sub_80B4808
	waitmovement 0
	msgbox Route119_Text_29DEF7, MSGBOX_DEFAULT
	register_matchcall TRAINER_CATHERINE_1
	release
	end

Route119_EventScript_1F48BD:: @ 81F48BD
	trainerbattle_rematch TRAINER_CATHERINE_1, Route119_Text_29DF6B, Route119_Text_29DF92
	msgbox Route119_Text_29DFAF, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F48D4:: @ 81F48D4
	trainerbattle_single TRAINER_HUGH, Route119_Text_29E007, Route119_Text_29E063
	msgbox Route119_Text_29E071, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F48EB:: @ 81F48EB
	trainerbattle_single TRAINER_PHIL, Route119_Text_29E0A5, Route119_Text_29E0E1
	msgbox Route119_Text_29E0F6, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F4902:: @ 81F4902
	trainerbattle_single TRAINER_YASU, Route119_Text_29E134, Route119_Text_29E18D
	msgbox Route119_Text_29E19D, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F4919:: @ 81F4919
	trainerbattle_single TRAINER_TAKASHI, Route119_Text_29E1F5, Route119_Text_29E22B
	msgbox Route119_Text_29E245, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F4930:: @ 81F4930
	trainerbattle_single TRAINER_HIDEO, Route119_Text_29E26A, Route119_Text_29E288
	msgbox Route119_Text_29E2A3, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F4947:: @ 81F4947
	trainerbattle_single TRAINER_CHRIS, Route119_Text_29E30D, Route119_Text_29E372
	msgbox Route119_Text_29E3A2, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F495E:: @ 81F495E
	trainerbattle_single TRAINER_FABIAN, Route119_Text_29E3FF, Route119_Text_29E44F
	msgbox Route119_Text_29E492, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F4975:: @ 81F4975
	trainerbattle_single TRAINER_DAYTON, Route119_Text_29E4DF, Route119_Text_29E513
	msgbox Route119_Text_29E532, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F498C:: @ 81F498C
	trainerbattle_single TRAINER_RACHEL, Route119_Text_29E56F, Route119_Text_29E5B1
	msgbox Route119_Text_29E5CB, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_1F49A3:: @ 81F49A3
	lock
	faceplayer
	msgbox Route119_Text_1F50EB, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route119_EventScript_1F49BA:: @ 81F49BA
	lock
	faceplayer
	msgbox Route119_Text_1F5147, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route119_EventScript_1F49D1:: @ 81F49D1
	msgbox Route119_Text_1F51A2, MSGBOX_NPC
	end

Route119_EventScript_1F49DA:: @ 81F49DA
	msgbox Route119_Text_1F52B9, MSGBOX_NPC
	end

Route119_EventScript_1F49E3:: @ 81F49E3
	msgbox Route119_Text_1F5339, MSGBOX_SIGN
	end

Route119_EventScript_1F49EC:: @ 81F49EC
	lockall
	pokenavcall Route119_Text_1F4FBA
	waitmessage
	clearflag FLAG_REGISTER_WINONA_POKENAV
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

Route119_Text_1F49FD: @ 81F49FD
	.string "FLORA: {PLAYER}{KUN}!\n"
	.string "Où étais-tu? Je te cherchais!\p"
	.string "Tu as beaucoup progressé?\n"
	.string "Laisse-moi faire!\p"
	.string "Vous êtes prêts, tes POKéMON et toi?\n"
	.string "Evidemment! Allez, c'est parti!$"

Route119_Text_1F4A98: @ 81F4A98
	.string "Waouh!\n"
	.string "Quelle force, {PLAYER}{KUN}!\p"
	.string "Et moi qui craignais que tu aies\n"
	.string "décroché avec l'entraînement!$"

Route119_Text_1F4AF3: @ 81F4AF3
	.string "FLORA: Mais je n'ai pas de souci à me\n"
	.string "faire! Garde le rythme!\p"
	.string "Et viens là! J'ai un cadeau pour toi.$"

Route119_Text_1F4B56: @ 81F4B56
	.string "FLORA: Si tu utilises VOL, ton POKéMON\n"
	.string "te portera dans une ville de ton choix\l"
	.string "que tu as déjà visitée.\p"
	.string "Mais pour pouvoir utiliser VOL, il faut\n"
	.string "le BADGE de l'ARENE de CIMETRONELLE.\l"
	.string "C'est important. N'oublie pas!\p"
	.string "Tu devrais utiliser VOL pour retourner\n"
	.string "chez toi à BOURG-EN-VOL.\p"
	.string "Je parie que ta maman se fait du souci\n"
	.string "pour toi, {PLAYER}{KUN}.\p"
	.string "Bon, on se reverra!$"

Route119_Text_1F4C9A: @ 81F4C9A
	.string "BRICE: {PLAYER}! C'est donc là que tu\n"
	.string "cherches des POKéMON?\p"
	.string "Montre-moi voir si t'en as attrapé des.\n"
	.string "bons. Je vais te tester!\p"
	.string "Maintenant!\n"
	.string "C'est un combat, alors combattons!$"

Route119_Text_1F4D24: @ 81F4D24
	.string "Hum…\n"
	.string "T'as sacrément bien progressé.$"

Route119_Text_1F4D4B: @ 81F4D4B
	.string "BRICE: Tu sais, tu as assez de talent\n"
	.string "pour chercher des POKéMON où tu veux.\p"
	.string "Tiens, je te donne ça.\n"
	.string "Essaie, tu verras bien.$"

Route119_Text_1F4DB5: @ 81F4DB5
	.string "BRICE: Si tu utilises VOL, ton POKéMON\n"
	.string "te portera dans une ville de ton choix\l"
	.string "que tu as déjà visitée.\p"
	.string "Mais pour cela, il faut que tu aies\n"
	.string "le BADGE de l'ARENE de CIMETRONELLE.\p"
	.string "En tout cas, moi, il faut que je file.$"

Route119_Text_1F4E60: @ 81F4E60
	.string "SCOTT: Hahahah!\n"
	.string "Bien joué, {PLAYER}{KUN}!\p"
	.string "Je viens de croiser un DRESSEUR sur\n"
	.string "un VELO.\p"
	.string "Tu viens de le battre, n'est-ce pas?\n"
	.string "Ne dis rien, je suis sûr que c'est toi!\p"
	.string "Il était tout rouge de colère. Tu as\n"
	.string "réussi à bien l'énerver.\p"
	.string "Je te croise souvent en ce moment.\n"
	.string "Vas-tu te rendre à l'ARENE de\l"
	.string "CIMETRONELLE?\p"
	.string "Je suis sûr que tu vas y faire des\n"
	.string "merveilles.\p"
	.string "A la prochaine!$"


Route119_Text_1F4FBA: @ 81F4FBA
	.string "… … … … … …\n"
	.string "… … … … … Bip!\p"
	.string "SCOTT: Hé, {PLAYER}{KUN}, c'est moi!\p"
	.string "Comme je l'imaginais, tu as battu\n"
	.string "le CHAMPION D'ARENE de\l"
	.string "CIMETRONELLE.\p"
	.string "Cette force…\n"
	.string "Peut-être que tu es le DRESSEUR\l"
	.string "que je cherche partout.\p"
	.string "N'oublie pas, je suis un vrai fan!\n"
	.string "Je serai toujours là pour te\l"
	.string "soutenir. Continue comme ça!\p"
	.string "… … … … … …\n"
	.string "… … … … … Clic!$"

Route119_Text_1F50EB: @ 81F50EB
	.string "Nous, on surveille ici.\p"
	.string "Hé, toi! Ne t'approche pas du CENTRE\n"
	.string "METEO. C'est dangereux.$"

Route119_Text_1F5147: @ 81F5147
	.string "C'est très ennuyeux de surveiller.\p"
	.string "Hé, toi! Ne t'approche pas trop près du\n"
	.string "CENTRE METEO, s'il te plaît.$"

Route119_Text_1F51A2: @ 81F51A2
	.string "Je croyais qu'on pouvait faire un VOL en\n"
	.string "attrapant toute une volée de POKéMON\l"
	.string "OISEAU et en s'accrochant à eux.\p"
	.string "il s'avère qu'il existe une capacité\n"
	.string "CS appelée VOL!\p"
	.string "J'aurais bien voulu le savoir plus tôt…$"

Route119_Text_1F5261: @ 81F5261
	.string "Pff…\n"
	.string "C'est une zone de non-droit…\p"
	.string "Les herbes hautes se coincent dans les.\n"
	.string "roues des VELOS.$"

Route119_Text_1F52B9: @ 81F52B9
	.string "Ton POKéMON peut-il utiliser sa\n"
	.string "FORCE CACHEE sur un gros tas\l"
	.string "d'herbe et créer une BASE SECRETE?$"

Route119_Text_1F530E: @ 81F530E
	.string "ROUTE 119\n"
	.string "{RIGHT_ARROW} CIMETRONELLE$"

Route119_Text_1F5327: @ 81F5327
	.string "CENTRE METEO$"

Route119_Text_1F5339: @ 81F5339
	.string "CONSEILS AUX DRESSEURS\p"
	.string "Vous pouvez mettre jusqu'à seize\n"
	.string "objets de décoration et meubles dans\l"
	.string "votre BASE SECRETE.\p"
	.string "A vous de choisir vos objets préférés\n"
	.string "pour aménager votre BASE SECRETE\l"
	.string "personnelle à votre guise.$"
