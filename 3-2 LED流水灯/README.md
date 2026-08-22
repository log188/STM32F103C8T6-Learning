# 3-2 LED 流水灯

GPIO 批量输出实验：让 PA0~PA7 共 8 个 LED 依次点亮，形成流水灯效果。

## 功能

- 初始化 GPIOA 全部引脚（`GPIO_Pin_All`）为推挽输出
- 通过 `GPIO_Write(GPIOA, ~0x0001)` 依次赋不同的值，配合 100ms 延时
- 每次只让一位为低（取反后），LED 依次点亮流动

## 涉及知识点

- GPIO 一次操作多个引脚：`GPIO_Write(GPIOx, uint16_t portval)`
- 位取反控制单灯点亮
- `GPIO_Pin_All` 批量初始化

## 源码大致逻辑

```c
while (1) {
    GPIO_Write(GPIOA, ~0x0001); Delay_ms(100);  // LED0 亮
    GPIO_Write(GPIOA, ~0x0002); Delay_ms(100);  // LED1 亮
    // ... 0x0004 ~ 0x0080，依次点亮 8 个灯
}
```

## 接线

| 8个LED | STM32 |
|--------|-------|
| 各正极(经限流电阻) | PA0 ~ PA7 |
| 各负极 | GND (低电平点亮) |

> 让 0x0001 对应的位输出低电平，是利用取反操作；具体接线需与板载灯对应。
