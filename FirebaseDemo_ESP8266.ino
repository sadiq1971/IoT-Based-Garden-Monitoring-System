#include <Servo.h>

//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseDemo_ESP8266 is a sample that demo the different functions
// of the FirebaseArduino API.

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "iotbased404.firebaseio.com"
#define FIREBASE_AUTH "9LJpfmSTPBQMuy0MEMnQOGEwnxb5QJ6wL3w2Jzzh"
#define WIFI_SSID "Aula231"
#define WIFI_PASSWORD "pranta231"




void setup() {
  Serial.begin(9600);

  // connect to wifi.
   Serial.print("tring to connecting....");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
// WiFi.begin(WIFI_SSID);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

float n = 20.0;

void loop() {

    Firebase.setFloat("temp", n);
    if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
    Firebase.setFloat("mois", 54.0);
    if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
    Firebase.setString("lastUpdated", "29-4-2018");
    if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
   

    Firebase.getFloat("temp");
    Firebase.getFloat("mois");
    Firebase.getString("lastUpdated");

    Serial.println(Firebase.getString("lastUpdated"));
    
    
  n++;
  delay(5000);
}
