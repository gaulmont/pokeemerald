RustboroCity_Flat1_2F_MapScripts:: @ 8215139
	.byte 0

RustboroCity_Flat1_2F_EventScript_21513A:: @ 821513A
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_Flat1_2F_EventScript_21518D
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_Flat1_2F_EventScript_2151AD

RustboroCity_Flat1_2F_EventScript_215157:: @ 8215157
	special DoWaldaNamingScreen
	waitstate
	compare VAR_0x8004, 1
	goto_if_eq RustboroCity_Flat1_2F_EventScript_2151D7
	compare VAR_0x8004, 2
	goto_if_eq RustboroCity_Flat1_2F_EventScript_2151E1
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_Flat1_2F_EventScript_2151F8
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_Flat1_2F_EventScript_215221
	end

RustboroCity_Flat1_2F_EventScript_21518D:: @ 821518D
	msgbox RustboroCity_Flat1_2F_Text_2152FA, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_Flat1_2F_EventScript_2151CD
	msgbox RustboroCity_Flat1_2F_Text_2154AD, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_215157

RustboroCity_Flat1_2F_EventScript_2151AD:: @ 82151AD
	msgbox RustboroCity_Flat1_2F_Text_215448, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_Flat1_2F_EventScript_2151CD
	msgbox RustboroCity_Flat1_2F_Text_2154AD, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_215157

RustboroCity_Flat1_2F_EventScript_2151CD:: @ 82151CD
	msgbox RustboroCity_Flat1_2F_Text_2154E7, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_2151D7:: @ 82151D7
	msgbox RustboroCity_Flat1_2F_Text_2156E3, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_2151E1:: @ 82151E1
	msgbox RustboroCity_Flat1_2F_Text_21561E, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_215238
	msgbox RustboroCity_Flat1_2F_Text_215699, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_2151F8:: @ 82151F8
	msgbox RustboroCity_Flat1_2F_Text_215535, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_215238
	msgbox RustboroCity_Flat1_2F_Text_215565, MSGBOX_DEFAULT
	applymovement 6, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_215792, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_215221:: @ 8215221
	msgbox RustboroCity_Flat1_2F_Text_2155A4, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_215238
	msgbox RustboroCity_Flat1_2F_Text_2155D4, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_215238:: @ 8215238
	turnobject 6, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_21523D:: @ 821523D
	msgbox RustboroCity_Flat1_2F_Text_21524F, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_215246:: @ 8215246
	msgbox RustboroCity_Flat1_2F_Text_215923, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_21524F: @ 821524F
	.string "Oh, c'est chaque jour si difficile…\p"
	.string "Ce qui est difficile?\n"
	.string "Tu me le demandes?\p"
	.string "Tous les jours, je dois décider ce que\n"
	.string "je vais préparer pour le repas.\p"
	.string "C'est vraiment pas facile de trouver\n"
	.string "des idées différentes chaque jour.$"

RustboroCity_Flat1_2F_Text_2152FA: @ 82152FA
	.string "Oh, bonjour!\n"
	.string "Bienvenue chez les BOFOND.\p"
	.string "J'ai une question à te poser. As-tu\n"
	.string "déjà fait du baby-sitting?\p"
	.string "Tu vois, je viens d'être papa, alors\n"
	.string "élever un enfant est quelque chose\l"
	.string "de nouveau pour moi.\p"
	.string "Et j'ai un problème, ma fille BERCIA\n"
	.string "ne rit pas beaucoup.\p"
	.string "Je pense qu'elle rirait plus si je lui\n"
	.string "disais quelque chose d'amusant.\p"
	.string "Connaîtrais-tu un mot ou une phrase\n"
	.string "amusante que je pourrais lui dire?$"

RustboroCity_Flat1_2F_Text_215448: @ 8215448
	.string "Je lui ai déjà dit “{STR_VAR_1}”\n"
	.string "pour la faire rire.\p"
	.string "Connaîtrais-tu une autre phrase ou un\n"
	.string "autre mot qui pourrait la faire rire?$"

RustboroCity_Flat1_2F_Text_2154AD: @ 82154AD
	.string "Oh, formidable!\n"
	.string "Alors donne-moi ta suggestion.$"

RustboroCity_Flat1_2F_Text_2154E7: @ 82154E7
	.string "Oh, vraiment?\p"
	.string "N'hésite pas à me le dire si tu\n"
	.string "as une suggestion.$"

RustboroCity_Flat1_2F_Text_215535: @ 8215535
	.string "Ah, je vois.\n"
	.string "Eh bien, nous n'avons plus qu'à essayer.\l"
	.string "D'accord?$"

RustboroCity_Flat1_2F_Text_215565: @ 8215565
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Oh oui! Elle rigole!\n"
	.string "Oh, je suis aussi heureux qu'elle!$"

RustboroCity_Flat1_2F_Text_2155A4: @ 82155A4
	.string "Ah, je vois.\n"
	.string "Eh bien, nous n'avons plus qu'à essayer.\l"
	.string "D'accord?$"

RustboroCity_Flat1_2F_Text_2155D4: @ 82155D4
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmmm… Ça n'a pas l'air de fonctionner.\n"
	.string "Peut-être que BERCIA est juste un\n"
	.string "bébé trop sérieux…$"

RustboroCity_Flat1_2F_Text_21561E: @ 821561E
	.string "Tu ne connais pas de bons mots alors…\n"
	.string "Je vais continuer d'essayer.\p"
	.string "Hmm…\n"
	.string "Et “{STR_VAR_1}”?\l"
	.string "Voyons si ça marche.$"

RustboroCity_Flat1_2F_Text_215699: @ 8215699
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmmm… Ça n'a pas l'air de fonctionner.\n"
	.string "Peut-être que BERCIA est juste un\n"
	.string "bébé trop sérieux…$"

RustboroCity_Flat1_2F_Text_2156E3: @ 82156E3
	.string "Tu ne connais pas de bons mots alors…\n"
	.string "Je vais essayer de l'amuser avec les\l"
	.string "mots que j'utilisais avant.\p"
	.string "Quoi qu'il en soit, n'hésite pas à me le\n"
	.string "dire si tu as une suggestion?$"

RustboroCity_Flat1_2F_Text_215792: @ 8215792
	.string "Merci!\p"
	.string "Grâce à toi, ma petite BERCIA m'a\n"
	.string "montré son sourire!\p"
	.string "Au fait, je ne te l'ai pas dit mais je\n"
	.string "suis chercheur chez DEVON.\p"
	.string "Alors que pourrais-je faire en retour\n"
	.string "pour toi?\p"
	.string "Je sais, je vais ajouter de nouveaux\n"
	.string "fonds aux BOITES de Gestion de\l"
	.string "Stocks de POKéMON sur ton PC.\p"
	.string "Dans le menu des fonds, sélectionne\n"
	.string "“AMIS”.\p"
	.string "Tu auras alors accès à un nouveau fond \n"
	.string "chaque fois que tu feras rire ma fille.$"

RustboroCity_Flat1_2F_Text_215923: @ 8215923
	.string "C'est une POUPEE POKéMON!$"

