#include "SceneFactory.h"

USING_NS_CC;

cocos2d::Scene* SceneFactory::create() {
	auto scene = Scene::create();

	return scene;
}