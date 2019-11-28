LavaridgeTown_MapScripts:: @ 81EA4D3
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_MapScript2_1EA547
	.byte 0

LavaridgeTown_OnTransition: @ 81EA4DE
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call_if_set FLAG_FLANNERY_GIVES_BADGE_INFO, LavaridgeTown_EventScript_1EA514
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_1EA53F
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	compare VAR_LAVARIDGE_TOWN_STATE, 1
	call_if_eq LavaridgeTown_EventScript_1EA518
	compare VAR_LAVARIDGE_TOWN_STATE, 1
	call_if_eq LavaridgeTown_EventScript_1EA543
	end

LavaridgeTown_EventScript_1EA514:: @ 81EA514
	clearflag FLAG_FLANNERY_GIVES_BADGE_INFO
	return

LavaridgeTown_EventScript_1EA518:: @ 81EA518
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 9
	goto_if_eq LavaridgeTown_EventScript_1EA529
	return

LavaridgeTown_EventScript_1EA529:: @ 81EA529
	setobjectxyperm 8, 11, 9
	setobjectxyperm 7, 9, 8
	setobjectmovementtype 7, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL_1
	return

LavaridgeTown_EventScript_1EA53F:: @ 81EA53F
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_1EA543:: @ 81EA543
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_MapScript2_1EA547: @ 81EA547
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_1EA551
	.2byte 0

LavaridgeTown_EventScript_1EA551:: @ 81EA551
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	compare VAR_0x8008, 9
	call_if_eq LavaridgeTown_EventScript_1EA63A
	compare VAR_0x8008, 9
	call_if_ne LavaridgeTown_EventScript_1EA65C
	delay 20
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LavaridgeTown_EventScript_1EA630
	compare VAR_RESULT, FEMALE
	call_if_eq LavaridgeTown_EventScript_1EA635
	compare VAR_0x8008, 9
	call_if_eq LavaridgeTown_EventScript_1EA6A1
	compare VAR_0x8008, 9
	call_if_ne LavaridgeTown_EventScript_1EA6AC
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LavaridgeTown_EventScript_1EA5B5
	compare VAR_RESULT, FEMALE
	goto_if_eq LavaridgeTown_EventScript_1EA5DA
	end

LavaridgeTown_EventScript_1EA5B5:: @ 81EA5B5
	msgbox LavaridgeTown_Text_1EA7C0, MSGBOX_DEFAULT
	giveitem_std ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_1EA897, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_1EA5FF
	end

LavaridgeTown_EventScript_1EA5DA:: @ 81EA5DA
	msgbox LavaridgeTown_Text_1EA9A2, MSGBOX_DEFAULT
	giveitem_std ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_1EAA2E, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_1EA5FF
	end

LavaridgeTown_EventScript_1EA5FF:: @ 81EA5FF
	closemessage
	removeobject 8
	addobject 7
	delay 30
	compare VAR_0x8008, 9
	call_if_eq LavaridgeTown_EventScript_1EA6B7
	compare VAR_0x8008, 9
	call_if_ne LavaridgeTown_EventScript_1EA6C9
	removeobject 7
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_1EA630:: @ 81EA630
	playbgm MUS_GIRL_SUP, 1
	return

LavaridgeTown_EventScript_1EA635:: @ 81EA635
	playbgm MUS_BOY_SUP, 1
	return

LavaridgeTown_EventScript_1EA63A:: @ 81EA63A
	applymovement 8, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	playse SE_PIN
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

LavaridgeTown_EventScript_1EA65C:: @ 81EA65C
	opendoor 12, 15
	waitdooranim
	addobject 8
	applymovement 8, LavaridgeTown_Movement_1EA6F8
	waitmovement 0
	closedoor 12, 15
	waitdooranim
	applymovement 8, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	playse SE_PIN
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

LavaridgeTown_EventScript_1EA6A1:: @ 81EA6A1
	applymovement 8, LavaridgeTown_Movement_1EA6F4
	waitmovement 0
	return

LavaridgeTown_EventScript_1EA6AC:: @ 81EA6AC
	applymovement 8, LavaridgeTown_Movement_1EA6ED
	waitmovement 0
	return

LavaridgeTown_EventScript_1EA6B7:: @ 81EA6B7
	applymovement EVENT_OBJ_ID_PLAYER, LavaridgeTown_Movement_1EA6DF
	applymovement 7, LavaridgeTown_Movement_1EA6E3
	waitmovement 0
	return

LavaridgeTown_EventScript_1EA6C9:: @ 81EA6C9
	applymovement 7, LavaridgeTown_Movement_1EA6D4
	waitmovement 0
	return

LavaridgeTown_Movement_1EA6D4: @ 81EA6D4
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_1EA6DF: @ 81EA6DF
	delay_16
	delay_8
	walk_in_place_fastest_right
	step_end

LavaridgeTown_Movement_1EA6E3: @ 81EA6E3
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_1EA6ED: @ 81EA6ED
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_1EA6F4: @ 81EA6F4
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_1EA6F8: @ 81EA6F8
	walk_down
	step_end

LavaridgeTown_EventScript_1EA6FA:: @ 81EA6FA
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, 1
	goto_if_eq LavaridgeTown_EventScript_1EA70B
	end

LavaridgeTown_EventScript_1EA70B:: @ 81EA70B
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_1EA70E:: @ 81EA70E
	msgbox LavaridgeTown_Text_1EAE03, MSGBOX_NPC
	end

LavaridgeTown_EventScript_1EA717:: @ 81EA717
	msgbox LavaridgeTown_Text_1EAEE1, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_1EA720:: @ 81EA720
	msgbox LavaridgeTown_Text_1EAF9B, MSGBOX_NPC
	end

LavaridgeTown_EventScript_1EA729:: @ 81EA729
	msgbox LavaridgeTown_Text_1EB003, MSGBOX_NPC
	end

LavaridgeTown_EventScript_1EA732:: @ 81EA732
	msgbox LavaridgeTown_Text_1EB092, MSGBOX_NPC
	end

LavaridgeTown_EventScript_1EA73B:: @ 81EA73B
	msgbox LavaridgeTown_Text_1EAF4E, MSGBOX_NPC
	end

LavaridgeTown_EventScript_1EA744:: @ 81EA744
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_1EA787
	msgbox LavaridgeTown_Text_1EAB80, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LavaridgeTown_EventScript_1EA79B
	getpartysize
	compare VAR_RESULT, 6
	goto_if_eq LavaridgeTown_EventScript_1EA791
	msgbox LavaridgeTown_Text_1EACC0, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_FANFA4
	message LavaridgeTown_Text_1EACF4
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end

LavaridgeTown_EventScript_1EA787:: @ 81EA787
	msgbox LavaridgeTown_Text_1EAD9E, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_1EA791:: @ 81EA791
	msgbox LavaridgeTown_Text_1EAD09, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_1EA79B:: @ 81EA79B
	msgbox LavaridgeTown_Text_1EAD44, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_1EA7A5:: @ 81EA7A5
	msgbox LavaridgeTown_Text_1EB12B, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_1EA7AE:: @ 81EA7AE
	msgbox LavaridgeTown_Text_1EB178, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_1EA7B7:: @ 81EA7B7
	msgbox LavaridgeTown_Text_1EB1CB, MSGBOX_SIGN
	end

LavaridgeTown_Text_1EA7C0: @ 81EA7C0
	.string "FLORA: {PLAYER}{KUN}! Ça faisait un bail!\p"
	.string "Oh? Tu as eu le BADGE de VERMILAVA\n"
	.string "pendant que j'étais aux sources.\p"
	.string "Tu as dû attraper pas mal de POKéMON…\n"
	.string "Enfin, je devrais plutôt dire «dresser»\l"
	.string "pas mal de POKéMON.\p"
	.string "Je pense que ce serait bien pour toi\n"
	.string "d'avoir ça.$"

LavaridgeTown_Text_1EA897: @ 81EA897
	.string "FLORA: Avec ces LUNET. SABLE,\n"
	.string "tu pourras sans problème traverser le\l"
	.string "désert près de la ROUTE 111.\p"
	.string "Mais, waouh, {PLAYER}{KUN}…\n"
	.string "Te battre dans les ARENES…\p"
	.string "Tu t'entraînes dur car je parie que tu\n"
	.string "ne veux pas perdre contre moi!\p"
	.string "{PLAYER}{KUN}, je crois que je devrais défier\n"
	.string "ton père à l'ARENE de CLEMENTI-VILLE.\p"
	.string "A une prochaine fois, {PLAYER}{KUN}!$"

LavaridgeTown_Text_1EA9A2: @ 81EA9A2
	.string "BRICE: Hé, {PLAYER}, ça fait un bail.\n"
	.string "Comment ça va?\p"
	.string "Hum…\n"
	.string "Voilà une collection de BADGES\l"
	.string "plutôt honnête.\p"
	.string "Bon, très bien.\n"
	.string "Tu peux aussi prendre ça.$"

LavaridgeTown_Text_1EAA2E: @ 81EAA2E
	.string "BRICE: Prends-les avec toi si tu\n"
	.string "comptes aller dans ce désert, près de\l"
	.string "la ROUTE 111.\p"
	.string "Il devrait y avoir des POKéMON que tu\n"
	.string "ne peux affronter que dans le désert.\l"
	.string "Regarde autour de toi pour les trouver.\p"
	.string "En ce qui me concerne…\n"
	.string "J'envisage de défier NORMAN, le\l"
	.string "CHAMPION D'ARENE de CLEMENTI-VILLE.\p"
	.string "Contrairement à toi, {PLAYER}, ton père\n"
	.string "semble être très fort.\p"
	.string "A plus tard!$"

LavaridgeTown_Text_1EAB80: @ 81EAB80
	.string "J'ai un OEUF ici.\p"
	.string "J'espérais le faire éclore dans le\n"
	.string "sable chaud, près des sources chaudes.\l"
	.string "Mais ça n'a pas l'air de suffire…\p"
	.string "J'ai entendu dire qu'il valait mieux qu'il\n"
	.string "reste avec d'autres POKéMON, dans\l"
	.string "une équipe.\p"
	.string "Tu es DRESSEUR, n'est-ce pas?\n"
	.string "Et tes POKéMON dégagent de la vitalité.\p"
	.string "Alors, qu'est-ce que t'en dis?\n"
	.string "Tu veux bien ajouter cet OEUF\l"
	.string "à ton équipe pour le faire éclore?$"

LavaridgeTown_Text_1EACC0: @ 81EACC0
	.string "Bien! J'espère que cet OEUF ne va pas\n"
	.string "vous ralentir!$"

LavaridgeTown_Text_1EACF4: @ 81EACF4
	.string "{PLAYER} reçoit l'OEUF.$"

LavaridgeTown_Text_1EAD09: @ 81EAD09
	.string "Oh? Tu as trop de POKéMON.\n"
	.string "Il n'y a plus de place pour cet OEUF…$"

LavaridgeTown_Text_1EAD44: @ 81EAD44
	.string "Bon, comme tu veux…\p"
	.string "Si tu changes d'avis et que tu décides\n"
	.string "de faire éclore cet OEUF, je serai là.$"

LavaridgeTown_Text_1EAD9E: @ 81EAD9E
	.string "Parfois, on trouve des OEUFS\n"
	.string "à la PENSION POKéMON.\p"
	.string "En tout cas, c'est ce qu'il paraît.$"

LavaridgeTown_Text_1EAE03: @ 81EAE03
	.string "On prend toute notre eau chaude aux\n"
	.string "sources, mais elles ne s'assèchent pas.\p"
	.string "N'est-ce pas magique?\p"
	.string "Les sources chaudes se forment près\n"
	.string "des volcans actifs. Des filets d'eau,\l"
	.string "chauffés par le magma, jaillissent de\l"
	.string "la terre sous forme de sources chaudes.$"

LavaridgeTown_Text_1EAEE1: @ 81EAEE1
	.string "Etre enseveli dans ce sable chaud…\n"
	.string "Ahhhh…\p"
	.string "Si chaud et divin…\p"
	.string "Eh? Aaaaah! Ouille!\p"
	.string "Un POKéMON m'a pincé le dos!$"

LavaridgeTown_Text_1EAF4E: @ 81EAF4E
	.string "Oh, tu aimes les sources chaudes,\n"
	.string "n'est-ce pas?\p"
	.string "C'est surprenant pour quelqu'un d'aussi\n"
	.string "jeune que toi.$"

LavaridgeTown_Text_1EAF9B: @ 81EAF9B
	.string "Je me baigne chaque jour dans les\n"
	.string "sources chaudes.\p"
	.string "Je veux être DRESSEUR comme\n"
	.string "ADRIANE, et aussi belle et forte qu'elle.$"

LavaridgeTown_Text_1EB003: @ 81EB003
	.string "Si on mettait des POKéMON dans les\n"
	.string "sources, ça pourrait être très étrange.\p"
	.string "Ça pourrait être un bain électrique, un\n"
	.string "bain de bulles ou même un bain de lave…$"

LavaridgeTown_Text_1EB092: @ 81EB092
	.string "Ils affirment que ces sources chaudes\n"
	.string "calment la nervosité, soulagent les\l"
	.string "douleurs musculaires, peuvent résoudre\l"
	.string "les soucis de cœur et attirent l'argent.$"

LavaridgeTown_Text_1EB12B: @ 81EB12B
	.string "VERMILAVA\p"
	.string "“CENTRE POKéMON des SOURCES\n"
	.string "CHAUDES. Détente garantie!”$"

LavaridgeTown_Text_1EB178: @ 81EB178
	.string "ARENE POKéMON de VERMILAVA\n"
	.string "CHAMPION: ADRIANE\l"
	.string "“Ici brûle le feu de la passion!”$"

LavaridgeTown_Text_1EB1CB: @ 81EB1CB
	.string "HERBORISTERIE POKéMON\n"
	.string "“Plus c'est amer et plus c'est sain!”$"

