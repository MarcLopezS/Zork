#include "NPCsDialogues.h"


NPCsDialogues::NPCsDialogues()
{
	allDialogues = readJson();
}

NPCsDialogues::~NPCsDialogues()
{
}

void NPCsDialogues::dialogueController(NPCType npcType, int& stateDialog)
{
	switch (npcType)
	{
	case NPCType::MOM:
		momController(stateDialog);
		break;
	case NPCType::BROTHER:
		brotherController(stateDialog);
		break;
	case NPCType::STRANGER:
		strangerDialogue(stateDialog);
		break;
	default:
		break;
	}
}

void NPCsDialogues::momController(int& stateDialog)
{
	std::string keyDialog = "Mom_D" + std::to_string(stateDialog);
	
	if (stateDialog == 1 || stateDialog == 2)
	{
		dialogueFormat(keyDialog, NPCType::MOM);
		stateDialog++;
	}
	else if (stateDialog == 3)
	{
		dialogueFormat(keyDialog, NPCType::MOM);
		
		keyDialog = "Mom_D" + std::to_string(stateDialog+1);
		
		dialogueFormat(keyDialog, NPCType::MOM);
	}
}

void NPCsDialogues::brotherController(int& stateDialog)
{
	std::string keyDialog = "Brother_D" + std::to_string(stateDialog);

	dialogueFormat(keyDialog, NPCType::BROTHER);
}

void NPCsDialogues::strangerDialogue(int& stateDialog)
{
	std::string keyDialog = "Stranger_D" + std::to_string(stateDialog);

	if (stateDialog == 1)
	{
		dialogueFormat(keyDialog, NPCType::STRANGER);
		keyDialog = "Stranger_D" + std::to_string(stateDialog + 1);
		dialogueFormat(keyDialog, NPCType::STRANGER);
		keyDialog = "Stranger_D" + std::to_string(stateDialog + 2);
		dialogueFormat(keyDialog, NPCType::STRANGER);

		stateDialog += 3;
	}
	else if (stateDialog == 4)
	{   
		//TODO: check additional dialogues if player has specific objects in inventory
		dialogueFormat(keyDialog, NPCType::STRANGER);
		
	}
	else if (stateDialog == 7)
	{
		dialogueFormat(keyDialog, NPCType::STRANGER);
		keyDialog = "Stranger_D" + std::to_string(stateDialog + 1);
		dialogueFormat(keyDialog, NPCType::STRANGER);
		stateDialog++;
	}
	else {
		dialogueFormat(keyDialog, NPCType::STRANGER);
	}
		
}

void NPCsDialogues::dialogueFormat(const std::string& keyDialog, NPCType npcType)
{
	std::string npcName;

	if (npcType == NPCType::MOM) {
		npcName = "Mom: ";
	}
	else if (npcType == NPCType::BROTHER){
		npcName = "Matias: ";
	}
	else if (npcType == NPCType::STRANGER) {
		npcName = "Stranger: ";
	}
	else {
		std::cout << "There is no dialog defined for any other NPC." << std::endl;
		return;
	}

	std::cout << npcName + allDialogues[keyDialog] << std::endl;	
}	