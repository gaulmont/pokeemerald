MossdeepCity_House3_MapScripts:: @ 82225C2
	.byte 0

MossdeepCity_House3_EventScript_2225C3:: @ 82225C3
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_222602
	msgbox MossdeepCity_House3_Text_222616, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_House3_EventScript_22260C
	msgbox MossdeepCity_House3_Text_2226B6, MSGBOX_DEFAULT
	giveitem_std ITEM_SUPER_ROD
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_2226F0, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_222602:: @ 8222602
	msgbox MossdeepCity_House3_Text_222751, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_22260C:: @ 822260C
	msgbox MossdeepCity_House3_Text_222733, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_222616: @ 8222616
	.string "Hé, toi, DRESSEUR!\n"
	.string "Une MEGA CANNE, c'est vraiment super!\p"
	.string "Tu peux dire c'que tu veux, ce bébé peut\n"
	.string "attraper des POKéMON au fond de la mer!\p"
	.string "Qu'est-ce que t'en penses?\n"
	.string "Tu veux qu'on essaie, hein?$"

MossdeepCity_House3_Text_2226B6: @ 82226B6
	.string "Tu paries, tu paries! Après tout, une\n"
	.string "MEGA CANNE, c'est super!$"

MossdeepCity_House3_Text_2226F0: @ 82226F0
	.string "S'il y a de l'eau, essaie de lancer ta\n"
	.string "CANNE et attends de voir si ça mord!$"

MossdeepCity_House3_Text_222733: @ 8222733
	.string "Hum?\n"
	.string "T'aimes pas pêcher?$"

MossdeepCity_House3_Text_222751: @ 8222751
	.string "Essaie d'attraper les POKéMON au fond\n"
	.string "de la mer avec ta MEGA CANNE.$"

