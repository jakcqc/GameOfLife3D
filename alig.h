#include <vector>
#include <cmath>

struct Point {
	//Position
	float x = 0;
	float y = 0;
	float z = 0;

	//Velocity
	float vx = 0;
	float vy = 0;
	float vz = 0;


	Point(float _x, float _y, float _z) {
		x = _x;
		y = _y;
		z = _z;
	}
};