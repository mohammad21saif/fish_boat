#define DIR_PIN 3   // Direction pin
#define STEP_PIN 4  // Pulse pin
#define EN_PIN 5    // Enable pin (optional)
#define ThrPin 2
#define TrnPin 7
int flag_left = 0;
int flag_right = 0;
int steps  = 100;
long int delay_input;
int turn_steps = 100;
// int turn_steps;
unsigned Thr_pul_width;
unsigned Trn_pul_width;

void setup() {
  Serial.begin(9600);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(EN_PIN, OUTPUT);
  pinMode(ThrPin, INPUT);
  pinMode(TrnPin, INPUT);

  // Enable the motor driver
  digitalWrite(EN_PIN, LOW); // LOW to enable
}

void loop() {
  Thr_pul_width = pulseIn(ThrPin, HIGH, 250000);
  Trn_pul_width = pulseIn(TrnPin, HIGH, 250000);
  delay_input = map(Thr_pul_width, 1480, 1899, 500, 250);
  
  Serial.println("Throttle");
  Serial.println(Thr_pul_width);

  Serial.println("Turning");
  Serial.println(Trn_pul_width);

  //Rotate clockwise
    digitalWrite(DIR_PIN, HIGH); // Set direction
    for (int i = 0; i < steps; i++) { // Adjust steps as per motor/revolution (e.g., 200 for 1.8° step motor)
      digitalWrite(STEP_PIN, HIGH);
      delayMicroseconds(delay_input); // Adjust speed
      digitalWrite(STEP_PIN, LOW);
      delayMicroseconds(delay_input);
    }
    //Rotate counterclockwise
    digitalWrite(DIR_PIN, LOW); // Change direction
    for (int i = 0; i < steps; i++) {
      digitalWrite(STEP_PIN, HIGH);
      delayMicroseconds(delay_input);
      digitalWrite(STEP_PIN, LOW);
      delayMicroseconds(delay_input);
    }

    if ((Trn_pul_width > 1090) && (Trn_pul_width < 1400) && (flag_left == 0) ) {
    digitalWrite(DIR_PIN, HIGH);
    for (int i = 0; i < turn_steps; i++) {
      digitalWrite(STEP_PIN, HIGH);
      delayMicroseconds(200);
      digitalWrite(STEP_PIN, LOW);
      delayMicroseconds(200);
      }
    flag_left = 1;
    }

    else if ((Trn_pul_width > 1500) && (Trn_pul_width < 1900) && flag_right == 0) {
    digitalWrite(DIR_PIN, LOW);
    for (int i = 0; i < turn_steps; i++) {
      digitalWrite(STEP_PIN, HIGH);
      delayMicroseconds(200);
      digitalWrite(STEP_PIN, LOW);
      delayMicroseconds(200);
      }
    flag_right = 1;
    }

    else if ((Trn_pul_width > 1400) && (Trn_pul_width < 1500)) {
    flag_left = 0;
    flag_right = 0;
    }



  
  // if ((Trn_pul_width > 1090) && (Trn_pul_width < 1400)) {
  //   digitalWrite(DIR_PIN, HIGH);
  //   for (int i = 0; i < turn_steps; i++) {
  //     digitalWrite(STEP_PIN, HIGH);
  //     delayMicroseconds(200);
  //     digitalWrite(STEP_PIN, LOW);
  //     delayMicroseconds(200);
  //   }

  //   //Rotate clockwise
  //   digitalWrite(DIR_PIN, HIGH); // Set direction
  //   for (int i = 0; i < steps; i++) { // Adjust steps as per motor/revolution (e.g., 200 for 1.8° step motor)
  //     digitalWrite(STEP_PIN, HIGH);
  //     delayMicroseconds(delay_input); // Adjust speed
  //     digitalWrite(STEP_PIN, LOW);
  //     delayMicroseconds(delay_input);
  //   }
  //   //Rotate counterclockwise
  //   digitalWrite(DIR_PIN, LOW); // Change direction
  //   for (int i = 0; i < steps; i++) {
  //     digitalWrite(STEP_PIN, HIGH);
  //     delayMicroseconds(delay_input);
  //     digitalWrite(STEP_PIN, LOW);
  //     delayMicroseconds(delay_input);
  //   }
  // }

  // else if ((Trn_pul_width > 1500) && (Trn_pul_width < 1900)) {
  //   digitalWrite(DIR_PIN, LOW);
  //   for (int i = 0; i < turn_steps; i++) {
  //     digitalWrite(STEP_PIN, HIGH);
  //     delayMicroseconds(200);
  //     digitalWrite(STEP_PIN, LOW);
  //     delayMicroseconds(200);
  //   }

  //   //Rotate clockwise
  //   digitalWrite(DIR_PIN, HIGH); // Set direction
  //   for (int i = 0; i < steps; i++) { // Adjust steps as per motor/revolution (e.g., 200 for 1.8° step motor)
  //     digitalWrite(STEP_PIN, HIGH);
  //     delayMicroseconds(delay_input); // Adjust speed
  //     digitalWrite(STEP_PIN, LOW);
  //     delayMicroseconds(delay_input);
  //   }
  //   //Rotate counterclockwise
  //   digitalWrite(DIR_PIN, LOW); // Change direction
  //   for (int i = 0; i < steps; i++) {
  //     digitalWrite(STEP_PIN, HIGH);
  //     delayMicroseconds(delay_input);
  //     digitalWrite(STEP_PIN, LOW);
  //     delayMicroseconds(delay_input);
  //   }
  // }

  // else {
  //   //Rotate clockwise
  //   digitalWrite(DIR_PIN, HIGH); // Set direction
  //   for (int i = 0; i < steps; i++) { // Adjust steps as per motor/revolution (e.g., 200 for 1.8° step motor)
  //     digitalWrite(STEP_PIN, HIGH);
  //     delayMicroseconds(delay_input); // Adjust speed
  //     digitalWrite(STEP_PIN, LOW);
  //     delayMicroseconds(delay_input);
  //   }
  //   //Rotate counterclockwise
  //   digitalWrite(DIR_PIN, LOW); // Change direction
  //   for (int i = 0; i < steps; i++) {
  //     digitalWrite(STEP_PIN, HIGH);
  //     delayMicroseconds(delay_input);
  //     digitalWrite(STEP_PIN, LOW);
  //     delayMicroseconds(delay_input);
  //   }
  // }
}
