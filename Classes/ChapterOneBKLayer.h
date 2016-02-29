#pragma once
#include "cocos2d.h"
#include "BaseBKLayer.h"
#include "Player.h"

using namespace cocos2d;


// �ؿ�һ�ı���ͼ�㣬�������ر���ͼ�Լ�TMX��ͼ [2/27/2016 aha19]

const int CHAPTER_ONE_FLOOR_HEIGHT = 190;



class ChapterOneBKLayer : public BaseBKLayer {
public:
	ChapterOneBKLayer();

	~ChapterOneBKLayer();

	virtual bool init();

	CREATE_FUNC(ChapterOneBKLayer);

private:
	Size visibleSize;
	Vec2 visibleOrigin;
};