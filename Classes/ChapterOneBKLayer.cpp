#include "ChapterOneBKLayer.h"



ChapterOneBKLayer::ChapterOneBKLayer() {

}

ChapterOneBKLayer::~ChapterOneBKLayer() {

}

bool ChapterOneBKLayer::init() {
	if (!BaseBKLayer::init()) {
		return false;
	}

	//��ȡ��������
	this->visibleSize = Director::getInstance()->getVisibleSize();
	this->visibleOrigin = Director::getInstance()->getVisibleOrigin();


	//��ӱ���
	auto bk = Sprite::create("pic/Chapter1/Chapter1BK.png");
	bk->setAnchorPoint(Vec2::ZERO);
	bk->setPosition(Vec2::ZERO);
	this->addChild(bk);


	auto floorBody = PhysicsBody::createBox(Size(visibleSize.width, CHAPTER_ONE_FLOOR_HEIGHT),PhysicsMaterial(0,0,0));
	//���ø���Ϊ��̬��
	floorBody->setDynamic(false);
	auto floorNode = Node::create();
	floorNode->setPhysicsBody(floorBody);
	floorNode->setPosition(visibleSize.width / 2, CHAPTER_ONE_FLOOR_HEIGHT / 2);
	this->addChild(floorNode);



	return true;
}
