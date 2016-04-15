#ifndef __PWM_H__
#define __PWM_H__

/*pwm.h: function and macro definition of PWM API , driver level */
/*user_light.h: user interface for light API, user level*/
/*user_light_adj: API for color changing and lighting effects, user level*/


 /*NOTE!!  : DO NOT CHANGE THIS FILE*/

 /*SUPPORT UP TO 8 PWM CHANNEL*/
#define PWM_CHANNEL_NUM_MAX 8 

struct pwm_param {
    uint32 period;
    uint32 freq;
    uint32 duty[PWM_CHANNEL_NUM_MAX];  //PWM_CHANNEL <= 8
};

/**
 * Initialize PWM function, including GPIO selection,
 * period and duty cycle.
 *
 * Note that this API can be called only once.
 */
void pwm_init(uint32 period, uint32 *duty, uint32 pwm_channel_num, uint32 (*pin_info_list)[3]);

/**
 * Starts PWM.
 * This function needs to be called after PWM config
 * is changed.
 */
void pwm_start(void);

/**
 *  Sets duty cycle of a PWM output. Set the time
 *  that high-level single will last, duty depends
 *  on period, the max value can be Period * 1000 / 45.
 *  For example, 1kHz PWM, duty range is 0 ~ 22222.
 *
 *  Note that after setting configuration, pwm_start()
 *  need to be called to take effect.
 */
void pwm_set_duty(uint32 duty, uint8 channel);

/**
 * Gets duty cycle of PWM output, duty cycle will be
 * (duty * 45) / (period * 1000).
 */
uint32 pwm_get_duty(uint8 channel);

/**
 * Sets PWM period, unit is us.
 * The range is 1000μs (1kHz) to 10000μs (100Hz)
 * For example, for 1kKz PWM, period is 1000us.
 *
 * Note that after setting configuration, pwm_start()
 * need to be called to take effect.
 */
void pwm_set_period(uint32 period);

/**
 * Gets PWM period.
 */
uint32 pwm_get_period(void);

/**
 * Get version information of PWM
 */
uint32 get_pwm_version(void);


void set_pwm_debug_en(uint8 print_en);

#endif

