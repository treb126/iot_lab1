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
}

void loop() {
    const char *msg = "hello"; // "Just say hello" ~Rene Froger

    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(200);
}



