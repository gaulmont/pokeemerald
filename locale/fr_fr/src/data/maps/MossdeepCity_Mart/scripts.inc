MossdeepCity_Mart_MapScripts:: @ 82223C7
	.byte 0

MossdeepCity_Mart_EventScript_2223C8:: @ 82223C8
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MossdeepCity_Mart_Pokemart_2223E0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MossdeepCity_Mart_Pokemart_2223E0: @ 82223E0
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_NONE
	release
	end

MossdeepCity_Mart_EventScript_2223F6:: @ 82223F6
	msgbox MossdeepCity_Mart_Text_222411, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_2223FF:: @ 82223FF
	msgbox MossdeepCity_Mart_Text_2224A0, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_222408:: @ 8222408
	msgbox MossdeepCity_Mart_Text_2224FA, MSGBOX_NPC
	end

MossdeepCity_Mart_Text_222411: @ 8222411
	.string "RAPPEL est fabuleux!\p"
	.string "Si tu en donnes à un POKéMON K.O.,\n"
	.string "il reprend connaissance.\p"
	.string "Mais attention, RAPPEL ne restitue\n"
	.string "pas les PP des capacités déjà utilisés.$"

MossdeepCity_Mart_Text_2224A0: @ 82224A0
	.string "MAX REPOUSSE maintient les POKéMON\n"
	.string "faibles à l'écart\p"
	.string "Parmi tous les REPOUSSES, c'est celui\n"
	.string "qui dure le plus longtemps.$"

MossdeepCity_Mart_Text_2224FA: @ 82224FA
	.string "Les FILET BALLS et les SCUBA BALLS\n"
	.string "sont des POKé BALLS rares, qui ne\l"
	.string "sont fabriquées qu'à ALGATIA\p"
	.string "La FILET BALL est efficace contre les\n"
	.string "POKéMON des types INSECTE et EAU.\p"
	.string "La SCUBA BALL est plus efficace\n"
	.string "contre les POKéMON qui vivent\l"
	.string "au fond de la mer.$"

