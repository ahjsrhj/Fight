#include "GameScene.h"



GameScene::GameScene() {

}

GameScene::~GameScene() {

}

bool GameScene::init() {
	if (Scene::initWithPhysics()) {
		this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
		this->getPhysicsWorld()->setGravity(Vec2(0, -980));
		auto bkLayer = ChapterOneBKLayer::create();
		this->addChild(bkLayer);

		auto gameLayer = GameLayer::create();
		this->addChild(gameLayer);

		auto controlLayer = ControlLayer::create();
		controlLayer->bindGameLayer(gameLayer);
		this->addChild(controlLayer);

		return true;
	} else {
		return false;
	}

}
