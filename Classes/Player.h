#pragma once
#include "cocos2d.h"
#include "Entity.h"

using namespace cocos2d;

// �����࣬�������ǣ��������Ƕ��� [2/28/2016 aha19]



class Player : public Entity {
public:
	//��ȡ���ǵ�����
	static Player *getInstance();

	static void destroyInstance();

	virtual bool init();

	CREATE_FUNC(Player);

	void walk();
	
	void stand();


private:
	static Player *sharedInstance;

};
