#pragma once

#ifndef RIGHTGUI_INI_HPP
#define RIGHTGUI_INI_HPP

#include <string>

namespace RightGUI
{
    struct ini
    {
        ini();

        explicit ini(const std::string &FilePath);

        void open(const std::string &FilePath);

        const bool exists(const std::string &name) const, NamespaceExists(const std::string &NamespaceName) const,
            exists(const std::string &NamespaceName, const std::string &name) const;

        const std::string get(const std::string &name) const,
            get(const std::string &NamespaceName, const std::string &name) const;

      private:
        std::string FilePath;
    };
} // namespace RightGUI

#endif // RIGHTGUI_INI_HPP
