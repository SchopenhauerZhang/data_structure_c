#include <iostream>
using namespace std;
#include <vector>

// 斐波那契数列优化1、
int fibo(int n,vector<int>& arr){
	if (n ==  0 ){
		return 0;
	}
	if (n==1 || n==2){
	    return 1;
	}
	if (arr[n] != 0){
	    return arr[n];
	}

	 return arr[n] = fibo(n-1,arr)+fibo(n-2,arr);
}

int call_fibo(int n){
    vector<int> arr(n+1,0);
    fibo(n,arr);
    for (int i =0;i<arr.size();i++){
	    cout << arr[i]<<"/"<<i<<"\n";
   	}

       return 0
}

// 斐波那契数列优化2、
// 「状态转移方程」？把 f(n) 想做一个状态 n，这个状态 n 是由状态 n - 1 和状态 n - 2 相加转移而来，
// 这就叫状态转移.
int dp_table(int n){
    vector<int> arr(n+1,0);
    if (n==1 || n==2){
        arr[n] = 1;
    }
    arr[1]=arr[2]=1;
    
    for (int i =3;i <= n;i++){
        arr[i]=arr[i-1]+arr[i-2];
        cout <<i<<"："<<arr[i]<<"\n";
        
    }
    
    return 0;
}

// 斐波那契数列优化3、空间复杂度为o(1)
int fn(int n){
    if (n ==0){
        return  0;
    } 
    if (n==1 || n==2){
        return 1;
    }
    int pre =1;
    int prep =1;
    for (int i =3;i <= n;i++){
        int sum = pre +  prep;
        prep = pre;
        pre = sum;
    }
    return pre;
}

int main(int argc, char * argv[]){
    int n = 10;
    
   	cout << "fibonaci deal one:\n";
    call_fibo(n);
    cout << "fibonaci deal second:\n";
    dp_table(n);
    cout << "fibonaci deal third:\n";
    fn(n);
   	
   	return 0;
}