class SortedStack{
public:
	stack<int> s;
	void sort();
};

void SortedStack(){
   stack<int>s2;
   while(!s.empty()){
        // pop out the first element
       int val=s.top();
       s.pop();
        //while temporary stack is not empty and top
        // of stack is greater than temp
       while(!s2.empty() and s2.top()>val){
            // pop from temporary stack and push
            // it to the input stack
           s.push(s2.top());
           s2.pop();
       }
        // push temp in tempory of stack
       s2.push(val);
   }

   while(!s2.empty()){
       cout<<s2.top()<<" ";
       s2.pop();
   }
}