project(moonVeilSrc LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
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
  "scene/menuScene/menuScene.h"
  "scene/menuScene/menuScene.cpp"
  "scene/pauseScene/pauseScene.h"
  "scene/pauseScene/pauseScene.cpp"
  "scene/gameScene/gameScene.h"
  "scene/gameScene/gameScene.cpp"
  "resourceManager/resourceManager.h"
  "resourceManager/resourceManager.cpp"
  "entity/entity.h"
  "entity/entity.cpp"
  "characters/david/david.h"
  "characters/david/david.cpp"
  "characters/galmar/galmar.cpp"
  "characters/galmar/galmar.h"
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
  "tileMap/tileMap.h"
  "tileMap/tileMap.cpp"
  "abilities/defaultAttack/defaultAttack.h"
  "abilities/defaultAttack/defaultAttack.cpp"
  "characters/bloodClaws/bloodClaws.h"
  "characters/bloodClaws/bloodClaws.cpp"
  "characters/floralWretch/floralWretch.h"
  "characters/floralWretch/floralWretch.cpp"
  "characters/maidenMaw/maidenMaw.h"
  "characters/maidenMaw/maidenMaw.cpp"
  "characters/slug/slug.h"
  "characters/slug/slug.cpp"
  "characters/eyeGore/eyeGore.h"
  "characters/eyeGore/eyeGore.cpp"
  "characters/steelBound/steelBound.h"
  "characters/steelBound/steelBound.cpp"
  "gameTimer/gameTimer.h"
  "gameTimer/gameTimer.cpp"
  "abilities/poisonousGas/poisonousGas.h"
  "abilities/poisonousGas/poisonousGas.cpp"
  "button/button.h"
  "button/button.cpp"
  "scene/settingsScene/settingsScene.cpp"
  "scene/settingsScene/settingsScene.h"
  "../external/raygui.h"
  "scene/deathScene/deathScene.cpp"
  "scene/deathScene/deathScene.h"

  "scene/heroSelectionScene/heroSelectionScene.cpp"
  "scene/heroSelectionScene/heroSelectionScene.h"
  "scene/mapSelectionScene/mapSelectionScene.h"
  "scene/mapSelectionScene/mapSelectionScene.cpp"

  "../external/simpleini/SimpleIni.h"

  "settings/settings.h"
  "settings/settings.cpp"
  "abilities/fireBallMonster/fireBallMonster.h"
  "abilities/fireBallMonster/fireBallMonster.cpp"
  "abilities/fireStorm/fireStorm.cpp"
  "abilities/fireStorm/fireStorm.h"

  "spawner/spawner.h"
  "spawner/spawner.cpp"
  "scene/congratulationsScene/congratulationsScene.h"
  "scene/congratulationsScene/congratulationsScene.cpp"
)

target_link_libraries(moonVeilSrc PRIVATE spdlog::spdlog)
target_link_libraries(moonVeilSrc PRIVATE raylib imgui )
target_link_libraries(moonVeilSrc PRIVATE rlImGui)
target_link_libraries(moonVeilSrc PRIVATE raylib-tmx)
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