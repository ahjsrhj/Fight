#pragma once
#include "cocos2d.h"
#include "Player.h"

using namespace cocos2d;

// ÓÎÏ·²ã£¬¿ØÖÆÓÎÏ·Âß¼­ [3/1/2016 aha19]

class GameLayer : public Layer {
public:
	virtual bool init() override;

	CREATE_FUNC(GameLayer);

	void onMoveLeft();

	void onMoveRight();

	void onStand();


private:
	Player *player;

};