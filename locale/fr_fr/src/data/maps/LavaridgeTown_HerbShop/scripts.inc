LavaridgeTown_HerbShop_MapScripts:: @ 81FE4D6
	.byte 0

LavaridgeTown_HerbShop_EventScript_1FE4D7:: @ 81FE4D7
	lock
	faceplayer
	message LavaridgeTown_HerbShop_Text_1FE53E
	waitmessage
	pokemart LavaridgeTown_HerbShop_Pokemart_1FE4F0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_HerbShop_Pokemart_1FE4F0: @ 81FE4F0
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_NONE
	release
	end

LavaridgeTown_HerbShop_EventScript_1FE4FC:: @ 81FE4FC
	msgbox LavaridgeTown_HerbShop_Text_1FE685, MSGBOX_NPC
	end

LavaridgeTown_HerbShop_EventScript_1FE505:: @ 81FE505
	lock
	faceplayer
	goto_if_set FLFLAG_RECEIVED_CHARCOAL, LavaridgeTown_HerbShop_EventScript_1FE534
	msgbox LavaridgeTown_HerbShop_Text_1FE584, MSGBOX_DEFAULT
	giveitem_std ITEM_CHARCOAL
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLFLAG_RECEIVED_CHARCOAL
	release
	end

LavaridgeTown_HerbShop_EventScript_1FE534:: @ 81FE534
	msgbox LavaridgeTown_HerbShop_Text_1FE5EB, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_HerbShop_Text_1FE53E: @ 81FE53E
	.string "Bienvenue à l'HERBORISTERIE, la maison\n"
	.string "des médicaments efficaces à bas prix!$"

LavaridgeTown_HerbShop_Text_1FE584: @ 81FE584
	.string "Tu viens chercher des médicaments\n"
	.string "à base de plantes à VERMILAVA?\p"
	.string "C'est très honorable.\p"
	.string "Je t'aime bien! Prends ça!$"

LavaridgeTown_HerbShop_Text_1FE5EB: @ 81FE5EB
	.string "Le CHARBON que je t'ai donné est utilisé\n"
	.string "pour faire des médicaments naturels.\p"
	.string "Il fait aussi des merveilles lorsqu'il\n"
	.string "est tenu par un POKéMON.\p"
	.string "Il augmente la puissance des attaques\n"
	.string "de type FEU.$"

LavaridgeTown_HerbShop_Text_1FE685: @ 81FE685
	.string "La médecine à base de plantes est\n"
	.string "extrêmement efficace. Mais tes POKéMON\p"
	.string "risquent de ne pas apprécier\n"
	.string "Les médicaments sont très amers!$"

