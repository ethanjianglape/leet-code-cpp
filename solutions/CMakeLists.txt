file(GLOB solution_files CONFIGURE_DEPENDS "*.cpp")

foreach(solution_file ${solution_files})
    get_filename_component(target_name ${solution_file} NAME_WE)
    add_executable(${target_name} ${solution_file})
endforeach()
