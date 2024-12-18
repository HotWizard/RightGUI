add_rules("mode.debug", "mode.release")
add_languages("c++23")

add_requires(
    "glfw3",
    "vulkan",
    {system = true}
)

target("RightGUI")
    set_kind("static")
    add_files(
        "sources/*.cpp",
        "sources/*/*.cpp"
    )
    add_packages(
        "glfw3",
        "vulkan"
    )
