# New ports collection makefile for:  madplay
# Date created:        26 November 2003
# Whom:                Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	madplay
PORTVERSION=	0.15.2b
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF/mad/${PORTNAME}/${PORTVERSION} \
		ftp://ftp.mars.org/pub/mpeg/


MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Madplay MP3 player (part of MAD project)

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/libmad \
		id3tag.0:${PORTSDIR}/audio/libid3tag

LICENSE=	GPLv2

WANT_GNOME=	yes

GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
ALL_TARGET=	all madtime

MAN1=		abxtest.1 madplay.1

OPTIONS_DEFINE=NLS ESOUND
OPTIONS_DEFAULT=NLS ESOUND
NO_OPTIONS_SORT=yes
TCL82_MAN_DESC= Install tcl 8.3 manpages

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.if ${PORT_OPTIONS:MESOUND}
USE_GNOME+=	esound
.else
CONFIGURE_ARGS+=	--without-esd
.endif

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/madtime ${PREFIX}/bin

.include <bsd.port.mk>
