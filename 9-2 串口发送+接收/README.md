# 9-2 串口发送+接收

UART 串口双向通讯实验：接收上位机数据并在 OLED 显示，同时回发。

## 功能

- 串口接收上位机发来的数据（使用 **中断接收**）
- 收到一字节后：
  - 通过 `Serial_SendByte` 原样回发（回显）
  - 在 OLED 显示接收到的十六进制值 `RxData: xx`

## 涉及知识点

- **USART 中断接收**：`RXNE` 接收寄存器非空中断
- 中断接收标志 `Serial_GetRxFlag()` 查询
- 接收数据读取 `Serial_GetRxData()`
- 串口与 OLED 结合显示

## 源文件

| 文件 | 说明 |
|------|------|
| `User/main.c` | 主循环轮询收数并显示 |
| `User/Serial.c/h` | 串口驱动（含中断接收） |

## 核心接口

| 函数 | 说明 |
|------|------|
| `Serial_Init()` | 初始化 USART1 与接收中断 |
| `Serial_GetRxFlag()` | 是否有新接收数据（1=有） |
| `Serial_GetRxData()` | 读取接收的字节 |

## 源码大致逻辑

```c
while (1) {
    if (Serial_GetRxFlag() == 1) {        // 有收到数据
        RxData = Serial_GetRxData();
        Serial_SendByte(RxData);          // 回显
        OLED_ShowHexNum(1, 8, RxData, 2); // OLED 显示
    }
}
```

## 接线

| 模块 | STM32 |
|------|-------|
| TX | PA9 (USART1_TX) |
| RX | PA10 (USART1_RX) |
| GND | 共地 |

> 用串口调试助手发送任意字节，串口会回显，OLED 同步显示该字节的十六进制值。
