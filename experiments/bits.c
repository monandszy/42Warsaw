#include <stdio.h>

int main(int argc, char **argv) {
	if (argc != 2)
		return (printf("Invalid Input"), 1);
	char *strnum = argv[1];

	for (int i = 0; strnum[i]; i++) {
		int cursor = 1;
		int target = strnum[i];
		for(int j = 0; j < 8; j++) {
			int d = cursor & target;
			if (d > 0)
				printf("1");
			else
				printf("0");
			cursor = cursor << 1;			
		}
		printf("\n");
	}
}
