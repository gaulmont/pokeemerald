RustboroCity_House1_MapScripts:: @ 821593E
	.byte 0

RustboroCity_House1_EventScript_21593F:: @ 821593F
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_2159D5
	setvar VAR_0x8008, INGAME_TRADE_SEEDOT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox RustboroCity_House1_Text_2159E8, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_House1_EventScript_2159BD
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq RustboroCity_House1_EventScript_2159BD
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne RustboroCity_House1_EventScript_2159C7
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox RustboroCity_House1_Text_215A77, MSGBOX_DEFAULT
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House1_EventScript_2159BD:: @ 82159BD
	msgbox RustboroCity_House1_Text_215ACE, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_2159C7:: @ 82159C7
	bufferspeciesname 0, VAR_0x8009
	msgbox RustboroCity_House1_Text_215A9D, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_2159D5:: @ 82159D5
	msgbox RustboroCity_House1_Text_215B17, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_2159DF:: @ 82159DF
	msgbox RustboroCity_House1_Text_215B57, MSGBOX_NPC
	end

RustboroCity_House1_Text_2159E8: @ 82159E8
	.string "Hein? Mon POKéMON est mignon?\n"
	.string "Bien sûr que je le sais.\p"
	.string "Mais si tu veux, je suis d'accord pour\n"
	.string "te l'échanger.\p"
	.string "Je t'échange mon {STR_VAR_2} contre\n"
	.string "un {STR_VAR_1} si tu veux.$"

RustboroCity_House1_Text_215A77: @ 8215A77
	.string "Hé hé…\n"
	.string "Sois sympa avec mon POKéMON.$"

RustboroCity_House1_Text_215A9D: @ 8215A9D
	.string "Hein? Il ressemble pas vraiment à\n"
	.string "un {STR_VAR_1}.$"

RustboroCity_House1_Text_215ACE: @ 8215ACE
	.string "Oh, si tu ne veux pas, c'est d'accord.\n"
	.string "Mais il est vraiment mignon, tu sais?$"

RustboroCity_House1_Text_215B17: @ 8215B17
	.string "Tous les POKéMON peuvent être mignons\n"
	.string "s'ils sont élevés avec gentillesse.$"

RustboroCity_House1_Text_215B57: @ 8215B57
	.string "Chaque endroit a ses types précis de\n"
	.string "POKéMON et de personnes.\p"
	.string "Je trouve ça si fascinant que je me\n"
	.string "balade un peu partout.$"

