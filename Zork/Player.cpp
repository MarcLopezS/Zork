#include "Player.h"

Player::Player(const std::string& namePlayer, const std::string descriptPlayer, Room* locationPlayer)
	:Creature(namePlayer, descriptPlayer, locationPlayer)
{
	type = EntityType::PLAYER;
}

Player::~Player()
{
}

bool Player::Go(const std::string& userCommand)
{
	//TODO: implement go method
}
