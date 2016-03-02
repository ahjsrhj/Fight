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


	auto floorBody = PhysicsBody::createBox(Size(visibleSize.width, CHAPTER_ONE_FLOOR_HEIGHT),PhysicsMaterial(0,0,0));
	//设置刚体为静态的
	floorBody->setDynamic(false);
	auto floorNode = Node::create();
	floorNode->setPhysicsBody(floorBody);
	floorNode->setPosition(visibleSize.width / 2, CHAPTER_ONE_FLOOR_HEIGHT / 2);
	this->addChild(floorNode);



	return true;
}
