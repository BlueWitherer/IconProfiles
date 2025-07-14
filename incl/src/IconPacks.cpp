#include "../IconPacks.hpp"

#include <Geode/Geode.hpp>

#include <Geode/utils/terminate.hpp>

using namespace geode::prelude;

namespace iconpacks {
    Mod* m_thisMod = getMod();

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
};