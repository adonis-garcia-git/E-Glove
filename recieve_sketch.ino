// initialize all pins and variables
#define greenledPin 8 
#define blueledPin 12
int state = 0;
int count = 0;

// initialize led states and begin serial communication
void setup() {
  pinMode(greenledPin, OUTPUT);
  pinMode(blueledPin, OUTPUT);
  digitalWrite(greenledPin, HIGH);
  digitalWrite(blueledPin, LOW);
  Serial.begin(9600); // Default communication rate of the Bluetooth module
}

void loop() {
 if(Serial.available() > 0){ // if data available at serial port
    digitalWrite(blueledPin, HIGH); // if there is, then turn blue led on
    count = 0; // keeps count at 0 when recieving data
    state = Serial.read(); // assign incoming data to variable state
    Serial.write(state); // write data to serial monitor
 }
 count += 1; // start adding once data is not being recieved
 
 if(count > 30000){ // if count reaches 30000, then that means data is not available
   digitalWrite(blueledPin, LOW); // if data not available, turn blue led off
 }
}
