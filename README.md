# Data and Machine Learning

This project incorporates the use of Machine Learning to train a user’s facial expressions; converting these trained expressions to control an Arduino board, programming it to light up an LED in various colours.

[Installation](#Installation) | [What does it do?](#MachineLearning) | [How does it work?](#MachineLearning2) |

Technologies: C++, Arduino IDE, Wekinator,

## <a name="Installation">Installation — How does it work?</a>

- Install the example code found here: (http://www.wekinator.org/examples/#VideoWebcam) for the input
- Open the processing file in Processing (Right click > Open With > Processing), and the IDE file in ArduinoIDE.
- Verify and Upload the IDE File onto your Arduino.
- Your Arduino should flash to signify that its successfully received data. Run the Processing file.
- On Wekinator, create 14 inputs and 1 output, and change the output type to Dynamic time warping.

## <a name="MachineLearning">Machine Learning — What does it do?</a>

With the release of in-built LED Back Panels on TVs, that mimic the colours being emitted from the screen; I wondered if you could do the same thing, but instead of analysing and outputting colours from the TV, would instead analyse the emotions that the user is feeling when watching their favourite TV show. 

The creative purpose for this project is a small scale prototype for a potential product. This product could use a webcam, reading a users facial expressions while engaging with entertainment (TV, Games, etc) - to set room ambience with a light bar or LED strip.

## <a name="MachineLearning2">This project — How does it work?</a>

An Arduino Board and the Wekinator App were prominently used to create this project

### Arduino IDE

The Arduino integrated development environment (IDE) was solely used to allow the Arduino board to connect and contact with the workstation. This would then converse with the Wekinator application to transfer outputs to the board

## Setting up the board

We would first initialise the physical pins on the connected boards to the LED Bulb

```
// Initializing the pins for led's
int red_light_pin = 11;
int green_light_pin = 10;
int blue_light_pin = 9;
``` 
<p align="center">
  <img width="460" height="300" src=./Images/PictureIDE.png>
</p>

This is what the physical part of the project looked like.

Next, create the communication field

```
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
```




