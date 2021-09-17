/*
 * hw_access.h
 *
 *  Created on: Mar 11, 2021
 *      Author: MahmoudH
 */

#ifndef HW_ACCESS_H_
#define HW_ACCESS_H_

#include "Platform_Types.h"

// Read/write Access
#define RW					volatile
// Read-only access
#define RO					const volatile

// I/O 8-bits register given the address
#define IO_RW_REG8(addr)	(*((RW uint8 *)(addr)))
#define IO_RO_REG8(addr)	(*((RO uint8 *)(addr)))

// I/O 16-bits register given the address
#define IO_RW_REG16(addr)	(*((RW uint16 *)(addr)))
#define IO_RO_REG16(addr)	(*((RO uint16 *)(addr)))

// I/O 32-bits register given the address
#define IO_RW_REG32(addr)	(*((RW uint32 *)(addr)))
#define IO_RO_REG32(addr)	(*((RO uint32 *)(addr)))

// I/O 64-bits register given the address
#define IO_RW_REG64(addr)	(*((RW uint64 *)(addr)))
#define IO_RO_REG64(addr)	(*((RO uint64 *)(addr)))

#endif /* HW_ACCESS_H_ */
