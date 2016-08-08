#include<cstdio>
#include<ctime>
#include<cstring>
#include<cstdlib>
#include<windows.h>
#include<cmath>

int lei,leinum,xnum,ynum,x,y,startxy[2];
int neigou=0,shengyu;
bool donghua=0,shengyin=0;

char a[42][42],b[42][42],c[42][42];

void shuoming(){
	puts("懒得写 自己悟\n");
//	Sleep(1000);
}

void shuchu(){	
	if(donghua){
		puts("正在加载...");
		Sleep(100);
	}
	for(int i=0;i<=xnum;i++)printf("%2d",i);
	printf("\n");
	for(int j=1;j<=ynum;j++){
		printf("%2d ",j);
		for(int i=1;i<=xnum;i++){ 
			printf("%c ",a[i][j]);///////////
			if(donghua){
				if(shengyin)
					Beep(1000,10);
				else
					Sleep(10);
			}
		}
		putchar('\n');
	}
	//printf("debug %d",shengyu);
}

void shuchu1(){
	if(donghua){
		puts("正在加载...");
		Sleep(100);
	}
	for(int i=0;i<=xnum;i++)printf("%2d",i);
	putchar('\n');
	for(int j=1;j<=ynum;j++){
		printf("%2d ",j);
		for(int i=1;i<=xnum;i++){ 
			printf("%c ",b[i][j]);
			if(donghua){
				if(shengyin)
					Beep(1000,10);
				else
					Sleep(10);
			}
		}
		putchar('\n');
	}
}

void shuchu2(){
	if(donghua){
		puts("正在加载...");
		Sleep(100);
	}
	for(int i=0;i<=xnum;i++)printf("%2d",i);
	printf("\n");
	for(int j=1;j<=ynum;j++){
		printf("%2d ",j);
		for(int i=1;i<=xnum;i++){
			printf("* ");
			if(donghua){
				if(shengyin)
					Beep(1000,10);
				else
					Sleep(10);
			}
		}
		putchar('\n');
	}
}

void ready(int xnum,int ynum,int leinum){
	for(int i=0;i<=xnum+1;i++)
		for(int j=0;j<=ynum+1;j++)
			a[i][j]=b[i][j]='*';
	lei=0;
	srand((unsigned)time(0));
	while(lei<leinum){
		x=rand() % (xnum+1);
		if(x<1)x=1;
		if(x>xnum)x=xnum;
		y=rand() % (ynum+1);
		if(y<1)y=1;
		if(y>ynum)y=ynum;
		if(x==startxy[0]&&y==startxy[1]);
		else if(b[x][y]!='$'){
				b[x][y]='$';
				lei++;
			}
	}
	for(int i=1;i<=xnum;i++)
		for(int j=1;j<=ynum;j++){
			//shuchu();
			//cout<<i<<' '<<j;
			if(b[i][j]=='$')continue;
			int nn=0;
			if(b[i-1][j-1]=='$')nn++;
			if(b[i-1][j]=='$')nn++;
			if(b[i-1][j+1]=='$')nn++;
			if(b[i][j-1]=='$')nn++;
			if(b[i][j+1]=='$')nn++;
			if(b[i+1][j-1]=='$')nn++;
			if(b[i+1][j]=='$')nn++;
			if(b[i+1][j+1]=='$')nn++;
			b[i][j]=(char)nn+'0';
		}
	shengyu=xnum*ynum;
}

void panduan1(int x,int y){
	a[x][y]=b[x][y];
	if(b[x][y]!='0')return;
	if(c[x][y])return;
	c[x][y]=1;
	shengyu--;
	panduan1(x-1,y-1);
	panduan1(x-1,y);
	panduan1(x-1,y+1);
	panduan1(x,y+1);
	panduan1(x,y-1);
	panduan1(x+1,y-1);
	panduan1(x+1,y);
	panduan1(x+1,y+1);
}

int panduan(int x,int y){
	char buf[20];
	if(x==0&&y==0)return 0;
	else if(x<1||x>xnum||y<1||y>ynum)
		puts("不存在此坐标 请重新输入");
	else if(b[x][y]=='$'){
		a[x][y]='$';
		puts("啊哦，这里是雷哦");
		shuchu1();
		puts("输入任意字符以重新开始");
		scanf("%s",buf);
		return 0;
	}
	else if(shengyu==leinum){
		puts("！！！恭喜你成功了！！！");
		shuchu1();
		puts("输入任意字符以重新开始");
		scanf("%s",buf);
		return 0;
	} 
	else if(b[x][y]=='0'){
		memset(c,0,sizeof(c));
		panduan1(x,y);
		puts("这里是：0");
		shuchu();
	}
	else{
		a[x][y]=b[x][y];
		printf("这里是：%c\n",b[x][y]);
		shuchu();
		shengyu--; 
	}
	return 1;
}

void zidingyi(){
	puts("请输入棋盘长度（3~35）");
	scanf("%d",&xnum);
	if(xnum<3){xnum=3; puts("过小，自动纠正为 3\n");Sleep(500);}
	if(xnum>35){xnum=35; puts("过大，自动纠正为 35\n");Sleep(500);}
	
	puts("请输入棋盘宽度（3~35）");
	scanf("%d",&ynum);
	if(ynum<3){ynum=3; puts("过小，自动纠正为 3\n");Sleep(500);}
	if(ynum>35){ynum=35; puts("过大，自动纠正为 35\n");Sleep(500);}
	
	puts("请输入雷数");
	while(1){
		scanf("%d",&leinum);
		if(leinum+1<xnum*ynum)break;
		puts("数量太大，请重新输入");Sleep(500);
	}
	if(leinum<1){leinum=1; puts("最小为 1，已自动纠正\n");Sleep(500);}
}

int main()
{ 
	puts("===================================================================");
	puts("这里是：");
	puts("                            扫雷dos版");
	puts("                                                          v2.1Alpha");
	puts("===================================================================");
	puts("注意！本游戏不提供保存功能                   更新日志请查看附带文档");
	printf("正在启动"); Sleep(250);
	putchar('.'); Sleep(250);
	putchar('.'); Sleep(250);
	putchar('.'); Sleep(250);
	putchar('.'); Sleep(250);
	putchar('.'); Sleep(250);
	putchar('.'); Sleep(250);
	putchar('\n');
	char buf[20];
	puts("是否开启动画？（1.开启（默认） 0.关闭）");
	scanf("%s",buf);
	donghua=buf[0]-'0';
	printf("动画已设置为 "); if(donghua)puts("开"); else puts("关");
	Sleep(500);
	puts("是否开启声音（有些电脑不支持）？（1.开启（默认） 0.关闭）");
	scanf("%s",buf);
	shengyin=buf[0]-'0';
	printf("声音已设置为 "); if(shengyin)puts("开"); else puts("关");
	Sleep(500);
	puts("是否需要帮助信息（输入'Y'以获得帮助）");
	char ch;
	scanf("%s",&ch);
//	getchar();
	if(ch=='y'||ch=='Y')
		shuoming();
	Sleep(1000);
	while(1){
		int cc;
		puts("请选择棋盘类型：\n1.简单 2.适当（默认） 3.困难 4.更难（谨慎尝试） 5.自定义\n输入 0 以退出");
		scanf("%d",&cc);
		if(cc>5)cc=2;
		switch(cc){
			case 0:puts("如果没有退出请按任意字符");
				   return 0;
			case 1:xnum=ynum=5;
				   leinum=4;
				   break;
			case 2:xnum=ynum=10;
				   leinum=12;
				   break;
			case 3:xnum=ynum=20;
				   leinum=35;
				   break;
			case 4:xnum=ynum=30;
				   leinum=100;
				   break;
			case 5:zidingyi();
		}
		puts("棋盘初始化成功");
		shuchu2();
		puts("等待指令...(输入 0 0 坐标以重新开始)");
		scanf("%d %d",&startxy[0],&startxy[1]);
		if(startxy[0]==0&&startxy[1]==0)continue;
		while(startxy[0]<1||startxy[0]>xnum||startxy[1]<1||startxy[1]>ynum){
			puts("不存在此坐标 请重新输入\n");
			scanf("%d %d",&startxy[0],&startxy[1]);
		}
		ready(xnum,ynum,leinum);
		panduan(startxy[0],startxy[1]);
		while(1){
			puts("等待指令...(输入 0 0 坐标以重新开始)\n");
			scanf("%d %d",&x,&y);
			if(!panduan(x,y))break;
		}
	}
	return 0;
}
