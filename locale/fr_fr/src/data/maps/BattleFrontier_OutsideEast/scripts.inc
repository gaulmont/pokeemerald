BattleFrontier_OutsideEast_MapScripts:: @ 8242C04
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_MapScript1_242C0F
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_MapScript1_242C2D
	.byte 0

BattleFrontier_OutsideEast_MapScript1_242C0F: @ 8242C0F
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_242C19
	end

BattleFrontier_OutsideEast_EventScript_242C19:: @ 8242C19
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_MapScript1_242C2D: @ 8242C2D
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_242C3F
	end

BattleFrontier_OutsideEast_EventScript_242C3F:: @ 8242C3F
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_242C43:: @ 8242C43
	msgbox BattleFrontier_OutsideEast_Text_242E11, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_242C4C:: @ 8242C4C
	msgbox BattleFrontier_OutsideEast_Text_242E58, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_242C55:: @ 8242C55
	msgbox BattleFrontier_OutsideEast_Text_242E96, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_242C5E:: @ 8242C5E
	msgbox BattleFrontier_OutsideEast_Text_242ECF, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_242C67:: @ 8242C67
	msgbox BattleFrontier_OutsideEast_Text_242F8C, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242C70:: @ 8242C70
	msgbox BattleFrontier_OutsideEast_Text_242FDC, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242C79:: @ 8242C79
	msgbox BattleFrontier_OutsideEast_Text_24308C, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242C82:: @ 8242C82
	msgbox BattleFrontier_OutsideEast_Text_243106, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242C8B:: @ 8242C8B
	msgbox BattleFrontier_OutsideEast_Text_2431A5, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242C94:: @ 8242C94
	lock
	msgbox BattleFrontier_OutsideEast_Text_2432DD, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_242C9F:: @ 8242C9F
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, 0
	msgbox BattleFrontier_OutsideEast_Text_24334B, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_242CB2:: @ 8242CB2
	msgbox BattleFrontier_OutsideEast_Text_243363, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242CBB:: @ 8242CBB
	msgbox BattleFrontier_OutsideEast_Text_243425, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242CC4:: @ 8242CC4
	msgbox BattleFrontier_OutsideEast_Text_2434A0, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242CCD:: @ 8242CCD
	msgbox BattleFrontier_OutsideEast_Text_243504, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242CD6:: @ 8242CD6
	lock
	msgbox BattleFrontier_OutsideEast_Text_243529, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_242CE1:: @ 8242CE1
	msgbox BattleFrontier_OutsideEast_Text_243230, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo:: @ 8242CEA
	lock
	faceplayer
	waitse
	playse 269
	applymovement 14, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo:: @ 8242CFC
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitstate
	waitse
	playse SE_USSOKI
	applymovement 14, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, 2
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, 14  @ Sudowoodo object event id
	setwildbattle SPECIES_SUDOWOODO, 40, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BattleFrontier_OutsideEast_EventScript_RemoveSudowoodo
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq BattleFrontier_OutsideEast_EventScript_RemoveSudowoodo
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq BattleFrontier_OutsideEast_EventScript_RemoveSudowoodo
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_RemoveSudowoodo:: @ 8242D60
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake: @ 8242D69
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_242D79:: @ 8242D79
	msgbox BattleFrontier_OutsideEast_Text_243598, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242D82:: @ 8242D82
	msgbox BattleFrontier_OutsideEast_Text_243668, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242D8B:: @ 8242D8B
	msgbox BattleFrontier_OutsideEast_Text_2436F2, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242D94:: @ 8242D94
	msgbox BattleFrontier_OutsideEast_Text_243809, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242D9D:: @ 8242D9D
	msgbox BattleFrontier_OutsideEast_Text_243895, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242DA6:: @ 8242DA6
	msgbox BattleFrontier_OutsideEast_Text_243943, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242DAF:: @ 8242DAF
	msgbox BattleFrontier_OutsideEast_Text_2439A0, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242DB8:: @ 8242DB8
	lock
	msgbox BattleFrontier_OutsideEast_Text_243A2B, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_242DC3:: @ 8242DC3
	lock
	msgbox BattleFrontier_OutsideEast_Text_243A53, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_242DCE:: @ 8242DCE
	msgbox BattleFrontier_OutsideEast_Text_242F0D, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_242DD7:: @ 8242DD7
	msgbox BattleFrontier_OutsideEast_Text_242F4A, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_242DE0:: @ 8242DE0
	msgbox BattleFrontier_OutsideEast_Text_243B68, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242DE9:: @ 8242DE9
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_242DFE
	msgbox BattleFrontier_OutsideEast_Text_243C2C, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_242DFE:: @ 8242DFE
	msgbox BattleFrontier_OutsideEast_Text_243CA3, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_242E08:: @ 8242E08
	msgbox BattleFrontier_OutsideEast_Text_243D0B, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_242E11: @ 8242E11
	.string "TOUR DE COMBAT\n"
	.string "“Enchaînez les victoires!”$"

BattleFrontier_OutsideEast_Text_242E58: @ 8242E58
	.string "PALACE DE COMBAT\n"
	.string "“Gardez un œil sur vos POKéMON!”$"

BattleFrontier_OutsideEast_Text_242E96: @ 8242E96
	.string "DOJO DE COMBAT\n"
	.string "“Que les équipes se forment!”$"

BattleFrontier_OutsideEast_Text_242ECF: @ 8242ECF
	.string "PYRAMIDE DE COMBAT\n"
	.string "“Découvrez l'aventure du COMBAT\l"
	.string "QUETE!”$"

BattleFrontier_OutsideEast_Text_242F0D: @ 8242F0D
	.string "HALL DE CLASSEMENT\n"
	.string "“Jetez un œil aux records des\l"
	.string "meilleurs!”$"

BattleFrontier_OutsideEast_Text_242F4A: @ 8242F4A
	.string "SERVICE D'ECHANGE\n"
	.string "“Echangez vos POINTS DE COMBAT!”$"

BattleFrontier_OutsideEast_Text_242F8C: @ 8242F8C
	.string "Waouh!\n"
	.string "C'est immense!\p"
	.string "La TOUR DE COMBAT est un endroit\n"
	.string "unique. Il ne ressemble à aucun autre.$"

BattleFrontier_OutsideEast_Text_242FDC: @ 8242FDC
	.string "Ma grande ambition est de conquérir la\n"
	.string "ZONE DE COMBAT et la LIGUE POKéMON.\p"
	.string "Si mon rêve se réalise…\p"
	.string "Je demanderai à MIMI si elle veut bien\n"
	.string "être mon amie!$"

BattleFrontier_OutsideEast_Text_24308C: @ 824308C
	.string "La PYRAMIDE DE COMBAT est trop dure!\n"
	.string "Je n'arrive pas à atteindre le sommet!\p"
	.string "Je pense que je vais essayer de\n"
	.string "l'atteindre par l'extérieur…$"

BattleFrontier_OutsideEast_Text_243106: @ 8243106
	.string "Je m'épanouis dans l'obscurité…\n"
	.string "Oui… Ce qui compte à mes yeux?\l"
	.string "La PYRAMIDE DE COMBAT…\p"
	.string "J'aime me promener dans l'obscurité la\n"
	.string "plus totale, au bord du désespoir.$"

BattleFrontier_OutsideEast_Text_2431A5: @ 82431A5
	.string "Je n'ai pas dormi depuis une semaine,\n"
	.string "mais j'ai réuni une super équipe!\p"
	.string "Franchement, je ne peux pas perdre.\n"
	.string "A moi le DOJO DE COMBAT!$"

BattleFrontier_OutsideEast_Text_243230: @ 8243230
	.string "Tu es ici grâce à SCOTT?\n"
	.string "Il est bizarre, quand même, non?\p"
	.string "Il est très fort pour repérer les\n"
	.string "DRESSEURS qui ont du talent, oui…\p"
	.string "Mais je ne l'ai absolument jamais vu\n"
	.string "se battre.$"

BattleFrontier_OutsideEast_Text_2432DD: @ 82432DD
	.string "ZIGG!\n"
	.string "Je crois en toi, mon bébé!\p"
	.string "Je te préparerai tout ce que tu voudras\n"
	.string "si tu gagnes, mon petit ZIGG!$"

BattleFrontier_OutsideEast_Text_24334B: @ 824334B
	.string "ZIGZATON a l'air absent…$"

BattleFrontier_OutsideEast_Text_243363: @ 8243363
	.string "Les cuisiniers du PALACE disent que je\n"
	.string "suis un fouineur. C'est peut-être vrai…\p"
	.string "Ta toque est de travers!\n"
	.string "C'est tombé par terre, ramasse vite!\l"
	.string "Vite, c'est presque l'heure du dîner!\p"
	.string "Je ne peux pas m'empêcher de mettre\n"
	.string "mon grain de sel…$"

BattleFrontier_OutsideEast_Text_243425: @ 8243425
	.string "Je ne fais plus très peur, mais dans le\n"
	.string "temps, j'ai battu un CHAMPION D'ARENE.\p"
	.string "Qui sait, peut-être que je devrais m'y\n"
	.string "remettre!?!$"

BattleFrontier_OutsideEast_Text_2434A0: @ 82434A0
	.string "Sur mon VELO, je suis rapide.\n"
	.string "Aux combats aussi!\p"
	.string "Je gagne mes combats en un clin\n"
	.string "d'œil!$"

BattleFrontier_OutsideEast_Text_243504: @ 8243504
	.string "Je suis plus forte que mon père\n"
	.string "aux POKéMON.$"

BattleFrontier_OutsideEast_Text_243529: @ 8243529
	.string "Allez, mon bébé!\n"
	.string "Va gagner pour papa!\p"
	.string "Tu ressembles à ta mère, tu vas les\n"
	.string "mener par le bout du nez!$"

BattleFrontier_OutsideEast_Text_243598: @ 8243598
	.string "Je viens de très loin, j'avais entendu\n"
	.string "dire qu'il y avait une jolie fille au DOJO\l"
	.string "DE COMBAT.\p"
	.string "Tu sais ce que j'ai trouvé à\n"
	.string "la place?\p"
	.string "Un ramassis de fanas d'arts\n"
	.string "martiaux!$"

BattleFrontier_OutsideEast_Text_243668: @ 8243668
	.string "Des fois, je vois un vieil homme à l'air\n"
	.string "très important qui entre ici.\p"
	.string "Il a des POKéMON magnifiques.\n"
	.string "Il a l'air très gentil.$"

BattleFrontier_OutsideEast_Text_2436F2: @ 82436F2
	.string "Tu la connais, la légende de la\n"
	.string "PYRAMIDE DE COMBAT?\p"
	.string "Quand un DRESSEUR sûr de lui\n"
	.string "atteindra le sommet doré, un homme\l"
	.string "apparaîtra parmi les hommes.\p"
	.string "Tu ne connais pas cette légende?\n"
	.string "Pas étonnant, je viens de l'inventer!\p"
	.string "Il y a un sens caché, tu sais.\n"
	.string "Désolé, motus et bouche cousue!$"

BattleFrontier_OutsideEast_Text_243809: @ 8243809
	.string "Mince, alors!\n"
	.string "C'est la première fois que je perds!\p"
	.string "Je me suis fait écraser comme un\n"
	.string "moucheron!\p"
	.string "Et en plus, on vient me dire que je\n"
	.string "n'ai aucun talent! Mince…$"

BattleFrontier_OutsideEast_Text_243895: @ 8243895
	.string "Cet homme a dû se battre contre un\n"
	.string "DRESSEUR horriblement fort à la TOUR\l"
	.string "DE COMBAT.\p"
	.string "Et maintenant, regarde-le…\p"
	.string "Si tu décides d'aller à la TOUR DE\n"
	.string "COMBAT, fais bien attention.$"

BattleFrontier_OutsideEast_Text_243943: @ 8243943
	.string "Chouette!\n"
	.string "J'ai enfin assez de POINTS DE COMBAT!\p"
	.string "Je pense que je vais les échanger\n"
	.string "contre une autre POUPEE!$"

BattleFrontier_OutsideEast_Text_2439A0: @ 82439A0
	.string "Waouh… Alors comme ça, c'est le\n"
	.string "HALL DE CLASSEMENT!\p"
	.string "J'aimerais qu'on se souvienne de moi.\n"
	.string "J'aimerais que mon nom soit inscrit ici.\l"
	.string "Je veux passer à la postérité!$"

BattleFrontier_OutsideEast_Text_243A2B: @ 8243A2B
	.string "Avec toi à mes côtés, rien ne peut\n"
	.string "m'arrêter.$"

BattleFrontier_OutsideEast_Text_243A53: @ 8243A53
	.string "Oh, mon chéri! Tu es formidable!\p"
	.string "Je ne veux plus attendre!\p"
	.string "Allons vite dans une SALLE DE COMBAT\n"
	.string "MULTI!\p"
	.string "Si nous allons dans le SALON DE\n"
	.string "COMBAT ensemble, ils vont tous trembler\l"
	.string "devant la force de notre amour.\p"
	.string "Ils vont tous s'effondrer comme des\n"
	.string "dominos devant nous!$"

BattleFrontier_OutsideEast_Text_243B68: @ 8243B68
	.string "La ZONE DE COMBAT n'est pas réservée\n"
	.string "qu'aux bons DRESSEURS.\p"
	.string "Il paraît que des gens ayant d'autres\n"
	.string "aptitudes ont été invités aussi.\p"
	.string "Ce SCOTT…\p"
	.string "Peut-être qu'il avait une idée derrière\n"
	.string "la tête en construisant cet endroit…$"

BattleFrontier_OutsideEast_Text_243C2C: @ 8243C2C
	.string "Pardon, petit.\n"
	.string "As-tu une bonne vue?\p"
	.string "Il y a un arbre bizarre là-bas.\n"
	.string "J'ai l'impression qu'il bouge.$"

BattleFrontier_OutsideEast_Text_243CA3: @ 8243CA3
	.string "Pardon, petit.\n"
	.string "As-tu une bonne mémoire?\p"
	.string "Il me semble qu'il y avait un arbre\n"
	.string "bizarre là-bas, avant.$"

BattleFrontier_OutsideEast_Text_243D0B: @ 8243D0B
	.string "…\n"
	.string "Je l'ai vu!\p"
	.string "J'ai vu un POKéMON du genre gluant\n"
	.string "avec une longue queue!\p"
	.string "Il se cachait derrière un rocher et\n"
	.string "n'arrêtait pas de me regarder!$"
