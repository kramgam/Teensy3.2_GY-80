void HMC5883()
{
  int16_t x, y, z; //triple axis data

  //Tell the HMC5883 where to begin reading data
  Wire.beginTransmission(AddressCompass);
  Wire.write(0x03); //select register 3, X MSB register
  Wire.endTransmission();

  //Read data from each axis, 2 registers per axis
  Wire.requestFrom(AddressCompass, 6);
  if (6 <= Wire.available()) {
    x = Wire.read() << 8; //X msb
    x |= Wire.read(); //X lsb
    z = Wire.read() << 8; //Z msb
    z |= Wire.read(); //Z lsb
    y = Wire.read() << 8; //Y msb
    y |= Wire.read(); //Y lsb
  }

  //Print out values of each axis
  Serial.print("{x,T,"); Serial.print(x); Serial.println("}");
  Serial.print("{y,T,"); Serial.print(y); Serial.println("}");
  Serial.print("{z,T,"); Serial.print(z); Serial.println("}");
}
