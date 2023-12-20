#include <stdio.h>
#include <math.h>
typedef int bool ;
#define EPS 1e-4
#define MAX_ULP 1 

bool cmp1(float x,float y);
bool cmp2(float x,float y);
bool cmp3(float x,float y);
bool cmp4(float x,float y);


int main(){

	float x = 16777216.99999;
	float y = 16777217.00001;
	printf("%d\n",cmp1(x,y));
	printf("%d\n",cmp2(x,y));
	printf("%d\n",cmp3(x,y));
	printf("%d\n",cmp4(x,y));

	return 0;
}
bool cmp1(float x, float y) {
return (x == y);
}


bool cmp2(float x, float y) {
return (fabs(x-y) < EPS);
}


bool cmp3(float x, float y) {
float diff = fabs(x-y);
x = fabs(x); y = fabs(y);
float largest = (x > y?x:y);
return (diff/largest < EPS);
}


bool cmp4(float x, float y) {
int xi = *(int *)&x;
int yi = *(int *)&y;
return (fabs(xi-yi) <= MAX_ULP);
}