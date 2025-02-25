# Arduino [Rising Phoenix](https://starwars.fandom.com/wiki/Rising_Phoenix) Electronics
Open-source electronics project for the Rising Phoenix jetpack worn by Din Djarin in 'The Mandalorian'.

![Screenshot](RisingPhoenixScreenshot.jpg)

Includes LEDs with flame effect, sound effects, and smoke that is all controlled by a wireless remote.

[Buy a Rising Phoenix PCB here](https://markalorian.gumroad.com/l/risingphoenixpcb)
Currently out of stock. The .ino file to have your own made is available above however.

Video Demo - https://www.youtube.com/shorts/M8bbbQtCOJw

Follow me on Instagram - https://www.instagram.com/the_markalorian/

## Parts list
In addition to the 3d printed parts available in the files section, you will need the following:
1) [Arduino Nano](https://smile.amazon.com/gp/product/B0713XK923/) - controller for this project.
2) [Rising Phoenix board](https://markalorian.gumroad.com/l/risingphoenixpcb) (or blank [prototyping PCBs](https://smile.amazon.com/gp/product/B072Z7Y19F/) and [connectors](https://smile.amazon.com/gp/product/B088LSS14J/)).
3) [DFPlayer Mini](https://www.dfrobot.com/product-1121.html) - get an authentic one made by DFRobot. The knock-offs didn't work in my experience.
4) Micro SD card - any size should do.
5) [1k ohm resistor](https://smile.amazon.com/gp/product/B07QG1V4YL/) - for the DFPlayer's RX pin. (This is included with the Rising Phoenix board.)
6) [12v mini amplifier](https://smile.amazon.com/gp/product/B08GYQTTXF/) - to increase the output of the DFPlayer Mini.
7) (2) [25mm exciters](https://smile.amazon.com/gp/product/B00M292316/) - these stick to the inside of the pack to create the sound.
8) (2) [16 bit Neopixel LED rings](https://smile.amazon.com/Adafruit-NeoPixel-Ring-Integrated-Drivers/dp/B00KBXT9I0/) - to place inside the thrusters for the flame effect. Other brands with WS2812B or SK6812-based LEDs should also work, but you may need to change one line in the Arduino .ino file
9) (4) [5v relay modules](https://smile.amazon.com/gp/product/B09G6H7JDT/) - to activate the various components.
10) (2) [5v 5015 blower fans](https://smile.amazon.com/gp/product/B07V2KVQB7/) - used to increase airflow of smoke.
11) (2) [12v mini air pumps](https://smile.amazon.com/gp/product/B0786BQYKM/) - used to push air through the vaporizers.
12) (2) ecig vaporizers/atomizers - the [Kanger T2](https://www.google.com/search?q=kanger+t2+clearomizer) design seems works best and what this project was designed for but they are getting hard to find.
  Optional (2) [510 threaded connectors](https://www.aliexpress.us/item/3256804393659205.html) - Makes connecting the negative wire to the atomizor much easier
13) (2) [18650 batteries](https://www.18650batterystore.com/products/molicel-p26a) - need a high current output. These power the vaporizers.
14) [Talentcell 3000 mAh rechargable battery pack](https://smile.amazon.com/gp/product/B01M7Z9Z1N/) - provides both 5v and 12v power to everything except the vaporizers. Will not automatically power off like most USB battery packs.
15) [Wiress RF remote](https://www.amazon.com/gp/product/B077ZQMQDZ) - to activate the jetpack. 
16) [Silicone Tubing 4mm ID X 6mm OD](https://smile.amazon.com/gp/product/B07V5MX1Q4/)
17) [Silicone Tubing 8mm ID x 11mm OD](https://smile.amazon.com/gp/product/B07V5PKYMK/)
18) [24-22 AWG hookup wire](https://smile.amazon.com/gp/product/B073QHPGMC/)
19) [Ferrule Connectors](https://www.amazon.com/Ferrule-Crimping-Tools-Wire-Pliers/dp/B07WRQN45C/) - Optional
20) [Wago lever nuts](https://smile.amazon.com/gp/product/B07W4RQ6R6/) - Optional - for some of the 12v wire connections

## Wiring Diagram
Using custom Rising Phoenix board
![Custom PCB Diagram](MandoJetpackCustomPCB_bb.png)

Using prototype board
![Breadboard Diagram](MandoJetpackBreadboard-v1.1.png)

## Instructions

Detailed instructions coming soon

![Custom PCB](https://user-images.githubusercontent.com/26532166/213885789-4250f816-c399-4070-83a2-46ca65842486.jpg)
![Full Interior](https://user-images.githubusercontent.com/26532166/213885795-49783b32-0949-4dde-9b04-192754ed75e2.jpg)
![Left Side 1](https://user-images.githubusercontent.com/26532166/213885799-f96e9c15-b55e-401c-a0f2-e44c2cdaa6cc.jpg)
![Left Side 2](https://user-images.githubusercontent.com/26532166/213885803-ee82f3f9-a74b-41d1-84b8-0c2709d51f0b.jpg)
![Right Side 1](https://user-images.githubusercontent.com/26532166/213885809-7cfd07d8-72a5-4993-a394-aa67f80eb149.jpg)
![Right Side 2](https://user-images.githubusercontent.com/26532166/213885812-ca522bf8-8eb5-4003-b72b-4c9647b45bf9.jpg)
