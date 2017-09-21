int LEDPin1 = 26;
int LEDPin2 = 28;
int LEDPin3 = 32;
int LEDPin4 = 34;
int LEDPin5 = 38;
int LEDPin6 = 40;
int LEDPin7 = 44;
int LEDPin8 = 46;
int LEDPin9 = 50;
int LEDPin10 = 52;
int BUTTONPin1 = 27;    
int BUTTONPin2 = 29;
int BUTTONPin3 = 33;
int BUTTONPin4 = 35;
int BUTTONPin5 = 39;
int BUTTONPin6 = 41;
int BUTTONPin7 = 45;
int BUTTONPin8 = 47;
int BUTTONPin9 = 51;
int BUTTONPin10 = 53;

int SHUTTER_PIN = 4;
int FOCUS_PIN = 3;

bool ST1 = false;
bool ST2 = false;
bool ST3 = false;
bool ST4 = false;
bool ST5 = false;
bool ST6 = false;
bool ST7 = false;
bool ST8 = false;
bool ST9 = false;
bool ST10 = false;
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
  pinMode(LEDPin8, OUTPUT);
  pinMode(LEDPin9, OUTPUT);
  pinMode(LEDPin10, OUTPUT);
  pinMode(SHUTTER_PIN, OUTPUT);
  pinMode(FOCUS_PIN, OUTPUT);
  pinMode(BUTTONPin1, INPUT);
  pinMode(BUTTONPin2, INPUT);
  pinMode(BUTTONPin3, INPUT);
  pinMode(BUTTONPin4, INPUT);
  pinMode(BUTTONPin5, INPUT);
  pinMode(BUTTONPin6, INPUT);
  pinMode(BUTTONPin7, INPUT);
  pinMode(BUTTONPin8, INPUT);
  pinMode(BUTTONPin9, INPUT);
  pinMode(BUTTONPin10, INPUT);


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
  digitalWrite(LEDPin8,LOW);
  digitalWrite(LEDPin9,LOW);
  digitalWrite(LEDPin10,LOW);
}

void onAll(){
  digitalWrite(LEDPin1,HIGH);
  digitalWrite(LEDPin2,HIGH);
  digitalWrite(LEDPin3,HIGH);
  digitalWrite(LEDPin4,HIGH);
  digitalWrite(LEDPin5,HIGH); 
  digitalWrite(LEDPin6,HIGH);
  digitalWrite(LEDPin7,HIGH);
  digitalWrite(LEDPin8,HIGH);
  digitalWrite(LEDPin9,HIGH);
  digitalWrite(LEDPin10,HIGH);
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
   if(digitalRead(BUTTONPin8) == HIGH){
     if(ST8) {ST8=false;takeShot();digitalWrite(LEDPin8,LOW);Serial.println("off8");}
   }
    if(digitalRead(BUTTONPin9) == HIGH){
     if(ST9) {ST9=false;takeShot();digitalWrite(LEDPin9,LOW);Serial.println("off9");}
   }
    if(digitalRead(BUTTONPin10) == HIGH){
     if(ST10) {ST10=false;takeShot();digitalWrite(LEDPin10,LOW);Serial.println("off10");}
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
  digitalWrite(LEDPin8,HIGH);delay(300);digitalWrite(LEDPin8,LOW);
  digitalWrite(LEDPin9,HIGH);delay(300);digitalWrite(LEDPin9,LOW);
  digitalWrite(LEDPin10,HIGH);delay(300);digitalWrite(LEDPin10,LOW);
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
           if(inData == "st8\n"){ST8 = true;}
           if(inData == "st9\n"){ST9 = true;}
           if(inData == "st10\n"){ST10 = true;}
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
            if(inData == "on8\n"){ digitalWrite(LEDPin8,HIGH); }
            if(inData == "off8\n"){ digitalWrite(LEDPin8,LOW); }
            if(inData == "on9\n"){ digitalWrite(LEDPin9,HIGH); }
            if(inData == "off9\n"){ digitalWrite(LEDPin9,LOW); }
            if(inData == "on10\n"){ digitalWrite(LEDPin10,HIGH); }
            if(inData == "off10\n"){ digitalWrite(LEDPin10,LOW); }
            
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
