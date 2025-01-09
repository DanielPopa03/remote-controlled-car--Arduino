#include <Arduino.h>
#include <SoftwareSerial.h>
#define RX_PIN 2
#define TX_PIN 4
#define leftSideFrontMotorFoward 3//
#define leftSideFrontMotorBack 7
#define leftSideBackMotorFoward 5
#define leftSideBackMotorBack 10
#define rightSideFrontMotorFoward 6
#define rightSideFrontMotorBack 9
#define rightSideBackMotorFoward 11//
#define rightSideBackMotorBack 8
SoftwareSerial slaveSerial(RX_PIN, TX_PIN);
long lastTime = 0;

class QueueActions {
private:
    int arr[5];        
    int front, size; 
    const int capacity;    
    char command;
public:
 
    QueueActions(char command): capacity(5) {
      this->command = command;
      size = 0;
      front = 0;
    }

    QueueActions(const QueueActions& ref) : capacity(ref.capacity) {
      for (int i = 0; i < ref.capacity; i++) {
        this->arr[i] = ref.arr[i];
      }
      this->command = ref.command;
      this->size = ref.size;
      this->front = ref.front;
    }

    char getCommand() {
      return command;
    }

    int getFront() {
      // Queue is empty
      if (size == 0) 
          return -1; 
      return arr[front];
    }

    int getRear() {
      
      // Queue is empty
      if (size == 0) 
          return -1; 
      int rear = (front + size - 1) % capacity;
      return arr[rear];
    }

    void enqueue(int x) {
      // Queue is full
      if (size == capacity) 
          return; 
      int rear = (front + size) % capacity;
      arr[rear] = x;
      size++;
    }

    int dequeue() {
      // Queue is empty
      if (size == 0) 
          return -1;
      int res = arr[front];
      front = (front + 1) % capacity;
      size--;
      return res;
    }

    QueueActions& operator=(const QueueActions& other) {
      if (this == &other) {
        return *this;
      }
      for (int i = 0; i < other.capacity; i++) {
        this->arr[i] = other.arr[i];
      }
      this->command = other.command;
      this->size = other.size;
      this->front = other.front;
      return *this;
    }

};
QueueActions queueOfActions = QueueActions('-');

void pwmControl(int pin, int dutyCycleInPercentages) {
  analogWrite(pin, dutyCycleInPercentages * 255 / 100);
}

void clearMotor() {
  pwmControl(leftSideFrontMotorFoward, 0);
  digitalWrite(leftSideFrontMotorBack, LOW);
  pwmControl(leftSideBackMotorFoward, 0);
  digitalWrite(leftSideBackMotorBack, LOW);
  pwmControl(rightSideFrontMotorFoward, 0);
  digitalWrite(rightSideFrontMotorBack, LOW);
  pwmControl(rightSideBackMotorFoward, 0);
  digitalWrite(rightSideBackMotorBack, LOW);
}


char lastCommnand = '\0';
const int startPercentageForDutyCycle = 60;
bool isFirstInsert = false;
int currentDutyCycle = startPercentageForDutyCycle;
void stopTimer() {
  TCCR1B &= ~(1 << CS12); 
  Serial.println("Timer stopped: ");
  lastCommnand = '\0';
}
void startTimer() {
  queueOfActions.enqueue(startPercentageForDutyCycle);
  TCCR1B &= ~(1 << CS12);
  TCNT1 = 0;       
  TCCR1B |= (1 << CS12); 
  Serial.println("Timer started: "); 
}
void moveMotor() {
  int currentDutyCycle = queueOfActions.dequeue();
  if (currentDutyCycle == -1) {
    stopTimer();
    clearMotor();
    return;
  }
  switch (queueOfActions.getCommand()) {
  case 'F':
    pwmControl(leftSideFrontMotorFoward, currentDutyCycle);
    digitalWrite(leftSideFrontMotorBack, LOW);
    pwmControl(leftSideBackMotorFoward, currentDutyCycle);
    digitalWrite(leftSideBackMotorBack, LOW);
    pwmControl(rightSideFrontMotorFoward, currentDutyCycle);
    digitalWrite(rightSideFrontMotorBack, LOW);
    pwmControl(rightSideBackMotorFoward, currentDutyCycle);
    digitalWrite(rightSideBackMotorBack, LOW);
    break;
  case 'B':
    pwmControl(leftSideFrontMotorFoward, 0);
    digitalWrite(leftSideFrontMotorBack, HIGH);
    pwmControl(leftSideBackMotorFoward, 0);
    digitalWrite(leftSideBackMotorBack, HIGH);
    pwmControl(rightSideFrontMotorFoward, 0);
    digitalWrite(rightSideFrontMotorBack, HIGH);  
    pwmControl(rightSideBackMotorFoward, 0);
    digitalWrite(rightSideBackMotorBack, HIGH);
    break;
  case 'L':
    pwmControl(leftSideFrontMotorFoward, 0);
    digitalWrite(leftSideFrontMotorBack,  LOW);
    pwmControl(leftSideBackMotorFoward, 0);
    digitalWrite(leftSideBackMotorBack, LOW);
    pwmControl(rightSideFrontMotorFoward, 100);
    digitalWrite(rightSideFrontMotorBack, LOW);
    pwmControl(rightSideBackMotorFoward, 100);
    digitalWrite(rightSideBackMotorBack, LOW);
    break;
  case 'R':
    pwmControl(leftSideFrontMotorFoward, 100);
    digitalWrite(leftSideFrontMotorBack, LOW);
    pwmControl(leftSideBackMotorFoward, 100);
    digitalWrite(leftSideBackMotorBack, LOW);
    pwmControl(rightSideFrontMotorFoward, 0);
    digitalWrite(rightSideFrontMotorBack, LOW);
    pwmControl(rightSideBackMotorFoward, 0);
    digitalWrite(rightSideBackMotorBack, LOW);
    break;
  default:
    return;
    break;
  }
}
ISR(TIMER1_COMPA_vect) {
  Serial.println("Timer expired: ");
  Serial.println(millis() - lastTime);
  moveMotor();
}

bool isValidCommand(char command) {
    return command == 'F' || command == 'B' || command == 'L' || command == 'R';
}

void motorControl(char command) {
  if (!isValidCommand(command)) {
    return;
  }
  if (command == lastCommnand) {
    if (currentDutyCycle < 100)
    currentDutyCycle += 10;
    queueOfActions.enqueue(currentDutyCycle);
    if (isFirstInsert) {
      isFirstInsert = false;
      moveMotor();
    }
  } else {
    stopTimer();
    currentDutyCycle = startPercentageForDutyCycle;
    queueOfActions = QueueActions(command);
    isFirstInsert = true;
    startTimer();
  }
  lastCommnand = command;
}


int i = 0;
long mil = 0;
void serialDataReceivedISR() {
  // Read the received data
  i ++;
  if(slaveSerial.available()) {
    char received = slaveSerial.read();
    Serial.print("Received in interupt: ");
    Serial.print(i);
    Serial.print(" ");
    Serial.print(millis()- mil);
    Serial.print(" ");
    Serial.println(received);
    mil = millis();
    i = 0;
    motorControl(received);
  }

}

void configureTimer() {
  cli(); 

  TCCR1A = 0; 
  TCCR1B = 0;
  TCNT1 = 0;

  OCR1A = 31250; // Set compare match value for 500ms

  TIMSK1 |= (1 << OCIE1A); // Enable Timer1 Compare Match A interrupt

  TCCR1B |= (1 << WGM12); // Configure Timer1 in CTC mode

  sei();

}

void setup() {
  configureTimer();
  Serial.begin(9600);           // Serial monitor communication
  Serial.println("Slave initialized");
  slaveSerial.begin(9600);      // Communication with the HC-05 module

  // Set motor pins as output
  pinMode(leftSideFrontMotorFoward, OUTPUT);
  pinMode(leftSideFrontMotorBack, OUTPUT);
  pinMode(leftSideBackMotorFoward, OUTPUT);
  pinMode(leftSideBackMotorBack, OUTPUT);
  pinMode(rightSideFrontMotorFoward, OUTPUT);
  pinMode(rightSideFrontMotorBack, OUTPUT);
  pinMode(rightSideBackMotorFoward, OUTPUT);
  pinMode(rightSideBackMotorBack, OUTPUT);

  // Set RX_PIN as input for interrupt
  pinMode(RX_PIN, INPUT_PULLUP);
  // Attach pin change interrupt
  attachInterrupt(digitalPinToInterrupt(RX_PIN), serialDataReceivedISR, CHANGE);
}

void loop() {}

