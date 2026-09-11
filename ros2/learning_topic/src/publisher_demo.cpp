#include "rclcpp/executors.hpp"
#include "rclcpp/logging.hpp"
#include "rclcpp/publisher.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp/timer.hpp"
#include "rclcpp/utilities.hpp"
#include "std_msgs/msg/detail/string__struct.hpp"
#include "std_msgs/msg/string.hpp"
#include <chrono>
#include <cstddef>
#include <functional>
#include <memory>
#include <string>

class Talker : public rclcpp::Node{
public:
    Talker() : Node("talker_demo_node"){
        RCLCPP_INFO(this->get_logger(), "发布者创建成功，开始发送消息...");
        publisher_ = this->create_publisher<std_msgs::msg::String>("chatter", 10);
        timer_ = this->create_wall_timer(
        std::chrono::milliseconds(500), 
        std::bind(&Talker::time_callback, this));
        /*
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(500),
            [this]() { timer_callback(); })
        */
    }

private:
    void time_callback(){
        auto msg = std_msgs::msg::String();
        msg.data = "hello world " + std::to_string(count_++);
        RCLCPP_INFO(this->get_logger(), "发布: %s", msg.data.c_str());
        publisher_->publish(msg);
    }

private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    size_t count_;

};

int main(int argc, char** argv){
    rclcpp::init(argc, argv);

    rclcpp::spin(std::make_shared<Talker>());

    rclcpp::shutdown();
    return 0;
}