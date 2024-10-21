#include <Geode/Geode.hpp>
#include <vector>
#include <string>
#include <random>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/EditorPauseLayer.hpp>
#include "cocos2d.h"
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/loader/SettingV3.hpp>

using namespace geode::prelude;

// Quote Function
std::string getRandomQuote() {
    // Rare Quote
    std::string rareQuote = "Good Job! You found an extremely rare quote, you might just be able to now beat this level!";

    if ((rand() % 10000) == 0) {
        return rareQuote;
    }

    // List of quotes
    std::vector<std::string> quotes = {
        "You've got this, just keep trying. you're so close!", // 1
		"Every fail is just practice for success. Keep at it!", // 2
		"I know it's frustrating, but you're improving every time.", // 3
		"Believe in yourself, even when it feels tough. You can do this.", // 4
		"Don't quit now, I promise you're almost there.", // 5
		"It's okay to struggle. that's how we grow. You're doing great!", // 6
		"Remember, every expert was once a beginner, just like you.", // 7
		"You're tougher than this level. One more go!", // 8
		"You've already come so far. Take a breath and try again.", // 9
		"Focus, relax, and trust yourself. You can do this.", // 10
		"Each jump, each fail. it's all progress. Keep moving!", // 11
		"No one gets it perfect the first time. Keep trying!", // 12
		"This is hard, but so are you. Don't give up now.", // 13
		"You're learning something new every time you try.", // 14
		"Every attempt matters, even if it doesn't feel like it right now.", // 15
		"You're making progress. It may be slow, but it's progress!", // 16
		"You've got the skills. you just need a little more patience.", // 17
		"Trust me, every fail makes you better. Keep pushing!", // 18
		"Just one more try. you're closer than you think!", // 19
		"Stay calm, stay patient. You can do this.", // 20
		"You've beaten harder things before. this is just another challenge.", // 21
		"Remember, it's not about perfection, it's about persistence.", // 22
		"Believe in your progress, even when it's hard to see.", // 23
		"Don't worry about failing. it's part of the process.", // 24
		"You're almost there. one jump at a time.", // 25
		"It's okay to take a break, but don't quit.", // 26
		"Keep clicking, keep trying. You're stronger than this level.", // 27
		"Even small progress is still progress. You're getting better!", // 28
		"You're getting closer with every try. Don't give up now.", // 29
		"Think about how amazing it'll feel when you finally beat it.", // 30
		"Stay positive. you're learning so much with each attempt.", // 31
		"You're doing better than you think. Keep going.", // 32
		"Don't forget to celebrate how far you've already come.", // 33
		"It's not about how fast you get there, just that you get there.", // 34
		"You've got the determination, now just keep pushing.", // 35
		"You're learning the patterns. Each mistake teaches you more.", // 36
		"Everyone struggles with these. you're not alone. Keep trying.", // 37
		"Take a deep breath. You're capable of more than you know.", // 38
		"You're closer than you were yesterday. Just keep moving.", // 39
		"This level is tough, but you're tougher.", // 40
		"Don't be afraid of messing up. every try gets you closer.", // 41
		"Stay focused. You're almost there!", // 42
		"You've got the patience, now just take it one step at a time.", // 43
		"It's okay if it takes time. You're making progress.", // 44
		"Every mistake is a lesson. You're getting better.", // 45
		"Failing just means you're trying. Keep going.", // 46
		"You're so much closer to beating it than you realize.", // 47
		"Someday soon, you'll laugh at how hard this seemed.", // 48
		"Even if it's slow, you're improving every time you play.", // 49
		"This journey may be tough, but I know you can do it. Keep at it.", // 50
		"You've got this, just keep trying. you're so close!", // 51
		"Every fail is just practice for success. Keep at it!", // 52
		"I know it's frustrating, but you're improving every time.", // 53
		"Believe in yourself, even when it feels tough. You can do this.", // 54
		"Don't quit now, I promise you're almost there.", // 55
		"It's okay to struggle. that's how we grow. You're doing great!", // 56
		"Remember, every expert was once a beginner, just like you.", // 57
		"You're tougher than this level. One more go!", // 58
		"You've already come so far. Take a breath and try again.", // 59
		"Focus, relax, and trust yourself. You can do this.", // 60
		"Each jump, each fail. it's all progress. Keep moving!", // 61
		"No one gets it perfect the first time. Keep trying!", // 62
		"Just one more try. you're closer than you think!", // 63
		"You're learning something new every time you try.", // 64
		"Every attempt matters, even if it doesn't feel like it right now.", // 65
		"You're making progress. It may be slow, but it's progress!", // 66
		"You've got the skills. you just need a little more patience.", // 67
		"Trust me, every fail makes you better. Keep pushing!", // 68
		"This is hard, but so are you. Don't give up now.", // 69
		"Stay calm, stay patient. You can do this.", // 70
		"You've beaten harder things before. this is just another challenge.", // 71
		"Remember, it's not about perfection, it's about persistence.", // 72
		"Believe in your progress, even when it's hard to see.", // 73
		"Don't worry about failing. it's part of the process.", // 74
		"You're almost there. one jump at a time.", // 75
		"It's okay to take a break, but don't quit.", // 76
		"Keep clicking, keep trying. You're stronger than this level.", // 77
		"Even small progress is still progress. You're getting better!", // 78
		"You're getting closer with every try. Don't give up now.", // 79
		"Think about how amazing it'll feel when you finally beat it.", // 80
		"Stay positive. you're learning so much with each attempt.", // 81
		"You're doing better than you think. Keep going.", // 82
		"Don't forget to celebrate how far you've already come.", // 83
		"It's not about how fast you get there, just that you get there.", // 84
		"You've got the determination, now just keep pushing.", // 85
		"You're learning the patterns. Each mistake teaches you more.", // 86
		"Everyone struggles with these. you're not alone. Keep trying.", // 87
		"Take a deep breath. You're capable of more than you know.", // 88
		"You're closer than you were yesterday. Just keep moving.", // 89
		"This level is tough, but you're tougher.", // 90
		"Don't be afraid of messing up. every try gets you closer.", // 91
		"Stay focused. You're almost there!", // 92
		"You've got the patience, now just take it one step at a time.", // 93
		"It's okay if it takes time. You're making progress.", // 94
		"Every mistake is a lesson. You're getting better.", // 95
		"Failing just means you're trying. Keep going.", // 96
		"You're so much closer to beating it than you realize.", // 97
		"Someday soon, you'll laugh at how hard this seemed.", // 98
		"Even if it's slow, you're improving every time you play.", // 99
		"This journey may be tough, but I know you can do it. Keep at it.", // 100
		"Good Job! You found an extremely rare quote, you might just be able to now beat this level!", // 101
		"The only one who never fails, is the one who never tries.", // 102
		"If there's no failure, there's no point of success." // 103
		"Just imagine how hard it is when player verify Top 1's" //104
    };

    int randomIndex = rand() % quotes.size();
    return quotes[randomIndex];
}

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
