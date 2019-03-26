/****************************************************************************
 * \brief       
 * \copyright   2018-2019, Zhejiang University, Program Design Project, Group 6. 
 * \verson      1.0
 * \author      
 * \file        Polynomial_Base.h
 * 
 * \date 2019/03/25 Fang :created
****************************************************************************/
typedef char char_t;
typedef int int32_t;
typedef *Term Poterm
typedef double double_t
typedef enum { False, True } bool_t;
typedef enum { Add=0 ,Minus, multiple, Divide}operator_t

typedef struct
{
	double_t x,y;				//power of x,y
	double_t co;					//coefficient of the term
	Term *next;
}Term;
/****************************************************************************
 * Function:    OpType 
 * Brief:       Return the type of Operator
 * Param [in]:  char
 * Param [out]: operator_t
 * Author:      Fang
 * Date:        2019/03/25
****************************************************************************/
extern operator_t OpType(char op);
