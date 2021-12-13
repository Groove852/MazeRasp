#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;

const double pi = 3.14159265358979323846;


int         lastPID                   = 0;
int         angle                     = 0; 

float       lastErr                   = 0;
float       lastLastErr               = 0;
float       lenght                    = 0;

const int   numberOfChanks            = 16;
const int   numberOfInternalChanks    = 4;
const int   numberOfCornerChanks      = 4;
const int   numberOfDirectionChanks   = 8;

const int   firstQuarter[2]           = {1,1};
const int   secondQuarter[2]          = {-1,1};
const int   thirdQuarter[2]           = {-1,-1};
const int   fourthQuarter[2]          = {1,-1};

// структура каждой точки с информацией о ней же 
// (IDK COMPLETE)
struct point
{
    float  spacing;
    int    coordinates[2];
    int    index;
};

// Регулятор 
// (COMPLETE, WAIT TESTING)
int PID(float err, float Kp, float Ki, float Kd, int timerValue) 
{   
    int PID;
    if (err == 0) {
        lastPID = 0;
        PID = 0;
    }
    PID          = lastPID + Kp * Ki * err + Kp * (err - lastErr) + ((Kp * Kd) / timerValue) * (err - 2 * lastErr + lastLastErr);
    lastPID      = PID;
    lastLastErr  = lastErr;
    lastErr      = err;
    return PID;
}

// Координаты конца вектора 
// (COMPLETE, WAIT TESTING)
vector<float> coordEndVector(float length, int angleAndIndex) 
{
    vector<float> coord;
    float x = length * cos((angleAndIndex * pi) / 180);
    float y = length * sin((angleAndIndex * pi) / 180);
    coord.push_back(x);
    coord.push_back(y);
    return coord;//yVector; 
}

// расчёт вхождения точек в чанки 
// (UNCOMPLETE)
bool comparison() 
{
    return 0;
}

// структура одного сабчанка
// (UNCOMPLETE)
class Subchank {
private:

    static const unsigned int Vertex = 4;
    static const unsigned int Coordinates = 2;
    int vertexes[Vertex][Coordinates]; //координаты вершины каждого квадрата(чанка)
    int numberOfPoints; //колличество точек входящих в чанк

public:
    Subchank() {
    }
    Subchank(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
        vertexes[0][0] = x1; //x1,
        vertexes[0][1] = y1; //y1

        vertexes[1][0] = x2; //x2
        vertexes[1][1] = y2; //y2

        vertexes[2][0] = x3; //x3
        vertexes[2][1] = y3; //y3

        vertexes[3][0] = x4; //x4
        vertexes[3][1] = y4; //y4
    }

};

// структура одного чанка 
// (UNCOMPLETE)
class Chank {
private:

    static const unsigned int Vertex = 4;
    static const unsigned int Coordinates = 2;
    int vertexes[Vertex][Coordinates]; //координаты вершины каждого квадрата(чанка)
    int numberOfPoints; //колличество точек входящих в чанк
    string niceVertexes = "[ ";// найс вертексы

    //метод для перевода из строкового в целочисленный тип данных 
    //(COMPLETE)
    string to_string(int n[])
    {
        ostringstream ss;
        ss << n;
        return ss.str();
    }

public:

    Chank() {
    }
    Chank(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
        vertexes[0][0] = x1; //x1,
        vertexes[0][1] = y1; //y1

        vertexes[1][0] = x2; //x2
        vertexes[1][1] = y2; //y2

        vertexes[2][0] = x3; //x3
        vertexes[2][1] = y3; //y3

        vertexes[3][0] = x4; //x4
        vertexes[3][1] = y4; //y4
    }

    //получение ошибки из сабчанков
    //(UNCOMPLETE)
    void getComputation(int SubchankIndex) {

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

    //запуск вычислений в чанке
    //(UNCOMPLETE)
    void run(float sensorValues[360]) {
        getComputation(0);
        getComputation(1);
        getComputation(2);
        getComputation(3);
        showVertexes();
        for (int i = 0; i < 360; i++) {
            comparison(sensorValues[i]);
        }
    }

};

//чанки по четвертям
Chank firstChank;
Chank secondChank;
Chank thirdChank;
Chank fourthChank;

double scan_callback(const sensor_msgs::LaserScan::ConstPtr& msg) {
    return msg->ranges;
}

vector<int> scan_callback(const sensor_msgs::LaserScan::ConstPtr& msg) {
    vector<int> valuesFromOpenCR;
    valuesFromOpenCR.push_back(msg->spdL);
    valuesFromOpenCR.push_back(msg->spdR);
    valuesFromOpenCR.push_back(msg->temp);
    return valuesFromOpenCR;
}

int main()
{
    float error;
    //ros::ok()
    while (true) {
        unsigned int startTime = clock();
        /*
        firstChank.run();
        secondChank.run();
        thirdChank.run();
        fourthChank.run();
        */


        PID(error, 1, 1, 1, startTime);

        float endTime = clock();
        float timer = endTime - startTime;
        cout << timer << endl;
        startTime = 0;
        endTime = 0;
    }
}