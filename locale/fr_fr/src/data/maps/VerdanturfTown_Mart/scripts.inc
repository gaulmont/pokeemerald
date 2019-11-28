VerdanturfTown_Mart_MapScripts:: @ 8202586
	.byte 0

VerdanturfTown_Mart_EventScript_202587:: @ 8202587
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VerdanturfTown_Mart_Pokemart_2025A0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart_2025A0: @ 82025A0
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_FLUFFY_TAIL
	.2byte ITEM_NONE
	release
	end

VerdanturfTown_Mart_EventScript_2025BA:: @ 82025BA
	msgbox VerdanturfTown_Mart_Text_2025D5, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_2025C3:: @ 82025C3
	msgbox VerdanturfTown_Mart_Text_20264C, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_2025CC:: @ 82025CC
	msgbox VerdanturfTown_Mart_Text_2026C9, MSGBOX_NPC
	end

VerdanturfTown_Mart_Text_2025D5: @ 82025D5
	.string "Pour les combats de POKéMON, SPECIAL +\n"
	.string "est crucial.\p"
	.string "Cela permet d'augmenter la puissance de\n"
	.string "certaines attaques pendant un combat.$"

VerdanturfTown_Mart_Text_20264C: @ 820264C
	.string "Je ne trouve aucun livre de stratégie\n"
	.string "sur les TENTES DE COMBAT…\p"
	.string "Peut-être qu'il faut simplement suivre\n"
	.string "son instinct, après tout…$"

VerdanturfTown_Mart_Text_2026C9: @ 82026C9
	.string "La FAIBLO BALL fonctionne mieux\n"
	.string "sur les POKéMON faibles.\p"
	.string "On ne peut en acheter qu'à VERGAZON.$"

