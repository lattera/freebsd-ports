# Create by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kasablanca
PORTVERSION=	0.4.0.2
PORTREVISION=	8
CATEGORIES=	ftp kde
MASTER_SITES=	BERLIOS \
		http://www.hitnet.rwth-aachen.de/~brueffer/distfiles/

MAINTAINER=	c.petrik.sosa@gmail.com
COMMENT=	Graphical ftp client for KDE

EXTRA_PATCHES=	${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_AUTOTOOLS=	libtool

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g'	${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|\(-lssl\)|\1 -lcrypto|' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
