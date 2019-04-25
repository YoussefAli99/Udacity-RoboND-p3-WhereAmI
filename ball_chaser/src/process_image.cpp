#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    ball_chaser::DriveToTarget srv;
    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;

    if (!client.call(srv)) {
        ROS_ERROR("Failed to call service /ball_chaser/command_robot");
    }
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{
    int white_pixel = 255;

    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.step; x++) {
            int i = y * img.step + x;
            if (img.data[i] == white_pixel) {
                float rate = (float)x / img.step;
                if (rate < .3) {
                    drive_robot(0, .5);
                } else if (.7 < rate) {
                    drive_robot(0, -.5);
                } else {
                    drive_robot(1.0, 0.);
                }
                return;
            }
        }
    }

    drive_robot(0., 0.);
    return;
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}

