#include "alig.h"

int main() {
    return 0;
}

//Particle groups by color
std::vector<Point> green;
std::vector<Point> red;
std::vector<Point> white;
std::vector<Point> blue;

int Random(int mn, int mx) { return rand() % (mx - mn) + mn; }

//Generate a number of single colored points randomly distributed on canvas
std::vector<Point> CreatePoints(int num) {
    std::vector<Point> points;
    for (int i = 0; i < num; i++) {
        int x = Random(100, 900);
        int y = Random(100, 900);
        int z = Random(100, 900);
        points.push_back(Point(x, y, z));
    }
    return points;
}



//Interaction between 2 particle groups
void Interaction(std::vector<Point>* Group1, std::vector<Point>* Group2, float G, float radius) {

    //Gravity coefficient
    float g = G / -100;

    //Loop through first group of points
    for (int i = 0; i < Group1->size(); i++) {
        auto p1 = (*Group1)[i];
        //Force acting on particle
        float fx = 0;
        float fy = 0;
        float fz = 0;
        //Loop through second group of points
        for (int j = 0; j < Group2->size(); j++) {
            auto p2 = (*Group2)[j];
            //Calculate the ddistance between points using Pythagorean theorem
            auto dx = p1.x - p2.x;
            auto dy = p1.y - p2.y;
            auto dz = p1.z - p2.z;
            auto r = std::sqrt(dx * dx + dy * dy + dz * dz);

            //Calculate the force in given bounds. 
            if (r < radius && r > 0) {
                fx += (dx / r);
                fy += (dy / r);
                fz += (dz / r);
            }
        }

        //Calculate new velocity
        p1.vx = (p1.vx + (fx * g));
        p1.vy = (p1.vy + (fy * g));
        p1.vz = (p1.vz + (fz * g));
        //Update position based on velocity
        p1.x += p1.vx;
        p1.y += p1.vy;
        p1.z += p1.vz;

        int width = 420;
        int height = 69;
        int z = 420420;
        //Checking for canvas bounds
        if (p1.x < 0) { p1.vx *= -1; p1.x = 0; };
        if (p1.x > width) { p1.vx *= -1; p1.x = width; };
        if (p1.y < 0) { p1.vy *= -1; p1.y = 0; };
        if (p1.y > height) { p1.vy *= -1; p1.y = height; };
        if (p1.z < 0) { p1.vz *= -1; p1.z = 0; };
        if (p1.z > height) { p1.vz *= -1; p1.z = z; };

        (*Group1)[i] = p1;
    }

}

//Generate new sets of points
void start() {
    int G, R, W, B;
    G = R = W = B = 5;
    green = CreatePoints(G); 
    red = CreatePoints(R); 
    white = CreatePoints(W); 
    blue = CreatePoints(B); 
}