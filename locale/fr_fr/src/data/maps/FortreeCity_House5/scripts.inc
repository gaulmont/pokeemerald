FortreeCity_House5_MapScripts:: @ 8217EF1
	.byte 0

FortreeCity_House5_EventScript_217EF2:: @ 8217EF2
	msgbox FortreeCity_House5_Text_217F17, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_217EFB:: @ 8217EFB
	msgbox FortreeCity_House5_Text_217F80, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_217F04:: @ 8217F04
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, 0
	msgbox FortreeCity_House5_Text_217FFB, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House5_Text_217F17: @ 8217F17
	.string "Les cabanes de CIMETRONELLE\n"
	.string "sont géniales!\p"
	.string "Je trouve que c'est la ville parfaite\n"
	.string "pour vivre avec les POKéMON.$"

FortreeCity_House5_Text_217F80: @ 8217F80
	.string "Les POKéMON et les hommes se sont\n"
	.string "adaptés à la nature pour survivre.\p"
	.string "Il n'est pas nécessaire d'adapter la\n"
	.string "nature au mode de vie que l'on souhaite.$"

FortreeCity_House5_Text_217FFB: @ 8217FFB
	.string "ZIGZATON: Zaaaton!$"

