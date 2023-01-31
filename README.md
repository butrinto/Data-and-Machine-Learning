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

#### Setting up the board

We would first initialise the physical pins on the connected boards to the LED Bulb

```
// Initializing the pins for led's
int red_light_pin = 11;
int green_light_pin = 10;
int blue_light_pin = 9;
``` 
<p align="center">
  <img width="235" height="300" src=./images/PictureIDE.png>
</p>

<p align="center">
This is what the physical part of the project looked like.
</p>


#### Communication Field

This was used to set up the signal which would allow the pins to communicate.

```
void setup()
{
  /* Starting the serial communication - Processing through serial. The baudrate should be same as on the processing side. */
  Serial.begin(19200);
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);

  // Synchronizing the variable with the processing. The variable must be int type.
  receiver.observe(output);
}
```

#### Colours

Lastly, setting up the LED Pins to emit colour. As they were all RBG bulbs, they had to be set up using the Decimal Code (R, G, B):

```
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
```

### Wekinator
Wekinator is an open source machine learning programme with a simple interface which allows you to use any OSC (Open Sound Control) output and input. In this case, our input will be facial expressions, and our output will be the LED Bulbs on the Arduino

<p align="center">
  <img width="400" height="300" src=./images/Image13.png>
</p>

<p align="center">
This is the core system of Wekinator's FaceOSC, using openFrameworks
</p>

With Wekinator to 'record' facial features from openFrameworks - this allows the software to train different features by using the record button on Wekinator

<p align="center">
  <img width="400" height="275" src=./images/image14.jpg>
</p>

<p align="center">
Diagram showing on Wekinator uses the inputs and outputs into different applications
openFrameworks > Wekinator > Arduino Board
</p>
