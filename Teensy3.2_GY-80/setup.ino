void runSetup()
{
  Wire.begin();
  Serial.begin(9600);
  delay(1000);

  //baroData //BMP085
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP085 sensor, check wiring!");
    while (1) {
      //program stops here if bmp not found
    }
  }
  delay(50);

  //accelData
  Wire.beginTransmission(ADXAddress);
  Wire.write(Register_2D);
  Wire.write(8);                //measuring enable
  Wire.endTransmission();     // stop transmitting
  delay(50);

  //compassData //HMC5883
  Wire.beginTransmission(AddressCompass); //open communication with HMC5883
  Wire.write(0x02); //select mode register
  Wire.write(0x00); //continuous measurement mode
  Wire.endTransmission();
  delay(50);

  //gyroData  //L3G4200D
  setupL3G4200D(2000); // Configure L3G4200  - 250, 500 or 2000 deg/sec
  delay(50);
}
