#include<stdio.h>
int main()
{
	int a[12][20]={0};
	a[1][1]=5;
	a[2][1]=4;
	a[3][1]=3;
	a[4][1]=2;
	a[5][1]=1;
	int x,y,X,Y;
	char con;
	
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<20;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	
	while(scanf("%c",&con))
	{
		getchar();
		//找到蛇头并记录位置 
		for(int i=0;i<12;i++)
		{
			for(int j=0;j<20;j++)
			{
				if(a[i][j]==1)
				{
					y=i;
					x=j;
				}
			}
		}
		X=x;Y=y;
		//递归蛇身计算 
		for(;a[y][x];)
		{
			if(a[y+1][x]==a[y][x]+1)
			{
				a[y][x]=a[y+1][x];
				y++;
			}
			
			else if(a[y-1][x]==a[y][x]+1)
			{
				a[y][x]=a[y-1][x];
				y--;
			}
			
			else if(a[y][x+1]==a[y][x]+1)
			{
				a[y][x]=a[y][x+1];
				x++;
			}
			
			else if(a[y][x-1]==a[y][x]+1)
			{
				a[y][x]=a[y][x-1];
				x--;
			}
			else
			a[y][x]=0;
			
		}
		//命令控制蛇体移动 
		switch(con)
		{
			case 'l':a[Y][X-1]=1;break;
			case 'r':a[Y][X+1]=1;break;
			case 'd':a[Y+1][X]=1;break;
			case 'u':a[Y-1][X]=1;break;
				
		}
		//打印图像 
		for(int i=0;i<12;i++)
		{
			for(int j=0;j<20;j++)
				printf("%d ",a[i][j]);
			printf("\n");
		}
		

	}
	return 0;
}
