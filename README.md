# NULCEO-F091RC-PIDMotoroCTRL-ROS
https://os.mbed.com/users/6f953f6d-adb0-4afd-b254-05004248a722/code/NULCEO-F091RC-PIDMotoroCTRL-ROS/ <br /> 
Dependencies:<br /> 
  &emsp;ROS noetic:<br />
    &emsp;&emsp;-rosserial<br />
    &emsp;&emsp;-python3<br />
  &emsp;mbed:<br />
    &emsp;&emsp;-PIDmotor<br />
    &emsp;&emsp;-RotaryEncoder<br />

Installation:<br />
  &emsp;ROS:
    
    sudo apt-get install ros-noetic-rosserial

Usage:<br />

    sudo chmod +777 /dev/ttyACM0
    roscore
    rosrun rosserial_python serial_node.py /dev/ttyACM0 #new terminal
    python3 teleop-ros.py #new terminal
