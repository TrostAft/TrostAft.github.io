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

// Numerically differentiate cos(x) on [0, 2*pi] via spectral differentiation.
int main(int argc, char **argv)
{
  if (argc != 2)
  {
    printf("USAGE: ./spectral_differentiation.out num_pts\n\
            In addition, num_pts should be even.\n\
            SAMPLE: ./spectral_differentiation.out 4096");
    exit(1);
  }
  int M = atoi(argv[1]), N = 8;

  fftw_complex *fxx, *out;
  out = (fftw_complex *) fftw_malloc(sizeof(fftw_complex) * M);

  while (N < M)
  {
    fxx = (fftw_complex *) fftw_malloc(sizeof(fftw_complex) * N);
    for (int k = 0; k < N; k++)
    { //Build [0,2*pi] and map cos() onto it.
      fxx[k][0] = cos(k*2*M_PI / N); fxx[k][1] = 0;
    }
    spectral_diff(fxx, N, out, M);
    double err = 0.0;
    for (int k = 0; k < M; k++)
    {
      err = fmax(err, fabs( out[k][0] - (cos(k*2*M_PI / M)) ));
    }
    printf("%d, %e\n", N, err);

    fftw_free(fxx); N = N + 8;
  }
  fftw_free(out);
}
