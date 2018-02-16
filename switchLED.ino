

#define SIZE 10
#define BLINKING 70
#define SHN_RELEASE 200;

char buffer[5];
byte LED[SIZE] = {26,28,32,34,38,40,44,46,50,52};
byte BTN[SIZE] = {27,29,33,35,39,41,45,47,51,53};
//byte LED[SIZE] = {26,28,32,34,38,40,44};
//byte BTN[SIZE] = {27,29,33,35,39,41,45};
bool ST[SIZE] = {false,false,false,false,false,false,false,false,false,false};
byte SHUTTER_PIN = 10;
byte FOCUS_PIN = 9;

int CUR = -1;
int PRE = -1;
int BLN = BLINKING;
int SHN = SHN_RELEASE;
bool BS = false;
bool debug = false;
bool test = false;
byte SH = 0;
unsigned long time;


void setup() {
  Serial.begin(9600);
  Serial.flush();
  Serial.println("OH YES LET'S GO!");
  
  for(int i = 0;i<SIZE;i++){
    pinMode(LED[i], OUTPUT);
    pinMode(BTN[i], OUTPUT);
  }
  pinMode(SHUTTER_PIN, OUTPUT);
  pinMode(FOCUS_PIN, OUTPUT);
}
String inData;

void takeShot(){ 
  SHN = SHN_RELEASE;
  SH = 1;
  digitalWrite(SHUTTER_PIN,HIGH);
}
void numOn(char n){
  CUR = int(n);
   for(int i = 0;i<SIZE;i++){
     if(ST[i] && i!=CUR){
      digitalWrite(LED[i],LOW);
      ST[i] = false;
     }
  }
  
  BLN = BLINKING;
  BS = true;
  ST[CUR] = true;
  digitalWrite(LED[CUR],HIGH); 
}
void randomOn(){
  int n = random(0,SIZE); 
  numOn(n);
  //ST[n] = true;
}
void offAll(){
  CUR = -1;
  for(int i = 0;i<SIZE;i++){
     digitalWrite(LED[i],LOW);
  }
}

void onAll(){
   CUR = -1;
   for(int i = 0;i<SIZE;i++){
     digitalWrite(LED[i],HIGH);
  }
}

void loop() {

  if(SH==1){
    SHN--;
    if(SHN<50){ 
      SH = 2;
      digitalWrite(SHUTTER_PIN,LOW);
    }
   
  }else if(SH==2){
    SHN--;
     if(SHN<0){
      SH = 0;
      digitalWrite(LED[PRE],LOW);
      sprintf(buffer,"bf%d",PRE+1);
      Serial.println(buffer);
      PRE = -1;
      if(test){
        randomOn();  
      }
    }
  }
  
  if(CUR>-1){
    BLN = BLN-1;

    if(BLN<0){
       BLN = BLINKING;
      if(BS){
        digitalWrite(LED[CUR],LOW);
      }else{
        digitalWrite(LED[CUR],HIGH);
      }
      BS=!BS;
     }

     for(int i = 0;i<SIZE;i++){
       if(digitalRead(BTN[i]) == HIGH){   
         if(ST[i]) {
            ST[i]=false;
            sprintf(buffer,"bd%d",CUR+1);
            Serial.println(buffer);
            digitalWrite(LED[CUR],HIGH);
            takeShot();
            PRE = CUR;
            CUR=-1;
            
          }
        }
     }
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
    
            if(inData == "t\n"){
              takeShot();
            }
            else if(inData == "offAll\n"){
              offAll();
            }
            else if(inData == "onAll\n"){
              onAll();
            }
            else if(inData == "test\n"){
             test = !test;
             if(test){
                randomOn();
              }else{
                offAll();
                CUR=-1;
              }

           //Button of from GameUI for general
           }else if(inData.substring(0,2)=="bo"){
              char n = inData.charAt(2)-49;
              numOn(n);


           //Button off from GameUI for testing
           }else if(inData.substring(0,2)=="bf"){
              char n = inData.charAt(2)-49;
              if(ST[n]) {
              ST[n]=false;
              sprintf(buffer,"bd%d",CUR+1);
              Serial.println(buffer);
              digitalWrite(LED[CUR],HIGH);
              takeShot();
              PRE = CUR;
              CUR=-1;
            }
           }
           
           inData = "";
            
        }
    }
    //Serial.println("AAA");
    delay(1);

}
