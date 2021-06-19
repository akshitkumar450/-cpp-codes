char* reverse(char *S, int len)
{
    //code here
    stack<char>st;
    for(int i=0;i<len;i++){
        st.push(S[i]);
    }

    int i=0;
    while(!st.empty()){
        char ch=st.top();
        st.pop();
    S[i]=ch;
        i++;
    }
    return S;
}