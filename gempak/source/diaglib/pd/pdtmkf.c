#include "pd.h"

static const float RPRM = 9.0F / 5.0F;

void pd_tmkf ( const float *tmpk, const int *np, float *tmpf, int *iret )
/************************************************************************
 * pd_tmkf								*
 *									*
 * This subroutine computes TMPF from TMPK.  The following equation	*
 * is used:								*
 *									*
 *           TMPF  =  ( ( TMPK - TMCK ) * 9 / 5 ) + 32			*
 *									*
 * pd_tmkf ( tmpk, np, tmpf, iret )					*
 *									*
 * Input parameters:							*
 *	*tmpk		const float	Temperature in Kelvin		*
 *	*np		const int	Number of points		*
 *									*
 * Output parameters:							*
 *	*tmpf		float		Temperature in Fahrenheit	*
 *	*iret		int		Return code			*
 *					  0 = normal return		*
 **									*
 * Log:									*
 * M. desJardins/GSFC	 7/89	GEMPAK 5				*
 * G. Krueger/EAI        4/96   Replaced C->K constant with TMCK	*
 * K. Brill/HPC		11/02	Remove SUBFLG input logical array	*
 * R. Tian/SAIC		 9/05	Translated from FORTRAN			*
 ************************************************************************/
{
    int npt, i;
/*----------------------------------------------------------------------*/
    *iret = 0;
    npt = *np;

    /*
     * Loop through all the points.
     */
    for ( i = 0; i < npt; i++ ) {
	/*
	 * Check for missing data.
	 */
	if ( ERMISS ( tmpk [i] ) ) {
	    tmpf [i] = RMISSD;
	} else {
	    tmpf [i] = ( ( tmpk [i] - TMCK ) * RPRM ) + 32.0F;
	}
    }

    return;
}
