#include "Adafruit_NeoPixel.h"
#include <EEPROM.h>
#include <string.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 11

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

byte neopix_gamma[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
    2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
    5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
   10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
   17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
   25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
   37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
   51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
   69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
   90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
  115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
  144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
  177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
  215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };

int redColor = 0;
int greenColor = 0;
int blueColor = 0;

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  Serial.begin(9600);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {

  strip.setBrightness(EEPROM.read(1));

  while(!Serial.available()){
        
      if(EEPROM.read(0) == 11){
           colorWipe(strip.Color(255, 0, 0), EEPROM.read(2)); // Red
      }else if(EEPROM.read(0) == 12){
           colorWipe(strip.Color(0, 0, 255), EEPROM.read(2)); // Blue 
      }else if(EEPROM.read(0) == 13){
           colorWipe(strip.Color(0, 255, 0), EEPROM.read(2)); // Green
      }else if(EEPROM.read(0) == 14){
          colorWipe(strip.Color(255, 0, 0), EEPROM.read(2)); // Red
          colorWipe(strip.Color(0, 0, 255), EEPROM.read(2)); // Blue
      }else if(EEPROM.read(0) == 15){
          colorWipe(strip.Color(255, 0, 0), EEPROM.read(2)); // Red
          colorWipe(strip.Color(0, 255, 0), EEPROM.read(2)); // Green
      }else if(EEPROM.read(0) == 16){
          colorWipe(strip.Color(0, 0, 255), EEPROM.read(2)); // Blue
          colorWipe(strip.Color(0, 255, 0), EEPROM.read(2)); // Green
      }else if(EEPROM.read(0) == 17){
          colorWipe(strip.Color(255, 0, 0), EEPROM.read(2)); // Red
          colorWipe(strip.Color(0, 0, 255), EEPROM.read(2)); // Blue
          colorWipe(strip.Color(0, 255, 0), EEPROM.read(2)); // Green
      }else if(EEPROM.read(0) == 31){
           theaterChase(strip.Color(127, 0, 0), EEPROM.read(2)); // Red
      }else if(EEPROM.read(0) == 32){
           theaterChase(strip.Color(0, 0, 127), EEPROM.read(2)); // Blue
      }else if(EEPROM.read(0) == 33){
           theaterChase(strip.Color(0, 127, 0), EEPROM.read(2)); // Green
      }else if(EEPROM.read(0) == 34){
          theaterChase(strip.Color(127, 0, 0), EEPROM.read(2)); // Red
          theaterChase(strip.Color(0, 0, 127), EEPROM.read(2)); // Blue
      }else if(EEPROM.read(0) == 35){
          theaterChase(strip.Color(127, 0, 0), EEPROM.read(2)); // Red
          theaterChase(strip.Color(0, 127, 0), EEPROM.read(2)); // Green
      }else if(EEPROM.read(0) == 36){
          theaterChase(strip.Color(0, 0, 127), EEPROM.read(2)); // Blue
          theaterChase(strip.Color(0, 127, 0), EEPROM.read(2)); // Green
      }else if(EEPROM.read(0) == 37){
          theaterChase(strip.Color(127, 0, 0), EEPROM.read(2)); // Red
          theaterChase(strip.Color(0, 0, 127), EEPROM.read(2)); // Blue
          theaterChase(strip.Color(0, 127, 0), EEPROM.read(2)); // Green
      }else if(EEPROM.read(0) == 2){
          rainbowCycle(EEPROM.read(2));
      }else if(EEPROM.read(0) == 100){
        
          colorWipe(strip.Color(255, 0, 0), 50); // Red
          colorWipe(strip.Color(0, 255, 0), 50); // Green
          colorWipe(strip.Color(0, 0, 255), 50); // Blue
          theaterChase(strip.Color(127, 127, 127), 50); // White
          theaterChase(strip.Color(127, 0, 0), 50); // Red
          theaterChase(strip.Color(0, 0, 127), 50); // Blue
          rainbow(20);
          rainbowCycle(20);
          theaterChaseRainbow(50);
      }else if(EEPROM.read(0) == 101){
          whiteOverRainbow(20,75,5);
          rainbowFade2White(3,3,1);
      }else if(EEPROM.read(0) == 102){
          theaterChase(strip.Color(127, 127, 127), 20);
          theaterChaseRainbow(20);
      }else if(EEPROM.read(0) == 103){
          Colorful();
      }

  }
    

  if(Serial.available()){

    String info, cmd, cmd2, cmd3;
    int pos, wait;
    info = Serial.readStringUntil('\n');

    if(info.equals("Simulation1")){

  colorWipe(strip.Color(255, 0, 0), 50); // Red
  colorWipe(strip.Color(0, 255, 0), 50); // Green
  colorWipe(strip.Color(0, 0, 255), 50); // Blue
//colorWipe(strip.Color(0, 0, 0, 255), 50); // White RGBW
  // Send a theater pixel chase in...
  theaterChase(strip.Color(127, 127, 127), 50); // White
  theaterChase(strip.Color(127, 0, 0), 50); // Red
  theaterChase(strip.Color(0, 0, 127), 50); // Blue

  rainbow(20);
  rainbowCycle(20);
  theaterChaseRainbow(50);
  EEPROM.write(0, 100);
      
    }else if(info.equals("Simulation2")){

      whiteOverRainbow(20,75,5);
      rainbowFade2White(3,3,1);
      EEPROM.write(0, 101);
      
    }else if(info.equals("Simulation3")){

      theaterChase(strip.Color(127, 127, 127), 20);
      theaterChaseRainbow(20);
      EEPROM.write(0, 102);
      
    }else if(info.equals("Simulation4")){

       Colorful();
       EEPROM.write(0, 103);
      
    }else{
    
    cmd = info;
    cmd2 = info;
    cmd3 = info;
    pos = info.indexOf(':');
    info = info.substring(0, pos);
    cmd = cmd.substring(pos+1, cmd2.indexOf('|'));
    cmd2 = cmd2.substring(cmd2.indexOf('|')+1);//, cmd2.indexOf('!')-cmd2.indexOf('|')-1);
    cmd3 = cmd3.substring(cmd3.indexOf('!')+1);
    strip.setBrightness(cmd.toInt());

    wait = cmd2.toInt();
    
    EEPROM.write(1, cmd.toInt());
    EEPROM.write(2, wait);

    
    if(info.equals("ColorWipe")){

      if(cmd3.equals("R")){
           colorWipe(strip.Color(255, 0, 0), wait); // Red
           EEPROM.write(0, 11);
      }else if(cmd3.equals("B")){
           colorWipe(strip.Color(0, 0, 255), wait); // Blue
           EEPROM.write(0, 12); 
      }else if(cmd3.equals("G")){
           colorWipe(strip.Color(0, 255, 0), wait); // Green
           EEPROM.write(0, 13);
      }else if(cmd3.equals("RB")){
          colorWipe(strip.Color(255, 0, 0), wait); // Red
          colorWipe(strip.Color(0, 0, 255), wait); // Blue
          EEPROM.write(0, 14);
      }else if(cmd3.equals("RG")){
          colorWipe(strip.Color(255, 0, 0), wait); // Red
          colorWipe(strip.Color(0, 255, 0), wait); // Green
          EEPROM.write(0,15);
      }else if(cmd3.equals("BG")){
          colorWipe(strip.Color(0, 0, 255), wait); // Blue
          colorWipe(strip.Color(0, 255, 0), wait); // Green
          EEPROM.write(0,16);
      }else if(cmd3.equals("RBG")){
          colorWipe(strip.Color(255, 0, 0), wait); // Red
          colorWipe(strip.Color(0, 0, 255), wait); // Blue
          colorWipe(strip.Color(0, 255, 0), wait); // Green
          EEPROM.write(0,17);
      } 
      
     }else if(info.equals("Rainbow")){

      rainbowCycle(wait);
       EEPROM.write(0, 2);
      
    }else if(info.equals("Wheel")){

      if(cmd3.equals("R")){
           theaterChase(strip.Color(127, 0, 0), wait); // Red
           EEPROM.write(0, 31);
      }else if(cmd3.equals("B")){
           theaterChase(strip.Color(0, 0, 127), wait); // Blue
           EEPROM.write(0, 32); 
      }else if(cmd3.equals("G")){
           theaterChase(strip.Color(0, 127, 0), wait); // Green
           EEPROM.write(0, 33);
      }else if(cmd3.equals("RB")){
          theaterChase(strip.Color(127, 0, 0), wait); // Red
          theaterChase(strip.Color(0, 0, 127), wait); // Blue
          EEPROM.write(0, 34);
      }else if(cmd3.equals("RG")){
          theaterChase(strip.Color(127, 0, 0), wait); // Red
          theaterChase(strip.Color(0, 127, 0), wait); // Green
          EEPROM.write(0,35);
      }else if(cmd3.equals("BG")){
          theaterChase(strip.Color(0, 0, 127), wait); // Blue
          theaterChase(strip.Color(0, 127, 0), wait); // Green
          EEPROM.write(0,36);
      }else if(cmd3.equals("RBG")){
          theaterChase(strip.Color(127, 0, 0), wait); // Red
          theaterChase(strip.Color(0, 0, 127), wait); // Blue
          theaterChase(strip.Color(0, 127, 0), wait); // Green
          EEPROM.write(0,37);
      }
      
    }

  }
  
  }
  
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }

   for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void whiteOverRainbow(uint8_t wait, uint8_t whiteSpeed, uint8_t whiteLength ) {
  
  if(whiteLength >= strip.numPixels()) whiteLength = strip.numPixels() - 1;

  int head = whiteLength - 1;
  int tail = 0;

  int loops = 3;
  int loopNum = 0;

  static unsigned long lastTime = 0;


  while(true){
    for(int j=0; j<256; j++) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
        if((i >= tail && i <= head) || (tail > head && i >= tail) || (tail > head && i <= head) ){
          strip.setPixelColor(i, strip.Color(0,0,0, 255 ) );
        }
        else{
          strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
        }
        
      }

      if(millis() - lastTime > whiteSpeed) {
        head++;
        tail++;
        if(head == strip.numPixels()){
          loopNum++;
        }
        lastTime = millis();
      }

      if(loopNum == loops) return;
    
      head%=strip.numPixels();
      tail%=strip.numPixels();
        strip.show();
        delay(wait);
    }
  }
  
}

void rainbowFade2White(uint8_t wait, int rainbowLoops, int whiteLoops) {
  float fadeMax = 100.0;
  int fadeVal = 0;
  uint32_t wheelVal;
  int redVal, greenVal, blueVal;

  for(int k = 0 ; k < rainbowLoops ; k ++){
    
    for(int j=0; j<256; j++) { // 5 cycles of all colors on wheel

      for(int i=0; i< strip.numPixels(); i++) {

        wheelVal = Wheel(((i * 256 / strip.numPixels()) + j) & 255);

        redVal = red(wheelVal) * float(fadeVal/fadeMax);
        greenVal = green(wheelVal) * float(fadeVal/fadeMax);
        blueVal = blue(wheelVal) * float(fadeVal/fadeMax);

        strip.setPixelColor( i, strip.Color( redVal, greenVal, blueVal ) );

      }

      //First loop, fade in!
      if(k == 0 && fadeVal < fadeMax-1) {
          fadeVal++;
      }

      //Last loop, fade out!
      else if(k == rainbowLoops - 1 && j > 255 - fadeMax ){
          fadeVal--;
      }

        strip.show();
        delay(wait);
    }
  
  }



  delay(500);


  for(int k = 0 ; k < whiteLoops ; k ++){

    for(int j = 0; j < 256 ; j++){

        for(uint16_t i=0; i < strip.numPixels(); i++) {
            strip.setPixelColor(i, strip.Color(0,0,0, neopix_gamma[j] ) );
          }
          strip.show();
        }

        delay(2000);
    for(int j = 255; j >= 0 ; j--){

        for(uint16_t i=0; i < strip.numPixels(); i++) {
            strip.setPixelColor(i, strip.Color(0,0,0, neopix_gamma[j] ) );
          }
          strip.show();
        }
  }

  delay(500);


}

uint8_t red(uint32_t c) {
  return (c >> 16);
}
uint8_t green(uint32_t c) {
  return (c >> 8);
}
uint8_t blue(uint32_t c) {
  return (c);
}

void setColor(){
  redColor = random(0, 255);
  greenColor = random(0,255);
  blueColor = random(0, 255);
  Serial.print("red: ");
  Serial.println(redColor);
  Serial.print("green: ");
  Serial.println(greenColor);
  Serial.print("blue: ");
  Serial.println(blueColor);
  
}

void Colorful(){

  setColor();

  for(int i=0;i<24;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    strip.setPixelColor(i, strip.Color(redColor, greenColor, blueColor)); // Moderately bright green color.

    strip.show(); // This sends the updated pixel color to the hardware.

    delay(100); // Delay for a period of time (in milliseconds).
    
    // Serial.println(i);
    
    if (i == 24){
      i = 0; // start all over again!
        setColor();
    }

  }

}
