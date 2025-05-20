#include "settingsScene.h"

#define RAYGUI_IMPLEMENTATION
#include "../../../external/raygui.h"

void SettingsScene::HandleInput(float deltaTime) {}


void SettingsScene::Render()
{
    float scale = fmaxf((float)GetScreenWidth() / m_backgroundTexture.width,
                        (float)GetScreenHeight() / m_backgroundTexture.height);
    Vector2 backgroundPos = {
        (GetScreenWidth() - (m_backgroundTexture.width * scale)) * 0.5f,
        (GetScreenHeight() - (m_backgroundTexture.height * scale)) * 0.5f};
    DrawTextureEx(m_backgroundTexture, backgroundPos, 0.0f, scale, WHITE);

    DrawText("Settings", Settings::START_X, Settings::START_Y,
             Settings::TITLE_FONT_SIZE, WHITE);

    Rectangle sliderBounds = {Settings::START_X, Settings::SLIDER_Y,
                              Settings::SLIDER_WIDTH, Settings::SLIDER_HEIGHT};
    GuiSlider(sliderBounds, "", "", &SettingsGlobal::g_volume, 0.0f, 100.0f);

    char volumeText[32];
    sprintf(volumeText, "Volume: %.0f%%", SettingsGlobal::g_volume);
    DrawText(volumeText, sliderBounds.x,
             sliderBounds.y - Settings::SLIDER_HEIGHT,
             Settings::CONTROL_FONT_SIZE, WHITE);

    float controlsY = Settings::CONTROLS_START_Y;
    DrawText("Controls:", Settings::START_X, controlsY,
             Settings::LABEL_FONT_SIZE, WHITE);
    controlsY += Settings::CONTROL_SPACING;

    auto drawControlSetting = [&](const char *label, int &key)
    {
        DrawText(label, Settings::START_X, controlsY,
                 Settings::CONTROL_FONT_SIZE, WHITE);

        char keyName[32];
        if (currentlyChangingKey == &key)
        {
            strcpy(keyName, "Press any key...");
        }
        else
        {
            const char *name = GetKeyName(key);
            if (key == KEY_SPACE)
            {
                strcpy(keyName, "SPACE");
            }
            else if (name != nullptr)
            {
                strcpy(keyName, name);
            }
            else
            {
                strcpy(keyName, "Unknown");
            }
        }

        Rectangle buttonBounds = {Settings::START_X + 160, controlsY, 150, 30};
        if (GuiButton(buttonBounds, keyName))
        {
            currentlyChangingKey = &key;
        }

        controlsY += Settings::CONTROL_SPACING;
    };

    drawControlSetting("Move Left:", SettingsGlobal::g_controls.moveLeft);
    drawControlSetting("Move Right:", SettingsGlobal::g_controls.moveRight);
    drawControlSetting("Move Up:", SettingsGlobal::g_controls.moveUp);
    drawControlSetting("Move Down:", SettingsGlobal::g_controls.moveDown);
    drawControlSetting("Dash:", SettingsGlobal::g_controls.dash);
    drawControlSetting("Third spell:", SettingsGlobal::g_controls.thirdSpell);

    float buttonY = GetScreenHeight() - 80;
    constexpr float buttonWidth = 150;
    constexpr float buttonHeight = 40;
    constexpr float spacing = 20;

    Rectangle saveButton = {Settings::START_X, buttonY, buttonWidth,
                            buttonHeight};
    Rectangle backButton = {Settings::START_X + buttonWidth + spacing, buttonY,
                            buttonWidth, buttonHeight};

    if (GuiButton(saveButton, "Save"))
    {
        SettingsGlobal::SaveInputSettings();
    }

    if (GuiButton(backButton, "Back"))
    {
        m_game->ChangeScene(new MenuScene(m_game));
    }
}


void SettingsScene::Update(float deltaTime)
{
    if (currentlyChangingKey)
    {
        for (int key = KEY_NULL + 1; key < KEY_KB_MENU; ++key)
        {
            if (IsKeyPressed(key))
            {
                *currentlyChangingKey = key;
                currentlyChangingKey = nullptr;
                break;
            }
        }
    }
}
