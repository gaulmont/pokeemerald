AbandonedShip_Corridors_1F_MapScripts:: @ 82379A4
	.byte 0

AbandonedShip_Corridors_1F_EventScript_2379A5:: @ 82379A5
	msgbox AbandonedShip_Corridors_1F_Text_237A60, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_2379AE:: @ 82379AE
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_2379C5, AbandonedShip_Corridors_1F_Text_237A01
	msgbox AbandonedShip_Corridors_1F_Text_237A1B, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_1F_Text_2379C5: @ 82379C5
	.string "Qu'est-ce qu'il y a de si drôle à me voir\n"
	.string "à bord du bateau avec ma bouée?$"

AbandonedShip_Corridors_1F_Text_237A01: @ 8237A01
	.string "Waouh, tu m'as écrasé!$"

AbandonedShip_Corridors_1F_Text_237A1B: @ 8237A1B
	.string "C'est dur de lancer des POKé BALLS tout\n"
	.string "en se cramponnant à une bouée!$"

AbandonedShip_Corridors_1F_Text_237A60: @ 8237A60
	.string "C'est cool ici, hein?\n"
	.string "Je suis tout excité rien que d'être là!$"
