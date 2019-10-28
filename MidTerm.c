#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define num 10
#define Num (6*num)
#define number (2*num)

void creatnum(double* a);
void calcul(double* a,double* b);
void assign(double* a,double* b,char* c);
int* sort(double *nu);
void input(int *a);

struct stuterm
{
	char nam;
    double stuNum;
	double linu;
	double python;
	double java;
	double html;
	double hb;
	double cyy;
	double ave;
	double sum;
}stunum[num];

 int main()
{
	double score[Num];
	double aver[number];
	char name[num]={'A','B','C','D','E','F','G','H','I','J'};
	double *p=&score[0],*q=&aver[0];
    int sor[Num];
    int *n=&sor[0];
	char *m=&name[0];
    creatnum(p);
	calcul(p,q);
	assign(p,q,m);
    n=sort(q);
    input(n);
    return 0;
}

void creatnum(double* a)
{
    int i60=0,i90=0;
    double data;
    srand((unsigned)time(NULL));
    for(int i=0;i<Num;i++)
    {
        data=rand()%101;
        if(data<60)
        {
            if(i60>=6)
                i--;
            else
            {
                a[i]=data;
                i60++;
            }
        }
        else if(data>90)
        {
            if(i90>=6)
                i--;
            else
            {
                a[i]=data;
                i90++;
            }
        }
        else
        a[i]=data;
    }
}

void calcul(double* a,double* b)
{
    int i=0,j=0,js=0,k=0;
    double sum1=0,ave1=0;
    for(int i=0;i<Num;i++)
    {
        sum1+=a[i];
        js++;
        if(js%6==0)
        {
            ave1=sum1/6.0;
            b[k]=ave1;
            b[k+1]=sum1;
            sum1=0;
            k=k+2;
        }
    }
}

void assign(double* a,double* b,char* c)
{
    int i=0,j=0,k=0;
    double n=201723010200;
    for(int m=0;m<num;m++)
    {
        stunum[m].nam=c[i];
        stunum[m].stuNum=++n;
	    stunum[m].linu=a[j];
	    stunum[m].python=a[j+1];
    	stunum[m].java=a[j+2];
    	stunum[m].html=a[j+3];
    	stunum[m].hb=a[j+4];
    	stunum[m].cyy=a[j+5];
    	stunum[m].ave=b[k];
    	stunum[m].sum=b[k+1];
    	i++;
    	j=j+6;
    	k=k+2;
    }

}
int* sort(double *nu)
{
    int a[10]={0,1,2,3,4,5,6,7,8,9};
    
    double b[10000];
    int n=1;
    for(int k=0;k<num;k++)
    {
        b[k]=nu[n];
        n=n+2;
    }
    for(int i=0;i<num-1;i++)
        for(int j=0;j<num-i-1;j++)
            if(b[j]>b[j+1])
            {
                int tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
		int tm=b[j];
                b[j]=b[j+1];
                b[j+1]=tm;
            }
    int *p=&a[0]; 
    return p;
}
void input(int *a)
{
    printf("name\tstuNum\t\tlinux\tpython\tjava\thtml\thb\tcyy\tave\tsum\n");
    for(int m=0;m<num;m++)
    {
        printf("%c\t%.0lf\t%.0lf\t%.0lf\t%.0lf\t%.0lf\t%.0lf\t%.0lf\t%.2lf\t%.2lf\n",stunum[a[m]].nam,stunum[a[m]].stuNum,stunum[a[m]].linu,stunum[a[m]].python,stunum[a[m]].java,stunum[a[m]].html,stunum[a[m]].hb,stunum[a[m]].cyy,stunum[a[m]].ave,stunum[a[m]].sum);
    }
}
