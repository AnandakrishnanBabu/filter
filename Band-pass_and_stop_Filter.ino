/*
 
 * Band-pass and stop Filter
 * Designed by AKBN(Anand),2020.

 */

int sensorPin = 0;          
int sensorValue = 0;       
 
float low_freq_slg = 0.05;     
float High_freq_slg = 0.4;
 
int low_freq_slg_1 = 0;          
int High_freq_slg_1 = 0;
 
int highpass = 0;
int bandpass = 0;
int bandstop = 0;
 
void setup(){
  Serial.begin(115200);                     
   
  low_freq_slg_1 = analogRead(sensorPin);        
  High_freq_slg_1 = analogRead(sensorPin);
}
 
void loop(){
  sensorValue = analogRead(sensorPin);      
   
  low_freq_slg_1 = (low_freq_slg*sensorValue) + ((1-low_freq_slg)*low_freq_slg_1);          
  High_freq_slg_1 = (High_freq_slg*sensorValue) + ((1-High_freq_slg)*High_freq_slg_1);
   
  bandpass = High_freq_slg_1 - low_freq_slg_1;        //find the band-pass sgl
  bandstop = sensorValue - bandpass;        //find the band-stop sgl
 
  Serial.print(bandpass);
  Serial.print(" ");
  Serial.print(low_freq_slg_1);
  Serial.print(" ");
  Serial.println(bandstop);
   
  delay(100);                               
}
