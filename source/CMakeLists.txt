add_library(cxxplot SHARED)
target_sources(cxxplot PRIVATE
        ${CMAKE_SOURCE_DIR}/source/Graph.cpp
        ${CMAKE_SOURCE_DIR}/source/pyplot/Plot.cpp
        ${CMAKE_SOURCE_DIR}/source/pyplot/Pyplot.cpp)
target_include_directories(cxxplot PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/include/pyplot
        ${Python3_INCLUDE_DIRS}
        ${Python3_NumPy_INCLUDE_DIRS}
        ${CMAKE_BINARY_DIR})
target_link_libraries(cxxplot PRIVATE ${Python3_LIBRARIES})

set_target_properties(cxxplot PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_compile_definitions(cxxplot PRIVATE cxxplot_EXPORT)

    add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/examples/cxxplot.dll
            COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:cxxplot>" "$<TARGET_FILE_DIR:example_1>"
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

include(GNUInstallDirs)
install(TARGETS cxxplot
        EXPORT cxxplot
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT cxxplot_RunTime
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT cxxplot_RunTime NAMELINK_COMPONENT cxxplot_Development
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT cxxplot_Development)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include
        DESTINATION .
        FILES_MATCHING
        PATTERN *.hpp
        PERMISSIONS OWNER_READ OWNER_WRITE
        GROUP_READ
        WORLD_READ)

install(EXPORT cxxplot
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/cxxplot
        NAMESPACE cxxplot::
        FILE cxxplotConfig.cmake
        )