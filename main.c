#include <iostream>
#include <cmath>

using namespace std;

class Coordinates 
{
    public:
    double x, y, z;

    Coordinates(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) 
    {
        
    }
    void newCoordinates(double newx,double newy,double newz)
    {
        x=newx;
        y=newy;
        z=newz;
    }
};
class Formuls
{
    public:
    double obem(double radius,double height)
    {
        return 3.14*(pow(radius,2))*height;
    }
    
    
   bool IsPointInside(Coordinates point, double radius,double height,Coordinates center)
    {
       double dx1=point.x;
       double dy1=point.y;
       double dz1=point.z;
     
     
     bool condition1=(pow(dx1,2)+pow(dy1,2))<(pow(radius,2));
     bool condition2=(-height/2.0<=dz1)&&(dz1<=height/2.0);
     return condition1&&condition2;
    
    
    }
};
int main()
{
    Formuls calculator;
    double radius, height;
    Coordinates center;
   
    
    cout << "Введите координаты центра основания цилиндра : ";
    cin >> center.x >> center.y >> center.z;
    cout << "Введите радиус цилиндра: ";
    cin >> radius;
    cout << "Введите высоту цилиндра: ";
    cin >> height;
    
    double obem = calculator.obem(radius, height);
    cout << "Объем цилиндра: " << obem << endl;
    
    
      
    Coordinates point;
    cout << "Введите координаты точки : ";
    cin >> point.x >>point.y >> point.z;

    bool isInside = calculator.IsPointInside(point, radius, height, center);

    if (isInside) {
        cout << "Точка лежит внутри цилиндра." << endl;
    } else {
        cout << "Точка не лежит внутри цилиндра." << endl;
    }

    return 0;

}
