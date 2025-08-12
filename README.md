# Echo – An Interactive Kinetic Sculpture

|  |  |
|--|--|
| <img src="https://github.com/user-attachments/assets/50bfbdfe-01cf-46bf-9d5f-3e7f946f87d2" width="650px"/> | <img src="https://github.com/user-attachments/assets/7ae4e2c4-c9a9-465c-a246-cf53c5484a1f" width="550px"/> |


> A 49-servo mechanical mirror that translates a viewer’s silhouette into a tactile, fabric-pushing relief in real time — merging live computer vision with physical motion.

**Full project write-up:** [Read on my portfolio](https://samirsfolder.com)  
**Demo video:** [Watch on YouTube](https://youtu.be/rVO2bWj8Jqg?si=mCggyzzBLfMNlfva)

---

## Overview
Echo reimagines Narcissus’s myth in the age of the selfie.  
A USB camera feed is segmented via **MediaPipe** in **TouchDesigner** into a 7×7 grid of push/pull commands sent to 49 SG90 servos. These servos drive polystyrene-tipped cranks behind a stretchable fabric, creating a ghostly, physical trace of the viewer’s form.

---

## Features
- **Real-time computer vision** with MediaPipe.
- **Physical actuation** using 49 micro-servos and crank mechanisms.
- **Serial communication** between TouchDesigner and Arduino for low-latency control.
- Modular wooden frame and crank system designed for repeatable assembly.

---

## Tech Stack
- **Software:** TouchDesigner, Arduino
- **Libraries:** MediaPipe, Adafruit PCA9685 Servo Driver Library
- **Hardware:** SG90 servos, Arduino Leonardo, PCA9685 boards, bench power supply, USB webcam, stretch fabric

---

## How to Run

1. **Download**
   - Download both the Arduino and TouchDesigner project files.

2. **TouchDesigner**
   - Open TouchDesigner.
   - Configure your webcam input.

3. **Arduino**
   - Upload the provided Arduino sketch to your microcontroller.

4. **Serial Connection**
   - Ensure serial port settings match between TouchDesigner and Arduino.

---
