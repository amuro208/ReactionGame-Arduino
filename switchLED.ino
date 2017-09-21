int LEDPin1 = 52;
int LEDPin2 = 46;
int LEDPin3 = 44;
int LEDPin4 = 38;
int LEDPin5 = 36;
int LEDPin6 = 30;
int LEDPin7 = 28;
int BUTTONPin1 = 50;    
int BUTTONPin2 = 48;
int BUTTONPin3 = 42;
int BUTTONPin4 = 40;
int BUTTONPin5 = 34;
int BUTTONPin6 = 32;
int BUTTONPin7 = 26;
int SHUTTER_PIN = 10;
int FOCUS_PIN = 9;

bool ST1 = false;
bool ST2 = false;
bool ST3 = false;
bool ST4 = false;
bool ST5 = false;
bool ST6 = false;
bool ST7 = false;

unsigned long time;
bool debug = false;
bool testloop = false;
void setup() {
  Serial.begin(19200);
  Serial.flush();
  pinMode(LEDPin1, OUTPUT);
  pinMode(LEDPin2, OUTPUT);
  pinMode(LEDPin3, OUTPUT);
  pinMode(LEDPin4, OUTPUT);
  pinMode(LEDPin5, OUTPUT);
  pinMode(LEDPin6, OUTPUT);
  pinMode(LEDPin7, OUTPUT);
  pinMode(SHUTTER_PIN, OUTPUT);
  pinMode(FOCUS_PIN, OUTPUT);
  pinMode(BUTTONPin1, INPUT);
  pinMode(BUTTONPin2, INPUT);
  pinMode(BUTTONPin3, INPUT);
  pinMode(BUTTONPin4, INPUT);
  pinMode(BUTTONPin5, INPUT);
  pinMode(BUTTONPin6, INPUT);
  pinMode(BUTTONPin7, INPUT);



}
String inData;

void takeShot(){
  digitalWrite(SHUTTER_PIN,HIGH);
  delay(10);
  digitalWrite(SHUTTER_PIN,LOW); 
}
void offAll(){
  digitalWrite(LEDPin1,LOW);
  digitalWrite(LEDPin2,LOW);
  digitalWrite(LEDPin3,LOW);
  digitalWrite(LEDPin4,LOW);
  digitalWrite(LEDPin5,LOW);
  digitalWrite(LEDPin6,LOW);
  digitalWrite(LEDPin7,LOW);
}

void onAll(){
  digitalWrite(LEDPin1,HIGH);
  digitalWrite(LEDPin2,HIGH);
  digitalWrite(LEDPin3,HIGH);
  digitalWrite(LEDPin4,HIGH);
  digitalWrite(LEDPin5,HIGH); 
  digitalWrite(LEDPin6,HIGH);
  digitalWrite(LEDPin7,HIGH);
}
void loop() {
  
   if(digitalRead(BUTTONPin1) == HIGH){
     if(ST1) {ST1=false;takeShot();digitalWrite(LEDPin1,LOW);Serial.println("off1");}
   }
   if(digitalRead(BUTTONPin2) == HIGH){
     if(ST2) {ST2=false;takeShot();digitalWrite(LEDPin2,LOW);Serial.println("off2");}
   }
   if(digitalRead(BUTTONPin3) == HIGH){
     if(ST3) {ST3=false;takeShot();digitalWrite(LEDPin3,LOW);Serial.println("off3");}
   }
   if(digitalRead(BUTTONPin4) == HIGH){
     if(ST4) {ST4=false;takeShot();digitalWrite(LEDPin4,LOW);Serial.println("off4");}
   }
   if(digitalRead(BUTTONPin5) == HIGH){
     if(ST5) {ST5=false;takeShot();digitalWrite(LEDPin5,LOW);Serial.println("off5");}
   }
   if(digitalRead(BUTTONPin6) == HIGH){
     if(ST6) {ST6=false;takeShot();digitalWrite(LEDPin6,LOW);Serial.println("off6");}
   }
   if(digitalRead(BUTTONPin7) == HIGH){
     if(ST7) {ST7=false;takeShot();digitalWrite(LEDPin7,LOW);Serial.println("off7");}
   }
 

  if(testloop){
  onAll();delay(500);
  offAll();delay(500);
  onAll();delay(500);
  offAll();delay(500);
  digitalWrite(LEDPin1,HIGH);delay(300);digitalWrite(LEDPin1,LOW);
  digitalWrite(LEDPin2,HIGH);delay(300);digitalWrite(LEDPin2,LOW);
  digitalWrite(LEDPin3,HIGH);delay(300);digitalWrite(LEDPin3,LOW);
  digitalWrite(LEDPin4,HIGH);delay(300);digitalWrite(LEDPin4,LOW);
  digitalWrite(LEDPin5,HIGH);delay(300);digitalWrite(LEDPin5,LOW);
  digitalWrite(LEDPin6,HIGH);delay(300);digitalWrite(LEDPin6,LOW);
  digitalWrite(LEDPin7,HIGH);delay(300);digitalWrite(LEDPin7,LOW);

  delay(1000);
  }
   
   while (Serial.available() > 0)
    {
        char recieved = Serial.read();
         inData += recieved; 

        // Process message when new line character is recieved
        if (recieved == '\n')
        {
          /*
            Serial.print("@,");
            Serial.print("Arduino Received: ");
            Serial.print(inData);

            // You can put some if and else here to process the message juste like that:

            if(inData == "d\n"){ // DON'T forget to add "\n" at the end of the string.
              debug = true;
              Serial.print("@,DEBUG ");
            }   
            if(inData == "n\n"){ // DON'T forget to add "\n" at the end of the string.
              debug = false;
              Serial.print("@,NORMAL");
            }  
            */
          //  
           if(inData == "st1\n"){ST1 = true;}
           if(inData == "st2\n"){ST2 = true;}
           if(inData == "st3\n"){ST3 = true;}
           if(inData == "st4\n"){ST4 = true;}
           if(inData == "st5\n"){ST5 = true;}
           if(inData == "st6\n"){ST6 = true;}
           if(inData == "st7\n"){ST7 = true;}

            if(inData == "on1\n"){ digitalWrite(LEDPin1,HIGH); }
            if(inData == "off1\n"){ digitalWrite(LEDPin1,LOW); }
            if(inData == "on2\n"){ digitalWrite(LEDPin2,HIGH); }
            if(inData == "off2\n"){ digitalWrite(LEDPin2,LOW); }
            if(inData == "on3\n"){ digitalWrite(LEDPin3,HIGH); }
            if(inData == "off3\n"){ digitalWrite(LEDPin3,LOW); }
            if(inData == "on4\n"){ digitalWrite(LEDPin4,HIGH); }
            if(inData == "off4\n"){ digitalWrite(LEDPin4,LOW); }
            if(inData == "on5\n"){ digitalWrite(LEDPin5,HIGH); }
            if(inData == "off5\n"){ digitalWrite(LEDPin5,LOW); }
            if(inData == "on6\n"){ digitalWrite(LEDPin6,HIGH); }
            if(inData == "off6\n"){ digitalWrite(LEDPin6,LOW); }
            if(inData == "on7\n"){ digitalWrite(LEDPin7,HIGH); }
            if(inData == "off7\n"){ digitalWrite(LEDPin7,LOW); }
            
            if(inData == "offAll\n"){
              offAll();
            }
            if(inData == "onAll\n"){
              onAll();
            }
             if(inData == "loop\n"){
              testloop = !testloop;
               Serial.println("testloop");
             }
            inData = "";
            
        }else{
         
        }
    }
    delay(1);

}
