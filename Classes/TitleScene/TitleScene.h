#ifndef _TITLESCENE_H_2017_11_11_
#define _TITLESCENE_H_2017_11_11_

#include "cocos2d.h"

class TitleUILayer;

class TitleScene : public cocos2d::Scene
{
public:
	TitleScene() {};
	~TitleScene() {};
	bool init();
	void update();
	CREATE_FUNC(TitleScene);

private:
	TitleUILayer* m_uilayer;
};
#endif