#include <iostream>
#include <cmath>
using std::cout; using std::endl; using std::cin;

class Curve{
public:
    Curve(){}
    ~Curve(){}
};

class Line : public Curve{
protected:
    double x1,y1,x2,y2;
public:
    Line(double x1,double y1,double x2,double y2):x1(x1),y1(y1),x2(x2),y2(y2){}
    virtual double length(){
        return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    }
};

class Circle : public Curve{
protected:
    static const double PI;
    double radius;
public:
    Circle(double radius):radius(radius){}
    virtual double length(){
        return 2*PI*radius;
    }
};

class Arc : public Circle{
protected:
    double startAngle,endAngle;
public:
    Arc(double radius, double startAngle, double endAngle):Circle(radius),startAngle(startAngle),endAngle(endAngle){}
    virtual double length(){
        return Circle::length()*fabs(endAngle-startAngle)/360.0;
    }
};

int main(){
    cout << "输入直线参数：" << endl;
    double x1, y1, x2, y2;
    cout << "输入起始点坐标：";
    cin >> x1 >> y1;
    cout << "输入终止点坐标：";
    cin >> x2 >> y2;
    Line line(x1, y1, x2, y2);
    cout << "直线长度：" << line.length() << endl;

    cout << endl << "输入圆参数：" << endl;
    double radius;
    cout << "输入圆半径：";
    cin >> radius;
    Circle circle(radius);
    cout << "圆周长度：" << circle.length() << endl;

    cout << endl << "输入圆弧参数：" << endl;
    double startAngle, endAngle;
    cout << "输入圆半径：";
    cin >> radius;
    cout << "输入起始角度：";
    cin >> startAngle;
    cout << "输入终止角度：";
    cin >> endAngle;
    Arc arc(radius, startAngle, endAngle);
    cout << "圆弧线长度：" << arc.length() << endl;
    return 0;
}

const double Circle::PI = 3.1415926;