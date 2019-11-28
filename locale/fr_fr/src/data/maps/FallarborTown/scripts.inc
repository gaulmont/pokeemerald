FallarborTown_MapScripts:: @ 81EB1FA
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition: @ 81EB200
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_LINK_CONTEST_ROOM_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_1EB20C:: @ 81EB20C
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_1EB221
	msgbox FallarborTown_Text_1EB26B, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_1EB221:: @ 81EB221
	msgbox FallarborTown_Text_1EB2DE, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_1EB22B:: @ 81EB22B
	msgbox FallarborTown_Text_1EB35F, MSGBOX_NPC
	end

FallarborTown_EventScript_1EB234:: @ 81EB234
	msgbox FallarborTown_Text_1EB3CA, MSGBOX_NPC
	end

FallarborTown_EventScript_1EB23D:: @ 81EB23D
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, 0
	msgbox FallarborTown_Text_1EB3B5, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_1EB250:: @ 81EB250
	msgbox FallarborTown_Text_1EB4C2, MSGBOX_SIGN
	end

FallarborTown_EventScript_1EB259:: @ 81EB259
	msgbox FallarborTown_Text_1EB4FE, MSGBOX_SIGN
	end

FallarborTown_EventScript_1EB262:: @ 81EB262
	msgbox FallarborTown_Text_1EB534, MSGBOX_SIGN
	end

FallarborTown_Text_1EB26B: @ 81EB26B
	.string "Il se passe quelque chose d'étrange,\n"
	.string "je n'aime pas trop ça!\p"
	.string "J'ai aperçu quelqu'un entrer et sortir\n"
	.string "du LABO du PROF. KOSMO.$"

FallarborTown_Text_1EB2DE: @ 81EB2DE
	.string "Cela fait très longtemps que cette\n"
	.string "région est connue pour ses météorites.\p"
	.string "Un météorite se serait jadis écrasé,\n"
	.string "creusant le SITE METEORE.$"

FallarborTown_Text_1EB35F: @ 81EB35F
	.string "Tu vois! Regarde!\n"
	.string "C'est mon cher AZURILL!\p"
	.string "Il est adroit, et en plus il est doux!$"

FallarborTown_Text_1EB3B5: @ 81EB3B5
	.string "AZURILL: Azuzuuu.$"

FallarborTown_Text_1EB3CA: @ 81EB3CA
	.string "As-tu déjà affronté ADRIANE, le\n"
	.string "CHAMPION de l'ARENE de VERMILAVA?\p"
	.string "Son grand-père était célèbre.\n"
	.string "Il a fait partie du CONSEIL 4\l"
	.string "de la LIGUE POKéMON.\p"
	.string "Ça ne me surprendrait pas de voir\n"
	.string "ADRIANE devenir un grand DRESSEUR\l"
	.string "à son tour.$"

FallarborTown_Text_1EB4C2: @ 81EB4C2
	.string "TENTE DE COMBAT d'AUTEQUIA\n"
	.string "“Que les meilleures équipes|nb|se rencontrent!”$"

FallarborTown_Text_1EB4FE: @ 81EB4FE
	.string "AUTEQUIA\n"
	.string "“Une communauté agricole et ses\l"
	.string "petites jardins.”$"

FallarborTown_Text_1EB534: @ 81EB534
	.string "MAISON DU MAITRE DES CAPACITES\n"
	.string "“Venez apprendre de nouvelles\l"
	.string "capacités à vos POKéMON!”$"

