#pragma once
#include "cocos2d.h"
#include "GameLayer.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;
using namespace ui;

// ��Ϸ���Ʋ㣬�����û����� [3/1/2016 aha19]

class ControlLayer : public Layer {
public:
	virtual bool init() override;
	
	CREATE_FUNC(ControlLayer);


	//������Ϸ��ʵ��
	void bindGameLayer(GameLayer *gameLayer);

	
private:
	void leftBtnEvent(Ref *pSender, TouchEventType type);

	void rightBtnEvent(Ref *pSender, TouchEventType type);


private:
	GameLayer *gameLayer;

	Button *leftBtn;
	Button *rightBtn;

};


