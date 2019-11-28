SootopolisCity_LotadAndSeedotHouse_MapScripts:: @ 822722A
	.byte 0

SootopolisCity_LotadAndSeedotHouse_EventScript_22722B:: @ 822722B
	special GetSeedotSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_227369, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	compare VAR_RESULT, 255
	goto_if_eq SootopolisCity_LotadAndSeedotHouse_EventScript_227272
	special CompareSeedotSize
	compare VAR_RESULT, 1
	goto_if_eq SootopolisCity_LotadAndSeedotHouse_EventScript_22727C
	compare VAR_RESULT, 2
	goto_if_eq SootopolisCity_LotadAndSeedotHouse_EventScript_227286
	compare VAR_RESULT, 3
	goto_if_eq SootopolisCity_LotadAndSeedotHouse_EventScript_227290
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_227272:: @ 8227272
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_2275BC, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_22727C:: @ 822727C
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_227584, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_227286:: @ 8227286
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_227544, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_227290:: @ 8227290
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_227480, MSGBOX_DEFAULT
	giveitem_std ITEM_ELIXIR
	compare VAR_RESULT, 0
	goto_if_eq SootopolisCity_LotadAndSeedotHouse_EventScript_2272B2
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_2272B2:: @ 82272B2
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_227524, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_2272BC:: @ 82272BC
	special GetLotadSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_227676, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	compare VAR_RESULT, 255
	goto_if_eq SootopolisCity_LotadAndSeedotHouse_EventScript_227303
	special CompareLotadSize
	compare VAR_RESULT, 1
	goto_if_eq SootopolisCity_LotadAndSeedotHouse_EventScript_22730D
	compare VAR_RESULT, 2
	goto_if_eq SootopolisCity_LotadAndSeedotHouse_EventScript_227317
	compare VAR_RESULT, 3
	goto_if_eq SootopolisCity_LotadAndSeedotHouse_EventScript_227321
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_227303:: @ 8227303
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_227896, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_22730D:: @ 822730D
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_227867, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_227317:: @ 8227317
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_22782A, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_227321:: @ 8227321
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_22776C, MSGBOX_DEFAULT
	giveitem_std ITEM_ELIXIR
	compare VAR_RESULT, 0
	goto_if_eq SootopolisCity_LotadAndSeedotHouse_EventScript_227343
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_227343:: @ 8227343
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_22780A, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_22734D:: @ 822734D
	special GetSeedotSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_227617, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_22735B:: @ 822735B
	special GetLotadSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_2278F2, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_Text_227369: @ 8227369
	.string "Tu connais le POKéMON GRAINIPIOT?\n"
	.string "Il se fait rare à ATALANOPOLIS.\p"
	.string "Moi, j'adore les grands GRAINIPIOT.\n"
	.string "Plus ils sont grands et mieux c'est.\p"
	.string "Mais mon p'tit frère, il dit que les\n"
	.string "NENUPIOT sont plus grands.\p"
	.string "C'est pas vrai. Les GRAINIPIOT\n"
	.string "sont encore plus grands!\p"
	.string "Hum? Tu as un GRAINIPIOT avec toi?\n"
	.string "Oh, fais-moi voir, s'il te plaît!$"

SootopolisCity_LotadAndSeedotHouse_Text_227480: @ 8227480
	.string "{STR_VAR_2} cm!\n"
	.string "Waouh, il est grand celui-là!\p"
	.string "Il pourrait même dépasser le grand\n"
	.string "NENUPIOT que mon p'tit frère a vu!\p"
	.string "Merci de me l'avoir montré.\n"
	.string "Tiens, c'est ma façon de te remercier!$"

SootopolisCity_LotadAndSeedotHouse_Text_22750E: @ 822750E
	.string "{PLAYER} received a POTION.$"

SootopolisCity_LotadAndSeedotHouse_Text_227524: @ 8227524
	.string "Oh?\n"
	.string "Ton SAC est carrément plein.$"

SootopolisCity_LotadAndSeedotHouse_Text_227544: @ 8227544
	.string "{STR_VAR_2} cm, c'est ça?\p"
	.string "Hum… J'ai vu un plus grand GRAINIPIOT\n"
	.string "que celui-là.$"

SootopolisCity_LotadAndSeedotHouse_Text_227584: @ 8227584
	.string "Ah oui, c'est quelque chose!\n"
	.string "Mais c'est pas un GRAINIPIOT!$"

SootopolisCity_LotadAndSeedotHouse_Text_2275BC: @ 82275BC
	.string "Tu n'as pas de grand GRAINIPIOT?\n"
	.string "Quel dommage…\p"
	.string "Si tu trouves un grand GRAINIPIOT,\n"
	.string "viens me le montrer.$"

SootopolisCity_LotadAndSeedotHouse_Text_227617: @ 8227617
	.string "Le plus grand GRAINIPIOT jamais vu!\n"
	.string "Un géant de {STR_VAR_2} cm appartenant\l"
	.string  à {STR_VAR_3}!\p"
	.string "Un GRAINIPIOT encore plus\n"
	.string "grand qu'un NENUPIOT!$"

SootopolisCity_LotadAndSeedotHouse_Text_227676: @ 8227676
	.string "Tu connais le POKéMON NENUPIOT?\n"
	.string "On en voit rarement à ATALANOPOLIS.\p"
	.string "J'adore, j'adore les grands NENUPIOT!\p"
	.string "Mon grand frère dit que le GRAINIPIOT\n"
	.string "est plus grand.\p"
	.string "Mais c'est faux! Tout le monde sait\n"
	.string "bien que le NENUPIOT est plus grand.\p"
	.string "Hum? Tu as un NENUPIOT?\n"
	.string "Fais-moi voir, s'il te plaît!$"

SootopolisCity_LotadAndSeedotHouse_Text_22776C: @ 822776C
	.string "{STR_VAR_2} cm!\n"
	.string "Waouh, c'est beaucoup!\p"
	.string "C'est peut-être encore plus grand que\n"
	.string "l'énorme GRAINIPIOT que mon frère a vu.\p"
	.string "Merci de me l'avoir montré!\n"
	.string "Tiens, c'est pour te remercier!$"

SootopolisCity_LotadAndSeedotHouse_Text_2277F4: @ 82277F4
	.string "{PLAYER} received a POTION.$"

SootopolisCity_LotadAndSeedotHouse_Text_22780A: @ 822780A
	.string "Oh?\n"
	.string "Ton SAC est carrément plein.$"

SootopolisCity_LotadAndSeedotHouse_Text_22782A: @ 822782A
	.string "{STR_VAR_2} cm?\p"
	.string "Hum… J'ai vu un plus grand NENUPIOT\n"
	.string "que celui-là.$"

SootopolisCity_LotadAndSeedotHouse_Text_227867: @ 8227867
	.string "Eh bien, ça c'est quelque chose!\n"
	.string "Mais c'est pas un NENUPIOT!$"

SootopolisCity_LotadAndSeedotHouse_Text_227896: @ 8227896
	.string "Tu n'as pas de grand NENUPIOT?\n"
	.string "C'est dommage…\p"
	.string "Si tu trouves un grand NENUPIOT,\n"
	.string "viens me le montrer.$"

SootopolisCity_LotadAndSeedotHouse_Text_2278F2: @ 82278F2
	.string "Le plus grand NENUPIOT jamais vu!\n"
	.string "Un colosse de {STR_VAR_2} cm appartenant\l"
	.string "à {STR_VAR_3}!\p"
	.string "Un NENUPIOT encore plus\n"
	.string "grand qu'un GRAINIPIOT!$"

