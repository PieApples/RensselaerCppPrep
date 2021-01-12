
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

float find_volume_sphere(float radius){

	float volume = ((4.0/3.0) * M_PI * pow(radius, 3));
	return volume;
}

float find_volume_cube(float side){

	float vol = pow(side, 3);
	return vol;
}

float gumballs(float sales){

	float gumballs = sales*1.25;
	return gumballs;
}

float sideBalls(float gumballs){

	float sideBalls = ceil(pow(gumballs, (1.0/3.0)));
	return sideBalls;
}


int main() {

	float radius;
	cout << "Enter the gum ball radius (in.) => ";
	cin >> radius;

	float sales;
	cout << "\n" << "Enter the weekly sales => ";
	cin >> sales;

	cout << "The machine needs to hold " << sideBalls(gumballs(sales)) << " gum balls along each edge.";
	cout << "\n" << "Total edge length is " << fixed << setprecision(2) << (radius*2)*sideBalls(gumballs(sales)) << " inches.";
	cout << "\n" << "Target sales were " << fixed << setprecision(0) << ceil(gumballs(sales)) << ", but the machine will hold " << pow((radius*2)*sideBalls(gumballs(sales)), 3)-ceil(gumballs(sales)) << " extra gum balls.";
	cout << "Wasted space is " << fixed << setprecision(2) <<   find_volume_cube((radius*2)*sideBalls(gumballs(sales))) - pow(find_volume_sphere(radius)*sideBalls(gumballs(sales)), 3);
	cout << "\n" << find_volume_cube(2.0);
}