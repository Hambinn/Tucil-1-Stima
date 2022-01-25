#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// masukin index nya ke 2 vector berbeda aja terus nanti index yg di print nya dari 2 vector itu

bool checkIndex(int idxi, int idxj, vector<vector<int>> idsi, vector<vector<int>> idsj){
    for(int i=0; i<idsi.size();i++){
        for(int j=0;j<idsi[i].size();j++){
            if(idsi[i][j]==idxi && idsj[i][j]==idxj){
                // cout << "soal: "<<idxi << " " << idxj << endl;
                // cout << "jawaban: "<<idsi[i][j] << " " << idsj[i][j] << " "<< i << " " << j << " " <<endl;
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n;
    vector<string> jawab;
    string plc;
    vector<char> ans;
    vector<string> soal;
    string kosong;
    string delimiter = " ";
    vector<int> indexi;
    vector<int> indexj;
    vector<vector<int>> indicesi;
    vector<vector<int>> indicesj;
    int check = 0;
    string filename;
    vector<string> color = {{"\033[1;31m"}, {"\033[1;32m"}, {"\033[1;33m"}, {"\033[1;34m"}, {"\033[1;35m"}, {"\033[1;36m"}, {"\033[1;37m"}};
    
    // take input from user
    cout << "Masukkan nama file (spesifik dengan tempatnya): ";
    cin >> filename;
    ifstream myfile(filename);

    cout << "Masukan banyak baris soal: ";
    cin >> n;

    // Ambil data dari file & parsing
    if(!myfile){
        cout << "Error opening output file" << endl;
        system("pause");
        return -1;
    }

    for(int i = 0; i<n;i++){
        getline(myfile, kosong, '\n');
        soal.push_back(kosong);
    }

    for(int i = 0; i<n;i++){
        for(int j = 0; j<soal[0].size();j++){
            if(soal[i][j] == ' '){
                soal[i].erase(j,1);
            }
        }
        // cout << soal[i] << "\n";
    }

    for(int k = 0; k<2;k++){
        getline(myfile, kosong, '\n');
    }

    cout << "\n";
    int i = 0;
    while(getline(myfile, plc, '\n')){
        jawab.push_back(plc);
        // cout << jawab[i] << "\n";
        i++;
    }
    
    cout << "\n";
    for(int i = 0; i<jawab.size();i++){ // looping jawaban ke bawah
            int count = 0;
            ans.clear();
            indexi.clear();
            indexj.clear();
            int j =0; 
            for(int k=0;k<soal.size();k++){ // looping soal ke bawah
                ans.clear();
                indexi.clear();
                indexj.clear();
                count = 0;
                for(int l=0;l<soal[0].length();l++){ // looping soal ke samping
                    ans.clear();
                    indexi.clear();
                    indexj.clear();
                    count = 0;
                    if(jawab[i][j] == soal[k][l]){ // kalo jawaban sama dengan soal 
                        if(jawab[i][j+1]== soal[k][l+1] && jawab[i][j+2]== soal[k][l+2] && j!= jawab[i].length()-1){ // kalo jawaban+1 sama dengan soal+1 (arah kanan)
                                for(int m=0;m<jawab[i].length();m++){ // looping jawaban ke samping
                                    for(int n=l;n<soal[0].length();n++){ // looping soal ke samping
                                        n += count;
                                        if(jawab[i][m] == soal[k][n]){
                                            indexi.push_back(k);
                                            indexj.push_back(n);
                                            ans.push_back(soal[k][n]); // disini
                                            n = soal[0].length();
                                            count++;
                                            if(count == jawab[i].length()){
                                                l = soal[0].length();
                                                k = soal.size();
                                                for(int x=0;x<ans.size();x++){
                                                    cout << ans[x];
                                                }
                                                indicesi.push_back(indexi);
                                                indicesj.push_back(indexj);
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
                                            indexi.push_back(k);
                                            indexj.push_back(n);
                                            ans.push_back(soal[k][n]);
                                            n = -1;
                                            count++;
                                            if(count == jawab[i].length()){
                                                l = soal[0].length();;
                                                m = jawab[i].length();
                                                k = soal.size();
                                                n = -1;
                                                for(int x=0;x<ans.size();x++){
                                                    cout << ans[x];
                                                }
                                                indicesi.push_back(indexi);
                                                indicesj.push_back(indexj);
                                                count = 0;
                                                cout << "\n";
                                            }
                                        }
                                    }
                                }
                            }
                        else if(k == soal.size()-2 || k == soal.size()-1){
                            if((jawab[i][j+1] == soal[k-1][l]) && jawab[i][j+2] == soal[k-2][l]){
                                        for(int m=0;m<jawab[i].length();m++){
                                            for(int n=k-count;n>=0;n--){
                                                if(jawab[i][m] == soal[n][l] && (n!= 0 || count == jawab[i].length()-1)){
                                                    indexi.push_back(n);
                                                    indexj.push_back(l);
                                                    ans.push_back(soal[n][l]);
                                                    n = 0;
                                                    count++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        indicesi.push_back(indexi);
                                                        indicesj.push_back(indexj);
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
                                                }
                                            }
                                        }

                                }
                                else if(jawab[i][j+1] == soal[k-1][l-1]){
                                        for(int m=0;m<jawab[i].length();m++){
                                            for(int n=k;n>=0;n -= count){ // loop bawah soal
                                                for(int o=l;o>=0;o--){
                                                    o -= count; // loop kanan soal
                                                    if(jawab[i][m] == soal[n][o] && (n!= 0 || count == jawab[i].length()-1)){
                                                        indexi.push_back(n);
                                                        indexj.push_back(o);
                                                        ans.push_back(soal[n][o]);
                                                        o = 0;
                                                        n = -1;
                                                        count++;
                                                        if(count == jawab[i].length()){
                                                            for(int x=0;x<ans.size();x++){
                                                                cout << ans[x];
                                                            }
                                                            indicesi.push_back(indexi);
                                                            indicesj.push_back(indexj);
                                                            count = 0;
                                                            o = 0;
                                                            n = -1;
                                                            m = jawab[i].length();
                                                            l = soal[0].length();
                                                            k = soal.size();
                                                            cout << "\n";
                                                        }
                                                    }
                                                    else if (n == 0 && count != jawab[i].length()-1){
                                                        o = 0;
                                                        n = -1;
                                                        m = jawab[i].length();
                                                    }
                                                }
                                            }
                                        }
                                }
                                else if(jawab[i][j+1] == soal[k-1][l+1]){
                                    for(int m=0;m<jawab[i].length();m++){
                                        for(int n=k;n>=0;n -= count){
                                            for(int o=l;o<soal[0].length();o++){
                                                o += count;
                                                if(jawab[i][m] == soal[n][o]  && (n!= 0 || count == jawab[i].length()-1)){
                                                    indexi.push_back(n);
                                                    indexj.push_back(o);
                                                    ans.push_back(soal[n][o]);
                                                    o = soal[0].length();
                                                    n = -1;
                                                    count ++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        indicesi.push_back(indexi);
                                                        indicesj.push_back(indexj);
                                                        count = 0;
                                                        o = soal[0].length();
                                                        n = -1;
                                                        m = jawab[i].length();
                                                        l = soal[0].length();
                                                        k = soal.size();
                                                        cout << "\n";
                                                    }
                                                }
                                                else if (n == 0 && count != jawab[i].length()-1){
                                                    o = soal[0].length();
                                                    n = -1;
                                                    m = jawab[i].length();
                                                }
                                            }
                                        }
                                    }
                                }
                        }
                        else if(k == 0 || k == 1){
                            if((jawab[i][j+1] == soal[k+1][l]) && (jawab[i][j+2] == soal[k+2][l])){ // kebawah
                                        for(int m=0;m<jawab[i].length();m++){
                                            for(int n=k+count;n<soal.size();n++){
                                                if(jawab[i][m] == soal[n][l] && (n!= soal.size()-1 || count == jawab[i].length()-1)){
                                                    indexi.push_back(n);
                                                    indexj.push_back(l);
                                                    ans.push_back(soal[n][l]);
                                                    n = soal.size();
                                                    count++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        indicesi.push_back(indexi);
                                                        indicesj.push_back(indexj);
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
                                                }
                                            }
                                        }
                                }
                            else if(jawab[i][j+1] == soal[k+1][l+1] && jawab[i][j+2] == soal[k+2][l+2]){
                                    for(int m=0;m<jawab[i].length();m++){
                                        for(int n=k+count;n<soal.size();n += count){ // loop bawah soal
                                            for(int o=l;o<soal[0].length();o++){
                                                o += count; // loop kanan soal
                                                if(jawab[i][m] == soal[n][o] && (n!= soal.size()-1 || count == jawab[i].length()-1)){
                                                    indexi.push_back(n);
                                                    indexj.push_back(o);
                                                    ans.push_back(soal[n][o]);
                                                    o = soal[0].length();
                                                    n = soal.size();
                                                    count++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        indicesi.push_back(indexi);
                                                        indicesj.push_back(indexj);
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
                                                }
                                            }
                                        }
                                    }
                                }
                            else if(jawab[i][j+1] == soal[k+1][l-1] && jawab[i][j+2] == soal[k+2][l-2]){
                                for(int m=0;m<jawab[i].length();m++){
                                        for(int n=k+count;n<soal.size();n += count){
                                            for(int o=l;o>=0;o--){
                                                o -= count;
                                                if(jawab[i][m] == soal[n][o] && (n!= soal.size()-1 || count == jawab[i].length()-1)){
                                                    indexi.push_back(n);
                                                    indexj.push_back(o);
                                                    ans.push_back(soal[n][o]);
                                                    o = -1;
                                                    n = soal.size();
                                                    count ++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        indicesi.push_back(indexi);
                                                        indicesj.push_back(indexj);
                                                        count = 0;
                                                        o = -1;
                                                        n = soal.size();
                                                        m = jawab[i].length();
                                                        l = soal[0].length();
                                                        k = soal.size();
                                                        cout << "\n";
                                                    }
                                                }
                                                else if(n == soal.size()-1 && count != jawab[i].length()-1){
                                                    o = 0;
                                                    n = soal.size();
                                                    m = jawab[i].length();
                                                }
                                            }
                                        }
                                    }
                            }
                        }
                        else{
                            if((jawab[i][j+1] == soal[k-1][l] && jawab[i][j+2] == soal[k-2][l])){ // kebawah
                                        for(int m=0;m<jawab[i].length();m++){
                                            for(int n=k-count;n>=0;n--){
                                                if(jawab[i][m] == soal[n][l] && (n!= 0 || count == jawab[i].length()-1)){
                                                    indexi.push_back(n);
                                                    indexj.push_back(l);
                                                    ans.push_back(soal[n][l]);
                                                    n = 0;
                                                    count++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        indicesi.push_back(indexi);
                                                        indicesj.push_back(indexj);
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
                                                }
                                            }
                                        }
                                }
                                else if(jawab[i][j+1] == soal[k-1][l-1] && jawab[i][j+2] == soal[k-2][l-2]){ // kiri bawah
                                        for(int m=0;m<jawab[i].length();m++){
                                            for(int n=k-count;n>=0;n -= count){ // loop bawah soal
                                                for(int o=l;o>=0;o--){
                                                    o -= count; // loop kanan soal
                                                    if(jawab[i][m] == soal[n][o] && (n!= 0 || count == jawab[i].length()-1)){
                                                        indexi.push_back(n);
                                                        indexj.push_back(o);
                                                        ans.push_back(soal[n][o]);
                                                        o = -1;
                                                        n = -1;
                                                        count++;
                                                        if(count == jawab[i].length()){
                                                            for(int x=0;x<ans.size();x++){
                                                                cout << ans[x];
                                                            }
                                                            indicesi.push_back(indexi);
                                                            indicesj.push_back(indexj);
                                                            count = 0;
                                                            o = 0;
                                                            n = -1;
                                                            m = jawab[i].length();
                                                            l = soal[0].length();
                                                            k = soal.size();
                                                            cout << "\n";
                                                        }
                                                    }
                                                    else if(n == 0 && count != jawab[i].length()-1){
                                                        n = -1;
                                                        o = 0;
                                                        m = jawab[i].length();
                                                    }
                                                }
                                            }
                                        }
                                }
                                else if(jawab[i][j+1] == soal[k-1][l+1] && jawab[i][j+2] == soal[k-2][l+2]){
                                    for(int m=0;m<jawab[i].length();m++){
                                        for(int n=k-count;n>=0;n -= count){
                                            for(int o=l;o<soal[0].length();o++){
                                                o += count;
                                                if(jawab[i][m] == soal[n][o] && (n!= 0 || count == jawab[i].length()-1)){
                                                    indexi.push_back(n);
                                                    indexj.push_back(o);
                                                    ans.push_back(soal[n][o]);
                                                    o = soal[0].length();
                                                    n = -1;
                                                    count ++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        indicesi.push_back(indexi);
                                                        indicesj.push_back(indexj);
                                                        count = 0;
                                                        o = soal[0].length();
                                                        n = -1;
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
                                                }
                                            }
                                        }
                                    }
                                    
                                }
                            else if((jawab[i][j+1] == soal[k+1][l] && jawab[i][j+2] == soal[k+2][l])){ // kebawah
                                        for(int m=0;m<jawab[i].length();m++){
                                            for(int n=k+count;n<soal.size();n++){
                                                if(jawab[i][m] == soal[n][l] && (n!= soal.size()-1 || count == jawab[i].length()-1)){
                                                    indexi.push_back(n);
                                                    indexj.push_back(l);
                                                    ans.push_back(soal[n][l]);
                                                    n = soal.size();
                                                    count++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        indicesi.push_back(indexi);
                                                        indicesj.push_back(indexj);
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
                                                }
                                            }
                                        }
                                }
                            else if(jawab[i][j+1] == soal[k+1][l+1] && jawab[i][j+2] == soal[k+2][l+2]){
                                    for(int m=0;m<jawab[i].length();m++){
                                        for(int n=k;n<soal.size();n++){ // loop bawah soal
                                            n += count;
                                            for(int o=l;o<soal[0].length();o++){
                                                o += count; // loop kanan soal
                                                if(jawab[i][m] == soal[n][o] && (n!= soal.size()-1 || count == jawab[i].length()-1)){
                                                    indexi.push_back(n);
                                                    indexj.push_back(o);
                                                    ans.push_back(soal[n][o]);
                                                    o = soal[0].length();
                                                    n = soal.size();
                                                    count++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        indicesi.push_back(indexi);
                                                        indicesj.push_back(indexj);
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
                                                }
                                                else{
                                                    o = soal[0].length();
                                                    n = soal.size();
                                                    m = jawab[i].length();
                                                }
                                            }
                                        }
                                    }
                                }
                            else if(jawab[i][j+1] == soal[k+1][l-1] && jawab[i][j+2] == soal[k+2][l-2]){
                                for(int m=0;m<jawab[i].length();m++){
                                        for(int n=k+count;n<soal.size();n += count){
                                            for(int o=l;o>=0;o--){
                                                o -= count;
                                                if(jawab[i][m] == soal[n][o] && (n!= soal.size()-1 || count == jawab[i].length()-1)){
                                                    // cout << soal[n][o];
                                                    indexi.push_back(n);
                                                    indexj.push_back(o);
                                                    ans.push_back(soal[n][o]);
                                                    o = 0;
                                                    n = soal.size();
                                                    count ++;
                                                    if(count == jawab[i].length()){
                                                        for(int x=0;x<ans.size();x++){
                                                            cout << ans[x];
                                                        }
                                                        indicesi.push_back(indexi);
                                                        indicesj.push_back(indexj);
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
                                                }else{
                                                    o = 0;
                                                    n = soal.size();
                                                    m = jawab[i].length();
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
    for(int i=0;i<soal.size();i++){ // soal kebawah
        for(int j=0;j<soal[0].length();j++){ // soal kesamping
            if(checkIndex(i,j,indicesi,indicesj) == true){
                cout << "\033[1;31m" << soal[i][j] <<"\033[0m" << " ";
            }
            else{
                cout << soal[i][j] << " ";
            }
        }
        cout << endl;
    }
    
    cout << "aminsky" << endl;
    return 0;
}