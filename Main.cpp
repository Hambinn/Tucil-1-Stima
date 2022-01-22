#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// int Small(){

// }

int main(){
    vector<string> jawab;
    string plc;
    vector<char> ans;
    int mamang[] = {1};
    string soal[7];
    string kosong;
    string delimiter = " ";
    string line1[7];
    ifstream myfile("file.txt");
    

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
    int i = 0;
    while(getline(myfile, plc, '\n')){
        jawab.push_back(plc);
        cout << jawab[i] << "\n";
        i++;
    }
    // for(int i = 0; i<8;i++){
    //     getline(myfile, jawab[i], '\n');
    //     cout<< jawab[i] << "\n";
    //     // cout<< soal[0][0] << "\n";
    // }
    
    cout << "\n";
    for(int i = 0; i<8;i++){
            int count = 0;
            ans.clear();
            // cout << i <<  "\n";
            int j =0; // looping jawaban ke bawah
            for(int k=0;k<7;k++){ // looping soal ke bawah
                for(int l=0;l<8;l++){ // looping soal ke samping
                    if(jawab[i][j] == soal[k][l]){ // kalo jawaban sama dengan soal 
                        if(jawab[i][j+1]== soal[k][l+1] && j!= jawab[i].length()-1){ // kalo jawaban+1 sama dengan soal+1 (arah kanan)
                            if(jawab[i][j+2]== soal[k][l+2] && j!= jawab[i].length()-1){
                                // cout<< i << "," << j << "\n";
                                // cout << "1. "<<soal[k][l] << "\n";
                                for(int m=0;m<jawab[i].length();m++){ // looping jawaban ke samping
                                    for(int n=l;n<8;n++){ // looping soal ke samping
                                        // cout << "2. "<<soal[k][n] << "\n";
                                        n += count;
                                        if(jawab[i][m] == soal[k][n]){
                                            ans.push_back(soal[k][n]); // disini
                                            // cout << k << ", " << n << "\n";
                                            n = 8;
                                            count++;
                                            if(count == jawab[i].length()){
                                                l = 8;
                                                k = 7;
                                                for(int x=0;x<ans.size();x++){
                                                    cout << ans[x];
                                                }
                                                count = 0;
                                            }
                                        }
                                    }
                                }
                                cout << "\n";
                            }
                        } 
                        else if(jawab[i][j+1]== soal[k][l-1]&& j!= jawab[i].length()-1){ // kalo jawaban+1 sama dengan soal-1 (arah kiri)
                            if(jawab[i][j+2]== soal[k][l-2] && j!= jawab[i].length()-1){
                                // cout<< i <<", "<< j <<"  gerbang " << "\n";
                                // cout<< i <<", "<< j <<"  gerbang " << jawab[i][j+1] << "\n";
                                // cout<< i <<", "<< j <<"  gerbang " << jawab[i][j+2] << "\n";
                                // cout << "1. "<<soal[k][l] << "\n";
                                for(int m=0;m<jawab[i].length();m++){ // looping jawaban ke samping
                                    // cout<< i <<", "<< j << " dalem " << "\n";
                                    for(int n=l;n>=0;n--){ // looping soal ke samping
                                        // cout << "2. "<<soal[k][n] << "\n";
                                        n -= count;
                                        if(jawab[i][m] == soal[k][n]){
                                            ans.push_back(soal[k][n]);
                                            n = 0;
                                            count++;
                                            if(count == jawab[i].length()){
                                                l = 8;
                                                k = 7;
                                                for(int x=0;x<ans.size();x++){
                                                    cout << ans[x];
                                                }
                                                count = 0;
                                            }
                                        }
                                    }
                                }
                                cout << "\n";
                            }
                        }
                        else if(k < 5){
                            if((jawab[i][j+1] == soal[k+1][l])){
                                // cout<< i <<", "<< j <<"  gerbang " << "\n";
                                // cout<< i <<", "<< j <<"  gerbang " << jawab[i][j+1] << "\n";
                                // cout<< i <<", "<< j <<"  gerbang " << jawab[i][j+2] << "\n";
                                if(jawab[i][j+2] == soal[k+2][l]){
                                    // cout<< i <<", "<< j <<"  gerbang " << "\n";
                                    // cout<< i <<", "<< j <<"  gerbang " << jawab[i][j+1] << "\n";
                                    // cout<< i <<", "<< j <<"  gerbang " << jawab[i][j+2] << "\n";
                                    for(int m=0;m<jawab[i].length();m++){
                                        for(int n=k;n<7;n++){
                                            if(jawab[i][m] == soal[n][l]){
                                                cout << soal[n][l];
                                                n = 7;
                                                count++;
                                                if(count == jawab[i].length()){
                                                    count = 0;
                                                }
                                            }
                                        }
                                    }
                                    cout << "\n";
                                }
                            }
                            else if(jawab[i][j+1] == soal[k+1][l+1]){
                                if(jawab[i][j+2] == soal[k+2][l+2]){
                                    for(int m=0;m<jawab[i].length();m++){
                                        for(int n=k;n<7;n++){ // loop bawah soal
                                            n += count;
                                            for(int o=l;o<8;o++){
                                                o += count; // loop kanan soal
                                                if(jawab[i][m] == soal[n][o]){
                                                    cout << soal[n][o];
                                                    // cout << n << ", " << o << "\n";
                                                    o = 8;
                                                    n = 7;
                                                    count++;
                                                    if(count == jawab[i].length()){
                                                        count = 0;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    cout << "\n";
                                }
                            }
                        }
                        else if(k > 2){
                            if((jawab[i][j+1] == soal[k-1][l])){
                                // cout<< i <<", "<< j <<"  gerbang " << "\n";
                                // cout<< i <<", "<< j <<"  gerbang " << jawab[i][j+1] << "\n";
                                // cout<< i <<", "<< j <<"  gerbang " << jawab[i][j+2] << "\n";
                                if(jawab[i][j+2] == soal[k-2][l]){
                                    // cout<< i <<", "<< j <<"  gerbang " << "\n";
                                    // cout<< i <<", "<< j <<"  gerbang " << jawab[i][j+1] << "\n";
                                    // cout<< i <<", "<< j <<"  gerbang " << jawab[i][j+2] << "\n";
                                    for(int m=0;m<jawab[i].length();m++){
                                        for(int n=k;n>=0;n--){
                                            if(jawab[i][m] == soal[n][l]){
                                                cout << soal[n][l];
                                                n = 0;
                                                count++;
                                                if(count == jawab[i].length()){
                                                    count = 0;
                                                }
                                            }
                                        }
                                    }
                                    cout << "\n";
                                }
                            }
                            else if(jawab[i][j+1] == soal[k-1][l-1]){
                                // cout << k-1 << ", "<< l-1 << "\n";
                                if(jawab[i][j+2] == soal[k-2][l-2]){
                                    // cout << "madepsya\n";
                                    for(int m=0;m<jawab[i].length();m++){
                                        for(int n=k;n>=0;n--){ // loop bawah soal
                                            cout << count << "\n";
                                            n -= count;
                                            for(int o=l;o>=0;o--){
                                                o -= count; // loop kanan soal
                                                if(jawab[i][m] == soal[n][o]){
                                                    cout << soal[n][o];
                                                    // cout << n << ", " << o << "\n";
                                                    o = 0;
                                                    n = 0;
                                                    count++;
                                                    if(count == jawab[i].length()){
                                                        count = 0;
                                                    }
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
    cout << "\n";


    // for(int i=0; i<jawab[5].length();i++){
    //     for(int j=0;j<8;j++){
    //         if(jawab[5][i] == soal[j][7]){
    //             cout << jawab[5][i];
    //             j = 8;
    //         }
    //     }
    // }

    cout << "aman\n";
    

    // cek semua jawaban dalam 8 arah seandainya udah ketemu 1 huruf depan yang sama.

    
    

    return 0;
}
