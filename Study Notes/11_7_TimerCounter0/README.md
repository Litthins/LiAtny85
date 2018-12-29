# TimerCounter0 with PWM

- 注意，Timer/Counter0的OCR0A与OCR0B功能上有所不同，对应引脚不同，配置时需要查表，认真区分。
- 两种时钟可选，内部时钟（1、8、64、256、1024分频），外部时钟无分频。外部时钟频率不应大于（clk<sub>io</sub>/2），推荐不大于（clk<sub>io</sub>/2.5），且使用外部时钟会引入2.5至3.5个系统时钟延迟（From an edge has been applied to the T0 pin to the counter is updated.）
- 【11.4】定时器/计数器溢出中断标志位，**TOV0**是否置位，与**WGM[2:0]**所确定的工作模式有关。
- 【11.5】比较匹配中断标志位，**OCF0A\OCF0B**，在相应中断使能的情况下，产生比较匹配中断。中断函数执行时，中断位自动清除，也可在程序中对相应引脚**I/O位**写**逻辑1**来清除。
- 【11.5.1】在**非PWM**模式下，可以**强制比较匹配**，通过向**FOC0x**写**1**来实现。**强制比较匹配不会置OCF0x中断位，也不会更新或清除定时器。**但是引脚OC0x会产生与真实比较匹配一致的动作。该动作由**COM0[1:0]**决定。
- 【11.5.2】**比较匹配阻滞。**向**TCNT0**写数据会block下一个周期的比较匹配，**这一特性使得可以在不触发中断的条件下初始化OCROx，使其值与TCNT0相等。**
- 
- 以下是一些可用的配置实例。

- ## void My_TimerCounter0_Normal_Toggle();

```c
//Waveform Generation Mode:Normal;
//Compare Output Mode:COM0B,Toggle;
//Clock Select:clk(io),No prescaling.
```

- ## void My_TimerCounter0_CTC_Toggle();

```c
//Waveform Generation Mode:CTC;
//Compare Output Mode:COM0A,Toggle;
//Clock Select:clk(io),No prescaling.
```
