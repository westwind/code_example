#include <stdio.h>

int main() {
	int i=0, j=0;
	int target=9;

first:
	i=i+1;
	j=1;
	if (i>target) {
		goto end;
	}
second:
	if (j<=target){
		printf("%dx%d=%d\t",j, i, j*i);
		j++;
		goto second;
	} else {
		printf("\n");
		goto first;
	}
end:
	return;
}
