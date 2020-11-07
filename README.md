# Eye-Controlled-Wheelchair

As the name suggests, this is a wheelchair that can be controlled by the motion of eyes. Being specific though, we built a prototype, which can be easily implemented on an actual wheelchair.<br />
We started off with this super-cool project in November'19. The idea sparked as an initiative for a social cause. We were also lucky enough to present our project in the Inter-IIT Tech Meet 8.0 held at IIT Roorkee. <br />
 In this blog we describe the steps to build a similar project and also the problems encountered and their fixes.

# The Problem Statement
People who have completely lost the control their muscles cannot operate wheelchair on their own. Our project is an attempt to make lives of the people suffering from diseases like motor-neuron disability simple and self-reliant. The idea is to use the motion of pupil of the person's eye sitting on the wheelchair to allow him to move in a desired direction. The system is cost effective and thus can be used by patients spread over a large economy range.
The actual wheelchair with additional features might look like this:

# Proposed Solution
Locomotion is important for keeping up with the pace of life. There are many people who are unable to move from one place to another because of physical disability. Traditional wheelchairs does this job but at the same time it either made them dependent on another person or they were too difficult to operate by self. An individual might be partially paralyzed and hence would always require an external help to move. <br />
Eye Controlled Wheelchair is an idea that might solve the issue. It functions as a normal wheelchair but it eliminates the dependency of the user on external help. The idea is to control the movement of the wheelchair with the motion of pupil. The direction in which a person looks is detected by a camera mounted on the wheelchair. The camera sends the signals to a microprocessor and it sends signal to the wheels and the wheels move in the desired direction. The idea is cost effective and can be possessed by anyone in need of the product. <br />
This is a powerful idea that combines the technologies of Artificial Intelligence and Robotics in the Health Care sector. <br />

# Working
The idea is to control the movement of the wheelchair with the motion of pupil. The direction in which a person looks is detected by a camera mounted on the wheelchair. Camera takes frames of eye positions and then processing on the frame done based on the eye position(center, left, right) and returns the result. We also set a Boolean to start or stop the Wheelchair. The person has to close his eyes for 5 seconds for either action. The action is then being send to the NodeMCU by a (int) variable wirelessly. NodeMCU processes the instruction(center, left, right, start, stop) and give power to the wheels according to the instruction.

# Installation Instructions
First off all you will need a Python IDE. You can use the link given below to download Python. <br />
 Since we have implemented our project on Python version-3 , so I recommend you the same to avoid unnecessary errors. https://www.python.org/downloads/ <br />
Opencv is a Computer Vision Library which is used to record the face of the person. To install opencv, open your Ubuntu terminal and type the command written below:<br />
sudo apt-get install python-opencv <br />
We used dlib library for face detection. I encourage you to use other methods such as Viola Jones, Harr Cascade or YOLO and also share your results with us. To install dlib, open your Ubuntu terminal and type the command written below:<br />
pip install dlib <br />
If you get some errors you can refer to the documentation link provided below:<br />
https://www.learnopencv.com/install-dlib-on-ubuntu/<br />
Numpy is a Python library to do mathematical computations. Since Python does not come with Numpy pre-installed, you have to install it as well.To install Numpy, open your Ubuntu terminal and type the command written below:<br />
sudo apt install python-numpy<br />
You have to download a facial landmarks file too. Refer to the link below to download the same from the githhub repository:<br />
https://github.com/AKSHAYUBHAT/TensorFace/blob/master/openface/models/dlib/ shape_predictor_68_face_landmarks.dat<br />
A point to note here is that your Python Working Directory should contain this file.<br />
You have to install NodeMCU drivers on your Arduino IDE. Refer to the documentation below to install the drivers:<br />
https://arduino-esp8266.readthedocs.io/en/latest/installing.html<br />

# Python Code:
The section does not include the complete code but it contains some essential parts of the code. Complete code can be found on the Github link provided at the end of the blog.
Function for calculating blinking ratio which essentially is the ratio of vertical distance to the horizontal distance of the eye if its large then that means eyes are open and if its small then it means eyes are close.. This property is then used to set a Boolean toggle for start and stop of the wheelchair. The person has to close his eyes for 5 seconds for either action.<br />
From the eye we calculate a gaze ratio which is essentially a measure of how the black part(pupil) is located when we look in different directions.If we see forward then its value comes out to be in between 1 to 2 if its right its value is less than 1 and if its value is greater than 2 then it means left.<br />
Enter the server IP i.e. ( Microprocessor IP address) in the appropriate space provided.<br />
CamHandler is a class which contains a function where ping from NodeMCU is received.<br />
Pings from NodeMCU are served until Escape key is pressed.<br />
The code below is a part of CamHandler class. Once the line of sight is detected, this is now compiled in a way which can be easily sent over the local network.<br />
a is the variable which is actually a number but is sent as a string. This number contains the information of the direction of vision of the person. Rest all the lines in the code are attributes of the information.<br />

# Arduino IDE Code:
This section does not contain the complete code that is to be run on NodeMCU but a necessary explanation of its main components.<br />
The following libraries have to be installed and imported correctly.<br />
A function which returns the value sent by python code over a local connection. A value of 1 indicates Right turn, 2 indicates Center, 3 indicates Left turn, a value of 0 indicates no movement and if something else is obtained depicts that the Python program has stopped running.<br />
void setup function checks for connection over the local network and also connects to the network. Enter the hotspot name and password in the space provided in the code and a wireless connection is set-up. An important point to note is that the server (Laptop or any other Microprocessor) and the receiver (NodeMCU) should be connected to the same network. We used mobile hotspot but hotspot of the microprocessor can also be used.<br />
The line below runs in a loop and sends a ping to the server every second (this time can be different for your code).<br />
The server responds to the ping request and sends a number which is basically the direction in which the person is looking at the time.<br />
This is a part of void loop section of the code.<br />
Once, the direction is known power is sent to the motors through motor driver containing H- bridge.<br />

# Hardware:
You need to buy a NodeMCU as it contains a Wifi with GPIO pins. GPIO pins are used to power the motors according to our needs.<br />
We use L298N as the H-bridge. Also, we have put the front motors and the back motors in parallel so that an additional H-bridge is not required.<br />
Also use a good quality camera on the server side. The camera can be connected on a laptop where the Python code is running or on any other Microprocessor.<br />
We also gave an option of speed control to the user. We achieved this by using a potentiometer connected between 3.3 V annd Ground supply of NodeMCU. The variable end was connected on A0 pin of NodeMCU.<br />

# Limitations:
1. The face of the user should be well - illuminated.<br />
2. The head of the person should be steady when frames were captured so that detection is precise.<br />
3. The camera should be at a specific distance from the user and the background should not contain other faces.<br />
4. The accuracy of the model is between 70%-90% which can be further increased using more sophisticated models.<br />

# Conclusion:
Quadriplegia is paralysis caused by illness or injury to the humans that results in partial or complete loss of limbs and torso. Its a phenomenon which confines the ability of a person to move by himself, and he has to rely on someone to carry him around.<br />
 We wanted to utilize the opportunity to design something which could be a contribution in our own small way to the society.<br />
The system functions with an accuracy rate of 70–90 % which is quite satisfactory. The image capture, eye movement detection and the algorithm for validating movement attempts perform very reliably as our results suggest.
<br />
