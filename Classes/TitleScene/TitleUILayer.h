#ifndef _TITLEUILAYER_H_2017_11_11_
#define _TITLEUILAYER_H_2017_11_11_

#include "cocos2d.h"

USING_NS_CC;

class TitleUILayer : public cocos2d::Layer
{
public:
	bool init();
	void update();
	CREATE_FUNC(TitleUILayer);
	void StartFade();
private:
	virtual bool onTouchBegin(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
//	virtual void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	//virtual void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);

	Sprite* m_button;
	Sprite* m_backGround;
	bool	m_startFlag;
};


#endif