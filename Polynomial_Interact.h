/****************************************************************************
 * \brief       
 * \copyright   2018-2019, Zhejiang University, Program Design Project, Group 6. 
 * \verson      1.0
 * \author      
 * \file        Polynomial_Interact.h
 * 
 * \date 2019/03/25 Fang :created
****************************************************************************/
//#include "Polynomial_Base.h"

#ifndef _POLYNOMIAL_INTERACT_H
#define _POLYNOMIAL_INTERACT_H

#include "Polynomial_Base.h"

/****************************************************************************
 * Function:    init
 * Brief:       form a interactive interface
 * Param [in]:  NA
 * Param [out]: NA
 * Author:      
 * Date:        2019/03/25
****************************************************************************/
extern void init();


/****************************************************************************
 * Function:    output
 * Brief:       Output the answer 
 * Param [in]:  Poterm t
 * Param [out]: NA
 * Author:      
 * Date:        2019/03/25
****************************************************************************/
static void output(Poterm t);

/****************************************************************************
 * Function:    
 * Brief:       Output the answer 
 * Param [in]:  Poterm t
 * Param [out]: NA
 * Author:      
 * Date:        2019/03/25
****************************************************************************/
static char_t op(Poterm t);

#endif