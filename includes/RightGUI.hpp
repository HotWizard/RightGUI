#pragma once

#ifndef RIGHTGUI_HPP
#define RIGHTGUI_HPP

#include "vector2.hpp"
#include "version.hpp"
#include "vulkan.hpp"

#include <string>

namespace RightGUI
{
    extern void SetApplicationName(const std::string &ApplicationName),
        SetApplicationVersion(const version &ApplicationVersion);

    extern const std::string &GetApplicationName(), GetCurrentWindowsAPI();

    extern const version &GetApplicationVersion();
} // namespace RightGUI

#endif // RIGHTGUI_HPP
