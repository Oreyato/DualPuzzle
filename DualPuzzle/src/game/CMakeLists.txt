file( GLOB game_SOURCES *.cpp )
add_library( game ${game_SOURCES})
add_subdirectory( actors )
target_include_directories(game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
