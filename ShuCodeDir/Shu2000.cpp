//  main.cpp
//  qqq
//
//  Created by 高松 on 16/4/9.
//  Copyright © 2016年 yisa. All rights reserved.
//

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int T;
    cin>>T;
    int F[11];
    int count;
    int s;
//    for(int i=0;i<10;i++){
//        cout<<F[i];
//    }
//    cout<<endl;
    while(T--)
    {
        int n,m;
        memset(F,0,sizeof(F));
        //    for(int i=0;i<10;i++){
        //        cout<<F[i];
        //    }
        //    cout<<endl;
        cin>>m;
        int i=0;
        count=0;
        n=m;
        while(n!=0)
        {
            F[i]=n%10;
            if(F[i]==8)
                count++;
            n=n/10;
            i++;
        }
        //    for(int i=0;i<10;i++){
        //        cout<<F[i];
        //    }
        //    cout<<endl;
        if(count==3)
            cout<<m<<endl;
        else
        {
            if(count<3)
            {
                //    for(int i=0;i<10;i++){
                //        cout<<F[i];
                //    }
                //    cout<<endl;
                for(int j=0;j<=10;j++)
                {
                    //    for(int i=0;i<10;i++){
                    //        cout<<F[i];
                    //    }
                    //    cout<<endl;
                    if(F[j]<8)
                    {
                        F[j]=8;
                        count++;
                    }
                    else if(F[j]>8)
                    {
                        //    for(int i=0;i<10;i++){
                        //        cout<<F[i];
                        //    }
                        //    cout<<endl;
                        F[j]=8;
                        count++;
                        //    for(int i=0;i<10;i++){
                        //        cout<<F[i];
                        //    }
                        //    cout<<endl;
                        for(int k=j+1;k<=10;k++)
                        {
                            if(F[k]!=8)
                            {
                                F[k]++;
                                while(F[k]==10)
                                {
                                    //    for(int i=0;i<10;i++){
                                    //        cout<<F[i];
                                    //    }
                                    //    cout<<endl;
                                    int w;
                                    F[k]=0;
                                    for(w=k+1;w<=10;w++)
                                        if(F[w]!=8)
                                        {
                                            F[w]++;
                                            break;
                                        }
                                    k=w;
                                }
                                //    for(int i=0;i<10;i++){
                                //        cout<<F[i];
                                //    }
                                //    cout<<endl;
                                break;
                            }
                        }
                    }
                    if(count==3)
                        break;
                }
            }
            else if(count>3)
            {
                //    for(int i=0;i<10;i++){
                //        cout<<F[i];
                //    }
                //    cout<<endl;
                s=0;
                for(int j=i-1;j>=0;j--)
                {
                    if(F[j]==8)
                        s++;
                    if(s==4&&F[j]==8)
                    {
                        //    for(int i=0;i<10;i++){
                        //        cout<<F[i];
                        //    }
                        //    cout<<endl;
                       F[j]=9;
                        for(int k=j-1;k>=0;k--)
                            F[k]=0;
                        break;
                    }
                }
            }
            //    for(int i=0;i<10;i++){
            //        cout<<F[i];
            //    }
            //    cout<<endl;
            bool flag =false;;
            for(int j=10;j>=0;j--)
            {
                if(F[j]!=0)
                    flag = true;
                if(flag)
                    cout<<F[j];
            }
            cout<<endl;
        }
    }
    return 0;
}
