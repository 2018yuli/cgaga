## 环境准备

```bash
sudo apt update
sudo apt install build-essential gdb
```

### 安装插件

- MemoryView

### launch.json

```bash
# 在 .vscode/launch.json 里指定调试器
{
  "name": "C++ 调试 (gdb)",
  "type": "cppdbg",
  "request": "launch",
  "program": "${fileDirname}/${fileBasenameNoExtension}",
  "cwd": "${fileDirname}",
  "MIMode": "gdb",
  "miDebuggerPath": "/usr/bin/gdb"
}
```