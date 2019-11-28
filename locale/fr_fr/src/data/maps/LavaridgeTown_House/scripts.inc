LavaridgeTown_House_MapScripts:: @ 81FF911
	.byte 0

LavaridgeTown_House_EventScript_1FF912:: @ 81FF912
	msgbox LavaridgeTown_House_Text_1FF92E, MSGBOX_NPC
	end

LavaridgeTown_House_EventScript_1FF91B:: @ 81FF91B
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, 0
	msgbox LavaridgeTown_House_Text_1FF9BB, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LavaridgeTown_House_Text_1FF92E: @ 81FF92E
	.string "Ma femme tente de faire éclore un OEUF\n"
	.string "dans les sources chaudes. Elle\l"
	.string "vient de me le dire.\p"
	.string "Elle a laissé deux POKéMON à la PENSION.\n"
	.string "Et ils ont découvert cet OEUF!$"

LavaridgeTown_House_Text_1FF9BB: @ 81FF9BB
	.string "ZIGZATON: Zigzaaa!$"

