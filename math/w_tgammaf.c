/* w_gammaf.c -- float version of w_gamma.c.
 * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
 */

/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

#include <math.h>
#include <math_private.h>

float
__tgammaf(float x)
{
	int local_signgam;
	float y = __ieee754_gammaf_r(x,&local_signgam);

	if(__builtin_expect(!__finitef(y), 0) && __finitef(x)
	   && _LIB_VERSION != _IEEE_) {
	  if (x == (float)0.0)
	    /* tgammaf pole */
	    return __kernel_standard_f(x, x, 150);
	  else if(__floorf(x)==x&&x<0.0f)
	    /* tgammaf domain */
	    return __kernel_standard_f(x, x, 141);
	  else
	    /* tgammaf overflow */
	    return __kernel_standard_f(x, x, 140);
	}
	return local_signgam < 0 ? - y : y;
}
weak_alias (__tgammaf, tgammaf)
