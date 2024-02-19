#include "World.h"
#include "Global.h"
#include "Player.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include "NPC.h"
#include "NPCsDialogues.h"


World::World()
{
	isGameOver = false;
	setupGame();
	
}

void World::setupGame()
{
	Room* bedroom = new Room("Bedroom", "This is my bedroom.");
	Room* livingRoom = new Room("Living Room", "This is my big living room.");
	Room* bathroom = new Room("Bathroom", "This is my beloved bathroom.");
	Room* mother_bedroom = new Room("Mom's bedroom", "Always very tidy and clean. My mother doesn't want us to be around here, so it's better to not touch anything.");
	Room* brother_bedroom = new Room("Matias's Bedroom", "The bedroom of my brother. Everything is on the floor as usual...");
	Room* house_entrance = new Room("Front entrance", "The front entrance. Very colorful with all kinds of flowers surrounding the entrance.");
	Room* kitchen = new Room("Kitchen", "My paradise. In here it is cooked the best meals I've ever tasted.");
	Room* hallway = new Room("Hallway", "In here there is the access to another bathroom and Matias's bedroom.");

	entities.push_back(bedroom);
	entities.push_back(livingRoom);
	entities.push_back(bathroom);
	entities.push_back(mother_bedroom);
	entities.push_back(brother_bedroom);
	entities.push_back(house_entrance);
	entities.push_back(kitchen);


	Exit* exitBedroom = new Exit(nameCommand.SOUTH_1, "Bedroom door", "This door comunicates my bedroom with the living room.", bedroom, livingRoom,true);
	Exit* exitBathroom = new Exit(nameCommand.NORTH_1, "Bathroom door", "This door communicates the hallway with the bathroom.", hallway, bathroom);
	Exit* exitMatiasBedroom = new Exit(nameCommand.WEST_1, "Matias bedroom", "This door communicates my bedroom with the bathroom.", hallway, brother_bedroom);
	Exit* exitHallway = new Exit(nameCommand.EAST_1, "Hallway door", "This door communicates my the living room with the hallway.", hallway, livingRoom);
	Exit* exitKitchen = new Exit(nameCommand.WEST_1, "Kitchen access", "This access communicates the kitchen with the living room.", kitchen, livingRoom);
	Exit* exitEntranceHouse = new Exit(nameCommand.SOUTH_1, "House entrance", "The door entrance of my house.", livingRoom, house_entrance);
	Exit* exitMomBedroom = new Exit(nameCommand.UP_1, "Mom's door", "This door communicates my mother's bedroom with the stairs in the living room.", livingRoom, mother_bedroom);

	entities.push_back(exitBedroom);
	entities.push_back(exitBathroom);
	entities.push_back(exitMatiasBedroom);
	entities.push_back(exitHallway);
	entities.push_back(exitKitchen);
	entities.push_back(exitEntranceHouse);
	entities.push_back(exitMomBedroom);
	

	Item* photo = new Item("Photo", "This is a memory of my family going to the mountains.", bedroom, false);
	Item* bottle = new Item("Bottle", "I use this bottle for drinking outside home.", livingRoom,false);
	Item* backpack = new Item("Backpack", "My favourite backpack. It's a little worn.", bedroom, true);
	Item* keyBedroom = new Item("KeyBed", "This is the key to open and close my bedroom", bedroom, false, exitBedroom);

	entities.push_back(photo);
	entities.push_back(bottle);
	entities.push_back(backpack);
	entities.push_back(keyBedroom);

	player = new Player("Marc", "The player of this game", bedroom);

	entities.push_back(player);

	NPC* mother = new NPC("Mom", "There is my mother, lying on the sofa.", livingRoom,NPCType::MOM);
	NPC* brother = new NPC("Matias", "There is my annoying brother, still sleeping...", brother_bedroom, NPCType::BROTHER);
	NPC* stranger = new NPC("Stranger", "There is someone tied at the corner of the bed. One of Mom's adventures? Disgusting ...", mother_bedroom, NPCType::STRANGER);
	
	entities.push_back(mother);
	entities.push_back(brother);
	entities.push_back(stranger);

	NPCsDialogues* allDialoguesNPCs = new NPCsDialogues(mother, brother, stranger); //REMINDER: free up memory in destructor
	allDialogues = allDialoguesNPCs;
}

bool World::parseUserCommand(std::vector<std::string>& arguments)
{
	std::string command = arguments[0];
	bool isParseOK = true;

	switch (arguments.size())
	{
	case 1: 
		isParseOK = handleOnlyCommand(command);
		break;
	case 2: 
		isParseOK = handleOneArgument(arguments);
		break;
	case 3:
		isParseOK = handleTwoArguments(arguments);
		break;
	case 4: 
		isParseOK = handleThreeArguments(arguments);
		break;
	default:
		isParseOK = false;
		break;
	}

	return isParseOK;
}

bool World::handleOnlyCommand(const std::string& command)
{
	bool handleOK = true;

	if(command == nameCommand.NORTH_1 || command == nameCommand.NORTH_2)
	{
		player->go(nameCommand.NORTH_1);
	}
	else if (command == nameCommand.SOUTH_1 || command == nameCommand.SOUTH_2)
	{
		player->go(nameCommand.SOUTH_1);
	}
	else if (command == nameCommand.EAST_1 || command == nameCommand.EAST_2)
	{
		player->go(nameCommand.EAST_1);
	}
	else if (command == nameCommand.WEST_1 || command == nameCommand.WEST_2)
	{
		player->go(nameCommand.WEST_1);
	}
	else if (command == nameCommand.UP_1 || command == nameCommand.UP_2)
	{
		player->go(nameCommand.UP_1);
	}
	else if (command == nameCommand.DOWN_1 || command == nameCommand.DOWN_2)
	{
		player->go(nameCommand.DOWN_1);
	}
	else if (command == nameCommand.LOOK_1 || command == nameCommand.LOOK_2)
	{
		player->look();
	}
	else if (command == nameCommand.INVENTORY_1 || command == nameCommand.INVENTORY_2)
	{
		player->inventory();
	}
	else if (command == nameCommand.QUIT_1 || command == nameCommand.QUIT_2)
	{
		checkGameOver();
	}
	else
	{
		handleOK = false;
	}

	return handleOK;
}

bool World::handleOneArgument(std::vector<std::string>& arguments)
{
	bool handleOK = true;

	if (arguments[0] == nameCommand.TAKE)
	{
		player->take(arguments[1]);
	}
	else if (arguments[0] == nameCommand.DROP)
	{
		player->drop(arguments[1]);
	}
	else if (arguments[0] == nameCommand.OPEN)
	{
		player->open(arguments[1]);
	}
	else
	{
		handleOK = false;
	}

	return handleOK;
}

bool World::handleTwoArguments(std::vector<std::string>& arguments)
{
	bool handleOK = true;
	
	if (arguments[0] == nameCommand.OPEN)
	{
		player->open(arguments);
	}
	else {
		handleOK = false;
	}

	return handleOK;
}


bool World::handleThreeArguments(std::vector<std::string>& arguments)
{
	bool handleOK = true;

	if (arguments[0] == nameCommand.PUT && arguments[2] == nameCommand.IN)
	{
		player->put(arguments);
	}
	else if (arguments[0] == nameCommand.TAKE && arguments[2] == nameCommand.FROM)
	{
		player->take(arguments);
	}
	else
	{
		handleOK = false;
	}

	return handleOK;
}

void World::checkGameOver()
{
	isGameOver = true;
	std::cout << "GAME OVER" << std::endl;
}

void World::printCurrentRoom() const
{
	std::cout << player->location->name << std::endl;
}

void World::checkFirstTimeRoom()
{
	if (player->location->firstTime)
	{
		std::cout << "\n";
		player->look();
		std::cout << "\n";

		player->location->seeFirstTime();
	}
}