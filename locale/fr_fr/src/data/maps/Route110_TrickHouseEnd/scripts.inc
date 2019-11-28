Route110_TrickHouseEnd_MapScripts:: @ 826ACAF
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHouseEnd_MapScript1_26ACC4
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseEnd_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHouseEnd_MapScript2_26ACF5
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHouseEnd_MapScript2_26ACDE
	.byte 0

Route110_TrickHouseEnd_MapScript1_26ACC4: @ 826ACC4
	compare VAR_TEMP_1, 1
	call_if_eq Route110_TrickHouseEnd_EventScript_26AD0D
	end

Route110_TrickHouseEnd_OnTransition: @ 826ACD0
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	special SetTrickHouseEndRoomFlag
	end

Route110_TrickHouseEnd_MapScript2_26ACDE: @ 826ACDE
	map_script_2 VAR_TEMP_2, 0, Route110_TrickHouseEnd_EventScript_26ACE8
	.2byte 0

Route110_TrickHouseEnd_EventScript_26ACE8:: @ 826ACE8
	addobject 1
	showobjectat 1, MAP_ROUTE110_TRICK_HOUSE_END
	turnobject 1, DIR_EAST
	end

Route110_TrickHouseEnd_MapScript2_26ACF5: @ 826ACF5
	map_script_2 VAR_TEMP_1, 0, Route110_TrickHouseEnd_EventScript_26ACFF
	.2byte 0

Route110_TrickHouseEnd_EventScript_26ACFF:: @ 826ACFF
	setvar VAR_TEMP_1, 1
	call Route110_TrickHouseEnd_EventScript_26AD0D
	special DrawWholeMapView
	end

Route110_TrickHouseEnd_EventScript_26AD0D:: @ 826AD0D
	setmetatile 10, 1, METATILE_GenericBuilding_TrickHouse_Door_Closed, 1
	return

Route110_TrickHouseEnd_EventScript_26AD17:: @ 826AD17
	lock
	faceplayer
	msgbox Route110_TrickHouseEnd_Text_26B08D, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 1
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, Route110_TrickHouseEnd_EventScript_26AD84
	case 1, Route110_TrickHouseEnd_EventScript_26ADC0
	case 2, Route110_TrickHouseEnd_EventScript_26ADFC
	case 3, Route110_TrickHouseEnd_EventScript_26AE38
	case 4, Route110_TrickHouseEnd_EventScript_26AE74
	case 5, Route110_TrickHouseEnd_EventScript_26AEB0
	case 6, Route110_TrickHouseEnd_EventScript_26AEEC
	case 7, Route110_TrickHouseEnd_EventScript_26AF28
	end

Route110_TrickHouseEnd_EventScript_26AD84:: @ 826AD84
	msgbox Route110_TrickHouseEnd_Text_26B0BC, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_26B73D, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem_std ITEM_RARE_CANDY
	compare VAR_RESULT, 0
	call_if_eq Route110_TrickHouseEnd_EventScript_26AFEF
	msgbox Route110_TrickHouseEnd_Text_26B7EF, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_26AFCF
	release
	end

Route110_TrickHouseEnd_EventScript_26ADC0:: @ 826ADC0
	msgbox Route110_TrickHouseEnd_Text_26B13B, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_26B73D, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem_std ITEM_TIMER_BALL
	compare VAR_RESULT, 0
	call_if_eq Route110_TrickHouseEnd_EventScript_26AFEF
	msgbox Route110_TrickHouseEnd_Text_26B7EF, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_26AFCF
	release
	end

Route110_TrickHouseEnd_EventScript_26ADFC:: @ 826ADFC
	msgbox Route110_TrickHouseEnd_Text_26B1AD, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_26B73D, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem_std ITEM_HARD_STONE
	compare VAR_RESULT, 0
	call_if_eq Route110_TrickHouseEnd_EventScript_26AFEF
	msgbox Route110_TrickHouseEnd_Text_26B7EF, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_26AFCF
	release
	end

Route110_TrickHouseEnd_EventScript_26AE38:: @ 826AE38
	msgbox Route110_TrickHouseEnd_Text_26B223, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_26B73D, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem_std ITEM_SMOKE_BALL
	compare VAR_RESULT, 0
	call_if_eq Route110_TrickHouseEnd_EventScript_26AFEF
	msgbox Route110_TrickHouseEnd_Text_26B7EF, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_26AFCF
	release
	end

Route110_TrickHouseEnd_EventScript_26AE74:: @ 826AE74
	msgbox Route110_TrickHouseEnd_Text_26B293, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_26B73D, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem_std ITEM_TM12
	compare VAR_RESULT, 0
	call_if_eq Route110_TrickHouseEnd_EventScript_26AFEF
	msgbox Route110_TrickHouseEnd_Text_26B7EF, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_26AFCF
	release
	end

Route110_TrickHouseEnd_EventScript_26AEB0:: @ 826AEB0
	msgbox Route110_TrickHouseEnd_Text_26B315, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_26B73D, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem_std ITEM_MAGNET
	compare VAR_RESULT, 0
	call_if_eq Route110_TrickHouseEnd_EventScript_26AFEF
	msgbox Route110_TrickHouseEnd_Text_26B7EF, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_26AFCF
	release
	end

Route110_TrickHouseEnd_EventScript_26AEEC:: @ 826AEEC
	msgbox Route110_TrickHouseEnd_Text_26B365, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_26B73D, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem_std ITEM_PP_MAX
	compare VAR_RESULT, 0
	call_if_eq Route110_TrickHouseEnd_EventScript_26AFEF
	msgbox Route110_TrickHouseEnd_Text_26B7EF, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_26AFCF
	release
	end

Route110_TrickHouseEnd_EventScript_26AF28:: @ 826AF28
	msgbox Route110_TrickHouseEnd_Text_26B3AB, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, DIR_SOUTH
	call_if_eq Route110_TrickHouseEnd_EventScript_26B015
	compare VAR_FACING, DIR_NORTH
	call_if_eq Route110_TrickHouseEnd_EventScript_26B020
	compare VAR_FACING, DIR_WEST
	call_if_eq Route110_TrickHouseEnd_EventScript_26B02B
	compare VAR_FACING, DIR_EAST
	call_if_eq Route110_TrickHouseEnd_EventScript_26B036
	delay 30
	msgbox Route110_TrickHouseEnd_Text_26B3FA, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	delay 30
	msgbox Route110_TrickHouseEnd_Text_26B485, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	call Route110_TrickHouseEnd_EventScript_26AFA5
	compare VAR_RESULT, 0
	call_if_eq Route110_TrickHouseEnd_EventScript_26B002
	msgbox Route110_TrickHouseEnd_Text_26B69A, MSGBOX_DEFAULT
	call Route110_TrickHouseEnd_EventScript_26AFCF
	special ResetTrickHouseEndRoomFlag
	release
	end

Route110_TrickHouseEnd_EventScript_26AFA5:: @ 826AFA5
	multichoice 0, 0, MULTI_TENT, 1
	switch VAR_RESULT
	case 0, Route110_TrickHouseEnd_EventScript_26AFBF
	goto Route110_TrickHouseEnd_EventScript_26AFC7

Route110_TrickHouseEnd_EventScript_26AFBF:: @ 826AFBF
	givedecoration_std DECOR_RED_TENT
	return

Route110_TrickHouseEnd_EventScript_26AFC7:: @ 826AFC7
	givedecoration_std DECOR_BLUE_TENT
	return

Route110_TrickHouseEnd_EventScript_26AFCF:: @ 826AFCF
	applymovement 1, Route110_TrickHouseEnd_Movement_269E36
	waitmovement 0
	playse SE_W153
	applymovement 1, Route110_TrickHouseEnd_Movement_269E3F
	waitmovement 0
	removeobject 1
	addvar VAR_TRICK_HOUSE_LEVEL, 1
	return

Route110_TrickHouseEnd_EventScript_26AFEF:: @ 826AFEF
	call Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEnd_Text_26B760, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

Route110_TrickHouseEnd_EventScript_26B002:: @ 826B002
	call Common_EventScript_NoRoomLeftForAnother
	msgbox Route110_TrickHouseEnd_Text_26B615, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

Route110_TrickHouseEnd_EventScript_26B015:: @ 826B015
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_26B020:: @ 826B020
	applymovement 1, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_26B02B:: @ 826B02B
	applymovement 1, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_26B036:: @ 826B036
	applymovement 1, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_26B041:: @ 826B041
	lockall
	turnobject 1, DIR_WEST
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	applymovement 1, Route110_TrickHouseEnd_Movement_26B08B
	waitmovement 0
	playse SE_W153
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox Route110_TrickHouseEnd_Text_26B8BD, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Route110_TrickHouseEnd_Movement_26B089
	waitmovement 0
	delay 4
	turnobject 1, DIR_EAST
	releaseall
	end

Route110_TrickHouseEnd_Movement_26B089: @ 826B089
	walk_down
	step_end

Route110_TrickHouseEnd_Movement_26B08B: @ 826B08B
	jump_in_place_left
	step_end

Route110_TrickHouseEnd_Text_26B08D: @ 826B08D
	.string "string "Aaargh! Tu m'as retrouvé?\n"
	.string "Hmmm… Tu as l'œil!$"

Route110_TrickHouseEnd_Text_26B0BC: @ 826B0BC
	.string "Il m'a fallu toute la nuit pour planter\n"
	.string "tous ces arbres…\p"
	.string "Tu es presque aussi balèze que moi,\n"
	.string "à 1, 2, 3, 4, 5, 6 endroits près!$"

Route110_TrickHouseEnd_Text_26B13B: @ 826B13B
	.string "Il m'a fallu toute la nuit pour faire ce\n"
	.string "labyrinthe…\p"
	.string "Tu es presque aussi balèze que moi,\n"
	.string "à 1, 2, 3, 4, 5 endroits près!$"

Route110_TrickHouseEnd_Text_26B1AD: @ 826B1AD
	.string "Il m'a fallu toute la nuit pour préparer\n"
	.string "ces pans de mur…\p"
	.string "Tu es presque aussi balèze que moi,\n"
	.string "à un, deux, trois, quatre endroits près!$"

Route110_TrickHouseEnd_Text_26B223: @ 826B223
	.string "Il m'a fallu toute la nuit pour pousser\n"
	.string "jusqu'ici tous ces rochers…\p"
	.string "Tu es presque aussi balèze que moi,\n"
	.string "à un, deux, trois endroits près!$"

Route110_TrickHouseEnd_Text_26B293: @ 826B293
	.string "Il m'a fallu une nuit pour fabriquer ces\n"
	.string "MECAPOUPEES et une pour les questions.\p"
	.string "Tu es presque aussi balèze que moi,\n"
	.string "à un, deux endroits près!$"

Route110_TrickHouseEnd_Text_26B315: @ 826B315
	.string "Il m'a fallu toute une nuit pour\n"
	.string "installer ces portes…\p"
	.string "Tu es presque aussi balèze que moi!$"

Route110_TrickHouseEnd_Text_26B365: @ 826B365
	.string "Il m'a fallu toute la nuit pour installer\n"
	.string "ces flèches…\p"
	.string "Tu es aussi balèze que moi!$"

Route110_TrickHouseEnd_Text_26B3AB: @ 826B3AB
	.string "Il m'a fallu toute la nuit pour cirer\n"
	.string "les parquets…\p"
	.string "Tu es plus balèze que moi!\n"
	.string "Il est possible que…$"

Route110_TrickHouseEnd_Text_26B3FA: @ 826B3FA
	.string "Que… Qu'est-ce que je vais faire? Mes\n"
	.string "sources d'inspiration sont épuisées…\p"
	.string "Je devrais peut-être parcourir le pays\n"
	.string "à la recherche de nouveaux pièges…$"

Route110_TrickHouseEnd_Text_26B485: @ 826B485
	.string "Ça me coûte de l'admettre, mais je\n"
	.string "crois que tu as fait mieux que moi!\p"
	.string "Cependant, mon charisme doit\n"
	.string "t'impressionner, puisque tu viens me\l"
	.string "voir très souvent. Aucun doute!\p"
	.string "Mais malgré tout, j'ai perdu!\p"
	.string "Pour sceller cette nouvelle amitié\n"
	.string "entre toi, le disciple, et moi, le génie,\l"
	.string "je te propose de garder un petit\l"
	.string "souvenir!\p"
	.string "Tu as le choix entre une TENTE ROUGE\n"
	.string "ou une TENTE BLEUE.\l"
	.string "Que préfères-tu?$"

Route110_TrickHouseEnd_Text_26B615: @ 826B615
	.string "Quoi? Plus de place dans ton PC?\n"
	.string "Qu'est-ce que je vais faire de ça?\p"
	.string "J'aimerais te dire tant pis, mais je suis\n"
	.string "sympa. J'attendrai que tu reviennes!$"

Route110_TrickHouseEnd_Text_26B69A: @ 826B69A
	.string "… … … … … …\p"
	.string "Je vais partir à l'aventure.\n"
	.string "En quête de nouveaux pièges!\p"
	.string "J'espère que tu reviendras me voir\n"
	.string "pour me divertir.\p"
	.string "Bon, allez, à la prochaine!$"

Route110_TrickHouseEnd_Text_26B73D: @ 826B73D
	.string "Excellent!\n"
	.string "Tu as gagné cette récompense!$"

Route110_TrickHouseEnd_Text_26B760: @ 826B760
	.string "Quoi? Tu n'as plus de place?\n"
	.string "Combien d'objets transportes-tu déjà?\p"
	.string "Soit, puisque tu m'as trouvé, je garde\n"
	.string "ta récompense. Reviens me voir.$"

Route110_TrickHouseEnd_Text_26B7EF: @ 826B7EF
	.string "Epargne-moi ce sourire narquois! Ne va\n"
	.string "pas t'imaginer que tu as déjà gagné!\p"
	.string "Je trouverai de nouveaux pièges pour\n"
	.string "te coller. Après, tu pourras te moquer.\p"
	.string "Reviens me voir pour un autre\n"
	.string "défi passionnant!$"

Route110_TrickHouseEnd_Text_26B8BD: @ 826B8BD
	.string "Quoi? Comment oses-tu? Tu m'ignores,\n"
	.string "maintenant? Ça me fend le cœur!$"

