BattleFrontier_Lounge5_MapScripts:: @ 82645C5
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl:: @ 82645C6
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	compare VAR_0x8004, 255
	goto_if_eq BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq BattleFrontier_Lounge5_EventScript_NatureGirlEgg
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlEgg:: @ 8264603
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown:: @ 826460D
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_264617:: @ 8264617
	msgbox BattleFrontier_Lounge5_Text_264F22, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_264620:: @ 8264620
	msgbox BattleFrontier_Lounge5_Text_264F64, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_264629:: @ 8264629
	msgbox BattleFrontier_Lounge5_Text_264FAB, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting:: @ 8264632
	.string "Hé, hé, hé!\n"
	.string "Je sais ce que les POKéMON pensent!\p"
	.string "S'il te plaît!\n"
	.string "Je peux voir tes POKéMON?$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown:: @ 826467F
	.string "Bouh!\n"
	.string "C'est pas sympa!$"

BattleFrontier_Lounge5_Text_NatureGirlHardy:: @ 826468D
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime se battre!\n"
	.string "Même couvert de bobos, il se battra!$"

BattleFrontier_Lounge5_Text_NatureGirlLonely:: @ 82646E5
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime être sournois!\n"
	.string "Mais s'il est couvert de bobos, il\l"
	.string "ripostera!$"

BattleFrontier_Lounge5_Text_NatureGirlBrave:: @ 8264741
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime se battre!\n"
	.string "Mais s'il se retrouve couvert de bobos,\l"
	.string "il se met à pleurnicher!$"

BattleFrontier_Lounge5_Text_NatureGirlAdamant:: @ 82647A4
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime se battre!\n"
	.string "Même couvert de bobos, il se battra!$"

BattleFrontier_Lounge5_Text_NatureGirlNaughty:: @ 82647FC
	.string "Hum…\p"
	.string "Celui-là dit qu'il prend soin de lui!\n"
	.string "Mais s'il accumule les bobos, il\l"
	.string "ripostera!$"

BattleFrontier_Lounge5_Text_NatureGirlBold:: @ 8264858
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime être sournois!\n"
	.string "Mais s'il se retrouve couvert de bobos,\l"
	.string "il se met à pleurnicher!$"

BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky:: @ 82648BE
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime se battre!\n"
	.string "Même couvert de bobos, il se battra!$"

BattleFrontier_Lounge5_Text_NatureGirlRelaxed:: @ 8264916
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime être sournois!\n"
	.string "Mais s'il est couvert de bobos, il\l"
	.string "ripostera!$"

BattleFrontier_Lounge5_Text_NatureGirlImpish:: @ 8264972
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime se battre!\n"
	.string "Mais s'il se retrouve couvert de bobos,\l"
	.string "il se met à pleurnicher!$"

BattleFrontier_Lounge5_Text_NatureGirlLax:: @ 82649D5
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime être sournois!\n"
	.string "Il aime être sournois même quand il\l"
	.string "est couvert de bobos!$"

BattleFrontier_Lounge5_Text_NatureGirlTimid:: @ 8264A3F
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime se battre!\n"
	.string "Mais s'il se retrouve couvert de bobos,\l"
	.string "il deviendra sournois!$"

BattleFrontier_Lounge5_Text_NatureGirlHasty:: @ 8264A9B
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime se battre!\n"
	.string "Même couvert de bobos, il se battra!$"

BattleFrontier_Lounge5_Text_NatureGirlSerious:: @ 8264AF3
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime être sournois!\n"
	.string "Il aime être sournois même quand il\l"
	.string "est couvert de bobos!$"

BattleFrontier_Lounge5_Text_NatureGirlJolly:: @ 8264B5D
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime être sournois!\n"
	.string "Mais s'il se retrouve couvert de bobos,\l"
	.string "il se met à pleurnicher!$"

BattleFrontier_Lounge5_Text_NatureGirlModest:: @ 8264BC3
	.string "Hum…\p"
	.string "Celui-là dit qu'il prend soin de lui!\n"
	.string "Il ne pense qu'à lui, qu'il soit ou\l"
	.string "non couvert de bobos!$"

BattleFrontier_Lounge5_Text_NatureGirlMild:: @ 8264C36
	.string "Hum…\p"
	.string "Celui-là dit qu'il prend soin de lui!\n"
	.string "Mais s'il se retrouve couvert de bobos,\l"
	.string "il deviendra sournois!$"

BattleFrontier_Lounge5_Text_NatureGirlBashful:: @ 8264C95
	.string "Hum…\p"
	.string "Celui-là dit qu'il prend soin de lui!\n"
	.string "Il ne pense qu'à lui même quand il\l"
	.string "est couvert de bobos!$"

BattleFrontier_Lounge5_Text_NatureGirlRash:: @ 8264D01
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime être sournois!\n"
	.string "Il aime être sournois même quand il\l"
	.string "est couvert de bobos!$"

BattleFrontier_Lounge5_Text_NatureGirlCalm:: @ 8264D6B
	.string "Hum…\p"
	.string "Celui-là dit qu'il prend soin de lui!\n"
	.string "Il ne pense qu'à lui même quand il\l"
	.string "est couvert de bobos!$"

BattleFrontier_Lounge5_Text_NatureGirlGentle:: @ 8264DD7
	.string "Hum…\p"
	.string "Celui-là dit qu'il prend soin de lui!\n"
	.string "Mais s'il est couvert de bobos, il\l"
	.string "ripostera!$"

BattleFrontier_Lounge5_Text_NatureGirlSassy:: @ 8264E33
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime se battre!\n"
	.string "Mais s'il se retrouve couvert de bobos,\l"
	.string "il deviendra sournois!$"

BattleFrontier_Lounge5_Text_NatureGirlCareful:: @ 8264E8F
	.string "Hum…\p"
	.string "Celui-là dit qu'il prend soin de lui!\n"
	.string "Mais s'il se retrouve couvert de bobos,\l"
	.string "il deviendra sournois!$"

BattleFrontier_Lounge5_Text_NatureGirlEgg:: @ 8264EEE
	.string "C'est n'importe quoi! Comment tu veux\n"
	.string "que je parle avec un OEUF!?!$"

BattleFrontier_Lounge5_Text_264F22:: @ 8264F22
	.string "Comme c'est mignon!\n"
	.string "Cette jeune fille prétend qu'elle peut\l"
	.string "comprendre les POKéMON!$"

BattleFrontier_Lounge5_Text_264F64:: @ 8264F64
	.string "J'ai l'impression que cette fille dit\n"
	.string "quelque chose de profond.$"

BattleFrontier_Lounge5_Text_264FAB:: @ 8264FAB
	.string "J'ai une info!\p"
	.string "Cette fille joue souvent dans le\n"
	.string "bâtiment rouge!$"
