/****************************************************************************
 * \brief       Console
 * \copyright   2018-2019, Zhejiang University, Program Design Project, Group 6. 
 * \verson      1.2
 * \author      Chenyun Lu
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
 * Brief:       form an interactive interface
 * Param [in]:  NA
 * Param [out]: NA
 * Author:      Chenyun Lu
 * Date:        2019/04/03
****************************************************************************/
extern void init();

/****************************************************************************
 * Function:    output_guide
 * Brief:       Output guide
 * Param [in]:  NA
 * Param [out]: NA
 * Author:      Chenyun Lu
 * Date:        2019/04/05
****************************************************************************/
static void output_guide();

/****************************************************************************
 * Function:    output
 * Brief:       Output the result 
 * Param [in]:  Poterm t
 * Param [out]: NA
 * Author:      Chenyun Lu
 * Date:        2019/04/03
****************************************************************************/
static void output( Poterm t );

#endif