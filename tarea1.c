#include <stdio.h>
#include <math.h>
int main(int argc, char* argv[]){
	double pi=0;
	double suma=0;
	int s=1;
	for(int i=1; i<65533; i+=2) {
		suma=(((double)s)/((double)i));
		pi= pi + suma;
		s=s*(-1);
	}
	pi=4*pi;
	printf("%.64lf", pi);
	return 0;
}