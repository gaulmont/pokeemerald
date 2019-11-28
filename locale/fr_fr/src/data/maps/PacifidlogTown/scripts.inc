PacifidlogTown_MapScripts:: @ 81EBAB1
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_MapScript1_1EBAC0
	.byte 0

PacifidlogTown_OnTransition: @ 81EBABC
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_MapScript1_1EBAC0: @ 81EBAC0
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_1EBAC3:: @ 81EBAC3
	msgbox PacifidlogTown_Text_1EBB6C, MSGBOX_NPC
	end

PacifidlogTown_EventScript_1EBACC:: @ 81EBACC
	msgbox PacifidlogTown_Text_1EBAE7, MSGBOX_NPC
	end

PacifidlogTown_EventScript_1EBAD5:: @ 81EBAD5
	msgbox PacifidlogTown_Text_1EBBAC, MSGBOX_NPC
	end

PacifidlogTown_EventScript_1EBADE:: @ 81EBADE
	msgbox PacifidlogTown_Text_1EBC7A, MSGBOX_SIGN
	end

PacifidlogTown_Text_1EBAE7: @ 81EBAE7
	.string "Le courant de la mer entre PACIFIVILLE\n"
	.string "et POIVRESSEL est très fort.\p"
	.string "Si tu décidais de faire du SURF,\n"
	.string "tu pourrais te faire emporter et\l"
	.string "te retrouver très loin d'ici.$"

PacifidlogTown_Text_1EBB6C: @ 81EBB6C
	.string "Regarde comme c'est chouette!\n"
	.string "Ces maisons sont construites sur l'eau.\p"
	.string "Je suis né ici!$"

PacifidlogTown_Text_1EBBAC: @ 81EBBAC
	.string "LE PILIER CELESTE?\p"
	.string "Oh, tu veux sûrement parler de cette\n"
	.string "très très grande tour un peu plus loin.\p"
	.string "Si tu veux mon avis, il faut être fou\n"
	.string "pour vouloir monter si haut!\p"
	.string "Vivre au niveau de la mer, ici à\n"
	.string "PACIFIVILLE, voilà ce qui me va!$"

PacifidlogTown_Text_1EBC7A: @ 81EBC7A
	.string "PACIFIVILLE\p"
	.string "“Là où le soleil du matin se reflète\n"
	.string "sur les eaux.”$"

