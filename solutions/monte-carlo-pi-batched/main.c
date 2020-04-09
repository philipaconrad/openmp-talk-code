// Approximating Pi with Monte Carlo methods.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> // time()
#include <math.h> // sqrt()


void show_help() {
    printf("Monte Carlo Approximation of Pi.\n");
    printf("Usage:\n");
    printf("  ./montecarlo NUM_TRIALS [SEED]\n");
}


int samples_inside_circle(struct drand48_data* buffer, int num_samples) {
    int i, count;
    double x, y, z;

    count = 0;

    for (i = 0; i < num_samples; i++) {
        // Pick a random point in the unit square.
        drand48_r(buffer, &x);
        drand48_r(buffer, &y);

        // Compute the distance from the origin.
        z = sqrt((x * x) + (y * y));

        // If we're inside the unit circle, increment the counter.
        if(z <= 1) {
            count += 1;
        }
    }

    return count;
}


int main(int argc, char *argv[]) {
    int i, num_trials, count, seed, num_batches;
    double pi;
    struct drand48_data buffer;

    if (argc < 2) {
        show_help();
        exit(1);
    }

    num_trials = atoi(argv[1]);
    if (argc < 3) {
        seed = time(NULL);
    } else {
        seed = atoi(argv[2]);
    }

    count = 0;
    num_batches = 8;

    // Initialize RNG.
    srand48_r(seed, &buffer);

    #pragma omp parallel for private(buffer) reduction(+: count)
    for (i = 0; i < num_batches; i++) {
        // Run a batch of trials. `result` is how many were inside the circle.
        int result = samples_inside_circle(&buffer, num_trials / num_batches);
        count += result;
    }

    pi = ((double)count) / num_trials * 4;

    printf("Approximated value of Pi = %g (%d trials)\n", pi, num_trials);

    return 0;
}
