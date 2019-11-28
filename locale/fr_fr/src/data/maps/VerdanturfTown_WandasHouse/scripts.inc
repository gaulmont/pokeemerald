VerdanturfTown_WandasHouse_MapScripts:: @ 82028BE
	.byte 0

VerdanturfTown_WandasHouse_EventScript_2028BF:: @ 82028BF
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_2028D7
	msgbox VerdanturfTown_WandasHouse_Text_202993, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_2028D7:: @ 82028D7
	msgbox VerdanturfTown_WandasHouse_Text_202ABE, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_2028E1:: @ 82028E1
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_202909
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_2028FF
	msgbox VerdanturfTown_WandasHouse_Text_202B37, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_2028FF:: @ 82028FF
	msgbox VerdanturfTown_WandasHouse_Text_202C20, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_202909:: @ 8202909
	msgbox VerdanturfTown_WandasHouse_Text_202C4E, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_202913:: @ 8202913
	msgbox VerdanturfTown_WandasHouse_Text_202E00, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_20291C:: @ 820291C
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_202944
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_20293A
	msgbox VerdanturfTown_WandasHouse_Text_202D91, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_20293A:: @ 820293A
	msgbox VerdanturfTown_WandasHouse_Text_202CCF, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_202944:: @ 8202944
	msgbox VerdanturfTown_WandasHouse_Text_202D91, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_20294E:: @ 820294E
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_202989
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_20297F
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_202975
	msgbox VerdanturfTown_WandasHouse_Text_202E47, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_202975:: @ 8202975
	msgbox VerdanturfTown_WandasHouse_Text_202F19, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_20297F:: @ 820297F
	msgbox VerdanturfTown_WandasHouse_Text_202F73, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_202989:: @ 8202989
	msgbox VerdanturfTown_WandasHouse_Text_202FDB, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_202993: @ 8202993
	.string "TIMMY: J'ai perdu contre toi, {PLAYER},\n"
	.string "mais je ne me sens plus déprimé.\p"
	.string "Maintenant, j'ai un nouveau but dans\n"
	.string "la vie. Avec mon TARSAL, je vais\p"
	.string "parcourir les ARENES et devenir un\n"
	.string "grand DRESSEUR.\p"
	.string "Regarde-moi bien, {PLAYER}.\n"
	.string "Je vais devenir plus fort que toi.\p"
	.string "Quand ce sera le cas, je te défierai\n"
	.string "encore une fois.$"

VerdanturfTown_WandasHouse_Text_202ABE: @ 8202ABE
	.string "TIMMY: Regarde-moi bien, {PLAYER}.\n"
	.string "Je vais devenir plus fort que toi.\p"
	.string "Quand ce sera le cas, je te défierai\n"
	.string "encore une fois.$"

VerdanturfTown_WandasHouse_Text_202B37: @ 8202B37
	.string "TONTON: Oh! {PLAYER}{KUN}!\n"
	.string "TIMMY est juste à côté.\p"
	.string "Mais avant, j'ai quelque chose à te dire.\p"
	.string "Cet environnement naturel fait des\n"
	.string "merveilles sur la santé de TIMMY.\p"
	.string "Mais ce n'est pas seulement\n"
	.string "l'environnement. Les POKéMON lui\l"
	.string "donnent aussi beaucoup d'espoir.$"

VerdanturfTown_WandasHouse_Text_202C20: @ 8202C20
	.string "TIMMY est parti…\n"
	.string "Il suit son propre chemin…$"

VerdanturfTown_WandasHouse_Text_202C4E: @ 8202C4E
	.string "TONTON: C'est vrai?\n"
	.string "TIMMY est allé aussi loin tout seul…\p"
	.string "Eh bien, il faudra que je le félicite.\n"
	.string "C'est bien le fils de mon frère.$"

VerdanturfTown_WandasHouse_Text_202CCF: @ 8202CCF
	.string "SYLVIE: Qui es-tu?\n"
	.string "Oh, d'accord, j'y suis!\p"
	.string "Tu es {PLAYER} TIMMY m'a parlé de toi.\p"
	.string "Je suis la cousine de TIMMY.\n"
	.string "Enchantée de te rencontrer!\p"
	.string "Je crois que TIMMY est bien plus enjoué\n"
	.string "et solide depuis qu'il est arrivé ici.$"

VerdanturfTown_WandasHouse_Text_202D91: @ 8202D91
	.string "SYLVIE: Ne t'inquiète pas pour\n"
	.string "TIMMY. Tout ira bien pour lui.\p"
	.string "Je connais bien mon petit cousin\n"
	.string "En plus, il a un POKéMON avec lui.$"

VerdanturfTown_WandasHouse_Text_202E00: @ 8202E00
	.string "Grâce à toi, je peux voir ma copine\n"
	.string "tous les jours.\l"
	.string "Si je suis content? Bien entendu!$"

VerdanturfTown_WandasHouse_Text_202E47: @ 8202E47
	.string "Le petit ami de ma fille est un garçon\n"
	.string "très expansif et passionné.\p"
	.string "Il creuse jour et nuit un tunnel juste\n"
	.string "pour voir ma fille.\p"
	.string "Ma fille est un peu inquiète, donc elle\n"
	.string "va souvent voir si le tunnel est fini.$"

VerdanturfTown_WandasHouse_Text_202F19: @ 8202F19
	.string "Incroyable, le petit ami de ma fille a\n"
	.string "creusé le tunnel de ses propres mains!\p"
	.string "C'est hallucinant!$"

VerdanturfTown_WandasHouse_Text_202F73: @ 8202F73
	.string "Si quelque chose arrivait à TIMMY,\n"
	.string "je ne pourrais plus regarder ses\l"
	.string "parents en face…$"

VerdanturfTown_WandasHouse_Text_202FDB: @ 8202FDB
	.string "TIMMY était à ETERNARA?\p"
	.string "Ses parents, qui sont à CLEMENTI,\n"
	.string "seraient stupéfaits d'entendre ça!$"

