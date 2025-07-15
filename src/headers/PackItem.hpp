#pragma once

#include "../../incl/IconPacks.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;
using namespace iconpacks;

class PackItem : public CCNode {
protected:
    IconPack m_pack;

    bool init(IconPack pack, CCSize size);

public:
    static PackItem* create(IconPack pack, CCSize size);
};