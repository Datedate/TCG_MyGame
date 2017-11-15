#ifndef _LOBBY_MAIN_LAYER_H_2017_11_14_
#define _LOBBY_MAIN_LAYER_H_2017_11_14_

#include "cocos2d.h"
#include <string>

USING_NS_CC;

class LobbyMainLayer:public Layer
{
public:
	enum class STATUS
	{
		PLAY,
		DECK,
		RANKING,
		COUNT_MAX
	};
public:
	LobbyMainLayer() {};
	~LobbyMainLayer() {};
	bool init();
	CREATE_FUNC(LobbyMainLayer);
private:
	void OnEventEnter(const std::string _name , const std::string* _nameList);
private:
	Vector<Sprite*>		m_spriteContainer;
	const std::string name[3] = {
		"play","deck","ranking"
	};
};

#endif
