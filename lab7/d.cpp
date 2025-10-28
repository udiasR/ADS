#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct person{
    string surname;
    string name;
    double gpa;
};


void merge(vector<person>&v, int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;

    vector<person>L(n1), R(n2);
    for(int i = 0; i < n1;i++)L[i] = v[l+i];
    for(int j = 0; j < n2;j++)R[j] = v[m+1+j];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i].gpa < R[j].gpa){
            v[k] = L[i];
            i++;
            k++;
        } else if(L[i].gpa > R[j].gpa){
            v[k] = R[j];
            k++;
            j++;
        } else{
            if(L[i].surname < R[j].surname){
                v[k] = L[i];
                i++;
                k++;
            } else if(L[i].surname > R[j].surname){
                v[k] = R[j];
                k++;
                j++;
            } else{
                if(L[i].name < R[j].name){
                    v[k] = L[i];
                    k++;
                    i++;
                } else {
                    v[k] = R[j];
                    k++;
                    j++;
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

void mergeSort(vector<person>&v, int l , int r){
    if(l < r){
        int m = (l+r)/2;
        mergeSort(v, l, m);
        mergeSort(v, m+1, r);

        merge(v, l, m,r);
    }

}


double gpaGrad(string gp){
    if(gp == "A+")return 4.00;
    else if(gp == "A")return 3.75;
    else if(gp == "B+")return 3.50;
    else if(gp == "B")return 3.00;
    else if(gp == "C+")return 2.50;
    else if(gp == "C")return 2.00;
    else if(gp == "D+")return 1.50;
    else if(gp == "D")return 1.00;
    else return 0;
}

int main(){
    int n, m;
    cin >> n;

    vector<person> p1(100001);
    
    for(int i = 0; i < n;i++){
        cin >> p1[i].surname >> p1[i].name >> m;
        double gpascor = 0;
        int num_of_credits = 0;
        for(int j = 0; j < m;j++){
            string x;
            int t;
            cin >> x >> t;
            gpascor +=gpaGrad(x)*t;
            num_of_credits+=t;
        }
        p1[i].gpa = gpascor/num_of_credits;
    }

    mergeSort(p1, 0, n-1);

    for(int i = 0; i < n;i++){
        cout  << p1[i].surname << " " << p1[i].name << " "<< fixed << setprecision(3) << p1[i].gpa << "\n";
    }
     
}