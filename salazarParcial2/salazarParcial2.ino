int humedadSensor = A0;
int myLEDs [5] = {4,5,6,7,8};
bool btnState = false;
const byte pinBuzzer = 3; // zumbador test
int buttonPin = 2;


//-----------------------------------------------------------

void setup(){
  
  pinMode(buttonPin, INPUT);
  
  for(int i = 0; i < 5; i++){
   pinMode(myLEDs[i], OUTPUT);

  }
  
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}


//-------------------------------------------------------

void loop(){
  int humedad = analogRead(humedadSensor);
  Serial.println(humedad);
  delay(1000);
  btnState = digitalRead(buttonPin);

  if(humedad < 20)
  {
  analogWrite(pinBuzzer, HIGH);
  delay(250);
  analogWrite(pinBuzzer, LOW);
  delay(250);
  analogWrite(pinBuzzer, HIGH);
  delay(250);
  analogWrite(pinBuzzer, LOW);
  delay(250);
  analogWrite(pinBuzzer, HIGH);
  delay(250);
  analogWrite(pinBuzzer, LOW);
  delay(250);
  analogWrite(pinBuzzer, HIGH);
  delay(250);
  analogWrite(pinBuzzer, LOW);
  delay(250);
  analogWrite(pinBuzzer, HIGH);
  delay(250);
  analogWrite(pinBuzzer, LOW);
  delay(250);
  analogWrite(pinBuzzer, HIGH);
  delay(250);
  analogWrite(pinBuzzer, LOW);
   
    
  }else{
    analogWrite(pinBuzzer, LOW);
  
   }
  
  if(humedad > 700){
  
  analogWrite(pinBuzzer, HIGH);
 
    
  }
  
 //----------------- detectar nivel de humedad y LED
  
  for(int i = 0; i < 5; i++){
     if(humedad > 800){
        digitalWrite(myLEDs[4 - i], HIGH);
        delay(100);

  
    }else{
       
        digitalWrite(myLEDs[i], LOW);

     }
     
     delay(500);
  }
  
  
  
}
//------------------------------ boton de apagar

/*if(btnstate === true)
{
    analogWrite(pinBuzzer, LOW);
    digitalWrite(myLEDs[4 - i], LOW);
}
*/
