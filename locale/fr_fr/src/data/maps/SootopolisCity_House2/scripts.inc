SootopolisCity_House2_MapScripts:: @ 8226A76
	.byte 0

SootopolisCity_House2_EventScript_226A77:: @ 8226A77
	lock
	faceplayer
	msgbox SootopolisCity_House2_Text_226AAB, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_eq SootopolisCity_House2_EventScript_226A99
	compare VAR_RESULT, 0
	call_if_eq SootopolisCity_House2_EventScript_226AA2
	release
	end

SootopolisCity_House2_EventScript_226A99:: @ 8226A99
	msgbox SootopolisCity_House2_Text_226AF1, MSGBOX_DEFAULT
	return

SootopolisCity_House2_EventScript_226AA2:: @ 8226AA2
	msgbox SootopolisCity_House2_Text_226B41, MSGBOX_DEFAULT
	return

SootopolisCity_House2_Text_226AAB: @ 8226AAB
	.string "MONT MEMORIA…\p"
	.string "Au sommet reposent deux orbes\n"
	.string "l'un à côté de l'autre. Tu le savais?$"

SootopolisCity_House2_Text_226AF1: @ 8226AF1
	.string "C'est ça, deux orbes côte à côte…\p"
	.string "Les voir ensemble…\n"
	.string "C'est apaisant…$"

SootopolisCity_House2_Text_226B41: @ 8226B41
	.string "Non. C'est vrai?\n"
	.string "Tu devrais peut-être y aller pour voir…$"

