#ifdef UCD_COMPATIBLE

#include <net-snmp/agent/auto_nlist.h>

#else

#error "Please update your headers or configure using --enable-ucd-snmp-compatibility"

#endif
