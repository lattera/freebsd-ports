# New ports collection makefile for:	qssl
# Date created:		10 November 2002
# Whom:			dd
#
# $FreeBSD$
#

PORTNAME=	qssl
PORTVERSION=	2.0
PORTREVISION=	7
CATEGORIES=	devel security
MASTER_SITES=	SF/psi/Common/Common

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	QSSL is a Qt plugin that helps applications use OpenSSL

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

SHLIB_MAJOR=	1

USE_OPENSSL=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
MAKE_ARGS=	QTDIR=${QT_PREFIX}
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"
USE_QT_VER=	3

.include <bsd.port.pre.mk>

post-patch:
.if ${OPENSSLBASE} == ${LOCALBASE} || ${OSVERSION} < 800000
	${REINPLACE_CMD} -e '531s|^|const|' ${WRKSRC}/qssl.cpp
.endif

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ARGS} qmake \
		-spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ qssl.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libqssl.so \
		${PREFIX}/lib/libqssl.so.${SHLIB_MAJOR}
	${LN} -s libqssl.so.${SHLIB_MAJOR} ${PREFIX}/lib/libqssl.so

.include <bsd.port.post.mk>
