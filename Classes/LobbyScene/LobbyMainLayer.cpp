#include "LobbyScene\LobbyMainLayer.h"


bool LobbyMainLayer::init() {
	if (!Layer::init()) {
		return false;
	}

	auto displaySize = Director::getInstance()->getVisibleSize();

	

	m_spriteContainer.pushBack(Sprite::create("play_button.png"));
	m_spriteContainer.pushBack(Sprite::create("deck_button.png"));
	m_spriteContainer.pushBack(Sprite::create("ranking_button.png"));
	
	for (int i = 0;i < m_spriteContainer.size();++i) {
		m_spriteContainer.at(i)->setName(name[i]);
		m_spriteContainer.at(i)->setPosition(displaySize.width / 2, displaySize.height / 2 + 100 + (-100)*i);
		this->addChild(m_spriteContainer.at(i));
	}

#if COCOS2D_DEBUG
	EventListenerMouse* mouseListener = EventListenerMouse::create();
	mouseListener->onMouseDown = [&](Event* _event) {
		auto mouseInfo = (EventMouse*)_event;
		auto target = (Sprite*)mouseInfo->getCurrentTarget();

		Rect targetbox = target->getBoundingBox();
		Point touchPos = Vec2(mouseInfo->getLocationInView().x, mouseInfo->getLocationInView().y);

		if (targetbox.containsPoint(touchPos)) {
			log("タップ");
			OnEventEnter(target->getName(), &name[0]);
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, m_spriteContainer.at(0));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener->clone(), m_spriteContainer.at(1));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener->clone(), m_spriteContainer.at(2));

#else
	EventListenerTouchOneByOne* touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = [=](Touch* _touch, Event* _event) {
		auto touchInfo = _touch;
		auto target = (Sprite*)_event->getCurrentTarget();

		Rect targetbox = target->getBoundingBox();
		Point touchPos = Vec2(touchInfo->getLocationInView().x, touchInfo->getLocationInView().y);

		if (targetbox.containsPoint(touchPos)) {
			log("タップ");
			OnEventEnter(target->getName(), &name[0]);
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, m_spriteContainer.at(0));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener->clone(), m_spriteContainer.at(1));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener->clone(), m_spriteContainer.at(2));
#endif

	return true;
}

void LobbyMainLayer::OnEventEnter(const std::string _name, const std::string* _nameList) {
	STATUS sts;
	if (_name == *(_nameList)) {
		sts = STATUS::PLAY;
		Director::getInstance()->replaceScene(Scene::create());
	}
	else if (_name == *(_nameList+1)) {
		sts = STATUS::DECK;
		Director::getInstance()->replaceScene(Scene::create());
	}
	else if (_name == *(_nameList+2)) {
		sts = STATUS::RANKING;
		Director::getInstance()->replaceScene(Scene::create());
	}
}