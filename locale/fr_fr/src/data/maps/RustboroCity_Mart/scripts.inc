RustboroCity_Mart_MapScripts:: @ 8214F05
	.byte 0

RustboroCity_Mart_EventScript_214F06:: @ 8214F06
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_unset FLAG_MET_DEVON_EMPLOYEE, RustboroCity_Mart_EventScript_214F21
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, RustboroCity_Mart_EventScript_214F48
	end

RustboroCity_Mart_EventScript_214F21:: @ 8214F21
	pokemart RustboroCity_Mart_Pokemart_214F30
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

RustboroCity_Mart_Pokemart_214F30: @ 8214F30
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_NONE
	release
	end

RustboroCity_Mart_EventScript_214F48:: @ 8214F48
	pokemart RustboroCity_Mart_Pokemart_214F58
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
RustboroCity_Mart_Pokemart_214F58: @ 8214F58
	.2byte ITEM_POKE_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_NONE
	release
	end

RustboroCity_Mart_EventScript_214F74:: @ 8214F74
	msgbox RustboroCity_Mart_Text_214F8F, MSGBOX_NPC
	end

RustboroCity_Mart_EventScript_214F7D:: @ 8214F7D
	msgbox RustboroCity_Mart_Text_214FF1, MSGBOX_NPC
	end

RustboroCity_Mart_EventScript_214F86:: @ 8214F86
	msgbox RustboroCity_Mart_Text_21505C, MSGBOX_NPC
	end

RustboroCity_Mart_Text_214F8F: @ 8214F8F
	.string "J'achète des ANTI-PARA et des\n"
	.string "ANTIDOTES.\p"
	.string "C'est juste au cas où je tomberais sur\n"
	.string "un BALIGNON au BOIS CLEMENTI.$"

RustboroCity_Mart_Text_214FF1: @ 8214FF1
	.string "Mon POKéMON a évolué.\n"
	.string "Il a plein de PV maintenant.\p"
	.string "Je ferais mieux d'acheter des SUPER\n"
	.string "POTIONS plutôt que de simples POTIONS.$"

RustboroCity_Mart_Text_21505C: @ 821505C
	.string "J'ai pris une CORDE SORTIE, juste au\n"
	.string "cas où je me perdrais dans une caverne.\p"
	.string "Il me suffit de l'utiliser pour me\n"
	.string "retrouver directement à l'entrée.$"

