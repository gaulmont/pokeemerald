BattleFrontier_Lounge6_MapScripts:: @ 8264FEC
	.byte 0

BattleFrontier_Lounge6_EventScript_264FED:: @ 8264FED
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_265083
	setvar VAR_0x8008, INGAME_TRADE_MEOWTH
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox BattleFrontier_Lounge6_Text_26508D, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_Lounge6_EventScript_26506B
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq BattleFrontier_Lounge6_EventScript_26506B
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne BattleFrontier_Lounge6_EventScript_265075
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox BattleFrontier_Lounge6_Text_265128, MSGBOX_DEFAULT
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_26506B:: @ 826506B
	msgbox BattleFrontier_Lounge6_Text_2651CB, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_265075:: @ 8265075
	bufferspeciesname 0, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_26518D, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_265083:: @ 8265083
	msgbox BattleFrontier_Lounge6_Text_26520E, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_26508D: @ 826508D
	.string "Mon POKéMON est un {STR_VAR_2}.\n"
	.string "Tu connais?\l"
	.string "C'est assez mignon et plutôt joli.\p"
	.string "Celui-là, je serais fière de l'échanger!\p"
	.string "Tu veux échanger un {STR_VAR_1} contre\n"
	.string "mon {STR_VAR_2}?$"

BattleFrontier_Lounge6_Text_265128: @ 8265128
	.string "Oh, c'est adorable!\n"
	.string "Merci!\l"
	.string "Je vais bien m'en occuper!\p"
	.string "Dis, j'espère que tu prendras bien soin\n"
	.string "de mon {STR_VAR_2}!$"

BattleFrontier_Lounge6_Text_26518D: @ 826518D
	.string "Oh, je suis désolée!\n"
	.string "Je ferai l'échange uniquement contre un\l"
	.string "{STR_VAR_1}.$"

BattleFrontier_Lounge6_Text_2651CB: @ 82651CB
	.string "Oh, tu ne veux pas?\n"
	.string "Bon, pas de problème.\l"
	.string "Reviens quand tu veux.$"

BattleFrontier_Lounge6_Text_26520E: @ 826520E
	.string "Hi, hi!\n"
	.string "Un SKITTY, c'est encore plus mignon\l"
	.string "que je ne le pensais!$"
