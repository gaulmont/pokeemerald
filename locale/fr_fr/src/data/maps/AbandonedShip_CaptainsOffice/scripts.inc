AbandonedShip_CaptainsOffice_MapScripts:: @ 82387E1
	.byte 0

AbandonedShip_CaptainsOffice_EventScript_2387E2:: @ 82387E2
	lock
	faceplayer
	goto_if_set FLAG_EXCHANGED_SCANNER, AbandonedShip_CaptainsOffice_EventScript_23881A
	checkitem ITEM_SCANNER, 1
	compare VAR_RESULT, 1
	goto_if_eq AbandonedShip_CaptainsOffice_EventScript_238810
	goto_if_set FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_4_SCANNER, AbandonedShip_CaptainsOffice_EventScript_23881A
	msgbox AbandonedShip_CaptainsOffice_Text_238824, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_238810:: @ 8238810
	msgbox AbandonedShip_CaptainsOffice_Text_23889D, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_23881A:: @ 823881A
	msgbox AbandonedShip_CaptainsOffice_Text_238918, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_Text_238824: @ 8238824
	.string "J'examine ce bateau pour le\n"
	.string "CAPT. POUPE.\p"
	.string "Il m'a aussi demandé de rapporter un\n"
	.string "SCANNER, mais je n'en ai pas trouvé…$"

AbandonedShip_CaptainsOffice_Text_23889D: @ 823889D
	.string "Oh, c'est un SCANNER!\p"
	.string "Ecoute, je peux te demander d'apporter\n"
	.string "ça au CAPT. POUPE?\p"
	.string "Je voudrais continuer d'examiner ce\n"
	.string "bateau.$"

AbandonedShip_CaptainsOffice_Text_238918: @ 8238918
	.string "Ce navire s'appelle LE CACTUS.\n"
	.string "Il semble être d'une autre époque.$"

