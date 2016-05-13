//
//  main.cpp
//  Compilers
//
//  Created by 李一帆nanak on 16/5/11.
//  Copyright © 2016年 李一帆nanak. All rights reserved.
//

#include <iostream>
using namespace std;

char prog[80];//整个程序字符串
char ch;//指针所指的字符
int syn;//单词种别码,
int p;//指针的位置
int sum;//整型常数
string temp;//暂时存放取到的单词
char* keywords[8] = {"if","int","for","while","do","return","break","continue"};
char* operationalSymbol[10] = {"+","-","*","/","=","<",">",">=","<=","!="};
char* partitionSymbol[6] = {",",";","(",")","{","}"};

int isKeywords(string a){
    for (int i = 0; i < 8; i++) {
        string temp = keywords[i];
        if (temp == a) {
            return 1;
        };
    };
    return 0;
};

int isLetter(char a){
    if((a >='a'&&a<='z')||(a>='A'&&a<='Z')){
        return 2;
    }else
        return 0;
}

int isDigit(char a){
    if(a >='0'&&a<='9'){
        return 3;
    }else
        return 0;
}

int isOperationalSymbol(char a){
    for (int i = 0; i < 10; i++) {
        char temp = *operationalSymbol[i];
        if (temp == a) {
            return 4;
        };
    };
    return 0;
}

int isPartitionSymbol(char a){
    for (int i = 0; i < 6; i++) {
        char temp = *partitionSymbol[i];
        if (temp == a) {
            return 5;
        };
    };
    return 0;
}

int main(int argc, const char * argv[]) {
    
    p = 0;
    cout<<"Please enter your code:"<<endl;
    
    do{
        cin.get(ch);
        prog[p++] = ch;
    }while (ch!='#');
    
//    int count = 0;
//    do{
//        cout<<prog[count];
//        count++;
//    }while (prog[count]!= '#');
//    cout<<endl;
    
    cout<<"The answer is as below:"<<endl;
    for (int i = 0; i < p; i++) {
        
        if(isLetter(prog[i])){
            
            //取词
            int j = i;
            do{
                temp = temp + prog[j];
                i++;
                if (!isLetter(prog[j+1])) {
                    break;
                }
            }while(isLetter(prog[j++]));
            i--;
            
            if (isKeywords(temp)) {
                
                syn = isKeywords(temp);
                cout<<"("<<syn<<","<<"'"<<temp<<"'"<<")"<<endl;
                temp = "";
            }else{
                
                syn = 2;
                cout<<"("<<syn<<","<<"'"<<temp<<"'"<<")"<<endl;
                temp = "";
            }
        }else if(isDigit(prog[i])){
            
            //取数字
            int j = i;
            do{
                temp = temp + prog[j];
                i++;
                if (!isDigit(prog[j+1])) {
                    break;
                }
            }while(isDigit(prog[j++]));
            i--;
            
            syn = 3;
            cout<<"("<<syn<<","<<"'"<<temp<<"'"<<")"<<endl;
            temp = "";
        }else if(isOperationalSymbol(prog[i])){
            
            syn = isOperationalSymbol(prog[i]);
            cout<<"("<<syn<<","<<"'"<<prog[i]<<"'"<<")"<<endl;
        }else if(isPartitionSymbol(prog[i])){
            
            syn = isPartitionSymbol(prog[i]);
            cout<<"("<<syn<<","<<"'"<<prog[i]<<"'"<<")"<<endl;
        }else if(prog[i] == ' '){
            
        }else if(prog[i] == '\n'){
            
        }
    }
    return 0;
}


