Route111_WinstrateFamilysHouse_MapScripts:: @ 822A48C
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_22A48D:: @ 822A48D
	lock
	faceplayer
	setvar VAR_0x8008, 2
	msgbox Route111_WinstrateFamilysHouse_Text_22A539, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_22A52C
	end

Route111_WinstrateFamilysHouse_EventScript_22A4A2:: @ 822A4A2
	lock
	faceplayer
	setvar VAR_0x8008, 3
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_22A4DA
	msgbox Route111_WinstrateFamilysHouse_Text_22A5F4, MSGBOX_DEFAULT
	giveitem_std ITEM_MACHO_BRACE
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_22A52C
	end

Route111_WinstrateFamilysHouse_EventScript_22A4DA:: @ 822A4DA
	msgbox Route111_WinstrateFamilysHouse_Text_22A6B4, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_22A52C
	end

Route111_WinstrateFamilysHouse_EventScript_22A4E8:: @ 822A4E8
	lock
	faceplayer
	setvar VAR_0x8008, 1
	msgbox Route111_WinstrateFamilysHouse_Text_22A6F7, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_22A52C
	end

Route111_WinstrateFamilysHouse_EventScript_22A4FD:: @ 822A4FD
	lock
	faceplayer
	setvar VAR_0x8008, 4
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_22A51E
	msgbox Route111_WinstrateFamilysHouse_Text_22A780, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_22A52C
	end

Route111_WinstrateFamilysHouse_EventScript_22A51E:: @ 822A51E
	msgbox Route111_WinstrateFamilysHouse_Text_22A89B, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_22A52C
	end

Route111_WinstrateFamilysHouse_EventScript_22A52C:: @ 822A52C
	closemessage
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route111_WinstrateFamilysHouse_Text_22A539: @ 822A539
	.string "C'est la première fois que je vois un\n"
	.string "DRESSEUR qui maîtrise aussi bien\l"
	.string "ses POKéMON.\p"
	.string "Mais il vaut mieux que je te prévienne,\n"
	.string "mon fils est plus fort que toi.\p"
	.string "Il a même relevé le défi de la LIGUE\n"
	.string "POKéMON, j'te signale.$"

Route111_WinstrateFamilysHouse_Text_22A5F4: @ 822A5F4
	.string "Nous utilisons ce BRAC. MACHO\n"
	.string "pour améliorer l'entraînement\l"
	.string "de nos POKéMON.\p"
	.string "Je ne sais pas si tu en auras besoin,\n"
	.string "mais comme tu nous as tous battus ici,\l"
	.string "nous t'offrons notre BRAC. MACHO.$"

Route111_WinstrateFamilysHouse_Text_22A6B4: @ 822A6B4
	.string "Lorsqu'on parle de combats de POKéMON,\n"
	.string "on est souvent très passionnés.$"

Route111_WinstrateFamilysHouse_Text_22A6F7: @ 822A6F7
	.string "Maman est plus forte que papa.\p"
	.string "Je suis plus forte que maman.\p"
	.string "Et mémé est plus forte que moi!\p"
	.string "Mais mon grand frère est encore plus\n"
	.string "fort que mémé.$"

Route111_WinstrateFamilysHouse_Text_22A780: @ 822A780
	.string "Aucun doute, tu es très robuste.\p"
	.string "Mais si tu te mesurais à mon petit-fils,\n"
	.string "tu pleurerais comme un bébé.\p"
	.string "Notre famille n'a jamais vu un DRESSEUR\n"
	.string "aussi fort que lui.\p"
	.string "En ce moment, il doit défier le MAITRE\n"
	.string "de la LIGUE POKéMON.\p"
	.string "Tel que je connais mon petit-fils, il est\n"
	.string "peut-être déjà le MAITRE!$"

Route111_WinstrateFamilysHouse_Text_22A89B: @ 822A89B
	.string "En ce moment, mon petit-fils doit défier\n"
	.string "le MAITRE de la LIGUE POKéMON.\p"
	.string "Tel que je connais mon petit-fils, il est\n"
	.string "peut-être déjà le MAITRE!$"

