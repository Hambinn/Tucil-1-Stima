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
    vector<string> soal;
    string kosong;
    string delimiter = " ";
    ifstream myfile("Toy.txt");
    

    // Ambil data dari file & parsing
    if(!myfile){
        cout << "Error opening output file" << endl;
        system("pause");
        return -1;
    }

    for(int i = 0; i<14;i++){
        getline(myfile, kosong, '\n');
        soal.push_back(kosong);
    }

    for(int i = 0; i<14;i++){
        for(int j = 0; j<28;j++){
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
    for(int i = 0; i<jawab.size();i++){ // looping jawaban ke bawah
            int count = 0;
            ans.clear();
            int j =0; 
            for(int k=0;k<soal.size();k++){ // looping soal ke bawah
                ans.clear();
                count = 0;
                for(int l=0;l<soal[0].length();l++){ // looping soal ke samping
                    ans.clear();
                    count = 0;
                    if(jawab[i][j] == soal[k][l]){ // kalo jawaban sama dengan soal 
                        if(jawab[i][j+1]== soal[k][l+1] && jawab[i][j+2]== soal[k][l+2] && j!= jawab[i].length()-1){ // kalo jawaban+1 sama dengan soal+1 (arah kanan)
                                for(int m=0;m<jawab[i].length();m++){ // looping jawaban ke samping
                                    for(int n=l;n<soal[0].length();n++){ // looping soal ke samping
                                        n += count;
                                        if(jawab[i][m] == soal[k][n]){
                                            ans.push_back(soal[k][n]); // disini
                                            n = soal[0].length();
                                            count++;
                                            if(count == jawab[i].length()){
                                                l = soal[0].length();
                                                k = soal.size();
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
                                                l = soal[0].length();;
                                                k = soal.size();
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
                                                        l = soal[0].length();
                                                        k = soal.size();
                                                        cout << "\n";                                                        
                                                    }
                                                }
                                                else if (n == 0 && count != jawab[i].length()-1){
                                                    n = 0;
                                                    m = jawab[i].length();
                                                    l = soal[0].length();
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
                                                            l = soal[0].length();
                                                            k = soal.size();
                                                            cout << "\n";
                                                        }
                                                    }
                                                    else if (n == 0 && count != jawab[i].length()-1){
                                                        o = 0;
                                                        n = 0;
                                                        m = jawab[i].length();
                                                        l = soal[0].length();
                                                    }
                                                }
                                            }
                                        }
                                }
                                else if(jawab[i][j+1] == soal[k-1][l+1]){
                                    for(int m=0;m<jawab[i].length();m++){
                                        for(int n=k;n>=0;n--){
                                            n -= count;
                                            for(int o=l;o<soal[0].length();o++){
                                                o += count;
                                                if(jawab[i][m] == soal[n][o]  && (n!= 0 || count == jawab[i].length()-1)){
                                                    ans.push_back(soal[n][o]);
                                                    o = soal[0].length();
                                                    n = 0;
                                                    count ++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        count = 0;
                                                        o = soal[0].length();
                                                        n = 0;
                                                        m = jawab[i].length();
                                                        l = soal[0].length();
                                                        k = soal.size();
                                                    }
                                                }
                                                else if (n == 0 && count != jawab[i].length()-1){
                                                    o = soal[0].length();
                                                    n = 0;
                                                    m = jawab[i].length();
                                                    l = soal[0].length();
                                                }
                                            }
                                        }
                                    }
                                }
                        }
                        else if(k == 0){
                            if((jawab[i][j+1] == soal[k+1][l])){ // kebawah
                                        for(int m=0;m<jawab[i].length();m++){
                                            for(int n=k;n<soal.size();n++){
                                                if(jawab[i][m] == soal[n][l] && (n!= soal.size()-1 || count == jawab[i].length()-1)){
                                                    ans.push_back(soal[n][l]);
                                                    n = soal.size();
                                                    count++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        count = 0;
                                                        n = soal.size();
                                                        m = jawab[i].length();
                                                        l = soal[0].length();
                                                        k = soal.size();
                                                        cout << "\n";
                                                    }
                                                }else if (n == soal.size()-1 && count != jawab[i].length()-1){
                                                    n = soal.size();
                                                    m = jawab[i].length();
                                                    l = soal[0].length();
                                                }
                                            }
                                        }
                                }
                            else if(jawab[i][j+1] == soal[k+1][l+1]){
                                    for(int m=0;m<jawab[i].length();m++){
                                        for(int n=k;n<soal.size();n++){ // loop bawah soal
                                            n += count;
                                            for(int o=l;o<soal[0].length();o++){
                                                o += count; // loop kanan soal
                                                if(jawab[i][m] == soal[n][o] && (n!= soal.size()-1 || count == jawab[i].length()-1)){
                                                    ans.push_back(soal[n][o]);
                                                    o = soal[0].length();
                                                    n = soal.size();
                                                    count++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        count = 0;
                                                        o = soal[0].length();
                                                        n = soal.size();
                                                        m = jawab[i].length();
                                                        l = soal[0].length();
                                                        k = soal.size();
                                                        cout << "\n";
                                                    }
                                                }
                                                else if(n == soal.size()-1 && count != jawab[i].length()-1){
                                                    o = soal[0].length();
                                                    n = soal.size();
                                                    m = jawab[i].length();
                                                    l = soal[0].length();
                                                }
                                            }
                                        }
                                    }
                                }
                            else if(jawab[i][j+1] == soal[k+1][l-1]){
                                for(int m=0;m<jawab[i].length();m++){
                                        for(int n=0;n<soal.size();n++){
                                            n += count;
                                            for(int o=l;o>=0;o--){
                                                o -= count;
                                                if(jawab[i][m] == soal[n][o] && (n!= soal.size()-1 || count == jawab[i].length()-1)){
                                                    ans.push_back(soal[n][o]);
                                                    o = 0;
                                                    n = soal.size();
                                                    count ++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        count = 0;
                                                        o = 0;
                                                        n = soal.size();
                                                        m = jawab[i].length();
                                                        l = soal[0].length();
                                                        k = soal.size();
                                                    }
                                                }
                                                else if(n == soal.size()-1 && count != jawab[i].length()-1){
                                                    o = 0;
                                                    n = soal.size();
                                                    m = jawab[i].length();
                                                    l = soal[0].length();
                                                }
                                            }
                                        }
                                    }
                            }
                        }
                        else{
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
                                                        l = soal[0].length();
                                                        k = soal.size();
                                                        cout << "\n";
                                                    }
                                                }
                                                else if (n == 0 && count != jawab[i].length()-1){
                                                    n = 0;
                                                    m = jawab[i].length();
                                                    l = soal[0].length();
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
                                                            l = soal[0].length();
                                                            k = soal.size();
                                                            cout << "\n";
                                                        }
                                                    }
                                                    else if(n == 0 && count != jawab[i].length()-1){
                                                        n = 0;
                                                        o = 0;
                                                        m = jawab[i].length();
                                                        l = soal[0].length();
                                                    }
                                                }
                                            }
                                        }
                                }
                                else if(jawab[i][j+1] == soal[k-1][l+1]){
                                    for(int m=0;m<jawab[i].length();m++){
                                        for(int n=k;n>=0;n--){
                                            n -= count;
                                            for(int o=l;o<soal[0].length();o++){
                                                o += count;
                                                if(jawab[i][m] == soal[n][o] && (n!= 0 || count == jawab[i].length()-1)){
                                                    ans.push_back(soal[n][o]);
                                                    o = soal[0].length();
                                                    n = 0;
                                                    count ++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        count = 0;
                                                        o = soal[0].length();
                                                        n = 0;
                                                        m = jawab[i].length();
                                                        l = soal[0].length();
                                                        k = soal.size();
                                                        cout << "\n";
                                                    }
                                                }
                                                else if(n == 0 && count != jawab[i].length()-1){
                                                    o = soal[0].length();
                                                    n = 0;
                                                    m = jawab[i].length();
                                                    l = soal[0].length();
                                                }
                                            }
                                        }
                                    }
                                    
                                }
                            else if((jawab[i][j+1] == soal[k+1][l])){ // kebawah
                                        for(int m=0;m<jawab[i].length();m++){
                                            for(int n=k;n<soal.size();n++){
                                                if(jawab[i][m] == soal[n][l] && (n!= soal.size()-1 || count == jawab[i].length()-1)){
                                                    ans.push_back(soal[n][l]);
                                                    n = soal.size();
                                                    count++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        count = 0;
                                                        n = soal.size();
                                                        m = jawab[i].length();
                                                        l = soal[0].length();
                                                        k = soal.size();
                                                        cout << "\n";
                                                    }
                                                }else if(n == soal.size()-1 && count != jawab[i].length()-1){
                                                    n = soal.size();
                                                    m = jawab[i].length();
                                                    l = soal[0].length();
                                                }
                                            }
                                        }
                                }
                            else if(jawab[i][j+1] == soal[k+1][l+1]){
                                    for(int m=0;m<jawab[i].length();m++){
                                        for(int n=k;n<soal.size();n++){ // loop bawah soal
                                            n += count;
                                            for(int o=l;o<soal[0].length();o++){
                                                o += count; // loop kanan soal
                                                if(jawab[i][m] == soal[n][o] && (n!= soal.size()-1 || count == jawab[i].length()-1)){
                                                    ans.push_back(soal[n][o]);
                                                    o = soal[0].length();
                                                    n = soal.size();
                                                    count++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        count = 0;
                                                        o = soal[0].length();
                                                        n = soal.size();
                                                        m = jawab[i].length();
                                                        l = soal[0].length();
                                                        k = soal.size();
                                                        cout << "\n";
                                                    }
                                                }
                                                else if(n == soal.size()-1 && count != jawab[i].length()-1){
                                                    n = soal.size();
                                                    o = soal[0].length();
                                                    m = jawab[i].length();
                                                    l = soal[0].length();
                                                }else{
                                                    o = soal[0].length();
                                                    n = soal.size();
                                                    m = jawab[i].length();
                                                    l = soal[0].length();
                                                }
                                            }
                                        }
                                    }
                                }
                            else if(jawab[i][j+1] == soal[k+1][l-1]){
                                for(int m=0;m<jawab[i].length();m++){
                                        for(int n=0;n<soal.size();n++){
                                            n += count;
                                            for(int o=l;o>=0;o--){
                                                o -= count;
                                                if(jawab[i][m] == soal[n][o] && (n!= soal.size()-1 || count == jawab[i].length()-1)){
                                                    ans.push_back(soal[n][o]);
                                                    o = 0;
                                                    n = soal.size();
                                                    count ++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        count = 0;
                                                        o = 0;
                                                        n = soal.size();
                                                        m = jawab[i].length();
                                                        l = soal[0].length();
                                                        k = soal.size();
                                                        cout << "\n";
                                                    }
                                                }
                                                else if(n == soal.size()-1 && count != jawab[i].length()-1){
                                                    n = soal.size();
                                                    o = 0;
                                                    m = jawab[i].length();
                                                    l = soal[0].length();
                                                }else{
                                                    n = soal.size();
                                                    o = 0;
                                                    m = jawab[i].length();
                                                    l = soal[0].length();
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
    cout << "aman" << endl;
    return 0;
}
