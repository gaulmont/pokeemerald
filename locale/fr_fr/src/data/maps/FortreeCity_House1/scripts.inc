FortreeCity_House1_MapScripts:: @ 82162BA
	.byte 0

FortreeCity_House1_EventScript_2162BB:: @ 82162BB
	lock
	faceplayer
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_216355
	setvar VAR_0x8008, INGAME_TRADE_PLUSLE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox FortreeCity_House1_Text_21637B, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq FortreeCity_House1_EventScript_21633D
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq FortreeCity_House1_EventScript_21633D
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne FortreeCity_House1_EventScript_216347
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname 0, VAR_0x8009
	msgbox FortreeCity_House1_Text_216440, MSGBOX_DEFAULT
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	release
	end

FortreeCity_House1_EventScript_21633D:: @ 821633D
	msgbox FortreeCity_House1_Text_21649F, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_216347:: @ 8216347
	bufferspeciesname 0, VAR_0x8009
	msgbox FortreeCity_House1_Text_216474, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_216355:: @ 8216355
	msgbox FortreeCity_House1_Text_2164DB, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_21635F:: @ 821635F
	msgbox FortreeCity_House1_Text_21653B, MSGBOX_NPC
	end

FortreeCity_House1_EventScript_216368:: @ 8216368
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, 0
	msgbox FortreeCity_House1_Text_216597, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House1_Text_21637B: @ 821637B
	.string "Aaaah, j'en veux un!\n"
	.string "Il me faut un {STR_VAR_1}!\l"
	.string "Je ferais n'importe quoi pour en\n"
	.string "avoir un! C'est un vrai cri du cœur\p"
	.string "Maintenant que tu es au courant,\n"
	.string "tu vas échanger ton {STR_VAR_1}\l"
	.string "contre un {STR_VAR_2}, n'est-ce pas?$"

FortreeCity_House1_Text_216440: @ 8216440
	.string "Ouais, super!\p"
	.string "{STR_VAR_1}, bienvenue!\n"
	.string "{STR_VAR_2}, fais attention à toi!$"

FortreeCity_House1_Text_216474: @ 8216474
	.string "Ah non, je ne pense pas!\n"
	.string "Ce n'est pas un {STR_VAR_1}.$"

FortreeCity_House1_Text_21649F: @ 821649F
	.string "Non? Tu ne veux pas faire d'échange?\n"
	.string "Même après que je t'ai ouvert mon cœur?$"

FortreeCity_House1_Text_2164DB: @ 82164DB
	.string "A partir de maintenant, je vais rendre\n"
	.string "ce MUCIOLE très fort!\p"
	.string "J'espère que tu feras la même chose\n"
	.string "avec POSIPI!$"

FortreeCity_House1_Text_21653B: @ 821653B
	.string "Echanger des POKéMON avec d'autres…\p"
	.string "C'est comme échanger ses propres\n"
	.string "souvenirs avec quelqu'un d'autre.$"

FortreeCity_House1_Text_216597: @ 8216597
	.string "ZIGZATON: Zigzaaa?$"

