#include "headers/PacksPopup.hpp"

#include <Geode/Geode.hpp>

#include <Geode/modify/GJGarageLayer.hpp>

using namespace geode::prelude;

class $modify(MyGarageLayer, GJGarageLayer) {
    bool init() {
        if (GJGarageLayer::init()) {
            if (auto leftMenu = getChildByID("shards-menu")) {
                auto packBtnSprite = CCSprite::createWithSpriteFrameName("accountBtn_myLevels_001.png");
                packBtnSprite->setScale(0.875f);

                auto packBtn = CCMenuItemSpriteExtra::create(
                    packBtnSprite,
                    this,
                    menu_selector(MyGarageLayer::onPacksButton)
                );
                packBtn->setID("button"_spr);

                leftMenu->addChild(packBtn);
                leftMenu->updateLayout(true);
            } else {
                log::error("Shards menu not found!");
            };

            return true;
        } else {
            return false;
        };
    };

    void onPacksButton(CCObject*) {
        PacksPopup::create("Icon Packs", "Access your icon sets quickly.", "OK");
    };
};