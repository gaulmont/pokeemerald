SeafloorCavern_Room1_MapScripts:: @ 82347EB
	.byte 0

SeafloorCavern_Room1_EventScript_2347EC:: @ 82347EC
	trainerbattle_single TRAINER_GRUNT_5, SeafloorCavern_Room1_Text_23481A, SeafloorCavern_Room1_Text_23484A
	msgbox SeafloorCavern_Room1_Text_23485D, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_234803:: @ 8234803
	trainerbattle_single TRAINER_GRUNT_6, SeafloorCavern_Room1_Text_234898, SeafloorCavern_Room1_Text_2348CD
	msgbox SeafloorCavern_Room1_Text_2348E3, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_23481A: @ 823481A
	.string "Pas besoin d'un môme dans nos pattes!\n"
	.string "Rentre chez toi!$"

SeafloorCavern_Room1_Text_23484A: @ 823484A
	.string "Je veux rentrer chez moi…$"

SeafloorCavern_Room1_Text_23485D: @ 823485D
	.string "Je veux avoir une promotion pour\n"
	.string "donner des ordres aux SBIRES…$"

SeafloorCavern_Room1_Text_234898: @ 8234898
	.string "Ce sous-marin… C'est minuscule à\n"
	.string "l'intérieur. J'ai mal partout!$"

SeafloorCavern_Room1_Text_2348CD: @ 82348CD
	.string "Ça m'énerve de perdre!$"

SeafloorCavern_Room1_Text_2348E3: @ 82348E3
	.string "Ce sous-marin qu'on a piqué…\n"
	.string "Plutôt brutale la balade!\l"
	.string "C'est trop étroit là-dedans!$"

