# New ports collection makefile for:	jpegpixi
# Date created:		28 May 2002
# Whom:			verm@drunkmonk.net
#
# $FreeBSD$
#

PORTNAME=	jpegpixi
PORTVERSION=	1.1.1
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://www.zero-based.org/software/jpegpixi/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Useful to correct images from digital camera with CCD defects

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-10-20

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MANLANG=	"" de fi fr
MAN1=		jpeghotp.1 jpegpixi.1

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.mk>
