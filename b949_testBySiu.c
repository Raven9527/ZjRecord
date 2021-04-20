#include <stdio.h>
#include <string.h>
#define MAX 107
#define MAXULL 18446744073709551615
#define MAXU25 737869762948382064
#define MAXINT 858993459
typedef unsigned long long ull;
char a[MAX + MAX], b[MAX + MAX], c[MAX + MAX];
int answer[MAX + MAX + 12];

void bigMul(int, int);

int main () {
	int a_len, b_len, k;
	ull num;
	
	char op;
	while(scanf("%s", &a) != EOF) {
		
		num = 0;
		for(k = 0; a[k]; k++) {
			num = ((ull)num * (ull)10) + (ull)(a[k] - 48);
		}
		
		if(num <= MAXINT) {
			printf("%llu\n", (ull)num * (ull)num * (ull)25);
			continue;
		}
		
		strcpy(b, a);
		a_len = strlen(a);
		b_len = strlen(b);
		bigMul(a_len, b_len);
		
		strcpy(a, c);
		strcpy(b, "25");
		a_len = strlen(a);
		b_len = strlen(b);
		bigMul(a_len, b_len);
		
		printf("%s\n", c);
	}
	return 0;
}
void bigMul(int a_len, int b_len) {
	
	int k, j, tmp, ansk, cc, flag;
	
	memset(answer, 0, sizeof(answer));
	cc = 0;
	for(j = (b_len - 1); j >= 0; j--, cc++) {
		ansk = cc;
		for(k = (a_len - 1); k >= 0; k--, ansk++) {
			answer[ansk] += (a[k] - 48) * (b[j] - 48);
		}
	}
	
	for(k = 0; k < ansk; k++) {
		answer[k + 1] += answer[k] / 10;
		answer[k] %= 10;
	}
	if(answer[k + 1] != 0) {
		tmp = answer[k + 1] / 10;
		answer[k + 1] %= 10;
		answer[k + 2] = tmp;
	}
	k += 5;
	
	for(ansk = (k - 1); ansk >= 0; ansk--) {
		if(answer[ansk] != 0)
			break;
		
	}
	
	for(k = 0; ansk >= 0; ansk--, k++) {
		c[k] = answer[ansk] + 48;
	}
	c[k] = 0;
	
	return;
}