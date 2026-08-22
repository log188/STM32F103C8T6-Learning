# 6-5 PWM 驱动直流电机

PWM 调速实验：用 PWM + 方向控制驱动直流电机，按键调节速度正反。

## 功能

- 两个 PWM 输出控制电机驱动模块（如 L298N/TB6612），实现转向与调速
- 按 K1 每次 `+20` 速度，超过 100 跳到 `-100`（反转），循环
- OLED 显示当前速度 `Speed:`（可正可负）

## 涉及知识点

- PWM 调速：占空比决定转速
- **H 桥** 电机驱动模块的方向控制
- 有符号速度值的处理与显示

## 源文件

| 文件 | 说明 |
|------|------|
| `User/main.c` | 主逻辑与显示 |
| `User/Motor.c/h` | 电机驱动 |
| `User/Key.c/h` | 按键扫描 |

## 核心接口

| 函数 | 说明 |
|------|------|
| `Motor_Init()` | 初始化电机 PWM 与控制引脚 |
| `Motor_SetSpeed(int8_t)` / `Motor_SetSpeed1()` | 设置两路 PWM 实现调速/转向 |

## 源码大致逻辑

```c
while (1) {
    KeyNum = Key_GetNum();
    if (KeyNum == 1) { Speed += 20; if (Speed > 100) Speed = -100; }
    Motor_SetSpeed(Speed);
    Motor_SetSpeed1(Speed);
    OLED_ShowSignedNum(1, 7, Speed, 3);
}
```

## 接线

| 电机驱动(TB6612等) | STM32 |
|-------------------|-------|
| PWMA / PWMB | `Motor.h` 配置引脚 |
| AIN1/BIN1、AIN2/BIN2 | 控制引脚 |
| VMOT / GND | 电源 / GND |
| 电机 | 驱动输出端子 |

> 驱动模块用H桥方式，两路 PWM 同时输出即可控制正反转和速度。
