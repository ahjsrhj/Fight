#pragma once
#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

// ���Ǻ͹�����Ļ��� [2/27/2016 aha19]


typedef enum {
	DIRECTION_LEFT,
	DIRECTION_RIGHT
} Direction;

typedef struct {
	char name[100];
	int num;
} ActionList;

class Entity : public Node {
public:
	Entity();
	~Entity();

	virtual bool init();

	CREATE_FUNC(Entity);

	//************************************
	// Method:    bindSprite
	// FullName:  Entity::bindSprite
	// Access:    public 
	// Returns:   void
	// Qualifier: ���Ӷ��󴴽���sprite����󶨵���Ա����sprite��
	// Parameter: Sprite * sprite
	//************************************
	void bindSprite(Sprite *sprite);

	//************************************
	// Method:    initActionWithFile
	// FullName:  Entity::initActionWithFile
	// Access:    public 
	// Returns:   void
	// Qualifier: �����ļ��а����Ķ����б�����ʼ����������ʽ���£�
	//			player_stand 4
	// Parameter: const char * str
	//************************************
	void initActionWithFile(const char *str);

	
	void runActionWithString(string str);

	void setDirection(Direction direction);

	Direction getDirection();

	virtual const Size& getContentSize() const override;

	Sprite *getSprite();

private:
	//************************************
	// Method:    createAnimation
	// FullName:  Entity::createAnimation
	// Access:    public 
	// Returns:   cocos2d::Animation *
	// Qualifier: ���ݴ����str�Լ�num����animation����
	// Parameter: const char * str
	// Parameter: int num
	//exm str = "player_stand%d.png", num = 4
	//************************************
	Animation *createAnimation(const char *str, int num);


private:
	Sprite *sprite;

	Map<string, Animate*> actionMap;

	Direction direction;

};