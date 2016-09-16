
/*
 * The Library is Too Dang Hot
 * A project for #brocklibmakes
 * 
 * 
 * Originally developed by Tim Ribaric @elibtronic
 * 
 * This build will create a tempurature indicator and turns an LED
 * - Green if temp in C is 22 or lower
 * - Yellow if temp is between 23
 * 
 * 
 * 
 * for more Make fun check out:
 * http://make.library.brocku.ca
 * 
 */


// These lines initialize the temp sensor
// be sure the two DHT.* files are in the same
// directory as your source code
// these drivers graciously cribbed from AdaFruit:
// https://github.com/adafruit/DHT-sensor-library

#include "DHT.h"
#define DHTPIN 2        //We'll attach sensor to digital pin 2
#define DHTTYPE DHT11   //The side of the sensor has the model number stamped on it
DHT dht(DHTPIN,DHTTYPE);
#define CHECK_DELAY 1000  //This is the amount of time we want in-between checks of the sensor

// These lines setup what digital pins we'll use for the different colour LEDS
// Experiment with making these different (or adding more even)
#define RED 8           //Red LED on digital pin 8
#define YELLOW 10       //Yellow LED on digital pin 10
#define GREEN 12        //Green LED on digital pin 12



//This function is only run once when the Arduino powers up
//it sets up the LEDS and does the 'cool boot-up animation'
void setup() {

  //When we use pins to power LEDs we set them to OUTPUTs
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);

  //'Cool boot-up animation'
  cycle_lights();

  //Start the temp sensor
  dht.begin();
  
}

//This is only run once when the Arduino boots up
//try exerimenting with different combinations to get an
//even 'cooler' boot-up animation
void cycle_lights(){

  digitalWrite(GREEN, HIGH);
  delay(750);
  digitalWrite(YELLOW, HIGH);
  delay(750);
  digitalWrite(RED, HIGH); 
  delay(1000);              
  digitalWrite(RED, LOW);   
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
  

}


void loop() {

  delay(CHECK_DELAY);
  float t = dht.readTemperature();

  if (t >= 25){ //Really hot, turns red
    digitalWrite(RED,HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);
  }
  if (t <= 24 && t >= 23){ //Medium hot, just a tad uncomfortable so proceed with caution
    digitalWrite(YELLOW,HIGH);
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
  }
  if (t <= 22){ //Cool as a cucumber, so green like one too
    digitalWrite(GREEN,HIGH);
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, LOW);
  }

  

}
