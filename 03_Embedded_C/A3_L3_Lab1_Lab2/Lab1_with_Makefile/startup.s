/*
 * startup.s
 *
 *  Created on: Sep 1, 2021
 *      Author: MahmoudH
 */

.global reset
reset:  ldr sp, =stack_top
        bl main
stop:   b stop
