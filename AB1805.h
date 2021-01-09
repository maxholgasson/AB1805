#ifndef AB1850_h
#define AB1850_h
#include <Arduino.h>
//#include <I2C.h>
#include <Wire.h>

#include "stdint.h"

#define AM1805 0x69

#define HUNDRETH_REGISTER           0x00
#define SECOND_REGISTER             0x01
#define MINUTE_REGISTER             0x02
#define HOUR_REGISTER               0x03
#define DATE_REGISTER               0x04
#define MONTH_REGISTER              0x05
#define YEAR_REGISTER               0x06
#define WEEKDAY_REGISTER            0x07

#define HUNDRETH_ALARM_REGISTER     0x08
#define SECOND_ALARM_REGISTER       0x09
#define MINUTE_ALARM_REGISTER       0x0A
#define HOUR_ALARM_REGISTER         0x0B
#define DATE_ALARM_REGISTER         0x0C
#define MONTH_ALARM_REGISTER        0x0D
#define WEEKDAY_ALARM_REGISTER      0x0E
#define STATU_REGISTER              0x0F

#define CONTROL1_REGISTER           0x10
#define CONTROL2_REGISTER           0x11
#define INT_MASK_REGISTER           0x12
#define SQW_REGISTER                0x13
#define CAL_XT_REGISTER             0x14
#define CAL_RC_HI_REGISTER          0x15
#define CAL_RC_LOW_REGISTER         0x16
#define SLEEP_CONTROL_REGISTER      0x17
#define TIMER_CONTROL_REGISTER      0x18
#define TIMER_REGISTER              0x19
#define TIMER_INITIAL_REGISTER      0x1A
#define WDT_REGISTER                0x1B
#define OSC_CONTROL_REGISTER        0x1C
#define OSC_STATUS_REGISTER         0x1D

#define CONFIG_KEY_REGISTER         0x1F
#define TRICKLE_REGISTER            0x20
#define BREF_CONTROL_REGISTER       0x21

#define REG_CONFIG_KEY             0x1f      //!< Register to set to modify certain other keys
#define REG_CONFIG_KEY_OSC_CTRL    0xa1      //!< Configuration key, enable setting REG_OSC_CTRL
#define REG_CONFIG_KEY_SW_RESET    0x3c      //!< Configuration key, software reset
#define REG_CONFIG_KEY_OTHER       0x9d
#define REG_TRICKLE                 0x20 //!< Trickle charger control register
#define REG_TRICKLE_DEFAULT         0x00 //Trickle charger control register, default value
#define REG_TRICKLE_TCS_MASK        0xf0 //Trickle charger control register, enable mask
#define REG_TRICKLE_TCS_ENABLE      0xa0 //Trickle charger control register, enable value (0b10100000)
#define REG_TRICKLE_DIODE_MASK      0x0c //Trickle charger control register, diode mask
#define REG_TRICKLE_DIODE_0_6       0x08 //Trickle charger control register, diode 0.6V drop
#define REG_TRICKLE_DIODE_0_3       0x04 //Trickle charger control register, diode 0.3V drop
#define REG_TRICKLE_ROUT_MASK       0x03 //Trickle charger control register, rout mask
#define REG_TRICKLE_ROUT_11K        0x03 //Trickle charger control register, rout 11K
#define REG_TRICKLE_ROUT_6K         0x02 //Trickle charger control register, rout 6K
#define REG_TRICKLE_ROUT_3K         0x01 //Trickle charger control register, rout 3K
#define REG_TRICKLE_ROUT_DISABLE    0x00 //Trickle charger control register, rout disable

#define REG_STATUS_DEFAULT          0x00
#define REG_TIMER_CTRL_DEFAULT      0x23

#define AFCTRL_REGISTER             0x26
#define BATMODE_REGISTER            0x27

#define ID0_REGISTER                0x28
#define ID1_REGISTER                0x29
#define ID2_REGISTER                0x2A
#define ID3_REGISTER                0x2B
#define ID4_REGISTER                0x2C
#define ID5_REGISTER                0x2D
#define ID6_REGISTER                0x2E
#define ASTAT_REGISTER              0X2F

#define OCTRL_REGISTER              0x30
#define EXTENSION_ADDRESS_REGISTER  0x3F

#define TENTH_MASK                  0xF0
#define HUNDRETH_MASK               0x0F
#define SECOND_MASK                 0x7F
#define MINUTE_MASK                 0x7F
#define HOUR_24_MASK                0x3F
#define HOUR_12_MASK                0x1F
#define AM_PM_MASK                  0x20
#define DATE_MASK                   0x3F
#define MONTH_MASK                  0x1F
#define YEAR_MASK                   0xFF
#define DAY_MASK                    0x07

#define TENTH_ALARM_MASK            0xF0
#define HUNDRETH_ALARM_MASK         0xF0
#define SECOND_ALARM_MASK           0x7F
#define MINUTE_ALARM_MASK           0x7F
#define HOUR_24_ALARM_MASK          0x3F
#define HOUR_12_ALARM_MASK          0x1F
#define DATE_ALARM_MASK             0x3F
#define MONTH_ALARM_MASK            0x1F
#define WEEKDAY_ALARM_MASK          0x07

//status mask
#define STATUS_READ_ALL_MASK 0xFF

#define STATUS_CB_MASK 0x80
#define STATUS_BAT_MASK 0x40
#define STATUS_WDT_MASK 0x20
#define STATUS_BL_MASK 0x10
#define STATUS_TIM_MASK 0x08
#define STATUS_ALM_MASK 0x04
#define STATUS_EX2_MASK 0x02
#define STATUS_EX1_MASK 0x01

//CONTROL1 mask
#define CONTROL1_1224_MASK 0x40
#define CONTROL1_RSP_MASK 0x08
#define CONTROL1_ARST_MASK 0x04
#define CONTROL1_PWR2_MASK 0x02
#define CONTROL1_WRTC_MASK 0x01

//interrupt mask
#define INTERRUPT_CEB_MASK 0x80
#define INTERRUPT_IM_MASK 0x60
#define INTERRUPT_BLIE_MASK 0x10
#define INTERRUPT_TIE_MASK 0x08
#define INTERRUPT_AIE_MASK 0x04
#define INTERRUPT_EX2E_MASK 0x02
#define INTERRUPT_EX1E_MASK 0x01

//control2 mask
#define CONTROL2_RS1E_MASK 0x20
#define CONTROL2_OUT2S_MASK 0x1C
#define CONTROL2_OUT1S_MASK 0x03
#define REG_CTRL_2_OUT1S_nIRQ 0x00
// control2 sleep value
#define CONTROL2_SLEEP_MODE 0x6
#define SLEEP_CONTROL_SLTO_MAX_VALUE 7

//sleep control mask
#define SLEEP_CONTROL_SLP_MASK 0x80
#define SLEEP_CONTROL_SLRES_MASK 0x40 //When 1, assert nRST low when the Power Control SM is in the SLEEP state.
#define SLEEP_CONTROL_EX2P_MASK 0x20 //When 1, the external interrupt XT2 will trigger on a rising edge of the WDI pin.
#define SLEEP_CONTROL_EX1P_MASK 0x10 //When 1, the external interrupt XT1 will trigger on a rising edge of the EXTI pin.
#define SLEEP_CONTROL_SLST_MASK 0x08 //Set when the AM18X5 enters Sleep Mode
#define SLEEP_CONTROL_SLTO_MASK 0x07 //The number of 7.8 ms periods after SLP is set until the Power Control SM goes into the SLEEP state.

// Timer Register and countdown control
#define TIMER_CONTROL_TE_MASK 0x80
#define TIMER_CONTROL_TM_MASK 0x40
#define TIMER_CONTROL_TRPT_MASK 0x20
#define TIMER_CONTROL_RPT_MASK 0x1C
#define TIMER_CONTROL_TFS_MASK 0x03
#define REG_TIMER_CTRL_TFS_1_60 0x03
#define REG_TIMER_CTRL_TFS_1 0x02

#define TIMER_CONTROL_RPT_ONCE_PER_SECOND     7
#define TIMER_CONTROL_RPT_ONCE_PER_MINUTE     6
#define TIMER_CONTROL_RPT_ONCE_PER_HOUR       5
#define TIMER_CONTROL_RPT_ONCE_PER_DAY        4
#define TIMER_CONTROL_RPT_ONCE_PER_WEEK       3
#define TIMER_CONTROL_RPT_ONCE_PER_MONTH      2
#define TIMER_CONTROL_RPT_ONCE_PER_YEAR       1
#define TIMER_CONTROL_ALAM_DISABLE            0

//outcontrol sleep mode value
#define CCTRL_SLEEP_MODE_MASK 0xC0 //清除 WDDS,EXDS,RSEN,O4EN,O3EN,O1EN

//OSC Control mask
#define OSC_CONTROL_MASK 0xFF

#define OSC_CONTROL_OSEL_MASK 0x80
#define OSC_CONTROL_ACAL_MASK 0x60
#define OSC_CONTROL_AOS_MASK 0x10
#define OSC_CONTROL_FOS_MASK 0x08
#define OSC_CONTROL_PWGT_MASK 0x04
#define OSC_CONTROL_OFIE_MASK 0x02
#define OSC_CONTROL_ACIE_MASK 0x01

//WDT register mask
#define WDT_REGISTER_MASK 0xFF

#define WDT_REGISTER_WDS_MASK 0x80
#define WDT_REGISTER_BMB_MASK 0x7C
#define WDT_REGISTER_WRB_MASK 0x03

//outcontrol sleep mode value
#define CCTRL_SLEEP_MODE_MASK 0xC0 //清除 WDDS,EXDS,RSEN,O4EN,O3EN,O1EN

//outcontrol mask
#define OCTRL_MASK 0xFF

#define OCTRL_WDBM_MASK 0x80
#define OCTRL_EXBM_MASK 0x40
#define OCTRL_WDDS_MASK 0x20
#define OCTRL_EXDS_MASK 0x10
#define OCTRL_RSEN_MASK 0x08
#define OCTRL_O4EN_MASK 0x04
#define OCTRL_O3EN_MASK 0x02
#define OCTRL_O1EN_MASK 0x01

#define OSEL_MASK 0x80
//#define STATUS_MASK                 0x

#define MONDAY                      0
#define TUESDAY                     1
#define WEDNESDAY                   2
#define THURSDAY                    3
#define FRIDAY                      4
#define SATURDAY                    5
#define SUNDAY                      6

#define MIN_SECOND                  0
#define MAX_SECOND                  0x60
#define MIN_MINUTE                  0
#define MAX_MINUTE                  0x60
#define MIN_HOURS                   0
#define MAX_HOURS                   0x24
#define MIN_DAY                     1
#define MAX_DAY                     0x08
#define MIN_DATE                    0
#define MAX_DATE                    0x32
#define MIN_MONTH                   0
#define MAX_MONTH                   0x13
#define MIN_YEAR                    0
#define MAX_YEAR                    0x100

#define CONST_DATE_TIME_STRING_LEN 30

class AB1805 {
  public:
    // func
    AB1805();
    void begin();
    void begin(short sda_pin, short scl_pin);

    uint8_t read_rtc_register(const uint8_t rtc_register);
    uint8_t write_rtc_register(const uint8_t rtc_register, const uint8_t data);
    uint8_t setBit_rtc_register(const uint8_t rtc_register, const uint8_t bitMask);

    uint8_t get_rtc_data(const uint8_t rtc_register, const uint8_t register_mask);

    uint8_t get_hundredths(void);
    uint8_t get_second(void);
    uint8_t get_minute(void);
    uint8_t get_hour(void);
    uint8_t get_weekday(void);
    uint8_t get_date(void);
    uint8_t get_month(void);
    uint8_t get_year(void);

    void get_datetime(void);

    uint8_t get_second_alarm(void);
    uint8_t get_minute_alarm(void);
    uint8_t get_hour_alarm(void);
    uint8_t get_weekday_alarm(void);
    uint8_t get_date_alarm(void);
    uint8_t get_month_alarm(void);
    //uint8_t get_year_alarm(void);

    void set_second(const uint8_t value);
    void set_minute(const uint8_t value);
    void set_hour(const uint8_t value);
    void set_weekday(const uint8_t value);
    void set_date(const uint8_t value);
    void set_month(const uint8_t value);
    void set_year(const uint8_t value);

    void set_datetime(uint8_t year, uint8_t month, uint8_t date,
    uint8_t day, uint8_t hour, uint8_t minutes, uint8_t seconds);

    bool set_second_alarm(uint8_t value);
    bool set_minute_alarm(uint8_t value);
    bool set_hour_alarm(uint8_t value);
    bool set_weekday_alarm(uint8_t value);
    bool set_date_alarm(uint8_t value);
    bool set_month_alarm(uint8_t value);

void init();
    //bool set_year_alarm(uint8_t value);

/**
     * @brief Set an interrupt at a time in the future using a time_t
     *
     * @param time The number of second after January 1, 1970 UTC.
     *
     * @return true on success or false if an error occurs.
     *
     * This causes an interrupt on FOUT/nIRQ in the future. It will execute
     * once. This can only be done if the RTC has been programmed with
     * the current time, which it normally gets from the cloud at startup.
     *
     * There can only be one interrupt set. Setting at one-time or repeating interrupt
     * removes any previously set interrupt time.
     */
    bool interruptAtTime(time_t time);

    /**
     * @brief Set an interrupt at a time in the future using a struct tm *.
     *
     * @param timeptr pointer to struct tm. This specifies the time (UTC).
     *
     * @return true on success or false if an error occurs.
     *
     * This causes an interrupt on FOUT/nIRQ in the future. It will execute
     * once. This can only be done if the RTC has been programmed with
     * the current time, which it normally gets from the cloud at startup.
     *
     * Only the tm_sec, tm_min, tm_hour, tm_mday, tm_mon, and tm_year are
     * used. The tm_wday field is ignored. Note that tm_mon is 0-11, not 1-12.
     *
     * There can only be one interrupt set. Setting at one-time or repeating interrupt
     * removes any previously set interrupt time.
     *
     * The fields of the timeptr are:
     * - tm_sec	  seconds after the minute	0-61 (usually 0-59)
     * - tm_min	  minutes after the hour 0-59
     * - tm_hour  hours since midnight 0-23
     * - tm_mday  day of the month 1-31
     * - tm_mon	  months since January 0-11 (not 1-12!)
     * - tm_year  years since 1900 (note: 2020 = 120)
     * - tm_wday  days since Sunday	0-6
     */
    bool interruptAtTm(struct tm *timeptr);

    /**
     * @brief Set a repeating interrupt
     *
     * @param timeptr pointer to struct tm. This specifies the time (UTC).
     *
     * @param rptValue a constant for which fields of timeptr are used.
     *
     * @return true on success or false if an error occurs.
     *
     * This causes an interrupt on FOUT/nIRQ in the future, repeating.
     * This can only be done if the RTC has been programmed with
     * the current time, which it normally gets from the cloud at startup.
     *
     * - `REG_TIMER_CTRL_RPT_SEC` tm_sec matches (once per minute)
     * - `REG_TIMER_CTRL_RPT_MIN` tm_sec, tm_min match (once per hour)
     * - `REG_TIMER_CTRL_RPT_HOUR` tm_sec, tm_min, tm_hour match (once per day)
     * - `REG_TIMER_CTRL_RPT_WKDY` tm_sec, tm_min, tm_hour, tm_wday match (once per week)
     * - `REG_TIMER_CTRL_RPT_DATE` tm_sec, tm_min, tm_hour, tm_mday match (once per month)
     * - `REG_TIMER_CTRL_RPT_MON` tm_sec, tm_min, tm_hour, tm_mday, tm_mon match (once per year)
     *
     * Note that tm_mon (month) is 0 - 11, not 1 - 12!
     *
     * There can only be one interrupt set. Setting at one-time or repeating interrupt
     * removes any previously set interrupt time.
     *
     * If you reset the AB1805 configuration using `resetConfig()`, the repeating timer
     * will be cleared, unless you add the `AB1805::RESET_PRESERVE_REPEATING_TIMER` parameter
     * to preserve it.
     *
     * The fields of the timeptr are:
     * - tm_sec	  seconds after the minute	0-61 (usually 0-59)
     * - tm_min	  minutes after the hour 0-59
     * - tm_hour  hours since midnight 0-23
     * - tm_mday  day of the month 1-31
     * - tm_mon	  months since January 0-11 (not 1-12!)
     * - tm_year  years since 1900 (note: 2020 = 120)
     * - tm_wday  days since Sunday	0-6
     */
    bool repeatingInterrupt(struct tm *timeptr, uint8_t rptValue);

    /**
     * @brief Clear repeating interrupt set with `repeatingInterrupt()`.
     * @return true on success or false if an error occurs.
     */
    bool clearRepeatingInterrupt();

    /**
     * @brief Interrupt at a time in the future, either in minutes or seconds
     *
     * @param value Value in seconds or minutes. Must be 0 < value <= 255!
     *
     * @param minutes True if minutes, false if seconds
     *
     * @return true on success or false if an error occurs.
     * The countdown timer works even if the RTC has not been set yet, but is more
     * limited in range (maximum: 255 minutes).
     */
    bool interruptCountdownTimer(int value, bool minutes);

    void interruptCountdownTimer_seconds(int value);

    void interruptCountdownTimer_minutes(int value);

    /**
     * @brief Enters deep power down reset mode, using the EN pin
     *
     * @param seconds number of seconds to power down. Must be 0 < seconds <= 255.
     * The default is 30 seconds. If time-sensitive, 10 seconds is probably sufficient.
     *
     * @return true on success or false if an error occurs.
     *
     * This method powers down the MCU and cellular modem by using a combination
     * of the EN and RST pins. This super-reset is similar to what would happen if
     * you disconnected the battery.
     *
     * It assumes that EN is connected to /nIRQ2 (PSW) on the AB1805 using an
     * N-channel MOSFET and RST is connected to /RESET on the AB1805.
     *
     * After the deep reset finishes, the device will reboot and go back through
     * setup() again. Calling getWakeReset() will return the reason `DEEP_POWER_DOWN`.
     *
     * This works even if the RTC has not been set yet.
     */
    bool deepPowerDown(int seconds = 30);

    /**
     * @brief Used internally by interruptCountdownTimer and deepPowerDown.
     *
     * @param value Value in seconds or minutes. Must be 0 < value <= 255!
     *
     * @param minutes True if minutes, false if seconds
     *
     * @return true on success or false if an error occurs.
     *
     * The countdown timer works even if the RTC has not been set yet, but is more
     * limited in range (maximum: 255 minutes).
     */
    bool setCountdownTimer(int value, bool minutes);

    bool setRegisterBit(uint8_t regAddr, uint8_t bitMask);
    bool maskRegister(uint8_t regAddr, uint8_t andValue, uint8_t orValue);

      /**
       * @brief Utility function to convert a struct tm * to a readable string
       *
       * @return String in the format of "yyyy-mm-dd hh:mm:ss".
       */
      static String tmToString(const struct tm *timeptr);

      /**
       * @brief Convert a struct tm to register values for the AB1805
       *
       * @param timeptr Pointer to a struct tm with the values to convert from
       *
       * @param array Array of uint8_t to store the values to. This must be at least 6 bytes
       * if includeYear is false or 7 if true. This points to the seconds field, not the
       * hundredths field!
       *
       * @param includeYear True if this is the the year should be included (time setting),
       * or false if the year should not be included (alarm setting).
       *
       * Note: Does not include the hundredths are struct tm doesn't include fractional seconds.
       */
      static void tmToRegisters(const struct tm *timeptr, uint8_t *array, bool includeYear);

      /**
       * @brief Convert register values to a struct tm
       *
       * @param array Pointer to an array of values from the AB1805. Point to the seconds
       * (not hundredths).
       *
       * @param timeptr Pointer to a struct tm to hold the converted time
       *
       * @param includeYear True if this is the the year should be included (time setting),
       * or false if the year should not be included (alarm setting).
       */
      static void registersToTm(const uint8_t *array, struct tm *timeptr, bool includeYear);

      /**
       * @brief Convert a bcd value (0x00-0x99) into an integer (0-99)
       */
      static int bcdToValue(uint8_t bcd);

      /**
       * @brief Convert an integer value (0-99) into a bcd value (0x00 - 0x99)
       */
      static uint8_t valueToBcd(int value);

    void set_datetime_alarm(uint8_t month, uint8_t date, uint8_t hour, uint8_t minutes, uint8_t seconds) ;
    //Hundredths, seconds, minutes, hours, date and month match (once per year)

    void set_datetime_alarm(uint8_t date, uint8_t hour, uint8_t minutes, uint8_t seconds) ;
    //Hundredths, seconds, minutes, hours and date match (once per month)

    void set_week_alarm(uint8_t weekday, uint8_t hour, uint8_t minutes, uint8_t seconds) ;
    //Hundredths, seconds, minutes, hours and weekday match (once per week)

    void set_datetime_alarm(uint8_t hour, uint8_t minutes, uint8_t seconds) ; //Hundredths, seconds, minutes and hours match (once per day)

    void set_datetime_alarm(uint8_t minutes, uint8_t seconds); //Hundredths, seconds and minutes match (once per hour)

    void set_datetime_alarm(uint8_t seconds) ; //Hundredths, seconds match (once per minute)

    void set_once_second_alarm(uint8_t hundredths); //Hundredths match (once per second)

    void set_once_per_minute_alarm(uint8_t seconds);
    void stop_status_AIE();

    char *get_date_time();

		String get_date_string(void);

    uint8_t get_timerregister(void);
    //status registers
    uint8_t get_status(void);
    uint8_t get_CB_status(void);
    uint8_t get_BAT_status(void);
    uint8_t get_WDT_status(void);
    uint8_t get_BL_status(void);
    uint8_t get_TIM_status(void);
    uint8_t get_ALM_status(void);
    uint8_t get_EX2_status(void);
    uint8_t get_EX1_status(void);

    uint8_t clean_CB_status(void);
    uint8_t clean_BAT_status(void);
    uint8_t clean_WDT_status(void);
    uint8_t clean_BL_status(void);
    uint8_t clean_TIM_status(void);
    uint8_t clean_ALM_status(void);
    uint8_t clean_EX2_status(void);
    uint8_t clean_EX1_status(void);

    //set func
    uint8_t set_control1(uint8_t value);
    uint8_t set_1224(uint8_t value);
    uint8_t set_RSP(uint8_t value);
    uint8_t set_ARST(uint8_t value);
    uint8_t set_PWR2(uint8_t value);
    uint8_t set_WRTC(uint8_t value);

    //get/set interrupt
    uint8_t get_interrupt(void);
    uint8_t get_BLIE_interrupt(void); //Battery Low Interrupt Enable.
    uint8_t get_TIE_interrupt(void); //Timer Interrupt Enable.
    uint8_t get_AIE_interrupt(void); //Alarm Interrupt Enable.
    uint8_t get_EX1E_interrupt(void); //XT1 Interrupt Enable.
    uint8_t get_EX2E_interrupt(void); //XT2 Interrupt Enable.

    uint8_t set_interrupt(uint8_t value);
    uint8_t set_BLIE_interrupt(uint8_t value);
    uint8_t set_TIE_interrupt(uint8_t value);
    uint8_t set_AIE_interrupt(uint8_t value);
    uint8_t set_EX1E_interrupt(uint8_t value);
    uint8_t set_EX2E_interrupt(uint8_t value);

    //control2 register mode
    uint8_t get_control2(void);
    uint8_t get_RS1E_control2(void); //When 1, enable the nEXTR pin to generate nRST.
    uint8_t get_OUT2S_control2(void); //Controls the function of the PSW/nIRQ2 pin, as shown in Table 60.
    uint8_t get_OUT1S_control2(void); //Controls the function of the FOUT/NIRQ pin, as shown in Table 61.

    uint8_t set_control2(uint8_t value);
    uint8_t set_RS1E_control2(uint8_t value);
    uint8_t set_OUT2S_control2(uint8_t value);
    uint8_t set_OUT1S_control2(uint8_t value);

    //sleep mode
    uint8_t get_sleep(void);
    uint8_t get_SLP_sleep(void); //When 1, the Power Control SM will transition to the SWAIT state.
    uint8_t get_SLRES_sleep(void); //When 1, assert nRST low when the Power Control SM is in the SLEEP state.
    uint8_t get_EX2P_sleep(void); //When 1, the external interrupt XT2 will trigger on a rising edge of the WDI pin.
    uint8_t get_EX1P_sleep(void); //When 1, the external interrupt XT1 will trigger on a rising edge of the EXTI pin.
    uint8_t get_SLST_sleep(void); //Set when the AM18X5 enters Sleep Mode.
    uint8_t get_SLTO_sleep(void); //The number of 7.8 ms periods after SLP is set until the Power Control SM goes into the SLEEP state.

    uint8_t set_sleep(uint8_t value);
    uint8_t set_SLP_sleep(uint8_t value);
    uint8_t set_SLRES_sleep(uint8_t value);
    uint8_t set_EX2P_sleep(uint8_t value);
    uint8_t set_EX1P_sleep(uint8_t value);
    uint8_t clean_SLST_sleep(void);
    uint8_t set_SLTO_sleep(uint8_t value);

    //countdown control
    uint8_t get_time_control(void);
    uint8_t get_TE_time_control(void); //Timer Enable. When 1, the Countdown Timer will count down.
    uint8_t get_TM_time_control(void); //Timer Interrupt Mode.
    uint8_t get_TRPT_time_control(void); //Along with TM, this controls the repeat function of the Countdown Timer.
    //uint8_t get_RPT_time_control(void); //These bits enable the Alarm Interrupt repeat function.
    uint8_t get_RPT_time_control_0(void);
    uint8_t get_RPT_time_control_1(void);
    uint8_t get_RPT_time_control_2(void);
    //uint8_t get_TFS_time_control(void); //Select the clock frequency and interrupt pulse width of the Countdown Timer
    uint8_t get_TFS_time_control_0(void); //bit 0
    uint8_t get_TFS_time_control_1(void); //bit 1


    uint8_t set_time_control(uint8_t value);
    uint8_t set_TE_time_control(uint8_t value);
    uint8_t set_TM_time_control(uint8_t value);
    uint8_t set_TRPT_time_control(uint8_t value);
    uint8_t set_RPT_time_control(uint8_t value);
    uint8_t set_TFS_time_control(uint8_t value);

  //trickle charge
  void setTrickle(const uint8_t diodeAndRout);

    //outcontrol registers
    uint8_t get_outcontrol(void);
    uint8_t get_outcontrol(uint8_t mask);

    uint8_t set_outcontrol(uint8_t value);
    uint8_t set_outcontrol(uint8_t value,uint8_t mask);

    //OSC control registers
    uint8_t get_osc_control(void);
    uint8_t get_osc_control(uint8_t mask);
    uint8_t get_osc_control_OSEL(void);


    uint8_t set_osc_control(uint8_t value);
    uint8_t set_osc_control(uint8_t value,uint8_t mask);

    //WDT registers
    uint8_t get_WDT_register(void);
    uint8_t get_WDT_register(uint8_t mask);

    uint8_t set_WDT_register(uint8_t value);
    uint8_t set_WDT_register(uint8_t value,uint8_t mask);


    //sleep control methods
    void enter_sleep_mode_PWR(void);
    void enter_sleep_mode_PWR(uint8_t value);

    uint8_t enter_sleep_mode(uint8_t timeout,uint8_t mode);

		//convert func
    uint8_t dec_hex(uint8_t tens, uint8_t digits);
    uint8_t hex_dec(uint8_t hex);


    unsigned char hex2dec(unsigned char val);
    unsigned char dec2hex(unsigned char val);

	  unsigned bcd2bin(unsigned char val);
    unsigned char bin2bcd(unsigned val);

  private:
  //func

  //data

    volatile uint8_t _year;
    volatile uint8_t _month;
    volatile uint8_t _date;
    volatile uint8_t _weekday;
    volatile uint8_t _hour;
    volatile uint8_t _minute;
    volatile uint8_t _second;
    volatile uint8_t _hundredth;

    volatile uint8_t _alarm_year;
    volatile uint8_t _alarm_month;
    volatile uint8_t _alarm_date;
    volatile uint8_t _alarm_weekday;
    volatile uint8_t _alarm_hour;
    volatile uint8_t _alarm_minute;
    volatile uint8_t _alarm_second;
    char data_time_string[CONST_DATE_TIME_STRING_LEN];

    uint8_t _status;
    uint8_t _control1;
    uint8_t _control2;
    uint8_t _interrupt;
    uint8_t _sleep_mode;
    uint8_t _timer_control_mode;
    uint8_t _outcontrol;
    uint8_t _osc_control;
    uint8_t _wdt_register;
};

#define DEBUG_SIO Serial
/*
#if defined(DEBUG_SIO)
  #define SERIAL_DEBUG_BEGIN DEBUG_SIO.begin(74880);
  #define DBGPRINT(__VA_ARGS__) DEBUG_SIO.print(__VA_ARGS__)
  #define DBGPRINTLN(__VA_ARGS__) DEBUG_SIO.println(__VA_ARGS__)
  #define DBGPRINTF(fmt,...) DEBUG_SIO.printf(fmt,__VA_ARGS__)

#else
  #define SERIAL_DEBUG_BEGIN
  #define DBGPRINT(__VA_ARGS__)
  #define DBGPRINTLN(__VA_ARGS__)
  #define DBGPRINTF(fmt,...)
#endif
*/
#endif
