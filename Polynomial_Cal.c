/****************************************************************************
 * \brief       
 * \copyright   2018-2019, Zhejiang University, Program Design Project, Group 6. 
 * \verson      1.0
 * \author      
 * \file        Polynimial_Cal.c
 * 
 * \date 2019/03/25 Fang :created
****************************************************************************/

#include "Polynomial_Cal.h"

static Poterm coreverse( Poterm TermTobeReverse )
{
    Poterm p = TermTobeReverse->next;
    while ( p != NULL ) p->co *= -1, p = p->next;
    return TermTobeReverse;
}

static Poterm product( Poterm TermTobeMult, Poterm term )
{
    Poterm Result_term = ( Poterm )malloc( sizeof( struct Term ) );
    Result_term->next = NULL;
    Poterm p = Result_term;
    TermTobeMult = TermTobeMult->next;
    
    while ( TermTobeMult != NULL )
    {
        Creat( p, TermTobeMult->x + term->x, TermTobeMult->y + term->y, 
            TermTobeMult->co * term->co );
        TermTobeMult = TermTobeMult->next;
        p = p->next;
    }
    return Result_term;
}

extern Poterm ADD( Poterm First_term, Poterm Add_term )
{
    Poterm Result_term = ( Poterm )malloc( sizeof( struct Term ) );
    Poterm p = Result_term, a = First_term, b = Add_term;
    Result_term->next = NULL;

    First_term = a->next;
    Add_term = b->next;
    free( a );
    free( b );

    while ( First_term != NULL && Add_term != NULL )
    {
        a = First_term, b = Add_term;
        int32_t cmp = Powercmp( a, b );
        if ( cmp == 0 )
        {
            if ( a->co + b->co != 0 )
            {
                Creat( p, a->x, a->y, a->co + a->co );
                p = p->next;
            }
            First_term = a->next, Add_term = b->next;
            free( a ), free( b );
        } else
        {
            if ( cmp == -1 ) a = b;   
            p->next = a;
            First_term = a->next;
            p = p->next;
        }
    }
    if ( First_term != NULL ) p->next = First_term;
    else p->next = Add_term;

    return Result_term;
}

extern Poterm MINUS(Poterm First_term,Poterm Minus_term)
{
    return ADD( First_term, coreverse( Minus_term ) );
}

extern Poterm MULTIPLE(Poterm First_term,Poterm Multiple_term)
{
    Poterm Result_term = ( Poterm )malloc( sizeof( struct Term ) );
    Multiple_term = Multiple_term->next;
    Result_term->next = NULL;

	while ( Multiple_term != NULL )
    {
        Result_term = ADD( Result_term, product( First_term, Multiple_term ) );
        Multiple_term = Multiple_term->next;
    }
    return Result_term;
}