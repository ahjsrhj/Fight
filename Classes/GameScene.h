#pragma once
#include "cocos2d.h"
#include "ChapterOneBKLayer.h"
#include "GameLayer.h"
#include "ControlLayer.h"

// ”Œœ∑≥°æ∞¿‡ [2/27/2016 aha19]

using namespace cocos2d;

class GameScene : public Scene {
public:
	GameScene();

	~GameScene();

	virtual bool init();

	CREATE_FUNC(GameScene);
};