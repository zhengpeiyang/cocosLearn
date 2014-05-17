#include "SplashScene.h"

using namespace cocos2d;


CCScene* SplashScene::scene()
{
	CCScene* scene = NULL;
	do 
	{
		scene = CCScene::create();
		CC_BREAK_IF(!scene);
		
		CCLayer* layer = SplashScene::create();
		CC_BREAK_IF(! layer);

		scene->addChild(layer);

	} while (0);
	return scene;
}

bool SplashScene::init()
{
	bool bset = false;
	
//	CC_BREAK_IF(! CCLayer::init);

	do 
	{
		CCLayer::init();
		CCLog("===========================1");
		CCMenuItemImage* pcloseItem = CCMenuItemImage::create(
			"CloseNormal.png",
			"CloseSelected.png",
			this,menu_selector(SplashScene::menuCloseCallback));

		CC_BREAK_IF(!pcloseItem);
		pcloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width-20,CCDirector::sharedDirector()->getWinSize().height-20));

		CCMenu* menu = CCMenu::create(pcloseItem,NULL);
		menu->setPosition(CCPointZero);
		CC_BREAK_IF(!menu);

		CCLabelTTF* label = CCLabelTTF::create("Hello World!","UTF-8",24);
		label->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2,CCDirector::sharedDirector()->getWinSize().height-40));
		CC_BREAK_IF(!label);

		CCSprite* sprite = CCSprite::create("HelloWorld.png");
		sprite->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2,CCDirector::sharedDirector()->getWinSize().height/2));
		CC_BREAK_IF(!sprite);

		this->addChild(sprite,0);
		this->addChild(label,1);
		this->addChild(menu);
		bset = true;
	} while (0);

	return bset;

}

void SplashScene::menuCloseCallback(CCObject* ssender)
{
	CCDirector* director = CCDirector::sharedDirector();
	director->end();
}