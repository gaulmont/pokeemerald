Route116_MapScripts:: @ 81F2C0C
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route116_MapScript1_1F2C4F
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route116_MapScript2_1F2C66
	.byte 0

Route116_OnTransition: @ 81F2C1C
	call_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_1F2C47
	compare VAR_SHOULD_END_UNUSUAL_WEATHER, 1
	call_if_eq UnusualWeather_EventScript_HideMapNamePopup
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_116_NORTH
	call_if_eq UnusualWeather_StartGroudonWeather
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_116_SOUTH
	call_if_eq UnusualWeather_StartGroudonWeather
	end

Route116_EventScript_1F2C47:: @ 81F2C47
	setobjectxyperm 21, 38, 10
	return

Route116_MapScript1_1F2C4F: @ 81F2C4F
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_116_NORTH
	call_if_eq UnusualWeather_EventScript_PlaceTilesRoute116North
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_116_SOUTH
	call_if_eq UnusualWeather_EventScript_PlaceTilesRoute116South
	end

Route116_MapScript2_1F2C66: @ 81F2C66
	map_script_2 VAR_SHOULD_END_UNUSUAL_WEATHER, 1, UnusualWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route116_EventScript_1F2C70:: @ 81F2C70
	lock
	faceplayer
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_1F2C8E
	goto_if_set FLAG_DEVON_GOODS_STOLEN, Route116_EventScript_1F2C98
	msgbox Route116_Text_1F3140, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_1F2C8E:: @ 81F2C8E
	msgbox Route116_Text_1F32C1, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_1F2C98:: @ 81F2C98
	msgbox Route116_Text_1F3166, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_1F2CA2:: @ 81F2CA2
	lock
	faceplayer
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, Route116_EventScript_1F2D2B
	msgbox Route116_Text_1F3317, MSGBOX_DEFAULT
	goto Route116_EventScript_1F2CBB
	end

Route116_EventScript_1F2CBB:: @ 81F2CBB
	setflag FLAG_MET_DEVON_EMPLOYEE
	giveitem_std ITEM_REPEAT_BALL
	compare VAR_RESULT, 0
	goto_if_eq Route116_EventScript_1F2D39
	msgbox Route116_Text_1F3521, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, DIR_NORTH
	call_if_eq Route116_EventScript_1F2D15
	compare VAR_FACING, DIR_SOUTH
	call_if_eq Route116_EventScript_1F2D15
	compare VAR_FACING, DIR_WEST
	call_if_eq Route116_EventScript_1F2D15
	compare VAR_FACING, DIR_EAST
	call_if_eq Route116_EventScript_1F2D20
	removeobject VAR_LAST_TALKED
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setflag FLAG_RECEIVED_REPEAT_BALL
	release
	end

Route116_EventScript_1F2D15:: @ 81F2D15
	applymovement VAR_LAST_TALKED, Route116_Movement_1F2D43
	waitmovement 0
	return

Route116_EventScript_1F2D20:: @ 81F2D20
	applymovement VAR_LAST_TALKED, Route116_Movement_1F2D4C
	waitmovement 0
	return

Route116_EventScript_1F2D2B:: @ 81F2D2B
	msgbox Route116_Text_1F35CE, MSGBOX_DEFAULT
	goto Route116_EventScript_1F2CBB
	end

Route116_EventScript_1F2D39:: @ 81F2D39
	msgbox Route116_Text_1F3593, MSGBOX_DEFAULT
	release
	end

Route116_Movement_1F2D43: @ 81F2D43
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route116_Movement_1F2D4C: @ 81F2D4C
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

Route116_EventScript_1F2D57:: @ 81F2D57
	msgbox Route116_Text_1F379D, MSGBOX_SIGN
	end

Route116_EventScript_1F2D60:: @ 81F2D60
	msgbox Route116_Text_1F37B7, MSGBOX_SIGN
	end

Route116_EventScript_1F2D69:: @ 81F2D69
	msgbox Route116_Text_1F380F, MSGBOX_SIGN
	end

Route116_EventScript_1F2D72:: @ 81F2D72
	msgbox Route116_Text_1F3825, MSGBOX_SIGN
	end

Route116_EventScript_1F2D7B:: @ 81F2D7B
	msgbox Route116_Text_1F38D4, MSGBOX_SIGN
	end

Route116_EventScript_1F2D84:: @ 81F2D84
	lock
	faceplayer
	msgbox Route116_Text_1F309D, MSGBOX_DEFAULT
	setvar VAR_ROUTE116_STATE, 2
	release
	end

Route116_EventScript_1F2D95:: @ 81F2D95
	lockall
	applymovement 11, Common_Movement_WalkInPlaceFastestRight
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox Route116_Text_1F309D, MSGBOX_DEFAULT
	setvar VAR_ROUTE116_STATE, 2
	releaseall
	end

Route116_EventScript_1F2DB6:: @ 81F2DB6
	lock
	faceplayer
	checkitem ITEM_BLACK_GLASSES, 1
	compare VAR_RESULT, 1
	goto_if_eq Route116_EventScript_1F2DF1
	specialvar VAR_RESULT, FoundBlackGlasses
	compare VAR_RESULT, 1
	goto_if_eq Route116_EventScript_1F2DE2
	msgbox Route116_Text_1F3657, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_1F2DE2:: @ 81F2DE2
	msgbox Route116_Text_1F3718, MSGBOX_DEFAULT
	closemessage
	goto Route116_EventScript_1F2E2A
	end

Route116_EventScript_1F2DF1:: @ 81F2DF1
	msgbox Route116_Text_1F3657, MSGBOX_DEFAULT
	msgbox Route116_Text_1F3688, MSGBOX_DEFAULT
	specialvar VAR_RESULT, FoundBlackGlasses
	compare VAR_RESULT, 1
	goto_if_eq Route116_EventScript_1F2E1B
	msgbox Route116_Text_1F375E, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_1F2E1B:: @ 81F2E1B
	msgbox Route116_Text_1F36B4, MSGBOX_DEFAULT
	closemessage
	goto Route116_EventScript_1F2E2A
	end

Route116_EventScript_1F2E2A:: @ 81F2E2A
	delay 20
	compare VAR_FACING, DIR_NORTH
	call_if_eq Route116_EventScript_1F2E5E
	compare VAR_FACING, DIR_SOUTH
	call_if_eq Route116_EventScript_1F2E5E
	compare VAR_FACING, DIR_WEST
	call_if_eq Route116_EventScript_1F2E5E
	compare VAR_FACING, DIR_EAST
	call_if_eq Route116_EventScript_1F2E69
	removeobject VAR_LAST_TALKED
	release
	end

Route116_EventScript_1F2E5E:: @ 81F2E5E
	applymovement VAR_LAST_TALKED, Route116_Movement_1F2E74
	waitmovement 0
	return

Route116_EventScript_1F2E69:: @ 81F2E69
	applymovement VAR_LAST_TALKED, Route116_Movement_1F2E7E
	waitmovement 0
	return

Route116_Movement_1F2E74: @ 81F2E74
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

Route116_Movement_1F2E7E: @ 81F2E7E
	walk_up
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

Route116_EventScript_1F2E89:: @ 81F2E89
	trainerbattle_single TRAINER_JOEY, Route116_Text_29BB79, Route116_Text_29BB9A
	msgbox Route116_Text_29BBC6, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_1F2EA0:: @ 81F2EA0
	trainerbattle_single TRAINER_JOSE, Route116_Text_29BBFD, Route116_Text_29BC25
	msgbox Route116_Text_29BC42, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_1F2EB7:: @ 81F2EB7
	trainerbattle_single TRAINER_JERRY_1, Route116_Text_29BD0C, Route116_Text_29BD66, Route116_EventScript_1F2EF8
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route116_EventScript_1F2F4E
	setvar VAR_0x8004, TRAINER_JERRY_1
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq Route116_EventScript_1F2F22
	msgbox Route116_Text_29BD92, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_1F2EF8:: @ 81F2EF8
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_1F2F03
	release
	end

Route116_EventScript_1F2F03:: @ 81F2F03
	special sub_80B4808
	waitmovement 0
	msgbox Route116_Text_29BE71, MSGBOX_DEFAULT
	register_matchcall TRAINER_JERRY_1
	release
	end

Route116_EventScript_1F2F22:: @ 81F2F22
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_1F2F35
	msgbox Route116_Text_29BD92, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_1F2F35:: @ 81F2F35
	msgbox Route116_Text_29BDEF, MSGBOX_DEFAULT
	register_matchcall TRAINER_JERRY_1
	release
	end

Route116_EventScript_1F2F4E:: @ 81F2F4E
	trainerbattle_rematch TRAINER_JERRY_1, Route116_Text_29BEF3, Route116_Text_29BF4C
	msgbox Route116_Text_29BF68, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_1F2F65:: @ 81F2F65
	trainerbattle_single TRAINER_CLARK, Route116_Text_29BACD, Route116_Text_29BB0F
	msgbox Route116_Text_29BB31, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_1F2F7C:: @ 81F2F7C
	trainerbattle_single TRAINER_JANICE, Route116_Text_29BC7F, Route116_Text_29BCB3
	msgbox Route116_Text_29BCCC, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_1F2F93:: @ 81F2F93
	trainerbattle_single TRAINER_KAREN_1, Route116_Text_29BFC5, Route116_Text_29BFFA, Route116_EventScript_1F2FD4
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route116_EventScript_1F302A
	setvar VAR_0x8004, TRAINER_KAREN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq Route116_EventScript_1F2FFE
	msgbox Route116_Text_29C010, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_1F2FD4:: @ 81F2FD4
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_1F2FDF
	release
	end

Route116_EventScript_1F2FDF:: @ 81F2FDF
	special sub_80B4808
	waitmovement 0
	msgbox Route116_Text_29C096, MSGBOX_DEFAULT
	register_matchcall TRAINER_KAREN_1
	release
	end

Route116_EventScript_1F2FFE:: @ 81F2FFE
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_1F3011
	msgbox Route116_Text_29C010, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_1F3011:: @ 81F3011
	msgbox Route116_Text_29C052, MSGBOX_DEFAULT
	register_matchcall TRAINER_KAREN_1
	release
	end

Route116_EventScript_1F302A:: @ 81F302A
	trainerbattle_rematch TRAINER_KAREN_1, Route116_Text_29C0DA, Route116_Text_29C11F
	msgbox Route116_Text_29C13B, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_1F3041:: @ 81F3041
	trainerbattle_single TRAINER_SARAH, Route116_Text_29C173, Route116_Text_29C1B8
	msgbox Route116_Text_29C1EA, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_1F3058:: @ 81F3058
	trainerbattle_single TRAINER_DAWSON, Route116_Text_29C266, Route116_Text_29C2C2
	msgbox Route116_Text_29C2DD, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_1F306F:: @ 81F306F
	trainerbattle_single TRAINER_DEVAN, Route116_Text_29C350, Route116_Text_29C365
	msgbox Route116_Text_29C380, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_1F3086:: @ 81F3086
	trainerbattle_single TRAINER_JOHNSON, Route116_Text_29C3C1, Route116_Text_29C3F7
	msgbox Route116_Text_29C418, MSGBOX_AUTOCLOSE
	end

Route116_Text_1F309D: @ 81F309D
	.string "Ohhh, que vais-je faire?\p"
	.string "On se baladait, PIKO et moi, quand\n"
	.string "une grosse brute nous a sauté dessus…\p"
	.string "Ce vaurien a filé avec mon cher\n"
	.string "PIKO!\p"
	.string "Oooooooooooh! PIKO!$"

Route116_Text_1F3140: @ 81F3140
	.string "Arrg… Haaaa!\p"
	.string "Je veux creuser ce tunnel!$"

Route116_Text_1F3166: @ 81F3166
	.string "Arrg…!\n"
	.string "Que se passe-t-il?\p"
	.string "Je creusais le tunnel sans aucun outil\n"
	.string "quand cet imbécile m'a chassé!\p"
	.string "Ce tunnel regorge de POKéMON qui\n"
	.string "réagissent mal aux bruits forts.\l"
	.string "Ils pourraient créer un brouhaha.\p"
	.string "C'est pour cela que nous avons arrêté\n"
	.string "d'utiliser de gros engins pour creuser…\p"
	.string "J'ai peur que cet imbécile n'agisse\n"
	.string "stupidement et effraie les POKéMON\l"
	.string "qui créeraient un brouhaha.$"

Route116_Text_1F32C1: @ 81F32C1
	.string "Arrg… Haaaa!\p"
	.string "Cette espèce d'imbécile a vite filé du\n"
	.string "tunnel! Je peux me remettre à creuser!$"

Route116_Text_1F3317: @ 81F3317
	.string "Oh! C'est toi!\p"
	.string "Tu es la personne qui non seulement m'a\n"
	.string "aidé au BOIS CLEMENTI, mais qui m'a\l"
	.string "aussi rapporté mon paquet volé et qui\l"
	.string "l'a gentiment livré à POIVRESSEL!\p"
	.string "Le CAPT. POUPE nous a également\n"
	.string "informés de l'arrivée du paquet!\p"
	.string "Je te remercie sincèrement!\p"
	.string "Si j'étais un nuage, je t'inonderais de\n"
	.string "gratitude et t'enverrais une pluie de\l"
	.string "remerciements!\p"
	.string "Pour toi, le plus merveilleux des\n"
	.string "DRESSEURS, j'ai une bonne nouvelle!\p"
	.string "Notre entreprise a récemment conçu\n"
	.string "une nouvelle sorte de POKé BALL.\p"
	.string "Comme preuve de notre reconnaissance,\n"
	.string "voici pour notre DRESSEUR d'exception!$"

Route116_Text_1F3521: @ 81F3521
	.string "Notre nouvelle POKé BALL sera en vente\n"
	.string "à la BOUTIQUE POKéMON de MEROUVILLE.\p"
	.string "Il faut l'essayer!\n"
	.string "Merci. Au revoir!$"

Route116_Text_1F3593: @ 81F3593
	.string "Le SAC est plein à craquer. Il est\n"
	.string "impossible d'y mettre cette BIS BALL!$"

Route116_Text_1F35CE: @ 81F35CE
	.string "En gage de notre reconnaissance pour\n"
	.string "avoir livré notre paquet, j'ai un cadeau\l"
	.string "pour notre DRESSEUR d'exception: une\l"
	.string "nouvelle sorte de POKé BALL!$"

Route116_Text_1F3657: @ 81F3657
	.string "J'ai fait tomber mes lunettes…\n"
	.string "Tu peux m'aider à les retrouver?$"

Route116_Text_1F3688: @ 81F3688
	.string "Ces lunettes-là!\n"
	.string "Je peux les voir une seconde?$"

Route116_Text_1F36B4: @ 81F36B4
	.string "Hum…\n"
	.string "Ce sont des LUNET.NOIRES.\l"
	.string "Ce ne sont pas celles que je cherche…\p"
	.string "Peut-être mes lunettes ne sont-elles\n"
	.string "pas par ici…$"

Route116_Text_1F3718: @ 81F3718
	.string "Hum…\n"
	.string "Je n'ai trouvé mes lunettes nulle part…\l"
	.string "Peut-être ne sont-elles pas par ici…$"

Route116_Text_1F375E: @ 81F375E
	.string "Hum…\n"
	.string "Ce sont des LUNET.NOIRES.\l"
	.string "Ce ne sont pas celles que je cherche…$"

Route116_Text_1F379D: @ 81F379D
	.string "ROUTE 116\n"
	.string "{LEFT_ARROW} MEROUVILLE$"

Route116_Text_1F37B7: @ 81F37B7
	.string "TUNNEL MERAZON\n"
	.string "“Passage entre MEROUVILLE\n"
	.string "et VERGAZON.”\p"
	.string "Le projet de création du tunnel\n"
	.string "a été annulé.”$"

Route116_Text_1F380F: @ 81F380F
	.string "REFUGE DES FOREURS$"

Route116_Text_1F3825: @ 81F3825
	.string "CONSEILS AUX DRESSEURS\p"
	.string "Si vous voulez empêcher un POKéMON\n"
	.string "d'évoluer, appuyez sur le bouton B au\l"
	.string "moment où il commence à évoluer. Le\l"
	.string "POKéMON, effrayé, arrêtera d'évoluer.\p"
	.string "C'est une cessation d'évolution.$"

Route116_Text_1F38D4: @ 81F38D4
	.string "CONSEILS AUX DRESSEURS\p"
	.string "Votre SAC a plusieurs POCHES.\p"
	.string "Les objets obtenus sont directement\n"
	.string "placés dans la POCHE appropriée.\p"
	.string "Aucun DRESSEUR ne peut se permettre\n"
	.string "de voyager sans avoir son propre SAC.$"

