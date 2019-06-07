#include <stdlib.h>
#include <math.h>

#include <fftw3.h>

void f(fftw_complex &x)
{
  x[0] = cos(x[0]);
}

void print_domain(fftw_complex *xx, int N)
{
  printf("(%f, %f)", xx[0][0], xx[0][1]);
  for (int k = 1; k < N; k++)
  {
    printf(",(%f, %f)", xx[k][0], xx[k][1]);
  }
  printf("\n");
}

// Numerically differentiate f(x) on [0, 2*pi] via spectral differentiation.
int main(int argc, char **argv)
{
  if (argc != 2)
  {
    printf("USAGE: ./spectral_differentiation.out num_gridpoints\n\
            In addition, num_gridpoints should be even.\n");
    exit(1);
  }
  int N = atoi(argv[1]);

  fftw_complex *xx; fftw_plan p;
  xx = (fftw_complex *) fftw_malloc(sizeof(fftw_complex) * N);
  p = fftw_plan_dft_1d(N, xx, xx, FFTW_FORWARD, FFTW_ESTIMATE);

  for (int k = 0; k < N; k++)
  { //Build [0,2*pi] and map f onto it.
    xx[k][0] = k*2*M_PI / N; xx[k][1] = 0;
    f(xx[k]);
  }

  fftw_execute(p);
  p = fftw_plan_dft_1d(N, xx, xx, FFTW_BACKWARD, FFTW_ESTIMATE); 

  for (int k = 0; k < N; k++)
  {
    int w = (k < N/2) ? k : k-N;
    double temp = xx[k][0]; xx[k][0] = -w*xx[k][1]/N; xx[k][1] = temp*w/N;
  }
  xx[N/2][0] = 0; xx[N/2][1] = 0;

  fftw_execute(p);
  print_domain(xx, N);

  fftw_destroy_plan(p); fftw_free(xx);
}
