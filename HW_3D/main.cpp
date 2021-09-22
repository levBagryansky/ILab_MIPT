#include <iostream>

struct Point{
    double xyz[3];
};

class Triangle{
public:
    Point ABC[3];

public:
    Triangle();
    Triangle(double x1, double y1, double z1,
             double x2, double y2, double z2,
             double x3, double y3, double z3);
    Triangle(Point A, Point B, Point C);
};

Triangle::Triangle(): ABC(){};

Triangle::Triangle(Point A, Point B, Point C) {
    ABC[0] = A;
    ABC[1] = B;
    ABC[2] = C;
}

std::istream& operator>> (std::istream& is, Triangle& t){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            is >> t.ABC[i].xyz[j];
        }
    }
    return is;
}

std::ostream& operator<< (std::ostream& os,const Triangle& t){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            os << t.ABC[i].xyz[j] << ' ';
        }
    }
    return os;
}

bool areCross(const Triangle t1, const Triangle t2){
    ;
}

double computeDet(int m[3][3]){
    return m[0][0] * m[1][1] * m[2][2] +
           m[0][1] * m[1][2] * m[2][0] +
           m[0][2] * m[1][0] * m[2][1] -
           m[2][0] * m[1][1] * m[0][2] -
           m[1][0] * m[0][1] * m[2][2] -
           m[0][0] * m[2][1] * m[1][2];
}

void reverseMatrix()

int main() {
    //std::cout << "Hello, World!" << std::endl;
    Triangle t;
    std::cout << "Tringle is: " << t <<std::endl;
    return 0;
}
