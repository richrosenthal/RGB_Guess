//Pin 3: Input for reading the button state
//pin 2 output for controlling the led
int buttonValue = 0;
int buttonValue2 = 0;
int buttonValue3 = 0;



int button = 3;
int button2 = 5;
int button3 = 7;
int LED = 2; 
int LED2 = 4;
int LED3 = 6;
int LEDWIN = 13;


void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LEDWIN, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 buttonValue = digitalRead(button);
 buttonValue2 = digitalRead(button2);
 buttonValue3 = digitalRead(button3);

 digitalWrite(LEDWIN, HIGH);

 if(buttonValue != 0){
  digitalWrite(LED, HIGH);
  Serial.write("button1");
  Serial.println();
 }
 else if(buttonValue2 != 0){
  digitalWrite(LED2, HIGH);
  Serial.write("button2");
  Serial.println();
 }
 else if(buttonValue3 != 0){
  digitalWrite(LED3, HIGH);
  Serial.write("button3");
  Serial.println();
 }
 else {
  digitalWrite(LED, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  
 }
}
