file( GLOB actors_SOURCES *.cpp )
add_library( actors ${actors_SOURCES} )
target_include_directories(actors PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
