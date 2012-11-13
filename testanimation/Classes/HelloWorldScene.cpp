#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "CCSpriterX.h"

using namespace cocos2d;
using namespace CocosDenshion;

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
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Thonburi", 34);

    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    // position the label on the center of the screen
    pLabel->setPosition( ccp(size.width / 2, size.height - 20) );

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition( ccp(size.width/2, size.height/2) );

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    
    // Create a label and initialize with string "Hello World".
    CCLabelTTF* pLabel1 = CCLabelTTF::create("Spriter Demo", "Arial", 24);
//    CC_BREAK_IF(! pLabel1);
    
    // Get window size and place the label upper.
    pLabel1->setPosition(ccp(size.width / 2, size.height - 50));
    
    // Add the label to HelloWorld layer as a child layer.
    this->addChild(pLabel1, 1);
    
    CCSpriterX *animator; //= CCSpriterX::create("Example.SCML");
    
//    CC_BREAK_IF(! animator);
    
//    animator->setPosition(ccp(200, 10));
//    animator->setScale(0.8f);
//    
//    this->addChild(animator, 0, 100);
//    
//    
//    animator = CCSpriterX::create("Example.SCML");
    
//    CC_BREAK_IF(! animator);
    
//    animator->setPosition(ccp(420, 160));
//    animator->setScale(0.6f);
//    animator->PlayNext();
//    
//    this->addChild(animator, 0, 110);
    
//    animator = CCSpriterX::create("Hero.SCML");
    
//    CC_BREAK_IF(! animator);
    
//    animator->setPosition(ccp(20, 10));
    
//    this->addChild(animator, 0, 200);
    
//    animator = CCSpriterX::create("Hero.SCML");
//    
////    CC_BREAK_IF(! animator);
//    
//    animator->setPosition(ccp(80, 10));
//    animator->PlayNext();
//    
//    this->addChild(animator, 0, 210);
    
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("aaa.plist");
    
    animator = CCSpriterX::create("test.scml");
    
    animator->setPosition(ccp(80, 100));
    animator->PlayNext();
    this->addChild(animator, 0, 200);
    
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    
    
    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


bool HelloWorld::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	CCSpriterX *animator = (CCSpriterX *)this->getChildByTag(200);
//    CCSize tempsize =  animator->getContentSize();
//    CCSprite* tempspr = animator->getSprite(1, 1);
//    
//    this->addChild(tempspr);

    animator->setPosition(ccp(59,29));
    animator->setanimaID(1);
    animator->setisloop(false);
//    
//	if (animator)
//		animator->PlayNext();
//    
//	animator = (CCSpriterX *)this->getChildByTag(110);
//    
//	if (animator)
//		animator->setisloop(false);
    
//	animator = (CCSpriterX *)this->getChildByTag(200);
//    
//	if (animator)
//		animator->PlayNext();
//    
//	animator = (CCSpriterX *)this->getChildByTag(210);
//    
//	if (animator)
//		animator->PlayNext();
    
    return true;
}