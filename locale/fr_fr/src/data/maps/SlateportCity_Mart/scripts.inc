SlateportCity_Mart_MapScripts:: @ 820DC48
	.byte 0

SlateportCity_Mart_EventScript_20DC49:: @ 820DC49
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Mart_Pokemart_20DC60
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_Mart_Pokemart_20DC60: @ 820DC60
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_HARBOR_MAIL
	.2byte ITEM_NONE
	release
	end

SlateportCity_Mart_EventScript_20DC76:: @ 820DC76
	msgbox SlateportCity_Mart_Text_20DC88, MSGBOX_NPC
	end

SlateportCity_Mart_EventScript_20DC7F:: @ 820DC7F
	msgbox SlateportCity_Mart_Text_20DCF8, MSGBOX_NPC
	end

SlateportCity_Mart_Text_20DC88: @ 820DC88
	.string "Il doit y avoir certains produits\n"
	.string "intéressants au MARCHE.\p"
	.string "Mais certains objets ne sont en vente\n"
	.string "que dans les BOUTIQUES POKéMON.$"

SlateportCity_Mart_Text_20DCF8: @ 820DCF8
	.string "La SUPER BALL est plus efficace que la\n"
	.string "POKé BALL pour attraper des POKéMON.\p"
	.string "Avec ça, je devrais pouvoir attraper\n"
	.string "ce POKéMON insaisissable…$"