# 🎶 Arduino Mario Melody Player with Potentiometer & Button

This is a simple Arduino project that plays the Super Mario Bros. theme song using a piezo buzzer. The tempo (speed) of the melody can be adjusted with a potentiometer, and the melody starts playing only when a pushbutton is pressed.

---

## 🛠 Components Required
| Component           | Quantity |
|---------------------|----------|
| Arduino UNO (or compatible) | 1 |
| Piezo Buzzer / Speaker      | 1 |
| Potentiometer (10kΩ)        | 1 |
| Pushbutton                  | 1 |
| Breadboard                  | 1 |
| Jumper Wires                | As needed |

---

## Circuit Diagram

> Speaker (Piezo)
> - Positive Lead → Digital Pin 9
> - Negative Lead → GND (with optional 220Ω resistor in series)

> Potentiometer
> - Left Pin → GND
> - Middle Pin → Analog Pin A0
> - Right Pin → 5V

> Pushbutton
> - One Side → Digital Pin 2
> - Other Side → GND


---

## How It Works
- Power on Arduino uno to play the melody.
- Rotate the potentiometer to control the speed (tempo) of the melody.
- The buzzer plays notes by generating sound frequencies via the `tone()` function.

---

## Uploading to Arduino
1. Open the `.ino` file in Arduino IDE.
2. Connect your Arduino board via USB.
3. Select the correct Board and COM Port in the IDE.
4. Click Upload.
5. Once uploaded, press the button to hear the Mario melody.

---

## License
This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.

---

## Contributing
Feel free to fork this repository and submit pull requests to add new melodies or improve features!

---

## Project Demo
> https://drive.google.com/drive/folders/1hKxMfMlIoWV4klkA6-JxuFuGnRLxHt2Q?usp=sharing

---

## ⭐ Credits
- Mario Theme Song by Nintendo.
- Based on simple Arduino tone-playing examples.
