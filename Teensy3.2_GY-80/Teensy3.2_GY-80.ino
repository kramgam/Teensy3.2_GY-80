#include <Wire.h>




//baroData //BMP085
#include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp;


//accelData //ADXL345
#define Register_ID 0
#define Register_2D 0x2D
#define Register_X0 0x32
#define Register_X1 0x33
#define Register_Y0 0x34
#define Register_Y1 0x35
#define Register_Z0 0x36
#define Register_Z1 0x37
int ADXAddress = 0xA7 >> 1;  // the default 7-bit slave address
int reading = 0;
int val = 0;
int16_t X0, X1, X_out;
int16_t Y0, Y1, Y_out;
int16_t Z1, Z0, Z_out;
double xA, yA, zA;


//compassData //HMC5883
#define AddressCompass 0x1E //0011110b, I2C 7bit address of HMC5883


//gyroData //L3G4200D
#define CTRL_REG1 0x20
#define CTRL_REG2 0x21
#define CTRL_REG3 0x22
#define CTRL_REG4 0x23
#define CTRL_REG5 0x24
int L3G4200D_Address = 105; //I2C address of the L3G4200D
int16_t xG;
int16_t yG;
int16_t zG;




void setup()
{
  runSetup();
}




void loop()
{
  runMotion();
}
