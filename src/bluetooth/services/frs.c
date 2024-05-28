#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>

#include <bluetooth/services/frs.h>

#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(bt_frs, CONFIG_BT_FRS_LOG_LEVEL);

static bool notify_enabled;
static bt_frs_cb frs_cb;

static void frslc_ccc_cfg_changed(const struct bt_gatt_attr *attr,
				  uint16_t value)
{
	notify_enabled = (value == BT_GATT_CCC_NOTIFY);
}

/* LED Button Service Declaration */
BT_GATT_SERVICE_DEFINE(frs_svc,
BT_GATT_PRIMARY_SERVICE(BT_UUID_FRS),
	BT_GATT_CHARACTERISTIC(BT_UUID_FRS_FLOWRATE,
			       BT_GATT_CHRC_READ | BT_GATT_CHRC_NOTIFY,
			       BT_GATT_PERM_READ, NULL, NULL, NULL),
	BT_GATT_CCC(frslc_ccc_cfg_changed,
		    BT_GATT_PERM_READ | BT_GATT_PERM_WRITE),
);

int bt_frs_init(bt_frs_cb *callbacks)
{
	if (callbacks) {
        frs_cb.flowrate_cb = callbacks->flowrate_cb;
	}

	return 0;
}
