cmake_minimum_required(VERSION 3.5)
project(B)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

find_package(ament_cmake REQUIRED)

add_library(b_target INTERFACE)
target_include_directories(b_target
  INTERFACE
    $<INSTALL_INTERFACE:include>
  )
# TODO replace with ament_target_dependencies when ament/ament_cmake#178 is merged
target_link_libraries(b_target INTERFACE C::c_target)

install(FILES B.hpp
  DESTINATION include/${PROJECT_NAME}
)

install(TARGETS b_target EXPORT b_target)

ament_export_interfaces(b_target)

# Required or A will fail with:
#    CMake Error at CMakeLists.txt:11 (add_executable):
#      Target "a_exe" links to target "C::c_target" but the target was not found.
#      Perhaps a find_package() call is missing for an IMPORTED target, or an
#      ALIAS target is missing?
ament_export_dependencies(C)

ament_package()
