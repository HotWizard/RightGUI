#pragma once

#ifndef RIGHTGUI_VULKAN_HPP
#define RIGHTGUI_VULKAN_HPP

#include "version.hpp"

#include <string>
#include <vulkan/vulkan.h>

#ifdef RIGHTGUI_WINDOWSAPIS_GLFW
#include <GLFW/glfw3.h>
#endif

#define RIGHTGUI_VULKAN
#ifdef RIGHTGUI_VULKAN
namespace RightGUI
{
    namespace vulkan
    {
        extern void init(const std::string &ApplicationName, const version &ApplicationVersion), CreateInstance(),
            clean();
        extern VkInstanceCreateInfo &GetInstanceCreateInfo();
    } // namespace vulkan
} // namespace RightGUI
#endif

#endif // RIGHTGUI_VULKAN_HPP
