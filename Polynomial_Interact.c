/****************************************************************************
 * \brief       Console
 * \copyright   2018-2019, Zhejiang University, Program Design Project, Group 6. 
 * \verson      1.0
 * \author      Chenyun Lu
 * \file        Polynomial_Interact.c
 * 
 * \date 2019/03/25 Fang :created
****************************************************************************/

#include "Polynomial_Interact.h"

extern void init()
{
	Poterm Head = PolyIdentify("0");
    int32_t x = 2;
	char_t str[1000];
	bool_t j = False;
	printf( "Input the first Polynomial\n" ); 
    while ( x != 0 )											//exit if zero inputed
	{
		switch ( x )
		{
			case 1:												//clear
				printf( "Polynomial clear\n" ); 
				Head = MULTIPLY( Head, PolyIdentify( "0" ) );
				output( Head );
				break;
			
			case 2:
				if ( j == True )								//judge whether a polynomial has been inputed
					printf( "Input the Polynomial to be added\n" ); 
				else j = True;
				scanf("%s",str);
				Head = ADD( Head, PolyIdentify(str) );			//add 
				output( Head );
				break;
			
			case 3:
				printf( "Input the Polynomial to be substracted\n" ); 
				scanf("%s",str);
				Head = SUBSTRACT( Head, PolyIdentify(str) );	//substract
				output( Head );
				break;
			
			case 4: 
				printf( "Input the Polynomial to be multiplied\n" ); 
				scanf("%s",str);
				Head = MULTIPLY( Head, PolyIdentify(str) );		//multiply
				output( Head );
				break;
			
			case 5:
				output(Head);									//output
				break;
			
			case 0: 
				break;

			default:                                            
				Head = MULTIPLY( Head, PolyIdentify( "0" ) );	//clear
				Head = ADD( Head, PolyIdentify(str) );			//change into the newly inputed polynomial 
				output( Head );
				break;
		}
        if ( x != 0 ) output_guide();							//output the guide
        scanf("%s",str);										//scanf the option
		x = str[0] - '0';
	}
}

static void output_guide()
{	
	printf("！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("Input the numbers\n");
    printf("1-Polynomial Clear\n");
    printf("2-Polynomial Addition(+)\n");
    printf("3-Polynomial Substraction(-)\n");
    printf("4-Polynomial Multiplication(*)\n");
    printf("5-Polynomial Output\n");
    printf("0-Exit\n");
	printf("！！！！！！！！！！！！！！！！！！！！！！\n");
}

static void output(Poterm t)
{
	Poterm first_term;
	first_term = t = t->next; 
	printf("The solution:") ;
	if(t == NULL) printf( "0" );
    while ( t != NULL )
    {
    	if ( t != first_term && t->co > 0 )                     
			printf( "+" );
		else if ( t->co == -1 )
			printf( "-" );		  								//print the operator
        if ( t->co != 1 && t->co != -1 )
			printf( "%.1lf", t->co );							//print the coefficient       
		
		if ( t->x != 0 )                                        //exceptional case:the power of x is zero or one
		{
			printf( "x" );
			if ( t->x != 1 ) printf( "^%d", t->x );
		}
		if ( t->y != 0 )                                        //exceptional case:the power of y is zero or one
		{
			printf( "y" );
			if ( t->y != 1 ) printf( "^%d", t->y );
		}
		t = t->next;
    }
	printf( "\n" );
}
