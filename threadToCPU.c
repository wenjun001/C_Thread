#include <stdio.h>
#define __USE_GNU
#include <sched.h>
#include <pthread.h>
#include <sys/sysinfo.h>

void bind_cpu(int cpu_id)
{
    cpu_set_t mask;
    CPU_ZERO(&mask);
    CPU_SET(cpu_id, &mask);
    if (sched_setaffinity(0, sizeof(cpu_set_t), &mask) < 0) {
        printf("Error: cpu id %d sched_setaffinity\n", cpu_id);
        printf("Warning: performance may be impacted \n");
    }
    return;
}

void new_thread(void *cpu_id)
{
    int bind_cpu = (int)(long)cpu_id;
    mybind_cpu(cpuid);
    printf("test success!\n");
    return;
}

int main(int argc, char **argv)
{
    int res;
    void *thread_result;
    pthread_t test_thread_ctrl;
    printf("This system has %d processors configured and "
                   "%d processors available.\n",
           get_nprocs_conf(), get_nprocs());
    pthread_create(&test_thread_ctrl, NULL, (void *)new_thread, (void *)16);
    res = pthread_join(test_thread_ctrl, &thread_result);
    (void)res;
    return 0;
}
