#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void randData(double *,int,int);

void findColSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,result,N,M); 
	showData(result,1,M);
}

//Write definition of randData(), showData() and findColSum()
void randData(double *dPtr,int N,int M){
	for(int i=0;i<(N*M);i++){
		*(dPtr+i) = (rand()%101)/100.00;

	}
}

void findColSum(const double *dPtr,double *result,int N,int M){
	double sum=0;
	for(int i=0;i<M;i++){
		sum=0;
		for(int j=0;j<N;j++){
			sum += *(dPtr+i+j*M);
		}
		*(result+i) = sum;
	}
}




void showData(double *dPtr,int N,int M){
	for(int i=0;i<(N*M);i++){
		if(i%7==0) cout<<endl;
		cout<<*(dPtr+i)<<"  ";
	}
	cout<<endl;
}

