#include <iostream>
using namespace std;
#include <fstream>
#include<sstream>
#include <string>
#include <chrono>
using namespace std::chrono;
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int smallestIndex=i;
        for (int j=i+1;j<n;j++){
            if (arr[i]==arr[j]){
                continue;

            }
            if (arr[j]<arr[smallestIndex]){
                smallestIndex=j;
            }
        }
    swap(arr[i],arr[smallestIndex]);
    }
}

int main() {
    ifstream fin("numbers.txt");
    if (!fin){
        cout<<"error in opening ";
        return 0;
    }

    string line, token;
    getline(fin, line);
    fin.close();
    int count=1;
    for (char c:line){
        if (c==','){
            count++;
        }
    }

    int * arr=new int [count];
    int n=0;
    stringstream ss(line);
    while (getline(ss,token,',')){
        arr[n++]=stoi(token);
    }

 
     auto start=high_resolution_clock::now();
    selectionSort(arr, n);
    auto stop=high_resolution_clock::now();
    auto duration =duration_cast<milliseconds>(stop - start);
  

    

    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++)
        {cout << arr[i] << " ";}
    cout<<"time taken by bubble sort:"<<duration.count()<<"milli second";
      

    return 0;
}
