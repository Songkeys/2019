#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int run(int noun, int verb, vector<int> ops) {
	ops[1] = noun;
	ops[2] = verb;
	int i = 0;
	while (ops[i] != 99) {
		if (ops[i] == 1) ops[ops[i+3]] = ops[ops[i+1]] + ops[ops[i+2]];
		if (ops[i] == 2) ops[ops[i+3]] = ops[ops[i+1]] * ops[ops[i+2]];
		i += 4;
	}
	return ops[0];
}

int main(int argc, char const *argv[]) {
	ifstream infile ("./02.txt");
	string buf;
	vector<int> ops;
	if (infile.is_open()) {
		for (string ss; getline(infile, ss, ',');) {
			ops.push_back(stoi(ss));
		}
	}

	/* part 1 */
	cout << run(12, 2, ops) << endl;

	/* part 2 */
	for (int i = 0; i <= 99; ++i) {
		for (int j = 0; j <= 99; ++j) {
			if (run(i, j, ops) == 19690720) {
				cout << 100 * i + j << endl;
				return 0;
			} 
		}
	}
}