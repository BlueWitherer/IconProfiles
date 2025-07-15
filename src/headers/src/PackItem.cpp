#include "../PackItem.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

bool PackItem::init(IconPack pack, CCSize size) {
    m_pack = pack;

    if (CCNode::init()) {
        setID(pack.unique);
        setAnchorPoint({ 0, 1 });
        setContentSize(size);

        auto gm = GameManager::get();

        // Layout to automatically position buttons on button menu
        auto iconsLayout = RowLayout::create();
        iconsLayout->setDefaultScaleLimits(0.625f, 0.875f);
        iconsLayout->setAxisAlignment(AxisAlignment::Start);
        iconsLayout->setCrossAxisAlignment(AxisAlignment::Center);
        iconsLayout->setCrossAxisLineAlignment(AxisAlignment::Center);
        iconsLayout->setAutoGrowAxis(true);
        iconsLayout->setAxisReverse(false);
        iconsLayout->setGap(5.f);

        auto iconsMenu = CCMenu::create();
        iconsMenu->setID("icons-menu");
        iconsMenu->setAnchorPoint({ 0, 0.5 });
        iconsMenu->setScaledContentSize({ size.width - 50.f, size.height - 5.f });
        iconsMenu->setPosition({ 2.5f, size.height / 2.f });
        iconsMenu->setLayout(iconsLayout);

        iconsMenu->updateLayout(true);
        addChild(iconsMenu);

        if (auto icon = SimplePlayer::create(pack.icon)) {
            if (pack.glow) icon->setGlowOutline(gm->colorForIdx(pack.colorGlow));

            icon->setColors(gm->colorForIdx(pack.color1), gm->colorForIdx(pack.color2));
            iconsMenu->addChild(icon);
        };

        return true;
    } else {
        return false;
    };
};

PackItem* PackItem::create(IconPack pack, CCSize size) {
    auto ret = new PackItem();

    if (!ret || !ret->init(pack, size)) {
        CC_SAFE_DELETE(ret);
        return nullptr;
    };

    ret->autorelease();
    return ret;
};