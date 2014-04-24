float readtemp(){
  float temp_c;
  temp_c = (int)(sht1x.readTemperatureC() * 100.0)/100.0;
  return temp_c;
}

float readhumidity(){
  float humidity1;
  humidity1 = (int)(sht1x.readHumidity() * 100.0)/100.0;
  return humidity1;
}
