#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/loader/SettingV3.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <random>
#include "cocos2d.h"
#include <filesystem>

using namespace geode::prelude;

// Load Quotes from File
std::vector<std::string> loadQuotesFromFile(const std::filesystem::path & filename) {
    std::vector<std::string> quotes;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        return quotes;
    }

    while (std::getline(file, line)) {
        if (!line.empty()) {
            quotes.push_back(line);
        }
    }

    return quotes;
}

// Initialize Quotes
std::vector<std::string> quotes = loadQuotesFromFile(Mod::get()->getResourcesDir() / "quotes.txt");
std::vector<std::string> jokequotes = loadQuotesFromFile(Mod::get()->getResourcesDir() / "jokequotes.txt");
std::vector<std::string> kysquotes = loadQuotesFromFile(Mod::get()->getResourcesDir() / "kysquotes.txt");
std::vector<std::string> customquotes = loadQuotesFromFile(Mod::get()->getConfigDir() / "custom.txt");
std::string rareQuote = "Good Job! You found an extremely rare quote, you might just be able to now beat this level! -MobMasterMind";

// Get Random Quote
std::string getRandomQuote() {

    if ((rand() % 10000) == 0) {
        return rareQuote;
    }

    bool jokequoteson = Mod::get()->getSettingValue<bool>("jokequoteson");
    bool kysquoteson = Mod::get()->getSettingValue<bool>("kysquoteson");
    bool quoteson = Mod::get()->getSettingValue<bool>("quoteson");
    bool customquoteson = Mod::get()->getSettingValue<bool>("customquoteson");

    std::vector<std::vector<std::string>*> activePools;
    if (quoteson) {
        if (quotes.empty()) return "Seems like quotes is empty.";
        activePools.push_back(&quotes);
    }
    if (jokequoteson) {
        if (jokequotes.empty()) return "Seems like jokequotes is empty.";
        activePools.push_back(&jokequotes);
    }
    if (kysquoteson) {
        if (kysquotes.empty()) return "Seems like kysquotes is empty.";
        activePools.push_back(&kysquotes);
    }

    if (customquoteson) {
        std::vector<std::string> customquotes = loadQuotesFromFile(Mod::get()->getConfigDir() / "custom.txt");
        if (customquotes.empty()) return "Edit The custom file (Tutorial in Mod Description) -Encouraging Quotes";
        activePools.push_back(&customquotes);
    }

    if (activePools.empty()) return "Looks like you don't have any settings enabled to display Quotes. Enable them from the Mod's Settings.";

    int totalSize = 0;
    for (const auto* pool : activePools) {
        totalSize += pool->size();
    }

    int randomIndex = rand() % totalSize;

    for (const auto* pool : activePools) {
        if (randomIndex < pool->size()) {
            return (*pool)[randomIndex];
        }
        randomIndex -= pool->size();
    }

    return "";
}

// Modified MyMenuLayer
class $modify(MyMenuLayer, MenuLayer) {

    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        auto menu = this->getChildByID("bottom-menu");

        if (Mod::get()->getSettingValue<bool>("enableButtoninMenuLayer")) {
            auto myButton = CCMenuItemSpriteExtra::create(
                CCSprite::createWithSpriteFrameName("GJ_chatBtn_001.png"),
                this,
                menu_selector(MyMenuLayer::onMyButton)
            );
            myButton->setID("quote-button"_spr);
            menu->addChild(myButton);
            menu->updateLayout();
        }

        return true;
    }

    void onMyButton(CCObject*) {
        FLAlertLayer::create("Quote", getRandomQuote().c_str(), "Alright")->show();
    }
};

// Modified MyPauseLayer
class $modify(MyPauseLayer, PauseLayer) {
    void customSetup() {
        PauseLayer::customSetup();

        auto myButton = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_chatBtn_001.png"),
            this,
            menu_selector(MyPauseLayer::onMyButton)
        );
        myButton->setID("quote-button"_spr);

        auto menu = this->getChildByID("left-button-menu");
        menu->addChild(myButton);
        menu->updateLayout();
    }

    void onMyButton(CCObject*) {
        FLAlertLayer::create("Quote", getRandomQuote().c_str(), "Alright")->show();
    }
};