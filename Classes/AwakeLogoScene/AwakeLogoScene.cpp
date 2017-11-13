#include "AwakeLogoScene\AwakeLogoScene.h"
#include "TitleScene\TitleScene.h"
bool AwakeLogoScene::init() {
	if (!Scene::init()) {
		return false;
	}

	auto layer = Layer::create();
	auto sprite = Sprite::create("HelloWorld.png");

	auto displaySize = Director::getInstance()->getVisibleSize();

	sprite->setPosition(displaySize.width / 2, displaySize.height / 2);
	sprite->setOpacity(0);
	sprite->setScale(0.5f, 0.5f);

	auto seq = Sequence::create(
		FadeIn::create(1.0f),
		DelayTime::create(1.0f),
		FadeOut::create(0.8f),
		CallFunc::create([]() {
			Director::getInstance()->replaceScene(TitleScene::create());
		}),
		NULL
		);

	sprite->runAction(seq);

	layer->addChild(sprite);
	this->addChild(layer);

	return true;
}
