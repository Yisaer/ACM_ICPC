//
//  main.cpp
//  计算几何
//
//  Created by 高松 on 16/3/12.
//  Copyright © 2016年 yisa. All rights reserved.
//
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;
const double eps = 1e-8;
const double PI = acos(-1.0);

int sgn (double x){
    if(fabs(x)<eps) return 0 ;
    if(x<0) return -1;
    else return 1;
}

struct Point {
    double x,y;
    Point(){}
    Point(double _x,double _y){
        x=_x;
        y=_y;
    }
    Point operator - (const Point &b)const {
        return Point(x-b.x,y-b.y);
    }
    //叉乘
    double operator ^ (const Point &b)const {
        return x*b.y-y*b.x;
    }
    //点积
    double operator * (const Point &b)const {
        return x*b.x+y*b.y;
        
    }
    void transXY(double B){
        double tx=x,ty=y;
        x= tx*cos(B)-ty*sin(B);
        y= tx*sin(B)+ty*cos(B);
    }
};

//Line
struct Line{
    Point s,e;
    Line(){};
    Line(Point _s,Point _e){
        s=_s;
        e=_e;
    }
    //两直线相交求交点
    //第一个值为0表示直线重合 为1表示平行
    pair<int,Point> operator & (const Line &b) const {
        Point res = s;
        if(sgn((s-e)^(b.s-b.e))==0)
        {
            if(sgn((s-b.e)^(b.s-b.e))==0){
                return make_pair(0,res);//重合
                
            }
            else return make_pair(1,res);//平行
                }
        double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
        res.x+=(e.x-s.x)*t;
        res.y+=(e.y-s.y)*t;
        return make_pair(2,res);
    }
    
};

//两点间距离

double dis(Point a ,Point b){
    return sqrt((a-b)*(a-b));
    
}

//计算多边形面积
double CalcArea(Point p[],int n){
    
    double res = 0;
    for(int i=0;i<n;i++){
        res+=(p[i]^p[(i+1)%n])/2;
    }
    return fabs(res);
}


//判断凸多边形

bool isconvec(Point poly[],int n){
    
    bool s[3];
    memset(s,false,sizeof(s));
    for(int i=0;i<n;i++){
        s[sgn((poly[(i+1)%n]-poly[i])^(poly[(i+2)%n]-poly[i]))+1]=true;
        if(s[0]&&s[2]) return false;
    }
    return true;
}


int main (){
    int n;
    while(cin>>n){
    Point p[10];
    for(int i=0;i<n;i++){
        cin>>p[i].x>>p[i].y;
    }
    cout<<CalcArea(p,n)<<endl;
    }
}


