# About this project
[Udacity Robotics Software Engineer Nanodegree](https://www.udacity.com/course/robotics-software-engineer--nd209)
is one of Udacity classes, in which there are lectures about how to emulate
and control robots in ROS environment including gazebo, RViz, and so on.
The goal of this project "Where Am I" is to implement source code to estimate
current state of a robot car moving in the house, and navigate to designated
position in the map. To estimate the position from LIDAR mounted in front of
the car, Udacity encourage to use ROS package [amcl](http://wiki.ros.org/amcl)
which implements adaptive Monte Carlo localization algorithm. Using amcl,
robot car can recognize current state probabilistically.

# Project Details
In project 2, I implemented algorithm of robot car chasing white ball
located in the house using image captured by camera. In project 3, I modified
source code implemented in project 2 so as to use [amcl](http://wiki.ros.org/move_base)
localization package, and move_base navigation package.

After launching the environment, robot car is placed on the map in RViz window.
If you specify In RViz window If you click the 2D Nav Goal button in the toolbar,
then click and drag on the map, you can send the goal to the robot.
It will start moving and localize itself in the process.

This gif animation of localization example is shown below.
![RViz Screenshot Movie](images/movie_AMCL.gif)

# Getting Started
1. Install ROS kinetic in Ubuntu 16.04 environment (time consuming step)
``` bash
$ sudo apt-get update
$ sudo apt-get install ros-kinetic-desktop-full
```
2. Install ROS packages used in this project.
``` bash
$ sudo apt-get install ros-kinetic-navigation
$ sudo apt-get install ros-kinetic-map-server
$ sudo apt-get install ros-kinetic-move-base
$ sudo apt-get install ros-kinetic-amcl
```
3. Clone this github repository.
``` bash
$ git clone https://github.com/tnakae/Udacity-RoboND-p3-WhereAmI.git
```
4. Build.
``` bash
$ cd Udacity-RoboND-p3-WhereAmI/catkin_ws/
$ catkin_make
```
5. Launch environment *in Ubuntu GUI*. It launches gazebo and RViz.
``` bash
$ source devel/setup.bash
$ roslaunch my_robot world.launch
```
6. *Open another terminal*, and launch AMCL algorithm.
``` bash
$ cd Udacity-RoboND-p3-WhereAmI/catkin_ws/
$ source devel/setup.bash
$ roslaunch my_robot amcl.launch
```
7. In RViz window, select `File` -> `Open Config File`, and open
`catkin_ws/src/config.rviz`. Map is shown around the robot in RViz window.
8. Push `2D Nav Goal` button in the toolbar of RViz, and, then click and
drag on the map to send the goal to the robot.
It will start moving and localize itself in the process.
