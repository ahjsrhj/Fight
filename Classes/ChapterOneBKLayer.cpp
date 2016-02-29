#include "ChapterOneBKLayer.h"



ChapterOneBKLayer::ChapterOneBKLayer() {

}

ChapterOneBKLayer::~ChapterOneBKLayer() {

}

bool ChapterOneBKLayer::init() {
	if (!BaseBKLayer::init()) {
		return false;
	}

	//获取窗口数据
	this->visibleSize = Director::getInstance()->getVisibleSize();
	this->visibleOrigin = Director::getInstance()->getVisibleOrigin();


	//添加背景
	auto bk = Sprite::create("pic/Chapter1/Chapter1BK.png");
	bk->setAnchorPoint(Vec2::ZERO);
	bk->setPosition(Vec2::ZERO);
	this->addChild(bk);


	auto floorBody = PhysicsBody::createBox(Size(visibleSize.width, CHAPTER_ONE_FLOOR_HEIGHT));
	//设置刚体为静态的
	floorBody->setDynamic(false);
	//设置恢复系数为0，防止跳跃反弹
	floorBody->getShape(0)->setRestitution(0);
	auto floorNode = Node::create();
	floorNode->setPhysicsBody(floorBody);
	floorNode->setPosition(visibleSize.width / 2, CHAPTER_ONE_FLOOR_HEIGHT / 2);
	this->addChild(floorNode);


	auto player = Player::getInstance();
	player->setPosition(100, 250);
	this->addChild(player);
	player->stand();
	//player->walk();
	auto playerBody = PhysicsBody::createBox(player->getContentSize());
	playerBody->setDynamic(true);
	player->getSprite()->setPhysicsBody(playerBody);



	return true;
}
