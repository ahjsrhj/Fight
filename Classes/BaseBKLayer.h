#pragma once
#include "cocos2d.h"

using namespace cocos2d;


// ��Ϸ����������Ļ��� [2/27/2016 aha19]

class BaseBKLayer : public Layer {
public:

	BaseBKLayer();

	~BaseBKLayer();

	virtual bool init();

	CREATE_FUNC(BaseBKLayer);

protected:
	TMXTiledMap* map;
};