# Hardware Connections (Arduino UNO)

## Components
- Arduino UNO
- RC522 RFID Reader
- DFPlayer Mini + Speaker
- HC-SR04 Ultrasonic Sensor
- Push Button
- Buzzer
- 5V Power Supply

## Pin Configuration

| Component | Pin | Arduino Pin |
|------------|-----|--------------|
| RC522 SDA  |     | D10 |
| RC522 SCK  |     | D13 |
| RC522 MOSI |     | D11 |
| RC522 MISO |     | D12 |
| RC522 RST  |     | D9 |
| RC522 VCC  |     | 3.3V |
| RC522 GND  |     | GND |
| HC-SR04 TRIG |   | D7 |
| HC-SR04 ECHO |   | D8 |
| DFPlayer RX |    | D6 |
| DFPlayer TX |    | D5 |
| DFPlayer VCC |   | 5V |
| DFPlayer GND |   | GND |
| Button |         | D2 |
| Buzzer |         | D3 |

> RC522 runs at 3.3V (do not use 5V).
