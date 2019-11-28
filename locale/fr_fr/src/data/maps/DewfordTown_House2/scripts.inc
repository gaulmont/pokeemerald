DewfordTown_House2_MapScripts:: @ 81FE22D
	.byte 0

DewfordTown_House2_EventScript_1FE22E:: @ 81FE22E
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_1FE267
	msgbox DewfordTown_House2_Text_1FE27A, MSGBOX_DEFAULT
	giveitem_std ITEM_SILK_SCARF
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_House2_EventScript_1FE25D
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_1FE25D:: @ 81FE25D
	msgbox DewfordTown_House2_Text_1FE356, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_1FE267:: @ 81FE267
	msgbox DewfordTown_House2_Text_1FE3D1, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_1FE271:: @ 81FE271
	msgbox DewfordTown_House2_Text_1FE444, MSGBOX_NPC
	end

DewfordTown_House2_Text_1FE27A: @ 81FE27A
	.string "Regarde-moi cette merveille!\p"
	.string "un MOUCH. SOIE. C'est à la pointe\n"
	.string "de la mode!\p"
	.string "Oh, je vois une lueur dans tes yeux!\n"
	.string "Mon style éblouissant te plaît!\p"
	.string "Oh, tu me fais plaisir!\n"
	.string "Tiens, voilà. Je te le donne!$"

DewfordTown_House2_Text_1FE356: @ 81FE356
	.string "Oh, tu n'as plus de place?\p"
	.string "Bon, écoute-moi bien, cet objet est\n"
	.string "indispensable! Il vaut bien tous les\l"
	.string "objets que j'ai sur moi.$"

DewfordTown_House2_Text_1FE3D1: @ 81FE3D1
	.string "Le MOUCH. SOIE augmente la puissance\n"
	.string "des attaques de type NORMAL.\p"
	.string "C'est un MOUCHOIR merveilleux assorti à\n"
	.string "presque tous les POKéMON!$"

DewfordTown_House2_Text_1FE444: @ 81FE444
	.string "Ouah, tu as franchi la mer pour\n"
	.string "venir visiter MYOKARA?\p"
	.string "Tu es peut-être ici parce que tu\n"
	.string "as entendu parler de BASTIEN?\p"
	.string "Il est super cool…\n"
	.string "Tout le monde l'adore.$"

