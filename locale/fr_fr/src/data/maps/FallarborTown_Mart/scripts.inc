FallarborTown_Mart_MapScripts:: @ 81FFCBE
	.byte 0

FallarborTown_Mart_EventScript_1FFCBF:: @ 81FFCBF
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FallarborTown_Mart_Pokemart_1FFCD8
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FallarborTown_Mart_Pokemart_1FFCD8: @ 81FFCD8
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_NONE
	release
	end

FallarborTown_Mart_EventScript_1FFCF4:: @ 81FFCF4
	msgbox FallarborTown_Mart_Text_1FFD19, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_1FFCFD:: @ 81FFCFD
	msgbox FallarborTown_Mart_Text_1FFE09, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_1FFD06:: @ 81FFD06
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, 0
	msgbox FallarborTown_Mart_Text_1FFDFA, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_Mart_Text_1FFD19: @ 81FFD19
	.string "J'ai du mal à me décider. Faut-il que\n"
	.string "je fasse évoluer mon SKITTY?\p"
	.string "Il me suffirait d'utiliser cette PIERRE\n"
	.string "LUNE, mais je n'arrive pas à me décider…\p"
	.string "Si je le fais évoluer, il sera bien plus\n"
	.string "puissant.\p"
	.string "Mais il changera aussi d'apparence.$"

FallarborTown_Mart_Text_1FFDFA: @ 81FFDFA
	.string "SKITTY: Kiiiiity?$"

FallarborTown_Mart_Text_1FFE09: @ 81FFE09
	.string "J'ai trouvé une PEPITE, ici…\n"
	.string "Je suppose que je vais devoir la vendre,\l"
	.string "puisqu'elle ne sert à rien d'autre.$"

