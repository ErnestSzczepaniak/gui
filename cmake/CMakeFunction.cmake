function(collect_files output)

    set(options)
    set(args)
    set(list_args EXTENSION_COMMON EXTENSION_TARGET EXTENSION_HOST DIRECTORY_COMMON DIRECTORY_TARGET DIRECTORY_HOST)

    cmake_parse_arguments(
        PARSE_ARGV 0
        platform
        "${options}"
        "${args}"
        "${list_args}"
    )

    foreach(directory ${platform_DIRECTORY_COMMON})

        foreach(extension ${platform_EXTENSION_COMMON})
        
            list(APPEND my_list ${directory}*.${extension})

        endforeach()
        
        if (${build_architecture} STREQUAL x86)

            foreach(extension ${platform_EXTENSION_HOST})
        
                list(APPEND my_list ${directory}*.${extension})

            endforeach()

        else()

            foreach(extension ${platform_EXTENSION_TARGET})
        
                list(APPEND my_list ${directory}*.${extension})

            endforeach()

        endif()

    endforeach()

    if (${build_architecture} STREQUAL x86)
        
        foreach(directory ${platform_DIRECTORY_HOST})

            foreach(extension ${platform_EXTENSION_COMMON})

                list(APPEND my_list ${directory}*.${extension})

            endforeach()

            foreach(extension ${platform_EXTENSION_HOST})

                list(APPEND my_list ${directory}*.${extension})

            endforeach()

        endforeach()

    else()

        foreach(directory ${platform_DIRECTORY_TARGET})

            foreach(extension ${platform_EXTENSION_COMMON})

                list(APPEND my_list ${directory}*.${extension})

            endforeach()

            foreach(extension ${platform_EXTENSION_TARGET})

                list(APPEND my_list ${directory}*.${extension})

            endforeach()

        endforeach()
        
    endif()
        
    file(GLOB_RECURSE temp ${my_list})
    set(${output} ${temp} PARENT_SCOPE)

endfunction()

function(target_set)

    set(options COMPILE_DEFINITIONS INCLUDE_DIRECTORIES COMPILE_OPTIONS LINK_OPTIONS COMPILE_FEATURES)
    set(args NAME SCOPE)
    set(list_args COMMON TARGET HOST)

    cmake_parse_arguments(
        PARSE_ARGV 0
        platform
        "${options}"
        "${args}"
        "${list_args}"
    )

    if (${platform_COMPILE_DEFINITIONS})

        if (${build_architecture} STREQUAL x86)
            target_compile_definitions(${platform_NAME} ${platform_SCOPE} build_version=${build_definition_version} ${platform_COMMON} $<$<BOOL:${build_type_debug}>:build_type_debug> ${platform_HOST})
        else()
            target_compile_definitions(${platform_NAME} ${platform_SCOPE} build_version=${build_definition_version} ${platform_COMMON} $<$<BOOL:${build_type_debug}>:build_type_debug> ${platform_TARGET})
        endif()

    endif()

    if (${platform_INCLUDE_DIRECTORIES})

        if (${build_architecture} STREQUAL x86)
            target_include_directories(${platform_NAME} ${platform_SCOPE} ${platform_COMMON} ${platform_HOST})
        else()
            target_include_directories(${platform_NAME} ${platform_SCOPE} ${platform_COMMON} ${platform_TARGET})
        endif()

    endif()

    if (${platform_COMPILE_OPTIONS})

        if (${build_architecture} STREQUAL x86)
            target_compile_options(${platform_NAME} ${platform_SCOPE} ${platform_COMMON} $<$<BOOL:${build_type_debug}>:-g> ${platform_HOST})
        else()
            target_compile_options(${platform_NAME} ${platform_SCOPE} ${platform_COMMON} $<$<BOOL:${build_type_debug}>:-g> ${platform_TARGET})
        endif()

    endif()

    if (${platform_LINK_OPTIONS})

        if (${build_architecture} STREQUAL x86)
            target_link_options(${platform_NAME} ${platform_SCOPE} ${platform_COMMON} ${platform_HOST})
        else()
            target_link_options(${platform_NAME} ${platform_SCOPE} ${platform_COMMON} ${platform_TARGET})
        endif()

    if (${platform_COMPILE_FEATURES})

        if (${build_architecture} STREQUAL x86)
            target_compile_features(${platform_NAME} ${platform_SCOPE} ${platform_COMMON} ${platform_HOST})
        else()
            target_compile_features(${platform_NAME} ${platform_SCOPE} ${platform_COMMON} ${platform_TARGET})
        endif()

    endif()

endif()

endfunction()

function(add)

    set(options LIBRARY EXECUTABLE)
    set(args NAME)
    set(list_args COMMON TARGET HOST)

    cmake_parse_arguments(
        PARSE_ARGV 0
        platform
        "${options}"
        "${args}"
        "${list_args}"
    )

    if (${platform_LIBRARY})
    
        if (${build_architecture} STREQUAL x86)
            add_library(${platform_NAME} STATIC ${platform_COMMON} ${platform_HOST})
        else()
            add_library(${platform_NAME} STATIC ${platform_COMMON} ${platform_TARGET})
        endif()

    endif()

    if (${platform_EXECUTABLE})

        if (${build_architecture} STREQUAL x86)
            add_executable(${platform_NAME} ${platform_COMMON} ${platform_HOST})
        else()
            add_executable(${platform_NAME} ${platform_COMMON} ${platform_TARGET})
        endif()

    endif()

endfunction()

function(output)

    if (${build_output_dump})

        if (${build_architecture} STREQUAL x86)

            add_custom_command(
                TARGET executable.elf POST_BUILD
                COMMAND readelf -S ../binary/executable.elf > ../dump/read_sections.txt
                COMMAND readelf -h ../binary/executable.elf > ../dump/read_headers.txt
                COMMAND readelf -s ../binary/executable.elf > ../dump/read_symbols.txt
                COMMAND objdump -S ../binary/executable.elf > ../dump/dump_assembly.txt
                COMMAND objdump -s ../binary/executable.elf > ../dump/dump_sections_content.txt
                COMMAND objdump -h ../binary/executable.elf > ../dump/dump_sections.txt
                COMMAND objdump -t ../binary/executable.elf > ../dump/dump_symbols.txt
            )
        
        else()
        
            add_custom_command(
                TARGET executable.elf POST_BUILD
                COMMAND arm-none-eabi-readelf -S ../binary/executable.elf > ../dump/read_sections.txt
                COMMAND arm-none-eabi-readelf -h ../binary/executable.elf > ../dump/read_headers.txt
                COMMAND arm-none-eabi-readelf -s ../binary/executable.elf > ../dump/read_symbols.txt
                COMMAND arm-none-eabi-objdump -S ../binary/executable.elf > ../dump/dump_assembly.txt
                COMMAND arm-none-eabi-objdump -s ../binary/executable.elf > ../dump/dump_sections_content.txt
                COMMAND arm-none-eabi-objdump -h ../binary/executable.elf > ../dump/dump_sections.txt
                COMMAND arm-none-eabi-objdump -t ../binary/executable.elf > ../dump/dump_symbols.txt
            )

        endif()

    endif()

    if (${build_output_image})

        if (${build_architecture} STREQUAL x86)

        else()

            add_custom_command(
                TARGET executable.elf POST_BUILD
                COMMAND arm-none-eabi-objcopy -O binary ../binary/executable.elf ../binary/executable.bin
                COMMAND mkimage -A arm -T standalone -C none -a 0 -e 0 -n "executable.elf" -d ../binary/executable.bin ../binary/executable.img
            )

            #invalid on shared folders :(

        endif()

    endif()

endfunction()
