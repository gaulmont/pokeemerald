SootopolisCity_House3_MapScripts:: @ 8226B71
	.byte 0

SootopolisCity_House3_EventScript_226B72:: @ 8226B72
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_226BA4, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq SootopolisCity_House3_EventScript_226B91
	msgbox SootopolisCity_House3_Text_226C44, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_226B91:: @ 8226B91
	msgbox SootopolisCity_House3_Text_226C20, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_226B9B:: @ 8226B9B
	msgbox SootopolisCity_House3_Text_226C9C, MSGBOX_NPC
	end

SootopolisCity_House3_Text_226BA4: @ 8226BA4
	.string "Tu es DRESSEUR, non?\p"
	.string "JUAN d'ATALANOPOLIS a de nombreux\n"
	.string "fans. Encore plus que son élève MARC!\p"
	.string "Et toi, tu en as?$"

SootopolisCity_House3_Text_226C20: @ 8226C20
	.string "Oh, quelle puissance tu dois avoir!$"

SootopolisCity_House3_Text_226C44: @ 8226C44
	.string "Oh, mon p'tit…\n"
	.string "Tu es un peu solitaire.\p"
	.string "Essaie de travailler plus dur pour\n"
	.string "avoir des fans à tes côtés.$"

SootopolisCity_House3_Text_226C9C: @ 8226C9C
	.string "Les fans dévoués viennent même\n"
	.string "d'en dehors de HOENN.\p"
	.string "C'était la folie quand je suis allée au\n"
	.string "FAN CLUB DES DRESSEURS à NENUCRIQUE.$"

