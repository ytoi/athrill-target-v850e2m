#ifndef _VDEV_PRIVATE_H_
#define _VDEV_PRIVATE_H_

#include "device.h"
#include "inc/vdev.h"
#include "std_errno.h"
#include "udp/udp_comm.h"

typedef enum {
	VdevIoOperation_UDP = 0,
	VdevIoOperation_MMAP,
	VdevIoOperation_EV3PROXY,
} VdevIoOperationType;

typedef struct {
	UdpCommConfigType config;
	MpuAddressRegionType *region;
	uint32		cpu_freq;
	uint64 		vdev_sim_time[VDEV_SIM_INX_NUM]; /* usec */
	/*
	 * for UDP ONLY
	 */
	UdpCommType comm;
	char *remote_ipaddr;
	char *local_ipaddr;

	/*
	 * for MMAP ONLY
	 */
	uint32		tx_data_addr;
	uint8		*tx_data;
	uint32		rx_data_addr;
	uint8		*rx_data;

	/*
	* for EV3Proxy Only
	*/
	FILE *tx_fp;
	FILE *rx_fp;
} VdevControlType;
extern VdevControlType vdev_control;
extern void device_init_vdev(MpuAddressRegionType *region, VdevIoOperationType op_type);

/*
 * UDP operations
 */
extern void device_init_vdev_udp(MpuAddressRegionType *region);
extern void device_supply_clock_vdev_udp(DeviceClockType *dev_clock);
extern MpuAddressRegionOperationType	vdev_udp_memory_operation;


/*
 * MMAP operations
 */
extern void device_init_vdev_mmap(MpuAddressRegionType *region);
extern void device_supply_clock_vdev_mmap(DeviceClockType *dev_clock);
extern MpuAddressRegionOperationType	vdev_mmap_memory_operation;


/*
* EV3 proxy operations
*/
extern void device_init_vdev_ev3proxy(MpuAddressRegionType *region);
extern void device_supply_clock_vdev_ev3proxy(DeviceClockType *dev_clock);
extern MpuAddressRegionOperationType	vdev_ev3proxy_memory_operation;


#endif /* _VDEV_PRIVATE_H_ */
