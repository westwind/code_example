#include <stdio.h>

int main() {
	int i=1;
	int result = 0;
	int target =100;

start:
	if (i<=target) {
		result = result +i;
		i++;
		goto start;
	} else {
		goto end;
	}
end:
	printf("1+%d=%d\n", target, result);
}
