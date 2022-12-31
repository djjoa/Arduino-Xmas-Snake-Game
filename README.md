# Arduino-Xmas-Snake-Game
Automatic snake game using WS2811 RGB lights and FastLED. 

## Description 
 I created this as an xmas project. 
- (red) snake grows when eating a piece of (green) food 
- small end animation when the game is finished which flashes lights and creates a growing rainbow effect.
- the program loops infinitely. 

Merry Christmas and Happy New Year 12/31/22! 
 
## Materials List
- [Arduino Uno](https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/ref=asc_df_B008GRTSV6/?tag=&linkCode=df0&hvadid=309751315916&hvpos=&hvnetw=g&hvrand=8606497603945950419&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9008306&hvtargid=pla-457497319401&ref=&adgrpid=67183599252&th=1) 
- [12v WS2811 LED string lights](https://www.amazon.com/dp/B06XSFT1VK?ref=ppx_yo2ov_dt_b_product_details&th=1) 
- USB cable to power the Arduino 
- Wall USB power supply ( I used a power strip with a 3 amp USB port)
- Jumper cables (3 Male -> Male, 3 Female -> Male) 
  - this bundle has both https://www.amazon.com/Elegoo-EL-CP-004-Multicolored-Breadboard-arduino/dp/B01EV70C78/ref=sr_1_1_sspa?keywords=jumper%2Bwires%2Bmale%2Bto%2Bmale&qid=1672508309&sr=8-1-spons&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUFUMUxLSjkwVVBUVE0mZW5jcnlwdGVkSWQ9QTAwMDY0NzIzOU9BN0xES1dGTzZTJmVuY3J5cHRlZEFkSWQ9QTA0NTg2ODEzNzBURUJUUExUWkVaJndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ&th=1
  
## Wiring

|LEDS|Arduino|
|:--|:--|
|WS2811 12v power \[female] (wire with the AWG markings) |VIN| 
|WS2811 Data Pin \[female] (middle wire on my strip) | 4| 
|WS2811 Ground Pin \[female] (wire with the gray dashes)| GND| 

## Notes
- If using more than 250 lights, power must be injected. There are tons of YouTube videos on how to do this. 
- I added Snake3.py so everyone could see transition examples from python to C++. Snake3.py is not used in the project; it's just there as a reference. 

## Resources / References 
- FastLED: https://fastled.io/docs/3.1/group___colorutils.html

## Acknowledgements 

**Flávio Amieiro**

Thank you Flávio Amieiro! Although I didn't use any of your code in this project, your examples were very helpful.
- GitHub: https://github.com/flavioamieiro
- GitHub 1d_snake: https://github.com/flavioamieiro/snake_1D

**Engineer Man** 

Second thank you to Engineer Man for the Python Snake video and repo which I also used to build the MVP before converting to C++
- EM snake-game video : https://www.youtube.com/watch?v=rbasThWVb-c
- EM snake-game repo: https://github.com/engineer-man/youtube/blob/bfca0f792cee59582c8dc39841e8446352f3481f/015/snake.py

**@Random936**

@Random936 did the brunt of the work converting my Python rendition of this project into C++ and helped debug new features. Thank you Sir! 
- GitHub: https://github.com/Random936

**@djjoa** 

If you are happy with this project give it a start on GitHub! 
- My GitHub: https://github.com/djjoa

