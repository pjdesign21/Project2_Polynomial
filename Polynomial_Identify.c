/****************************************************************************
 * \brief       
 * \copyright   2018-2019, Zhejiang University, Program Design Project, Group 6. 
 * \verson      1.0
 * \author      Fang
 * \file        Polynomial_Identify.c
 * 
 * \date 2019/03/25 Fang :created
****************************************************************************/


#include "Polynomial_Identify.h"

extern Poterm arrange( Poterm TermTobeArrange )
{
    Poterm p = TermTobeArrange->next;
    struct Term Tmp_term[ 10 ];
    int32_t n = 0,i;
    while ( p != NULL ) Tmp_term[ n++ ] = *p, p = p->next;
    qsort( Tmp_term, n, sizeof(Tmp_term[0]), Cmp);
    p = TermTobeArrange;
    for (  i = 0; i < n; i++ ) 
    {
        p->next->x = Tmp_term[ i ].x;
        p->next->y = Tmp_term[ i ].y;
        p->next->co = Tmp_term[ i ].co;
        p = p->next;
    }
    return TermTobeArrange;
}

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
	if(str[*l]=='+')
	(*l)++;
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
	if(num==0&&str[*l-1]=='0')
	return 0; 
	if(num==0)
		{
			if(Minu==True)return -1;
			else return 1;
		}
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
	double_t Num,Cofficient;
	int32_t Powerofx,Powerofy;
	Poterm Head;
	Head=(Poterm)malloc(sizeof(struct Term));
	Head->x=0;Head->y=0;Head->co=0;Head->next=NULL;
	while(str[l]!='\0')
	{
		if(Isnum(str[l]))
		{
			Co=True;
			Cofficient=ReadNum(str,&l);
			if((Isnum(str[l])||str[l]=='\0')&&Py==False&&Px==False)
			{ 
				Powerofx=Powerofy=0;
				Px=Py=True;
			}
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
			if(str[l]!='y'&&Py==False)
			{
				Py=True;
				Powerofy=0;
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
			if(str[l]!='x'&&Px==False)
			{
				Px=True;
				Powerofx=0;
			}
		}
		if(Px==True&&Py==True)
		{
			if(Cofficient!=0)
				Creat(Head,Powerofx,Powerofy,Cofficient);
			Co=Px=Py=False;
		}
	}
	return arrange(Head);
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
		printf("%d,%d,%lf\n",Head->x,Head->y,Head->co);
		Head=Head->next;
	}
	return 0;
}*/