#include <iostream>
#include <math.h>
using namespace std;

struct twoDimensions{
    int x;
    int y;
};

struct threeDimensions{
    int x;
    int y;
    int z;
};

void afiseazaPunct(twoDimensions punct) {
    cout << "(" << punct.x << " , " << punct.y << ")\n";
}

void afiseazaPunct(threeDimensions punct) {
    cout << "(" << punct.x << " , " << punct.y << " , " << punct.z << ")\n";
}

double calcDist(twoDimensions punct, twoDimensions origin) {
    double y = origin.y - punct.y;
    double x = origin.x - punct.x;

    return sqrt(y*y + x*x);
}

double calcDist(threeDimensions punct, threeDimensions origin) {
    double y = origin.y - punct.y;
    double x = origin.x - punct.x;
    double z = origin.z - punct.z;


    return sqrt(y*y + x*x + z*z);
}

int main()
{
    struct twoDimensions p1 = {1,2}, p2 = {4,3};
    afiseazaPunct(p1);
    afiseazaPunct(p2);

    cout << "Distanta intre p1 si p2 = " << calcDist(p1,p2) << "\n";
    
    struct threeDimensions p3 = {1,2,3}, p4 = {4,3,0};
    afiseazaPunct(p3);
    afiseazaPunct(p4);

    cout << "Distanta intre p3 si p4 = " << calcDist(p3,p4) << "\n";

    return 0;
}