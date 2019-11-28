LilycoveCity_DepartmentStore_3F_MapScripts:: @ 821FC64
	.byte 0

LilycoveCity_DepartmentStore_3F_EventScript_21FC65:: @ 821FC65
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_21FC7C
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_3F_Pokemart_21FC7C: @ 821FC7C
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_3F_EventScript_21FC8C:: @ 821FC8C
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_21FCA4
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_3F_Pokemart_21FCA4: @ 821FCA4
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_3F_EventScript_21FCB6:: @ 821FCB6
	msgbox LilycoveCity_DepartmentStore_3F_Text_21FCD1, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_3F_EventScript_21FCBF:: @ 821FCBF
	msgbox LilycoveCity_DepartmentStore_3F_Text_21FD3B, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_3F_EventScript_21FCC8:: @ 821FCC8
	msgbox LilycoveCity_DepartmentStore_3F_Text_21FDB4, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_3F_Text_21FCD1: @ 821FCD1
	.string "Pour endurcir les POKéMON en un rien\n"
	.string "de temps, rien de mieux que les objets.\p"
	.string "Les PROTEINES accroissent l'ATTAQUE et\n"
	.string "le CALCIUM augmente l'ATQ. SPE.$"

LilycoveCity_DepartmentStore_3F_Text_21FD3B: @ 821FD3B
	.string "Je veux que mon POKéMON ait plus\n"
	.string "d'endurance.\p"
	.string "Je ne sais pas si je dois élever sa\n"
	.string "DEFENSE avec le FER ou sa DEF. SPE\l"
	.string "avec le ZINC.$"

LilycoveCity_DepartmentStore_3F_Text_21FDB4: @ 821FDB4
	.string "J'ai donné du CARBONE à mon POKéMON\n"
	.string "et sa VITESSE a augmenté.$"