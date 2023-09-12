#include "map.h"
using namespace std;

void Callback(const bool::ConstPtr& is_node){
}

int main(int argc, char **argv){
    ros::init(argc, argv, "main_func");
    ros::NodeHandle nh;
    ros::Publisher orientation_pub = nh.advertise<int>("/cmd_ori", 1);
    ros::Subscriber pose_sub = nh.subscribe("/node_detect",1,Callback);
    ros::Rate rate(20); //20Hz
    MAP::buildNode();
    while(nh.ok()){

    }
    return 0;
}