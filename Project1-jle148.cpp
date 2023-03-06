//main.cpp
#include "bc.h"
#include "fc.h"
#include <iostream>

using namespace std;

int main(){
    string problem;
    string solution;

    cout << "Starting backwards chaining code....\n" << endl;

    bc backwards;
    problem.assign(backwards.start());

    cout << "Done with backwards chaining, your problem is : \n" << problem << endl;
    if (problem !="NO ISSUE"){
        cout << "Starting forwards chaining code....\n" << endl ;

        fc forwards(problem);
        solution.assign(forwards.start());

        cout << "To fix you need to replace " << problem << endl;
    }
    else{
        cout << "Your car is fine "<< endl;
    }
}
