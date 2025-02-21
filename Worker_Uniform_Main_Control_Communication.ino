//A Prototype and Reference code - Part of Research Work

#include <DHT.h>
#include <DHT_U.h>

#define MQ_135 A0   //Ammonia_and_CO2_Sensor Input PIN
#define MQ_2 A1     //Methane_and_Smoke_Sensor Input PIN
#define MQ_7 A2     //CarbonMonoxide_Sensor Input PIN
#define Alert 2     //Alert Alarm On Uniform of Worker

#define DHTPIN A3   //Temperature_And_Humidity_Sensor Input PIN
#define DHTTYPE DHT22

//Initialization of DTH22 Sensor with Type and PIN Information
DHT DHT_Sensor(DHTPIN, DHTTYPE);    

//Declaration and Initialization of Parameters.
float Ammonia_and_CO2_Values=0.0 ;
float Methane_and_Smoke_Values=0.0 ;
float CarbonMonoxide_Values=0.0 ;
float Humidity_Values=0.0;
float Temperature_Values=0.0;
float Result[5];


void setup() {
  Serial.begin(115200);
  DHT_Sensor.begin();
  pinMode(MQ_135, INPUT); //Ammonia_and_CO2_Values
  pinMode(MQ_2, INPUT);   //Methane_and_Smoke_Values
  pinMode(MQ_7, INPUT);   //CarbonMonoxide_Values
}

void loop() {
  //Reading Input and Storing to Parameters.
  Ammonia_and_CO2_Values=analogRead(MQ_135);
  Methane_and_Smoke_Values=analogRead(MQ_2);
  CarbonMonoxide_Values=analogRead(MQ_7);
  Temperature_Values=DHT_Sensor.readTemperature();
  Humidity_Values=DHT_Sensor.readHumidity();

  Result[0]=Ammonia_and_CO2_Values;
  Result[1]=Methane_and_Smoke_Values;
  Result[2]=CarbonMonoxide_Values;
  Result[3]=Temperature_Values;
  Result[4]=Humidity_Values;

  Serial.println(String(Result[0])+" "+String(Result[1])+" "+String(Result[2])+" "+String(Result[3])+" "+String(Result[4]));
  delay(1500);

}
