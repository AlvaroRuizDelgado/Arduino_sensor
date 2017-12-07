#include <Time.h>
#include <TimeLib.h>

time_t t;

void setup()
{
  Serial.begin(9600); //set baud rate
  
//   setTime(hour, minute, second, day, month, year);
  setTime(19,18,0,7,12,2017);
  t = now();
}

void loop()
{
  t = now();
  showTime(&t);
  delay(1400); //delay
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