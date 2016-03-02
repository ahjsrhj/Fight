#include "ControlLayer.h"

bool ControlLayer::init() {
	if (!Layer::init()) {
		return false;
	}

	//´´½¨×óÓÒ°´Å¥
	this->leftBtn = Button::create(
		"arrow_left.png", 
		"arrow_pressed.png", 
		"arrow_pressed.png",
		Widget::TextureResType::PLIST);
	this->leftBtn->setPosition(Vec2(100,100));
	this->leftBtn->addTouchEventListener(this, toucheventselector(ControlLayer::leftBtnEvent));
	this->addChild(this->leftBtn);

	this->rightBtn = Button::create(
		"arrow_right.png",
		"arrow_pressed.png",
		"arrow_pressed.png",
		Widget::TextureResType::PLIST);
	this->rightBtn->setPosition(Vec2(200, 100));
	this->rightBtn->addTouchEventListener(this, toucheventselector(ControlLayer::rightBtnEvent));
	this->addChild(this->rightBtn);


	return true;
}

void ControlLayer::bindGameLayer(GameLayer *gameLayer) {
	this->gameLayer = gameLayer;
}

void ControlLayer::leftBtnEvent(Ref *pSender, TouchEventType type) {
	switch (type) {
	case TouchEventType::TOUCH_EVENT_BEGAN:
		this->gameLayer->onMoveLeft();
		break;;
	case TouchEventType::TOUCH_EVENT_ENDED:
	case TouchEventType::TOUCH_EVENT_CANCELED:
		this->gameLayer->onStand();
		break;
		
	default:
		break;
	}
}

void ControlLayer::rightBtnEvent(Ref *pSender, TouchEventType type) {
	switch (type) {
	case TouchEventType::TOUCH_EVENT_BEGAN:
		this->gameLayer->onMoveRight();
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:
	case TouchEventType::TOUCH_EVENT_CANCELED:
		this->gameLayer->onStand();
		break;
		
	default:
		break;
	}
}

