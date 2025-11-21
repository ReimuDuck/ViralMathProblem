#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>
#define SOLUTION 66

using namespace std;
double j=0;// variable initilized at 0
void input(void);
void arrayInitilizer(double *arr);
void arraySolver(double *arr, double *stuff);

int main(){
// x+13*y/z+g+12*l-s-11+b*u/k-10=66 problem to be solved
    srand(time(NULL));
    double stuff[9]; //array handling the movement of numbers that have been used
    double arr[9]; //array containing numbers 1-9
    input();
    arrayInitilizer(arr);
    arraySolver(arr, stuff); 
    cout << "Done! ";
    //lists out the entries

    return 0;
}
void input(void){
    cout << "Welcome to my janky #viral math problem solver. " << endl;
    cout << "Due to my lack of knowledge and lack of care this does not loop through all possible solutions and must be ran multiple times. "<< endl;
    cout << "For current purposes this is okay, but a total rework is needed. " << endl;
    return;
}
void arrayInitilizer(double *arr){
    //this initilizes each entry in the array as well as resets when a solution is not found
    for(int i = 0; i <= 8; i++){
        double j = double(i);
        arr[i] = j+1.0;
        //cout << arr[i] << endl;
    }

    return;
}
void arraySolver(double *arr, double *stuff){

    int ran;// interger used to contain a random number from 1-9
    cout << "Calculating...";
    while(j != SOLUTION){
        
        //loops through each array entry
        //giving each entry in "stuff" a random number from "arr"
        for(int i = 0; i < 9; i++ ){      
            ran = rand() % 9;
            while(arr[ran]== 1234.0){
                //1234.0 is an "empty" array, it allows the program to know what entries to skip
                ran = rand() % (9);
            }            
            stuff[i] = arr[ran];
            arr[ran]=1234.0;         
        }
        //calculation
        j = stuff[0] + 13.0*stuff[1] / stuff[2]+ stuff[3]+12.0*stuff[4]-stuff[5]-11.0+stuff[6]*stuff[7]/stuff[8]-10.0;
        //resets array if not found
        arrayInitilizer(arr);
    }
        cout <<endl << "Possible solution: " <<"{";
    for(int i = 0; i < 9; i++ ){
        cout<<" " << stuff[i]<< " ";
    }
    cout << "}" << endl;
    // simply to show the equation in a neat format
    cout <<"Answer: "<< stuff[0] <<"+"<< 13.0<<"*"<<stuff[1] <<"/"<< stuff[2]<<"+"<<stuff[3]<<"+"<<12.0<<"*"<<stuff[4]<<"-"<<stuff[5]<<"-"<<11.0<<"+"<<stuff[6]<<"*"<<stuff[7]<<"/"<<stuff[8]<<"-"<<10.0 << "= " << j <<endl;

}
