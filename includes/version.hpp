#pragma once

#ifndef RIGHTGUI_VERSION_HPP
#define RIGHTGUI_VERSION_HPP

namespace RightGUI
{
    union version {
        version() = default;

        version(const int &major, const int &minor, const int &revision);

        version(const version &_version);

        ~version();

        const int &major() const, &minor() const, &revision() const;

        void set(const version &_version), set(const int &major, const int &minor, const int &revision),
            SetMajor(const int &major), SetMinor(const int &minor), SetRevision(const int &revision);

        version &operator=(const version &_version) noexcept;

      private:
        int _major, _minor, _revision;
    };
} // namespace RightGUI

#endif // RIGHTGUI_VERSION_HPP
