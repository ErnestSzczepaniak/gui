#cmake_version
cmake_minimum_required(VERSION 3.15)

#includes
include(cmake/CMakeConfig.cmake)
include(cmake/CMakeToolchain.cmake)
include(cmake/CMakeFunction.cmake)

#project_name
project(gui VERSION ${build_definition_version} LANGUAGES CXX C ASM)

#//---------------------------------------------| collect files |---------------------------------------------//

collect_files(
    source_files
    EXTENSION_COMMON cpp c
    EXTENSION_TARGET s
    DIRECTORY_COMMON source/
)

collect_files(
    architecture_files
    EXTENSION_COMMON cpp c
    EXTENSION_TARGET s
    DIRECTORY_COMMON architecture/${build_architecture}/
)

collect_files(
    library_files
    EXTENSION_COMMON a
    DIRECTORY_COMMON library/
)

collect_files(
    test_files
    EXTENSION_HOST cpp
    DIRECTORY_HOST test/
)

# //---------------------------------------------| add current library |---------------------------------------------//

add(
    LIBRARY
    NAME ${PROJECT_NAME}
    COMMON ${source_files}
)

# //---------------------------------------------| options |---------------------------------------------//

target_set(
    COMPILE_DEFINITIONS
    NAME ${PROJECT_NAME}
    SCOPE PUBLIC
    COMMON ${build_definition_common} 
    TARGET ${build_definition_target} build_platform_target
    HOST ${build_definiton_host} build_platform_host
)

target_set(
    COMPILE_OPTIONS
    NAME ${PROJECT_NAME}
    SCOPE PUBLIC
    COMMON ${build_compile_option_common}
    TARGET ${build_compile_option_target}
    HOST ${build_compile_option_host}
)

target_set(
    INCLUDE_DIRECTORIES
    NAME ${PROJECT_NAME}
    SCOPE PUBLIC
    COMMON ${build_include_common} include/ architecture/${build_architecture}/
    TARGET ${build_include_target}
    HOST ${build_include_host} test/
)
    
target_set(
    COMPILE_FEATURES
    NAME ${PROJECT_NAME}
    SCOPE PUBLIC
    COMMON ${build_compile_feature_common}
    TARGET ${build_compile_feature_target}
    HOST ${build_compile_feature_host}
)

# //---------------------------------------------| create executable |---------------------------------------------//

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)

    add(
        EXECUTABLE
        NAME executable.elf
        COMMON main.cpp ${architecture_files}
        HOST ${test_files}
    )

    target_set(
        LINK_OPTIONS
        NAME executable.elf
        SCOPE PRIVATE
        TARGET --specs=nosys.specs -nostartfiles -T ${CMAKE_SOURCE_DIR}/linker/script.ld 
        -Wl,--defsym=__memory_sdram_size=${build_target_sdram_size}
    )
    
    #input_libraries
    target_link_libraries(executable.elf PRIVATE ${PROJECT_NAME} pthread)
    target_link_libraries(executable.elf PRIVATE ${library_files})

    #external_libraries

    #external_subdirectories

    output()

endif()