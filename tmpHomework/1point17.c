#include <stdio.h>
FILE * getFile() {
	FILE * fp;
	if ((fp=fopen("test","w"))==NULL) {
		printf("File cannot be opened");
	}
}

int main()
{
	;
	return 0;
}
