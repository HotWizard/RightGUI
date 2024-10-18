#pragma once

#ifndef RIGHTGUI_VECTOR2_HPP
#define RIGHTGUI_VECTOR2_HPP

namespace RightGUI
{
	template<typename T>
    class vector2
    {
      public:
        explicit vector2();

        explicit vector2(const T &x, const T &y);

        const T &X() const, &Y() const;

      private:
        T x = 0, y = 0;
    };
} // namespace RightGUI

#include "vector2.tpp"

#endif // RIGHTGUI_VECTOR2_HPP
