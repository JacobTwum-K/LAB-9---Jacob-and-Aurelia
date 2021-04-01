/*
 * Jacob Twum-Koranteng - 05672023
 * Aurelia Anthony - 96742023
 * 
 * LAB 9
 * */

#include <iostream>
#include <stdlib.h>
using namespace std;

//creation and initialisation of 2-D array with fixed length, 101

/*
 * 
 * function populateArray(..., int N); that takes a parameter N,
 * indicating how random pairs of indices i,j times it should generate,
 * to update the entries the array A[][].
 * 
 * */
 
void populateArray(int A[101][101],int N){
	
	for(int h = 0;h <N; h++){
		
		int i = rand()%100;
		int j = rand()%100;
		
		if(A[i][j]==0){
			
			A[i][j]=1;
		}
		else{
			
			A[i][j]=A[i][j]++;
		}
	} 
}

/*
 * 
 * function searchValidEntries(int XL, int YL, int XH, int YH, ...);
 * that takes the values of the coordinates of the corners of the bounding box 
 * and reports the indices and counts of the entries in A[i][j] with positive count values
 * 
 * */
void searchValidEntries(int XL, int YL, int XH, int YH, int A[101][101]){
	for(int i = 0; i < 101; i++){
		
		for(int j = 0; j < 101; j++){
			
			if((j>=XL && j<=XH) && (i >= YL && i <= YH) && (A[i][j] !=0)){
				
				cout<< i << "," << " " << j << ";" << " " << A[i][j]  <<endl;
				}
			}
		}
}

/*
 * 
 * the main program that reads the values of 5 bounding boxes, one line at a time,
 * and report the indices
 * It then returns the counts of the entries in A[][] that lie within the bounding boxes
 * 
 * */
int main(){
	int A[101][101];
	
	for(int i = 0; i < 101; i++){
		
		for(int j = 0; j < 101; j++){
			
			A[i][j] = 0;
		}
	}
	
/*
 * 
 * function tests
 * 
 * */	
	populateArray(A, 2000); //2000 indices


	cout<<"Bounding Box 1:"<<endl;
	cout<<"XL = 80, YL = 1, XH = 100, YH = 10"<<endl;
	searchValidEntries(80,1,100,10,A);
	
	cout<<" "<<endl;
	cout<<"Bounding Box 2:"<<endl;
	cout<<"XL = 10, YL = 20, XH = 40, YH = 79"<<endl;
	searchValidEntries(10,20,40,79,A);
	
	cout<<" "<<endl;
	cout<<"Bounding Box 3:"<<endl;
	cout<<"XL = 1, YL = 90, XH = 100, YH = 100"<<endl;
	searchValidEntries(1,90,100,100,A);
	
	cout<<" "<<endl;
	cout<<"Bounding Box 4:"<<endl;
	cout<<"XL = 40, YL = 30, XH = 70, YH = 60"<<endl;
	searchValidEntries(40,30,70,60,A);
	
	cout<<" "<<endl;
	cout<<"Bounding Box 5:"<<endl;
	cout<<"XL = 50, YL = 50, XH = 70, YH = 70"<<endl;
	searchValidEntries(50,50,70,70,A);
	
	
}
