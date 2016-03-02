#include "GameLayer.h"



bool GameLayer::init() {
	if (!Layer::init()) {
		return false;
	}

	//�������
	this->player = Player::getInstance();
	this->player->setPosition(1000, 230);
	this->player->stand();
	auto playerBody = PhysicsBody::createBox(this->player->getContentSize(), PhysicsMaterial(0,0,0));
	playerBody->setDynamic(true);
	//���ø������������
	playerBody->setLinearDamping(0.0f);
	//playerBody->setVelocity(Vec2(1000, 0));


	//���ø���Ļָ�ϵ��
	playerBody->getShape(0)->setRestitution(0.0f);
	this->player->setPhysicsBody(playerBody);
	this->addChild(this->player);
	log("VelocityLimit %f", playerBody->getVelocityLimit());

	return true;
}


void GameLayer::onMoveLeft() {
	player->setDirection(Direction::DIRECTION_LEFT);
	this->player->walk();

}

void GameLayer::onMoveRight() {
	player->setDirection(Direction::DIRECTION_RIGHT);
	this->player->walk();

}

void GameLayer::onStand() {
	log("GameLayer::onStand");
	this->player->stand();
	auto velocity = this->player->getPhysicsBody()->getVelocity();
	this->player->getPhysicsBody()->setVelocity(Vec2(0, velocity.y));
}
