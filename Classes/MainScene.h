#ifndef __MainScene_h__
#define __MainScene_h__


#include "cocos2d.h"

class MainScene
  : public cocos2d::Layer
  , public cocos2d::EventListenerKeyboard
{
public:
  // there's no 'id' in cpp, so we recommend returning the class instance pointer
  static cocos2d::Scene* createScene();

  // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
  virtual bool init();

  // implement the "static create()" method manually
  static MainScene* create();


};

#endif // __MainScene_h__
