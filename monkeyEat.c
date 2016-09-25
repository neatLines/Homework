#include <stdio.h>
// int main(int argc, char const *argv[])
// {
// 	int peal[11] = {0};
// 	peal[0] = 1;
// 	for (int i = 0; i < 10; ++i) {
// 		peal[i+1] = (peal[i] + 1)*2;
// 		// printf("%d\n", peal[i]);
// 	}
// 	printf("%d\n", peal[9]);
// 	return 0;
// }


// typedef struct LPeal {
//     int pealsNumber;
//     struct LPeal *next;
// } LPeal ,*LPeallist;

// int main(int argc, char const *argv[])
// {
//     LPeallist lPeallist = (LPeallist) malloc(sizeof(LPeal));
//     lPeallist->next = NULL;
//     lPeallist->pealsNumber = 1;
//     for (int i = 0; i < 9; ++i) {
//         lPeallist->next = (LPeallist) malloc(sizeof(LPeal));
//         lPeallist->next->pealsNumber = 2*(lPeallist->pealsNumber+1);
//         lPeallist = lPeallist->next;
//     }
//     printf("%d\n", lPeallist->pealsNumber);
//     return 0;
// }


// int oneday(int pealsNumber,int count) {
// 	pealsNumber++;
// 	pealsNumber*=2;
// 	count--;
// 	if (count) {
// 		return oneday(pealsNumber,count);
// 	} else {
// 		return pealsNumber;
// 	}
// }
// int main(int argc, char const *argv[]) {
// 	// int pealsNumber = 1;
// 	printf("%d\n", oneday(1,9));
// 	return 0;
// }


// int main(int argc, char const *argv[])
// {
// 	int peal = 1;
// 	int n = 3;
// 	for (int i = 0; i < 9; ++i) {
// 		peal += n;
// 		n*=2;
// 	}
// 	printf("%d\n", peal);
// 	return 0;
// }
