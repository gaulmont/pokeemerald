FallarborTown_CozmosHouse_MapScripts:: @ 8200F12
	.byte 0

FallarborTown_CozmosHouse_EventScript_200F13:: @ 8200F13
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM27, FallarborTown_CozmosHouse_EventScript_200FB2
	checkitem ITEM_METEORITE, 1
	compare VAR_RESULT, 1
	goto_if_eq FallarborTown_CozmosHouse_EventScript_200F38
	msgbox FallarborTown_CozmosHouse_Text_200FEE, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_200F38:: @ 8200F38
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_200F8B
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_200F9C
	compare VAR_RESULT, 0
	goto_if_eq FallarborTown_CozmosHouse_EventScript_200FA5
	msgbox FallarborTown_CozmosHouse_Text_201159, MSGBOX_DEFAULT
	giveitem_std ITEM_TM27
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM27
	msgbox FallarborTown_CozmosHouse_Text_2011A5, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_200F8B:: @ 8200F8B
	msgbox FallarborTown_CozmosHouse_Text_200FEE, MSGBOX_DEFAULT
	msgbox FallarborTown_CozmosHouse_Text_2010A2, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_200F9C:: @ 8200F9C
	msgbox FallarborTown_CozmosHouse_Text_201249, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_200FA5:: @ 8200FA5
	setflag FLAG_TEMP_2
	msgbox FallarborTown_CozmosHouse_Text_201212, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_200FB2:: @ 8200FB2
	msgbox FallarborTown_CozmosHouse_Text_2011A5, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_200FBC:: @ 8200FBC
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM27, FallarborTown_CozmosHouse_EventScript_200FE4
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_200FDA
	msgbox FallarborTown_CozmosHouse_Text_2012BC, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_200FDA:: @ 8200FDA
	msgbox FallarborTown_CozmosHouse_Text_201310, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_200FE4:: @ 8200FE4
	msgbox FallarborTown_CozmosHouse_Text_20134B, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_Text_200FEE: @ 8200FEE
	.string "PROF. KOSMO: Oh…\n"
	.string "Je n'aurais jamais dû me laisser rouler\l"
	.string "dans la farine et avouer à la TEAM MAGMA\l"
	.string "où on peut trouver des METEORITES…\p"
	.string "Ce METEORITE du SITE METEORE…\n"
	.string "Il ne sera jamais à moi, maintenant…$"

FallarborTown_CozmosHouse_Text_2010A2: @ 82010A2
	.string "Oh!\n"
	.string "Hein?\p"
	.string "Mais, cet objet…\p"
	.string "C'est impossible!?!\p"
	.string "Est-ce le METEORITE que la TEAM\n"
	.string "MAGMA a pris au SITE METEORE?\p"
	.string "S'il te plaît, tu peux me le donner?\p"
	.string "Je suis prêt à te l'échanger contre un\n"
	.string "objet de valeur. Que dirais-tu d'une CT?$"

FallarborTown_CozmosHouse_Text_201159: @ 8201159
	.string "PROF. KOSMO: Cette CT est le symbole\n"
	.string "de ma gratitude à ton égard.\l"
	.string "N'hésite pas à l'utiliser!$"

FallarborTown_CozmosHouse_Text_2011A5: @ 82011A5
	.string "PROF. KOSMO: Oh, je n'arrive pas à\n"
	.string "y croire. C'est vraiment super génial!\p"
	.string "Ça va faire avancer mes recherches!$"

FallarborTown_CozmosHouse_Text_201212: @ 8201212
	.string "PROF. COZMO: Oh, but…\n"
	.string "I'm crushed with disappointment…$"

FallarborTown_CozmosHouse_Text_201249: @ 8201249
	.string "PROF. KOSMO: Oh, mais\n"
	.string "Je suis extrêmement déçu…\p"
	.string "PROF. KOSMO: S'il te plaît, tu peux\n"
	.string "me donner ce METEORITE?\p"
	.string "Je suis prêt à te l'échanger contre un\n"
	.string "objet de valeur. Que dirais-tu d'une CT?$"

FallarborTown_CozmosHouse_Text_2012BC: @ 82012BC
	.string "Le PROF. KOSMO est parti au SITE\n"
	.string "METEORE, sur la ROUTE 114, avec\l"
	.string "des types de la TEAM MAGMA.$"

FallarborTown_CozmosHouse_Text_201310: @ 8201310
	.string "Pauvre PROF. KOSMO… Il est si déprimé…\n"
	.string "Ça me fend le cœur.$"

FallarborTown_CozmosHouse_Text_20134B: @ 820134B
	.string "Regarde le PROF. KOSMO…\n"
	.string "Il est tellement content! C'est génial!$"

