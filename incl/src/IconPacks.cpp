#include "../IconPacks.hpp"

#include <Geode/Geode.hpp>

#include <Geode/utils/terminate.hpp>

using namespace geode::prelude;
using namespace matjson;

namespace iconpacks {
    Mod* m_thisMod = getMod();

    IconPack IconPackManager::parsePack(Value json) {
        return IconPack();
    };

    std::vector<IconPack> IconPackManager::getAllIconPacks() {
        auto saveData = m_thisMod->getSaveContainer();
        std::vector<IconPack> packs;

        for (auto& [key, value] : saveData) {
            if (value["pack"].asBool()) {
                log::debug("Processed icon pack {}", key);
            } else {
                log::error("Invalid icon pack object");
            };
        };

        return packs;
    };

    void IconPackManager::savePack(IconPack pack) {
        auto packJson = Value::object();

        packJson["pack"] = pack.pack;

        packJson["name"] = pack.name;
        packJson["priority"] = pack.priority;

        packJson["icon"] = pack.icon;
        packJson["ship"] = pack.ship;
        packJson["ball"] = pack.ball;
        packJson["ufo"] = pack.ufo;
        packJson["wave"] = pack.wave;
        packJson["robot"] = pack.robot;
        packJson["spider"] = pack.spider;
        packJson["swing"] = pack.swing;

        packJson["shipFire"] = pack.shipFire;

        packJson["color1"] = pack.color1;
        packJson["color2"] = pack.color2;

        packJson["colorGlow"] = pack.colorGlow;

        packJson["glow"] = pack.glow;

        m_thisMod->setSavedValue(std::to_string(pack.priority), packJson);
    };
};