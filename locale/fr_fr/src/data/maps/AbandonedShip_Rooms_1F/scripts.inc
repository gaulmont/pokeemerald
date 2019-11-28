AbandonedShip_Rooms_1F_MapScripts:: @ 8237A92
	.byte 0

AbandonedShip_Rooms_1F_EventScript_237A93:: @ 8237A93
	msgbox AbandonedShip_Rooms_1F_Text_237B15, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_237A9C:: @ 8237A9C
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_237D0C, AbandonedShip_Rooms_1F_Text_237D2A
	msgbox AbandonedShip_Rooms_1F_Text_237D41, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_237AB3:: @ 8237AB3
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_237B76, AbandonedShip_Rooms_1F_Text_237BB8, AbandonedShip_Rooms_1F_EventScript_237ADF
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq AbandonedShip_Rooms_1F_EventScript_237AFE
	msgbox AbandonedShip_Rooms_1F_Text_237BDB, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_EventScript_237ADF:: @ 8237ADF
	special sub_80B4808
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_237C2A, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_237AFE:: @ 8237AFE
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_237C69, AbandonedShip_Rooms_1F_Text_237CB2
	msgbox AbandonedShip_Rooms_1F_Text_237CC9, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_237B15: @ 8237B15
	.string "Les bateaux de ce genre sont rares,\n"
	.string "alors je vais y jeter un coup d'œil.\p"
	.string "Hum…\n"
	.string "On dirait qu'il y a d'autres cabines…$"

AbandonedShip_Rooms_1F_Text_237B76: @ 8237B76
	.string "Qu'est-ce qui a bien pu te pousser\n"
	.string "à venir ici?\p"
	.string "Tu ne sais pas que la curiosité est\n"
	.string "un vilain défaut?$"

AbandonedShip_Rooms_1F_Text_237BB8: @ 8237BB8
	.string "Et plutôt tenace en plus de ça!$"

AbandonedShip_Rooms_1F_Text_237BDB: @ 8237BDB
	.string "L'homme d'à côté…\p"
	.string "Il dit qu'il est juste là pour voir le\n"
	.string "paysage, mais j'ai du mal à le croire.$"

AbandonedShip_Rooms_1F_Text_237C2A: @ 8237C2A
	.string "Tu es si jeune pour un DRESSEUR!\n"
	.string "Laisse-moi t'enregistrer!$"

AbandonedShip_Rooms_1F_Text_237C69: @ 8237C69
	.string "Qu'est-ce qui a bien pu te pousser\n"
	.string "à revenir ici?\p"
	.string "Quelle curiosité, ma parole!$"

AbandonedShip_Rooms_1F_Text_237CB2: @ 8237CB2
	.string "C'est normal d'avoir tant de force\n"
	.string "dans un si petit corps?$"

AbandonedShip_Rooms_1F_Text_237CC9: @ 8237CC9
	.string "Je suis sûre que cet homme cherche\n"
	.string "quelque chose. Il est vraiment étrange!$"

AbandonedShip_Rooms_1F_Text_237D0C: @ 8237D0C
	.string "Waaah!\n"
	.string "Tu m'as trouvé?$"

AbandonedShip_Rooms_1F_Text_237D2A: @ 8237D2A
	.string "Oh, t'es pas ma maman toi!$"

AbandonedShip_Rooms_1F_Text_237D41: @ 8237D41
	.string "J'ai peur de me faire gronder, alors\n"
	.string "je me cache…\p"
	.string "Tu diras rien, d'accord?$"

