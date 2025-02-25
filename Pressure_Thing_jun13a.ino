/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled 2"
  https://create.arduino.cc/cloud/things/559ccdc2-c704-4748-8f2c-446ddec5caae 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  float pressure;
  float pressure2;
  int rawlevelreading1;
  int rawlevelreading2;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

const int sensorPin = A2;
const int sensorPin2 = A3;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  // set up led screen
  matrix.begin();

  matrix.beginDraw();

  matrix.stroke(0xFFFFFFFF);
  matrix.textScrollSpeed(100);

  const char text[] = "  HELLO  ";
  matrix.textFont(Font_4x6);
  matrix.beginText(0, 1, 0xFFFFFF);
  matrix.println(text);
  matrix.endText(SCROLL_LEFT);

  matrix.endDraw();
}

void loop() {
  ArduinoCloud.update();
  int sensorValue = analogRead(sensorPin); // Read the analog input
  pressure = sensorValue*0.0139 - 2.6577;
  int sensorValue2 = analogRead(sensorPin2); // Read the analog input
  pressure2 = sensorValue2*0.0176 - 2.7184;

  rawlevelreading1 = sensorValue;
  rawlevelreading2 = sensorValue2;
  
  Serial.print(pressure);
  Serial.print("\n");
  Serial.print(pressure2);
  Serial.print("\n");

  Serial.print(sensorValue);
  Serial.print("\n");

  Serial.print(sensorValue2);
  Serial.print("\n");

  
  if (WiFi.status() == WL_CONNECTED) {
        matrix.beginDraw();

    matrix.loadFrame(LEDMATRIX_CLOUD_WIFI);
  }
  
  else {
    matrix.beginDraw();

    matrix.stroke(0xFFFFFFFF);
    matrix.textScrollSpeed(50);

    // add the text
    const char text[] = "    Not Connected :(    ";
    matrix.textFont(Font_5x7);
    matrix.beginText(0, 1, 0xFFFFFF);
    matrix.println(text);
    matrix.endText(SCROLL_LEFT);

    matrix.endDraw();
  }
  delay(1000);
  
}


/*
  Since Pressure is READ_WRITE variable, onPressureChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onPressureChange()  {
  // Add your code here to act upon Pressure change
}


/*
  Since Pressure2 is READ_WRITE variable, onPressure2Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onPressure2Change()  {
  // Add your code here to act upon Pressure2 change
}


/*
  Since Rawlevelreading1 is READ_WRITE variable, onRawlevelreading1Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onRawlevelreading1Change()  {
  // Add your code here to act upon Rawlevelreading1 change
}

/*
  Since Rawlevelreading2 is READ_WRITE variable, onRawlevelreading2Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onRawlevelreading2Change()  {
  // Add your code here to act upon Rawlevelreading2 change
}