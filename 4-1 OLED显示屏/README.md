# 4-1 OLED 显示屏

显示基础实验：演示 OLED 各种显示函数的用法。

## 功能

在 OLED 上依次显示：
- 单个字符 `'A'`
- 字符串 `"HelloWorld!"`
- 无符号数字 `12345`
- 有符号数字 `-12345`
- 十六进制 `0xAA55`
- 二进制 `0xAA55`

## 涉及知识点

- OLED（SSD1306）初始化与驱动
- 各种显示 API：
  - `OLED_ShowChar(x, y, 'A')`
  - `OLED_ShowString(x, y, "HelloWorld!")`
  - `OLED_ShowNum(x, y, 12345, 5)`
  - `OLED_ShowSignedNum(x, y, -12345, 5)`
  - `OLED_ShowHexNum(x, y, 0xAA55, 4)`
  - `OLED_ShowBinNum(x, y, 0xAA55, 16)`

## 源码示例

```c
OLED_Init();
OLED_ShowChar(1, 1, 'A');
OLED_ShowString(1, 3, "HelloWorld!");
OLED_ShowNum(2, 1, 12345, 5);
OLED_ShowSignedNum(2, 7, -12345, 5);
OLED_ShowHexNum(3, 1, 0xAA55, 4);
OLED_ShowBinNum(4, 1, 0xAA55, 16);
```

## 接线

| OLED | STM32 |
|------|-------|
| SCL | PB8 |
| SDA | PB9 |
| VCC | 3.3V |
| GND | GND |

> 坐标：x=行号（1~4），y=列号（1~128）；一个字符占 2 列左右。
