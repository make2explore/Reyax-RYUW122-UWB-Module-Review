// ---------------------------------- make2explore.com -------------------------------------------------------//
// Project           - Reyax-RYUW122 Application - Distance Measurement
// Created By        - info@make2explore.com
// Last Modified     - 07/02/2024 18:16:00 @admin
// Software          - C/C++, Arduino IDE, Libraries
// Hardware          - NodeMCU ESP32S, Reyax RYUW122 UWB Module, OLED Display        
// Sensors Used      - Null
// Source Repo       - github.com/make2explore
// -----------------------------------------------------------------------------------------------------------//
// This code is of **UWB ANCHOR Node**
// We have not included configuration AT commands in code.
// We've pre-configured UWB modules using manual method we discussed in video.
// *Asynchronous Code - In this code, we are not checking responses and Error codes of commands.
// This is simple and minimal coding paradigm.
// ===========================================================================================================//

// Include Libraries
#include <Wire.h>                // Include wire/I2C library
#include <Adafruit_GFX.h>        // Include core graphics library
#include <Adafruit_SSD1306.h>    // Include Adafruit_SSD1306 library to drive the display

// Define SSD1306 OLED Display Resolution 128x64 
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Invoke Display and Create display Instance 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// "make2explore Systems" Logo Bitmap array 
static const uint8_t image_data_096OLEDscreens[1024] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x03, 0xe0, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x3f, 0xfc, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0xff, 0xfe, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x63, 0xff, 0xff, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc7, 0xff, 0x3f, 0x80, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8f, 0xff, 0x3f, 0x80, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x1f, 0xfe, 0x1f, 0xc0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x3f, 0xf8, 0x07, 0xc0, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x7f, 0xf8, 0x07, 0xc0, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x7f, 0xfe, 0x1f, 0xc0, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xff, 0xff, 0x3f, 0xc0, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0xff, 0xff, 0x3f, 0xc0, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0xff, 0xff, 0xff, 0x80, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0xff, 0xff, 0xff, 0x80, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x19, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0xff, 0xff, 0xfe, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0xff, 0xff, 0xf8, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0xff, 0xff, 0xe0, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0xff, 0xf8, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0xff, 0xe0, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0xff, 0xc0, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0xff, 0x80, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x19, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0xff, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0xfe, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0xfe, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xfe, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x7e, 0x07, 0xf8, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x7e, 0x07, 0xf8, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x3e, 0x07, 0xf8, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x1e, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8e, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc7, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xc0, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// ANCHOR send command
// AT+ANCHOR_SEND=<Address of TAG>,<Payload/data length>,<data in ASCII format>
// AT+ANCHOR_SEND=9,4,TEST
String ANCHOR_SendMSG_cmd = "AT+ANCHOR_SEND=9,4,TEST";

// variables for timer
const unsigned long sendInterval = 10000;
unsigned long previousTime = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(115200);

  Serial.println("Starting....");
  Serial.println("");

  // initialize the display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000); // Pause for 2 seconds
 
  // Clear the buffer.
  display.clearDisplay();
  
  // Draw bitmap (make2explore Logo) on the screen
  display.drawBitmap(0, 0, image_data_096OLEDscreens, 128, 64, 1);
  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(20, 56);
  // Display static text
  display.println("make2explore.com");
  display.display();
  delay(7000);

  // Clear the buffer.
  display.clearDisplay();
  display.drawRect(0, 0, 126, 62, WHITE);
  display.drawLine(0, 20, 126, 20, WHITE);
  //display.fillRect(0, 0, 126, 28, WHITE);
  display.setCursor(28,3);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.print("ANCHOR");
  
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(5,30);
  display.print("- - -");
  
  display.setCursor(98,36);
  display.setTextSize(2);
  display.print("cm");
   
  display.display();
}

// Function for serially sending Anchor Send command
void sendMsg(){
  Serial.println(ANCHOR_SendMSG_cmd);
  Serial1.println(ANCHOR_SendMSG_cmd); 
}

//====================== Function for parsing the incomming data String ======================================//
String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;
 
    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

//====================== Function to Check Incomming Serial Data ====================================//
void checkSerial(){
  while (Serial1.available() > 0) {
    // get the new byte:
    String inString = Serial1.readString();
    inString.remove(0,3);     //Remove +OK\n
    Serial.print("Received Data : ");
    Serial.println(inString); 
    // To understand the AT commands and their responses, please refer AT commands guide document
    // When we issue ANCHOR+SEND command we will receive 2 responses. First is +OK for ANCHOR+SEND
    // command and Second is +ANCHOR_RCV subcommand will get automatically executed to show the distance
    // Data receiving format : +ANCHOR_RCV=<TAG Address>,< PAYLOAD LENGTH>,<TAG DATA>,<DISTANCE>
    // Example:   +OK
    //            +ANCHOR_RCV=DAVID123,5,HELLO,40 cm
    //                |          |   |    |   |
    //                0          1   2    3   4
    // So to get Distance : String DataIn = getValue(inString, ',', index number);
    // Example:    So to get Distance which is at position 4 in above response : 
    //             String DataIn = getValue(inString, ',', 4);
    // Please note, if there is issue in receiving distance value, please adjust the index number
    // here we have set it to 3, you can set according to your responses
    // Sometimes we get garbage value or no values at all. 
    // These RYUW122 modules need to placed face to face in clear LOS(Line of Sight), otherwise you
    // may not get readings properly or you may also get corrupted readings.
    // Use RESET button to reset the module

    String Distance = getValue(inString, ',', 3);     //--> data
    Serial.print("Distance = ");
    Serial.println(Distance);

    // Clear the buffer.
    display.clearDisplay();
    display.drawRect(0, 0, 126, 62, WHITE);
    display.drawLine(0, 20, 126, 20, WHITE);

    display.setCursor(28,3);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.print("ANCHOR");
    
    // Display the Distance Value
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(5,30);
    display.print(Distance);
     
    display.display(); 
  }  
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();
  if (currentTime - previousTime >= sendInterval) {
    sendMsg();
    previousTime = currentTime;
  }
  checkSerial();
}

// ---------------------------------- make2explore.com----------------------------------------------------//