cmake_minimum_required(VERSION 3.25)

# Это имя твоего проекта для компилятора
project(AutoConfirm)

# Подключаем библиотеки Geode
find_package(Geode REQUIRED)

# Указываем, какие файлы на C++ нужно собрать (наш main.cpp из папки src)
add_geode_mod(
    ${PROJECT_NAME}
    GD
    src/main.cpp
)
