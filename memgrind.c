#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "mymalloc.h"

#define usec_to_sec 1000000.0
#define num_tests 50.0

long test1()
{
    struct timeval tv;
    struct timezone tz;
    time_t start_sec, end_sec;
    suseconds_t start_usec, end_usec;
    long start,end;

    gettimeofday(&tv,&tz);
    start_sec = tv.tv_sec;
    start_usec = tv.tv_usec;
    start = start_sec * usec_to_sec + start_usec;

    for(int i = 0; i < 120; i++)
    {
        char *p = malloc(sizeof(char));
        free(p);
    }

    gettimeofday(&tv,&tz);
    end_sec = tv.tv_sec;
    end_usec = tv.tv_usec;
    end = end_sec * usec_to_sec + end_usec;
    double run_time = end - start;
    return run_time;
}

long test2()
{
    struct timeval tv;
    struct timezone tz;
    time_t start_sec, end_sec;
    suseconds_t start_usec, end_usec;
    long start,end;

    gettimeofday(&tv,&tz);
    start_sec = tv.tv_sec;
    start_usec = tv.tv_usec;
    start = start_sec * usec_to_sec + start_usec;

    char *pointers_arr[120];
    for(int i = 0; i < 120; i++)
    {
        pointers_arr[i] = malloc(sizeof(char));
    }
    for(int i = 0; i < 120; i++)
    {
        free(pointers_arr[i]);
    }

    gettimeofday(&tv,&tz);
    end_sec = tv.tv_sec;
    end_usec = tv.tv_usec;
    end = end_sec * usec_to_sec + end_usec;
    double run_time = end - start;
    return run_time;
}

long test3()
{
    struct timeval tv;
    struct timezone tz;
    time_t start_sec, end_sec;
    suseconds_t start_usec, end_usec;
    long start,end;

    gettimeofday(&tv,&tz);
    start_sec = tv.tv_sec;
    start_usec = tv.tv_usec;
    start = start_sec * usec_to_sec + start_usec;

    int num_mallocs = 0;
    char *pointers_arr[120];
    int index = 0;
    while (num_mallocs < 120)
    {
        int choice = rand() % 2;
        if (choice == 0)
        {
            pointers_arr[index] = malloc(sizeof(char));
            num_mallocs++;
            index++;
        }
        else
        {
            if(index > 0)
            {
                free(pointers_arr[index-1]);
                index--;
            }
        }
    }

    while (index > 0)
    {
        free(pointers_arr[index-1]);
        index--;
    }
    
    

    gettimeofday(&tv,&tz);
    end_sec = tv.tv_sec;
    end_usec = tv.tv_usec;
    end = end_sec * usec_to_sec + end_usec;
    double run_time = end - start;
    return run_time;
}

long test4()
{
    struct timeval tv;
    struct timezone tz;
    time_t start_sec, end_sec;
    suseconds_t start_usec, end_usec;
    long start,end;

    gettimeofday(&tv,&tz);
    start_sec = tv.tv_sec;
    start_usec = tv.tv_usec;
    start = start_sec * usec_to_sec + start_usec;

    char *pointers_arr[500];
    for(int i = 0; i < 500; i++)
    {
        pointers_arr[i] = malloc(sizeof(char));
        if(pointers_arr[i] == NULL)
            break;
    }
    for(int i = 0; i < 500; i++)
    {
        if(pointers_arr[i] == NULL)
            break;
        free(pointers_arr[i]);
    }

    gettimeofday(&tv,&tz);
    end_sec = tv.tv_sec;
    end_usec = tv.tv_usec;
    end = end_sec * usec_to_sec + end_usec;
    double run_time = end - start;
    return run_time;
}

long test5()
{
    struct timeval tv;
    struct timezone tz;
    time_t start_sec, end_sec;
    suseconds_t start_usec, end_usec;
    long start,end;

    gettimeofday(&tv,&tz);
    start_sec = tv.tv_sec;
    start_usec = tv.tv_usec;
    start = start_sec * usec_to_sec + start_usec;

    char *pointers_arr[500];
    int index = 0;
    while (1)
    {
        int choice = rand() % 4;
        if (choice == 0 || choice == 1 || choice == 2)
        {
            pointers_arr[index] = malloc(sizeof(char));
            index++;
            if (pointers_arr[index] == NULL)
            {
                index--;
                break;
            }
        }
        else
        {
            if(index > 0)
            {
                free(pointers_arr[index-1]);
                index--;
            }
        }
    }

    while (index > 0)
    {
        free(pointers_arr[index-1]);
        index--;
    }
    
    

    gettimeofday(&tv,&tz);
    end_sec = tv.tv_sec;
    end_usec = tv.tv_usec;
    end = end_sec * usec_to_sec + end_usec;
    double run_time = end - start;
    return run_time;
}

int main(int argc, char **argv)
{
    long test_time = 0;
    long sum_time = 0;
    double avg_test_time = 0.0;

    for(int i = 0; i < num_tests; i++)
    {
        test_time = test1();
        sum_time += test_time;
    }
    avg_test_time = sum_time/num_tests;
    printf("Average time for test1: %.2f micro sec\n",avg_test_time);

    test_time = 0;
    sum_time = 0;
    for(int i = 0; i < num_tests; i++)
    {
        test_time = test2();
        sum_time += test_time;
    }
    avg_test_time = sum_time/num_tests;
    printf("Average time for test2: %.2f micro sec\n",avg_test_time);

    test_time = 0;
    sum_time = 0;
    for(int i = 0; i < num_tests; i++)
    {
        test_time = test3();
        sum_time += test_time;
    }
    avg_test_time = sum_time/num_tests;
    printf("Average time for test3: %.2f micro sec\n",avg_test_time);

    test_time = 0;
    sum_time = 0;
    for(int i = 0; i < num_tests; i++)
    {
        test_time = test4();
        sum_time += test_time;
    }
    avg_test_time = sum_time/num_tests;
    printf("Average time for test4: %.2f micro sec\n",avg_test_time);

    test_time = 0;
    sum_time = 0;
    for(int i = 0; i < num_tests; i++)
    {
        test_time = test5();
        sum_time += test_time;
    }
    avg_test_time = sum_time/num_tests;
    printf("Average time for test5: %.2f micro sec\n",avg_test_time);

    return EXIT_SUCCESS;
}
