LilycoveCity_CoveLilyMotel_2F_MapScripts:: @ 82186D2
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_2186D3:: @ 82186D3
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_2186F9
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_21870F
	specialvar VAR_RESULT, HasAllHoennMons
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_218702
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_2186F9:: @ 82186F9
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_218774, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_218702:: @ 8218702
	setflag FLAG_TEMP_2
	playfanfare MUS_FANFA4
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_21870F
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_21870F:: @ 821870F
	message LilycoveCity_CoveLilyMotel_2F_Text_21881C
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	waitstate
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_218720:: @ 8218720
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_2188D6, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_218729:: @ 8218729
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_21892B, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_218732:: @ 8218732
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_21896C, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_21873B:: @ 821873B
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_218A21, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_218744:: @ 8218744
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_218A5B, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_21874D:: @ 821874D
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_21876A
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_218ACF, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_21876A:: @ 821876A
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_218C33, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_218774: @ 8218774
	.string "Je suis le CONCEPTEUR DE JEU.\p"
	.string "Oh, est-ce que c'est vrai?\n"
	.string "Tu travailles sur un POKéDEX?\p"
	.string "C'est difficile de le compléter, mais\n"
	.string "n'abandonne pas.\p"
	.string "Si tu arrives à le compléter, reviens\n"
	.string "me voir.$"

LilycoveCity_CoveLilyMotel_2F_Text_21881C: @ 821881C
	.string "Waouh! C'est impressionnant!\n"
	.string "Ouais, carrément impressionnant!\p"
	.string "Ce POKéDEX est totalement rempli!\n"
	.string "Tu dois vraiment aimer les POKéMON!\p"
	.string "Je suis si impressionné!\p"
	.string "Laisse-moi te donner quelque chose\n"
	.string "pour récompenser ton exploit!$"

LilycoveCity_CoveLilyMotel_2F_Text_2188D6: @ 82188D6
	.string "Moi? C'est à moi que tu parles?\n"
	.string "Je suis le PROGRAMMEUR.\p"
	.string "Je me demande à quoi ressemblent\n"
	.string "les MACHINES A SOUS ici.$"

LilycoveCity_CoveLilyMotel_2F_Text_21892B: @ 821892B
	.string "Je suis le GRAPHISTE! Les POKéMON de\n"
	.string "HOENN ne sont-ils pas intéressants?$"

LilycoveCity_CoveLilyMotel_2F_Text_21896C: @ 821896C
	.string "Les filles FLOTTEURS sont à croquer,\n"
	.string "non? Pour affronter une de ces filles…\p"
	.string "Ouhhh, ça m'rend dingue!\p"
	.string "Et les JUMELLES! Mignonnes, hein? Un\n"
	.string "combat 2 contre 2 avec les JUMELLES…\p"
	.string "Ouhhh, c'est terrible!$"

LilycoveCity_CoveLilyMotel_2F_Text_218A21: @ 8218A21
	.string "La brise marine emballe mon cœur.\n"
	.string "Quel bonheur d'être ici!$"

LilycoveCity_CoveLilyMotel_2F_Text_218A5B: @ 8218A5B
	.string "Tu ne peux pas savoir où et quand on\n"
	.string "va te défier.\p"
	.string "C'est pour cela que je ne sors jamais\n"
	.string "sans ma GAME BOY ADVANCE.$"

LilycoveCity_CoveLilyMotel_2F_Text_218ACF: @ 8218ACF
	.string "SCOTT: … … … … …\n"
	.string "… … … … … Zzz…\p"
	.string "… … … … … Hein?!\n"
	.string "Oh, désolé, j'étais en train de dormir!\p"
	.string "Je suis venu voir ce qui se passe dans\n"
	.string "ces CONCOURS POKéMON.\p"
	.string "Je dois admettre que c'est plutôt\n"
	.string "divertissant, mais…\p"
	.string "En tant que puriste, je préfère les\n"
	.string "combats dangereux.\p"
	.string "Mais ce n'est que mon avis.\p"
	.string "{PLAYER}{KUN}, j'espère que tu vas profiter\n"
	.string "de tout: les ARENES, les CONCOURS,\l"
	.string "les TENTES DE COMBAT, tout!$"

LilycoveCity_CoveLilyMotel_2F_Text_218C33: @ 8218C33
	.string "SCOTT: Il faut beaucoup de stratégie\n"
	.string "pour remporter un CONCOURS.\p"
	.string "Parler des stratégies des CONCOURS\n"
	.string "est, à mon avis, une façon de devenir\l"
	.string "un bon DRESSEUR.$"

