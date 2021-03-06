# New ports collection makefile for:	sensors-applet
# Date created:			03 May 2006
# Whom:				Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sensors-applet
PORTVERSION=	1.6.1
PORTREVISION=	10
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/GNOME%20Sensors%20Applet%20Version%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GNOME applet displaying hardware sensor values

RUN_DEPENDS=	mbmon:${PORTSDIR}/sysutils/mbmon \
		smartctl:${PORTSDIR}/sysutils/smartmontools

USE_GNOME=	gnomehack gnomeprefix intlhack gnomepanel libgnomeui
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
DEFINES=	-DMBMON_EXECUTABLE=\\\"${LOCALBASE}/bin/mbmon\\\" \
		-DSMARTCTL_HELPER=\\\"${PREFIX}/libexec/smartctl-helper\\\"
CPPFLAGS+=	-I${LOCALBASE}/include ${DEFINES}
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${CP} -f ${FILESDIR}/mbmon-sensors-interface.* \
		${FILESDIR}/smartctl-sensors-interface.* ${WRKSRC}/src

post-build:
	${CC} ${CFLAGS} -DSMARTCTL=\"${LOCALBASE}/sbin/smartctl\" \
		-o ${WRKSRC}/smartctl-helper ${FILESDIR}/smartctl-helper.c

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/smartctl-helper ${PREFIX}/libexec
	${CHMOD} u+s ${PREFIX}/libexec/smartctl-helper

.include <bsd.port.mk>
