#include <complex.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

#include <vector>

#include <Eigen/Eigen>

typedef Eigen::Triplet<double> T;

#define BOX_SIZE 2.0
#define NUM_FRAMES 240

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    perror("USAGE: ./julia.out resolution \n");
    return -1;
  }
  int resolution = atoi(argv[1]);
  int w = 4*resolution; double w_grid[w];
  for (int i = 0; i < w; i++) { w_grid[i] = -BOX_SIZE + 2*i*BOX_SIZE/w; }
  int h = 4*resolution; double h_grid[h];
  for (int i = 0; i < h; i++) { h_grid[i] = -BOX_SIZE + 2*i*BOX_SIZE/h; }

  int frame = 0; double angle = 0.0;
  while (angle < 2*M_PI)
  {
    frame = frame + 1;
    char filename[50]; sprintf(filename, "%d.pgm", frame);
    FILE* current_frame = fopen(filename, "w");

    fprintf(current_frame, "P2\n\n%d %d\n255\n", w, h);

    for (int i = 0; i < w; i++)
    {
      for (int j = 0; j < h; j++)
      {
        complex<double> z(w_grid[i], h_grid[j]);
        complex<double> c(-1.0+0.5*sin(angle), 0.5*cos(angle));
        int n = 255;
        while (cabs(z) < 10 && n > 0)
        {
          z = pow(z,2) + c;
          n = n - 5;
        }
        fprintf(current_frame, "%d ", n);
      }
      fprintf(current_frame, "\n");
    }

    fclose(current_frame);
    printf("%s\n", filename);
    angle += 2*M_PI/NUM_FRAMES;
  }
  return 0;
}
