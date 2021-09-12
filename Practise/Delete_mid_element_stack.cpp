//                        Delete middle element of a stack
// Link - https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1


#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void deleteMiddle(stack<int> &s, int sizeOfStack, int top){
        if(s.size()+1 <=  ceil(sizeOfStack/2.0)) return;
        int bottom = s.top();
        s.pop();
        deleteMiddle(s, sizeOfStack, bottom);
        s.push(top);

    }
    void deleteMid(stack<int> &s, int sizeOfStack){
        int bottom = s.top();
        s.pop();
        deleteMiddle(s, sizeOfStack, bottom);
    }
};

int main() {
    int t;
    cin >> t;
    
    while(t--){
        int sizeOfStack;
        cin >> sizeOfStack;
        
        stack<int> myStack;
        
        for(int i = 0; i < sizeOfStack; i++){
            int x;
            cin >> x;
            myStack.push(x);    
        }

        Solution ob;
        ob.deleteMid(myStack,myStack.size());
        while(!myStack.empty()){
            cout << myStack.top() << " ";
            myStack.pop();
        }
        cout << endl;
    }   
return 0;
}