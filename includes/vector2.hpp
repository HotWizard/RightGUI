#pragma once

#ifndef RIGHTGUI_VECTOR2_HPP
#define RIGHTGUI_VECTOR2_HPP

namespace RightGUI
{
    template <typename T> struct vector2
    {
        vector2() = default;

        vector2(const T &x, const T &y);

        vector2(const vector2 &_T);

        ~vector2();

        const T &X() const, &Y() const;

        vector2 &operator=(const vector2 &_T);

        void SetX(const T &x), SetY(const T &y);

      private:
        T x = 0, y = 0;
    };
} // namespace RightGUI

#include "vector2.tpp"

#endif // RIGHTGUI_VECTOR2_HPP
