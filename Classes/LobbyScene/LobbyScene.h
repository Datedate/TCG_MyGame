#ifndef _LOBBYSCENE_H_2017_11_13_
#define _LOBBYSCENE_H_2017_11_13_

#include "cocos2d.h"

class LobbyScene:public cocos2d::Scene
{
public:
	LobbyScene() {};
	~LobbyScene() {};
	bool init();
	CREATE_FUNC(LobbyScene);
private:

};


#endif