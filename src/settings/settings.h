#pragma once
#include "../../external/simpleini/SimpleIni.h"

struct Controls
{
    int moveLeft;
    int moveRight;
    int moveUp;
    int moveDown;
    int dash;
    int thirdSpell;
};

namespace SettingsGlobal
{
extern Controls g_controls;
extern float g_volume;


void LoadInputSettings();
void SaveInputSettings();
} // namespace SettingsGlobal
