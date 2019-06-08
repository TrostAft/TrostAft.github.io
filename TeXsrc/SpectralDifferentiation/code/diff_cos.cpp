/*
 * FILE: dff_cos.cpp
 * AUTHOR: Abhijit Chowdhary 2019/06/07.
 * ----------------------------------
 * An example showing how we can use the Fourier transform to numerically
 * approximate the derivative, with spectral accuracy.
 */
#include <stdlib.h>
#include <math.h>

#include <fftw3.h>

#include "spectral_diff.h"

void print_domain(fftw_complex *xx, int N)
{
  printf("(%f, %f)", xx[0][0], xx[0][1]);
  for (int k = 1; k < N; k++)
  {
    printf(",(%f, %f)", xx[k][0], xx[k][1]);
  }
  printf("\n");
}

// Numerically differentiate cos(x) on [0, 2*pi] via spectral differentiation.
int main(int argc, char **argv)
{
  if (argc != 3)
  {
    printf("USAGE: ./spectral_differentiation.out num_gridpoints num_interpts\n\
            In addition, num_gridpoints and num_interpts should be even.\n\
            SAMPLE: ./spectral_differentiation.out 32 4096");
    exit(1);
  }
  int N = atoi(argv[1]), M = atoi(argv[2]);

  fftw_complex *fxx, *out;
  fxx = (fftw_complex *) fftw_malloc(sizeof(fftw_complex) * N);
  out = (fftw_complex *) fftw_malloc(sizeof(fftw_complex) * M);

  for (int k = 0; k < N; k++)
  { //Build [0,2*pi] and map cos() onto it.
    fxx[k][0] = cos(k*2*M_PI / N); fxx[k][1] = 0;
  }
  spectral_diff(fxx, N, out, M);

  print_domain(out, M);

  fftw_free(fxx); fftw_free(out);
}
