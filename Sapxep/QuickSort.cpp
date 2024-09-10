#include <iostream>
using namespace std ;
// tăng dần
void Quicksort (int a[] , int left , int right){  
    int x ;                 
    int i , j ;            
    if (left >= right){
        return ;
    }                           
    x = a[(left + right)/2];             // x = a[1] = 6 
    i = left ;                           // i = 0   left = 0 
    j = right ;                          // j = 3   right = 3 
    while (i<j){                         // i = 2  
        while (a[i] < x) i++ ;           // j = 2
        while (a[j] > x) j-- ;          // i = 0  , left =0 (gọi hàm lần 1 ) 
        if ( i <=j){                     // j = 2  , right =2 ;
            swap (a[i] , a[j]);          // x = a[1] =5 
            i++ ;                         // i = 2 
            j-- ;                         // j = 0 ;
        }                                //  i=2  j =3 gọi hàm lần 2 
    }                                    // x = [2] = 7 ;
        Quicksort (a ,left ,j);          
        Quicksort (a , i , right);
}
/***
 n=4   
     4 6 7 5 -> 4 5 7 6 -> 4 5 6 7
     7 6 4 5 -> 7 6 5 4
pos  0 1 2 3
i = 0 j = 3;
x = a[1] = 6;
i = 0 j = 2;
i = 1 j = 1
qui 1
i = left = 0, j = 1
x = a[i] = 6;
i = 1, j = 1
i = 2, j = 0
qui 2
i = 2, right = 3;
x = a[2] = 4;
i = 2 j = 3;
i = 3 j = 2
 ***/
int main (){
    int a[100];
    int n ;
    cin>>n;
    for (int i=0 ; i<n;i++){
        cin>>a[i];
    }
    Quicksort (a,0,n-1);
    for (int i=0 ; i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0 ;
}

// giảm dần
#include <iostream>
using namespace std;
void QuickSort(int a[], int left, int right) {
    int x, i, j;
    if(left >= right) return;
    x = a[(left + right) / 2];
    i = left; j = right;
    while(i < j) {
        while(a[i] > x) i++;
        while(a[j] < x) j--;
        if(i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    }
    QuickSort(a, left, j);
    QuickSort(a, i, right);
}
int main() {
    int n, a[100];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    QuickSort(a, 0, n - 1);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}