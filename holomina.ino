//Colour for RGB
      int redPin = 9;   // Red LED,   connected to digital pin 9
      int grnPin = 10;  // Green LED, connected to digital pin 10
      int bluPin = 11;  // Blue LED,  connected to digital pin 11
      
//Knock Sensor
      int knock = 0;
      
//Internet Connectivity


  // Set up the LED outputs
    void setup(){
      //Blynk.begin(auth); 
      pinMode(redPin, OUTPUT);   // sets the pins as output
      pinMode(grnPin, OUTPUT);   
      pinMode(bluPin, OUTPUT); 
      Serial.begin(9600);  // ...set up the serial ouput 
      
    }

  // Main program: list the order of crossfades
    void loop(){
    knock = analogRead(0);
    Serial.println(knock); 
      if(knock>=700){
         change();
        }//end of knock part
        
       else{
          analogWrite(redPin, random(0, 255)); 
          analogWrite(grnPin, random(0, 255));
          analogWrite(bluPin, random(0, 255));
          knock = analogRead(0);
          Serial.println(knock); 
            if(knock>=700){
               change();
              }
           delay(4000); 
  }//end of else
            
    }//end of method





//Other methods being called 

int change(){
                  int count;
                  for(count=100; count>0;count--) {
                     analogWrite(redPin, count); 
                     analogWrite(grnPin, count); 
                     analogWrite(bluPin, count); 
                     delay(50);
                     if(count==1){
                      delay(15000);
                      break;
                      }
                  }
               
  
  }
