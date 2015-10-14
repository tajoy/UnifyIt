#include "MainScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene * MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = MainScene::create();

    // add layer as a child to scene
    scene->addChild( layer );

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto rootNode = CSLoader::createNode( "MainScene.csb" );

    addChild( rootNode );


    this->m_pListener = EventListenerKeyboard::create();

    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority( this->m_pListener, this );
    this->setKeypadEnabled( true );
	this->setKeyboardEnabled(true);
    this->m_pListener->onKeyPressed =
        [](
            EventKeyboard::KeyCode keyCode,
            Event * pEvent
        )
    {
    };

    this->m_pListener->onKeyReleased =
        [](
            EventKeyboard::KeyCode keyCode,
            Event * pEvent
        )
    {
        if ( keyCode == EventKeyboard::KeyCode::KEY_ESCAPE )
        {
            CCDirector::getInstance()->end();
        }
    };

    return true;
}

MainScene * MainScene::create()
{
    MainScene * pRet = new( std::nothrow ) MainScene();

    if ( pRet && pRet->init() )
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}
