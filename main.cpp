#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
const int NUM_SORT = 4;
const int MAX_LIST_SIZE = 1000000;
using namespace std;
vector<int> createList(int);
void showList(vector<int>&);
void measureTime(int, int);
void insertionSort(vector<int>&, int);
void bubbleSort(vector<int>&, int);
void quickSort(vector<int>&, int, int);
void mergeSort(vector<int>&, int, int);
void mergeSort_merge(vector<int>&, int, int, int);

int main(){
    srand(time(0));
    for (long int i=10; i<MAX_LIST_SIZE; i=i*10){
        for (int j=1; j<NUM_SORT; j++){
            measureTime(i,j);
        }
        cout << "+++++++++++++++++++++++++++++++++++\n";
    }
    return 0;
}
vector<int> createList(const int sizeOfVect){
    cout << "Creating list with " <<sizeOfVect << " elements" <<endl;
    vector<int> newVector(sizeOfVect);
    for(int i=0; i!=sizeOfVect; i++){
        newVector[i]= (rand()%10000000);
        //cout << newVector[i]<< endl;
    }
    return newVector;
}
void showList(const vector<int>& vect){
    cout <<"Showing list"<<endl;
    for(unsigned int i = 0; i<vect.size(); i++){
        cout<< vect[i]<< endl;
    }
}
void measureTime(const int n, const int selection){
    vector<int> v = createList(n);
    if (selection==1)       cout << "\tInsertion Sort with " << n << " elements: ";
    else if (selection==2)  cout << "\tBubble Sort with    "<< n << " elements: ";
    else                    cout << "\tQuick Sort with     " << n << " elements: ";

    clock_t begin = clock();
    if (selection==1)
        insertionSort(v,n);
    else if (selection==2)
        bubbleSort(v,n);
    else
        quickSort(v, 0, n-1);


    clock_t end = clock();
    double elapsed_secs = double(end-begin)/CLOCKS_PER_SEC;
    cout <<"\tElapsed time:" << elapsed_secs <<endl;
}
void insertionSort(vector<int>& v, const int n){
    int i, k, add;
    for (i=1; i<n; i++){
        add=v[i];
        for (k=i-1; k>=0 && add<v[k]; k--){
            v[k+1] = v[k];
        }
        v[k+1]=add;
    }
    //showList(v);
}
void bubbleSort(vector<int>& v, const int n){
    int temp;
    for(int i=0; i<n-1; i++){
        for (int k=0; k<n-1-i; k++){
            if(v[k]>v[k+1]){
                temp = v[k];
                v[k]=v[k+1];
                v[k+1]=temp;
            }
        }
    }
    //showList(v);
}
void quickSort(vector<int>& v,const int low, const int high){
    int pivot,j,temp,i;
    if(low<high){
            pivot = low;
            i = low;
            j = high;
            while(i<j){
                    while((v[i]<=v[pivot])&&(i<high)){
                        i++;
                    }while(v[j]>v[pivot]){
                        j--;
                    }
                    if(i<j){
                        temp=v[i];
                        v[i]=v[j];
                        v[j]=temp;
                    }
            }
            temp=v[pivot];
            v[pivot]=v[j];
            v[j]=temp;
            quickSort(v,low,j-1);
            quickSort(v,j+1,high);
    }
}
