/****************************************************************************
 * \brief       
 * \copyright   2018-2019, Zhejiang University, Program Design Project, Group 6. 
 * \verson      1.0
 * \author      
 * \file        Polynomial_Base.h
 * 
 * \date 2019/03/25 Fang :created
****************************************************************************/
#include <stdlib.h>
typedef char char_t;
typedef int int32_t;
typedef struct Term *Poterm;
typedef double double_t;
typedef enum {Add,Minus}operator_t;

struct Term
{
	double_t x,y;				//power of x,y
	double_t co;					//coefficient of the term
	Poterm next;
};
/****************************************************************************
 * Function:    OpType 
 * Brief:       Return the type of Operator
 * Param [in]:  char
 * Param [out]: operator_t
 * Author:      Fang
 * Date:        2019/03/25
****************************************************************************/
extern operator_t OpType(char op);
<<<<<<< HEAD
=======
/****************************************************************************
 * Function:    Powercmop 
 * Brief:       compare the power of term,if powera>powerb return 1
 powera<powerb return -1 powera==powerb return 1
 * Param [in]:  Poterm term_1,Poterm term_2
 * Param [out]: int32_t
 * Author:      Fang
 * Date:        2019/03/25
****************************************************************************/
extern int32_t Powercmp(Poterm term_1,Poterm term_2);
/****************************************************************************
 * Function:    Creat
 * Brief:       creat a new node to the link
 * Param [in]:  Poterm TermTobeAdd,double Powerx,double Powery,double Cofficient
 * Param [out]: NA
 * Author:      Fang
 * Date:        2019/03/25
****************************************************************************/
extern void Creat(Poterm TermTobeAdd,double Powerx,double Powery,double Cofficient);
>>>>>>> parent of 8872f46... Revert "1.2"

