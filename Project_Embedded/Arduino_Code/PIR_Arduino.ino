#include<SPI.h>
volatile boolean rx_data;
volatile uint16_t Slave_rx;
void setup()
{
  Serial.begin(9600);
  pinMode(MISO,OUTPUT);                  
  pinMode(10,INPUT);
  digitalWrite(10,LOW);
  SPCR |= _BV(SPE);                      
  rx_data = false;
  SPI.attachInterrupt();
  Serial.print("Starting...........");
  delay(2000);
  Serial.print("READY");  
}

ISR(SPI_STC_vect)
{
  Slave_rx = SPDR;
  rx_data = true;
}
void loop()
{
  if (rx_data)
  {
    if (Slave_rx!=0)
    {
      rx_data=false;
      Serial.println("Motion Detected");
      delay(200);
    }
    if (Slave_rx == 0)
    {   
            rx_data=false;
            Serial.println("No Motion");
            delay(200);

    }
  }
}
