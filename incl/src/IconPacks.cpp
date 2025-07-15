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
            if (value.isObject()) {
                if (value["pack"].asBool()) {
                    IconPack icons();
                    log::debug("Processed icon pack {}", key);
                } else {
                    log::error("Invalid icon pack object '{}'", key);
                };
            } else {
                log::error("{} is not an object", key);
            };
        };

        return packs;
    };

    Value IconPackManager::savePack(IconPack pack) {
        auto packJson = Value::object();

        // so its easier to check later
        packJson["pack"] = pack.pack;

        // pack details
        packJson["name"] = pack.name;
        packJson["priority"] = pack.priority;

        // player icons
        packJson["icon"] = pack.icon;
        packJson["ship"] = pack.ship;
        packJson["ball"] = pack.ball;
        packJson["ufo"] = pack.ufo;
        packJson["wave"] = pack.wave;
        packJson["robot"] = pack.robot;
        packJson["spider"] = pack.spider;
        packJson["swing"] = pack.swing;

        // other player visuals
        packJson["streak"] = pack.streak;
        packJson["shipFire"] = pack.shipFire;

        // player colors
        packJson["color1"] = pack.color1;
        packJson["color2"] = pack.color2;
        packJson["colorGlow"] = pack.colorGlow;

        // glowwwww
        packJson["glow"] = pack.glow;

        m_thisMod->setSavedValue(std::to_string(pack.priority), packJson);
        return packJson;
    };

    Value IconPackManager::editPack(IconPack pack, std::string name) {
        return Value::object();
    };
};