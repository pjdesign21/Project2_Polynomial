/****************************************************************************
 * \brief       identification of the string polynomial
 * \copyright   2018-2019, Zhejiang University, Program Design Project, Group 6. 
 * \verson      1.2
 * \author      Fang
 * \file        Polynomial_Identify.h
 * 
 * \date 2019/03/25 Fang :created
****************************************************************************/


#ifndef _POLYNOMIAL_IDENTIFY_H
#define _POLYNOMIAL_IDENTIFY_H

#include "Polynomial_Base.h"


/****************************************************************************
 * Function:    Cmp
 * Brief:       function for qort
 * Param [in]:  const void *a , const void *b
 * Param [out]: int32_t
 * Author:      Fang
 * Date:        2019/03/25
****************************************************************************/
extern int32_t Cmp( const void *a , const void *b );


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

#endif
