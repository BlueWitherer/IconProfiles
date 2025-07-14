#include "../PacksPopup.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

bool PacksPopup::setup() {
    setID("popup"_spr);
    setTitle("Icon Packs");

    auto gm = GameManager::get();

    log::info("The setted up!");

    return true;
};

PacksPopup* PacksPopup::create() {
    auto ret = new PacksPopup();

    if (ret && ret->initAnchored(350.f, 200.f)) {
        ret->autorelease();
        return ret;
    };

    CC_SAFE_DELETE(ret);
    return nullptr;
};