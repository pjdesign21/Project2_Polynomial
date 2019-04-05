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

extern int32_t Cmp( const void *a , const void *b ) 
{
	struct Term *c = (struct Term *)a;
	struct Term *d = (struct Term *)b;
	if(c->x+c->y != d->x+d->y) return d->x+d->y - c->x-c->y; 
	else return d->x - c->x;
}

extern Poterm arrange( Poterm TermTobeArrange )
{
    Poterm p = TermTobeArrange->next;
    struct Term Tmp_term[ 20 ];//copy the link to an array
    int32_t n = 0,i;
    while ( p != NULL ) Tmp_term[ n++ ] = *p, p = p->next;
    qsort( Tmp_term, n, sizeof(Tmp_term[0]), Cmp);// use qsort function in the stl.
    p = TermTobeArrange;
    for (  i = 0; i < n; i++ )//recreate a new link
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
	if(num==0&&str[*l-1]=='0')//if the string is '0'
	return 0; 
	if(num==0)
		{
			if(Minu==True)return -1;//if the num is - in -xy.
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
	Py=Px=False;
	while(str[l]!='\0')
	{
		if(Isnum(str[l]))
		{
			Co=True;
			Cofficient=ReadNum(str,&l);
			if((Isnum(str[l])||str[l]=='\0')&&Py==False&&Px==False)//judge whether is a constant term
			{ 
				Powerofx=Powerofy=0;
				Px=Py=True;
			}
		}
		if(Isx(str[l]))
		{
			if(Co==False)Cofficient=1;//if there has no cofficient before term,like xy;
			Px=True;
			if(str[l+1]!='^')//if the power of x is 1, we generally write it as x instead of x^1
			{
				Powerofx=1;
				l++;
			}
			else
			{
				l+=2;
				Powerofx=ReadNum(str,&l);//Read the power of x;
			}
			if(str[l]!='y'&&Py==False)//if there is no y.
			{
				Py=True;
				Powerofy=0;
			}
		}
		if(Isy(str[l]))
		{
			if(Co==False)Cofficient=1; //if there has no cofficient before term,like xy;
			Py=True;
			
			if(str[l+1]!='^')//if the power of y is 1
			{
				Powerofy=1;
				l++;
			}
			else
			{
				l+=2;
				Powerofy=ReadNum(str,&l);//Read the power of x;
			}
			if(str[l]!='x'&&Px==False)//if there is no y.
			{
				Px=True;
				Powerofx=0;
			}
		}
		if(Px==True&&Py==True)//if record the all term
		{
			if(Cofficient!=0)
				Creat(Head,Powerofx,Powerofy,Cofficient);//creat a new link
			Co=Px=Py=False;//reset
		}
	}
	return arrange(Head);//arrange the link
}
