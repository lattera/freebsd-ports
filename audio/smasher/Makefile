# New ports collection makefile for:	smasher
# Date created:		22 June 2009
# Whom:			chris@officialunix.com
#
# $FreeBSD$
#

PORTNAME=	smasher
PORTVERSION=	1.1.6
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	c.petrik.sosa@gmail.com
COMMENT=	Cross platform audio loop slicer

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile \
		mad.2:${PORTSDIR}/audio/libmad \
		csound64.5:${PORTSDIR}/audio/csound

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CONFIGURE_ARGS=	--with-wx-config=${LOCALBASE}/bin/wxgtk2-2.8-config
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_XORG=	x11
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_WX=		yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/pixmaps|${LOCALBASE}/share/pixmaps|g' \
		${WRKSRC}/src/Makefile.am ${WRKSRC}/src/Makefile.in

	@${REINPLACE_CMD} -e 's|/usr/share/applications|${LOCALBASE}/share/applications|g' \
		${WRKSRC}/src/Makefile.am ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
