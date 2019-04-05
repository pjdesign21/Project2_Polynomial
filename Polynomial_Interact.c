/****************************************************************************
 * \brief       
 * \copyright   2018-2019, Zhejiang University, Program Design Project, Group 6. 
 * \verson      1.0
 * \author      
 * \file        Polynomial_Interact.c
 * 
 * \date 2019/03/25 Fang :created
****************************************************************************/

#include "Polynomial_Interact.h"

extern void init()
{
	Poterm Head = PolyIdentify("0");
    int32_t x = 2;
	char_t *str;
	printf( "Input the first Polynomial\n" ); 
    while ( x != 0 )
	{
		switch (x)
		{
			case 1: 
				break;
			
			case 2:
				scanf("%s",str);
				Head = ADD( Head, PolyIdentify(str) );
				output( Head );
				break;
			
			case 3:
				scanf("%s",str);
				Head = MINUS( Head, PolyIdentify(str) );
				output( Head );
			break;
			
			case 4: 
				scanf("%s",str);
				Head = MULTIPLE( Head, PolyIdentify(str) );
				output( Head );
			break;
			
			case 5:
				output(Head);
				break;
			
			case 0: 
				break;
		}
        if ( x != 0 ) 
		{
        	printf("Input the numbers\n");
	        printf("1-Polynomial Input\n");
	        printf("2-Polynomial Addition(+)\n");
	        printf("3-Polynomial Substraction(-)\n");
	        printf("4-Polynomial Multiplication(*)\n");
	        printf("5-Polynomial Output\n");
	        printf("0-Exit\n");
        }
		scanf( "%d", &x );
	}
}

static void output(Poterm t)
{
	Poterm first_term;
	first_term = t = t->next; 
	if(t == NULL) printf( "0" );
    while ( t != NULL )
    {
    	if ( t != first_term )
			printf( "%c%lf", op(t), t->co );
        else 
			printf( "%lf", t->co );
		
		if ( t->x != 0 )
		{
			printf( "x" );
			if ( t->x != 1 ) printf( "^%d", t->x );
		}

		if ( t->y != 0 )
		{
			printf( "y" );
			if ( t->y != 1 ) printf( "^%d", t->y );
		}

		t = t->next;
    }
	printf( "\n" );
}

static char_t op( Poterm t )
{
	if ( t->co > 0 ) 
		return '+';
	else if( t->co < 0 ) 
		return '-';
}