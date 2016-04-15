/*
 * log.c
 *
 *  Created on: 2016年4月7日
 *      Author: Light Snail
 */


#include "log.h"
#include "driver/uart.h"
#include "osapi.h"

void Log_initialize(){
//	system_set_os_print(0);
	uart_init( 115200, 115200);
};
//void Log_printf(const char* fmt,  ...){
//	   system_set_os_print(1);
//		os_printf_plus("\n");
//	    system_set_os_print(0);
//};
//void Log_printfln(const char* fmt, va...){
//		static const char flash_str[] ICACHE_RODATA_ATTR __attribute__((aligned(4))) = fmt;
//		os_printf_plus(flash_str, va);
//		os_printf_plus("\n");
//};
