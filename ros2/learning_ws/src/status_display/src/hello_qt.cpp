#include <QApplication>
#include <QLabel>
#include <QString>
#include <qcoreapplication.h>
#include <qlabel.h>

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    QLabel* lable = new QLabel;
    QString message = QString::fromStdString(("Hello Qt!"));
    lable->setText(message);
    lable->show();
    app.exec(); // 执行应用，阻塞代码  ==> rclcpp::spin();

    return 0;
}
