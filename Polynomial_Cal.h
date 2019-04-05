/****************************************************************************
 * \brief       
 * \copyright   2018-2019, Zhejiang University, Program Design Project, Group 6. 
 * \verson      1.0
 * \author      
 * \file        Polynimial_Cal.h
 * 
 * \date 2019/03/25 Fang :created
****************************************************************************/

#ifndef _POLYNOMIAL_CAL_H
#define _POLYNOMIAL_CAL_H

#include "Polynomial_Base.h"

/****************************************************************************
 * Function:    coreverse
 * Brief:       coefficient -> -coefficient
 * Param [in]:  Poterm TermTobeReverse
 * Param [out]: Poterm TermTobeReverse
 * Author:      Zhengze Liu
 * Date:        2019/03/26
****************************************************************************/
static Poterm coreverse( Poterm TermTobeReverse );


/****************************************************************************
 * Function:    product
 * Brief:       multiply with single term
 * Param [in]:  Poterm TermTobeMult, Poterm term
 * Param [out]: Poterm Result_term
 * Author:      Zhengze Liu
 * Date:        2019/03/26
****************************************************************************/
static Poterm product( Poterm TermTobeMult, Poterm term );


/****************************************************************************
 * Function:    ADD
 * Brief:       add a term
 * Param [in]:  Poterm First_term,term Add_term
 * Param [out]: Poterm First_term
 * Author:      Zhengze Liu
 * Date:        2019/03/25
****************************************************************************/
extern Poterm ADD(Poterm First_term,Poterm Add_term);


/****************************************************************************
 * Function:    MINUS
 * Brief:       minus a term
 * Param [in]:  Poterm First_term,term Minus_term
 * Param [out]: Poterm First_term
 * Author:      Zhengze Liu
 * Date:        2019/03/25
****************************************************************************/
extern Poterm MINUS(Poterm First_term,Poterm Minus_term);


/****************************************************************************
 * Function:    MULTIPLE
 * Brief:       multiple a term
 * Param [in]:  Poterm First_term,term Multiple_term
 * Param [out]: Poterm First_term
 * Author:      Zhengze Liu
 * Date:        2019/03/25
****************************************************************************/
extern Poterm MULTIPLE(Poterm First_term,Poterm Multiple_term);

#endif