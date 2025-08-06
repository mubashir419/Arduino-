// Pin assignments
const int speakerPin = 9;     // Speaker on digital pin 9
const int potPin = A0;        // Potentiometer on analog pin A0
const int buttonPin = 2;      // Pushbutton on digital pin 2

// Mario tune note frequencies (Hz)
#define NOTE_E6  1319
#define NOTE_A6  1760
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_D7  2349
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_G6  1568
#define NOTE_G7  3136
#define NOTE_A7  3520
#define NOTE_REST 0

// Melody sequence (Mario Bros. Intro Theme)
const int melody[] = {
  NOTE_E7, NOTE_E7, NOTE_REST, NOTE_E7,
  NOTE_REST, NOTE_C7, NOTE_E7, NOTE_REST,
  NOTE_G7, NOTE_REST, NOTE_REST, NOTE_G6,
  NOTE_REST, NOTE_C7, NOTE_REST, NOTE_G6,
  NOTE_REST, NOTE_E6, NOTE_REST, NOTE_A6,
  NOTE_B6, NOTE_A6, NOTE_A6, NOTE_REST,
  NOTE_G6, NOTE_E7, NOTE_G7, NOTE_A7,
  NOTE_F7, NOTE_G7, NOTE_REST, NOTE_E7,
  NOTE_C7, NOTE_D7, NOTE_B6
};

// Corresponding note durations (relative values)
const int durations[] = {
  8, 8, 8, 8,
  8, 8, 4, 8,
  4, 8, 8, 4,
  8, 8, 8, 4,
  8, 8, 8, 8,
  4, 8, 8, 8,
  4, 8, 8, 4,
  8, 8, 8, 8,
  4, 8, 4
};

void setup() {
  pinMode(speakerPin, OUTPUT);       // Speaker pin as OUTPUT
  pinMode(buttonPin, INPUT_PULLUP);  // Button with internal pull-up resistor
}

void loop() {
  // Wait for button press (active LOW)
  if (digitalRead(buttonPin) == LOW) {
    // Read potentiometer to adjust tempo
    int potVal = analogRead(potPin);
    int tempoFactor = map(potVal, 0, 1023, 30, 300);  // Adjust tempo from slow to fast

    int notes = sizeof(melody) / sizeof(melody[0]);   // Total number of notes in melody

    // Play each note in the melody
    for (int i = 0; i < notes; i++) {
      int noteDuration = tempoFactor * durations[i];  // Calculate note duration based on tempo

      if (melody[i] != NOTE_REST) {
        tone(speakerPin, melody[i], noteDuration);    // Play note
      }

      delay(noteDuration * 1.3);                      // Add spacing between notes
      noTone(speakerPin);                             // Stop sound before next note
    }

    delay(500);  // Short pause after melody completes
  }
}
