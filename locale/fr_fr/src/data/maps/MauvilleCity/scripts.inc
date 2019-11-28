MauvilleCity_MapScripts:: @ 81DF385
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
	.byte 0

MauvilleCity_OnTransition: @ 81DF38B
	setflag FLAG_VISITED_MAUVILLE_CITY
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	clearflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
	setflag FLAG_SYS_TV_START
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	setvar VAR_MAUVILLE_GYM_STATE, 0
	call_if_set FLAG_GOT_TM24_FROM_WATTSON, MauvilleCity_EventScript_1DF3A9
	end

MauvilleCity_EventScript_1DF3A9:: @ 81DF3A9
	clearflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
	return

MauvilleCity_EventScript_1DF3B3:: @ 81DF3B3
	msgbox MauvilleCity_Text_1E0301, MSGBOX_NPC
	end

MauvilleCity_EventScript_1DF3BC:: @ 81DF3BC
	msgbox MauvilleCity_Text_1E037C, MSGBOX_NPC
	end

MauvilleCity_EventScript_1DF3C5:: @ 81DF3C5
	msgbox MauvilleCity_Text_1E03FB, MSGBOX_NPC
	end

MauvilleCity_EventScript_1DF3CE:: @ 81DF3CE
	msgbox MauvilleCity_Text_1E044A, MSGBOX_NPC
	end

MauvilleCity_EventScript_1DF3D7:: @ 81DF3D7
	msgbox MauvilleCity_Text_1E0485, MSGBOX_SIGN
	end

MauvilleCity_EventScript_1DF3E0:: @ 81DF3E0
	msgbox MauvilleCity_Text_1E04B7, MSGBOX_SIGN
	end

MauvilleCity_EventScript_1DF3E9:: @ 81DF3E9
	msgbox MauvilleCity_Text_1E0504, MSGBOX_SIGN
	end

MauvilleCity_EventScript_1DF3F2:: @ 81DF3F2
	msgbox MauvilleCity_Text_1E053C, MSGBOX_SIGN
	end

MauvilleCity_EventScript_1DF3FB:: @ 81DF3FB
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_1DF413
	msgbox MauvilleCity_Text_1E056A, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

MauvilleCity_EventScript_1DF413:: @ 81DF413
	msgbox MauvilleCity_Text_1E0699, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_1DF41D:: @ 81DF41D
	lock
	faceplayer
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_1DF43D
	msgbox MauvilleCity_Text_1DF7DC, MSGBOX_DEFAULT
	closemessage
	applymovement 7, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_1DF43D:: @ 81DF43D
	msgbox MauvilleCity_Text_1DFAA5, MSGBOX_DEFAULT
	closemessage
	applymovement 7, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_1DF452:: @ 81DF452
	lockall
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_1DF690
	applymovement 6, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox MauvilleCity_Text_1DF845, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_1DF8B9, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_1DF963, MSGBOX_DEFAULT
	applymovement 6, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement 6, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_Text_1DF9B2, MSGBOX_YESNO
	goto MauvilleCity_EventScript_1DF4AD
	end

MauvilleCity_EventScript_1DF4AD:: @ 81DF4AD
	compare VAR_RESULT, 1
	call_if_eq MauvilleCity_EventScript_1DF63A
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_EventScript_1DF683
	closemessage
	switch VAR_FACING
	case DIR_NORTH, MauvilleCity_EventScript_1DF4E0
	case DIR_EAST, MauvilleCity_EventScript_1DF53D
	end

MauvilleCity_EventScript_1DF4E0:: @ 81DF4E0
	applymovement EVENT_OBJ_ID_PLAYER, MauvilleCity_Movement_1DF6DF
	applymovement 6, MauvilleCity_Movement_1DF6A8
	applymovement 7, MauvilleCity_Movement_1DF6E2
	waitmovement 0
	applymovement 6, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	delay 30
	applymovement EVENT_OBJ_ID_PLAYER, MauvilleCity_Movement_1DF6EE
	applymovement 7, MauvilleCity_Movement_1DF6F3
	waitmovement 0
	msgbox MauvilleCity_Text_1DFD34, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, MauvilleCity_Movement_1DF6CC
	applymovement 7, MauvilleCity_Movement_1DF6FA
	applymovement 6, MauvilleCity_Movement_1DF6B4
	waitmovement 0
	goto MauvilleCity_EventScript_1DF593
	end

MauvilleCity_EventScript_1DF53D:: @ 81DF53D
	applymovement EVENT_OBJ_ID_PLAYER, MauvilleCity_Movement_1DF6DC
	applymovement 6, MauvilleCity_Movement_1DF6AE
	applymovement 7, MauvilleCity_Movement_1DF6E8
	waitmovement 0
	applymovement 6, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	delay 30
	applymovement 7, MauvilleCity_Movement_1DF6F7
	waitmovement 0
	msgbox MauvilleCity_Text_1DFD34, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, MauvilleCity_Movement_1DF6D0
	applymovement 7, MauvilleCity_Movement_1DF703
	applymovement 6, MauvilleCity_Movement_1DF6C0
	waitmovement 0
	goto MauvilleCity_EventScript_1DF593
	end

MauvilleCity_EventScript_1DF593:: @ 81DF593
	removeobject 6
	removeobject 7
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	compare VAR_FACING, DIR_NORTH
	call_if_eq MauvilleCity_EventScript_1DF5F3
	compare VAR_FACING, DIR_EAST
	call_if_eq MauvilleCity_EventScript_1DF601
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox MauvilleCity_Text_1DFED5, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	compare VAR_FACING, DIR_NORTH
	call_if_eq MauvilleCity_EventScript_1DF616
	compare VAR_FACING, DIR_EAST
	call_if_eq MauvilleCity_EventScript_1DF628
	removeobject 11
	releaseall
	end

MauvilleCity_EventScript_1DF5F3:: @ 81DF5F3
	addobject 11
	applymovement 11, MauvilleCity_Movement_1DF70D
	waitmovement 0
	return

MauvilleCity_EventScript_1DF601:: @ 81DF601
	setobjectxyperm 11, 12, 13
	addobject 11
	applymovement 11, MauvilleCity_Movement_1DF719
	waitmovement 0
	return

MauvilleCity_EventScript_1DF616:: @ 81DF616
	applymovement EVENT_OBJ_ID_PLAYER, MauvilleCity_Movement_1DF6D5
	applymovement 11, MauvilleCity_Movement_1DF725
	waitmovement 0
	return

MauvilleCity_EventScript_1DF628:: @ 81DF628
	applymovement EVENT_OBJ_ID_PLAYER, MauvilleCity_Movement_1DF6D8
	applymovement 11, MauvilleCity_Movement_1DF72F
	waitmovement 0
	return

MauvilleCity_EventScript_1DF63A:: @ 81DF63A
	msgbox MauvilleCity_Text_1DFB6D, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_2, MauvilleCity_Text_1DFB96
	applymovement 6, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox MauvilleCity_Text_1DFBC3, MSGBOX_DEFAULT
	applymovement 6, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_1DFBED, MSGBOX_DEFAULT
	applymovement 6, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox MauvilleCity_Text_1DFC8A, MSGBOX_DEFAULT
	return

MauvilleCity_EventScript_1DF683:: @ 81DF683
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
	msgbox MauvilleCity_Text_1DFA4A, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_1DF690:: @ 81DF690
	applymovement 6, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_1DFB42, MSGBOX_YESNO
	goto MauvilleCity_EventScript_1DF4AD
	end

MauvilleCity_Movement_1DF6A8: @ 81DF6A8
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

MauvilleCity_Movement_1DF6AE: @ 81DF6AE
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_1DF6B4: @ 81DF6B4
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_1DF6C0: @ 81DF6C0
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_1DF6CC: @ 81DF6CC
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

MauvilleCity_Movement_1DF6D0: @ 81DF6D0
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

MauvilleCity_Movement_1DF6D5: @ 81DF6D5
	delay_16
	walk_in_place_fastest_left
	step_end

MauvilleCity_Movement_1DF6D8: @ 81DF6D8
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

MauvilleCity_Movement_1DF6DC: @ 81DF6DC
	delay_16
	walk_in_place_fastest_down
	step_end

MauvilleCity_Movement_1DF6DF: @ 81DF6DF
	delay_16
	walk_in_place_fastest_left
	step_end

MauvilleCity_Movement_1DF6E2: @ 81DF6E2
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

MauvilleCity_Movement_1DF6E8: @ 81DF6E8
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_1DF6EE: @ 81DF6EE
	delay_16
	delay_8
	delay_4
	walk_in_place_fastest_down
	step_end

MauvilleCity_Movement_1DF6F3: @ 81DF6F3
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

MauvilleCity_Movement_1DF6F7: @ 81DF6F7
	walk_right
	walk_up
	step_end

MauvilleCity_Movement_1DF6FA: @ 81DF6FA
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_1DF703: @ 81DF703
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_1DF70D: @ 81DF70D
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

MauvilleCity_Movement_1DF719: @ 81DF719
	walk_up
	walk_up
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

MauvilleCity_Movement_1DF725: @ 81DF725
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_1DF72F: @ 81DF72F
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_EventScript_1DF73A:: @ 81DF73A
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM24_FROM_WATTSON, MauvilleCity_EventScript_1DF7B0
	compare VAR_NEW_MAUVILLE_STATE, 2
	goto_if_eq MauvilleCity_EventScript_1DF784
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_1DF77A
	msgbox MauvilleCity_Text_1DFFE4, MSGBOX_DEFAULT
	giveitem_std ITEM_BASEMENT_KEY
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
	msgbox MauvilleCity_Text_1E0154, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_1DF77A:: @ 81DF77A
	msgbox MauvilleCity_Text_1E0154, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_1DF784:: @ 81DF784
	msgbox MauvilleCity_Text_1E020E, MSGBOX_DEFAULT
	giveitem_std ITEM_TM24
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM24_FROM_WATTSON
	msgbox MauvilleCity_Text_1E02AA, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_1DF7B0:: @ 81DF7B0
	msgbox MauvilleCity_Text_1E02AA, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_1DF7BA:: @ 81DF7BA
	lockall
	pokenavcall MauvilleCity_Text_1DFDFB
	waitmessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox MauvilleCity_Text_1DFEB4, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
	clearflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	releaseall
	end

#ifdef FRENCH

MauvilleCity_Text_1DF7DC: @ 81DF7DC
	.string "TONTON: C'est grâce aux POKéMON\n"
	.string "que ce garçon a retrouvé la pêche…\l"
	.string "Mais il l'a même un peu trop maintenant…$"

MauvilleCity_Text_1DF845: @ 81DF845
	.string "TIMMY: Oh, TONTON, s'il te plaît?\p"
	.string "Je veux me battre dans cette ARENE\n"
	.string "pour voir à quel point j'ai progressé.\p"
	.string "S'il te plaît! Je peux?$"

MauvilleCity_Text_1DF8B9: @ 81DF8B9
	.string "TONTON: Attends, TIMMY.\p"
	.string "Depuis que tu as commencé à vivre avec\n"
	.string "ton POKéMON, tu es devenu plus fort.\p"
	.string "Mais tu ne trouves pas que combattre\n"
	.string "dans une ARENE est un peu prématuré?$"

MauvilleCity_Text_1DF963: @ 81DF963
	.string "TIMMY: Pas du tout.\p"
	.string "Quand je suis avec mon TARSAL,\n"
	.string "on peut battre n'importe qui!$"

MauvilleCity_Text_1DF9B2: @ 81DF9B2
	.string "TIMMY: Oh! Salut, {PLAYER}!\p"
	.string "Je suis devenu bien plus fort depuis\n"
	.string "notre dernière rencontre.\p"
	.string "{PLAYER}, je veux que mon oncle et toi\n"
	.string "compreniez ça.\p"
	.string "{PLAYER}, tu acceptes de te battre\n"
	.string "contre moi?$"

MauvilleCity_Text_1DFA4A: @ 81DFA4A
	.string "TIMMY: Oh… Si tu n'accceptes pas de\n"
	.string "m'affronter, mon oncle ne pourra pas\l"
	.string "voir que je suis devenu vraiment fort.$"

MauvilleCity_Text_1DFAA5: @ 81DFAA5
	.string "TONTON: {PLAYER}{KUN}.\n"
	.string "De la part de TIMMY, je peux te\l"
	.string "demander de l'affronter juste une fois?\p"
	.string "Vu l'état dans lequel il est, je ne pense\n"
	.string "pas qu'il reviendra à la raison.$"

MauvilleCity_Text_1DFB42: @ 81DFB42
	.string "TIMMY: {PLAYER}, s'il te plaît!\n"
	.string "Bats-toi contre moi, je t'en supplie.$"

MauvilleCity_Text_1DFB6D: @ 81DFB6D
	.string "TIMMY: Merci, {PLAYER}.\p"
	.string "OK. J'arrive!$"

MauvilleCity_Text_1DFB96: @ 81DFB96
	.string "TIMMY: … … … … … … …\p"
	.string "… … … … … … … …\p"
	.string "J'ai perdu…$"

MauvilleCity_Text_1DFBC3: @ 81DFBC3
	.string "TIMMY: TONTON…\n"
	.string "Je vais rentrer à VERGAZON…$"

MauvilleCity_Text_1DFBED: @ 81DFBED
	.string "Merci, {PLAYER}.\n"
	.string "C'est dur d'être DRESSEUR, hein?\p"
	.string "Il ne suffit pas d'avoir des POKéMON\n"
	.string "et de les envoyer au combat. C'est pas\l"
	.string "ça être un vrai DRESSEUR.$"

MauvilleCity_Text_1DFC8A: @ 81DFC8A
	.string "TONTON: TIMMY, ce n'est pas la peine\n"
	.string "d'être aussi dur avec toi-même.\p"
	.string "Rien ne t'empêche de devenir encore\n"
	.string "plus fort!\p"
	.string "Allez viens, rentrons chez nous.\n"
	.string "Tout le monde t'attend.$"

MauvilleCity_Text_1DFD34: @ 81DFD34
	.string "TONTON: {PLAYER}{KUN}, je viens juste de\n"
	.string "réaliser que tu dois être le DRESSEUR\l"
	.string "qui a gardé un œil sur TIMMY quand il\l"
	.string "a attrapé son POKéMON.\p"
	.string "Pourquoi ne viendrais-tu pas nous voir\n"
	.string "à VERGAZON un de ces jours?\l"
	.string "Ça ferait sûrement plaisir à TIMMY.$"


MauvilleCity_Text_1DFDFB: @ 81DFDFB
	.string "… … … … … …\n"
	.string "… … … … … Bip!\p"
	.string "TIMMY: Oh, bonjour, {PLAYER}!\p"
	.string "Je voulais juste te dire que mon\n"
	.string "oncle m'a acheté un POKéNAV!\p"
	.string "Je peux t'appeler quand je veux!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

MauvilleCity_Text_1DFEB4: @ 81DFEB4
	.string "Vous avez enregistré TIMMY dans\n"
	.string "dans votre POKéNAV.$"

MauvilleCity_Text_1DFED5: @ 81DFED5
	.string "SCOTT: Héhé…\n"
	.string "J'ai assisté à ton combat!\p"
	.string "TIMMY et toi êtes amis, n'est-ce pas?\p"
	.string "Mais tu n'as pourtant pas retenu tes\n"
	.string "coups et tu l'as battu magistralement!\p"
	.string "C'est ça que j'aime dans les combats\n"
	.string "de POKéMON!\p"
	.string "J'adore les DRESSEURS comme toi!\p"
	.string "… … … … … …\n"
	.string "Tu peux compter sur moi pour\n"
	.string "t'encourager!$"

MauvilleCity_Text_1DFFE4: @ 81DFFE4
	.string "VOLTERE: Oh, {PLAYER}{KUN}!\n"
	.string "Tu sembles avoir beaucoup d'entrain!\l"
	.string "C'est une bonne chose, ah, ah, ah!\p"
	.string "Bien! J'ai pris une décision!\n"
	.string "J'ai une faveur à te demander, {PLAYER}{KUN}!\p"
	.string "LAVANDIA comprend une partie\n"
	.string "souterraine appelée NEW LAVANDIA.\p"
	.string "{PLAYER}{KUN}, j'aimerais que tu t'y rendes et\n"
	.string "que tu éteignes le GENERATEUR.\p"
	.string "Le GENERATEUR fonctionne un peu\n"
	.string "bizarrement. Ça devient dangereux.\p"
	.string "Tiens, voilà la CLE pour pouvoir\n"
	.string "entrer dans NEW LAVANDIA.$"

MauvilleCity_Text_1E0154: @ 81E0154
	.string "VOLTERE: Ne t'inquiète pas pour ça.\n"
	.string "Ce ne sera pas trop dur pour toi.\p"
	.string "Pour arriver à NEW LAVANDIA, un peu de\n"
	.string "SURF au bout de la ROUTE 110 suffira.\p"
	.string "C'est tout. Alros tu as ma confiance!\n"
	.string "Wahahahaha!$"

MauvilleCity_Text_1E020E: @ 81E020E
	.string "VOLTERE: Wahahahaha!\p"
	.string "Je l'savais, {PLAYER}{KUN}! Je savais que\n"
	.string "j'avais raison en m'adressantà toi!\p"
	.string "Voilà ma façon de te remercier: une CT\n"
	.string "contenant TONNERRE!\p"
	.string "Allez, tu l'as bien méritée!$"

MauvilleCity_Text_1E02AA: @ 81E02AA
	.string "VOLTERE: Wahahahaha!\p"
	.string "Je suis très content de voir les jeunes\n"
	.string "avancer et prendre les choses en main!$"

MauvilleCity_Text_1E0301: @ 81E0301
	.string "Tu sais, c'est bien gentil d'envoyer les\n"
	.string "POKéMON au combat…\p"
	.string "Mais si un des tes POKéMONest blessé, tu\n"
	.string "dois le soigner pour qu'il soit en forme.$"

MauvilleCity_Text_1E037C: @ 81E037C
	.string "Les routes de cette ville s'étendent du\n"
	.string "nord au sud et d'est en ouest.\p"
	.string "Alors ici, les gens viennent de partout.$"

MauvilleCity_Text_1E03FB: @ 81E03FB
	.string "Tu connais les CYCLES RODOLPHE?\p"
	.string "RODOLPHE, le propriétaire, est une homme\n"
	.string "très généreux.$"

MauvilleCity_Text_1E044A: @ 81E044A
	.string "Même si tu es sur ton VELO, les,\n"
	.string "POKéMON peuvent te sauter dessus.$"

MauvilleCity_Text_1E0485: @ 81E0485
	.string "LAVANDIA\n"
	.string "“La brillante ville du fun!”$"

MauvilleCity_Text_1E04B7: @ 81E04B7
	.string "ARENE POKéMON de LAVANDIA\n"
	.string "CHAMPION : VOLTERE\l"
	.string "“Un homme électrifiant!”$"

MauvilleCity_Text_1E0504: @ 81E0504
	.string "“Roule sur le gravier et remets\n"
	.string "tes idées en place!”\l"
	.string "CYCLES RODOLPHE$"

MauvilleCity_Text_1E053C: @ 81E053C
	.string "“La salle de jeux pour tous!”\n"
	.string "CASION DE LAVANDIA$"

MauvilleCity_Text_1E056A: @ 81E056A
	.string "Salut, ça t'arrive de regarder\n"
	.string "la télé?\p"
	.string "Plusieurs nouvelles émissions très\n"
	.string "sympas ont récemment été porgrammées.\p"
	.string "C'est sympa. J'ai vu mes amis à la télé\n"
	.string "alors que je ne m'y attendais pas.\p"
	.string "Quelquefois, ils te font même passer\n"
	.string "à la télé sans te le dire.\p"
	.string "J'espère que je passerai moi aussi\n"
	.string "à la télé un jour.\p"
	.string "Tu vois, tu devrais regarder la télé\n"
	.string "le plus souvent possible.$"

MauvilleCity_Text_1E0699: @ 81E0699
	.string "Salut! T'as regardé la télé?$"

#else

MauvilleCity_Text_1DF7DC: @ 81DF7DC
	.string "UNCLE: It's because of POKéMON that\n"
	.string "this boy's got more pep, I suppose…\l"
	.string "But he's become a bit too peppy…$"

MauvilleCity_Text_1DF845: @ 81DF845
	.string "WALLY: Aww, UNCLE, please?\p"
	.string "I want to challenge this GYM and see\n"
	.string "how much better I've become.\p"
	.string "Please? May I, please?$"

MauvilleCity_Text_1DF8B9: @ 81DF8B9
	.string "UNCLE: Now hold on, WALLY.\p"
	.string "Since you started living with POKéMON,\n"
	.string "you have grown quite a lot stronger.\p"
	.string "But don't you think you're pushing it\n"
	.string "to suddenly challenge a GYM?$"

MauvilleCity_Text_1DF963: @ 81DF963
	.string "WALLY: I'm not pushing it.\p"
	.string "If I combine forces with RALTS,\n"
	.string "we can beat anyone!$"

MauvilleCity_Text_1DF9B2: @ 81DF9B2
	.string "WALLY: Oh! Hi, {PLAYER}!\p"
	.string "I've gotten a lot stronger since\n"
	.string "we met.\p"
	.string "{PLAYER}, I want you and my UNCLE to\n"
	.string "understand that.\p"
	.string "{PLAYER}, please, will you have\n"
	.string "a battle with me?$"

MauvilleCity_Text_1DFA4A: @ 81DFA4A
	.string "WALLY: Oh… If you won't battle me,\n"
	.string "{PLAYER}, my UNCLE won't know that I've\l"
	.string "become really strong.$"

MauvilleCity_Text_1DFAA5: @ 81DFAA5
	.string "UNCLE: {PLAYER}{KUN}, was it?\n"
	.string "On WALLY's behalf, can I ask you to\l"
	.string "battle with him just this once?\p"
	.string "I don't think he's going to listen to\n"
	.string "any reason the way he is now.$"

MauvilleCity_Text_1DFB42: @ 81DFB42
	.string "WALLY: {PLAYER}, please!\n"
	.string "Battle with me, please.$"

MauvilleCity_Text_1DFB6D: @ 81DFB6D
	.string "WALLY: {PLAYER}, thank you.\p"
	.string "Okay… Here I come!$"

MauvilleCity_Text_1DFB96: @ 81DFB96
	.string "WALLY: … … … … … … …\p"
	.string "… … … … … … … …\p"
	.string "I lost…$"

MauvilleCity_Text_1DFBC3: @ 81DFBC3
	.string "WALLY: UNCLE…\n"
	.string "I'll go back to VERDANTURF…$"

MauvilleCity_Text_1DFBED: @ 81DFBED
	.string "{PLAYER}, thank you.\n"
	.string "Being a TRAINER is tough, isn't it?\p"
	.string "It's not enough just to have POKéMON\n"
	.string "and make them battle. That isn't what\l"
	.string "being a real TRAINER is about.$"

MauvilleCity_Text_1DFC8A: @ 81DFC8A
	.string "UNCLE: WALLY, there's no need to be so\n"
	.string "down on yourself.\p"
	.string "Why, what's keeping you from becoming\n"
	.string "stronger and stronger?\p"
	.string "Come on, let's go home.\n"
	.string "Everyone's waiting for you.$"

MauvilleCity_Text_1DFD34: @ 81DFD34
	.string "UNCLE: {PLAYER}{KUN}, it just dawned on me\n"
	.string "that you must be the TRAINER who kept\l"
	.string "an eye out for WALLY when he caught\l"
	.string "his POKéMON.\p"
	.string "Why don't you visit us in VERDANTURF\n"
	.string "sometime?\l"
	.string "I'm sure WALLY would enjoy it.$"


MauvilleCity_Text_1DFDFB: @ 81DFDFB
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "WALLY: Oh, hello, {PLAYER}!\p"
	.string "I just wanted to tell you that\n"
	.string "my uncle bought me a POKéNAV!\p"
	.string "Now I can get in touch with you\n"
	.string "anytime, {PLAYER}!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

MauvilleCity_Text_1DFEB4: @ 81DFEB4
	.string "Registered WALLY\n"
	.string "in the POKéNAV.$"

MauvilleCity_Text_1DFED5: @ 81DFED5
	.string "SCOTT: Hehe…\n"
	.string "I was watching that match!\p"
	.string "You're friends with that boy WALLY,\n"
	.string "aren't you?\p"
	.string "But you didn't hold anything back\n"
	.string "and beat him impressively.\p"
	.string "Yeah! That's what a real POKéMON\n"
	.string "battle is all about!\p"
	.string "I idolize TRAINERS like that!\p"
	.string "… … … … … …\n"
	.string "I'll be cheering for you!$"

MauvilleCity_Text_1DFFE4: @ 81DFFE4
	.string "WATTSON: Oh, {PLAYER}{KUN}!\n"
	.string "You look like you have a lot of zip!\l"
	.string "That's a good thing, wahahahaha!\p"
	.string "Fine! I've decided!\n"
	.string "I need a favor, {PLAYER}{KUN}!\p"
	.string "MAUVILLE CITY has an underground\n"
	.string "sector called NEW MAUVILLE.\p"
	.string "{PLAYER}{KUN}, I'd like you to go there and\n"
	.string "switch off the GENERATOR.\p"
	.string "The GENERATOR has been running a bit\n"
	.string "haywire. It's getting unsafe.\p"
	.string "Here, this is the KEY to get into\n"
	.string "NEW MAUVILLE.$"

MauvilleCity_Text_1E0154: @ 81E0154
	.string "WATTSON: Don't you worry about it.\n"
	.string "It won't be a challenge to you.\p"
	.string "The entrance to NEW MAUVILLE is just\n"
	.string "a short SURF away from ROUTE 110.\p"
	.string "That's it, then, you have my trust!\n"
	.string "Wahahahaha!$"

MauvilleCity_Text_1E020E: @ 81E020E
	.string "WATTSON: Wahahahaha!\p"
	.string "I knew it, {PLAYER}{KUN}! I knew I'd made\n"
	.string "the right choice asking you!\p"
	.string "This is my thanks--a TM containing\n"
	.string "THUNDERBOLT!\p"
	.string "Go on, you've earned it!$"

MauvilleCity_Text_1E02AA: @ 81E02AA
	.string "WATTSON: Wahahahaha!\p"
	.string "It pleases me to no end to see\n"
	.string "the young step up and take charge!$"

MauvilleCity_Text_1E0301: @ 81E0301
	.string "You know, it's cool to have POKéMON\n"
	.string "battles and stuff…\p"
	.string "But if your POKéMON gets hurt,\n"
	.string "you have to nurse it back to health.$"

MauvilleCity_Text_1E037C: @ 81E037C
	.string "The roads of this town stretch north\n"
	.string "and south, and east and west.\p"
	.string "Because of that, we get all sorts of\n"
	.string "people coming through.$"

MauvilleCity_Text_1E03FB: @ 81E03FB
	.string "Have you been to RYDEL'S CYCLES yet?\p"
	.string "RYDEL, the owner, is a very generous\n"
	.string "man.$"

MauvilleCity_Text_1E044A: @ 81E044A
	.string "Even if you're riding a BIKE,\n"
	.string "wild POKéMON could jump you.$"

MauvilleCity_Text_1E0485: @ 81E0485
	.string "MAUVILLE CITY\n"
	.string "“The bright and shiny city of fun!”$"

MauvilleCity_Text_1E04B7: @ 81E04B7
	.string "MAUVILLE CITY POKéMON GYM\n"
	.string "LEADER: WATTSON\l"
	.string "“The cheerfully electrifying man!”$"

MauvilleCity_Text_1E0504: @ 81E0504
	.string "“Ride in gravel and shake up your\n"
	.string "soul!”\l"
	.string "RYDEL'S CYCLES$"

MauvilleCity_Text_1E053C: @ 81E053C
	.string "“The play spot for all!”\n"
	.string "MAUVILLE GAME CORNER$"

MauvilleCity_Text_1E056A: @ 81E056A
	.string "Hi, do you check out TV at all?\p"
	.string "They've added a bunch of cool new\n"
	.string "shows recently.\p"
	.string "TV is so cool. I've seen my friends on\n"
	.string "TV just out of the blue.\p"
	.string "And, sometimes, they even put you on TV\n"
	.string "without telling you.\p"
	.string "I wish I would be on TV sometime.\p"
	.string "That's why I think you should check\n"
	.string "out TVs whenever you can.$"

MauvilleCity_Text_1E0699: @ 81E0699
	.string "Hi, have you been checking out TVs?$"

#endif