LavaridgeTown_Mart_MapScripts:: @ 81FF9CD
	.byte 0

LavaridgeTown_Mart_EventScript_1FF9CE:: @ 81FF9CE
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LavaridgeTown_Mart_Pokemart_1FF9E8
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_Mart_Pokemart_1FF9E8: @ 81FF9E8
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_NONE
	release
	end

LavaridgeTown_Mart_EventScript_1FF9FE:: @ 81FF9FE
	msgbox LavaridgeTown_Mart_Text_1FFA10, MSGBOX_NPC
	end

LavaridgeTown_Mart_EventScript_1FFA07:: @ 81FFA07
	msgbox LavaridgeTown_Mart_Text_1FFA83, MSGBOX_NPC
	end

LavaridgeTown_Mart_Text_1FFA10: @ 81FFA10
	.string "Utilise VITESSE + pour augmenter la\n"
	.string "VITESSE d'un POKéMON au combat.\p"
	.string "Ça lui donnera plus de chances de\n"
	.string "frapper le premier, un sacré avantage!$"

LavaridgeTown_Mart_Text_1FFA83: @ 81FFA83
	.string "Au sommet du MONT CHIMNEE, on\n"
	.string "trouve une spécialité locale qu'on ne\l"
	.string "peut acheter que là-haut.\p"
	.string "Donne-la à un POKéMON. Il sera ravi.$"

