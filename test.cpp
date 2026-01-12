#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st ;
    vector<int> arr = {1,2,3,4,5};

    for(auto it: arr){
        st.push(it);
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop(); 
    }
}