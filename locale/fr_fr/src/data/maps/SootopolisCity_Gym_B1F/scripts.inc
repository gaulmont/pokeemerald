SootopolisCity_Gym_B1F_MapScripts:: @ 8225C8A
	.byte 0

SootopolisCity_Gym_B1F_EventScript_Andrea:: @ 8225C8B
	trainerbattle_single TRAINER_ANDREA, SootopolisCity_Gym_B1F_Text_AndreaPreBattle, SootopolisCity_Gym_B1F_Text_AndreaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AndreaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Crissy:: @ 8225CA2
	trainerbattle_single TRAINER_CRISSY, SootopolisCity_Gym_B1F_Text_CrissyPreBattle, SootopolisCity_Gym_B1F_Text_CrissyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_CrissyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Brianna:: @ 8225CB9
	trainerbattle_single TRAINER_BRIANNA, SootopolisCity_Gym_B1F_Text_BriannaPreBattle, SootopolisCity_Gym_B1F_Text_BriannaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BriannaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Connie:: @ 8225CD0
	trainerbattle_single TRAINER_CONNIE, SootopolisCity_Gym_B1F_Text_ConniePreBattle, SootopolisCity_Gym_B1F_Text_ConnieDefeat
	msgbox SootopolisCity_Gym_B1F_Text_ConniePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bridget:: @ 8225CE7
	trainerbattle_single TRAINER_BRIDGET, SootopolisCity_Gym_B1F_Text_BridgetPreBattle, SootopolisCity_Gym_B1F_Text_BridgetDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Olivia:: @ 8225CFE
	trainerbattle_single TRAINER_OLIVIA, SootopolisCity_Gym_B1F_Text_OliviaPreBattle, SootopolisCity_Gym_B1F_Text_OliviaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_OliviaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Tiffany:: @ 8225D15
	trainerbattle_single TRAINER_TIFFANY, SootopolisCity_Gym_B1F_Text_TiffanyPreBattle, SootopolisCity_Gym_B1F_Text_TiffanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_TiffanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bethany:: @ 8225D2C
	trainerbattle_single TRAINER_BETHANY, SootopolisCity_Gym_B1F_Text_BethanyPreBattle, SootopolisCity_Gym_B1F_Text_BethanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BethanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Annika:: @ 8225D43
	trainerbattle_single TRAINER_ANNIKA, SootopolisCity_Gym_B1F_Text_AnnikaPreBattle, SootopolisCity_Gym_B1F_Text_AnnikaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AnnikaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Daphne:: @ 8225D5A
	trainerbattle_single TRAINER_DAPHNE, SootopolisCity_Gym_B1F_Text_DaphnePreBattle, SootopolisCity_Gym_B1F_Text_DaphneDefeat
	msgbox SootopolisCity_Gym_B1F_Text_DaphnePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_Text_AndreaPreBattle: @ 8225D71
	.string "Tu vas voir les super techniques que\n"
	.string "notre CHAMPION JUAN m'a apprises!$"

SootopolisCity_Gym_B1F_Text_AndreaDefeat: @ 8225DB6
	.string "De grâce, pardonne-moi, JUAN…$"

SootopolisCity_Gym_B1F_Text_AndreaPostBattle: @ 8225DCF
	.string "Regarde ce qui arrive si tu casses tous\n"
	.string "les carreaux du sol.$"

SootopolisCity_Gym_B1F_Text_CrissyPreBattle: @ 8225E04
	.string "Tu as fait tout le chemin jusqu'ici, mais\n"
	.string "tu n'auras pas l'occasion de voir JUAN.\p"
	.string "Pas si tu perds contre moi en tout cas!$"

SootopolisCity_Gym_B1F_Text_CrissyDefeat: @ 8225E60
	.string "Quelle force tu as!\n"
	.string "Ton air tout gentil est trompeur!$"

SootopolisCity_Gym_B1F_Text_CrissyPostBattle: @ 8225E90
	.string "Tu réussiras peut-être à ne pas te\n"
	.string "faire démolir par JUAN en un seul coup.$"

SootopolisCity_Gym_B1F_Text_DaphnePreBattle: @ 8225ED6
	.string "Voir JUAN mener un combat…\p"
	.string "Rien que la beauté de ce spectacle \n"
	.string "m'a incitée à devenir DRESSEUR.$"

SootopolisCity_Gym_B1F_Text_DaphneDefeat: @ 8225F35
	.string "Tu as combattu avec plus de brio\n"
	.string "que je n'ai su le faire…$"

SootopolisCity_Gym_B1F_Text_DaphnePostBattle: @ 8225F67
	.string "L'élégance que tu dégages au combat\n"
	.string "est fabuleuse.\p"
	.string "Oh… J'ai vraiment de la chance d'avoir\n"
	.string "combats peuvent être rudes.$"

SootopolisCity_Gym_B1F_Text_ConniePreBattle: @ 8225FBE
	.string "Je devrais t'apprendre combien les\n"
	.string "can be.$"

SootopolisCity_Gym_B1F_Text_ConnieDefeat: @ 8225FEB
	.string "Oh!\n"
	.string "Quelle puissance!$"

SootopolisCity_Gym_B1F_Text_ConniePostBattle: @ 8225FFE
	.string "Je vais te donner un conseil.\p"
	.string "Si tu veux rejoindre JUAN, tu dois\n"
	.string "fouler chaque carreau une seule fois.$"

SootopolisCity_Gym_B1F_Text_BridgetPreBattle: @ 8226061
	.string "La meilleure ARENE POKéMON de la\n"
	.string "région de HOENN…\p"
	.string "C'est l'ARENE d'ATALANOPOLIS.$"

SootopolisCity_Gym_B1F_Text_BridgetDefeat: @ 82260B6
	.string "Quel bon niveau tu as!$"

SootopolisCity_Gym_B1F_Text_BridgetPostBattle: @ 82260D1
	.string "Plutôt que de se contenter d'être dans\n"
	.string "une ARENE puissante, j'imagine que\l"
	.string "s'entraîner ailleurs rend plus fort. Et\l"
	.string "ça a surtout l'air plus sympa.$"

SootopolisCity_Gym_B1F_Text_OliviaPreBattle: @ 8226164
	.string "Je m'entraîne avec JUAN.\n"
	.string "Je ne suis pas une adversaire facile!$"

SootopolisCity_Gym_B1F_Text_OliviaDefeat: @ 82261A7
	.string "Je me suis fait battre…$"

SootopolisCity_Gym_B1F_Text_OliviaPostBattle: @ 82261B5
	.string "Je pense que tu as du potentiel. Tu\n"
	.string "devrais rester t'entraîner avec nous.$"

SootopolisCity_Gym_B1F_Text_TiffanyPreBattle: @ 82261F7
	.string "Une élégante glissade sur la glace\n"
	.string "sans dépasser aucune ligne…\p"
	.string "Un DRESSEUR capable de cette prouesse\n"
	.string "serait d'une élégance folle!$"

SootopolisCity_Gym_B1F_Text_TiffanyDefeat: @ 8226274
	.string "Eh bien, tu m'excuses?!$"

SootopolisCity_Gym_B1F_Text_TiffanyPostBattle: @ 8226286
	.string "Il est évident que l'âge n'a rien à voir\n"
	.string "avec la puissance que tu peux avoir\l"
	.string "en tant que DRESSEUR.$"

SootopolisCity_Gym_B1F_Text_BethanyPreBattle: @ 82262F3
	.string "Quand je suis avec mes POKéMON,\n"
	.string "le temps défile à la vitesse de l'éclair.$"

SootopolisCity_Gym_B1F_Text_BethanyDefeat: @ 822633B
	.string "Oups!$"

SootopolisCity_Gym_B1F_Text_BethanyPostBattle: @ 8226341
	.string "J'aimerais aussi oublier les défaites\n"
	.string "à la vitesse de l'éclair.$"

SootopolisCity_Gym_B1F_Text_AnnikaPreBattle: @ 8226388
	.string "Si tu veux, je peux me battre avec des\n"
	.string "POKéMON très rares.$"

SootopolisCity_Gym_B1F_Text_AnnikaDefeat: @ 82263BD
	.string "Oh! Tu as eu le temps de bien voir\n"
	.string "mes POKéMON?$"

SootopolisCity_Gym_B1F_Text_AnnikaPostBattle: @ 82263F4
	.string "Je suis venue dans cette ARENE\n"
	.string "parce que JUAN m'avait fait les\l"
	.string "louanges de mes POKéMON chéris.\p"
	.string "Oh, si seulement je l'avais rencontré\n"
	.string "quand j'étais plus jeune…$"

SootopolisCity_Gym_B1F_Text_BriannaPreBattle: @ 822646E
	.string "Hi hi…\n"
	.string "Ton regard est vraiment charmant.$"

SootopolisCity_Gym_B1F_Text_BriannaDefeat: @ 8226495
	.string "Eh bien. Je devais être trop sûre de\n"
	.string "ma victoire.$"

SootopolisCity_Gym_B1F_Text_BriannaPostBattle: @ 82264BC
	.string "Tu ne pourras pas poser un doigt\n"
	.string "sur JUAN, j'en suis sûre!$"

