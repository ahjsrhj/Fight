#pragma once
#include "cocos2d.h"
#include "GameScene.h"

using namespace cocos2d;

// 加载界面，在此界面进行游戏资源文件的预加载 [2/28/2016 aha19]

class LoadingScene : public Layer {
public:

	LoadingScene();

	~LoadingScene();

	static Scene *createScene();

	virtual bool init() override;

	virtual void onEnter() override;

	CREATE_FUNC(LoadingScene);
};