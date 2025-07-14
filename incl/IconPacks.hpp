#pragma once

namespace iconpacks {
    struct IconPack {
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

    class IconPackManager {};
};