/*
 
 * Band-pass and stop Filter
 * Designed by AKBN(Anand),2020.

 */

int sensorPin = 0;          
int sensorValue = 0;       
 
float EMA_a_low = 0.05;     
float EMA_a_high = 0.4;
 
int EMA_S_low = 0;          
int EMA_S_high = 0;
 
int highpass = 0;
int bandpass = 0;
int bandstop = 0;
 
void setup(){
  Serial.begin(115200);                     
   
  EMA_S_low = analogRead(sensorPin);        
  EMA_S_high = analogRead(sensorPin);
}
 
void loop(){
  sensorValue = analogRead(sensorPin);      
   
  EMA_S_low = (EMA_a_low*sensorValue) + ((1-EMA_a_low)*EMA_S_low);          
  EMA_S_high = (EMA_a_high*sensorValue) + ((1-EMA_a_high)*EMA_S_high);
   
  bandpass = EMA_S_high - EMA_S_low;        //find the band-pass signal
 
  bandstop = sensorValue - bandpass;        //find the band-stop signal
 
  Serial.print(bandpass);
  Serial.print(" ");
  Serial.print(EMA_S_low);
  Serial.print(" ");
  Serial.println(bandstop);
   
  delay(100);                               
}
