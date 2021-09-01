/*
 * startup.s
 *
 *  Created on: Sep 1, 2021
 *      Author: MahmoudH
 */

.global reset
reset:  ldr sp, =0x00011000
        bl main
stop:   b stop
