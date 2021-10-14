#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int m=0,n=4;
int cal(int temp[10][10],int t[10][10])
{
	int i,j,m=0;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
		{
			if(temp[i][j]!=t[i][j])
                m++;
		}
	return m;
}

int check(int a[10][10],int t[10][10])
{
	int i,j,f=1;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			if(a[i][j]!=t[i][j])
				f=0;
	return f;
}
void main()
{
	int p,i,j,n=4,a[10][10],t[10][10],temp[10][10],r[10][10];
	int m=0,x=0,y=0,d=1000,dmin=0,l=0,x1,y1;
    printf("\nEnter the matrix to be solved,space with zero :\n");
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			scanf("%d",&a[i][j]);
    printf("\nEnter the target matrix,space with zero :\n");
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			scanf("%d",&t[i][j]);
    printf("\nEntered Matrix is :\n");
	for(i=0;i < n;i++)
	{
		for(j=0;j < n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}

	printf("\nTarget Matrix is :\n");
	for(i=0;i < n;i++)
	{
		for(j=0;j < n;j++)
			printf("%d\t",t[i][j]);
		printf("\n");
	}
    int ch;
    printf("\n");
    printf("1.Solve using computer\n2.Solve manually\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        while(!(check(a,t)))
        {
            l++;
            d=1000;
            for(i=0;i < n;i++)
                for(j=0;j < n;j++)
                {
                    if(a[i][j]==0)
                    {
                        x=i;
                        y=j;
                    }
                }
            //To move upwards
            for(i=0;i < n;i++)
                for(j=0;j < n;j++)
                    temp[i][j]=a[i][j];
            if(x!=0)
            {
                p=temp[x][y];
                temp[x][y]=temp[x-1][y];
                temp[x-1][y]=p;
            }
            m=cal(temp,t);
            dmin=l+m;
            if(dmin < d)
            {
                d=dmin;
                for(i=0;i < n;i++)
                    for(j=0;j < n;j++)
                        r[i][j]=temp[i][j];
            }
            //To move downwards
            for(i=0;i < n;i++)
                for(j=0;j < n;j++)
                    temp[i][j]=a[i][j];
            if(x!=n-1)
            {
                p=temp[x][y];
                temp[x][y]=temp[x+1][y];
                temp[x+1][y]=p;
            }
            m=cal(temp,t);
            dmin=l+m;
            if(dmin < d)
            {
                d=dmin;
                for(i=0;i < n;i++)
                    for(j=0;j < n;j++)
                        r[i][j]=temp[i][j];
            }
            //To move right side
            for(i=0;i < n;i++)
                for(j=0;j < n;j++)
                    temp[i][j]=a[i][j];
            if(y!=n-1)
            {
                p=temp[x][y];
                temp[x][y]=temp[x][y+1];
                temp[x][y+1]=p;
            }
            m=cal(temp,t);
            dmin=l+m;
            if(dmin < d)
            {
                d=dmin;
                for(i=0;i < n;i++)
                    for(j=0;j < n;j++)
                        r[i][j]=temp[i][j];
            }
            //To move left
            for(i=0;i < n;i++)
                for(j=0;j < n;j++)
                    temp[i][j]=a[i][j];
            if(y!=0)
            {
                p=temp[x][y];
                temp[x][y]=temp[x][y-1];
                temp[x][y-1]=p;
            }
            m=cal(temp,t);
            dmin=l+m;
            if(dmin < d)
            {
                d=dmin;
                for(i=0;i < n;i++)
                    for(j=0;j < n;j++)
                        r[i][j]=temp[i][j];
            }
            printf("\nCalculated Intermediate Matrix Value :\n");
            for(i=0;i < n;i++)
            {
                for(j=0;j < n;j++)
                printf("%d\t",r[i][j]);
			printf("\n");
            }
            for(i=0;i < n;i++)
                for(j=0;j < n;j++)
                {
                    a[i][j]=r[i][j];
                    temp[i][j]=0;
                }
        }
        getch();
    case 2:
        for(i=0;i < n;i++)
        {
                for(j=0;j < n;j++)
                {
                    if(a[i][j]==0)
                    {
                        x1=i;
                        y1=j;
                    }
                }
        }
        int ch1;
        while(1)
        {
            printf("1.Up\n2.Down\n3.Left\n4.Right\n");
            printf("Choose your next move");
            scanf("%d",&ch1);
            switch(ch)
            {
            case 1:
                if(x1!=0)
                {
                    p=temp[x1][y1];
                    temp[x1][y1]=temp[x1-1][y1];
                    temp[x1-1][y1]=p;
                }
            case 2:
                if(x1!=n-1)
                {
                    p=temp[x1][y1];
                    temp[x1][y1]=temp[x1+1][y1];
                    temp[x1+1][y1]=p;
                }
            case 3:
                if(y1!=0)
                {
                    p=temp[x1][y1];
                    temp[x1][y1]=temp[x1][y1-1];
                    temp[x1][y1-1]=p;
                }
            case 4:
                if(y1!=n-1)
                {
                    p=temp[x1][y1];
                    temp[x1][y1]=temp[x1][y1+1];
                    temp[x1][y1+1]=p;
                }
            }

        }
    }
}

