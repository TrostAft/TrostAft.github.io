/*
 * FILE: spectral_diff.h
 * AUTHOR: Abhijit Chowdhary 2019/06/07.
 * ----------------------------------
 * Provides a function to numerically approximate the derivative of a function
 * applied to a the grid [0, 2*pi].
 */

#ifndef SPECTRAL_DIFF_H
#define SPECTRAL_DIFF_H

#include <stdio.h>
#include <fftw3.h>


inline void print_domain(fftw_complex *x, int N)
{
  printf("(%f, %f)", x[0][0], x[0][1]);
  for (int k = 1; k < N; k++)
  {
    printf(",(%f, %f)", x[k][0], x[k][1]);
  }
  printf("\n");
}

/* 
 * FUNCTION: spectral_diff
 * -----------------------
 * Computes the derivative of the given function. The assumption that the
 * function is periodic over the domain [0,2*pi].
 *
 * INPUT:
 * fftw_complex &fxx: An array of complex numbers describing the function which
 *                    the derivative is to be taken on applied to the grid
 *                    [0,2*pi].
 * int N: Spacing of the above grid, i.e. fxx[k] = f(2*pi*k/N). Must be even.
 * int M: Spacing of output grid, i.e. out[k] = f'(2*pi*k/M). Must be even and
 *        M >> N must be true..
 * OUTPUT:
 * fftw_complex &out: Output array containing (d/dx)fxx of size M. 
 */
inline void 
spectral_diff(fftw_complex *fxx, int N, fftw_complex *out, int M)
{
  fftw_plan p = fftw_plan_dft_1d(N, fxx, out, FFTW_FORWARD, FFTW_ESTIMATE);
  fftw_execute(p);

  int nyqst = N/2;
  for (int k = nyqst; k < N; k++) 
  { 
    out[(M-1)-(N-1-k)][0] = out[k][0]; out[(M-1)-(N-1-k)][1] = out[k][1]; 
  }
  out[nyqst][0] = out[nyqst][0]/2; out[nyqst][1] = out[nyqst][1]/2;
  out[nyqst+M-N-1][0] = out[nyqst][0]; out[nyqst+M-N-1][1] = out[nyqst][1];

  //for (int k = 0; k < M; k++)
  //{
  //  int w = 0;
  //  if (k < nyqst)  { w = k; }
  //  else if (k > (M-N-1)+nyqst) { w = k - M; }
  //  double temp = out[k][0]; out[k][0] = -w*N*out[k][1]/M; out[k][1] = temp*N*w/M;
  //}
  for (int k = 0; k < M; k++)
  {
    int w = 0;
    if (k < nyqst)  { w = 1; }
    else if (k > (M-N-1)+nyqst) { w = 1; }
    out[k][0] *= w*N*out[k][0]/(N*M); out[k][1] *= N*w*out[k][1]/(N*M);
  }

  p = fftw_plan_dft_1d(M, out, out, FFTW_BACKWARD, FFTW_ESTIMATE);
  fftw_execute(p);
  fftw_destroy_plan(p);
}

#endif
