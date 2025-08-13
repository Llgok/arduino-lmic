/*

Module:  getpinmap_t_connect_pro.cpp

Function:
        Arduino-LMIC C++ HAL pinmap for T-Connect-Pro

Copyright & License:
        See accompanying LICENSE file.

*/

#if defined(ARDUINO_T_CONNECT_PRO)

#include <arduino_lmic_hal_boards.h>
#include <Arduino.h>

#include "../lmic/oslmic.h"

namespace Arduino_LMIC {

    class HalConfiguration_T_Connect_Pro : public HalConfiguration_t {
    public:
        enum DIGITAL_PINS : uint8_t {
            PIN_NSS = 14,
            PIN_NRESET = 42,
            PIN_BUSY = 38,
#ifdef ARDUINO_LMIC_LIBRARY_DISABLE_INT_PIN
            PIN_DIO1 = HalPinmap_t::UNUSED_PIN,
#else
            PIN_DIO1 = 45,
#endif
            PIN_DIO2 = HalPinmap_t::UNUSED_PIN,
            PIN_DIO3 = HalPinmap_t::UNUSED_PIN,
            PIN_ANT_SWITCH_RX = HalPinmap_t::UNUSED_PIN,
            PIN_ANT_SWITCH_TX_BOOST = HalPinmap_t::UNUSED_PIN,
            PIN_ANT_SWITCH_TX_RFO = HalPinmap_t::UNUSED_PIN,
            PIN_VDD_BOOST_ENABLE = HalPinmap_t::UNUSED_PIN,
        };

        virtual u1_t queryBusyPin(void) override { return HalConfiguration_T_Connect_Pro::PIN_BUSY; };

        virtual bool queryUsingDcdc(void) override { return true; };

        virtual bool queryUsingDIO2AsRfSwitch(void) override { return true; };

        virtual bool queryUsingDIO3AsTCXOSwitch(void) override { return true; };
    };

    static HalConfiguration_T_Connect_Pro myConfig;

    static const HalPinmap_t myPinmap =
    {
        .nss = HalConfiguration_T_Connect_Pro::PIN_NSS,
        .rxtx = HalConfiguration_T_Connect_Pro::PIN_ANT_SWITCH_RX,
        .rst = HalConfiguration_T_Connect_Pro::PIN_NRESET,
        .dio = {
            HalConfiguration_T_Connect_Pro::PIN_DIO1,
            HalConfiguration_T_Connect_Pro::PIN_DIO2,
            HalConfiguration_T_Connect_Pro::PIN_DIO3,
        },
        .rxtx_rx_active = 0,
        .rssi_cal = 8,
        .spi_freq = 8000000, /* 8MHz */
        .pConfig = &myConfig
    };

    const HalPinmap_t* GetPinmap_T_Connect_Pro(void) {
        return &myPinmap;
    }

}; // namespace Arduino_LMIC

#endif // defined(ARDUINO_T_CONNECT_PRO)