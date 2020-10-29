/*
 
 * High-Pass Filter
 * Designed by AKBN(Anand),2020.

 */


const float alpha = 0.5;
double data_filtered[] = {0, 0};
double data[] = {0, 0};
const int n = 1;
const int analog_pin = 0;

void setup(){
    Serial.begin(9600);
}

void loop(){
    // Retrieve Data
    data[0] = analogRead(analog_pin);

    // High Pass Filter
    data_filtered[n] = alpha * (data_filtered[n-1] + data[n] - data[n-1]);

    // Store the previous data in correct index
    data[n-1] = data[n];
    data_filtered[n-1] = data_filtered[n];

    // Print Data
    Serial.println(data_filtered[0]);
    delay(100);
}
