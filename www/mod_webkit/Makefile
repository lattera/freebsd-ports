# New ports collection makefile for:	mod_webkit
# Date created:		2005-12-22
# Whom:			Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	mod_webkit
PORTVERSION=	1.1b1
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/webware/Webware/1.1b1
DISTNAME=	Webware-${PORTVERSION}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	A apache module for WebWare WebKit AppServer

MAKE_JOBS_SAFE=  yes

USE_APACHE=	22+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
AP_EXTRAS=	marshal.c

WRKSRC=		${WRKDIR}/Webware-${PORTVERSION}/WebKit/Adapters/${PORTNAME}2

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/sbin/apxs|${APXS}|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
