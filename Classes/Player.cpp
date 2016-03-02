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

	if (Sprite::initWithSpriteFrameName("player_stand0.png")) {
		this->initActionWithFile("player_action.txt");

		this->setDirection(Direction::DIRECTION_RIGHT);
	}

	return true;
}


void Player::walk() {
	this->stopAllActions();
	this->runActionWithString("player_walk");
}

void Player::stand() {
	this->stopAllActions();
	this->runActionWithString("player_stand");
}
