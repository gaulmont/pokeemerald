LilycoveCity_DepartmentStore_4F_MapScripts:: @ 821FDEA
	.byte 0

LilycoveCity_DepartmentStore_4F_EventScript_21FDEB:: @ 821FDEB
	msgbox LilycoveCity_DepartmentStore_4F_Text_21FE50, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_21FDF4:: @ 821FDF4
	msgbox LilycoveCity_DepartmentStore_4F_Text_21FEC7, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_21FDFD:: @ 821FDFD
	msgbox LilycoveCity_DepartmentStore_4F_Text_21FF2D, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_21FE06:: @ 821FE06
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_21FE20
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_21FE20: @ 821FE20
	.2byte ITEM_TM38
	.2byte ITEM_TM25
	.2byte ITEM_TM14
	.2byte ITEM_TM15
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_4F_EventScript_21FE2C:: @ 821FE2C
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_21FE44
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_21FE44: @ 821FE44
	.2byte ITEM_TM17
	.2byte ITEM_TM20
	.2byte ITEM_TM33
	.2byte ITEM_TM16
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_4F_Text_21FE50: @ 821FE50
	.string "Humm…\p"
	.string "Une capacité offensive…\n"
	.string "Une capacité défensive…\p"
	.string "Ce n'est pas facile de savoir quelle CT\n"
	.string "doit apprendre un POKéMON…$"

LilycoveCity_DepartmentStore_4F_Text_21FEC7: @ 821FEC7
	.string "Il y a tellement de CT différentes.\p"
	.string "Une brochure que j'ai lue indiquait\n"
	.string "qu'il y en avait cinquante sortes.$"

LilycoveCity_DepartmentStore_4F_Text_21FF2D: @ 821FF2D
	.string "J'aimerais bien avoir toutes les sortes\n"
	.string "de CT, mais un POKéMON ne peut\l"
	.string "apprendre que quatre capacités.$"
