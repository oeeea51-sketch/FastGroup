#include <Geode/Geode.hpp>
#include <Geode/modify/SetupEditTriggerPopup.hpp>

using namespace geode::prelude;

// Модифицируем класс окна настройки триггеров и групп
class $modify(MySetupEditTriggerPopup, SetupEditTriggerPopup) {

    // Перехватываем метод инициализации окна
    bool init(EffectGameObject* object, cocos2d::CCArray* objects) {
        if (!SetupEditTriggerPopup::init(object, objects)) {
            return false;
        }
        return true;
    }

    // Перехватываем функцию добавления группы (кнопка "Add")
    void onAddGroup(cocos2d::CCObject* sender) {
        // Создаем всплывающее окно "Confirm" прямо поверх интерфейса редактора
        geode::createQuickPopup(
            "Confirm",                                 // Заголовок окна
            "Apply this group to the trigger/object?", // Текст вопроса
            "Cancel", "Confirm",                       // Кнопки 1 и 2
            [this, sender](auto, bool btn2) {
                if (btn2) {
                    // Если нажата кнопка "Confirm" (btn2 == true)
                    // Вызываем оригинальную функцию применения группы
                    SetupEditTriggerPopup::onAddGroup(sender);
                    
                    // Выводим красивое уведомление об успешном сохранении
                    Notification::create("Group applied successfully!", NotificationIcon::Success)->show();
                }
            }
        );
    }
};
