# IO_Ports(PORTB0-PORTB4 Only)

- **注意，PORTB5默认状态下为<a href="https://www.codecogs.com/eqnedit.php?latex=\overline{RESET}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\overline{RESET}" title="\overline{RESET}" /></a>引脚，上电后需保持高电平，可通过设置熔丝更改默认设置，但会影响USBASP下载功能。**

- **Port Pin Configurations**
| DDxn | PORTxn | PUD(in MCUCR) |  I/O  | Pull-up |     Comment     |
| :--: | :----: | :-----------: |  :--: | :-----: |     :-----:     |
|   0  |    0   |       X       | Input |    No   | Tri-state(Hi-Z) |
|   0  |    1   |       0       | Input |    Yes  | Pxn will source current if ext. pulled low. |
|   0  |    1   |       1       | Input |    No   | Tri-state(Hi-Z) |
|   1  |    0   |       X       | Output|    No   | Output Low(Sink)|
|   1  |    1   |       X       | Output|    No   | Output High(Source) |


