# Arduino Certification: Learning Through Tangible Circuits

A complete documentation of my self-directed journey through a 10-lesson Arduino Junior Certification — started December 2024, completed independently with no instructor or mentor.

---

## 📓 Lessons

| Lesson | Topic | Status |
|--------|-------|--------|
| Lesson 0 | Unboxing + Safety + Setup | ✅ Complete |
| Lesson 1 | First Circuit — Closed Loop LED | ✅ Complete |
| Lesson 2 | Ohm's Law + Series vs Parallel | ✅ Complete |
| Lesson 3 | Traffic Light + Digital/Analog Inputs | ✅ Complete |
| Lesson 4 | Potentiometer + Analog Data | ✅ Complete |
| Lesson 5 | Capstone 1 — Multi-Mode Holiday Hub | ✅ Complete |
| Lesson 6 | Capacitors + Servo Motor | ✅ Complete |
| Lesson 7 | Windshield Wiper + Switch-Case + Loops | ✅ Complete |
| Lesson 8 | Piezo Buzzer + Resistor Ladder + Musical Keyboard | ✅ Complete |
| Lesson 9 | Phototransistor + Light Wave Radar | ✅ Complete |
| Lesson 10 | Capstone 2 — Wireless Environmental Scanner | 🔧 In Progress |

---

## 💡 Engineering Philosophy

I don't just follow instructions. Every lesson I connect what I learn to the history of who invented it and why, the physics behind how it works, and what it means for real systems. Whether it's tracing the resistor ladder back to hardware optimization principles or connecting asynchronous timing to robotics decision loops, I treat every circuit as a system to understand, not just build.

---

## 🔬 Technical Highlights

**Proving Ohm's Law (Lesson 2)**
Measured voltage across series and parallel circuits with a multimeter:
- Series 2 LEDs: 1.82V per LED
- Series 3 LEDs: 1.64V per LED
- Parallel 2 LEDs: 1.87V per LED

Confirmed tolerance of ±0.1V due to internal resistance and wire voltage drop.

**Adaptive Engineering — Missing Capacitor (Lesson 6)**
Kit arrived without a polarized capacitor. Instead of stopping, I found TinkerCAD and built a digital twin to complete the lesson virtually. Documented the full troubleshooting process including box destruction and online research before finding the solution.

**Resistor Ladder + Musical Keyboard (Lesson 8)**
Built an octave keyboard using one analog pin to read four buttons by assigning each a different resistor. Hardware does the sorting so the software stays clean — one analogRead instead of four digitalReads.

**Logic Synthesis Document**
After completing lessons 1-9, I wrote a synthesis connecting every major concept to software engineering principles — blocking vs non-blocking code, hardware optimization vs software logic, physical state vs boolean variables. See Logic_Synthesis.md.

---

## 📂 Repository Structure

```
/journal          — Post-lesson reflections for lessons 0-9 + Logic Synthesis
/src              — Arduino (.ino) code files
/media            — Circuit photos and multimeter readings
/schematics       — Wiring diagrams
```

---

## 🎓 What Came Next

These lessons directly led to:
- **arduino-for-kids** — A free 8-lesson Arduino curriculum I designed and teach at my local public library for ages 11-14
- **MIT BWSI 2026** — Accepted to MIT Beaver Works Summer Institute, Microelectronics and Embedded Systems track