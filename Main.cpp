#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// int Small(){

// }

int main(){
    string jawab[8];
    int mamang[] = {1};
    string soal[7];
    string kosong;
    string delimiter = " ";
    string line1[7];
    ifstream myfile("file.txt");
    int count = 0;

    // Ambil data dari file & parsing
    if(!myfile){
        cout << "Error opening output file" << endl;
        system("pause");
        return -1;
    }

    for(int i = 0; i<7;i++){
        getline(myfile, line1[i], '\n');
        // cout<< line1[i] << "\n";
    }

    for(int i = 0; i<7;i++){
        int a = 0;
        for(int j = 0;j<15;j++){
            if(line1[i][j] != ' '){
                // cout << line1[i][j];
                soal[i][a] = line1[i][j];
                cout << soal[i][a];
                a++;
            }
            
        }
        cout << "\n";
    }


    for(int k = 0; k<2;k++){
        getline(myfile, kosong, '\n');
    }

    cout << "\n";

    for(int i = 0; i<8;i++){
        getline(myfile, jawab[i], '\n');
        cout<< jawab[i] << "\n";
        // cout<< soal[0][0] << "\n";
    }
    
    cout << "\n";
    for(int i = 0; i<8;i++){ // looping jawaban ke bawah
        for(int j=0;j<jawab[i].length();j++){ // looping jawaban ke samping
            for(int k=0;k<7;k++){ // looping soal ke bawah
                for(int l=0;l<8;l++){ // looping soal ke samping
                    if(jawab[i][j] == soal[k][l]){ // kalo jawaban sama dengan soal
                        if(jawab[i][j+1]== soal[k][l+1]){ // kalo jawaban+1 sama dengan soal+1
                            if(jawab[i][j+2]== soal[k][l+2]){
                                // cout<< i << "," << j << "\n";
                                // cout << "1. "<<soal[k][l] << "\n";
                                for(int m=0;m<jawab[i].length();m++){ // looping jawaban ke samping
                                    for(int n=l;n<8;n++){ // looping soal ke samping
                                        // cout << "2. "<<soal[k][n] << "\n";
                                        if(jawab[i][m] == soal[k][n]){
                                            cout<< jawab[i][m]; // disini
                                            n = 8;
                                            count++;
                                            if(count == jawab[i].length()){
                                                l = 8;
                                                j = jawab[i].length();
                                                count = 0;
                                            }
                                        }
                                    }
                                }
                                cout << "\n";
                            }
                        }
                    }
                }
            }
        }
    }


    // for(int i=0; i<jawab[3].length();i++){
    //     for(int j=1;j<8;j++){
    //         if(jawab[3][i] == soal[6][j]){
    //             cout << jawab[3][i];
    //             j = 8;
    //         }
    //     }
    // }
    

    // cek semua jawaban dalam 8 arah seandainya udah ketemu 1 huruf depan yang sama.

    
    
    

    return 0;
}
