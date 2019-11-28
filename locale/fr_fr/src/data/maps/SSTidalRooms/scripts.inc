SSTidalRooms_MapScripts:: @ 823C9F1
	.byte 0

SSTidalRooms_EventScript_23C9F2:: @ 823C9F2
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM49, SSTidalRooms_EventScript_23CA29
	msgbox SSTidalRooms_Text_23D098, MSGBOX_DEFAULT
	giveitem_std ITEM_TM49
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM49
	msgbox SSTidalRooms_Text_23D145, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_23CA29:: @ 823CA29
	msgbox SSTidalRooms_Text_23D145, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_23CA33:: @ 823CA33
	lockall
	msgbox SSTidalRooms_Text_23CAF2, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_23C0A7
	releaseall
	end

SSTidalRooms_EventScript_23CA49:: @ 823CA49
	trainerbattle_single TRAINER_COLTON, SSTidalRooms_Text_23CB14, SSTidalRooms_Text_23CB58
	msgbox SSTidalRooms_Text_23CB75, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_23CA60:: @ 823CA60
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_23CBEB, SSTidalRooms_Text_23CC04
	msgbox SSTidalRooms_Text_23CC26, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_23CA77:: @ 823CA77
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_23CC68, SSTidalRooms_Text_23CC8A
	msgbox SSTidalRooms_Text_23CCBB, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_23CA8E:: @ 823CA8E
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_23CD04, SSTidalRooms_Text_23CD54, SSTidalRooms_Text_23CDC6
	msgbox SSTidalRooms_Text_23CD5F, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_23CAA9:: @ 823CAA9
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_23CE04, SSTidalRooms_Text_23CE4B, SSTidalRooms_Text_23CEB0
	msgbox SSTidalRooms_Text_23CE59, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_23CAC4:: @ 823CAC4
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_23CEEE, SSTidalRooms_Text_23CF36
	msgbox SSTidalRooms_Text_23CF45, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_23CADB:: @ 823CADB
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_23CF97, SSTidalRooms_Text_23CFF4
	msgbox SSTidalRooms_Text_23D013, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_Text_23CAF2: @ 823CAF2
	.string "Ah, un lit!\n"
	.string "Je vais me reposer.$"

SSTidalRooms_Text_23CB14: @ 823CB14
	.string "Je vais souvent à NENUCRIQUE.\p"
	.string "C'est parce que j'aime faire des\n"
	.string "CONCOURS POKéMON, tu vois.$"

SSTidalRooms_Text_23CB58: @ 823CB58
	.string "C'était un match très intéressant!$"

SSTidalRooms_Text_23CB75: @ 823CB75
	.string "Je suis tout nerveux à l'idée de\n"
	.string "découvrir de nouveaux POKéMON pendant\l"
	.string "les CONCOURS. J'ai hâte d'y être!$"

SSTidalRooms_Text_23CBEB: @ 823CBEB
	.string "Tes amis sont-ils puissants?$"

SSTidalRooms_Text_23CC04: @ 823CC04
	.string "Ah oui, tes amis sont puissants!$"

SSTidalRooms_Text_23CC26: @ 823CC26
	.string "Les amis ne sont pas forcément humains.\n"
	.string "Mes POKéMON sont mes meilleurs amis!$"

SSTidalRooms_Text_23CC68: @ 823CC68
	.string "Dis-moi…\n"
	.string "Tu as frappé avant d'entrer?$"

SSTidalRooms_Text_23CC8A: @ 823CC8A
	.string "On doit accepter la défaite calmement,\n"
	.string "sans paniquer.$"

SSTidalRooms_Text_23CCBB: @ 823CCBB
	.string "Un véritable GENTLEMAN ne doit jamais\n"
	.string "s'énerver, quelle que soit la situation.$"

SSTidalRooms_Text_23CD04: @ 823CD04
	.string "ALI: Ça me gêne un peu, mais… On va\n"
	.string "te montrer le pouvoir de notre amour!$"

SSTidalRooms_Text_23CD54: @ 823CD54
	.string "ALI: Soupir…$"

SSTidalRooms_Text_23CD5F: @ 823CD5F
	.string "ALI: C'est la première fois que le\n"
	.string "pouvoir de notre amour n'est pas le\l"
	.string "plus fort! Tu es un DRESSEUR puissant!$"

SSTidalRooms_Text_23CDC6: @ 823CDC6
	.string "ALI: Tu n'as qu'un POKéMON?\n"
	.string "La solitude ne te pèse pas trop?$"

SSTidalRooms_Text_23CE04: @ 823CE04
	.string "LISE: C'est un peu naïf, mais… On va\n"
	.string "te montrer le pouvoir de notre amour!$"

SSTidalRooms_Text_23CE4B: @ 823CE4B
	.string "LISE: Ouin-ouin!$"

SSTidalRooms_Text_23CE59: @ 823CE59
	.string "LISE: Je n'y crois pas! Le pouvoir de\n"
	.string "notre amour n'a pas été le plus fort…\l"
	.string "plus fort! Tu es un DRESSEUR puissant!$"

SSTidalRooms_Text_23CEB0: @ 823CEB0
	.string "LISE: Je voulais me battre…\n"
	.string "Mais tu n'as même pas deux POKéMON…$"

SSTidalRooms_Text_23CEEE: @ 823CEEE
	.string "Ah, tu arrives à temps.\p"
	.string "Je m'ennuie terriblement, tu sais.\n"
	.string "Tu vas me divertir.$"

SSTidalRooms_Text_23CF36: @ 823CF36
	.string "Pfff… Tu m'as bien diverti.$"

SSTidalRooms_Text_23CF45: @ 823CF45
	.string "Je devrais peut-être demander à mon\n"
	.string "père de m'acheter un yacht.\l"
	.string "Un yacht rien que pour mes POKéMON\n"
	.string "et moi!$"

SSTidalRooms_Text_23CF97: @ 823CF97
	.string "Oh, quel DRESSEUR adorable tu es.\n"
	.string "Veux-tu prendre un thé?\l"
	.string "Ou préfères-tu te battre?$"

SSTidalRooms_Text_23CFF4: @ 823CFF4
	.string "Je vois.\n"
	.string "Tu es du genre entreprenant.$"

SSTidalRooms_Text_23D013: @ 823D013
	.string "Une croisière autour du monde dans un\n"
	.string "yacht de luxe n'est pas sans charme…\p"
	.string "Mais je dois bien avouer que voyager\n"
	.string "dans un ferry est plutôt plaisant.$"

SSTidalRooms_Text_23D098: @ 823D098
	.string "Heu… Salut! Je… Non, je n'ai pas l'air\n"
	.string "suspect! Heu… Tu veux ça? C'est gratuit!\p"
	.string "C'est… Honestly, I didn't SNATCH it from\n"
	.string "someone! Je le jure, je ne l'ai pas volé!\l"
	.string "Je n'oserais jamais voler! SAISIE?\p"
	.string "Ne crains rien! Tu peux t'en servir!$"

SSTidalRooms_Text_23D145: @ 823D145
	.string "SAISIE permet de voler l'attaque\n"
	.string "ennemie et d'en obtenir les effets.$"

