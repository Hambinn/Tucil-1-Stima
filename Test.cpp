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
    vector<string> soal;
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
        getline(myfile, kosong, '\n');
        soal.push_back(kosong);
    }

    for(int i = 0; i<7;i++){
        for(int j = 0; j<15;j++){
            if(soal[i][j] == ' '){
                soal[i].erase(j,1);
            }
        }
        cout << soal[i] << "\n";
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
    
    cout << "\n";
    for(int i = 0; i<8;i++){
            int count = 0;
            ans.clear();
            int j =0; // looping jawaban ke bawah
            for(int k=0;k<7;k++){ // looping soal ke bawah
                ans.clear();
                count = 0;
                for(int l=0;l<8;l++){ // looping soal ke samping
                    ans.clear();
                    count = 0;
                    if(jawab[i][j] == soal[k][l]){ // kalo jawaban sama dengan soal 
                        if(jawab[i][j+1]== soal[k][l+1] && jawab[i][j+2]== soal[k][l+2] && j!= jawab[i].length()-1){ // kalo jawaban+1 sama dengan soal+1 (arah kanan)
                                for(int m=0;m<jawab[i].length();m++){ // looping jawaban ke samping
                                    for(int n=l;n<8;n++){ // looping soal ke samping
                                        n += count;
                                        if(jawab[i][m] == soal[k][n]){
                                            ans.push_back(soal[k][n]); // disini
                                            n = 8;
                                            count++;
                                            if(count == jawab[i].length()){
                                                l = 8;
                                                k = 7;
                                                for(int x=0;x<ans.size();x++){
                                                    cout << ans[x];
                                                }
                                                count = 0;
                                                cout << "\n";     
                                            }
                                        }
                                    }
                                }                       
                        } 
                        else if(jawab[i][j+1]== soal[k][l-1] && jawab[i][j+2]== soal[k][l-2] &&  j!= jawab[i].length()-1){ // kalo jawaban+1 sama dengan soal-1 (arah kiri)
                                for(int m=0;m<jawab[i].length();m++){ // looping jawaban ke samping
                                    for(int n=l;n>=0;n--){ // looping soal ke samping
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
                                                cout << "\n";
                                            }
                                        }
                                    }
                                }
                            }
                        else if(k == soal.size()-1){
                            if((jawab[i][j+1] == soal[k-1][l])){
                                        for(int m=0;m<jawab[i].length();m++){
                                            for(int n=k;n>=0;n--){
                                                if(jawab[i][m] == soal[n][l] && (n!= 0 || count == jawab[i].length()-1)){
                                                    ans.push_back(soal[n][l]);
                                                    n = 0;
                                                    count++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        count = 0;
                                                        n = 0;
                                                        m = jawab[i].length();
                                                        l = 8;
                                                        k = 7;
                                                        cout << "\n";                                                        
                                                    }
                                                }
                                                else if (n == 0 && count != jawab[i].length()-1){
                                                    n = 0;
                                                    m = jawab[i].length();
                                                    l = 8;
                                                }
                                            }
                                        }

                                }
                                else if(jawab[i][j+1] == soal[k-1][l-1]){
                                        for(int m=0;m<jawab[i].length();m++){
                                            for(int n=k;n>=0;n--){ // loop bawah soal
                                                n -= count;
                                                for(int o=l;o>=0;o--){
                                                    o -= count; // loop kanan soal
                                                    if(jawab[i][m] == soal[n][o] && (n!= 0 || count == jawab[i].length()-1)){
                                                        ans.push_back(soal[n][o]);
                                                        o = 0;
                                                        n = 0;
                                                        count++;
                                                        if(count == jawab[i].length()){
                                                            for(int x=0;x<ans.size();x++){
                                                                cout << ans[x];
                                                            }
                                                            count = 0;
                                                            o = 0;
                                                            n = 0;
                                                            m = jawab[i].length();
                                                            l = 8;
                                                            k = 7;
                                                            cout << "\n";
                                                        }
                                                    }
                                                    else if (n == 0 && count != jawab[i].length()-1){
                                                        o = 0;
                                                        n = 0;
                                                        m = jawab[i].length();
                                                        l = 8;
                                                    }
                                                }
                                            }
                                        }
                                }
                                else if(jawab[i][j+1] == soal[k-1][l+1]){
                                    for(int m=0;m<jawab[i].length();m++){
                                        for(int n=k;n>=0;n--){
                                            n -= count;
                                            for(int o=l;o<8;o++){
                                                o += count;
                                                if(jawab[i][m] == soal[n][o]  && (n!= 0 || count == jawab[i].length()-1)){
                                                    ans.push_back(soal[n][o]);
                                                    o = 8;
                                                    n = 0;
                                                    count ++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        count = 0;
                                                        o = 8;
                                                        n = 0;
                                                        m = jawab[i].length();
                                                        l = 8;
                                                        k = 7;
                                                    }
                                                }
                                                else if (n == 0 && count != jawab[i].length()-1){
                                                    o = 8;
                                                    n = 0;
                                                    m = jawab[i].length();
                                                    l = 8;
                                                }
                                            }
                                        }
                                    }
                                }
                        }
                        else if(k == 0){
                            if((jawab[i][j+1] == soal[k+1][l])){ // kebawah
                                        for(int m=0;m<jawab[i].length();m++){
                                            for(int n=k;n<7;n++){
                                                if(jawab[i][m] == soal[n][l] && (n!= soal.size()-1 || count == jawab[i].length()-1)){
                                                    ans.push_back(soal[n][l]);
                                                    n = 7;
                                                    count++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        count = 0;
                                                        n = 7;
                                                        m = jawab[i].length();
                                                        l = 8;
                                                        k = 7;
                                                        cout << "\n";
                                                    }
                                                }else if (n == soal.size()-1 && count != jawab[i].length()-1){
                                                    n = 7;
                                                    m = jawab[i].length();
                                                    l = 8;
                                                }
                                            }
                                        }
                                }
                            else if(jawab[i][j+1] == soal[k+1][l+1]){
                                    for(int m=0;m<jawab[i].length();m++){
                                        for(int n=k;n<7;n++){ // loop bawah soal
                                            n += count;
                                            for(int o=l;o<8;o++){
                                                o += count; // loop kanan soal
                                                if(jawab[i][m] == soal[n][o] && (n!= soal.size()-1 || count == jawab[i].length()-1)){
                                                    ans.push_back(soal[n][o]);
                                                    o = 8;
                                                    n = 7;
                                                    count++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        count = 0;
                                                        o = 8;
                                                        n = 7;
                                                        m = jawab[i].length();
                                                        l = 8;
                                                        k = 7;
                                                        cout << "\n";
                                                    }
                                                }
                                                else if(n == soal.size()-1 && count != jawab[i].length()-1){
                                                    o = 8;
                                                    n = 7;
                                                    m = jawab[i].length();
                                                    l = 8;
                                                }
                                            }
                                        }
                                    }
                                }
                            else if(jawab[i][j+1] == soal[k+1][l-1]){
                                for(int m=0;m<jawab[i].length();m++){
                                        for(int n=0;n<7;n++){
                                            n += count;
                                            for(int o=l;o>=0;o--){
                                                o -= count;
                                                if(jawab[i][m] == soal[n][o] && (n!= soal.size()-1 || count == jawab[i].length()-1)){
                                                    ans.push_back(soal[n][o]);
                                                    o = 0;
                                                    n = 7;
                                                    count ++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        count = 0;
                                                        o = 0;
                                                        n = 7;
                                                        m = jawab[i].length();
                                                        l = 8;
                                                        k = 7;
                                                    }
                                                }
                                                else if(n == soal.size()-1 && count != jawab[i].length()-1){
                                                    o = 0;
                                                    n = 7;
                                                    m = jawab[i].length();
                                                    l = 8;
                                                }
                                            }
                                        }
                                    }
                            }
                        }
                        else{
                            if((jawab[i][j+1] == soal[k-1][l])){
                                        cout << "masuk mars 2";
                                        for(int m=0;m<jawab[i].length();m++){
                                            for(int n=k;n>=0;n--){
                                                if(jawab[i][m] == soal[n][l] && (n!= 0 || count == jawab[i].length()-1)){
                                                    ans.push_back(soal[n][l]);
                                                    n = 0;
                                                    count++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        count = 0;
                                                        n = 0;
                                                        m = jawab[i].length();
                                                        l = 8;
                                                        k = 7;
                                                        cout << "\n";
                                                    }
                                                }
                                                else if (n == 0 && count != jawab[i].length()-1){
                                                    n = 0;
                                                    m = jawab[i].length();
                                                    l = 8;
                                                }
                                            }
                                        }
                                }
                                else if(jawab[i][j+1] == soal[k-1][l-1]){
                                        for(int m=0;m<jawab[i].length();m++){
                                            for(int n=k;n>=0;n--){ // loop bawah soal
                                                n -= count;
                                                for(int o=l;o>=0;o--){
                                                    o -= count; // loop kanan soal
                                                    if(jawab[i][m] == soal[n][o] && (n!= 0 || count == jawab[i].length()-1)){
                                                        ans.push_back(soal[n][o]);
                                                        o = 0;
                                                        n = 0;
                                                        count++;
                                                        if(count == jawab[i].length()){
                                                            for(int x=0;x<ans.size();x++){
                                                                cout << ans[x];
                                                            }
                                                            count = 0;
                                                            o = 0;
                                                            n = 0;
                                                            m = jawab[i].length();
                                                            l = 8;
                                                            k = 7;
                                                            cout << "\n";
                                                        }
                                                    }
                                                    else if(n == 0 && count != jawab[i].length()-1){
                                                        n = 0;
                                                        o = 0;
                                                        m = jawab[i].length();
                                                        l = 8;
                                                    }
                                                }
                                            }
                                        }
                                }
                                else if(jawab[i][j+1] == soal[k-1][l+1]){
                                    for(int m=0;m<jawab[i].length();m++){
                                        for(int n=k;n>=0;n--){
                                            n -= count;
                                            for(int o=l;o<8;o++){
                                                o += count;
                                                if(jawab[i][m] == soal[n][o] && (n!= 0 || count == jawab[i].length()-1)){
                                                    ans.push_back(soal[n][o]);
                                                    o = 8;
                                                    n = 0;
                                                    count ++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        count = 0;
                                                        o = 8;
                                                        n = 0;
                                                        m = jawab[i].length();
                                                        l = 8;
                                                        k = 7;
                                                        cout << "\n";
                                                    }
                                                }
                                                else if(n == 0 && count != jawab[i].length()-1){
                                                    o = 8;
                                                    n = 0;
                                                    m = jawab[i].length();
                                                    l = 8;
                                                }
                                            }
                                        }
                                    }
                                    
                                }
                            else if((jawab[i][j+1] == soal[k+1][l])){ // kebawah
                                        for(int m=0;m<jawab[i].length();m++){
                                            for(int n=k;n<7;n++){
                                                if(jawab[i][m] == soal[n][l] && (n!= soal.size()-1 || count == jawab[i].length()-1)){
                                                    ans.push_back(soal[n][l]);
                                                    n = 7;
                                                    count++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        count = 0;
                                                        n = 7;
                                                        m = jawab[i].length();
                                                        l = 8;
                                                        k = 7;
                                                        cout << "\n";
                                                    }
                                                }else if(n == soal.size()-1 && count != jawab[i].length()-1){
                                                    n = 7;
                                                    m = jawab[i].length();
                                                    l = 8;
                                                }
                                            }
                                        }
                                }
                            else if(jawab[i][j+1] == soal[k+1][l+1]){
                                    for(int m=0;m<jawab[i].length();m++){
                                        for(int n=k;n<7;n++){ // loop bawah soal
                                            n += count;
                                            for(int o=l;o<8;o++){
                                                o += count; // loop kanan soal
                                                if(jawab[i][m] == soal[n][o] && (n!= soal.size()-1 || count == jawab[i].length()-1)){
                                                    ans.push_back(soal[n][o]);
                                                    o = 8;
                                                    n = 7;
                                                    count++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        count = 0;
                                                        o = 8;
                                                        n = 7;
                                                        m = jawab[i].length();
                                                        l = 8;
                                                        k = 7;
                                                        cout << "\n";
                                                    }
                                                }
                                                else if(n == soal.size()-1 && count != jawab[i].length()-1){
                                                    n = 7;
                                                    o = 8;
                                                    m = jawab[i].length();
                                                    l = 8;
                                                }
                                            }
                                        }
                                    }
                                }
                            else if(jawab[i][j+1] == soal[k+1][l-1]){
                                for(int m=0;m<jawab[i].length();m++){
                                        for(int n=0;n<7;n++){
                                            n += count;
                                            for(int o=l;o>=0;o--){
                                                o -= count;
                                                if(jawab[i][m] == soal[n][o] && (n!= soal.size()-1 || count == jawab[i].length()-1)){
                                                    ans.push_back(soal[n][o]);
                                                    o = 0;
                                                    n = 7;
                                                    count ++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        count = 0;
                                                        o = 0;
                                                        n = 7;
                                                        m = jawab[i].length();
                                                        l = 8;
                                                        k = 7;
                                                        cout << "\n";
                                                    }
                                                }
                                                else if(n == soal.size()-1 && count != jawab[i].length()-1){
                                                    n = 7;
                                                    o = 0;
                                                    m = jawab[i].length();
                                                    l = 8;
                                                }
                                            }
                                        }
                                    }
                            }                            
                        }
                    }
                }
            }
    }
    cout << endl;
    cout << "aminsky";
    return 0;
}
