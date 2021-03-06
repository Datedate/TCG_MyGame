#include "LobbyScene\LobbyScene.h"
#include "LobbyScene\LobbyMainLayer.h"
#include "LobbyScene\LobbyUILayer.h"
#include "LobbyScene\LobbyBackGroundLayer.h"

bool LobbyScene::init() {
	if (!Scene::init()) {
		return false;
	}

	m_mainLayer = LobbyMainLayer::create();
	m_backLayer = LobbyBackGroundLayer::create();
	m_uiLayer = LobbyUILayer::create();

	this->addChild(m_backLayer, 1);
	this->addChild(m_mainLayer, 2);
	this->addChild(m_uiLayer, 3);

	return true;
}
