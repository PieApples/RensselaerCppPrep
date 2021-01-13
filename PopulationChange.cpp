#include <iostream>
#include <tuple>
#include <math.h>
#include <algorithm>
using namespace std;

int tourists(int bears){
	int tourists = 0;
	if(bears <= 4 or bears >= 15){

		return tourists;
	}
	else{
		int multiplier;
		
		for (int i=1; i<=bears; i++){
			
			if(i<=10){
				multiplier = 10000;
			}
			else if(i>10){
				multiplier = 20000;
			}

			tourists+=multiplier;
		}

		return tourists;
	}
}

tuple<int, float> find_next(int bears, float berries){
	int bears_next = berries/(50*(bears+1)) + bears*0.60 - (log(1+tourists(bears))*0.1);
	float berries_next = (berries*1.5) - (bears+1)*(berries/14.0) - (float(log(1+tourists(bears)))*.05);

	bears_next = max(0, bears_next);
	berries_next = max(float(0), berries_next);

	cout << bears_next;
	cout << "\n" << berries_next << "\n";

	return make_tuple(bears_next, berries_next);
}

int main(){

	cout << "Number of bears => ";

	int bears;
	cin >> bears;

	cout << "Size of berry area => ";

	float berries;
	cin >> berries;

	cout << tourists(bears);

	int val1;
	float val2;

	tie(val1,val2) = find_next(5, 10);

	cout << "\n" << val1 << "\n" << val2;
	
}
