BattleFrontier_Lounge2_MapScripts:: @ 8260642
	.byte 0

BattleFrontier_Lounge2_EventScript_260643:: @ 8260643
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_26065F
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_260766, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_26066D
	end

BattleFrontier_Lounge2_EventScript_26065F:: @ 826065F
	msgbox BattleFrontier_Lounge2_Text_260857, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_26066D
	end

BattleFrontier_Lounge2_EventScript_26066D:: @ 826066D
	compare VAR_FRONTIER_MANIAC_FACILITY, 0
	call_if_eq BattleFrontier_Lounge2_EventScript_26070A
	compare VAR_FRONTIER_MANIAC_FACILITY, 1
	call_if_eq BattleFrontier_Lounge2_EventScript_26070F
	compare VAR_FRONTIER_MANIAC_FACILITY, 2
	call_if_eq BattleFrontier_Lounge2_EventScript_260714
	compare VAR_FRONTIER_MANIAC_FACILITY, 3
	call_if_eq BattleFrontier_Lounge2_EventScript_260719
	compare VAR_FRONTIER_MANIAC_FACILITY, 4
	call_if_eq BattleFrontier_Lounge2_EventScript_26071E
	compare VAR_FRONTIER_MANIAC_FACILITY, 5
	call_if_eq BattleFrontier_Lounge2_EventScript_260723
	compare VAR_FRONTIER_MANIAC_FACILITY, 6
	call_if_eq BattleFrontier_Lounge2_EventScript_260728
	compare VAR_FRONTIER_MANIAC_FACILITY, 7
	call_if_eq BattleFrontier_Lounge2_EventScript_26072D
	compare VAR_FRONTIER_MANIAC_FACILITY, 8
	call_if_eq BattleFrontier_Lounge2_EventScript_260732
	compare VAR_FRONTIER_MANIAC_FACILITY, 9
	call_if_eq BattleFrontier_Lounge2_EventScript_260737
	compare VAR_FRONTIER_MANIAC_FACILITY, 3
	call_if_le BattleFrontier_Lounge2_EventScript_2606F8
	compare VAR_FRONTIER_MANIAC_FACILITY, 4
	call_if_ge BattleFrontier_Lounge2_EventScript_260701
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_2606F8:: @ 82606F8
	msgbox BattleFrontier_Lounge2_Text_260933, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_260701:: @ 8260701
	msgbox BattleFrontier_Lounge2_Text_2608F2, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_26070A:: @ 826070A
	bufferstdstring 0, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_26070F:: @ 826070F
	bufferstdstring 0, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_260714:: @ 8260714
	bufferstdstring 0, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_260719:: @ 8260719
	bufferstdstring 0, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_26071E:: @ 826071E
	bufferstdstring 0, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_260723:: @ 8260723
	bufferstdstring 0, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_260728:: @ 8260728
	bufferstdstring 0, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_26072D:: @ 826072D
	bufferstdstring 0, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_260732:: @ 8260732
	bufferstdstring 0, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_260737:: @ 8260737
	bufferstdstring 0, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_26073C:: @ 826073C
	lock
	msgbox BattleFrontier_Lounge2_Text_261C9C, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_260747:: @ 8260747
	lock
	msgbox BattleFrontier_Lounge2_Text_261CDC, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_260752:: @ 8260752
	lock
	msgbox BattleFrontier_Lounge2_Text_261D1D, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_26075D:: @ 826075D
	msgbox BattleFrontier_Lounge2_Text_261D5C, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_260766:: @ 8260766
	.string "Bonjour! Si tu veux des infos sur la\n"
	.string "ZONE DE COMBAT, tu es au bon endroit.\p"
	.string "Je suis en quelque sorte le MORDU DE\n"
	.string "LA ZONE!\p"
	.string "Toi, tu es un DRESSEUR,\n"
	.string "n'est-ce pas?\p"
	.string "Je serais ravi de partager mes infos sur\n"
	.string "la ZONE DE COMBAT avec toi.$"

BattleFrontier_Lounge2_Text_260857:: @ 8260857
	.string "Bonjour! Je parierais que tu es là\n"
	.string "pour me faire parler un peu!$"

BattleFrontier_Lounge2_Text_2608A1:: @ 82608A1
	.string "Well? Well? Well?\p"
	.string "I'm sure my information's been\n"
	.string "seriously useful to you, right?$"

BattleFrontier_Lounge2_Text_2608F2:: @ 82608F2
	.string "Voyons voir…\p"
	.string "L'endroit le plus en vue en ce moment…\n"
	.string "{STR_VAR_1}, sans hésitation.$"

BattleFrontier_Lounge2_Text_260933:: @ 8260933
	.string "Voyons voir…\p"
	.string "Le {STR_VAR_1} de la TOUR DE COMBAT\n"
	.string "est le meilleur du moment.$"

BattleFrontier_Lounge2_Text_260971:: @ 8260971
	.string "Je suis sûr que je vais t'apprendre\n"
	.string "quelque chose!\p"
	.string "Un des super DRESSEURS que SCOTT\n"
	.string "appelle les MENEURS DE ZONE est ici.\p"
	.string "C'est un mystérieux DRESSEUR surnommé\n"
	.string "l'AS DU SALON.$"

BattleFrontier_Lounge2_Text_260A1E:: @ 8260A1E
	.string "As-tu affronté l'AS DU SALON?\p"
	.string "Elle utilise ces POKéMON quand elle veut\n"
	.string "se mettre à la hauteur de l'adversaire:\p"
	.string "Un POKéMON de type PSY,\n"
	.string "un POKéMON VOLCAN de type FEU\l"
	.string "et un POKéMON PIONCEUR de type NORMAL.$"

BattleFrontier_Lounge2_Text_260AE7:: @ 8260AE7
	.string "As-tu affonté l'AS DU SALON\n"
	.string "quand elle est sérieuse?\p"
	.string "Quand elle se bat à fond, elle utilise\n"
	.string "les POKéMON suivants:\p"
	.string "Un POKéMON EON de type DRAGON/PSY,\n"
	.string "un POKéMON FOUDRE de type ELECTRIK\l"
	.string "et un POKéMON PIONCEUR de type NORMAL.$"

BattleFrontier_Lounge2_Text_260BC4:: @ 8260BC4
	.string "Je vais t'apprendre quelque chose!\p"
	.string "Un des super DRESSEURS que SCOTT\n"
	.string "appelle les MENEURS DE ZONE est ici.\p"
	.string "C'est l'extravagant DRESSEUR appelé la\n"
	.string "STAR DU DOME.$"

BattleFrontier_Lounge2_Text_260C6D:: @ 8260C6D
	.string "As-tu affronté la STAR DU DOME?\p"
	.string "Quand il ne prend pas l'adversaire au\n"
	.string "sérieux, il utilise ces POKéMON:\p"
	.string "Un POKéMON DRAGON du type DRAGON/VOL,\n"
	.string "un POKéMON POISSONBOUE du type EAU/\l"
	.string "SOL et un POKéMON FLAMME du type\l"
	.string "FEU/VOL.$"

BattleFrontier_Lounge2_Text_260D3A:: @ 8260D3A
	.string "As-tu affronté la STAR DU DOME\n"
	.string "quand il se bat sérieusement?\p"
	.string "Quand il veut faire preuve de stratégie,\n"
	.string "il utilise ces trois POKéMON:\p"
	.string "Un POKéMON EON de type DRAGON/PSY,\n"
	.string "un POKéMON POISSONBOUE de type\l"
	.string "EAU/SOL et un POKéMON PATTEFER\l"
	.string "de type ACIER/PSY.$"

BattleFrontier_Lounge2_Text_260E1E:: @ 8260E1E
	.string "Je vais t'apprendre quelque chose!\p"
	.string "Un des super DRESSEURS que SCOTT\n"
	.string "appelle les MENEURS DE ZONE est ici.\p"
	.string "C'est l'étrange DRESSEUR appelé\n"
	.string "le CHEF D'USINE.$"

BattleFrontier_Lounge2_Text_260EC7:: @ 8260EC7
	.string "As-tu déjà affronté le CHEF D'USINE?\p"
	.string "Tu sais… Au combat, il doit utiliser\n"
	.string "trois POKéMON de location.\p"
	.string "Il se bat dans les mêmes conditions que\n"
	.string "les autres, en fait.$"

BattleFrontier_Lounge2_Text_260F74:: @ 8260F74
	.string "As-tu déjà affronté le CHEF D'USINE\n"
	.string "quand il se bat sérieusement?\p"
	.string "Même quand il veut se battre à fond, il\n"
	.string "doit utiliser trois POKéMON de location.\p"
	.string "En fin de compte, il se bat dans les\n"
	.string "mêmes conditions que les autres.$"

BattleFrontier_Lounge2_Text_261026:: @ 8261026
	.string "Je vais t'apprendre quelque chose!\p"
	.string "Un des super DRESSEURS que SCOTT\n"
	.string "appelle les MENEURS DE ZONE est ici.\p"
	.string "C'est le DRESSEUR effrayant appelé la\n"
	.string "REINE VENIN.$"

BattleFrontier_Lounge2_Text_2610CC:: @ 82610CC
	.string "Tu as déjà affronté la REINE VENIN?\p"
	.string "Quand elle est de bonne humeur, elle\n"
	.string "utilise ces POKéMON:\p"
	.string "Un POKéMON SERPACROC de type POISON,\n"
	.string "un POKéMON POURRI de type\l"
	.string "INSECTE/ROCHE et un POKéMON TENDRE\l"
	.string "de type EAU.$"

BattleFrontier_Lounge2_Text_261194:: @ 8261194
	.string "Tu as déjà affronté la REINE VENIN\n"
	.string "quand elle est énervée?\p"
	.string "Quand elle est vraiment agressive,\n"
	.string "elle utilise ces trois POKéMON:\p"
	.string "Un POKéMON SERPACROC de type POISON,\n"
	.string "Un POKéMON SERPENFER de type\l"
	.string "ACIER/SOL et un POKéMON TERRIFIANT\l"
	.string "de type EAU/VOL.$"

BattleFrontier_Lounge2_Text_261282:: @ 8261282
	.string "Je vais t'apprendre quelque chose!\p"
	.string "Un des super DRESSEURS que SCOTT\n"
	.string "appelle les MENEURS DE ZONE est ici.\p"
	.string "C'est le DRESSEUR pas mal appelé\n"
	.string "la PRO DU DOJO.$"

BattleFrontier_Lounge2_Text_261329:: @ 8261329
	.string "As-tu déjà affronté la PRO DU DOJO?\p"
	.string "Quand elle veut laisser une chance à\n"
	.string "l'adversaire, elle utilise ces POKéMON:\p"
	.string "Un POKéMON UNICORNE de type INSECTE/\n"
	.string "COMBAT, un POKéMON LUNE de type\l"
	.string "TENEBRES et un POKéMON EXUVIE\l"
	.string "de type INSECTE/SPECTRE.$"

BattleFrontier_Lounge2_Text_261403:: @ 8261403
	.string "As-tu déjà affronté la PRO DU DOJO?\p"
	.string "Si elle ne veut laisser aucune chance à\n"
	.string "l'adversaire, elle utilise ces POKéMON:\p"
	.string "Un POKéMON LUNE de type TENEBRES,\n"
	.string "un POKéMON OMBRE de type\l"
	.string "SPECTRE/POISON et un POKéMON\l"
	.string "CHAMPIGNON de type PLANTE/COMBAT.$"

BattleFrontier_Lounge2_Text_2614E6:: @ 82614E6
	.string "Je vais t'apprendre quelque chose!\p"
	.string "Un des super DRESSEURS que SCOTT\n"
	.string "appelle les MENEURS DE ZONE est ici.\p"
	.string "C'est ce DRESSEUR sinistre appelé\n"
	.string "le CAPT. PALACE.$"

BattleFrontier_Lounge2_Text_261591:: @ 8261591
	.string "Tu as déjà affronté le CAPT. PALACE?\p"
	.string "S'il veut tester l'adversaire, il utilise\n"
	.string "ces POKéMON:\p"
	.string "Un POKéMON CHOVSOURIS de type POISON/\n"
	.string "VOL, un POKéMON FAINEANT de type\l"
	.string "NORMAL et un POKéMON TRANSPORT\l"
	.string "de type EAU/GLACE.$"

BattleFrontier_Lounge2_Text_26166F:: @ 826166F
	.string "Tu as déjà combattu le CAPT. PALACE?\p"
	.string "Quand il se bat à fond, il utilise ces\n"
	.string "POKéMON:\p"
	.string "Un POKéMON LEGENDAIRE de type FEU,\n"
	.string "un POKéMON FAINEANT de type NORMAL\l"
	.string "et un POKéMON AURORE de type EAU.$"

BattleFrontier_Lounge2_Text_26174D:: @ 826174D
	.string "Je vais t'apprendre quelque chose!\p"
	.string "Un des super DRESSEURS que SCOTT\n"
	.string "appelle les MENEURS DE ZONE est ici.\p"
	.string "C'est ce DRESSEUR intrépide appelé\n"
	.string "le ROI PYRAMIDE.$"

BattleFrontier_Lounge2_Text_2617F9:: @ 82617F9
	.string "As-tu déjà affronté le ROI PYRAMIDE?\p"
	.string "Quand il veut évaluer l'adversaire,\n"
	.string "il utilise ces POKéMON:\p"
	.string "Un POKéMON PIC ROCHEUX de type ROCHE,\n"
	.string "un POKéMON ICEBERG de type GLACE\l"
	.string "et un POKéMON FER de type ACIER.$"

BattleFrontier_Lounge2_Text_2618C4:: @ 82618C4
	.string "As-tu déjà affronté le ROI PYRAMIDE\n"
	.string "quand il se bat pour de bon?\p"
	.string "Quand il est gonflé à bloc, il utilise\n"
	.string "ces POKéMON:\p"
	.string "Un POKéMON GLACIAIRE de type\n"
	.string "GLACE/VOL, un POKéMON ELECTRIQUE\l"
	.string "de type ELECTRIK/VOL et un POKéMON\l"
	.string "FLAMME de type FEU/VOL.$"

BattleFrontier_Lounge2_Text_2619AC:: @ 82619AC
	.string "Oui, il y a plein d'endroits où faire des\n"
	.string "COMBATS DUO.\p"
	.string "Mais il vaut mieux commencer par les\n"
	.string "SALLES DE COMBAT DUO de la\l"
	.string "TOUR DE COMBAT!\p"
	.string "C'est là que tu apprendras ce qu'est un\n"
	.string "COMBAT DUO dans la ZONE DE COMBAT.$"

BattleFrontier_Lounge2_Text_261A91:: @ 8261A91
	.string "Fais bien attention à toi.\p"
	.string "Il paraît que certains DRESSEURS\n"
	.string "développent des stratégies spéciales\l"
	.string "pour les COMBATS DUO.$"

BattleFrontier_Lounge2_Text_261B0C:: @ 8261B0C
	.string "Quand tu y maîtriseras les COMBATS DUO,\n"
	.string "tu pourrais essayer d'en faire ailleurs.$"

BattleFrontier_Lounge2_Text_261B95:: @ 8261B95
	.string "Toutes sortes de DRESSEURS se\n"
	.string "trouvent dans le SALON DE COMBAT.\p"
	.string "Il se peut que tu rencontres des amis\n"
	.string "ou encore des fans! Ouvre les yeux!$"

BattleFrontier_Lounge2_Text_261C1A:: @ 8261C1A
	.string "Si tu es avec un ami, dirige-toi vers\n"
	.string "la SALLE DE COMBAT MULTI LINK.\p"
	.string "Si ton ami est fort, les adversaires\n"
	.string "seront certainement de taille!$"

BattleFrontier_Lounge2_Text_261C9C:: @ 8261C9C
	.string "Quelle capacité de synthèse!\n"
	.string "Mon mentor est le meilleur!$"

BattleFrontier_Lounge2_Text_261CDC:: @ 8261CDC
	.string "Quel talent d'observation!\n"
	.string "Mon mentor est le meilleur!$"

BattleFrontier_Lounge2_Text_261D1D:: @ 8261D1D
	.string "Quelle force de persuasion!\n"
	.string "Mon mentor est le meilleur!$"

BattleFrontier_Lounge2_Text_261D5C:: @ 8261D5C
	.string "C'est quoi, cet endroit?\n"
	.string "J'ai un peu peur…$"
