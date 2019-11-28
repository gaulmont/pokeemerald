BattleFrontier_BattleTowerMultiBattleRoom_MapScripts:: @ 8243D92
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiBattleRoom_MapScript1_243DA7
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiBattleRoom_MapScript1_243DB0
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiBattleRoom_MapScript2_243E14
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiBattleRoom_MapScript2_243E23
	.byte 0

BattleFrontier_BattleTowerMultiBattleRoom_MapScript1_243DA7: @ 8243DA7
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_RESTORE_PARTY
	special CallBattlePyramidFunction
	end

BattleFrontier_BattleTowerMultiBattleRoom_MapScript1_243DB0: @ 8243DB0
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243DDA
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	setvar VAR_0x8004, 10
	special sub_8161F74
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243DDA:: @ 8243DDA
	setvar VAR_OBJ_GFX_ID_0, EVENT_OBJ_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, EVENT_OBJ_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, EVENT_OBJ_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, EVENT_OBJ_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, EVENT_OBJ_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, EVENT_OBJ_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, EVENT_OBJ_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, EVENT_OBJ_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm 1, 10, 2
	end

BattleFrontier_BattleTowerMultiBattleRoom_MapScript2_243E14: @ 8243E14
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E1E
	.2byte 0

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E1E:: @ 8243E1E
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiBattleRoom_MapScript2_243E23: @ 8243E23
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E41
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E35
	.2byte 0

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E35:: @ 8243E35
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243EB5
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E41:: @ 8243E41
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243E75
	waitmovement 0
	applymovement 1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243E77
	waitmovement 0
	copyobjectxytoperm 1
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiBattleRoom_Text_244056, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243E75: @ 8243E75
	walk_down
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243E77: @ 8243E77
	walk_left
	walk_in_place_fastest_down
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E7A:: @ 8243E7A
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_244094
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E9D
	msgbox BattleFrontier_BattleTowerMultiBattleRoom_Text_24410C, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E9D:: @ 8243E9D
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 1
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_241C03
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243EB5:: @ 8243EB5
	msgbox BattleFrontier_BattleTowerMultiBattleRoom_Text_244149, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243EE4
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 255, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243EE4:: @ 8243EE4
	applymovement 1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F26
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F1A
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243EF6: @ 8243EF6
	applymovement 1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F26
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F1E
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F08: @ 8243F08
	applymovement 1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F26
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F22
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F1A: @ 8243F1A
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F1E: @ 8243F1E
	walk_right
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F22: @ 8243F22
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F26: @ 8243F26
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F29:: @ 8243F29
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36:: @ 8243F36
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FC3
	setvar VAR_0x8004, 11
	setvar VAR_0x8005, 0
	special sub_8161F74
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 11
	setvar VAR_0x8005, 1
	special sub_8161F74
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 11
	setvar VAR_0x8005, 2
	special sub_8161F74
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FC3
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FC3
	setvar VAR_0x8004, 11
	setvar VAR_0x8005, 3
	special sub_8161F74
	waitmessage
	waitbuttonpress
	closemessage
	compare VAR_FACING, DIR_SOUTH
	call_if_ne BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FD4
	compare VAR_FACING, DIR_SOUTH
	call_if_eq BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FDF
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_BATTLE_ROOM, 255, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FC3:: @ 8243FC3
	setvar VAR_0x8004, 11
	setvar VAR_0x8005, 4
	special sub_8161F74
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FD4:: @ 8243FD4
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243FEA
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FDF:: @ 8243FDF
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243FF2
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243FEA: @ 8243FEA
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243FF2: @ 8243FF2
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FFB:: @ 8243FFB
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_244008:: @ 8244008
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_244015:: @ 8244015
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_244022:: @ 8244022
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_24402F:: @ 824402F
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_24403C:: @ 824403C
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_244049:: @ 8244049
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_Text_244056: @ 8244056
	.string "Veuillez choisir le DRESSEUR qui sera\n"
	.string "votre partenaire.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244094: @ 8244094
	.string "{PLAYER}, vous n'avez pas trouvé\n"
	.string "de partenaire.\p"
	.string "Voulez-vous arrêter de chercher et\n"
	.string "retourner au guichet d'inscription?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24410C: @ 824410C
	.string "Alors je vous prie de choisir l'un de ces\n"
	.string "DRESSEURS comme partenaire.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244149:: @ 8244149
	.string "Merci d'avoir choisi un partenaire.\p"
	.string "Je vais maintenant vous mener à votre\n"
	.string "SALLE DE COMBAT MULTI.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24419A:: @ 824419A
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
	.string "You can call me {STR_VAR_3}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2441CA:: @ 82441CA
	.string "On {STR_VAR_1}'s advice, I brought\n"
	.string "one {STR_VAR_3} with {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2441F7:: @ 82441F7
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Please, let me join you as a tag team.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24422E:: @ 824422E
	.string "Thank you!\n"
	.string "I'll go register right now.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244255:: @ 8244255
	.string "I really wanted to form a tag team\n"
	.string "with you, {PLAYER}…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244286:: @ 8244286
	.string "I am {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
	.string "My name is {STR_VAR_3}.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2442B2:: @ 82442B2
	.string "I got advice from {STR_VAR_1} and chose\n"
	.string "one {STR_VAR_3} with {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2442E4:: @ 82442E4
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Please, let's form a tag team!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244313:: @ 8244313
	.string "Thank you very much!\n"
	.string "I'll be done with registration quickly!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244350:: @ 8244350
	.string "{PLAYER}, I was hoping that I could\n"
	.string "partner up with you…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244383:: @ 8244383
	.string "Hum, je m'appelle {STR_VAR_3}. Je suis\n"
	.string "l'apprenti nº {STR_VAR_2} de {STR_VAR_1}.\p"
	.string "Sniff…\p"
	.string "Je suis désolé!\n"
	.string "Je ne supporte pas cette pression…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2443E7:: @ 82443E7
	.string "{STR_VAR_3} m'a conseillé. J'ai un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244413:: @ 8244413
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Sniff…\n"
	.string "S'il te plaît, fais équipe avec moi!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24444B:: @ 824444B
	.string "Vraiment? Tu veux bien?\n"
	.string "Super! Extra!\p"
	.string "Oh… Je suis désolé…\n"
	.string "Ce sont des larmes de joie…\p"
	.string "Je vais nous inscrire tout de suite.\n"
	.string "Surtout, reste ici!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2444D6:: @ 82444D6
	.string "Oh, mais…\n"
	.string "Sniff… Ouin!!!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2444EF:: @ 82444EF
	.string "Bonjour! Je suis {STR_VAR_3}!\n"
	.string "Je suis l'apprenti nº {STR_VAR_2} de {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24451E:: @ 824451E
	.string "{STR_VAR_3} a choisi mon équipe!\n"
	.string "J'ai un {STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244549:: @ 8244549
	.string "et un {STR_VAR_2} avec {STR_VAR_1}!\n"
	.string "Plutôt pas mal, hein?\p"
	.string "Allez, vas-y!\n"
	.string "Fais équipe avec moi!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24459B:: @ 824459B
	.string "Ouais, super!\n"
	.string "Je vais m'inscrire, alors!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2445C5:: @ 82445C5
	.string "Mais pourquoi, d'abord?\n"
	.string "Je veux faire équipe avec toi, {PLAYER}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2445E8:: @ 82445E8
	.string "Je suis {STR_VAR_3}, l'apprenti nº {STR_VAR_2}\n"
	.string "de {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244618:: @ 8244618
	.string "J'ai demandé conseil à {STR_VAR_3}.\n"
	.string "Un {STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244643:: @ 8244643
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}, voilà ce que j'ai.\p"
	.string "S'il te plaît, tu veux bien faire\n"
	.string "équipe avec moi?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24468F:: @ 824468F
	.string "Merci!\n"
	.string "Je vais nous inscrire tout de suite!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2446B4:: @ 82446B4
	.string "{PLAYER}, j'avais tellement envie de\n"
	.string "faire équipe avec toi…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2446E5:: @ 82446E5
	.string "Oh… Ça me fait plaisir\n"
	.string "que tu viennes me parler.\p"
	.string "Je m'appelle {STR_VAR_3}.\n"
	.string "Je suis l'apprentie nº {STR_VAR_2} de {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24474D:: @ 824474D
	.string "{STR_VAR_3} a bien voulu me conseiller.\n"
	.string "Je lui dois tant de choses!\p"
	.string "Dans mon équipe, j'ai un {STR_VAR_2}\n"
	.string "qui utilise {STR_VAR_1} et un$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24479E:: @ 824479E
	.string "{STR_VAR_2} qui utilise {STR_VAR_1}.\n"
	.string "Je sais que j'en demande trop…\p"
	.string "Tu vas sûrement refuser, mais tu veux\n"
	.string "bien qu'on fasse équipe?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24480C:: @ 824480C
	.string "Vraiment? Je n'arrive pas à le croire!\n"
	.string "On va faire équipe!\l"
	.string "Je… Je serai à la hauteur!\p"
	.string "Bon… Je vais vite nous inscrire\n"
	.string "avant que tu ne changes d'avis!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2448A7:: @ 82448A7
	.string "Je comprends…\n"
	.string "Je ne suis pas à la hauteur…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2448CD:: @ 82448CD
	.string "Salut, je m'appelle {STR_VAR_3}.\n"
	.string "Je suis l'apprentie nº {STR_VAR_2} de {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2448F5:: @ 82448F5
	.string "C'est {STR_VAR_3} qui a fait mon équipe!\n"
	.string "J'ai un {STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244939:: @ 8244939
	.string "et un {STR_VAR_2} qui connaît\n"
	.string "{STR_VAR_1}.\p"
	.string "Pas mal, non?\n"
	.string "Alors, on fait équipe?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244989:: @ 8244989
	.string "D'accord!\n"
	.string "J'espère qu'on va bien s'entendre!\l"
	.string "Je vais nous inscrire.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2449E6:: @ 82449E6
	.string "Quoi? Tu refuses?\n"
	.string "Tu ne sais pas ce que tu perds!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244A23:: @ 8244A23
	.string "Je m'appelle {STR_VAR_3}. Je suis\n"
	.string "TRIATHLETE. Je n'arrête pas!\l"
	.string "Footing, entraînement, danse…\p"
	.string "Et je suis aussi l'apprenti nº {STR_VAR_2}\n"
	.string "de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244AA9:: @ 8244AA9
	.string "Voilà ce que {STR_VAR_3} m'a conseillé.\n"
	.string "Un {STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244AD6:: @ 8244AD6
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "Malgré tout ce que j'ai à faire, j'ai\n"
	.string "trouvé le temps de les dresser!\p"
	.string "On fait équipe et on voit ce que\n"
	.string "ça donne?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244B52:: @ 8244B52
	.string "Merci! Tu as l'esprit sportif!\n"
	.string "Ne bouge pas, je vais nous inscrire?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244B93:: @ 8244B93
	.string "Je vois. Pour ta gouverne, je déteste\n"
	.string "qu'on me fasse perdre mon temps!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244BD2:: @ 8244BD2
	.string "Bonjour!\n"
	.string "Comment ça va?\p"
	.string "Je suis {STR_VAR_3}, l'apprentie nº {STR_VAR_2}\n"
	.string "de {STR_VAR_1}. Enchantée!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244C18:: @ 8244C18
	.string "Ecoute, écoute! C'est {STR_VAR_3} qui\n"
	.string "a composé mon équipe POKéMON.\l"
	.string "J'ai un {STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244C6E:: @ 8244C6E
	.string "et un {STR_VAR_2} avec {STR_VAR_1}.\n"
	.string "Je les ai bien dressés!\p"
	.string "Tu veux qu'on fasse équipe?\n"
	.string "Je suis sûre qu'on ira bien ensemble!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244CD6:: @ 8244CD6
	.string "Super, on va bien s'amuser!\n"
	.string "Je vais nous inscrire!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244D07:: @ 8244D07
	.string "Quelle méchanceté!\n"
	.string "Je suis sûre que tu vas le regretter.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244D36:: @ 8244D36
	.string "Je me présente, je m'appelle\n"
	.string "{STR_VAR_3}.\p"
	.string "Je suis l'apprentie nº {STR_VAR_2}\n"
	.string "de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244D82:: @ 8244D82
	.string "J'ai suivi les conseils de {STR_VAR_3}\n"
	.string "et dans mon équipe j'ai un\l"
	.string "{STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244DC6:: @ 8244DC6
	.string "et un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "On fait équipe ensemble?\n"
	.string "S'il te plaît!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244DFE:: @ 8244DFE
	.string "Oh… J'en suis ravie!\n"
	.string "Je vais donner tout ce que j'ai!\p"
	.string "Allez, je vais nous inscrire!\n"
	.string "Attends-moi ici!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244E5B:: @ 8244E5B
	.string "J'espérais vraiment être ta partenaire,\n"
	.string "{PLAYER}…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244E7E:: @ 8244E7E
	.string "Hé, tu m'as parlée!\n"
	.string "Ça me fait tellement plaisir!\p"
	.string "Je m'appelle {STR_VAR_3}! Je suis\n"
	.string "l'apprentie nº {STR_VAR_2} de {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244ECA:: @ 8244ECA
	.string "J'ai écouté {STR_VAR_3} et j'ai dressé\n"
	.string "un {STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244EF4:: @ 8244EF4
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "Tu veux bien exaucer mon souhait?\n"
	.string "J'aimerais faire équipe avec toi!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244F4F:: @ 8244F4F
	.string "Oh… C'est un jour merveilleux!\n"
	.string "Merci infiniment!\l"
	.string "Je vais nous inscrire sur le champ!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244F98:: @ 8244F98
	.string "Oh! Tu n'as donc aucun cœur?\n"
	.string "Mais je t'admire, tu sais…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244FD3:: @ 8244FD3
	.string "Bonjour! Je suis l'apprenti nº {STR_VAR_2}\n"
	.string "de {STR_VAR_1}!\p"
	.string "Je m'appelle {STR_VAR_3}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245013:: @ 8245013
	.string "Mon mentor {STR_VAR_3} m'a conseillé\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24503D:: @ 824503D
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Pas mal, non?\n"
	.string "On fait équipe, alors?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245087:: @ 8245087
	.string "Excellent!\n"
	.string "Je vais nous inscrire vite fait!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2450C0:: @ 82450C0
	.string "Je me méfierai de toi à l'avenir,\n"
	.string "{PLAYER}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2450E6:: @ 82450E6
	.string "Tu sais quoi? C'est le dernier jour\n"
	.string "de la TOUR DE COMBAT!\p"
	.string "… … … … … …\n"
	.string "Mais non, je rigole!\p"
	.string "On m'appelle {STR_VAR_3}. Normal, c'est\n"
	.string "mon nom! Je suis l'apprenti nº 1 000 de\l"
	.string "{STR_VAR_1}. Non, je suis le nº {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245196:: @ 8245196
	.string "{STR_VAR_3} m'a recommandé\n"
	.string "les {STR_VAR_2} utilisant {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2451BD:: @ 82451BD
	.string "et les {STR_VAR_2} utilisant\n"
	.string "{STR_VAR_1}. J'en ai dix de chaque.\l"
	.string "Je rigole, j'en ai qu'un de chaque!\p"
	.string "Alors, on fait équipe, toi et moi?\n"
	.string "Qu'en dis-tu?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24522F:: @ 824522F
	.string "Youpi!\n"
	.string "Allez, je te donne un POKéMON!\p"
	.string "Tu m'as pas cru, j'espère! Je passe au\n"
	.string "guichet d'inscription et je reviens!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24529A:: @ 824529A
	.string "Tu me le paieras! Je vais faire de\n"
	.string "ta vie un enfer!\p"
	.string "Mais non, je rigole! Ha, ha, ha!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2452EF:: @ 82452EF
	.string "Salut, DRESSEUR!\n"
	.string "J'attends ici depuis des heures!\p"
	.string "Non, je ne suis pas un requin blanc…\n"
	.string "Je suis {STR_VAR_3}, le MARIN chantant!\p"
	.string "Je suis l'apprenti nº {STR_VAR_2} de {STR_VAR_1}.\n"
	.string "Avec moi, ça va swinguer!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2453B4:: @ 82453B4
	.string "Les conseils de {STR_VAR_3}, je les ai\n"
	.string "suivis, et mon équipe a bien grandi!\l"
	.string "J'ai un {STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245406:: @ 8245406
	.string "et un {STR_VAR_2} avec\n"
	.string "{STR_VAR_1}!\p"
	.string "Faisons équipe,\n"
	.string "nom d'une pipe!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245464:: @ 8245464
	.string "Hé, hé, j'aime ton style!\n"
	.string "Je vais nous inscrire, je file!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2454A3:: @ 82454A3
	.string "Hé, {PLAYER}! Tu me surprends!\n"
	.string "Moi, j'étais partant!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2454D6:: @ 82454D6
	.string "Yahou, yippie!\n"
	.string "Oh, je t'en prie, reste!\p"
	.string "Je m'appelle {STR_VAR_3}!\n"
	.string "Je suis l'apprenti nº {STR_VAR_2} de {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245535:: @ 8245535
	.string "{STR_VAR_3} m'a dit quoi faire.\n"
	.string "J'ai un {STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24555F:: @ 824555F
	.string "et un {STR_VAR_2} avec\n"
	.string "{STR_VAR_1}.\p"
	.string "Qu'en dis-tu?\n"
	.string "Me choisiras-tu?\p"
	.string "Laisse-moi être ton partenaire!\n"
	.string "Allez… Accepte, partenaire!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2455EC:: @ 82455EC
	.string "Oh, ça me fait tellement plaisir!\n"
	.string "Je ne sais pas quoi dire!\p"
	.string "Je vais nous inscrire!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245656:: @ 8245656
	.string "Tu me rejettes?\n"
	.string "{PLAYER}, ton comportement est abject!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24568A:: @ 824568A
	.string "Oh, je tousse!\p"
	.string "Désolé, j'ai pris froid.\n"
	.string "Mes POKéMON vont bien, eux.\p"
	.string "Je m'appelle {STR_VAR_3}. Je suis\n"
	.string "l'apprenti nº {STR_VAR_2} de {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2456F5:: @ 82456F5
	.string "{STR_VAR_3} a formé mon équipe.\n"
	.string "J'ai un {STR_VAR_2} qui utilise\l"
	.string "{STR_VAR_1} et aussi un$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245740:: @ 8245740
	.string "{STR_VAR_2} qui utilise {STR_VAR_1}.\p"
	.string "Je les entraîne tous les jours, qu'il\n"
	.string "pleuve, qu'il neige, qu'il vente!\p"
	.string "C'est d'ailleurs pour ça que j'ai pris\n"
	.string "froid, je pense.\p"
	.string "Maintenant que tu me connais un peu,\n"
	.string "tu veux qu'on fasse équipe?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2457D9:: @ 82457D9
	.string "Merci! Ça me fait plaisir!\n"
	.string "Je n'arrête pas de tousser… \l"
	.string "Allez, je vais nous inscrire.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24581F:: @ 824581F
	.string "Tu ne veux pas?\n"
	.string "Quel dommage, {PLAYER}.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245851:: @ 8245851
	.string "Bonjour!\n"
	.string "Il y a trop de monde, ici… \p"
	.string "Je m'appelle {STR_VAR_3}.\n"
	.string "Je suis l'apprenti nº {STR_VAR_2} de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24589C:: @ 824589C
	.string "{STR_VAR_3} m'a conseillé cette équipe… \n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2458CE:: @ 82458CE
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Ça me met mal à l'aise de te parler… \n"
	.string "Mais veux-tu qu'on fasse équipe?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245923:: @ 8245923
	.string "Oh, merci!\n"
	.string "J'ai peur mais je ferai de mon mieux!\p"
	.string "Je vais nous inscrire.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24597F:: @ 824597F
	.string "Tu ne peux pas refuser!\n"
	.string "Je crois que je vais faire un malaise…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2459BE:: @ 82459BE
	.string "Je m'appelle {STR_VAR_3}, je suis\n"
	.string "l'apprenti nº {STR_VAR_2} de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2459F7:: @ 82459F7
	.string "Je dois mon équipe à {STR_VAR_3}.\p"
	.string "J'ai suivi ses conseils. J'ai un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et un$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245A5F:: @ 8245A5F
	.string "{STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Si tu es d'accord, j'aimerais être ton\n"
	.string "partenaire.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245AB4:: @ 8245AB4
	.string "Tu acceptes?\n"
	.string "Tu ne le regretteras pas!\p"
	.string "Je vais nous inscrire et nous pourrons\n"
	.string "commencer!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245B3E:: @ 8245B3E
	.string "Tu refuses?\n"
	.string "Ton humour est totalement déplacé.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245B79:: @ 8245B79
	.string "Je m'appelle {STR_VAR_1}.\n"
	.string "Je suis une FILLETTE!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245B91:: @ 8245B91
	.string "J'ai un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1} et puis un$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245BBD:: @ 8245BBD
	.string "{STR_VAR_2} qui utilise {STR_VAR_1}.\n"
	.string "C'est tout ce que j'ai avec moi.\p"
	.string "On fait équipe?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245C05:: @ 8245C05
	.string "Merci!\n"
	.string "Je vais nous inscrire!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245C2D:: @ 8245C2D
	.string "Tu ne veux pas de moi comme partenaire?\n"
	.string "Tu vas t'en mordre les doigts!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245C66:: @ 8245C66
	.string "Salut!\p"
	.string "Je suis GAMIN {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245C7F:: @ 8245C7F
	.string "Tu veux savoir ce que j'ai?\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245CAC:: @ 8245CAC
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "On va faire équipe, toi et moi,\n"
	.string "non?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245CE6:: @ 8245CE6
	.string "Chouette!\n"
	.string "Je vais nous inscrire, alors!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245D07:: @ 8245D07
	.string "Tu as tort! Avec tes POKéMON et les\n"
	.string "miens, on serait invincibles!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245D4B:: @ 8245D4B
	.string "Bien le bonjour!\n"
	.string "Je suis MONTAGNARD {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245D60:: @ 8245D60
	.string "Tu veux savoir ce que j'ai avec moi?\n"
	.string "Un {STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245D8D:: @ 8245D8D
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}!\p"
	.string "Pas trop mal, non?\n"
	.string "Tu veux qu'on fasse équipe?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245DC7:: @ 8245DC7
	.string "D'accord!\n"
	.string "Je vais au guichet et je reviens.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245DF0:: @ 8245DF0
	.string "Dommage, j'aurais aimé me battre à tes\n"
	.string "côtés.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245E20:: @ 8245E20
	.string "Bonjour! Je m'appelle {STR_VAR_1}\n"
	.string "et je suis un CANON!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245E41:: @ 8245E41
	.string "Tu sais ce que j'ai dressé?\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245E78:: @ 8245E78
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "Qu'en penses-tu?\n"
	.string "Tu veux qu'on fasse équipe?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245EBD:: @ 8245EBD
	.string "Merveilleux!\n"
	.string "Je vais au guichet!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245EEC:: @ 8245EEC
	.string "Quel dommage!\p"
	.string "Toi et moi, nous aurions fait une belle\n"
	.string "équipe!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245F2B:: @ 8245F2B
	.string "Bonjour, toi!\p"
	.string "Tu sais qui je suis?\n"
	.string "Je suis {STR_VAR_1} le PECHEUR!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245F58:: @ 8245F58
	.string "Mon équipe se compose d'un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245F87:: @ 8245F87
	.string "d'un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Qu'en dis-tu?\n"
	.string "On fait équipe?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245FC6:: @ 8245FC6
	.string "Bien, bien!\n"
	.string "Je me charge de tout!\p"
	.string "Je vais nous inscrire tout de suite.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246002:: @ 8246002
	.string "Oh, c'est bien dommage…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246020:: @ 8246020
	.string "Ravie de te rencontrer.\n"
	.string "Je suis MADEMOISELLE {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246051:: @ 8246051
	.string "Je suis accompagnée d'un\n"
	.string "{STR_VAR_2} maîtrisant {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246082:: @ 8246082
	.string "et d'un {STR_VAR_2} maîtrisant\n"
	.string "{STR_VAR_1}.\p"
	.string "M'acceptes-tu comme partenaire?\n"
	.string "Cela me ferait tant plaisir!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2460D5:: @ 82460D5
	.string "Je te remercie du fond du cœur.\n"
	.string "Je m'occupe de l'inscription.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24610D:: @ 824610D
	.string "Je suis sûre que tu vas le regretter.\n"
	.string "Cependant, je respecte ta décision.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24614A:: @ 824614A
	.string "Je m'appelle {STR_VAR_1}. Je suis\n"
	.string "TRIATHLETE!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24615D:: @ 824615D
	.string "Voyons ce que j'ai…\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24617D:: @ 824617D
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\n"
	.string "C'est mon équipe!\p"
	.string "Dis, tu veux bien qu'on soit\n"
	.string "partenaires?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2461C7:: @ 82461C7
	.string "Merci!\n"
	.string "Je vais nous inscrire.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2461F5:: @ 82461F5
	.string "C'est dommage, je sais qu'on aurait été\n"
	.string "très forts ensemble!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24622A:: @ 824622A
	.string "Bonjour!\n"
	.string "Je suis le SCOUT {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246244:: @ 8246244
	.string "Regarde ce que j'ai!\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24626E:: @ 824626E
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "Je te propose que nous fassions\n"
	.string "équipe, tous les deux! Tu es d'accord?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2462AA:: @ 82462AA
	.string "Bien!\p"
	.string "Je m'occupe de l'inscription,\n"
	.string "partenaire.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2462E4:: @ 82462E4
	.string "Tu sais, mes POKéMON valent le détour.\n"
	.string "J'espère que tu ne le regretteras pas!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24631F:: @ 824631F
	.string "Bonjour!\n"
	.string "Je suis l'ELEVE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24633C:: @ 824633C
	.string "J'ai dressé un {STR_VAR_2}\n"
	.string "qui utilise {STR_VAR_1} et un$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24636B:: @ 824636B
	.string "{STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "C'est plutôt bien, non?\n"
	.string "Tu veux qu'on fasse équipe?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2463C5:: @ 82463C5
	.string "Merci!\n"
	.string "Je m'occupe de l'inscription.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2463FF:: @ 82463FF
	.string "Je suis déçu…\p"
	.string "En me battant avec toi, j'aurais pu\n"
	.string "apprendre un tas de choses…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246449:: @ 8246449
	.string "Bonjour.\n"
	.string "Je suis RICHARD {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246478:: @ 8246478
	.string "Tu ne devineras jamais ce que j'ai!\n"
	.string "Un {STR_VAR_2} utilisant {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24649D:: @ 824649D
	.string "et un {STR_VAR_2} utilisant\n"
	.string "{STR_VAR_1}!\p"
	.string "Si tu le souhaites, tu peux faire équipe\n"
	.string "avec moi.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2464EE:: @ 82464EE
	.string "C'est intelligent de ta part! Avec moi,\n"
	.string "impossible de perdre!\p"
	.string "Je m'occupe de l'inscription!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246529:: @ 8246529
	.string "Tu vas le regretter!\n"
	.string "Je suis le meilleur dans cette pièce!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246571:: @ 8246571
	.string "Hiyah!\n"
	.string "Je suis KARATEKA {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24658C:: @ 824658C
	.string "J'ai un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2465B5:: @ 82465B5
	.string "un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "Sois sympa, choisis-moi comme\n"
	.string "partenaire!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246605:: @ 8246605
	.string "Hiyah!\n"
	.string "Je vais nous inscrire illico presto!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24662A:: @ 824662A
	.string "Je comprends…\n"
	.string "Ce n'est que partie remise…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246662:: @ 8246662
	.string "Bonjour!\n"
	.string "Je suis FLOTTEUR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246686:: @ 8246686
	.string "Voilà ce que j'ai…\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2466B4:: @ 82466B4
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\n"
	.string "Tu veux bien qu'on fasse équipe?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2466E6:: @ 82466E6
	.string "Merci!\n"
	.string "Je vais nous inscrire immédiatement!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24670A:: @ 824670A
	.string "Ensemble, on aurait pu battre\n"
	.string "n'importe qui, j'en suis sûre!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246741:: @ 8246741
	.string "Bien le bonjour…\n"
	.string "Je suis MYSTIMANIAC {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246760:: @ 8246760
	.string "J'ai sur moi un {STR_VAR_2} qui\n"
	.string "utilise {STR_VAR_1} et un$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246791:: @ 8246791
	.string "{STR_VAR_2} qui utilise {STR_VAR_1}…\p"
	.string "Je t'en supplie…\n"
	.string "Choisis-moi comme partenaire…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2467C4:: @ 82467C4
	.string "Je te remercie…\n"
	.string "Je vais nous inscrire…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2467E6:: @ 82467E6
	.string "J'espérais tant qu'on fasse équipe…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2467FF:: @ 82467FF
	.string "Comment ça va? Je m'appelle\n"
	.string "{STR_VAR_1}. Je suis un ELEVEUR!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246831:: @ 8246831
	.string "J'ai deux POKéMON pas mal du tout!\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246864:: @ 8246864
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "Qu'en penses-tu?\n"
	.string "Tu penses qu'on devrait faire équipe?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2468A7:: @ 82468A7
	.string "Je te remercie!\p"
	.string "Ne bouge pas, je vais au guichet\n"
	.string "d'inscription!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2468FE:: @ 82468FE
	.string "J'aurais préféré que tu dises oui,\n"
	.string "bien sûr… Mais tant pis!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24692B:: @ 824692B
	.string "Bonjour! Je m'appelle {STR_VAR_1}.\n"
	.string "Je suis TRIATHLETE!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24694B:: @ 824694B
	.string "Tu veux savoir ce que j'ai?\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24697C:: @ 824697C
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "Alors?\n"
	.string "On fait équipe?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2469B4:: @ 82469B4
	.string "C'est parti!\n"
	.string "Je vais nous inscrire sur le champ!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2469F1:: @ 82469F1
	.string "Toi et moi, on aurait fait un carton!\n"
	.string "Tu ne sais pas ce que tu rates…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246A22:: @ 8246A22
	.string "Bonjour! Je m'appelle {STR_VAR_1}!\n"
	.string "Je suis TRIATHLETE!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246A4E:: @ 8246A4E
	.string "J'ai bien entraîné mes POKéMON! J'ai\n"
	.string "un {STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246A85:: @ 8246A85
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}!\p"
	.string "Il y a pire, non?\n"
	.string "Tu veux de moi comme partenaire?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246ACF:: @ 8246ACF
	.string "Très bien!\n"
	.string "Je cours nous inscrire!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246AF7:: @ 8246AF7
	.string "J'aurais bien aimé combattre\n"
	.string "à tes côtés…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246B2B:: @ 8246B2B
	.string "Je suis COMBATTANTE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246B3F:: @ 8246B3F
	.string "J'ai dressé un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1} et un$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246B6B:: @ 8246B6B
	.string "{STR_VAR_2} qui utilise {STR_VAR_1}!\p"
	.string "Alors, ça te plaît?\n"
	.string "Si on faisait équipe?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246BB2:: @ 8246BB2
	.string "Oh, merci!\p"
	.string "Je m'occupe de l'inscription,\n"
	.string "ne bouge pas!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246BE9:: @ 8246BE9
	.string "Je suis sûre qu'ensemble, on aurait\n"
	.string "été imbattables…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246C22:: @ 8246C22
	.string "Je m'appelle {STR_VAR_1}.\n"
	.string "Je suis TRIATHLETE!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246C35:: @ 8246C35
	.string "J'ai un {STR_VAR_2} à qui j'ai appris\n"
	.string "{STR_VAR_1} et un$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246C6C:: @ 8246C6C
	.string "{STR_VAR_2} qui connaît {STR_VAR_1}!\p"
	.string "On ferait une équipe du tonnerre,\n"
	.string "tous les deux! Non?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246CB3:: @ 8246CB3
	.string "Merci!\p"
	.string "Il ne reste plus qu'à nous inscrire.\n"
	.string "J'y cours!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246CE9:: @ 8246CE9
	.string "C'est dommage. Je me faisais une telle\n"
	.string "joie à l'idée de combattre à tes côtés!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246D2D:: @ 8246D2D
	.string "Moi?\n"
	.string "Je suis FLOTTEUR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246D3F:: @ 8246D3F
	.string "Ce que j'ai? Un {STR_VAR_2} qui\n"
	.string "connaît {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246D6A:: @ 8246D6A
	.string "un {STR_VAR_2} qui connaît\n"
	.string "{STR_VAR_1}!\p"
	.string "Alors, on fait équipe?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246D9E:: @ 8246D9E
	.string "D'accord!\p"
	.string "Je vais nous inscrire!\n"
	.string "Ça va déménager!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246DD3:: @ 8246DD3
	.string "Mes POKéMON sont forts…\n"
	.string "C'est bête que tu ne veuilles pas de moi.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246E1A:: @ 8246E1A
	.string "Bonjour!\n"
	.string "Je suis GUITARISTE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246E39:: @ 8246E39
	.string "Regarde qui est là…\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246E64:: @ 8246E64
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "On pourrait pas rêver mieux, non?\n"
	.string "Alors, on fait équipe?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246EB6:: @ 8246EB6
	.string "Super! Je vais m'occuper des formalités\n"
	.string "au guichet. Je reviens!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246EEE:: @ 8246EEE
	.string "Mes POKéMON sont les meilleurs!\n"
	.string "Tu risques de le regretter!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246F21:: @ 8246F21
	.string "Ravi de faire ta connaissance.\n"
	.string "Je suis {STR_VAR_1}, un vrai GENTLEMAN.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246F4C:: @ 8246F4C
	.string "Mon cher {STR_VAR_2} avec\n"
	.string "{STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246F7B:: @ 8246F7B
	.string "mon cher {STR_VAR_2} avec\n"
	.string "{STR_VAR_1} sont ici.\p"
	.string "Puis-je te demander de me choisir\n"
	.string "comme partenaire?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246FCC:: @ 8246FCC
	.string "Je te remercie de ta confiance.\n"
	.string "Reste ici, je m'occupe de l'inscription.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247013:: @ 8247013
	.string "Cela m'aurait fait tant plaisir…\p"
	.string "J'espère que nous aurons l'occasion de\n"
	.string "faire équipe une autre fois…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24705B:: @ 824705B
	.string "Bonjour, je m'appelle {STR_VAR_1}.\n"
	.string "Je suis POKéFAN!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24707D:: @ 824707D
	.string "Avec moi, j'ai un {STR_VAR_2}\n"
	.string "qui utilise {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2470B2:: @ 82470B2
	.string "un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "Est-ce que ça te plaît?\n"
	.string "On fait équipe?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2470FD:: @ 82470FD
	.string "Merci!\n"
	.string "Je m'occupe de l'inscription!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24712A:: @ 824712A
	.string "Tu ne sais pas reconnaître de bons\n"
	.string "POKéMON quand tu en vois…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24716C:: @ 824716C
	.string "Je suis {STR_VAR_1}. Je suis un EXPERT!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24718D:: @ 824718D
	.string "J'ai élevé un {STR_VAR_2} qui connaît\n"
	.string "{STR_VAR_1} et un$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2471C7:: @ 82471C7
	.string "{STR_VAR_2} qui connaît {STR_VAR_1}!\p"
	.string "Que dirais-tu de faire équipe avec moi?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2471FB:: @ 82471FB
	.string "Parfait!\n"
	.string "Je vais de ce pas nous inscrire!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247238:: @ 8247238
	.string "Je doute que tu aies fait le bon choix…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247268:: @ 8247268
	.string "Bonjour, bonjour!\n"
	.string "Je suis EXPERT {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247291:: @ 8247291
	.string "J'ai élevé mes POKéMON avec soin.\n"
	.string "J'ai un {STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2472C7:: @ 82472C7
	.string "et un {STR_VAR_2} avec {STR_VAR_1}.\n"
	.string "Voilà!\p"
	.string "Voudrais-tu faire équipe avec moi?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247313:: @ 8247313
	.string "Bien, bien.\n"
	.string "Je vais de suite nous inscrire.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247348:: @ 8247348
	.string "D'accord. On remet ça à une prochaine\n"
	.string "fois, alors.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24737A:: @ 824737A
	.string "Je suis DRACOLOGUE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24738F:: @ 824738F
	.string "Mon équipe se compose d'un\n"
	.string "{STR_VAR_2} utilisant {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2473C6:: @ 82473C6
	.string "et d'un {STR_VAR_2} utilisant\n"
	.string "{STR_VAR_1}!\p"
	.string "Qu'est-ce que tu en dis?\n"
	.string "Tu me prends comme partenaire?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2473FB:: @ 82473FB
	.string "Je te promets de faire de mon mieux!\n"
	.string "Je m'occupe de l'inscription, d'accord?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247438:: @ 8247438
	.string "Tu sais, tu ne trouveras pas mieux que\n"
	.string "moi, ici!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247470:: @ 8247470
	.string "Je suis l'ORNITHOLOGUE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247484:: @ 8247484
	.string "Quels POKéMON j'ai? Un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2474AF:: @ 82474AF
	.string "et un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Tu ne penses pas qu'on ferait une bonne\n"
	.string "équipe, toi et moi?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2474EC:: @ 82474EC
	.string "Super, merci!\n"
	.string "Je vais m'occuper de l'inscription!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24751D:: @ 824751D
	.string "Mes POKéMON et moi sommes très\n"
	.string "forts. Quel dommage pour toi!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24754A:: @ 824754A
	.string "Je suis NINJA FAN {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24755C:: @ 824755C
	.string "Mon équipe de POKéMON comporte\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24758B:: @ 824758B
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "Faisons équipe, tous les deux!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2475BC:: @ 82475BC
	.string "Ouais!\n"
	.string "Je me charge de l'inscription!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2475D5:: @ 82475D5
	.string "Tu vas regretter de ne pas avoir mes\n"
	.string "POKéMON à tes côtés!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24760D:: @ 824760D
	.string "Bonjour!\n"
	.string "Je suis SŒUR PARASOL {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247629:: @ 8247629
	.string "Je ne suis pas seule. J'ai avec moi un\n"
	.string "{STR_VAR_2} utilisant {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247655:: @ 8247655
	.string "un {STR_VAR_2} utilisant\n"
	.string "{STR_VAR_1}.\p"
	.string "N'est-ce pas merveilleux?\n"
	.string "Tu veux faire équipe avec nous?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24769B:: @ 824769B
	.string "Merci beaucoup!\p"
	.string "Je vais nous inscrire au guichet.\n"
	.string "Nous ferons de notre mieux!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2476ED:: @ 82476ED
	.string "Mes POKéMON sont incroyablement forts.\n"
	.string "Quelle déception…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247724:: @ 8247724
	.string "Bonjour!\n"
	.string "Je suis {STR_VAR_1} l'ENTOMOMANIAC!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247749:: @ 8247749
	.string "Oui, j'ai trouvé mes POKéMON.\n"
	.string "J'ai un {STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24777A:: @ 824777A
	.string "et {STR_VAR_2} avec {STR_VAR_1}.\n"
	.string "C'est tout ce que j'ai trouvé.\p"
	.string "Ça t'intéresse de faire équipe avec\n"
	.string "moi?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2477CE:: @ 82477CE
	.string "Compris!\n"
	.string "Super!\p"
	.string "Je m'occupe de l'inscription.\n"
	.string "Ça ne prendra pas longtemps!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247807:: @ 8247807
	.string "Avec mes POKéMON, on aurait gagné à\n"
	.string "coup sûr, tu sais?…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247838:: @ 8247838
	.string "Bonjour!\n"
	.string "Je suis MARIN {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247854:: @ 8247854
	.string "Mes POKéMON sont ma fierté! J'ai un\n"
	.string "{STR_VAR_2} utilisant {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247889:: @ 8247889
	.string "et un {STR_VAR_2} utilisant\n"
	.string "{STR_VAR_1}!\p"
	.string "Tu veux faire équipe avec moi,\n"
	.string "n'est-ce pas?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2478DD:: @ 82478DD
	.string "J'en étais sûr!\n"
	.string "Je m'occupe de l'inscription.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24790D:: @ 824790D
	.string "Avec mes POKéMON et moi, c'était\n"
	.string "pourtant la victoire assurée!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247942:: @ 8247942
	.string "Bonjour, je suis COLLEC {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24795F:: @ 824795F
	.string "J'ai ici deux beaux spécimens: un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247991:: @ 8247991
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "C'est le nec plus ultra en matière de\n"
	.string "POKéMON, non? On fait équipe?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2479CE:: @ 82479CE
	.string "Oh, super!\p"
	.string "Ne perdons pas de temps.\n"
	.string "Je vais nous inscrire!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247A18:: @ 8247A18
	.string "Ça me chiffonne un peu…\n"
	.string "Tu n'aimes pas mes POKéMON…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247A51:: @ 8247A51
	.string "Bonjour, je m'appelle {STR_VAR_1}.\n"
	.string "Je suis un POKéMON RANGER.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247A76:: @ 8247A76
	.string "Je suis escorté par un\n"
	.string "{STR_VAR_2} qui utilise {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247AA1:: @ 8247AA1
	.string "un {STR_VAR_2} qui\n"
	.string "utilise {STR_VAR_1}!\p"
	.string "Tu ne penses pas qu'on ferait une\n"
	.string "équipe du tonnerre, toi et moi?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247AE3:: @ 8247AE3
	.string "C'est super!\n"
	.string "Je vais m'occuper de l'inscription.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247B16:: @ 8247B16
	.string "La prochaine fois, choisis mes POKéMON\n"
	.string "où je risque de me vexer…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247B3E:: @ 8247B3E
	.string "Je suis {STR_VAR_1}, une\n"
	.string "POKéMON RANGER!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247B62:: @ 8247B62
	.string "Voici mon équipe: j'ai un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247B9B:: @ 8247B9B
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "Tu veux faire équipe avec mes petits\n"
	.string "protégés et moi?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247BE7:: @ 8247BE7
	.string "Nous ferons de notre mieux, c'est\n"
	.string "promis! Je vais nous inscrire!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247C23:: @ 8247C23
	.string "J'espère que tu nous choisiras, la\n"
	.string "prochaine fois…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247C4E:: @ 8247C4E
	.string "Ravie de faire ta connaissance. Je suis\n"
	.string "AROMA {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247C8C:: @ 8247C8C
	.string "Je sillonne les chemins avec un\n"
	.string "{STR_VAR_2} utilisant {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247CB2:: @ 8247CB2
	.string "et un {STR_VAR_2} utilisant\n"
	.string "{STR_VAR_1}.\p"
	.string "J'espère qu'ils te conviennent.\n"
	.string "Tu veux bien qu'on soit partenaires?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247D07:: @ 8247D07
	.string "Ton choix m'honore.\n"
	.string "Je vais au guichet d'inscription.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247D4E:: @ 8247D4E
	.string "Cela me ferait plaisir de faire équipe\n"
	.string "avec toi une prochaine fois.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247D97:: @ 8247D97
	.string "Tu veux savoir qui je suis?\n"
	.string "Je suis RUINEMANIAC {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247DC7:: @ 8247DC7
	.string "Les POKéMON qui m'accompagnent sont\n"
	.string "un {STR_VAR_2} utilisant {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247DFE:: @ 8247DFE
	.string "et un {STR_VAR_2} utilisant\n"
	.string "{STR_VAR_1}!\p"
	.string "Intrigant, n'est-ce pas?\n"
	.string "Si nous faisions équipe?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247E3E:: @ 8247E3E
	.string "C'est une sage décision! Je me charge\n"
	.string "des formalités d'inscription.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247E7E:: @ 8247E7E
	.string "Hum…\n"
	.string "Mes POKéMON sont très forts pourtant…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247EA1:: @ 8247EA1
	.string "Je suis TOPDRESSEUR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247EB5:: @ 8247EB5
	.string "J'ai amené un {STR_VAR_2}\n"
	.string "qui sait utiliser {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247EE9:: @ 8247EE9
	.string "un {STR_VAR_2} qui sait utiliser\n"
	.string "{STR_VAR_1}. Impressionnant, je sais!\p"
	.string "Dis, tu ne crois pas qu'on devrait faire\n"
	.string "équipe, toi et moi?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247F3F:: @ 8247F3F
	.string "Cool! Je vais vite au guichet\n"
	.string "d'inscription!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247F6D:: @ 8247F6D
	.string "On aurait pourtant bien combattu\n"
	.string "ensemble.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247FA3:: @ 8247FA3
	.string "Je suis TOPDRESSEUR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247FB7:: @ 8247FB7
	.string "L'équipe que j'ai formée comporte un\n"
	.string "{STR_VAR_2} utilisant {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247FE9:: @ 8247FE9
	.string "un {STR_VAR_2} utilisant {STR_VAR_1}.\p"
	.string "Ça correspond à ce que tu cherches?\n"
	.string "On fait équipe?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248031:: @ 8248031
	.string "J'espérais que tu dirais ça!\n"
	.string "Je vais nous inscrire, alors.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24805E:: @ 824805E
	.string "Je pensais qu'on aurait fait une\n"
	.string "belle équipe…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24808D:: @ 824808D
	.string "Bonjour!\n"
	.string "Je suis POKéMANIAC {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2480AB:: @ 82480AB
	.string "Tu te demandes ce que j'ai?\n"
	.string "Un {STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2480DC:: @ 82480DC
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}. Oui, rien que ça!\p"
	.string "Je sais que ça t'impressionne.\n"
	.string "Allez, faisons équipe!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248128:: @ 8248128
	.string "Excellente décision!\n"
	.string "Je vais nous inscrire!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248151:: @ 8248151
	.string "Rien ne peut arrêter mes POKéMON!\n"
	.string "Tu vas regretter ta décision!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24818E:: @ 824818E
	.string "Salut, toi! Je m'appelle {STR_VAR_1}!\n"
	.string "Je suis un SALTIMBANQUE.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2481A9:: @ 82481A9
	.string "Voici le fruit de mon entraînement:\n"
	.string "un {STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2481E1:: @ 82481E1
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}!\p"
	.string "Alors, qu'en dis-tu?\n"
	.string "On fait équipe?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248221:: @ 8248221
	.string "Bien!\n"
	.string "Je m'occupe de l'inscription.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24824F:: @ 824824F
	.string "Quel dommage. Promets-moi qu'on\n"
	.string "fera équipe la prochaine fois.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248297:: @ 8248297
	.string "Je suis CAMPEUR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2482B1:: @ 82482B1
	.string "J'ai dressé un {STR_VAR_2} qui sait\n"
	.string "utiliser {STR_VAR_1} et un$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2482DC:: @ 82482DC
	.string "{STR_VAR_2} qui sait utiliser\n"
	.string "{STR_VAR_1}.\p"
	.string "On s'amuserait bien si on était dans la\n"
	.string "même équipe! Alors, on essaie?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248321:: @ 8248321
	.string "Super!\n"
	.string "Sur ce, je vais nous inscrire!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24833D:: @ 824833D
	.string "Bon, une prochaine fois, alors!\n"
	.string "J'aimerais bien combattre à tes côtés!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248369:: @ 8248369
	.string "Bonjour!\n"
	.string "Je suis PIQUE-NIQUE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24838D:: @ 824838D
	.string "J'ai avec moi un {STR_VAR_2}\n"
	.string "qui utilise {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2483C1:: @ 82483C1
	.string "un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "Ça te dirait de faire équipe avec moi?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248401:: @ 8248401
	.string "Eh bien, merci!\n"
	.string "Je me charge de l'inscription.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248431:: @ 8248431
	.string "D'accord. J'espère qu'on fera équipe\n"
	.string "une prochaine fois.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248467:: @ 8248467
	.string "Je suis KINESISTE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248477:: @ 8248477
	.string "Les deux POKéMON que j'ai dressés sont\n"
	.string "un {STR_VAR_2} utilisant {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2484AC:: @ 82484AC
	.string "et un {STR_VAR_2} utilisant\n"
	.string "{STR_VAR_1}.\p"
	.string "Qu'en dis-tu?\n"
	.string "On est partenaires?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2484E7:: @ 82484E7
	.string "Très bien!\n"
	.string "Je vais nous inscrire!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248517:: @ 8248517
	.string "D'accord. Mais tu dois me promettre\n"
	.string "qu'on fera équipe bientôt.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248553:: @ 8248553
	.string "Je suis KINESISTE {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24856A:: @ 824856A
	.string "J'ai avec moi…\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24857D:: @ 824857D
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\n"
	.string "Ce sont mes disciples.\p"
	.string "Je suis sûre que tout cela t'intrigue…\n"
	.string "Si tu veux, nous pouvons faire équipe.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2485E5:: @ 82485E5
	.string "Merci.\n"
	.string "Je vais nous inscrire.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248614:: @ 8248614
	.string "J'espère qu'il y aura une autre\n"
	.string "occasion. Tu m'intrigues…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24864E:: @ 824864E
	.string "Je suis ELEVE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248661:: @ 8248661
	.string "Mes POKéMON? J'ai un\n"
	.string "{STR_VAR_2} qui utilise {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248671:: @ 8248671
	.string "un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "Ça me plairait bien d'être ta\n"
	.string "partenaire. Tu es d'accord?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2486C6:: @ 82486C6
	.string "Oh, merci! Je vais aller au guichet\n"
	.string "pour nous inscrire!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2486FF:: @ 82486FF
	.string "Hein?\n"
	.string "La prochaine fois alors, non?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248725:: @ 8248725
	.string "Coucou! Je suis {STR_VAR_1}, un\n"
	.string "ELEVEUR!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248751:: @ 8248751
	.string "Voici les POKéMON que j'ai dressés: un\n"
	.string " {STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248781:: @ 8248781
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "C'est plutôt tentant, je sais.\n"
	.string "On fait équipe, d'accord?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2487C9:: @ 82487C9
	.string "Parfait!\n"
	.string "Laisse-moi m'occuper de l'inscription!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2487F7:: @ 82487F7
	.string "Je comprends, mais la prochaine fois,\n"
	.string "tu ne pourras pas refuser!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248829:: @ 8248829
	.string "Je suis {STR_VAR_1}. Je suis une\n"
	.string "POKéFAN.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24885B:: @ 824885B
	.string "Mes POKéMON chéris sont un\n"
	.string "{STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248892:: @ 8248892
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "Ne sont-ils pas mignons?\n"
	.string "Il faut absolument qu'on fasse équipe!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2488D8:: @ 82488D8
	.string "Je te remercie!\n"
	.string "Je m'occupe de l'inscription!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248908:: @ 8248908
	.string "Mes POKéMON chéris sont les meilleurs,\n"
	.string "crois-moi. Mais c'est toi qui décides!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24894B:: @ 824894B
	.string "Bonjour! Je suis {STR_VAR_1},\n"
	.string "une NAGEUSE.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24895F:: @ 824895F
	.string "J'ai entraîné un {STR_VAR_2} qui\n"
	.string "sait utiliser {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24896F:: @ 824896F
	.string "un {STR_VAR_2} qui sait utiliser\n"
	.string "{STR_VAR_1}.\p"
	.string "Si on faisait équipe, toi et moi?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2489BD:: @ 82489BD
	.string "Super!\n"
	.string "Je vais nous inscrire.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2489E7:: @ 82489E7
	.string "Si jamais on se rencontre de nouveau,\n"
	.string "tu ne pourras pas refuser!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248A10:: @ 8248A10
	.string "Oui? Je m'appelle {STR_VAR_1}\n"
	.string "et je suis TRIATHLETE.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248A40:: @ 8248A40
	.string "J'ai quelques POKéMON qui se défendent:\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248A72:: @ 8248A72
	.string "un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}!\p"
	.string "Ce serait sympa si on faisait équipe,\n"
	.string "tous les deux.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248AC0:: @ 8248AC0
	.string "Merveilleux!\n"
	.string "Je vais nous inscrire.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248AEB:: @ 8248AEB
	.string "Tu me laisseras être ton partenaire\n"
	.string "la prochaine fois, j'espère.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248B22:: @ 8248B22
	.string "Je suis {STR_VAR_1}, une TRIATHLETE!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248B39:: @ 8248B39
	.string "Un {STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248B4C:: @ 8248B4C
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}, voilà ce que j'ai.\p"
	.string "Qu'en penses-tu?\n"
	.string "Je pense qu'on ferait une bonne équipe.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248BB4:: @ 8248BB4
	.string "J'aime cette réponse!\n"
	.string "Je m'occupe de l'inscription!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248BEE:: @ 8248BEE
	.string "Promets-moi que tu me donneras\n"
	.string "bientôt ma chance…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248C2E:: @ 8248C2E
	.string "Bonjour, bonjour!\n"
	.string "Je suis {STR_VAR_1}, un NAGEUR!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248C5B:: @ 8248C5B
	.string "Regarde quels POKéMON j'ai dressés!\n"
	.string "Un {STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248C90:: @ 8248C90
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}!\p"
	.string "Pas mal, non?\n"
	.string "Alors, on fait équipe?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248CCF:: @ 8248CCF
	.string "Quel honneur!\n"
	.string "Je me charge de l'inscription!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248D04:: @ 8248D04
	.string "On remet ça à une prochaine fois,\n"
	.string "d'accord?$"

