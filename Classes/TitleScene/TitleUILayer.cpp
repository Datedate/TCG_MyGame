#include "TitleScene\TitleUILayer.h"
#include "LobbyScene\LobbyScene.h"

bool TitleUILayer::init() {
	if (!Layer::init()) {
		return false;
	}
	
	m_fadeFlag = false;

	auto displaySize = Director::getInstance()->getVisibleSize();
	m_button = Sprite::create("CloseNormal.png");
	m_button->setPosition(Vec2(displaySize.width / 2, displaySize.height / 2));
	m_button->setOpacity(0);

	m_backGround = Sprite::create("BackGround.jpg");
	m_backGround->setPosition(Vec2(displaySize.width / 2, displaySize.height / 2));
	m_backGround->setOpacity(0);
	m_backGround->setScale(2.0f, 2.0f);

	auto seqbutton = Sequence::create(
		FadeIn::create(0.5),
		NULL
		);

	m_button->runAction(seqbutton);

	auto seqbackground = Sequence::create(
		FadeIn::create(0.8),
		CallFunc::create([&]() {
			log("タップ開始");
			m_fadeFlag = true;
		}),
		NULL
		);

	InitListener();
	
	m_backGround->runAction(seqbackground);
	
	this->addChild(m_button,5);
	this->addChild(m_backGround, 0);
	return true;
}

void TitleUILayer::InitListener() {
#if COCOS2D_DEBUG
	EventListenerMouse* mouseListener = EventListenerMouse::create();
	mouseListener->onMouseDown = [=](Event* _event) {
		if (!m_fadeFlag) return;
		auto seq = Sequence::create(
			FadeOut::create(0.4),
			CallFunc::create([&]() {
			Director::getInstance()->replaceScene(LobbyScene::create());
		}),
			NULL
			);

		m_backGround->runAction(seq);
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);
#else
	EventListenerTouchOneByOne* touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegin = [=](Touch* _touch,Event* _event) {
		if (!m_fadeFlag) return;
		auto seq = Sequence::create(
			FadeOut::create(0.4),
			CallFunc::create([&]() {
			Director::getInstance()->replaceScene(LobbyScene::create());
		}),
			NULL
			);

		m_backGround->runAction(seq);
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
#endif
}

bool TitleUILayer::onTouchBegin(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) {
	if (!m_fadeFlag) return false;

	auto bbox = m_button->getBoundingBox();
	Point touchPos = Vec2(pTouch->getLocationInView().x, pTouch->getLocationInView().y);

	if (bbox.containsPoint(touchPos)) {
		log("Next Scene");
		Director::getInstance()->replaceScene(LobbyScene::create());
		return true;
	}
	return false;
}
