# 🚗 Embedded RC Car Updated Version – AVR-Based Smart System

This project demonstrates a **fully functional smart RC car** implemented using the **AVR ATmega32 microcontroller**. The system supports both manual and automatic driving modes, real-time distance measurement via ultrasonic sensors, UART communication for wireless control, and an LCD interface for status monitoring. It combines precise motor control with real-time decision-making to create an embedded vehicle system.

---

## 🎯 Features

- 🔄 **Manual Control Mode** via UART (Bluetooth or Serial Terminal)
- 🚘 **Automatic Obstacle Avoidance Mode** using ultrasonic sensors
- 📏 **Dynamic Speed Control** based on front distance readings
- 💬 **Live LCD Feedback** for car speed and ultrasonic distance
- 🚨 **Collision Detection** that halts the vehicle automatically
- 🟢🔴 **LED Indicators** for movement status
- 🧠 Modular architecture with reusable embedded drivers

---

## 📁 Repository Structure

```
Embedded-RC-Car-Updated-Version/
├── SMART_CAR_/ # Main embedded source code
│ ├── main.c # Application entry point with main loop
│ ├── Smart_Car.h # Main header (global vars, mode flags)
│ │
│ ├── BUTTON.c / BUTTON.h # Push button interface (engine start)
│ ├── DIO.c / DIO.h # Digital I/O abstraction
│ ├── External_Interrupt.c/.h # External interrupt routines (INT0/INT1)
│ ├── LCD.c / LCD.h # 16x2 LCD handling
│ ├── LCD_CONFIG.h # LCD pin configuration macros
│ ├── LED.c / LED.h # Status LED (collision / active)
│ ├── Motors.c / Motors.h # Motor motion logic (forward, drift, etc.)
│ ├── Registers.h # ATmega32-specific register map
│ ├── STD_Macros.h # Utility macros for bitwise ops
│ ├── STD_Types.h # Standard typedefs (u8, u16, etc.)
│ ├── Timers.c / Timers.h # Timer0 / Timer2 for PWM and delays
│ ├── USART.c / USART.h # UART communication driver
│ ├── UltraSonic.c / UltraSonic.h # HC-SR04 interfacing via input capture
│ └── Debug/ # Build system output (from IDE)
│
├── Smat_Car.pdsprj # Project file for Proteus/IDE
├── LICENSE # Project license (MIT)
└── README.md # Documentation file (this one)
```

---

## ⚙️ System Configuration

| Component         | Description                                     |
|------------------|-------------------------------------------------|
| MCU              | ATmega32 @ 8 MHz                                |
| LCD              | 16x2 Alphanumeric (HD44780 compatible)          |
| Motor Driver     | Dual DC motor driver (L298N or equivalent)      |
| Distance Sensor  | HC-SR04 Ultrasonic Sensor                       |
| UART Interface   | Bluetooth module / USB-UART                     |
| Control Inputs   | Mobile App or Serial Terminal                   |
| Status Outputs   | LCD, LEDs, UART                                 |

---

## 🚀 How It Works

1. **Startup Sequence**
   - System waits for engine start via push button.
   - LCD displays "Engine On Hold" with red LED indication.

2. **Manual Driving Mode**
   - Receive commands via UART (e.g., `F` for forward, `B` for backward).
   - Speed is adjustable with predefined or custom slider values.
   - Real-time speed and distance shown on LCD.

3. **Obstacle Detection**
   - Uses ultrasonic sensor to read distance to objects.
   - If an obstacle is closer than 40 cm during forward motion, the car stops.

4. **Automatic Mode**
   - If enabled, the car autonomously navigates using a single front ultrasonic sensor.
   - Executes avoidance maneuvers (turn, drift) based on measured distances.

5. **Speed Regulation Mode**
   - Car adjusts PWM speed output based on measured distance (near → slower, far → faster).

---

## 🛠️ Development & Tools

- **Language:** Embedded C (AVR-GCC)
- **Simulation (Optional):** Proteus 8.0 or later
- **Compiler/IDE:** Atmel Studio / Microchip Studio / AVRDUDE
- **Programmer:** USBasp / USBtiny / ArduinoISP

---

## 📡 UART Command Reference

| Command Code         | Action                            |
|----------------------|-----------------------------------|
| `F`                  | Move Forward                      |
| `B`                  | Move Backward                     |
| `R` / `L`            | Turn Right / Left                 |
| `D` / `G`            | Drift Right / Left                |
| `0-90` (slider)      | Set speed to custom PWM           |
| `A`                  | Activate Automatic Mode           |
| `U` / `Q`            | Enable / Disable ultrasonic speed |
| `S`                  | Stop Car                          |

---

## 📷 Screenshots

[> Videos For Car In Real](https://drive.google.com/drive/folders/13eISjtNETk8Ca6FLa6vn31HT-yrpULg9?usp=sharing)

---

## 📄 License

This project is licensed under the [Apatch 2.0](LICENSE).  
You're free to use, modify, and distribute it with attribution.

---

## 👨‍💻 Author

**Adham Amr**  
🔗 [GitHub Profile](https://github.com/Adham-amr-1)  
🎓 Embedded Systems | Robotics | Automotive Electronics

---

> For questions, improvements, or collaborations — feel free to open an issue or pull request!



