#ifndef _LOBBY_UI_LAYER_H_2017_11_14_
#define _LOBBY_UI_LAYER_H_2017_11_14_

#include "cocos2d.h"

USING_NS_CC;

class LobbyUILayer :public Layer
{
public:
	LobbyUILayer() {};
	~LobbyUILayer() {};
	bool init();
	CREATE_FUNC(LobbyUILayer);
private:

};

#endif