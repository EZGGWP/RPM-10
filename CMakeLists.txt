# CMakeList.txt: проект CMake для Laba 10 na CMAKE; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("Laba 10 na CMAKE")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (CMakeTarget "Laba 10 na CMAKE.cpp")

add_library (packet "packet.cpp" "packet.h" "packetFactory.cpp" "packetFactory.h" "ruleClass.cpp" "ruleClass.h" "Supportive.h" "trafficPacketHandler.cpp" "trafficPacketHandler.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
