solution("Animation-Calibrator")
	configurations({"Debug", "Release"})

	project("Animation-Calibrator")
		kind("ConsoleApp")
		language("C++")
		files({
			"../include/**.h",
			"../src/**.cpp"
			})
		includedirs({
			"../include",
			"../include/**"
			})
		libdirs({
			"../lib",
			"../lib/**"
			})

		links({
			"SDL2.framework",
			"SDL2_image.framework",
			"OpenGL.framework",
			"TGAEngine"
			})

		configuration("Debug")
			defines({"DEBUG"})

		configuration("Release")
			defines({"NDEBUG"})
