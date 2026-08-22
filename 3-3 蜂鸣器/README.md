# 3-3 蜂鸣器

GPIO 数字输出实验：控制有源蜂鸣器按时间间隔鸣叫。

## 功能

- 初始化 GPIOB 的 PB12 为推挽输出
- 循环 `ResetBits`（低电平触发）鸣响 100ms、`SetBits` 停止 100ms，蜂鸣器间歇鸣叫

## 涉及知识点

- GPIO 数字输出控制
- 有源蜂鸣器的驱动方式（低电平触发，需配合三极管/ULN2003 驱动）

## 源码大致逻辑

```c
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
// GPIO_Init PB12 推挽输出
while (1) {
    GPIO_ResetBits(GPIOB, GPIO_Pin_12);   // 蜂鸣器响
    Delay_ms(100);
    GPIO_SetBits(GPIOB, GPIO_Pin_12);     // 蜂鸣器停
    Delay_ms(100);
}
```

## 接线

| 蜂鸣器模块 | STM32 |
|-----------|-------|
| I/O | PB12 |
| VCC | 3.3V / 5V |
| GND | GND |

> 有源蜂鸣器内部自带振荡，通电即响，只需控制通断即可。
