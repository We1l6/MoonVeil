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
  "tileMap/tileMap.h"
  "tileMap/tileMap.cpp"
  "game/game.h"
  "game/game.cpp"
  "player/player.h"
  "player/player.cpp"
  "scene/scene.h"
  "scene/menuScene.h"
  "scene/menuScene.cpp"
  "scene/pauseScene.h"
  "scene/pauseScene.cpp"
  "scene/gameScene.h"
  "scene/gameScene.cpp"
  "resourceManager/resourceManager.h"
  "resourceManager/resourceManager.cpp"
  "entity/entity.h"
  "entity/entity.cpp"
  "characters/david/david.h"
  "characters/david/david.cpp"
  "abilities/abilities.h"
  "abilities/abilities.cpp"
  "abilities/abilities.h"
  "abilities/abilities.cpp"
  "abilities/fireBall/fireBall.h"
  "abilities/fireBall/fireBall.cpp"
  "gameObject/gameObject.h"
  "gameObject/gameObject.cpp"
  "cameraController/cameraController.h"
  "cameraController/cameraController.cpp"
  "collisionSystem/collisionSystem.h"
  "collisionSystem/collisionSystem.cpp"
  "interface/HUD/hud.h"
  "interface/HUD/hud.cpp"
  "enemy/enemy.h"
  "enemy/enemy.cpp"
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