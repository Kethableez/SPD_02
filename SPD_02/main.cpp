#define FILENAME "data.txt"

#include "witi.h"

int main() {
	Data d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;

	Data Data_List[11] = { d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11 };
	std::string Data_number[11] = { "data.10:", "data.11:", "data.12:", "data.13:", "data.14:", "data.15:", "data.16:", "data.17:", "data.18:", "data.19:", "data.20:" };

	for (int i = 0; i < 11; i++) {
		Data_List[i].Add(FILENAME, Data_number[i]);
		Data_List[i].cokolwiek();
	}
}