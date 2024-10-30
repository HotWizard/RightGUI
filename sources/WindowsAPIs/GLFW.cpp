#include "../../includes/WindowsAPIs/GLFW.hpp"

#include <stdexcept>

namespace RightGUI
{
    namespace WindowsAPIs
    {
        namespace GLFW
        {
            inline GLFWwindow *window;
            inline uint32_t ExtensionCount = 0;
            inline const char **extensions;
        } // namespace GLFW
    } // namespace WindowsAPIs
} // namespace RightGUI

void RightGUI::WindowsAPIs::GLFW::init()
{
    if (!glfwInit())
        throw std::runtime_error("Couldn't initialize GLFW.");

    if (!glfwVulkanSupported())
        throw std::runtime_error("Vulkan isn't supported.");

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
}

void RightGUI::WindowsAPIs::GLFW::create(const vector2<short> size, const std::string &title)
{
    window = glfwCreateWindow(size.X(), size.Y(), title.c_str(), NULL, NULL);

    if (!window)
        throw std::runtime_error("Failed to create a GLFW window");
}

void RightGUI::WindowsAPIs::GLFW::display(const std::vector<std::function<void()>> &functions)
{
    do
    {
        glfwPollEvents();

        for (const auto &i : functions)
            i();
    } while (!glfwWindowShouldClose(window));
}

void RightGUI::WindowsAPIs::GLFW::close()
{
    window = NULL;
}

void RightGUI::WindowsAPIs::GLFW::clean()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

const RightGUI::version RightGUI::WindowsAPIs::GLFW::GetVersion()
{
    int major, minor, revision;

    glfwGetVersion(&major, &minor, &revision);

    return RightGUI::version(major, minor, revision);
}

void RightGUI::WindowsAPIs::GLFW::InitExtensions(VkInstanceCreateInfo &VulkanInstanceCreateInfo)
{
    RightGUI::WindowsAPIs::GLFW::extensions =
        glfwGetRequiredInstanceExtensions(&RightGUI::WindowsAPIs::GLFW::ExtensionCount);

    VulkanInstanceCreateInfo.enabledExtensionCount = RightGUI::WindowsAPIs::GLFW::ExtensionCount;
    VulkanInstanceCreateInfo.ppEnabledExtensionNames = RightGUI::WindowsAPIs::GLFW::extensions;

    VulkanInstanceCreateInfo.enabledLayerCount = 0;
}
