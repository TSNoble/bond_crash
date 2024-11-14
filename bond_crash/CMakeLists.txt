cmake_minimum_required(VERSION 3.5)
project(bond_crash)
set(CMAKE_CXX_STANDARD 17)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(bondcpp REQUIRED)

add_executable(bond_node src/bond_node.cpp)
ament_target_dependencies(bond_node PUBLIC rclcpp bondcpp)

install(TARGETS bond_node DESTINATION lib/${PROJECT_NAME})
install(DIRECTORY launch DESTINATION share/${PROJECT_NAME}/)

ament_package()