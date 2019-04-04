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

void init()
{
	Poterm Head;
	int32_t x;
	char_t *str;
	printf( "�������һ������ʽ��" );

	Head = PolyIdentify("0");
    x = 2;
    while ( x != 0 )
	{
		switch (x){
		case 1: 
	    break;
		
		case 2:
	    scanf("%s",str);
	    Head = function2 ( str );
	    output( Head );
		break;
		
		case 3:
	    scanf("%s",str);
	    Head = function3 ( str );
	    output( Head );
	    break;
		
		case 4: 
	    scanf("%s",str);
	    Head = function4 ( str );
	    output( Head );
	    break;
		
		case 5:
		output(Head);
		break;
		
		case 0: 
		break;
		}
		scanf( "%d", &x );
        if ( x != 0 ) {
        	printf("����ѡ��\n");
	        printf("1-����ʽ����\n");
	        printf("2-����ʽ�ӣ�+��\n");
	        printf("3-����ʽ����-��\n");
	        printf("4-����ʽ�ˣ�*��\n");
	        printf("5-����ʽ���\n");
	        printf("0-�˳�\n");
        }
	}
}
Poterm function1 (char *str)
{
    return ( PolyIdentify(str) ) ;
}
Poterm function2 (char *str)
{
	return ( ADD( Head1 ,  function1 (str) ) );
}
Poterm function3 (char *str)
{
	return ( MINUS( Head1 ,  function1 (str) ) );
}
Poterm function4 (char *str)
{ 
	return ( MULTIPLE( Head1 ,  function1 (str) ) );
}


void output(Poterm t)
{
	
	if(Head!=NULL){
		if( Head->co >0 ){
			if( Head->co == 1 ) {
			  if( Head->x == 1) printf("xy^%lf\n",Head->y);
			  else if (Head->y == 1) printf("x^%lfy\n",Head->x);
		   }
		   else printf("%lfx^%lfy^%lf",Head->co,Head->x,Head->y);
		}
	    if( Head->co <0 ){
	    	if ( Head->co == -1 ){
			  if( Head->x == 1) printf("-xy^%lf\n",Head->y);
			  else if (Head->y == 1) printf("-x^%lfy\n",Head->x);
			  else printf("%lfx^%lfy^%lf",Head->co,Head->x,Head->y);
		    }
	    }
	    if( Head->co == 0) ;
		Head=Head->next;
	}
	while(Head!=NULL)
	{
		if( Head->co >0 ){
			if( Head->co == 1 ) {
			  if( Head->x == 1) printf("+xy^%lf\n",Head->y);
			  else if (Head->y == 1) printf("+x^%lfy\n",Head->x);
		   }
		   else printf("+%lfx^%lfy^%lf",Head->co,Head->x,Head->y);
		}
	    if( Head->co <0 ){
	    	if ( Head->co == -1 ){
			  if( Head->x == 1) printf("-xy^%lf\n",Head->y);
			  else if (Head->y == 1) printf("-x^%lfy\n",Head->x);
			  else printf("%lfx^%lfy^%lf",Head->co,Head->x,Head->y);
		    }
	    }
	    if( Head->co == 0) ;
		Head=Head->next;
	}
}
