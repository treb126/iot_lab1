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
/*
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


*/
/*
U8G2_SSD1306_128X64_NONAME_F_SW_I2C  
u8g2 (U8G2_R0, 14,12, U8X8_PIN_NONE) ;
void setup(void) {
  u8g2.begin();

}

void loop(void) {
  /*
  u8g2.clearBuffer();					// clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr);	// choose a suitable font
  u8g2.drawStr(0,10,"Hello World!");	// write something to the internal memory
  u8g2.sendBuffer();					// transfer internal memory to the display
  delay(1000);  


}
*/