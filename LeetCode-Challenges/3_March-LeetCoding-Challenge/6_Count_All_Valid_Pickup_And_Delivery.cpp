#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    long long getModulo(long long num){
        int m = 1e9 + 7;
        return (num%m + m)%m;
    }
    
    long long addModulo(long long a, long long b){
        return getModulo(getModulo(a) + getModulo(b));
    }
    
    long long mulModulo(long long a, long long b){
        return getModulo(getModulo(a) * getModulo(b));
    }
    
    int getFact(int num){
        vector<long long> fact(501, 0);
        fact[0] = 1;
        fact[1] = 1;
        
        for(int i=2; i<fact.size(); i++){
            fact[i] = mulModulo(fact[i-1], (long long)i);
        }
        
        return fact[num];
    }
    
    int getFactor(int num){
        vector<long long> fac(501, 0);
        fac[0] = 1;
        for(int i=1; i<fac.size(); i++){
            fac[i] = mulModulo(fac[i-1], 2*(i+1)-1);
        }
        
        return fac[num];
    }
    
    int countOrders(int n) {
        return mulModulo(getFact(n), getFactor(n-1));
    }
};

int main(){
    Solution sol;
    cout << sol.countOrders(300) << endl;
}