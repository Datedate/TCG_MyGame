#ifndef _LOBBYSCENE_H_2017_11_13_
#define _LOBBYSCENE_H_2017_11_13_

#include "cocos2d.h"

class LobbyMainLayer;
class LobbyBackGroundLayer;
class LobbyUILayer;

USING_NS_CC;

class LobbyScene:public cocos2d::Scene
{
public:
	LobbyScene() {};
	~LobbyScene() {};
	bool init();
	CREATE_FUNC(LobbyScene);
private:
	LobbyMainLayer*		  m_mainLayer;
	LobbyBackGroundLayer* m_backLayer;
	LobbyUILayer*		  m_uiLayer;
};


#endif