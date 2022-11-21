// #define BUTTON_NEED_PULLUP // if set we need to turn on the internal CPU pullup during sleep

#define I2C_SDA 21
#define I2C_SCL 22

#define BUTTON_PIN 0     // The middle button GPIO on the T-Beam
//#define BUTTON_PIN_ALT 13 // Alternate GPIO for an external button if needed. Does anyone use this? It is not documented anywhere.
#define EXT_NOTIFY_OUT 25 // Default pin to use for Ext Notify Module.

#define LED_INVERTED 1
#define LED_PIN 12 // Newer tbeams (1.1) have an extra led on GPIO4

// TTGO uses a common pinout for their SX1262 vs RF95 modules - both can be enabled and we will probe at runtime for RF95 and if
// not found then probe for SX1262
#define USE_RF95
#define USE_SX1262
#define USE_SX1268

#define LORA_DIO0  -1 // a No connect on the SX1262 module
#define LORA_RESET 14
#define LORA_DIO1 33 // SX1262 IRQ
#define LORA_DIO2 39 // SX1262 BUSY
#define LORA_DIO3    // Not connected on PCB, but internally on the TTGO SX1262, if DIO3 is high the TXCO is enabled
#define LORA_RXEN 2  // Input - RF switch RX control, connecting external MCU IO, valid in high level
#define LORA_TXEN 4  // Input - RF switch TX control, connecting external MCU IO or DIO2, valid in high level

// PINS FOR THE 900M30S
#undef RF95_SCK
#define RF95_SCK 18
#undef RF95_MISO
#define RF95_MISO 19
#undef RF95_MOSI
#define RF95_MOSI 23
#undef RF95_NSS
#define RF95_NSS 5

// RX/TX for RFM95/SX127x
#define RF95_RXEN LORA_RXEN
#define RF95_TXEN LORA_TXEN

#ifdef USE_SX1262
#define SX126X_CS RF95_NSS // FIXME - we really should define LORA_CS instead
#define SX126X_DIO1 LORA_DIO1
#define SX126X_BUSY LORA_DIO2
#define SX126X_RESET LORA_RESET
#define SX126X_RXEN LORA_RXEN
#define SX126X_TXEN LORA_TXEN
#define SX126X_E22 // Not really an E22 but TTGO seems to be trying to clone that
// Internally the TTGO module hooks the SX1262-DIO2 in to control the TX/RX switch (which is the default for the sx1262interface
// code)
#endif

// Leave undefined to disable our PMU IRQ handler.  DO NOT ENABLE THIS because the pmuirq can cause sperious interrupts
// and waking from light sleep
// #define PMU_IRQ 35
//#define HAS_AXP192
#define GPS_UBLOX