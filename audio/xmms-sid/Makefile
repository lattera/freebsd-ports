# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	xmms-sid
PORTVERSION=	0.7.4
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://www.tnsp.org/xs-files/

MAINTAINER=	c.petrik.sosa@gmail.com
COMMENT=	XMMS input plugin to play SID files

LIB_DEPENDS=	sidplay.1:${PORTSDIR}/audio/libsidplay
BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

PLIST_FILES=	lib/xmms/Input/libsid.so
USE_BZIP2=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS = -O2 -W -Wall|CFLAGS = @CFLAGS@ |; \
		s|-lstdc++||; \
		s|^LIBS = -lsidplay|LIBS = -lsidplay -lstdc++|' \
		${BUILD_WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
