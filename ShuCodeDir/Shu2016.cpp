#include <iostream>
using namespace std;



int main (){
    
    int a = 0;
    int cur = 0;
    while(cin>>a){
        if(a>300){
            
            for(int i=0;i<11;i++){
                cin>>a;
            }
            cout<<-1<<endl;
            continue;
        }
        cur = (300-a)%100;
        bool flag = true;
        int cun = (300-a)/100;
        int X = 0;
        for(int i=0;i<11;i++){
            cin>>a;
            if(flag){
            if(300+cur<a){
                X = i+2;
                flag = false;
                }
            }
            int tmp = cur;
            cur = (tmp+300-a)%100;
            cun+=(tmp+300-a)/100;
        }
        if(flag){
            cout<<cur+cun*100*1.2<<endl;
        }
        else{
            cout<<-X<<endl;
            
        }
        
    }
}

