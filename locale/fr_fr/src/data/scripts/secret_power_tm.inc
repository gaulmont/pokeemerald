Route111_Text_2762C9: @ 82762C9
	.string "Qu'est-ce que c'est?\n"
	.string "Qu'est-ce que je fais?\p"
	.string "Je vais me créer ma propre pièce ici, en\n"
	.string "utilisant la capacité d'un POKéMON.\p"
	.string "Je sais! Je vais te donner cette CT.\n"
	.string "Tu vas l'utiliser pour avoir ta pièce?$"

Route111_Text_27636E: @ 827636E
	.string "Trouve un grand arbre qui pourrait\n"
	.string "avoir des lianes.\p"
	.string "Utilise FORCE CACHEE devant l'arbre.\n"
	.string "Des lianes peuvent en tomber\l"
	.string "et te permettre de monter.\p"
	.string "Tu trouveras toute la place qu'il te\n"
	.string "faut pour y mettre tes objets préférés.\p"
	.string "Ce sera ta pièce secrète…\n"
	.string "Ta BASE SECRETE!\p"
	.string "Tu devrais t'en créer une!\p"
	.string "Autre chose: une BASE SECRETE ne se\n"
	.string "construit pas toujours dans un arbre.\p"
	.string "Essaie d'utiliser FORCE CACHEE sur\n"
	.string "des façades rocheuses fissurées.\p"
	.string "Je vais aussi chercher d'autres lieux.\n"
	.string "Salut!$"

Route111_Text_27655C: @ 827655C
	.string "Oh, tu n'en veux pas? Si tu changes\n"
	.string "d'avis, fais-moi signe, OK?$"

Route111_Text_27659D: @ 827659D
	.string "Oh, tu n'as pas de place pour ça.\p"
	.string "Bon, je vais la garder et tu pourras la\n"
	.string "prendre une autre fois, d'accord?$"

Route111_EventScript_2765FF:: @ 82765FF
	lock
	faceplayer
	msgbox Route111_Text_2762C9, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route111_EventScript_27661E
	msgbox Route111_Text_27655C, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_27661E:: @ 827661E
	giveitem_std ITEM_TM43
	compare VAR_RESULT, 0
	goto_if_eq Route111_EventScript_276680
	msgbox Route111_Text_27636E, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	clearflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
	compare VAR_FACING, DIR_WEST
	call_if_eq Route111_EventScript_27666A
	compare VAR_FACING, DIR_EAST
	call_if_eq Route111_EventScript_27666A
	compare VAR_FACING, DIR_NORTH
	call_if_eq Route111_EventScript_276675
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_27666A:: @ 827666A
	applymovement VAR_LAST_TALKED, Route111_Movement_27668A
	waitmovement 0
	return

Route111_EventScript_276675:: @ 8276675
	applymovement VAR_LAST_TALKED, Route111_Movement_276696
	waitmovement 0
	return

Route111_EventScript_276680:: @ 8276680
	msgbox Route111_Text_27659D, MSGBOX_DEFAULT
	release
	end

Route111_Movement_27668A: @ 827668A
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Movement_276696: @ 8276696
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end
