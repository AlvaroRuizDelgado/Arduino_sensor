#include <Time.h>
#include <TimeLib.h>

time_t t;
time_t t_change;
time_t t_delta;

String message; //string that stores the incoming message

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); //set baud rate

  //   setTime(hour, minute, second, day, month, year);
  setTime(19,48,0,7,12,2017);
  t = now();
  t_change = now();
  t_delta = t - t_change;

  Serial.println("AT+NAMESensorDeDilatacion"); // set bluetooth name
  delay(600);
  // int8_t lengthOfResponse = 10;  // 'OKsetname\n'
  // char responseMessage[lengthOfResponse];
  // int8_t responseCount = 0;
  // while(1) { // Read until 'OKsetname' is read and cleared from buffer.
  //   if(Serial.available()) {
  //     responseMessage[responseCount] += Serial.read();
  //     responseCount++;
  //     if(responseCount == 9) break;
  //   }
  //   delay(10);
  // }
  // Serial.println(responseMessage);
}

void loop()
{
  t = now();
  while(Serial.available())
  {//while there is data available on the serial monitor
    message+=char(Serial.read());//store string from serial command
  }
  if(!Serial.available())
  {
    if(message!="")
    {//if data is available
      // if(message=="48\r\n") {
      if(message[0]=='4' && message[1]=='8') {
        digitalWrite(LED_BUILTIN, LOW);
        showTime(&t);
        Serial.println("Lights off");
        Serial.print("They were ON for ");
        Serial.print(t - t_change);
        Serial.println(" seconds.");
        t_change = now();
      // } else if (message=="49\r\n") {
      } else if (message[0]=='4' && message[1]=='9') {
        digitalWrite(LED_BUILTIN, HIGH);
        showTime(&t);
        Serial.println("Lights on");
        Serial.print("They were OFF for ");
        Serial.print(t - t_change);
        Serial.println(" seconds.");
        t_change = now();
      }
      Serial.println(message); //show the data
      message=""; //clear the data
    }
  }
  delay(5*1000); //delay
}

void showTime(time_t *t) {
  Serial.print(year(*t));
  Serial.print('/');
  Serial.print(month(*t));
  Serial.print('/');
  Serial.print(day(*t));
  Serial.print("  ");
  Serial.print(hour(*t));
  Serial.print(':');
  Serial.print(minute(*t));
  Serial.print(':');
  Serial.print(second(*t));
  Serial.print('\n');
}