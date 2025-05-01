include_directories(${PROJECT_SOURCE_DIR}/app/desktop/src)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "/opt/Qt/6.8.1/gcc_64/lib/cmake")

find_package(Qt6 REQUIRED COMPONENTS Svg Widgets)
qt_standard_project_setup()

qt_add_executable(vaultage_desktop
    src/main.cpp
	src/ui/main_window/main_window.cpp
	src/ui/settings_window/settings_window.cpp
)

target_link_libraries(vaultage_desktop
	PRIVATE
		Qt6::Svg
		Qt6::Widgets
)

set_target_properties(vaultage_desktop PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)