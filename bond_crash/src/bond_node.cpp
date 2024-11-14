#include <rclcpp/rclcpp.hpp>
#include <bondcpp/bond.hpp>

// Replacing the Node with a LifecycleNode that starts the bond when active appears to fix the issue.

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    // auto node = std::make_shared<rclcpp_lifecycle::LifecycleNode>("bond_node");
    auto node = std::make_shared<rclcpp::Node>("bond_node");
    bond::Bond bond(node->get_name(), node->get_name(), node);
    // typedef rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn CallbackReturn;
    // auto on_activate = [&bond](const rclcpp_lifecycle::State&){ bond.start(); return CallbackReturn::SUCCESS; };
    // node->register_on_activate(on_activate);
    bond.start();
    rclcpp::spin(node->get_node_base_interface());
    rclcpp::shutdown();
    return 0;
}