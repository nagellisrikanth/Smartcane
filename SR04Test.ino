const int TrigPin = 2; 
const int EchoPin = 3; 
float cm; 
void setup() 
{ 
Serial.begin(9600); 
pinMode(TrigPin, OUTPUT); 
pinMode(EchoPin, INPUT); 
pinMode(13, OUTPUT);
} 
void loop() 
{ 
//发一个10ms的高脉冲去触发TrigPin 
digitalWrite(TrigPin, LOW); 
delayMicroseconds(2); 
digitalWrite(TrigPin, HIGH); 
delayMicroseconds(10); 
digitalWrite(TrigPin, LOW); 
 
cm = pulseIn(EchoPin, HIGH) / 58.0; //算成厘米 
cm = (int(cm * 100.0)) / 100.0; //保留两位小数 
if(cm<30)
{
  digitalWrite(13, HIGH);   // 
  delay(30);              // 
  digitalWrite(13, LOW);    // 
  delay(5);    
}
else if(cm<60)
{  
  digitalWrite(13, HIGH);   // 
  delay(25);              // 
  digitalWrite(13, LOW);    // 
  delay(10);   
}
else if(cm<90)
{  
  digitalWrite(13, HIGH);   // 
  delay(20);              // 
  digitalWrite(13, LOW);    // 
  delay(15);   
}
else digitalWrite(13, LOW); 

Serial.print(cm); 
Serial.print("cm"); 
Serial.println(); 
delay(100); 
}


