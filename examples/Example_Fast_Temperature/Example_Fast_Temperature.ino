///
/// @file Example_Fast_Temperature.ino
/// @brief Example of features for fast edition
///
/// @details Library for Pervasive Displays EXT3 - Basic level
///
/// @author Rei Vilo
/// @date 21 Jan 2024
/// @version 704
///
/// @copyright (c) Rei Vilo, 2010-2023
/// @copyright Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)
///
/// @see ReadMe.txt for references
/// @n
///

// Screen
#include "PDLS_EXT3_Basic_Fast.h"

// SDK
// #include <Arduino.h>
#include "hV_HAL_Peripherals.h"

// Include application, user and local libraries
// #include <SPI.h>

// Configuration
#include "hV_Configuration.h"

// Set parameters

// Define structures and classes


// Define variables and constants
Screen_EPD_EXT3_Fast myScreen(eScreen_EPD_EXT3_266_0C_Fast, boardRaspberryPiPico_RP2040);
// Screen_EPD_EXT3_Fast myScreen(eScreen_EPD_EXT3_271_09_Wide, boardRaspberryPiPico_RP2040);

// Prototypes

// Utilities

// Functions
void check(int8_t temperatureC, uint8_t expectedMode)
{
    const char * stringMode[] = { "NONE", "GLOBAL", "FAST", "PARTIAL" };
    myScreen.setTemperatureC(temperatureC);
    uint8_t recommendedMode = myScreen.checkTemperatureMode(expectedMode);
    Serial.print("Temperature= ");
    Serial.print(temperatureC);
    Serial.print(" C - Mode: ");
    Serial.print(stringMode[expectedMode]);
    Serial.print(" -> ");
    Serial.print(stringMode[recommendedMode]);
    Serial.println();
}

void performTest()
{
    check(+70, UPDATE_FAST);

    check(+60, UPDATE_FAST);
    check(+50, UPDATE_FAST);
    check(+25, UPDATE_FAST);
    check(-15, UPDATE_FAST);
    check(-25, UPDATE_FAST);
}

// Add setup code
///
/// @brief Setup
///
void setup()
{
    Serial.begin(115200);
    delay(5000);

    Serial.println();
    Serial.println("=== " __FILE__);
    Serial.println("=== " __DATE__ " " __TIME__);
    Serial.println();

    myScreen.begin();

    Serial.println(formatString("=== %s %ix%i", myScreen.WhoAmI().c_str(), myScreen.screenSizeX(), myScreen.screenSizeY()));

    performTest();

    Serial.println("=== ");
    Serial.println();
}

// Add loop code
///
/// @brief Loop, empty
///
void loop()
{
    delay(1000);
}
