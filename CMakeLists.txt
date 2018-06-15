
cmake_minimum_required (VERSION 3.9)
project (shellex)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/x64)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/x64)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/x64)

  
add_executable(shellopenfolder "")


target_include_directories(shellopenfolder
 PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(shellopenfolder 
PRIVATE
   main.hpp
   main.cpp
)

if(CMAKE_HOST_WIN32)
    set_target_properties(shellopenfolder PROPERTIES LINK_FLAGS /SUBSYSTEM:WINDOWS )
endif(CMAKE_HOST_WIN32)

target_link_libraries(shellopenfolder
 PRIVATE
  Shell32.lib
)