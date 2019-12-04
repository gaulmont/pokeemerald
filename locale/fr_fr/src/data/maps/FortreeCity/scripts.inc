FortreeCity_MapScripts:: @ 81E25A4
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_MapScript1_1E25B3
	.byte 0

FortreeCity_OnTransition: @ 81E25AF
	setflag FLAG_VISITED_FORTREE_CITY
	end

FortreeCity_MapScript1_1E25B3: @ 81E25B3
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_1E25B6:: @ 81E25B6
	msgbox FortreeCity_Text_1E2676, MSGBOX_NPC
	end

FortreeCity_EventScript_1E25BF:: @ 81E25BF
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_1E25D4
	msgbox FortreeCity_Text_1E2738, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_1E25D4:: @ 81E25D4
	msgbox FortreeCity_Text_1E27B6, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_1E25DE:: @ 81E25DE
	msgbox FortreeCity_Text_1E27FE, MSGBOX_NPC
	end

FortreeCity_EventScript_1E25E7:: @ 81E25E7
	msgbox FortreeCity_Text_1E2880, MSGBOX_NPC
	end

FortreeCity_EventScript_1E25F0:: @ 81E25F0
	msgbox FortreeCity_Text_1E292E, MSGBOX_NPC
	end

FortreeCity_EventScript_1E25F9:: @ 81E25F9
	msgbox FortreeCity_Text_1E299D, MSGBOX_NPC
	end

FortreeCity_EventScript_1E2602:: @ 81E2602
	msgbox FortreeCity_Text_1E2AAC, MSGBOX_SIGN
	end

FortreeCity_EventScript_1E260B:: @ 81E260B
	msgbox FortreeCity_Text_1E2AE6, MSGBOX_SIGN
	end

FortreeCity_EventScript_1E2614:: @ 81E2614
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE, 1
	compare VAR_RESULT, 1
	goto_if_eq FortreeCity_EventScript_1E2630
	msgbox FortreeCity_Text_1E29E5, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_1E2630:: @ 81E2630
	msgbox FortreeCity_Text_1E2A08, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq FortreeCity_EventScript_1E2645
	release
	end

FortreeCity_EventScript_1E2645:: @ 81E2645
	msgbox FortreeCity_Text_1E2A48, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, 2
	delay 40
	waitmoncry
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_1E2674
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_1E2674: @ 81E2674
	walk_right
	step_end

FortreeCity_Text_1E2676: @ 81E2676
	.string "Personne ne me croit, mais j'ai\n"
	.string "vraiment vu ce POKéMON gigantesque\ldans le ciel.\p"
	.string "J'ai eu l'impression qu'il volait vers\n"
	.string "le CHENAL 131.\p"
	.string "Snifff… \n"
	.string "Hum… Tu, euh…sens le brûlé.\p"
	.string "Tu étais sur un volcan ou quelque chose\lcomme ça?$"

FortreeCity_Text_1E2738: @ 81E2738
	.string "Je veux aller à l'ARENE POKéMON, mais\n"
	.string "quelque chose bloque le passage.\p"
	.string "Après tout le mal que je me suis donné\n"
	.string "poru venir m'entraîner sur la ROUTE 120…$"

FortreeCity_Text_1E27B6: @ 81E27B6
	.string "J'ai des POKéMON qui font ma joie et ma\n"
	.string "fierté. Cette fois, je battrai ALIZEE.$"

FortreeCity_Text_1E27FE: @ 81E27FE
	.string "Le sol absorbe l'eau de pluie et les\n"
	.string "arbres poussent en puisant cette eau…\p"
	.string "Notre CIMETRONELLE existe grâce\n"
	.string "à l'eau et à la terre.$"

FortreeCity_Text_1E2880: @ 81E2880
	.string "C'est une VILLE formée de maisons\n"
	.string "construites dans les arbres.\p"
	.string "Ici, on est tous en forme et dynamiques.\n"
	.string "Probablement grâce à ce mode de vie!\p"
	.string "Même moi, j'ai l'impression d'avoir\n"
	.string "rajeuni de trente ans.$"

FortreeCity_Text_1E292E: @ 81E292E
	.string "C'est bien de vivre en haut des arbres.\p"
	.string "Mais parfois, des POKéMON du type\n"
	.string "INSECTE passent pas les fenêtres.\l"
	.string "Ça peut faire très peur.$"

FortreeCity_Text_1E299D: @ 81E299D
	.string "Certains POKéMON évoluent quand ils\n"
	.string "sont échangés! C'est ce qu'on raconte!$"

FortreeCity_Text_1E29E5: @ 81E29E5
	.string "Quelque chose d'invisiblebloque la\n"
	.string "voie.$"

FortreeCity_Text_1E2A08: @ 81E2A08
	.string "Quelque chose d'invisiblebloque la\n"
	.string "voie.\p"
	.string "Voulez-vous utiliser le DEVON SCOPE?$"

FortreeCity_Text_1E2A48: @ 81E2A48
	.string "{PLAYER} utilise le DEVON SCOPE.\p"
	.string "Un POKéMONinvisible devient tout à coup\n"
	.string "visible!\p"
	.string "Le POKéMON effrayé, s'enfuit!$"

FortreeCity_Text_1E2AAC: @ 81E2AAC
	.string "CIMETRONELLE\n"
	.string "“là où les cimes des arbres sont\l"
	.string "en harmonie avec la nature.”$"

FortreeCity_Text_1E2AE6: @ 81E2AE6
	.string "ARENE POKéMON de CIMETRONELLE\n"
	.string "CHAMPION: ALIZEE\p"
	.string "“Celle qui utilise les oiseaux et prend\n"
	.string "son envol dans le monde.”$"
