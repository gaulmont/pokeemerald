RustboroCity_DevonCorp_1F_MapScripts:: @ 8211245
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition: @ 821124B
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_211255
	end

RustboroCity_DevonCorp_1F_EventScript_211255:: @ 8211255
	setobjectxyperm 2, 14, 2
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_211261:: @ 8211261
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_211289
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_21127F
	msgbox RustboroCity_DevonCorp_1F_Text_2113D1, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_21127F:: @ 821127F
	msgbox RustboroCity_DevonCorp_1F_Text_211446, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_211289:: @ 8211289
	msgbox RustboroCity_DevonCorp_1F_Text_2114DE, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_211293:: @ 8211293
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_2112BA
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_2112C4
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_2112C4
	msgbox RustboroCity_DevonCorp_1F_Text_21151B, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_2112BA:: @ 82112BA
	msgbox RustboroCity_DevonCorp_1F_Text_211585, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_2112C4:: @ 82112C4
	msgbox RustboroCity_DevonCorp_1F_Text_211558, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_2112CE:: @ 82112CE
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_2112F5
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_2112FF
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_2112FF
	msgbox RustboroCity_DevonCorp_1F_Text_21131B, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_2112F5:: @ 82112F5
	msgbox RustboroCity_DevonCorp_1F_Text_21131B, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_2112FF:: @ 82112FF
	msgbox RustboroCity_DevonCorp_1F_Text_21138B, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_211309:: @ 8211309
	msgbox RustboroCity_DevonCorp_1F_Text_2115AC, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_211312:: @ 8211312
	msgbox RustboroCity_DevonCorp_1F_Text_211722, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_21131B: @ 821131B
	.string "Bonjour et bienvenue à la DEVON SARL.\p"
	.string "Nous produisons avec fierté des objets\n"
	.string "et médicaments qui simplifient la vie.$"

RustboroCity_DevonCorp_1F_Text_21138B: @ 821138B
	.string "Une de nos équipes de chercheurs s'est\n"
	.string "fait voler un important paquet.$"

RustboroCity_DevonCorp_1F_Text_2113D1: @ 82113D1
	.string "Hé, ces CHAUSSURES DE SPORT!\n"
	.string "Elles sortent de nos ateliers!\p"
	.string "J'aime constater que ce que nous\n"
	.string "avons produit sert à quelqu'un.$"

RustboroCity_DevonCorp_1F_Text_211446: @ 8211446
	.string "Ce paquet qui a été volé…\p"
	.string "Bien sûr, c'est important, mais ce n'est\n"
	.string "pas utile à tout le monde.\p"
	.string "Et d'après mes calculs, le voleur ne\n"
	.string "doit pas être très intelligent.$"

RustboroCity_DevonCorp_1F_Text_2114DE: @ 82114DE
	.string "Ils ont l'air d'avoir retrouvé le\n"
	.string "PACK DEVON qui avait été volé.$"

RustboroCity_DevonCorp_1F_Text_21151B: @ 821151B
	.string "Désolé, mais seules les personnes\n"
	.string "autorisées peuvent entrer ici.$"

RustboroCity_DevonCorp_1F_Text_211558: @ 8211558
	.string "C'est trop bête!\n"
	.string "Comment a-t-on pu se faire voler?$"

RustboroCity_DevonCorp_1F_Text_211585: @ 8211585
	.string "Bonjour! C'est toujours avec grand\n"
	.string "plaisir que nous vous accueillons ici!$"

RustboroCity_DevonCorp_1F_Text_2115AC: @ 82115AC
	.string "Des échantillons de pierres et de\n"
	.string "métaux sont placés dans une vitrine.\p"
	.string "Il y a un panneau avec quelque chose\n"
	.string "d'écrit…\p"
	.string "“DEVON était à l'origine une\n"
	.string "compagnie d'exploitation minière.\p"
	.string "La compagnie a également produit de\n"
	.string "l'acier en exploitant la limaille se\l"
	.string "trouvant dans le sable.\p"
	.string "DEVON s'est sans cesse développé\n"
	.string "depuis ses humbles débuts.\p"
	.string "DEVON fabrique maintenant\n"
	.string "une grande variété de produits\l"
	.string "industriels.”$"

RustboroCity_DevonCorp_1F_Text_211722: @ 8211722
	.string "La vitrine est pleine de prototypes et\n"
	.string "d'échantillons.\p"
	.string "Il y a un panneau avec une inscription…\p"
	.string "“En plus de ses produits industriels,\n"
	.string "DEVON souhaite se développer sur le\p"
	.string "marché pharmaceutique pour\n"
	.string "améliorer notre qualité de vie.\p"
	.string "Récemment, DEVON a commercialisé des\n"
	.string "outils pour les DRESSEURS, comme les\p"
	.string "POKé BALLS et les systèmes POKéNAV.”$"

