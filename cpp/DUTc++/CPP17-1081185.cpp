#include <iostream>
#include <cmath>
using std::cin; using std::cout; using std::endl;

class Curve{
public:
    Curve();
    Curve(const Curve &_Curve);
    virtual ~Curve();
    virtual double length()=0;
};

class Line : public Curve{
protected:
    double x1,y1,x2,y2;
public:
    Line(double x1,double y1,double x2,double y2);
    Line(const Line &_Line);
    virtual ~Line();
    virtual double length();
};

class Circle : public Curve{
protected:
    static const double PI;
    double r;
public:
    Circle(double _r);
    Circle(const Circle &_Circle);
    virtual ~Circle();
    virtual double length();
};

class Arc : public Circle{
protected:
    double start_angle,end_angle;
public:
    Arc(double _r,double _start_angle,double _end_angle);
    Arc(const Arc &_Arc);
    virtual ~Arc();
    virtual double length();
};

int main(){
    Curve *ptr;//用基类的指针进行各种曲线长度的输出，为了在调用类的时候也体现动态多态性

    double x1,y1,x2,y2;
    cout<<"输入直线参数："<<endl;
    cout<<"输入起始点坐标：";
    cin>>x1>>y1;
    cout<<"输入终止点坐标：";
    cin>>x2>>y2;
    Line line(x1,y1,x2,y2);
    ptr=&line;
    cout<<endl<<"直线长度："<<ptr->length()<<endl;

    cout<<endl<<"输入圆参数："<<endl;
    double r;
    cout<<"输入圆半径：";
    cin>>r;
    Circle circle(r);
    ptr=&circle;
    cout<<endl<<"圆周长度："<<ptr->length()<<endl;

    cout<<endl<<"输入圆弧参数："<<endl;
    double start_angle,end_angle;
    cout<<"输入圆半径：";
    cin>>r;
    cout<<"输入起始角度：";
    cin>>start_angle;
    cout<<"输入终止角度：";
    cin>>end_angle;
    Arc arc(r,start_angle, end_angle);
    ptr=&arc;
    cout<<"圆弧线长度："<<ptr->length()<<endl;
    return 0;
}

Curve::Curve() {}
Curve::Curve(const Curve &_Curve) {}
Curve::~Curve(){}

Line::Line(double _x1,double _y1,double _x2,double _y2):
    x1(_x1),y1(_y1),x2(_x2),y2(_y2) {}
Line::Line(const Line &_Line):
    x1(_Line.x1),y1(_Line.y1),x2(_Line.x2),y2(_Line.y2) {}
Line::~Line(){}
double Line::length(){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

const double Circle::PI=3.14159;//经过与样例进行比对，猜测$\pi$应该是取了五位小数
Circle::Circle(double _r):
    r(_r) {}
Circle::Circle(const Circle &_Circle):
    r(_Circle.r) {}
Circle::~Circle(){}
double Circle::length(){
    return 2*PI*r;
}

Arc::Arc(double _r,double _start_angle,double _end_angle):
    Circle(_r),
    start_angle(_start_angle),end_angle(_end_angle) {}
Arc::Arc(const Arc &_Arc):
    Circle(_Arc.r),
    start_angle(_Arc.start_angle),end_angle(_Arc.end_angle){}
Arc::~Arc(){}
double Arc::length(){
    return fabs(start_angle-end_angle)/360*Circle::length();
}