#include <iostream>
#include <cmath>
#include <climits>
#include <iomanip>
#include <vector>
typedef long long ll;
using namespace std;

struct person{
    string name;
    string surname;
    double gpa;
};

void merge(vector<person>&v, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<person>L(n1);
    vector<person>R(n2);

    for(int i = 0; i < n1;i++)L[i] = v[l+i];
    for(int i = 0; i < n2;i++)R[i] = v[m+i+1];

    int i = 0; int j = 0; int k  = l;

    while(i < n1 && j < n2){
        if(L[i].gpa < R[j].gpa){
            v[k] = L[i];
            i++;
            k++;
        } else if(L[i].gpa > R[j].gpa) {
            v[k] = R[j];
            j++;
            k++;
        } else{
            if(L[i].surname == R[j].surname){
                if(L[i].name == R[j].name){
                    v[k] = L[i];
                    i++;
                    k++;
                } else{
                    if(L[i].name < R[j].name){
                        v[k] = L[i];
                        i++;
                        k++;
                    } else{
                        v[k] = R[j];
                        j++;
                        k++;
                }

                }
            } else{
                if(L[i].surname < R[j].surname){
                    v[k] = L[i];
                    i++;
                    k++;
                } else{
                    v[k] = R[j];
                    j++;
                    k++;
                }

            }
        }
    }

    while(i < n1){
        v[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        v[k] = R[j];
        j++;
        k++;
    }

}

void mergeSort(vector<person>&v, int l, int r){
    if(l < r){
        int m = (l+r)/2;

        mergeSort(v, l, m);
        mergeSort(v, m+1, r);

        merge(v, l, m ,r);
    }
}

int main(){
    int n;
    cin >> n;
    vector<person>p(n);
    for(int i = 0; i < n;i++){
        int m;
        cin >> p[i].surname >> p[i].name >> m;
        int cnt_subjects = 0; double sum_of_gpa = 0;
        for(int i = 0; i < m;i++){
            string s; int x;
            cin >> s >> x;
            if(s == "A+") sum_of_gpa += (4.0 * x);
            if(s == "A") sum_of_gpa += (3.75 * x);
            if(s == "B+") sum_of_gpa += (3.5 * x);
            if(s == "B") sum_of_gpa += (3.0 * x);
            if(s == "C+") sum_of_gpa += (2.5 * x);
            if(s == "C") sum_of_gpa += (2.0 * x);
            if(s == "D+") sum_of_gpa += (1.5 * x);
            if(s == "D") sum_of_gpa += (1.0 * x);
            if(s == "F") sum_of_gpa += (0 * x);

            cnt_subjects+=x;
        }
        p[i].gpa = sum_of_gpa / cnt_subjects;
    }

    mergeSort(p, 0, n-1);

    for(int i = 0; i < n;i++){
        cout << p[i].surname << " " << p[i].name << " " << fixed << setprecision(3) << p[i].gpa << "\n";
    }

}