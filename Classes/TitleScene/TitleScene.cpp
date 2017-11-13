#include "TitleScene\TitleScene.h"
#include "TitleSCene\TitleUILayer.h"

bool TitleScene::init() {

	if (!Scene::init()) {
		return false;
	}
	// Update�֐����ĂԂ悤�ɂ���
	this->scheduleUpdate();

	m_uilayer = TitleUILayer::create();

	this->addChild(m_uilayer, 1, "TitleUILayer");

	return true;
}
