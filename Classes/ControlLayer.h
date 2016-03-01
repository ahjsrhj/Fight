#pragma once
#include "cocos2d.h"
#include "GameLayer.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;
using namespace ui;

// 游戏控制层，处理用户输入 [3/1/2016 aha19]

class ControlLayer : public Layer {
public:
	virtual bool init() override;
	
	CREATE_FUNC(ControlLayer);


	//保存游戏层实例
	void bindGameLayer(GameLayer *gameLayer);

	
private:
	void leftBtnEvent(Ref *pSender, TouchEventType type);

	void rightBtnEvent(Ref *pSender, TouchEventType type);


private:
	GameLayer *gameLayer;

	Button *leftBtn;
	Button *rightBtn;

};


