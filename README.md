Arduino Certification: Learning through Tangible Circuits
- This repository is a comprehensive documentation of my journey through a 10-lesson Arduino certification. I am tracking my progress from basic electron movement to building interactive systems that respond to the real world.

💡 My Engineering Philosophy
- I don't just want to follow instructions; I want to connect what I learn to real life. Whether it's comparing a Piezo buzzer to a drumhead or debunking the myth that Benjamin Franklin discovered electricity all by himself with a kite, I try to understand the "why" behind every component.

🛠️ Technical Deep-Dives (Lessons 1-9)

- Proving Ohm's Law (Lesson 2)Now that my multimeter finally works, I used it to prove Ohm’s Law V = IR. I tested how voltage behaves in different setups:
 Series (2 LEDs): 1.82V
 Series (3 LEDs): 1.64V
 Parallel (2 LEDs): 1.87V
 Parallel circuits are better for smaller projects because the LEDs stay at maximum brightness, though I have to be careful not to pull too much current and overheat the Arduino.

Potentiometers & Analog Data (Lesson 4)
- I learned that a potentiometer is a variable resistor. By turning a knob, I change the path electricity takes through a resistive track. This taught me how the Analog-to-Digital Converter (ADC) translates a voltage (0V to 5V) into a digital number (0 to 1023) that my code can actually use.

Adaptive Engineering: The Missing Capacitor (Lesson 6)
- I ran into an issue where I was missing a polarized capacitor for my servo circuit. I didn't let that stop me. I used TinkerCad to build a Digital Twin (a virtual model) to test the circuit safely. It taught me that an engineer's best tool isn't always a screwdriver, it's the ability to adapt.

Musical Keyboards & Resistor Ladders (Lesson 8)
- I built a musical keyboard that plays an entire octave. Instead of writing an "insane amount" of if statements for every button, I used a resistor ladder. This structure let me use just one analog pin to read multiple buttons, which showed me how hardware can make software much simpler.

Sensors & Functional Programming (Lesson 9)
- I worked with Phototransistors (which are like the opposites of LEDs). I also learned how to organize my code into functions like transmitter(), receiver(), and collectData(). This makes the code way cleaner and easier to debug than just cramming everything into the void loop.

🎓 Tutoring & Outreach
- I’m currently turning these lessons into a curriculum for middle schoolers at my local library.
- Senior Tutor Experience: I am a Senior Tutor on Schoolhouse.world for Algebra 2.
- Global Reach: I have hosted 32 sessions, reached learners in 16 countries, and have over 120 positive ratings. I use my "detailed and patient" teaching style to help other kids get excited about circuits.

📂 Repository Structure
Based on my project organization:
- /Journals: Detailed post-lesson reflections and vocabulary for Lessons 1-9.
- /Code: Arduino (.ino) files for the Holiday Hub, Traffic Light, and Keyboard.
- /Media: Visual proof of closed circuits and multimeter readings.
"I honestly love Arduino so far—there isn't anything to complain about. I just love the idea of creating tangible circuits. I don't think I will ever not want to create circuits." — From my Lesson 5 Reflection