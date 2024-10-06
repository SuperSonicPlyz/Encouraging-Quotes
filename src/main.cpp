#include <Geode/Geode.hpp>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/EditorPauseLayer.hpp>
#include "cocos2d.h"
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {

	bool init() {

		if (!MenuLayer::init()) {
			return false;
		}

		log::debug("Hello from my MenuLayer::init hook! This layer has {} children.", this->getChildrenCount());

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
    // List of possible quotes
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
		"Good Job! You found an extremely rare quote, you might just be able to now beat this level!",
		"You're stronger than you think. just take it one jump at a time."
		"Progress isn't always obvious, but you're moving forward."
		"Every fail brings you one step closer to the win."
		"Stay determined, and you'll find your way through."
		"You've faced tough challenges before-this is no different."
		"A little persistence goes a long way. Keep it up!"
		"You're capable of more than you realize. keep trying."
		"You've got the courage to keep going, and that's what matters."
		"Every attempt teaches you something new. Embrace it."
		"Don't let frustration get in the way. you're getting better."
		"Remember, it's okay to struggle. It just means you're growing."
		"You're doing amazing, even if it doesn't feel like it yet."
		"The harder the struggle, the sweeter the victory. Keep going!"
		"Stay patient, stay focused, and you will succeed."
		"Believe in yourself, even when it seems impossible."
		"The more you try, the closer you are to beating it."
		"Mistakes are part of the journey to success."
		"Every setback is a setup for a stronger comeback."
		"You're on the right path. just keep moving forward."
		"Remember how far you've come, not just how far you have to go."
		"Each fail is a chance to improve. You're getting there!"
		"You have what it takes to beat this. Keep going."
		"The struggle is worth it. every attempt matters."
		"Don't let a little difficulty stop you. You're tougher than that."
		"You're getting better, even if it doesn't always feel like it."
		"Focus on the progress you've made, not just the obstacles."
		"The key is to keep trying, no matter what."
		"You've overcome tough moments before. you can do it again."
		"No one ever succeeded by giving up. Keep at it!"
		"Each attempt is making you stronger. Don't stop now."
		"You're capable of more than you think. Trust yourself."
		"Progress is still progress, no matter how small."
		"You've got this. one step, one jump at a time."
		"The only way to fail is to stop trying."
		"Remember, every expert was once at your level."
		"You're building skills with every jump. Keep it up!"
		"Persistence beats difficulty every time. Keep pushing!"
		"It's okay to take breaks, but always come back stronger."
		"Don't let a mistake define you. let it teach you."
		"The finish line is closer than it seems. Keep moving!"
		"You're not just trying, you're improving. Keep going!"
		"Stay calm, stay focused. you're almost there."
		"Don't give up. Your determination is your strength."
		"You can handle this. One more try."
		"Mistakes are just part of the learning process. You've got this."
		"You've come so far. don't let this stop you now."
		"Even if it's tough, you're tougher. Keep trying."
		"The more you practice, the better you'll be. Keep at it!"
		"Every click gets you closer to the goal."
		"No obstacle is too big when you're determined to win."
		"You're stronger than you think. just take it one jump at a time."
		"Progress isn't always obvious, but you're moving forward."
		"Every fail brings you one step closer to the win."
		"Stay determined, and you'll find your way through."
		"You've faced tough challenges before. this is no different."
		"A little persistence goes a long way. Keep it up!"
		"You're capable of more than you realize. keep trying."
		"You've got the courage to keep going, and that's what matters."
		"Every attempt teaches you something new. Embrace it."
		"Don't let frustration get in the way. you're getting better."
		"Remember, it's okay to struggle. It just means you're growing."
		"You're doing amazing, even if it doesn't feel like it yet."
		"The harder the struggle, the sweeter the victory. Keep going!"
		"Stay patient, stay focused, and you will succeed."
		"Believe in yourself, even when it seems impossible."
		"The more you try, the closer you are to beating it."
		"Mistakes are part of the journey to success."
		"Every setback is a setup for a stronger comeback."
		"You're on the right path. just keep moving forward."
		"Remember how far you've come, not just how far you have to go."
		"Each fail is a chance to improve. You're getting there!"
		"You have what it takes to beat this. Keep going."
		"The struggle is worth it. every attempt matters."
		"Don't let a little difficulty stop you. You're tougher than that."
		"You're getting better, even if it doesn't always feel like it."
		"Focus on the progress you've made, not just the obstacles."
		"The key is to keep trying, no matter what."
		"You've overcome tough moments before. you can do it again."
		"No one ever succeeded by giving up. Keep at it!"
		"Each attempt is making you stronger. Don't stop now."
		"You're capable of more than you think. Trust yourself."
		"Progress is still progress, no matter how small."
		"You've got this. one step, one jump at a time."
		"The only way to fail is to stop trying."
		"Remember, every expert was once at your level."
		"You're building skills with every jump. Keep it up!"
		"Persistence beats difficulty every time. Keep pushing!"
		"It's okay to take breaks, but always come back stronger."
		"Don't let a mistake define you. let it teach you."
		"The finish line is closer than it seems. Keep moving!"
		"You're not just trying, you're improving. Keep going!"
		"Stay calm, stay focused. you're almost there."
		"Don't give up. Your determination is your strength."
		"You can handle this. One more try."
		"Mistakes are just part of the learning process. You've got this."
		"You've come so far. don't let this stop you now."
		"Even if it's tough, you're tougher. Keep trying."
		"The more you practice, the better you'll be. Keep at it!"
		"Every click gets you closer to the goal."
		"No obstacle is too big when you're determined to win."
	};

    // Seed number generator
    std::srand(std::time(0));

    // Get random idx
    int randomIndex = std::rand() % quotes.size();

    // Quote Alert
    FLAlertLayer::create("Quote", quotes[randomIndex].c_str(), "Alright")->show();
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

		myButton->setPosition({35.f, 90.f});
		myButton->setID("quote-button"_spr);
		myButton->setit

		CCMenu* menu = CCMenu::create();
		menu->setPosition({0, 0});

		menu->addChild(myButton);
		this->addChild(menu);
	};

	
	void onMyButton(CCObject*) {
    // List of possible quotes
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
		"Congragulations! You found an extremely rare quote, you might just be able to now beat this level!",
		"You're stronger than you think. just take it one jump at a time."
		"Progress isn't always obvious, but you're moving forward."
		"Every fail brings you one step closer to the win."
		"Stay determined, and you'll find your way through."
		"You've faced tough challenges before. this is no different."
		"A little persistence goes a long way. Keep it up!"
		"You're capable of more than you realize. keep trying."
		"You've got the courage to keep going, and that's what matters."
		"Every attempt teaches you something new. Embrace it."
		"Don't let frustration get in the way. you're getting better."
		"Remember, it's okay to struggle. It just means you're growing."
		"You're doing amazing, even if it doesn't feel like it yet."
		"The harder the struggle, the sweeter the victory. Keep going!"
		"Stay patient, stay focused, and you will succeed."
		"Believe in yourself, even when it seems impossible."
		"The more you try, the closer you are to beating it."
		"Mistakes are part of the journey to success."
		"Every setback is a setup for a stronger comeback."
		"You're on the right path. just keep moving forward."
		"Remember how far you've come, not just how far you have to go."
		"Each fail is a chance to improve. You're getting there!"
		"You have what it takes to beat this. Keep going."
		"The struggle is worth it. every attempt matters."
		"Don't let a little difficulty stop you. You're tougher than that."
		"You're getting better, even if it doesn't always feel like it."
		"Focus on the progress you've made, not just the obstacles."
		"The key is to keep trying, no matter what."
		"You've overcome tough moments before. you can do it again."
		"No one ever succeeded by giving up. Keep at it!"
		"Each attempt is making you stronger. Don't stop now."
		"You're capable of more than you think. Trust yourself."
		"Progress is still progress, no matter how small."
		"You've got this. one step, one jump at a time."
		"The only way to fail is to stop trying."
		"Remember, every expert was once at your level."
		"You're building skills with every jump. Keep it up!"
		"Persistence beats difficulty every time. Keep pushing!"
		"It's okay to take breaks, but always come back stronger."
		"Don't let a mistake define you. let it teach you."
		"The finish line is closer than it seems. Keep moving!"
		"You're not just trying, you're improving. Keep going!"
		"Stay calm, stay focused. you're almost there."
		"Don't give up. Your determination is your strength."
		"You can handle this. One more try."
		"Mistakes are just part of the learning process. You've got this."
		"You've come so far. don't let this stop you now."
		"Even if it's tough, you're tougher. Keep trying."
		"The more you practice, the better you'll be. Keep at it!"
		"Every click gets you closer to the goal."
		"No obstacle is too big when you're determined to win."
		"You're stronger than you think. just take it one jump at a time."
		"Progress isn't always obvious, but you're moving forward."
		"Every fail brings you one step closer to the win."
		"Stay determined, and you'll find your way through."
		"You've faced tough challenges before. this is no different."
		"A little persistence goes a long way. Keep it up!"
		"You're capable of more than you realize. keep trying."
		"You've got the courage to keep going, and that's what matters."
		"Every attempt teaches you something new. Embrace it."
		"Don't let frustration get in the way. you're getting better."
		"Remember, it's okay to struggle. It just means you're growing."
		"You're doing amazing, even if it doesn't feel like it yet."
		"The harder the struggle, the sweeter the victory. Keep going!"
		"Stay patient, stay focused, and you will succeed."
		"Believe in yourself, even when it seems impossible."
		"The more you try, the closer you are to beating it."
		"Mistakes are part of the journey to success."
		"Every setback is a setup for a stronger comeback."
		"You're on the right path. just keep moving forward."
		"Remember how far you've come, not just how far you have to go."
		"Each fail is a chance to improve. You're getting there!"
		"You have what it takes to beat this. Keep going."
		"The struggle is worth it. every attempt matters."
		"Don't let a little difficulty stop you. You're tougher than that."
		"You're getting better, even if it doesn't always feel like it."
		"Focus on the progress you've made, not just the obstacles."
		"The key is to keep trying, no matter what."
		"You've overcome tough moments before. you can do it again."
		"No one ever succeeded by giving up. Keep at it!"
		"Each attempt is making you stronger. Don't stop now."
		"You're capable of more than you think. Trust yourself."
		"Progress is still progress, no matter how small."
		"You've got this. one step, one jump at a time."
		"The only way to fail is to stop trying."
		"Remember, every expert was once at your level."
		"You're building skills with every jump. Keep it up!"
		"Persistence beats difficulty every time. Keep pushing!"
		"It's okay to take breaks, but always come back stronger."
		"Don't let a mistake define you. let it teach you."
		"The finish line is closer than it seems. Keep moving!"
		"You're not just trying, you're improving. Keep going!"
		"Stay calm, stay focused. you're almost there."
		"Don't give up. Your determination is your strength."
		"You can handle this. One more try."
		"Mistakes are just part of the learning process. You've got this."
		"You've come so far. don't let this stop you now."
		"Even if it's tough, you're tougher. Keep trying."
		"The more you practice, the better you'll be. Keep at it!"
		"Every click gets you closer to the goal."
		"No obstacle is too big when you're determined to win."
	};

    // Seed number generator
    std::srand(std::time(0));

    // Get random idx
    int randomIndex = std::rand() % quotes.size();

    // Quote Alert
    FLAlertLayer::create("Quote", quotes[randomIndex].c_str(), "Alright")->show();
	}
};
