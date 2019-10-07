set(build_architecture ${architecture} CACHE STRING "")

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)

    if (${build_architecture} STREQUAL x86)

        set(CMAKE_SYSTEM_NAME Linux)
        set(CMAKE_C_COMPILER gcc)
        set(CMAKE_CXX_COMPILER g++)

    else()

        set(CMAKE_SYSTEM_NAME Generic)
        set(CMAKE_C_COMPILER arm-none-eabi-gcc)
        set(CMAKE_CXX_COMPILER arm-none-eabi-g++)

        set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

    endif()

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/binary)

endif()