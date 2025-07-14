#include <Geode/Geode.hpp>

#include <Geode/modify/GJGarageLayer.hpp>

using namespace geode::prelude;

class $modify(MyGarageLayer, GJGarageLayer) {
    bool init() {
        if (GJGarageLayer::init()) {
            log::info("Hooked garage!");
            // auto gm = GameManager::get();

            return true;
        } else {
            return false;
        };
    };
};