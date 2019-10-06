class Solution {

public:
    stack<char> myS;
    map<char, char> chars;
    
    bool isValid(string s) {
        stack<char> myFinalS;
        chars['('] = ')', chars[')'] = '(';
        chars['{'] = '}', chars['}'] = '{';
        chars['['] = ']', chars[']'] = '[';
        string ans;
        
        //test case 0 or 1
        if (s == "") return true;
        if (s.length() == 1) return false;
        
        parLoop(s);
        
        return (myS.empty()) ? true : false;
    }
    
    void parLoop(string str) {
        //first iteration, stack would be empty hence push. else segment fault 
        myS.push(str[0]);
       
        //loop through each string and push this to a Stack
        //O(n)
        for (int i=1; i < str.length(); i++ ) { //why =
            //if next itr is the same (on top of queue) keep injecting 

            //I need this because if not myS will be empty then I get errors b/c I
            //want to access the top
            if ( myS.empty() ) { 
                myS.push(str[i]); 
             } else if (myS.top() == str[i]) {  
                   //found an equal so keep pushing up the stack
                 myS.push(str[i]); 
             } else if ((myS.top() != str[i]) && (chars[myS.top()] == str[i] ) ) {
                  //if next is not same remove only if the next is its own opposite (pop)
                  //if true there will ALWAYS be a closing bracket coming up eventually
                  //if next is not same and not opposite keep on going 
                myS.pop();
             } else {
                //else push
                //push because theres nothing equal(which doens't matter here (second if))
                //but theres nothing to close 
                myS.push(str[i]);
            }
        }
    }
};







class Solution {

public:
    stack<char> myS;
    map<char, char> chars;
    
    bool isValid(string s) {
        stack<char> myFinalS;
        chars['('] = ')', chars[')'] = '(';
        chars['{'] = '}', chars['}'] = '{';
        chars['['] = ']', chars[']'] = '[';
        string ans;
        
        //test case 0 or 1
        if (s == "") return true;
        if (s.length() == 1) return false;
        
        parLoop(s);
        
        return (myS.empty()) ? true : false;
    }
    
    void parLoop(string str) {
        //first iteration, stack would be empty hence push. else segment fault 
        myS.push(str[0]);
       
        //loop through each string and push this to a Stack
        //O(n)
        for (int i=1; i < str.length(); i++ ) { //why =
            //if next itr is the same (on top of queue) keep injecting 

            //I need this because if not myS will be empty then I get errors b/c I
            //want to access the top
            if ( myS.empty() ) { 
                myS.push(str[i]); 
             }  else if ((myS.top() != str[i]) && (chars[myS.top()] == str[i] ) ) {
                  //if next is not same remove only if the next is its own opposite (pop)
                  //if true there will ALWAYS be a closing bracket coming up eventually
                  //if next is not same and not opposite keep on going 
                myS.pop();
             } else { 
                //(I removed the second if, its doing the same thing as this)
                //else push
                //push because theres nothing equal(which doens't matter here (second if))
                //but theres nothing to close 
                myS.push(str[i]);
            }
        }
    }
};