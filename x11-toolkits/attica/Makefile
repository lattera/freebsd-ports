# New ports collection Makefile for:	attica
# Date created:				2009-12-05
# Whom:					fluffy
#
# $FreeBSD$

PORTNAME=	attica
PORTVERSION=	0.2.9
PORTEPOCH=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Collaboration Services API library

USE_QT4=	dbus network moc_build uic_build rcc_build qmake_build
USE_BZIP2=	yes
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

post-patch:
	${MKDIR} ${WRKSRC}
	${REINPLACE_CMD} -e \
		's,$${LIB_DESTINATION}/pkgconfig,libdata/pkgconfig,' \
		${WRKSRC}/lib/CMakeLists.txt

.include <bsd.port.mk>
