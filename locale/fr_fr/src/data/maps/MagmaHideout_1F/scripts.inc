MagmaHideout_1F_MapScripts:: @ 8239880
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition: @ 8239886
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

MagmaHideout_1F_EventScript_23988C:: @ 823988C
	trainerbattle_single TRAINER_GRUNT_38, MagmaHideout_1F_Text_2398BA, MagmaHideout_1F_Text_239964
	msgbox MagmaHideout_1F_Text_2399B1, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_2398A3:: @ 82398A3
	trainerbattle_single TRAINER_GRUNT_39, MagmaHideout_1F_Text_2399F5, MagmaHideout_1F_Text_239ABA
	msgbox MagmaHideout_1F_Text_239ACD, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_2398BA: @ 82398BA
	.string "A l'appel de la TEAM MAGMA, nous\n"
	.string "nous sommes présentés un par un pour\l"
	.string "recevoir nos assignements.\p"
	.string "C'est pour ça que je suis coincé dans\n"
	.string "ce coin, j'arrive toujours trop tard!$"

MagmaHideout_1F_Text_239964: @ 8239964
	.string "J'arrive aussi toujours en retard aux\n"
	.string "entraînements!\p"
	.string "J'aime pas trop l'avouer, mais je suis\n"
	.string "loin d'être le meilleur…$"

MagmaHideout_1F_Text_2399B1: @ 82399B1
	.string "OK, je vais essayer de m'entraîner\n"
	.string "un peu plus sérieusement.$"

MagmaHideout_1F_Text_2399F5: @ 82399F5
	.string "Notre leader nous a dit de creuser dans\n"
	.string "le MONT CHIMNEE, alors on a creusé.\p"
	.string "Et pendant qu'on était en train de\n"
	.string "creuser, on est tombés sur quelque\l"
	.string "chose de vraiment incroyable!\p"
	.string "Tu veux savoir ce que c'est?\p"
	.string "Ouahahah!\n"
	.string "Je te le dirai si t'arrives à me battre!$"

MagmaHideout_1F_Text_239ABA: @ 8239ABA
	.string "Ouille!\n"
	.string "Tu m'as eu!$"

MagmaHideout_1F_Text_239ACD: @ 8239ACD
	.string "J'ai changé d'avis, j'vais rien te dire!\n"
	.string "Tu vas devoir découvrir par toi-même!\p"
	.string "Je te gâcherais la surprise si je te\n"
	.string "disais tout, tu crois pas?$"

