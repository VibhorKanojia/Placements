#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define FLT_MAX 10000000

struct point {
	int x;
	int y;
};


float findDistance(point a, point b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

float findMin(float a, float b){
	return a >= b ? b : a;
}


int compareX(const void* a, const void* b){
	point * p1 = (point *)a;
	point * p2 = (point *)b;
	return (p1->x - p2->x);
}

int compareY(const void* a, const void* b){
	point * p1 = (point *)a;
	point * p2 = (point *)b;
	return (p1->y - p2->y);
}


float bruteForce(point array[] , int N){
	float mymin = FLT_MAX;
	for (int i = 0 ; i < N ; i++){
		for (int j = i+1 ; j < N ; j++){
			if (findDistance(array[i], array[j]) < mymin){
				mymin = findDistance(array[i], array[j]);
			}
		}
	}
	return mymin;
}


float shortestStrip(point strip[], int size, float dist){
	float min_dist = dist;
	for (int i = 0 ; i < size ; i++){
		for (int j = i+1 ; j < size && (strip[j].y - strip[i].y) < min_dist ; j++){
			if (findDistance(strip[j], strip[i]) < min_dist ){
				min_dist = findDistance(strip[j], strip[i]);
			}
		} 
	}
	return min_dist;
}

float findShortest(point arrayX[], point arrayY[], int N){
	if (N <= 3){
		return bruteForce(arrayX, N);
	}

	point pivot = arrayX[N/2];

	int midpoint = N/2;
	point arrayLeft[midpoint];
	point arrayRight[N- midpoint];
	int L_index =0;
	int R_index =0;

	for (int i =0 ; i < N ; i++){
		if (arrayY[i].x < pivot.x){
			arrayLeft[L_index] = arrayY[i];
			L_index++;
		}
		else{
			arrayRight[R_index] = arrayY[i];
			R_index++;
		}
	}

	float d1 = findShortest( arrayX , arrayLeft , midpoint);
	float d2 = findShortest( arrayX , arrayRight , N-midpoint);

	float d = findMin(d1,d2);

	point strip[N];
	int count = 0;

	for (int i = 0 ; i < N ; i++){
		if (abs(arrayY[i].x - pivot.x) < d){
			strip[count]=arrayY[i];
			count++;
		}
	}

	return findMin(d, shortestStrip(strip, count , d));

}




int main(){
	int N;
	cin >> N;
	point array[N];
	point arrayX[N];
	point arrayY[N];
	for (int i =0 ; i < N ; i++){
		cin>>array[i].x;
		cin>>array[i].y;
		arrayX[i]=array[i];
		arrayY[i]=array[i];
	}

	qsort(arrayX, N, sizeof(point), compareX);
	qsort(arrayY, N, sizeof(point), compareY);

	float short_dist = findShortest(arrayX,arrayY, N);
	cout<<short_dist<<endl;
	return 0;
}





