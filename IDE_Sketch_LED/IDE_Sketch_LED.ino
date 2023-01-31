#include <VSync.h>    //Including the library that will help us in receiving and sending the values from processing
ValueReceiver<1> receiver;  /*Creating the receiver that will receive 1 value.
  Put the number of values to synchronize in the brackets */

/* The below variable will be synchronized in the processing
  and they should be same on both sides. */
int output;

// Initializing the pins for led's
int red_light_pin = 11;
int green_light_pin = 10;
int blue_light_pin = 9;

void setup()
{
  /* Starting the serial communication because we are communicating with the
    Processing through serial. The baudrate should be same as on the processing side. */
  Serial.begin(19200);
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);

  // Synchronizing the variable with the processing. The variable must be int type.
  receiver.observe(output);
}

void loop()
{
  // Receiving the output from the processing.
  receiver.sync();

  // Matching the received output to light up the RGB LED
  if (output == 1)
  {
    RGB_color(255, 0, 0); // Red
  }
  else if (output == 2)
  {
    RGB_color(0, 255, 0); // Green
  }
  else if (output == 3)
  {
    RGB_color(0, 0, 255); // Blue
  }
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
{
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
