cmake_minimum_required(VERSION 3.20)

project(Seminar12 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra)

# 1. Указываем CMake, где лежит корень FLTK (обратите внимание: без \bin в конце)
# Используем прямые слеши (/) для совместимости.
# Лучше задать FLTK_DIR — это надёжнее для find_package(FLTK CONFIG),
# но CMAKE_PREFIX_PATH тоже работает, если путь корректен.
set(CMAKE_PREFIX_PATH "c:/FLTK_install")
set(FLTK_DIR "c:/FLTK_install" CACHE FILEPATH "FLTK install root")

# 2. Ищем FLTK в режиме CONFIG (это заставит CMake искать FLTKConfig.cmake)
find_package(FLTK CONFIG REQUIRED)

set(TARGET "checker_board")

add_executable(
    ${TARGET}
    src/main.cpp
    
    src/Graph_lib/Graph.cpp
    src/Graph_lib/GUI.cpp
    src/Graph_lib/Window.cpp

    src/design.cpp
    src/day.cpp

)

# target_include_directories для ваших исходников Graph_lib оставляем
target_include_directories(${TARGET} PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

# 3. Линкуем с современной целью fltk::fltk
# Она автоматически добавит нужные include-директории,
# а также сама подтянет fltk_jpeg, fltk_png, fltk_z и gdiplus на Windows.
# ВАЖНО: fltk::png, fltk::jpeg, fltk::z НЕ нужно указывать вручную —
# они автоматически линкуются через fltk::images. Явное указание
# может привести к ошибкам конфигурации, если эти цели не экспортируются.
target_link_libraries(${TARGET} PRIVATE
    fltk::fltk
    fltk::images      # <-- Правильное имя для библиотеки изображений
    # fltk::gl        # <-- Раскомментируйте ТОЛЬКО если реально используете OpenGL
)

# Копирование ресурсов. Учтите: этот блок копирует ВСЁ содержимое
# исходной папки (включая .cpp, .h, CMakeLists.txt) в build-папку.
# Если нужны только ресурсы (картинки, шрифты) — укажите конкретную подпапку,
# например ${PROJECT_SOURCE_DIR}/resources
