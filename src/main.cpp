#include <Geode/Geode.hpp>
#include <vector>
#include <string>
#include <random>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/EditorPauseLayer.hpp>
#include "cocos2d.h"
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

// Global list of possible quotes
std::vector<std::string> quotes = {
    	"You've got this, just keep trying. you're so close!",
		"Every fail is just practice for success. Keep at it!",
		"I know it's frustrating, but you're improving every time.",
		"Believe in yourself, even when it feels tough. You can do this.",
		"Don't quit now, I promise you're almost there.",
		"It's okay to struggle. that's how we grow. You're doing great!",
		"Remember, every expert was once a beginner, just like you.",
		"You're tougher than this level. One more go!",
		"You've already come so far. Take a breath and try again.",
		"Focus, relax, and trust yourself. You can do this.",
		"Each jump, each fail. it's all progress. Keep moving!",
		"No one gets it perfect the first time. Keep trying!",
		"This is hard, but so are you. Don't give up now.",
		"You're learning something new every time you try.",
		"Every attempt matters, even if it doesn't feel like it right now.",
		"You're making progress. It may be slow, but it's progress!",
		"You've got the skills. you just need a little more patience.",
		"Trust me, every fail makes you better. Keep pushing!",
		"Just one more try. you're closer than you think!",
		"Stay calm, stay patient. You can do this.",
		"You've beaten harder things before. this is just another challenge.",
		"Remember, it's not about perfection, it's about persistence.",
		"Believe in your progress, even when it's hard to see.",
		"Don't worry about failing. it's part of the process.",
		"You're almost there. one jump at a time.",
		"It's okay to take a break, but don't quit.",
		"Keep clicking, keep trying. You're stronger than this level.",
		"Even small progress is still progress. You're getting better!",
		"You're getting closer with every try. Don't give up now.",
		"Think about how amazing it'll feel when you finally beat it.",
		"Stay positive. you're learning so much with each attempt.",
		"You're doing better than you think. Keep going.",
		"Don't forget to celebrate how far you've already come.",
		"It's not about how fast you get there, just that you get there.",
		"You've got the determination, now just keep pushing.",
		"You're learning the patterns. Each mistake teaches you more.",
		"Everyone struggles with these. you're not alone. Keep trying.",
		"Take a deep breath. You're capable of more than you know.",
		"You're closer than you were yesterday. Just keep moving.",
		"This level is tough, but you're tougher.",
		"Don't be afraid of messing up. every try gets you closer.",
		"Stay focused. You're almost there!",
		"You've got the patience, now just take it one step at a time.",
		"It's okay if it takes time. You're making progress.",
		"Every mistake is a lesson. You're getting better.",
		"Failing just means you're trying. Keep going.",
		"You're so much closer to beating it than you realize.",
		"Someday soon, you'll laugh at how hard this seemed.",
		"Even if it's slow, you're improving every time you play.",
		"This journey may be tough, but I know you can do it. Keep at it.",
		"You've got this, just keep trying. you're so close!",
		"Every fail is just practice for success. Keep at it!",
		"I know it's frustrating, but you're improving every time.",
		"Believe in yourself, even when it feels tough. You can do this.",
		"Don't quit now, I promise you're almost there.",
		"It's okay to struggle. that's how we grow. You're doing great!",
		"Remember, every expert was once a beginner, just like you.",
		"You're tougher than this level. One more go!",
		"You've already come so far. Take a breath and try again.",
		"Focus, relax, and trust yourself. You can do this.",
		"Each jump, each fail. it's all progress. Keep moving!",
		"No one gets it perfect the first time. Keep trying!",
		"This is hard, but so are you. Don't give up now.",
		"You're learning something new every time you try.",
		"Every attempt matters, even if it doesn't feel like it right now.",
		"You're making progress. It may be slow, but it's progress!",
		"You've got the skills. you just need a little more patience.",
		"Trust me, every fail makes you better. Keep pushing!",
		"Just one more try. you're closer than you think!",
		"Stay calm, stay patient. You can do this.",
		"You've beaten harder things before. this is just another challenge.",
		"Remember, it's not about perfection, it's about persistence.",
		"Believe in your progress, even when it's hard to see.",
		"Don't worry about failing. it's part of the process.",
		"You're almost there. one jump at a time.",
		"It's okay to take a break, but don't quit.",
		"Keep clicking, keep trying. You're stronger than this level.",
		"Even small progress is still progress. You're getting better!",
		"You're getting closer with every try. Don't give up now.",
		"Think about how amazing it'll feel when you finally beat it.",
		"Stay positive. you're learning so much with each attempt.",
		"You're doing better than you think. Keep going.",
		"Don't forget to celebrate how far you've already come.",
		"It's not about how fast you get there, just that you get there.",
		"You've got the determination, now just keep pushing.",
		"You're learning the patterns. Each mistake teaches you more.",
		"Everyone struggles with these. you're not alone. Keep trying.",
		"Take a deep breath. You're capable of more than you know.",
		"You're closer than you were yesterday. Just keep moving.",
		"This level is tough, but you're tougher.",
		"Don't be afraid of messing up. every try gets you closer.",
		"Stay focused. You're almost there!",
		"You've got the patience, now just take it one step at a time.",
		"It's okay if it takes time. You're making progress.",
		"Every mistake is a lesson. You're getting better.",
		"Failing just means you're trying. Keep going.",
		"You're so much closer to beating it than you realize.",
		"Someday soon, you'll laugh at how hard this seemed.",
		"Even if it's slow, you're improving every time you play.",
		"This journey may be tough, but I know you can do it. Keep at it.",
		"Good Job! You found an extremely rare quote, you might just be able to now beat this level!"
};

// Function to get a random quote
std::string getRandomQuote() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, quotes.size() - 1);
    return quotes[dis(gen)];
}

class $modify(MyMenuLayer, MenuLayer) {

    bool init() {

        if (!MenuLayer::init()) {
            return false;
        }

        auto myButton = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_chatBtn_001.png"),
            this,
            menu_selector(MyMenuLayer::onMyButton)
        );

        auto menu = this->getChildByID("bottom-menu");
        menu->addChild(myButton);

        myButton->setID("quote-button"_spr);

        menu->updateLayout();

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

        //myButton->setPosition({35.f, 90.f});
        myButton->setID("quote-button"_spr);

        auto menu = this->getChildByID("left-button-menu");
        menu->addChild(myButton);
	menu->updateLayout();
    };

    void onMyButton(CCObject*) {
        FLAlertLayer::create("Quote", getRandomQuote().c_str(), "Alright")->show();
    }
};
