int ledPin = 13;  //LED is 13 pin
int switchPin = 4;                       // Switch connected to pin 4

void setup( ) {
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600); //シ リ  ア ル  通 信 の  転 送  速 度  を 9600bps に 指 定
  
  pinMode(switchPin, INPUT);             // Set pin 0 as an input
  Serial.begin(9600);                    // Start serial communication at 9600 bps

}

void loop( ) {
  if(Serial.available( )  >0) //シ リ ア  ル ポ ー ト  か ら デ  ー タ を 受 け 取 る と 1 以 上の 値  が 返 さ  れ 、  真 と  な る
  {  
    switch (Serial.read( ) ) //switch 文  デ ー  タ を 読  み 込  む
    {
    case 'a': //デ ー  タ が'a'で  あ れ  ば 次 を  実 行  す る
      digitalWrite(ledPin,HIGH);
      break;
    case 'b': //デ ー  タ が'b'で  あ れ ば  次 を  実 行  す る
      digitalWrite(ledPin,LOW);
      break;
    default: //そ の  他 で  あ れ ば  次 を  実 行  す る
      break;
      break;
    }
  }
  
  if (digitalRead(switchPin) == HIGH) {  // If switch is ON,
    Serial.println(1);               // send 1 to Processing
  } else {                               // If the switch is not ON,
    Serial.println(0);               // send 0 to Processing
  }
  delay(100); 
}


