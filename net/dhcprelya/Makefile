# New ports collection makefile for:	dhcprelya
# Date created:				17 December 2007
# Whom:					Sergey Matveychuk <sem@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dhcprelya
PORTVERSION=	4.3
CATEGORIES=	net
MASTER_SITES=	http://sem.semmy.ru/

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Lightweight DHCP relay agent. Yandex edition

USE_RC_SUBR=	dhcprelya

PORTDOCS=	README

PLIST_FILES=	sbin/${PORTNAME} lib/${PORTNAME}_log_plugin.so \
		lib/${PORTNAME}_option82_plugin.so

OPTIONS=	RADIUS_PLUGIN "build radius plugin" off

.include <bsd.port.options.mk>

.if defined(WITH_RADIUS_PLUGIN)
PLIST_FILES+=	lib/${PORTNAME}_radius_plugin.so
LIB_DEPENDS=	freeradius-client.2:${PORTSDIR}/net/freeradius-client
MAKE_ARGS=	-DWITH_RADIUS_PLUGIN
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/local#${PREFIX}#' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
