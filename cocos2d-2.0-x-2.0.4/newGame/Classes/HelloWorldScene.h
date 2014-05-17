#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
//#include "Tools.h"

#include "Box2D/Box2D.h"

#include "SimpleAudioEngine.h"
using namespace cocos2d;

class HelloWorld : public cocos2d::CCLayer
{
public:
    virtual bool init();  
    static cocos2d::CCScene* scene();
	virtual void LJCallback(CCObject* pSender);  
	virtual void CXCallback(CCObject* pSender);  
	virtual void BJCallback(CCObject* pSender);  
	virtual void Initback(CCObject* pSender);  
	virtual void GZCallback(CCObject* pSender);  
	virtual void JDCallback(CCObject* pSender);  
	virtual void onExit();  


private:
	cocos2d::CCSprite* m_tamara;  
	cocos2d::CCProgressTimer *m_left;  
	cocos2d::CCSize s; 

	//LAYER_NODE_FUNC(HelloWorld);
	CREATE_FUNC(HelloWorld);
};


#endif  // __HELLOWORLD_SCENE_H__