//
//  main.cpp
//  organizing a stack
//
//  Created by Shaan Diwanji on 5/23/17.
//  Copyright © 2017 Shaan Diwanji. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <stack>
using namespace std;

stack<int> func(stack<int> sta){
    
    stack<int> stamp;
    int comp = 0;
    
    bool disorganized = true;
    
    while (disorganized){
        
        comp = sta.top();
        sta.pop();
        while (!sta.empty()){
            
            if (sta.top() > comp){
                stamp.push(sta.top());
                sta.pop();
                // comp remains the same
            } else if (sta.top() <= comp){
                stamp.push(comp);
                comp = sta.top();
                sta.pop();
            }
            
        }
        
        stamp.push(comp);
        
        
        
        disorganized = false;
        int temp = stamp.top();
        stamp.pop();
        while (!stamp.empty()){
            sta.push(temp);
            if (stamp.top() < temp ){
                disorganized = true;
            }
            temp = stamp.top();
            stamp.pop();
        }
        sta.push(temp);
        
    }
    
    return sta;
}


int main(int argc, const char * argv[]) {

    stack<int> stack_example;
    stack_example.push(9);
    stack_example.push(6);
    stack_example.push(5);
    stack_example.push(8);
    stack_example.push(12);
    stack_example.push(10);
    stack_example.push(1);
    stack_example.push(3);
    stack_example.push(2);
    stack_example.push(7);
    stack_example.push(15);
    stack_example.push(14);
    stack_example.push(13);
    stack_example.push(4);
    stack_example.push(11);
    
    

    stack_example = func(stack_example);
    
    while (!stack_example.empty()){
        cout << stack_example.top() << endl;
        stack_example.pop();
    }
    
    return 0;
}
