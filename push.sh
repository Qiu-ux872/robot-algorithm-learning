#!/bin/bash

echo "=============================="
echo "   Git 自动提交并推送"
echo "=============================="

# 查看当前状态
echo ""
echo "【1/4】检查 Git 状态..."
git status

# 添加所有修改
echo ""
echo "【2/4】添加文件..."
git add .

# 输入提交信息
echo ""
read -p "请输入本次提交信息: " message

# 判断提交信息是否为空
if [ -z "$message" ]; then
    echo "提交信息不能为空！"
    exit 1
fi

# 提交
echo ""
echo "【3/4】提交..."
git commit -m "$message"

# 推送
echo ""
echo "【4/4】推送到 GitHub..."
git push

echo ""
echo "=============================="
echo "   推送完成！"
echo "=============================="
