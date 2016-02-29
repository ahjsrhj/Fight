#pragma once
#include "cocos2d.h"
#include "Entity.h"

using namespace cocos2d;

// 主角类，创建主角，控制主角动作 [2/28/2016 aha19]



class Player : public Entity {
public:
	//获取主角单例类
	static Player *getInstance();

	static void destroyInstance();

	virtual bool init();

	CREATE_FUNC(Player);

	void walk();
	
	void stand();


private:
	static Player *sharedInstance;

};
