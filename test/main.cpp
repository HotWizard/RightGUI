#include "../includes/RightGUI.hpp"

#define RIGHTGUI_WINDOWSAPIS_GLFW
#include "../includes/WindowsAPIs.hpp"

#include <cstdlib>
#include <iostream>

using namespace std;

inline vector<function<void()>> functions;

inline void InitVulkan()
{
    RightGUI::vulkan::init("RightGUI", RightGUI::version(0, 0, 1));
}

inline void InitGLFW()
{
    RightGUI::WindowsAPIs::GLFW::init();
    RightGUI::WindowsAPIs::GLFW::InitExtensions(RightGUI::vulkan::GetInstanceCreateInfo());
}

inline void init()
{
    InitVulkan();

    InitGLFW();
}

inline void clean()
{
    RightGUI::vulkan::clean();

    RightGUI::WindowsAPIs::GLFW::clean();
}

int main(void)
{
    init();

    RightGUI::vulkan::CreateInstance();

    RightGUI::WindowsAPIs::GLFW::create(RightGUI::vector2<short>(800, 600), "RightGUI");
    RightGUI::WindowsAPIs::GLFW::display(functions);

    clean();
}
