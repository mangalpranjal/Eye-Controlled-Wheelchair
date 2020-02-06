// change your ssid and password accordingly

#include <ESP8266WiFi.h>

#include <ESP8266HTTPClient.h>
const int analog_ip = A0;
int inputVal  = 0;
int analog1=5;
int m1_in1=14;
int m1_in2=12;
int analog2=4;
int m2_in1=13;
int m2_in2=15;
String me;
String  httpurl;
String  TheHiddenAnswerOfClient;
HTTPClient http;

String gettheAnswer(String IPcache, String monmessagecache) {
httpurl = "http://";
httpurl+=IPcache;
httpurl+="/";
httpurl+=monmessagecache;
http.begin(httpurl);
http.GET();
TheHiddenAnswerOfClient = (http.getString());
http.end();
return TheHiddenAnswerOfClient;
}

void setup()
{
  pinMode(analog1,OUTPUT);
  pinMode(m1_in1,OUTPUT);
  pinMode(m1_in2,OUTPUT);
  pinMode(analog2,OUTPUT);
  pinMode(m2_in1,OUTPUT);
  pinMode(m2_in2,OUTPUT);
 
  Serial.begin(9600);
  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
   WiFi.begin("Hotspot Name","password");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("..");

  }
  Serial.println("Connected");
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP().toString()));
  
  
//16,5,4,0,2
}


void loop()
{
 me=gettheAnswer("ServerIP:Port","Cache");
 inputVal = analogRead(analog_ip);
 if(me[0]=='0')
 {
  Serial.println("None");
  analogWrite(analog1,inputVal);
  digitalWrite(m1_in1,LOW);
  digitalWrite(m1_in2,LOW);
  analogWrite(analog2,inputVal);
  digitalWrite(m2_in1,LOW);
  digitalWrite(m2_in2,LOW);
  delay(1000);
 }
 else if(me[0]=='1')
 {
  Serial.println("Right");  
  analogWrite(analog1,inputVal);
  digitalWrite(m1_in1,LOW);
  digitalWrite(m1_in2,HIGH);
  analogWrite(analog2,inputVal);
  digitalWrite(m2_in1,HIGH);
  digitalWrite(m2_in2,LOW);
  delay(1000);
 }
 
 else if(me[0]=='2')
 {
  Serial.println("Center");
  analogWrite(analog1,inputVal);  
  digitalWrite(m1_in1,HIGH);
  digitalWrite(m1_in2,LOW);
  analogWrite(analog2,inputVal);
  digitalWrite(m2_in1,HIGH);
  digitalWrite(m2_in2,LOW);
  delay(1000);
 }
 else if(me[0]=='3')
 {
  Serial.println("Left");
  analogWrite(analog1,inputVal);  
  digitalWrite(m1_in1,HIGH);
  digitalWrite(m1_in2,LOW);
  analogWrite(analog2,inputVal);
  digitalWrite(m2_in1,LOW);
  digitalWrite(m2_in2,HIGH);
  delay(1000);
 }
  else
 {
  Serial.println("Stopped");
  analogWrite(analog1,inputVal);
  digitalWrite(m1_in1,LOW);
  digitalWrite(m1_in2,LOW);
  analogWrite(analog2,inputVal);
  digitalWrite(m2_in1,LOW);
  digitalWrite(m2_in2,LOW);
  delay(1000);
 }
}
