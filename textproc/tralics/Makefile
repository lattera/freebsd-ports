# Created by: siasia
# $FreeBSD$

PORTNAME=      tralics
PORTVERSION=   2.13.7
CATEGORIES=    textproc
MASTER_SITES=  ftp://ftp-sop.inria.fr/apics/tralics-src/
DISTNAME=      $(PORTNAME)-src-$(PORTVERSION)

MAINTAINER=    ports@FreeBSD.org
COMMENT=       LaTeX to XML translator

NO_INSTALL_MANPAGES=yes

WRKSRC=        $(WRKDIR)/$(PORTNAME)-$(PORTVERSION)/src
ALL_TARGET=    tralics

PLIST_FILES=   bin/tralics

do-install:
	$(INSTALL_PROGRAM) $(WRKSRC)/tralics $(PREFIX)/bin

.include <bsd.port.mk>
