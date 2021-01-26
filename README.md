# Dave's Garage
# Controlls WS2812B leds and outputs to the intergrated OLED Display and serial

### Need help or have a question? See Dave's Garage on YouTube.

## Contents
- [Development Status](#development-status)
- [Installation Instructions](#installation-instructions)
- [Decoding Exceptions](#decoding-exceptions)
- [Issue/Bug report template](#issuebug-report-template)
- [WEMOS LOLIN32 with OLED Board](#WEMOS-LOLIN32)
- [AdaFruit Feather32](#-AdaFruit-Feather32)
- [Heltec WiFi LORA 32 V1](#Heltec-WiFi-LORA-32-V1)
- [BME280](#BME280)

## Development Status

Working at this whole thing.

## Installation Instructions
- Use VS Code and PlatformIO

#### Decoding exceptions

I have no idea how to do this or what they are talking about.

#### Issue/Bug report template

Finally, if you're sure no one else had the issue, it's probably you.

## WEMOS LOLIN32
Board name WEMOS LOLIN32.<br/>
Must hold down button near edge to begin program.

This ESP32 board requires the SSD1306 libraries to communicate with the OLED display.<br/>
On this board the I2C communication pins to the OLED display are pin5 (SDA) and pin4 (SCL), so make sure to change the pins in the initialization: SSD1306 display(0x3c, 5, 4)
![Pin Functions](docs/WemosESP32OLEDTop.jpg)
![Pin Functions](docs/WemosESP32OLEDBottom.jpg)
![Pin Functions](docs/WemosESP32OLEDPinout.jpg)

## AdaFruit Feather32
Adafruit HUZZAH32 – ESP32 Feather Board<br/>
Don't need to hold anything low on the Feather.<br/>
<ul>
    <li>I2C Connections:</li>
    <li>    SCL 22</li>
    <li>    SDA 23</li>
</ul>

![Pin Functions](docs/AdafruitHUZZAH32-ESP32FeatherPinoutTop.jpg)
![Pin Functions](docs/AdafruitHUZZAH32-ESP32FeatherPinoutBottom.jpg)

## Heltec WiFi LORA 32 V1
Heltec WiFi LORA 32 V1 – ESP32 with OLED and LORA Board<br/>
To program you need to hold button labeled PRG near coil antenna.<br/>
<ul>
    <li>I2C Connections:</li>
    <li>    SCL 22</li>
    <li>    SDA 21</li>
    <li>OLED Connections:</li>
    <li>    CLOCK 15</li>
    <li>    DATA 4</li>
    <li>    RESET 16</li>
</ul>

![Pin Functions](docs/WiFi-LORA-32-pinout-Diagram.png)

## BME280
I2C address is 0x76 or 0x77 if you cut the trace between the left two pads and add a jumper to the right two pads.
![Pin Functions](docs/BMP280.jpg)

## Hint

Sometimes to program ESP32 via serial you must keep GPIO0 LOW during the programming process.