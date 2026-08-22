# 7-1 AD 单通道（ADC）

AD 采集实验：单路 ADC 采集模拟电压，OLED 同时显示原始 ADC 值和换算的电压值。

## 功能

- ADC1 单通道采集（12 位，范围 0~4095）
- 读取数字量后换算为实际电压：`Voltage = ADValue / 4095 * 3.3`
- OLED 第一行显示 ADC 原始值 `ADValue:`，第二行显示电压 `Voltage: x.xxV`

## 涉及知识点

- **ADC** 外设配置：通道、采样周期、转换模式
- 模拟量 → 数字量的换算公式
- 电压值的显示（整数部分 + 小数部分分开处理）

## 源文件

| 文件 | 说明 |
|------|------|
| `User/main.c` | 采集与显示 |
| `User/AD.c/h` | ADC 初始化与读取 |

## 核心接口

| 函数 | 说明 |
|------|------|
| `AD_Init()` | 初始化 ADC |
| `AD_GetValue()` | 返回当前通道 ADC 值（0~4095） |

## 源码示例

```c
ADValue = AD_GetValue();
Voltage = (float)ADValue / 4095 * 3.3;   // 换算电压

OLED_ShowNum(1, 9, ADValue, 4);          // ADC 原始值
OLED_ShowNum(2, 9, Voltage, 1);          // 电压整数部分
OLED_ShowNum(2, 11, (uint16_t)(Voltage*100)%100, 2); // 小数两位
```

## 接线

| 可调电位器/信号 | STM32 |
|--------------|-------|
| 输出(中脚) | ADC 输入引脚（见 `AD.h` 配置） |
| 两端 | 3.3V / GND |

> 输入电压范围 0 ~ 3.3V，超出会损坏引脚。
