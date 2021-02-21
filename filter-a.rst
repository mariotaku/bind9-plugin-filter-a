.. 
   Copyright (C) Internet Systems Consortium, Inc. ("ISC")
   
   This Source Code Form is subject to the terms of the Mozilla Public
   License, v. 2.0. If a copy of the MPL was not distributed with this
   file, you can obtain one at https://mozilla.org/MPL/2.0/.
   
   See the COPYRIGHT file distributed with this work for additional
   information regarding copyright ownership.

..
   Copyright (C) Internet Systems Consortium, Inc. ("ISC")

   This Source Code Form is subject to the terms of the Mozilla Public
   License, v. 2.0. If a copy of the MPL was not distributed with this
   file, You can obtain one at http://mozilla.org/MPL/2.0/.

   See the COPYRIGHT file distributed with this work for additional
   information regarding copyright ownership.


.. highlight: console

.. _man_filter-a:

filter-a.so - filter A in DNS responses when A is present
---------------------------------------------------------------

Synopsis
~~~~~~~~

:program:`plugin query` "filter-a.so" [{ parameters }];

Description
~~~~~~~~~~~

``filter-a.so`` is a query plugin module for ``named``, enabling
``named`` to omit some IPv4 addresses when responding to clients.

Until BIND 9.12, this feature was implemented natively in ``named`` and
enabled with the ``filter-a`` ACL and the ``filter-a-on-v4`` and
``filter-a-on-v6`` options. These options are now deprecated in
``named.conf``, but can be passed as parameters to the
``filter-a.so`` plugin, for example:

::

   plugin query "/usr/local/lib/filter-a.so" {
           filter-a-on-v4 yes;
           filter-a-on-v6 yes;
           filter-a { 192.0.2.1; 2001:db8:2::1; };
   };

This module is intended to aid transition from IPv4 to IPv6 by
withholding IPv6 addresses from DNS clients which are not connected to
the IPv6 Internet, when the name being looked up has an IPv4 address
available. Use of this module is not recommended unless absolutely
necessary.

Note: This mechanism can erroneously cause other servers not to give
A records to their clients. If a recursing server with both IPv6 and
IPv4 network connections queries an authoritative server using this
mechanism via IPv4, it will be denied A records even if its client is
using IPv4.

Options
~~~~~~~

``filter-a``
   Specifies a list of client addresses for which A filtering is to
   be applied. The default is ``any``.

``filter-a-on-v6``
   If set to ``yes``, the DNS client is at an IPv6 address, in
   ``filter-a``, and if the response does not include DNSSEC
   signatures, then all A records are deleted from the response. This
   filtering applies to all responses and not only authoritative
   responses.

   If set to ``break-dnssec``, then A records are deleted even when
   DNSSEC is enabled. As suggested by the name, this causes the response
   to fail to verify, because the DNSSEC protocol is designed to detect
   deletions.

   This mechanism can erroneously cause other servers not to give A
   records to their clients. A recursing server with both IPv6 and IPv4
   network connections that queries an authoritative server using this
   mechanism via IPv4 will be denied A records even if its client is
   using IPv4.

``filter-a-on-v4``
   Identical to ``filter-a-on-v4``, except it filters A responses
   to queries from IPv4 clients instead of IPv6 clients. To filter all
   responses, set both options to ``yes``.

See Also
~~~~~~~~

BIND 9 Administrator Reference Manual.
