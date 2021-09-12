//                             Sort a stack
// Link - https://practice.geeksforgeeks.org/problems/sort-a-stack/1


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s){
    while (!s.empty()){
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main(){
    int t;
    cin >> t;
    while(t--){
        SortedStack *ss = new SortedStack();
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            int k;
            cin >> k;
            ss -> s.push(k);
        }
        ss -> sort();
        printStack(ss -> s);
    }
}
// } Driver Code Ends



void mainSort(stack <int> &s, int top){
    if(s.empty()) {
        s.push(top);
        return;
    }
    int temp = top;
    top = max(top, s.top());
    int bottom = min(temp, s.top());
    s.pop();
    mainSort(s, bottom);
    s.push(top);
}

void SortedStack :: sort(){
   if(s.size() <= 1) return;
   int top = s.top();
   s.pop();
   sort();
   if(top < s.top()) mainSort(s, top);
   else s.push(top);
}