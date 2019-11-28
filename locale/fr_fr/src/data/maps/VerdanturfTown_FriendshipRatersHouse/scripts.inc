VerdanturfTown_FriendshipRatersHouse_MapScripts:: @ 8203030
	.byte 0

VerdanturfTown_FriendshipRatersHouse_EventScript_203031:: @ 8203031
	lock
	faceplayer
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_2030ED, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case 0, VerdanturfTown_FriendshipRatersHouse_EventScript_203094
	case 1, VerdanturfTown_FriendshipRatersHouse_EventScript_20309E
	case 2, VerdanturfTown_FriendshipRatersHouse_EventScript_2030A8
	case 3, VerdanturfTown_FriendshipRatersHouse_EventScript_2030B2
	case 4, VerdanturfTown_FriendshipRatersHouse_EventScript_2030BC
	case 5, VerdanturfTown_FriendshipRatersHouse_EventScript_2030C6
	case 6, VerdanturfTown_FriendshipRatersHouse_EventScript_2030D0
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_203094:: @ 8203094
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_2032DF, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_20309E:: @ 820309E
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_203288, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_2030A8:: @ 82030A8
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_203249, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_2030B2:: @ 82030B2
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_203213, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_2030BC:: @ 82030BC
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_2031D1, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_2030C6:: @ 82030C6
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_203192, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_2030D0:: @ 82030D0
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_203141, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_2030DA:: @ 82030DA
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, 0
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_20334A, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VerdanturfTown_FriendshipRatersHouse_Text_2030ED: @ 82030ED
	.string "Laisse-moi voir ton POKéMON.\n"
	.string "Je vais regarder s'il t'aime bien.\p"
	.string "Oh.\n"
	.string "Ton POKéMON…$"

VerdanturfTown_FriendshipRatersHouse_Text_203141: @ 8203141
	.string "Il t'adore.\n"
	.string "Il ne pourrait pas t'aimer plus.\l"
	.string "Ça fait plaisir à voir.$"

VerdanturfTown_FriendshipRatersHouse_Text_203192: @ 8203192
	.string "Il semble très heureux.\n"
	.string "A l'évidence, il t'aime de tout son cœur.$"

VerdanturfTown_FriendshipRatersHouse_Text_2031D1: @ 82031D1
	.string "Il t'aime beaucoup.\n"
	.string "Il semble vouloir être dorloté.$"

VerdanturfTown_FriendshipRatersHouse_Text_203213: @ 8203213
	.string "Il commence à s'habituer à toi.\n"
	.string "Il a l'air de croire en toi.$"

VerdanturfTown_FriendshipRatersHouse_Text_203249: @ 8203249
	.string "Il n'est pas encore très habitué à toi.\n"
	.string "Il ne t'aime pas, mais ne te déteste pas\l"
	.string "non plus.$"

VerdanturfTown_FriendshipRatersHouse_Text_203288: @ 8203288
	.string "Il est sur ses gardes.\n"
	.string "Il pourrait être agressif.\l"
	.string "Il ne t'aime pas du tout.$"

VerdanturfTown_FriendshipRatersHouse_Text_2032DF: @ 82032DF
	.string "C'est un peu difficile à annoncer…\p"
	.string "Ton POKéMON te déteste franchement.\n"
	.string "Ça ne te met pas un peu mal à l'aise?$"

VerdanturfTown_FriendshipRatersHouse_Text_20334A: @ 820334A
	.string "PIKACHU: Pika pika!$"

