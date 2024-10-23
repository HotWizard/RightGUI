#include "../include/version.hpp"

RightGUI::version::version(const short &x, const short &y, const short &z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void RightGUI::version::SetX(const short &x)
{
    this->x = x;
}

void RightGUI::version::SetY(const short &y)
{
    this->y = y;
}

void RightGUI::version::SetZ(const short &z)
{
    this->z = z;
}

const short &RightGUI::version::X()
{
    return x;
}

const short &RightGUI::version::Y()
{
    return y;
}

const short &RightGUI::version::Z()
{
    return z;
}
