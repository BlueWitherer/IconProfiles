#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class PackItemEdit : public Popup<> {
protected:
    IconPack m_pack;
    TextInput* m_nameTextBox = nullptr;
};