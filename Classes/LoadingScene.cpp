#include "LoadingScene.h"



LoadingScene::LoadingScene() {

}

LoadingScene::~LoadingScene() {

}

cocos2d::Scene * LoadingScene::createScene() {
	auto scene = Scene::create();
	auto layer = LoadingScene::create();
	scene->addChild(layer);

	return scene;
}

bool LoadingScene::init() {
	if (!Layer::init()) {
		return false;
	}

	auto bg = Sprite::create("pic/LoadingSceneBK.png");
	bg->setPosition(Director::getInstance()->getVisibleSize() / 2);
	this->addChild(bg);

	return true;
}

void LoadingScene::onEnter() {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("pic/texture.plist", "pic/texture.png");

	//Ԥ������Ч  ������

	

	//֮�������Ϸ�����棬ѡ��ʼ��Ϸ ������
	auto scene = GameScene::create();
	auto transition = TransitionFade::create(2.0f, scene);
	Director::getInstance()->replaceScene(transition);
}