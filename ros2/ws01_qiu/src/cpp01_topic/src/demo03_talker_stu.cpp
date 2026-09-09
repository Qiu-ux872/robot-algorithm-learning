#include "rclcpp/rclcpp.hpp"
#include 

class TalkerStu : public rclcpp::Node{
public:
    TalkerStu() : Node("talker_stu_cpp"){

    }
};

int main(int argc, char** argv){
    rclcpp::init(argc, argv);

    rclcpp::spin(std::make_shared<TalkerStu>());

    rclcpp::shutdown();
    return 0;
}