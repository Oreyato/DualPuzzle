file( GLOB collision_SOURCES *.cpp )
add_library( collision ${collision_SOURCES} )
target_include_directories(collision PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
