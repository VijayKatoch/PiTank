/*
 * app.c
 *
 *  Created on: Dec 28, 2018
 *      Author: Vijay Katoch
 */

#include <motor_control.h>
#include<stdio.h>

#include "app_i.h"
#include "appErrorCodes_i.h"

void app_init()
{
    STATUS status = -1;

    hal_init_raspberryPi();
    status = motor_init();

    /*Enable motor direction control*/
    motor_control_enable();
}

void handlePOSTRequest(POST_DATA *data)
{
    printf("Post Req %d %d\n", data->cmd, data->value);

    switch(data->cmd)
    {
        case forward:
            motor_move_forward();
            break;
        case reverse:
            motor_move_reverse();
            break;
        case stop:
            motor_stop();
            break;
        case speed:
            motor_speed(data->value);
            break;
    }
}
