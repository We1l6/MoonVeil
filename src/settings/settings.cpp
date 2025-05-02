#include "settings.h"

Controls SettingsGlobal::g_controls = {};
float SettingsGlobal::g_volume = 100.0f;


void SettingsGlobal::LoadInputSettings()
{
    CSimpleIniA ini;
    ini.SetUnicode();
    ini.LoadFile("settings.ini");

    SettingsGlobal::g_volume =
        (float)ini.GetDoubleValue("Audio", "Volume", 80.0f);

    SettingsGlobal::g_controls.moveLeft =
        ini.GetLongValue("Controls", "MoveLeft", 65);
    SettingsGlobal::g_controls.moveRight =
        ini.GetLongValue("Controls", "MoveRight", 68);
    SettingsGlobal::g_controls.moveUp =
        ini.GetLongValue("Controls", "MoveUp", 87);
    SettingsGlobal::g_controls.moveDown =
        ini.GetLongValue("Controls", "MoveDown", 83);
    SettingsGlobal::g_controls.dash = ini.GetLongValue("Controls", "Jump", 32);
    SettingsGlobal::g_controls.thirdSpell =
        ini.GetLongValue("Controls", "Interact", 69);
}

void SettingsGlobal::SaveInputSettings()
{
    CSimpleIniA ini;
    ini.SetUnicode();

    ini.SetDoubleValue("Audio", "Volume",
                       static_cast<int>(SettingsGlobal::g_volume));
    ini.SetLongValue("Controls", "MoveLeft",
                     SettingsGlobal::g_controls.moveLeft);
    ini.SetLongValue("Controls", "MoveRight",
                     SettingsGlobal::g_controls.moveRight);
    ini.SetLongValue("Controls", "MoveUp", SettingsGlobal::g_controls.moveUp);
    ini.SetLongValue("Controls", "MoveDown",
                     SettingsGlobal::g_controls.moveDown);
    ini.SetLongValue("Controls", "Jump", SettingsGlobal::g_controls.dash);
    ini.SetLongValue("Controls", "Interact",
                     SettingsGlobal::g_controls.thirdSpell);

    ini.SaveFile("settings.ini");
}