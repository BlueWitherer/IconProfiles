#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

namespace iconpacks {
    extern Mod* m_thisMod; // Favorite Mods

    struct IconPack {
        bool pack = true;

        std::string name = "";
        int priority = 0;

        int icon = 1;
        int ship = 1;
        int ball = 1;
        int ufo = 1;
        int wave = 1;
        int robot = 1;
        int spider = 1;
        int swing = 1;

        int shipFire = 1;

        int color1 = 1;
        int color2 = 2;

        int colorGlow = 3;

        bool glow = false;

        IconPack() = default;
    };

    class IconPackManager {
    public:
        // Get an array of all the player's icon packs
        std::vector<IconPack> getAllIconPacks();

        // Save a new icon pack
        IconPack savePack(
            IconPack pack // The constructed icon pack
        );
    };
};