SSTidalLowerDeck_MapScripts:: @ 823C818
	.byte 0

SSTidalLowerDeck_EventScript_23C819:: @ 823C819
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_23C847, SSTidalLowerDeck_Text_23C8A0
	msgbox SSTidalLowerDeck_Text_23C8B4, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_23C830:: @ 823C830
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_23C917, SSTidalLowerDeck_Text_23C97D
	msgbox SSTidalLowerDeck_Text_23C98E, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_Text_23C847: @ 823C847
	.string "Arrrg! J'en ai plein le dos de nettoyer\n"
	.string "cet endroit gigantesque!\p"
	.string "C'est l'heure de la pause,\n"
	.string "battons-nous!$"

SSTidalLowerDeck_Text_23C8A0: @ 823C8A0
	.string "Hé, p'tit frère, j'ai perdu!$"

SSTidalLowerDeck_Text_23C8B4: @ 823C8B4
	.string "Nous sommes les FRERES PROPRETE!\p"
	.string "L'aîné répand le détergent et le\n"
	.string "benjamin frotte!$"

SSTidalLowerDeck_Text_23C917: @ 823C917
	.string "Nous sommes dans la cale du navire.\n"
	.string "Il y a beaucoup de place.\l"
	.string "Profitons-en pour faire un combat\l"
	.string "de POKéMON.$"

SSTidalLowerDeck_Text_23C97D: @ 823C97D
	.string "Hé, grand frère, j'ai perdu!$"

SSTidalLowerDeck_Text_23C98E: @ 823C98E
	.string "Nous sommes les FRERES PROPRETE!\p"
	.string "L'aîné répand le détergent et le\n"
	.string "benjamin frotte!$"

