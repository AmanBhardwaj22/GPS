// #include <TinyGPS.h>
// #include <SoftwareSerial.h> 

// float lat,lon; // create variable for latitude and longitude object 
// SoftwareSerial gpsSerial(3,4);//rx,tx
// TinyGPS gps; // create gps object

// void setup(){
//     Serial.begin(9600); // connect serial
//     gpsSerial.begin(9600); // connect gps sensor
//     Serial.println("setup complete");
// }

// void loop(){
//     while(gpsSerial.available()){ // check for gps data
//         Serial.print((char) gpsSerial.read());
//     }

//     Serial.println("gpsSerial is not available");
//     String latitude = String(lat,6);
//     String longitude = String(lon,6);
//     Serial.println(latitude+";"+longitude);
//     delay(1000);
// }

#include <SoftwareSerial.h>
#include <TinyGPS++.h>
int Rx_pin = 3;
int Tx_pin = 4;
SoftwareSerial SerialGPS(Rx_pin, Tx_pin);
TinyGPSPlus gps;
void setup()
{
  Serial.begin(9600);
  SerialGPS.begin(9600);
}

void loop()
{
  while (SerialGPS.available() > 0){
 // Serial.write(SerialGPS.read()); // to project raw data from gps to serial monitor
  if (gps.encode(SerialGPS.read())){
     if (gps.location.isValid()) {
        // Get latitude and longitude
        float latitude = gps.location.lat();
        float longitude = gps.location.lng();

        // Print latitude and longitude
        Serial.print("Latitude: ");
        Serial.println(latitude, 6);
        Serial.print("Longitude: ");
        Serial.println(longitude, 6);
      } else {
        Serial.println("Searching for satelite . . .");
      }
  }
  }
}