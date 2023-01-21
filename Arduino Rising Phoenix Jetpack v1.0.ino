//Arduino Rising Phoenix Jetpack Version 1.0
//Created by Mark Konior
//Neopixel Fire Simulation code written by Robo Ulbricht - https://github.com/RoboUlbricht/arduinoslovakia/tree/master/neopixel/neopixel_fire01
//
//This code is covered by a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License - https://github.com/konior21/ArduinoRisingPhoenix/blob/main/LICENSE
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.

#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>
#include <DFPlayerMini_Fast.h>
SoftwareSerial mySerial(4, 3); // RX, TX Pins on Nano to DFPlayer Mini
DFPlayerMini_Fast myMP3;

#define PIN 12 // Neopixel Pin
// led count
#define CNT 16

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(CNT, PIN, NEO_GRB + NEO_KHZ800);

///
/// Fire simulator
///

uint32_t fire_color   = strip.Color ( 255,  100,  00);
uint32_t off_color    = strip.Color (  0,  0,  0);

class NeoFire
{
  Adafruit_NeoPixel &strip;
 public:

  NeoFire(Adafruit_NeoPixel&);
  void Draw();
  void Clear();
  void AddColor(uint8_t position, uint32_t color);
  void SubstractColor(uint8_t position, uint32_t color);
  uint32_t Blend(uint32_t color1, uint32_t color2);
  uint32_t Substract(uint32_t color1, uint32_t color2);
};

///
/// Constructor
///
NeoFire::NeoFire(Adafruit_NeoPixel& n_strip)
: strip (n_strip)
{
}

///
/// Set all colors
///
void NeoFire::Draw()
{
Clear();

for(int i=0;i<CNT;i++)
  {
  AddColor(i, fire_color);
  int r = random(50,150);
  uint32_t diff_color = strip.Color ( r, r/2, r/2);
  SubstractColor(i, diff_color);
  }
  
strip.show();
}

///
/// Set color of LED
///
void NeoFire::AddColor(uint8_t position, uint32_t color)
{
uint32_t blended_color = Blend(strip.getPixelColor(position), color);
strip.setPixelColor(position, blended_color);
}

///
/// Set color of LED
///
void NeoFire::SubstractColor(uint8_t position, uint32_t color)
{
uint32_t blended_color = Substract(strip.getPixelColor(position), color);
strip.setPixelColor(position, blended_color);
}

///
/// Color blending
///
uint32_t NeoFire::Blend(uint32_t color1, uint32_t color2)
{
uint8_t r1,g1,b1;
uint8_t r2,g2,b2;
uint8_t r3,g3,b3;

r1 = (uint8_t)(color1 >> 16),
g1 = (uint8_t)(color1 >>  8),
b1 = (uint8_t)(color1 >>  0);

r2 = (uint8_t)(color2 >> 16),
g2 = (uint8_t)(color2 >>  8),
b2 = (uint8_t)(color2 >>  0);

return strip.Color(constrain(r1+r2, 0, 255), constrain(g1+g2, 0, 255), constrain(b1+b2, 0, 255));
}

///
/// Color blending
///
uint32_t NeoFire::Substract(uint32_t color1, uint32_t color2)
{
uint8_t r1,g1,b1;
uint8_t r2,g2,b2;
uint8_t r3,g3,b3;
int16_t r,g,b;

r1 = (uint8_t)(color1 >> 16),
g1 = (uint8_t)(color1 >>  8),
b1 = (uint8_t)(color1 >>  0);

r2 = (uint8_t)(color2 >> 16),
g2 = (uint8_t)(color2 >>  8),
b2 = (uint8_t)(color2 >>  0);

r=(int16_t)r1-(int16_t)r2;
g=(int16_t)g1-(int16_t)g2;
b=(int16_t)b1-(int16_t)b2;
if(r<0) r=0;
if(g<0) g=0;
if(b<0) b=0;

return strip.Color(r, g, b);
}

///
/// Every LED to black
///
void NeoFire::Clear()
{
for(uint16_t i=0; i<strip.numPixels (); i++)
  strip.setPixelColor(i, off_color);
}

NeoFire fire(strip);

//[GLOBAL_VARIABLES]
int btnPin = 10;

boolean isBtn(){
   int a = digitalRead(btnPin);
     if(!a){
       return true;
     }
     else{
       return false;
     }
}

int cnt1 = 0;
int cnt2 = 0;

int pump = 7;
int fan = 2;
int vape = 13;

boolean btnPressed = false;
int cnt = 0;
int delayApplied = true;
int delayTime = 1400; //Delay before Neopixels activate. You can adjust if needed (in ms).

void DelayTimer(long int DelayValue){
  long int DelayTime = millis();
  do {

if(!delayApplied){
       delay(delayTime);
       delayApplied = true;
      }
    

   fire.Draw();
   delay(random(25,125)); //Rate of color change for fire effect
     if(!isBtn()){
       break;
    }
  }while (millis()-DelayTime < DelayValue);
}


void setup() {
  pinMode(btnPin, INPUT_PULLUP);
   pinMode(pump, OUTPUT);
    pinMode(fan, OUTPUT);
     pinMode(vape, OUTPUT);
  strip.begin();
strip.show(); 
 mySerial.begin(9600);
  myMP3.begin(mySerial, true);
   myMP3.volume(30);
}



void loop() {

  if(isBtn()){
    btnPressed = true;
    activatePumps();
    activateFans();
    activateVape();
     
     myMP3.play(1); //0001.mp3, the starting sound
     DelayTimer(40000);
   
  }
  else{
     if(btnPressed){
      delayApplied = false;
      for(uint16_t i=0; i<strip.numPixels (); i++){
        strip.setPixelColor(i, off_color);
      }
      strip.show();
       deactivateVape();
        deactivatePumps();
        deactivateFans();
        myMP3.play(2); //0002.mp3, the ending sound
        btnPressed = false;
         
     }
  }
}

void activateVape(){
   digitalWrite(vape, HIGH);
   
}

void deactivateVape(){
   digitalWrite(vape, LOW);
   
}

void activatePumps(){
   digitalWrite(pump, HIGH);
   
}

void deactivatePumps(){
   digitalWrite(pump, LOW);
   
}

void activateFans(){
   digitalWrite(fan, HIGH);

}

void deactivateFans(){
   digitalWrite(fan, LOW);

}
