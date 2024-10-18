add_rules("mode.debug", "mode.release")
add_languages("c++23")

target("RightGUI")
	set_kind("static")
	add_files("src/*.cpp")
