#include "../includes/RightGUI.hpp"
#include "../includes/ini/ini.hpp"

namespace RightGUI
{
    namespace settings
    {
        inline std::string ApplicationName;
        inline version ApplicationVersion;
    } // namespace settings
} // namespace RightGUI

void RightGUI::SetApplicationName(const std::string &ApplicationName)
{
    settings::ApplicationName = ApplicationName;
}

void RightGUI::SetApplicationVersion(const version &ApplicationVersion)
{
    settings::ApplicationVersion = ApplicationVersion;
}

const std::string &RightGUI::GetApplicationName()
{
    return settings::ApplicationName;
}

const std::string RightGUI::GetCurrentWindowsAPI()
{
    ini RightGUISettingsINI("RightGUISettings.ini");

    if (RightGUISettingsINI.exists("CurrentWindowsAPI"))
        return RightGUISettingsINI.get("CurrentWindowsAPI");

    return "";
}

const RightGUI::version &RightGUI::GetApplicationVersion()
{
    return settings::ApplicationVersion;
}
