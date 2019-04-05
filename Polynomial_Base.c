/****************************************************************************
 * \brief       
 * \copyright   2018-2019, Zhejiang University, Program Design Project, Group 6. 
 * \verson      1.0
 * \author      
 * \file        Polynomial_Base.c
 * 
 * \date 2019/03/25 Fang :created
****************************************************************************/

#include "Polynomial_Base.h" 

extern operator_t OpType(char op)
{
	if(op=='+')return Add;
	if(op=='-')return Minus;
}

extern int32_t Powercmp(Poterm term_1,Poterm term_2)
{
	double power_1,power_2;
	power_1=term_1->x+term_1->y;
	power_2=term_2->x+term_2->y;
	if(power_1>power_2)return 1;
	if(power_1<power_2)return -1;
	if(term_1->x>term_2->x)return 1;
	if(term_1->x<term_2->x)return -1;
	return 0;
}

extern int32_t Cmp( const void *a , const void *b ) 
{
	struct Term *c = (struct Term *)a; 
	struct Term *d = (struct Term *)b; 
	if(c->x+c->y != d->x+d->y) return d->x+d->y - c->x-c->y; 
	else return d->x - c->x; 
}

extern void Creat(Poterm TermTobeAdd,int32_t Powerx,int32_t Powery,double Cofficient)
{
	Poterm Newterm;
	Newterm=(Poterm)malloc(sizeof(struct Term));
	Newterm->x=Powerx;
	Newterm->y=Powery;
	Newterm->co=Cofficient;
	Newterm->next=TermTobeAdd->next;
	TermTobeAdd->next=Newterm;
}