SootopolisCity_House4_MapScripts:: @ 8226D15
	.byte 0

SootopolisCity_House4_EventScript_226D16:: @ 8226D16
	msgbox SootopolisCity_House4_Text_226D3B, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_226D1F:: @ 8226D1F
	msgbox SootopolisCity_House4_Text_226DEA, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_226D28:: @ 8226D28
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, 0
	msgbox SootopolisCity_House4_Text_226E7F, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House4_Text_226D3B: @ 8226D3B
	.string "Ecoute-moi bien, je vais te dire\n"
	.string "quelque chose d'intéressant.\p"
	.string "Il paraît qu'il existe, pas très loin\n"
	.string "d'ici, une vieille ruine dans la mer.\p"
	.string "Il y a peut-être là-bas des trésors qui\n"
	.string "ne demandent qu'à être découverts.$"

SootopolisCity_House4_Text_226DEA: @ 8226DEA
	.string "D'anciens trésors…\p"
	.string "Ce serait formidable s'ils existaient\n"
	.string "vraiment, mais même si ce n'est pas le\l"
	.string "cas, ce serait merveilleux de faire\l"
	.string "un tour sous l'eau avec mon POKéMON.$"

SootopolisCity_House4_Text_226E7F: @ 8226E7F
	.string "AZUMARILL: Zuzu.$"

