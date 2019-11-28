MtPyre_2F_MapScripts:: @ 82310FB
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp: @ 823110B
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F, 255, 0, 0
	end

MtPyre_2F_EventScript_231116:: @ 8231116
	msgbox MtPyre_2F_Text_2311A3, MSGBOX_NPC
	end

MtPyre_2F_EventScript_23111F:: @ 823111F
	msgbox MtPyre_2F_Text_2311E6, MSGBOX_NPC
	end

MtPyre_2F_EventScript_231128:: @ 8231128
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_231258, MtPyre_2F_Text_2312A2
	msgbox MtPyre_2F_Text_2312CB, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_23113F:: @ 823113F
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_23130F, MtPyre_2F_Text_2313A1, MtPyre_2F_Text_231414
	msgbox MtPyre_2F_Text_2313B1, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_23115A:: @ 823115A
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_231492, MtPyre_2F_Text_231534, MtPyre_2F_Text_231582
	msgbox MtPyre_2F_Text_23154D, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_231175:: @ 8231175
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_231604, MtPyre_2F_Text_231645
	msgbox MtPyre_2F_Text_23165A, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_23118C:: @ 823118C
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_2316C7, MtPyre_2F_Text_2316E1
	msgbox MtPyre_2F_Text_2316FB, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_Text_2311A3: @ 82311A3
	.string "Souvenirs de mon cher SKITTY…\n"
	.string "A sa pensée, les larmes me viennent.$"

MtPyre_2F_Text_2311E6: @ 82311E6
	.string "Ouille, ouille… Des trous parsèment le\n"
	.string "sol ici et là.\p"
	.string "J'avais pas fait attention et je suis\n"
	.string "tombé de l'étage du dessus.$"

MtPyre_2F_Text_231258: @ 8231258
	.string "Hé! Tu cherches des POKéMON?\n"
	.string "Alors tu m'as trouvé! Quelle audace!$"

MtPyre_2F_Text_2312A2: @ 82312A2
	.string "Aïïïïe!\n"
	.string "Désolé, excuse-moi, je t'en prie!$"

MtPyre_2F_Text_2312CB: @ 82312CB
	.string "Les gens venant rarement ici, je me\n"
	.string "disais qu'il y aurait des POKéMON rares.$"

MtPyre_2F_Text_23130F: @ 823130F
	.string "KARL: C'est un défi.\p"
	.string "Hé, si je lui prouve que je suis génial,\n"
	.string "elle tombera amoureuse de moi. Je l'sais!\p"
	.string "Je sais! Je vais te mettre la pâtée pour\n"
	.string "lui montrer que je suis génial!$"

MtPyre_2F_Text_2313A1: @ 82313A1
	.string "KARL: Oh là là!$"

MtPyre_2F_Text_2313B1: @ 82313B1
	.string "KARL: On a perdu, mais c'est\n"
	.string "pas grave!\p"
	.string "Je reste avec toi, on va y arriver!$"

MtPyre_2F_Text_231414: @ 8231414
	.string "KARL: Si tu veux m'affronter,\n"
	.string "apporte plus de POKéMON.\p"
	.string "Sinon, je ne pourrai pas montrer à ma\n"
	.string "copine à quel point je suis génial!$"

MtPyre_2F_Text_231492: @ 8231492
	.string "ANNIE: Si je suis là, c'est parce qu'on\n"
	.string "a fait un pari avec mon petit ami.\p"
	.string "C'est effrayant, mais comme je suis\n"
	.string "avec mon petit ami, ça va.\p"
	.string "Je sais! Mon petit ami va être craquant\n"
	.string "quand il va te battre!$"

MtPyre_2F_Text_231534: @ 8231534
	.string "ANNIE: Aaaaah! J'ai peur!$"

MtPyre_2F_Text_23154D: @ 823154D
	.string "ANNIE: On s'aime tendrement, alors on\n"
	.string "s'en fiche de perdre!$"

MtPyre_2F_Text_231582: @ 8231582
	.string "ANNIE: Pour nous affronter, il faut\n"
	.string "que tu aies au moins deux POKéMON.\p"
	.string "Mon petit ami est fort.\n"
	.string "Un seul POKéMON, ça ne suffira pas!$"

MtPyre_2F_Text_231604: @ 8231604
	.string "Je pressens un malheur…\n"
	.string "Pars avant qu'il ne soit trop tard!$"

MtPyre_2F_Text_231645: @ 8231645
	.string "Humm…\n"
	.string "Plutôt coriace!$"

MtPyre_2F_Text_23165A: @ 823165A
	.string "Dans ma famille, nous sommes DRESSEURS\n"
	.string "depuis des générations…\p"
	.string "Il est de mon devoir de protéger cette\n"
	.string "montagne…$"

MtPyre_2F_Text_2316C7: @ 82316C7
	.string "Aaaaah!\n"
	.string "Je suis terrifié!$"

MtPyre_2F_Text_2316E1: @ 82316E1
	.string "Nooon!\n"
	.string "J'ai perdu toute confiance en moi!$"

MtPyre_2F_Text_2316FB: @ 82316FB
	.string "J'ai peur dès que je vois quelque chose\n"
	.string "bouger…\p"
	.string "Je n'aurais pas dû venir m'entraîner\n"
	.string "ici…$"

