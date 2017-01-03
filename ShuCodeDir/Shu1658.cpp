using namespace std;
#include <string>


string AnsString;

/*


2
3
50 50
20 10 30
3
50 50
10  40 30
*/
using namespace std ;
class Loading {
public :
    int n ;//集装箱数
    int w[40] ;//集装箱重量数组
    int c ;//第一搜轮船的载重量
    int cw;//当前载重量
    int bestw;//当前最优载重量
    int r;//剩余集装箱重量
public :
    int maxLoading( string str)
    {
        cw = 0 ;
        bestw = 0;

        //初始化r

        backtrack(1,str);
        //计算最优解
        return bestw;

    }
    void backtrack(int i,string str )
    {

        int j;
        //搜索第i层结点
        if(i>n)
            //到达叶子结点
        {
            if(cw>bestw){

                bestw = cw ;
                AnsString = str;

            }

            return;
        }
        //
        //搜索子树
        //！！！
        r -=w[i];
        if(cw+w[i]<=c)
        {
            //搜索左子树
            cw+=w[i];
            backtrack(i+1,str+'1');
            cw-=w[i];
        }
        if(cw+r>bestw)
        {

            backtrack(i+1,str+'0');
        }
        r+=w[i];
    }

};



int main()
{

    Loading load ;
    int T ;
    int j =1 ;

    int c1 ;
    while( cin>>load.n)
    {
        string tmp = "";
        for(int  i =1;i<=load.n;i++){
            tmp+='1';
        }
        string str = "";
        int i =1 ;
        int sum = 0;
        load.r =0 ;
        while(i<=load.n)
        {
            cin>>load.w[i];
            load.r=load.r+load.w[i];
            //   cout<<"第"<<i<<"个集装箱"<<load.w[i]<<endl;
            sum+=load.w[i];
            i++;

        }
        cin>>load.c;
        cin>>c1;
        // cout<<"sum:"<<sum<<endl;
        load.maxLoading(str);
        if(load.bestw>0&& ((sum-load.bestw)<=c1))
        {
            cout<<"Case "<<j<<endl;
            cout<<load.bestw<<" "<<AnsString<<endl;
        }else if(sum<=c1){
            cout<<"Case "<<j<<endl;
            cout<<load.bestw<<" "<<tmp<<endl;
        }else{
            cout<<"Case "<<j<<endl;
            cout<<"No"<<endl;
        }
        load.bestw = 0 ;
        load.c = 0;
        load.cw = 0;
        load.n  = 0 ;
        load.r = 0 ;
        int b =1 ;
        for(  ;  b <40 ; b ++)
            load.w[b]=0;
        T--;
        j++;
    }
    return 0 ;
}
