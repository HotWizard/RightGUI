#include "../includes/version.hpp"

RightGUI::version::version(const int &major, const int &minor, const int &revision)
{
    _major = major;
    _minor = minor;
    _revision = revision;
}

RightGUI::version::version(const version &_version)
{
    set(_version.major(), _version.minor(), _version.revision());
}

RightGUI::version::~version()
{
    _major = 0;
    _minor = 0;
    _revision = 0;
}

const int &RightGUI::version::major() const
{
    return _major;
}

const int &RightGUI::version::minor() const
{
    return _minor;
}

const int &RightGUI::version::revision() const
{
    return _revision;
}

void RightGUI::version::set(const version &_version)
{
    _major = _version.major();
    _minor = _version.minor();
    _revision = _version.revision();
}

void RightGUI::version::set(const int &major, const int &minor, const int &revision)
{
    set(version(major, minor, revision));
}

void RightGUI::version::SetMajor(const int &major)
{
    _major = major;
}

void RightGUI::version::SetMinor(const int &minor)
{
    _minor = minor;
}

void RightGUI::version::SetRevision(const int &revision)
{
    _revision = revision;
}

RightGUI::version &RightGUI::version::operator=(const version &_version) noexcept
{
    set(_version);
    return *this;
}
