void saveData(char *data, float tempDis, float humidityDis){
  File file = SD.open(fileName, FILE_WRITE);
  
  if (file) {
    Serial.print("Writing to test.txt...");
    file.print(data);
    file.print(",");
    file.print(tempDis);
    file.print(",");
    file.print(humidityDis);
    file.println(",");
    file.close();
    Serial.println("done.");
  } else {
    Serial.println("error opening test.txt");
  }
}

void sdtest(){
  myFile = SD.open("test4.txt", FILE_WRITE);
  
  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3.");
	// close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  
  // re-open the file for reading:
  myFile = SD.open("test4.txt");
  if (myFile) {
    Serial.println("test.txt:");
    
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
    	Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
  	// if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}
