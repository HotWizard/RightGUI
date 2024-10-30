#ifndef RIGHTGUI_WINDOWSAPIS_GLFW_HPP
#define RIGHTGUI_WINDOWSAPIS_GLFW_HPP

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include <functional>

#include "../vector2.hpp"
#include "../version.hpp"

namespace RightGUI
{
    namespace WindowsAPIs
    {
        namespace GLFW
        {
            extern void init(), create(const vector2<short> size, const std::string &title),
                display(const std::vector<std::function<void()>> &functions), close(), clean(),
                InitExtensions(VkInstanceCreateInfo &VulkanInstanceCreateInfo);

            const version GetVersion();
        } // namespace GLFW
    } // namespace WindowsAPIs
} // namespace RightGUI

#endif // RIGHTGUI_WINDOWSAPIS_GLFW_HPP
