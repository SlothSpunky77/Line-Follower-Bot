# Line-Following Robot with Obstacle and Traffic Light Detection

### Project Description
This project is an Arduino-powered autonomous robot that follows a black line on the floor while detecting and responding to obstacles and traffic lights. The robot uses multiple sensors to navigate and make decisions:
- **Ultrasound sensor** for obstacle detection, ensuring the robot stops when an object or wall is placed in its path.
- **Infrared sensors** for line tracking, allowing the robot to follow a black line on a white surface.
- **Color sensor** for traffic light recognition, stopping at a red light and proceeding at a green light.

### Features
- **Line Following:** The robot uses two infrared sensors to follow a black line on the ground.
- **Obstacle Avoidance:** The ultrasonic sensor detects objects in the robot's path and halts movement until the obstacle is cleared.
- **Traffic Light Recognition:** The color sensor identifies red and green lights, stopping the robot at red and allowing it to proceed at green.
- **Real-Time Decision Making:** The robot makes real-time decisions based on sensor input to navigate safely and efficiently.

### How It Works
- **Line Following:** The infrared sensors detect the contrast between the black line and the white surface, sending signals to the Arduino to adjust the motors accordingly.
- **Obstacle Avoidance:** The ultrasonic sensor continuously measures the distance to objects in front of the robot. When an object is detected within a certain threshold, the robot stops.
- **Traffic Light Control:** The color sensor detects the color of lights. If a red light is detected, the robot stops. If a green light is detected, the robot resumes movement.
