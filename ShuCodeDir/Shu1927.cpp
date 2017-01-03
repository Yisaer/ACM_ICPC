//  main.cpp
//  Yaoge的超电磁炮
//
//  Created by 高松 on 15/11/27.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>

int const  CMax=10;
int Map[CMax][CMax];


int main(int argc, const char * argv[]) {
    int T;
    cin>>T;
    int cas=0;
    while(T--)
    {
        memset(Map,0,sizeof(Map));
        int N;
        cin>>N;
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
            {
                cin>>Map[i][j];
                Map[i][0]+=Map[i][j];
                Map[0][j]+=Map[i][j];
            }
      
        bool flag=true;
        int cnt=0;
        int dir=0; //1 横向 0 纵向
        int MaxIndex;
        while(flag==true)
        {
           
            cas++;
          //  cout<<"here"<<endl;
            //cout<<endl;
            int Max=0;
            flag=false;
            //cout<<"flag="<<flag<<endl;
            bool Hflag=true;
            bool Sflag=true;
            for(int i=1;i<=N;i++)
            {
                Hflag=true;
                Sflag=true;
                for(int j=1;j<=N;j++)
                {
                    if(Map[i][j]==-1)
                    {
                        Hflag=false;
                        break;
                    }
                    else if(Map[i][j]==1)
                    {
                        flag=true;
                  //      cout<<"flag i="<<i<<" j="<<j<<endl;
                    }
                }
              
                if(Hflag&&Map[i][0]>Max)
                {
                    Max=Map[i][0];
                    dir=1;
                    MaxIndex=i;
               //     cout<<"横向 Max="<<Max<<endl;
                    
                }
              //  cout<<"Max="<<Max<<endl;
                for(int j=1;j<=N;j++)
                {
                    if(Map[j][i]==-1)
                    {
                        Sflag=false;
                        
                    }
                    else if(Map[j][i]==1)
                    {
                        flag = true;
       //      cout<<"纵向 i="<<j<<" j="<<i<<endl;
                    }
                }
              //  cout<<"flag="<<flag<<endl;
                if(Sflag&&Map[0][i]>Max)
                {
                    Max=Map[0][i];
                    dir=0;
               //     cout<<"纵向 Max="<<Max<<endl;
                    MaxIndex=i;
                }
           
            }
           // cout<<"Max="<<Max<<" dir="<<dir<<endl;
            if(dir==1&&Max!=0)
            {
                cnt++;
                for(int j=1;j<=N;j++)
                {
                    if(Map[MaxIndex][j]==1)
                    {
                        Map[MaxIndex][j]=-1;
                        Map[0][j]--;
                        Map[MaxIndex][0]--;
                    }
                }
            }
            else if(dir==0&&Max!=0)
            {
                cnt++;
                for(int j=1;j<=N;j++)
                {
                    if(Map[j][MaxIndex]==1)
                    {
                        Map[j][MaxIndex]=-1;
                        Map[MaxIndex][0]--;
                        Map[0][j]--;
                    }
                }
                
            }
          //  cout<<"flag="<<flag<<endl;
            
            if(cas==6)
                break;
        }
        cout<<cnt<<endl;
    }
    
    
    return 0;
}
