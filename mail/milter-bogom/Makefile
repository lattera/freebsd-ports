# New ports collection makefile for:	milter-bogom
# Date created:			12 Feb 2005
# Whom:				Victor Balada Diaz <victor@bsdes.net>
#
# $FreeBSD$
#

PORTNAME=	bogom
PORTVERSION=	1.9.2
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.usebox.net/jjm/bogom/ \
		http://blackshell.usebox.net/bogom/
PKGNAMEPREFIX=	milter-

MAINTAINER=	victor@bsdes.net
COMMENT=	Simple sendmail milter to interface bogofilter

RUN_DEPENDS=	bogofilter:${PORTSDIR}/mail/bogofilter

MAN8=		bogom.8

MAKE_ARGS=	CPPFLAGS="-DDEF_CONF=\\\"${PREFIX}/etc/bogom.conf\\\" ${PTHREAD_CFLAGS}" \
		LIBS="-lmilter ${PTHREAD_LIBS}"

USE_RC_SUBR=	milter-bogom
SUB_FILES=	pkg-message

PLIST_FILES=	sbin/bogom \
		etc/bogom.conf-example

PORTDOCS=	README CHANGELOG

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' ${WRKSRC}/bogom.8
	@${REINPLACE_CMD} -e \
		's|/usr/local/bin/bogofilter|${LOCALBASE}/bin/bogofilter|g' \
		${WRKSRC}/bogom.8 \
		${WRKSRC}/bogom.conf-example \
		${WRKSRC}/milter.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bogom ${PREFIX}/sbin
	@${INSTALL_MAN} ${WRKSRC}/bogom.8 ${MAN8PREFIX}/man/man8
	@${INSTALL_DATA} ${WRKSRC}/bogom.conf-example ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
