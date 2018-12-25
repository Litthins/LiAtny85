# TimerCounter0 with PWM

- 注意，Timer/Counter0的OCR0A与OCR0B功能上有所不同，对应引脚不同，配置时需要查表，认真区分。

- 两种时钟可选，内部时钟（1、8、64、256、1024分频），外部时钟无分频。外部时钟频率不应大于（clk<sub>io</sub>/2），推荐不大于（clk<sub>io</sub>/2.5），且使用外部时钟会引入2.5至3.5个系统时钟延迟（From an edge has been applied to the To pin to the counter is updated.）以下是一些可用的配置实例。

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
