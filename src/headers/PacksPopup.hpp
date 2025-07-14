#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class PacksPopup : public Popup<> {
protected:
    bool setup() override;

public:
    static PacksPopup* create();
};