#include "Sort Algorithms.h"

const int size = 1000;
std::vector<int> vector(size);

bool do_insertion_1000_times() {
	for (int i = 0; i < size; i++) {
		vector[i] = i % 10;
	}
	insertion_sort<int>(vector);
	return true;
}

int main()
{
	Chronometer<bool> timer(do_insertion_1000_times);
	timer.run();
	std::cout << "ns: " << timer.getDurationInNanoseconds() << "\n";
	std::cout << "us: " << timer.getDurationInMicroseconds() << "\n";
	std::cout << "ms: " << timer.getDurationInMilliseconds() << "\n";
	std::cout << "sec: " << timer.getDurationInSeconds() << "\n";
	system("PAUSE");
}

