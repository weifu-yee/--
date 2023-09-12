#include<bits/stdc++.h>
using namespace std;

class Equation{
private:
    const double m_firingPin = 35; //g
    const double m_baseball = 30; //g
    const double m_badminton = 5; //g
    const double k_spring380 = 43; //N/m
    const double l_spring380 = 380; //mm
    const double l_spring = 380; //mm  看要多長
public:
    double theta; //仰角
    double x = 197.9; //cm  看要多遠
    double y = 110; //cm  看要多高
    double delta_s; //mm  彈簧壓縮多長
    double k_spring(double l); //彈簧常數 N/m
    double v_firingPin(double delta_s); //撞針擊發速度 cm/s
    double v_baseball(double delta_s); //棒球擊發速度 cm/s
    double v_badminton(double delta_s); //羽球擊發速度 cm/s
    double v_x(double v); //x方向速度
    double v_y(double v); //y方向速度
    double t(int op, double delta_s); //飛行時間

    Equation(double theta):theta(theta){};
};

double Equation::k_spring(double l){
    return (k_spring380 * l_spring380) / l;
}
double Equation::v_firingPin(double delta_s){
    double v = sqrt(k_spring(l_spring) / (m_firingPin/1000)) * (delta_s/1000);
    return v * 100;
}
double Equation::v_baseball(double delta_s){
    return m_baseball / m_firingPin * v_firingPin(delta_s);
}
double Equation::v_badminton(double delta_s){
    return m_badminton / m_firingPin * v_firingPin(delta_s);
}
double Equation::v_x(double v){
    return v * cos(theta);
}
double Equation::v_y(double v){
    return v * sin(theta);
}
double Equation::t(int op, double delta_s){
    if(op == 1)
        return x / v_x(v_baseball(delta_s));
    else if(op == 2)
        return y / v_y(v_baseball(delta_s));
}


int main(){

}