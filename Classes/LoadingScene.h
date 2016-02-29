#pragma once
#include "cocos2d.h"
#include "GameScene.h"

using namespace cocos2d;

// ���ؽ��棬�ڴ˽��������Ϸ��Դ�ļ���Ԥ���� [2/28/2016 aha19]

class LoadingScene : public Layer {
public:

	LoadingScene();

	~LoadingScene();

	static Scene *createScene();

	virtual bool init() override;

	virtual void onEnter() override;

	CREATE_FUNC(LoadingScene);
};