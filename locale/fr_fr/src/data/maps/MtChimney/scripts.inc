MtChimney_MapScripts:: @ 822EDC1
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_MapScript1_22EDD2
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

MtChimney_OnTransition: @ 822EDCC
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_MapScript1_22EDD2: @ 822EDD2
	setstepcallback STEP_CB_ASH
	end

MtChimney_EventScript_22EDD5:: @ 822EDD5
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_22EDF9
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_22EE02
	closemessage
	applymovement 1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_22EDF9:: @ 822EDF9
	msgbox MtChimney_Text_22FAD2, MSGBOX_DEFAULT
	return

MtChimney_EventScript_22EE02:: @ 822EE02
	msgbox MtChimney_Text_22FBC7, MSGBOX_DEFAULT
	return

MtChimney_EventScript_22EE0B:: @ 822EE0B
	lockall
	playbgm MUS_MGM0, 0
	msgbox MtChimney_Text_22F26A, MSGBOX_DEFAULT
	applymovement 2, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	msgbox MtChimney_Text_22F32E, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_2, MtChimney_Text_22F5CF
	msgbox MtChimney_Text_22F5F7, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreen 1
	removeobject 2
	removeobject 29
	removeobject 3
	removeobject 22
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreen 0
	setobjectxyperm 1, 10, 12
	addobject 1
	compare VAR_FACING, DIR_EAST
	call_if_eq MtChimney_EventScript_22EEC7
	compare VAR_FACING, DIR_NORTH
	call_if_eq MtChimney_EventScript_22EED2
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox MtChimney_Text_22FC3D, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, DIR_EAST
	call_if_eq MtChimney_EventScript_22EEDD
	compare VAR_FACING, DIR_NORTH
	call_if_eq MtChimney_EventScript_22EEE8
	removeobject 1
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

MtChimney_EventScript_22EEC7:: @ 822EEC7
	applymovement 1, MtChimney_Movement_22EF83
	waitmovement 0
	return

MtChimney_EventScript_22EED2:: @ 822EED2
	applymovement 1, MtChimney_Movement_22EF94
	waitmovement 0
	return

MtChimney_EventScript_22EEDD:: @ 822EEDD
	applymovement 1, MtChimney_Movement_22EF8B
	waitmovement 0
	return

MtChimney_EventScript_22EEE8:: @ 822EEE8
	applymovement 1, MtChimney_Movement_22EF9C
	waitmovement 0
	return

MtChimney_EventScript_22EEF3:: @ 822EEF3
	lock
	faceplayer
	showmoneybox 0, 0, 0
	msgbox MtChimney_Text_22FE04, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MtChimney_EventScript_22EF69
	checkmoney 200, 0
	compare VAR_RESULT, 0
	goto_if_eq MtChimney_EventScript_22EF76
	msgbox MtChimney_Text_22FE4D, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE, 1
	compare VAR_RESULT, 1
	call_if_eq MtChimney_EventScript_22EF5E
	giveitem_std ITEM_LAVA_COOKIE
	compare VAR_RESULT, 0
	goto_if_eq MtChimney_EventScript_22EF51
	hidemoneybox
	nop
	nop
	release
	end

MtChimney_EventScript_22EF51:: @ 822EF51
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	nop
	nop
	release
	end

MtChimney_EventScript_22EF5E:: @ 822EF5E
	takemoney 200, 0
	updatemoneybox 0, 0
	return

MtChimney_EventScript_22EF69:: @ 822EF69
	msgbox MtChimney_Text_22FE9B, MSGBOX_DEFAULT
	hidemoneybox
	nop
	nop
	release
	end

MtChimney_EventScript_22EF76:: @ 822EF76
	msgbox MtChimney_Text_22FE5E, MSGBOX_DEFAULT
	hidemoneybox
	nop
	nop
	release
	end

MtChimney_Movement_22EF83: @ 822EF83
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_22EF8B: @ 822EF8B
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_22EF94: @ 822EF94
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_22EF9C: @ 822EF9C
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_22EFA6: @ 822EFA6
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_22EFB8: @ 822EFB8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_22EFC1: @ 822EFC1
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_22EFD0: @ 822EFD0
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_22EFE9: @ 822EFE9
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_22EFF4: @ 822EFF4
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_22F004: @ 822F004
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_22F015: @ 822F015
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_down
	step_end

MtChimney_Movement_22F01D: @ 822F01D
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_22F02B: @ 822F02B
	walk_down
	step_end

MtChimney_Movement_22F02D: @ 822F02D
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_22F035: @ 822F035
	delay_16
	delay_16
	walk_in_place_fastest_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_22F03F: @ 822F03F
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_22F04A: @ 822F04A
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_22F04F: @ 822F04F
	walk_left
	walk_in_place_fastest_right
	delay_16
	step_end

MtChimney_EventScript_22F053:: @ 822F053
	msgbox MtChimney_Text_22FD1F, MSGBOX_SIGN
	end

MtChimney_EventScript_22F05C:: @ 822F05C
	msgbox MtChimney_Text_22FD5B, MSGBOX_SIGN
	end

MtChimney_EventScript_22F065:: @ 822F065
	msgbox MtChimney_Text_22FDA1, MSGBOX_SIGN
	end

MtChimney_EventScript_22F06E:: @ 822F06E
	trainerbattle_single TRAINER_TABITHA_2, MtChimney_Text_22F6AA, MtChimney_Text_22F72C
	msgbox MtChimney_Text_22F76D, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_22F085:: @ 822F085
	trainerbattle_single TRAINER_GRUNT_31, MtChimney_Text_22F7A2, MtChimney_Text_22F83A
	msgbox MtChimney_Text_22F859, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_22F09C:: @ 822F09C
	msgbox MtChimney_Text_22F978, MSGBOX_SIGN
	end

MtChimney_EventScript_22F0A5:: @ 822F0A5
	msgbox MtChimney_Text_22F9B2, MSGBOX_SIGN
	end

MtChimney_EventScript_22F0AE:: @ 822F0AE
	msgbox MtChimney_Text_22F9D1, MSGBOX_SIGN
	end

MtChimney_EventScript_22F0B7:: @ 822F0B7
	msgbox MtChimney_Text_22FA2F, MSGBOX_SIGN
	end

MtChimney_EventScript_22F0C0:: @ 822F0C0
	msgbox MtChimney_Text_22FA8B, MSGBOX_SIGN
	end

MtChimney_EventScript_22F0C9:: @ 822F0C9
	msgbox MtChimney_Text_22FAA5, MSGBOX_SIGN
	end

MtChimney_EventScript_22F0D2:: @ 822F0D2
	msgbox MtChimney_Text_22FACB, MSGBOX_SIGN
	end

MtChimney_EventScript_22F0DB:: @ 822F0DB
	msgbox MtChimney_Text_22FDFC, MSGBOX_SIGN
	end

MtChimney_EventScript_22F0E4:: @ 822F0E4
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_22F137
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_22F12D
	msgbox MtChimney_Text_22FF12, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MtChimney_EventScript_22F123
	msgbox MtChimney_Text_22FF66, MSGBOX_DEFAULT
	giveitem_std ITEM_METEORITE
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end

MtChimney_EventScript_22F123:: @ 822F123
	msgbox MtChimney_Text_22FF9C, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_22F12D:: @ 822F12D
	msgbox MtChimney_Text_22FFC0, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_22F137:: @ 822F137
	msgbox MtChimney_Text_22FEAA, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_22F141:: @ 822F141
	msgbox MtChimney_Text_22FFFA, MSGBOX_SIGN
	end

MtChimney_EventScript_22F14A:: @ 822F14A
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_23001D, MtChimney_Text_230076, MtChimney_EventScript_22F176
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq MtChimney_EventScript_22F195
	msgbox MtChimney_Text_2300A2, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_22F176:: @ 822F176
	special sub_80B4808
	waitmovement 0
	msgbox MtChimney_Text_2300E3, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

MtChimney_EventScript_22F195:: @ 822F195
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_230153, MtChimney_Text_2301BB
	msgbox MtChimney_Text_2301E7, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_22F1AC:: @ 822F1AC
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_23022A, MtChimney_Text_23026D
	msgbox MtChimney_Text_230292, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_22F1C3:: @ 822F1C3
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_2302BD, MtChimney_Text_230304
	msgbox MtChimney_Text_23033A, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_22F1DA:: @ 822F1DA
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_2303DF, MtChimney_Text_230436
	msgbox MtChimney_Text_230463, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_22F1F1:: @ 822F1F1
	trainerbattle_single TRAINER_GRUNT_24, MtChimney_Text_22F8B6, MtChimney_Text_22F921
	msgbox MtChimney_Text_22F93A, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_22F208:: @ 822F208
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_2304B3, MtChimney_Text_2304F7, MtChimney_EventScript_22F234
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq MtChimney_EventScript_22F253
	msgbox MtChimney_Text_230519, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_22F234:: @ 822F234
	special sub_80B4808
	waitmovement 0
	msgbox MtChimney_Text_230557, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

MtChimney_EventScript_22F253:: @ 822F253
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_23059C, MtChimney_Text_2305E3
	msgbox MtChimney_Text_230614, MSGBOX_AUTOCLOSE
	end

MtChimney_Text_22F26A: @ 822F26A
	.string "La puissance contenue dans le\n"
	.string "METEORITE…\p"
	.string "En l'amplifiant avec cette machine,\n"
	.string "l'activité volcanique du MONT CHIMNEE\l"
	.string "va s'intensifier instantanément…\p"
	.string "Son énergie va grandir à l'intérieur\n"
	.string "de ce cratère et…\l"
	.string "Hahaha…$"

MtChimney_Text_22F32E: @ 822F32E
	.string "MAX: Hum?\n"
	.string "Qui es-tu?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "J'ai entendu ARTHUR se plaindre d'un\n"
	.string "DRESSEUR qui se serait mêlé des\l"
	.string "affaires de la TEAM AQUA.\p"
	.string "Il devait parler de toi, je pense.\p"
	.string "Humpf! Alors tu veux également te\n"
	.string "mêler des affaires de la TEAM MAGMA?\p"
	.string "Ecoute-moi bien! Les êtres vivants ont\n"
	.string "besoin de la terre pour se développer.\p"
	.string "La terre représente tout! C'est le\n"
	.string "berceau de toute vie!\p"
	.string "C'est pour cela que la TEAM MAGMA\n"
	.string "s'est engagée à étendre la terre.\p"
	.string "Notre but est de faire prospérer les\n"
	.string "êtres humains et les POKéMON!\p"
	.string "Et pour cela, nous avons besoin de\n"
	.string "la puissance qui sommeille dans\l"
	.string "cette montagne…\p"
	.string "Oh, tu n'avais pas vraiment besoin de\n"
	.string "savoir tout ça…\p"
	.string "Mais peu importe!\n"
	.string "Je vais te montrer ce qu'il en coûte\l"
	.string "de se mêler de nos affaires!$"

MtChimney_Text_22F5CF: @ 822F5CF
	.string "Quoi?!\p"
	.string "Moi, MAX, j'ai été pris au dépourvu?!$"

MtChimney_Text_22F5F7: @ 822F5F7
	.string "MAX: Ça suffit. Je pars pour cette\n"
	.string "fois.\p"
	.string "Mais n'espère pas ne plus entendre\n"
	.string "parler de la TEAM MAGMA.\p"
	.string "Hahaha…\p"
	.string "Même sans le METEORITE, si nous\n"
	.string "parvenons à obtenir l'ORBE… Alors là!$"

MtChimney_Text_22F6AA: @ 822F6AA
	.string "Hé, hé, hé!\p"
	.string "Alors t'as fait tout le chemin jusqu'ici!\p"
	.string "Mais il est trop tard!\n"
	.string "J'ai déjà remis le METEORITE du\l"
	.string "SITE METEORE au CHEF!$"

MtChimney_Text_22F72C: @ 822F72C
	.string "Héhéhé…\p"
	.string "Même si j'ai perdu, si notre chef arrive\n"
	.string "à réveiller cette chose…$"

MtChimney_Text_22F76D: @ 822F76D
	.string "CHEF, vite!\n"
	.string "Donne-lui l'énergie du METEORITE!\p"
	.string "Héhéhé…$"

MtChimney_Text_22F7A2: @ 822F7A2
	.string "Nous, la TEAM MAGMA, nous travaillons\n"
	.string "dur dans l'intérêt de tous.\p"
	.string "Si la puissance de cette chose\n"
	.string "étendait la terre, il y aurait plus\l"
	.string "d'espace pour vivre.\p"
	.string "Tout le monde serait heureux!$"

MtChimney_Text_22F83A: @ 822F83A
	.string "Hum?\n"
	.string "Tu veux dire que j'ai perdu?$"

MtChimney_Text_22F859: @ 822F859
	.string "Notre CHEF dit que ça rendra tout\n"
	.string "le monde heureux.\p"
	.string "Mais pourquoi tout le monde se met en\n"
	.string "travers de notre route?$"

MtChimney_Text_22F8B6: @ 822F8B6
	.string "S'il y avait plus de terre, je pourrais\n"
	.string "avoir ma propre maison!\p"
	.string "Je vais en construire une sur de\n"
	.string "la lave froide!$"

MtChimney_Text_22F921: @ 822F921
	.string "Mon rêve de grande maison…$"

MtChimney_Text_22F93A: @ 822F93A
	.string "A ton âge, tu devrais être en\n"
	.string "train de jouer dans le sable!$"

MtChimney_Text_22F978: @ 822F978
	.string "Cette TEAM AQUA est agaçante…\n"
	.string "Ils font toujours échouer nos plans!$"

MtChimney_Text_22F9B2: @ 822F9B2
	.string "Les METEORITES contiennent une\n"
	.string "puissance stupéfiante!$"

MtChimney_Text_22F9D1: @ 822F9D1
	.string "Tu ferais bien de pas te mêler de ça!\p"
	.string "Nous essayons de réveiller cette chose\n"
	.string "pour le bien de tous!$"

MtChimney_Text_22FA2F: @ 822FA2F
	.string "Nous sommes la TEAM MAGMA!\p"
	.string "Ils sont la TEAM AQUA!\p"
	.string "Ça m'énerve vraiment qu'ils utilisent\n"
	.string "un nom comme le nôtre!$"

MtChimney_Text_22FA8B: @ 822FA8B
	.string "Yé!\n"
	.string "Fais-en du feu!$"

MtChimney_Text_22FAA5: @ 822FAA5
	.string "On va continuer à créer plus de terre!$"

MtChimney_Text_22FACB: @ 822FACB
	.string "Youhou!$"

MtChimney_Text_22FAD2: @ 822FAD2
	.string "ARTHUR: Grr, {PLAYER}!\n"
	.string "J'aurais dû me douter que tu pointerais\n"
	.string "le bout de ton nez!\p"
	.string "Vois par toi-même de quoi sont\n"
	.string "capables les fanatiques de la\l"
	.string "TEAM MAGMA!\p"
	.string "Ils essaient d'injecter la puissance\n"
	.string "du METEORITE volé à l'intérieur\l"
	.string "du volcan!\p"
	.string "A cause d'eux, le volcan risque\n"
	.string "d'entrer en éruption!$"

MtChimney_Text_22FBC7: @ 822FBC7
	.string "ARTHUR: Arrrgh!\p"
	.string "Je veux arrêter ce MAX,\n"
	.string "mais je ne peux pas!\p"
	.string "Je suis trop occupé à me battre\n"
	.string "contre trois adversaires à la fois.$"

MtChimney_Text_22FC3D: @ 822FC3D
	.string "ARTHUR: {PLAYER}!\n"
	.string "Merci!\p"
	.string "Grâce à ton aide, nous avons déjoué\n"
	.string "les plans de la TEAM MAGMA!\p"
	.string "Mais… Toi…\n"
	.string "De quel côté es-tu?\p"
	.string "Ah, peu importe…\p"
	.string "Nous resterons vigilants et\n"
	.string "continuerons de poursuivre la\l"
	.string "TEAM MAGMA.\p"
	.string "{PLAYER}, nous nous reverrons!$"

MtChimney_Text_22FD1F: @ 822FD1F
	.string "La TEAM MAGMA est venue en force!\n"
	.string "Arrêtons! On ne fera pas le poids!$"

MtChimney_Text_22FD5B: @ 822FD5B
	.string "S'ils étendent la terre, il y aura moins\n"
	.string "d'espace pour les POKéMON EAU!$"

MtChimney_Text_22FDA1: @ 822FDA1
	.string "Nous sommes la TEAM AQUA!\p"
	.string "Ils sont la TEAM MAGMA!\p"
	.string "Ça me fait mal au cœur qu'ils utilisent\n"
	.string "un nom qui ressemble au nôtre!$"

MtChimney_Text_22FDFC: @ 822FDFC
	.string "Bouhaha!$"

MtChimney_Text_22FE04: @ 822FE04
	.string "Les LAVA COOKIES sont les spécialités\n"
	.string "locales du MONT CHIMNEE.\p"
	.string "Goûtes-en un. Ça ne coûte que 200¥.$"

MtChimney_Text_22FE4D: @ 822FE4D
	.string "Merci, mon p'tit!$"

MtChimney_Text_22FE5E: @ 822FE5E
	.string "Oh, tu ne peux pas acheter ce que tu\n"
	.string "veux, si tu n'as pas assez d'argent.$"

MtChimney_Text_22FE9B: @ 822FE9B
	.string "Bon, très bien.$"

MtChimney_Text_22FEAA: @ 822FEAA
	.string "Un METEORITE est placé sur une\n"
	.string "mystérieuse machine…\p"
	.string "Cette machine semble stocker de\n"
	.string "l'énergie dans le METEORITE.$"

MtChimney_Text_22FF12: @ 822FF12
	.string "Un METEORITE est placé sur une\n"
	.string "mystérieuse machine…\p"
	.string "Voulez-vous retirer le METEORITE?$"

MtChimney_Text_22FF66: @ 822FF66
	.string "{PLAYER} retire le METEORITE de la\n"
	.string "mystérieuse machine.$"

MtChimney_Text_22FF9C: @ 822FF9C
	.string "{PLAYER} laisse le METEORITE à sa\n"
	.string "place.$"

MtChimney_Text_22FFC0: @ 822FFC0
	.string "Cette mystérieuse machine…\n"
	.string "Elle ne répond pas.$"

MtChimney_Text_22FFFA: @ 822FFFA
	.string "{DOWN_ARROW} SENTIER SINUROC\n"
	.string "VERMILAVA DROIT DEVANT$"

MtChimney_Text_23001D: @ 823001D
	.string "Je suis allée aux sources chaudes pour\n"
	.string "revigorer mes os fatigués.\l"
	.string "Maintenant, je me sens forte!$"

MtChimney_Text_230076: @ 8230076
	.string "Oh, ça alors!\n"
	.string "Quel DRESSEUR tu fais!$"

MtChimney_Text_2300A2: @ 82300A2
	.string "Eh bien, j'ai perdu. Je ne peux plus me\n"
	.string "considérer comme étant EXPERT, hein?$"

MtChimney_Text_2300E3: @ 82300E3
	.string "Merci, mon p'tit! C'était amusant\n"
	.string "Comme si je m'étais battue contre\l"
	.string "mes petits-enfants.\p"
	.string "Reviens me voir quand tu veux\n"
	.string "pour une revanche.$"

MtChimney_Text_230153: @ 8230153
	.string "Si tu réussis à toucher le cœur\n"
	.string "de tes POKéMON, tu devrais pouvoir\l"
	.string "accomplir de grandes choses.$"

MtChimney_Text_2301BB: @ 82301BB
	.string "Oh, ça alors!\n"
	.string "Quel DRESSEUR tu fais!$"

MtChimney_Text_2301E7: @ 82301E7
	.string "Peut-être ton cœur ne fait-il plus\n"
	.string "qu'un avec celui de tes POKéMON.$"

MtChimney_Text_23022A: @ 823022A
	.string "J'ai le feu en moi, bébé.\n"
	.string "J'en peux plus! Il faut que j'me batte!$"

MtChimney_Text_23026D: @ 823026D
	.string "Oh, oh! C'était un combat torride!$"

MtChimney_Text_230292: @ 8230292
	.string "La chaleur du MONT CHIMNEE avive\n"
	.string "le feu qui brûle en moi, bébé!$"

MtChimney_Text_2302BD: @ 82302BD
	.string "Je suis enfin parvenue au MONT CHIMNEE.\n"
	.string "Je veux que mon POKéMON combatte!$"

MtChimney_Text_230304: @ 8230304
	.string "La façon dont tu te bats… C'est comme\n"
	.string "une éruption du MONT CHIMNEE!$"

MtChimney_Text_23033A: @ 823033A
	.string "Comme je l'ai dit, je suis enfin parvenue\n"
	.string "au MONT CHIMNEE. Ce serait dommage\l"
	.string "que ce ne soit qu'en touriste…\p"
	.string "Je veux gagner quelques combats et\n"
	.string "ramener des COOKIES en souvenir.$"

MtChimney_Text_2303DF: @ 82303DF
	.string "Depuis ma baignade dans les sources\n"
	.string "chaudes, je suis en super forme!\l"
	.string "Je suis sûre que je vais gagner!$"

MtChimney_Text_230436: @ 8230436
	.string "Atchoum!\n"
	.string "Je prends froid hors de l'eau.$"

MtChimney_Text_230463: @ 8230463
	.string "Je vais devoir prendre un autre bain\n"
	.string "dans les sources chaudes. Tu viens?\p"
	.string "Je plaisante!$"

MtChimney_Text_2304B3: @ 82304B3
	.string "C'est une belle montagne! Pleine de\n"
	.string "gens pour te tenir compagnie!$"

MtChimney_Text_2304F7: @ 82304F7
	.string "Oh, tu as le feu, toi!$"

MtChimney_Text_230519: @ 8230519
	.string "Je ferais mieux d'aller me baigner\n"
	.string "avec les gens du coin!$"

MtChimney_Text_230557: @ 8230557
	.string "J'aime les petites boules de feu\n"
	.string "comme toi.\p"
	.string "Laisse-moi t'enregistrer dans mon\n"
	.string "POKéNAV.$"

MtChimney_Text_23059C: @ 823059C
	.string "Je suis entouré de gens chauds comme\n"
	.string "la braise, je ne peux pas perdre!$"

MtChimney_Text_2305E3: @ 82305E3
	.string "Tu as autant le feu qu'avant!$"

MtChimney_Text_230614: @ 8230614
	.string "En fait, il fait un peu trop chaud ici.\n"
	.string "Je dois être un peu trop habillé.$"

