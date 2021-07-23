#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <FirebaseESP8266.h>

// Variables for main.cpp //
unsigned long sendDataPrevMillis = 0;
#define irPin D0
#define ldrPin A0
int occupied;
#define Fan D6
int val1;
#define light D7
int val2;
#define TV D8
int val3;

#define Firebase_host "endpoint"
#define Firebase_auth "auth_ID"

#define wifi_ssid ""
#define wifi_pass ""
// #define wifi_pass "Sy#Crbtx@900890"