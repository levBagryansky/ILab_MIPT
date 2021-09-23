#include <iostream>
#include <vector>
#include <math.h>

struct Point{
    std::vector<double> xyz;
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

Triangle::Triangle(): ABC(){}

Triangle::Triangle(double x1, double y1, double z1,
                   double x2, double y2, double z2,
                   double x3, double y3, double z3) {
    Point A = {{x1, y1, z1}};
    Point B = {{x2, y2, z2}};
    Point C = {{x3, y3, z3}};
    ABC[0] = A;
    ABC[1] = B;
    ABC[2] = C;
}

Triangle::Triangle(Point A, Point B, Point C) {
    ABC[0] = A;
    ABC[1] = B;
    ABC[2] = C;
}

std::istream& operator>> (std::istream& is, Triangle& t){
    for (int i = 0; i < 3; ++i) {
        t.ABC[i].xyz = std::vector<double>(3);
        for (int j = 0; j < 3; ++j) {
            is >> t.ABC[i].xyz[j];
        }
    }
    return is;
}

std::ostream& operator<< (std::ostream& os,const Triangle& t){
    for (int i = 0; i < 3; ++i) {
        os << '(';
        for (int j = 0; j < 2; ++j) {
            os << t.ABC[i].xyz[j] << ' ';
        }
        os << t.ABC[i].xyz[2] << ") ";
    }
    return os;
}

Point operator*(const std::vector<std::vector<double>>& m, const Point& point){
    Point result = {{0}};
    for (int i = 0; i < 3; ++i) {
        result.xyz[i] = 0;
        for (int j = 0; j < 3; ++j) {
            result.xyz[i] += (m[i][j] * point.xyz[j]);
        }
    }
    return result;
}

void printMatrix (std::vector<std::vector<double>>&m){
    std::cout << "Matrix is:" << std::endl;

    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[0].size(); ++j) {
            std::cout << m[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<double>> getUnderMartix (const std::vector<std::vector<double>>&m,
                                                 int i, int j){
    std::vector<std::vector<double>> m_i_j(m);
    m_i_j.erase(m_i_j.begin() + i);
    for (int k = 0; k < m.size() - 1; ++k)
        m_i_j[k].erase(m_i_j[k].begin() + j);

    return m_i_j;
}

double computeDet(const std::vector<std::vector<double>>& m){
    if(m.size() == 1)
        return m[0][0];
    if (m.size() == 2)
        return m[0][0]*m[1][1] - m[0][1]*m[1][0];
    if (m.size() == 3)
        return m[0][0] * m[1][1] * m[2][2] +
               m[0][1] * m[1][2] * m[2][0] +
               m[0][2] * m[1][0] * m[2][1] -
               m[2][0] * m[1][1] * m[0][2] -
               m[1][0] * m[0][1] * m[2][2] -
               m[0][0] * m[2][1] * m[1][2];

    else{
        double det = 0;
        for (int j = 0; j < m.size(); ++j) {
            std::vector<std::vector<double>> m_i_j =
                    getUnderMartix(m, 0, j);

            det += (m[0][j] * computeDet(m_i_j) * pow(-1, j));
        }

        return det;
    }
}

std::vector<std::vector<double>> reverseMatrix(
const std::vector<std::vector<double>>& m){
    std::vector<std::vector<double>> result(m.size(),
                std::vector<double> (m.size())); //создание вектора 3x3

    double det = computeDet(m);

    if(det == 0)
        exit(1);

    for (int j = 0; j < m.size(); ++j) {
        for (int i = 0; i < m.size(); ++i) {
            result[i][j] = computeDet(getUnderMartix(m, j, i));
            result[i][j] *= pow(-1, i + j);
            result[i][j] /= det;
        }
    }

    return result;
}

void changeCS(Triangle& t1, std::vector<double> deltaArr){
    for (Point& point: t1.ABC) {
        int i = 0;
        for(double& coordinate: point.xyz) {
            coordinate -= deltaArr[i];
            i++;
        }
    }
}

std::vector<std::vector<double>> matrixPhi(
    const Triangle& t){
    std::vector<std::vector<double>> result =
            std::vector<std::vector<double>> (3, std::vector<double>(3));

    result[0][1] = t.ABC[0].xyz[1];
    for (int j = 0; j < 2; ++j) {
        for (int i = 0; i < 3; ++i) {
            result[i][j] = t.ABC[j + 1].xyz[i];
        }
    }

    result[0][2] = t.ABC[1].xyz[1] * t.ABC[2].xyz[2] - t.ABC[2].xyz[1] * t.ABC[1].xyz[2];
    result[1][2] = t.ABC[1].xyz[2] * t.ABC[2].xyz[0] - t.ABC[2].xyz[2] * t.ABC[1].xyz[0];
    result[2][2] = t.ABC[1].xyz[0] * t.ABC[2].xyz[1] - t.ABC[2].xyz[0] * t.ABC[1].xyz[1];
    /*int i = 0;   //цикл найдет такую третью колонку m, чтобы |m| != 0
    while (computeDet(result) == 0){
        result[1][2] = i;
        result[2][2] = i + 2;
        i++;
    }*/


    return result;
}

bool areCross(const Triangle& t1, const Triangle& t2){
    Triangle mod_t1(t1);
    Triangle mod_t2(t2);

    std::vector<double> deltaArr = t1.ABC[0].xyz;
    changeCS(mod_t1, deltaArr);
    changeCS(mod_t2, deltaArr);
        // подбираем матрицу преобразования, чтобы стороны AB и AC первого
        // треугольника равнялись 1 и были параллельны осям:
    std::vector<std::vector<double>> m =
        reverseMatrix(matrixPhi(t1));

    for (Point& p: mod_t1.ABC) {
        p = m * p;
    }

    for (Point& p: mod_t2.ABC) {
        p = m * p;
    }

    std::cout << mod_t1 << std::endl;
    std::cout << mod_t2 << std::endl;

    return true;
}

int main() {
    //std::cout << "Hello, World!" << std::endl;
    /*Triangle t;
    //std::cout << "Tringle is: " << t <<std::endl;

    std::vector<std::vector<double>> m1 = {{1, 4, 4, 4},
                                          {1, 6, 7, 8},
                                          {1, 5, 9, 10},
                                          {1, 2, 2, 2}};


    std::vector<std::vector<double>> m2 = {{-1, 2, 3},
                                           {2, -1, -2},
                                           {-2, 5, 4}};

    printMatrix(m2);
    std::cout << "Det = " << computeDet(m2) << std::endl;

    std::vector<std::vector<double>> revers = reverseMatrix(m2);
    printMatrix(revers); */
    /*{
        Triangle t1, t2;
        std::cin >> t1 >> t2;
        Triangle mod_t1(t1);
        Triangle mod_t2(t2);

        std::vector<double> deltaArr = t1.ABC[0].xyz;
        changeCS(mod_t1, deltaArr);
        changeCS(mod_t2, deltaArr);

        std::cout << "mod_t1: " << mod_t1 << std::endl <<
                  "mod_t2: " << mod_t2;
    } */
    /*
    {
        std::vector<std::vector<double>> m = matrixPhi({0, 0, 0, 1, 2, 3, 4, 5, 6});
        printMatrix(m);

        Point p = {{10, 20, 30}};
        p = m * p;
        std::cout << "Point: ";
        for (int i = 0; i < 3; ++i) {
            std::cout << p.xyz[i] << ' ';
        }
        std::cout << std::endl;
    } */

    areCross({0, 0, 0, 1, 0, 0, 0, 1, 0},
             {12, 13, 14, 15, 16, 17, 18, 19, 11});
    return 0;
}
