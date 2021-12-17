cmake_minimum_required(VERSION 3.15)
project(UB_MOD_ESSENTIALS)

set (MOD_UNLOCALIZED_NAME, "ub_essentials")
file (GLOB_RECURSE UB_MOD_ESSENTIALS_SRC "include/*/*.cpp" "include/*.cpp")

add_library(UB_MOD_ESSENTIALS MODULE
	${UB_MOD_ESSENTIALS_SRC}
)

if(MSVC)
	source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/include/${MOD_UNLOCALIZED_NAME} FILES ${UB_MOD_ESSENTIALS_SRC})
	target_compile_options(UB_MOD_ESSENTIALS PRIVATE "/MP")
endif()

add_dependencies(UB_MOD_ESSENTIALS
    UB_CAPPUCCINO
    UB_ESPRESSO
    UB_RHR
)

set_target_properties(UB_MOD_ESSENTIALS PROPERTIES OUTPUT_NAME "${MOD_UNLOCALIZED_NAME}")

target_link_libraries(UB_MOD_ESSENTIALS PUBLIC
	UB_CAPPUCCINO
    UB_ESPRESSO
    UB_RHR
	
	glad::glad
	glfw
#	imgui::imgui
	Vulkan::Vulkan
	freetype
)

target_include_directories(UB_MOD_ESSENTIALS PUBLIC
	"${PROJECT_BINARY_DIR}"
	"${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_SOURCE_DIR}/ub_cappuccino/include"
    "${CMAKE_SOURCE_DIR}/ub_espresso/include"
    "${CMAKE_SOURCE_DIR}/ub_rhr/include"

    ${STB_INCLUDE_DIRS}
	${RAPIDJSON_INCLUDE_DIRS}
	${VULKAN_INCLUDE_DIRS}
)

add_custom_command(
	TARGET UB_MOD_ESSENTIALS POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
	$<TARGET_FILE:UB_MOD_ESSENTIALS>
	$<TARGET_FILE_DIR:UB_CLIENT>/mods/
)