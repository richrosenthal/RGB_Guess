//Author Richard Rosenthal
//Date 1-9-21

int buttonValue = 0;
int buttonValue2 = 0;
int buttonValue3 = 0;

bool won = false;
bool stillPlaying;
bool guessing = true;

int winningNumber;
int score = 0;

int button = 3;
int button2 = 5;
int button3 = 7;
int LED = 2; 
int LED2 = 4;
int LED3 = 6;
int LEDWIN = 13;
int buzzer = 11;




void setup() {
  // put your setup code here, to run once:

  
  
  pinMode(button, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LEDWIN, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);



}

void loop() {

 
 startUpLights();
 winningNumber = generateWinningNumber();
 stillPlaying = true;
 guessing = true;
 score = 0;
 while (stillPlaying){
    
    while(guessing){

        buttonValue = digitalRead(button);
        buttonValue2 = digitalRead(button2);
        buttonValue3 = digitalRead(button3);

       if(buttonValue != 0){

          if (winningNumber == 1){
            digitalWrite(LED, HIGH);
            delay(1000);
            digitalWrite(LED, LOW);
            won = true;
            guessing = false;
            }
           else{
            Serial.println("Lost round");
            score -= 1;
            guessing = false;
           }
        }
       else if(buttonValue2 != 0){

          if (winningNumber == 2){
            digitalWrite(LED2, HIGH);
            delay(1000);
            digitalWrite(LED2, LOW);
            won = true;
            guessing = false;           
            }
           else{
            Serial.println("Lost round");
            score -= 1;
            guessing = false;
           } 
        }
       else if(buttonValue3 != 0){
        if (winningNumber == 3){
            digitalWrite(LED2, HIGH);
            delay(1000);
            digitalWrite(LED2, LOW);
            won = true;
            guessing = false; 
        }
        else{
            Serial.println("Lost round");
            score -= 1;
            guessing = false;
          }
       }
       else {
       digitalWrite(LED, LOW);
       digitalWrite(LED2, LOW);
       digitalWrite(LED3, LOW);
       }
      
      }

   if (won == true){
     score += 1;
    }
   if(score == 3){
     digitalWrite(LEDWIN, HIGH);
     delay(10000);
     digitalWrite(LEDWIN, LOW);
     stillPlaying = false;
     guessing = true;
    }
   if(score == -1){
    stillPlaying = false;
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
   }
  }

 
}



//function to start up lights
void startUpLights(){
digitalWrite(LED3, HIGH);
delay(1000);
digitalWrite(LED3, LOW);
delay(500);
digitalWrite(LED, HIGH);
delay(500);
digitalWrite(LED2, HIGH);
delay(100);
digitalWrite(LED, LOW);
delay(500);
digitalWrite(LED2, LOW);
digitalWrite(LEDWIN, HIGH);
delay(500);
digitalWrite(LEDWIN, LOW);
 }


 //function to select winning number
 int generateWinningNumber(){
  int randomNumber = random(1,4);
  return randomNumber;
 }
