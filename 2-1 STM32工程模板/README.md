# 2-1 STM32 工程模板

基于标准外设库的最小 Keil 工程框架，是后续所有实验的起点。

## 目录结构

| 目录 | 说明 |
|------|------|
| `User/`    | 用户源码（`main.c`、中断文件等） |
| `Library/` | 标准外设库源文件（`stm32f10x_*.c/h`） |
| `Start/`   | 启动文件、内核文件、系统时钟配置 |
| `Objects/` | 编译输出（`.gitignore` 已排除） |
| `Listings/` | 链接给列表（已排除） |
| `DebugConfig/` | Keil 调试配置（已排除） |

## 源文件说明

| 文件 | 说明 |
|------|------|
| `User/main.c` | 主函数，示例为 GPIO 控制 PC13 引脚输出高电平（点灯） |
| `User/stm32f10x_it.c/h` | 中断服务函数 |
| `User/stm32f10x_conf.h` | 外设库头文件包含配置 |
| `Start/startup_stm32f10x_md.s` | 中容量启动文件（适用于 F103C8） |
| `Start/system_stm32f10x.c` | 系统时钟初始化 |

## 用法

1. 用 Keil 打开本目录下的 `Project.uvprojx`
2. 在 `User/main.c` 的 `main()` 中编写你的逻辑
3. 编译、下载到开发板运行

> 新工程可从本模板复制，再按需添加外设模块。
