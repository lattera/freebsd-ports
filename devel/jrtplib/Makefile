# Created by: Petr Holub <hopet@ics.muni.cz>
# $FreeBSD$

PORTNAME=	jrtplib
PORTVERSION=	3.7.1
CATEGORIES=	devel
MASTER_SITES=	http://research.edm.uhasselt.be/jori/jrtplib/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Object-oriented RTP library written in C++

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-jthread

PLIST_SUB+=	JRTPLIB_VER=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|\$$(libdir)/pkgconfig|\$$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/pkgconfig/Makefile.in

.include <bsd.port.mk>
