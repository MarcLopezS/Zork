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
		std::cout << "Mom: " + allDialogues[keyDialog] << std::endl;
		stateDialog++;
	}
	else if (stateDialog == 3)
	{
		std::cout << "Mom: " + allDialogues[keyDialog] << std::endl;
		
		keyDialog = "Mom_D" + std::to_string(stateDialog+1);
		
		std::cout << "Mom: " + allDialogues[keyDialog] << std::endl;
	}
}

void NPCsDialogues::brotherController(int& stateDialog)
{
	std::string keyDialog = "Brother_D" + std::to_string(stateDialog);

	std::cout << "Matias: " + allDialogues[keyDialog] << std::endl;
}