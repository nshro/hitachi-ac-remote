
#define maxLen 2000
#include <IRremote.h>

int RECEIVE_PIN = 25;
int khz = 38;

volatile  unsigned int irBuffer[maxLen];
volatile unsigned int x = 0;

void setup() {
  attachInterrupt(digitalPinToInterrupt(RECEIVE_PIN), rxIR_Interrupt_Handler, CHANGE);
}

void rxIR_Interrupt_Handler() {
  if (x > maxLen) return;
  irBuffer[x++] = micros();
}

void loop() {
  Serial.println(F("Press the button on the remote now - once only"));
  delay(5000);
  if (x) {
    Serial.println();
    Serial.print(F("Raw: ("));
    Serial.print((x - 1));
    Serial.print(F(") "));
    detachInterrupt(0);
    for (int i = 1; i < x; i++) {
      // if (!(i & 0x1)) Serial.print(F("-"));
      Serial.print(irBuffer[i] - irBuffer[i - 1]);
      Serial.print(F(", "));
    }
    x = 0;
    Serial.println();
    Serial.println();
    attachInterrupt(0, rxIR_Interrupt_Handler, CHANGE);
  }
}
