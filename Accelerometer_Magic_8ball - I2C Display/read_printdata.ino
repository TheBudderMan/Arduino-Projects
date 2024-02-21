/*
 * Read and print data functions 
 */

void printData()
{
  // print out data

  //int aXConv = accelerometer_x / 64;
  //Serial.print("aX = "); Serial.print(convert_int16_to_str(accelerometer_x));
  //Serial.print(" | aY = "); Serial.print(convert_int16_to_str(accelerometer_y));
  //Serial.print(" | aZ = "); Serial.print(convert_int16_to_str(accelerometer_z));
  // the following equation was taken from the documentation [MPU-6000/MPU-6050 Register Map and Description, p.30]
  //Serial.print(" | tmp = "); Serial.print(temperature/340.00+36.53);
  //Serial.print(" | gX = "); Serial.print(convert_int16_to_str(gyro_x));
  //Serial.print(" | gY = "); Serial.print(convert_int16_to_str(gyro_y));
  //Serial.print(" | gZ = "); Serial.print(convert_int16_to_str(gyro_z));
  //Serial.println();
}

void readData()
{
  // "Wire.read()<<8 | Wire.read();" means two registers are read and stored in the same variable
  accelerometer_x = Wire.read()<<8 | Wire.read(); // reading registers: 0x3B (ACCEL_XOUT_H) and 0x3C (ACCEL_XOUT_L)
  accelerometer_y = Wire.read()<<8 | Wire.read(); // reading registers: 0x3D (ACCEL_YOUT_H) and 0x3E (ACCEL_YOUT_L)
  accelerometer_z = Wire.read()<<8 | Wire.read(); // reading registers: 0x3F (ACCEL_ZOUT_H) and 0x40 (ACCEL_ZOUT_L)
  temperature = Wire.read()<<8 | Wire.read(); // reading registers: 0x41 (TEMP_OUT_H) and 0x42 (TEMP_OUT_L)
  //gyro_x = Wire.read()<<8 | Wire.read(); // reading registers: 0x43 (GYRO_XOUT_H) and 0x44 (GYRO_XOUT_L)
  //gyro_y = Wire.read()<<8 | Wire.read(); // reading registers: 0x45 (GYRO_YOUT_H) and 0x46 (GYRO_YOUT_L)
  //gyro_z = Wire.read()<<8 | Wire.read(); // reading registers: 0x47 (GYRO_ZOUT_H) and 0x48 (GYRO_ZOUT_L)
}
