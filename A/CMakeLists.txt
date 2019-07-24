cmake_minimum_required(VERSION 3.5)
project(A)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

find_package(ament_cmake REQUIRED)
find_package(B REQUIRED)

add_executable(a_exe A.cpp)
# TODO replace with ament_target_dependencies when ament/ament_cmake#178 is merged
target_link_libraries(a_exe PRIVATE B::b_target)

install(TARGETS a_exe
  DESTINATION lib/${PROJECT_NAME})

ament_package()
