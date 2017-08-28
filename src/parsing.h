#ifndef PARSING_H
#define PARSING_H

#include "common.h"

// parse ip header data
u_int8_t parse_ip(const u_char *packet, struct ip **iphdr);
// parse tcp header data
int parse_tcp(const u_char *segment, struct tcphdr **tcphdr);
// parse data
int parse_data(const u_char *payload, bpf_u_int32 len);

#endif // PARSING_H

