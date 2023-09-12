#include <math.h>
#include <Servo.h>

#define relay_in 4
#define button 13
#define servo 9
#define Beam 12

Servo trigger;

const int fire = 40;
const int hook = 13;
const int d = 2;
void pull(float l){
    bool beam = 0;
    bool beam2 = 0;
    float lNow = 0;
    while(lNow <= l){
        beam = digitalRead(Beam);
        if(beam != beam2){
            lNow += d * M_PI / 20 / 2;
        }
        beam2 = beam;
    }
    digitalWrite(relay_in, LOW);
    delay(3000);
    trigger.write(fire);
    delay(1000);
    trigger.write(hook);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); 

  trigger.attach(servo);
  trigger.write(hook);

  pinMode(button, INPUT_PULLUP);
  pinMode(relay_in, OUTPUT);
  pinMode(Beam, INPUT_PULLUP);

  digitalWrite(relay_in, LOW);
}

void loop() {
    if(digitalRead(button) == LOW){
        pull(2);
    }
}