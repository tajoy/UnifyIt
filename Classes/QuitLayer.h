#ifndef __QuitLayer_h__
#define __QuitLayer_h__


#include "cocos2d.h"

class QuitLayer : public cocos2d::Layer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(QuitLayer);
};

#endif // __QuitLayer_h__
