FortreeCity_DecorationShop_MapScripts:: @ 821800D
	.byte 0

FortreeCity_DecorationShop_EventScript_21800E:: @ 821800E
	msgbox FortreeCity_DecorationShop_Text_218078, MSGBOX_NPC
	end

FortreeCity_DecorationShop_EventScript_218017:: @ 8218017
	msgbox FortreeCity_DecorationShop_Text_2180ED, MSGBOX_NPC
	end

FortreeCity_DecorationShop_EventScript_218020:: @ 8218020
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration FortreeCity_DecorationShop_PokemartDecor_Desks
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

    .align 2
FortreeCity_DecorationShop_PokemartDecor_Desks: @ 8218038
	.2byte DECOR_SMALL_DESK
	.2byte DECOR_POKEMON_DESK
	.2byte DECOR_HEAVY_DESK
	.2byte DECOR_RAGGED_DESK
	.2byte DECOR_COMFORT_DESK
	.2byte DECOR_BRICK_DESK
	.2byte DECOR_CAMP_DESK
	.2byte DECOR_HARD_DESK
	.2byte DECOR_NONE
	release
	end

FortreeCity_DecorationShop_EventScript_21804C:: @ 821804C
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration FortreeCity_DecorationShop_PokemartDecor_Chairs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FortreeCity_DecorationShop_PokemartDecor_Chairs: @ 8218064
	.2byte DECOR_SMALL_CHAIR
	.2byte DECOR_POKEMON_CHAIR
	.2byte DECOR_HEAVY_CHAIR
	.2byte DECOR_RAGGED_CHAIR
	.2byte DECOR_COMFORT_CHAIR
	.2byte DECOR_BRICK_CHAIR
	.2byte DECOR_CAMP_CHAIR
	.2byte DECOR_HARD_CHAIR
	.2byte DECOR_NONE
	release
	end

FortreeCity_DecorationShop_Text_218078: @ 8218078
	.string "Ce que tu achètes ici est directement\n"
	.string "envoyé sur ton PC.\p"
	.string "C'est génial! J'aimerais bien qu'on me\n"
	.string "livre aussi comme ça, chez moi.$"

FortreeCity_DecorationShop_Text_2180ED: @ 82180ED
	.string "Je vais acheter un beau bureau et\n"
	.string "mettre mes jolies POUPEES dessus.\p"
	.string "Sinon, quand je vais décorer ma BASE\n"
	.string "SECRETE, mes POUPEES vont être salies\l"
	.string "et couvertes d'échardes.$"

