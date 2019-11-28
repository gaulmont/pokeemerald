SlateportCity_OceanicMuseum_1F_MapScripts:: @ 820AD95
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_20AD96:: @ 820AD96
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B026, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AD9F:: @ 820AD9F
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_20ADC1
	end

SlateportCity_OceanicMuseum_1F_EventScript_20ADB0:: @ 820ADB0
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_20ADC1
	end

SlateportCity_OceanicMuseum_1F_EventScript_20ADC1:: @ 820ADC1
	showmoneybox 0, 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_20AFD5, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_20ADE8
	closemessage
	hidemoneybox
	nop
	nop
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_20AE4B
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_20ADE8:: @ 820ADE8
	checkmoney 50, 0
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_20AE18
	playse SE_REGI
	takemoney 50, 0
	updatemoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B026, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	nop
	nop
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AE18:: @ 820AE18
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_20AE39
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B03D, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	nop
	nop
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_20AE4B
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AE39:: @ 820AE39
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B075, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	nop
	nop
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_20AE4B: @ 820AE4B
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_20AE4D:: @ 820AE4D
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B0E8, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AE56:: @ 820AE56
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B112, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AE5F:: @ 820AE5F
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B165, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AE68:: @ 820AE68
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B19C, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AE71:: @ 820AE71
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B1D4, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AE7A:: @ 820AE7A
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B218, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AE83:: @ 820AE83
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B4CF, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AE8C:: @ 820AE8C
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B547, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AE95:: @ 820AE95
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B5CA, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AE9E:: @ 820AE9E
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B699, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AEA7:: @ 820AEA7
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B74B, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AEB0:: @ 820AEB0
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B81F, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AEB9:: @ 820AEB9
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B912, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AEC2:: @ 820AEC2
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B9C0, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AECB:: @ 820AECB
	msgbox SlateportCity_OceanicMuseum_1F_Text_20BA9C, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AED4:: @ 820AED4
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B25F, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AEDD:: @ 820AEDD
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B2A2, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AEE6:: @ 820AEE6
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B302, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AEEF:: @ 820AEEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B369, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AEF8:: @ 820AEF8
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applymovement 13, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 13, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B3AB, MSGBOX_DEFAULT
	giveitem_std ITEM_TM46
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_20AFB5
	setflag FLAG_RECEIVED_TM46
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B449, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, DIR_NORTH
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_20AF6C
	compare VAR_FACING, DIR_SOUTH
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_20AF83
	compare VAR_FACING, DIR_WEST
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_20AF93
	compare VAR_FACING, DIR_EAST
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_20AF93
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AF6C:: @ 820AF6C
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_20AFBF
	applymovement 13, SlateportCity_OceanicMuseum_1F_Movement_20AFCE
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_20AFAA
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AF83:: @ 820AF83
	applymovement 13, SlateportCity_OceanicMuseum_1F_Movement_20AFC7
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_20AFAA
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AF93:: @ 820AF93
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_20AFC4
	applymovement 13, SlateportCity_OceanicMuseum_1F_Movement_20AFC7
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_20AFAA
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AFAA:: @ 820AFAA
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_KAIDAN
	removeobject 13
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AFB5:: @ 820AFB5
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B49B, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_20AFBF: @ 820AFBF
	delay_16
	delay_8
	delay_4
	walk_in_place_fastest_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_20AFC4: @ 820AFC4
	delay_16
	walk_in_place_fastest_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_20AFC7: @ 820AFC7
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_20AFCE: @ 820AFCE
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_20AFD5: @ 820AFD5
	.string "Bienvenue au MUSEE OCEANOGRAPHIQUE.\p"
	.string "L'entrée coûte 50$.\n"
	.string "Voulez-vous entrer?$"

SlateportCity_OceanicMuseum_1F_Text_20B026: @ 820B026
	.string "Bonne visite!$"

SlateportCity_OceanicMuseum_1F_Text_20B03D: @ 820B03D
	.string "Oh, désolée, mais vous ne semblez pas\n"
	.string "avoir suffisamment d'argent.$"

SlateportCity_OceanicMuseum_1F_Text_20B075: @ 820B075
	.string "Oh, vous faites partie du groupe qui\n"
	.string "est entré tout à l'heure?\p"
	.string "Ils doivent déjà être loin.\n"
	.string "Vous feriez bien de les rattraper!$"

SlateportCity_OceanicMuseum_1F_Text_20B0E8: @ 820B0E8
	.string "Nous, la TEAM AQUA, nous existons\n"
	.string "pour le bien de tous!$"

SlateportCity_OceanicMuseum_1F_Text_20B112: @ 820B112
	.string "On nous a dit de nous regrouper ici,\n"
	.string "alors on l'a fait, mais…\p"
	.string "Notre CHEF, le pivot du groupe,\n"
	.string "n'est pas là.$"

SlateportCity_OceanicMuseum_1F_Text_20B165: @ 820B165
	.string "Si je piquais tout ce qu'il y a ici,\n"
	.string "est-ce que ça me rendrait riche?$"

SlateportCity_OceanicMuseum_1F_Text_20B19C: @ 820B19C
	.string "Ce que j'apprends ici, je peux m'en\n"
	.string "servir pour agir de façon infâme…$"

SlateportCity_OceanicMuseum_1F_Text_20B1D4: @ 820B1D4
	.string "Ce que j'apprends ici, je peux m'en\n"
	.string "à MEROUVILLE, on n'en serait pas là.$"

SlateportCity_OceanicMuseum_1F_Text_20B218: @ 820B218
	.string "Je n'avais pas les 50$, alors j'ai dû\n"
	.string "parlementer avec la réceptionniste.$"

SlateportCity_OceanicMuseum_1F_Text_20B25F: @ 820B25F
	.string "Je veux tirer des enseignements de la\n"
	.string "mer et m'en servir pour combattre.$"

SlateportCity_OceanicMuseum_1F_Text_20B2A2: @ 820B2A2
	.string "Je suis tout excité quand je vois\n"
	.string "la mer!\p"
	.string "Le CAPT. POUPE est un exemple pour moi!$"

SlateportCity_OceanicMuseum_1F_Text_20B302: @ 820B302
	.string "La mer est sans limite et d'une\n"
	.string "infinie profondeur…\p"
	.string "Il doit y avoir de nombreux POKéMON\n"
	.string "dont on ignore tout.$"

SlateportCity_OceanicMuseum_1F_Text_20B369: @ 820B369
	.string "Je veux un POKéMON de la mer.\p"
	.string "Je crois que ce serait sympa de le tenir\n"
	.string "contre moi.$"

SlateportCity_OceanicMuseum_1F_Text_20B3AB: @ 820B3AB
	.string "Héééé!\n"
	.string "Qu'est-ce que tu fais là?\p"
	.string "Moi? Je suis le membre de la TEAM AQUA\n"
	.string "que tu as déjà affronté. Tu t'souviens?\l"
	.string "C'était dans le TUNNEL MERAZON!\p"
	.string "Tiens, prends ça!\n"
	.string "Et pardonne-moi!$"

SlateportCity_OceanicMuseum_1F_Text_20B449: @ 820B449
	.string "Cette CT te sera plus utile qu'à moi.\p"
	.string "J'espère ne jamais te revoir!\n"
	.string "Ouahahaha!$"

SlateportCity_OceanicMuseum_1F_Text_20B49B: @ 820B49B
	.string "Allez, viens!\n"
	.string "Prends ça et laisse-moi partir!$"

SlateportCity_OceanicMuseum_1F_Text_20B4CF: @ 820B4CF
	.string "Un liquide bleu forme une spirale à\n"
	.string "l'intérieur d'un récipient en verre.\p"
	.string "“C'est un tourbillon reproduit\n"
	.string "artificiellement avec du vent.”$"

SlateportCity_OceanicMuseum_1F_Text_20B547: @ 820B547
	.string "Une balle rouge monte et descend à\n"
	.string "l'intérieur d'un récipient en verre.\p"
	.string "“C'est une expérience simulant\n"
	.string "une CASCADE avec la flottabilité\l"
	.string "de la balle.”$"

SlateportCity_OceanicMuseum_1F_Text_20B5CA: @ 820B5CA
	.string "C'est un échantillon provenant du fond\n"
	.string "de l'océan.\p"
	.string "“Les débris de toutes formes de vie\n"
	.string "se sont au fur et à mesure amassés au\l"
	.string "fond de la mer, formant des couches\l"
	.string "sédimentaires.”\p"
	.string "“L'analyse de ces sédiments\n"
	.string "révèle le temps passé.”$"

SlateportCity_OceanicMuseum_1F_Text_20B699: @ 820B699
	.string "C'est un échantillon de sable de plage.\p"
	.string "“Les roches des montagnes sont\n"
	.string "détrempées par les rivières, ce qui les\l"
	.string "rend friables et les décompose.”\p"
	.string "“Elles sont réduites en poussière\n"
	.string "et deviennent le sable des plages.”$"

SlateportCity_OceanicMuseum_1F_Text_20B74B: @ 820B74B
	.string "“DEVINETTE SUR LA MER 1\n"
	.string "Pourquoi l'eau de mer est-elle bleue?\p"
	.string "“Les rayons de lumière sont composés\n"
	.string "de nombreuses couleurs.\p"
	.string "“La plupart d'entre eux perdent leur\n"
	.string "couleur lorsqu'ils traversent l'eau.\p"
	.string "“Mais les rayons bleus, eux, sont\n"
	.string "réfléchis, rendant la mer bleue.”$"

SlateportCity_OceanicMuseum_1F_Text_20B81F: @ 820B81F
	.string "“DEVINETTE SUR LA MER 2\n"
	.string "Pourquoi l'eau de mer est-elle salée?\p"
	.string "“L'eau de mer contient du sel dissous\n"
	.string "sous forme d'ions sodium et chlorure.\p"
	.string "“Ces ions proviennent des roches\n"
	.string "et la pluie les transporte dans la mer.\p"
	.string "“La concentration en sel dissous\n"
	.string "rend la mer salée.”$"

SlateportCity_OceanicMuseum_1F_Text_20B912: @ 820B912
	.string "“DEVINETTE SUR LA MER 3\n"
	.string "Quelle est la plus vaste? La mer\l"
	.string "ou la terre?\p"
	.string "“La mer couvre environ 70% de la\n"
	.string "planète et la terre, le reste.\p"
	.string "“La mer est donc au moins deux fois\n"
	.string "plus vaste que la terre.”$"

SlateportCity_OceanicMuseum_1F_Text_20B9C0: @ 820B9C0
	.string "C'est un fossile à stries ondulées.\p"
	.string "“Le fond de l'océan est drainé\n"
	.string "par la marée.”\p"
	.string "“Le mouvement de l'eau de mer dessine\n"
	.string "des stries et des creux sur le sol.”\p"
	.string "“Si ce sol se fossilise, on parle\n"
	.string "d'ondulation.”$"

SlateportCity_OceanicMuseum_1F_Text_20BA9C: @ 820BA9C
	.string "Un engin étrange pivote sous un\n"
	.string "dôme en verre.\p"
	.string "Peut-être est-ce pour mesurer la\n"
	.string "profondeur de quelque chose…$"
