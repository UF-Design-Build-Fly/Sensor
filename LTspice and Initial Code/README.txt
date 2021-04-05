Sensor_Demo.asc is the LTspice schematic for contructing a simple blink circuit using a transistor. The associated Arduino code is included here as sensor_demo.ino.

Sensor_test.asc is the LTspice schematic built off of Sensor_Demo meant for simulating the design of the actual circuit to be built. The first revision simply used diodes and the built in IRF530 spice transistor model. The current revision makes use of accurate LED and transistor models and is what will be used to build the circuit when we get shop access. The program to run the test is sensor_test.ino.

Further documentation available on our google drive in the Sensor Design and LTspice Models folder. You will need to look over this to correctly simulate the sensor_test.asc file! 