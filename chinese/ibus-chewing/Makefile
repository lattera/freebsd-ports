# Created by: Eric L. Chen <lihong@ieee.org>
# $FreeBSD$

PORTNAME=	ibus-chewing
PORTVERSION=	1.4.2
CATEGORIES=	chinese
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${PORTVERSION}-Source

MAINTAINER=	lihong@ieee.org
COMMENT=	Chewing engine for IBus

LICENSE=	GPLv2

BUILD_DEPENDS=	gob2:${PORTSDIR}/devel/gob2 \
		${LOCALBASE}/share/cmake/Modules/ManageEnvironment.cmake:${PORTSDIR}/devel/cmake-fedora \
		ibus-daemon:${PORTSDIR}/textproc/ibus
RUN_DEPENDS=	ibus-daemon:${PORTSDIR}/textproc/ibus
LIB_DEPENDS=	chewing:${PORTSDIR}/chinese/libchewing

CMAKE_ARGS+=	-DSYSCONF_INSTALL_DIR=${PREFIX}/etc \
		-DLIB_DIR=${PREFIX}/lib
GCONF_SCHEMAS=	${PORTNAME}.schemas
USE_CMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gconf2 gtk20
USE_XORG=	xtst

PROJECTHOST=	ibus

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
