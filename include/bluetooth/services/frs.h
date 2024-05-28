/*
 */

#ifndef BT_FRS_H_
#define BT_FRS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <zephyr/types.h>

// TODO: How to select UUID?
// @brief FRS Service UUID
#define BT_UUID_FRS_VAL \
	BT_UUID_128_ENCODE(0x00001523, 0x1212, 0xefde, 0x1523, 0x785feabcd123)

// TODO: How to select UUID?
// @brief Button Characteristic UUID
#define BT_UUID_FRS_FLOWRATE_VAL \
	BT_UUID_128_ENCODE(0x00001524, 0x1212, 0xefde, 0x1523, 0x785feabcd123)

#define BT_UUID_FRS           BT_UUID_DECLARE_128(BT_UUID_FRS_VAL)
#define BT_UUID_FRS_FLOWRATE  BT_UUID_DECLARE_128(BT_UUID_FRS_FLOWRATE_VAL)

// @brief Callback type for when flow rate information
typedef void (*frs_cb_t)(void);

// @brief Callback struct used by the FRS Service
struct bt_frs_cb {
	// Flow rate information callback
	frs_cb_t flowrate_cb;
};

// @brief Initialize the FRS Service.
int bt_frs_init(bt_frs_cb *callbacks);

#ifdef __cplusplus
}
#endif

#endif /* BT_FRS_H_ */
