#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>
#include <RH_ASK.h>

#define RADIO_TX_PIN 16



#define RADIOHEAD_BAUD 2000 // Transmission Speed
#define RADIOHEAD_TX_PIN 16  // Pin of the 433MHz transmitter
#define RADIOHEAD_RX_PIN 16 // Pin of the 433MHz receiver (here not used)


RH_ASK driver(RADIOHEAD_BAUD, RADIOHEAD_RX_PIN, RADIOHEAD_TX_PIN);

void setup() {
    driver.init();
    Serial.begin(9600);
}

void loop() {
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);

    if (driver.recv(buf, &buflen)) { // Non-blocking
        int i;

        // Message with a good checksum received, dump it.
        driver.printBuffer("Got:", buf, buflen);
        for(int i=0; i< 10; i++){
          
          Serial.println((char)buf[i]);
        }
    }
}
