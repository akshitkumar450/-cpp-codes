 
    node*One=NULL;
    node*Zero=NULL;
    node*two=NULL;
    node*OneIt=NULL;
    node*ZeroIt=NULL;
    node*twoit=NULL;
    node*temp=head;
    
    while(temp){
        if(temp->data==1){
            if(One==NULL){
                One=temp;
                OneIt=temp;
                temp=temp->next;
            } else{
                OneIt->next=temp;
                OneIt=OneIt->next;
                temp=temp->next;
            }
        } else if(temp->data==0){
            if(Zero==NULL){
                Zero=temp;
                ZeroIt=temp;
                temp=temp->next;
            } else{
                ZeroIt->next=temp;
                ZeroIt=ZeroIt->next;
                temp=temp->next;
            }
        } else if(temp->data==2){
            if(two==NULL){
                two=temp;
                twoit=temp;
                temp=temp->next;
            } else{
                twoit->next=temp;
                twoit=twoit->next;
                temp=temp->next;
            }
        }
    }
    
    print(Zero);
    print(One);
    print(two);
    // if(ZeroIt){
    //     if(ZeroIt) ZeroIt->next=One;
    //     if(OneIt) OneIt->next=two;
    //     twoit->next=NULL;
    //     return Zero;
    // } else if(OneIt) {
    //      if(OneIt) OneIt->next=two;
    //     // if(OneIt) OneIt->next=two;
    //     twoit->next=NULL;
    //     return One;
    // } else{
    //     if(twoit) 
    //         twoit->next=NULL;
    //     return two;
    // }
  
     