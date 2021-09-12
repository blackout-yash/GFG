//                                    Power Set Using Recursion
// Link - https://practice.geeksforgeeks.org/problems/power-set-using-recursion/1/?track=sp-recursion&batchId=105#

#include <bits/stdc++.h>
using namespace std;

void subset(string inp, string out, vector <string> &v){
    if(inp.empty()){
        if(!out.empty())v.push_back(out);
        return;
    }
    string s1 = inp.substr(0,1), s2 = inp.substr(1);
    subset(s2, out, v);
    subset(s2, out+s1, v);
}

vector <string> powerSet(string s){
    vector <string> v;
    string o;
    subset(s, o, v);
return v;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        
        vector<string> ans = powerSet(s);
        
        sort(ans.begin(),ans.end());
        
        for(auto x: ans)
        cout << x << " ";
        cout << endl;   
    }
return 0;
}   