template <class T> RightGUI::vector2<T>::vector2()
{
}

template <typename T> RightGUI::vector2<T>::vector2(const T &x, const T &y) : x(x), y(y)
{
}

template <typename T> const T &RightGUI::vector2<T>::X() const
{
    return x;
}

template <typename T> const T &RightGUI::vector2<T>::Y() const
{
    return y;
}
