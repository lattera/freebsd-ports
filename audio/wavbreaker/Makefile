# New ports collection makefile for:	wavbreaker
# Date created:				20 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	wavbreaker
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Tool to split and merge wav files

OPTIONS_DEFINE=	PULSEAUDIO NLS

USE_GNOME=	gnomehack gtk20 libxml2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PKG_CONFIG="${LOCALBASE}/bin/pkg-config"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-alsa
INSTALLS_ICONS=	yes

MAN1=		wavbreaker.1 wavinfo.1 wavmerge.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
.else
CONFIGURE_ARGS+=	--disable-pulse
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

.include <bsd.port.mk>
