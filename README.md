# The E-Glove: A Computer Vision-Based Wireless Mouse Alternative

## Overview

The E-Glove is an innovative hands-free mouse replacement system that combines computer vision, haptic feedback, and wireless communication to enable intuitive computer control through hand gestures. This project was developed during my first semester at NYU Tandon School of Engineering and received two university innovation awards for its novel approach to human-computer interaction.

## The Story Behind the Project

Growing up in the South Bronx, I watched my mother work multiple jobs, often coming home with her hands cramped from long hours of working in the cold. During my senior year of high school, when she needed knee surgery, I saw firsthand how traditional input devices could be challenging for people with mobility limitations. That experience planted a seed: what if we could interact with computers more naturally, using just our hands in space?

When I arrived at NYU as a bright-eyed freshman, I knew I wanted to tackle this challenge. The E-Glove represents that vision: a system that tracks hand movements through a webcam and translates them into precise cursor control, with physical buttons on a glove providing click functionality. It's about making technology more accessible and natural to use. Plus, let's be honest, controlling your computer by waving your hand around makes you feel like a wizard, and who doesn't want that?

## How It Works

The E-Glove system consists of three integrated components working together like a well-choreographed dance:

### 1. **Computer Vision Tracking (Python)**
- Uses OpenCV to detect and track a colored marker (green fingertip) in real-time video feed
- Implements HSV color space filtering for robust color detection under varying lighting conditions
- Calculates precise x, y coordinates of the marker and maps them to screen coordinates
- Achieves 92% tracking accuracy with smooth, responsive cursor movement
- Processes frames at 30+ FPS for real-time interaction

### 2. **Haptic Feedback System (Arduino)**
- Three physical buttons integrated into the glove structure
- Each button triggers a different mouse function (left click, right click, middle click)
- String actuation mechanism provides tactile feedback to the user
- Wireless communication via serial port eliminates cable constraints

### 3. **Wireless Communication Protocol**
- PySerial library bridges Python tracking system and Arduino hardware
- Real-time data transmission with minimal latency (<50ms)
- Robust error handling ensures consistent button response
- Auto-detection of Arduino serial ports for easy setup

## Technical Architecture

```
User's Hand Movement
        ↓
Webcam Captures Video
        ↓
OpenCV Processing:
- Color Detection (HSV)
- Contour Detection
- Centroid Calculation
        ↓
Coordinate Mapping
        ↓
Mouse Cursor Movement (Pynput)

[In Parallel]

Button Press on Glove
        ↓
Arduino Detects Input
        ↓
Serial Communication
        ↓
Mouse Click Action (Pynput)
```

## Key Features

- **Real-time Tracking**: Processes video at 30+ FPS for smooth cursor control
- **Dual Input System**: Combines visual tracking for movement with physical buttons for clicking
- **Wireless Operation**: No cables between user and computer (freedom at last!)
- **Calibration Tool**: HSV range tracker allows customization for different lighting conditions
- **Cross-platform**: Works on Windows, macOS, and Linux
- **Accessible Design**: Created with accessibility and ease of use in mind

## Technical Challenges & Solutions

Building this wasn't all sunshine and rainbows. Here are some of the headaches (and eventual breakthroughs) I encountered:

### Challenge 1: Lighting Variations
**Problem**: Color detection failed under different lighting conditions  
**Solution**: Implemented HSV color space (more robust than RGB) and created calibration tool for real-time adjustment of color thresholds. Turns out, computers don't like when you move from your dorm room to the library and the lighting completely changes. Who knew?

### Challenge 2: Smooth Cursor Movement
**Problem**: Jittery cursor due to noise in tracking  
**Solution**: Applied Gaussian blur for noise reduction and implemented deque-based smoothing with configurable buffer size. Before this fix, the cursor moved like it had too much coffee. Not ideal.

### Challenge 3: Accurate Coordinate Mapping
**Problem**: Webcam coordinates didn't map intuitively to screen space  
**Solution**: Calculated coordinate transformations accounting for frame dimensions and implemented mirroring for natural left-right movement. Initially, moving your hand left made the cursor go right. My brain hurt trying to use it backwards.

### Challenge 4: Serial Communication Reliability
**Problem**: Dropped signals between Arduino and Python  
**Solution**: Implemented robust serial port detection, error handling, and optimized baud rate (9600) for consistent communication. Nothing quite like clicking a button and having your computer ignore you completely.

## Recognition & Impact

- **NYU Outstanding Innovator Award 2022**: Awarded to 1 student out of 230+ teams
- **NYU Gunter Georgi Award 2022**: Honored for innovation in engineering design
- **92% Tracking Accuracy**: Achieved through rigorous testing and optimization (and countless hours of debugging)
- **Educational Impact**: Project now serves as reference for future NYU engineering students exploring computer vision and HCI

## Personal Reflection

Working on The E-Glove taught me that the most meaningful innovations often come from personal experience. Every line of code carries my mother's sacrifices and the challenges faced by people who deserve more intuitive technology. This project wasn't just about building a mouse replacement but instead about opening doors for those who find traditional interfaces limiting.

The late nights debugging serial communication, the frustration of inconsistent color tracking, the joy of finally seeing smooth cursor movement - these moments shaped me as an engineer. I learned that creating accessible technology requires not just technical skills, but empathy and persistence. Also, I learned that OpenCV documentation can be both your best friend and your worst enemy, sometimes on the same day.

There's something magical about seeing your code come to life in the physical world. When I first got the cursor to move smoothly across the screen just by moving my hand, I literally jumped out of my chair. My roommate thought I was crazy. He was probably right.

## Technologies Used

**Programming Languages:**
- Python 3.8+
- C++ (Arduino)

**Libraries & Frameworks:**
- OpenCV (cv2) - Computer vision and image processing
- NumPy - Numerical computations
- Imutils - Image processing utilities
- Pynput - Mouse control
- PySerial - Serial communication
- Arduino IDE - Microcontroller programming

**Hardware:**
- Arduino Uno/Nano
- Push buttons (3x)
- Webcam (720p minimum)
- Connecting wires
- Glove structure (and lots of hot glue)

**Design Tools:**
- Fusion 360 - 3D modeling and design

## Installation & Setup

### Prerequisites
```bash
python >= 3.8
pip >= 21.0
Arduino IDE >= 1.8
```

### Python Dependencies
```bash
pip install opencv-python numpy imutils pynput pyserial
```

### Hardware Setup
1. Connect Arduino to computer via USB
2. Upload `transmit_sketch.ino` to Arduino
3. Connect three push buttons to Arduino digital pins 2, 3, and 4
4. Attach buttons to glove structure (duct tape works in a pinch, but I don't recommend it)
5. Attach colored marker to fingertip

### Software Configuration
1. Run `hsv_range_tracker.py` to calibrate color detection for your lighting
2. Update HSV values in `glove_tracking_with_mouse_movement_and_clicking.py`
3. Run main script and select Arduino COM port when prompted
4. Test tracking and button functionality
5. Feel like a wizard

## Usage

```bash
# Calibrate color detection (do this first, trust me)
python hsv_range_tracker.py

# Run the E-Glove system
python glove_tracking_with_mouse_movement_and_clicking.py

# When prompted, enter your Arduino COM port number
# Example: If you see "COM3", enter "3"
```

### Controls
- **Hand Movement**: Move cursor (wave hello to your screen)
- **Button 1**: Left click
- **Button 2**: Right click  
- **Button 3**: Middle click
- **'Q' Key**: Exit program (for when you inevitably need to take a break)

## File Structure

```
eglove/
├── glove_tracking_with_mouse_movement_and_clicking.py  # Main system
├── hsv_range_tracker.py                                 # Calibration tool
├── transmit_sketch.ino                                  # Arduino transmitter
├── receive_sketch.ino                                   # Arduino receiver (optional)
├── hsv_value.npy                                        # Saved calibration values
└── README.md                                            # This file
```

## Future Enhancements

If I had unlimited time and coffee, here's what I'd love to add:

- **Machine Learning Integration**: Train models to recognize hand gestures for additional commands
- **Multi-hand Tracking**: Support for two-handed control schemes (imagine the possibilities!)
- **Gesture Recognition**: Replace physical buttons with gesture-based clicking
- **Mobile Integration**: Extend system to work with smartphone cameras
- **Accessibility Features**: Add customizable sensitivity and hold-time settings
- **VR/AR Integration**: Adapt system for 3D spatial computing environments

## Lessons Learned

1. **Empathy Drives Innovation**: The best solutions come from understanding real user needs
2. **Iteration is Essential**: The first version rarely works - embrace the debugging process (and the second, and the third...)
3. **Integration is Hard**: Combining hardware and software requires patience and problem-solving (and maybe some stress eating)
4. **Documentation Matters**: Good documentation makes complex systems accessible to others (and to future you)
5. **Testing is Non-negotiable**: Edge cases will break your system - find them early (before your demo, preferably)
6. **Hot Glue is Not a Long-term Solution**: But it'll get you through the presentation

## Contributing

This project was developed as an academic exercise, but I welcome feedback and suggestions. If you're inspired to build upon this work or adapt it for accessibility applications, please reach out! I'd love to hear what you create.

## Contact

**Adonis Garcia**  
Computer Science Student, NYU Tandon School of Engineering  
Email: adonis.garcia@nyu.edu  
LinkedIn: [linkedin.com/in/adonis-garcia-swe](https://linkedin.com/in/adonis-garcia-swe)  
Portfolio: [adonisgarcia.com](https://adonisgarcia.com)

---

*"Every line of code I write carries my mother's sacrifices. This project was about creating technology that works for everyone, especially those who've been left behind by traditional interfaces. Also, it's pretty cool to control your computer by waving your hand around like you're casting a spell."*
