MossdeepCity_House1_MapScripts:: @ 8221FD5
	.byte 0

MossdeepCity_House1_EventScript_221FD6:: @ 8221FD6
	lock
	faceplayer
	bufferleadmonspeciesname 0
	msgbox MossdeepCity_House1_Text_22200F, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetPokeblockNameByMonNature
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_House1_EventScript_221FFC
	msgbox MossdeepCity_House1_Text_22201D, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_221FFC:: @ 8221FFC
	msgbox MossdeepCity_House1_Text_222068, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_222006:: @ 8222006
	msgbox MossdeepCity_House1_Text_222099, MSGBOX_NPC
	end

MossdeepCity_House1_Text_22200F: @ 822200F
	.string "Hum!\n"
	.string "Ton {STR_VAR_1}…$"

MossdeepCity_House1_Text_22201D: @ 822201D
	.string "Un {STR_VAR_1}S, il aime bien ça\n"
	.string "n'est-ce pas?\p"
	.string "Je suis catégorique là-dessus! Il aime\n"
	.string "beaucoup le {STR_VAR_1}S!$"

MossdeepCity_House1_Text_222068: @ 8222068
	.string "Il semble insensible aux différents\n"
	.string "goûts des {POKEBLOCK}S.$"

MossdeepCity_House1_Text_222099: @ 8222099
	.string "En un clin d'œil, mon mari peut dire\n"
	.string "quels {POKEBLOCK}S un POKéMON aime.$"

