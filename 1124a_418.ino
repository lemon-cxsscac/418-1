// 可調式電阻調整 LED 明暗範例程式碼

// 接線說明：
// 可調式電阻：
// 中間腳接 Arduino 的 A0 (類比輸入)
// 其他兩腳分別接 Arduino 的 5V 和 GND
//
// LED 燈：
// 正極 (長腳) 接 Arduino 的數位腳位 9 (PWM 腳位，透過限流電阻)
// 負極 (短腳) 接 Arduino 的 GND

const int potPin = A0; // 可調式電阻接腳
const int ledPin = 9;  // LED 接腳 (PWM 腳位)

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600); // 用於監控輸入值
}

void loop() {
  int potValue = analogRead(potPin); // 讀取可調式電阻的類比值 (0 到 1023)
  int ledBrightness = map(potValue, 0, 1023, 0, 255); // 將值映射到 PWM 範圍 (0 到 255)

  analogWrite(ledPin, ledBrightness); // 調整 LED 的亮度


}
