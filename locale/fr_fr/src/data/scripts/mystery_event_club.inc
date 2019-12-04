MysteryEventClub_EventScript_Man:: @ 8291539
	lock
	faceplayer
	goto_if_set FLAG_SYS_CHAT_USED, MysteryEventClub_EventScript_2915F5
	msgbox MysteryEventClub_Text_CollectTrainerProfiles, MSGBOX_DEFAULT
	goto MysteryEventClub_EventScript_291552
	end

MysteryEventClub_EventScript_291552:: @ 8291552
	msgbox MysteryEventClub_Text_2916FF, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, 0
	switch VAR_RESULT
	case 0, MysteryEventClub_EventScript_29159F
	case 1, MysteryEventClub_EventScript_2915EB
	case 2, MysteryEventClub_EventScript_291591
	case MULTI_B_PRESSED, MysteryEventClub_EventScript_2915EB
	end

MysteryEventClub_EventScript_291591:: @ 8291591
	msgbox MysteryEventClub_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto MysteryEventClub_EventScript_291552
	end

MysteryEventClub_EventScript_29159F:: @ 829159F
	msgbox MysteryEventClub_Text_291969, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	compare VAR_RESULT, 0
	goto_if_eq MysteryEventClub_EventScript_2915CB
	compare VAR_RESULT, 1
	goto_if_eq MysteryEventClub_EventScript_2915D5
	end

MysteryEventClub_EventScript_2915CB:: @ 82915CB
	msgbox MysteryEventClub_Text_2919DC, MSGBOX_DEFAULT
	release
	end

MysteryEventClub_EventScript_2915D5:: @ 82915D5
	setvar VAR_0x8004, 0
	special sub_811EECC
	waitmessage
	delay 80
	msgbox MysteryEventClub_Text_291B22, MSGBOX_DEFAULT
	release
	end

MysteryEventClub_EventScript_2915EB:: @ 82915EB
	msgbox MysteryEventClub_Text_291991, MSGBOX_DEFAULT
	release
	end

MysteryEventClub_EventScript_2915F5:: @ 82915F5
	msgbox MysteryEventClub_Text_YouHaveWonderfulSmile, MSGBOX_DEFAULT
	goto MysteryEventClub_EventScript_291603
	end

MysteryEventClub_EventScript_291603:: @ 8291603
	msgbox MysteryEventClub_Text_MayISeeYourNewProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, 0
	switch VAR_RESULT
	case 0, MysteryEventClub_EventScript_291650
	case 1, MysteryEventClub_EventScript_29167C
	case 2, MysteryEventClub_EventScript_291642
	case MULTI_B_PRESSED, MysteryEventClub_EventScript_29167C
	end

MysteryEventClub_EventScript_291642:: @ 8291642
	msgbox MysteryEventClub_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto MysteryEventClub_EventScript_291603
	end

MysteryEventClub_EventScript_291650:: @ 8291650
	msgbox MysteryEventClub_Text_291A6B, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	compare VAR_RESULT, 0
	goto_if_eq MysteryEventClub_EventScript_2915CB
	compare VAR_RESULT, 1
	goto_if_eq MysteryEventClub_EventScript_2915D5
	end

MysteryEventClub_EventScript_29167C:: @ 829167C
	msgbox MysteryEventClub_Text_291ABA, MSGBOX_DEFAULT
	release
	end

MysteryEventClub_EventScript_291686:: @ 8291686
	return

MysteryEventClub_Text_CollectTrainerProfiles: @ 8291687
	.string "Salut, DRESSEUR!\n"
	.string "Quel magnifique sourire tu as là!\p"
	.string "J'ai une passion. Je rassemble les\n"
	.string "profils de DRESSEURS de POKéMON.$"

MysteryEventClub_Text_2916FF: @ 82916FF
	.string "Alors, qu'en dis-tu?\n"
	.string "Je peux voir ton profil?$"

MysteryEventClub_Text_EasyChatExplanation: @ 8291729
	.string "Pour créer son propre profil,\n"
	.string "il faut associer quatre mots ou\l"
	.string "groupes de mots.\p"
	.string "Je vais donner un exemple de profil\n"
	.string "constitué de quatre segments de texte.\p"
	.string "Chacun remplace, à sa guise, ces quatre\n"
	.string "segments de texte par d'autres, de\l"
	.string "façon à dépeindre son propre profil.\p"
	.string "Les mots que l'on peut utiliser sont\n"
	.string "nombreux.\p"
	.string "Ils sont classés par catégories, telles\n"
	.string "que POKéMON, vie quotidienne, hobbies,\l"
	.string "permettant de les trouver facilement.\p"
	.string "Il faut d'abord choisir une catégorie\n"
	.string "pour afficher une liste de choix.\p"
	.string "Ensuite, il faut sélectionner son choix.\p"
	.string "Il suffit de refaire pareil pour les\n"
	.string "autres choix et le profil est déterminé.$"

MysteryEventClub_Text_291969: @ 8291969
	.string "Oui! Merci!\n"
	.string "Alors, voyons ton profil!$"

MysteryEventClub_Text_291991: @ 8291991
	.string "Oh non, vraiment?\p"
	.string "J'imagine que quelqu'un comme toi\n"
	.string "doit avoir un merveilleux profil…$"

MysteryEventClub_Text_2919DC: @ 82919DC
	.string "Oh? Tu ne veux pas le faire maintenant?\p"
	.string "Comme tu veux!$"

MysteryEventClub_Text_YouHaveWonderfulSmile: @ 8291A1B
	.string "Salut, DRESSEUR!\n"
	.string "Quel magnifique sourire tu as!$"

MysteryEventClub_Text_MayISeeYourNewProfile: @ 8291A4F
	.string "Puis-je voir ton nouveau profil?$"

MysteryEventClub_Text_291A6B: @ 8291A6B
	.string "Oui! Merci!\p"
	.string "J'espère que ce sera encore mieux que\n"
	.string "le profil que tu m'as déjà montré.$"

MysteryEventClub_Text_291ABA: @ 8291ABA
	.string "Oh, tu aimes ton profil tel qu'il est.\p"
	.string "Je ne t'en blâme pas. C'est devenu un\n"
	.string "très bon profil.$"

MysteryEventClub_Text_291B22: @ 8291B22
	.string "F… Fantastique!\p"
	.string "Ton profil est génial!\n"
	.string "Il révèle vraiment qui tu es.\p"
	.string "Tu sais, en voyant ce profil, on est\n"
	.string "forcément captivé par toi!\p"
	.string "Merci!$"

MysteryEventClub_Text_291BB7: @ 8291BB7
	.string "Oh?\n"
	.string "You know the secret saying!\p"
	.string "That means you're now a fellow member\n"
	.string "of the MYSTERY EVENT CLUB!$"
