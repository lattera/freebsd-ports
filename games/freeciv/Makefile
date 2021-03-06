# New ports collection makefile for:	freeciv
# Date created:		Jun 20 1997
# Whom:			ada@bsd.org
#
# $FreeBSD$
#

PORTNAME=	freeciv
PORTVERSION=	2.3.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/freeciv/Freeciv%20${PORTVERSION:R}/${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Free turn-based multiplayer strategy

RUN_DEPENDS=	hicolor-icon-theme>=0:${PORTSDIR}/misc/hicolor-icon-theme

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-libiconv-prefix=${PREFIX} --program-transform-name=
INSTALLS_ICONS=	yes

MAN6=		freeciv-server.6 freeciv-client.6 \
		freeciv-xaw.6 freeciv-sdl.6 freeciv-gtk2.6 \
		freeciv-modpack.6

OPTIONS_DEFINE?=	X11 SDL MYSQL IPV6
OPTIONS_DEFAULT?=	X11 MYSQL IPV6

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSDL} && empty(PORT_OPTIONS:MX11)
IGNORE=		cannot use SDL without X11: re-run make config
.endif

.if ${PORT_OPTIONS:MX11}
LIB_DEPENDS+=	tiff:${PORTSDIR}/graphics/tiff \
		png15:${PORTSDIR}/graphics/png \
		ggz:${PORTSDIR}/games/libggz \
		ggz-gtk:${PORTSDIR}/games/ggz-gtk-client \
		ggzcore:${PORTSDIR}/games/ggz-client-libs \
		ggzmod:${PORTSDIR}/games/ggz-client-libs
USE_XORG=	xpm
USE_SDL=	mixer
USE_GNOME=	gtk20
CONFIGURE_ARGS+=--enable-client=gtk
CONFLICTS=	freeciv-nox11-[0-9]*
PLIST_SUB+=	X11="" GTK=""
.else
PKGNAMESUFFIX?=	-nox11
CONFIGURE_ARGS+=--enable-client=no
CONFLICTS=	freeciv-[0-9]*
PLIST_SUB+=	X11="@comment " GTK="@comment "
.endif

.if ${PORT_OPTIONS:MSDL}
CONFIGURE_ARGS+=--enable-client=gtk,sdl
USE_SDL=	sdl image ttf
PLIST_SUB+=	SDL=""
.else
PLIST_SUB+=	SDL="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
CONFIGURE_ARGS+=--enable-auth --with-mysql-prefix=${LOCALBASE}
USE_MYSQL=	yes
.endif

.if empty(PORT_OPTIONS:MIPV6)
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/test.*==/s|==|=|;\
		/^LIBS/s|mixer|mixer $$SDL_LIBS|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name Makefile.in|${XARGS} ${REINPLACE_CMD} -e\
		'/pkgdatadir/s|$$[(]datadir[)]/@PACKAGE@|${DATADIR}|'

.if ${PORT_OPTIONS:MX11}
post-install:
	@${INSTALL_DATA} ${WRKSRC}/data/civclient.dsc ${DATADIR}/
	@cd ${PREFIX}/bin && ${LN} -s freeciv-gtk2 freeciv-client
.endif

.include <bsd.port.mk>
