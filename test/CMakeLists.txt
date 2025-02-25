project(tests LANGUAGES CXX)

set(TESTS_SOURCES
    template_test.cpp
    calculator_test.cpp)

add_executable(template_test
  ${TESTS_SOURCES}
)

target_link_libraries(template_test PUBLIC Catch2::Catch2WithMain)

