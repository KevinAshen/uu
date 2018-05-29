//在遍历时就要计算每一局分别得分 并不能最后除
//应该将每一场的比分存入数组
//或者说结束标志是一方达到11||21？ 
//不好 这样搞不出每一局的 问题在于如何同时处理两场比赛，需要两组 
#include<stdio.h>
#include<string.h>
#define maxn 1000
int main (void)
{
	int len,score_hua=0,score_dui=0,score_hua_21=0,score_dui_21=0;
	int hua_11[maxn],hua_21[maxn],dui_11[maxn],dui_21[maxn];
	int i,flag=1,i1=0,j1=0;
	char s[maxn];
	while (flag!=0) {
		scanf ("%s",s);
		len=strlen(s);
		for (i=0;i<len;i++) {
			if (s[i]=='E') {
				flag=0;
				break;
			}
			if (s[i]=='W') {
				score_hua++;
				score_hua_21++;
			}
			if (score_hua==11) {
				hua_11[i1]=11;
				dui_11[i1]=score_dui;
				score_hua=0;
				score_dui=0;
				i1++;
			}
			if (score_hua_21==21) {
				hua_21[j1]=21;
				dui_21[j1]=score_dui_21;
				score_hua_21=0;
				score_dui_21=0;
				j1++;
			}
			if (s[i]=='L') {
				score_dui++;
				score_dui_21++;
			}
			if (score_dui==11) {
				dui_11[i1]=11;
				hua_11[i1]=score_hua;
				score_dui=0;
				score_hua=0;
				i1++;
			}
			if (score_dui_21==21) {
				dui_21[j1]=21;
				hua_21[j1]=score_hua_21;
				score_dui_21=0;
				score_hua_21=0;
				j1++;
			}
		}
	}
	//printf ("%d %d",score_hua,score_dui);
	dui_11[i1]=score_dui;
	hua_11[i1]=score_hua;
	dui_21[j1]=score_dui_21;
	hua_21[j1]=score_hua_21;
	for (i=0;i<i1+1;i++) {
		printf ("%d:%d\n",hua_11[i],dui_11[i]);
	}
	printf ("\n");
	for (i=0;i<j1+1;i++) {
		printf ("%d:%d\n",hua_21[i],dui_21[i]);
	}
	return 0;
} 
