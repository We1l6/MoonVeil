project(moonVeilSrc LANGUAGES CXX)

set(MAIN_SOURCES
    "main.cpp")

set(MAIN_HEADERS
    "main.h")
        
add_executable(moonVeilSrc
  ${MAIN_SOURCES}
  ${MAIN_HEADERS}
  "imGuiManager/imGuiManager.cpp"
  "imGuiManager/imGuiManager.h"
  "loggerManager/loggerManager.cpp"
  "loggerManager/loggerManager.h"
  "imGuiManager/loggerWindow/loggerWindow.cpp"
  "imGuiManager/loggerWindow/loggerWindow.h"
)

target_link_libraries(moonVeilSrc PRIVATE spdlog::spdlog)
target_link_libraries(moonVeilSrc PRIVATE raylib imgui )
target_link_libraries(moonVeilSrc PRIVATE rlImGui)

if(ENABLE_SANITIZE_ADDR OR ENABLE_SANITIZE_UNDEF)
    include(Sanitizers)
    #add_sanitizer_flags()
endif()

if(${ENABLE_WARNINGS})
    target_set_warnings(
        moonVeilSrc
        ${ENABLE_WARNINGS}
        ${ENABLE_WARNINGS_AS_ERRORS}
    )
endif()