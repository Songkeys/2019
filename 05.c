#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run(int ops[], int input) {	
	int i = 0;
	while (1) {
		char op[6];
		sprintf(op, "%05d", ops[i]);
		if (op[3] == '9' && op[4] == '9') break;
		int a = op[2] == '0' ? ops[ops[i+1]] : ops[i+1];
		int b = op[1] == '0' ? ops[ops[i+2]] : ops[i+2];
		if (op[4] == '1') {
			ops[ops[i+3]] = a + b;
			i += 4;
		}
		if (op[4] == '2') {
			ops[ops[i+3]] = a * b;
			i += 4;
		}
		if (op[4] == '3') {
			ops[ops[i+1]] = 1;
			i += 2;
		}
		if (op[4] == '4') {
			printf("%d\n", a);
			i += 2;
		}
		if (op[4] == '5') {
			i = a != 0 ? b : i + 3;
		}
		if (op[4] == '6') {
			i = a == 0 ? b : i + 3;
		}
		if (op[4] == '7') {
			ops[ops[i+3]] = a < b ? 1 : 0;
			i += 4;
		}
		if (op[4] == '8') {
			ops[ops[i+3]] = a == b ? 1 : 0;
			i += 4;
		}
	}
}

int main(int argc, char const *argv[]) {
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	fp = fopen("./05.txt", "r");
	getline(&line, &len, fp);

	int n = 0;
	int ops[1000];

	char *pt;
	pt = strtok(line, ",");
	while (pt != NULL) {
		int a = atoi(pt);
		ops[n] = a;
		++n;
		pt = strtok(NULL, ",");
	}

	printf("---Part 1---\n");
	run(ops, 1);

	printf("---Part 2---\n");
	run(ops, 5);

	return 0;
}
