/**
\brief This project runs the full OpenWSN stack.

\author Thomas Watteyne <watteyne@eecs.berkeley.edu>, August 2010
*/

#include "board.h"
#include "scheduler.h"
#include "openwsn.h"
#include "udp_log_message.h"


int mote_main() {

   initialize_udp_log_message();

   udp_log_message("board_init()");
   board_init();

   udp_log_message("scheduler_init()");
   scheduler_init();

   udp_log_message("openwsn_init()");
   openwsn_init();

   udp_log_message("scheduler_start()");
   scheduler_start();
   return 0; // this line should never be reached
}
