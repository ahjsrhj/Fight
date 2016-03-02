#include "Entity.h"



Entity::Entity() {

}

Entity::~Entity() {

}

bool Entity::init() {
	if (!Node::init()) {
		return false;
	}

	return true;
}

cocos2d::Animation * Entity::createAnimation(const char *str, int num) {
	//»ñÈ¡»º´æÊµÀý
	SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();

	SpriteFrame *frame = nullptr;
	Vector<SpriteFrame*> frameVec;


	for (int i = 0; i < num; i++) {
		frame = frameCache->getSpriteFrameByName(StringUtils::format("%s%d.png", str, i));
		frameVec.pushBack(frame);
	}

	Animation *animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.2f);

	return animation;
}

void Entity::initActionWithFile(const char *str) {
	string data = FileUtils::getInstance()->getStringFromFile(str);
	unsigned int pos;
	ActionList actionList;
	pos = data.find_first_of("\n");
	string line = data.substr(0, pos);
	data = data.substr(pos + 1);
	while (line != "") {
		sscanf(line.c_str(), "%s %d", actionList.name, &actionList.num);
		auto action = Animate::create(this->createAnimation(actionList.name, actionList.num));
		this->actionMap.insert(actionList.name, action);

		pos = data.find_first_of("\n");
		line = data.substr(0, pos);
		data = data.substr(pos + 1);
	}

}

void Entity::runActionWithString(string str) {
	this->runAction(this->actionMap.at(str));
}

void Entity::setDirection(Direction direction) {
	this->direction = direction;

	if (this->direction == DIRECTION_LEFT) {
		this->setFlippedX(false);
	} else {
		this->setFlippedX(true);
	}
}

Direction Entity::getDirection() {
	return this->direction;
}


