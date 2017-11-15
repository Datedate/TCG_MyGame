#include "LobbyScene\LobbyBackGroundLayer.h"

bool LobbyBackGroundLayer::init() {
	if (!Layer::init()) {
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Texture2D *bgTexture = Director::getInstance()->getTextureCache()->addImage("background_01.jpg");
	const Texture2D::TexParams tp = { GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT };

	Sprite *background = Sprite::createWithTexture(bgTexture, Rect(0, 0, visibleSize.width, visibleSize.height));
	background->getTexture()->setTexParameters(tp);
	background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

	this->addChild(background);
	return true;
}