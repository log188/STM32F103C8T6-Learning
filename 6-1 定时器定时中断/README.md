# 6-1 定时器定时中断

定时器中断实验：定时器溢出触发中断，OLED 显示计数值。

## 功能

- 定时器 TIM2 以固定周期产生更新中断
- 中断服务函数中 `Num++`
- OLED 显示 `Num:` 当前自增数目

## 涉及知识点

- **定时器（TIM）** 的配置：预分频 PSC、自动重装载 ARR
- 定时器更新中断（`TIM_IT_Update`）
- 中断服务函数编写 `TIM2_IRQHandler`
- 中断标志位的查询与清除

## 核心接口

| 函数 | 说明 |
|------|------|
| `Timer_Init()` | 初始化定时器并使能更新中断 |

## 源码示例

```c
// 中断服务函数
void TIM2_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET) {
        Num++;
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    }
}
```

## 说明

定时周期由时钟源、`PSC` 与 `ARR` 共同决定。例如：

```
定时周期 = (PSC + 1) x (ARR + 1) / 定时器时钟频率
```

具体分频值以 `Timer.c` 内配置为准。
