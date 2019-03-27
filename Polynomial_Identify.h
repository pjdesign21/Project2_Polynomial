/****************************************************************************
 * \brief       
 * \copyright   2018-2019, Zhejiang University, Program Design Project, Group 6. 
 * \verson      1.0
 * \author      
 * \file        Polynomial_Identify.h
 * 
 * \date 2019/03/25 Fang :created
****************************************************************************/
//#include "Polynomial_Base.h"
#include "Polynomial_Cal.c"
/****************************************************************************
 * Function:    arrange
 * Brief:       Arrange the term by power
 * Param [in]:  Poterm TermTobeArrange
 * Param [out]: Poterm
 * Author:      Liu
 * Date:        2019/03/27
****************************************************************************/
extern Poterm arrange( Poterm TermTobeArrange); 
/****************************************************************************
 * Function:    Isx
 * Brief:       define whether a char is 'x'
 * Param [in]:  char ch
 * Param [out]: int32_t
 * Author:      Fang
 * Date:        2019/03/26
****************************************************************************/
static int32_t Isx(char ch);
/****************************************************************************
 * Function:    Isy
 * Brief:       define whether a char is 'y'
 * Param [in]:  char ch
 * Param [out]: int32_t
 * Author:      Fang
 * Date:        2019/03/26
****************************************************************************/
static int32_t Isy(char ch);
/****************************************************************************
 * Function:    Isnum
 * Brief:       define whether a char is num
 * Param [in]:  char ch
 * Param [out]: int32_t
 * Author:      Fang
 * Date:        2019/03/26
****************************************************************************/
static int32_t Isnum(char ch);
/****************************************************************************
 * Function:    ReadNum
 * Brief:       Read a char string as a num
 * Param [in]:  char *str,int32_t *l
 * Param [out]: double_t
 * Author:      Fang
 * Date:        2019/03/26
****************************************************************************/
static double_t ReadNum(char *str,int32_t *l);
/****************************************************************************
 * Function:    PolyIdentify
 * Brief:       Indentify char string as a term
 * Param [in]:  char *str 
 * Param [out]: Poterm
 * Author:      
 * Date:        2019/03/25
****************************************************************************/
Poterm PolyIdentify(char *str);
