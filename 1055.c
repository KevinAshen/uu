//也就是要按频率进行降序排序 然后在按照字典顺序输出依次的颜色 
#include<stdio.h>
#include<string.h>
struct balloon {
	char colour [20];
	int counter;
}kid[100];
int main (void)
{
	struct balloon t;
	int N,num_colour,num_now;
	int i,j,flag,max,i1;
	char colour[20];
	for (i=0;i<101;i++) {
		kid[i].counter=0;
	}
	i=0;
	scanf ("%d",&N);
	while (N--) {
		flag=0;
		scanf ("%s",colour);
		for (j=0;j<i+1;j++) {
			if (strcmp(colour,kid[j].colour)==0) {
				kid[j].counter++;
				flag=1;
				break;
			}
		}
		if (flag==0) {
			kid[i].counter++;
			strcpy(kid[i++].colour,colour);
		}
	} 
	//printf ("%s %d %s %d",kid[0].colour,kid[0].counter,kid[1].colour,kid[1].counter);
	//以上将颜色写入 并统计了每个颜色的数目 此时i代表有几种颜色
	num_colour=i;
	//for (i=0;i<num_colour;i++) {
	//	printf ("%s %d\n*************\n",kid[i].colour,kid[i].counter);
	//}
	for (i=0;i<num_colour-1;i++) {
		for (j=i+1;j<num_colour;j++) {
			if ((kid[i].counter<kid[j].counter)||(kid[i].counter==kid[j].counter&&(strcmp(kid[i].colour,kid[j].colour)>0))) {
				t=kid[i];
				kid[i]=kid[j];
				kid[j]=t;
			}
		}
	}
	//for (i=0;i<num_colour;i++) {
	//	printf ("%s %d\n",kid[i].colour,kid[i].counter);
	//}
	//printf ("%s %d %s %d",kid[0].colour,kid[0].counter,kid[1].colour,kid[1].counter);
	//以上 将颜色按照频率降序排序 接下来要对相同的按字典排序 
	//??我们完全可以先按照字典排序 不对 还是老实点吧
	//不过这个有点麻烦啊。。。 
	//试试 试试又不会怀孕 
	//试完了 斌没有用 老实点吧 
	//首先找出同一counter的kid 
	max=0;
	for (i=0;i<num_colour;i++) {
		if (max<kid[i].counter) {
			max=kid[i].counter;
		}
	}
	num_now=max;
	printf ("%d\n",num_colour);
	printf ("%d\n",num_now);
	for (i=0;i<num_colour;i++) {
		if (num_now==kid[i].counter) {
			printf ("%s\n",kid[i].colour);
		} else {
			num_now=kid[i].counter;
			printf ("%d\n",num_now);
			printf ("%s\n",kid[i].colour);
		}
	}
	return 0;
} 
