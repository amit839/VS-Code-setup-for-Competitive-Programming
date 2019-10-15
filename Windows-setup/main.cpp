#include<bits/stdc++.h>
using namespace std;

void testcase(){
    int n;
    cin >> n;
    cout << n * n;
} 

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cout.precision(10);
    cout << fixed;
#ifdef AKP 
    freopen("in.txt","r",stdin);
#endif
    int t = 1;
    //cin >> t;
    while(t--){
        testcase();
        cout << '\n';
    }

}