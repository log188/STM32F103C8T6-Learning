# 3-1 LED 闪烁

GPIO 输出基础实验：让 LED 灯按固定时间间隔闪烁。

## 功能

- 使用 GPIO 推挽输出模式，控制 PA0 引脚输出高低电平
- 通过 `Delay_ms(500)` 让 LED 每 500ms 翻转一次，实现闪烁

## 涉及知识点

- GPIO 输出初始化（`GPIO_Mode_Out_PP` 推挽输出）
- 时钟外设使能 `RCC_APB2PeriphClockCmd`
- GPIO 置高/置低：`GPIO_SetBits` / `GPIO_ResetBits` / `GPIO_WriteBit`
- 软件延时 `Delay_ms`

## 源码示例

```c
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

GPIO_InitTypeDef GPIO_InitStructure;
GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_Init(GPIOA, &GPIO_InitStructure);

while (1) {
    GPIO_ResetBits(GPIOA, GPIO_Pin_0);
    Delay_ms(500);
    GPIO_SetBits(GPIOA, GPIO_Pin_0);
    Delay_ms(500);
}
```

## 接线

| LED | STM32 |
|-----|-------|
| 正极(经限流电阻) | PA0 |
| 负极 | GND |

> 采用 **低电平点亮** 接线时，`ResetBits` 亮、`SetBits` 灭。
