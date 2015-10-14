#ifndef __GameScene_h__
#define __GameScene_h__


#include "cocos2d.h"


#include <map>
#include <vector>

class GameScene : public cocos2d::Layer {
    public:
        // there's no 'id' in cpp, so we recommend returning the class instance pointer
        static cocos2d::Scene * createScene();

        // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
        virtual bool init();

        // implement the "static create()" method manually
        CREATE_FUNC( GameScene );


        void levelUP();
        void insertMoreColors();
        void updateColors( int width, int height );


    private:

        void insertColor(
            std::vector<cocos2d::Color4B> & colors,
			cocos2d::Color4B cr0,
			cocos2d::Color4B cr1
        );

        void onColorClicked(
            int x,
            int y,
            cocos2d::LayerColor * pLayer
        );




        std::map<int, std::map<int, int>> m_mmCounter;

        std::map<int, std::map<int, cocos2d::LayerColor *>> m_mmTiles;
        cocos2d::Layer * m_pLayerContainer;



        std::vector<cocos2d::Color4B> m_vColors;
        int m_nLevelNow;
};

#endif // __GameScene_h__
