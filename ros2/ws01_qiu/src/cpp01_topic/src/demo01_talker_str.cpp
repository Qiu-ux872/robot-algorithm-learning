/*
  需求：以固定频率发送Hello World文本，文本后缀编号逐条+1
  流程：
    1、包含头文件
    2、初始化ROS2客户端
    3、自定义节点类
      3-1、创建消息发布方
      3-2、创建定时器 控制发布频率
      3-3、组织并发布消息
    4、调用spin函数并传入自定义类对象指针
    5、释放资源

*/

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class Talker : public rclcpp::Node{
public:
  Talker() : Node("talker_node_cpp"), count_(0){
    RCLCPP_INFO(this->get_logger(), "发布节点创建");
      // 3-1、创建消息发布方
      /*
        模板：被发布的消息类型
        参数：
          1、话题名称
          2、Qos--服务质量管理（消息队列长度）
        返回值：发布对象指针
      */
      publisher_ = this->create_publisher<std_msgs::msg::String>("chatter", 10); // 自定义话题名称
      // 10:设置消息队列 深度为10，即遇到突发情况如网络终端将消息放到队列等待恢复后继续发布
      // 3-2、创建定时器 控制发布频率
      /*
        参数：
          1、时间间隔
          2、回调函数
        返回值：定时器对象指针
      
      */
      timer_ = this->create_wall_timer(1s, std::bind(&Talker::on_timer, this));
  
  }
private:
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  // 设置整型计数器
  size_t count_;

private:
  void on_timer(){
    // 3-3、组织并发布消息
    // 核心API：publisher_->publish() 传入被发送的消息
    // 创建msg对象
    auto message = std_msgs::msg::String();
    message.data = "Hello World!" + std::to_string(count_++);
    RCLCPP_INFO(this->get_logger(), "发布方发布的消息：%s", message.data.c_str());
    publisher_->publish(message);

  }

};

int main(int argc, char** argv){
  // 2、初始化ROS2客户端
  rclcpp::init(argc, argv);

  // 4、调用spin函数并传入自定义类对象指针
  rclcpp::spin(std::make_shared<Talker>());

  // 5、释放资源
  rclcpp::shutdown();
  return 0;
}