#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace std;

#define TILES_WIDTH 4
#define TILES_HEIGHT 6

Scene * GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild( layer );

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto rootNode = CSLoader::createNode( "GameScene.csb" );

    addChild( rootNode );


    auto winSize = CCDirector::getInstance()->getWinSize();


    m_vColors.clear();
    m_vColors.push_back(
        Color4B( 0x00, 0x00, 0x00, 0xFF )
    );
    m_vColors.push_back(
        Color4B( 0xFF, 0xFF, 0xFF, 0xFF )
    );
    m_nLevelNow = 0;

    m_pLayerContainer = Layer::create();
    this->addChild( m_pLayerContainer );

    this->updateColors( TILES_WIDTH, TILES_HEIGHT );

    std::function<void()> callback = [&]()
    {
        this->levelUP();
    };

    this->runAction(
        RepeatForever::create(
            Sequence::create(
                DelayTime::create( 3.0f ),
                CallFunc::create( callback ),
                NULL
            )
        )
    );


    return true;
}

void GameScene::levelUP()
{
    m_nLevelNow++;
    this->insertMoreColors();
    this->updateColors( TILES_WIDTH, TILES_HEIGHT );
}

void GameScene::insertColor( std::vector<cocos2d::Color4B> & colors, Color4B cr0, Color4B cr1 )
{
    colors.push_back(
        Color4B(
            ( cr0.r + cr1.r / 2 ),
            cr0.g,
            cr0.b,
            0xFF
        )
    );

    colors.push_back(
        Color4B(
            cr0.r,
            ( cr0.g + cr1.g / 2 ),
            cr0.b,
            0xFF
        )
    );

    colors.push_back(
        Color4B(
            cr0.r,
            cr0.g,
            ( cr0.b + cr1.b / 2 ),
            0xFF
        )
    );
}


void GameScene::insertMoreColors()
{
    std::vector<cocos2d::Color4B> tempColors;
    tempColors.clear();
    tempColors.swap( m_vColors );

    for ( int i = 0; i < tempColors.size() - 1; i++ )
    {
        auto cr0 = tempColors[i];
        auto cr1 = tempColors[i + 1];
        m_vColors.push_back( cr0 );
        this->insertColor( m_vColors, cr0, cr1 );
        m_vColors.push_back( cr1 );
    }
}

void GameScene::updateColors( int width, int height )
{
    auto winSize = CCDirector::getInstance()->getWinSize();

    m_pLayerContainer->removeAllChildren();

    m_mmTiles.clear();
    m_mmCounter.clear();


    for ( int i = 0; i < width; i++ )
    {
        m_mmTiles[i] = map<int, LayerColor *>();
        m_mmCounter[i] = map<int, int>();

        for ( int j = 0; j < height; j++ )
        {
            m_mmCounter[i][j] = rand() % m_vColors.size();


            auto pLayer = LayerColor::create();
            pLayer->initWithColor(
                m_vColors[m_mmCounter[i][j]]
            );

            pLayer->setContentSize(
                CCSizeMake(
                    winSize.width / width,
                    winSize.height / height
                )
            );
            pLayer->setPosition(
                ccp(
                    i * winSize.width / width,
                    j * winSize.height / height
                )
            );

            m_mmTiles[i][j] = pLayer;
            m_pLayerContainer->addChild( pLayer );
        }
    }
}

void GameScene::onColorClicked( int x, int y, cocos2d::LayerColor * pLayer )
{
    //TODO: Code GameScene::onColorClicked

}
