/******************************************************************************
 * Copyright 2013-2014 Espressif Systems (Wuxi)
 *
 * FileName: user_main.c
 *
 * Description: entry file of user application
 *
 * Modification history:
 *     2014/1/1, v1.0 create this file.
*******************************************************************************/
#include "ets_sys.h"
#include "osapi.h"
#include "user_interface.h"
#include "driver/uart.h"
#include "log.h"
#include "math.h"

#include "user_devicefind.h"
#include "user_webserver.h"

#if ESP_PLATFORM
#include "user_esp_platform.h"
#endif
/******************************************************************************
 * FunctionName : user_init
 * Description  : entry of user application, init user function here
 * Parameters   : none
 * Returns      : none
*******************************************************************************/
void my_print(){
	    uint8 buffer[64] = {0};
	    os_sprintf(buffer, "\r\n\n s Test Format :%d,%lf,%d,%lf,%d,%f \r\n\n ",10,	10,  10.0, 10.0,  M_PI, M_PI);
	    at_port_print(buffer);
}
void my_print2(){
	    uint8 buffer[64] = {0};
	    ets_vprintf(buffer, "\r\n\n v Test Format :%d,%f,%d,%f,%d,%f \r\n\n ",-5,	-5,  12.0, 12.0,  M_PI, M_PI);
	    at_port_print(buffer);
}
void user_init(void)
{
//	uart_init(BIT_RATE_115200, BIT_RATE_115200);
	uart_init( 115200, 115200);
//    os_printf("\r\nready0!!!\r\n");
//    os_printf("SDK version: %s \n", system_get_sdk_version());
//    os_install_putc1();
//    os_printf("\r\nready1!!!\r\n");
//    uart0_sendStr("\r\nready2\r\n");

	Log_initialize();

//	ets_vprintf("\n\n000 PI is %d \n\n", M_PI);
//	my_print();
//	my_print2();
//	UART_SetPrintPort(1);

	Log_printfln("\n========================");
	Log_printfln("start log");
	Log_printfln("========================");
	Log_printfln("========================");
	Log_printfln("========================");

	Log_printfln("111 PI is %d", 10);

	Log_printf("\r\n hello,lightSnail  Log_printf ! \r\n");
	Log_printf("lightSnail  Log_printf(fmt,...) SDK version: %s  kkkk  ", system_get_sdk_version());
	Log_printfln("lightSnail Log_printfln(fmt,...)  SDK version: %s \n", system_get_sdk_version());
//
	Log_printfln("222  PI is %d", -110);
	Log_printfln("\nlog finished~~\n========================");

//    uart0_sendStr("\r\n hello,lightSnail! \r\n");

#if ESP_PLATFORM
    /*Initialization of the peripheral drivers*/
    /*For light demo , it is user_light_init();*/
    /* Also check whether assigned ip addr by the router.If so, connect to ESP-server  */
    user_esp_platform_init();
#endif
    /*Establish a udp socket to receive local device detect info.*/
    /*Listen to the port 1025, as well as udp broadcast.
    /*If receive a string of device_find_request, it rely its IP address and MAC.*/
    user_devicefind_init();

    /*Establish a TCP server for http(with JSON) POST or GET command to communicate with the device.*/
    /*You can find the command in "2B-SDK-Espressif IoT Demo.pdf" to see the details.*/
    /*the JSON command for curl is like:*/
    /*3 Channel mode: curl -X POST -H "Content-Type:application/json" -d "{\"period\":1000,\"rgb\":{\"red\":16000,\"green\":16000,\"blue\":16000}}" http://192.168.4.1/config?command=light      */
    /*5 Channel mode: curl -X POST -H "Content-Type:application/json" -d "{\"period\":1000,\"rgb\":{\"red\":16000,\"green\":16000,\"blue\":16000,\"cwhite\":3000,\"wwhite\",3000}}" http://192.168.4.1/config?command=light      */
#ifdef SERVER_SSL_ENABLE
    user_webserver_init(SERVER_SSL_PORT);
#else
    user_webserver_init(SERVER_PORT);
#endif
}

/******************************************************************************
 * FunctionName : user_rf_pre_init
 * Description  : It is provided for RF initialization.
 * Parameters   : none
 * Returns      : none
*******************************************************************************/
void user_rf_pre_init(void)
{
	// TODO
}
