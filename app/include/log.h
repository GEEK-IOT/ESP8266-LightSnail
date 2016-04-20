/*
 * log.h
 *
 *  Created on: 2016年4月7日
 *      Author: Light Snail
 */




//#define test(fmt, ...) do {	\
//		static const char flash_str[] ICACHE_RODATA_ATTR __attribute__((aligned(4))) = fmt;	\
//		os_printf_plus(flash_str, ##__VA_ARGS__);	\
//} while(0)
#define Log_initialize() do{\
	uart_init( 115200, 115200);\
	system_set_os_print(0);\
} while(0)

#define  Log_printf(fmt, ...) do {	\
	    system_set_os_print(1);\
			static const char flash_str[] ICACHE_RODATA_ATTR __attribute__((aligned(4))) = fmt;	\
			os_printf_plus(flash_str, ##__VA_ARGS__);	\
	    system_set_os_print(0);\
} while(0)
//

#define Log_printfln(fmt, ...) do{ \
	   system_set_os_print(1);\
			static const char flash_str[] ICACHE_RODATA_ATTR __attribute__((aligned(4))) = fmt;	\
			os_printf_plus(flash_str, ##__VA_ARGS__);	\
			os_printf_plus("\n");\
	   system_set_os_print(0);\
}while(0)

//void Log_printf(const char* fmt, ...);
//void Log_printfln(const char* fmt, ...);
