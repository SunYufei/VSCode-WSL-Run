# WSL-Run

调用WSL编译运行代码文件，支持c、cpp、java、python

## 使用方法

### Step 1 安装WSL

请参考[官方安装指南](https://docs.microsoft.com/zh-cn/windows/wsl/install-win10)

### Step 2 安装VSCode

请到[VSCode官网](https://code.visualstudio.com/)下载安装适合的Windows版本

### Step 3 安装插件 Launcher

### Step 4 下载 VSCode-WSL-Run

```shell
git clone --depth=1 https://github.com/SunYufei/VSCode-WSL-Run
```

将VSCode-WSL-Run文件夹添加到系统环境变量中

### Step 5 VSCode 设置

点击文件->首选项->设置，在用户设置中添加
```
"launcher.terminal": {
    "executable": "cmd.exe",
    "parameters": "/c start bashrun.exe \"%item%\""
}
```

### Step 6 使用

使用VSCode打开源代码文件，按下`Ctrl+Shift+T`即可编译运行单一代码文件


## 致谢

[SilenceU's Blog](https://silenceu.me/tool/vscodeide.html)
[vscode-launcher](https://github.com/ilich/vscode-launcher)