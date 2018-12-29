# TimerCounter0 with PWM

- **注意，Timer/Counter0的OCR0A与OCR0B功能上有所不同，对应引脚不同，配置时需要查表，认真区分。**

- 两种时钟可选，内部时钟（1、8、64、256、1024分频），外部时钟无分频。外部时钟频率不应大于（clk<sub>io</sub>/2），推荐不大于（clk<sub>io</sub>/2.5），且使用外部时钟会引入2.5至3.5个系统时钟延迟（From an edge has been applied to the T0 pin to the counter is updated.）

- 【11.4】定时器/计数器溢出中断标志位，**TOV0**是否置位，与**WGM[2:0] **所确定的工作模式有关。

  【11.5】比较匹配中断标志位，**OCF0A\OCF0B**，在相应中断使能的情况下，产生比较匹配中断。中断函数执行时，中断位自动清除，也可在程序中对相应引脚**I/O位**写**逻辑1**来清除。

  【11.5.1】在**非PWM**模式下，可以**强制比较匹配**，通过向**FOC0x**写**1**来实现。**强制比较匹配不会置OCF0x中断位，也不会更新或清除定时器。**但是引脚OC0x会产生与真实比较匹配一致的动作。该动作由**COM0[1:0]**决定。

  【11.5.2】**比较匹配阻滞。**向**TCNT0**写数据会block下一个周期的比较匹配，**这一特性使得可以在不触发中断的条件下初始化OCROx，使其值与TCNT0相等。**

  【11.5.3】**OC0x寄存器**应该在**设置端口引脚所对应的方向寄存器<sub>Data Direction Register</sub>之前设置**。最简单的方法是在普通模式Normal中，使用强制比较匹配，**FOC0x**，达到目的。在改变**波形发生模式<sub>Waveform Generator modes</sub>**时，**OC0x寄存器**的值不会改变。

  【11.6.1】**COM0[1:0]**改变后，相应设置将在下一次比较匹配时生效，也可以通过**强制比较匹配使之立即生效**。

  【11.7】定时器/计数器及其输出引脚的行为，由**波形发生模式寄存器<sub>Waveform Generator mode</sub><sup>WGM0[2:0]</sup>、比较输出模式寄存器<sub>Compare Output Mode</sub><sup>COM0x[1:0]</sup>**共同决定。

- **比较输出模式寄存器<sub>Compare Output Mode</sub><sup>COM0x[1:0]</sup>**在PWM模式中决定波形是否反转，在非PWM模式中，决定比较匹配时的输出动作，包括置位、清除和反转。

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
