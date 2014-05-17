#pragma once
#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "SimpleAudioEngine.h"

class SplashScene : public cocos2d::CCLayer
{
public:

	static cocos2d::CCScene* scene();

	virtual bool init();

	void menuCloseCallback(CCObject* ssender);
	CREATE_FUNC(SplashScene);
};
