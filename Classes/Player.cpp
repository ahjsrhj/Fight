#include "Player.h"


Player *Player::sharedInstance = nullptr;

Player * Player::getInstance() {
	if (sharedInstance == nullptr) {
		sharedInstance = new Player();
		if (!sharedInstance->init()) {
			delete sharedInstance;
			sharedInstance = nullptr;
			log("can't create player!");
		}
	}

	return sharedInstance;
}

void Player::destroyInstance() {
	CC_SAFE_DELETE(sharedInstance);
}

bool Player::init() {
	if (!Entity::init()) {
		return false;
	}

	auto sprite = Sprite::createWithSpriteFrameName("player_stand0.png");

	this->bindSprite(sprite);

	this->initActionWithFile("player_action.txt");

	this->setDirection(Direction::DIRECTION_RIGHT);

	return true;
}


void Player::walk() {
	this->runActionWithString("player_walk");
}

void Player::stand() {
	this->runActionWithString("player_stand");
}
