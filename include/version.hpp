#pragma once

#ifndef RIGHTGUI_VERSION_HPP
#define RIGHTGUI_VERSION_HPP

namespace RightGUI
{
    struct version
    {
        void SetX(const short &x), SetY(const short &y), SetZ(const short &z);

        const short &X(), &Y(), &Z();

      private:
        short x = 0, y = 0, z = 0;

      public:
        version() = default;
        version(const short &x, const short &y, const short &z);
    };
} // namespace RightGUI

#endif // RIGHTGUI_VERSION_HPP
