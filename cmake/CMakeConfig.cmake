#architecture
set(architecture                    x86)

#variables
option(build_type_debug ""          on)

#output
option(build_output_dump ""         off)
option(build_output_image ""        off)


#build_target_memory
set(build_target_sdram_size         1024M)

#build_version
set(build_definition_version        1.0.0)

#build_include_directories
set(build_include_common            )
set(build_include_target            )
set(build_include_host              )

#build_compile_definitions
set(build_definition_common         )
set(build_definition_target         )
set(build_definiton_host            )

#build_compile_options
set(build_compile_option_common     -O0 -std=c++1z)
set(build_compile_option_target     -mcpu=cortex-a9)
set(build_compile_option_host       )

#build_compile_features
set(build_compile_feature_common    )
set(build_compile_feature_target    )
set(build_compile_feature_host      )
