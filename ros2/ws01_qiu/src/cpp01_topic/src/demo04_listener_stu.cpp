#include "rclcpp/rclcpp.hpp"

class ListenerStu : public rclcpp::Node{
public:
    ListenerStu() : Node("listener_stu_cpp"){

    }
};

int main(int argc, char** argv){
    rclcpp::init(argc, argv);

    rclcpp::spin(std::make_shared<ListenerStu>());

    rclcpp::shutdown();
    return 0;
}