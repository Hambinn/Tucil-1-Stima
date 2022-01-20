#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string line1[7];
    string line2[7][8];
    string delimiter = " ";
    ifstream myfile("file.txt");
    int a = 0;
    int b = 0;
    if(!myfile){
        cout << "Error opening output file" << endl;
        system("pause");
        return -1;
    }

    for(int i = 0; i<7;i++){
        getline(myfile, line1[i], '\n');
        cout<< line1[i] << "\n";
    }

    for(int i = 0; i<7;i++){
        a = 0;
        for(int j = 0;j<15;j++){
            if(line1[i][j] != ' '){
                // cout << line1[i][j];
                line2[i][a] = line1[i][j];
                cout << line2[i][a];
                a++;
            }
            
        }
        cout << "\n";
    }




    
    
    

    return 0;
}