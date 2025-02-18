set(CALCULATOR_SOURCES 
    "calculator.cpp")

set(CALCULATOR_HEADERS 
    "calculator.h")

add_library(calculator STATIC ${CALCULATOR_SOURCES} ${CALCULATOR_SOURCES})

target_include_directories(calculator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})