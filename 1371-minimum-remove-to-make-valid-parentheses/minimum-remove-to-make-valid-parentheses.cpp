class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        vector<bool> remove(s.length(),false);

        for(int i=0;i<s.length();i++){

            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){

                if(!st.empty()){
                    st.pop();
                }

                else{
                    remove[i]=true;
                }
            }
        }
        while(!st.empty()){
            remove[st.top()]=true;
            st.pop();
        }

        string ans="";
        for(int i=0;i<s.length();i++){
            if(!remove[i]){
                ans+=s[i];
            }
        }
        return ans;
    }
};