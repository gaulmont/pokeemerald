SeafloorCavern_Room4_MapScripts:: @ 8234C9B
	.byte 0

SeafloorCavern_Room4_EventScript_234C9C:: @ 8234C9C
	trainerbattle_single TRAINER_GRUNT_7, SeafloorCavern_Room4_Text_234CCA, SeafloorCavern_Room4_Text_234CF3
	msgbox SeafloorCavern_Room4_Text_234CFC, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_EventScript_234CB3:: @ 8234CB3
	trainerbattle_single TRAINER_GRUNT_9, SeafloorCavern_Room4_Text_234D3A, SeafloorCavern_Room4_Text_234D68
	msgbox SeafloorCavern_Room4_Text_234D79, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_Text_234CCA: @ 8234CCA
	.string "Qui es-tu?\n"
	.string "Comment as-tu atterri ici?$"

SeafloorCavern_Room4_Text_234CF3: @ 8234CF3
	.string "J'ai perdu…$"

SeafloorCavern_Room4_Text_234CFC: @ 8234CFC
	.string "J'arrive pas à trouver d'issue!\p"
	.string "J'ai pas peur. Comprends-moi bien!$"

SeafloorCavern_Room4_Text_234D3A: @ 8234D3A
	.string "Qui es-tu?\n"
	.string "Pour qui est-ce que tu te prends?$"

SeafloorCavern_Room4_Text_234D68: @ 8234D68
	.string "Tu m'as eue!$"

SeafloorCavern_Room4_Text_234D79: @ 8234D79
	.string "Mon partenaire a oublié la carte dans\n"
	.string "le sous-marin!\p"
	.string "C'est le roi des incapables!$"

