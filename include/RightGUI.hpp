#pragma once

#ifndef RIGHTGUI_HPP
#define RIGHTGUI_HPP

#include "version.hpp"

#include <string>

namespace RightGUI
{
    version GetVersion();

    void init();

    namespace ApplicationSettings
    {
        void SetName(const std::string &name), SetVersion(const version &ApplicationVersion);

        const std::string &GetName();

        const version &GetVersion();
    } // namespace ApplicationSettings
} // namespace RightGUI

#endif // RIGHTGUI_HPP
