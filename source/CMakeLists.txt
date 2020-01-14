# Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
#
# Distributed under The MIT License (MIT)
# See accompanying file LICENSE.txt
#---------------------------------------------------------------------------//

include(GNUInstallDirs)
add_library(cxxplot SHARED)

target_sources(cxxplot PRIVATE
        ${CMAKE_SOURCE_DIR}/source/Matplotlib.cpp
        ${CMAKE_SOURCE_DIR}/source/pyplot/Plot.cpp
        ${CMAKE_SOURCE_DIR}/source/pyplot/Pyplot.cpp)

target_include_directories(cxxplot PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_link_libraries(cxxplot PRIVATE Python3::Python Python3::NumPy)

set_target_properties(cxxplot PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_compile_definitions(cxxplot PUBLIC cxxplot_EXPORT)

    add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/examples/cxxplot.dll
            COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:cxxplot>" "$<TARGET_FILE_DIR:plot_1>"
            VERBATIM)
    add_custom_target(copyddlexamples ALL
            DEPENDS ${CMAKE_BINARY_DIR}/examples/cxxplot.dll cxxplot
            VERBATIM)

    #    add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/tests/cxxplot.dll
    #            COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:cxxplot>" "$<TARGET_FILE_DIR:test_timer>"
    #            VERBATIM)
    #    add_custom_target(copyddltests ALL
    #            DEPENDS ${CMAKE_BINARY_DIR}/tests/cxxplot.dll cxxplot
    #            VERBATIM)
endif ()

install(TARGETS cxxplot EXPORT cxxplotTargets
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT cxxplot_RunTime
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT cxxplot_RunTime NAMELINK_COMPONENT cxxplot_Development
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT cxxplot_Development
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/
        TYPE INCLUDE
        FILES_MATCHING
        PATTERN *.hpp
        PERMISSIONS OWNER_READ OWNER_WRITE
        GROUP_READ
        WORLD_READ)

install(FILES ${CMAKE_BINARY_DIR}/cxxplot_export.h
        TYPE INCLUDE
        PERMISSIONS OWNER_READ OWNER_WRITE
        GROUP_READ
        WORLD_READ)

install(EXPORT cxxplotTargets
        NAMESPACE cxxplot::
        FILE cxxplotConfig.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/cxxplot)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        cxxplotConfigVersion.cmake
        VERSION 1.0.0
        COMPATIBILITY SameMajorVersion)

install(FILES ${PROJECT_BINARY_DIR}/source/cxxplotConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/cxxplot)