# New ports collection Makefile for:	kpartsplugin
# Date created:				9 July 2012
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kpartsplugin
DISTVERSION=	0.0-${PORTDATE}
CATEGORIES=	www kde
MASTER_SITES=	http://www.unix-ag.uni-kl.de/~fischer/${PORTNAME}/
DISTNAME=	${PORTNAME}-${PORTDATE}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Browser file viewer using KDE technology

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USE_QT4=	gui moc_build qmake_build rcc_build uic_build
USE_BZIP2=	yes
USE_CMAKE=	yes
CMAKE_ARGS=	-DNSPLUGIN_INSTALL_DIR:PATH="${WEBPLUGINS_DIR}"
MAKE_JOBS_SAFE=	yes

PORTDATE=	20120723

USE_WEBPLUGINS=	native
WEBPLUGINS_FILES=	lib${PORTNAME}.so

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/firefox/Makefile.webplugins"
.include <bsd.port.post.mk>
