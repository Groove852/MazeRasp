#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

const double pi = 3.14159265358979323846;

//метод для перевода из строкового в целочисленный тип данных
string to_string(int n[])
{
    ostringstream ss;
    ss << n;
    return ss.str();
}

//Регулятор
int PID(int spdL, int spdR, float err, float Kp, float Ki, float Kd, vector<float> sensorsValue, int timerValue) 
{
    return 0;
}

//Координаты конца вектора
vector<float> coordEndVector(float length, int angleAndIndex) 
{
    vector<float> coord;
    float x = length * cos((angleAndIndex * pi) / 180);
    float y = length * sin((angleAndIndex * pi) / 180);
    coord.push_back(x);
    coord.push_back(y);
    return coord;//yVector; 
}

//расчёт вхождения точек в чанки
bool comparison() 
{
    return 0;
}

//структура каждой точки с информацией о ней же
struct point 
{
    float spacing;
    int coordinates[2];
    int index;
};

//структура одного чанка
class Chank {
private:
    static const unsigned int Vertex = 4;
    static const unsigned int Coordinates = 2;
public:
    //если хочешь узнать что это, то напиши, я тебе статейку скину
    Chank() {
    }
    Chank(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
        vertexes[0][0] = x1; //{x1, y1}
        vertexes[0][1] = y1; //{x1, y1}

        vertexes[1][0] = x2; //{x2, y2}
        vertexes[1][1] = y2; //{x2, y2}

        vertexes[2][0] = x3; //{x3, y3}
        vertexes[2][1] = y3; //{x3, y3}

        vertexes[3][0] = x4; //{x4, y4}
        vertexes[3][1] = y4; //{x4, y4}
    }

    int vertexes[Vertex][Coordinates]; //координаты вершины каждого квадрата(чанка)
    int numberOfPoints; //колличество точек входящих в чанк
    point arrayOfPoints[100];
    float cardinalDirections[4];//длина по каждой из 4 сторон света, где Север соответствует 
    float error; //ошибка, вычисляемая в чанке

    string niceVertexes = "[ ";// найс вертексы

    //расчёт ошибки
    void computation() {

    }

    string showVertexes() {
        for (int i = 0; i < 4; i++) {
            niceVertexes += "[";
            for (int j = 0; j < 2; j++) {
                niceVertexes += to_string(vertexes[i][j]) + ", ";
            }
            niceVertexes += "] ";
        }
        niceVertexes += "]";
        return niceVertexes;
    }
};



const int numberOfChanks = 16;
const int numberOfInternalChanks = 4;
const int numberOfCornerChanks = 4;
const int numberOfDirectionChanks = 8;

Chank internalArrayMap[numberOfInternalChanks];//массив внешних чанков (0, 1, 2, 3 согласно рисунку на флипчарте)
Chank cornerArrayMap[numberOfCornerChanks];//массив чанков, которые операются на углы (6, 9, 12, 15 согласно рисунку на флипчарте)
Chank directionArrayMap[numberOfDirectionChanks];//массив чанков, которые операются на стороны(4, 5, 7, 8, 10, 11, 13, 14 согласно рисунку на флипчарте)

//константы для определенния коэффициентов координат точек массивов
const int firstQuarter[2] = { 1, 1 };
const int secondQuarter[2] = { -1, 1 };
const int thirdQuarter[2] = { -1, -1 };
const int fourthQuarter[2] = { 1, -1 };
float lenght; 
int angle;

int main()
{
    //ros::ok()
    while (true) {
        unsigned int startTime = clock();
        for (int i = 0; i < numberOfChanks; i++)
        {

        }
        cin >> lenght;
        cin >> angle;
        cout << coordEndVector(lenght, angle)[0] << "  ";
        cout << coordEndVector(lenght, angle)[1] << endl;
        float endTime = clock();
        float timer = endTime - startTime;
        cout << timer << endl;
    }

}