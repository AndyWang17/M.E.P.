
#include "SR04.h"
#include <assert.h>

#define TRIG_PIN1 3
#define ECHO_PIN1 4
#define TRIG_PIN2 5
#define ECHO_PIN2 6

SR04 sr04_1 = SR04(ECHO_PIN1, TRIG_PIN1);
SR04 sr04_2 = SR04(ECHO_PIN2,TRIG_PIN2);

long a;
long b;
long c;
long d;

void setup() {
    Serial.begin(9600);
    delay(500);
}

void loop() {
  do {
    a = sr04_1.Distance();
    b = sr04_2.Distance();
   } while (a == 0 || b == 0);
    if (a > 40) a = 40;
    if (b > 40) b = 40;
    Serial.print(a);
    Serial.println(b);
    delay(50);
    do {
      c = sr04_1.Distance();
      d = sr04_2.Distance();
    } while (c == 0 || d == 0);
   
    if (c < a - 5) {
        for (int i = 0; i < 20; i++) {
            delay(50);
            d = sr04_2.Distance();
            if (d < b - 5){
              Serial.println("FROM Left to Right");
              delay(1000);
              return;
            }
        }
    }

    if (d < b -5) {
        for (int i = 0; i < 20; i++) {
            delay(50);
            c = sr04_1.Distance();
            if (c < a -5) {
              Serial.println("FROM Right to Left");
              delay(1000);
              return;
            }
        }
    }
    
     
}
