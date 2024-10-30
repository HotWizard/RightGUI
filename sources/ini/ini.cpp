#include "../../includes/ini/ini.hpp"

#include <filesystem>
#include <fstream>
#include <functional>
#include <vector>

namespace RightGUI
{
    namespace INIRules
    {
        std::vector<std::function<bool(std::string str)>> variable, ns;
    }

    namespace INI
    {
        struct VariableStructure
        {
            std::string name, value;
        };

        struct NamespaceStructure
        {
            std::string name;
            std::vector<VariableStructure> variables;
        };

        struct structure
        {
            std::vector<VariableStructure> variables;
            std::vector<NamespaceStructure> namespaces;
        } structure;
    } // namespace INI
} // namespace RightGUI

inline const std::string StringTrimWhitespaces(const std::string &str)
{
    std::string output;

    for (const auto &i : str)
    {
        if (!std::isspace(i))
            output += i;
    }

    return output;
}

inline void InitVariableRules()
{
    RightGUI::INIRules::variable.push_back([&](std::string str) {
        str = StringTrimWhitespaces(str);

        if (str[0] == '=')
            return false;

        bool a = false, b = false, c = false;

        for (const auto &i : str)
        {
            if (!a)
            {
                if (i == '=')
                    a = true;
            }
            else
            {
                if (i == '"')
                {
                    if (!b && !c)
                        b = true;
                    else if (b && !c)
                        c = true;
                }
            }
        }

        if (!c)
            return false;

        return true;
    });
}

inline void InitNamespaceRules()
{
    RightGUI::INIRules::ns.push_back([&](std::string str) {
        str = StringTrimWhitespaces(str);

        if ((str[0] != '[' && str.back() != ']') || (str[0] != '[' || str.back() != ']'))
            return false;

        return true;
    });
}

const inline bool IsVariable(std::string str)
{
    str = StringTrimWhitespaces(str);

    for (const auto &i : RightGUI::INIRules::variable)
    {
        if (!i(str))
            return false;
    }

    return true;
}

const inline bool IsNamespace(std::string str)
{
    str = StringTrimWhitespaces(str);

    for (const auto &i : RightGUI::INIRules::ns)
    {
        if (!i(str))
            return false;
    }

    return true;
}

const inline std::string GetVariableName(const std::string &str)
{
    std::string output;

    bool b = false;

    for (const auto &i : str)
    {
        if (i == '=')
            break;

        if (!std::isspace(i))
            b = true;

        if (b)
            output += i;
    }

    while (std::isspace(output.back()))
    {
        output.pop_back();
    }

    return output;
}

const inline std::string GetVariableValue(const std::string &str)
{
    std::string output;

    bool a = false;

    for (const auto &i : str)
    {
        if (a && i == '"')
            break;

        if (a)
            output += i;

        if (i == '"')
            a = true;
    }

    return output;
}

const inline std::string GetNamespaceName(const std::string &str)
{
    std::string output;

    bool b = false;

    for (const auto &i : str)
    {
        if (i == '[' && !b)
        {
            b = true;
            continue;
        }

        if (i == ']')
            break;

        if (b)
            output += i;
    }

    return output;
}

inline void ParseFile(const std::string &FilePath)
{
    std::ifstream is(FilePath);

    std::string temp;

    bool ns = false;

    while (std::getline(is, temp))
    {
        if (temp.back() == '\n')
            temp.pop_back();

        if (IsNamespace(temp))
        {
            ns = true;
            RightGUI::INI::structure.namespaces.push_back({GetNamespaceName(temp)});
            continue;
        }

        if (!ns && IsVariable(temp))
            RightGUI::INI::structure.variables.push_back({GetVariableName(temp), GetVariableValue(temp)});
        else if (ns && IsVariable(temp))
            RightGUI::INI::structure.namespaces.back().variables.push_back(
                {GetVariableName(temp), GetVariableValue(temp)});
    }
}

inline void InitRules()
{
    InitVariableRules();
    InitNamespaceRules();
}

RightGUI::ini::ini()
{
    InitRules();
}

RightGUI::ini::ini(const std::string &FilePath)
{
    InitRules();
    open(FilePath);
}

void RightGUI::ini::open(const std::string &FilePath)
{
    if (std::filesystem::exists(FilePath) && std::filesystem::path(FilePath).extension() == ".ini")
        ParseFile(FilePath);
    else if (std::filesystem::path(FilePath).extension() != ".ini")
        throw std::runtime_error("INI file extension must be \".ini\".");
    else
        throw std::runtime_error("Failed to open INI file at \"" + FilePath + "\" path.");
}

const bool RightGUI::ini::exists(const std::string &name) const
{
    for (const auto &i : RightGUI::INI::structure.variables)
    {
        if (i.name == name)
            return true;
    }

    return false;
}

const bool RightGUI::ini::NamespaceExists(const std::string &NamespaceName) const
{
    for (const auto &i : RightGUI::INI::structure.namespaces)
    {
        if (i.name == NamespaceName)
            return true;
    }

    return false;
}

const bool RightGUI::ini::exists(const std::string &NamespaceName, const std::string &name) const
{
    for (const auto &i : RightGUI::INI::structure.namespaces)
    {
        if (i.name == NamespaceName)
        {
            for (const auto &j : i.variables)
            {
                if (j.name == name)
                    return true;
            }
        }
    }

    return false;
}

const std::string RightGUI::ini::get(const std::string &name) const
{
    std::string output;

    for (const auto &i : RightGUI::INI::structure.variables)
    {
        if (i.name == name)
            output = i.value;
    }

    return output;
}

const std::string RightGUI::ini::get(const std::string &NamespaceName, const std::string &name) const
{
    std::string output;

    for (const auto &i : RightGUI::INI::structure.namespaces)
    {
        if (i.name == NamespaceName)
        {
            for (const auto &j : i.variables)
            {
                if (j.name == name)
                    output = j.value;
            }
        }
    }

    return output;
}
