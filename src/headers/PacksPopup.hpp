#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class PacksPopup : public Popup<> {
protected:
    ScrollLayer* m_scrollLayer = nullptr;

    void Pack(std::string name, int priority);
    bool setup() override;

public:
    static PacksPopup* create();
};