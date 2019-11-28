PacifidlogTown_House4_MapScripts:: @ 8203F4B
	.byte 0

PacifidlogTown_House4_EventScript_203F4C:: @ 8203F4C
	msgbox PacifidlogTown_House4_Text_204017, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_203F55:: @ 8203F55
	msgbox PacifidlogTown_House4_Text_203F93, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_203F5E:: @ 8203F5E
	lock
	faceplayer
	msgbox PacifidlogTown_House4_Text_204035, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PacifidlogTown_House4_EventScript_203F7F
	compare VAR_RESULT, 0
	goto_if_eq PacifidlogTown_House4_EventScript_203F89
	end

PacifidlogTown_House4_EventScript_203F7F:: @ 8203F7F
	msgbox PacifidlogTown_House4_Text_20404E, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_EventScript_203F89:: @ 8203F89
	msgbox PacifidlogTown_House4_Text_204084, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_Text_203F93: @ 8203F93
	.string "Les gens racontent qu'ils ont vu un\n"
	.string "POKéMON VOLANT au-dessus de\l"
	.string "la région de HOENN.\p"
	.string "Est-ce qu'il vole tout le temps?\n"
	.string "Il doit bien se reposer, non?$"

PacifidlogTown_House4_Text_204017: @ 8204017
	.string "Un POKéMON ciel!\n"
	.string "Un POKéMON ciel!$"

PacifidlogTown_House4_Text_204035: @ 8204035
	.string "D'où viens-tu?$"

PacifidlogTown_House4_Text_20404E: @ 820404E
	.string "Oui?\n"
	.string "OUI VILLE?\p"
	.string "Je n'ai jamais entendu parler de\n"
	.string "cet endroit.$"

PacifidlogTown_House4_Text_204084: @ 8204084
	.string "Non? Mais c'est n'importe quoi.\n"
	.string "Tu dois bien venir de quelque part.\p"
	.string "Oh! Attends! Tu ne vas pas me dire que\n"
	.string "tu viens du fond de l'océan?$"

