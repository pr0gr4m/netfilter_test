#include "parsing.h"

/*
 * Prototype : u_int8_t parse_ip(const u_char *packet, struct ip *iphdr)
 * Last Modified 2017/08/06
 * Written by pr0gr4m
 *
 * store ip header by packet
 * return protocol
 */
u_int8_t parse_ip(const u_char *packet, struct ip **iphdr)
{
	*iphdr = (struct ip *)packet;
    return (*iphdr)->ip_p;
}

/*
 * Prototype : int parse_tcp (const u_char *segment, struct tcphdr *tcphdr)
 * Last Modified 2017/08/29
 * Written by pr0gr4m
 *
 * store tcp header by segment
 * return data offset
 */
int parse_tcp(const u_char *segment, struct tcphdr **tcphdr)
{
	*tcphdr = (struct tcphdr *)segment;
	return ntohs((*tcphdr)->dest);
}

static int parse_host(const char *data, char *buf)
{
	char *p = strstr(data, "Host: ");
	char *e = strchr(p, '\r');
	p += strlen("Host: ");

	strncpy(buf, p, e - p + 1);
	buf[e - p + 1] = 0;
	return TRUE;
}

static int check_host(const char *hostname)
{
	if (!strncmp(hostname, "www.avnana.com", strlen("www.avnana.com")) ||
			!strncmp(hostname, "avnana.com", strlen("avnana.com")))
		return TRUE;
	else
		return FALSE;
}

/*
 * Prototype : int parse_data(const u_char *payload, bpf_u_int32 len)
 * Last Modified 2017/08/29
 * Written by pr0gr4m
 *
 * Print payload
 * return TRUE
 */
int parse_data(const u_char *payload, bpf_u_int32 len)
{
	char hostname[BUF_LEN];
	parse_host((const char *)payload, hostname);

	if (check_host(hostname))
		return TRUE;
	else
		return FALSE;
}
