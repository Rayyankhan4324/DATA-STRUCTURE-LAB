#include <iostream>
using namespace std;
#include <fstream>
#include<sstream>
#include <string>
#include <chrono>
using namespace std::chrono;
void bubbleSort(int arr[], int n) {
    bool swapped;
    for(int i = 0; i < n - 1; i++) {
        swapped = false;
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
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

 
    // int n = sizeof(arr) / sizeof(arr[0]);
     auto start=high_resolution_clock::now();
     
    bubbleSort(arr, n);
    auto stop=high_resolution_clock::now();
    auto duration =duration_cast<milliseconds>(stop - start);
  

    

    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++)
        {cout << arr[i] << " ";}
    cout<<"time taken by bubble sort:"<<duration.count()<<"milli second";
      

    return 0;
}
