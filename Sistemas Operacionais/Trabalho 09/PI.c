#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define n_threads 8
static long num_steps = 100000;
double step;

int main(){
	double x, pi, sum = 0.0;
	step = 1.0/(double)num_steps;
	double pass_per_thread = num_steps/n_threads;

	#pragma omp parallel num_threads(n_threads)
	{
		int id = omp_get_thread_num(), i = 0;
		double psum = 0;
		for(i = id*pass_per_thread; i < (id + 1)*pass_per_thread; i++){
			x = (i + 0.5)*step;
			psum = psum + 4.0/(1.0 + x*x);
		}

		pi += step*psum;
	}
	printf("%f\n",pi);
}
