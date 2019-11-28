AbandonedShip_Rooms2_1F_MapScripts:: @ 82380A6
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_2380A7:: @ 82380A7
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_23819D, AbandonedShip_Rooms2_1F_Text_2381DA, AbandonedShip_Rooms2_1F_Text_238257, AbandonedShip_Rooms2_1F_EventScript_2380D7
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq AbandonedShip_Rooms2_1F_EventScript_2380F0
	msgbox AbandonedShip_Rooms2_1F_Text_23820F, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_2380D7:: @ 82380D7
	msgbox AbandonedShip_Rooms2_1F_Text_2383BB, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_2380F0:: @ 82380F0
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_2383FF, AbandonedShip_Rooms2_1F_Text_238473, AbandonedShip_Rooms2_1F_Text_238509
	msgbox AbandonedShip_Rooms2_1F_Text_238491, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_23810B:: @ 823810B
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_2382A4, AbandonedShip_Rooms2_1F_Text_2382F4, AbandonedShip_Rooms2_1F_Text_23836F, AbandonedShip_Rooms2_1F_EventScript_23813B
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq AbandonedShip_Rooms2_1F_EventScript_238154
	msgbox AbandonedShip_Rooms2_1F_Text_23830A, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_23813B:: @ 823813B
	msgbox AbandonedShip_Rooms2_1F_Text_2383BB, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_238154:: @ 8238154
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_238556, AbandonedShip_Rooms2_1F_Text_2385F2, AbandonedShip_Rooms2_1F_Text_238668
	msgbox AbandonedShip_Rooms2_1F_Text_23860B, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_23816F:: @ 823816F
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_2386B4, AbandonedShip_Rooms2_1F_Text_2386E8
	msgbox AbandonedShip_Rooms2_1F_Text_238708, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_238186:: @ 8238186
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_23873F, AbandonedShip_Rooms2_1F_Text_238779
	msgbox AbandonedShip_Rooms2_1F_Text_2387A9, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_23819D: @ 823819D
	.string "JOE: En cherchant des trésors,\n"
	.string "on a découvert un DRESSEUR!$"

AbandonedShip_Rooms2_1F_Text_2381DA: @ 82381DA
	.string "JOE: On n'a pas réussi à gagner,\n"
	.string "même en se mettant ensemble…$"

AbandonedShip_Rooms2_1F_Text_23820F: @ 823820F
	.string "JOE: On n'a pas trouvé de trésors…\n"
	.string "Quelqu'un les aurait-il déjà pris?$"

AbandonedShip_Rooms2_1F_Text_238257: @ 8238257
	.string "JOE: Tu n'as même pas deux POKéMON.\n"
	.string "N'espère pas nous battre comme ça.$"

AbandonedShip_Rooms2_1F_Text_2382A4: @ 82382A4
	.string "RITA: Oh?! On cherchait des trésors,\n"
	.string "mais on n'a trouvé qu'un DRESSEUR.$"

AbandonedShip_Rooms2_1F_Text_2382F4: @ 82382F4
	.string "RITA: Oh, waouh, quelle force!$"

AbandonedShip_Rooms2_1F_Text_23830A: @ 823830A
	.string "RITA: Je me demande où les trésors\n"
	.string "peuvent bien être cachés.\p"
	.string "Je sais déjà ce que je vais m'acheter\n"
	.string "quand on les aura trouvés!$"

AbandonedShip_Rooms2_1F_Text_23836F: @ 823836F
	.string "RITA: Tu n'as pas deux POKéMON?\n"
	.string "On se battra une autre fois alors!$"

AbandonedShip_Rooms2_1F_Text_2383BB: @ 82383BB
	.string "RITA: Tu m'as mise en colère!\n"
	.string "Je vais t'enregistrer pour la peine!$"

AbandonedShip_Rooms2_1F_Text_2383FF: @ 82383FF
	.string "JOE: On a passé tout ce temps à\n"
	.string "chercher des trésors.\p"
	.string "Nos POKéMON sont devenus plus forts.\n"
	.string "On t'fait voir, OK?$"

AbandonedShip_Rooms2_1F_Text_238473: @ 8238473
	.string "JOE: Toujours autant de force!$"

AbandonedShip_Rooms2_1F_Text_238491: @ 8238491
	.string "JOE: On n'a pas trouvé de trésors,\n"
	.string "on a perdu notre combat de POKéMON…\p"
	.string "Je veux rentrer à la maison… Mais si je\n"
	.string "dis ça, elle va m'en vouloir…$"

AbandonedShip_Rooms2_1F_Text_238509: @ 8238509
	.string "JOE: Tu n'as même pas deux POKéMON.\n"
	.string "N'espère pas nous battre comme ça.$"

AbandonedShip_Rooms2_1F_Text_238556: @ 8238556
	.string "RITA: Oh, salut! Comme on s'retrouve!\p"
	.string "Tout comme nous, t'as pas arrêté de\n"
	.string "chercher des trésors!\p"
	.string "Si on se battait? Et le perdant arrête\n"
	.string "de chercher!$"

AbandonedShip_Rooms2_1F_Text_2385F2: @ 82385F2
	.string "RITA: Oh, on a encore perdu…$"

AbandonedShip_Rooms2_1F_Text_23860B: @ 823860B
	.string "RITA: On va élever le niveau de nos\n"
	.string "POKéMON."
	.string "Et on ne rentrera pas à la maison avant\l"
	.string "d'avoir trouvé des trésors!$"

AbandonedShip_Rooms2_1F_Text_238668: @ 8238668
	.string "RITA: Tu n'as pas deux POKéMON?\n"
	.string "On se battra une autre fois alors!$"

AbandonedShip_Rooms2_1F_Text_2386B4: @ 82386B4
	.string "Je ne sais pas bien nager, mais quand\n"
	.string "il s'agit de se battre…$"

AbandonedShip_Rooms2_1F_Text_2386E8: @ 82386E8
	.string "Oups, ça n'a pas vraiment bien marché.$"

AbandonedShip_Rooms2_1F_Text_238708: @ 8238708
	.string "Ça ne se fait pas vraiment de marcher\n"
	.string "pieds nus sur un bateau.$"

AbandonedShip_Rooms2_1F_Text_23873F: @ 823873F
	.string "Force et compassion…\n"
	.string "Ce sont les trésors d'un DRESSEUR!$"

AbandonedShip_Rooms2_1F_Text_238779: @ 8238779
	.string "Quelque chose brille en toi, ça se\n"
	.string "voit tout de suite.$"

AbandonedShip_Rooms2_1F_Text_2387A9: @ 82387A9
	.string "J'ai vu quelque chose briller dans une\n"
	.string "des cabines du bateau.$"
