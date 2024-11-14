#include <rclcpp/rclcpp.hpp>
#include <bondcpp/bond.hpp>

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("bond_node");
    bond::Bond bond(node->get_name(), node->get_name(), node);
    bond.start();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}