# 🤖 Beach Cleaner Robot – Motor Control Code

This folder contains the embedded control code used for the prototype developed during the conceptual phase of the **Beach Waste Collection Robot**.

The code was written for an **Arduino Nano** and allows basic remote control via Bluetooth using a mobile app interface. The robot responds to serial commands to perform directional movements using an H-bridge motor driver.

---

## 📄 File: `beach_cleaner_motors.ino`

### 🛠️ Description
- **Title**: Programa de Diseño Conceptual
- **Author**: Diego Méndez Carter
- **Initial Release**: Revision A – 09/07/2024
- **Language**: Arduino C++
- **Purpose**: Control motor direction and speed using serial Bluetooth commands.

---

## 🎮 Serial Commands

| Command | Action         |
|---------|----------------|
| `d`     | Move forward    |
| `a`     | Move backward   |
| `i`     | Turn left       |
| `d`     | Turn right (note: duplicated, may require refactor) |
| `s`     | Stop            |

---

## ⚙️ Pin Configuration

| Motor     | IN1 | IN2 |
|-----------|-----|-----|
| Left (A)  | 10  | 9   |
| Right (B) | 6   | 5   |

---

## 🧠 Code Structure

- `setup()` initializes all motor pins and stops motors.
- `loop()` listens for serial commands and sets motor currents accordingly.
- Helper functions:
  - `set_motor_currents(int pwm_A, int pwm_B)`
  - `set_motor_pwm(int pwm, int IN1_PIN, int IN2_PIN)`

PWM values range from `-255` (full reverse) to `255` (full forward).

---

## ⚠️ Notes

- The forward (`d`) and right-turn (`d`) commands share the same character. This should be revised for clarity and functionality.
- Designed to be tested via Bluetooth module (e.g., HC-05) sending characters from a mobile app.

---

## 🧾 License

This code is provided for educational and prototype use only.

---

## 👤 Author

**Diego Méndez Carter**  
Mechatronics Engineer | Robotics Developer  
🔗 [GitHub](https://github.com/deimencart)
This section is to describing the code for the concept. 
