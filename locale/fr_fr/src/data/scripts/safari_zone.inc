SafariZone_EventScript_OutOfBallsMidBattle:: @ 82A4B4C
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 255, 2, 5
	end

SafariZone_EventScript_Exit:: @ 82A4B5D
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 255, 2, 5
	waitstate
	end

SafariZone_EventScript_RetirePrompt:: @ 82A4B6F
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire:: @ 82A4B85
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp:: @ 82A4B8A
	lockall
	playse SE_PINPON
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls:: @ 82A4B9B
	lockall
	playse SE_PINPON
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder:: @ 82A4BAC
	lockall
	special GetPokeblockFeederInFront
	compare VAR_RESULT, 0xFFFF
	goto_if_ne SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock:: @ 82A4BD0
	fadescreen 1
	special OpenPokeblockCaseOnFeeder
	waitstate
	compare VAR_RESULT, 0xFFFF
	goto_if_ne SafariZone_EventScript_PokeblockPlaced
	end

SafariZone_EventScript_PokeblockPlaced:: @ 82A4BE2
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent:: @ 82A4BEB
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_WouldYouLikeToExit: @ 82A4BF4
	.string "Voulez-vous quitter le PARC SAFARI\n"
	.string "tout de suite?$"

SafariZone_Text_TimesUp: @ 82A4C26
	.string "Ding-dong! Le temps est écoulé!\n"
	.string "Votre partie de SAFARI est terminée.$"

SafariZone_Text_OutOfBalls: @ 82A4C56
	.string "Vous n'avez plus de SAFARI BALLS.\n"
	.string "Votre partie de SAFARI est terminée.$"

SafariZone_Text_PlacePokeblockOnFeeder: @ 82A4C90
	.string "Voulez-vous placer un {POKEBLOCK}\n"
	.string "dans la MANGEOIRE {POKEBLOCK}?$"

SafariZone_Text_PokeblockStillHere: @ 82A4CC5
	.string "Le {STR_VAR_1} que vous aviez\n"
	.string "placé là y est encore.$"

SafariZone_Text_PokeblockWasPlaced: @ 82A4CEB
	.string "Le {STR_VAR_1} a été placé\n"
	.string "dans la MANGEOIRE {POKEBLOCK}.$"

Route121_SafariZoneEntrance_Text_WelcomeToSafariZone: @ 82A4D12
	.string "Bienvenue dans le PARC SAFARI!\p"
	.string "Ici, vous pourrez admirer de nombreuses\n"
	.string "espèces de POKéMON rares à HOENN.\p"
	.string "Et vous pourrez les voir à l'état\n"
	.string "sauvage, dans leur habitat naturel.\p"
	.string "De plus, les DRESSEURS DE POKéMON\n"
	.string "sont les bienvenus dans ce parc.\p"
	.string "Vous êtes encouragés à attraper des\n"
	.string "POKéMON et à les garder!\p"
	.string "Entrez et amusez-vous au PARC SAFARI!$"

Route121_SafariZoneEntrance_Text_WelcomeFirstTime: @ 82A4E46
	.string "Bienvenue au PARC SAFARI!\n"
	.string "C'est la première fois que vous venez?$"

Route121_SafariZoneEntrance_Text_ComeInAndEnjoy: @ 82A4E7E
	.string "Entrez et amusez-vous au PARC SAFARI!$"

Route121_SafariZoneEntrance_Text_FirstTimeInfo: @ 82A4EA1
	.string "Lorsque vous entrez dans le PARC\n"
	.string "SAFARI, vous recevez 30 SAFARI\l"
	.string "BALLS pour attraper des POKéMON.\p"
	.string "La partie de SAFARI se termine lorsque\n"
	.string "vous n'avez plus de SAFARI BALLS ou\l"
	.string "lorsque vous avez parcouru 500 pas.\p"
	.string "Entrez et amusez-vous au PARC SAFARI!$"

Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay: @ 82A4F74
	.string "Bienvenue au PARC SAFARI!\p"
	.string "Attrapez un max de POKéMON pour 500$!\n"
	.string "Voulez-vous faire un SAFARI?$"

Route121_SafariZoneEntrance_Text_PlayAnotherTime: @ 82A4FD7
	.string "D'accord.\n"
	.string "Revenez nous voir une autre fois!$"

Route121_SafariZoneEntrance_Text_NotEnoughMoney: @ 82A4FF7
	.string "Vous n'avez pas assez d'argent.\n"
	.string "Désolé.$"

Route121_SafariZoneEntrance_Text_ThatWillBe500Please: @ 82A501B
	.string "Cela fera 500¥, s'il vous plaît.$"

Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls: @ 82A5036
	.string "Voici vos SAFARI BALLS.$"

Route121_SafariZoneEntrance_Text_Received30SafariBalls: @ 82A5052
	.string "{PLAYER} reçoit 30 SAFARI BALLS.$"

Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself: @ 82A506F
	.string "Nous vous préviendrons quand votre\n"
	.string "SAFARI sera terminé.\p"
	.string "En attendant, amusez-vous bien!\n"
	.string "Profitez de votre équipée sauvage!$"

Route121_SafariZoneEntrance_Text_PCIsFull: @ 82A50E5
	.string "Je regrette!\n"
	.string "La BOITE de votre PC est pleine.$"

Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase: @ 82A5105
	.string "Je regrette!\n"
	.string "Vous n'avez pas de BOITE {POKEBLOCK}S.\p"
	.string "Vous attraperez bien plus de POKéMON\n"
	.string "si vous utilisez des {POKEBLOCK}S.\p"
	.string "Revenez nous voir avec une\n"
	.string "BOITE {POKEBLOCK}S.\p"
	.string "On vous en fournira peut-être une dans\n"
	.string "la SALLE DE CONCOURS de NENUCRIQUE.$"

SafariZone_South_Text_StillHaveTimeExit: @ 82A51D4
	.string "Votre temps n'est pas encore écoulé.\n"
	.string "Voulez-vous quitter le PARC SAFARI?$"

SafariZone_South_Text_EnjoyTheRestOfYourAdventure: @ 82A521A
	.string "Amusez-vous bien et profitez de votre\n"
	.string "équipée sauvage!$"

SafariZone_South_Text_ExitEarlyThankYouForPlaying: @ 82A5248
	.string "Bien.\p"
	.string "Je vais reprendre vos SAFARI BALLS\n"
	.string "restantes.\p"
	.string "Merci d'avoir joué.\n"
	.string "Nous espérons vous revoir bientôt.$"

SafariZone_South_Text_GoodLuck: @ 82A52AB
	.string "Bonne chance!\p"
	.string "Si vous avez besoin de quoi que ce soit,\n"
	.string "n'hésitez pas à venir me voir!$"

SafariZone_South_Text_Boy: @ 82A52EF
	.string "Le savais-tu?\p"
	.string "Si tu mets un {POKEBLOCK} dans cette boîte\n"
	.string "carrée, les POKéMON tourneront autour.$"

SafariZone_South_Text_Man: @ 82A533B
	.string "J'aimerais bien continuer plus loin, mais\n"
	.string "j'ai oublié d'apporter un VELO.\p"
	.string "Quelque chose me dit que des POKéMON\n"
	.string "rares vivent dans les zones reculées.$"

SafariZone_Southwest_Text_Woman: @ 82A53B7
	.string "Parfois, j'envoie un {POKEBLOCK} à un\n"
	.string "POKéMON, mais il l'ignore.\p"
	.string "Est-ce que les POKéMON ont des\n"
	.string "préférences en matière de nourriture?$"

SafariZone_Northwest_Text_Man: @ 82A542C
	.string "Pfou… Pfou…\n"
	.string "Je… J'ai réussi à venir jusqu'ici, mais…\p"
	.string "Je suis épuisé… Je n'ai plus la force\n"
	.string "d'attraper des POKéMON…$"

SafariZone_North_Text_Fisherman: @ 82A5489
	.string "J'ai pour mission de trouver des\n"
	.string "POKéMON EAU introuvables à HOENN.\p"
	.string "Tu sais où se trouve le lac?$"

SafariZone_North_Text_Man: @ 82A54F0
	.string "Je vais attraper plein de POKéMON rares\n"
	.string "ici et je les échangerai avec mes amis!$"

SafariZone_South_Text_Youngster: @ 82A553E
	.string "J'ai mis un {POKEBLOCK} dans la MANGEOIRE.\n"
	.string "Mais apparemment, il a disparu.\p"
	.string "Je suppose qu'un POKéMON l'a mangé\n"
	.string "pendant que je ne regardais pas.$"

Route121_SafariZoneEntrance_Text_TrainerTip: @ 82A55BB
	.string "PARC SAFARI - CONSEIL AUX DRESSEURS!\p"
	.string "Lancez des {POKEBLOCK}S aux POKéMON\n"
	.string "sauvages pour éviter qu'ils s'enfuient.$"

SafariZone_Southwest_Text_RestHouseSign: @ 82A5613
	.string "“Reposez vos jambes fatiguées.”\n"
	.string "REFUGE$"

SafariZone_RestHouse_Text_Youngster: @ 82A5639
	.string "Je n'ai pas de {POKEBLOCK}, mais j'ai quand\n"
	.string "même attrapé beaucoup de POKéMON.\p"
	.string "Tu peux augmenter tes chances\n"
	.string "d'attraper un POKéMON en t'approchant\l"
	.string "avant de jeter une SAFARI BALL.$"

SafariZone_RestHouse_Text_PsychicM: @ 82A56E1
	.string "Si tu leur donnes des {POKEBLOCK}S, les\n"
	.string "POKéMON s'enfuient moins vite.\p"
	.string "Ça ne sert pas à grand-chose de donner\n"
	.string "des {POKEBLOCK}S aux POKéMON qui ne\l"
	.string "sont pas farouches.$"

SafariZone_RestHouse_Text_FatMan: @ 82A5764
	.string "Si tu mets un {POKEBLOCK} dans la MANGEOIRE,\n"
	.string "ça attirera les POKéMON.\p"
	.string "Je crois que certains types de POKéMON\n"
	.string "sont attirés par certains {POKEBLOCK}S.$"

SafariZone_South_Text_AreaOffLimits1: @ 82A57EE
	.string "Cette zone est encore en construction.\n"
	.string "Vous ne pouvez pas entrer, désolé!$"

SafariZone_Southeast_Text_ExpansionIsFinished: @ 82A582D
	.string "Les travaux d'agrandissement du\n"
	.string "PARC SAFARI sont terminés.\p"
	.string "Nous espérons que la nouvelle zone\n"
	.string "vous apportera entière satisfaction.$"

SafariZone_South_Text_AreaOffLimits2: @ 82A5887
	.string "Cette zone est encore en construction.\n"
	.string "Vous ne pouvez pas entrer, désolé!$"

SafariZone_Southeast_Text_LittleGirl: @ 82A58C6
	.string "Waouh! Délire! C'est la première fois que\n"
	.string "je vois ce genre de POKéMON!$"

SafariZone_Southeast_Text_FatMan: @ 82A58FD
	.string "Je n'avais jamais vu aucun des POKéMON\n"
	.string "de cette zone.\p"
	.string "Et j'ai le droit d'attraper tous ces\n"
	.string "POKéMON rares? Trop cool!$"

SafariZone_Southeast_Text_RichBoy: @ 82A5960
	.string "Je ne pense pas que les POKéMON qui\n"
	.string "se trouvent ici soient de HOENN.$"

SafariZone_Northeast_Text_Boy: @ 82A59A4
	.string "Il ne me reste que quelques\n"
	.string "SAFARI BALLS.\p"
	.string "J'ai du mal à décider ce que je dois\n"
	.string "attraper.$"

SafariZone_Northeast_Text_Woman: @ 82A5A09
	.string "On dit qu'il y a des PIKACHU ici.\n"
	.string "Je me demande bien où ils se cachent.$"

SafariZone_Northeast_Text_Girl: @ 82A5A44
	.string "Oh, bouh!\n"
	.string "Je n'arrive à rien ici!\p"
	.string "J'ai payé l'entrée, il faut absolument\n"
	.string "que j'attrape quelque chose!$"
