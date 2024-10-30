add_rules("mode.debug", "mode.release")
add_languages("c++23")

add_requires(
    "glfw3",
    "vulkan",
    {system = true}
)

target("RightGUItest")
    set_kind("binary")
    add_linkdirs(
        "../build/linux/x86_64/release"
    )
    add_links(
        "RightGUI"
    )
    add_files(
        "main.cpp"
    )
    add_packages(
        "glfw3",
        "vulkan"
    )
