#include "GameLayer.h"



bool GameLayer::init() {
	if (!Layer::init()) {
		return false;
	}

	//�������
	this->player = Player::getInstance();
	this->player->setPosition(100, 230);
	this->player->stand();
	playerBody = PhysicsBody::createBox(this->player->getContentSize());
	playerBody->setDynamic(true);
	//���ø������������
	playerBody->setLinearDamping(0.0f);
	this->player->getSprite()->setPhysicsBody(playerBody);
	this->addChild(this->player);
	this->player->retain();

	return true;
}


void GameLayer::onMoveLeft() {
	player->setDirection(Direction::DIRECTION_LEFT);
	this->player->walk();
	this->playerBody->setVelocity(Vec2(100, 0));
}

void GameLayer::onMoveRight() {
	player->setDirection(Direction::DIRECTION_RIGHT);
	this->player->walk();
	this->playerBody->setVelocity(Vec2(-100, 0));

}

void GameLayer::onStand() {
	log("GameLayer::onStand");
	this->player->stand();
	this->player->getPhysicsBody()->setVelocity(Vec2::ZERO);
}
