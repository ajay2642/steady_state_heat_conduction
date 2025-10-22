#include<iostream>
#include<fstream>
#include <vector>
#include <cmath>
#include<utility>
using namespace std;
// printer 
void printer(vector<vector<double>> array ,  int k ){
    for (int i =0; i< k; ++i){
        for (int j= 0; j < k; ++j){
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}
// norm of matrix
double norm(vector<vector<double>> array){
    double sum = 0;
    for (int i =0; i < array.size(); ++i){
        for(int j = 0 ;  j<  array[i].size() ; ++j ){
            sum += array[i][j] * array [i][j];
        }
    }
    return sqrt(sum);
}
// jacobi
pair<vector<vector<double>>,int> jacobi(int n ){
    vector<vector<double>> T(n , vector<double>(n,0));
    vector<vector<double>> k1(n , vector<double>(n,0));
    int count = 0;
    for(int i = 0; i < n ;++i){
        T[n-1][i] =1;
    }
    
    
    double residue = 1e-6;
    double res = 10;


    while(res > residue){
        vector<vector<double>> Told = T;
        for (int i =1; i< n-1 ; ++i){
            for(int j = 1; j < n-1 ; ++j){
            T[i][j] = 0.25 *(Told[i-1][j] +Told[i+1][j] +Told[i][j-1] +Told[i][j+1]);
            }
        }
        for (int i = 0; i < n ; ++i){
            T[i][n-1] = T[i][n-2];
        }
        for(int i = 0; i < n ; ++i){
            for(int j = 0 ; j < n;++j){
                k1 [i][j] = abs(T[i][j] - Told[i][j]);
            }
        }
        res = norm(k1);
        count += 1;
        cout << res<<endl;
    }
    return {T , count};
}
// gauss seidel
pair<vector<vector<double>>,int> gauss(int n ){
    vector<vector<double>> T(n , vector<double>(n,0));
    vector<vector<double>> k1(n , vector<double>(n,0));
    int count = 0;
    for(int i = 0; i < n ;++i){
        T[n-1][i] =1;
    }
    // printer(T,10);
    
    
    double residue = 1e-6;
    double res = 10;


    while(res > residue){
        vector<vector<double>> Told = T;
        for (int i =1; i< n-1 ; ++i){
            for(int j = 1; j < n-1 ; ++j){
            T[i][j] = 0.25 *(T[i-1][j] +T[i+1][j] +T[i][j-1] +T[i][j+1]);
            }
        }
        for (int i = 0; i < n ; ++i){
            T[i][n-1] = T[i][n-2];
        }
        for(int i = 0; i < n ; ++i){
            for(int j = 0 ; j < n;++j){
                k1 [i][j] = abs(T[i][j] - Told[i][j]);
            }
        }
        res = norm(k1);
        cout << res<<endl;
        count += 1;
    }
    return {T , count};
}
// sor
pair<vector<vector<double>>,int> sor(int n ){
    vector<vector<double>> T(n , vector<double>(n,0));
    vector<vector<double>> k1(n , vector<double>(n,0));
    int count = 0;
    float omega = 1.5;
    for(int i = 0; i < n ;++i){
        T[n-1][i] =1;
    }
    
    double residue = 1e-6;
    double res = 10;


    while(res > residue){
        vector<vector<double>> Told = T;
        for (int i =1; i< n-1 ; ++i){
            for(int j = 1; j < n-1 ; ++j){
            Told[i][j] = 0.25 *(Told[i-1][j] +Told[i+1][j] +Told[i][j-1] +Told[i][j+1]);
            }
        }
        for (int i = 0; i < n ; ++i){
            Told[i][n-1] = Told[i][n-2];
        }
        for (int i = 0 ; i < n ; ++i){
            for (int j =0; j<n; ++j){
                T[i][j] = T[i][j] + omega*(Told[i][j] - T[i][j]);
            }
        }
        for(int i = 0; i < n ; ++i){
            for(int j = 0 ; j < n;++j){
                k1 [i][j] = abs(T[i][j] - Told[i][j]);
            }
        }
        res = norm(k1);
        cout << res<<endl;
        count += 1;
    }
    return {T , count};
}

int main(){
    ofstream file("data.csv");
    file << "jacobi,sor,gauss\n";
    int n = 80;

    pair<vector<vector<double>>,int> result = sor(n);
    pair<vector<vector<double>>,int> result1 = jacobi(n);
    pair<vector<vector<double>>,int> result2 = gauss(n);



    vector<vector<double>> q = result.first;
    int iter =  result.second;
    vector<vector<double>> q1 = result1.first;
    int iter1 =  result1.second;
    vector<vector<double>> q2 = result2.first;
    int iter2 =  result2.second;


    for(int i =0; i< n; ++i )
    {
        for (int j=0; j < n; ++j){
            file << q1[i][j] << ","<< q[i][j]<< ","<< q2[i][j] << endl;

        }

    }
    file.close();

    cout << "sor " << iter << endl;
    cout << "jacobi " << iter1 << endl;
    cout << "gauss " << iter2 << endl;

    cout << "file saved sucessfully";
    return 0;
}

