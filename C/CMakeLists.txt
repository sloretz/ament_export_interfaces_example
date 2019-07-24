cmake_minimum_required(VERSION 3.5)
project(C)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

find_package(ament_cmake REQUIRED)

add_library(c_target INTERFACE)
target_include_directories(c_target
  INTERFACE
    $<INSTALL_INTERFACE:include>
  )

install(FILES C.hpp
  DESTINATION include/${PROJECT_NAME}
)

install(TARGETS c_target EXPORT c_target)

ament_export_interfaces(c_target)

ament_package()
