#pragma once
#include "cocos2d.h"

using namespace cocos2d;


// 游戏场景背景层的基类 [2/27/2016 aha19]

class BaseBKLayer : public Layer {
public:

	BaseBKLayer();

	~BaseBKLayer();

	virtual bool init();

	CREATE_FUNC(BaseBKLayer);

protected:
	TMXTiledMap* map;
};