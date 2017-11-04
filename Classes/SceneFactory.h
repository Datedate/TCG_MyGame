#pragma once
#include "cocos2d.h"

enum SCENE {
	FIRST_LOGO,
	TITLE,
	GAME,
	RESULT
};

class SceneFactory {
public:
	static cocos2d::Scene* create();
};