# New ports collection makefile for:    svgviewer
# Date created:         14 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	svgviewer
PORTVERSION=	0.2.0
PORTREVISION=	6
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://gnu.ethz.ch/debian/svgviewer/
DISTNAME=	SVGViewer-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SVG Viewer for GNUstep

LIB_DEPENDS+=	svg.1:${PORTSDIR}/graphics/libsvg
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

.include <bsd.port.mk>
