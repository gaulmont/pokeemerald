PacifidlogTown_House3_MapScripts:: @ 8203C10
	.byte 0

PacifidlogTown_House3_EventScript_203C11:: @ 8203C11
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_203CAB
	setvar VAR_0x8008, INGAME_TRADE_HORSEA
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox PacifidlogTown_House3_Text_203CBE, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq PacifidlogTown_House3_EventScript_203C93
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq PacifidlogTown_House3_EventScript_203C93
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne PacifidlogTown_House3_EventScript_203C9D
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname 0, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_203D87, MSGBOX_DEFAULT
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

PacifidlogTown_House3_EventScript_203C93:: @ 8203C93
	msgbox PacifidlogTown_House3_Text_203E12, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_203C9D:: @ 8203C9D
	bufferspeciesname 0, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_203DDE, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_203CAB:: @ 8203CAB
	msgbox PacifidlogTown_House3_Text_203E7F, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_203CB5:: @ 8203CB5
	msgbox PacifidlogTown_House3_Text_203EF1, MSGBOX_NPC
	end

PacifidlogTown_House3_Text_203CBE: @ 8203CBE
	.string "Check out this {STR_VAR_2}!\p"
	.string "Je l'ai attrapé hier pour fêter mon\n"
	.string "anniversaire!\p"
	.string "Il te plaît, on dirait!\n"
	.string "Comme je te comprends…\p"
	.string "Bon… J'accepterais peut-être\n"
	.string "de l'échanger contre un {STR_VAR_1}.$"

PacifidlogTown_House3_Text_203D87: @ 8203D87
	.string "Oh, c'est un {STR_VAR_1}?\p"
	.string "Ça ressemble à un {STR_VAR_2}, la\n"
	.string "différence est subtile.\p"
	.string "Merci!$"

PacifidlogTown_House3_Text_203DDE: @ 8203DDE
	.string "Non, non et non! Un {STR_VAR_1}\n"
	.string "sinon rien!$"

PacifidlogTown_House3_Text_203E12: @ 8203E12
	.string "Oh, pas d'échange alors?\p"
	.string "Pas de problème. Je n'insiste pas.$"

PacifidlogTown_House3_Text_203E7F: @ 8203E7F
	.string "Je sais que j'aurais pu m'en trouver un\n"
	.string "moi-même…\p"
	.string "Mais je voulais un DRABY attrapé par un\n"
	.string "autre DRESSEUR…$"

PacifidlogTown_House3_Text_203EF1: @ 8203EF1
	.string "C'est un POKéDEX?\p"
	.string "Tu as rencontré beaucoup de POKéMON\n"
	.string "différents?\p"
	.string "J'aimerais bien être comme toi.$"

