AquaHideout_1F_MapScripts:: @ 8233493
	.byte 0

AquaHideout_1F_EventScript_233494:: @ 8233494
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_2334BC
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_2334B2
	msgbox AquaHideout_1F_Text_23351D, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_2334B2:: @ 82334B2
	msgbox AquaHideout_1F_Text_2335E3, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_2334BC:: @ 82334BC
	msgbox AquaHideout_1F_Text_23367D, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_2334C6:: @ 82334C6
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_2334EE
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_2334E4
	msgbox AquaHideout_1F_Text_233739, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_2334E4:: @ 82334E4
	msgbox AquaHideout_1F_Text_2337FA, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_2334EE:: @ 82334EE
	msgbox AquaHideout_1F_Text_233884, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_2334F8:: @ 82334F8
	trainerbattle_single TRAINER_GRUNT_1, AquaHideout_1F_Text_23393D, AquaHideout_1F_Text_233964, AquaHideout_1F_EventScript_233513
	msgbox AquaHideout_1F_Text_233977, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_233513:: @ 8233513
	msgbox AquaHideout_1F_Text_233977, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_23351D: @ 823351D
	.string "Quoi? Quoi? Qu'est-ce que tu veux\n"
	.string "à la TEAM AQUA?\p"
	.string "Notre CHEF n'est pas là! Il est parti\n"
	.string "chercher quelque chose d'important!\p"
	.string "… …\n"
	.string "Où est-il allé?\p"
	.string "Aaaaah! Tu crois vraiment que je vais\n"
	.string "te dire quelque chose d'aussi vital?$"

AquaHideout_1F_Text_2335E3: @ 82335E3
	.string "Qu… Quoi?\n"
	.string "Tu appartiens à la TEAM MAGMA?\p"
	.string "Il paraît que la TEAM MAGMA essaye\n"
	.string "de réveiller un POKéMON formidable\l"
	.string "dans leur PLANQUE.\p"
	.string "Mais où est-ce que cette PLANQUE\n"
	.string "peut bien se trouver?$"

AquaHideout_1F_Text_23367D: @ 823367D
	.string "Quoi? Quoi? Qu'est-ce que tu veux\n"
	.string "à la TEAM AQUA?\p"
	.string "Notre CHEF n'est pas là! Il est parti\n"
	.string "piquer un sous-marin!\p"
	.string "… …\n"
	.string "Où est-il allé?\p"
	.string "Aaaaah! Tu crois vraiment que je vais\n"
	.string "te dire quelque chose d'aussi vital?$"

AquaHideout_1F_Text_233739: @ 8233739
	.string "Quoi? Quoi? Qu'est-ce que tu veux\n"
	.string "à la TEAM AQUA?\p"
	.string "Notre CHEF n'est pas là! Il est parti\n"
	.string "Il est sur le CHENAL 122, en direction\l"
	.string "du MONT MEMORIA!\p"
	.string "… …\n"
	.string "Où est-il allé?\p"
	.string "Aaaaah! Tu crois vraiment que je vais\n"
	.string "te dire quelque chose d'aussi vital?$"

AquaHideout_1F_Text_2337FA: @ 82337FA
	.string "Qu… Quoi?\n"
	.string "Tu appartiens à la TEAM MAGMA?\p"
	.string "Il paraît que la TEAM MAGMA veut\n"
	.string "attraper un POKéMON formidable\l"
	.string "Mais à quoi peut bien ressembler\n"
	.string "ce POKéMON?$"

AquaHideout_1F_Text_233884: @ 8233884
	.string "Quoi? Quoi? Qu'est-ce que tu veux\n"
	.string "à la TEAM AQUA?\p"
	.string "Notre CHEF n'est pas là! Il est parti\n"
	.string "en direction de POIVRESSEL!\p"
	.string "… …\n"
	.string "Où est-il allé?\p"
	.string "Aaaaah! Tu crois vraiment que je vais\n"
	.string "te dire quelque chose d'aussi vital?$"

AquaHideout_1F_Text_23393D: @ 823393D
	.string "Ayaya!\n"
	.string "Personnage louche repéré!$"

AquaHideout_1F_Text_233964: @ 8233964
	.string "Arrrrg…\n"
	.string "J'ai perdu!$"

AquaHideout_1F_Text_233977: @ 8233977
	.string "J'ai perdu en essayant de défendre la\n"
	.string "TEAM, mais j'ai fait de mon mieux…$"

