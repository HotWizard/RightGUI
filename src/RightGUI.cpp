#include "../include/RightGUI.hpp"

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

namespace RightGUI
{
    struct settings
    {
        void SetApplicationName(const std::string &name)
        {
            ApplicationName = name;
        }

        void SetApplicationVersion(const version &ApplicationVersion)
        {
            this->ApplicationVersion = ApplicationVersion;
        }

        const std::string &GetApplicationName() const
        {
            return ApplicationName;
        }

        const std::string &GetEngineName() const
        {
            return EngineName;
        };

        const version &GetApplicationVersion() const
        {
            return ApplicationVersion;
        }

        const version &GetEngineVersion() const
        {
            return EngineVersion;
        };

      private:
        std::string ApplicationName, EngineName;
        version ApplicationVersion, EngineVersion;

      public:
        settings() = default;
    } settings{};

    namespace VulkanStuff
    {
        inline VkApplicationInfo VulkanApplicationInfo{};
    }
} // namespace RightGUI

inline void InitVulkanApplicationInfo()
{
    using namespace RightGUI::VulkanStuff;

    RightGUI::version ApplicationVersion = RightGUI::ApplicationSettings::GetVersion(),
                      EngineVersion = RightGUI::settings.GetEngineVersion();

    VulkanApplicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    VulkanApplicationInfo.pApplicationName = RightGUI::ApplicationSettings::GetName().c_str();
    VulkanApplicationInfo.applicationVersion =
        VK_MAKE_VERSION(ApplicationVersion.X(), ApplicationVersion.Y(), ApplicationVersion.Z());
    VulkanApplicationInfo.pEngineName = RightGUI::settings.GetEngineName().c_str();
    VulkanApplicationInfo.engineVersion = VK_MAKE_VERSION(EngineVersion.X(), EngineVersion.Y(), EngineVersion.Z());
    VulkanApplicationInfo.apiVersion = VK_VERSION_1_3;
}

RightGUI::version RightGUI::GetVersion()
{
    return settings.GetEngineVersion();
}

void RightGUI::init()
{
    InitVulkanApplicationInfo();
}

void RightGUI::ApplicationSettings::SetName(const std::string &name)
{
    settings.SetApplicationName(name);
}

void RightGUI::ApplicationSettings::SetVersion(const version &ApplicationVersion)
{
    settings.SetApplicationVersion(ApplicationVersion);
}

const std::string &RightGUI::ApplicationSettings::GetName()
{
    return settings.GetApplicationName();
}

const RightGUI::version &RightGUI::ApplicationSettings::GetVersion()
{
    return settings.GetApplicationVersion();
}
