template <typename T> RightGUI::vector2<T>::vector2(const T &x, const T &y)
{
    this->x = x;
    this->y = y;
}

template <typename T> RightGUI::vector2<T>::vector2(const vector2 &_T)
{
    x = _T.x;
    y = _T.y;
}

template <typename T> RightGUI::vector2<T>::~vector2()
{
    x = 0;
    y = 0;
}

template <typename T> const T &RightGUI::vector2<T>::X() const
{
    return x;
}

template <typename T> const T &RightGUI::vector2<T>::Y() const
{
    return y;
}

template <typename T> RightGUI::vector2<T> &RightGUI::vector2<T>::operator=(const RightGUI::vector2<T> &_T)
{
    x=_T.x;
    y=_T.y;
    return *this;
}

template <typename T> void RightGUI::vector2<T>::SetX(const T &x)
{
    this->x = x;
}

template <typename T> void RightGUI::vector2<T>::SetY(const T &y)
{
    this->y = y;
}
