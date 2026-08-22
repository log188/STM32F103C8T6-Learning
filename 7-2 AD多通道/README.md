# 7-2 AD 多通道（ADC）

AD 采集实验：多路 ADC 通道扫描，OLED 同时显示 4 路采样值。

## 功能

- ADC 多通道采集 CH0~CH3 共 4 路
- 通过 `AD_GetValue(通道)` 参数指定要读取的通道
- OLED 四行分别显示 `AD0: ~ AD3:` 的值

## 涉及知识点

- ADC 多通道 **扫描** / 通道切换
- 通过函数参数指定 ADC 通道
- 多路数据显示布局

## 源文件

| 文件 | 说明 |
|------|------|
| `User/main.c` | 采集与显示 |
| `User/AD.c/h` | ADC 多通道驱动 |

## 核心接口

| 函数 | 说明 |
|------|------|
| `AD_Init()` | 初始化 ADC 多通道 |
| `AD_GetValue(uint8_t ch)` | 返回指定通道（如 `ADC_Channel_0`）的 ADC 值 |

## 源码示例

```c
AD0 = AD_GetValue(ADC_Channel_0);
AD1 = AD_GetValue(ADC_Channel_1);
AD2 = AD_GetValue(ADC_Channel_2);
AD3 = AD_GetValue(ADC_Channel_3);
```

## 接线

| 4路模拟信号 | STM32 |
|------------|-------|
| 通道 0~3 | 对应 ADC 引脚（见 `AD.h`） |
| GND | 共地 |

> 通道切换在读取时完成；若多路采样需注意采样时间与稳定性。
