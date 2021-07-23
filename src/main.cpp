#include "creds.h"

const char *ssid = wifi_ssid;
const char *pass = wifi_pass;
const char *fb_host = Firebase_host;
const char *fb_auth = Firebase_auth;

int prevInput = 0;

FirebaseData fbdo1;
FirebaseData fbdo2;
FirebaseData fbdo3;
FirebaseData fbdo_occupied;

void firebasereconnect()
{
  Serial.println("Trying to reconnect");
  Firebase.begin(fb_host, fb_auth);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  //Setup Pinmodes
  pinMode(irPin, INPUT);
  pinMode(ldrPin, INPUT);

  pinMode(Fan, OUTPUT);
  pinMode(light, OUTPUT);
  pinMode(TV, OUTPUT);

  //Setup WiFi
  WiFi.begin(ssid,pass);
  Serial.print("Connecting to SSID: ");Serial.println(ssid);
  while (WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected:");
  Serial.println(WiFi.localIP());
  delay(100);

  //Setup Firebase interface
  Firebase.begin(fb_host,fb_auth);
  Firebase.reconnectWiFi(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))         // 15sec delay
  {
    sendDataPrevMillis = millis();

    int ldr = analogRead(ldrPin);
    Serial.print("LDR: ");Serial.println(ldr);
        
    Firebase.getString(fbdo1,"S1");
    val1 = fbdo1.stringData().toInt();                                         //Reading the value of the varialble Status from the firebase
    
    if(val1==1)                                                             // If, the Status is 1, turn on the Fan
    {
      digitalWrite(Fan,HIGH);
      Serial.println("Fan ON");
    }
    else if(val1==0)                                                      // If, the Status is 0, turn Off the Fan
    {                                      
      digitalWrite(Fan,LOW);
      Serial.println("Fan OFF");
    }

    Firebase.getString(fbdo2, "S2");
    val2=fbdo2.stringData().toInt();                                        //Reading the value of the varialble Status from the firebase
    
    if(val2==1)                                                             // If, the Status is 1, turn on the Light
    {
      digitalWrite(TV,HIGH);
      Serial.println("TV  ON");
    }
    else if(val2==0)                                                      // If, the Status is 0, turn Off the Light
    {                                      
      digitalWrite(TV,LOW);
      Serial.println("TV  OFF");
    }

    Firebase.getString(fbdo3, "S3");
    val3 = fbdo3.stringData().toInt();
    
    if(ldr <= 300 && val3==0)                                                      
    {                                      
      digitalWrite(light,LOW);
      Serial.println("Lights OFF");
    }
    if( ldr <=300 && val3 == 1)                                                             
    {
      digitalWrite(light,HIGH);
      Serial.println("Lights ON");
    }
    else if(ldr > 300 || val3==0)                                                      
    {                                      
      digitalWrite(light,LOW);
      Serial.println("Lights OFF");
    }
  }
}