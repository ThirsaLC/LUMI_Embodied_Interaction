//Script for ball 1 - Blue arduino with pins on the bottom
#define BLYNK_TEMPLATE_ID "TMPL4m3VXFfeR"
#define BLYNK_TEMPLATE_NAME "EI MKR1000"
#define BLYNK_AUTH_TOKEN "ckV7pD0m0KB66zkq1Rsg4wJq-bUrC4XT"  //EI ARDUINO

#include <BlynkSimpleMKR1000.h>
#include <SPI.h>
#include <WiFi101.h>
#include <Adafruit_NeoPixel.h>

#include "arduino_secrets.h"

char ssid[] = SECRET_SSID;    //network
char pass[] = SECRET_PASS;    //password
int status = WL_IDLE_STATUS;  //WiFi radio status

#define LED_PIN 4
#define LED_PIN2 5
#define LED_COUNT 16
Adafruit_NeoPixel ring(LED_COUNT, LED_PIN, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel ring2(LED_COUNT, LED_PIN2, NEO_RGBW + NEO_KHZ800);
#include "colour_LEDs.h"

void setup() {
  connect();
  //Blynk app connection
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  //neopixels setup
  ring.begin();
  ring2.begin();
  ring.setBrightness(50);
  ring2.setBrightness(50);
  ring.show();
  ring2.show();
  Serial.println("LEDs are here");
}

void loop() {
  // check the network connection once every  10 seconds:
  printData();
  Serial.println("-------------------------------");

  // run blynk app
  Blynk.run();
  delay(1000);
}

BLYNK_WRITE(V0) {
  int value = param.asInt();
  if (value == 1) {
    Serial.println("Button V0 on");
    Anger(255);
  } else {
    Serial.println("Button V0 off");
  }
}
BLYNK_WRITE(V1) {
  Serial.println("Button V1 on");
  Sad();
}
BLYNK_WRITE(V2) {
  Serial.println("Button V2 on");
  Happy();
}

BLYNK_WRITE(V4) {
  int valueS = param.asInt();
  Anger(valueS);
}

BLYNK_WRITE(V8) {
  int r = param[0].asInt();
  int g = param[1].asInt();
  int b = param[2].asInt();
  MixColours(r, g, b);
}

BLYNK_WRITE(V9) {
  int r2 = param[0].asInt();
  int g2 = param[1].asInt();
  int b2 = param[2].asInt();
  HalfColour(r2, g2, b2);
}

void printData() {
  Serial.println("Board Information:");
  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  Serial.println();
  Serial.println("Network Information:");
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.println(rssi);
}

void connect() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial)
    ;

  //attempt to connect
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to network: ");
    Serial.println(ssid);
    //connect to WPA/WPA2 network;
    status = WiFi.begin(ssid, pass);

    //wait 10s for connection;
    delay(10000);
  }

  //connected now, print the data:
  Serial.println("You are connected to the network");
  Serial.println("--------------------------------");
  printData();
  Serial.println("--------------------------------");
}
