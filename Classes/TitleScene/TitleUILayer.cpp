#include "TitleScene\TitleUILayer.h"
#include "LobbyScene\LobbyScene.h"

bool TitleUILayer::init() {
	if (!Layer::init()) {
		return false;
	}

	auto displaySize = Director::getInstance()->getVisibleSize();
	m_button = Sprite::create("CloseNormal.png");
	m_button->setOpacity(1);
	m_backGround = Sprite::create("BackGround.jpg");
	m_backGround->setPosition(Vec2(displaySize.width / 2, displaySize.height / 2));
	m_backGround->setScale(1.5f, 1.5f);
	m_backGround->setOpacity(1);
	this->addChild(m_button,5);
	this->addChild(m_backGround, 0);
	return true;
}

void TitleUILayer::update() {
	if (!this->isVisible()) return;
}

bool TitleUILayer::onTouchBegin(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) {
	if (!this->isVisible()) return false;

	auto bbox = m_button->getBoundingBox();
	Point touchPos = Vec2(pTouch->getLocationInView().x, pTouch->getLocationInView().y);

	if (bbox.containsPoint(touchPos)) {
		log("Next Scene");
		return true;
	}
	return false;
}

void TitleUILayer::StartFade() {
	this->setVisible(true);


}