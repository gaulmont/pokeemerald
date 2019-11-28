DewfordTown_House1_MapScripts:: @ 81FC3CD
	.byte 0

DewfordTown_House1_EventScript_1FC3CE:: @ 81FC3CE
	msgbox DewfordTown_House1_Text_1FC3F3, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_1FC3D7:: @ 81FC3D7
	msgbox DewfordTown_House1_Text_1FC45B, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_1FC3E0:: @ 81FC3E0
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, 0
	msgbox DewfordTown_House1_Text_1FC510, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_1FC3F3: @ 81FC3F3
	.string "Je pourrais parler pendant des heures\n"
	.string "de la vie sur une si petite île,\p"
	.string "en harmonie avec sa famille et ses\n"
	.string "POKéMON.$"

DewfordTown_House1_Text_1FC45B: @ 81FC45B
	.string "J'ai quitté POIVRESSEL pour\n"
	.string "vivre avec mon mari ici.\p"
	.string "La vie passe lentement sur cette\n"
	.string "île. Mais c'est un vrai bonheur d'être\l"
	.string "entourée de cette mer magnifique.$"

DewfordTown_House1_Text_1FC510: @ 81FC510
	.string "ZIGZATON: Zaaaton!$"

