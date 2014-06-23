/**
\brief This project runs the full OpenWSN stack.

\author Thomas Watteyne <watteyne@eecs.berkeley.edu>, August 2010
*/

#include "board.h"
#include "scheduler.h"
#include "openwsn.h"
#include "udp_log_message.h"


int mote_main(void) {

 initialize_udp_log_message(); 
 
 board_init(self);
 udp_log_message("board_init()");

 scheduler_init(self);
 udp_log_message("scheduler_init()");

 openwsn_init(self);
 udp_log_message("openwsn_init()");

 scheduler_start(self);
 udp_log_message("scheduler_start()");
   return 0; // this line should never be reached
}
