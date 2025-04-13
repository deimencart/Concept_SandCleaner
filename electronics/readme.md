
# ⚡ Electronics Overview – Beach Cleaner Robot

This section details the electronics used in the beach cleaner robot prototype and their interconnection, as shown in the following schematic:

---

## 🖼️ Wiring Diagram

![image](https://github.com/user-attachments/assets/4ac52cc8-9386-45a2-919e-8b2f9fe06311)

---

## 🔌 Components and Connections

| Component               | Role                                        |
|------------------------|---------------------------------------------|
| **Arduino Nano**       | Main microcontroller for controlling the motors |
| **Bluetooth Module (HC-05)** | Enables wireless communication via mobile app |
| **L298N Motor Driver** | Drives two DC motors with forward/reverse control |
| **2x DC Gear Motors**  | Provides motion for the robot’s wheels      |
| **2x 18650 Li-ion Batteries** | Power supply for motors and logic         |
| **Slide Switch** (optional) | Turns system on/off manually                |

---

## 🧠 Functional Flow

- The **Bluetooth module** sends control commands (like `a`, `d`, `i`, `s`) to the **Arduino Nano** via serial.
- The Arduino interprets these commands and sends PWM/direction signals to the **L298N motor driver**.
- The **motor driver** regulates power to the **gear motors**, allowing forward, backward, and turning movements.
- **Batteries** directly power both the driver and Arduino through regulated paths.

---

## ⚠️ Notes

- Be sure to include a common ground (GND) between the Arduino, motor driver, and power source.
- The motor driver and batteries must be chosen to handle appropriate current for your motors.

---

## 👤 Author

**Diego Méndez Carter**  
Mechatronics Engineer | Robotics Developer  
🔗 [GitHub](https://github.com/deimencart)
