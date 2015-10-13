#include "MainScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MainScene::createScene()
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
  if ( !Layer::init() ) {
    return false;
  }
  if ( !EventListenerKeyboard::init() ) {
    return false;
  }

  auto rootNode = CSLoader::createNode( "MainScene.csb" );

  addChild( rootNode );

  this->getEventDispatcher()->addEventListener( this );
  this->onKeyPressed = [](
                         EventKeyboard::KeyCode keyCode,
                         Event * pEvent
  ) {

    CCLOG( "call: %s -> keyCode: %d, event:%d",
           "onKeyPressed",
           keyCode,
           pEvent ? ( int )pEvent->getType() : 0
         );
  };

  this->onKeyReleased = [](
                          EventKeyboard::KeyCode keyCode,
                          Event * pEvent
  ) {

    CCLOG( "call: %s -> keyCode: %d, event:%d",
           "onKeyReleased",
           keyCode,
           pEvent ? ( int )pEvent->getType() : 0
         );
  };

  return true;
}

MainScene* MainScene::create()
{
  MainScene *pRet = new( std::nothrow ) MainScene();
  if ( pRet && pRet->MainScene::init() ) {
    pRet->autorelease();
    return pRet;
  } else {
    delete pRet;
    pRet = NULL;
    return NULL;
  }
}
