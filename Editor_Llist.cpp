//
//  main.cpp
//  Editor
//
//  Created by 임채빈 on 06/11/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
using namespace std;
string s;
int N;

// node 구현
class node{
public:
    char c;
    node *left, *right;
    node(char _c){
        c = _c;
        left = right = NULL;
    }
};

// doubly linked list 구현
class Llist{
public:
    node* cursor;
    Llist(char c){
        node* newNode = new node(c);
        node* newNode2 = new node(' ');
        newNode -> right = newNode2;
        newNode2 -> left = newNode;
        cursor = newNode2;
    }
    void push(char c){
        node* newNode = new node(c);
        if(cursor -> left != NULL){
            cursor-> left -> right = newNode;
            newNode -> left = cursor -> left;
        }
        cursor -> left = newNode;
        newNode -> right = cursor;
    }
    
    void pop(){
        if(cursor -> left != NULL){
            node* temp = cursor -> left;
            if(temp -> left != NULL){
                cursor -> left = temp -> left;
                cursor -> left -> right = cursor;
            }else{
                cursor -> left = NULL;
            }
        }
    }
    
    void left(){
        if(cursor -> left != NULL){
            cursor = cursor -> left;
        }
    }
    
    void right(){
        if(cursor -> right != NULL){
            cursor = cursor -> right;
        }
    }
    
    void print(){
        while(cursor -> left != NULL){
            cursor = cursor -> left;
        }
        while(cursor -> right != NULL){
            cout << cursor -> c;
            cursor = cursor -> right;
        }
    }
};




int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    cin >> s >> N;
    Llist l = Llist(s[0]);
    for(int i = 1; i < s.length(); i++){
        l.push(s[i]);
    }
    for(int i = 0; i < N; i++){
        char input;
        cin >> input;
        if(input == 'L'){
            l.left();
        }else if(input == 'D'){
            l.right();
        }else if(input == 'B'){
            l.pop();
        }else if(input == 'P'){
            char input2;
            cin >> input2;
            l.push(input2);
        }
    }
    l.print();
    return 0;
}
