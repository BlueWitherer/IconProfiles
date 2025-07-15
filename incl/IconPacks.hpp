#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;
using namespace matjson;

namespace iconpacks {
    extern Mod* m_thisMod; // Favorite Mods

    // An icon pack
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

        int streak = 1;
        int shipFire = 1;

        int color1 = 1;
        int color2 = 2;

        int colorGlow = 3;

        bool glow = false;

        std::string unique = fmt::format("{}:{}:{}:{}:{}:{}:{}:{}-{}",
                                         icon, ship, ball, ufo, wave, robot, spider, swing, priority);

        // evil constructor
        IconPack(
            bool pk, // Set to true
            std::string nme, // Custom name for the pack
            int prio, // List priority of the pack for UI
            int ic, // Player's icon ID
            int sh, // Player's ship ID
            int bl, // Player's ball ID
            int uo, // Player's UFO ID
            int wv, // Player's wave ID
            int rb, // Player's robot ID
            int sp, // Player's spider ID
            int sw, // Player's swing ID
            int str, // Player's streak ID
            int shFr, // Player's ship fire ID
            int co1, // Player's primary color ID
            int co2, // Player's secondary color ID
            int coGl, // Player's glow color ID
            bool gl, // Player's glow setting
            std::string u // Unique ID to the pack (leave empty if saving as new)
        ) : pack(pk), name(nme), priority(prio),
            icon(ic), ship(sh), ball(bl), ufo(uo), wave(wv), robot(rb), spider(sp), swing(sw),
            streak(str), shipFire(shFr),
            color1(co1), color2(co2), colorGlow(coGl), glow(gl),
            unique(u) {};

        // Default constructor
        IconPack() = default;
    };

    class IconPackManager {
    protected:
        IconPack parsePack(Value json);

    public:
        // Get an array of all the player's icon packs
        static std::vector<IconPack> getAllIconPacks();

        // Save a new icon pack
        static Value savePack(
            IconPack pack, // The constructed icon pack
            std::string id = "" // Optional id, empty if saving new pack
        );

        // Edit a pre-existing icon pack
        static Value editPack(
            IconPack pack, // The constructed icon pack
            std::string name // The name of the current icon pack
        );
    };
};