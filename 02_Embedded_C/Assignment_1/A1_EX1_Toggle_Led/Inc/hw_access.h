/*
 * hw_access.h
 *
 *  Created on: Mar 11, 2021
 *      Author: MahmoudH
 */

#ifndef HW_ACCESS_H_
#define HW_ACCESS_H_

#include "Platform_Types.h"

#define RW					volatile
#define RO					const volatile

#define IO_RW_REG8(x)		(*((RW uint8 *)(x)))
#define IO_RO_REG8(x)		(*((RO uint88 *)(x)))

#define IO_RW_REG16(x)		(*((RW uint16 *)(x)))
#define IO_RO_REG16(x)		(*((RO uint16 *)(x)))

#define IO_RW_REG32(x)		(*((RW uint32 *)(x)))
#define IO_RO_REG32(x)		(*((RO uint32 *)(x)))

#define IO_RW_REG64(x)		(*((RW uint64 *)(x)))
#define IO_RO_REG64(x)		(*((RO uint64 *)(x)))

#endif /* HW_ACCESS_H_ */
