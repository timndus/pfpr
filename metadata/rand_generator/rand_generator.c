
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	double low, high;
	int count;
	cout << "Enter low: ";
	cin >> low ;
	
	cout << "Enter high: ";
	cin >> high;

	cout << "Enter count: ";
	cin >> count;

	int i = 0;
	srand(time(NULL));
	while(i++ < count) {
		float r = low + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(high-low)));
		cout << r << "\n";
	}
	return 0;
}
