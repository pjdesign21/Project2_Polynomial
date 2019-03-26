/****************************************************************************
 * \brief       
 * \copyright   2018-2019, Zhejiang University, Program Design Project, Group 6. 
 * \verson      1.0
 * \author      
 * \file        Polynomial_Identify.c
 * 
 * \date 2019/03/25 Fang :created
****************************************************************************/
#include "Polynomial_Identify.h"
#include <stdlib.h>
#include <stdio.h>
static double_t ReadNum(char *str,int32_t *l)
{
	double_t num,Time;
	num=0;
	Time=1;
	bool_t HaveDot,Minu;
	Minu=HaveDot=False;
	if(str[*l]=='-')
	{
		Minu=True;(*l)++;
	}
	while((str[*l]>='0'&&str[*l]<='9')||str[*l]=='.')
	{
		if(str[*l]=='.')
		{
			HaveDot=True;
			(*l)++;
			continue;
		}
		if(HaveDot==True)Time*=10;
		num*=10;
		num+=str[*l]-'0';
		(*l)++;
	}
	if(Minu==True)num=-num;
	num/=Time;
	if(num==0)return -1;
	return num;
}
static int32_t Isnum(char ch)
{
	if(ch=='-'||ch=='+'||(ch>='0'&&ch<='9'))
	return 1;
	return 0;
}
static int32_t Isx(char ch){return ch=='x'?1:0;}
static int32_t Isy(char ch){return ch=='y'?1:0;}
Poterm PolyIdentify(char *str)
{
	int32_t l;
	l=0;
	bool_t Px,Py,Co;
	double_t Num,Cofficient,Powerofx,Powerofy;
	Poterm Head;
	Head=(Poterm)malloc(sizeof(struct Term));
	Head->x=0;Head->y=0;Head->co=0;Head->next=NULL;
	while(str[l]!='\0')
	{
		if(Isnum(str[l]))
		{
			Co=True;
			Cofficient=ReadNum(str,&l);
		}
		if(Isx(str[l]))
		{
			if(Co==False)Cofficient=1; 
			Px=True;
			if(str[l+1]!='^')
			{
				Powerofx=1;
				l++;
			}
			else
			{
				l+=2;
				Powerofx=ReadNum(str,&l);
			}
		}
		if(Isy(str[l]))
		{
			if(Co==False)Cofficient=1; 
			Py=True;
			if(str[l+1]!='^')
			{
				Powerofy=1;
				l++;
			}
			else
			{
				l+=2;
				Powerofy=ReadNum(str,&l);
			}
		}
		if(Px==True&&Py==True)
		{
			Creat(Head,Powerofx,Powerofy,Cofficient);
			Co=Px=Py=False;
		}
	}
	return Head;
}
/*int main()
{
	char str[10000];
	scanf("%s",str);
	Poterm Head;
	Head=PolyIdentify(str);
	Head=Head->next;
	while(Head!=NULL)
	{
		printf("%lf,%lf,%lf\n",Head->x,Head->y,Head->co);
		Head=Head->next;
	}
	return 0;
}*/
