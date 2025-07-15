#include "../PacksPopup.hpp"

#include "../PackItem.hpp"

#include "../../incl/IconPacks.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;
using namespace iconpacks;

bool PacksPopup::setup() {
    setID("popup"_spr);
    setTitle("Icon Packs");

    // Create main content area
    auto contentSize = getContentSize();
    auto scrollSize = CCSize{ 280.f, 175.f };

    // Background for scroll layer
    auto scrollBG = CCScale9Sprite::create("square02b_001.png");
    scrollBG->setContentSize(scrollSize);
    scrollBG->setAnchorPoint({ 0.5, 0.5 });
    scrollBG->ignoreAnchorPointForPosition(false);
    scrollBG->setPosition({ contentSize.width / 2.f, (contentSize.height / 2.f) - 35.f });
    scrollBG->setColor({ 0, 0, 0 });
    scrollBG->setOpacity(100);

    m_mainLayer->addChild(scrollBG);

    // Create layout for scroll layer
    auto scrollLayerLayout = ColumnLayout::create()
        ->setAxisAlignment(AxisAlignment::End)
        ->setAutoGrowAxis(360.f)
        ->setAxisReverse(true)
        ->setGap(5.f);

    // Create scroll layer
    m_scrollLayer = ScrollLayer::create({ scrollSize.width - 12.5f, scrollSize.height - 12.5f });
    m_scrollLayer->setID("scroll-layer");
    m_scrollLayer->setAnchorPoint({ 0.5, 0.5 });
    m_scrollLayer->ignoreAnchorPointForPosition(false);
    m_scrollLayer->setPosition(scrollBG->getPosition());
    m_scrollLayer->m_contentLayer->setLayout(scrollLayerLayout);

    m_mainLayer->addChild(m_scrollLayer);

    m_scrollLayer->m_contentLayer->updateLayout(true);
    m_scrollLayer->scrollToTop();

    return true;
};

void PacksPopup::Pack(std::string name, int priority) {
    auto gm = GameManager::get();

    IconPack pack(
        true,
        name,
        priority,
        gm->getIconRequestID(),
        gm->getPlayerShip(),
        gm->getPlayerBall(),
        gm->getPlayerBird(),
        gm->getPlayerDart(),
        gm->getPlayerRobot(),
        gm->getPlayerSpider(),
        gm->getPlayerSwing(),
        gm->getPlayerStreak(),
        gm->getPlayerShipFire(),
        gm->getPlayerColor(),
        gm->getPlayerColor2(),
        gm->getPlayerGlowColor(),
        gm->getPlayerGlow(),
        ""
    );

    IconPackManager::savePack(pack);
};

PacksPopup* PacksPopup::create() {
    auto ret = new PacksPopup();

    if (ret && ret->initAnchored(350.f, 200.f)) {
        ret->autorelease();
        return ret;
    };

    CC_SAFE_DELETE(ret);
    return nullptr;
};