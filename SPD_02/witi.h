#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Data{
	int len;
	std::vector<int> P;
	std::vector<int> W;
	std::vector<int> D;

	void Add(std::string Filename, std::string data_number) {
		std::string line, l1, l2, l3;

		std::ifstream File(Filename);

		while (line != data_number) File >> line;

		File >> len;

		for (int i = 0; i < len; i++) {
			File >> l1 >> l2 >> l3;
			P.push_back(std::stoi(l1));
			W.push_back(std::stoi(l2));
			D.push_back(std::stoi(l3));
		}

		File.close();
	}

	void Show() {
		for (int i = 0; i < len; i++) {
			std::cout << P[i] << " " << W[i] << " " << D[i] << "\n";
		}
	}

	void cokolwiek() {
		int N = 1 << len, * F = new int[N];
		F[0] = 0;

		for (int set = 1; set < N; set++) {
			int c = 0;
			for (int i = 0, b = 1; i < len; i++, b *= 2) if (set & b) c += P[i];

			F[set] = 999999999;

			for (int k = 0, b = 1; k < len; k++, b *= 2) if (set & b) {
				F[set] = std::min(F[set], F[set - b] + W[k] * std::max(c - D[k], 0));
			}
		}
		std::cout << "Minimalna kara: " << F[N - 1] << std::endl;
		delete[] F;
	}
};