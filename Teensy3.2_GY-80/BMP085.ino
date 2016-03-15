void BMP085()
{
  Serial.print("{Temperature(*C),T,"); Serial.print(bmp.readTemperature()); Serial.println("}"); Serial.flush();
  //Serial.print("{Pressure(Pa),T,"); Serial.print(bmp.readPressure()); Serial.println("}"); Serial.flush();
  Serial.print("{Altitude(meters),T,"); Serial.print(bmp.readAltitude()); Serial.println("}"); Serial.flush();
  //Serial.print("{Pressure at sealevel(calculated)(Pa),T,"); Serial.print(bmp.readSealevelPressure()); Serial.println("}"); Serial.flush();
  Serial.print("{Real altitude(meters),T,"); Serial.print(bmp.readAltitude(101500)); Serial.println("}"); Serial.flush();
}
