void ADXL345()
{
  //--------------X
  Wire.beginTransmission(ADXAddress); // transmit to device
  Wire.write(Register_X0);
  Wire.write(Register_X1);
  Wire.endTransmission();
  Wire.requestFrom(ADXAddress, 2);
  if (Wire.available() <= 2)
  {
    X0 = Wire.read();
    X1 = Wire.read();
    X1 = X1 << 8;
    X_out = X0 + X1;
  }

  //------------------Y
  Wire.beginTransmission(ADXAddress); // transmit to device
  Wire.write(Register_Y0);
  Wire.write(Register_Y1);
  Wire.endTransmission();
  Wire.requestFrom(ADXAddress, 2);
  if (Wire.available() <= 2)
  {
    Y0 = Wire.read();
    Y1 = Wire.read();
    Y1 = Y1 << 8;
    Y_out = Y0 + Y1;
  }
  //------------------Z
  Wire.beginTransmission(ADXAddress); // transmit to device
  Wire.write(Register_Z0);
  Wire.write(Register_Z1);
  Wire.endTransmission();
  Wire.requestFrom(ADXAddress, 2);
  if (Wire.available() <= 2)
  {
    Z0 = Wire.read();
    Z1 = Wire.read();
    Z1 = Z1 << 8;
    Z_out = Z0 + Z1;
  }
  xA = X_out / 256.0;
  yA = Y_out / 256.0;
  zA = Z_out / 256.0;

  //multiply values by 1000 to make it easier to read in MegunoLink amongst other values
  xA *= 1000;
  yA *= 1000;
  zA *= 1000;

  Serial.print("{xA,T,"); Serial.print(xA); Serial.println("}"); Serial.flush();
  Serial.print("{yA,T,"); Serial.print(yA); Serial.println("}"); Serial.flush();
  Serial.print("{zA,T,"); Serial.print(zA); Serial.println("}"); Serial.flush();
}
