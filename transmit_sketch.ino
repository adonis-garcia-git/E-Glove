// initialize all pins and variables
#define button1 8
#define button2 12
#define button3 13
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

// set buttons as input and begin serial communication
void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  Serial.begin(9600); // default communication rate of the Bluetooth module
}

void loop() {
 delay(100);
 // read when buttons are clicked
 buttonState1 = digitalRead(button1); 
 buttonState2 = digitalRead(button2);
 buttonState3 = digitalRead(button3);
 // depending on button click, print the corresponding number
 if (buttonState1 == HIGH) {
   Serial.print('1'); // sends '1' to serialout
 }
 else if (buttonState2 == HIGH) {
   Serial.print('2'); // sends '2' to serialout
 }
 else if (buttonState3 == HIGH) {
   Serial.print('3'); // sends '3' to serialout
 }
 // default when no button is pressed
 else {
   Serial.print('0'); // sends '0' to serialout
 }  
}
