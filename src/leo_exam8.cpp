#define BLYNK_TEMPLATE_ID "TMPL6N_-7GvRl"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "aGtgFfLCvRY8b_q-iK703e6v3B4nYVv-"
#include <Arduino.h>
#include <Ultrasonic.h>
#include <TridentTD_LineNotify.h>
#include <WiFi.h>

#include <BlynkSimpleEsp32.h>
#include <WiFiClient.h>

#define led 18
#define SSID "DX100"
#define PASSWORD "11111111"
#define LINE_TOKEN "ZQpn1iMnORrrnZS5EdSKTboA8S5MFnafFrj904EzCqR"


Ultrasonic ultrasonic(16, 17);
void dx100_work8_setup()
{
    pinMode(led, OUTPUT);
    Serial.begin(115200);
    Blynk.begin(BLYNK_AUTH_TOKEN, SSID, PASSWORD);
    WiFi.begin(SSID, PASSWORD);
    Serial.print("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
    LINE.setToken(LINE_TOKEN);
    // LINE.notify("Hello from ESP32 on Wokwi!");
    // LINE.notifyPicture("สวัสดีวันอังคาร","https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEjT21_Z_eLPyjFuRQDzJiN9hGFsRHeatpgeDj47T93t93MV3BvROSx6c4Tku-dWEKFaVadWRSWHl9MPEo3ErxqoTv9fT4jHt8v8CZ4aXVfCL86oBroodOgN3xciMB8ffO_y7T-Ob2TUj-AxcWsDPcnmxnRFNUiKZqgOO5H3Gcp3A5W3taHgoBFoL63cUg/s2093/1684132556354.jpg");
    // LINE.notifyPicture("uto
    // kawaii","https://cdn.discordapp.com/attachments/1138409352777175150/1188863197151776828/GBOOGKHawAALsGz.jfif?ex=659c1222&is=65899d22&hm=4fff9989b9c2c766ddf79ba549247abfa939ae32417bf16259d9f0b76512031c&");
}
void measureAndNotifyDistance()
{
    Serial.println("Hello");
    int distance = ultrasonic.read();
    if (distance <= 5)
    {
        LINE.notify("Some one entered the house");
        digitalWrite(led, HIGH);
        Blynk.virtualWrite(V3, distance);
        String message = String("");
        message += ">>> ";
        message += distance;
        message += " cm";
        LINE.notify(message);
    }
    else
    {
        digitalWrite(led, LOW);
        //
    }
}
void dx100_work8_loop()
{
    measureAndNotifyDistance();
    delay(100);
    Blynk.run();
}
