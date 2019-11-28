LilycoveCity_House1_MapScripts:: @ 821ECCD
	.byte 0

LilycoveCity_House1_EventScript_21ECCE:: @ 821ECCE
	msgbox LilycoveCity_House1_Text_21ECEA, MSGBOX_NPC
	end

LilycoveCity_House1_EventScript_21ECD7:: @ 821ECD7
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KECLEON, 0
	msgbox LilycoveCity_House1_Text_21ED63, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_House1_Text_21ECEA: @ 821ECEA
	.string "Les POKéMON sont les partenaires des\n"
	.string "hommes. Ils ne sont pas nos outils.\p"
	.string "Malheureusement, certaines personnes\n"
	.string "ne veulent pas comprendre ça…$"

LilycoveCity_House1_Text_21ED63: @ 821ED63
	.string "KECLEON: Kécléééon?$"