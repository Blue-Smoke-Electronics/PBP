#include "hartbeat.h"
#include "pico/stdlib.h"
#include "Pcb.h"


Hartbeat::Hartbeat(){
//    TaskHandle_t hartbeat_Task = NULL; 
//    uint32_t s1 = xTaskCreate(Hartbeat_task, "Hartbeat",1024,NULL,0,&hartbeat_Task);
            gpio_init(Pcb::debbug_led_pin);
        gpio_set_dir(Pcb::debbug_led_pin, GPIO_OUT);
        led_value =0; 
        update_timer = time_us_32();
}
void Hartbeat::Update(){
        if(time_us_32() - update_timer > update_freq_us )
        {
            update_timer = time_us_32();
            gpio_put(Pcb::debbug_led_pin, led_value);
            led_value = !led_value; 
        }
        
}

