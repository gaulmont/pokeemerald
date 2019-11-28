BattleFrontier_ScottsHouse_MapScripts:: @ 82636A7
	.byte 0

BattleFrontier_ScottsHouse_EventScript_2636A8:: @ 82636A8
	lock
	faceplayer
	goto_if_set FLAG_TEMP_4, BattleFrontier_ScottsHouse_EventScript_2637DA
	goto_if_set FLAG_TEMP_3, BattleFrontier_ScottsHouse_EventScript_2638AA
	goto_if_set FLAG_TEMP_2, BattleFrontier_ScottsHouse_EventScript_263939
	goto BattleFrontier_ScottsHouse_EventScript_2636CB
	end

BattleFrontier_ScottsHouse_EventScript_2636CB:: @ 82636CB
	goto_if_unset FLAG_SCOTT_GIVES_BATTLE_POINTS, BattleFrontier_ScottsHouse_EventScript_263943
	goto_if_unset FLAG_COLLECTED_ALL_SILVER_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_263704
	goto_if_unset FLAG_RECEIVED_STARF_BERRY_FROM_SCOTT, BattleFrontier_ScottsHouse_EventScript_26376A
	goto BattleFrontier_ScottsHouse_EventScript_2636EC
	end

BattleFrontier_ScottsHouse_EventScript_2636EC:: @ 82636EC
	goto_if_unset FLAG_RECEIVED_SILVER_SHIELD, BattleFrontier_ScottsHouse_EventScript_26381B
	goto_if_unset FLAG_RECEIVED_GOLD_SHIELD, BattleFrontier_ScottsHouse_EventScript_2638B4
	goto BattleFrontier_ScottsHouse_EventScript_2637E4
	end

BattleFrontier_ScottsHouse_EventScript_263704:: @ 8263704
	goto_if_unset FLAG_SYS_TOWER_SILVER, BattleFrontier_ScottsHouse_EventScript_2636EC
	goto_if_unset FLAG_SYS_DOME_SILVER, BattleFrontier_ScottsHouse_EventScript_2636EC
	goto_if_unset FLAG_SYS_PALACE_SILVER, BattleFrontier_ScottsHouse_EventScript_2636EC
	goto_if_unset FLAG_SYS_ARENA_SILVER, BattleFrontier_ScottsHouse_EventScript_2636EC
	goto_if_unset FLAG_SYS_FACTORY_SILVER, BattleFrontier_ScottsHouse_EventScript_2636EC
	goto_if_unset FLAG_SYS_PIKE_SILVER, BattleFrontier_ScottsHouse_EventScript_2636EC
	goto_if_unset FLAG_SYS_PYRAMID_SILVER, BattleFrontier_ScottsHouse_EventScript_2636EC
	msgbox BattleFrontier_ScottsHouse_Text_2640BC, MSGBOX_DEFAULT
	giveitem_std ITEM_LANSAT_BERRY
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_ScottsHouse_EventScript_2637D0
	setflag FLAG_COLLECTED_ALL_SILVER_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_26376A:: @ 826376A
	goto_if_unset FLAG_SYS_TOWER_GOLD, BattleFrontier_ScottsHouse_EventScript_2636EC
	goto_if_unset FLAG_SYS_DOME_GOLD, BattleFrontier_ScottsHouse_EventScript_2636EC
	goto_if_unset FLAG_SYS_PALACE_GOLD, BattleFrontier_ScottsHouse_EventScript_2636EC
	goto_if_unset FLAG_SYS_ARENA_GOLD, BattleFrontier_ScottsHouse_EventScript_2636EC
	goto_if_unset FLAG_SYS_FACTORY_GOLD, BattleFrontier_ScottsHouse_EventScript_2636EC
	goto_if_unset FLAG_SYS_PIKE_GOLD, BattleFrontier_ScottsHouse_EventScript_2636EC
	goto_if_unset FLAG_SYS_PYRAMID_GOLD, BattleFrontier_ScottsHouse_EventScript_2636EC
	msgbox BattleFrontier_ScottsHouse_Text_264216, MSGBOX_DEFAULT
	giveitem_std ITEM_STARF_BERRY
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_ScottsHouse_EventScript_2637D0
	setflag FLAG_RECEIVED_STARF_BERRY_FROM_SCOTT
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_2637D0:: @ 82637D0
	msgbox BattleFrontier_ScottsHouse_Text_2643EB, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_2637DA:: @ 82637DA
	msgbox BattleFrontier_ScottsHouse_Text_264373, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_2637E4:: @ 82637E4
	random 3
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_ScottsHouse_EventScript_263807
	compare VAR_RESULT, 2
	goto_if_eq BattleFrontier_ScottsHouse_EventScript_263811
	msgbox BattleFrontier_ScottsHouse_Text_263DDD, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_263807:: @ 8263807
	msgbox BattleFrontier_ScottsHouse_Text_263F12, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_263811:: @ 8263811
	msgbox BattleFrontier_ScottsHouse_Text_263FFE, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_26381B:: @ 826381B
	setvar VAR_FRONTIER_BATTLE_MODE, 0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	special sub_8161F74
	compare VAR_RESULT, 50
	goto_if_ge BattleFrontier_ScottsHouse_EventScript_26387A
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 1
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	special sub_8161F74
	compare VAR_RESULT, 50
	goto_if_ge BattleFrontier_ScottsHouse_EventScript_26387A
	goto BattleFrontier_ScottsHouse_EventScript_2637E4
	end

BattleFrontier_ScottsHouse_EventScript_26387A:: @ 826387A
	msgbox BattleFrontier_ScottsHouse_Text_264412, MSGBOX_DEFAULT
	givedecoration_std DECOR_SILVER_SHIELD
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_ScottsHouse_EventScript_2638A0
	setflag FLAG_RECEIVED_SILVER_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_2638AA
	end

BattleFrontier_ScottsHouse_EventScript_2638A0:: @ 82638A0
	msgbox BattleFrontier_ScottsHouse_Text_264583, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_2638AA:: @ 82638AA
	msgbox BattleFrontier_ScottsHouse_Text_264546, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_2638B4:: @ 82638B4
	setvar VAR_FRONTIER_BATTLE_MODE, 0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	special sub_8161F74
	compare VAR_RESULT, 100
	goto_if_ge BattleFrontier_ScottsHouse_EventScript_263913
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 1
	special CallFrontierUtilFunc
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	special sub_8161F74
	compare VAR_RESULT, 100
	goto_if_ge BattleFrontier_ScottsHouse_EventScript_263913
	goto BattleFrontier_ScottsHouse_EventScript_2637E4
	end

BattleFrontier_ScottsHouse_EventScript_263913:: @ 8263913
	msgbox BattleFrontier_ScottsHouse_Text_26449F, MSGBOX_DEFAULT
	givedecoration_std DECOR_GOLD_SHIELD
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_ScottsHouse_EventScript_2638A0
	setflag FLAG_RECEIVED_GOLD_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_2638AA
	end

BattleFrontier_ScottsHouse_EventScript_263939:: @ 8263939
	msgbox BattleFrontier_ScottsHouse_Text_263DB8, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_263943:: @ 8263943
	msgbox BattleFrontier_ScottsHouse_Text_263A3F, MSGBOX_DEFAULT
	closemessage
	delay 30
	compare VAR_FACING, DIR_NORTH
	call_if_eq BattleFrontier_ScottsHouse_EventScript_263A13
	compare VAR_FACING, DIR_SOUTH
	call_if_eq BattleFrontier_ScottsHouse_EventScript_263A1E
	compare VAR_FACING, DIR_EAST
	call_if_eq BattleFrontier_ScottsHouse_EventScript_263A29
	compare VAR_FACING, DIR_WEST
	call_if_eq BattleFrontier_ScottsHouse_EventScript_263A34
	msgbox BattleFrontier_ScottsHouse_Text_263B29, MSGBOX_DEFAULT
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_ScottsHouse_Text_263BD4, MSGBOX_DEFAULT
	compare VAR_SCOTT_STATE, 13
	goto_if_eq BattleFrontier_ScottsHouse_EventScript_2639BC
	compare VAR_SCOTT_STATE, 9
	goto_if_ge BattleFrontier_ScottsHouse_EventScript_2639CB
	compare VAR_SCOTT_STATE, 6
	goto_if_ge BattleFrontier_ScottsHouse_EventScript_2639DA
	goto BattleFrontier_ScottsHouse_EventScript_2639E9
	end

BattleFrontier_ScottsHouse_EventScript_2639BC:: @ 82639BC
	buffernumberstring 0, 4
	setvar VAR_0x8004, 4
	goto BattleFrontier_ScottsHouse_EventScript_2639F8
	end

BattleFrontier_ScottsHouse_EventScript_2639CB:: @ 82639CB
	buffernumberstring 0, 3
	setvar VAR_0x8004, 3
	goto BattleFrontier_ScottsHouse_EventScript_2639F8
	end

BattleFrontier_ScottsHouse_EventScript_2639DA:: @ 82639DA
	buffernumberstring 0, 2
	setvar VAR_0x8004, 2
	goto BattleFrontier_ScottsHouse_EventScript_2639F8
	end

BattleFrontier_ScottsHouse_EventScript_2639E9:: @ 82639E9
	buffernumberstring 0, 1
	setvar VAR_0x8004, 1
	goto BattleFrontier_ScottsHouse_EventScript_2639F8
	end

BattleFrontier_ScottsHouse_EventScript_2639F8:: @ 82639F8
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_ScottsHouse_Text_263CB0, 9
	msgbox BattleFrontier_ScottsHouse_Text_263CD0, MSGBOX_DEFAULT
	setflag FLAG_SCOTT_GIVES_BATTLE_POINTS
	setflag FLAG_TEMP_2
	release
	end

BattleFrontier_ScottsHouse_EventScript_263A13:: @ 8263A13
	applymovement 1, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_263A1E:: @ 8263A1E
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_263A29:: @ 8263A29
	applymovement 1, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_263A34:: @ 8263A34
	applymovement 1, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

BattleFrontier_ScottsHouse_Text_263A3F: @ 8263A3F
	.string "SCOTT: Bonjour toi! Bienvenue!\n"
	.string "Désolé, je sais que c'est un peu petit.\p"
	.string "Je suis content de t'accueillir dans\n"
	.string "la ZONE DE COMBAT, {PLAYER}{KUN}.\p"
	.string "Mon rêve s'est enfin réalisé!\n"
	.string "Ça m'a pris des années et beaucoup\l"
	.string "d'efforts, mais j'y suis enfin parvenu.$"

BattleFrontier_ScottsHouse_Text_263B29: @ 8263B29
	.string "Ce fut un très long voyage…\p"
	.string "J'ai pris la route pour me mettre à la\n"
	.string "recherche de DRESSEURS forts.\p"
	.string "J'ai bâti ce rêve au prix de tant\n"
	.string "d'efforts et de sacrifices!$"

BattleFrontier_ScottsHouse_Text_263BD4: @ 8263BD4
	.string "Mais tout ça, c'est du passé!\n"
	.string "Je ne vais pas m'étendre sur le sujet!\p"
	.string "J'espère que tu vas pouvoir te\n"
	.string "battre jusqu'à plus soif, ici!\p"
	.string "{PLAYER}{KUN}, prends ça. C'est en souvenir\n"
	.string "de toutes les fois où nos chemins se\l"
	.string "sont croisés.$"

BattleFrontier_ScottsHouse_Text_263CB0: @ 8263CB0
	.string "{PLAYER} obtient {STR_VAR_1}\n"
	.string "POINT(S) DE COMBAT.$"

BattleFrontier_ScottsHouse_Text_263CD0: @ 8263CD0
	.string "SCOTT: Ton nombre de POINTS DE COMBAT\n"
	.string "est inscrit sur ton PASSE ZONE.\p"
	.string "Plus tu auras de succès dans la ZONE DE\n"
	.string "COMBAT, plus tu accumuleras de POINTS\l"
	.string "DE COMBAT.\p"
	.string "Utilise-les comme bon te semble.\n"
	.string "Tu peux les échanger contre des objets.$"

BattleFrontier_ScottsHouse_Text_263DB8: @ 8263DB8
	.string "Je vais te suivre de près. Je suis sûr\n"
	.string "que beaucoup de réussites t'attendent!$"

BattleFrontier_ScottsHouse_Text_263DDD: @ 8263DDD
	.string "SCOTT: Chaque DRESSEUR est unique.\n"
	.string "Chacun a sa propre histoire.\p"
	.string "Mais au combat, ils doivent laisser\n"
	.string "tout ça derrière eux!\p"
	.string "Ils sont tous DRESSEURS!\p"
	.string "J'aime cette pureté. Face au combat, les\n"
	.string "DRESSEURS sont tous égaux.\p"
	.string "C'est pourquoi je voyage à la recherche\n"
	.string "de DRESSEURS dignes de ce nom et\l"
	.string "que je les invite ici.$"

BattleFrontier_ScottsHouse_Text_263F12: @ 8263F12
	.string "SCOTT: As-tu déjà rencontré un des\n"
	.string "MENEURS DE ZONE?\p"
	.string "Encore mieux, as-tu déjà obtenu des\n"
	.string "symboles?\p"
	.string "Les MENEURS DE ZONE ont été triés sur\n"
	.string "le volet. Ce sont les meilleurs!\p"
	.string "Mais je suis sûr que tu serais capable\n"
	.string "de leur faire peur!$"

BattleFrontier_ScottsHouse_Text_263FFE: @ 8263FFE
	.string "SCOTT: Tu ne t'entraînes pas que pour\n"
	.string "les combats, n'est-ce pas?\p"
	.string "Il me semble que tu travailles aussi à\n"
	.string "un POKéDEX.\p"
	.string "Eh bien, devine quoi!\p"
	.string "Il y a des POKéMON sauvages dans la\n"
	.string "ZONE DE COMBAT…\l"
	.string "Ouvre les yeux!$"

BattleFrontier_ScottsHouse_Text_2640BC: @ 82640BC
	.string "SCOTT: Tout se passe bien dans la\n"
	.string "ZONE DE COMBAT?\p"
	.string "Attends un instant…\n"
	.string "Oh!\p"
	.string "Ton PASSE ZONE!\n"
	.string "Tu as tous les symboles argent!\p"
	.string "C'est impressionnant!\n"
	.string "Mais ça ne me surprend pas vraiment!\p"
	.string "D'ordinaire, je ne fais pas ce genre de\n"
	.string "choses, mais là c'est exceptionnel!\p"
	.string "Je veux que tu prennes ça.\n"
	.string "Je suis sûr que tu en feras bon usage.$"

BattleFrontier_ScottsHouse_Text_264216: @ 8264216
	.string "SCOTT: J'espère que ton séjour dans la\n"
	.string "ZONE DE COMBAT se passe bien.\p"
	.string "Mais, attends…\n"
	.string "Alors là, je n'en crois pas mes yeux!\p"
	.string "Ton PASSE ZONE!\n"
	.string "Tu as obtenu tous les symboles\l"
	.string "or!\p"
	.string "C'est prodigieux! Tu es plus incroyable\n"
	.string "que ce que je pensais!\p"
	.string "… … … … … …\p"
	.string "{PLAYER}, tu dois accepter ça!\p"
	.string "Je suis sûr que tu sauras apprécier ce\n"
	.string "cadeau à sa juste valeur!$"

BattleFrontier_ScottsHouse_Text_264373: @ 8264373
	.string "Je sais reconnaître un bon DRESSEUR\n"
	.string "quand j'en vois un.\p"
	.string "Je me félicite d'avoir décidé de\n"
	.string "t'inviter ici!$"

BattleFrontier_ScottsHouse_Text_2643EB: @ 82643EB
	.string "La POCHE BAIES a l'air pleine.$"

BattleFrontier_ScottsHouse_Text_264412: @ 8264412
	.string "SCOTT: Oh, on m'a raconté tes exploits à\n"
	.string "la TOUR DE COMBAT! Tu as battu plus de\l"
	.string "50 DRESSEURS à la suite?\p"
	.string "C'est fantastique!\n"
	.string "Je veux que tu acceptes ça!$"

BattleFrontier_ScottsHouse_Text_26449F: @ 826449F
	.string "SCOTT: Oh! Tu sais, on m'a parlé de tes\n"
	.string "exploits à la TOUR DE COMBAT! Tu as\l"
	.string "battu plus de 100 DRESSEURS à la suite?\p"
	.string "C'est incroyable, spectaculaire!\n"
	.string "Il faut que tu prennes ça!$"

BattleFrontier_ScottsHouse_Text_264546: @ 8264546
	.string "Je me demande bien quelles surprises\n"
	.string "tu me réserves encore!$"

BattleFrontier_ScottsHouse_Text_264583: @ 8264583
	.string "Eh bien si tu n'as pas de place pour\n"
	.string "l'instant, reviens plus tard.$"
