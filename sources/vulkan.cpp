#define RIGHTGUI_VULKAN
#include "../includes/vulkan.hpp"
#include "../includes/version.hpp"

#include <vulkan/vulkan.h>
#include <string>
#include <stdexcept>
#include <vector>

namespace RightGUI
{
    namespace vulkan
    {
        namespace stuff
        {
            VkInstance instance;
            VkApplicationInfo ApplicationInfo{};
            VkInstanceCreateInfo InstanceCreateInfo{};
            VkResult result;
        } // namespace stuff

        namespace ValidationLayer
        {

            const std::vector<const char *> ValidationLayers = {"VK_LAYER_KHRONOS_validation"};

#ifdef NDEBUG
            const bool EnableValidationLayers = false;
#else
            const bool EnableValidationLayers = true;
#endif
        } // namespace ValidationLayer
    } // namespace vulkan
} // namespace RightGUI

inline bool VulkanValidationLayerSupported()
{
    uint32_t LayerCount;

    vkEnumerateInstanceLayerProperties(&LayerCount, NULL);

    std::vector<VkLayerProperties> AvailableLayers(LayerCount);
    vkEnumerateInstanceLayerProperties(&LayerCount, AvailableLayers.data());

    for (const std::string &LayerName : RightGUI::vulkan::ValidationLayer::ValidationLayers)
    {
        bool found = false;

        for (const auto &LayerProperties : AvailableLayers)
        {
            if (LayerName == LayerProperties.layerName)
            {
                found = true;
                break;
            }
        }

        if (!found)
            return false;
    }

    return true;
}

inline void InitApplicationInfo(const std::string &ApplicationName, const RightGUI::version &ApplicationVersion)
{
    VkApplicationInfo &VAI = RightGUI::vulkan::stuff::ApplicationInfo;

    VAI.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    VAI.pApplicationName = ApplicationName.c_str();
    VAI.applicationVersion =
        VK_MAKE_VERSION(ApplicationVersion.major(), ApplicationVersion.minor(), ApplicationVersion.revision());
    VAI.pEngineName = "RightGUI";
    VAI.engineVersion = VK_MAKE_VERSION(0, 0, 1);
    VAI.apiVersion = VK_API_VERSION_1_0;
}

inline void InitInstanceCreateInfo()
{
    VkInstanceCreateInfo &VICI = RightGUI::vulkan::stuff::InstanceCreateInfo;

    VICI.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    VICI.pApplicationInfo = &RightGUI::vulkan::stuff::ApplicationInfo;

    if (RightGUI::vulkan::ValidationLayer::EnableValidationLayers)
    {
        VICI.enabledLayerCount = static_cast<uint32_t>(RightGUI::vulkan::ValidationLayer::ValidationLayers.size());
        VICI.ppEnabledLayerNames = RightGUI::vulkan::ValidationLayer::ValidationLayers.data();
    }
    else
        VICI.enabledLayerCount = 0;
}

inline void InitValidationLayer()
{
    if (RightGUI::vulkan::ValidationLayer::EnableValidationLayers && !VulkanValidationLayerSupported())
        throw std::runtime_error("Vulkan validation layers requested, but not available!");
}

void RightGUI::vulkan::init(const std::string &ApplicationName, const version &ApplicationVersion)
{
    InitValidationLayer();
    InitApplicationInfo(ApplicationName, ApplicationVersion);
}

VkInstanceCreateInfo &RightGUI::vulkan::GetInstanceCreateInfo()
{
    return RightGUI::vulkan::stuff::InstanceCreateInfo;
}

void RightGUI::vulkan::CreateInstance()
{
    if ((RightGUI::vulkan::stuff::result = vkCreateInstance(&RightGUI::vulkan::stuff::InstanceCreateInfo, NULL,
                                                            &RightGUI::vulkan::stuff::instance)) != VK_SUCCESS)
        throw std::runtime_error("Failed to create a Vulkan instance.");
}

void RightGUI::vulkan::clean()
{
    vkDestroyInstance(RightGUI::vulkan::stuff::instance, NULL);
}
