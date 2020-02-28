#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[N] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,result,N,M);
	showData(result,N,1);
}

//Write definition of randData(), showData() and findRowSum()


void randData(double *dPtr,int N,int M){
	for(int i=0;i<(N*M);i++){
		*(dPtr+i) = (rand()%101)/100.00;

	}
}

void findRowSum(const double *dPtr,double *result,int N,int M){
	double sum=0;
	for(int i=1;i<=(N*M);i++){
		sum += *dPtr;
		if(i%7==0){
			*result = sum;
			sum = 0;
			result++;
		}
		dPtr++;
	}
}




void showData(double *dPtr,int N,int M){
	for(int i=0;i<(N*M);i++){
		if(i%7==0) cout<<endl;
		cout<<*(dPtr+i)<<"  ";
	}
	cout<<endl;
}

