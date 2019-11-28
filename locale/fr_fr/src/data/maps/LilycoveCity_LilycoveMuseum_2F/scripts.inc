LilycoveCity_LilycoveMuseum_2F_MapScripts:: @ 821973A
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_LilycoveMuseum_2F_MapScript1_219745
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_LilycoveMuseum_2F_MapScript2_2197FE
	.byte 0

LilycoveCity_LilycoveMuseum_2F_MapScript1_219745: @ 8219745
	goto_if_set FLAG_COOL_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_21978B
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_219754
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_219754:: @ 8219754
	goto_if_set FLAG_BEAUTY_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_2197A3
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_219763
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_219763:: @ 8219763
	goto_if_set FLAG_CUTE_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_2197BB
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_219772
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_219772:: @ 8219772
	goto_if_set FLAG_SMART_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_2197D3
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_219781
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_219781:: @ 8219781
	goto_if_set FLAG_TOUGH_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_2197EB
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_21978B:: @ 821978B
	setmetatile 10, 6, METATILE_LilycoveMuseum_Painting2_Left, 1
	setmetatile 11, 6, METATILE_LilycoveMuseum_Painting2_Right, 1
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_219754
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_2197A3:: @ 82197A3
	setmetatile 18, 6, METATILE_LilycoveMuseum_Painting1_Left, 1
	setmetatile 19, 6, METATILE_LilycoveMuseum_Painting1_Right, 1
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_219763
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_2197BB:: @ 82197BB
	setmetatile 14, 10, METATILE_LilycoveMuseum_Painting3_Left, 1
	setmetatile 15, 10, METATILE_LilycoveMuseum_Painting3_Right, 1
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_219772
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_2197D3:: @ 82197D3
	setmetatile 6, 10, METATILE_LilycoveMuseum_Painting0_Left, 1
	setmetatile 7, 10, METATILE_LilycoveMuseum_Painting0_Right, 1
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_219781
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_2197EB:: @ 82197EB
	setmetatile 2, 6, METATILE_LilycoveMuseum_Painting4_Left, 1
	setmetatile 3, 6, METATILE_LilycoveMuseum_Painting4_Right, 1
	end

LilycoveCity_LilycoveMuseum_2F_MapScript2_2197FE: @ 82197FE
	map_script_2 VAR_LILYCOVE_MUSEUM_2F_STATE, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_219808
	.2byte 0

LilycoveCity_LilycoveMuseum_2F_EventScript_219808:: @ 8219808
	lockall
	applymovement 1, Common_Movement_FacePlayer
	applymovement EVENT_OBJ_ID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_219861
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_2199EB, MSGBOX_SIGN
	applymovement 1, LilycoveCity_LilycoveMuseum_2F_Movement_219863
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_219863
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_219A0D, MSGBOX_SIGN
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_219861
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_219BC4, MSGBOX_SIGN
	copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 0x1
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_Movement_219861: @ 8219861
	walk_in_place_fastest_left
	step_end

LilycoveCity_LilycoveMuseum_2F_Movement_219863: @ 8219863
	face_up
	delay_16
	step_end

LilycoveCity_LilycoveMuseum_2F_EventScript_219866:: @ 8219866
	lockall
	goto_if_set FLAG_RECEIVED_GLASS_ORNAMENT, LilycoveCity_LilycoveMuseum_2F_EventScript_219921
	specialvar VAR_0x8004, CountPlayerContestPaintings
	switch VAR_0x8004
	case 1, LilycoveCity_LilycoveMuseum_2F_EventScript_2198BA
	case 2, LilycoveCity_LilycoveMuseum_2F_EventScript_2198BA
	case 3, LilycoveCity_LilycoveMuseum_2F_EventScript_2198BA
	case 4, LilycoveCity_LilycoveMuseum_2F_EventScript_2198BA
	case 5, LilycoveCity_LilycoveMuseum_2F_EventScript_2198C3
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_219CF3, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_2198BA:: @ 82198BA
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_219D42, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_2198C3:: @ 82198C3
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_219DD4, MSGBOX_DEFAULT
	applymovement 1, LilycoveCity_LilycoveMuseum_2F_Movement_219863
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_219DE6, MSGBOX_DEFAULT
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_2198EA
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_2198EA:: @ 82198EA
	applymovement 1, Common_Movement_FacePlayer
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_219EC5, MSGBOX_DEFAULT
	givedecoration_std DECOR_GLASS_ORNAMENT
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_LilycoveMuseum_2F_EventScript_219911
	setflag FLAG_RECEIVED_GLASS_ORNAMENT
	closemessage
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_219911:: @ 8219911
	call Common_EventScript_NoRoomLeftForAnother
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_219EED, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_219921:: @ 8219921
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_219F1B, MSGBOX_NPC
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_21992B:: @ 821992B
	lockall
	goto_if_set FLAG_CUTE_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_2199C1
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_219FA0, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_21993E:: @ 821993E
	lockall
	goto_if_set FLAG_TOUGH_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_2199DD
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_219FD3, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_219951:: @ 8219951
	lockall
	goto_if_set FLAG_COOL_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_2199A5
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_21A03B, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_219964:: @ 8219964
	lockall
	goto_if_set FLAG_BEAUTY_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_2199B3
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_21A008, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_219977:: @ 8219977
	lockall
	goto_if_set FLAG_SMART_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_2199CF
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_21A06D, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_21998A:: @ 821998A
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_21A0BD, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_219993:: @ 8219993
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_21A132, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_21999C:: @ 821999C
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_21A1A8, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_2199A5:: @ 82199A5
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_21A0A1, MSGBOX_SIGN
	fadescreen 1
	drawcontestwinner 9
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_2199B3:: @ 82199B3
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_21A0A1, MSGBOX_SIGN
	fadescreen 1
	drawcontestwinner 10
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_2199C1:: @ 82199C1
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_21A0A1, MSGBOX_SIGN
	fadescreen 1
	drawcontestwinner 11
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_2199CF:: @ 82199CF
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_21A0A1, MSGBOX_SIGN
	fadescreen 1
	drawcontestwinner 12
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_2199DD:: @ 82199DD
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_21A0A1, MSGBOX_SIGN
	fadescreen 1
	drawcontestwinner 13
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_Text_2199EB: @ 82199EB
	.string "Notre salle d'œuvres contemporaines!$"

LilycoveCity_LilycoveMuseum_2F_Text_219A0D: @ 8219A0D
	.string "Comme il est facile de le constater, il\n"
	.string "n'y a pas un seul tableau exposé.\p"
	.string "Je ne souhaite pas exposer d'œuvres\n"
	.string "dites «classiques» ici.\p"
	.string "Les œuvres de ce type ont déjà leur\n"
	.string "place au rez-de-chaussée.\p"
	.string "Mon désir est d'exposer des œuvres\n"
	.string "qui se distinguent de l'art classique.\p"
	.string "L'art, après tout, ne se limite pas\n"
	.string "aux anciennes œuvres célèbres!\p"
	.string "Cette salle, je désire l'emplir…\p"
	.string "d'œuvres modernes et pleines de vie\n"
	.string "représentant des POKéMON prêts à\l"
	.string "s'élancer dans une vie heureuse!$"

LilycoveCity_LilycoveMuseum_2F_Text_219BC4: @ 8219BC4
	.string "Je m'excuse. Je n'avais pas l'intention\n"
	.string "de monopoliser la conversation.\p"
	.string "Tu es jeune et as déjà beaucoup\n"
	.string "voyagé…\p"
	.string "Tu as dû voir des POKéMON pleins\n"
	.string "de vie et des œuvres les dépeignant.\p"
	.string "Si tu découvrais une telle œuvre, nous\n"
	.string "te serions reconnaissants de bien\l"
	.string "vouloir obtenir la permission de\l"
	.string "l'artiste pour l'exposer ici?$"

LilycoveCity_LilycoveMuseum_2F_Text_219CF3: @ 8219CF3
	.string "J'aimerais emplir cette salle de\n"
	.string "tableaux modernes et pleins de\l"
	.string "vie représentant des POKéMON.$"

LilycoveCity_LilycoveMuseum_2F_Text_219D42: @ 8219D42
	.string "Merci. Grâce à toi, nous avons ajouté\n"
	.string "un nouveau tableau à notre collection!\p"
	.string "Il paraît qu'il représente ton POKéMON.\n"
	.string "Vraiment magnifique!\p"
	.string "Merci beaucoup!$"

LilycoveCity_LilycoveMuseum_2F_Text_219DD4: @ 8219DD4
	.string "Ah, c'est toi!\n"
	.string "{PLAYER}!$"

LilycoveCity_LilycoveMuseum_2F_Text_219DE6: @ 8219DE6
	.string "N'est-ce pas fabuleux?\n"
	.string "Cette collection de tableaux!\p"
	.string "Tous parfaits! Il n'y en a pas un\n"
	.string "meilleur que les autres!\p"
	.string "Ces tableaux ont fait augmenter le\n"
	.string "nombre de visiteurs dans notre MUSEE.\p"
	.string "Merci vraiment, {PLAYER}.\n"
	.string "Mon rêve est devenu réalité!$"

LilycoveCity_LilycoveMuseum_2F_Text_219EC5: @ 8219EC5
	.string "Voici un gage de ma reconnaissance.$"

LilycoveCity_LilycoveMuseum_2F_Text_219EED: @ 8219EED
	.string "Je vais le garder pour toi jusqu'à notre\n"
	.string "prochaine rencontre.$"

LilycoveCity_LilycoveMuseum_2F_Text_219F1B: @ 8219F1B
	.string "Ah, ça fait plaisir de te voir, {PLAYER}!\p"
	.string "Quel honneur que tu trouves le temps de\n"
	.string "nous rendre visite entre tes voyages!\p"
	.string "Détends-toi et apprécie ta venue\n"
	.string "à nos côtés.$"

LilycoveCity_LilycoveMuseum_2F_Text_219FA0: @ 8219FA0
	.string "C'est un cadre à ornements roses.$"

LilycoveCity_LilycoveMuseum_2F_Text_219FD3: @ 8219FD3
	.string "C'est un cadre à ornements jaunes.$"

LilycoveCity_LilycoveMuseum_2F_Text_21A008: @ 821A008
	.string "C'est un cadre à ornements bleus.$"

LilycoveCity_LilycoveMuseum_2F_Text_21A03B: @ 821A03B
	.string "C'est un cadre à ornements rouges.$"

LilycoveCity_LilycoveMuseum_2F_Text_21A06D: @ 821A06D
	.string "C'est un cadre à ornements verts.$"

LilycoveCity_LilycoveMuseum_2F_Text_21A0A1: @ 821A0A1
	.string "C'est un tableau de POKéMON.$"

LilycoveCity_LilycoveMuseum_2F_Text_21A0BD: @ 821A0BD
	.string "J'ai été absente longtemps. Alors les\n"
	.string "tableaux à l'étage me surprennent.\p"
	.string "J'aimerais bien que quelqu'un peigne\n"
	.string "mes POKéMON comme ça.$"

LilycoveCity_LilycoveMuseum_2F_Text_21A132: @ 821A132
	.string "Alors voilà où sont exposés les\n"
	.string "tableaux à thèmes de POKéMON.\p"
	.string "Je vois, ces nouveaux tableaux sont\n"
	.string "effectivement très amusants.$"

LilycoveCity_LilycoveMuseum_2F_Text_21A1A8: @ 821A1A8
	.string "Waouh, c'est vrai? Ces tableaux?\n"
	.string "représentent tes POKéMON.\p"
	.string "N'est-ce pas la joie ultime pour un\n"
	.string "DRESSEUR?$"

