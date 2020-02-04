/*
  2018.05.12 Written by @Toramin10
*/

#include <DigiKeyboard.h>  //Digisparkをkeyboardにするためのライブラリ
const int LED = 0;
const int SW1 = 1;
const int BUZZER = 2;
int freq[15] = {523, 587, 659, 698, 784, 880, 987, 1047, 1175, 1319, 1397, 1568, 1760, 1976, 2093};
bool state = false;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(SW1, INPUT);
}

void loop() {

  analogWrite(LED, 5);
  DigiKeyboard.delay(100);
  digitalWrite(LED, LOW);

  for (int i = 0; i <=  2500; i++) {

    if (digitalRead(SW1) == HIGH) {
      delay(10);
      if (!state) {
        digitalWrite(LED, HIGH);
        for (int k = 1; k <= 2; k++){
          tone(BUZZER, freq[7], 150);
          DigiKeyboard.delay(200);
        }
        DigiKeyboard.update();
        DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);　//Win + Rを出力
        DigiKeyboard.delay(150);
        DigiKeyboard.print("https\'//drive.google.com/drive/my-drive\n");  //GoogleDriveにアクセスさせる
        DigiKeyboard.delay(4000);
        for (int j = 1; j <= 5; j++) {
          digitalWrite(LED, LOW);
          DigiKeyboard.delay(80);
          digitalWrite(LED, HIGH);
          DigiKeyboard.delay(80);
        }
        for (int j = 200; j >= 0; j = j - 2) {
          analogWrite(LED, j);
          DigiKeyboard.delay(10);
        }
        state = true;
      }
    }
    else {
      state = false;
    }
    DigiKeyboard.delay(1);
  }

}
