// String message; //string that stores the incoming message

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); //set baud rate

  // Serial.print("AT+NAMESensorDeDilatacion"); // set bluetooth name
  // delay(600);
  // char responseMessage[10];  // 'OKsetname\n'
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
  String message;

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
        Serial.println("Lights off");
      // } else if (message=="49\r\n") {
      } else if (message[0]=='4' && message[1]=='9') {
        digitalWrite(LED_BUILTIN, HIGH);
        Serial.println("Lights on");
      }
      Serial.println(message); //show the data
      message=""; //clear the data
    }
  }
  delay(5*1000); //delay
}