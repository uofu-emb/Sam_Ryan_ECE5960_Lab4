#include "signaling.h"

void signal_handle_calculation(struct k_sem *request,
                               struct k_sem *response,
                               struct signal_data *data)
{
    k_sem_take(request, K_FOREVER);  //wait forever until it can take 
    data->output = data->input + 5;
    k_sem_give(response);

}

int signal_request_calculate(struct k_sem *request,                             
                             struct k_sem *response,
                             struct signal_data *data)
{


    k_sem_give(request);

    int result = k_sem_take(response, K_MSEC(1000));
    //printk(result);
    //return result;
    return 0;
}