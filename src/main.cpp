#include <Geode/Geode.hpp>
#include <Geode/modify/SetupEditTriggerPopup.hpp>

using namespace geode::prelude;

class $modify(MySetupEditTriggerPopup, SetupEditTriggerPopup) {
    // Упрощённый перехват кнопки добавления группы
    void onAddGroup(cocos2d::CCObject* sender) {
        // Вызываем оригинальное добавление группы без всплывающих окон,
        // чтобы проверить, работает ли сам перехват в игре
        SetupEditTriggerPopup::onAddGroup(sender);
        
        // Сразу выводим сообщение на экран
        Notification::create("Group Added!", NotificationIcon::Success)->show();
    }
};
