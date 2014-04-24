void displayOled(char *data, float tempDis, float humidityDis){
  lcd.setCursor(0,0);
  lcd.setFont(FONT_SIZE_SMALL);
  lcd.print(data);
  
  lcd.setCursor(0,1);
  lcd.setFont(FONT_SIZE_MEDIUM);
  //lcd.setTextColor(WHITE);
  lcd.print("Temp: ");
  
  lcd.setCursor(50,1);
  lcd.setFont(FONT_SIZE_MEDIUM);
  lcd.print(tempDis);
  
  lcd.setCursor(0,3);
  lcd.setFont(FONT_SIZE_MEDIUM);
  lcd.print("Humi: ");
  
  lcd.setCursor(50,3);
  lcd.setFont(FONT_SIZE_MEDIUM);
  lcd.print(humidityDis);
}
