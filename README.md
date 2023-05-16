# NULCEO-F091RC-PIDMotoroCTRL-ROS
Dependencies:
  ROS noetic:
    -rosserial
    -python3
  mbed:
    PIDmotor
    RotaryEncoder

Installation:
  ROS:
    sudo apt-get install ros-noetic-rosserial

Usage:
  1. sudo chmod +777 /dev/ttyACM0
  2. roscore
  3. rosrun rosserial_python serial_node.py /dev/ttyACM0 (new terminal)
  4. python3 teleop-ros.py (new terminal)
