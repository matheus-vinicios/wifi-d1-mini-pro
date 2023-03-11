#include <ESP8266WiFi.h>

#define WIFI_SSID "xxxx"
#define WIFI_PASS "xxxx"

void setup()
{
  Serial.begin(115200);
  Serial.println();

  //
  // CONFIGURAÇÃO DE WIFI
  //
  WiFi.hostname("RobotDyn-WiFi-D1-Mini");
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  //
  // CONFIGURAÇÃO DE LED
  //
  pinMode(BUILTIN_LED, OUTPUT);

  //
  // INICIAR
  //
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(200);

    if (digitalRead(BUILTIN_LED) == LOW)
      digitalWrite(BUILTIN_LED, HIGH);
    else
      digitalWrite(BUILTIN_LED, LOW);
  }

  digitalWrite(BUILTIN_LED, LOW);
  Serial.println("===== ROBOT DYN - WIFI D1 MINI =====");
  Serial.print("SSID       : ");
  Serial.println(WIFI_SSID);
  Serial.print("HOSTNAME   : ");
  Serial.println(WiFi.hostname());
  Serial.print("IP ADDRESS : ");
  Serial.println(WiFi.localIP());
  Serial.println("====================================");
}

void loop()
{

}