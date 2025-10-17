#!/bin/bash

# 开启代理
function proxy_on() {
    export http_proxy=http://172.17.0.1:7890
    export https_proxy=http://172.17.0.1:7890
    export no_proxy=172.17.0.1,localhost
    export HTTP_PROXY=http://172.17.0.1:7890
    export HTTPS_PROXY=http://172.17.0.1:7890
    export NO_PROXY=172.17.0.1,localhost
    echo -e "\033[32m[√] 已开启代理\033[0m"
}

# 关闭代理
function proxy_off() {
    unset http_proxy
    unset https_proxy
    unset no_proxy
    unset HTTP_PROXY
    unset HTTPS_PROXY
    unset NO_PROXY
    echo -e "\033[31m[×] 已关闭代理\033[0m"
}

# 查看代理状态
function status() {
    if [ -n "$http_proxy" ] || [ -n "$https_proxy" ]; then
        echo -e "\033[32m[√] 当前代理已开启\033[0m"
    else
        echo -e "\033[31m[×] 当前代理未开启\033[0m"
    fi
}

# 显示操作提示
function usage() {
    echo "使用方法:"
    echo "  source ./proxy.sh on    # 开启代理"
    echo "  source ./proxy.sh off   # 关闭代理"
    echo "  source ./proxy.sh status  # 查看代理状态"
    exit 1
}

# 选择操作
case "$1" in
    on)
        proxy_on
        ;;
    off)
        proxy_off
        ;;
    status)
        status
        ;;
    *)
        usage
        ;;
esac
