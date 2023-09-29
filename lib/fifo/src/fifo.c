#include "fifo.h"


void fifo_worker_handler(struct k_msgq *requests, struct k_msgq *results, int id)
{
    struct request_msg data = {};
    while(1)
    {
        k_msgq_get(requests, &data, K_FOREVER); //wait until it gets data
        //data manipulation
        data.output = data.input + 5;
        data.handled_by = id;

        k_msgq_put(results, &data, K_FOREVER);  //K_FOREVER: keep trying to put data in buffer until it can

    }





}