# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ktorrent
DISTVERSION=	4.3.0
PORTREVISION=	1
CATEGORIES=	net-p2p kde
MASTER_SITES=	http://ktorrent.org/downloads/${DISTVERSION}/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	BitTorrent client for KDE

LIB_DEPENDS=	tag:${PORTSDIR}/audio/taglib \
		ktorrent.5:${PORTSDIR}/net-p2p/libktorrent

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdehier kdeprefix automoc4 pimlibs workspace
USE_QT4=	qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CONFLICTS_BUILD=	ktorrent-2*

SHLIB_VER=	14.0.0
PLIST_SUB+=	SHLIB_VER=${SHLIB_VER} \
		SHLIB_SHVER=${SHLIB_VER:R:R}

CMAKE_ARGS+=	-DENABLE_KIO_MAGNET=1

.include <bsd.port.mk>
