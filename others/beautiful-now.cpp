/*********************** 
 c++ file 
***********************/

#include<iostream> 
#include<cstdio> 
#include<vector> 
#include<map> 
#include<algorithm> 
#include<string> 
#include<cstring> 
#include<set> 
#include<cmath> 
#include<queue> 
#include<fstream> 
#include<ctime> 
#include<iomanip> 
#include<bitset> 
#include<cstdlib> 
#include<deque> 
#include<list> 
#include<stack> 
#include<utility> 
 
#define ll long long 
#define inf 0x3f3f3f3f 
 
using namespace std; 
 
const int M = 1000*1000+10; 
const int MM=10000;
int k;

void swa(int ww[MM],int a,int b)
{
    int tt=ww[a];
    ww[a]=ww[b],ww[b]=tt;
}


string a;
int c[20],q[20],q1[20],p[20],len;
int minn,maxx;
 
void update()
{
	if(c[p[1]]==0) return; //第一位数字是0，不符合规则
	for(int i=1;i<=len;i++) q[i]=p[i]; //q数组内保存全排列后的位置
	int k1=0,s=0;
	for(int i=1;i<=len;i++)
	{
		s=s*10+c[p[i]];
		if(q[i]!=i) //如果当前位数字更改了
		{
			for(int j=i+1;j<=len;j++)
			{
				if(q[j]==i)
				{
					swap(q[i],q[j]);
					k1++;
					if(k1>k) return;
					break;
				}
			}
		}
	}
	if(k1>k) return;//转换了超过k次，就不行，可以的话，再看
	maxx=max(maxx,s);
	minn=min(minn,s);
}
void acsolve()
{
		memset(q,0,sizeof(q));
		memset(q1,0,sizeof(q1));
		for(int i=1;i<=len;i++)
		{
			c[i]=a[i-1]-'0';
			q[c[i]]++;
			q1[c[i]]++;
		}
		//if(k>=len-1)  //直接得到最大最小!!!不加等于就TLE
		//{
			//for(int i=1;i<=9;i++)
			//{
				//if(q[i])
				//{
					//printf("%d",i);
					//q[i]--;
					//break;
				//}
			//}
			//for(int i=0;i<=9;i++)
			//{
				//while(q[i])
				//{
					//printf("%d",i);
					//q[i]--;
				//}
			//}
			//printf(" ");
			//for(int i=9;i>=0;i--)
			//{
				//while(q1[i])
				//{
					//printf("%d",i);
					//q1[i]--;
				//}
			//}
			//printf("\n");
			//continue;
		//}
		for(int i=1;i<=len;i++) p[i]=i;  //每一位数字原来保存在哪里
		minn=2e9,maxx=-1;
		do
		{
			update();
		}
		while(next_permutation(p+1,p+len+1)) ;//全排列
		//printf("%d %d\n",minn,maxx);
}



 
int main() 
{ 
    fstream in("data.txt",ios::in);
    int t;
    in>>t;
    while(t--)
    {
        string s;
        in>>s>>k;
        a=s;
        int num[MM];
        int tp=0;
        tp=s.size();
        len=tp;
        for(int i=tp-1,j=0;i>-1;++j,--i)
        {
            num[j]=s[i]-'0';
        }
        acsolve();
        //}
        if(k>10)
        {
            sort(num,num+tp);
            int fr=0;
            while(num[fr]==0) fr++;
            cout<<num[fr];
            for(int i=0;i<tp;++i)
                if(i!=fr) cout<<num[i];
            cout<<" ";
            for(int i=tp-1;i>-1;--i)
                cout<<num[i];
            cout<<endl;
        }
        else
        {
            int ori[MM];
            int tmp[MM];
            int pre[20];
            int pre_min=-1;
            for(int i=0;i<tp;++i)
                pre[i]=ori[i]=tmp[i]=num[i];
            int mi=tp-1;
            for(int i=0;i<tp-1;++i)
                if(tmp[i]<tmp[mi]&&tmp[i]!=0)
                    mi=i;
            ll cnt=0;
            if(mi!=tp-1) 
            {
                pre_min=tmp[mi];
                swa(tmp,tp-1,mi);
                ++cnt;
            }
            int cur=tp-2;
            while(cnt<k&&cur>-1)
            {
                mi=cur;
                for(int i=0;i<cur;++i)
                    if(tmp[i]<tmp[mi])
                        mi=i;
                if(mi!=cur)
                {
                    bool sign=1;
                    if(tmp[mi]!=pre_min)
                    {
                        for(int i=0;i<tp;++i)
                            pre[i]=tmp[i];
                        pre_min=tmp[mi];
                        sign=0;
                    }
                    swa(tmp,cur,mi);
                    ++cnt;
                    if(sign)
                    {
                        for(int i=0;i<mi;++i)
                        {
                            if(pre[i]==pre_min)
                                if(tmp[i]<tmp[mi])
                                    swa(tmp,i,mi);
                        }
                    }
                }
                --cur;
            }
            int mymin=0;
            for(int i=tp-1;i>-1;--i)
                mymin*=10,mymin+=tmp[i];
            if(mymin!=minn)
            {
                cout<<s<<" "<<k<<endl<<mymin<<" "<<minn<<endl<<endl;
            }
            //cout<<" ";


            cur=tp-1;
            cnt=0;
            int pre_max=-1;
            while(cnt<k&&cur>=0)
            {
                mi=cur;
                for(int i=0;i<cur;++i)
                    if(num[i]>num[mi])
                        mi=i;
                if(mi!=cur)
                {
                    bool sign=1;
                    if(pre_max!=num[mi])
                    {
                        for(int i=0;i<tp;++i)
                            pre[i]=num[i];
                        pre_max=num[mi];
                        sign=0;
                    }
                    swa(num,cur,mi);
                    ++cnt;
                    if(sign)
                    {
                        for(int i=0;i<mi;++i)
                            if(pre[i]==pre[mi])
                                if(num[i]>num[mi])
                                    swa(num,i,mi);
                    }
                }
                --cur;
            }
            int mymax=0;
            for(int i=tp-1;i>-1;--i)
                mymax*=10,mymax+=num[i];
            if(mymax!=maxx)
            {
                cout<<s<<" "<<k<<endl<<mymax<<" "<<maxx<<endl<<endl;
            }
                //cout<<num[i];
            //cout<<endl;
        }
    }
    return 0; 
} 

