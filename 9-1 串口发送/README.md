# 9-1 串口发送

UART 串口通讯实验：通过串口向上位机发送各种格式的数据。

## 功能

程序上电后通过串口依次发送：
- 单字节 `'A'`
- 字节数组 `0x42 0x43 0x44 0x45`
- 字符串 `"Num1="`
- 数字 111（3 位格式）
- 使用 `printf` 格式化输出 `Num2=222`
- 用 `sprintf` 拼串后发送 `Num3=333`
- 封装的 `Serial_Printf` 输出 `Num4=444`

## 涉及知识点

- **USART** 串口初始化（波特率、停止位、校验等）
- 串口发送单字节 / 数组 / 字符串
- 重定向 `printf` 到串口
- 变参格式化输出 `Serial_Printf`

## 源文件

| 文件 | 说明 |
|------|------|
| `User/main.c` | 发送演示 |
| `User/Serial.c/h` | 串口驱动 |

## 核心接口

| 函数 | 说明 |
|------|------|
| `Serial_Init()` | 初始化 USART1 |
| `Serial_SendByte()` | 发送单字节 |
| `Serial_SendArray()` | 发送字节数组 |
| `Serial_SendString()` | 发送字符串 |
| `Serial_SendNumber()` | 以十进制发送数字 |
| `Serial_Printf()` | 格式化输出（类似 printf） |

## 接线

| 模块 | STM32 |
|------|-------|
| TX | PA9 (USART1_TX) |
| RX | PA10 (USART1_RX) |
| GND | 与 USB转TTL 共地 |

> 用串口调试助手，设置与 `Serial.c` 一致的波特率即可看到输出。
