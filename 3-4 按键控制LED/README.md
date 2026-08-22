# 3-4 按键控制 LED

GPIO 输入实验：按键控制 LED 翻转，并用分模块封装了 LED 和按键驱动。

## 功能

- 封装 `LED_Init` / `LED1_Turn` / `LED2_Turn` 和 `Key_Init` / `Key_GetNum`
- 主循环读取按键返回值：
  - 按 K1（返回 1）：`LED1_Turn()` 翻转 LED1
  - 按 K2（返回 2）：`LED2_Turn()` 翻转 LED2

## 涉及知识点

- GPIO **输入** 模式初始化
- 按键扫描（`Key_GetNum` 有去抖动逻辑）
- 模块化编程：把 LED、按键各自封装成独立模块（.c/.h）

## 源文件

| 文件 | 说明 |
|------|------|
| `User/main.c` | 主逻辑 |
| `User/LED.c/h` | LED 初始化与翻转 |
| `User/Key.c/h` | 按键扫描（带消抖） |
| `System/Delay.c/h` | 延时（消抖用） |

## 接线

| 硬件 | STM32 |
|------|-------|
| LED（低电平点亮） | 对应封装配置引脚 |
| 按键（按下接低） | `Key.h` 中配置的引脚 |

> 具体引脚以 `LED.h`、`Key.h` 中的 `#define` 为准。
