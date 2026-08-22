# 1-4 OLED 显示屏驱动函数模块

0.96 寸 OLED 显示屏（SSD1306, 128×64）驱动模块，提供字符、字符串、数字的显示函数，供后续工程复用。包含两种接线版本。

## 目录结构

| 目录 | 说明 |
|------|------|
| `4针脚I2C版本/` | I2C 接口（4 线：VCC/GND/SCL/SDA） |
| `7针脚SPI版本/` | SPI 接口（有线材差异的 7 线屏） |

## 文件

| 文件 | 说明 |
|------|------|
| `OLED.c` | 显示功能实现 |
| `OLED.h` | 接口声明与引脚配置 |
| `OLED_Font.h` | 字库（ASCII 字符点阵数据） |

## 常用接口

| 函数 | 说明 |
|------|------|
| `OLED_Init()` | 初始化电压传输屏 |
| `OLED_Clear()` | 清屏 |
| `OLED_ShowChar(x, y, 'A')` | 指定行、列显示单个字符 |
| `OLED_ShowString(x, y, "Hello")` | 显示字符串 |
| `OLED_ShowNum(x, y, 12345, 5)` | 显示无符号十进制数 |
| `OLED_ShowSignedNum(x, y, -12345, 5)` | 显示有符号十进制数 |
| `OLED_ShowHexNum(x, y, 0xAA55, 4)` | 十六进制显示 |
| `OLED_ShowBinNum(x, y, 0xAA, 8)` | 二进制显示 |
| `OLED_ShowFloatNum(...)` | 浮点显示（按版本） |

> 坐标参数 x 为行（1~4，一行 16 像素），y 为列（1~128）。

## 接线示例（I2C 版）

| OLED | STM32 |
|------|-------|
| SCL | PB8 |
| SDA | PB9 |
| VCC | 3.3V |
| GND | GND |

（具体引脚请以对应版本 `OLED.h` 中的配置为准）
