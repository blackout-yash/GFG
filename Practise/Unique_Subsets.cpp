//                              Unique Subsets
// Link - https://practice.geeksforgeeks.org/problems/subsets-1587115621/1#


#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void subset(string inp, string out, set <string> &v){
        if(inp.empty()){
            string s = out;
            sort(s.begin(), s.end());
            v.insert(s);
            return;
        }
        string s1 = inp.substr(0,1), s2 = inp.substr(1);
        subset(s2, out, v);
        subset(s2, out+s1, v);
    }

    set <string> powerSet(string s){
        set <string> v;
        string o;
        subset(s, o, v);
    return v;
    }

    vector<vector<int>> AllSubsets(vector<int> arr, int n){
        string ss;
        for(int i = 0; i < n; i++) ss.push_back(char(48+arr[i]));
        set<string> s = powerSet(ss);
        vector<vector<int>> v;
        for(auto it = s.begin(); it != s.end(); it++){
            string temp = *it; vector <int> v1;
            for(int j = 0; j < temp.size(); j++){
                v1.push_back(temp[j]-'0');
            }v.push_back(v1);
        }
    return v;
    }
};


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> A;
        int x;
        for(int i = 0; i < n; i++){
            cin >> x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int>>result = obj.AllSubsets(A,n);

        for(int i = 0; i < result.size(); i++){
            cout << '(';
            for(int j = 0; j < result[i].size(); j++){
                cout << result[i][j];
                if(j < result[i].size()-1)
                    cout << " ";
            }
            cout << ")";
        }
        cout << "\n";
    }
return 0;
}