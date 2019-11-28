VerdanturfTown_MapScripts:: @ 81EB566
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition: @ 81EB56C
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_LINK_CONTEST_ROOM_STATE, 0
	end

VerdanturfTown_EventScript_1EB575:: @ 81EB575
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_1EB594
	msgbox VerdanturfTown_Text_1EB5FD, MSGBOX_DEFAULT
	applymovement 2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_1EB594:: @ 81EB594
	msgbox VerdanturfTown_Text_1EB6E0, MSGBOX_DEFAULT
	applymovement 2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_1EB5A8:: @ 81EB5A8
	msgbox VerdanturfTown_Text_1EB736, MSGBOX_NPC
	end

VerdanturfTown_EventScript_1EB5B1:: @ 81EB5B1
	msgbox VerdanturfTown_Text_1EB7E2, MSGBOX_NPC
	end

VerdanturfTown_EventScript_1EB5BA:: @ 81EB5BA
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_1EB5CF
	msgbox VerdanturfTown_Text_1EB854, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_1EB5CF:: @ 81EB5CF
	msgbox VerdanturfTown_Text_1EB935, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_1EB5D9:: @ 81EB5D9
	msgbox VerdanturfTown_Text_1EB9C4, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_1EB5E2:: @ 81EB5E2
	msgbox VerdanturfTown_Text_1EBA11, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_1EB5EB:: @ 81EB5EB
	msgbox VerdanturfTown_Text_1EBA1F, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_1EB5F4:: @ 81EB5F4
	msgbox VerdanturfTown_Text_1EBA59, MSGBOX_SIGN
	end

VerdanturfTown_Text_1EB5FD: @ 81EB5FD
	.string "Mon papa m'a tout raconté.\p"
	.string "Il dit que ce tunnel est rempli de\n"
	.string "POKéMON craintifs.\p"
	.string "Ils ont tous peur du bruit et font\n"
	.string "beaucoup de brouhaha.\p"
	.string "Alors ils ont été obligés d'arrêter le\n"
	.string "projet du tunnel.\p"
	.string "Mais il y a encore un homme. Il essaie de\n"
	.string "creuser le tunnel tout seul!$"

VerdanturfTown_Text_1EB6E0: @ 81EB6E0
	.string "Il y a un type qui a creusé un\n"
	.string "tunnel pour la fille qu'il aime.\p"
	.string "Moi, je n'le ferais pas, mais bon,\n"
	.string "après tout…$"

VerdanturfTown_Text_1EB736: @ 81EB736
	.string "Le vent n'amène jamais les cendres\n"
	.string "volcaniques par là.\p"
	.string "L'air est sain et délicieux ici.\n"
	.string "Vivre ici est très bénéfique, surtout\l"
	.string "pour les personnes chétives et malades.$"

VerdanturfTown_Text_1EB7E2: @ 81EB7E2
	.string "Mes POKéMON et moi venons de réussir\n"
	.string "une grande série de victoires\l"
	.string "consécutives.\p"
	.string "Alors j'ai décidé de nous essayer à la\n"
	.string "TENTE DE COMBAT de cette ville.$"

VerdanturfTown_Text_1EB854: @ 81EB854
	.string "As-tu vu la caverne près de la\n"
	.string "BOUTIQUE POKéMON?\p"
	.string "Il y a un type là-bas qui essaie de\n"
	.string "casser des rochers pour pouvoir passer\l"
	.string "et se rendre de ce côté.\p"
	.string "Ce serait super de pouvoir passer…\n"
	.string "Ça serait facile d'aller à MEROUVILLE.$"

VerdanturfTown_Text_1EB935: @ 81EB935
	.string "Tu sais, cette caverne près de la\n"
	.string "BOUTIQUE POKéMON, elle relie\l"
	.string "désormais les deux côtés.\p"
	.string "C'est super! Plus de problème pour faire\n"
	.string "des courses chez DEVON à MEROUVILLE.$"

VerdanturfTown_Text_1EB9C4: @ 81EB9C4
	.string "VERGAZON\p"
	.string "“Les montagnes où le vent souffle et\n"
	.string "où le doux parfum de l'herbe se dégage.”$"

VerdanturfTown_Text_1EBA11: @ 81EBA11
	.string "MAISON DE SYLVIE$"

VerdanturfTown_Text_1EBA1F: @ 81EBA1F
	.string "TENTE DE COMBAT de VERGAZON\n"
	.string "“Venez admirer nos combats!”$"

VerdanturfTown_Text_1EBA59: @ 81EBA59
	.string "TUNNEL MERAZON\n"
	.string "“Passage entre MEROUVILLE\l"
	.string "et VERGAZON”.\p"
	.string "“Le projet de création du tunnel\n"
	.string "a été annulé.”$"

