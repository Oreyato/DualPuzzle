file( GLOB components_SOURCES *.cpp )
add_library( components ${components_SOURCES} )
target_include_directories(components PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
