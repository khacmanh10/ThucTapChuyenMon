#define BLYNK_TEMPLATE_ID "TMPL6_lmICFl7"
#define BLYNK_TEMPLATE_NAME "CAM BIEN KHI GAS"
#define BLYNK_AUTH_TOKEN "ZOm1e1WHcdij14ri685bqAhi7Ai2yBfa"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#define USE_NODE_MCU_BOARD
#include "BlynkEdgent.h"

int buzzer=5; // Socket D1
int button=0; //Socket D3
int mq5_value;
int mucCanhbao=500;
int timerID1,timerID2;
boolean buttonState=HIGH;
boolean btnStatus=1;
BlynkTimer timer;
boolean canhbaoState=0;
WidgetLED led(V0);

void setup()
{
  Serial.begin(115200);
  delay(100);
  pinMode(button,INPUT_PULLUP);
  pinMode(buzzer,OUTPUT);
  digitalWrite(buzzer,LOW);
  BlynkEdgent.begin();
  timerID1 = timer.setInterval(1000L,handleTimerID1);
}

void loop() {
  BlynkEdgent.run();
  timer.run();
  if(digitalRead(button)==LOW){
    if(buttonState==HIGH){
      buttonState=LOW;
      btnStatus=!btnStatus;
      Serial.println("Trạng thái: " + String(btnStatus));
      Blynk.virtualWrite(V4,btnStatus);
      delay(200);
    }
  }else{
    buttonState=HIGH;
  }
}

void handleTimerID1(){
  mq5_value = analogRead(A0);
  Blynk.virtualWrite(V1,mq5_value);
  if(led.getValue()) {
    led.off();
  } else {
    led.on();
  }
  if(btnStatus==1){
    if(mq5_value>mucCanhbao){
      if(canhbaoState==0){
        canhbaoState=1;
        Blynk.logEvent("warning", String("Cảnh báo!!! Khí gas trong không khí là " + String(mq5_value)+" vượt quá mức cho phép!"));
        timerID2 = timer.setTimeout(60000L,handleTimerID2);
      }
      digitalWrite(buzzer,HIGH);
      Blynk.virtualWrite(V3,HIGH);
      Serial.println("Cảnh báo đã được bật!");
    }else{
      digitalWrite(buzzer,LOW);
      Blynk.virtualWrite(V3,LOW);
      Serial.println("Cảnh báo đã được tắt!");
    }
  }else{
    digitalWrite(buzzer,LOW);
    Blynk.virtualWrite(V3,LOW);
    Serial.println("Cảnh báo đã được tắt!");
  }
}

void handleTimerID2(){
  canhbaoState=0;
}

BLYNK_CONNECTED() {
  Blynk.syncVirtual(V2,V4);
}

BLYNK_WRITE(V2) {
  mucCanhbao = param.asInt();
}

BLYNK_WRITE(V4) {
  btnStatus = param.asInt();
}
