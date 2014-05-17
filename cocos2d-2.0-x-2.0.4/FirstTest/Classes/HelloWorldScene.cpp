#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

#include <android/log.h>

#define  LOG_TAG    "world"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

using namespace cocos2d;
using namespace CocosDenshion;

void CTestSprite::draw(void)
{
	cocos2d::ccColor4F color = {0.0f, 1.0f, 0.0f, 1.0f};
	cocos2d::ccDrawSolidRect(ccp(0, 0), ccp(20, 20), color);
}

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    //CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Thonburi", 34);

    // ask director the window size
    //CCSize size = CCDirector::sharedDirector()->getWinSize();

    // position the label on the center of the screen
    //pLabel->setPosition( ccp(size.width / 2, size.height - 20) );

    // add the label as a child to this layer
    //this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    //CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    //pSprite->setPosition( ccp(size.width/2, size.height/2) );

    // add the sprite as a child to this layer
    //this->addChild(pSprite, 0);

	this->schedule( schedule_selector(HelloWorld::updateGame), 1.0 );
	this->setTouchEnabled(true);

	pSprite = new CTestSprite();
	pSprite->setPosition( ccp(100, CCDirector::sharedDirector()->getWinSize().height/2) );
	this->addChild(pSprite);

    return true;
}

void HelloWorld::draw()
{
	//ccColor4F color = {0.0f, 1.0f, 0.0f, 1.0f};
	//ccDrawSolidRect(ccp(50, 50), ccp(300, 300), color);
	
//	ccDrawColor4F(0.0, 1.0, 0.0, 1.0);
//	ccDrawPoint(ccp(100, 100));
//	ccDrawPoint(ccp(101, 100));
//	ccDrawPoint(ccp(102, 100));
//	ccDrawPoint(ccp(103, 100));
//	ccDrawPoint(ccp(104, 100));
//	ccDrawPoint(ccp(105, 100));

	//if (pSprite)
	//	pSprite->draw();
}

void HelloWorld::updateGame(cocos2d::CCTime dt)
{
	LOGD("pos x : %f\n", pSprite->getPositionX());
	LOGD("pos y : %f\n", pSprite->getPositionY());
}

void HelloWorld::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
	// Choose one of the touches to work with
	CCTouch* touch = (CCTouch*)( touches->anyObject() );
	CCPoint location = touch->getLocation();
	
	// Set up initial location of projectile
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	// Determinie offset of location to projectile
	float offX = location.x - pSprite->getPosition().x;
	float offY = location.y - pSprite->getPosition().y;

	// Bail out if we are shooting down or backwards
	if (offX <= 0) return;

	// Determine where we wish to shoot the projectile to
	float realX = winSize.width + (pSprite->getContentSize().width/2);
	float ratio = offY / offX;
	float realY = (realX * ratio) + pSprite->getPosition().y;
	CCPoint realDest = ccp(realX, realY);

	// Determine the length of how far we're shooting
	float offRealX = realX - pSprite->getPosition().x;
	float offRealY = realY - pSprite->getPosition().y;
	float length = sqrtf((offRealX * offRealX) + (offRealY*offRealY));
	float velocity = 240/1; // 480pixels/1sec
	float realMoveDuration = length/velocity;

	// Move projectile to actual endpoint
	pSprite->runAction( CCSequence::actions(
		CCMoveTo::actionWithDuration(realMoveDuration, realDest),
		CCCallFuncN::actionWithTarget(this, 

		callfuncN_selector(HelloWorld::spriteMoveFinished)), 
		NULL) );
}

void HelloWorld::spriteMoveFinished(CCNode* sender)
{

	pSprite->setPosition( ccp(100, CCDirector::sharedDirector()->getWinSize().height/2) );
	
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

HelloWorld::HelloWorld()
	: cocos2d::CCLayer()
	, pSprite(NULL)
{

}
