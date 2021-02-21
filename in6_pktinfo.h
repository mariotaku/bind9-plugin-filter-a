/* IPv6 packet information.  */
struct in6_pktinfo
  {
    struct in6_addr ipi6_addr;	/* src/dst IPv6 address */
    unsigned int ipi6_ifindex;	/* send/recv interface index */
  };