# 6-4 PWM 驱动舵机

PWM 控制实验：用一定周期和占空比的 PWM 控制舵机角度，按键调节角度。

## 功能

- 输出特定周期（通常 20ms）的 PWM 脉冲驱动舵机
- 不同占空比对应不同转角度数（0°~180°对应 0.5ms~2.5ms 高电平）
- 按 K1 每次 `+30°`，超过 180° 归 0，OLED 显示当前角度

## 涉及知识点

- PWM 周期与舵机角度的映射
- `Servo_SetAngle(度)` 内部换算占空比
- 按键输入 + 角度显示

## 源文件

| 文件 | 说明 |
|------|------|
| `User/main.c` | 主逻辑与角度显示 |
| `User/Servo.c/h` | 舵机驱动 |
| `User/Key.c/h` | 按键扫描 |

## 核心接口

| 函数 | 说明 |
|------|------|
| `Servo_Init()` | 初始化舵机 PWM |
| `Servo_SetAngle(float)` | 设置舵机角度（0~180°） |

## 源码大致逻辑

```c
Servo_SetAngle(90);
while (1) {
    KeyNum = Key_GetNum();
    if (KeyNum == 1) { Angle += 30; if (Angle > 180) Angle = 0; }
    Servo_SetAngle(Angle);
    OLED_ShowNum(1, 7, Angle, 3);
}
```

## 接线

| 舵机 | STM32 |
|------|-------|
| 信号线 | `Servo.h` 配置引脚 |
| VCC（红） | 5V |
| GND（棕/黑） | GND（需与 STM32 共地） |

> 舵机供电建议外接电源，避免拉低 STM32 电压。
